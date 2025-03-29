#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/CCEGLView.hpp>
#include <Geode/Geode.hpp>
#include <GLFW/glfw3.h>
using namespace geode::prelude;

class $modify(ModLevelEditorLayer, LevelEditorLayer) {
    struct Fields {
        CCPoint m_previousMousePos;
    };

    void startPanning();
    void updatePanning();
};

class $modify(ModCCEGLView, CCEGLView) {
    $override void onGLFWMouseCallBack(GLFWwindow* , int, int, int);
    $override void onGLFWMouseMoveCallBack(GLFWwindow*, double, double);
};
