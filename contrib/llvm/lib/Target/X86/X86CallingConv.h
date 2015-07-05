begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== X86CallingConv.h - X86 Custom Calling Convention Routines -*- C++ -*-===//
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
comment|// This file contains the custom routines for the X86 Calling Convention that
end_comment

begin_comment
comment|// aren't done by tablegen.
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
name|LLVM_LIB_TARGET_X86_X86CALLINGCONV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86CALLINGCONV_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|inline
name|bool
name|CC_X86_32_VectorCallIndirect
argument_list|(
name|unsigned
operator|&
name|ValNo
argument_list|,
name|MVT
operator|&
name|ValVT
argument_list|,
name|MVT
operator|&
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
name|ArgFlags
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
block|{
comment|// Similar to CCPassIndirect, with the addition of inreg.
name|LocVT
operator|=
name|MVT
operator|::
name|i32
expr_stmt|;
name|LocInfo
operator|=
name|CCValAssign
operator|::
name|Indirect
expr_stmt|;
name|ArgFlags
operator|.
name|setInReg
argument_list|()
expr_stmt|;
return|return
name|false
return|;
comment|// Continue the search, but now for i32.
block|}
specifier|inline
name|bool
name|CC_X86_AnyReg_Error
argument_list|(
name|unsigned
operator|&
argument_list|,
name|MVT
operator|&
argument_list|,
name|MVT
operator|&
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
argument_list|,
name|CCState
operator|&
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"The AnyReg calling convention is only supported by the "
expr|\
literal|"stackmap and patchpoint intrinsics."
argument_list|)
expr_stmt|;
comment|// gracefully fallback to X86 C calling convention on Release builds.
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

