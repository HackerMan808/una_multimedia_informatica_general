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

// Inicialización
document.addEventListener("DOMContentLoaded", () => {
  new GaleriaHorizontal("#carrusel", { speed: 1.1, smooth: 0.1 });
});
