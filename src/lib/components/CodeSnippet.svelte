<script lang="ts">
	import hljs from 'highlight.js';
	import 'highlight.js/styles/atom-one-dark.css';
	import { onMount } from 'svelte';
	import { slide } from 'svelte/transition';
	import Button from '$lib/components/Button.svelte';
	import Icon from '$lib/components/Icon.svelte';

	const {
		code = '',
		language = 'plaintext',
		title = '',
		startExpanded = false
	} = $props();

	let highlightedCode = $state('');
	let isExpanded = $state(startExpanded);

	onMount(() => {
		try {
			if (language && hljs.getLanguage(language)) {
				highlightedCode = hljs.highlight(code, { language }).value;
			} else {
				highlightedCode = hljs.highlightAuto(code).value;
			}
		} catch (e) {
			console.error('Highlight.js error:', e);
			highlightedCode = code; // Fallback
		}
	});
</script>

<div class="code-snippet my-6 rounded-lg border border-neutral-700 overflow-hidden">
	{#if title}
		<div class="bg-neutral-800 px-4 py-2 border-b border-neutral-700 flex justify-between items-center">
			<p class="text-sm font-semibold text-neutral-300">{title}</p>
			<Button
				variant="ghost"
				size="sm"
				class="text-xs !gap-2"
				onclick={() => (isExpanded = !isExpanded)}
				aria-expanded={isExpanded}
			>
				<span>{isExpanded ? 'Hide' : 'Show'} Code</span>
				<Icon name="chevron-down" class={`w-3 h-3 transition-transform duration-200 ${isExpanded ? 'rotate-180' : ''}`} />
			</Button>
		</div>
	{/if}

	{#if isExpanded}
		<div transition:slide={{ duration: 200 }}>
			<pre class="bg-neutral-900 p-4 overflow-x-auto"><code class="text-sm">{@html highlightedCode || '<p>Loading code...</p>'}</code></pre>
		</div>
	{/if}
</div>