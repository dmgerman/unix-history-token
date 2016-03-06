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
file|"MCTargetDesc/X86MCTargetDesc.h"
end_include

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
specifier|inline
name|bool
name|CC_X86_32_MCUInReg
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
comment|// This is similar to CCAssignToReg<[EAX, EDX, ECX]>, but makes sure
comment|// not to split i64 and double between a register and stack
specifier|static
specifier|const
name|MCPhysReg
name|RegList
index|[]
init|=
block|{
name|X86
operator|::
name|EAX
block|,
name|X86
operator|::
name|EDX
block|,
name|X86
operator|::
name|ECX
block|}
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|NumRegs
init|=
sizeof|sizeof
argument_list|(
name|RegList
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|RegList
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
name|SmallVectorImpl
operator|<
name|CCValAssign
operator|>
operator|&
name|PendingMembers
operator|=
name|State
operator|.
name|getPendingLocs
argument_list|()
expr_stmt|;
comment|// If this is the first part of an double/i64/i128, or if we're already
comment|// in the middle of a split, add to the pending list. If this is not
comment|// the end of the split, return, otherwise go on to process the pending
comment|// list
if|if
condition|(
name|ArgFlags
operator|.
name|isSplit
argument_list|()
operator|||
operator|!
name|PendingMembers
operator|.
name|empty
argument_list|()
condition|)
block|{
name|PendingMembers
operator|.
name|push_back
argument_list|(
name|CCValAssign
operator|::
name|getPending
argument_list|(
name|ValNo
argument_list|,
name|ValVT
argument_list|,
name|LocVT
argument_list|,
name|LocInfo
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ArgFlags
operator|.
name|isSplitEnd
argument_list|()
condition|)
return|return
name|true
return|;
block|}
comment|// If there are no pending members, we are not in the middle of a split,
comment|// so do the usual inreg stuff.
if|if
condition|(
name|PendingMembers
operator|.
name|empty
argument_list|()
condition|)
block|{
if|if
condition|(
name|unsigned
name|Reg
init|=
name|State
operator|.
name|AllocateReg
argument_list|(
name|RegList
argument_list|)
condition|)
block|{
name|State
operator|.
name|addLoc
argument_list|(
name|CCValAssign
operator|::
name|getReg
argument_list|(
name|ValNo
argument_list|,
name|ValVT
argument_list|,
name|Reg
argument_list|,
name|LocVT
argument_list|,
name|LocInfo
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|assert
argument_list|(
name|ArgFlags
operator|.
name|isSplitEnd
argument_list|()
argument_list|)
expr_stmt|;
comment|// We now have the entire original argument in PendingMembers, so decide
comment|// whether to use registers or the stack.
comment|// Per the MCU ABI:
comment|// a) To use registers, we need to have enough of them free to contain
comment|// the entire argument.
comment|// b) We never want to use more than 2 registers for a single argument.
name|unsigned
name|FirstFree
init|=
name|State
operator|.
name|getFirstUnallocated
argument_list|(
name|RegList
argument_list|)
decl_stmt|;
name|bool
name|UseRegs
init|=
name|PendingMembers
operator|.
name|size
argument_list|()
operator|<=
name|std
operator|::
name|min
argument_list|(
literal|2U
argument_list|,
name|NumRegs
operator|-
name|FirstFree
argument_list|)
decl_stmt|;
for|for
control|(
name|auto
operator|&
name|It
operator|:
name|PendingMembers
control|)
block|{
if|if
condition|(
name|UseRegs
condition|)
name|It
operator|.
name|convertToReg
argument_list|(
name|State
operator|.
name|AllocateReg
argument_list|(
name|RegList
index|[
name|FirstFree
operator|++
index|]
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|It
operator|.
name|convertToMem
argument_list|(
name|State
operator|.
name|AllocateStack
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|State
operator|.
name|addLoc
argument_list|(
name|It
argument_list|)
expr_stmt|;
block|}
name|PendingMembers
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
name|true
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

