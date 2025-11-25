<script lang="ts">
    import Button from '$lib/components/Button.svelte';
    import Hero from '$lib/components/Hero.svelte';
    import About from '$lib/components/About.svelte';
    import Experience from '$lib/components/Experience.svelte';
	import Projects from '$lib/components/Projects.svelte';
    import Contact from '$lib/components/Contact.svelte';
</script>
<div class="min-h-screen w-full  max-w-7xl mx-auto py-7 lg:grid lg:grid-cols-2 lg:grid-cols-[1fr_1.5fr] lg:gap-8 lg:py-0 xl:gap-10">
    <header id="hero" class="mb-9 lg:mb-0 lg:sticky lg:top-0 lg:flex lg:max-h-screen lg:w-full lg:flex-col lg:justify-between lg:py-9">
        <Hero />
    </header>
    <main class="lg:mt-8">
        <section id="about" class="mb-8">
            <About />
        </section>

        <section id="experience" class="mb-8">
            <Experience />
        </section>

        <section id="projects" class="mb-8">
            <Projects />
        </section>

        <section id="contact" class="mb-8">
            <Contact />
        </section>

        <footer class="w-full border-t border-neutral-800 text-center py-4 text-sm text-neutral-500">
            <a href="/design-system" class="hover:text-main-100 transition-colors inline-flex items-center gap-1 mt-1">
                <Button variant="link" class="text-neutral-200">
                    View Design System
                </Button>
            </a>
            <p>Built with SvelteKit & TailwindCSS.</p>
            <p>Design and layout heavily inspired by the work of Brittany Chiang.</p>
            <p>© {new Date().getFullYear()} Blake Smith. All rights reserved.</p>
        </footer>
    </main>
</div> 
