// From EvolutionSimGUI.cpp, inside the draw_plots method

void EvolutionSimGUI::draw_plots() {
    if (ImGui::Begin("Daily Simulation Stats")) {
        if (ImGui::BeginTabBar("StatsTabs")) {

            // --- Population Tab ---
            if (ImGui::BeginTabItem("Population")) {
                if (ImPlot::BeginPlot("##PopulationPlot", ImVec2(-1, -1))) {
                    ImPlot::SetupAxes("Day", "Actor Count");
                    ImPlot::PlotLine("Population", dayHistory.data(), actorPopulationHistory.data(), dayHistory.size());
                    ImPlot::EndPlot();
                }
                ImGui::EndTabItem();
            }

            // --- Physical Traits Tab ---
            if (ImGui::BeginTabItem("Physical Traits")) {
                if (ImPlot::BeginPlot("##PhysicalTraitsPlot", ImVec2(-1, -1))) {
                    ImPlot::SetupAxes("Day", "Average Value");
                    ImPlot::PlotLine("Speed", dayHistory.data(), avgActorSpeedHistory.data(), dayHistory.size());
                    ImPlot::PlotLine("Size", dayHistory.data(), avgActorSizeHistory.data(), dayHistory.size());
                    ImPlot::PlotLine("Sense", dayHistory.data(), avgActorSenseHistory.data(), dayHistory.size());
                    ImPlot::EndPlot();
                }
                ImGui::EndTabItem();
            }

            // --- Brave/Cautious Genetics Tab ---
            if (ImGui::BeginTabItem("Genetics (Brave/Cautious)")) {
                if (ImPlot::BeginPlot("##BraveCautiousPlot", ImVec2(-1, -1))) {
                    ImPlot::SetupAxes("Day", "Percentage (%)");
                    ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 100, ImGuiCond_Always);

                    ImPlot::PlotLine("Brave %", dayHistory.data(), bravePercentageHistory.data(), dayHistory.size());
                    ImPlot::PlotLine("Cautious %", dayHistory.data(), cautiousPercentageHistory.data(), dayHistory.size());
                    ImPlot::EndPlot();
                }
                ImGui::EndTabItem();
            }
            // ... (other tabs for social/generous traits) ...
            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}
