<script lang="ts">
	import Button from '$lib/components/Button.svelte';
    import Icon from '$lib/components/Icon.svelte';
</script>
<div>
    <header>
        <h1 class="text-gradient-main text-5xl font-bold inline">Blake Smith</h1>
        <h2 class="text-2xl text-gradient-secondary mt-1 font-semibold sm:text-3xl">Software Engineer</h2>
        <h3 class="text-lg text-neutral-100 -mt-2 sm:text-xl">Full Stack | Machine Learning | Embedded Systems</h3>
    </header>

    <div>
        <p class="mt-4 text-neutral-200 sm:text-lg leading-relaxed">
            I’m a motivated builder with a passion for engineering simple solutions to complex problems.
        </p>
        <span class="text-sm mt-1 text-neutral-300 block leading-tight sm:text-base sm:leading-normal">
            Senior at Ohio University, graduating December 2025 with a B.S. in Computer Science (GPA 3.8+).
        </span>
    </div>

    <div class="flex justify-between items-center mt-6 mr-2 lg:mt-7">
        <ul class="flex items-center gap-2 sm:gap-4">
            <li>
                <a href="https://github.com/bsmith709" aria-label="View my GitHub profile"><Button variant="link" size="icon" class="w-6 h-6 sm:w-7 sm:h-7"><Icon name="github"/></Button></a>
            </li>
            <li>
                <a href="https://app.joinhandshake.com/profiles/pcbj65" aria-label="View my handshake profile"><Button variant="link" size="icon" class="w-6 h-6 sm:w-7 sm:h-7"><Icon name="handshake"/></Button></a>
            </li>
            <li>
                <a href="https://www.linkedin.com/in/blake-smith-343398265" aria-label="View my LinkedIn profile"><Button variant="link" size="icon" class="w-6 h-6 sm:w-7 sm:h-7"><Icon name="linkedin"/></Button></a>
            </li>
        </ul>
        <a href="/Blake_Smith_Resume.pdf" target="_blank" class="noopener noreferrer" aria-label="View my resume"><Button variant="primary" size="sm" class="sm:h-7 sm:px-4 sm:text-base sm:gap-2"><span>View Résumé</span><Icon name="arrow-up-right" class="w-2 h-2 sm:w-3 sm:h-3"/></Button></a>
    </div>
</div>
