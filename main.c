#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include "forwards.h"

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <xinput.h>
#include <stdint.h>
#pragma comment(lib, "Dinput8.lib")
#pragma comment(lib, "Dxguid.lib")



void* g_game_ptr = NULL;
void* g_world_ptr = 0x0095C770;

DWORD* ai_current_player = NULL;
DWORD* fancy_player_ptr = NULL;

char* injected_pack = NULL;


DWORD for_pack_loading[2];





uint8_t color_ramp_function(float ratio, int period_duration, int cur_time) {

	if (cur_time <= 0 || 4 * period_duration <= cur_time)
		return 0;

	if (cur_time < period_duration) {

		float calc = ratio * cur_time;

		return min(calc, 1.0f) * 255;
	}


	if (period_duration <= cur_time && cur_time <= 3 * period_duration) {
		return 255;
	}#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include "forwards.h"

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <xinput.h>
#include <stdint.h>
#pragma comment(lib, "Dinput8.lib")
#pragma comment(lib, "Dxguid.lib")



void* g_game_ptr = NULL;
void* g_world_ptr = 0x0095C770;

DWORD* ai_current_player = NULL;
DWORD* fancy_player_ptr = NULL;

char* injected_pack = NULL;


DWORD for_pack_loading[2];





uint8_t color_ramp_function(float ratio, int period_duration, int cur_time) {

	if (cur_time <= 0 || 4 * period_duration <= cur_time)
		return 0;

	if (cur_time < period_duration) {

		float calc = ratio * cur_time;

		return min(calc, 1.0f) * 255;
	}


	if (period_duration <= cur_time && cur_time <= 3 * period_duration) {
		return 255;
	}


	if (cur_time <= 4 * period_duration) {

		int adjusted_time = cur_time - 3 * period_duration;
		float calc = 1.f - ratio * adjusted_time;

		return min(calc, 1.0f) * 255;
	}

}


typedef struct _list {
	struct _list* next;
	struct _list* prev;
	void* data;
}list;

typedef struct {
	BYTE unk[256];//not sure how big
}mString;

#define MAX_CHARS_SAFE 63
#define MAX_CHARS MAX_CHARS_SAFE+1
#define EXTEND_NEW_ENTRIES 20
#define MAX_ELEMENTS_PAGE 18

#pragma pack(1)
typedef struct {
	uint8_t unk[0x50];
	uint8_t status;
	uint8_t unk1[0x53];
	float x;
	float y;
	float z;
	uint8_t unk2[0x10];
	DWORD district_id;
	uint8_t unk3[0x4];
	uint8_t variants;
	uint8_t unk4[0x6B];
}region;


typedef enum {
	NORMAL,
	BOOLEAN_E,
	BOOLEAN_F,
	BOOLEAN_G,
	BOOLEAN_H,
	BOOLEAN_I,
	BOOLEAN_L,
	BOOLEAN_M,
	BOOLEAN_N,
	BOOLEAN_O,
	BOOLEAN_P,
	BOOLEAN_X,
	TEST,
	CUSTOM
}debug_menu_entry_type;


typedef enum {
	LEFT,
	RIGHT,
	ENTER
}custom_key_type;


struct _debug_menu_entry;
typedef char* (*custom_string_generator_ptr)(struct _debug_menu_entry* entry);

typedef struct _debug_menu_entry {

	char text[MAX_CHARS];
	debug_menu_entry_type entry_type;
	void* data;
	void* data1;
	custom_string_generator_ptr custom_string_generator;
}debug_menu_entry;

typedef void (*menu_handler_function)(debug_menu_entry*, custom_key_type key_type);
typedef void (*go_back_function)();

typedef struct {
	char title[MAX_CHARS];
	DWORD capacity;
	DWORD used_slots;
	DWORD window_start;
	DWORD cur_index;
	go_back_function go_back;
	menu_handler_function handler;
	debug_menu_entry* entries;
}debug_menu;



debug_menu* start_debug = NULL;
debug_menu* warp_menu = NULL;
debug_menu* game_menu = NULL;
debug_menu* game_flags_menu = NULL;
debug_menu* district_variants_menu = NULL;
debug_menu* hero_menu = NULL;
debug_menu* script_menu = NULL;
debug_menu* progression_menu = NULL;
debug_menu* devopt_flags_menu = NULL;
debug_menu* devopt_int_menu = NULL;
debug_menu* savegame_opt_menu = NULL;
debug_menu* level_select_menu = NULL;
debug_menu* mission_menu = NULL;
debug_menu* jf = NULL;
debug_menu* jg = NULL;
debug_menu* kf = NULL;
debug_menu* kg = NULL;
debug_menu* kh = NULL;
debug_menu* lf = NULL;
debug_menu* lg = NULL;
debug_menu* lh = NULL;
debug_menu* debug_render_menu = NULL;
debug_menu* replay_menu = NULL;
debug_menu* ai_menu = NULL;
debug_menu* memory_menu = NULL;
debug_menu* scriptmemtrack_menu = NULL;
debug_menu* slabs_menu = NULL;
debug_menu* stacksize_menu = NULL;
debug_menu* uninitsize_menu = NULL;
debug_menu* initsize_menu = NULL;
debug_menu* codesize_menu = NULL;
debug_menu* streams_menu = NULL; 
debug_menu* entity_menu = NULL;
debug_menu* ai_0 = NULL;
debug_menu* entity_0 = NULL;
debug_menu* entity_1 = NULL;
debug_menu* entity_2 = NULL;
debug_menu* entity_3 = NULL;
debug_menu* entity_4 = NULL;
debug_menu* entity_5 = NULL;
debug_menu* entity_6 = NULL;
debug_menu* entity_7 = NULL;
debug_menu* entity_8 = NULL;
debug_menu* entity_9 = NULL;
debug_menu* entity_10 = NULL;
debug_menu* entity_11 = NULL;



debug_menu** all_menus[] = {
	&start_debug,
	&warp_menu,
	&game_menu,
	&game_flags_menu,
	&district_variants_menu,
	&hero_menu,
	&script_menu,
	&progression_menu,
	&devopt_flags_menu,
	&devopt_int_menu,
	&level_select_menu,
	&mission_menu,
	&debug_render_menu,
	&replay_menu,
	&ai_menu,
	&memory_menu,
	&streams_menu,
	&entity_menu
};

debug_menu* current_menu = NULL;



void goto_start_debug() {
	current_menu = start_debug;
}

void goto_nav_debug() {
	current_menu = hero_menu;
}



void unlock_region(region* cur_region) {

	cur_region->status &= 0xFE;
}

void remove_debug_menu_entry(debug_menu_entry* entry) {


	DWORD to_be = (DWORD)entry;
	for (int i = 0; i < (sizeof(all_menus) / sizeof(void*)); i++) {

		debug_menu* cur = *all_menus[i];

		DWORD start = cur->entries;
		DWORD end = start + cur->used_slots * sizeof(debug_menu_entry);

		if (start <= entry && entry < end) {


			int index = (to_be - start) / sizeof(debug_menu_entry);

			memcpy(&cur->entries[index], &cur->entries[index + 1], cur->used_slots - (index + 1));
			memset(&cur->entries[cur->used_slots - 1], 0, sizeof(debug_menu_entry));
			cur->used_slots--;
			return;
		}

	}

	printf("FAILED TO DEALLOCATE AN ENTRY :S %08X\n", entry);

}

void* add_debug_menu_entry(debug_menu* menu, debug_menu_entry* entry) {

	if (menu->used_slots < menu->capacity) {
		void* ret = &menu->entries[menu->used_slots];
		memcpy(ret, entry, sizeof(debug_menu_entry));
		menu->used_slots++;
		return ret;
	}
	else {
		DWORD current_entries_size = sizeof(debug_menu_entry) * menu->capacity;
		DWORD new_entries_size = sizeof(debug_menu_entry) * EXTEND_NEW_ENTRIES;


		void* new_ptr = realloc(menu->entries, current_entries_size + new_entries_size);

		if (!new_ptr) {
			printf("RIP\n");
			__debugbreak();
		}
		else {

			menu->capacity += EXTEND_NEW_ENTRIES;
			menu->entries = new_ptr;
			memset(&menu->entries[menu->used_slots], 0, new_entries_size);

			return add_debug_menu_entry(menu, entry);
		}
	}
}




debug_menu* create_menu(const char* title, go_back_function go_back, menu_handler_function function, DWORD capacity) {

	debug_menu* menu = malloc(sizeof(debug_menu));
	memset(menu, 0, sizeof(debug_menu));

	strncpy(menu->title, title, MAX_CHARS_SAFE);

	menu->capacity = capacity;
	menu->handler = function;
	menu->go_back = go_back;

	DWORD total_entries_size = sizeof(debug_menu_entry) * capacity;
	menu->entries = malloc(total_entries_size);
	memset(menu->entries, 0, total_entries_size);

	return menu;

}


int vm_debug_menu_entry_garbage_collection_id = -1;

typedef int (*script_manager_register_allocated_stuff_callback_ptr)(void* func);
script_manager_register_allocated_stuff_callback_ptr script_manager_register_allocated_stuff_callback = 0x005AFE40;

typedef int (*construct_client_script_libs_ptr)();
construct_client_script_libs_ptr construct_client_script_libs = 0x0058F9C0;


void vm_debug_menu_entry_garbage_collection_callback(void* a1, list* lst) {

	list* end = lst->prev;

	for (list* cur = end->next; cur != end; cur = cur->next) {

		debug_menu_entry* entry = ((debug_menu_entry*)cur->data);
		//printf("Will delete %s %08X\n", entry->text, entry);
		remove_debug_menu_entry(entry);
	}

}

int construct_client_script_libs_hook() {


	if (vm_debug_menu_entry_garbage_collection_id == -1) {
		int res = script_manager_register_allocated_stuff_callback(vm_debug_menu_entry_garbage_collection_callback);
		vm_debug_menu_entry_garbage_collection_id = res;
	}
	return construct_client_script_libs();
}


typedef (__fastcall* mString_constructor_ptr)(mString* this, void* edx, char* str);
mString_constructor_ptr mString_constructor = 0x00421100;

typedef (__fastcall* mission_stack_manager_push_mission_pack_ptr)(DWORD* this, int, int, int, char);
mission_stack_manager_push_mission_pack_ptr mission_stack_manager_push_mission_pack = 0x005D7FE0;

typedef (__fastcall* mission_stack_manager_insert_mission_pack_ptr)(DWORD* this, int, int, int);
mission_stack_manager_insert_mission_pack_ptr mission_stack_manager_insert_mission_pack = 0x005D7FE0;

typedef (__fastcall* mString_finalize_ptr)(mString* this, void* edx, int zero);
mString_finalize_ptr mString_finalize = 0x004209C0;


typedef (__fastcall* mString_mString_ptr)(mString* this, const char* a2);
mString_mString_ptr mString_mString = 0x00421100;


region** all_regions = 0x0095C924;
DWORD* number_of_allocated_regions = 0x0095C920;

typedef (__fastcall* region_get_name_ptr)(void* this);
region_get_name_ptr region_get_name = 0x00519BB0;


typedef int(__fastcall* region_get_district_variant_ptr)(region* this);
region_get_district_variant_ptr region_get_district_variant = 0x005503D0;


typedef char(__fastcall* terrain_set_district_variant_ptr)(void* this, void* edx, DWORD district_id, int variant, char one);
terrain_set_district_variant_ptr terrain_set_district_variant = 0x00557480;

void set_text_writeable() {

	const DWORD text_end = 0x86F000;
	const DWORD text_start = 0x401000;

	DWORD old;
	VirtualProtect((void*)text_start, text_end - text_start, PAGE_EXECUTE_READWRITE, &old);
}

void set_rdata_writeable() {

	const DWORD end = 0x91B000;
	const DWORD start = 0x86F564;

	DWORD old;
	VirtualProtect((void*)start, end - start, PAGE_READWRITE, &old);
}

void HookFunc(DWORD callAdd, DWORD funcAdd, BOOLEAN jump, const unsigned char* reason) {

	//Only works for E8/E9 hooks	
	DWORD jmpOff = funcAdd - callAdd - 5;

	BYTE shellcode[] = { 0, 0, 0, 0, 0 };
	shellcode[0] = jump ? 0xE9 : 0xE8;

	memcpy(&shellcode[1], &jmpOff, sizeof(jmpOff));
	memcpy((void*)callAdd, shellcode, sizeof(shellcode));

	if (reason)
		printf("Hook: %08X -  %s\n", callAdd, reason);

}


void WriteDWORD(DWORD* address, DWORD newValue, const unsigned char* reason) {
	*address = newValue;
	if (reason)
		printf("Wrote: %08X -  %s\n", address, reason);
}

typedef int (*nflSystemOpenFile_ptr)(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove);
nflSystemOpenFile_ptr nflSystemOpenFile_orig = NULL;

nflSystemOpenFile_ptr* nflSystemOpenFile_data = (void*)0x0094985C;


HANDLE USM_handle = INVALID_HANDLE_VALUE;

int nflSystemOpenFile(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove) {


	//printf("Opening file %s\n", lpFileName);
	int ret = nflSystemOpenFile_orig(hHandle, lpFileName, a3, liDistanceToMove);


	if (strstr(lpFileName, "ultimate_spiderman.PCPACK")) {

	}
	return ret;
}



typedef int (*ReadOrWrite_ptr)(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite);
ReadOrWrite_ptr* ReadOrWrite_data = (void*)0x0094986C;
ReadOrWrite_ptr ReadOrWrite_orig = NULL;

int ReadOrWrite(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite) {

	int ret = ReadOrWrite_orig(a1, a2, a3, a4, lpBuffer, nNumberOfBytesToWrite);

	if (USM_handle == *a2) {
		printf("USM buffer was read %08X\n", (DWORD)lpBuffer);


	}
	return ret;
}


typedef void (*aeps_RenderAll_ptr)();
aeps_RenderAll_ptr aeps_RenderAll_orig = (void*)0x004D9310;

void** nglSysFont = (void**)0x00975208;

typedef void (*nglListAddString_ptr)(void* font, float x, float y, float z, DWORD color, float x_scale, float y_scale, char* format, ...);
nglListAddString_ptr nglListAddString = (void*)0x00779E90;



#define nglColor(r,g,b,a) ( (a << 24) |  (r << 16) | (g << 8) | (b & 255) )


typedef struct {
	BYTE unk[100];
}nglQuad;

typedef void (*nglInitQuad_ptr)(void*);
nglInitQuad_ptr nglInitQuad = (void*)0x0077AC40;


typedef void (*nglSetQuadRect_ptr)(void*, float, float, float, float);
nglSetQuadRect_ptr nglSetQuadRect = 0x0077AD30;


typedef void (*nglSetQuadColor_ptr)(void*, unsigned int);
nglSetQuadColor_ptr nglSetQuadColor = 0x0077AD10;


typedef void (*nglListAddQuad_ptr)(void*);
nglListAddQuad_ptr nglListAddQuad = 0x0077AFE0;


typedef int (*nglListBeginScene_ptr)(int);
nglListBeginScene_ptr nglListBeginScene = 0x0076C970;


typedef void (*nglListEndScene_ptr)();
nglListEndScene_ptr nglListEndScene = 0x00742B50;


typedef void (*nglSetQuadZ_ptr)(void*, float);
nglSetQuadZ_ptr nglSetQuadZ = 0x0077AD70;

typedef void (*nglSetClearFlags_ptr)(int);
nglSetClearFlags_ptr nglSetClearFlags = 0x00769DB0;

void aeps_RenderAll() {



	static cur_time = 0;
	int period = 60;
	int duration = 6 * period;
	float ratio = 1.f / period;

	uint8_t red = color_ramp_function(ratio, period, cur_time + 2 * period) + color_ramp_function(ratio, period, cur_time - 4 * period);
	uint8_t green = color_ramp_function(ratio, period, cur_time);
	uint8_t blue = color_ramp_function(ratio, period, cur_time - 2 * period);

	nglListAddString(*nglSysFont, 0.1f, 0.2f, 0.2f, nglColor(red, green, blue, 255), 1.f, 1.f, "");

	cur_time = (cur_time + 1) % duration;


	aeps_RenderAll_orig();
}


int debug_enabled = 0;
uint32_t keys[256];




typedef int (*nglGetStringDimensions_ptr)(int, char* EndPtr, int*, int*, float, float);
nglGetStringDimensions_ptr nglGetStringDimensions = 0x007798E0;



void getStringDimensions(char* str, int* width, int* height) {
	nglGetStringDimensions(*nglSysFont, str, width, height, 1.0, 1.0);
}

int getStringHeight(char* str) {
	int height;
	nglGetStringDimensions(*nglSysFont, str, NULL, &height, 1.0, 1.0);
	return height;
}


char* getRealText(debug_menu_entry* entry, char* str) {


	if (entry->entry_type == BOOLEAN_E) {
		BYTE* val = entry->data;
		sprintf(str, "%s: %s", entry->text, *val ? "True" : "False");
		return str;
	}


	
	if (entry->entry_type == BOOLEAN_H) {
		BYTE* num = entry->data;
		sprintf(str, "%s: %s", entry->text, *num ? "User" : "Chase");

		return str;
	}

	if (entry->entry_type == BOOLEAN_G) {
		BYTE* num = entry->data;
		sprintf(str, "%s: >", entry->text);

		return str;
	}

	if (entry->entry_type == BOOLEAN_I) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 7327", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_L) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 883", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_M) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 22", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_N) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 64", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_O) {
		BYTE* val = entry->data;
		sprintf(str, "%s: Chase", entry->text);
		return str;
	}



	if (entry->entry_type == BOOLEAN_P) {
		BYTE* num = entry->data;
		sprintf(str, "%s: %s", entry->text, *num ? "Off" : "On");

		return str;
	}

	if (entry->entry_type == BOOLEAN_F) {
		BYTE* val = entry->data;
		sprintf(str, "%s: %s", entry->text, *val ? "1" : "0");
	    return str;

	}
	if (entry->entry_type == CUSTOM) {

		return entry->custom_string_generator(entry);
	}


	return entry->text;


}




void render_current_debug_menu() {



	char text_buffer[128];
#define UP_ARROW " ^ ^ ^ "
#define DOWN_ARROW " v v v "


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	int needs_down_arrow = ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) ? 1 : 0;


	int cur_width, cur_height;
	int debug_width = 0;
	int debug_height = 0;

#define get_and_update(x) {\
	 getStringDimensions(x, &cur_width, &cur_height); \
	 debug_height += cur_height; \
	 debug_width = max(debug_width, cur_width);\
	}
	//printf("new size: %s %d %d (%d %d)\n", x, debug_width, debug_height, cur_width, cur_height); \

	get_and_update(current_menu->title);
	get_and_update(UP_ARROW);





	int total_elements_page = needs_down_arrow ? MAX_ELEMENTS_PAGE : current_menu->used_slots - current_menu->window_start;

	for (int i = 0; i < total_elements_page; i++) {

		debug_menu_entry* entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		get_and_update(cur);
	}


	if (needs_down_arrow) {
		get_and_update(DOWN_ARROW);
	}

	nglQuad quad;


	int menu_x_start = 20, menu_y_start = 40;
	int menu_x_pad = 24, menu_y_pad = 18;

	nglInitQuad(&quad);
	nglSetQuadRect(&quad, menu_x_start, menu_y_start, menu_x_start + debug_width + menu_x_pad, menu_y_start + debug_height + menu_y_pad);
	nglSetQuadColor(&quad, 0xBE0A0A0A);
	nglSetQuadZ(&quad, 0.5f);
	nglListAddQuad(&quad);


	int white_color = nglColor(255, 255, 255, 255);
	int yellow_color = nglColor(255, 255, 0, 255);
	int green_color = nglColor(0, 255, 0, 255);
	int pink_color = nglColor(255, 0, 255, 255);


	int render_height = menu_y_start;
	render_height += 12;
	int render_x = menu_x_start;
	render_x += 8;
	nglListAddString(*nglSysFont, render_x, render_height, 0.2f, green_color, 1.f, 1.f, current_menu->title);
	render_height += getStringHeight(current_menu->title);


	if (current_menu->window_start) {
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, pink_color, 1.f, 1.f, UP_ARROW);
	}
	render_height += getStringHeight(UP_ARROW);



	for (int i = 0; i < total_elements_page; i++) {

		int current_color = current_menu->cur_index == i ? yellow_color : white_color;

		debug_menu_entry* entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, current_color, 1.f, 1.f, cur);
		render_height += getStringHeight(cur);
	}

	if (needs_down_arrow) {
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, pink_color, 1.f, 1.f, DOWN_ARROW);
		render_height += getStringHeight(DOWN_ARROW);
	}




}
void myDebugMenu() {


	if (debug_enabled) {
		render_current_debug_menu();
	}
	nglListEndScene();
}


typedef int (*wndHandler_ptr)(HWND, UINT, WPARAM, LPARAM);
wndHandler_ptr orig_WindowHandler = 0x005941A0;

int WindowHandler(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

	switch (Msg) {
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_KEYUP:
	case WM_KEYDOWN:
	case WM_INPUT:
		printf("swallowed keypress\n");
		return;
	}

	return orig_WindowHandler(hwnd, Msg, wParam, lParam);

}

/*
	STDMETHOD(GetDeviceState)(THIS_ DWORD,LPVOID) PURE;
	STDMETHOD(GetDeviceData)(THIS_ DWORD,LPDIDEVICEOBJECTDATA,LPDWORD,DWORD) PURE;
*/


typedef int(__stdcall* GetDeviceState_ptr)(IDirectInputDevice8*, DWORD, LPVOID);
GetDeviceState_ptr GetDeviceStateOriginal = NULL;


typedef (__fastcall* game_pause_unpause_ptr)(void* this);
game_pause_unpause_ptr game_pause = 0x0054FBE0;
game_pause_unpause_ptr game_unpause = 0x0053A880;




typedef (__fastcall* game_get_cur_state_ptr)(void* this);
game_get_cur_state_ptr game_get_cur_state = 0x005363D0;



typedef (__fastcall* world_dynamics_system_remove_player_ptr)(void* this, void* edx, int number);
world_dynamics_system_remove_player_ptr world_dynamics_system_remove_player = 0x00558550;


typedef (__fastcall* world_dynamics_system_add_player_ptr)(void* this, void* edx, mString* str);
world_dynamics_system_add_player_ptr world_dynamics_system_add_player = 0x0055B400;


DWORD changing_model = 0;
char* current_costume = "ultimate_spiderman";

DWORD changing_mission = 0;
char* current_mission = "city";



typedef (*entity_teleport_abs_po_ptr)(DWORD, float*, int one);
entity_teleport_abs_po_ptr entity_teleport_abs_po = 0x004F3890;


typedef DWORD* (__fastcall* ai_ai_core_get_info_node_ptr)(DWORD* this, void* edx, int a2, char a3);
ai_ai_core_get_info_node_ptr ai_ai_core_get_info_node = 0x006A3390;



struct vm_executable;



typedef struct {
	uint8_t unk[0x20];
	struct vm_executable** vmexecutable;
}script_object;

typedef struct {
	uint8_t unk[0x2C];
	script_object* object;
}script_instance;


typedef struct {
	DWORD unk;
}script_executable;

typedef struct unknown_struct {
	DWORD unk;
	script_executable* scriptexecutable;
}unknown_struct;

typedef struct vm_executable {
	unknown_struct* unk_struct;
	DWORD unk[2];
	DWORD params;
}vm_executable;

typedef struct {
	uint8_t unk[0xC];
	script_instance* instance;
	vm_executable* vmexecutable;
}vm_thread;

typedef struct {
	uint8_t unk[0x184];
	DWORD stack_ptr;
	vm_thread* thread;
}slf;



typedef struct {
	DWORD unk[32];
}string_hash;

typedef void(__fastcall* test_ptr)(int a1, int a2, float a3);
test_ptr test = 0x005BACA0;


typedef void(__fastcall* string_hash_initialize_ptr)(string_hash* this, void* edx, int a2, char* Str1, int a4);
string_hash_initialize_ptr string_hash_initialize = 0x00547A00;


typedef int(__fastcall* script_object_find_func_ptr)(script_object* this, void* edx, string_hash* a2);
script_object_find_func_ptr script_object_find_func = 0x0058EF80;


typedef DWORD(__fastcall* script_executable_add_allocated_stuff_ptr)(script_executable* this, void* edx, int a2, int a3, int a4);
script_executable_add_allocated_stuff_ptr script_executable_add_allocated_stuff = 0x005A34B0;

void vm_stack_push(slf* function, void* data, DWORD size) {
	memcpy(function->stack_ptr, data, size);
	function->stack_ptr += size;
}

void vm_stack_pop(slf* function, DWORD size) {
	function->stack_ptr -= size;
}




void __stdcall missions(DWORD* this, int unk)
{

	if (!strncmp(*(const char**)(unk + 8), "fade", 0xFFFFu))
	{
		test((int)this, unk, 1.0);
	}
	else
	{
		DWORD* mission = (*(DWORD**)g_game_ptr) + 357;
		mString_mString((mString*)&this, (const char*)&mission);
		mString_mString((mString*)&this, "loading screen");
		mission_stack_manager_push_mission_pack((DWORD*)(int)&unk, (int)&unk, NULL, 0, this, 0);
		mString_mString(&mission, "title_");
		mString_mString((mString*)&this, "loading screen");
	}
}


uint8_t __stdcall slf__debug_menu_entry__set_handler__str(slf* function, void* unk) {

	vm_stack_pop(function, 8);

	void** params = (void**)function->stack_ptr;

	debug_menu_entry* entry = params[0];
	char* scrpttext = params[1];


	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, scrpttext, 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(DWORD*)&strhash);
	entry->data = instance;
	entry->data1 = functionid;

	return 1;
}

uint8_t __stdcall slf__destroy_debug_menu_entry__debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	debug_menu_entry** entry = (void*)function->stack_ptr;

	remove_debug_menu_entry(*entry);

	return 1;
}


uint8_t __stdcall slf__create_progression_menu_entry(slf* function, void* unk) {


	vm_stack_pop(function, 8);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s -> %s\n", strs[0], strs[1]);


	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, strs[1], 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(DWORD*)&strhash);

	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	entry.data = instance;
	entry.data1 = functionid;

	strcpy(entry.text, strs[0]);

	add_debug_menu_entry(progression_menu, &entry);






	/*
	if(function->thread->instance->object->vmexecutable[functionid]->params != 4)
	*/

	int push = 0;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}




uint8_t __stdcall slf__create_debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s ", strs[0]);


	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	strcpy(entry.text, strs[0]);

	void* res = add_debug_menu_entry(script_menu, &entry);

	script_executable* se = function->thread->vmexecutable->unk_struct->scriptexecutable;
	script_executable_add_allocated_stuff(se, NULL, vm_debug_menu_entry_garbage_collection_id, res, 0);

	//printf("%08X\n", res);

	int push = res;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}


DWORD modulo(int num, DWORD mod) {
	if (num >= 0) {
		return num % mod;
	}

	int absolute = abs(num);
	if (absolute % mod == 0)
		return 0;


	return mod - absolute % mod;
}


void menu_go_down() {


	if ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) {

		if (current_menu->cur_index < MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index++;
		else
			current_menu->window_start++;
	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index + 1, num_elements);
		if (current_menu->cur_index == 0)
			current_menu->window_start = 0;
	}
}

void menu_go_up() {


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	if (current_menu->window_start) {


		if (current_menu->cur_index > MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index--;
		else
			current_menu->window_start--;

	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index - 1, num_elements);
		if (current_menu->cur_index == (num_elements - 1))
			current_menu->window_start = current_menu->used_slots - num_elements;

	}

}

int sort_warp_entries(debug_menu_entry* entry1, debug_menu_entry* entry2) {
	return strcmp(entry1->text, entry2->text);
}


char* district_variant_string_generator(debug_menu_entry* entry) {

	char buffer[128];
	sprintf(buffer, "%s: %d", entry->text, region_get_district_variant(entry->data));
	return buffer;
}


HRESULT __stdcall GetDeviceStateHook(IDirectInputDevice8* this, DWORD cbData, LPVOID lpvData) {


	HRESULT res = GetDeviceStateOriginal(this, cbData, lpvData);


	//keyboard time babyyy
	if (cbData == 256) {

		BYTE* keysCurrent = lpvData;

		for (int i = 0; i < 256; i++) {

			if (keysCurrent[i]) {
				keys[i]++;
			}
			else {
				keys[i] = 0;
			}
		}

		int game_state = 0;
		if (g_game_ptr)
			game_state = game_get_cur_state(g_game_ptr);


		//debug menu stuff
		if (keys[DIK_X] == 2 && (game_state == 6 || game_state == 7)) {

			if (!debug_enabled && game_state == 7) {
				game_unpause(g_game_ptr);
				debug_enabled = !debug_enabled;
				current_menu = start_debug;
			}
			else if (!debug_enabled && game_state == 6) {
				game_pause(g_game_ptr);
				debug_enabled = !debug_enabled;
				current_menu = start_debug;
			}

			if (warp_menu->used_slots == 0) {

				debug_menu_entry poi = { "--- WARP TO POI ---", NORMAL, NULL };
				poi.data1 = 1;
				add_debug_menu_entry(warp_menu, &poi);

				for (int i = 0; i < *number_of_allocated_regions; i++) {
					region* cur_region = &(*all_regions)[i];
					char* region_name = region_get_name(cur_region);

					debug_menu_entry warp_entry = { "", NORMAL, cur_region };
					warp_entry.data1 = 0;
					strcpy(warp_entry.text, region_name);
					add_debug_menu_entry(warp_menu, &warp_entry);

					if (cur_region->variants >= 2) {
						warp_entry.entry_type = CUSTOM;
						warp_entry.custom_string_generator = district_variant_string_generator;
						add_debug_menu_entry(district_variants_menu, &warp_entry);
					}
				}
				qsort(warp_menu->entries, *number_of_allocated_regions, sizeof(debug_menu_entry), sort_warp_entries);
				qsort(district_variants_menu->entries, district_variants_menu->used_slots, sizeof(debug_menu_entry), sort_warp_entries);

			}


			if (devopt_flags_menu->used_slots == 0) {

				BYTE* cdonly = *(BYTE**)0x0096858C;
				debug_menu_entry cdonlys = { "CD ONLY ", BOOLEAN_E,  &cdonly[4 + 0x0] };
				add_debug_menu_entry(devopt_flags_menu, &cdonlys);

				BYTE* envmap = *(BYTE**)0x0096858C;
				debug_menu_entry envmaps = { "ENV MAP ", BOOLEAN_E,  &envmap[4 + 0x1] };
				add_debug_menu_entry(devopt_flags_menu, &envmaps);

				BYTE* nocd = *(BYTE**)0x0096858C;
				debug_menu_entry nocds = { "NO CD ", BOOLEAN_E,  &nocd[4 + 0x2] };
				add_debug_menu_entry(devopt_flags_menu, &nocds);

				BYTE* chattyload = *(BYTE**)0x0096858C;
				debug_menu_entry chattyloads = { "CHATTY LOAD ", BOOLEAN_E,  &chattyload[4 + 0x3] };
				add_debug_menu_entry(devopt_flags_menu, &chattyloads);

				BYTE* windowdefault = *(BYTE**)0x0096858C;
				debug_menu_entry windowdefaults = { "WINDOW DEFAULT ", BOOLEAN_E,  &windowdefault[4 + 0x4] };
				add_debug_menu_entry(devopt_flags_menu, &windowdefaults);

				BYTE* showfps = *(BYTE**)0x0096858C;
				debug_menu_entry showfpss = { "SHOW FPS ", BOOLEAN_E,  &showfps[4 + 0x5] };
				add_debug_menu_entry(devopt_flags_menu, &showfpss);

				

				BYTE* showstreamerinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showstreamerinfos = { "SHOW STREAMER INFO", BOOLEAN_E,  &showstreamerinfo[4 + 0x6] };
				add_debug_menu_entry(devopt_flags_menu, &showstreamerinfos);

				BYTE* showstreamerspam = *(BYTE**)0x0096858C;
				debug_menu_entry showstreamerspams = { "SHOW STREAMER SPAM", BOOLEAN_E,  &showstreamerspam[4 + 0x7] };
				add_debug_menu_entry(devopt_flags_menu, &showstreamerspams);


				BYTE* showresourcespam = *(BYTE**)0x0096858C;
				debug_menu_entry showresourcespams = { "SHOW RESOURCE SPAM", BOOLEAN_E,  &showresourcespam[4 + 0x8] };
				add_debug_menu_entry(devopt_flags_menu, &showresourcespams);


				BYTE* showmemoryinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showmemoryinfos = { "SHOW MEMORY INFO", BOOLEAN_E,  &showmemoryinfo[4 + 0x9] };
				add_debug_menu_entry(devopt_flags_menu, &showmemoryinfos);

				BYTE* showspideyinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showspideyinfos = { "SHOW SPIDEY SPEED", BOOLEAN_E,  &showspideyinfo[4 + 0xA] };
				add_debug_menu_entry(devopt_flags_menu, &showspideyinfos);

				BYTE* tracemissionmanager = *(BYTE**)0x0096858C;
				debug_menu_entry tracemissionmanagers = { "TRACE MISSION MANAGER", BOOLEAN_E,  &tracemissionmanager[4 + 0xB] };
				add_debug_menu_entry(devopt_flags_menu, &tracemissionmanagers);

				BYTE* dumpmissionheap = *(BYTE**)0x0096858C;
				debug_menu_entry dumpmissionheaps = { "DUMP MISSION HEAP", BOOLEAN_E,  &dumpmissionheap[4 + 0xC] };
				add_debug_menu_entry(devopt_flags_menu, &dumpmissionheaps);

				BYTE* cameracentricstreamer = *(BYTE**)0x0096858C;
				debug_menu_entry cameracentricstreamers = { "CAMERA CENTRIC STREAMER", BOOLEAN_E,  &cameracentricstreamer[4 + 0xD] };
				add_debug_menu_entry(devopt_flags_menu, &cameracentricstreamers);


				BYTE* renderlowlods = *(BYTE**)0x0096858C;
				debug_menu_entry renderlowlodss = { "RENDER LOWLODS ", BOOLEAN_E,  &renderlowlods[4 + 0xE] };
				add_debug_menu_entry(devopt_flags_menu, &renderlowlodss);


				BYTE* loadstringhashdictionary = *(BYTE**)0x0096858C;
				debug_menu_entry loadstringhashdictionarys = { "LOAD STRING HASH DICTIONARY ", BOOLEAN_E,  &loadstringhashdictionary[4 + 0xF] };
				add_debug_menu_entry(devopt_flags_menu, &loadstringhashdictionarys);


				BYTE* flag17 = *(BYTE**)0x0096858C;
				debug_menu_entry flags17 = { "LOG RUNTIME STRING HASHES ", BOOLEAN_E,  &flag17[4 + 0x10] };
				add_debug_menu_entry(devopt_flags_menu, &flags17);


				BYTE* flag18 = *(BYTE**)0x0096858C;
				debug_menu_entry flags18 = { "SHOW WATERMARK VELOCITY ", BOOLEAN_E,  &flag18[4 + 0x11] };
				add_debug_menu_entry(devopt_flags_menu, &flags18);


				BYTE* flag19 = *(BYTE**)0x0096858C;
				debug_menu_entry flags19 = { "SHOW STATS ", BOOLEAN_E,  &flag19[4 + 0x12] };
				add_debug_menu_entry(devopt_flags_menu, &flags19);


				BYTE* flag20 = *(BYTE**)0x0096858C;
				debug_menu_entry flags20 = { "ENABLE ZOOM MAP ", BOOLEAN_E,  &flag20[4 + 0x13] };
				add_debug_menu_entry(devopt_flags_menu, &flags20);


				BYTE* flag21 = *(BYTE**)0x0096858C;
				debug_menu_entry flags21 = { "SHOW DEBUG INFO  ", BOOLEAN_E,  &flag21[4 + 0x14] };
				add_debug_menu_entry(devopt_flags_menu, &flags21);


				BYTE* flag23 = *(BYTE**)0x0096858C;
				debug_menu_entry flags23 = { "SHOW LOCOMOTION INFO ", BOOLEAN_E,  &flag23[4 + 0x16] };
				add_debug_menu_entry(devopt_flags_menu, &flags23);



				BYTE* flag24 = *(BYTE**)0x0096858C;
				debug_menu_entry flags24 = { "GRAVITY ", BOOLEAN_E,  &flag24[4 + 0x17] };
				add_debug_menu_entry(devopt_flags_menu, &flags24);


				BYTE* flag25 = *(BYTE**)0x0096858C;
				debug_menu_entry flags25 = { "TEST MEMORY LEAKS ", BOOLEAN_E,  &flag25[4 + 0x18] };
				add_debug_menu_entry(devopt_flags_menu, &flags25);


				BYTE* flag26 = *(BYTE**)0x0096858C;
				debug_menu_entry flags26 = { "HALT ON ASSERTS  ", BOOLEAN_E,  &flag26[4 + 0x19] };
				add_debug_menu_entry(devopt_flags_menu, &flags26);


				BYTE* flag27 = *(BYTE**)0x0096858C;
				debug_menu_entry flags27 = { "SCREEN ASSERTS ", BOOLEAN_E,  &flag27[4 + 0x1A] };
				add_debug_menu_entry(devopt_flags_menu, &flags27);


				BYTE* flag28 = *(BYTE**)0x0096858C;
				debug_menu_entry flags28 = { "NO ANIM WARNINGS ", BOOLEAN_E,  &flag28[4 + 0x1B] };
				add_debug_menu_entry(devopt_flags_menu, &flags28);


				BYTE* flag29 = *(BYTE**)0x0096858C;
				debug_menu_entry flags29 = { "PROFILING ON ", BOOLEAN_E,  &flag29[4 + 0x1C] };
				add_debug_menu_entry(devopt_flags_menu, &flags29);


				BYTE* flag30 = *(BYTE**)0x0096858C;
				debug_menu_entry flags30 = { "MONO AUDIO ", BOOLEAN_E,  &flag30[4 + 0x1D] };
				add_debug_menu_entry(devopt_flags_menu, &flags30);


				BYTE* flag31 = *(BYTE**)0x0096858C;
				debug_menu_entry flags31 = { "NO MESSAGES ", BOOLEAN_E,  &flag31[4 + 0x1E] };
				add_debug_menu_entry(devopt_flags_menu, &flags31);


				BYTE* flag32 = *(BYTE**)0x0096858C;
				debug_menu_entry flags32 = { "LOCK STEP ", BOOLEAN_E,  &flag32[4 + 0x1F] };
				add_debug_menu_entry(devopt_flags_menu, &flags32);


				BYTE* flag33 = *(BYTE**)0x0096858C;
				debug_menu_entry flags33 = { "TEXTURE DUMP ", BOOLEAN_E,  &flag33[4 + 0x20] };
				add_debug_menu_entry(devopt_flags_menu, &flags33);


				BYTE* flag34 = *(BYTE**)0x0096858C;
				debug_menu_entry flags34 = { "DISABLE SOUND WARNINGS ", BOOLEAN_E,  &flag34[4 + 0x21] };
				add_debug_menu_entry(devopt_flags_menu, &flags34);


				BYTE* flag35 = *(BYTE**)0x0096858C;
				debug_menu_entry flags35 = { "DISABLE SOUND DEBUG OUTPUT ", BOOLEAN_E,  &flag35[4 + 0x22] };
				add_debug_menu_entry(devopt_flags_menu, &flags35);


				BYTE* flag36 = *(BYTE**)0x0096858C;
				debug_menu_entry flags36 = { "DELETE UNUSED SOUND BANKS ON PACK ", BOOLEAN_E,  &flag36[4 + 0x23] };
				add_debug_menu_entry(devopt_flags_menu, &flags36);


				BYTE* flag37 = *(BYTE**)0x0096858C;
				debug_menu_entry flags37 = { "LOCKED HERO ", BOOLEAN_E,  &flag37[4 + 0x24] };
				add_debug_menu_entry(devopt_flags_menu, &flags37);


				BYTE* flag38 = *(BYTE**)0x0096858C;
				debug_menu_entry flags38 = { "FOG OVERRIDE ", BOOLEAN_E,  &flag38[4 + 0x25] };
				add_debug_menu_entry(devopt_flags_menu, &flags38);


				BYTE* flag39 = *(BYTE**)0x0096858C;
				debug_menu_entry flags39 = { "FOG DISABLE ", BOOLEAN_E,  &flag39[4 + 0x25] };
				add_debug_menu_entry(devopt_flags_menu, &flags39);


				BYTE* flag40 = *(BYTE**)0x0096858C;
				debug_menu_entry flags40 = { "MOVE EDITOR ", BOOLEAN_E,  &flag40[4 + 0x27] };
				add_debug_menu_entry(devopt_flags_menu, &flags40);


				BYTE* flag41 = *(BYTE**)0x0096858C;
				debug_menu_entry flags41 = { "AI PATH DEBUG ", BOOLEAN_E,  &flag41[4 + 0x28] };
				add_debug_menu_entry(devopt_flags_menu, &flags41);


				BYTE* flag42 = *(BYTE**)0x0096858C;
				debug_menu_entry flags42 = { "AI PATH COLOR ", BOOLEAN_E,  &flag42[4 + 0x29] };
				add_debug_menu_entry(devopt_flags_menu, &flags42);


				BYTE* flag43 = *(BYTE**)0x0096858C;
				debug_menu_entry flags43 = { "AI CRITTER ACTIVITY ", BOOLEAN_E,  &flag43[4 + 0x2A] };
				add_debug_menu_entry(devopt_flags_menu, &flags43);


				BYTE* flag44 = *(BYTE**)0x0096858C;
				debug_menu_entry flags44 = { "AI PATH COLOR CRITTER ", BOOLEAN_E,  &flag44[4 + 0x2B] };
				add_debug_menu_entry(devopt_flags_menu, &flags44);


				BYTE* flag45 = *(BYTE**)0x0096858C;
				debug_menu_entry flags45 = { "AI PATH COLOR HERO ", BOOLEAN_E,  &flag45[4 + 0x2C] };
				add_debug_menu_entry(devopt_flags_menu, &flags45);


				BYTE* flag46 = *(BYTE**)0x0096858C;
				debug_menu_entry flags46 = { "NO PARTICLES ", BOOLEAN_E,  &flag46[4 + 0x2D] };
				add_debug_menu_entry(devopt_flags_menu, &flags46);


				BYTE* flag47 = *(BYTE**)0x0096858C;
				debug_menu_entry flags47 = { "NO PARTICLES PUMP", BOOLEAN_E,  &flag47[4 + 0x2E] };
				add_debug_menu_entry(devopt_flags_menu, &flags47);


				BYTE* flag48 = *(BYTE**)0x0096858C;
				debug_menu_entry flags48 = { "SHOW NORMALS ", BOOLEAN_E,  &flag48[4 + 0x2F] };
				add_debug_menu_entry(devopt_flags_menu, &flags48);


				BYTE* flag49 = *(BYTE**)0x0096858C;
				debug_menu_entry flags49 = { "SHOW SHADOW BALL ", BOOLEAN_E,  &flag49[4 + 0x30] };
				add_debug_menu_entry(devopt_flags_menu, &flags49);


				BYTE* flag50 = *(BYTE**)0x0096858C;
				debug_menu_entry flags50 = { "SHOW LIGHTS ", BOOLEAN_E,  &flag50[4 + 0x31] };
				add_debug_menu_entry(devopt_flags_menu, &flags50);


				BYTE* flag51 = *(BYTE**)0x0096858C;
				debug_menu_entry flags51 = { "SHOW PLRCTRL ", BOOLEAN_E,  &flag51[4 + 0x32] };
				add_debug_menu_entry(devopt_flags_menu, &flags51);


				BYTE* flag52 = *(BYTE**)0x0096858C;
				debug_menu_entry flags52 = { "SHOW PSX INFO ", BOOLEAN_E,  &flag52[4 + 0x33] };
				add_debug_menu_entry(devopt_flags_menu, &flags52);


				BYTE* flag53 = *(BYTE**)0x0096858C;
				debug_menu_entry flags53 = { "FLAT SHADE ", BOOLEAN_E,  &flag53[4 + 0x34] };
				add_debug_menu_entry(devopt_flags_menu, &flags53);


				BYTE* flag54 = *(BYTE**)0x0096858C;
				debug_menu_entry flags54 = { "INTERFACE DISABLE ", BOOLEAN_E,  &flag54[4 + 0x35] };
				add_debug_menu_entry(devopt_flags_menu, &flags54);


				BYTE* flag55 = *(BYTE**)0x0096858C;
				debug_menu_entry flags55 = { "WIDGET TOOLS ", BOOLEAN_E,  &flag55[4 + 0x36] };
				add_debug_menu_entry(devopt_flags_menu, &flags55);


				BYTE* flag56 = *(BYTE**)0x0096858C;
				debug_menu_entry flags56 = { "LIGHTING ", BOOLEAN_E,  &flag56[4 + 0x37] };
				add_debug_menu_entry(devopt_flags_menu, &flags56);


				BYTE* flag57 = *(BYTE**)0x0096858C;
				debug_menu_entry flags57 = { "FAKE POINT LIGHTS ", BOOLEAN_E,  &flag57[4 + 0x38] };
				add_debug_menu_entry(devopt_flags_menu, &flags57);


				BYTE* flag58 = *(BYTE**)0x0096858C;
				debug_menu_entry flags58 = { "BSP SPRAY PAINT  ", BOOLEAN_E,  &flag58[4 + 0x39] };
				add_debug_menu_entry(devopt_flags_menu, &flags58);


				BYTE* flag59 = *(BYTE**)0x0096858C;
				debug_menu_entry flags59 = { "CAMERA EDITOR ", BOOLEAN_E,  &flag59[4 + 0x3A] };
				add_debug_menu_entry(devopt_flags_menu, &flags59);



				BYTE* flag60 = *(BYTE**)0x0096858C;
				debug_menu_entry flags60 = { "IGNORE RAMPING ", BOOLEAN_E,  &flag60[4 + 0x3B] };
				add_debug_menu_entry(devopt_flags_menu, &flags60);


				BYTE* flag61 = *(BYTE**)0x0096858C;
				debug_menu_entry flags61 = { "POINT SAMPLE ", BOOLEAN_E,  &flag61[4 + 0x3C] };
				add_debug_menu_entry(devopt_flags_menu, &flags61);


				BYTE* flag62 = *(BYTE**)0x0096858C;
				debug_menu_entry flags62 = { "DISTANCE FADING ", BOOLEAN_E,  &flag62[4 + 0x3D] };
				add_debug_menu_entry(devopt_flags_menu, &flags62);


				BYTE* flag63 = *(BYTE**)0x0096858C;
				debug_menu_entry flags63 = { "OVERRIDE CONTROLLER OPTIONS ", BOOLEAN_E,  &flag63[4 + 0x3E] };
				add_debug_menu_entry(devopt_flags_menu, &flags63);


				BYTE* flag64 = *(BYTE**)0x0096858C;
				debug_menu_entry flags64 = { "DISABLE MOUSE PLAYER CONTROL ", BOOLEAN_E,  &flag64[4 + 0x3F] };
				add_debug_menu_entry(devopt_flags_menu, &flags64);


				BYTE* flag65 = *(BYTE**)0x0096858C;
				debug_menu_entry flags65 = { "NO MOVIES ", BOOLEAN_E,  &flag65[4 + 0x40] };
				add_debug_menu_entry(devopt_flags_menu, &flags65);


				BYTE* flag66 = *(BYTE**)0x0096858C;
				debug_menu_entry flags66 = { "XBOX USER CAM ", BOOLEAN_E,  &flag66[4 + 0x41] };
				add_debug_menu_entry(devopt_flags_menu, &flags66);


				BYTE* flag67 = *(BYTE**)0x0096858C;
				debug_menu_entry flags67 = { "NO LOAD SCREEN ", BOOLEAN_E,  &flag67[4 + 0x42] };
				add_debug_menu_entry(devopt_flags_menu, &flags67);


				BYTE* flag68 = *(BYTE**)0x0096858C;
				debug_menu_entry flags68 = { "NO EXCEPTION HANDLER ", BOOLEAN_E,  &flag68[4 + 0x43] };
				add_debug_menu_entry(devopt_flags_menu, &flags68);


				BYTE* flag69 = *(BYTE**)0x0096858C;
				debug_menu_entry flags69 = { "NO CD CHECK ", BOOLEAN_E,  &flag69[4 + 0x44] };
				add_debug_menu_entry(devopt_flags_menu, &flags69);


				BYTE* flag70 = *(BYTE**)0x0096858C;
				debug_menu_entry flags70 = { "NO LOAD METER ", BOOLEAN_E,  &flag70[4 + 0x45] };
				add_debug_menu_entry(devopt_flags_menu, &flags70);


				BYTE* flag71 = *(BYTE**)0x0096858C;
				debug_menu_entry flags71 = { "NO MOVIE BUFFER WARNING ", BOOLEAN_E,  &flag71[4 + 0x46] };
				add_debug_menu_entry(devopt_flags_menu, &flags71);


				BYTE* flag72 = *(BYTE**)0x0096858C;
				debug_menu_entry flags72 = { "LIMITED EDITION DISC ", BOOLEAN_E,  &flag72[4 + 0x49] };
				add_debug_menu_entry(devopt_flags_menu, &flags72);


				BYTE* flag73 = *(BYTE**)0x0096858C;
				debug_menu_entry flags73 = { "NEW COMBAT LOCO ", BOOLEAN_E,  &flag73[4 + 0x48] };
				add_debug_menu_entry(devopt_flags_menu, &flags73);


				BYTE* flag74 = *(BYTE**)0x0096858C;
				debug_menu_entry flags74 = { "LEVEL WARP ", BOOLEAN_E,  &flag74[4 + 0x47] };
				add_debug_menu_entry(devopt_flags_menu, &flags74);


				BYTE* flag75 = *(BYTE**)0x0096858C;
				debug_menu_entry flags75 = { "SMOKE TEST ", BOOLEAN_E,  &flag75[4 + 0x4A] };
				add_debug_menu_entry(devopt_flags_menu, &flags75);


				BYTE* flag76 = *(BYTE**)0x0096858C;
				debug_menu_entry flags76 = { "SMOKE TEST LEVEL ", BOOLEAN_E,  &flag76[4 + 0x4B] };
				add_debug_menu_entry(devopt_flags_menu, &flags76);


				BYTE* flag77 = *(BYTE**)0x0096858C;
				debug_menu_entry flags77 = { "COMBO TESTER ", BOOLEAN_E,  &flag77[4 + 0x4C] };
				add_debug_menu_entry(devopt_flags_menu, &flags77);


				BYTE* flag78 = *(BYTE**)0x0096858C;
				debug_menu_entry flags78 = { "DROP SHADOWS ALWAYS RAYCAST ", BOOLEAN_E,  &flag78[4 + 0x4D] };
				add_debug_menu_entry(devopt_flags_menu, &flags78);


				BYTE* flag79 = *(BYTE**)0x0096858C;
				debug_menu_entry flags79 = { "DISABLE DROP SHADOWS ", BOOLEAN_E,  &flag79[4 + 0x4E] };
				add_debug_menu_entry(devopt_flags_menu, &flags79);


				BYTE* flag80 = *(BYTE**)0x0096858C;
				debug_menu_entry flags80 = { "DISABLE HIRES SHADOWS ", BOOLEAN_E,  &flag80[4 + 0x4F] };
				add_debug_menu_entry(devopt_flags_menu, &flags80);


				BYTE* flag81 = *(BYTE**)0x0096858C;
				debug_menu_entry flags81 = { "DISABLE STENCIL SHADOWS ", BOOLEAN_E,  &flag81[4 + 0x50] };
				add_debug_menu_entry(devopt_flags_menu, &flags81);


				BYTE* flag82 = *(BYTE**)0x0096858C;
				debug_menu_entry flags82 = { "DISABLE COLORVOLS ", BOOLEAN_E,  &flag82[4 + 0x51] };
				add_debug_menu_entry(devopt_flags_menu, &flags82);


				BYTE* flag83 = *(BYTE**)0x0096858C;
				debug_menu_entry flags83 = { "DISABLE RENDER ENTS ", BOOLEAN_E,  &flag83[4 + 0x52] };
				add_debug_menu_entry(devopt_flags_menu, &flags83);


				BYTE* flag84 = *(BYTE**)0x0096858C;
				debug_menu_entry flags84 = { "DISABLE FULLSCREEN BLUR ", BOOLEAN_E,  &flag84[4 + 0x53] };
				add_debug_menu_entry(devopt_flags_menu, &flags84);


				BYTE* flag85 = *(BYTE**)0x0096858C;
				debug_menu_entry flags85 = { "FORCE TIGHTCRAWL ", BOOLEAN_E,  &flag85[4 + 0x54] };
				add_debug_menu_entry(devopt_flags_menu, &flags85);


				BYTE* flag86 = *(BYTE**)0x0096858C;
				debug_menu_entry flags86 = { "FORCE NONCRAWL ", BOOLEAN_E,  &flag86[4 + 0x55] };
				add_debug_menu_entry(devopt_flags_menu, &flags86);


				BYTE* flag87 = *(BYTE**)0x0096858C;
				debug_menu_entry flags87 = { "SHOW DEBUG TEXT ", BOOLEAN_E,  &flag87[4 + 0x57] };
				add_debug_menu_entry(devopt_flags_menu, &flags87);


				BYTE* flag88 = *(BYTE**)0x0096858C;
				debug_menu_entry flags88 = { "SHOW STYLE POINTS ", BOOLEAN_E,  &flag88[4 + 0x58] };
				add_debug_menu_entry(devopt_flags_menu, &flags88);


				BYTE* flag89 = *(BYTE**)0x0096858C;
				debug_menu_entry flags89 = { "CAMERA MOUSE MODE ", BOOLEAN_E,  &flag89[4 + 0x59] };
				add_debug_menu_entry(devopt_flags_menu, &flags89);


				BYTE* flag90 = *(BYTE**)0x0096858C;
				debug_menu_entry flags90 = { "USERCAM ON CONTROLLER2 ", BOOLEAN_E,  &flag90[4 + 0x5A] };
				add_debug_menu_entry(devopt_flags_menu, &flags90);


				BYTE* flag91 = *(BYTE**)0x0096858C;
				debug_menu_entry flags91 = { "DISABLE ANCHOR RETICLE RENDERING ", BOOLEAN_E,  &flag91[4 + 0x5B] };
				add_debug_menu_entry(devopt_flags_menu, &flags91);


				BYTE* flag92 = *(BYTE**)0x0096858C;
				debug_menu_entry flags92 = { "SHOW ANCHOR LINE ", BOOLEAN_E,  &flag92[4 + 0x5C] };
				add_debug_menu_entry(devopt_flags_menu, &flags92);


				BYTE* flag93 = *(BYTE**)0x0096858C;
				debug_menu_entry flags93 = { "FREE SPIDER REFLEXES ", BOOLEAN_E,  &flag93[4 + 0x5D] };
				add_debug_menu_entry(devopt_flags_menu, &flags93);


				BYTE* flag94 = *(BYTE**)0x0096858C;
				debug_menu_entry flags94 = { "SHOW BAR OF SHAME ", BOOLEAN_E,  &flag94[4 + 0x5E] };
				add_debug_menu_entry(devopt_flags_menu, &flags94);


				BYTE* flag95 = *(BYTE**)0x0096858C;
				debug_menu_entry flags95 = { "SHOW ENEMY HEALTH WIDGETS ", BOOLEAN_E,  &flag95[4 + 0x5F] };
				add_debug_menu_entry(devopt_flags_menu, &flags95);


				BYTE* flag96 = *(BYTE**)0x0096858C;
				debug_menu_entry flags96 = { "ALLOW IGC PAUSE ", BOOLEAN_E,  &flag96[4 + 0x60] };
				add_debug_menu_entry(devopt_flags_menu, &flags96);


				BYTE* flag97 = *(BYTE**)0x0096858C;
				debug_menu_entry flags97 = { "SHOW DISTRICTS ", BOOLEAN_E,  &flag97[4 + 0x61] };
				add_debug_menu_entry(devopt_flags_menu, &flags97);


				BYTE* flag98 = *(BYTE**)0x0096858C;
				debug_menu_entry flags98 = { "SHOW CHUCK DEBUGGER ", BOOLEAN_E,  &flag98[4 + 0x62] };
				add_debug_menu_entry(devopt_flags_menu, &flags98);


				BYTE* flag99 = *(BYTE**)0x0096858C;
				debug_menu_entry flags99 = { "CHUCK OLD FASHIONED ", BOOLEAN_E,  &flag99[4 + 0x63] };
				add_debug_menu_entry(devopt_flags_menu, &flags99);


				BYTE* flag100 = *(BYTE**)0x0096858C;
				debug_menu_entry flags100 = { "CHUCK DISABLE BREAKPOINTS ", BOOLEAN_E,  &flag100[4 + 0x64] };
				add_debug_menu_entry(devopt_flags_menu, &flags100);


				BYTE* flag101 = *(BYTE**)0x0096858C;
				debug_menu_entry flags101 = { "DISABLE SOUNDS ", BOOLEAN_E,  &flag101[4 + 0x65] };
				add_debug_menu_entry(devopt_flags_menu, &flags101);


				BYTE* flag102 = *(BYTE**)0x0096858C;
				debug_menu_entry flags102 = { "SHOW TERRAIN INFO ", BOOLEAN_E,  &flag102[4 + 0x66] };
				add_debug_menu_entry(devopt_flags_menu, &flags102);


				BYTE* flag103 = *(BYTE**)0x0096858C;
				debug_menu_entry flags103 = { "DISABLE AUDIO BOXES ", BOOLEAN_E,  &flag103[4 + 0x67] };
				add_debug_menu_entry(devopt_flags_menu, &flags103);


				BYTE* flag104 = *(BYTE**)0x0096858C;
				debug_menu_entry flags104 = { "NSL OLD FASHIONED ", BOOLEAN_E,  &flag104[4 + 0x68] };
				add_debug_menu_entry(devopt_flags_menu, &flags104);


				BYTE* flag105 = *(BYTE**)0x0096858C;
				debug_menu_entry flags105 = { "SHOW MASTER CLOCK ", BOOLEAN_E,  &flag105[4 + 0x69] };
				add_debug_menu_entry(devopt_flags_menu, &flags105);


				BYTE* playcityambientmusic = *(BYTE**)0x0096858C;
				debug_menu_entry playcityambientmusics = { "PLAY CITY AMBIENT MUSIC", BOOLEAN_E,  &playcityambientmusic[4 + 0x6A] };
				add_debug_menu_entry(streams_menu, &playcityambientmusics);


				BYTE* flag107 = *(BYTE**)0x0096858C;
				debug_menu_entry flags107 = { "BONUS LEVELS AVAILABLE ", BOOLEAN_E,  &flag107[4 + 0x6B] };
				add_debug_menu_entry(devopt_flags_menu, &flags107);


				BYTE* flag108 = *(BYTE**)0x0096858C;
				debug_menu_entry flags108 = { "COMBAT DISPLAY ", BOOLEAN_E,  &flag108[4 + 0x6C] };
				add_debug_menu_entry(devopt_flags_menu, &flags108);


				BYTE* flag109 = *(BYTE**)0x0096858C;
				debug_menu_entry flags109 = { "COMBAT DEBUGGER ", BOOLEAN_E,  &flag109[4 + 0x6E] };
				add_debug_menu_entry(devopt_flags_menu, &flags109);


				BYTE* flag110 = *(BYTE**)0x0096858C;
				debug_menu_entry flags110 = { "ALLOW ERROR POPUPS ", BOOLEAN_E,  &flag110[4 + 0x6F] };
				add_debug_menu_entry(devopt_flags_menu, &flags110);


				BYTE* flag111 = *(BYTE**)0x0096858C;
				debug_menu_entry flags111 = { "ALLOW WARNING POPUPS ", BOOLEAN_E,  &flag111[4 + 0x70] };
				add_debug_menu_entry(devopt_flags_menu, &flags111);


				BYTE* flag112 = *(BYTE**)0x0096858C;
				debug_menu_entry flags112 = { "OUTPUT WARNING DISABLE ", BOOLEAN_E,  &flag112[4 + 0x71] };
				add_debug_menu_entry(devopt_flags_menu, &flags112);


				BYTE* flag113 = *(BYTE**)0x0096858C;
				debug_menu_entry flags113 = { "OUTPUT ASSERT DISABLE ", BOOLEAN_E,  &flag113[4 + 0x73] };
				add_debug_menu_entry(devopt_flags_menu, &flags113);


				BYTE* flag114 = *(BYTE**)0x0096858C;
				debug_menu_entry flags114 = { "ASSERT ON WARNING ", BOOLEAN_E,  &flag114[4 + 0x74] };
				add_debug_menu_entry(devopt_flags_menu, &flags114);


				BYTE* flag115 = *(BYTE**)0x0096858C;
				debug_menu_entry flags115 = { "ALWAYS ACTIVE ", BOOLEAN_E,  &flag115[4 + 0x75] };
				add_debug_menu_entry(devopt_flags_menu, &flags115);


				BYTE* flag116 = *(BYTE**)0x0096858C;
				debug_menu_entry flags116 = { "FORCE PROGRESSION ", BOOLEAN_E,  &flag116[4 + 0x76] };
				add_debug_menu_entry(devopt_flags_menu, &flags116);


				BYTE* flag117 = *(BYTE**)0x0096858C;
				debug_menu_entry flags117 = { "LINK ", BOOLEAN_E,  &flag117[4 + 0x77] };
				add_debug_menu_entry(devopt_flags_menu, &flags117);


				BYTE* flag118 = *(BYTE**)0x0096858C;
				debug_menu_entry flags118 = { "WAIT FOR LINK ", BOOLEAN_E,  &flag118[4 + 0x78] };
				add_debug_menu_entry(devopt_flags_menu, &flags118);


				BYTE* flag119 = *(BYTE**)0x0096858C;
				debug_menu_entry flags119 = { "SHOW END OF PACK ", BOOLEAN_E,  &flag119[4 + 0x79] };
				add_debug_menu_entry(devopt_flags_menu, &flags119);


				BYTE* flag120 = *(BYTE**)0x0096858C;
				debug_menu_entry live_in_glass_house = { "LIVE_IN_GLASS_HOUSE ", BOOLEAN_E,  &flag120[4 + 0x7A] };
				add_debug_menu_entry(devopt_flags_menu, &live_in_glass_house);

				BYTE* flag121 = *(BYTE**)0x0096858C;
				debug_menu_entry flags121 = { "SHOW GLASS HOUSE ", BOOLEAN_E,  &flag121[4 + 0x7B] };
				add_debug_menu_entry(devopt_flags_menu, &flags121);


				BYTE* flag122 = *(BYTE**)0x0096858C;
				debug_menu_entry flags122 = { "DISABLE RACE PREVIEW ", BOOLEAN_E,  &flag122[4 + 0x7C] };
				add_debug_menu_entry(devopt_flags_menu, &flags122);


				BYTE* flag123 = *(BYTE**)0x0096858C;
				debug_menu_entry flags123 = { "FREE MINI MAP ", BOOLEAN_E,  &flag123[4 + 0x7D] };
				add_debug_menu_entry(devopt_flags_menu, &flags123);


				BYTE* flag124 = *(BYTE**)0x0096858C;
				debug_menu_entry flags124 = { "SHOW LOOPING ANIM WARNINGS ", BOOLEAN_E,  &flag124[4 + 0x7E] };
				add_debug_menu_entry(devopt_flags_menu, &flags124);


				BYTE* flag125 = *(BYTE**)0x0096858C;
				debug_menu_entry flags125 = { "SHOW PERF INFO ", BOOLEAN_E,  &flag125[4 + 0x7F] };
				add_debug_menu_entry(devopt_flags_menu, &flags125);


				BYTE* flag126 = *(BYTE**)0x0096858C;
				debug_menu_entry flags126 = { "COPY ERROR TO CLIPBOARD ", BOOLEAN_E,  &flag126[4 + 0x80] };
				add_debug_menu_entry(devopt_flags_menu, &flags126);


				BYTE* flag127 = *(BYTE**)0x0096858C;
				debug_menu_entry flags127 = { "BOTH HANDS UP REORIENT ", BOOLEAN_E,  &flag127[4 + 0x81] };
				add_debug_menu_entry(devopt_flags_menu, &flags127);


				BYTE* flag128 = *(BYTE**)0x0096858C;
				debug_menu_entry flags128 = { "SHOW CAMERA PROJECTION ", BOOLEAN_E,  &flag128[4 + 0x82] };
				add_debug_menu_entry(devopt_flags_menu, &flags128);


				BYTE* flag129 = *(BYTE**)0x0096858C;
				debug_menu_entry flags129 = { "OLD DEFAULT CONTROL SETTINGS ", BOOLEAN_E,  &flag129[4 + 0x83] };
				add_debug_menu_entry(devopt_flags_menu, &flags129);


				BYTE* flag130 = *(BYTE**)0x0096858C;
				debug_menu_entry flags130 = { "IGC SPEED CONTROL ", BOOLEAN_E,  &flag130[4 + 0x84] };
				add_debug_menu_entry(devopt_flags_menu, &flags130);

				BYTE* flag131 = *(BYTE**)0x0096858C;
				debug_menu_entry flags131 = { "RTDT ENABLED ", BOOLEAN_E,  &flag131[4 + 0x85] };
				add_debug_menu_entry(devopt_flags_menu, &flags131);

				BYTE* flag132 = *(BYTE**)0x0096858C;
				debug_menu_entry flags132 = { "ENABLE DECALS ", BOOLEAN_E,  &flag132[4 + 0x86] };
				add_debug_menu_entry(devopt_flags_menu, &flags132);

				BYTE* flag133 = *(BYTE**)0x0096858C;
				debug_menu_entry flags133 = { "AUTO STICK TO WALLS  ", BOOLEAN_E,  &flag133[4 + 0x87] };
				add_debug_menu_entry(devopt_flags_menu, &flags133);

				BYTE* flag134 = *(BYTE**)0x0096858C;
				debug_menu_entry flags134 = { "ENABLE PEDESTRIANS ", BOOLEAN_E,  &flag134[4 + 0x88] };
				add_debug_menu_entry(devopt_flags_menu, &flags134);

				BYTE* flag135 = *(BYTE**)0x0096858C;
				debug_menu_entry flags135 = { "CAMERA INVERT LOOKAROUND ", BOOLEAN_E,  &flag135[4 + 0x89] };
				add_debug_menu_entry(devopt_flags_menu, &flags135);

				BYTE* flag136 = *(BYTE**)0x0096858C;
				debug_menu_entry flags136 = { "CAMERA INVERT LOOKAROUND X ", BOOLEAN_E,  &flag136[4 + 0x8A] };
				add_debug_menu_entry(devopt_flags_menu, &flags136);

				BYTE* flag137 = *(BYTE**)0x0096858C;
				debug_menu_entry flags137 = { "CAMERA INVERT LOOKAROUND Y ", BOOLEAN_E,  &flag137[4 + 0x8B] };
				add_debug_menu_entry(devopt_flags_menu, &flags137);

				BYTE* flag138 = *(BYTE**)0x0096858C;
				debug_menu_entry flags138 = { "FORCE COMBAT CAMERA OFF ", BOOLEAN_E,  &flag138[4 + 0x8C] };
				add_debug_menu_entry(devopt_flags_menu, &flags138);

				BYTE* flag139 = *(BYTE**)0x0096858C;
				debug_menu_entry flags139 = { "DISPLAY THOUGHT BUBBLES ", BOOLEAN_E,  &flag139[4 + 0x8D] };
				add_debug_menu_entry(devopt_flags_menu, &flags139);

				BYTE* flag140 = *(BYTE**)0x0096858C;
				debug_menu_entry flags140 = { "ENABLE DEBUG LOG", BOOLEAN_E,  &flag140[4 + 0x8E] };
				add_debug_menu_entry(devopt_flags_menu, &flags140);

				BYTE* flag141 = *(BYTE**)0x0096858C;
				debug_menu_entry flags141 = { "ENABLE LONG CALLSTACK ", BOOLEAN_E,  &flag141[4 + 0x8F] };
				add_debug_menu_entry(devopt_flags_menu, &flags141);

				BYTE* flag143 = *(BYTE**)0x0096858C;
				debug_menu_entry flags143 = { "RENDER FE UI ", BOOLEAN_E,  &flag143[4 + 0x90] };
				add_debug_menu_entry(devopt_flags_menu, &flags143);

				BYTE* flag144 = *(BYTE**)0x0096858C;
				debug_menu_entry flags144 = { "LOCK INTERIORS", BOOLEAN_E,  &flag144[4 + 0x91] };
				add_debug_menu_entry(devopt_flags_menu, &flags144);

				BYTE* flag145 = *(BYTE**)0x0096858C;
				debug_menu_entry flags145 = { "MEMCHECK ON LOAD", BOOLEAN_E,  &flag145[4 + 0x92] };
				add_debug_menu_entry(devopt_flags_menu, &flags145);

				BYTE* flag146 = *(BYTE**)0x0096858C;
				debug_menu_entry flags146 = { "DISPLAY ALS USAGE PROFILE", BOOLEAN_E,  &flag146[4 + 0x93] };
				add_debug_menu_entry(devopt_flags_menu, &flags146);

				BYTE* flag147 = *(BYTE**)0x0096858C;
				debug_menu_entry flags147 = { "ENABLE FPU EXCEPTION HANDLING", BOOLEAN_E,  &flag147[4 + 0x94] };
				add_debug_menu_entry(devopt_flags_menu, &flags147);

				BYTE* flag148 = *(BYTE**)0x0096858C;
				debug_menu_entry flags148 = { "UNLOCK ALL UNLOCKABLES", BOOLEAN_E,  &flag148[4 + 0x95] };
				add_debug_menu_entry(devopt_flags_menu, &flags148);


				
				debug_menu_entry camera = { "Camera", BOOLEAN_O,  start_debug };
				add_debug_menu_entry(start_debug, &camera);

			}

			

			if (game_flags_menu->used_slots == 0) {

				BYTE* god_mode = 0x95A6A8;
				debug_menu_entry god_mode_entry = { "God Mode ", BOOLEAN_F,  &god_mode[0] };
				debug_menu_entry mega_god_mode = { "One Hit Kill ", BOOLEAN_F,  &god_mode[1] };
				debug_menu_entry ultra_god_mode = { "Bomb Mode ", BOOLEAN_F,  &god_mode[2] };

				add_debug_menu_entry(game_flags_menu, &god_mode_entry);
				add_debug_menu_entry(game_flags_menu, &mega_god_mode);
				add_debug_menu_entry(game_flags_menu, &ultra_god_mode);

				debug_menu_entry show_fps = { "Show Fps", BOOLEAN_E, 0x975848 };
				add_debug_menu_entry(game_flags_menu, &show_fps);
				debug_menu_entry memory_info = { "Show Memory Info", BOOLEAN_E, 0x975849 };
				add_debug_menu_entry(game_flags_menu, &memory_info);
				debug_menu_entry monkeytime = { "Monkey Time", BOOLEAN_F, 0x959E60 };
				add_debug_menu_entry(game_flags_menu, &monkeytime);
				debug_menu_entry unlockchars = { "Unlock All Characters", BOOLEAN_F, 0x960E1C };
				add_debug_menu_entry(game_flags_menu, &unlockchars);
				debug_menu_entry unlockalllandmarks = { "Unlock All Landmarks", BOOLEAN_F, 0x960E19 };
				add_debug_menu_entry(game_flags_menu, &unlockalllandmarks);
				debug_menu_entry unlockallconceptart = { "Unlock All Concept Art", BOOLEAN_F, 0x960E1A };
				add_debug_menu_entry(game_flags_menu, &unlockallconceptart);
				debug_menu_entry unlockallcovers = { "Unlock All Covers", BOOLEAN_F, 0x960E1B };
				add_debug_menu_entry(game_flags_menu, &unlockallcovers);
				debug_menu_entry disablepausemenu = { "Disable Pause Menu", BOOLEAN_F, 0x96B448 };
				add_debug_menu_entry(game_flags_menu, &disablepausemenu);
				debug_menu_entry enableredwatermark = { "Enable Red Watermark", BOOLEAN_F, 0x96B434 };
				add_debug_menu_entry(game_flags_menu, &enableredwatermark);
				debug_menu_entry testflag = { "TestFlag", BOOLEAN_F, 0x9581BC };
				add_debug_menu_entry(game_flags_menu, &testflag);
				debug_menu_entry savescreenshot = { "Save Screenshot", NORMAL, 0x97584A };
				add_debug_menu_entry(game_flags_menu, &savescreenshot);
				debug_menu_entry weirdflag = { "Weird Flag", BOOLEAN_E, 0x95C1E8 };
				add_debug_menu_entry(game_flags_menu, &weirdflag);
				debug_menu_entry disableenvironment = { "DISABLE ENVIRONMENT", NORMAL, 0x922558 };
				add_debug_menu_entry(game_flags_menu, &disableenvironment);
				debug_menu_entry unloaddistricts = { "UNLOAD DISTRICT", NORMAL, 0x921D79 };
				add_debug_menu_entry(game_flags_menu, &unloaddistricts);
				BYTE* camerastatus = *(BYTE**)0x0096858C;
				debug_menu_entry camera_status = { "Camera Status", BOOLEAN_P,  &camerastatus[4 + 0x15] };
				add_debug_menu_entry(game_flags_menu, &camera_status);


			}
	
				

				if (debug_render_menu->used_slots == 0) {

				debug_menu_entry capsulehistory = { "CAPSULE_HISTORY ", BOOLEAN_F, 0x961168 };
				add_debug_menu_entry(debug_render_menu, &capsulehistory);

				debug_menu_entry lights = { "LIGHTS ", BOOLEAN_F, 0x961178 };
				add_debug_menu_entry(debug_render_menu, &lights);

				debug_menu_entry boxtriggers = { "BOX_TRIGGERS ", BOOLEAN_F, 0x961188 };
				add_debug_menu_entry(debug_render_menu, &boxtriggers);

				debug_menu_entry waterexclusiontriggers = { "WATER_EXCLUSION_TRIGGERS ", BOOLEAN_F, 0x961198 };
				add_debug_menu_entry(debug_render_menu, &waterexclusiontriggers);

				debug_menu_entry pointtriggers = { "POINT_TRIGGERS ", BOOLEAN_F, 0x9611A8 };
				add_debug_menu_entry(debug_render_menu, &pointtriggers);

				debug_menu_entry entitytriggers = { "ENTITY_TRIGGERS ", BOOLEAN_F, 0x9611B8 };
				add_debug_menu_entry(debug_render_menu, &entitytriggers);

				debug_menu_entry interactabletriggers = { "INTERACTABLE_TRIGGERS ", BOOLEAN_F, 0x9611C8 };
				add_debug_menu_entry(debug_render_menu, &interactabletriggers);

				debug_menu_entry occlusion = { "OCCLUSION ", BOOLEAN_F, 0x9611D8 };
				add_debug_menu_entry(debug_render_menu, &occlusion);

				debug_menu_entry legos = { "LEGOS ", BOOLEAN_F, 0x9611E8 };
				add_debug_menu_entry(debug_render_menu, &legos);

				debug_menu_entry regionmeshes = { "REGION_MESHES ", BOOLEAN_F, 0x9611F8 };
				add_debug_menu_entry(debug_render_menu, &regionmeshes);

				debug_menu_entry entities = { "ENTITIES ", BOOLEAN_F, 0x961208 };
				add_debug_menu_entry(debug_render_menu, &entities);

				debug_menu_entry lowlods = { "LOW_LODS ", BOOLEAN_F, 0x961218 };
				add_debug_menu_entry(debug_render_menu, &lowlods);

				debug_menu_entry activityinfo = { "ACTIVITY_INFO ", BOOLEAN_F, 0x961228 };
				add_debug_menu_entry(debug_render_menu, &activityinfo);

				debug_menu_entry renderinfo = { "RENDER_INFO ", BOOLEAN_F, 0x961238 };
				add_debug_menu_entry(debug_render_menu, &renderinfo);

				debug_menu_entry collideinfo = { "COLLIDE_INFO ", BOOLEAN_F, 0x961248 };
				add_debug_menu_entry(debug_render_menu, &collideinfo);

			    debug_menu_entry markers = { "MARKERS ", BOOLEAN_F, 0x961258 };
				add_debug_menu_entry(debug_render_menu, &markers);

				debug_menu_entry parkingmakers = { "PARKING_MARKERS ", BOOLEAN_F, 0x961268 };
				add_debug_menu_entry(debug_render_menu, &parkingmakers);

				debug_menu_entry waterexitmakers = { "WATER_EXIT_MARKERS ", BOOLEAN_F, 0x961278 };
				add_debug_menu_entry(debug_render_menu, &waterexitmakers);

				debug_menu_entry missionmakers = { "MISSION_MARKERS ", BOOLEAN_F, 0x961288 };
				add_debug_menu_entry(debug_render_menu, &missionmakers);

				debug_menu_entry paths = { "PATHS ", BOOLEAN_F, 0x961298 };
				add_debug_menu_entry(debug_render_menu, &paths);

				debug_menu_entry glasshouse = { "GLASS_HOUSE ", BOOLEAN_F, 0x9612A8 };
				add_debug_menu_entry(debug_render_menu, &glasshouse);

				debug_menu_entry obbs = { "OBBS ", BOOLEAN_F, 0x9612B8 };
				add_debug_menu_entry(debug_render_menu, &obbs);

				debug_menu_entry trafficspaths = { "TRAFFIC_PATHS ", BOOLEAN_F, 0x9612C8 };
				add_debug_menu_entry(debug_render_menu, &trafficspaths);

				debug_menu_entry minigame = { "MINI_GAME ", BOOLEAN_F, 0x9612D8 };
				add_debug_menu_entry(debug_render_menu, &minigame);

				debug_menu_entry brains = { "BRAINS ", BOOLEAN_F, 0x9612E8 };
				add_debug_menu_entry(debug_render_menu, &brains);

				debug_menu_entry voice = { "VOICE ", BOOLEAN_F, 0x9612F8 };
				add_debug_menu_entry(debug_render_menu, &voice);

				debug_menu_entry patrols = { "PATROLS ", BOOLEAN_F, 0x961308 };
				add_debug_menu_entry(debug_render_menu, &patrols);

				debug_menu_entry pausetimers = { "PAUSE_TIMERS ", BOOLEAN_F, 0x961318 };
				add_debug_menu_entry(debug_render_menu, &pausetimers);

				debug_menu_entry animinfo = { "ANIM_INFO ", BOOLEAN_F, 0x961328 };
				add_debug_menu_entry(debug_render_menu, &animinfo);

				debug_menu_entry sceneaniminfo = { "SCENE_ANIM_INFO ", BOOLEAN_F, 0x961338 };
				add_debug_menu_entry(debug_render_menu, &sceneaniminfo);

				debug_menu_entry targeting = { "TARGETING ", BOOLEAN_F, 0x961348 };
				add_debug_menu_entry(debug_render_menu, &targeting);

				debug_menu_entry visspheres = { "VIS_SPHERES ", BOOLEAN_F, 0x961358 };
				add_debug_menu_entry(debug_render_menu, &visspheres);

				debug_menu_entry ladders = { "LADDERS ", BOOLEAN_F, 0x961368 };
				add_debug_menu_entry(debug_render_menu, &ladders);

				debug_menu_entry collisions = { "COLLISIONS ", BOOLEAN_F, 0x961378 };
				add_debug_menu_entry(debug_render_menu, &collisions);

				debug_menu_entry brainsenabled = { "BRAINS_ENABLED ", BOOLEAN_F, 0x961388 };
				add_debug_menu_entry(debug_render_menu, &brainsenabled);

				debug_menu_entry anchors = { "ANCHORS ", BOOLEAN_F, 0x961398 };
				add_debug_menu_entry(debug_render_menu, &anchors);

				debug_menu_entry lineinfo = { "LINE_INFO ", BOOLEAN_F, 0x9613A8 };
				add_debug_menu_entry(debug_render_menu, &lineinfo);

				debug_menu_entry subdivision = { "SUBDIVISION ", BOOLEAN_F, 0x9613B8 };
				add_debug_menu_entry(debug_render_menu, &subdivision);

				debug_menu_entry skeletons = { "SKELETONS ", BOOLEAN_F, 0x9613C8 };
				add_debug_menu_entry(debug_render_menu, &skeletons);

				debug_menu_entry soundstreamusage = { "SOUND_STREAM_USAGE ", BOOLEAN_F, 0x9613D8 };
				add_debug_menu_entry(debug_render_menu, &soundstreamusage);

				debug_menu_entry spheres = { "SPHERES ", BOOLEAN_F, 0x9613E8 };
				add_debug_menu_entry(debug_render_menu, &spheres);

				debug_menu_entry lines = { "LINES ", BOOLEAN_F, 0x9613F8 };
				add_debug_menu_entry(debug_render_menu, &lines);

				debug_menu_entry cylinders = { "CYLINDERS ", BOOLEAN_F, 0x961408 };
				add_debug_menu_entry(debug_render_menu, &cylinders);

				debug_menu_entry dgraph = { "DGRAPH ", BOOLEAN_F, 0x961418 };
				add_debug_menu_entry(debug_render_menu, &dgraph);

				debug_menu_entry peds = { "PEDS ", BOOLEAN_F, 0x961428 };
				add_debug_menu_entry(debug_render_menu, &peds);

				debug_menu_entry traffic = { "TRAFFIC ", BOOLEAN_F, 0x961438 };
				add_debug_menu_entry(debug_render_menu, &traffic);

				debug_menu_entry aicovermarkers = { "AI_COVER_MARKERS ", BOOLEAN_F, 0x961458 };
				add_debug_menu_entry(debug_render_menu, &aicovermarkers);

				debug_menu_entry limboglow = { "LIMBO_GLOW ", BOOLEAN_F, 0x961468 };
				add_debug_menu_entry(debug_render_menu, &limboglow);

				debug_menu_entry bipedcollvolumes = { "BIPED_COLL_VOLUMES ", BOOLEAN_F, 0x961478 };
				add_debug_menu_entry(debug_render_menu, &bipedcollvolumes);

				debug_menu_entry decals = { "DECALS ", BOOLEAN_F, 0x961488 };
				add_debug_menu_entry(debug_render_menu, &decals);
				
				

        }
				

				


			
				

				if (devopt_int_menu->used_slots == 0) {


				BYTE* ints0 = *(BYTE**)0X009685DC;
				debug_menu_entry int0 = { "DIFFICULTY", BOOLEAN_F,  &ints0[95 + 0x00] };
				add_debug_menu_entry(devopt_int_menu, &int0);

				BYTE* ints1 = *(BYTE**)0X009685DC;
				debug_menu_entry int1 = { "CAMERA_STYLE", BOOLEAN_F,  &ints1[95 + 0x01] };
				add_debug_menu_entry(devopt_int_menu, &int1);

				BYTE* ints2 = *(BYTE**)0X009685DC;
				debug_menu_entry int2 = { "CAMERA_STATE", BOOLEAN_F,  &ints2[95 + 0x02] };
				add_debug_menu_entry(devopt_int_menu, &int2);

				BYTE* ints3 = *(BYTE**)0X009685DC;
				debug_menu_entry int3 = { "CAMERA_FOV ", BOOLEAN_F,  &ints3[95 + 0x03] };
				add_debug_menu_entry(devopt_int_menu, &int3);

				BYTE* ints4 = *(BYTE**)0X009685DC;
				debug_menu_entry int4 = { "FOG_RED ", BOOLEAN_F,  &ints4[95 + 0x04] };
				add_debug_menu_entry(devopt_int_menu, &int4);

				BYTE* ints5 = *(BYTE**)0X009685DC;
				debug_menu_entry int5 = { "FOG_GREEN", BOOLEAN_F,  &ints5[95 + 0x05] };
				add_debug_menu_entry(devopt_int_menu, &int5);

				BYTE* ints6 = *(BYTE**)0X009685DC;
				debug_menu_entry int6 = { "FOG_DISTANCE", BOOLEAN_F,  &ints6[95 + 0x06] };
				add_debug_menu_entry(devopt_int_menu, &int6);

				BYTE* ints7 = *(BYTE**)0X009685DC;
				debug_menu_entry int7 = { "BIT DEPTH ", BOOLEAN_F,  &ints7[95 + 0x07] };
				add_debug_menu_entry(devopt_int_menu, &int7);

				BYTE* ints8 = (BYTE**)0X009685DC;
				debug_menu_entry int8 = { "MONKEY_MODE ", BOOLEAN_F,  &ints8[95 + 0x08] };
				add_debug_menu_entry(devopt_int_menu, &int8);

				BYTE* ints9 = *(BYTE**)0X009685DC;
				debug_menu_entry int9 = { "RANDOM_SEED", BOOLEAN_F,  &ints9[95 + 0x09] };
				add_debug_menu_entry(devopt_int_menu, &int9);

				BYTE* ints10 = *(BYTE**)0X009685DC;
				debug_menu_entry int10 = { "FORCE_WIN", BOOLEAN_F,  &ints10[95 + 0x0A] };
				add_debug_menu_entry(devopt_int_menu, &int10);

				BYTE* ints11 = *(BYTE**)0X009685DC;
				debug_menu_entry int11 = { "CONTROLLER_TYPE", BOOLEAN_F,  &ints11[95 + 0x0B] };
				add_debug_menu_entry(devopt_int_menu, &int11);

				BYTE* ints12 = *(BYTE**)0X009685DC;
				debug_menu_entry int12 = { "FRAME_LOCK", BOOLEAN_F,  &ints12[95 + 0x0C] };
				add_debug_menu_entry(devopt_int_menu, &int12);

				BYTE* ints13 = *(BYTE**)0X009685DC;
				debug_menu_entry int13 = { "FRAME_LIMIT", BOOLEAN_F,  &ints13[95 + 0x0D] };
				add_debug_menu_entry(devopt_int_menu, &int13);

				BYTE* ints14 = *(BYTE**)0X009685DC;
				debug_menu_entry int14 = { "SWING_DEBUG_TRAILS", BOOLEAN_F,  &ints14[95 + 0x0E] };
				add_debug_menu_entry(devopt_int_menu, &int14);

				BYTE* ints15 = *(BYTE**)0X009685DC;
				debug_menu_entry int15 = { "SOAK_SMOKE", BOOLEAN_F,  &ints15[95 + 0x0F] };
				add_debug_menu_entry(devopt_int_menu, &int15);

				BYTE* ints16 = *(BYTE**)0X009685DC;
				debug_menu_entry int16 = { "FAR_CLIP_PLANE", BOOLEAN_F,  &ints16[95 + 0x10] };
				add_debug_menu_entry(devopt_int_menu, &int16);

				BYTE* ints17 = *(BYTE**)0X009685DC;
				debug_menu_entry int17 = { "POI_DISPLAY_TYPE", BOOLEAN_F,  &ints17[95 + 0x11] };
				add_debug_menu_entry(devopt_int_menu, &int17);

				BYTE* ints18 = *(BYTE**)0X009685DC;
				debug_menu_entry int18 = { "STORY_MISSION", BOOLEAN_F,  &ints18[95 + 0x12] };
				add_debug_menu_entry(devopt_int_menu, &int18);

				BYTE* ints19 = *(BYTE**)0X009685DC;
				debug_menu_entry int19 = { "EXEC_DELAY", BOOLEAN_F,  &ints19[95 + 0x13] };
				add_debug_menu_entry(devopt_int_menu, &int19);

				BYTE* ints20 = *(BYTE**)0X009685DC;
				debug_menu_entry int20 = { "RUN_LENGTH", BOOLEAN_F,  &ints20[95 + 0x14] };
				add_debug_menu_entry(devopt_int_menu, &int20);

				BYTE* ints21 = *(BYTE**)0X009685DC;
				debug_menu_entry int21 = { "PC_WINDOW_TOP", BOOLEAN_F,  &ints21[95 + 0x15] };
				add_debug_menu_entry(devopt_int_menu, &int21);

				BYTE* ints22 = *(BYTE**)0X009685DC;
				debug_menu_entry int22 = { "PC_WINDOW_LEFT", BOOLEAN_F,  &ints22[95 + 0x16] };
				add_debug_menu_entry(devopt_int_menu, &int22);

				BYTE* ints23 = *(BYTE**)0X009685DC;
				debug_menu_entry int23 = { "PC_WINDOW_WIDTH", BOOLEAN_F,  &ints23[95 + 0x17] };
				add_debug_menu_entry(devopt_int_menu, &int23);

				BYTE* ints24 = *(BYTE**)0X009685DC;
				debug_menu_entry int24 = { "PC_WINDOW_HEIGHT", BOOLEAN_F,  &ints24[95 + 0x18] };
				add_debug_menu_entry(devopt_int_menu, &int24);

				BYTE* ints25 = *(BYTE**)0X009685DC;
				debug_menu_entry int25 = { "ALLOW_SCREENSHOT", BOOLEAN_F,  &ints25[95 + 0x19] };
				add_debug_menu_entry(devopt_int_menu, &int25);

				BYTE* ints26 = *(BYTE**)0X009685DC;
				debug_menu_entry int26 = { "AMALGA_REFRESH_INTERVAL", BOOLEAN_F,  &ints26[95 + 0x1A] };
				add_debug_menu_entry(devopt_int_menu, &int26);

				BYTE* ints27 = *(BYTE**)0X009685DC;
				debug_menu_entry int27 = { "ENABLE_LONG_MALOR_ASSERTS", BOOLEAN_F,  &ints27[95 + 0x1B] };
				add_debug_menu_entry(devopt_int_menu, &int27);

				BYTE* ints28 = *(BYTE**)0X009685DC;
				debug_menu_entry int28 = { "GOD MODE ", BOOLEAN_F,  &ints28[95 + 0x1C] };
				add_debug_menu_entry(devopt_int_menu, &int28);

				BYTE* ints29 = *(BYTE**)0X009685DC;
				debug_menu_entry int29 = { "PCLISTBUFFER", BOOLEAN_F,  &ints29[95 + 0x1D] };
				add_debug_menu_entry(devopt_int_menu, &int29);

				BYTE* ints30 = *(BYTE**)0X009685DC;
				debug_menu_entry int30 = { "PCSCRATCHBUFFER", BOOLEAN_F,  &ints30[95 + 0x1E] };
				add_debug_menu_entry(devopt_int_menu, &int1);

				BYTE* ints31 = *(BYTE**)0X009685DC;
				debug_menu_entry int31 = { "PCSCRATCHINDEXBUFFER", BOOLEAN_F,  &ints31[95 + 0x1F] };
				add_debug_menu_entry(devopt_int_menu, &int31);

				BYTE* ints32 = *(BYTE**)0X009685DC;
				debug_menu_entry int32 = { "PCSCRATCHVERTEXBUFFER", BOOLEAN_F,  &ints32[95 + 0x20] };
				add_debug_menu_entry(devopt_int_menu, &int32);


				BYTE* ints33 = *(BYTE**)0X009685DC;
				debug_menu_entry int33 = { "NAL_HEAP_SIZE", BOOLEAN_F,  &ints33[95 + 0x21] };
				add_debug_menu_entry(devopt_int_menu, &int33);

				BYTE* ints34 = *(BYTE**)0X009685DC;
				debug_menu_entry int34 = { "ASSERT_BOX_MARGIN", BOOLEAN_F,  &ints34[95 + 0x22] };
				add_debug_menu_entry(devopt_int_menu, &int34);

				BYTE* ints35 = *(BYTE**)0X009685DC;
				debug_menu_entry int35 = { "ASSERT_TEXT_MARGIN", BOOLEAN_F,  &ints35[95 + 0x23] };
				add_debug_menu_entry(devopt_int_menu, &int35);

				BYTE* ints36 = *(BYTE**)0X009685DC;
				debug_menu_entry int36 = { "ASSERT_FONT_PCT_X", BOOLEAN_F,  &ints36[95 + 0x24] };
				add_debug_menu_entry(devopt_int_menu, &int36);

				BYTE* ints37 = *(BYTE**)0X009685DC;
				debug_menu_entry int37 = { "ASSERT_FONT_PCT_Y", BOOLEAN_F,  &ints37[95 + 0x25] };
				add_debug_menu_entry(devopt_int_menu, &int37);

				BYTE* ints38 = *(BYTE**)0X009685DC;
				debug_menu_entry int38 = { "STREAMER_INFO_FONT_PCT", BOOLEAN_F,  &ints38[95 + 0x26] };
				add_debug_menu_entry(devopt_int_menu, &int38);

				BYTE* ints39 = *(BYTE**)0X009685DC;
				debug_menu_entry int39 = { "DEBUG_INFO_FONT_PCT", BOOLEAN_F,  &ints39[95 + 0x27] };
				add_debug_menu_entry(devopt_int_menu, &int39);

				BYTE* ints40 = *(BYTE**)0X009685DC;
				debug_menu_entry int40 = { "PITCH_FACTOR", BOOLEAN_F,  &ints40[95 + 0x28] };
				add_debug_menu_entry(devopt_int_menu, &int40);

				BYTE* ints41 = *(BYTE**)0X009685DC;
				debug_menu_entry int41 = { "BANK_FACTOR", BOOLEAN_F,  &ints41[95 + 0x29] };
				add_debug_menu_entry(devopt_int_menu, &int41);

				BYTE* ints42 = *(BYTE**)0X009685DC;
				debug_menu_entry int42 = { "SWING_INTERPOLATION_TIME", BOOLEAN_F,  &ints42[95 + 0x2A] };
				add_debug_menu_entry(devopt_int_menu, &int42);

				BYTE* ints43 = *(BYTE**)0X009685DC;
				debug_menu_entry int43 = { "BOTH_HANDS_INTERPOLATION_TIME", BOOLEAN_F,  &ints43[95 + 0x2B] };
				add_debug_menu_entry(devopt_int_menu, &int43);

				BYTE* ints44 = *(BYTE**)0X009685DC;
				debug_menu_entry int44 = { "MEM_DUMP_FRAME", BOOLEAN_F,  &ints44[95 + 0x2C] };
				add_debug_menu_entry(devopt_int_menu, &int44);

				BYTE* ints45 = *(BYTE**)0X009685DC;
				debug_menu_entry int45 = { "HERO_START_X",  BOOLEAN_F,  &ints45[95 + 0x2D] };
				add_debug_menu_entry(devopt_int_menu, &int45);

				BYTE* ints46 = *(BYTE**)0X009685DC;
				debug_menu_entry int46 = { "HERO_START_Y",  BOOLEAN_F,  &ints46[95 + 0x2E] };
				add_debug_menu_entry(devopt_int_menu, &int46);

				BYTE* ints47 = *(BYTE**)0X009685DC;
				debug_menu_entry int47 = { "HERO_START_Z", BOOLEAN_F,  &ints47[95 + 0x2F] };
				add_debug_menu_entry(devopt_int_menu, &int47);

				BYTE* ints48 = *(BYTE**)0X009685DC;
				debug_menu_entry int48 = { "SHOW_SOUND_INFO", BOOLEAN_F,  &ints48[95 + 0x30] };
				add_debug_menu_entry(devopt_int_menu, &int48);

				BYTE* ints49 = *(BYTE**)0X009685DC;
				debug_menu_entry int49 = { "SHOW_VOICE_BOX_INFO", BOOLEAN_F,  &ints49[95 + 0x31] };
				add_debug_menu_entry(devopt_int_menu, &int49);

				BYTE* ints50 = *(BYTE**)0X009685DC;
				debug_menu_entry int50 = { "DEBUG_CAMERA_PITCH_MULTIPLIER", BOOLEAN_F,  &ints50[95 + 0x32] };
				add_debug_menu_entry(devopt_int_menu, &int50);

				BYTE* ints51 = *(BYTE**)0X009685DC;
				debug_menu_entry int51 = { "DEBUG_CAMERA_YAW_MULTIPLIER", BOOLEAN_F,  &ints51[95 + 0x33] };
				add_debug_menu_entry(devopt_int_menu, &int51);

				BYTE* ints52 = *(BYTE**)0X009685DC;
				debug_menu_entry int52 = { "DEBUG_CAMERA_MOVE_MULTIPLIER", BOOLEAN_F,  &ints52[95 + 0x34] };
				add_debug_menu_entry(devopt_int_menu, &int52);

				BYTE* ints53 = *(BYTE**)0X009685DC;
				debug_menu_entry int53 = { "DEBUG_CAMERA_STRAFE_MULTIPLIER", BOOLEAN_F,  &ints53[95 + 0x35] };
				add_debug_menu_entry(devopt_int_menu, &int53);

				BYTE* ints54 = *(BYTE**)0X009685DC;
				debug_menu_entry int54 = { "TAM_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints54[95 + 0x36] };
				add_debug_menu_entry(devopt_int_menu, &int54);

				BYTE* ints55 = *(BYTE**)0X009685DC;
				debug_menu_entry int55 = { "TAM_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints55[95 + 0x37] };
				add_debug_menu_entry(devopt_int_menu, &int55);

				BYTE* ints56 = *(BYTE**)0X009685DC;
				debug_menu_entry int56 = { "THUG_HEALTH_UI_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints56[95 + 0x38] };
				add_debug_menu_entry(devopt_int_menu, &int56);

				BYTE* ints57 = *(BYTE**)0X009685DC;
				debug_menu_entry int57 = { "THUG_HEALTH_UI_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints57[156 + 0x39] };
				add_debug_menu_entry(devopt_int_menu, &int57);

				BYTE* ints58 = *(BYTE**)0X009685DC;
				debug_menu_entry int58 = { "THUG_HEALTH_UI_SCALE_MIN_PERCENT", BOOLEAN_F,  &ints58[156 + 0x3A] };
				add_debug_menu_entry(devopt_int_menu, &int58);

				BYTE* ints59 = *(BYTE**)0X009685DC;
				debug_menu_entry int59 = { "THUG_HEALTH_UI_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints59[156 + 0x3B] };
				add_debug_menu_entry(devopt_int_menu, &int59);

				BYTE* ints60 = *(BYTE**)0X009685DC;
				debug_menu_entry int60 = { "TestInt", BOOLEAN_F,  &ints60[156 + 0x3C] };
				add_debug_menu_entry(devopt_int_menu, &int60);

				BYTE* ints61 = *(BYTE**)0X009685DC;
				debug_menu_entry int61 = { "TestInt2", BOOLEAN_F,  &ints61[156 + 0x3D] };
				add_debug_menu_entry(devopt_int_menu, &int61);

				BYTE* ints62 = *(BYTE**)0X009685DC;
				debug_menu_entry int62 = { "TARGETING_RETICLE_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints62[156 + 0x3E] };
				add_debug_menu_entry(devopt_int_menu, &int62);

				BYTE* ints63 = *(BYTE**)0X009685DC;
				debug_menu_entry int63 = { "TARGETING_RETICLE_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints63[156 + 0x3F] };
				add_debug_menu_entry(devopt_int_menu, &int63);

				BYTE* ints64 = *(BYTE**)0X009685DC;
				debug_menu_entry int64 = { "TARGETING_RETICLE_SCALE_MIN_PERCENT", BOOLEAN_F,  &ints64[156 + 0x40] };
				add_debug_menu_entry(devopt_int_menu, &int64);


				BYTE* ints65 = *(BYTE**)0X009685DC;
				debug_menu_entry int65 = { "HIRES_SCREENSHOT_X", BOOLEAN_F,  &ints65[95 + 0x41] };
				add_debug_menu_entry(devopt_int_menu, &int65);


				BYTE* ints6a = *(BYTE**)0X009685DC;
				debug_menu_entry int6a = { "HIRES_SCREENSHOT_Y", BOOLEAN_F,  &ints6a[156 + 0x42] };
				add_debug_menu_entry(devopt_int_menu, &int6a);

				BYTE* ints66 = *(BYTE**)0X009685DC;
				debug_menu_entry int66 = { "TIME_OF_DAY", BOOLEAN_F,  &ints66[95 + 0x43] };
				add_debug_menu_entry(devopt_int_menu, &int66);

				BYTE* ints67 = *(BYTE**)0X009685DC;
				debug_menu_entry int67 = { "MINI_MAP_ZOOM", BOOLEAN_F,  &ints67[95 + 0x44] };
				add_debug_menu_entry(devopt_int_menu, &int67);

				BYTE* ints68 = *(BYTE**)0X009685DC;
				debug_menu_entry int68 = { "RTDT_REPLAY_BUFFER_SIZE", BOOLEAN_F,  &ints68[95 + 0x45] };
				add_debug_menu_entry(devopt_int_menu, &int68);

				BYTE* ints69 = *(BYTE**)0X009685DC;
				debug_menu_entry int69 = { "TIMER_WIDGET_TIME_DELTA_PERCENT", BOOLEAN_F,  &ints69[95 + 0x46] };
				add_debug_menu_entry(devopt_int_menu, &int69);

				BYTE* ints70 = *(BYTE**)0X009685DC;
				debug_menu_entry int70 = { "DEBUG_PARTICLE_LEVEL", BOOLEAN_F,  &ints70[95 + 0x47] };
				add_debug_menu_entry(devopt_int_menu, &int70);

				BYTE* ints71 = *(BYTE**)0X009685DC;
				debug_menu_entry int71 = { "DEBUG_PARTICLE_MEMORY", BOOLEAN_F,  &ints71[95 + 0x48] };
				add_debug_menu_entry(devopt_int_menu, &int71);

				BYTE* ints72 = *(BYTE**)0X009685DC;
				debug_menu_entry int72 = { "MAX_AEPS_ENTITIES", BOOLEAN_F,  &ints72[95 + 0x49] };
				add_debug_menu_entry(devopt_int_menu, &int72);

				BYTE* ints73 = *(BYTE**)0X009685DC;
				debug_menu_entry int73 = { "MAX_AEPS_SPAWNERS", BOOLEAN_F,  &ints73[95 + 0x4A] };
				add_debug_menu_entry(devopt_int_menu, &int73);

				BYTE* ints74 = *(BYTE**)0X009685DC;
				debug_menu_entry int74 = { "MAX_AEPS_EMITTERS", BOOLEAN_F,  &ints74[95 + 0x4B] };
				add_debug_menu_entry(devopt_int_menu, &int74);

				BYTE* ints75 = *(BYTE**)0X009685DC;
				debug_menu_entry int75 = { "MAX_AEPS_PARTICLES", BOOLEAN_F,  &ints75[95 + 0x4C] };
				add_debug_menu_entry(devopt_int_menu, &int75);

			}


		}

		if (debug_enabled) {



#define SCROLL_SPEED 4
			if (keys[DIK_DOWNARROW]) {

				if (keys[DIK_DOWNARROW] == 1) {
					menu_go_down();
				}
				else if (keys[DIK_DOWNARROW] >= SCROLL_SPEED && keys[DIK_DOWNARROW] % SCROLL_SPEED == 0) {
					menu_go_down();
				}
			}
			else if (keys[DIK_UPARROW]) {

				if (keys[DIK_UPARROW] == 1) {
					menu_go_up();
				}
				else if (keys[DIK_UPARROW] >= SCROLL_SPEED && keys[DIK_UPARROW] % SCROLL_SPEED == 0) {
					menu_go_up();
				}
			}
			else if (keys[DIK_RETURN] == 2) {
				current_menu->handler(&current_menu->entries[current_menu->window_start + current_menu->cur_index], ENTER);
			}
			else if (keys[DIK_SPACE] == 2) {
				current_menu->go_back();
			}
			else if (keys[DIK_LEFTARROW] == 2 || keys[DIK_RIGHTARROW] == 2) {

				debug_menu_entry* cur = &current_menu->entries[current_menu->window_start + current_menu->cur_index];
				if (cur->entry_type == BOOLEAN_E || cur->entry_type == CUSTOM)
					current_menu->handler(cur, (keys[DIK_LEFTARROW] == 2 ? LEFT : RIGHT));
			}


		}

	}


	if (debug_enabled) {
		memset(lpvData, 0, cbData);
	}



	//printf("Device State called %08X %d\n", this, cbData);

	return res;
}

typedef HRESULT(__stdcall* GetDeviceData_ptr)(IDirectInputDevice8*, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
GetDeviceData_ptr GetDeviceDataOriginal = NULL;

HRESULT __stdcall GetDeviceDataHook(IDirectInputDevice8* this, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags) {

	HRESULT res = GetDeviceDataOriginal(this, cbObjectData, rgdod, pdwInOut, dwFlags);


	if (res == DI_OK) {

		printf("All gud\n");
		for (int i = 0; i < *pdwInOut; i++) {


			if (LOBYTE(rgdod[i].dwData) > 0) {

				if (rgdod[i].dwOfs == DIK_SPACE) {

					printf("Pressed escaped\n");
					__debugbreak();
				}
			}
		}
	}
	//printf("Device Data called %08X\n", this);

	return res;
}



typedef HRESULT(__stdcall* IDirectInput8CreateDevice_ptr)(IDirectInput8W*, const GUID*, LPDIRECTINPUTDEVICE8W*, LPUNKNOWN);
IDirectInput8CreateDevice_ptr createDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8CreateDeviceHook(IDirectInput8W* this, const GUID* guid, LPDIRECTINPUTDEVICE8W* device, LPUNKNOWN unk) {

	//printf("CreateDevice %d %d %d %d %d %d %d\n", *guid, GUID_SysMouse, GUID_SysKeyboard, GUID_SysKeyboardEm, GUID_SysKeyboardEm2, GUID_SysMouseEm, GUID_SysMouseEm2);


	HRESULT res = createDeviceOriginal(this, guid, device, unk);

	DWORD* vtbl = (*device)->lpVtbl;
	if (!GetDeviceStateOriginal) {
		GetDeviceStateOriginal = vtbl[9];
		vtbl[9] = GetDeviceStateHook;
	}

	if (!GetDeviceDataOriginal) {
		GetDeviceDataOriginal = vtbl[10];
		vtbl[10] = GetDeviceDataHook;
	}

	return res;
}

typedef HRESULT(__stdcall* IDirectInput8Release_ptr)(IDirectInput8W*);
IDirectInput8Release_ptr releaseDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8ReleaseHook(IDirectInput8W* this) {

	printf("Release\n");

	return releaseDeviceOriginal(this);
}


BOOL CALLBACK EnumDevices(LPCDIDEVICEINSTANCE lpddi, LPVOID buffer) {

	wchar_t wGUID[40] = { 0 };
	char cGUID[40] = { 0 };

	//printf("%d\n", lpddi->guidProduct);
}

typedef HRESULT(__stdcall* DirectInput8Create_ptr)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
HRESULT __stdcall HookDirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	DirectInput8Create_ptr caller = *(void**)0x00987944;
	HRESULT res = caller(hinst, dwVersion, riidltf, ppvOut, punkOuter);


	IDirectInput8** iDir = ppvOut;
	printf("it's me mario %08X %08X\n", ppvOut, (*iDir)->lpVtbl);


	DWORD* vtbl = (DWORD*)(*iDir)->lpVtbl;
	if (!createDeviceOriginal) {
		createDeviceOriginal = vtbl[3];
		vtbl[3] = IDirectInput8CreateDeviceHook;
	}


	//(*iDir)->lpVtbl->EnumDevices(*iDir, DI8DEVCLASS_ALL, EnumDevices, NULL, DIEDFL_ALLDEVICES);
	return res;
}


DWORD hookDirectInputAddress = HookDirectInput8Create;


void update_state() {

	while (1) {
		OutputDebugStringA("PILA %d", 6);
	}
}

typedef int(__fastcall* game_handle_game_states_ptr)(void* this, void* edx, void* a2);
game_handle_game_states_ptr game_handle_game_states_original = 0x0055D510;

int __fastcall game_handle_game_states(void* this, void* edx, void* a2) {

	if (!g_game_ptr) {
		g_game_ptr = this;
	}

	if (changing_model) {


		changing_model--;

		if (!changing_model) {
			mString str;
			mString_constructor(&str, NULL, current_costume);
			world_dynamics_system_add_player(*(DWORD*)g_world_ptr, NULL, &str);
			mString_finalize(&str, NULL, 0);
			game_unpause(g_game_ptr);
		}
	}

	if (changing_mission) {


		changing_mission--;

		if (!changing_mission) {

			mString str;
			mString_constructor(&str, NULL, current_mission);
			world_dynamics_system_add_player(*(DWORD*)g_world_ptr, NULL, &str);
			mString_finalize(&str, NULL, 0);
			game_unpause(g_game_ptr);
		}
	}


	/*
	if (game_get_cur_state(this) == 14)
		__debugbreak();
		*/


		//printf("Current state %d %08X\n", game_get_cur_state(this), g_game_ptr);

	return game_handle_game_states_original(this, edx, a2);
}

typedef void(__fastcall* sub_41F9D0_ptr)(char* this, void* edx, const char* a2, signed int a3);
sub_41F9D0_ptr sub_41F9D0 = 0x41F9D0;


void __fastcall sub_41F9D0_hook(char* this, void* edx, const char* a2, signed int a3) {

	//printf("mString:%s\n", a2);


	return sub_41F9D0(this, edx, a2, a3);
}

typedef DWORD(__fastcall* ai_hero_base_state_check_transition_ptr)(DWORD* this, void* edx, DWORD* a2, int a3);
ai_hero_base_state_check_transition_ptr ai_hero_base_state_check_transition = 0x00478D80;

DWORD __fastcall ai_hero_base_state_check_transition_hook(DWORD* this, void* edx, DWORD* a2, int a3) {
	ai_current_player = this;
	return ai_hero_base_state_check_transition(this, edx, a2, a3);
}


typedef DWORD* (__fastcall* get_info_node_ptr)(void* this, void* edx, int a2, char a3);
get_info_node_ptr get_info_node = 0x006A3390;

DWORD* __fastcall get_info_node_hook(void* this, void* edx, int a2, char a3) {

	DWORD* res = get_info_node(this, edx, a2, a3);

	fancy_player_ptr = res;
	return res;
}


typedef int(_fastcall* resource_pack_streamer_load_internal_ptr)(void* this, void* edx, char* str, int a3, int a4, int a5);
resource_pack_streamer_load_internal_ptr resource_pack_streamer_load_internal = 0x0054C580;

void __fastcall resource_pack_streamer_load_internal_hook(void* this, void* edx, char* str, int a3, int a4, int a5) {


	return resource_pack_streamer_load_internal(this, edx, str, a3, a4, a5);
}


uint8_t __fastcall os_developer_options_flag(BYTE* this, void* edx, int flag) {

	char** flag_list = 0x936420;
	char* flag_text = flag_list[flag];

	uint8_t res = this[flag + 4];

	if (flag == 0x90) {
		printf("Game wants to know about: %d (%s) -> %d\n", flag, flag_text, res);
		__debugbreak();
	}


	//this[5 + 4] = 1;

	return res;
}

int __fastcall os_developer_options_int(DWORD* this, void* eax, int ints)
{
	char** ints_list = 0x936940;
	char* ints_text = ints_list[ints];

	uint8_t res = this[ints + 95];

	if (ints == 0x4C) {
		printf("Game wants to know about: %d (%s) -> %d\n", ints, ints_text, res);
		__debugbreak();
	}
	// this[5 + 95] = 1;
	return res;
}

void install_patches() {

	HookFunc(0x004EACF0, (DWORD)aeps_RenderAll, 0, "Patching call to aeps::RenderAll");

	HookFunc(0x0052B5D7, (DWORD)myDebugMenu, 0, "Hooking nglListEndScene to inject debug menu");
	//save orig ptr
	nflSystemOpenFile_orig = *nflSystemOpenFile_data;
	*nflSystemOpenFile_data = &nflSystemOpenFile;
	printf("Replaced nflSystemOpenFile %08X -> %08X\n", (DWORD)nflSystemOpenFile_orig, (DWORD)&nflSystemOpenFile);


	ReadOrWrite_orig = *ReadOrWrite_data;
	*ReadOrWrite_data = &ReadOrWrite;
	printf("Replaced ReadOrWrite %08X -> %08X\n", (DWORD)ReadOrWrite_orig, (DWORD)&ReadOrWrite);


	*(DWORD*)0x008218B2 = &hookDirectInputAddress;
	printf("Patching the DirectInput8Create call\n");


	HookFunc(0x0055D742, (DWORD)game_handle_game_states, 0, "Hooking handle_game_states");

	HookFunc(0x00421128, (DWORD)sub_41F9D0_hook, 0, "Hooking sub_41F9D0");


	/*
	WriteDWORD(0x00877524, ai_hero_base_state_check_transition_hook, "Hooking check_transition for peter hooded");
	WriteDWORD(0x00877560, ai_hero_base_state_check_transition_hook, "Hooking check_transition for spider-man");
	WriteDWORD(0x0087759C, ai_hero_base_state_check_transition_hook, "Hooking check_transition for venom");
	*/

	HookFunc(0x00478DBF, get_info_node_hook, 0, "Hook get_info_node to get player ptr");


	WriteDWORD(0x0089C710, slf__create_progression_menu_entry, "Hooking first ocurrence of create_progression_menu_entry");
	WriteDWORD(0x0089C718, slf__create_progression_menu_entry, "Hooking second ocurrence of create_progression_menu_entry");

	WriteDWORD(0x0089AF70, slf__create_debug_menu_entry, "Hooking first ocurrence of create_debug_menu_entry");
	WriteDWORD(0x0089C708, slf__create_debug_menu_entry, "Hooking second  ocurrence of create_debug_menu_entry");


	HookFunc(0x005AD77D, construct_client_script_libs_hook, 0, "Hooking construct_client_script_libs to inject my vm");

	WriteDWORD(0x0089C720, slf__destroy_debug_menu_entry__debug_menu_entry, "Hooking destroy_debug_menu_entry");
	WriteDWORD(0x0089C750, slf__debug_menu_entry__set_handler__str, "Hooking set_handler");

	//HookFunc(0x0054C89C, resource_pack_streamer_load_internal_hook, 1, "Hooking resource_pack_streamer::load_internal to inject interior loading");

	//HookFunc(0x005B87E0, os_developer_options_flag, 1, "Hooking os_developer_options::get_flag");
	//HookFunc(0x005B8810, os_developer_options_int, 1, "Hooking os_developer_options::get_int");

}

void close_debug() {
	debug_enabled = 0;
	game_pause(g_game_ptr);
}

void handle_debug_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}





typedef char(__fastcall* entity_tracker_manager_get_the_arrow_target_pos_ptr)(DWORD* this, void* edx, DWORD* a2);
entity_tracker_manager_get_the_arrow_target_pos_ptr entity_tracker_manager_get_the_arrow_target_pos = 0x0062EE10;

void handle_warp_entry(debug_menu_entry* entry) {


	float position[] = {
		0, -0, 1, 0,
		1, -0, -0, 0,
		0, 1, 0, 0,
		-203, 20, 430, 1
	};

	/*
	DWORD arg1 = *(DWORD*)0x96C158;
	DWORD* some_ptr = ai_ai_core_get_info_node(ai_current_player[5], NULL, arg1, 1);
	printf("WHYYYY %08X %08X\n", fancy_player_ptr, some_ptr);
	*/


	float final_pos[3] = { -203, 20, 430 };
	if (entry->data1 == 0) {
		region* cur_region = entry->data;
		final_pos[0] = cur_region->x;
		final_pos[1] = cur_region->y;
		final_pos[2] = cur_region->z;
		unlock_region(cur_region);
	}
	else {
		int res = entity_tracker_manager_get_the_arrow_target_pos(*(*(DWORD***)0x937B18 + 21), NULL, final_pos);
		if (!res)
			return;
	}

	position[12] = final_pos[0];
	position[13] = final_pos[1];
	position[14] = final_pos[2];

	close_debug();
	entity_teleport_abs_po(fancy_player_ptr[3], position, 1);
}






void handle_hero_entry(debug_menu_entry* entry) {

	DWORD* some_number = (*(DWORD**)g_world_ptr) + 142;

	while (*some_number) {
		//printf("some_number %d\n", *some_number);
		world_dynamics_system_remove_player(*(DWORD*)g_world_ptr, NULL, *some_number - 1);
	}

	debug_enabled = 1;
	changing_model = 2;
	current_costume = entry->text;
	BYTE* val = entry->data;
	*val = !*val;
	close_debug();
}




void handle_mission_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}


void handle_streams_entry(debug_menu_entry* entry) {
	BYTE* val = entry->data;
	*val = !*val;

}


void handle_jf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_jg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kh_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_lf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;


}

void handle_lg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}
void handle_lh_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}




















void handle_game_flags_entry(debug_menu_entry* entry, debug_menu_entry* enter) {

	BYTE* val = entry->data;
	*val = !*val;
	
	
}



typedef void* (__fastcall* script_instance_add_thread_ptr)(script_instance* this, void* edx, vm_executable* a1, void* a2);
script_instance_add_thread_ptr script_instance_add_thread = 0x005AAD00;

void handle_progression_select_entry(debug_menu_entry* entry) {

	script_instance* instance = entry->data;
	int functionid = entry->data1;

	DWORD addr = entry;

	script_instance_add_thread(instance, NULL, instance->object->vmexecutable[functionid], &addr);
	close_debug();
}


void handle_memory_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}

void handle_script_entry(debug_menu_entry* entry) {
	handle_progression_select_entry(entry);
}


void handle_devopt_flags_entry(debug_menu_entry* entry) {

	BYTE* val = entry->data;
	*val = !*val;
}


void handle_devopt_int_entry(debug_menu_entry* entry) {

	DWORD* val = entry->data;
	*val = !*val;
}

void handle_level_select_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}


void handle_debug_render_entry(debug_menu_entry* entry) {
	BYTE* val = entry->data;
	*val = !*val;

}

void handle_replay_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}

void handle_ai_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}

void handle_ai_1_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_entity_variants_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}

void handle_entity_1_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_entity_2_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_3_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_4_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_5_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_6_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_7_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_8_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_9_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_10_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}
void handle_entity_11_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_codesize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_initdatasize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_uninitsize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_stacksize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_savegame_opt_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_slabs_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_scriptmemtrack_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}


void handle_distriction_variants_select_entry(debug_menu_entry* entry, custom_key_type key_type) {

	region* reg = entry->data;
	void* terrain_ptr = *(*(DWORD***)g_world_ptr + 0x6B);
	int variants = reg->variants;
	int current_variant = region_get_district_variant(reg);
	DWORD district_id = reg->district_id;

	switch (key_type) {

	case LEFT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant - 1, variants), 1);
		break;
	case RIGHT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant + 1, variants), 1);
		break;
	default:
		return;
	}
}

void handle_game_entry(debug_menu_entry* entry, custom_key_type key_type) {

current_menu = entry->data;

}










	



void setup_debug_menu() {

	start_debug = create_menu("Debug Menu", close_debug, handle_debug_entry, 2);
	warp_menu = create_menu("Warp", goto_start_debug, handle_warp_entry, 300);
	game_menu = create_menu("Game", goto_start_debug, handle_game_entry, 4);
	game_flags_menu = create_menu("Game Flags", goto_start_debug, handle_game_flags_entry, 7);
	devopt_flags_menu = create_menu("Devopt Flags", goto_start_debug, handle_devopt_flags_entry, 150);
	devopt_int_menu = create_menu("Devopt Ints", goto_start_debug, handle_devopt_int_entry, 76);
	savegame_opt_menu = create_menu("Saved Game Settings", goto_start_debug, handle_savegame_opt_entry, 1);
	mission_menu = create_menu("Missions", goto_start_debug, handle_mission_entry, 1);
	jf = create_menu("JF", goto_start_debug, handle_jf_entry, 1);
	jg = create_menu("JG", goto_start_debug, handle_jg_entry, 1);
	kf = create_menu("KF", goto_start_debug, handle_kf_entry, 1);
	kg = create_menu("KG", goto_start_debug, handle_kg_entry, 1);
	kh = create_menu("KH", goto_start_debug, handle_kh_entry, 1);
	lf = create_menu("LH", goto_start_debug, handle_lf_entry, 1);
	lg = create_menu("LG", goto_start_debug, handle_lg_entry, 1);
	lh = create_menu("LH", goto_start_debug, handle_lh_entry, 1);
	debug_render_menu = create_menu("Debug Render", goto_start_debug, handle_debug_render_entry, 2);
	district_variants_menu = create_menu("District variants", goto_start_debug, handle_distriction_variants_select_entry, 15);
	replay_menu = create_menu("Replay", close_debug, handle_replay_entry, 2);
	ai_menu = create_menu("AI", goto_start_debug, handle_ai_entry, 2);
	ai_0 = create_menu("0x003ac42e", goto_start_debug, handle_ai_1_entry, 2);
	memory_menu = create_menu("Memory", goto_start_debug, handle_memory_entry, 2);
	scriptmemtrack_menu = create_menu("Script Memtrack", goto_start_debug, handle_scriptmemtrack_entry, 2);
	slabs_menu = create_menu("Slabs", goto_start_debug, handle_slabs_entry, 2);
	stacksize_menu = create_menu("Stack Size KB", goto_start_debug, handle_stacksize_entry, 2);
	initsize_menu = create_menu("Init Data Size", goto_start_debug, handle_initdatasize_entry, 2);
	codesize_menu = create_menu("Code Size KB", goto_start_debug, handle_codesize_entry, 2);
	uninitsize_menu = create_menu("Uninit Data Size", goto_start_debug, handle_uninitsize_entry, 2);
	entity_menu = create_menu("Entity", goto_start_debug, handle_entity_variants_entry, 2);
	entity_1 = create_menu("0x008230d88", goto_start_debug, handle_entity_1_entry, 1);
	entity_2 = create_menu("0x008230d89", goto_start_debug, handle_entity_2_entry, 1);
	entity_3 = create_menu("0x008230d8a", goto_start_debug, handle_entity_3_entry, 1);
	entity_4 = create_menu("0x008230d8b", goto_start_debug, handle_entity_4_entry, 1);
	entity_5 = create_menu("0x008230d8c", goto_start_debug, handle_entity_5_entry, 1);
	entity_6 = create_menu("0x008230d8d", goto_start_debug, handle_entity_6_entry, 1);
	entity_7 = create_menu("0x008230d8e", goto_start_debug, handle_entity_7_entry, 1);
	entity_8 = create_menu("0x008230d8f", goto_start_debug, handle_entity_8_entry, 1);
	entity_9 = create_menu("0x008230d90", goto_start_debug, handle_entity_9_entry, 1);
	entity_10 = create_menu("0x008230d91", goto_start_debug, handle_entity_10_entry, 1);
	entity_11 = create_menu("0x008230d92", goto_start_debug, handle_entity_11_entry, 1);
	level_select_menu = create_menu("Level Select", goto_start_debug, handle_level_select_entry, 2);
	hero_menu = create_menu("Hero", goto_start_debug, handle_hero_entry, 5);
	script_menu = create_menu("Script", goto_start_debug, handle_script_entry, 50);
	progression_menu = create_menu("Progression", goto_start_debug, handle_progression_select_entry, 10);
	streams_menu = create_menu("Streams", goto_start_debug, handle_streams_entry, 2);



	debug_menu_entry warp_entry = { "Warp", BOOLEAN_G, warp_menu };
	debug_menu_entry game_entry = { "Game", BOOLEAN_G, game_menu };
	debug_menu_entry game_flags_entry = { "Game Flags", BOOLEAN_G, game_flags_menu };
	debug_menu_entry devopt_flags_entry = { "Devopt Flags", BOOLEAN_G, devopt_flags_menu };
	debug_menu_entry devopt_int_entry = { "Devopt Ints", BOOLEAN_G, devopt_int_menu };
	debug_menu_entry savegame_opt_entry = { "Saved Game Settings", BOOLEAN_G, savegame_opt_menu };
	debug_menu_entry mission_entry = { "Missions", BOOLEAN_G, mission_menu };
	debug_menu_entry debug_render_select_entry = { "Debug Render", BOOLEAN_G, debug_render_menu };
	debug_menu_entry district_entry = { "District variants", BOOLEAN_G, district_variants_menu };
	debug_menu_entry replay_entry = { "Replay", BOOLEAN_G, replay_menu };
	debug_menu_entry ai_entry = { "AI", BOOLEAN_G, ai_menu };
	debug_menu_entry memory_entry = { "Memory", BOOLEAN_G, memory_menu };
	debug_menu_entry scriptmemtrack_entry = { "Script Memtrack", BOOLEAN_G, scriptmemtrack_menu };
	debug_menu_entry slabs_entry = { "Slabs", BOOLEAN_G, slabs_menu };
	debug_menu_entry entity_select_entry = { "Entity", BOOLEAN_G, entity_menu };
	debug_menu_entry level_select_entry = { "Level Select", BOOLEAN_G, level_select_menu };
	debug_menu_entry hero_entry = { "Hero Select", BOOLEAN_G, hero_menu };
	debug_menu_entry script_entry = { "Script", BOOLEAN_G, script_menu };
	debug_menu_entry progression_entry = { "Progression", BOOLEAN_G, progression_menu };
	debug_menu_entry streams_entry = { "Streams", BOOLEAN_G, streams_menu };




	add_debug_menu_entry(start_debug, &warp_entry);
	add_debug_menu_entry(start_debug, &game_entry);
	add_debug_menu_entry(game_menu, &devopt_flags_entry);
	add_debug_menu_entry(game_menu, &devopt_int_entry);
	add_debug_menu_entry(game_menu, &savegame_opt_entry);
	add_debug_menu_entry(game_menu, &game_flags_entry);
	add_debug_menu_entry(start_debug, &mission_entry);
	add_debug_menu_entry(start_debug, &debug_render_select_entry);
	add_debug_menu_entry(start_debug, &district_entry);
	add_debug_menu_entry(start_debug, &replay_entry);
	add_debug_menu_entry(start_debug, &ai_entry);
	add_debug_menu_entry(start_debug, &memory_entry);
	add_debug_menu_entry(memory_menu, &scriptmemtrack_entry);
	add_debug_menu_entry(memory_menu, &slabs_entry);
	add_debug_menu_entry(start_debug, &entity_select_entry);
	add_debug_menu_entry(start_debug, &level_select_entry);
	add_debug_menu_entry(level_select_menu, &hero_entry);
	add_debug_menu_entry(start_debug, &script_entry);
	add_debug_menu_entry(start_debug, &progression_entry);
	add_debug_menu_entry(start_debug, &streams_entry);







	debug_menu_entry start = { "Start", NORMAL, replay_menu };
	add_debug_menu_entry(replay_menu, &start);


	debug_menu_entry jf_entry = { "JF", BOOLEAN_G, jf };
	add_debug_menu_entry(mission_menu, &jf_entry);
	debug_menu_entry jg_entry = { "JG", BOOLEAN_G, jg };
	add_debug_menu_entry(mission_menu, &jg_entry);
	debug_menu_entry kf_entry = { "KF", BOOLEAN_G, kf };
	add_debug_menu_entry(mission_menu, &kf_entry);
	debug_menu_entry kg_entry = { "KG", BOOLEAN_G, kg };
	add_debug_menu_entry(mission_menu, &kg_entry);
	debug_menu_entry kh_entry = { "KH", BOOLEAN_G, kh };
	add_debug_menu_entry(mission_menu, &kh_entry);
	debug_menu_entry lf_entry = { "LF", BOOLEAN_G, lf };
	add_debug_menu_entry(mission_menu, &lf_entry);
	debug_menu_entry lg_entry = { "LG", BOOLEAN_G, lg };
	add_debug_menu_entry(mission_menu, &lg_entry);



	debug_menu_entry ai_1_entry = { "0x003ac42e", BOOLEAN_G, ai_0 };
	add_debug_menu_entry(ai_menu, &ai_1_entry);
	debug_menu_entry entity_1_entry = { "0x008230d88", BOOLEAN_G, entity_1 };
	add_debug_menu_entry(entity_menu, &entity_1_entry);
	debug_menu_entry entity_2_entry = { "0x008230d89", BOOLEAN_G, entity_2 };
	add_debug_menu_entry(entity_menu, &entity_2_entry);
	debug_menu_entry entity_3_entry = { "0x008230d8a", BOOLEAN_G, entity_3 };
	add_debug_menu_entry(entity_menu, &entity_3_entry);
	debug_menu_entry entity_4_entry = { "0x008230d8b", BOOLEAN_G, entity_4 };
	add_debug_menu_entry(entity_menu, &entity_4_entry);
	debug_menu_entry entity_5_entry = { "0x008230d8c", BOOLEAN_G, entity_5 };
	add_debug_menu_entry(entity_menu, &entity_5_entry);
	debug_menu_entry entity_6_entry = { "0x008230d8d", BOOLEAN_G, entity_6 };
	add_debug_menu_entry(entity_menu, &entity_6_entry);
	debug_menu_entry entity_7_entry = { "0x008230d8e", BOOLEAN_G, entity_7 };
	add_debug_menu_entry(entity_menu, &entity_7_entry);
	debug_menu_entry entity_8_entry = { "0x008230d8f", BOOLEAN_G, entity_8 };
	add_debug_menu_entry(entity_menu, &entity_8_entry);
	debug_menu_entry entity_9_entry = { "0x008230d90", BOOLEAN_G, entity_9 };
	add_debug_menu_entry(entity_menu, &entity_9_entry);
	debug_menu_entry entity_10_entry = { "0x008230d91", BOOLEAN_G, entity_10 };
	add_debug_menu_entry(entity_menu, &entity_10_entry);
	debug_menu_entry entity_11_entry = { "0x008230d92", BOOLEAN_G, entity_11 };
	add_debug_menu_entry(entity_menu, &entity_11_entry);
	debug_menu_entry codesize_entry = { "Code Size KB", BOOLEAN_I, memory_menu };
	add_debug_menu_entry(memory_menu, &codesize_entry);
	debug_menu_entry initdatasize_entry = { "Init Data Size KB", BOOLEAN_L, memory_menu };
	add_debug_menu_entry(memory_menu, &initdatasize_entry);
	debug_menu_entry uninitdatasize_entry = { "Uninit Data Size KB", BOOLEAN_M, memory_menu };
	add_debug_menu_entry(memory_menu, &uninitdatasize_entry);
	debug_menu_entry stacksize_entry = { "Stack Size KB", BOOLEAN_N, memory_menu };
	add_debug_menu_entry(memory_menu, &stacksize_entry);


	debug_menu_entry venom_ = { "venom", BOOLEAN_E, 0x984564, NULL };
	add_debug_menu_entry(hero_menu, &venom_);

	debug_menu_entry carnage = { "carnage", BOOLEAN_E, 0x984563, NULL };
	carnage.data1 = 1;
	add_debug_menu_entry(hero_menu, &carnage);

	debug_menu_entry ultimate_spiderman = { "ultimate_spiderman", BOOLEAN_E, 0x987A20, NULL };
	ultimate_spiderman.data1 = 1;
	add_debug_menu_entry(hero_menu, &ultimate_spiderman);

	debug_menu_entry venom_spider = { "venom_spider", BOOLEAN_E, 0x987980, NULL };
	venom_spider.data1 = 1;
	add_debug_menu_entry(hero_menu, &venom_spider);

	debug_menu_entry rhino = { "rhino", BOOLEAN_E, 0x9879D0, NULL };
	rhino.data1 = 1;
	add_debug_menu_entry(hero_menu, &rhino);

	debug_menu_entry electro_nosuit = { "electro_nosuit", BOOLEAN_E, 0x97DA0D, NULL };
	electro_nosuit.data1 = 1;
	add_debug_menu_entry(hero_menu, &electro_nosuit);

	debug_menu_entry electro_suit = { "electro_suit", BOOLEAN_E, 0x987A70, NULL };
	electro_suit.data1 = 1;
	add_debug_menu_entry(hero_menu, &electro_suit);

	debug_menu_entry carnage_01 = { "carnage_01", BOOLEAN_E, 0x984565, NULL };
	carnage_01.data1 = 1;
	add_debug_menu_entry(hero_menu, &carnage_01);

	debug_menu_entry wolverine = { "wolverine", BOOLEAN_E, 0x984BC0, NULL };
	wolverine.data1 = 1;
	add_debug_menu_entry(hero_menu, &wolverine);

	debug_menu_entry silver_sable = { "silver_sable", BOOLEAN_E, 0x97DA0C, NULL };
	silver_sable.data1 = 1;
	add_debug_menu_entry(hero_menu, &silver_sable);

	debug_menu_entry mary_jane = { "mary_jane", BOOLEAN_E, 0x97DA2B, NULL };
	mary_jane.data1 = 1;
	add_debug_menu_entry(hero_menu, &mary_jane);

	debug_menu_entry arachno_man_costume = { "arachno_man_costume", BOOLEAN_E, 0x97DA2A, NULL };
	arachno_man_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &arachno_man_costume);

	debug_menu_entry peter_hooded_costume = { "peter_hooded_costume", BOOLEAN_E, 0x97DA29, NULL };
	peter_hooded_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_hooded_costume);

	debug_menu_entry peter_parker_costume = { "peter_parker_costume", BOOLEAN_E, 0x97DA28, NULL};
	peter_parker_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_parker_costume);

	debug_menu_entry peter_parker = { "peter_parker", BOOLEAN_E, 0x97DA33, NULL };
	peter_parker.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_parker);

	debug_menu_entry peter_hooded = { "peter_hooded", BOOLEAN_E, 0x97DA32, NULL };
	peter_hooded.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_hooded);

	debug_menu_entry green_goblin = { "green_goblin", BOOLEAN_E, 0x97DA31, NULL };
	green_goblin.data1 = 1;
	add_debug_menu_entry(hero_menu, &green_goblin);


	debug_menu_entry venom_spider_lite = { "venom_spider_lite", BOOLEAN_E, 0x982470, NULL };
	venom_spider_lite.data1 = 1;
	add_debug_menu_entry(hero_menu, &venom_spider_lite);

	debug_menu_entry city = { "city", NORMAL, level_select_menu };
	city.data1 = NULL;
	add_debug_menu_entry(level_select_menu, &city);

	debug_menu_entry reboot = { "-- REBOOT --", NORMAL, level_select_menu };
	add_debug_menu_entry(level_select_menu, &reboot);

	/*
	for (int i = 0; i < 5; i++) {
		debug_menu_entry asdf;
		sprintf(asdf.text, "entry %d", i);
		printf("AQUI %s\n", asdf.text);
		add_debug_menu_entry(start_debug, &asdf);
	}
	add_debug_menu_entry(start_debug, &teste);
	*/





}





	BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID reserverd) {
		



	if (sizeof(region) != 0x134) {
		__debugbreak();

	}

	memset(keys, 0, sizeof(keys));
	if (fdwReason == DLL_PROCESS_ATTACH) {
		FreeConsole();



		setup_debug_menu();
		set_text_writeable();
		set_rdata_writeable();
		install_patches();

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
		FreeConsole();

	return TRUE;
}



int main() {
	return 0;
}


	if (cur_time <= 4 * period_duration) {

		int adjusted_time = cur_time - 3 * period_duration;
		float calc = 1.f - ratio * adjusted_time;

		return min(calc, 1.0f) * 255;
	}

}


typedef struct _list {
	struct _list* next;
	struct _list* prev;
	void* data;
}list;

typedef struct {
	BYTE unk[256];//not sure how big
}mString;

#define MAX_CHARS_SAFE 63
#define MAX_CHARS MAX_CHARS_SAFE+1
#define EXTEND_NEW_ENTRIES 20
#define MAX_ELEMENTS_PAGE 18

#pragma pack(1)
typedef struct {
	uint8_t unk[0x50];
	uint8_t status;
	uint8_t unk1[0x53];
	float x;
	float y;
	float z;
	uint8_t unk2[0x10];
	DWORD district_id;
	uint8_t unk3[0x4];
	uint8_t variants;
	uint8_t unk4[0x6B];
}region;


typedef enum {
	NORMAL,
	BOOLEAN_E,
	BOOLEAN_F,
	BOOLEAN_G,
	BOOLEAN_H,
	BOOLEAN_I,
	BOOLEAN_L,
	BOOLEAN_M,
	BOOLEAN_N,
	BOOLEAN_O,
	BOOLEAN_P,
	BOOLEAN_X,
	TEST,
	CUSTOM
}debug_menu_entry_type;


typedef enum {
	LEFT,
	RIGHT,
	ENTER
}custom_key_type;


struct _debug_menu_entry;
typedef char* (*custom_string_generator_ptr)(struct _debug_menu_entry* entry);

typedef struct _debug_menu_entry {

	char text[MAX_CHARS];
	debug_menu_entry_type entry_type;
	void* data;
	void* data1;
	custom_string_generator_ptr custom_string_generator;
}debug_menu_entry;

typedef void (*menu_handler_function)(debug_menu_entry*, custom_key_type key_type);
typedef void (*go_back_function)();

typedef struct {
	char title[MAX_CHARS];
	DWORD capacity;
	DWORD used_slots;
	DWORD window_start;
	DWORD cur_index;
	go_back_function go_back;
	menu_handler_function handler;
	debug_menu_entry* entries;
}debug_menu;



debug_menu* start_debug = NULL;
debug_menu* warp_menu = NULL;
debug_menu* game_menu = NULL;
debug_menu* game_flags_menu = NULL;
debug_menu* district_variants_menu = NULL;
debug_menu* hero_menu = NULL;
debug_menu* script_menu = NULL;
debug_menu* progression_menu = NULL;
debug_menu* devopt_flags_menu = NULL;
debug_menu* devopt_int_menu = NULL;
debug_menu* savegame_opt_menu = NULL;
debug_menu* level_select_menu = NULL;
debug_menu* mission_menu = NULL;
debug_menu* jf = NULL;
debug_menu* jg = NULL;
debug_menu* kf = NULL;
debug_menu* kg = NULL;
debug_menu* kh = NULL;
debug_menu* lf = NULL;
debug_menu* lg = NULL;
debug_menu* lh = NULL;
debug_menu* debug_render_menu = NULL;
debug_menu* replay_menu = NULL;
debug_menu* ai_menu = NULL;
debug_menu* memory_menu = NULL;
debug_menu* scriptmemtrack_menu = NULL;
debug_menu* slabs_menu = NULL;
debug_menu* stacksize_menu = NULL;
debug_menu* uninitsize_menu = NULL;
debug_menu* initsize_menu = NULL;
debug_menu* codesize_menu = NULL;
debug_menu* streams_menu = NULL; 
debug_menu* entity_menu = NULL;
debug_menu* ai_0 = NULL;
debug_menu* entity_0 = NULL;
debug_menu* entity_1 = NULL;
debug_menu* entity_2 = NULL;
debug_menu* entity_3 = NULL;
debug_menu* entity_4 = NULL;
debug_menu* entity_5 = NULL;
debug_menu* entity_6 = NULL;
debug_menu* entity_7 = NULL;
debug_menu* entity_8 = NULL;
debug_menu* entity_9 = NULL;
debug_menu* entity_10 = NULL;
debug_menu* entity_11 = NULL;



debug_menu** all_menus[] = {
	&start_debug,
	&warp_menu,
	&game_menu,
	&game_flags_menu,
	&district_variants_menu,
	&hero_menu,
	&script_menu,
	&progression_menu,
	&devopt_flags_menu,
	&devopt_int_menu,
	&level_select_menu,
	&mission_menu,
	&debug_render_menu,
	&replay_menu,
	&ai_menu,
	&memory_menu,
	&streams_menu,
	&entity_menu
};

debug_menu* current_menu = NULL;



void goto_start_debug() {
	current_menu = start_debug;
}



void unlock_region(region* cur_region) {

	cur_region->status &= 0xFE;
}

void remove_debug_menu_entry(debug_menu_entry* entry) {


	DWORD to_be = (DWORD)entry;
	for (int i = 0; i < (sizeof(all_menus) / sizeof(void*)); i++) {

		debug_menu* cur = *all_menus[i];

		DWORD start = cur->entries;
		DWORD end = start + cur->used_slots * sizeof(debug_menu_entry);

		if (start <= entry && entry < end) {


			int index = (to_be - start) / sizeof(debug_menu_entry);

			memcpy(&cur->entries[index], &cur->entries[index + 1], cur->used_slots - (index + 1));
			memset(&cur->entries[cur->used_slots - 1], 0, sizeof(debug_menu_entry));
			cur->used_slots--;
			return;
		}

	}

	printf("FAILED TO DEALLOCATE AN ENTRY :S %08X\n", entry);

}

void* add_debug_menu_entry(debug_menu* menu, debug_menu_entry* entry) {

	if (menu->used_slots < menu->capacity) {
		void* ret = &menu->entries[menu->used_slots];
		memcpy(ret, entry, sizeof(debug_menu_entry));
		menu->used_slots++;
		return ret;
	}
	else {
		DWORD current_entries_size = sizeof(debug_menu_entry) * menu->capacity;
		DWORD new_entries_size = sizeof(debug_menu_entry) * EXTEND_NEW_ENTRIES;


		void* new_ptr = realloc(menu->entries, current_entries_size + new_entries_size);

		if (!new_ptr) {
			printf("RIP\n");
			__debugbreak();
		}
		else {

			menu->capacity += EXTEND_NEW_ENTRIES;
			menu->entries = new_ptr;
			memset(&menu->entries[menu->used_slots], 0, new_entries_size);

			return add_debug_menu_entry(menu, entry);
		}
	}
}




debug_menu* create_menu(const char* title, go_back_function go_back, menu_handler_function function, DWORD capacity) {

	debug_menu* menu = malloc(sizeof(debug_menu));
	memset(menu, 0, sizeof(debug_menu));

	strncpy(menu->title, title, MAX_CHARS_SAFE);

	menu->capacity = capacity;
	menu->handler = function;
	menu->go_back = go_back;

	DWORD total_entries_size = sizeof(debug_menu_entry) * capacity;
	menu->entries = malloc(total_entries_size);
	memset(menu->entries, 0, total_entries_size);

	return menu;

}


int vm_debug_menu_entry_garbage_collection_id = -1;

typedef int (*script_manager_register_allocated_stuff_callback_ptr)(void* func);
script_manager_register_allocated_stuff_callback_ptr script_manager_register_allocated_stuff_callback = 0x005AFE40;

typedef int (*construct_client_script_libs_ptr)();
construct_client_script_libs_ptr construct_client_script_libs = 0x0058F9C0;


void vm_debug_menu_entry_garbage_collection_callback(void* a1, list* lst) {

	list* end = lst->prev;

	for (list* cur = end->next; cur != end; cur = cur->next) {

		debug_menu_entry* entry = ((debug_menu_entry*)cur->data);
		//printf("Will delete %s %08X\n", entry->text, entry);
		remove_debug_menu_entry(entry);
	}

}

int construct_client_script_libs_hook() {


	if (vm_debug_menu_entry_garbage_collection_id == -1) {
		int res = script_manager_register_allocated_stuff_callback(vm_debug_menu_entry_garbage_collection_callback);
		vm_debug_menu_entry_garbage_collection_id = res;
	}
	return construct_client_script_libs();
}


typedef (__fastcall* mString_constructor_ptr)(mString* this, void* edx, char* str);
mString_constructor_ptr mString_constructor = 0x00421100;

typedef (__fastcall* mission_stack_manager_push_mission_pack_ptr)(DWORD* this, int, int, int, char);
mission_stack_manager_push_mission_pack_ptr mission_stack_manager_push_mission_pack = 0x005D7FE0;

typedef (__fastcall* mission_stack_manager_insert_mission_pack_ptr)(DWORD* this, int, int, int);
mission_stack_manager_insert_mission_pack_ptr mission_stack_manager_insert_mission_pack = 0x005D7FE0;

typedef (__fastcall* mString_finalize_ptr)(mString* this, void* edx, int zero);
mString_finalize_ptr mString_finalize = 0x004209C0;


typedef (__fastcall* mString_mString_ptr)(mString* this, const char* a2);
mString_mString_ptr mString_mString = 0x00421100;


region** all_regions = 0x0095C924;
DWORD* number_of_allocated_regions = 0x0095C920;

typedef (__fastcall* region_get_name_ptr)(void* this);
region_get_name_ptr region_get_name = 0x00519BB0;


typedef int(__fastcall* region_get_district_variant_ptr)(region* this);
region_get_district_variant_ptr region_get_district_variant = 0x005503D0;


typedef char(__fastcall* terrain_set_district_variant_ptr)(void* this, void* edx, DWORD district_id, int variant, char one);
terrain_set_district_variant_ptr terrain_set_district_variant = 0x00557480;

void set_text_writeable() {

	const DWORD text_end = 0x86F000;
	const DWORD text_start = 0x401000;

	DWORD old;
	VirtualProtect((void*)text_start, text_end - text_start, PAGE_EXECUTE_READWRITE, &old);
}

void set_rdata_writeable() {

	const DWORD end = 0x91B000;
	const DWORD start = 0x86F564;

	DWORD old;
	VirtualProtect((void*)start, end - start, PAGE_READWRITE, &old);
}

void HookFunc(DWORD callAdd, DWORD funcAdd, BOOLEAN jump, const unsigned char* reason) {

	//Only works for E8/E9 hooks	
	DWORD jmpOff = funcAdd - callAdd - 5;

	BYTE shellcode[] = { 0, 0, 0, 0, 0 };
	shellcode[0] = jump ? 0xE9 : 0xE8;

	memcpy(&shellcode[1], &jmpOff, sizeof(jmpOff));
	memcpy((void*)callAdd, shellcode, sizeof(shellcode));

	if (reason)
		printf("Hook: %08X -  %s\n", callAdd, reason);

}


void WriteDWORD(DWORD* address, DWORD newValue, const unsigned char* reason) {
	*address = newValue;
	if (reason)
		printf("Wrote: %08X -  %s\n", address, reason);
}

typedef int (*nflSystemOpenFile_ptr)(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove);
nflSystemOpenFile_ptr nflSystemOpenFile_orig = NULL;

nflSystemOpenFile_ptr* nflSystemOpenFile_data = (void*)0x0094985C;


HANDLE USM_handle = INVALID_HANDLE_VALUE;

int nflSystemOpenFile(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove) {


	//printf("Opening file %s\n", lpFileName);
	int ret = nflSystemOpenFile_orig(hHandle, lpFileName, a3, liDistanceToMove);


	if (strstr(lpFileName, "ultimate_spiderman.PCPACK")) {

	}
	return ret;
}



typedef int (*ReadOrWrite_ptr)(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite);
ReadOrWrite_ptr* ReadOrWrite_data = (void*)0x0094986C;
ReadOrWrite_ptr ReadOrWrite_orig = NULL;

int ReadOrWrite(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite) {

	int ret = ReadOrWrite_orig(a1, a2, a3, a4, lpBuffer, nNumberOfBytesToWrite);

	if (USM_handle == *a2) {
		printf("USM buffer was read %08X\n", (DWORD)lpBuffer);


	}
	return ret;
}


typedef void (*aeps_RenderAll_ptr)();
aeps_RenderAll_ptr aeps_RenderAll_orig = (void*)0x004D9310;

void** nglSysFont = (void**)0x00975208;

typedef void (*nglListAddString_ptr)(void* font, float x, float y, float z, DWORD color, float x_scale, float y_scale, char* format, ...);
nglListAddString_ptr nglListAddString = (void*)0x00779E90;



#define nglColor(r,g,b,a) ( (a << 24) |  (r << 16) | (g << 8) | (b & 255) )


typedef struct {
	BYTE unk[100];
}nglQuad;

typedef void (*nglInitQuad_ptr)(void*);
nglInitQuad_ptr nglInitQuad = (void*)0x0077AC40;


typedef void (*nglSetQuadRect_ptr)(void*, float, float, float, float);
nglSetQuadRect_ptr nglSetQuadRect = 0x0077AD30;


typedef void (*nglSetQuadColor_ptr)(void*, unsigned int);
nglSetQuadColor_ptr nglSetQuadColor = 0x0077AD10;


typedef void (*nglListAddQuad_ptr)(void*);
nglListAddQuad_ptr nglListAddQuad = 0x0077AFE0;


typedef int (*nglListBeginScene_ptr)(int);
nglListBeginScene_ptr nglListBeginScene = 0x0076C970;


typedef void (*nglListEndScene_ptr)();
nglListEndScene_ptr nglListEndScene = 0x00742B50;


typedef void (*nglSetQuadZ_ptr)(void*, float);
nglSetQuadZ_ptr nglSetQuadZ = 0x0077AD70;

typedef void (*nglSetClearFlags_ptr)(int);
nglSetClearFlags_ptr nglSetClearFlags = 0x00769DB0;

void aeps_RenderAll() {



	static cur_time = 0;
	int period = 60;
	int duration = 6 * period;
	float ratio = 1.f / period;

	uint8_t red = color_ramp_function(ratio, period, cur_time + 2 * period) + color_ramp_function(ratio, period, cur_time - 4 * period);
	uint8_t green = color_ramp_function(ratio, period, cur_time);
	uint8_t blue = color_ramp_function(ratio, period, cur_time - 2 * period);

	nglListAddString(*nglSysFont, 0.1f, 0.2f, 0.2f, nglColor(red, green, blue, 255), 1.f, 1.f, "");

	cur_time = (cur_time + 1) % duration;


	aeps_RenderAll_orig();
}


int debug_enabled = 0;
uint32_t keys[256];




typedef int (*nglGetStringDimensions_ptr)(int, char* EndPtr, int*, int*, float, float);
nglGetStringDimensions_ptr nglGetStringDimensions = 0x007798E0;



void getStringDimensions(char* str, int* width, int* height) {
	nglGetStringDimensions(*nglSysFont, str, width, height, 1.0, 1.0);
}

int getStringHeight(char* str) {
	int height;
	nglGetStringDimensions(*nglSysFont, str, NULL, &height, 1.0, 1.0);
	return height;
}


char* getRealText(debug_menu_entry* entry, char* str) {


	if (entry->entry_type == BOOLEAN_E) {
		BYTE* val = entry->data;
		sprintf(str, "%s: %s", entry->text, *val ? "True" : "False");
		return str;
	}


	
	if (entry->entry_type == BOOLEAN_H) {
		BYTE* num = entry->data;
		sprintf(str, "%s: %s", entry->text, *num ? "User" : "Chase");

		return str;
	}

	if (entry->entry_type == BOOLEAN_G) {
		BYTE* num = entry->data;
		sprintf(str, "%s: >", entry->text);

		return str;
	}

	if (entry->entry_type == BOOLEAN_I) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 7327", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_L) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 883", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_M) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 22", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_N) {
		BYTE* val = entry->data;
		sprintf(str, "%s: 64", entry->text);
		return str;
	}

	if (entry->entry_type == BOOLEAN_O) {
		BYTE* val = entry->data;
		sprintf(str, "%s: Chase", entry->text);
		return str;
	}



	if (entry->entry_type == BOOLEAN_P) {
		BYTE* num = entry->data;
		sprintf(str, "%s: %s", entry->text, *num ? "Off" : "On");

		return str;
	}

	if (entry->entry_type == BOOLEAN_F) {
		BYTE* val = entry->data;
		sprintf(str, "%s: %s", entry->text, *val ? "1" : "0");
	    return str;

	}
	if (entry->entry_type == CUSTOM) {

		return entry->custom_string_generator(entry);
	}


	return entry->text;


}




void render_current_debug_menu() {



	char text_buffer[128];
#define UP_ARROW " ^ ^ ^ "
#define DOWN_ARROW " v v v "


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	int needs_down_arrow = ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) ? 1 : 0;


	int cur_width, cur_height;
	int debug_width = 0;
	int debug_height = 0;

#define get_and_update(x) {\
	 getStringDimensions(x, &cur_width, &cur_height); \
	 debug_height += cur_height; \
	 debug_width = max(debug_width, cur_width);\
	}
	//printf("new size: %s %d %d (%d %d)\n", x, debug_width, debug_height, cur_width, cur_height); \

	get_and_update(current_menu->title);
	get_and_update(UP_ARROW);





	int total_elements_page = needs_down_arrow ? MAX_ELEMENTS_PAGE : current_menu->used_slots - current_menu->window_start;

	for (int i = 0; i < total_elements_page; i++) {

		debug_menu_entry* entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		get_and_update(cur);
	}


	if (needs_down_arrow) {
		get_and_update(DOWN_ARROW);
	}

	nglQuad quad;


	int menu_x_start = 20, menu_y_start = 40;
	int menu_x_pad = 24, menu_y_pad = 18;

	nglInitQuad(&quad);
	nglSetQuadRect(&quad, menu_x_start, menu_y_start, menu_x_start + debug_width + menu_x_pad, menu_y_start + debug_height + menu_y_pad);
	nglSetQuadColor(&quad, 0xBE0A0A0A);
	nglSetQuadZ(&quad, 0.5f);
	nglListAddQuad(&quad);


	int white_color = nglColor(255, 255, 255, 255);
	int yellow_color = nglColor(255, 255, 0, 255);
	int green_color = nglColor(0, 255, 0, 255);
	int pink_color = nglColor(255, 0, 255, 255);


	int render_height = menu_y_start;
	render_height += 12;
	int render_x = menu_x_start;
	render_x += 8;
	nglListAddString(*nglSysFont, render_x, render_height, 0.2f, green_color, 1.f, 1.f, current_menu->title);
	render_height += getStringHeight(current_menu->title);


	if (current_menu->window_start) {
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, pink_color, 1.f, 1.f, UP_ARROW);
	}
	render_height += getStringHeight(UP_ARROW);



	for (int i = 0; i < total_elements_page; i++) {

		int current_color = current_menu->cur_index == i ? yellow_color : white_color;

		debug_menu_entry* entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, current_color, 1.f, 1.f, cur);
		render_height += getStringHeight(cur);
	}

	if (needs_down_arrow) {
		nglListAddString(*nglSysFont, render_x, render_height, 0.2f, pink_color, 1.f, 1.f, DOWN_ARROW);
		render_height += getStringHeight(DOWN_ARROW);
	}




}
void myDebugMenu() {


	if (debug_enabled) {
		render_current_debug_menu();
	}
	nglListEndScene();
}


typedef int (*wndHandler_ptr)(HWND, UINT, WPARAM, LPARAM);
wndHandler_ptr orig_WindowHandler = 0x005941A0;

int WindowHandler(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

	switch (Msg) {
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_KEYUP:
	case WM_KEYDOWN:
	case WM_INPUT:
		printf("swallowed keypress\n");
		return;
	}

	return orig_WindowHandler(hwnd, Msg, wParam, lParam);

}

/*
	STDMETHOD(GetDeviceState)(THIS_ DWORD,LPVOID) PURE;
	STDMETHOD(GetDeviceData)(THIS_ DWORD,LPDIDEVICEOBJECTDATA,LPDWORD,DWORD) PURE;
*/


typedef int(__stdcall* GetDeviceState_ptr)(IDirectInputDevice8*, DWORD, LPVOID);
GetDeviceState_ptr GetDeviceStateOriginal = NULL;


typedef (__fastcall* game_pause_unpause_ptr)(void* this);
game_pause_unpause_ptr game_pause = 0x0054FBE0;
game_pause_unpause_ptr game_unpause = 0x0053A880;




typedef (__fastcall* game_get_cur_state_ptr)(void* this);
game_get_cur_state_ptr game_get_cur_state = 0x005363D0;



typedef (__fastcall* world_dynamics_system_remove_player_ptr)(void* this, void* edx, int number);
world_dynamics_system_remove_player_ptr world_dynamics_system_remove_player = 0x00558550;


typedef (__fastcall* world_dynamics_system_add_player_ptr)(void* this, void* edx, mString* str);
world_dynamics_system_add_player_ptr world_dynamics_system_add_player = 0x0055B400;


DWORD changing_model = 0;
char* current_costume = "ultimate_spiderman";

DWORD changing_mission = 0;
char* current_mission = "city";



typedef (*entity_teleport_abs_po_ptr)(DWORD, float*, int one);
entity_teleport_abs_po_ptr entity_teleport_abs_po = 0x004F3890;


typedef DWORD* (__fastcall* ai_ai_core_get_info_node_ptr)(DWORD* this, void* edx, int a2, char a3);
ai_ai_core_get_info_node_ptr ai_ai_core_get_info_node = 0x006A3390;



struct vm_executable;



typedef struct {
	uint8_t unk[0x20];
	struct vm_executable** vmexecutable;
}script_object;

typedef struct {
	uint8_t unk[0x2C];
	script_object* object;
}script_instance;


typedef struct {
	DWORD unk;
}script_executable;

typedef struct unknown_struct {
	DWORD unk;
	script_executable* scriptexecutable;
}unknown_struct;

typedef struct vm_executable {
	unknown_struct* unk_struct;
	DWORD unk[2];
	DWORD params;
}vm_executable;

typedef struct {
	uint8_t unk[0xC];
	script_instance* instance;
	vm_executable* vmexecutable;
}vm_thread;

typedef struct {
	uint8_t unk[0x184];
	DWORD stack_ptr;
	vm_thread* thread;
}slf;



typedef struct {
	DWORD unk[32];
}string_hash;

typedef void(__fastcall* test_ptr)(int a1, int a2, float a3);
test_ptr test = 0x005BACA0;


typedef void(__fastcall* string_hash_initialize_ptr)(string_hash* this, void* edx, int a2, char* Str1, int a4);
string_hash_initialize_ptr string_hash_initialize = 0x00547A00;


typedef int(__fastcall* script_object_find_func_ptr)(script_object* this, void* edx, string_hash* a2);
script_object_find_func_ptr script_object_find_func = 0x0058EF80;


typedef DWORD(__fastcall* script_executable_add_allocated_stuff_ptr)(script_executable* this, void* edx, int a2, int a3, int a4);
script_executable_add_allocated_stuff_ptr script_executable_add_allocated_stuff = 0x005A34B0;

void vm_stack_push(slf* function, void* data, DWORD size) {
	memcpy(function->stack_ptr, data, size);
	function->stack_ptr += size;
}

void vm_stack_pop(slf* function, DWORD size) {
	function->stack_ptr -= size;
}




void __stdcall missions(DWORD* this, int unk)
{

	if (!strncmp(*(const char**)(unk + 8), "fade", 0xFFFFu))
	{
		test((int)this, unk, 1.0);
	}
	else
	{
		DWORD* mission = (*(DWORD**)g_game_ptr) + 357;
		mString_mString((mString*)&this, (const char*)&mission);
		mString_mString((mString*)&this, "loading screen");
		mission_stack_manager_push_mission_pack((DWORD*)(int)&unk, (int)&unk, NULL, 0, this, 0);
		mString_mString(&mission, "title_");
		mString_mString((mString*)&this, "loading screen");
	}
}


uint8_t __stdcall slf__debug_menu_entry__set_handler__str(slf* function, void* unk) {

	vm_stack_pop(function, 8);

	void** params = (void**)function->stack_ptr;

	debug_menu_entry* entry = params[0];
	char* scrpttext = params[1];


	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, scrpttext, 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(DWORD*)&strhash);
	entry->data = instance;
	entry->data1 = functionid;

	return 1;
}

uint8_t __stdcall slf__destroy_debug_menu_entry__debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	debug_menu_entry** entry = (void*)function->stack_ptr;

	remove_debug_menu_entry(*entry);

	return 1;
}


uint8_t __stdcall slf__create_progression_menu_entry(slf* function, void* unk) {


	vm_stack_pop(function, 8);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s -> %s\n", strs[0], strs[1]);


	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, strs[1], 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(DWORD*)&strhash);

	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	entry.data = instance;
	entry.data1 = functionid;

	strcpy(entry.text, strs[0]);

	add_debug_menu_entry(progression_menu, &entry);






	/*
	if(function->thread->instance->object->vmexecutable[functionid]->params != 4)
	*/

	int push = 0;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}




uint8_t __stdcall slf__create_debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s ", strs[0]);


	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	strcpy(entry.text, strs[0]);

	void* res = add_debug_menu_entry(script_menu, &entry);

	script_executable* se = function->thread->vmexecutable->unk_struct->scriptexecutable;
	script_executable_add_allocated_stuff(se, NULL, vm_debug_menu_entry_garbage_collection_id, res, 0);

	//printf("%08X\n", res);

	int push = res;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}


DWORD modulo(int num, DWORD mod) {
	if (num >= 0) {
		return num % mod;
	}

	int absolute = abs(num);
	if (absolute % mod == 0)
		return 0;


	return mod - absolute % mod;
}


void menu_go_down() {


	if ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) {

		if (current_menu->cur_index < MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index++;
		else
			current_menu->window_start++;
	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index + 1, num_elements);
		if (current_menu->cur_index == 0)
			current_menu->window_start = 0;
	}
}

void menu_go_up() {


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	if (current_menu->window_start) {


		if (current_menu->cur_index > MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index--;
		else
			current_menu->window_start--;

	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index - 1, num_elements);
		if (current_menu->cur_index == (num_elements - 1))
			current_menu->window_start = current_menu->used_slots - num_elements;

	}

}

int sort_warp_entries(debug_menu_entry* entry1, debug_menu_entry* entry2) {
	return strcmp(entry1->text, entry2->text);
}


char* district_variant_string_generator(debug_menu_entry* entry) {

	char buffer[128];
	sprintf(buffer, "%s: %d", entry->text, region_get_district_variant(entry->data));
	return buffer;
}


HRESULT __stdcall GetDeviceStateHook(IDirectInputDevice8* this, DWORD cbData, LPVOID lpvData) {


	HRESULT res = GetDeviceStateOriginal(this, cbData, lpvData);


	//keyboard time babyyy
	if (cbData == 256) {

		BYTE* keysCurrent = lpvData;

		for (int i = 0; i < 256; i++) {

			if (keysCurrent[i]) {
				keys[i]++;
			}
			else {
				keys[i] = 0;
			}
		}

		int game_state = 0;
		if (g_game_ptr)
			game_state = game_get_cur_state(g_game_ptr);


		//debug menu stuff
		if (keys[DIK_X] == 2 && (game_state == 6 || game_state == 7)) {

			if (!debug_enabled && game_state == 7) {
				game_unpause(g_game_ptr);
				debug_enabled = !debug_enabled;
				current_menu = start_debug;
			}
			else if (!debug_enabled && game_state == 6) {
				game_pause(g_game_ptr);
				debug_enabled = !debug_enabled;
				current_menu = start_debug;
			}

			if (warp_menu->used_slots == 0) {

				debug_menu_entry poi = { "--- WARP TO POI ---", NORMAL, NULL };
				poi.data1 = 1;
				add_debug_menu_entry(warp_menu, &poi);

				for (int i = 0; i < *number_of_allocated_regions; i++) {
					region* cur_region = &(*all_regions)[i];
					char* region_name = region_get_name(cur_region);

					debug_menu_entry warp_entry = { "", NORMAL, cur_region };
					warp_entry.data1 = 0;
					strcpy(warp_entry.text, region_name);
					add_debug_menu_entry(warp_menu, &warp_entry);

					if (cur_region->variants >= 2) {
						warp_entry.entry_type = CUSTOM;
						warp_entry.custom_string_generator = district_variant_string_generator;
						add_debug_menu_entry(district_variants_menu, &warp_entry);
					}
				}
				qsort(warp_menu->entries, *number_of_allocated_regions, sizeof(debug_menu_entry), sort_warp_entries);
				qsort(district_variants_menu->entries, district_variants_menu->used_slots, sizeof(debug_menu_entry), sort_warp_entries);

			}


			if (devopt_flags_menu->used_slots == 0) {

				BYTE* cdonly = *(BYTE**)0x0096858C;
				debug_menu_entry cdonlys = { "CD ONLY ", BOOLEAN_E,  &cdonly[4 + 0x0] };
				add_debug_menu_entry(devopt_flags_menu, &cdonlys);

				BYTE* envmap = *(BYTE**)0x0096858C;
				debug_menu_entry envmaps = { "ENV MAP ", BOOLEAN_E,  &envmap[4 + 0x1] };
				add_debug_menu_entry(devopt_flags_menu, &envmaps);

				BYTE* nocd = *(BYTE**)0x0096858C;
				debug_menu_entry nocds = { "NO CD ", BOOLEAN_E,  &nocd[4 + 0x2] };
				add_debug_menu_entry(devopt_flags_menu, &nocds);

				BYTE* chattyload = *(BYTE**)0x0096858C;
				debug_menu_entry chattyloads = { "CHATTY LOAD ", BOOLEAN_E,  &chattyload[4 + 0x3] };
				add_debug_menu_entry(devopt_flags_menu, &chattyloads);

				BYTE* windowdefault = *(BYTE**)0x0096858C;
				debug_menu_entry windowdefaults = { "WINDOW DEFAULT ", BOOLEAN_E,  &windowdefault[4 + 0x4] };
				add_debug_menu_entry(devopt_flags_menu, &windowdefaults);

				BYTE* showfps = *(BYTE**)0x0096858C;
				debug_menu_entry showfpss = { "SHOW FPS ", BOOLEAN_E,  &showfps[4 + 0x5] };
				add_debug_menu_entry(devopt_flags_menu, &showfpss);

				

				BYTE* showstreamerinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showstreamerinfos = { "SHOW STREAMER INFO", BOOLEAN_E,  &showstreamerinfo[4 + 0x6] };
				add_debug_menu_entry(devopt_flags_menu, &showstreamerinfos);

				BYTE* showstreamerspam = *(BYTE**)0x0096858C;
				debug_menu_entry showstreamerspams = { "SHOW STREAMER SPAM", BOOLEAN_E,  &showstreamerspam[4 + 0x7] };
				add_debug_menu_entry(devopt_flags_menu, &showstreamerspams);


				BYTE* showresourcespam = *(BYTE**)0x0096858C;
				debug_menu_entry showresourcespams = { "SHOW RESOURCE SPAM", BOOLEAN_E,  &showresourcespam[4 + 0x8] };
				add_debug_menu_entry(devopt_flags_menu, &showresourcespams);


				BYTE* showmemoryinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showmemoryinfos = { "SHOW MEMORY INFO", BOOLEAN_E,  &showmemoryinfo[4 + 0x9] };
				add_debug_menu_entry(devopt_flags_menu, &showmemoryinfos);

				BYTE* showspideyinfo = *(BYTE**)0x0096858C;
				debug_menu_entry showspideyinfos = { "SHOW SPIDEY SPEED", BOOLEAN_E,  &showspideyinfo[4 + 0xA] };
				add_debug_menu_entry(devopt_flags_menu, &showspideyinfos);

				BYTE* tracemissionmanager = *(BYTE**)0x0096858C;
				debug_menu_entry tracemissionmanagers = { "TRACE MISSION MANAGER", BOOLEAN_E,  &tracemissionmanager[4 + 0xB] };
				add_debug_menu_entry(devopt_flags_menu, &tracemissionmanagers);

				BYTE* dumpmissionheap = *(BYTE**)0x0096858C;
				debug_menu_entry dumpmissionheaps = { "DUMP MISSION HEAP", BOOLEAN_E,  &dumpmissionheap[4 + 0xC] };
				add_debug_menu_entry(devopt_flags_menu, &dumpmissionheaps);

				BYTE* cameracentricstreamer = *(BYTE**)0x0096858C;
				debug_menu_entry cameracentricstreamers = { "CAMERA CENTRIC STREAMER", BOOLEAN_E,  &cameracentricstreamer[4 + 0xD] };
				add_debug_menu_entry(devopt_flags_menu, &cameracentricstreamers);


				BYTE* renderlowlods = *(BYTE**)0x0096858C;
				debug_menu_entry renderlowlodss = { "RENDER LOWLODS ", BOOLEAN_E,  &renderlowlods[4 + 0xE] };
				add_debug_menu_entry(devopt_flags_menu, &renderlowlodss);


				BYTE* loadstringhashdictionary = *(BYTE**)0x0096858C;
				debug_menu_entry loadstringhashdictionarys = { "LOAD STRING HASH DICTIONARY ", BOOLEAN_E,  &loadstringhashdictionary[4 + 0xF] };
				add_debug_menu_entry(devopt_flags_menu, &loadstringhashdictionarys);


				BYTE* flag17 = *(BYTE**)0x0096858C;
				debug_menu_entry flags17 = { "LOG RUNTIME STRING HASHES ", BOOLEAN_E,  &flag17[4 + 0x10] };
				add_debug_menu_entry(devopt_flags_menu, &flags17);


				BYTE* flag18 = *(BYTE**)0x0096858C;
				debug_menu_entry flags18 = { "SHOW WATERMARK VELOCITY ", BOOLEAN_E,  &flag18[4 + 0x11] };
				add_debug_menu_entry(devopt_flags_menu, &flags18);


				BYTE* flag19 = *(BYTE**)0x0096858C;
				debug_menu_entry flags19 = { "SHOW STATS ", BOOLEAN_E,  &flag19[4 + 0x12] };
				add_debug_menu_entry(devopt_flags_menu, &flags19);


				BYTE* flag20 = *(BYTE**)0x0096858C;
				debug_menu_entry flags20 = { "ENABLE ZOOM MAP ", BOOLEAN_E,  &flag20[4 + 0x13] };
				add_debug_menu_entry(devopt_flags_menu, &flags20);


				BYTE* flag21 = *(BYTE**)0x0096858C;
				debug_menu_entry flags21 = { "SHOW DEBUG INFO  ", BOOLEAN_E,  &flag21[4 + 0x14] };
				add_debug_menu_entry(devopt_flags_menu, &flags21);


				BYTE* flag23 = *(BYTE**)0x0096858C;
				debug_menu_entry flags23 = { "SHOW LOCOMOTION INFO ", BOOLEAN_E,  &flag23[4 + 0x16] };
				add_debug_menu_entry(devopt_flags_menu, &flags23);



				BYTE* flag24 = *(BYTE**)0x0096858C;
				debug_menu_entry flags24 = { "GRAVITY ", BOOLEAN_E,  &flag24[4 + 0x17] };
				add_debug_menu_entry(devopt_flags_menu, &flags24);


				BYTE* flag25 = *(BYTE**)0x0096858C;
				debug_menu_entry flags25 = { "TEST MEMORY LEAKS ", BOOLEAN_E,  &flag25[4 + 0x18] };
				add_debug_menu_entry(devopt_flags_menu, &flags25);


				BYTE* flag26 = *(BYTE**)0x0096858C;
				debug_menu_entry flags26 = { "HALT ON ASSERTS  ", BOOLEAN_E,  &flag26[4 + 0x19] };
				add_debug_menu_entry(devopt_flags_menu, &flags26);


				BYTE* flag27 = *(BYTE**)0x0096858C;
				debug_menu_entry flags27 = { "SCREEN ASSERTS ", BOOLEAN_E,  &flag27[4 + 0x1A] };
				add_debug_menu_entry(devopt_flags_menu, &flags27);


				BYTE* flag28 = *(BYTE**)0x0096858C;
				debug_menu_entry flags28 = { "NO ANIM WARNINGS ", BOOLEAN_E,  &flag28[4 + 0x1B] };
				add_debug_menu_entry(devopt_flags_menu, &flags28);


				BYTE* flag29 = *(BYTE**)0x0096858C;
				debug_menu_entry flags29 = { "PROFILING ON ", BOOLEAN_E,  &flag29[4 + 0x1C] };
				add_debug_menu_entry(devopt_flags_menu, &flags29);


				BYTE* flag30 = *(BYTE**)0x0096858C;
				debug_menu_entry flags30 = { "MONO AUDIO ", BOOLEAN_E,  &flag30[4 + 0x1D] };
				add_debug_menu_entry(devopt_flags_menu, &flags30);


				BYTE* flag31 = *(BYTE**)0x0096858C;
				debug_menu_entry flags31 = { "NO MESSAGES ", BOOLEAN_E,  &flag31[4 + 0x1E] };
				add_debug_menu_entry(devopt_flags_menu, &flags31);


				BYTE* flag32 = *(BYTE**)0x0096858C;
				debug_menu_entry flags32 = { "LOCK STEP ", BOOLEAN_E,  &flag32[4 + 0x1F] };
				add_debug_menu_entry(devopt_flags_menu, &flags32);


				BYTE* flag33 = *(BYTE**)0x0096858C;
				debug_menu_entry flags33 = { "TEXTURE DUMP ", BOOLEAN_E,  &flag33[4 + 0x20] };
				add_debug_menu_entry(devopt_flags_menu, &flags33);


				BYTE* flag34 = *(BYTE**)0x0096858C;
				debug_menu_entry flags34 = { "DISABLE SOUND WARNINGS ", BOOLEAN_E,  &flag34[4 + 0x21] };
				add_debug_menu_entry(devopt_flags_menu, &flags34);


				BYTE* flag35 = *(BYTE**)0x0096858C;
				debug_menu_entry flags35 = { "DISABLE SOUND DEBUG OUTPUT ", BOOLEAN_E,  &flag35[4 + 0x22] };
				add_debug_menu_entry(devopt_flags_menu, &flags35);


				BYTE* flag36 = *(BYTE**)0x0096858C;
				debug_menu_entry flags36 = { "DELETE UNUSED SOUND BANKS ON PACK ", BOOLEAN_E,  &flag36[4 + 0x23] };
				add_debug_menu_entry(devopt_flags_menu, &flags36);


				BYTE* flag37 = *(BYTE**)0x0096858C;
				debug_menu_entry flags37 = { "LOCKED HERO ", BOOLEAN_E,  &flag37[4 + 0x24] };
				add_debug_menu_entry(devopt_flags_menu, &flags37);


				BYTE* flag38 = *(BYTE**)0x0096858C;
				debug_menu_entry flags38 = { "FOG OVERRIDE ", BOOLEAN_E,  &flag38[4 + 0x25] };
				add_debug_menu_entry(devopt_flags_menu, &flags38);


				BYTE* flag39 = *(BYTE**)0x0096858C;
				debug_menu_entry flags39 = { "FOG DISABLE ", BOOLEAN_E,  &flag39[4 + 0x25] };
				add_debug_menu_entry(devopt_flags_menu, &flags39);


				BYTE* flag40 = *(BYTE**)0x0096858C;
				debug_menu_entry flags40 = { "MOVE EDITOR ", BOOLEAN_E,  &flag40[4 + 0x27] };
				add_debug_menu_entry(devopt_flags_menu, &flags40);


				BYTE* flag41 = *(BYTE**)0x0096858C;
				debug_menu_entry flags41 = { "AI PATH DEBUG ", BOOLEAN_E,  &flag41[4 + 0x28] };
				add_debug_menu_entry(devopt_flags_menu, &flags41);


				BYTE* flag42 = *(BYTE**)0x0096858C;
				debug_menu_entry flags42 = { "AI PATH COLOR ", BOOLEAN_E,  &flag42[4 + 0x29] };
				add_debug_menu_entry(devopt_flags_menu, &flags42);


				BYTE* flag43 = *(BYTE**)0x0096858C;
				debug_menu_entry flags43 = { "AI CRITTER ACTIVITY ", BOOLEAN_E,  &flag43[4 + 0x2A] };
				add_debug_menu_entry(devopt_flags_menu, &flags43);


				BYTE* flag44 = *(BYTE**)0x0096858C;
				debug_menu_entry flags44 = { "AI PATH COLOR CRITTER ", BOOLEAN_E,  &flag44[4 + 0x2B] };
				add_debug_menu_entry(devopt_flags_menu, &flags44);


				BYTE* flag45 = *(BYTE**)0x0096858C;
				debug_menu_entry flags45 = { "AI PATH COLOR HERO ", BOOLEAN_E,  &flag45[4 + 0x2C] };
				add_debug_menu_entry(devopt_flags_menu, &flags45);


				BYTE* flag46 = *(BYTE**)0x0096858C;
				debug_menu_entry flags46 = { "NO PARTICLES ", BOOLEAN_E,  &flag46[4 + 0x2D] };
				add_debug_menu_entry(devopt_flags_menu, &flags46);


				BYTE* flag47 = *(BYTE**)0x0096858C;
				debug_menu_entry flags47 = { "NO PARTICLES PUMP", BOOLEAN_E,  &flag47[4 + 0x2E] };
				add_debug_menu_entry(devopt_flags_menu, &flags47);


				BYTE* flag48 = *(BYTE**)0x0096858C;
				debug_menu_entry flags48 = { "SHOW NORMALS ", BOOLEAN_E,  &flag48[4 + 0x2F] };
				add_debug_menu_entry(devopt_flags_menu, &flags48);


				BYTE* flag49 = *(BYTE**)0x0096858C;
				debug_menu_entry flags49 = { "SHOW SHADOW BALL ", BOOLEAN_E,  &flag49[4 + 0x30] };
				add_debug_menu_entry(devopt_flags_menu, &flags49);


				BYTE* flag50 = *(BYTE**)0x0096858C;
				debug_menu_entry flags50 = { "SHOW LIGHTS ", BOOLEAN_E,  &flag50[4 + 0x31] };
				add_debug_menu_entry(devopt_flags_menu, &flags50);


				BYTE* flag51 = *(BYTE**)0x0096858C;
				debug_menu_entry flags51 = { "SHOW PLRCTRL ", BOOLEAN_E,  &flag51[4 + 0x32] };
				add_debug_menu_entry(devopt_flags_menu, &flags51);


				BYTE* flag52 = *(BYTE**)0x0096858C;
				debug_menu_entry flags52 = { "SHOW PSX INFO ", BOOLEAN_E,  &flag52[4 + 0x33] };
				add_debug_menu_entry(devopt_flags_menu, &flags52);


				BYTE* flag53 = *(BYTE**)0x0096858C;
				debug_menu_entry flags53 = { "FLAT SHADE ", BOOLEAN_E,  &flag53[4 + 0x34] };
				add_debug_menu_entry(devopt_flags_menu, &flags53);


				BYTE* flag54 = *(BYTE**)0x0096858C;
				debug_menu_entry flags54 = { "INTERFACE DISABLE ", BOOLEAN_E,  &flag54[4 + 0x35] };
				add_debug_menu_entry(devopt_flags_menu, &flags54);


				BYTE* flag55 = *(BYTE**)0x0096858C;
				debug_menu_entry flags55 = { "WIDGET TOOLS ", BOOLEAN_E,  &flag55[4 + 0x36] };
				add_debug_menu_entry(devopt_flags_menu, &flags55);


				BYTE* flag56 = *(BYTE**)0x0096858C;
				debug_menu_entry flags56 = { "LIGHTING ", BOOLEAN_E,  &flag56[4 + 0x37] };
				add_debug_menu_entry(devopt_flags_menu, &flags56);


				BYTE* flag57 = *(BYTE**)0x0096858C;
				debug_menu_entry flags57 = { "FAKE POINT LIGHTS ", BOOLEAN_E,  &flag57[4 + 0x38] };
				add_debug_menu_entry(devopt_flags_menu, &flags57);


				BYTE* flag58 = *(BYTE**)0x0096858C;
				debug_menu_entry flags58 = { "BSP SPRAY PAINT  ", BOOLEAN_E,  &flag58[4 + 0x39] };
				add_debug_menu_entry(devopt_flags_menu, &flags58);


				BYTE* flag59 = *(BYTE**)0x0096858C;
				debug_menu_entry flags59 = { "CAMERA EDITOR ", BOOLEAN_E,  &flag59[4 + 0x3A] };
				add_debug_menu_entry(devopt_flags_menu, &flags59);



				BYTE* flag60 = *(BYTE**)0x0096858C;
				debug_menu_entry flags60 = { "IGNORE RAMPING ", BOOLEAN_E,  &flag60[4 + 0x3B] };
				add_debug_menu_entry(devopt_flags_menu, &flags60);


				BYTE* flag61 = *(BYTE**)0x0096858C;
				debug_menu_entry flags61 = { "POINT SAMPLE ", BOOLEAN_E,  &flag61[4 + 0x3C] };
				add_debug_menu_entry(devopt_flags_menu, &flags61);


				BYTE* flag62 = *(BYTE**)0x0096858C;
				debug_menu_entry flags62 = { "DISTANCE FADING ", BOOLEAN_E,  &flag62[4 + 0x3D] };
				add_debug_menu_entry(devopt_flags_menu, &flags62);


				BYTE* flag63 = *(BYTE**)0x0096858C;
				debug_menu_entry flags63 = { "OVERRIDE CONTROLLER OPTIONS ", BOOLEAN_E,  &flag63[4 + 0x3E] };
				add_debug_menu_entry(devopt_flags_menu, &flags63);


				BYTE* flag64 = *(BYTE**)0x0096858C;
				debug_menu_entry flags64 = { "DISABLE MOUSE PLAYER CONTROL ", BOOLEAN_E,  &flag64[4 + 0x3F] };
				add_debug_menu_entry(devopt_flags_menu, &flags64);


				BYTE* flag65 = *(BYTE**)0x0096858C;
				debug_menu_entry flags65 = { "NO MOVIES ", BOOLEAN_E,  &flag65[4 + 0x40] };
				add_debug_menu_entry(devopt_flags_menu, &flags65);


				BYTE* flag66 = *(BYTE**)0x0096858C;
				debug_menu_entry flags66 = { "XBOX USER CAM ", BOOLEAN_E,  &flag66[4 + 0x41] };
				add_debug_menu_entry(devopt_flags_menu, &flags66);


				BYTE* flag67 = *(BYTE**)0x0096858C;
				debug_menu_entry flags67 = { "NO LOAD SCREEN ", BOOLEAN_E,  &flag67[4 + 0x42] };
				add_debug_menu_entry(devopt_flags_menu, &flags67);


				BYTE* flag68 = *(BYTE**)0x0096858C;
				debug_menu_entry flags68 = { "NO EXCEPTION HANDLER ", BOOLEAN_E,  &flag68[4 + 0x43] };
				add_debug_menu_entry(devopt_flags_menu, &flags68);


				BYTE* flag69 = *(BYTE**)0x0096858C;
				debug_menu_entry flags69 = { "NO CD CHECK ", BOOLEAN_E,  &flag69[4 + 0x44] };
				add_debug_menu_entry(devopt_flags_menu, &flags69);


				BYTE* flag70 = *(BYTE**)0x0096858C;
				debug_menu_entry flags70 = { "NO LOAD METER ", BOOLEAN_E,  &flag70[4 + 0x45] };
				add_debug_menu_entry(devopt_flags_menu, &flags70);


				BYTE* flag71 = *(BYTE**)0x0096858C;
				debug_menu_entry flags71 = { "NO MOVIE BUFFER WARNING ", BOOLEAN_E,  &flag71[4 + 0x46] };
				add_debug_menu_entry(devopt_flags_menu, &flags71);


				BYTE* flag72 = *(BYTE**)0x0096858C;
				debug_menu_entry flags72 = { "LIMITED EDITION DISC ", BOOLEAN_E,  &flag72[4 + 0x49] };
				add_debug_menu_entry(devopt_flags_menu, &flags72);


				BYTE* flag73 = *(BYTE**)0x0096858C;
				debug_menu_entry flags73 = { "NEW COMBAT LOCO ", BOOLEAN_E,  &flag73[4 + 0x48] };
				add_debug_menu_entry(devopt_flags_menu, &flags73);


				BYTE* flag74 = *(BYTE**)0x0096858C;
				debug_menu_entry flags74 = { "LEVEL WARP ", BOOLEAN_E,  &flag74[4 + 0x47] };
				add_debug_menu_entry(devopt_flags_menu, &flags74);


				BYTE* flag75 = *(BYTE**)0x0096858C;
				debug_menu_entry flags75 = { "SMOKE TEST ", BOOLEAN_E,  &flag75[4 + 0x4A] };
				add_debug_menu_entry(devopt_flags_menu, &flags75);


				BYTE* flag76 = *(BYTE**)0x0096858C;
				debug_menu_entry flags76 = { "SMOKE TEST LEVEL ", BOOLEAN_E,  &flag76[4 + 0x4B] };
				add_debug_menu_entry(devopt_flags_menu, &flags76);


				BYTE* flag77 = *(BYTE**)0x0096858C;
				debug_menu_entry flags77 = { "COMBO TESTER ", BOOLEAN_E,  &flag77[4 + 0x4C] };
				add_debug_menu_entry(devopt_flags_menu, &flags77);


				BYTE* flag78 = *(BYTE**)0x0096858C;
				debug_menu_entry flags78 = { "DROP SHADOWS ALWAYS RAYCAST ", BOOLEAN_E,  &flag78[4 + 0x4D] };
				add_debug_menu_entry(devopt_flags_menu, &flags78);


				BYTE* flag79 = *(BYTE**)0x0096858C;
				debug_menu_entry flags79 = { "DISABLE DROP SHADOWS ", BOOLEAN_E,  &flag79[4 + 0x4E] };
				add_debug_menu_entry(devopt_flags_menu, &flags79);


				BYTE* flag80 = *(BYTE**)0x0096858C;
				debug_menu_entry flags80 = { "DISABLE HIRES SHADOWS ", BOOLEAN_E,  &flag80[4 + 0x4F] };
				add_debug_menu_entry(devopt_flags_menu, &flags80);


				BYTE* flag81 = *(BYTE**)0x0096858C;
				debug_menu_entry flags81 = { "DISABLE STENCIL SHADOWS ", BOOLEAN_E,  &flag81[4 + 0x50] };
				add_debug_menu_entry(devopt_flags_menu, &flags81);


				BYTE* flag82 = *(BYTE**)0x0096858C;
				debug_menu_entry flags82 = { "DISABLE COLORVOLS ", BOOLEAN_E,  &flag82[4 + 0x51] };
				add_debug_menu_entry(devopt_flags_menu, &flags82);


				BYTE* flag83 = *(BYTE**)0x0096858C;
				debug_menu_entry flags83 = { "DISABLE RENDER ENTS ", BOOLEAN_E,  &flag83[4 + 0x52] };
				add_debug_menu_entry(devopt_flags_menu, &flags83);


				BYTE* flag84 = *(BYTE**)0x0096858C;
				debug_menu_entry flags84 = { "DISABLE FULLSCREEN BLUR ", BOOLEAN_E,  &flag84[4 + 0x53] };
				add_debug_menu_entry(devopt_flags_menu, &flags84);


				BYTE* flag85 = *(BYTE**)0x0096858C;
				debug_menu_entry flags85 = { "FORCE TIGHTCRAWL ", BOOLEAN_E,  &flag85[4 + 0x54] };
				add_debug_menu_entry(devopt_flags_menu, &flags85);


				BYTE* flag86 = *(BYTE**)0x0096858C;
				debug_menu_entry flags86 = { "FORCE NONCRAWL ", BOOLEAN_E,  &flag86[4 + 0x55] };
				add_debug_menu_entry(devopt_flags_menu, &flags86);


				BYTE* flag87 = *(BYTE**)0x0096858C;
				debug_menu_entry flags87 = { "SHOW DEBUG TEXT ", BOOLEAN_E,  &flag87[4 + 0x57] };
				add_debug_menu_entry(devopt_flags_menu, &flags87);


				BYTE* flag88 = *(BYTE**)0x0096858C;
				debug_menu_entry flags88 = { "SHOW STYLE POINTS ", BOOLEAN_E,  &flag88[4 + 0x58] };
				add_debug_menu_entry(devopt_flags_menu, &flags88);


				BYTE* flag89 = *(BYTE**)0x0096858C;
				debug_menu_entry flags89 = { "CAMERA MOUSE MODE ", BOOLEAN_E,  &flag89[4 + 0x59] };
				add_debug_menu_entry(devopt_flags_menu, &flags89);


				BYTE* flag90 = *(BYTE**)0x0096858C;
				debug_menu_entry flags90 = { "USERCAM ON CONTROLLER2 ", BOOLEAN_E,  &flag90[4 + 0x5A] };
				add_debug_menu_entry(devopt_flags_menu, &flags90);


				BYTE* flag91 = *(BYTE**)0x0096858C;
				debug_menu_entry flags91 = { "DISABLE ANCHOR RETICLE RENDERING ", BOOLEAN_E,  &flag91[4 + 0x5B] };
				add_debug_menu_entry(devopt_flags_menu, &flags91);


				BYTE* flag92 = *(BYTE**)0x0096858C;
				debug_menu_entry flags92 = { "SHOW ANCHOR LINE ", BOOLEAN_E,  &flag92[4 + 0x5C] };
				add_debug_menu_entry(devopt_flags_menu, &flags92);


				BYTE* flag93 = *(BYTE**)0x0096858C;
				debug_menu_entry flags93 = { "FREE SPIDER REFLEXES ", BOOLEAN_E,  &flag93[4 + 0x5D] };
				add_debug_menu_entry(devopt_flags_menu, &flags93);


				BYTE* flag94 = *(BYTE**)0x0096858C;
				debug_menu_entry flags94 = { "SHOW BAR OF SHAME ", BOOLEAN_E,  &flag94[4 + 0x5E] };
				add_debug_menu_entry(devopt_flags_menu, &flags94);


				BYTE* flag95 = *(BYTE**)0x0096858C;
				debug_menu_entry flags95 = { "SHOW ENEMY HEALTH WIDGETS ", BOOLEAN_E,  &flag95[4 + 0x5F] };
				add_debug_menu_entry(devopt_flags_menu, &flags95);


				BYTE* flag96 = *(BYTE**)0x0096858C;
				debug_menu_entry flags96 = { "ALLOW IGC PAUSE ", BOOLEAN_E,  &flag96[4 + 0x60] };
				add_debug_menu_entry(devopt_flags_menu, &flags96);


				BYTE* flag97 = *(BYTE**)0x0096858C;
				debug_menu_entry flags97 = { "SHOW DISTRICTS ", BOOLEAN_E,  &flag97[4 + 0x61] };
				add_debug_menu_entry(devopt_flags_menu, &flags97);


				BYTE* flag98 = *(BYTE**)0x0096858C;
				debug_menu_entry flags98 = { "SHOW CHUCK DEBUGGER ", BOOLEAN_E,  &flag98[4 + 0x62] };
				add_debug_menu_entry(devopt_flags_menu, &flags98);


				BYTE* flag99 = *(BYTE**)0x0096858C;
				debug_menu_entry flags99 = { "CHUCK OLD FASHIONED ", BOOLEAN_E,  &flag99[4 + 0x63] };
				add_debug_menu_entry(devopt_flags_menu, &flags99);


				BYTE* flag100 = *(BYTE**)0x0096858C;
				debug_menu_entry flags100 = { "CHUCK DISABLE BREAKPOINTS ", BOOLEAN_E,  &flag100[4 + 0x64] };
				add_debug_menu_entry(devopt_flags_menu, &flags100);


				BYTE* flag101 = *(BYTE**)0x0096858C;
				debug_menu_entry flags101 = { "DISABLE SOUNDS ", BOOLEAN_E,  &flag101[4 + 0x65] };
				add_debug_menu_entry(devopt_flags_menu, &flags101);


				BYTE* flag102 = *(BYTE**)0x0096858C;
				debug_menu_entry flags102 = { "SHOW TERRAIN INFO ", BOOLEAN_E,  &flag102[4 + 0x66] };
				add_debug_menu_entry(devopt_flags_menu, &flags102);


				BYTE* flag103 = *(BYTE**)0x0096858C;
				debug_menu_entry flags103 = { "DISABLE AUDIO BOXES ", BOOLEAN_E,  &flag103[4 + 0x67] };
				add_debug_menu_entry(devopt_flags_menu, &flags103);


				BYTE* flag104 = *(BYTE**)0x0096858C;
				debug_menu_entry flags104 = { "NSL OLD FASHIONED ", BOOLEAN_E,  &flag104[4 + 0x68] };
				add_debug_menu_entry(devopt_flags_menu, &flags104);


				BYTE* flag105 = *(BYTE**)0x0096858C;
				debug_menu_entry flags105 = { "SHOW MASTER CLOCK ", BOOLEAN_E,  &flag105[4 + 0x69] };
				add_debug_menu_entry(devopt_flags_menu, &flags105);


				BYTE* playcityambientmusic = *(BYTE**)0x0096858C;
				debug_menu_entry playcityambientmusics = { "PLAY CITY AMBIENT MUSIC", BOOLEAN_E,  &playcityambientmusic[4 + 0x6A] };
				add_debug_menu_entry(streams_menu, &playcityambientmusics);


				BYTE* flag107 = *(BYTE**)0x0096858C;
				debug_menu_entry flags107 = { "BONUS LEVELS AVAILABLE ", BOOLEAN_E,  &flag107[4 + 0x6B] };
				add_debug_menu_entry(devopt_flags_menu, &flags107);


				BYTE* flag108 = *(BYTE**)0x0096858C;
				debug_menu_entry flags108 = { "COMBAT DISPLAY ", BOOLEAN_E,  &flag108[4 + 0x6C] };
				add_debug_menu_entry(devopt_flags_menu, &flags108);


				BYTE* flag109 = *(BYTE**)0x0096858C;
				debug_menu_entry flags109 = { "COMBAT DEBUGGER ", BOOLEAN_E,  &flag109[4 + 0x6E] };
				add_debug_menu_entry(devopt_flags_menu, &flags109);


				BYTE* flag110 = *(BYTE**)0x0096858C;
				debug_menu_entry flags110 = { "ALLOW ERROR POPUPS ", BOOLEAN_E,  &flag110[4 + 0x6F] };
				add_debug_menu_entry(devopt_flags_menu, &flags110);


				BYTE* flag111 = *(BYTE**)0x0096858C;
				debug_menu_entry flags111 = { "ALLOW WARNING POPUPS ", BOOLEAN_E,  &flag111[4 + 0x70] };
				add_debug_menu_entry(devopt_flags_menu, &flags111);


				BYTE* flag112 = *(BYTE**)0x0096858C;
				debug_menu_entry flags112 = { "OUTPUT WARNING DISABLE ", BOOLEAN_E,  &flag112[4 + 0x71] };
				add_debug_menu_entry(devopt_flags_menu, &flags112);


				BYTE* flag113 = *(BYTE**)0x0096858C;
				debug_menu_entry flags113 = { "OUTPUT ASSERT DISABLE ", BOOLEAN_E,  &flag113[4 + 0x73] };
				add_debug_menu_entry(devopt_flags_menu, &flags113);


				BYTE* flag114 = *(BYTE**)0x0096858C;
				debug_menu_entry flags114 = { "ASSERT ON WARNING ", BOOLEAN_E,  &flag114[4 + 0x74] };
				add_debug_menu_entry(devopt_flags_menu, &flags114);


				BYTE* flag115 = *(BYTE**)0x0096858C;
				debug_menu_entry flags115 = { "ALWAYS ACTIVE ", BOOLEAN_E,  &flag115[4 + 0x75] };
				add_debug_menu_entry(devopt_flags_menu, &flags115);


				BYTE* flag116 = *(BYTE**)0x0096858C;
				debug_menu_entry flags116 = { "FORCE PROGRESSION ", BOOLEAN_E,  &flag116[4 + 0x76] };
				add_debug_menu_entry(devopt_flags_menu, &flags116);


				BYTE* flag117 = *(BYTE**)0x0096858C;
				debug_menu_entry flags117 = { "LINK ", BOOLEAN_E,  &flag117[4 + 0x77] };
				add_debug_menu_entry(devopt_flags_menu, &flags117);


				BYTE* flag118 = *(BYTE**)0x0096858C;
				debug_menu_entry flags118 = { "WAIT FOR LINK ", BOOLEAN_E,  &flag118[4 + 0x78] };
				add_debug_menu_entry(devopt_flags_menu, &flags118);


				BYTE* flag119 = *(BYTE**)0x0096858C;
				debug_menu_entry flags119 = { "SHOW END OF PACK ", BOOLEAN_E,  &flag119[4 + 0x79] };
				add_debug_menu_entry(devopt_flags_menu, &flags119);


				BYTE* flag120 = *(BYTE**)0x0096858C;
				debug_menu_entry live_in_glass_house = { "LIVE_IN_GLASS_HOUSE ", BOOLEAN_E,  &flag120[4 + 0x7A] };
				add_debug_menu_entry(devopt_flags_menu, &live_in_glass_house);

				BYTE* flag121 = *(BYTE**)0x0096858C;
				debug_menu_entry flags121 = { "SHOW GLASS HOUSE ", BOOLEAN_E,  &flag121[4 + 0x7B] };
				add_debug_menu_entry(devopt_flags_menu, &flags121);


				BYTE* flag122 = *(BYTE**)0x0096858C;
				debug_menu_entry flags122 = { "DISABLE RACE PREVIEW ", BOOLEAN_E,  &flag122[4 + 0x7C] };
				add_debug_menu_entry(devopt_flags_menu, &flags122);


				BYTE* flag123 = *(BYTE**)0x0096858C;
				debug_menu_entry flags123 = { "FREE MINI MAP ", BOOLEAN_E,  &flag123[4 + 0x7D] };
				add_debug_menu_entry(devopt_flags_menu, &flags123);


				BYTE* flag124 = *(BYTE**)0x0096858C;
				debug_menu_entry flags124 = { "SHOW LOOPING ANIM WARNINGS ", BOOLEAN_E,  &flag124[4 + 0x7E] };
				add_debug_menu_entry(devopt_flags_menu, &flags124);


				BYTE* flag125 = *(BYTE**)0x0096858C;
				debug_menu_entry flags125 = { "SHOW PERF INFO ", BOOLEAN_E,  &flag125[4 + 0x7F] };
				add_debug_menu_entry(devopt_flags_menu, &flags125);


				BYTE* flag126 = *(BYTE**)0x0096858C;
				debug_menu_entry flags126 = { "COPY ERROR TO CLIPBOARD ", BOOLEAN_E,  &flag126[4 + 0x80] };
				add_debug_menu_entry(devopt_flags_menu, &flags126);


				BYTE* flag127 = *(BYTE**)0x0096858C;
				debug_menu_entry flags127 = { "BOTH HANDS UP REORIENT ", BOOLEAN_E,  &flag127[4 + 0x81] };
				add_debug_menu_entry(devopt_flags_menu, &flags127);


				BYTE* flag128 = *(BYTE**)0x0096858C;
				debug_menu_entry flags128 = { "SHOW CAMERA PROJECTION ", BOOLEAN_E,  &flag128[4 + 0x82] };
				add_debug_menu_entry(devopt_flags_menu, &flags128);


				BYTE* flag129 = *(BYTE**)0x0096858C;
				debug_menu_entry flags129 = { "OLD DEFAULT CONTROL SETTINGS ", BOOLEAN_E,  &flag129[4 + 0x83] };
				add_debug_menu_entry(devopt_flags_menu, &flags129);


				BYTE* flag130 = *(BYTE**)0x0096858C;
				debug_menu_entry flags130 = { "IGC SPEED CONTROL ", BOOLEAN_E,  &flag130[4 + 0x84] };
				add_debug_menu_entry(devopt_flags_menu, &flags130);

				BYTE* flag131 = *(BYTE**)0x0096858C;
				debug_menu_entry flags131 = { "RTDT ENABLED ", BOOLEAN_E,  &flag131[4 + 0x85] };
				add_debug_menu_entry(devopt_flags_menu, &flags131);

				BYTE* flag132 = *(BYTE**)0x0096858C;
				debug_menu_entry flags132 = { "ENABLE DECALS ", BOOLEAN_E,  &flag132[4 + 0x86] };
				add_debug_menu_entry(devopt_flags_menu, &flags132);

				BYTE* flag133 = *(BYTE**)0x0096858C;
				debug_menu_entry flags133 = { "AUTO STICK TO WALLS  ", BOOLEAN_E,  &flag133[4 + 0x87] };
				add_debug_menu_entry(devopt_flags_menu, &flags133);

				BYTE* flag134 = *(BYTE**)0x0096858C;
				debug_menu_entry flags134 = { "ENABLE PEDESTRIANS ", BOOLEAN_E,  &flag134[4 + 0x88] };
				add_debug_menu_entry(devopt_flags_menu, &flags134);

				BYTE* flag135 = *(BYTE**)0x0096858C;
				debug_menu_entry flags135 = { "CAMERA INVERT LOOKAROUND ", BOOLEAN_E,  &flag135[4 + 0x89] };
				add_debug_menu_entry(devopt_flags_menu, &flags135);

				BYTE* flag136 = *(BYTE**)0x0096858C;
				debug_menu_entry flags136 = { "CAMERA INVERT LOOKAROUND X ", BOOLEAN_E,  &flag136[4 + 0x8A] };
				add_debug_menu_entry(devopt_flags_menu, &flags136);

				BYTE* flag137 = *(BYTE**)0x0096858C;
				debug_menu_entry flags137 = { "CAMERA INVERT LOOKAROUND Y ", BOOLEAN_E,  &flag137[4 + 0x8B] };
				add_debug_menu_entry(devopt_flags_menu, &flags137);

				BYTE* flag138 = *(BYTE**)0x0096858C;
				debug_menu_entry flags138 = { "FORCE COMBAT CAMERA OFF ", BOOLEAN_E,  &flag138[4 + 0x8C] };
				add_debug_menu_entry(devopt_flags_menu, &flags138);

				BYTE* flag139 = *(BYTE**)0x0096858C;
				debug_menu_entry flags139 = { "DISPLAY THOUGHT BUBBLES ", BOOLEAN_E,  &flag139[4 + 0x8D] };
				add_debug_menu_entry(devopt_flags_menu, &flags139);

				BYTE* flag140 = *(BYTE**)0x0096858C;
				debug_menu_entry flags140 = { "ENABLE DEBUG LOG", BOOLEAN_E,  &flag140[4 + 0x8E] };
				add_debug_menu_entry(devopt_flags_menu, &flags140);

				BYTE* flag141 = *(BYTE**)0x0096858C;
				debug_menu_entry flags141 = { "ENABLE LONG CALLSTACK ", BOOLEAN_E,  &flag141[4 + 0x8F] };
				add_debug_menu_entry(devopt_flags_menu, &flags141);

				BYTE* flag143 = *(BYTE**)0x0096858C;
				debug_menu_entry flags143 = { "RENDER FE UI ", BOOLEAN_E,  &flag143[4 + 0x90] };
				add_debug_menu_entry(devopt_flags_menu, &flags143);

				BYTE* flag144 = *(BYTE**)0x0096858C;
				debug_menu_entry flags144 = { "LOCK INTERIORS", BOOLEAN_E,  &flag144[4 + 0x91] };
				add_debug_menu_entry(devopt_flags_menu, &flags144);

				BYTE* flag145 = *(BYTE**)0x0096858C;
				debug_menu_entry flags145 = { "MEMCHECK ON LOAD", BOOLEAN_E,  &flag145[4 + 0x92] };
				add_debug_menu_entry(devopt_flags_menu, &flags145);

				BYTE* flag146 = *(BYTE**)0x0096858C;
				debug_menu_entry flags146 = { "DISPLAY ALS USAGE PROFILE", BOOLEAN_E,  &flag146[4 + 0x93] };
				add_debug_menu_entry(devopt_flags_menu, &flags146);

				BYTE* flag147 = *(BYTE**)0x0096858C;
				debug_menu_entry flags147 = { "ENABLE FPU EXCEPTION HANDLING", BOOLEAN_E,  &flag147[4 + 0x94] };
				add_debug_menu_entry(devopt_flags_menu, &flags147);

				BYTE* flag148 = *(BYTE**)0x0096858C;
				debug_menu_entry flags148 = { "UNLOCK ALL UNLOCKABLES", BOOLEAN_E,  &flag148[4 + 0x95] };
				add_debug_menu_entry(devopt_flags_menu, &flags148);


				
				debug_menu_entry camera = { "Camera", BOOLEAN_O,  start_debug };
				add_debug_menu_entry(start_debug, &camera);

			}

			

			if (game_flags_menu->used_slots == 0) {

				BYTE* god_mode = 0x95A6A8;
				debug_menu_entry god_mode_entry = { "God Mode ", BOOLEAN_F,  &god_mode[0] };
				debug_menu_entry mega_god_mode = { "One Hit Kill ", BOOLEAN_F,  &god_mode[1] };
				debug_menu_entry ultra_god_mode = { "Bomb Mode ", BOOLEAN_F,  &god_mode[2] };

				add_debug_menu_entry(game_flags_menu, &god_mode_entry);
				add_debug_menu_entry(game_flags_menu, &mega_god_mode);
				add_debug_menu_entry(game_flags_menu, &ultra_god_mode);

				debug_menu_entry show_fps = { "Show Fps", BOOLEAN_E, 0x975848 };
				add_debug_menu_entry(game_flags_menu, &show_fps);
				debug_menu_entry memory_info = { "Show Memory Info", BOOLEAN_E, 0x975849 };
				add_debug_menu_entry(game_flags_menu, &memory_info);
				debug_menu_entry monkeytime = { "Monkey Time", BOOLEAN_F, 0x959E60 };
				add_debug_menu_entry(game_flags_menu, &monkeytime);
				debug_menu_entry unlockchars = { "Unlock All Characters", BOOLEAN_F, 0x960E1C };
				add_debug_menu_entry(game_flags_menu, &unlockchars);
				debug_menu_entry unlockalllandmarks = { "Unlock All Landmarks", BOOLEAN_F, 0x960E19 };
				add_debug_menu_entry(game_flags_menu, &unlockalllandmarks);
				debug_menu_entry unlockallconceptart = { "Unlock All Concept Art", BOOLEAN_F, 0x960E1A };
				add_debug_menu_entry(game_flags_menu, &unlockallconceptart);
				debug_menu_entry unlockallcovers = { "Unlock All Covers", BOOLEAN_F, 0x960E1B };
				add_debug_menu_entry(game_flags_menu, &unlockallcovers);
				debug_menu_entry disablepausemenu = { "Disable Pause Menu", BOOLEAN_F, 0x96B448 };
				add_debug_menu_entry(game_flags_menu, &disablepausemenu);
				debug_menu_entry enableredwatermark = { "Enable Red Watermark", BOOLEAN_F, 0x96B434 };
				add_debug_menu_entry(game_flags_menu, &enableredwatermark);
				debug_menu_entry testflag = { "TestFlag", BOOLEAN_F, 0x9581BC };
				add_debug_menu_entry(game_flags_menu, &testflag);
				debug_menu_entry savescreenshot = { "Save Screenshot", NORMAL, 0x97584A };
				add_debug_menu_entry(game_flags_menu, &savescreenshot);
				debug_menu_entry weirdflag = { "Weird Flag", BOOLEAN_E, 0x95C1E8 };
				add_debug_menu_entry(game_flags_menu, &weirdflag);
				debug_menu_entry disableenvironment = { "DISABLE ENVIRONMENT", NORMAL, 0x922558 };
				add_debug_menu_entry(game_flags_menu, &disableenvironment);
				debug_menu_entry unloaddistricts = { "UNLOAD DISTRICT", NORMAL, 0x921D79 };
				add_debug_menu_entry(game_flags_menu, &unloaddistricts);
				BYTE* camerastatus = *(BYTE**)0x0096858C;
				debug_menu_entry camera_status = { "Camera Status", BOOLEAN_P,  &camerastatus[4 + 0x15] };
				add_debug_menu_entry(game_flags_menu, &camera_status);


			}
	
				

				if (debug_render_menu->used_slots == 0) {

				debug_menu_entry capsulehistory = { "CAPSULE_HISTORY ", BOOLEAN_F, 0x961168 };
				add_debug_menu_entry(debug_render_menu, &capsulehistory);

				debug_menu_entry lights = { "LIGHTS ", BOOLEAN_F, 0x961178 };
				add_debug_menu_entry(debug_render_menu, &lights);

				debug_menu_entry boxtriggers = { "BOX_TRIGGERS ", BOOLEAN_F, 0x961188 };
				add_debug_menu_entry(debug_render_menu, &boxtriggers);

				debug_menu_entry waterexclusiontriggers = { "WATER_EXCLUSION_TRIGGERS ", BOOLEAN_F, 0x961198 };
				add_debug_menu_entry(debug_render_menu, &waterexclusiontriggers);

				debug_menu_entry pointtriggers = { "POINT_TRIGGERS ", BOOLEAN_F, 0x9611A8 };
				add_debug_menu_entry(debug_render_menu, &pointtriggers);

				debug_menu_entry entitytriggers = { "ENTITY_TRIGGERS ", BOOLEAN_F, 0x9611B8 };
				add_debug_menu_entry(debug_render_menu, &entitytriggers);

				debug_menu_entry interactabletriggers = { "INTERACTABLE_TRIGGERS ", BOOLEAN_F, 0x9611C8 };
				add_debug_menu_entry(debug_render_menu, &interactabletriggers);

				debug_menu_entry occlusion = { "OCCLUSION ", BOOLEAN_F, 0x9611D8 };
				add_debug_menu_entry(debug_render_menu, &occlusion);

				debug_menu_entry legos = { "LEGOS ", BOOLEAN_F, 0x9611E8 };
				add_debug_menu_entry(debug_render_menu, &legos);

				debug_menu_entry regionmeshes = { "REGION_MESHES ", BOOLEAN_F, 0x9611F8 };
				add_debug_menu_entry(debug_render_menu, &regionmeshes);

				debug_menu_entry entities = { "ENTITIES ", BOOLEAN_F, 0x961208 };
				add_debug_menu_entry(debug_render_menu, &entities);

				debug_menu_entry lowlods = { "LOW_LODS ", BOOLEAN_F, 0x961218 };
				add_debug_menu_entry(debug_render_menu, &lowlods);

				debug_menu_entry activityinfo = { "ACTIVITY_INFO ", BOOLEAN_F, 0x961228 };
				add_debug_menu_entry(debug_render_menu, &activityinfo);

				debug_menu_entry renderinfo = { "RENDER_INFO ", BOOLEAN_F, 0x961238 };
				add_debug_menu_entry(debug_render_menu, &renderinfo);

				debug_menu_entry collideinfo = { "COLLIDE_INFO ", BOOLEAN_F, 0x961248 };
				add_debug_menu_entry(debug_render_menu, &collideinfo);

			    debug_menu_entry markers = { "MARKERS ", BOOLEAN_F, 0x961258 };
				add_debug_menu_entry(debug_render_menu, &markers);

				debug_menu_entry parkingmakers = { "PARKING_MARKERS ", BOOLEAN_F, 0x961268 };
				add_debug_menu_entry(debug_render_menu, &parkingmakers);

				debug_menu_entry waterexitmakers = { "WATER_EXIT_MARKERS ", BOOLEAN_F, 0x961278 };
				add_debug_menu_entry(debug_render_menu, &waterexitmakers);

				debug_menu_entry missionmakers = { "MISSION_MARKERS ", BOOLEAN_F, 0x961288 };
				add_debug_menu_entry(debug_render_menu, &missionmakers);

				debug_menu_entry paths = { "PATHS ", BOOLEAN_F, 0x961298 };
				add_debug_menu_entry(debug_render_menu, &paths);

				debug_menu_entry glasshouse = { "GLASS_HOUSE ", BOOLEAN_F, 0x9612A8 };
				add_debug_menu_entry(debug_render_menu, &glasshouse);

				debug_menu_entry obbs = { "OBBS ", BOOLEAN_F, 0x9612B8 };
				add_debug_menu_entry(debug_render_menu, &obbs);

				debug_menu_entry trafficspaths = { "TRAFFIC_PATHS ", BOOLEAN_F, 0x9612C8 };
				add_debug_menu_entry(debug_render_menu, &trafficspaths);

				debug_menu_entry minigame = { "MINI_GAME ", BOOLEAN_F, 0x9612D8 };
				add_debug_menu_entry(debug_render_menu, &minigame);

				debug_menu_entry brains = { "BRAINS ", BOOLEAN_F, 0x9612E8 };
				add_debug_menu_entry(debug_render_menu, &brains);

				debug_menu_entry voice = { "VOICE ", BOOLEAN_F, 0x9612F8 };
				add_debug_menu_entry(debug_render_menu, &voice);

				debug_menu_entry patrols = { "PATROLS ", BOOLEAN_F, 0x961308 };
				add_debug_menu_entry(debug_render_menu, &patrols);

				debug_menu_entry pausetimers = { "PAUSE_TIMERS ", BOOLEAN_F, 0x961318 };
				add_debug_menu_entry(debug_render_menu, &pausetimers);

				debug_menu_entry animinfo = { "ANIM_INFO ", BOOLEAN_F, 0x961328 };
				add_debug_menu_entry(debug_render_menu, &animinfo);

				debug_menu_entry sceneaniminfo = { "SCENE_ANIM_INFO ", BOOLEAN_F, 0x961338 };
				add_debug_menu_entry(debug_render_menu, &sceneaniminfo);

				debug_menu_entry targeting = { "TARGETING ", BOOLEAN_F, 0x961348 };
				add_debug_menu_entry(debug_render_menu, &targeting);

				debug_menu_entry visspheres = { "VIS_SPHERES ", BOOLEAN_F, 0x961358 };
				add_debug_menu_entry(debug_render_menu, &visspheres);

				debug_menu_entry ladders = { "LADDERS ", BOOLEAN_F, 0x961368 };
				add_debug_menu_entry(debug_render_menu, &ladders);

				debug_menu_entry collisions = { "COLLISIONS ", BOOLEAN_F, 0x961378 };
				add_debug_menu_entry(debug_render_menu, &collisions);

				debug_menu_entry brainsenabled = { "BRAINS_ENABLED ", BOOLEAN_F, 0x961388 };
				add_debug_menu_entry(debug_render_menu, &brainsenabled);

				debug_menu_entry anchors = { "ANCHORS ", BOOLEAN_F, 0x961398 };
				add_debug_menu_entry(debug_render_menu, &anchors);

				debug_menu_entry lineinfo = { "LINE_INFO ", BOOLEAN_F, 0x9613A8 };
				add_debug_menu_entry(debug_render_menu, &lineinfo);

				debug_menu_entry subdivision = { "SUBDIVISION ", BOOLEAN_F, 0x9613B8 };
				add_debug_menu_entry(debug_render_menu, &subdivision);

				debug_menu_entry skeletons = { "SKELETONS ", BOOLEAN_F, 0x9613C8 };
				add_debug_menu_entry(debug_render_menu, &skeletons);

				debug_menu_entry soundstreamusage = { "SOUND_STREAM_USAGE ", BOOLEAN_F, 0x9613D8 };
				add_debug_menu_entry(debug_render_menu, &soundstreamusage);

				debug_menu_entry spheres = { "SPHERES ", BOOLEAN_F, 0x9613E8 };
				add_debug_menu_entry(debug_render_menu, &spheres);

				debug_menu_entry lines = { "LINES ", BOOLEAN_F, 0x9613F8 };
				add_debug_menu_entry(debug_render_menu, &lines);

				debug_menu_entry cylinders = { "CYLINDERS ", BOOLEAN_F, 0x961408 };
				add_debug_menu_entry(debug_render_menu, &cylinders);

				debug_menu_entry dgraph = { "DGRAPH ", BOOLEAN_F, 0x961418 };
				add_debug_menu_entry(debug_render_menu, &dgraph);

				debug_menu_entry peds = { "PEDS ", BOOLEAN_F, 0x961428 };
				add_debug_menu_entry(debug_render_menu, &peds);

				debug_menu_entry traffic = { "TRAFFIC ", BOOLEAN_F, 0x961438 };
				add_debug_menu_entry(debug_render_menu, &traffic);

				debug_menu_entry aicovermarkers = { "AI_COVER_MARKERS ", BOOLEAN_F, 0x961458 };
				add_debug_menu_entry(debug_render_menu, &aicovermarkers);

				debug_menu_entry limboglow = { "LIMBO_GLOW ", BOOLEAN_F, 0x961468 };
				add_debug_menu_entry(debug_render_menu, &limboglow);

				debug_menu_entry bipedcollvolumes = { "BIPED_COLL_VOLUMES ", BOOLEAN_F, 0x961478 };
				add_debug_menu_entry(debug_render_menu, &bipedcollvolumes);

				debug_menu_entry decals = { "DECALS ", BOOLEAN_F, 0x961488 };
				add_debug_menu_entry(debug_render_menu, &decals);
				
				

        }
				

				


			
				

				if (devopt_int_menu->used_slots == 0) {


				BYTE* ints0 = *(BYTE**)0X009685DC;
				debug_menu_entry int0 = { "DIFFICULTY", BOOLEAN_F,  &ints0[95 + 0x00] };
				add_debug_menu_entry(devopt_int_menu, &int0);

				BYTE* ints1 = *(BYTE**)0X009685DC;
				debug_menu_entry int1 = { "CAMERA_STYLE", BOOLEAN_F,  &ints1[95 + 0x01] };
				add_debug_menu_entry(devopt_int_menu, &int1);

				BYTE* ints2 = *(BYTE**)0X009685DC;
				debug_menu_entry int2 = { "CAMERA_STATE", BOOLEAN_F,  &ints2[95 + 0x02] };
				add_debug_menu_entry(devopt_int_menu, &int2);

				BYTE* ints3 = *(BYTE**)0X009685DC;
				debug_menu_entry int3 = { "CAMERA_FOV ", BOOLEAN_F,  &ints3[95 + 0x03] };
				add_debug_menu_entry(devopt_int_menu, &int3);

				BYTE* ints4 = *(BYTE**)0X009685DC;
				debug_menu_entry int4 = { "FOG_RED ", BOOLEAN_F,  &ints4[95 + 0x04] };
				add_debug_menu_entry(devopt_int_menu, &int4);

				BYTE* ints5 = *(BYTE**)0X009685DC;
				debug_menu_entry int5 = { "FOG_GREEN", BOOLEAN_F,  &ints5[95 + 0x05] };
				add_debug_menu_entry(devopt_int_menu, &int5);

				BYTE* ints6 = *(BYTE**)0X009685DC;
				debug_menu_entry int6 = { "FOG_DISTANCE", BOOLEAN_F,  &ints6[95 + 0x06] };
				add_debug_menu_entry(devopt_int_menu, &int6);

				BYTE* ints7 = *(BYTE**)0X009685DC;
				debug_menu_entry int7 = { "BIT DEPTH ", BOOLEAN_F,  &ints7[95 + 0x07] };
				add_debug_menu_entry(devopt_int_menu, &int7);

				BYTE* ints8 = (BYTE**)0X009685DC;
				debug_menu_entry int8 = { "MONKEY_MODE ", BOOLEAN_F,  &ints8[95 + 0x08] };
				add_debug_menu_entry(devopt_int_menu, &int8);

				BYTE* ints9 = *(BYTE**)0X009685DC;
				debug_menu_entry int9 = { "RANDOM_SEED", BOOLEAN_F,  &ints9[95 + 0x09] };
				add_debug_menu_entry(devopt_int_menu, &int9);

				BYTE* ints10 = *(BYTE**)0X009685DC;
				debug_menu_entry int10 = { "FORCE_WIN", BOOLEAN_F,  &ints10[95 + 0x0A] };
				add_debug_menu_entry(devopt_int_menu, &int10);

				BYTE* ints11 = *(BYTE**)0X009685DC;
				debug_menu_entry int11 = { "CONTROLLER_TYPE", BOOLEAN_F,  &ints11[95 + 0x0B] };
				add_debug_menu_entry(devopt_int_menu, &int11);

				BYTE* ints12 = *(BYTE**)0X009685DC;
				debug_menu_entry int12 = { "FRAME_LOCK", BOOLEAN_F,  &ints12[95 + 0x0C] };
				add_debug_menu_entry(devopt_int_menu, &int12);

				BYTE* ints13 = *(BYTE**)0X009685DC;
				debug_menu_entry int13 = { "FRAME_LIMIT", BOOLEAN_F,  &ints13[95 + 0x0D] };
				add_debug_menu_entry(devopt_int_menu, &int13);

				BYTE* ints14 = *(BYTE**)0X009685DC;
				debug_menu_entry int14 = { "SWING_DEBUG_TRAILS", BOOLEAN_F,  &ints14[95 + 0x0E] };
				add_debug_menu_entry(devopt_int_menu, &int14);

				BYTE* ints15 = *(BYTE**)0X009685DC;
				debug_menu_entry int15 = { "SOAK_SMOKE", BOOLEAN_F,  &ints15[95 + 0x0F] };
				add_debug_menu_entry(devopt_int_menu, &int15);

				BYTE* ints16 = *(BYTE**)0X009685DC;
				debug_menu_entry int16 = { "FAR_CLIP_PLANE", BOOLEAN_F,  &ints16[95 + 0x10] };
				add_debug_menu_entry(devopt_int_menu, &int16);

				BYTE* ints17 = *(BYTE**)0X009685DC;
				debug_menu_entry int17 = { "POI_DISPLAY_TYPE", BOOLEAN_F,  &ints17[95 + 0x11] };
				add_debug_menu_entry(devopt_int_menu, &int17);

				BYTE* ints18 = *(BYTE**)0X009685DC;
				debug_menu_entry int18 = { "STORY_MISSION", BOOLEAN_F,  &ints18[95 + 0x12] };
				add_debug_menu_entry(devopt_int_menu, &int18);

				BYTE* ints19 = *(BYTE**)0X009685DC;
				debug_menu_entry int19 = { "EXEC_DELAY", BOOLEAN_F,  &ints19[95 + 0x13] };
				add_debug_menu_entry(devopt_int_menu, &int19);

				BYTE* ints20 = *(BYTE**)0X009685DC;
				debug_menu_entry int20 = { "RUN_LENGTH", BOOLEAN_F,  &ints20[95 + 0x14] };
				add_debug_menu_entry(devopt_int_menu, &int20);

				BYTE* ints21 = *(BYTE**)0X009685DC;
				debug_menu_entry int21 = { "PC_WINDOW_TOP", BOOLEAN_F,  &ints21[95 + 0x15] };
				add_debug_menu_entry(devopt_int_menu, &int21);

				BYTE* ints22 = *(BYTE**)0X009685DC;
				debug_menu_entry int22 = { "PC_WINDOW_LEFT", BOOLEAN_F,  &ints22[95 + 0x16] };
				add_debug_menu_entry(devopt_int_menu, &int22);

				BYTE* ints23 = *(BYTE**)0X009685DC;
				debug_menu_entry int23 = { "PC_WINDOW_WIDTH", BOOLEAN_F,  &ints23[95 + 0x17] };
				add_debug_menu_entry(devopt_int_menu, &int23);

				BYTE* ints24 = *(BYTE**)0X009685DC;
				debug_menu_entry int24 = { "PC_WINDOW_HEIGHT", BOOLEAN_F,  &ints24[95 + 0x18] };
				add_debug_menu_entry(devopt_int_menu, &int24);

				BYTE* ints25 = *(BYTE**)0X009685DC;
				debug_menu_entry int25 = { "ALLOW_SCREENSHOT", BOOLEAN_F,  &ints25[95 + 0x19] };
				add_debug_menu_entry(devopt_int_menu, &int25);

				BYTE* ints26 = *(BYTE**)0X009685DC;
				debug_menu_entry int26 = { "AMALGA_REFRESH_INTERVAL", BOOLEAN_F,  &ints26[95 + 0x1A] };
				add_debug_menu_entry(devopt_int_menu, &int26);

				BYTE* ints27 = *(BYTE**)0X009685DC;
				debug_menu_entry int27 = { "ENABLE_LONG_MALOR_ASSERTS", BOOLEAN_F,  &ints27[95 + 0x1B] };
				add_debug_menu_entry(devopt_int_menu, &int27);

				BYTE* ints28 = *(BYTE**)0X009685DC;
				debug_menu_entry int28 = { "GOD MODE ", BOOLEAN_F,  &ints28[95 + 0x1C] };
				add_debug_menu_entry(devopt_int_menu, &int28);

				BYTE* ints29 = *(BYTE**)0X009685DC;
				debug_menu_entry int29 = { "PCLISTBUFFER", BOOLEAN_F,  &ints29[95 + 0x1D] };
				add_debug_menu_entry(devopt_int_menu, &int29);

				BYTE* ints30 = *(BYTE**)0X009685DC;
				debug_menu_entry int30 = { "PCSCRATCHBUFFER", BOOLEAN_F,  &ints30[95 + 0x1E] };
				add_debug_menu_entry(devopt_int_menu, &int1);

				BYTE* ints31 = *(BYTE**)0X009685DC;
				debug_menu_entry int31 = { "PCSCRATCHINDEXBUFFER", BOOLEAN_F,  &ints31[95 + 0x1F] };
				add_debug_menu_entry(devopt_int_menu, &int31);

				BYTE* ints32 = *(BYTE**)0X009685DC;
				debug_menu_entry int32 = { "PCSCRATCHVERTEXBUFFER", BOOLEAN_F,  &ints32[95 + 0x20] };
				add_debug_menu_entry(devopt_int_menu, &int32);


				BYTE* ints33 = *(BYTE**)0X009685DC;
				debug_menu_entry int33 = { "NAL_HEAP_SIZE", BOOLEAN_F,  &ints33[95 + 0x21] };
				add_debug_menu_entry(devopt_int_menu, &int33);

				BYTE* ints34 = *(BYTE**)0X009685DC;
				debug_menu_entry int34 = { "ASSERT_BOX_MARGIN", BOOLEAN_F,  &ints34[95 + 0x22] };
				add_debug_menu_entry(devopt_int_menu, &int34);

				BYTE* ints35 = *(BYTE**)0X009685DC;
				debug_menu_entry int35 = { "ASSERT_TEXT_MARGIN", BOOLEAN_F,  &ints35[95 + 0x23] };
				add_debug_menu_entry(devopt_int_menu, &int35);

				BYTE* ints36 = *(BYTE**)0X009685DC;
				debug_menu_entry int36 = { "ASSERT_FONT_PCT_X", BOOLEAN_F,  &ints36[95 + 0x24] };
				add_debug_menu_entry(devopt_int_menu, &int36);

				BYTE* ints37 = *(BYTE**)0X009685DC;
				debug_menu_entry int37 = { "ASSERT_FONT_PCT_Y", BOOLEAN_F,  &ints37[95 + 0x25] };
				add_debug_menu_entry(devopt_int_menu, &int37);

				BYTE* ints38 = *(BYTE**)0X009685DC;
				debug_menu_entry int38 = { "STREAMER_INFO_FONT_PCT", BOOLEAN_F,  &ints38[95 + 0x26] };
				add_debug_menu_entry(devopt_int_menu, &int38);

				BYTE* ints39 = *(BYTE**)0X009685DC;
				debug_menu_entry int39 = { "DEBUG_INFO_FONT_PCT", BOOLEAN_F,  &ints39[95 + 0x27] };
				add_debug_menu_entry(devopt_int_menu, &int39);

				BYTE* ints40 = *(BYTE**)0X009685DC;
				debug_menu_entry int40 = { "PITCH_FACTOR", BOOLEAN_F,  &ints40[95 + 0x28] };
				add_debug_menu_entry(devopt_int_menu, &int40);

				BYTE* ints41 = *(BYTE**)0X009685DC;
				debug_menu_entry int41 = { "BANK_FACTOR", BOOLEAN_F,  &ints41[95 + 0x29] };
				add_debug_menu_entry(devopt_int_menu, &int41);

				BYTE* ints42 = *(BYTE**)0X009685DC;
				debug_menu_entry int42 = { "SWING_INTERPOLATION_TIME", BOOLEAN_F,  &ints42[95 + 0x2A] };
				add_debug_menu_entry(devopt_int_menu, &int42);

				BYTE* ints43 = *(BYTE**)0X009685DC;
				debug_menu_entry int43 = { "BOTH_HANDS_INTERPOLATION_TIME", BOOLEAN_F,  &ints43[95 + 0x2B] };
				add_debug_menu_entry(devopt_int_menu, &int43);

				BYTE* ints44 = *(BYTE**)0X009685DC;
				debug_menu_entry int44 = { "MEM_DUMP_FRAME", BOOLEAN_F,  &ints44[95 + 0x2C] };
				add_debug_menu_entry(devopt_int_menu, &int44);

				BYTE* ints45 = *(BYTE**)0X009685DC;
				debug_menu_entry int45 = { "HERO_START_X",  BOOLEAN_F,  &ints45[95 + 0x2D] };
				add_debug_menu_entry(devopt_int_menu, &int45);

				BYTE* ints46 = *(BYTE**)0X009685DC;
				debug_menu_entry int46 = { "HERO_START_Y",  BOOLEAN_F,  &ints46[95 + 0x2E] };
				add_debug_menu_entry(devopt_int_menu, &int46);

				BYTE* ints47 = *(BYTE**)0X009685DC;
				debug_menu_entry int47 = { "HERO_START_Z", BOOLEAN_F,  &ints47[95 + 0x2F] };
				add_debug_menu_entry(devopt_int_menu, &int47);

				BYTE* ints48 = *(BYTE**)0X009685DC;
				debug_menu_entry int48 = { "SHOW_SOUND_INFO", BOOLEAN_F,  &ints48[95 + 0x30] };
				add_debug_menu_entry(devopt_int_menu, &int48);

				BYTE* ints49 = *(BYTE**)0X009685DC;
				debug_menu_entry int49 = { "SHOW_VOICE_BOX_INFO", BOOLEAN_F,  &ints49[95 + 0x31] };
				add_debug_menu_entry(devopt_int_menu, &int49);

				BYTE* ints50 = *(BYTE**)0X009685DC;
				debug_menu_entry int50 = { "DEBUG_CAMERA_PITCH_MULTIPLIER", BOOLEAN_F,  &ints50[95 + 0x32] };
				add_debug_menu_entry(devopt_int_menu, &int50);

				BYTE* ints51 = *(BYTE**)0X009685DC;
				debug_menu_entry int51 = { "DEBUG_CAMERA_YAW_MULTIPLIER", BOOLEAN_F,  &ints51[95 + 0x33] };
				add_debug_menu_entry(devopt_int_menu, &int51);

				BYTE* ints52 = *(BYTE**)0X009685DC;
				debug_menu_entry int52 = { "DEBUG_CAMERA_MOVE_MULTIPLIER", BOOLEAN_F,  &ints52[95 + 0x34] };
				add_debug_menu_entry(devopt_int_menu, &int52);

				BYTE* ints53 = *(BYTE**)0X009685DC;
				debug_menu_entry int53 = { "DEBUG_CAMERA_STRAFE_MULTIPLIER", BOOLEAN_F,  &ints53[95 + 0x35] };
				add_debug_menu_entry(devopt_int_menu, &int53);

				BYTE* ints54 = *(BYTE**)0X009685DC;
				debug_menu_entry int54 = { "TAM_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints54[95 + 0x36] };
				add_debug_menu_entry(devopt_int_menu, &int54);

				BYTE* ints55 = *(BYTE**)0X009685DC;
				debug_menu_entry int55 = { "TAM_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints55[95 + 0x37] };
				add_debug_menu_entry(devopt_int_menu, &int55);

				BYTE* ints56 = *(BYTE**)0X009685DC;
				debug_menu_entry int56 = { "THUG_HEALTH_UI_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints56[95 + 0x38] };
				add_debug_menu_entry(devopt_int_menu, &int56);

				BYTE* ints57 = *(BYTE**)0X009685DC;
				debug_menu_entry int57 = { "THUG_HEALTH_UI_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints57[156 + 0x39] };
				add_debug_menu_entry(devopt_int_menu, &int57);

				BYTE* ints58 = *(BYTE**)0X009685DC;
				debug_menu_entry int58 = { "THUG_HEALTH_UI_SCALE_MIN_PERCENT", BOOLEAN_F,  &ints58[156 + 0x3A] };
				add_debug_menu_entry(devopt_int_menu, &int58);

				BYTE* ints59 = *(BYTE**)0X009685DC;
				debug_menu_entry int59 = { "THUG_HEALTH_UI_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints59[156 + 0x3B] };
				add_debug_menu_entry(devopt_int_menu, &int59);

				BYTE* ints60 = *(BYTE**)0X009685DC;
				debug_menu_entry int60 = { "TestInt", BOOLEAN_F,  &ints60[156 + 0x3C] };
				add_debug_menu_entry(devopt_int_menu, &int60);

				BYTE* ints61 = *(BYTE**)0X009685DC;
				debug_menu_entry int61 = { "TestInt2", BOOLEAN_F,  &ints61[156 + 0x3D] };
				add_debug_menu_entry(devopt_int_menu, &int61);

				BYTE* ints62 = *(BYTE**)0X009685DC;
				debug_menu_entry int62 = { "TARGETING_RETICLE_SCALE_MIN_DISTANCE", BOOLEAN_F,  &ints62[156 + 0x3E] };
				add_debug_menu_entry(devopt_int_menu, &int62);

				BYTE* ints63 = *(BYTE**)0X009685DC;
				debug_menu_entry int63 = { "TARGETING_RETICLE_SCALE_MAX_DISTANCE", BOOLEAN_F,  &ints63[156 + 0x3F] };
				add_debug_menu_entry(devopt_int_menu, &int63);

				BYTE* ints64 = *(BYTE**)0X009685DC;
				debug_menu_entry int64 = { "TARGETING_RETICLE_SCALE_MIN_PERCENT", BOOLEAN_F,  &ints64[156 + 0x40] };
				add_debug_menu_entry(devopt_int_menu, &int64);


				BYTE* ints65 = *(BYTE**)0X009685DC;
				debug_menu_entry int65 = { "HIRES_SCREENSHOT_X", BOOLEAN_F,  &ints65[95 + 0x41] };
				add_debug_menu_entry(devopt_int_menu, &int65);


				BYTE* ints6a = *(BYTE**)0X009685DC;
				debug_menu_entry int6a = { "HIRES_SCREENSHOT_Y", BOOLEAN_F,  &ints6a[156 + 0x42] };
				add_debug_menu_entry(devopt_int_menu, &int6a);

				BYTE* ints66 = *(BYTE**)0X009685DC;
				debug_menu_entry int66 = { "TIME_OF_DAY", BOOLEAN_F,  &ints66[95 + 0x43] };
				add_debug_menu_entry(devopt_int_menu, &int66);

				BYTE* ints67 = *(BYTE**)0X009685DC;
				debug_menu_entry int67 = { "MINI_MAP_ZOOM", BOOLEAN_F,  &ints67[95 + 0x44] };
				add_debug_menu_entry(devopt_int_menu, &int67);

				BYTE* ints68 = *(BYTE**)0X009685DC;
				debug_menu_entry int68 = { "RTDT_REPLAY_BUFFER_SIZE", BOOLEAN_F,  &ints68[95 + 0x45] };
				add_debug_menu_entry(devopt_int_menu, &int68);

				BYTE* ints69 = *(BYTE**)0X009685DC;
				debug_menu_entry int69 = { "TIMER_WIDGET_TIME_DELTA_PERCENT", BOOLEAN_F,  &ints69[95 + 0x46] };
				add_debug_menu_entry(devopt_int_menu, &int69);

				BYTE* ints70 = *(BYTE**)0X009685DC;
				debug_menu_entry int70 = { "DEBUG_PARTICLE_LEVEL", BOOLEAN_F,  &ints70[95 + 0x47] };
				add_debug_menu_entry(devopt_int_menu, &int70);

				BYTE* ints71 = *(BYTE**)0X009685DC;
				debug_menu_entry int71 = { "DEBUG_PARTICLE_MEMORY", BOOLEAN_F,  &ints71[95 + 0x48] };
				add_debug_menu_entry(devopt_int_menu, &int71);

				BYTE* ints72 = *(BYTE**)0X009685DC;
				debug_menu_entry int72 = { "MAX_AEPS_ENTITIES", BOOLEAN_F,  &ints72[95 + 0x49] };
				add_debug_menu_entry(devopt_int_menu, &int72);

				BYTE* ints73 = *(BYTE**)0X009685DC;
				debug_menu_entry int73 = { "MAX_AEPS_SPAWNERS", BOOLEAN_F,  &ints73[95 + 0x4A] };
				add_debug_menu_entry(devopt_int_menu, &int73);

				BYTE* ints74 = *(BYTE**)0X009685DC;
				debug_menu_entry int74 = { "MAX_AEPS_EMITTERS", BOOLEAN_F,  &ints74[95 + 0x4B] };
				add_debug_menu_entry(devopt_int_menu, &int74);

				BYTE* ints75 = *(BYTE**)0X009685DC;
				debug_menu_entry int75 = { "MAX_AEPS_PARTICLES", BOOLEAN_F,  &ints75[95 + 0x4C] };
				add_debug_menu_entry(devopt_int_menu, &int75);

			}


		}

		if (debug_enabled) {



#define SCROLL_SPEED 4
			if (keys[DIK_DOWNARROW]) {

				if (keys[DIK_DOWNARROW] == 1) {
					menu_go_down();
				}
				else if (keys[DIK_DOWNARROW] >= SCROLL_SPEED && keys[DIK_DOWNARROW] % SCROLL_SPEED == 0) {
					menu_go_down();
				}
			}
			else if (keys[DIK_UPARROW]) {

				if (keys[DIK_UPARROW] == 1) {
					menu_go_up();
				}
				else if (keys[DIK_UPARROW] >= SCROLL_SPEED && keys[DIK_UPARROW] % SCROLL_SPEED == 0) {
					menu_go_up();
				}
			}
			else if (keys[DIK_RETURN] == 2) {
				current_menu->handler(&current_menu->entries[current_menu->window_start + current_menu->cur_index], ENTER);
			}
			else if (keys[DIK_SPACE] == 2) {
				current_menu->go_back();
			}
			else if (keys[DIK_LEFTARROW] == 2 || keys[DIK_RIGHTARROW] == 2) {

				debug_menu_entry* cur = &current_menu->entries[current_menu->window_start + current_menu->cur_index];
				if (cur->entry_type == BOOLEAN_E || cur->entry_type == CUSTOM)
					current_menu->handler(cur, (keys[DIK_LEFTARROW] == 2 ? LEFT : RIGHT));
			}


		}

	}


	if (debug_enabled) {
		memset(lpvData, 0, cbData);
	}



	//printf("Device State called %08X %d\n", this, cbData);

	return res;
}

typedef HRESULT(__stdcall* GetDeviceData_ptr)(IDirectInputDevice8*, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
GetDeviceData_ptr GetDeviceDataOriginal = NULL;

HRESULT __stdcall GetDeviceDataHook(IDirectInputDevice8* this, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags) {

	HRESULT res = GetDeviceDataOriginal(this, cbObjectData, rgdod, pdwInOut, dwFlags);


	if (res == DI_OK) {

		printf("All gud\n");
		for (int i = 0; i < *pdwInOut; i++) {


			if (LOBYTE(rgdod[i].dwData) > 0) {

				if (rgdod[i].dwOfs == DIK_SPACE) {

					printf("Pressed escaped\n");
					__debugbreak();
				}
			}
		}
	}
	//printf("Device Data called %08X\n", this);

	return res;
}



typedef HRESULT(__stdcall* IDirectInput8CreateDevice_ptr)(IDirectInput8W*, const GUID*, LPDIRECTINPUTDEVICE8W*, LPUNKNOWN);
IDirectInput8CreateDevice_ptr createDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8CreateDeviceHook(IDirectInput8W* this, const GUID* guid, LPDIRECTINPUTDEVICE8W* device, LPUNKNOWN unk) {

	//printf("CreateDevice %d %d %d %d %d %d %d\n", *guid, GUID_SysMouse, GUID_SysKeyboard, GUID_SysKeyboardEm, GUID_SysKeyboardEm2, GUID_SysMouseEm, GUID_SysMouseEm2);


	HRESULT res = createDeviceOriginal(this, guid, device, unk);

	DWORD* vtbl = (*device)->lpVtbl;
	if (!GetDeviceStateOriginal) {
		GetDeviceStateOriginal = vtbl[9];
		vtbl[9] = GetDeviceStateHook;
	}

	if (!GetDeviceDataOriginal) {
		GetDeviceDataOriginal = vtbl[10];
		vtbl[10] = GetDeviceDataHook;
	}

	return res;
}

typedef HRESULT(__stdcall* IDirectInput8Release_ptr)(IDirectInput8W*);
IDirectInput8Release_ptr releaseDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8ReleaseHook(IDirectInput8W* this) {

	printf("Release\n");

	return releaseDeviceOriginal(this);
}


BOOL CALLBACK EnumDevices(LPCDIDEVICEINSTANCE lpddi, LPVOID buffer) {

	wchar_t wGUID[40] = { 0 };
	char cGUID[40] = { 0 };

	//printf("%d\n", lpddi->guidProduct);
}

typedef HRESULT(__stdcall* DirectInput8Create_ptr)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
HRESULT __stdcall HookDirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	DirectInput8Create_ptr caller = *(void**)0x00987944;
	HRESULT res = caller(hinst, dwVersion, riidltf, ppvOut, punkOuter);


	IDirectInput8** iDir = ppvOut;
	printf("it's me mario %08X %08X\n", ppvOut, (*iDir)->lpVtbl);


	DWORD* vtbl = (DWORD*)(*iDir)->lpVtbl;
	if (!createDeviceOriginal) {
		createDeviceOriginal = vtbl[3];
		vtbl[3] = IDirectInput8CreateDeviceHook;
	}


	//(*iDir)->lpVtbl->EnumDevices(*iDir, DI8DEVCLASS_ALL, EnumDevices, NULL, DIEDFL_ALLDEVICES);
	return res;
}


DWORD hookDirectInputAddress = HookDirectInput8Create;


void update_state() {

	while (1) {
		OutputDebugStringA("PILA %d", 6);
	}
}

typedef int(__fastcall* game_handle_game_states_ptr)(void* this, void* edx, void* a2);
game_handle_game_states_ptr game_handle_game_states_original = 0x0055D510;

int __fastcall game_handle_game_states(void* this, void* edx, void* a2) {

	if (!g_game_ptr) {
		g_game_ptr = this;
	}

	if (changing_model) {


		changing_model--;

		if (!changing_model) {
			mString str;
			mString_constructor(&str, NULL, current_costume);
			world_dynamics_system_add_player(*(DWORD*)g_world_ptr, NULL, &str);
			mString_finalize(&str, NULL, 0);
			game_unpause(g_game_ptr);
		}
	}

	if (changing_mission) {


		changing_mission--;

		if (!changing_mission) {

			mString str;
			mString_constructor(&str, NULL, current_mission);
			world_dynamics_system_add_player(*(DWORD*)g_world_ptr, NULL, &str);
			mString_finalize(&str, NULL, 0);
			game_unpause(g_game_ptr);
		}
	}


	/*
	if (game_get_cur_state(this) == 14)
		__debugbreak();
		*/


		//printf("Current state %d %08X\n", game_get_cur_state(this), g_game_ptr);

	return game_handle_game_states_original(this, edx, a2);
}

typedef void(__fastcall* sub_41F9D0_ptr)(char* this, void* edx, const char* a2, signed int a3);
sub_41F9D0_ptr sub_41F9D0 = 0x41F9D0;


void __fastcall sub_41F9D0_hook(char* this, void* edx, const char* a2, signed int a3) {

	//printf("mString:%s\n", a2);


	return sub_41F9D0(this, edx, a2, a3);
}

typedef DWORD(__fastcall* ai_hero_base_state_check_transition_ptr)(DWORD* this, void* edx, DWORD* a2, int a3);
ai_hero_base_state_check_transition_ptr ai_hero_base_state_check_transition = 0x00478D80;

DWORD __fastcall ai_hero_base_state_check_transition_hook(DWORD* this, void* edx, DWORD* a2, int a3) {
	ai_current_player = this;
	return ai_hero_base_state_check_transition(this, edx, a2, a3);
}


typedef DWORD* (__fastcall* get_info_node_ptr)(void* this, void* edx, int a2, char a3);
get_info_node_ptr get_info_node = 0x006A3390;

DWORD* __fastcall get_info_node_hook(void* this, void* edx, int a2, char a3) {

	DWORD* res = get_info_node(this, edx, a2, a3);

	fancy_player_ptr = res;
	return res;
}


typedef int(_fastcall* resource_pack_streamer_load_internal_ptr)(void* this, void* edx, char* str, int a3, int a4, int a5);
resource_pack_streamer_load_internal_ptr resource_pack_streamer_load_internal = 0x0054C580;

void __fastcall resource_pack_streamer_load_internal_hook(void* this, void* edx, char* str, int a3, int a4, int a5) {


	return resource_pack_streamer_load_internal(this, edx, str, a3, a4, a5);
}


uint8_t __fastcall os_developer_options_flag(BYTE* this, void* edx, int flag) {

	char** flag_list = 0x936420;
	char* flag_text = flag_list[flag];

	uint8_t res = this[flag + 4];

	if (flag == 0x90) {
		printf("Game wants to know about: %d (%s) -> %d\n", flag, flag_text, res);
		__debugbreak();
	}


	//this[5 + 4] = 1;

	return res;
}

int __fastcall os_developer_options_int(DWORD* this, void* eax, int ints)
{
	char** ints_list = 0x936940;
	char* ints_text = ints_list[ints];

	uint8_t res = this[ints + 95];

	if (ints == 0x4C) {
		printf("Game wants to know about: %d (%s) -> %d\n", ints, ints_text, res);
		__debugbreak();
	}
	// this[5 + 95] = 1;
	return res;
}

void install_patches() {

	HookFunc(0x004EACF0, (DWORD)aeps_RenderAll, 0, "Patching call to aeps::RenderAll");

	HookFunc(0x0052B5D7, (DWORD)myDebugMenu, 0, "Hooking nglListEndScene to inject debug menu");
	//save orig ptr
	nflSystemOpenFile_orig = *nflSystemOpenFile_data;
	*nflSystemOpenFile_data = &nflSystemOpenFile;
	printf("Replaced nflSystemOpenFile %08X -> %08X\n", (DWORD)nflSystemOpenFile_orig, (DWORD)&nflSystemOpenFile);


	ReadOrWrite_orig = *ReadOrWrite_data;
	*ReadOrWrite_data = &ReadOrWrite;
	printf("Replaced ReadOrWrite %08X -> %08X\n", (DWORD)ReadOrWrite_orig, (DWORD)&ReadOrWrite);


	*(DWORD*)0x008218B2 = &hookDirectInputAddress;
	printf("Patching the DirectInput8Create call\n");


	HookFunc(0x0055D742, (DWORD)game_handle_game_states, 0, "Hooking handle_game_states");

	HookFunc(0x00421128, (DWORD)sub_41F9D0_hook, 0, "Hooking sub_41F9D0");


	/*
	WriteDWORD(0x00877524, ai_hero_base_state_check_transition_hook, "Hooking check_transition for peter hooded");
	WriteDWORD(0x00877560, ai_hero_base_state_check_transition_hook, "Hooking check_transition for spider-man");
	WriteDWORD(0x0087759C, ai_hero_base_state_check_transition_hook, "Hooking check_transition for venom");
	*/

	HookFunc(0x00478DBF, get_info_node_hook, 0, "Hook get_info_node to get player ptr");


	WriteDWORD(0x0089C710, slf__create_progression_menu_entry, "Hooking first ocurrence of create_progression_menu_entry");
	WriteDWORD(0x0089C718, slf__create_progression_menu_entry, "Hooking second ocurrence of create_progression_menu_entry");

	WriteDWORD(0x0089AF70, slf__create_debug_menu_entry, "Hooking first ocurrence of create_debug_menu_entry");
	WriteDWORD(0x0089C708, slf__create_debug_menu_entry, "Hooking second  ocurrence of create_debug_menu_entry");


	HookFunc(0x005AD77D, construct_client_script_libs_hook, 0, "Hooking construct_client_script_libs to inject my vm");

	WriteDWORD(0x0089C720, slf__destroy_debug_menu_entry__debug_menu_entry, "Hooking destroy_debug_menu_entry");
	WriteDWORD(0x0089C750, slf__debug_menu_entry__set_handler__str, "Hooking set_handler");

	//HookFunc(0x0054C89C, resource_pack_streamer_load_internal_hook, 1, "Hooking resource_pack_streamer::load_internal to inject interior loading");

	//HookFunc(0x005B87E0, os_developer_options_flag, 1, "Hooking os_developer_options::get_flag");
	//HookFunc(0x005B8810, os_developer_options_int, 1, "Hooking os_developer_options::get_int");

}

void close_debug() {
	debug_enabled = 0;
	game_pause(g_game_ptr);
}

void handle_debug_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}





typedef char(__fastcall* entity_tracker_manager_get_the_arrow_target_pos_ptr)(DWORD* this, void* edx, DWORD* a2);
entity_tracker_manager_get_the_arrow_target_pos_ptr entity_tracker_manager_get_the_arrow_target_pos = 0x0062EE10;

void handle_warp_entry(debug_menu_entry* entry) {


	float position[] = {
		0, -0, 1, 0,
		1, -0, -0, 0,
		0, 1, 0, 0,
		-203, 20, 430, 1
	};

	/*
	DWORD arg1 = *(DWORD*)0x96C158;
	DWORD* some_ptr = ai_ai_core_get_info_node(ai_current_player[5], NULL, arg1, 1);
	printf("WHYYYY %08X %08X\n", fancy_player_ptr, some_ptr);
	*/


	float final_pos[3] = { -203, 20, 430 };
	if (entry->data1 == 0) {
		region* cur_region = entry->data;
		final_pos[0] = cur_region->x;
		final_pos[1] = cur_region->y;
		final_pos[2] = cur_region->z;
		unlock_region(cur_region);
	}
	else {
		int res = entity_tracker_manager_get_the_arrow_target_pos(*(*(DWORD***)0x937B18 + 21), NULL, final_pos);
		if (!res)
			return;
	}

	position[12] = final_pos[0];
	position[13] = final_pos[1];
	position[14] = final_pos[2];

	close_debug();
	entity_teleport_abs_po(fancy_player_ptr[3], position, 1);
}






void handle_hero_entry(debug_menu_entry* entry) {

	DWORD* some_number = (*(DWORD**)g_world_ptr) + 142;

	while (*some_number) {
		//printf("some_number %d\n", *some_number);
		world_dynamics_system_remove_player(*(DWORD*)g_world_ptr, NULL, *some_number - 1);
	}

	debug_enabled = 1;
	changing_model = 2;
	current_costume = entry->text;
	BYTE* val = entry->data;
	*val = !*val;
	close_debug();
}




void handle_mission_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}


void handle_streams_entry(debug_menu_entry* entry) {
	BYTE* val = entry->data;
	*val = !*val;

}


void handle_jf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_jg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_kh_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}

void handle_lf_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;


}

void handle_lg_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}
void handle_lh_entry(debug_menu_entry* entry) {
	BYTE* val = entry->text;
	*val = !*val;

}




















void handle_game_flags_entry(debug_menu_entry* entry, debug_menu_entry* enter) {

	BYTE* val = entry->data;
	*val = !*val;
	
	
}



typedef void* (__fastcall* script_instance_add_thread_ptr)(script_instance* this, void* edx, vm_executable* a1, void* a2);
script_instance_add_thread_ptr script_instance_add_thread = 0x005AAD00;

void handle_progression_select_entry(debug_menu_entry* entry) {

	script_instance* instance = entry->data;
	int functionid = entry->data1;

	DWORD addr = entry;

	script_instance_add_thread(instance, NULL, instance->object->vmexecutable[functionid], &addr);
	close_debug();
}


void handle_memory_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}

void handle_script_entry(debug_menu_entry* entry) {
	handle_progression_select_entry(entry);
}


void handle_devopt_flags_entry(debug_menu_entry* entry) {

	BYTE* val = entry->data;
	*val = !*val;
}


void handle_devopt_int_entry(debug_menu_entry* entry) {

	DWORD* val = entry->data;
	*val = !*val;
}

void handle_level_select_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}


void handle_debug_render_entry(debug_menu_entry* entry) {
	BYTE* val = entry->data;
	*val = !*val;

}

void handle_replay_entry(debug_menu_entry* entry) {
	current_menu = entry->data;

}

void handle_ai_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}

void handle_ai_1_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_entity_variants_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}

void handle_entity_1_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_entity_2_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_3_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_4_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_5_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_6_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_7_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_8_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_9_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}

void handle_entity_10_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}
void handle_entity_11_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;

}


void handle_codesize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_initdatasize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_uninitsize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_stacksize_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_savegame_opt_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_slabs_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}

void handle_scriptmemtrack_entry(debug_menu_entry* entry) {

	BYTE* val = entry->text;
	*val = !*val;
}


void handle_distriction_variants_select_entry(debug_menu_entry* entry, custom_key_type key_type) {

	region* reg = entry->data;
	void* terrain_ptr = *(*(DWORD***)g_world_ptr + 0x6B);
	int variants = reg->variants;
	int current_variant = region_get_district_variant(reg);
	DWORD district_id = reg->district_id;

	switch (key_type) {

	case LEFT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant - 1, variants), 1);
		break;
	case RIGHT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant + 1, variants), 1);
		break;
	default:
		return;
	}
}

void handle_game_entry(debug_menu_entry* entry, custom_key_type key_type) {

current_menu = entry->data;

}










	



void setup_debug_menu() {

	start_debug = create_menu("Debug Menu", close_debug, handle_debug_entry, 2);
	warp_menu = create_menu("Warp", goto_start_debug, handle_warp_entry, 300);
	game_menu = create_menu("Game", goto_start_debug, handle_game_entry, 4);
	game_flags_menu = create_menu("Game Flags", goto_start_debug, handle_game_flags_entry, 7);
	devopt_flags_menu = create_menu("Devopt Flags", goto_start_debug, handle_devopt_flags_entry, 150);
	devopt_int_menu = create_menu("Devopt Ints", goto_start_debug, handle_devopt_int_entry, 76);
	savegame_opt_menu = create_menu("Saved Game Settings", goto_start_debug, handle_savegame_opt_entry, 1);
	mission_menu = create_menu("Missions", goto_start_debug, handle_mission_entry, 1);
	jf = create_menu("JF", goto_start_debug, handle_jf_entry, 1);
	jg = create_menu("JG", goto_start_debug, handle_jg_entry, 1);
	kf = create_menu("KF", goto_start_debug, handle_kf_entry, 1);
	kg = create_menu("KG", goto_start_debug, handle_kg_entry, 1);
	kh = create_menu("KH", goto_start_debug, handle_kh_entry, 1);
	lf = create_menu("LH", goto_start_debug, handle_lf_entry, 1);
	lg = create_menu("LG", goto_start_debug, handle_lg_entry, 1);
	lh = create_menu("LH", goto_start_debug, handle_lh_entry, 1);
	debug_render_menu = create_menu("Debug Render", goto_start_debug, handle_debug_render_entry, 2);
	district_variants_menu = create_menu("District variants", goto_start_debug, handle_distriction_variants_select_entry, 15);
	replay_menu = create_menu("Replay", close_debug, handle_replay_entry, 2);
	ai_menu = create_menu("AI", goto_start_debug, handle_ai_entry, 2);
	ai_0 = create_menu("0x003ac42e", goto_start_debug, handle_ai_1_entry, 2);
	memory_menu = create_menu("Memory", goto_start_debug, handle_memory_entry, 2);
	scriptmemtrack_menu = create_menu("Script Memtrack", goto_start_debug, handle_scriptmemtrack_entry, 2);
	slabs_menu = create_menu("Slabs", goto_start_debug, handle_slabs_entry, 2);
	stacksize_menu = create_menu("Stack Size KB", goto_start_debug, handle_stacksize_entry, 2);
	initsize_menu = create_menu("Init Data Size", goto_start_debug, handle_initdatasize_entry, 2);
	codesize_menu = create_menu("Code Size KB", goto_start_debug, handle_codesize_entry, 2);
	uninitsize_menu = create_menu("Uninit Data Size", goto_start_debug, handle_uninitsize_entry, 2);
	entity_menu = create_menu("Entity", goto_start_debug, handle_entity_variants_entry, 2);
	entity_1 = create_menu("0x008230d88", goto_start_debug, handle_entity_1_entry, 1);
	entity_2 = create_menu("0x008230d89", goto_start_debug, handle_entity_2_entry, 1);
	entity_3 = create_menu("0x008230d8a", goto_start_debug, handle_entity_3_entry, 1);
	entity_4 = create_menu("0x008230d8b", goto_start_debug, handle_entity_4_entry, 1);
	entity_5 = create_menu("0x008230d8c", goto_start_debug, handle_entity_5_entry, 1);
	entity_6 = create_menu("0x008230d8d", goto_start_debug, handle_entity_6_entry, 1);
	entity_7 = create_menu("0x008230d8e", goto_start_debug, handle_entity_7_entry, 1);
	entity_8 = create_menu("0x008230d8f", goto_start_debug, handle_entity_8_entry, 1);
	entity_9 = create_menu("0x008230d90", goto_start_debug, handle_entity_9_entry, 1);
	entity_10 = create_menu("0x008230d91", goto_start_debug, handle_entity_10_entry, 1);
	entity_11 = create_menu("0x008230d92", goto_start_debug, handle_entity_11_entry, 1);
	level_select_menu = create_menu("Level Select", goto_start_debug, handle_level_select_entry, 2);
	hero_menu = create_menu("Hero", goto_start_debug, handle_hero_entry, 5);
	script_menu = create_menu("Script", goto_start_debug, handle_script_entry, 50);
	progression_menu = create_menu("Progression", goto_start_debug, handle_progression_select_entry, 10);
	streams_menu = create_menu("Streams", goto_start_debug, handle_streams_entry, 2);



	debug_menu_entry warp_entry = { "Warp", BOOLEAN_G, warp_menu };
	debug_menu_entry game_entry = { "Game", BOOLEAN_G, game_menu };
	debug_menu_entry game_flags_entry = { "Game Flags", BOOLEAN_G, game_flags_menu };
	debug_menu_entry devopt_flags_entry = { "Devopt Flags", BOOLEAN_G, devopt_flags_menu };
	debug_menu_entry devopt_int_entry = { "Devopt Ints", BOOLEAN_G, devopt_int_menu };
	debug_menu_entry savegame_opt_entry = { "Saved Game Settings", BOOLEAN_G, savegame_opt_menu };
	debug_menu_entry mission_entry = { "Missions", BOOLEAN_G, mission_menu };
	debug_menu_entry debug_render_select_entry = { "Debug Render", BOOLEAN_G, debug_render_menu };
	debug_menu_entry district_entry = { "District variants", BOOLEAN_G, district_variants_menu };
	debug_menu_entry replay_entry = { "Replay", BOOLEAN_G, replay_menu };
	debug_menu_entry ai_entry = { "AI", BOOLEAN_G, ai_menu };
	debug_menu_entry memory_entry = { "Memory", BOOLEAN_G, memory_menu };
	debug_menu_entry scriptmemtrack_entry = { "Script Memtrack", BOOLEAN_G, scriptmemtrack_menu };
	debug_menu_entry slabs_entry = { "Slabs", BOOLEAN_G, slabs_menu };
	debug_menu_entry entity_select_entry = { "Entity", BOOLEAN_G, entity_menu };
	debug_menu_entry level_select_entry = { "Level Select", BOOLEAN_G, level_select_menu };
	debug_menu_entry hero_entry = { "Hero Select", BOOLEAN_G, hero_menu };
	debug_menu_entry script_entry = { "Script", BOOLEAN_G, script_menu };
	debug_menu_entry progression_entry = { "Progression", BOOLEAN_G, progression_menu };
	debug_menu_entry streams_entry = { "Streams", BOOLEAN_G, streams_menu };




	add_debug_menu_entry(start_debug, &warp_entry);
	add_debug_menu_entry(start_debug, &game_entry);
	add_debug_menu_entry(game_menu, &devopt_flags_entry);
	add_debug_menu_entry(game_menu, &devopt_int_entry);
	add_debug_menu_entry(game_menu, &savegame_opt_entry);
	add_debug_menu_entry(game_menu, &game_flags_entry);
	add_debug_menu_entry(start_debug, &mission_entry);
	add_debug_menu_entry(start_debug, &debug_render_select_entry);
	add_debug_menu_entry(start_debug, &district_entry);
	add_debug_menu_entry(start_debug, &replay_entry);
	add_debug_menu_entry(start_debug, &ai_entry);
	add_debug_menu_entry(start_debug, &memory_entry);
	add_debug_menu_entry(memory_menu, &scriptmemtrack_entry);
	add_debug_menu_entry(memory_menu, &slabs_entry);
	add_debug_menu_entry(start_debug, &entity_select_entry);
	add_debug_menu_entry(start_debug, &level_select_entry);
	add_debug_menu_entry(level_select_menu, &hero_entry);
	add_debug_menu_entry(start_debug, &script_entry);
	add_debug_menu_entry(start_debug, &progression_entry);
	add_debug_menu_entry(start_debug, &streams_entry);







	debug_menu_entry start = { "Start", NORMAL, replay_menu };
	add_debug_menu_entry(replay_menu, &start);


	debug_menu_entry jf_entry = { "JF", BOOLEAN_G, jf };
	add_debug_menu_entry(mission_menu, &jf_entry);
	debug_menu_entry jg_entry = { "JG", BOOLEAN_G, jg };
	add_debug_menu_entry(mission_menu, &jg_entry);
	debug_menu_entry kf_entry = { "KF", BOOLEAN_G, kf };
	add_debug_menu_entry(mission_menu, &kf_entry);
	debug_menu_entry kg_entry = { "KG", BOOLEAN_G, kg };
	add_debug_menu_entry(mission_menu, &kg_entry);
	debug_menu_entry kh_entry = { "KH", BOOLEAN_G, kh };
	add_debug_menu_entry(mission_menu, &kh_entry);
	debug_menu_entry lf_entry = { "LF", BOOLEAN_G, lf };
	add_debug_menu_entry(mission_menu, &lf_entry);
	debug_menu_entry lg_entry = { "LG", BOOLEAN_G, lg };
	add_debug_menu_entry(mission_menu, &lg_entry);



	debug_menu_entry ai_1_entry = { "0x003ac42e", BOOLEAN_G, ai_0 };
	add_debug_menu_entry(ai_menu, &ai_1_entry);
	debug_menu_entry entity_1_entry = { "0x008230d88", BOOLEAN_G, entity_1 };
	add_debug_menu_entry(entity_menu, &entity_1_entry);
	debug_menu_entry entity_2_entry = { "0x008230d89", BOOLEAN_G, entity_2 };
	add_debug_menu_entry(entity_menu, &entity_2_entry);
	debug_menu_entry entity_3_entry = { "0x008230d8a", BOOLEAN_G, entity_3 };
	add_debug_menu_entry(entity_menu, &entity_3_entry);
	debug_menu_entry entity_4_entry = { "0x008230d8b", BOOLEAN_G, entity_4 };
	add_debug_menu_entry(entity_menu, &entity_4_entry);
	debug_menu_entry entity_5_entry = { "0x008230d8c", BOOLEAN_G, entity_5 };
	add_debug_menu_entry(entity_menu, &entity_5_entry);
	debug_menu_entry entity_6_entry = { "0x008230d8d", BOOLEAN_G, entity_6 };
	add_debug_menu_entry(entity_menu, &entity_6_entry);
	debug_menu_entry entity_7_entry = { "0x008230d8e", BOOLEAN_G, entity_7 };
	add_debug_menu_entry(entity_menu, &entity_7_entry);
	debug_menu_entry entity_8_entry = { "0x008230d8f", BOOLEAN_G, entity_8 };
	add_debug_menu_entry(entity_menu, &entity_8_entry);
	debug_menu_entry entity_9_entry = { "0x008230d90", BOOLEAN_G, entity_9 };
	add_debug_menu_entry(entity_menu, &entity_9_entry);
	debug_menu_entry entity_10_entry = { "0x008230d91", BOOLEAN_G, entity_10 };
	add_debug_menu_entry(entity_menu, &entity_10_entry);
	debug_menu_entry entity_11_entry = { "0x008230d92", BOOLEAN_G, entity_11 };
	add_debug_menu_entry(entity_menu, &entity_11_entry);
	debug_menu_entry codesize_entry = { "Code Size KB", BOOLEAN_I, memory_menu };
	add_debug_menu_entry(memory_menu, &codesize_entry);
	debug_menu_entry initdatasize_entry = { "Init Data Size KB", BOOLEAN_L, memory_menu };
	add_debug_menu_entry(memory_menu, &initdatasize_entry);
	debug_menu_entry uninitdatasize_entry = { "Uninit Data Size KB", BOOLEAN_M, memory_menu };
	add_debug_menu_entry(memory_menu, &uninitdatasize_entry);
	debug_menu_entry stacksize_entry = { "Stack Size KB", BOOLEAN_N, memory_menu };
	add_debug_menu_entry(memory_menu, &stacksize_entry);


	debug_menu_entry venom_ = { "venom", BOOLEAN_E, 0x984564, NULL };
	add_debug_menu_entry(hero_menu, &venom_);

	debug_menu_entry carnage = { "carnage", BOOLEAN_E, 0x984563, NULL };
	carnage.data1 = 1;
	add_debug_menu_entry(hero_menu, &carnage);

	debug_menu_entry ultimate_spiderman = { "ultimate_spiderman", BOOLEAN_E, 0x987A20, NULL };
	ultimate_spiderman.data1 = 1;
	add_debug_menu_entry(hero_menu, &ultimate_spiderman);

	debug_menu_entry venom_spider = { "venom_spider", BOOLEAN_E, 0x987980, NULL };
	venom_spider.data1 = 1;
	add_debug_menu_entry(hero_menu, &venom_spider);

	debug_menu_entry rhino = { "rhino", BOOLEAN_E, 0x9879D0, NULL };
	rhino.data1 = 1;
	add_debug_menu_entry(hero_menu, &rhino);

	debug_menu_entry electro_nosuit = { "electro_nosuit", BOOLEAN_E, 0x97DA0D, NULL };
	electro_nosuit.data1 = 1;
	add_debug_menu_entry(hero_menu, &electro_nosuit);

	debug_menu_entry electro_suit = { "electro_suit", BOOLEAN_E, 0x987A70, NULL };
	electro_suit.data1 = 1;
	add_debug_menu_entry(hero_menu, &electro_suit);

	debug_menu_entry carnage_01 = { "carnage_01", BOOLEAN_E, 0x984565, NULL };
	carnage_01.data1 = 1;
	add_debug_menu_entry(hero_menu, &carnage_01);

	debug_menu_entry wolverine = { "wolverine", BOOLEAN_E, 0x984BC0, NULL };
	wolverine.data1 = 1;
	add_debug_menu_entry(hero_menu, &wolverine);

	debug_menu_entry silver_sable = { "silver_sable", BOOLEAN_E, 0x97DA0C, NULL };
	silver_sable.data1 = 1;
	add_debug_menu_entry(hero_menu, &silver_sable);

	debug_menu_entry mary_jane = { "mary_jane", BOOLEAN_E, 0x97DA2B, NULL };
	mary_jane.data1 = 1;
	add_debug_menu_entry(hero_menu, &mary_jane);

	debug_menu_entry arachno_man_costume = { "arachno_man_costume", BOOLEAN_E, 0x97DA2A, NULL };
	arachno_man_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &arachno_man_costume);

	debug_menu_entry peter_hooded_costume = { "peter_hooded_costume", BOOLEAN_E, 0x97DA29, NULL };
	peter_hooded_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_hooded_costume);

	debug_menu_entry peter_parker_costume = { "peter_parker_costume", BOOLEAN_E, 0x97DA28, NULL};
	peter_parker_costume.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_parker_costume);

	debug_menu_entry peter_parker = { "peter_parker", BOOLEAN_E, 0x97DA33, NULL };
	peter_parker.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_parker);

	debug_menu_entry peter_hooded = { "peter_hooded", BOOLEAN_E, 0x97DA32, NULL };
	peter_hooded.data1 = 1;
	add_debug_menu_entry(hero_menu, &peter_hooded);

	debug_menu_entry green_goblin = { "green_goblin", BOOLEAN_E, 0x97DA31, NULL };
	green_goblin.data1 = 1;
	add_debug_menu_entry(hero_menu, &green_goblin);


	debug_menu_entry venom_spider_lite = { "venom_spider_lite", BOOLEAN_E, 0x982470, NULL };
	venom_spider_lite.data1 = 1;
	add_debug_menu_entry(hero_menu, &venom_spider_lite);

	debug_menu_entry city = { "city", NORMAL, level_select_menu };
	city.data1 = NULL;
	add_debug_menu_entry(level_select_menu, &city);

	debug_menu_entry reboot = { "-- REBOOT --", NORMAL, level_select_menu };
	add_debug_menu_entry(level_select_menu, &reboot);

	/*
	for (int i = 0; i < 5; i++) {
		debug_menu_entry asdf;
		sprintf(asdf.text, "entry %d", i);
		printf("AQUI %s\n", asdf.text);
		add_debug_menu_entry(start_debug, &asdf);
	}
	add_debug_menu_entry(start_debug, &teste);
	*/





}





	BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID reserverd) {
		



	if (sizeof(region) != 0x134) {
		__debugbreak();

	}

	memset(keys, 0, sizeof(keys));
	if (fdwReason == DLL_PROCESS_ATTACH) {
		FreeConsole();



		setup_debug_menu();
		set_text_writeable();
		set_rdata_writeable();
		install_patches();

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
		FreeConsole();

	return TRUE;
}



int main() {
	return 0;
}

