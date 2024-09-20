/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Boid.h"
#include <vector>

#include "AlignBehaviour.h"
#include "AvoidBehaviour.h"
#include "CohesionBehaviour.h"
#include "Condition.h"
#include "SeparateBehaviour.h"
#include "UtilityAI.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Boids");

    SetTargetFPS(240);
    //--------------------------------------------------------------------------------------

	// Utility AI
    //--------------------------------------------------------------------------------------
    UtilityAI::UtilityAI* utilityAI = new UtilityAI::UtilityAI();
    utilityAI->AddBehaviour(new UtilityAI::AlignBehaviour());
    utilityAI->AddBehaviour(new UtilityAI::AvoidBehaviour());
    utilityAI->AddBehaviour(new UtilityAI::CohesionBehaviour());
    utilityAI->AddBehaviour(new UtilityAI::SeparateBehaviour());
	//--------------------------------------------------------------------------------------

	// Boids
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------
    float time = (float)GetTime();
    float deltaTime;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;

        // cap the elapsed time for when we debug
        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Spawn Boid
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            utilityAI->AddBoid(new UtilityAI::Boid(mousePos, RED, utilityAI));
        }

        for (UtilityAI::Boid* boid : utilityAI->GetBoids())
        {
            boid->Update(deltaTime);
        	boid->Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}