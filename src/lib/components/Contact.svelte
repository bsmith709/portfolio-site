<script lang="ts">
    import Button from './Button.svelte';
    import Icon from './Icon.svelte';
</script>

<header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 sm:text-lg">
    <h4 class="text-main-100 font-semibold uppercase tracking-wide">Contact</h4>
</header>

<p class="text-neutral-200 leading-relaxed mb-4 sm:text-lg">
   I'm currently seeking new opportunities and am always open to connecting with fellow developers, recruiters, and creative thinkers. If you have a project in mind, a question about my work, or just want to say hello, please don't hesitate to reach out.
</p>

<div class="flex items-center justify-center mt-4 sm:mt-6">
    <a href="mailto:blakesmithdev@outlook.com">
        <Button variant="primary" size="md">
            <span>Get In Touch</span>
            <Icon name="arrow-right" class="w-4 h-4" />
        </Button>
    </a>
</div>