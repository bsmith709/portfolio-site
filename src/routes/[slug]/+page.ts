import { error } from '@sveltejs/kit';
import type { PageLoad } from './$types';

export const load: PageLoad = async ({ params }) => {
	// Use import.meta.glob to find all project files.
	// This creates a map of paths to functions that load the module.
	const modules = import.meta.glob('/src/lib/projects/*.svx');

	// Construct the path we expect to find for the current slug.
	const path = `/src/lib/projects/${params.slug}.svx`;
	const projectModule = modules[path];

	// If the module for the current path doesn't exist, throw a 404 error.
	if (!projectModule) {
		throw error(404, `Could not find project: ${params.slug}`);
	}

	// If it exists, call the function to load the module's content.
	const { default: content, metadata } = await projectModule();

	return {
		content,
		metadata: metadata ?? {}
	};
};