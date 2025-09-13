// From WOActor.cpp, a condensed version of the updateLogic method

void WOActor::updateLogic(float deltaTime, /*...other params...*/) {
    // High-priority check: Flee if a predator is detected
    handlePredators(predators);
    if (this->detectedPredator != nullptr) {
        this->currentState = ActorState::FLEEING;
    }

    // Main State Machine Logic
    switch (this->currentState) {
        case ActorState::WANDERING:
            // If hungry, seek food. If evening, seek shelter.
            if (this->energy < this->settings->actorHungerThreshold * this->settings->maxEnergy) {
                this->currentState = ActorState::SEEKING_FOOD;
            } else if (timeState == TimeOfDay::EVENING) {
                this->currentState = ActorState::SEEKING_SHELTER;
            }
            break;

        case ActorState::SEEKING_FOOD:
            // Find and move towards the nearest apple
            if (this->targetApple == nullptr) {
                findClosestTarget(apples, this->targetApple);
            }
            // If no food is left, go back to wandering
            if (this->targetApple == nullptr) {
                this->currentState = ActorState::WANDERING;
            }
            break;

        // ... other states like SEEKING_SHELTER, RESCUING etc. ...

        case ActorState::RESCUING:
            // Logic for a brave actor to move towards a predator that has captured another actor
            if (this->targetPredatorForRescue) {
                Vector toPredator = targetPredatorForRescue->getPosition() - this->getPosition();
                setMoveDirection(toPredator);
            }
            break;
    }

    // Apply movement and social behaviors based on state and genes
    if (this->isSocial) {
        socialBehavior(deltaTime, otherActors, socialForce);
    } else {
        solitaryBehavior(deltaTime, otherActors, solitaryForce);
    }

    // ... combine forces and call seekTarget(deltaTime) ...
}