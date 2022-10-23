#pragma once
#include <imgui.h>
#include "log.hpp"

namespace example
{

void render_log()
{
    ImGui::Begin("Log", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

    ImGui::End();

    log_data.Draw("Log");
}
} // namespace example