
#include "dll/conactiondatabase.h"
#include "dll/hooking_common.h"

extern CLog logger;

intptr_t base_conactiondatabase_performevent_ptr = 0x0;
intptr_t base_steam_conactiondatabase_performevent_ptr = 0x1401d0790;
intptr_t base_gog_conactiondatabase_performevent_ptr = 0x1401ceb00;

void(*conactiondatabase_performevent_trampoline)(void* ptr1, void* ptr2, void* ptr3, void* ptr4, void* ptr5);
__declspec(noinline) void conactiondatabase_performevent_payload(void* ptr1, void* ptr2, void* ptr3, void* ptr4, void* ptr5) {
	CLog& logger = *getLogger();
	logger << "COnActionDatabase::PerformEvent - ";
#if DBG_PTR == 1
	logger << "ptr1(" << ptr1 << ") ptr2(" << ptr2 << ") " << ") ptr3(" << ptr3 << ") " << ") ptr4(" << ptr4 << ") " << ") ptr5(" << ptr5 << ") ";
#endif

	std::string* strptr = (std::string*) ((intptr_t)ptr2+0x8);
	if (strptr != nullptr) {
#if DBG_PTR == 1
		logger << "strptr(" << (void*)strptr << ")";
#endif
		logger << " " << *strptr;
	}
	logger.endl();
	void(*func_ptr)(void* ptr1, void* ptr2, void* ptr3, void* ptr4, void* ptr5);
	PopAddress(uint64_t(&func_ptr));
	return func_ptr(ptr1, ptr2, ptr3, ptr4, ptr5);

}

void conactiondatabase_hook_init(enumPlatforms thisPlatform, intptr_t p_CApplication_Base, intptr_t base_augustus_ptr) {

	if (thisPlatform == STEAM) {
		base_conactiondatabase_performevent_ptr = base_steam_conactiondatabase_performevent_ptr;
	}
	else if (thisPlatform == GOG) {
		base_conactiondatabase_performevent_ptr = base_gog_conactiondatabase_performevent_ptr;
	}

	intptr_t this_conactiondatabase_performevent_ptr = (intptr_t)p_CApplication_Base + (base_conactiondatabase_performevent_ptr - base_augustus_ptr);
	conactiondatabase_performevent_trampoline = (void(*)(void* ptr1, void* ptr2, void* ptr3, void* ptr4, void* ptr5)) installHook((void*)this_conactiondatabase_performevent_ptr, &conactiondatabase_performevent_trampoline, conactiondatabase_performevent_payload);
}