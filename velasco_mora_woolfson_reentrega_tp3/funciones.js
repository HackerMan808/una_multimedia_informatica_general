//Galeria

const chunkBy3 = (arr) =>                           // Declara una función flecha que recibe el arreglo 'arr'
  arr.reduce((acc, v, i) => {                       // Recorre 'arr' con reduce: 'acc' acumula los chunks, 'v' es el valor, 'i' el índice
    if (i % 3 === 0) acc.push([v]);                 // Si el índice es múltiplo de 3, inicia una NUEVA tripleta con el elemento actual
    else acc[acc.length - 1].push(v);               // Si no, agrega el elemento a la ÚLTIMA tripleta creada en 'acc'
    return acc;                                     // Devuelve el acumulador para la siguiente iteración del reduce
  }, [])                                            // Valor inicial del acumulador: un array vacío (no hay chunks aún)
  .filter(t => t.length === 3);                     // Al final, conserva solo las tripletas COMPLETAS (longitud exactamente 3)


window.preloadImages = (...sources) => {
  const doc = document;
  if (!doc.images) return; // si el documento no soporta imágenes, salimos

  // Creamos el cache si no existe (nullish coalescing assignment).
  doc.imagesList ??= [];

  sources
    .filter(src => typeof src === 'string' && !src.startsWith('#'))
    .forEach(src => {
      const img = new Image();
      img.src = src;
      doc.imagesList.push(img);
    });
};

window.swapImage = (...args) => {
  const list = [];
  // Reseteamos como hacía el original:
  document.imagesListSource = [];

  chunkBy3(args).forEach(([id, _unused, newSrc]) => {
    const el = window.findObj(id);
    if (!el) return;

    document.imagesListSource.push(el);
    el.oSrc ??= el.src; // guarda el src original si no existía
    el.src = newSrc;    // pisa con el nuevo source
  });
};

window.findObj = (id, doc = document) => {
  // Soporte básico para "miId?frameName" (legado)
  const qIdx = id.indexOf('?');
  if (qIdx > 0 && window.parent?.frames?.length) {
    const frameName = id.substring(qIdx + 1);
    try { doc = window.parent.frames[frameName].document; } catch { /* CORS u otro error */ }
    id = id.substring(0, qIdx);
  }

  // 1) Por ID
  const byId = doc.getElementById?.(id);
  if (byId) return byId;

  // 2) Por name (útil para inputs en formularios antiguos)
  const byName = doc.getElementsByName?.(id);
  if (byName?.length) return byName[0];

  // 3) Búsqueda en formularios por name (compat muy básica al original)
  for (let i = 0; i < (doc.forms?.length ?? 0); i++) {
    const candidate = doc.forms[i][id];
    if (candidate) return candidate;
  }

  return null;
};

window.showHideLayers = (...args) => {
  chunkBy3(args).forEach(([id, _unused, visArg]) => {
    const el = document.getElementById(id);
    if (!el) return;

    // Normalizamos 'show'/'hide' → 'visible'/'hidden'
    let vis = visArg;
    if (vis === 'show') vis = 'visible';
    else if (vis === 'hide') vis = 'hidden';

    // Si el elemento no tiene style, evitamos error (raro, pero por las dudas)
    el.style && (el.style.visibility = vis);
  });
};

document.addEventListener('DOMContentLoaded', function () {

  // --- Poner año en footer ---
  const y = new Date().getFullYear();
  const el1 = document.getElementById('year');
  const el2 = document.getElementById('year-2');
  const el3 = document.getElementById('year-3');
  if (el1) el1.textContent = y;
  if (el2) el2.textContent = y;
  if (el3) el3.textContent = y;

  // --- Galería: abrir modal al click de miniatura ---
  const gallery = document.getElementById('gallery');
  const modal = document.getElementById('gallery-modal');
  const modalImg = modal ? modal.querySelector('.modal-img') : null;
  const caption = modal ? modal.querySelector('#modal-caption') : null;
  const closeBtn = modal ? modal.querySelector('.modal-close') : null;
  const prevBtn = modal ? modal.querySelector('.modal-prev') : null;
  const nextBtn = modal ? modal.querySelector('.modal-next') : null;

  let thumbs = [];
  let currentIndex = -1;

  function refreshThumbs() {
    thumbs = Array.from(document.querySelectorAll('#gallery .thumb img'));
  }
  refreshThumbs();

  function openModal(index) {
    const img = thumbs[index];
    if (!img || !modal) return;
    const full = img.dataset.full || img.src;
    modalImg.src = full;
    modalImg.alt = img.alt || '';
    caption.textContent = img.closest('figure')?.querySelector('figcaption')?.textContent || '';
    modal.setAttribute('aria-hidden', 'false');
    currentIndex = index;
    // focus for accessibility
    closeBtn?.focus();
  }

  function closeModal() {
    modal.setAttribute('aria-hidden', 'true');
    modalImg.src = '';
    currentIndex = -1;
  }

  function showNext(delta = 1) {
    if (thumbs.length === 0) return;
    let next = currentIndex + delta;
    if (next < 0) next = thumbs.length - 1;
    if (next >= thumbs.length) next = 0;
    openModal(next);
  }

  if (gallery) {
    gallery.addEventListener('click', (e) => {
      const img = e.target.closest('img');
      if (!img) return;
      const list = Array.from(document.querySelectorAll('#gallery .thumb img'));
      const index = list.indexOf(img);
      if (index >= 0) openModal(index);
    });
  }

  // botones modal
  closeBtn?.addEventListener('click', closeModal);
  prevBtn?.addEventListener('click', () => showNext(-1));
  nextBtn?.addEventListener('click', () => showNext(1));

  // teclado: Esc, flechas
  document.addEventListener('keydown', (e) => {
    if (!modal || modal.getAttribute('aria-hidden') === 'true') return;
    if (e.key === 'Escape') closeModal();
    if (e.key === 'ArrowRight') showNext(1);
    if (e.key === 'ArrowLeft') showNext(-1);
  });

  // click fuera de la imagen cierra
  modal?.addEventListener('click', (e) => {
    if (e.target === modal) closeModal();
  });

  // Actualizar thumbs si el DOM cambia (por ejemplo al cargar dinámicamente)
  const observer = new MutationObserver(() => refreshThumbs());
  const galleryEl = document.getElementById('gallery');
  if (galleryEl) observer.observe(galleryEl, { childList: true, subtree: true });

  // --- Contact form: simple validación y demo de envío ---
  const form = document.getElementById('contact-form');
  if (form) {
    form.addEventListener('submit', (e) => {
      e.preventDefault();
      // validación básica
      const name = form.querySelector('#name').value.trim();
      const email = form.querySelector('#email').value.trim();
      const message = form.querySelector('#message').value.trim();
      if (!name || !email || !message) {
        alert('Por favor completa todos los campos.');
        return;
      }
      // En un TP bien se enviaría a un servidor; acá simulamos el envío.
      alert('Mensaje enviado (simulado). Gracias — ' + name);
      form.reset();
    });
  }

});



/*Sofia Mora*/ 
document.querySelectorAll('.gallery-item').forEach(item => {
    item.addEventListener('click', () => {
        const imageSrc = item.querySelector('img').src;
          const obraLink = item.dataset.link; 
        openModal(imageSrc, obraLink);
    });
});


// Función para abrir un modal con la imagen seleccionada
function openModal(imageSrc, obraLink) {
    // nuevo elemento <div> para el modal
    const modal = document.createElement('div');
    modal.classList.add('modal');  // Asigne la clase 'modal' al div para darle estilo
    
    // Define el contenido HTML del modal (que era un div), incluyendo un botón de cierre y la imagen
    modal.innerHTML = `
    <div class="modal-content">
        <span class="close">&times;</span>  <!-- Icono de cierre (×) -->
        <img src="${imageSrc}" alt="Imagen de proyecto" />  <!-- Imagen seleccionada con la URL proporcionada -->
        ${obraLink ? `<a href="${obraLink}" target="_blank" class="modal-link">Visitar obra</a>` : ''}
    </div>
`;
    
    document.querySelector('.sm-body').appendChild(modal);
    modal.querySelector('.close').onclick = () => modal.remove();
    modal.onclick = () => modal.remove();
}

