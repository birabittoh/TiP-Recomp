// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/retip_config.h"
#include "generated/retip_init.h"
#include "tip_engine/Types/CursorInstance.h"

#include "tip_engine/rex_macros.h"
#include <cstdint>
#include <type_traits>
#include "tip_engine/Log.h"

#include <rex/ppc/types.h>
#include "retip_app.h"
#include <rex/logging.h>
#include <iostream>

namespace renut::log {
  inline const rex::LogCategoryId Input = rex::RegisterLogCategory("retip");
}

#define RENUT_TRACE(...) REXLOG_CAT_TRACE(::renut::log::Input, __VA_ARGS__)
#define RENUT_DEBUG(...) REXLOG_CAT_DEBUG(::renut::log::Input, __VA_ARGS__)
#define RENUT_INFO(...)  REXLOG_CAT_INFO(::renut::log::Input, __VA_ARGS__)
#define RENUT_WARN(...)  REXLOG_CAT_WARN(::renut::log::Input, __VA_ARGS__)
#define RENUT_ERROR(...) REXLOG_CAT_ERROR(::renut::log::Input, __VA_ARGS__)

REX_DEFINE_APP(retip, RetipApp::Create)

REX_PPC_EXTERN_IMPORT(cursorMainGetCursor_822CC598);

cursorInst_s* cursorMainGetCursor_822CC598_Hook(uint32_t a1, char a2){
  cursorInst_s* result = REX_PPC_INVOKE2(cursorInst_s*, cursorMainGetCursor_822CC598, a1, a2);
  
  return result;
}

REX_PPC_HOOK(cursorMainGetCursor_822CC598);