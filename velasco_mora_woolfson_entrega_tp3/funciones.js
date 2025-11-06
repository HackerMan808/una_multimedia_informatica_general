export class GaleriaHorizontal {
  constructor(selector, options = {}) {
    this.container = document.querySelector(selector);
    if (!this.container) return;

    this.wrapper = this.container.querySelector(".r-carrusel");
    this.speed = options.speed || 1.2; // sensibilidad del scroll
    this.smooth = options.smooth || 0.08; // suavizado
    this.targetScroll = 0;
    this.currentScroll = 0;

    this._bindEvents();
    this._update();
  }

  _bindEvents() {
    this.container.addEventListener("wheel", e => {
      e.preventDefault();
      this.targetScroll += e.deltaY * this.speed;
      this._clampScroll();
    }, { passive: false });
  }

  _clampScroll() {
    const maxScroll = this.wrapper.scrollWidth - this.container.clientWidth;
    this.targetScroll = Math.max(0, Math.min(this.targetScroll, maxScroll));
  }

  _update() {
    this.currentScroll += (this.targetScroll - this.currentScroll) * this.smooth;
    this.wrapper.style.transform = `translateX(-${this.currentScroll}px)`;
    requestAnimationFrame(this._update.bind(this));
  }
}

/* funciones.js
   - Aquí va todo el JavaScript del sitio (galería, fecha en pies, validaciones, etc).
   - No poner código JS en los HTML.
*/

document.addEventListener('DOMContentLoaded', function () {

  // Galeria Rucupashi
  new GaleriaHorizontal("#carrusel", { speed: 1.1, smooth: 0.1 });

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

/*Carla Woiolfson*/

document.addEventListener('DOMContentLoaded', function () {
  const carruselElements = document.querySelectorAll('.cw-carrusel > *');
  const btnPrev = document.querySelector('.cw-carrusel-btn.prev');
  const btnNext = document.querySelector('.cw-carrusel-btn.next');
  let currentIndex = 0;
  let intervalo = null;

  function mostrarElemento(index) {
    carruselElements.forEach((el, i) => {
      el.classList.toggle('active', i === index);

      if (el.tagName === 'VIDEO') {
        el.pause();
        el.currentTime = 0;
        if (i === index) {
          el.play().catch(e => {
            // Ignora errores por autoplay bloqueado
          });
        }
      }
    });
  }

  function siguiente() {
    currentIndex = (currentIndex + 1) % carruselElements.length;
    mostrarElemento(currentIndex);
  }

  function anterior() {
    currentIndex = (currentIndex - 1 + carruselElements.length) % carruselElements.length;
    mostrarElemento(currentIndex);
  }

  function reiniciarIntervalo() {
    clearInterval(intervalo);
    intervalo = setInterval(siguiente, 3000);
  }

  // Inicializa
  mostrarElemento(currentIndex);
  intervalo = setInterval(siguiente, 3000);

  // Botones
  btnNext?.addEventListener('click', () => {
    siguiente();
    reiniciarIntervalo();
  });

  btnPrev?.addEventListener('click', () => {
    anterior();
    reiniciarIntervalo();
  });
});

