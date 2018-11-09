/*******************************************************************************************
*
*   raygui - controls test suite
*
*   TEST CONTROLS:
*       - GuiDropdownBox()
*       - GuiValueBox()
*       - GuiSpinner()
*       - GuiTextBox()
*       - GuiTextBoxMulti()
*       - GuiListView()
*
*   DEPENDENCIES:
*       raylib 2.1  - Windowing/input management and drawing.
*       raygui 2.0  - Immediate-mode GUI controls.
*
*   COMPILATION (Windows - MinGW):
*       gcc -o $(NAME_PART).exe $(FILE_NAME) -I../../src -lraylib -lopengl32 -lgdi32 -std=c99
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 raylib technologies (@raylibtech)
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../../src/raygui.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raygui - controls test suite");

    // GUI controls initialization
    //----------------------------------------------------------------------------------
    int dropdownBox000Active = 0;
    const char *dropdownBox000TextList[3] = { "ONE", "TWO", "THREE" };
    bool dropDown000EditMode = false;
    
    int dropdownBox001Active = 0;
    const char *dropdownBox001TextList[5] = { "ONE", "TWO", "THREE", "FOUR", "FIVE" };
    bool dropDown001EditMode = false;    
    
    int spinner001Value = 0;
    bool spinnerEditMode = false;
    
    int valueBox002Value = 0;
    bool valueBoxEditMode = false;
    
    char textBoxText[64] = "Text box";
    bool textBoxEditMode = false;
    
    int listViewScrollIndex = 1;
    int listViewActive = -1;
    const char *listViewList[6] = { "Charmander", "Bulbasaur", "Squirtel", "Pikachu", "Eevee", "Pidgey" };
    bool listViewEditMode = false;
    
    int listViewExScrollIndex = 0;
    int listViewExActive = -1;
    int listViewExFocus = -1;
    const char *listViewExList[8] = { "This", "is", "a", "list view", "with", "disable", "elements", "amazing!" };
    int listViewExElementsEnable[8] = {1, 0, 1, 1, 0, 0, 1};
    bool listViewExEditMode = false;
    
    char multiTextBoxText[141] = "Multi text box";    
    bool multiTextBoxEditMode = false;    
    
    bool forceSquaredChecked = false;
    //----------------------------------------------------------------------------------
    
    // Custom GUI font loading
    //Font font = LoadFontEx("fonts/rainyhearts16.ttf", 12, 0, 0);
    //GuiFont(font);

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(style[DEFAULT_BACKGROUND_COLOR]));
 
            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (dropDown000EditMode || dropDown001EditMode) GuiLock();
            //GuiDisable();
            
            // First GUI column
            forceSquaredChecked = GuiCheckBoxEx((Rectangle){ 25, 108, 15, 15 }, forceSquaredChecked, "Force Square");
            if (GuiSpinner((Rectangle){ 25, 135, 125, 30 }, &spinner001Value, 0, 100, 25, spinnerEditMode)) spinnerEditMode = !spinnerEditMode;
            if (GuiValueBox((Rectangle){ 25, 175, 125, 30 }, &valueBox002Value, 0, 100, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;
            if (GuiTextBox((Rectangle){ 25, 215, 125, 30 }, textBoxText, 64, textBoxEditMode)) textBoxEditMode = !textBoxEditMode;
            if (GuiButton((Rectangle){ 25, 255, 125, 30 }, "SAMPLE TEXT")) { }
                // NOTE: GuiDropdownBox must draw at the end of the column
            if (GuiDropdownBox((Rectangle){ 25, 65, 125, 30 }, dropdownBox001TextList, 5, &dropdownBox001Active, dropDown001EditMode)) dropDown001EditMode = !dropDown001EditMode;            
            if (GuiDropdownBox((Rectangle){ 25, 25, 125, 30 }, dropdownBox000TextList, 3, &dropdownBox000Active, dropDown000EditMode)) dropDown000EditMode = !dropDown000EditMode;           
            
            // Second GUI column      
            if (GuiListView((Rectangle){ 185, 25, 120, 100 }, listViewList, 6, &listViewScrollIndex, &listViewActive, listViewEditMode)) listViewEditMode = !listViewEditMode;
            if (GuiListViewEx((Rectangle){ 185, 155, 120, 200 }, listViewExList, listViewExElementsEnable, 8, &listViewExScrollIndex, &listViewExActive, &listViewExFocus, listViewExEditMode)) listViewExEditMode = !listViewExEditMode;
            if (listViewExFocus >= 0 && listViewExFocus < 8) DrawText(listViewExList[listViewExFocus], 195, 370, 20, RED);
            
            // Third GUI column
            if (GuiTextBoxMulti((Rectangle){ 325, 25, 225, 175 }, multiTextBoxText, 141, multiTextBoxEditMode)) multiTextBoxEditMode = !multiTextBoxEditMode;
            
            //GuiEnable();
            GuiUnlock();
            
            // Fourth GUI column
            GuiLock();
            GuiState(GUI_STATE_NORMAL); if (GuiButton((Rectangle){ 600, 25, 125, 30 }, "NORMAL")) { }
            GuiState(GUI_STATE_FOCUSED); if (GuiButton((Rectangle){ 600, 65, 125, 30 }, "FOCUSED")) { }
            GuiState(GUI_STATE_PRESSED); if (GuiButton((Rectangle){ 600, 105, 125, 30 }, "PRESSED")) { }
            GuiState(GUI_STATE_DISABLED); if (GuiButton((Rectangle){ 600, 145, 125, 30 }, "DISABLED")) { }
            GuiState(GUI_STATE_NORMAL);            
            GuiUnlock();
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}