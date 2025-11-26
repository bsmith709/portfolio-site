<script lang="ts">
    import Button from './Button.svelte';
    import Icon from './Icon.svelte';
</script>

<header class="sticky top-0 z-10 -mx-6 px-6 py-4 mb-4 backdrop-blur bg-neutral-900/75 sm:text-lg">
    <h4 class="text-gradient-main font-semibold uppercase tracking-wide w-fit translate-y-0.75">Contact</h4>
</header>

<p class="text-neutral-200 leading-relaxed mb-4 sm:text-lg">
   I'm currently seeking new opportunities and am always open to connecting with fellow developers, recruiters, and creative thinkers. If you have a project in mind, a question about my work, or just want to say hello, please don't hesitate to reach out.
</p>

<div class="flex items-center justify-center mt-4 sm:mt-6">
    <a href="mailto:blakesmithdev@outlook.com">
        <Button variant="primary" size="sm" class="sm:h-7 sm:px-4 sm:text-base sm:gap-2">
            <span>Get In Touch</span>
            <Icon name="arrow-right" class="w-3 h-3 sm:w-4 sm:h-4" />
        </Button>
    </a>
</div>