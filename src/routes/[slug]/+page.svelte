<script lang="ts">
    import { onMount, onDestroy } from 'svelte';
    import TableOfContents from '$lib/components/TableOfContents.svelte';
	import Icon from '$lib/components/Icon.svelte';
	
    const { data } = $props();

    let articleEl: HTMLElement;
    let links: { text: string; id: string; level: number }[] = $state([]);
    let activeId = $state(''); // State to hold the active heading ID

    let observer: IntersectionObserver;

    onMount(() => {
        // Find all h2 and h3 headings inside the article
		const headings = articleEl.querySelectorAll('h2, h3');
		
		const newLinks: typeof links = [];
		headings.forEach(heading => {
			const id = heading.textContent?.toLowerCase().replace(/\s+/g, '-').replace(/[^\w-]+/g, '') ?? '';
			heading.id = id;

			newLinks.push({
				text: heading.textContent ?? '',
				id: id,
				level: heading.tagName === 'H2' ? 2 : 3
			});
		});
		links = newLinks;

                // --- IntersectionObserver Logic ---
        const observerCallback = (entries: IntersectionObserverEntry[]) => {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    activeId = entry.target.id;
                }
            });
        };

        observer = new IntersectionObserver(observerCallback, {
            // This creates a horizontal line in the top of the viewport
            rootMargin: '-5% 0px -95% 0px',
        });

        headings.forEach(heading => observer.observe(heading));
    });

    onDestroy(() => {
        // Clean up the observer when the component is destroyed
        if (observer) {
            observer.disconnect();
        }
    });
</script>


<div class="max-w-7xl mx-auto mb-6">
    <a href="/" class="text-main-300 hover:text-main-100 my-5 inline-flex items-center gap-2 font-semibold lg:text-2xl">
        <Icon name="arrow-left" class="w-4 h-4" />
        Back
    </a>

    <div class="lg:grid lg:grid-cols-4 lg:gap-6">
        <div class="lg:col-span-3 mb-15">
            <article bind:this={articleEl} class="prose lg:prose-lg prose-invert max-w-none">
                <data.content/>
            </article>
        </div>
        <div class="lg:col-span-1">
            <TableOfContents {links} {activeId} />
        </div>
    </div>
</div>