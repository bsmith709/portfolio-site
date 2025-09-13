// From WOShelter.cpp, inside the addOccupant method

// --- 1. Physical Trait Inheritance (Averaging + Mutation) ---
float avgSpeed = (parent1->speed + parent2->speed) / 2.0f;
float avgSize = (parent1->size + parent2->size) / 2.0f;
float avgSense = (parent1->senseRadius + parent2->senseRadius) / 2.0f;

// Apply mutations based on mutation rate
if (ManagerRandomNumber::getRandomFloat(0.0f, 1.0f) < this->settings->mutationRate) {
    avgSpeed += ManagerRandomNumber::getRandomFloat(-this->settings->mutationAmount, this->settings->mutationAmount);
}
// ... (similar mutations for size and sense) ...

// Clamp values to their min/max bounds
avgSpeed = std::max(this->settings->actorMinSpeed, std::min(avgSpeed, this->settings->actorMaxSpeed));
// ... (clamping for size and sense) ...


// --- 2. Personality Trait Inheritance (Mendelian + Mutation) ---
GenePair childSocialGene, childBraveryGene, childGenerosityGene;

// Lambda to handle allele selection and mutation for any gene
auto getAllele = [&](char allele1, char allele2, char dominant, char recessive) {
    char chosen = (ManagerRandomNumber::getRandomInt(0, 1) == 0) ? allele1 : allele2;
    // Apply Mutation
    if (ManagerRandomNumber::getRandomFloat(0.0f, 1.0f) < this->settings->mutationRate) {
        chosen = (chosen == dominant) ? recessive : dominant; // Flip allele
    }
    return chosen;
};
