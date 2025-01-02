#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/CCEGLView.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/Geode.hpp>
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

class $modify(HookEditorUI, EditorUI) {
    $override virtual void ccTouchMoved(CCTouch*, CCEvent*);
};
