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
            // This creates a horizontal line in the middle of the viewport
            rootMargin: '-50% 0px -50% 0px',
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

<div class="max-w-7xl mx-auto px-3 py-6">
    <a href="/#projects" class="text-main-300 hover:text-main-100 mb-8 inline-flex items-center gap-2 font-semibold">
        <Icon name="arrow-left" class="w-4 h-4" />
        Back to Projects
    </a>

    <div class="lg:grid lg:grid-cols-6 lg:gap-6">
        <div class="lg:col-span-5">
            <article bind:this={articleEl} class="prose prose-lg prose-invert max-w-none">
                <data.content/>
            </article>
        </div>
        <div class="lg:col-span-1">
            <TableOfContents {links} {activeId} />
        </div>
    </div>
</div>