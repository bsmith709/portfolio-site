<script lang="ts">
    import Button from '$lib/components/Button.svelte';
    import Hero from '$lib/components/Hero.svelte';
    import About from '$lib/components/About.svelte';
	import Projects from '$lib/components/Projects.svelte';
	import Skills from '$lib/components/Skills.svelte';
    import Contact from '$lib/components/Contact.svelte';
</script>
<div class="w-full max-w-7xl mx-auto lg:grid lg:grid-cols-2 lg:gap-10">
    <main class="min-h-screen w-full max-w-7xl mx-auto px-5 py-6 sm:p-5 lg:p-6">
        <section id="hero" class="mb-9">
            <Hero />
        </section>

        <section id="about" class="mb-8">
            <About />
        </section>

        <section id="projects" class="mb-8">
            <Projects />
        </section>

        <section id="skills" class="mb-8">
            <Skills />
        </section>

        <section id="contact" class="mb-8">
            <Contact />
        </section>

        <footer class="w-full border-t border-neutral-800 text-center py-4 text-sm text-neutral-500">
            <p>© {new Date().getFullYear()} Blake Smith. All rights reserved.</p>
            <p>Built with SvelteKit & TailwindCSS.</p>
            <a href="/design-system" class="text-neutral-400 hover:text-main-100 transition-colors inline-flex items-center gap-1 mt-1">
                <Button variant="link">
                    View Design System
                </Button>
            </a>
        </footer>
    </main>
</div> 
