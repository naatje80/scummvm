/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "m4/riddle/gui/game_menu.h"
#include "m4/riddle/vars.h"
#include "graphics/thumbnail.h"
#include "m4/adv_r/other.h"
#include "m4/adv_r/adv_background.h"
#include "m4/adv_r/adv_control.h"
#include "m4/adv_r/adv_player.h"
#include "m4/core/errors.h"
#include "m4/core/imath.h"
#include "m4/gui/gui_event.h"
#include "m4/gui/hotkeys.h"
#include "m4/graphics/gr_line.h"
#include "m4/graphics/gr_sprite.h"
#include "m4/graphics/krn_pal.h"
#include "m4/gui/gui_sys.h"
#include "m4/gui/gui_vmng.h"
#include "m4/mem/mem.h"
#include "m4/platform/keys.h"
#include "m4/m4.h"

namespace M4 {
namespace Riddle {
namespace GUI {

static void CreateGameMenuMain(RGB8 *myPalette);

void CreateGameMenu(RGB8 *myPalette) {
	if ((!player_commands_allowed()) || (!INTERFACE_VISIBLE) ||
		_G(pal_fade_in_progress) || _G(menuSystemInitialized)) {
		return;
	}

	CreateGameMenuMain(myPalette);
}

void CreateGameMenuMain(RGB8 *myPalette) {
	if (!_G(menuSystemInitialized)) {
		menu_Initialize(myPalette);
	}

	// Keep the memory tidy
	PurgeMem();
	CompactMem();

	// Load in the game menu sprites
	if (!menu_LoadSprites("gamemenu", GM_TOTAL_SPRITES)) {
		return;
	}

	_GM(gameMenu) = menu_Create(_GM(menuSprites)[GM_DIALOG_BOX], GAME_MENU_X, GAME_MENU_Y, MENU_DEPTH | SF_GET_ALL | SF_BLOCK_ALL | SF_IMMOVABLE);
	if (!_GM(gameMenu)) {
		return;
	}
#if 0
	menu_ButtonAdd(_GM(gameMenu), GM_TAG_MAIN, GM_MAIN_X, GM_MAIN_Y, GM_MAIN_W, GM_MAIN_H, cb_Game_Main);
	menu_ButtonAdd(_GM(gameMenu), GM_TAG_OPTIONS, GM_OPTIONS_X, GM_OPTIONS_Y, GM_OPTIONS_W, GM_OPTIONS_H, cb_Game_Options);
	menu_ButtonAdd(_GM(gameMenu), GM_TAG_RESUME, GM_RESUME_X, GM_RESUME_Y, GM_RESUME_W, GM_RESUME_H, cb_Game_Resume);
	menu_ButtonAdd(_GM(gameMenu), GM_TAG_QUIT, GM_QUIT_X, GM_QUIT_Y, GM_QUIT_W, GM_QUIT_H, cb_Game_Quit);

	if (!_GM(gameMenuFromMain)) {
		menu_ButtonAdd(_GM(gameMenu), GM_TAG_SAVE, GM_SAVE_X, GM_SAVE_Y, GM_SAVE_W, GM_SAVE_H, cb_Game_Save);
	} else {
		menu_ButtonAdd(_GM(gameMenu), GM_TAG_SAVE, GM_SAVE_X, GM_SAVE_Y, GM_SAVE_W, GM_SAVE_H, cb_Game_Save, BTN_TYPE_GM_GENERIC, true);
	}

	// See if there are any games to load
	if (g_engine->savesExist()) {
		menu_ButtonAdd(_GM(gameMenu), GM_TAG_LOAD, GM_LOAD_X, GM_LOAD_Y, GM_LOAD_W, GM_LOAD_H, cb_Game_Load);
	} else {
		menu_ButtonAdd(_GM(gameMenu), GM_TAG_LOAD, GM_LOAD_X, GM_LOAD_Y, GM_LOAD_W, GM_LOAD_H, cb_Game_Load, BTN_TYPE_GM_GENERIC, true);
	}

	// Configure the game so pressing <esc> will cause the menu to disappear and the game to resume
	menu_Configure(_GM(gameMenu), cb_Game_Resume, cb_Game_Resume);

	vmng_screen_show((void *)_GM(gameMenu));
	LockMouseSprite(0);
#endif
}

} // namespace GUI
} // namespace Riddle
} // namespace M4
