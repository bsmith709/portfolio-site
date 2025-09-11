<script lang="ts">
    import Icon from '$lib/components/Icon.svelte';
    import Button from '$lib/components/Button.svelte';
    import Card from '$lib/components/Card.svelte';
    import Hero from '$lib/components/Hero.svelte';
    import About from '$lib/components/About.svelte';
	import Projects from '$lib/components/Projects.svelte';
	import Skills from '$lib/components/Skills.svelte';
    import Contact from '$lib/components/Contact.svelte';
</script>

<main class="min-h-screen w-full max-w-7xl mx-auto px-5 py-6 sm:p-5 lg:p-6">
    <section id="hero" class="mb-10">
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
</main>
