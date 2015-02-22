begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_flags.h -------------------------------------------*- C++ -*-===//
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
comment|// ASan runtime flags.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_flag_parser.h"
end_include

begin_comment
comment|// ASan flag values can be defined in four ways:
end_comment

begin_comment
comment|// 1) initialized with default values at startup.
end_comment

begin_comment
comment|// 2) overriden during compilation of ASan runtime by providing
end_comment

begin_comment
comment|//    compile definition ASAN_DEFAULT_OPTIONS.
end_comment

begin_comment
comment|// 3) overriden from string returned by user-specified function
end_comment

begin_comment
comment|//    __asan_default_options().
end_comment

begin_comment
comment|// 4) overriden from env variable ASAN_OPTIONS.
end_comment

begin_comment
comment|// 5) overriden during ASan activation (for now used on Android only).
end_comment

begin_decl_stmt
name|namespace
name|__asan
block|{
struct|struct
name|Flags
block|{
define|#
directive|define
name|ASAN_FLAG
parameter_list|(
name|Type
parameter_list|,
name|Name
parameter_list|,
name|DefaultValue
parameter_list|,
name|Description
parameter_list|)
value|Type Name;
include|#
directive|include
file|"asan_flags.inc"
undef|#
directive|undef
name|ASAN_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
block|}
struct|;
specifier|extern
name|Flags
name|asan_flags_dont_use_directly
decl_stmt|;
specifier|inline
name|Flags
modifier|*
name|flags
parameter_list|()
block|{
return|return
operator|&
name|asan_flags_dont_use_directly
return|;
block|}
name|void
name|InitializeFlags
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __asan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_FLAGS_H
end_comment

end_unit

