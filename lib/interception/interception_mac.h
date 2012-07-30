begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- interception_mac.h --------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Mac-specific interception methods.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INCLUDED_FROM_INTERCEPTION_LIB
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"interception_mac.h should be included from interception.h only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INTERCEPTION_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|INTERCEPTION_MAC_H
end_define

begin_include
include|#
directive|include
file|<mach/mach_error.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// Allocate memory for the escape island. This cannot be moved to
end_comment

begin_comment
comment|// mach_override, because each user of interceptors may specify its
end_comment

begin_comment
comment|// own memory range for escape islands.
end_comment

begin_extern
extern|extern
literal|"C"
block|{
name|mach_error_t
name|__interception_allocate_island
parameter_list|(
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|size_t
name|unused_size
parameter_list|,
name|void
modifier|*
name|unused_hint
parameter_list|)
function_decl|;
name|mach_error_t
name|__interception_deallocate_island
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|namespace
name|__interception
block|{
comment|// returns true if the old function existed.
name|bool
name|OverrideFunction
parameter_list|(
name|void
modifier|*
name|old_func
parameter_list|,
name|void
modifier|*
name|new_func
parameter_list|,
name|void
modifier|*
modifier|*
name|orig_old_func
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __interception
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_FUNCTION_MAC
parameter_list|(
name|old_func
parameter_list|,
name|new_func
parameter_list|)
define|\
value|::__interception::OverrideFunction((void*)old_func, (void*)new_func, \                                        (void**)&REAL(old_func))
end_define

begin_define
define|#
directive|define
name|INTERCEPT_FUNCTION_MAC
parameter_list|(
name|func
parameter_list|)
value|OVERRIDE_FUNCTION_MAC(func, WRAP(func))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// INTERCEPTION_MAC_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __APPLE__
end_comment

end_unit

