<script lang="ts">
    import Card from '$lib/components/Card.svelte';
    import Icon from '$lib/components/Icon.svelte';
    import Button from '$lib/components/Button.svelte';
    import melBandsImage from '$lib/assets/256MelBands.png';
    import evoSimImage from '$lib/assets/EvoSim.png';
</script>

<header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 sm:text-lg">
    <h4 class="text-main-100 font-semibold uppercase tracking-wide">Projects</h4>
</header>

<div class="grid grid-cols-1 gap-y-6">
    <Card 
        image={melBandsImage}
        title="Machine Learning on Edge Devices" 
        description="A self-contained system that runs a quantized respiratory disease model on a Google Coral Edge TPU, capable of performing real-time audio analysis for health monitoring." 
        tags={['Python', 'C++', 'TensorFlow', 'TFLite', 'Google Coral', 'ESP32', 'Raspberry Pi Pico', '3D Printing']}
    >
        {#snippet actions()}
        <Button 
            variant="link" 
            class="text-sm @md:text-base @xl:text-lg @4xl:text-xl"
        >
            Learn More
            <Icon name="link" class="h-3 w-3 sm:h-4 sm:w-4" />
        </Button>
        {/snippet}
    </Card>

    <Card 
        image={evoSimImage}
        title="AI Evolution Simulator" 
        description="An agent-based evolution simulator built in C++ within a professors game engine (AftrBurner). Autonomous agents with unique genetic traits for behavior (bravery, socialness) and physics (size, speed) evolve through natural selection in a dynamic ecosystem with predators and resources." 
        tags={['C++', 'AI State Machines', 'Genetic Algorithms', 'ImGui', 'ImPlot']}
    >
        {#snippet actions()}
        <Button 
            variant="link" 
            class="text-sm @md:text-base @xl:text-lg @4xl:text-xl"
        >
            Learn More
            <Icon name="link" class="h-3 w-3 sm:h-4 sm:w-4" />
        </Button>
        {/snippet}
    </Card>

    <Card 
        image={evoSimImage}
        title="Personal Portfolio & Design System" 
        description="A fully responsive personal portfolio built from scratch with SvelteKit, TypeScript, and Tailwind CSS. It features a modular, component-based architecture and includes a self-documented design system for consistent maintainable expansion." 
        tags={['SvelteKit', 'TypeScript', 'Tailwind CSS', 'Component Design']}
    >
        {#snippet actions()}
        <Button 
            variant="link" 
            class="text-sm @md:text-base @xl:text-lg @4xl:text-xl"
        >
            Learn More
            <Icon name="link" class="h-3 w-3 sm:h-4 sm:w-4" />
        </Button>
        {/snippet}
    </Card>
</div>