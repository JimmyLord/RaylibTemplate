#include "raylib.h"

#include "Game/Game.h"
#include "Helpers/InputTypes.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void updateDrawFrame();

static const int c_screenWidth = 1280;
static const int c_screenHeight = 720;

Game* g_game = nullptr;

int main()
{
    InitWindow( c_screenWidth, c_screenHeight, "Demo Window" );

    g_game = new Game();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop( updateDrawFrame, 0, 1 );
#else
    SetTargetFPS( 60 );

    // Main game loop
    while( !WindowShouldClose() )
    {
        updateDrawFrame();
    }
#endif

    delete g_game;

    CloseWindow();

    return 0;
}

void updateDrawFrame()
{
    for( int i=0; i<512; i++ )
    {
        if( IsKeyPressed(i) )
            g_game->onKey( i, KeyState::Pressed );
        else if( IsKeyReleased(i) )
            g_game->onKey( i, KeyState::Released );
    }

    // Update game state.
    g_game->update( GetFrameTime() );

    // Draw the game.
    BeginDrawing();
    g_game->draw();
    EndDrawing();
}
