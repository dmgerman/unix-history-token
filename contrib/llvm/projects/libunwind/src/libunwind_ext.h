begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------------ libunwind_ext.h -----------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Extensions to libunwind API.
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
name|__LIBUNWIND_EXT__
end_ifndef

begin_define
define|#
directive|define
name|__LIBUNWIND_EXT__
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<libunwind.h>
end_include

begin_include
include|#
directive|include
file|<unwind.h>
end_include

begin_define
define|#
directive|define
name|UNW_STEP_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|UNW_STEP_END
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// SPI
specifier|extern
name|void
name|unw_iterate_dwarf_unwind_cache
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|unw_word_t
name|ip_start
parameter_list|,
name|unw_word_t
name|ip_end
parameter_list|,
name|unw_word_t
name|fde
parameter_list|,
name|unw_word_t
name|mh
parameter_list|)
parameter_list|)
function_decl|;
comment|// IPI
specifier|extern
name|void
name|_unw_add_dynamic_fde
parameter_list|(
name|unw_word_t
name|fde
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_unw_remove_dynamic_fde
parameter_list|(
name|unw_word_t
name|fde
parameter_list|)
function_decl|;
if|#
directive|if
name|_LIBUNWIND_ARM_EHABI
specifier|extern
specifier|const
name|uint32_t
modifier|*
name|decode_eht_entry
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|_Unwind_Reason_Code
name|_Unwind_VRS_Interpret
parameter_list|(
name|_Unwind_Context
modifier|*
name|context
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|data
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __LIBUNWIND_EXT__
end_comment

end_unit

