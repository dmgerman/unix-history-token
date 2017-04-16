begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_win_weak_interception.h ---------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// This header provide helper macros to delegate calls of weak functions to the
end_comment

begin_comment
comment|// implementation in the main executable when a strong definition is present.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_WIN_WEAK_INTERCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_WIN_WEAK_INTERCEPTION_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|int
name|interceptWhenPossible
parameter_list|(
name|uptr
name|dll_function
parameter_list|,
specifier|const
name|char
modifier|*
name|real_function
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// ----------------- Function interception helper macros -------------------- //
end_comment

begin_comment
comment|// Weak functions, could be redefined in the main executable, but that is not
end_comment

begin_comment
comment|// necessary, so we shouldn't die if we can not find a reference.
end_comment

begin_define
define|#
directive|define
name|INTERCEPT_WEAK
parameter_list|(
name|Name
parameter_list|)
value|interceptWhenPossible((uptr) Name, #Name);
end_define

begin_define
define|#
directive|define
name|INTERCEPT_SANITIZER_WEAK_FUNCTION
parameter_list|(
name|Name
parameter_list|)
define|\
value|static int intercept_##Name() {                                              \     return __sanitizer::interceptWhenPossible((__sanitizer::uptr) Name, #Name);\   }                                                                            \   __pragma(section(".WEAK$M", long, read))                                     \   __declspec(allocate(".WEAK$M")) int (*__weak_intercept_##Name)() =           \       intercept_##Name;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_WIN_WEAK_INTERCEPTION_H
end_comment

end_unit

