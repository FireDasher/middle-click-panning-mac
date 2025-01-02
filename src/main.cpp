#include "main.hpp"

bool isPanning = false;
int dragButton = Mod::get()->getSettingValue<std::string>("drag-button") == "Right Click" ? GLFW_MOUSE_BUTTON_RIGHT : GLFW_MOUSE_BUTTON_MIDDLE;

$execute {
    listenForSettingChanges("drag-button", [](std::string value) {
        dragButton = value == "Right Click" ? GLFW_MOUSE_BUTTON_RIGHT : GLFW_MOUSE_BUTTON_MIDDLE;
    });
}


void ModLevelEditorLayer::startPanning() {
    m_fields->m_previousMousePos = getMousePos();
}

void ModLevelEditorLayer::updatePanning() {
    auto mouseDelta = getMousePos() - m_fields->m_previousMousePos;
    m_fields->m_previousMousePos = getMousePos();

    m_objectLayer->setPosition(m_objectLayer->getPosition() + mouseDelta);

    m_editorUI->constrainGameLayerPosition(-100, -100);
    m_editorUI->updateSlider();
}


void ModCCEGLView::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
    CCEGLView::onGLFWMouseCallBack(window, button, action, mods);
    if (button != dragButton) return;

    isPanning = action == GLFW_PRESS;

    if (auto lel = LevelEditorLayer::get()) {
        static_cast<ModLevelEditorLayer*>(lel)->startPanning();
    }
}

void ModCCEGLView::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
    CCEGLView::onGLFWMouseMoveCallBack(window, x, y);
    if (!isPanning) return;

    if (isPanning) {
        if (auto lel = LevelEditorLayer::get()) {
            static_cast<ModLevelEditorLayer*>(lel)->updatePanning();
        }
    }
}
