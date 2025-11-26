<script lang="ts">
    import Button from '$lib/components/Button.svelte';
    import Icon from '$lib/components/Icon.svelte';
    export let images: { src: string; alt: string }[] = [];

    let currentIndex = 0;

    const next = () => {
    currentIndex = (currentIndex + 1) % images.length;
    };

    const prev = () => {
    currentIndex = (currentIndex - 1 + images.length) % images.length;
    };
</script>

<div class="relative w-full group">
  <div class="relative w-full aspect-video overflow-hidden rounded-lg border border-neutral-800 bg-neutral-900">
    {#each images as image, i}
      <div 
        class="absolute inset-0 w-full h-full transition-opacity duration-500 ease-in-out flex items-center justify-center"
        class:opacity-100={i === currentIndex}
        class:opacity-0={i !== currentIndex}
        class:pointer-events-none={i !== currentIndex}
      >
        <img 
          src={image.src} 
          alt={image.alt} 
          class="w-full h-full object-contain"
        />
      </div>
    {/each}

    <Button onclick={prev} variant="custom" size="icon" class="border border-neutral-400 text-neutral-400 bg-transparent hover:bg-main-100 absolute left-6 top-1/2 -translate-y-1/2 !rounded-full w-6 h-6"><Icon name="arrow-left"/></Button>
    <Button onclick={next} variant="custom" size="icon" class="border border-neutral-400 text-neutral-400 bg-transparent hover:bg-main-100 absolute right-6 top-1/2 -translate-y-1/2 !rounded-full w-6 h-6"><Icon name="arrow-right"/></Button>
  </div>

  <div class="mt-3 flex flex-col items-center gap-2">
    <div class="flex gap-2">
      {#each images as _, i}
        <button 
          on:click={() => currentIndex = i}
          class="w-3 h-3 rounded-full transition-colors {i === currentIndex ? 'bg-main-100' : 'bg-neutral-600 hover:bg-neutral-400'}"
          aria-label="Go to slide {i + 1}"
        ></button>
      {/each}
    </div>
    <p class="text-sm text-neutral-400 font-mono text-center">
      {images[currentIndex].alt}
    </p>
  </div>
</div>