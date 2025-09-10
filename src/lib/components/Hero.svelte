<script lang="ts">
	import Button from '$lib/components/Button.svelte';
    import Icon from '$lib/components/Icon.svelte';
</script>

<header>
	<h1 class="text-gradient-main text-5xl font-bold">Blake Smith</h1>
	<h2 class="text-2xl text-gradient-secondary -mt-1 font-semibold">Software Engineer</h2>
    <h3 class="text-lg text-neutral-100 -mt-2">Machine Learning | Embedded Systems | Full Stack</h3>
</header>

<p class="mt-4 text-neutral-200">
    I’m a motivated builder with a passion for engineering simple solutions to complex problems. From architecting AI simulations in C++ to deploying Machine Learning models in constrained environments, I thrive on solving challenging problems.
</p>
<span class="text-sm mt-1 text-neutral-300 block leading-tight">
    Senior at Ohio University, graduating December 2025 with a B.S. in Computer Science (GPA 3.8+).
</span>

<div class="flex justify-between items-center mt-6 mr-2">
    <ul class="flex items-center gap-2">
        <li>
            <a href="https://github.com/bsmith709"><Button variant="link" size="icon" class="w-6 h-6"><Icon name="github"/></Button></a>
        </li>
        <li>
            <a href="https://app.joinhandshake.com/profiles/pcbj65"><Button variant="link" size="icon" class="w-6 h-6"><Icon name="handshake"/></Button></a>
        </li>
    </ul>
    <a href="/test.pdf" download="Blake-Smith-Resume.pdf"><Button variant="primary" size="sm"><span>Resume</span><Icon name="arrow-down-tray" class="w-3 h-3"/></Button></a>
</div>
