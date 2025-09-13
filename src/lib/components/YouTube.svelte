<script lang="ts">
	/**
	 * A responsive component to embed a YouTube video.
	 * It maintains a 16:9 aspect ratio.
	 */
	const {
		id,
		title = 'Embedded YouTube video',
		class: extraClasses = ''
	} = $props<{
		id: string; // The YouTube video ID
		title?: string;
		class?: string;
	}>();
</script>

<!--
  This container uses a classic CSS trick to maintain the aspect ratio.
  The padding-bottom (56.25%) creates a box that is 56.25% as tall as it is wide (16:9).
  The iframe is then absolutely positioned to fill this container.
-->
<div class={`relative h-0 overflow-hidden rounded-lg border border-neutral-700 pb-[56.25%] ${extraClasses}`}>
	<iframe
		src={`https://www.youtube.com/embed/${id}`}
		{title}
		class="absolute left-0 top-0 h-full w-full"
		frameborder="0"
		allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
		allowfullscreen
	></iframe>
</div>