<script lang="ts">
    import Card from "$lib/components/Card.svelte";
    import Icon from "$lib/components/Icon.svelte";
    import melBandsImage from '$lib/assets/256MelBands.png';
    import evoSimImage from '$lib/assets/EvoSim.png';
    import portfolioImage from '$lib/assets/Portfolio.png';
</script>

<div class="max-w-7xl mx-5 mb-6 lg:mx-6 xl:mx-auto">
    <header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 text-main-300 py-5 font-semibold">
        <a href="/" class="inline-flex items-center gap-2 hover:text-main-100">
            <Icon name="arrow-left" class="w-3 h-3 sm:w-4 sm:h-4" />
            <span class="font-semibold uppercase">Home</span>
        </a>
    </header>
    <header class="pb-4 flex items-center gap-4 border-b border-main-100 text-4xl xl:text-5xl font-extrabold tracking-wide text-white">All Projects</header>
    <ul class="grid grid-cols-1 gap-y-4 group/list transition-all mt-6">
        <li class="lg:hover:!opacity-100 lg:group-hover/list:opacity-50">
            <Card 
                link="edgeML"
                image={melBandsImage}
                title="Machine Learning on Edge Devices" 
                description="A self-contained system that runs a quantized respiratory disease model on a Google Coral Edge TPU, capable of performing real-time audio analysis for health monitoring." 
                tags={['Python', 'C++', 'TensorFlow', 'TFLite', 'Google Coral', 'ESP32', 'Raspberry Pi Pico', '3D Printing']}
            >
            </Card>
        </li>

        <li class="lg:hover:!opacity-100 lg:group-hover/list:opacity-50">
            <Card 
                link="evolutionSim"
                image={evoSimImage}
                title="AI Evolution Simulator" 
                description="An agent-based evolution simulator built in C++ within a professors game engine (AftrBurner). Autonomous agents with unique genetic traits for behavior (bravery, socialness) and physics (size, speed) evolve through natural selection in a dynamic ecosystem with predators and resources." 
                tags={['C++', 'AI State Machines', 'Genetic Algorithms', 'ImGui', 'ImPlot']}
            >
            </Card>
        </li>

        <!--- Comment out shell project card for now.
            <li class="lg:hover:!opacity-100 lg:group-hover/list:opacity-50">
                <Card 
                    link="cppShell"
                    title="Advanced C++ Shell" 
                    description="A valgrind-clean POSIX-like shell and interpreter written in C/++, Flex, and Bison. Features a standard fork/exec loop, a full parser that builds an Abstract Syntax Tree (AST), and support for control structures that turn it into a Turing-complete language." 
                    tags={['C++', 'C', 'Flex', 'Bison']}
                >
                </Card>
            </li>
        -->

        <li class="lg:hover:!opacity-100 lg:group-hover/list:opacity-50">
            <Card 
                link="portfolio"
                image={portfolioImage}
                title="Personal Portfolio & Design System" 
                description="A fully responsive personal portfolio built from scratch with SvelteKit, TypeScript, and Tailwind CSS. It features a modular, component-based architecture and includes a self-documented design system for consistent maintainable expansion." 
                tags={['SvelteKit', 'TypeScript', 'Tailwind CSS', 'Component Design']}
            >
            </Card>
        </li>
    </ul>
</div>