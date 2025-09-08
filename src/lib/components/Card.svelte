<script lang="ts">
    const {
        class: extraClasses = '', // Rename `class` prop to avoid conflict with the HTML attribute
        image='', // Optional image URL for the card
        title = '', // Optional title for the card
        description = '', // Optional description for the card
        tags = [] as string[], // Optional tags for the card
        children = null, // For card content
        ...restProps // Capture any other properties (like onclick, id, etc.)
    } = $props<{
        class?: string;
        title?: string;
        description?: string;
        tags?: string[];
        children?: Svelte5.Snippet; // For card content
        [key: string]: any; // Allow any other attributes
    }>();

</script>

<div
    class={`bg-neutral-800 rounded-lg p-6 shadow-md hover:shadow-lg transition-shadow duration-200 ${extraClasses}`}
    {...restProps}>
    {#if image}
        <img src="{image}" alt="{title}" class="w-full h-48 object-cover rounded mb-4" />
    {/if}
    {#if title}
        <h3 class="text-2xl font-semibold text-main-100 mb-2">{title}</h3>
    {/if}
    {#if description}
        <p class="text-neutral-300 mb-4">{description}</p>
    {/if}
    <div class="mb-4">
        {@render children?.()}
    </div>
    {#if tags.length > 0}
        <div class="flex flex-wrap gap-2">
            {#each tags as tag}
                <span class="bg-neutral-700 text-neutral-200 text-sm px-2 py-1 rounded">{tag}</span>
            {/each}
        </div>
    {/if}

</div>