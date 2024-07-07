#define PNTR_APP_IMPLEMENTATION
#define PNTR_ENABLE_DEFAULT_FONT
#include "pntr_app.h"

typedef struct AppData {
    pntr_font* font;
    pntr_image* logo;
} AppData;

bool Init(pntr_app* app) {
    AppData* appData = pntr_load_memory(sizeof(AppData));
    pntr_app_set_userdata(app, appData);

    // Load the default font
    appData->font = pntr_load_font_default();
    appData->logo = pntr_load_image("resources/logo.png");

    return true;
}

bool Update(pntr_app* app, pntr_image* screen) {
    AppData* appData = (AppData*)pntr_app_userdata(app);

    // Clear the background
    pntr_clear_background(screen, PNTR_RAYWHITE);

    // Draw the logo
    if (appData->logo) {
        pntr_draw_image(screen, appData->logo, screen->width / 2 - appData->logo->width / 2, screen->height / 2 - appData->logo->height / 2);
    }

    // Draw text on the screen
    pntr_draw_text(screen, appData->font, "Congrats! You created your first pntr_app!", 35, screen->height - 30, PNTR_DARKGRAY);

    return true;
}

void Close(pntr_app* app) {
    AppData* appData = (AppData*)pntr_app_userdata(app);

    // Unload the assets.
    pntr_unload_font(appData->font);
    pntr_unload_image(appData->logo);

    pntr_unload_memory(appData);
}

pntr_app Main(int argc, char* argv[]) {
    return (pntr_app) {
        .width = 400,
        .height = 225,
        .title = "pntr_app_starter",
        .init = Init,
        .update = Update,
        .close = Close,
        .fps = 60
    };
}
