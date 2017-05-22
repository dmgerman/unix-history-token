begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_flags.h ---------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer/AddressSanitizer runtime.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_FLAGS_H
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
enum|enum
name|HandleSignalMode
block|{
name|kHandleSignalNo
block|,
name|kHandleSignalYes
block|, }
enum|;
struct|struct
name|CommonFlags
block|{
define|#
directive|define
name|COMMON_FLAG
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
file|"sanitizer_flags.inc"
undef|#
directive|undef
name|COMMON_FLAG
name|void
name|SetDefaults
parameter_list|()
function_decl|;
name|void
name|CopyFrom
parameter_list|(
specifier|const
name|CommonFlags
modifier|&
name|other
parameter_list|)
function_decl|;
block|}
struct|;
comment|// Functions to get/set global CommonFlags shared by all sanitizer runtimes:
specifier|extern
name|CommonFlags
name|common_flags_dont_use
decl_stmt|;
specifier|inline
specifier|const
name|CommonFlags
modifier|*
name|common_flags
parameter_list|()
block|{
return|return
operator|&
name|common_flags_dont_use
return|;
block|}
specifier|inline
name|void
name|SetCommonFlagsDefaults
parameter_list|()
block|{
name|common_flags_dont_use
operator|.
name|SetDefaults
argument_list|()
expr_stmt|;
block|}
comment|// This function can only be used to setup tool-specific overrides for
comment|// CommonFlags defaults. Generally, it should only be used right after
comment|// SetCommonFlagsDefaults(), but before ParseCommonFlagsFromString(), and
comment|// only during the flags initialization (i.e. before they are used for
comment|// the first time).
specifier|inline
name|void
name|OverrideCommonFlags
parameter_list|(
specifier|const
name|CommonFlags
modifier|&
name|cf
parameter_list|)
block|{
name|common_flags_dont_use
operator|.
name|CopyFrom
argument_list|(
name|cf
argument_list|)
expr_stmt|;
block|}
name|void
name|SubstituteForFlagValue
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|out
parameter_list|,
name|uptr
name|out_size
parameter_list|)
function_decl|;
name|class
name|FlagParser
decl_stmt|;
name|void
name|RegisterCommonFlags
parameter_list|(
name|FlagParser
modifier|*
name|parser
parameter_list|,
name|CommonFlags
modifier|*
name|cf
init|=
operator|&
name|common_flags_dont_use
parameter_list|)
function_decl|;
name|void
name|RegisterIncludeFlags
parameter_list|(
name|FlagParser
modifier|*
name|parser
parameter_list|,
name|CommonFlags
modifier|*
name|cf
parameter_list|)
function_decl|;
comment|// Should be called after parsing all flags. Sets up common flag values
comment|// and perform initializations common to all sanitizers (e.g. setting
comment|// verbosity).
name|void
name|InitializeCommonFlags
parameter_list|(
name|CommonFlags
modifier|*
name|cf
init|=
operator|&
name|common_flags_dont_use
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_FLAGS_H
end_comment

end_unit

