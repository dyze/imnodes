#include <iostream>
#include "node_editor.h"
#include "imnodes.h"
#include "imnodes_internal.h"
#include <imgui.h>
#include "tools/log_widget.hpp"

namespace example
{
namespace
{
void mini_map_node_hovering_callback(int node_id, void* /*user_data*/)
{
    ImGui::SetTooltip("This is node %ld", node_id);
}

void node_moved_callback(int node_id, void* /*user_data*/)
{
    log_data.AddLog("node_moved_callback called %ld...", node_id);
}

class MoveWorldNodeEditor
{
public:
    void show()
    {
        render_log();

        ImGui::Begin("move node editor");

        ImNodes::BeginNodeEditor();

        for (int i = 0; i < 2; i++)
        {
            ImNodes::BeginNode(i);

            ImNodes::BeginNodeTitleBar();
            ImGui::TextUnformatted("move me");
            ImNodes::EndNodeTitleBar();

            ImNodes::BeginInputAttribute(i * 10 + 2);
            ImGui::Text("input");
            ImNodes::EndInputAttribute();

            ImNodes::BeginOutputAttribute(i * 10 + 3);
            ImGui::Indent(40);
            ImGui::Text("output");
            ImNodes::EndOutputAttribute();

            ImNodes::EndNode();
        }

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight, mini_map_node_hovering_callback);

        ImNodes::EndNodeEditor();

        ImGui::End();
    }
};

static MoveWorldNodeEditor editor;
} // namespace

void NodeEditorInitialize()
{
    log_data.AddLog("NodeEditorInitialize...");

    ImNodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f));

    auto& context = ImNodes::EditorContextGet();
    context.SetNodeMoveCallback(node_moved_callback);
}

void NodeEditorShow() { editor.show(); }

void NodeEditorShutdown()
{
    auto& context = ImNodes::EditorContextGet();
    context.SetNodeMoveCallback(nullptr);
}

} // namespace example
