begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------------------- Unwind-EHABI.hpp ---------------------------===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UNWIND_EHABI_H__
end_ifndef

begin_define
define|#
directive|define
name|__UNWIND_EHABI_H__
end_define

begin_include
include|#
directive|include
file|<__libunwind_config.h>
end_include

begin_if
if|#
directive|if
name|_LIBUNWIND_ARM_EHABI
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<unwind.h>
end_include

begin_comment
comment|// Unable to unwind in the ARM index table (section 5 EHABI).
end_comment

begin_define
define|#
directive|define
name|UNW_EXIDX_CANTUNWIND
value|0x1
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|signExtendPrel31
parameter_list|(
name|uint32_t
name|data
parameter_list|)
block|{
return|return
name|data
operator||
operator|(
operator|(
name|data
operator|&
literal|0x40000000u
operator|)
operator|<<
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|readPrel31
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|data
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|uint32_t
operator|)
operator|(
name|uintptr_t
operator|)
name|data
operator|)
operator|+
name|signExtendPrel31
argument_list|(
operator|*
name|data
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|_Unwind_Reason_Code
name|__aeabi_unwind_cpp_pr0
parameter_list|(
name|_Unwind_State
name|state
parameter_list|,
name|_Unwind_Control_Block
modifier|*
name|ucbp
parameter_list|,
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
function_decl|;
specifier|extern
name|_Unwind_Reason_Code
name|__aeabi_unwind_cpp_pr1
parameter_list|(
name|_Unwind_State
name|state
parameter_list|,
name|_Unwind_Control_Block
modifier|*
name|ucbp
parameter_list|,
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
function_decl|;
specifier|extern
name|_Unwind_Reason_Code
name|__aeabi_unwind_cpp_pr2
parameter_list|(
name|_Unwind_State
name|state
parameter_list|,
name|_Unwind_Control_Block
modifier|*
name|ucbp
parameter_list|,
name|_Unwind_Context
modifier|*
name|context
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBUNWIND_ARM_EHABI
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __UNWIND_EHABI_H__
end_comment

end_unit

