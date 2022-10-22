#include <iostream>
#include "node_editor.h"
#include "imnodes.h"
#include "imnodes_internal.h"
#include <imgui.h>

namespace example
{
namespace
{
void mini_map_node_hovering_callback(int node_id, void* /*user_data*/)
{
    ImGui::SetTooltip("This is node %d", node_id);
}

class MoveWorldNodeEditor
{
public:
    void show()
    {
        ImGui::Begin("move node editor");

        ImNodes::BeginNodeEditor();
        ImNodes::BeginNode(1);

        ImNodes::BeginNodeTitleBar();
        ImGui::TextUnformatted("simple node :)");
        ImNodes::EndNodeTitleBar();

        ImNodes::BeginInputAttribute(2);
        ImGui::Text("input");
        ImNodes::EndInputAttribute();

        ImNodes::BeginOutputAttribute(3);
        ImGui::Indent(40);
        ImGui::Text("output");
        ImNodes::EndOutputAttribute();

        ImNodes::EndNode();

        ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight, mini_map_node_hovering_callback);

        ImNodes::EndNodeEditor();

        ImGui::End();
    }
};

static MoveWorldNodeEditor editor;
} // namespace

void NodeEditorInitialize()
{
    std::cout << "NodeEditorInitialize\n";
    ImNodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f));
}

void NodeEditorShow() { editor.show(); }

void NodeEditorShutdown() {}

} // namespace example
