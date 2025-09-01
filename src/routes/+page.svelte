<script lang="ts">
  // An array of Tailwind CSS background color classes.
  // Using the full class name ensures Tailwind's JIT compiler will include them in the final CSS.
  const palettes = [
    {
      name: 'Main Colors',
      colors: [
        { name: 'Main-100', class: 'bg-main-100' },
        { name: 'Main-200', class: 'bg-main-200' },
        { name: 'Main-300', class: 'bg-main-300' },
        { name: 'Main-400', class: 'bg-main-400' },
        { name: 'Main-500', class: 'bg-main-500' },
        { name: 'Main-600', class: 'bg-main-600' },
        { name: 'Main-700', class: 'bg-main-700' },
        { name: 'Main-800', class: 'bg-main-800' },
        { name: 'Main-900', class: 'bg-main-900' }
      ]
    },
    {
      name: 'Secondary Colors',
      colors: [
        { name: 'Secondary-100', class: 'bg-secondary-100' },
        { name: 'Secondary-200', class: 'bg-secondary-200' },
        { name: 'Secondary-300', class: 'bg-secondary-300' },
        { name: 'Secondary-400', class: 'bg-secondary-400' },
        { name: 'Secondary-500', class: 'bg-secondary-500' },
        { name: 'Secondary-600', class: 'bg-secondary-600' },
        { name: 'Secondary-700', class: 'bg-secondary-700' },
        { name: 'Secondary-800', class: 'bg-secondary-800' },
        { name: 'Secondary-900', class: 'bg-secondary-900' }
      ]
    },
    {
      name: 'Semantic Colors',
      colors: [
        { name: 'Success-100', class: 'bg-semantic-green-100' },
        { name: 'Success-200', class: 'bg-semantic-green-200' },
        { name: 'Success-300', class: 'bg-semantic-green-300' },
        { name: 'Success-400', class: 'bg-semantic-green-400' },
        { name: 'Success-500', class: 'bg-semantic-green-500' },
        { name: 'Success-600', class: 'bg-semantic-green-600' },
        { name: 'Success-700', class: 'bg-semantic-green-700' },
        { name: 'Success-800', class: 'bg-semantic-green-800' },
        { name: 'Success-900', class: 'bg-semantic-green-900' },

        { name: 'Warning-100', class: 'bg-semantic-yellow-100' },
        { name: 'Warning-200', class: 'bg-semantic-yellow-200' },
        { name: 'Warning-300', class: 'bg-semantic-yellow-300' },
        { name: 'Warning-400', class: 'bg-semantic-yellow-400' },
        { name: 'Warning-500', class: 'bg-semantic-yellow-500' },
        { name: 'Warning-600', class: 'bg-semantic-yellow-600' },
        { name: 'Warning-700', class: 'bg-semantic-yellow-700' },
        { name: 'Warning-800', class: 'bg-semantic-yellow-800' },
        { name: 'Warning-900', class: 'bg-semantic-yellow-900' },

        { name: 'Error-100', class: 'bg-semantic-red-100' },
        { name: 'Error-200', class: 'bg-semantic-red-200' },
        { name: 'Error-300', class: 'bg-semantic-red-300' },
        { name: 'Error-400', class: 'bg-semantic-red-400' },
        { name: 'Error-500', class: 'bg-semantic-red-500' },
        { name: 'Error-600', class: 'bg-semantic-red-600' },
        { name: 'Error-700', class: 'bg-semantic-red-700' },
        { name: 'Error-800', class: 'bg-semantic-red-800' },
        { name: 'Error-900', class: 'bg-semantic-red-900' }
      ]
    },
    {
      name: 'Neutral Colors',
      colors: [
        { name: 'neutral-100', class: 'bg-neutral-100' },
        { name: 'neutral-200', class: 'bg-neutral-200' },
        { name: 'neutral-300', class: 'bg-neutral-300' },
        { name: 'neutral-400', class: 'bg-neutral-400' },
        { name: 'neutral-500', class: 'bg-neutral-500' },
        { name: 'neutral-600', class: 'bg-neutral-600' },
        { name: 'neutral-700', class: 'bg-neutral-700' },
        { name: 'neutral-800', class: 'bg-neutral-800' },
        { name: 'neutral-900', class: 'bg-neutral-900' }
      ]
    }
  ];

</script>

<div class="bg-neutral-900 min-h-screen w-full font-serif">
  <div class="max-w-7xl mx-auto p-4 sm:p-6 lg:p-8">

    <!-- Page header -->
    <header class="text-center">
      <h1 class="text-4xl sm:text-5xl font-extrabold tracking-tight text-main-300">
        Color Palette
      </h1>
    </header>

    <!-- Responsive grid for the color palettes -->
     {#each palettes as palette}
      <h2 class="text-2xl font-semibold text-neutral-100 mb-4">{palette.name}</h2>
      <div class="grid grid-cols-9 gap-6 sm:gap-8 mb-12">
        {#each palette.colors as color}
          <button 
            class="relative group"
            aria-label={color.name}
            tabindex="0"
          >

            <span class="absolute bottom-full mb-2 left-1/2 -translate-x-1/2 whitespace-nowrap bg-neutral-900 text-white text-xs font-semibold px-2 py-1 rounded-md opacity-0 group-hover:opacity-100 group-focus:opacity-100 transition-opacity duration-300 ease-in-out pointer-events-none">
              {color.name}
            </span>

            <!-- The main color splotch -->
            <div 
              class="aspect-square shadow-lg transition-all duration-300 ease-in-out group-hover:scale-110 group-hover:shadow-xl group-focus:scale-110 group-focus:shadow-xl {color.class}"
            ></div>
            
            <!-- A subtle border effect on hover/focus -->
            <div class="absolute inset-0 border-4 border-transparent group-hover:border-white/50 group-focus:border-white/50 transition-all duration-300"></div>
          </button>
        {/each}
      </div>
    {/each}

  </div>

</div>