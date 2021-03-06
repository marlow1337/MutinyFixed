#pragma once
#ifndef ERROR_CODES_H
#define ERROR_CODES_H

//#include "cx_strenc.h"

#define ERR_TITLE ("OLLIB")
#define ERR_CANT_OPEN_LICENSE ("Error Code 1")
#define ERR_CANT_CREATE_LICENSE ("Error Code 2")
#define ERR_INVALID_LICENSE ("Error Code 3")
#define ERR_NO_DEBUGGERS_ALLOWED ("Error Code 4")
#define ERR_NO_CONNECTION ("Error Code 5")
#define ERR_BAD_LICENSE_DATE ("Error Code 6")
#define ERR_INVALID_MOVEHELPER_POINTER ("Error Code 7")
#define ERR_CANT_FIND_MOVEHELPER_SIGNATURE ("Error Code 8")
#define ERR_CANT_FIND_TRACETOEXIT_SIGNATURE ("Error Code 9")
#define ERR_CANT_FIND_UTIL_CLIPTRACETOPLAYERS_SIGNATURE ("Error Code 10")
#define ERR_PREDICTION_CRASHED ("Error Code 11")
#define ERR_CANT_FIND_HELPER_GETLASTMATCHID ("Error Code 12")
#define ERR_CANT_FIND_BULLETPENETRATION_SIGNATURE ("Error Code 13")
#define ERR_CANT_FIND_SETCLANTAG_SIGNATURE ("Error Code 14")
#define ERR_CANT_FIND_M_PITCH_M_YAW_SENSITIVITY ("Error Code 15")
#define ERR_INVALID_VIEWANGLES ("Error Code 16")
#define ERR_CANT_FIND_CLIENT_STATE ("Error Code 17")
#define ERR_CANT_FIND_IS_PAUSED_SIGNATURE ("Error Code 18")
#define ERR_CANT_FIND_HOST_TICKCOUNT_SIGNATURE ("Error Code 19")
#define ERR_CANT_FIND_PREDICTION_RANDOMSEED_SIGNATURE ("Error Code 20")
#define ERR_CANT_FIND_RANDOMFLOAT ("Error Code 21")
#define ERR_CANT_FIND_RANDOMSEED ("Error Code 22")
#define ERR_CANT_FIND_GAMERULES_SIGNATURE ("Error Code 23")
#define ERR_CANT_FIND_PSEUDORANDOM_SIGNATURE ("Error Code 24")
#define ERR_CANT_FIND_INTERPOLATE_SIGNATURE ("Error Code 25")
#define ERR_CANT_FIND_INTERPOLATE_FSN_SIGNATURE ("Error Code 26")
#define ERR_CANT_FIND_SBINTERPOLATE_SIGNATURE ("Error Code 27")
#define ERR_CANT_FIND_DIDCHECKFOROCCLUSION_SIGNATURE ("Error Code 28")
#define ERR_CANT_FIND_STANDARDFILTERRULES_SIGNATURE ("Error Code 29")
#define ERR_CANT_FIND_GETCOMPRANK_SIGNATURE ("Error Code 30")
#define ERR_CANT_FIND_SETABSORIGIN_SIGNATURE ("Error Code 31")
#define ERR_CANT_FIND_SETABSANGLES_SIGNATURE ("Error Code 32")
#define ERR_CANT_FIND_SETABSVELOCITY_SIGNATURE ("Error Code 33")
#define ERR_CANT_FIND_LOOKUPPOSEPARAMETER_SIGNATURE ("Error Code 34")
#define ERR_CANT_FIND_GETPOSEPARAMETERRANGE_SIGNATURE ("Error Code 35")
#define ERR_CANT_FIND_SETPOSEPARAMETER_SIGNATURE ("Error Code 36")
#define ERR_CANT_FIND_OVERRIDEPOSTPROCESSING_SIGNATURE ("Error Code 37")
#define ERR_CANT_FIND_VIEWRENDER_SIGNATURE ("Error Code 38")
#define ERR_UNTRUSTED_LICENSE ("Error Code 39")
#define ERR_CANT_FIND_DIRECTX_TABLE ("Error Code 40")
#define ERR_CANT_FIND_DATACACHE_SETPOSEPARAM_SIG ("Error Code 41")
#define ERR_CANT_FIND_UPDATECLIENTSIDEANIMATION_SIG ("Error Code 42")
#define ERR_CANT_FIND_INVALIDATEPHYSICSRECURSIVE_SIG ("Error Code 43")
#define ERR_CANT_FIND_STANDARDFILTERRULES_SIGNATURE2 ("Error Code 44")
#define ERR_CANT_FIND_FREEENTITYBASELINES_SIGNATURE ("Error Code 45")
#define ERR_CANT_FIND_FRAMETIME_SIGNATURE ("Error Code 46")
#define ERR_CANT_FIND_VIEWMATRIX_SIGNATURE ("Error Code 47")
#define ERR_OUTDATED_CSGO_VERSION ("Error Code 48")
#define ERR_CANT_FIND_CLIENTLIST_SIGNATURE ("Error Code 49")
#define ERR_CANT_FIND_GOTV_SIGNATURE ("Error Code 50")
#define ERR_CANT_FIND_CLIENT_SIDE_ANIMATION_LIST_SIGNATURE ("Error Code 51")
#define ERR_CANT_FIND_ENABLE_INVALIDATE_BONE_CACHE_SIGNATURE ("Error Code 52")
#define ERR_CANT_FIND_GLOW_OBJECT_MANAGER_SIGNATURE ("Error Code 53")
#define ERR_CANT_FIND_RADAR_BASE_SIG ("Error Code 54")
#define ERR_CANT_FIND_IS_ENTITY_BREAKABLE_SIG1 ("Error Code 55")
#define ERR_CANT_FIND_IS_ENTITY_BREAKABLE_SIG2 ("Error Code 56")
#define ERR_CANT_FIND_IS_ENTITY_BREAKABLE_SIG3 ("Error Code 57")
#define ERR_CANT_FIND_DEMOPLAYER_CREATEMOVE_SIG ("Error Code 58")
#define ERR_CANT_FIND_ISREADY_SIG ("Error Code 59")
#define ERR_CANT_FIND_PREDICTION_PLAYER_SIG ("Error Code 60")

#ifndef MUTINY
inline __declspec(noinline) void THROW_ERROR(const char* errorcode)
{
	MessageBox(NULL, errorcode, ERR_TITLE, MB_OK);
}
#else
#ifdef NO_MUTINY_HEARTBEAT
inline __declspec(noinline) void THROW_ERROR(const char* errorcode)
{
	MessageBox(NULL, errorcode, ERR_TITLE, MB_OK);
}
#else
//#include "C:\ClientFramework\\Framework\Logging\Logging.h"
//#include "VMProtectDefs.h"
void THROW_ERROR(const char* str);
#define LOG_MESSAGE(a) THROW_ERROR(a)
//#define THROW_ERROR(str) //VMP_ENCDECSTRINGA(str)
#endif
#endif
#endif
