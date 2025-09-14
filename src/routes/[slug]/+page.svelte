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
            // This creates a horizontal line near the top of the viewport
            rootMargin: '-10% 0px -70% 0px',
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


<div class="max-w-7xl mx-5 mb-6 lg:mx-6 xl:mx-auto">
    <div class="w-full backdrop-blur bg-neutral-900/75 text-main-300 py-5 font-semibold sm:text-lg lg:text-xl lg:sticky lg:top-0 lg:-mx-10 lg:px-10">
        <a href="/" class="inline-flex items-center gap-2 hover:text-main-100">
            <Icon name="arrow-left" class="w-3 h-3 sm:w-4 sm:h-4" />
            <span class="font-semibold uppercase">Home</span>
        </a>
    </div>

    <div class="lg:grid lg:grid-cols-4 lg:gap-8 xl:gap-6">
        <div class="lg:col-span-3 lg:mb-15">
            <article bind:this={articleEl} class="prose xl:prose-lg prose-invert max-w-none">
                <data.content/>
            </article>
        </div>
        <div class="hidden lg:block lg:col-span-1">
            <TableOfContents {links} {activeId} />
        </div>
    </div>
</div>