
#include "glhelper.h"
#include "Mesh.h"
#include <iostream>

int main(void)
{
    GLHelper::init(800, 600, "Jae_Graphic");
    
    std::vector<Mesh> meshes;
    meshes.push_back(CreateCube(2, 2));
    meshes[0].init("cube");
    glm::mat4 view = {
1,0,0,0,
0,1,0,0,
0,0,1,0,
0,0,0,1
    };
    glm::mat4 projection = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
    };
    glm::vec3 eye = { 0.f, 2.f, 5.0f };
    glm::vec3 light = { 0.0f, 0.0f, 3.0f };
    Vec4 useNormal = Vec4(0.8f, 0.0f, 0.4f, -1.0f);
    view = glm::rotate(view, EIGHTH_PI, glm::vec3(1.0f, 0.0f, 0.0f));
    //view = glm::rotate(view, QUARTER_PI, glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::translate(view, -eye);

    projection = glm::perspective(glm::radians(45.0f), 1.f, 0.1f, 100.0f);
    while (!glfwWindowShouldClose(GLHelper::ptr_window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        meshes[0].draw(useNormal,view,projection,light,eye);
        glfwPollEvents();
        glfwSwapBuffers(GLHelper::ptr_window);
    }
    GLHelper::cleanup();
    return 0;
}