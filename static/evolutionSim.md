# **AI Evolution Simulator**

### **Project Overview**

I developed this project as my final for CS4350: Fundamentals of Game Engine Design. It is an agent-based 3D evolution simulator built in C++ within my professor's custom game engine, AftrBurner. Inspired by a fascination with emergent behavior, I created a simulation where autonomous "actors" evolve based on environmental pressures. The core of the project was observing how complex survival and social strategies arise from a simple set of genetic rules, environmental constraints, and interactions with AI predators.  
The simulation runs on a fixed timestep and is highly customizable through an ImGui-based interface, which allows for real-time adjustments to over 40 parameters and visualization of evolutionary trends through data plots.

**EMBED VIDEO:** [https://youtu.be/xcH7nGzvxvY](https://youtu.be/xcH7nGzvxvY)

### **Phase 1: Core Systems and Survival Loop**

In the initial phase, I focused on building the foundational systems of the simulation.

##### World Generation and Actor Spawning  
I began by implementing the core environmental components. To create a natural-looking and evenly spaced distribution of resources, I wrote a deterministic spawning system that places Plants (the primary food source) in a phyllotaxis cluster pattern. I then spawned Actors around this cluster, initializing them with randomized physical traits (Speed, Size, Sense) and a starting energy level.

##### Survival Mechanics  
I then established the fundamental survival loop. Actors deplete energy over time at a rate determined by their physical traits—larger, faster, and more perceptive actors have higher energy costs. To survive, they must find and consume Apples that spawn on plants. If an actor's energy drops to zero, I remove it from the simulation. This core mechanic created the initial selective pressure: an actor had to be efficient enough to find food before it starved.

### **Phase 2: Reproduction, Evolution, and Environmental Threats**

This phase introduced the mechanics necessary for evolution to occur.

##### Genetic Inheritance  
I implemented the reproduction system, centered around Shelters. When two actors with sufficient energy meet in a shelter, they produce an offspring. I designed a system where the child inherits a mix of its parents' traits:

* **Physical Traits (Speed, Size, Sense):** Inherited by averaging the parents' values, plus a small, random mutation.  
* **Personality Traits (Social, Brave, Generous):** Inherited via a Mendelian model, where I gave each parent dominant or recessive alleles for each gene. This system was also subject to a configurable mutation rate that could flip an allele.

##### Predator AI  
To create a more dynamic and challenging environment, I introduced Predators. I programmed these AI agents to patrol the environment using a simple state machine (PATROLLING, CHASING, GRABBING). They detect actors within a forward-facing cone and will chase the closest one. This added a significant survival pressure, making traits like speed and predator awareness (Sense) critical.

### **Phase 3: Emergent Social Behaviors and System Refinement**

The final phase focused on implementing the personality-driven behaviors that would lead to complex social dynamics.

##### Behavioral Genetics  
I linked the inherited personality traits directly to the actors' decision-making logic within their state machine:

* **Social vs. Solitary:** I made social actors exhibit flocking behavior by moving towards the center of mass of nearby actors, while solitary actors actively move away from others.  
* **Brave vs. Cautious:** This gene determines an actor's flight distance from predators. Crucially, I programmed brave actors to attempt to rescue a captured teammate by charging the predator, which sometimes stuns it but also risks their own capture.  
* **Generous vs. Selfish:** I designed generous actors with surplus energy and food to actively seek out and share resources with hungry actors nearby, a behavior that selfish actors never exhibit.

##### GUI for Control and Observation  
To make the simulation a useful tool for observation, I developed a comprehensive GUI using ImGui and ImPlot. This interface allows for real-time control over 40+ simulation parameters, from simulation speed to mutation rates to predator speed. It also includes a suite of plots that track the population's average physical and genetic traits over time, providing clear, quantitative data on the evolutionary trends emerging from the simulation's rules.  
*The ImGui-based control panel and ImPlot graphs, showing real-time data on population size and the distribution of genetic traits like "Brave" vs. "Cautious."*