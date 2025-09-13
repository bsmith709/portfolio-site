<script lang="ts">
	import hljs from 'highlight.js';
	import 'highlight.js/styles/atom-one-dark.css'; // Dark theme for code
	import { onMount } from 'svelte';

	const { code = '', language = 'plaintext', title = '' } = $props();

	let highlightedCode = $state('');

	// We need to highlight the code on the client-side after the component mounts
	onMount(() => {
		try {
			if (language && hljs.getLanguage(language)) {
				highlightedCode = hljs.highlight(code, { language }).value;
			} else {
				highlightedCode = hljs.highlightAuto(code).value;
			}
		} catch (e) {
			console.error('Highlight.js error:', e);
			highlightedCode = code; // Fallback to unhighlighted code
		}
	});
</script>

<div class="code-snippet my-6 rounded-lg border border-neutral-700 overflow-hidden">
	{#if title}
		<div class="bg-neutral-800 px-4 py-2 border-b border-neutral-700">
			<p class="text-sm font-semibold text-neutral-300">{title}</p>
		</div>
	{/if}
	<pre class="bg-neutral-900 p-4 overflow-x-auto"><code class="text-sm">{@html highlightedCode || '<p>Loading code...</p>'}</code></pre>
</div>