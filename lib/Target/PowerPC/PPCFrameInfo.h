begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCFrameInfo.h - Define TargetFrameInfo for PowerPC -----*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POWERPC_FRAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC_FRAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCFrameInfo
range|:
name|public
name|TargetFrameInfo
block|{
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
name|public
operator|:
name|PPCFrameInfo
argument_list|(
argument|const TargetMachine&tm
argument_list|,
argument|bool LP64
argument_list|)
operator|:
name|TargetFrameInfo
argument_list|(
name|TargetFrameInfo
operator|::
name|StackGrowsDown
argument_list|,
literal|16
argument_list|,
literal|0
argument_list|)
block|,
name|TM
argument_list|(
argument|tm
argument_list|)
block|{   }
comment|/// getReturnSaveOffset - Return the previous frame offset to save the
comment|/// return address.
specifier|static
name|unsigned
name|getReturnSaveOffset
argument_list|(
argument|bool LP64
argument_list|,
argument|bool isMacho
argument_list|)
block|{
if|if
condition|(
name|isMacho
condition|)
return|return
name|LP64
operator|?
literal|16
operator|:
literal|8
return|;
comment|// For ELF 32 ABI:
return|return
literal|4
return|;
block|}
comment|/// getFramePointerSaveOffset - Return the previous frame offset to save the
comment|/// frame pointer.
specifier|static
name|unsigned
name|getFramePointerSaveOffset
parameter_list|(
name|bool
name|LP64
parameter_list|,
name|bool
name|isMacho
parameter_list|)
block|{
comment|// For MachO ABI:
comment|// Use the TOC save slot in the PowerPC linkage area for saving the frame
comment|// pointer (if needed.)  LLVM does not generate code that uses the TOC (R2
comment|// is treated as a caller saved register.)
if|if
condition|(
name|isMacho
condition|)
return|return
name|LP64
condition|?
literal|40
else|:
literal|20
return|;
comment|// For ELF 32 ABI:
comment|// Save it right before the link register
return|return
operator|-
literal|4U
return|;
block|}
comment|/// getLinkageSize - Return the size of the PowerPC ABI linkage area.
comment|///
specifier|static
name|unsigned
name|getLinkageSize
parameter_list|(
name|bool
name|LP64
parameter_list|,
name|bool
name|isMacho
parameter_list|)
block|{
if|if
condition|(
name|isMacho
condition|)
return|return
literal|6
operator|*
operator|(
name|LP64
condition|?
literal|8
else|:
literal|4
operator|)
return|;
comment|// For ELF 32 ABI:
return|return
literal|8
return|;
block|}
comment|/// getMinCallArgumentsSize - Return the size of the minium PowerPC ABI
comment|/// argument area.
specifier|static
name|unsigned
name|getMinCallArgumentsSize
parameter_list|(
name|bool
name|LP64
parameter_list|,
name|bool
name|isMacho
parameter_list|)
block|{
comment|// For Macho ABI:
comment|// The prolog code of the callee may store up to 8 GPR argument registers to
comment|// the stack, allowing va_start to index over them in memory if its varargs.
comment|// Because we cannot tell if this is needed on the caller side, we have to
comment|// conservatively assume that it is needed.  As such, make sure we have at
comment|// least enough stack space for the caller to store the 8 GPRs.
if|if
condition|(
name|isMacho
condition|)
return|return
literal|8
operator|*
operator|(
name|LP64
condition|?
literal|8
else|:
literal|4
operator|)
return|;
comment|// For ELF 32 ABI:
comment|// There is no default stack allocated for the 8 first GPR arguments.
return|return
literal|0
return|;
block|}
comment|/// getMinCallFrameSize - Return the minimum size a call frame can be using
comment|/// the PowerPC ABI.
specifier|static
name|unsigned
name|getMinCallFrameSize
parameter_list|(
name|bool
name|LP64
parameter_list|,
name|bool
name|isMacho
parameter_list|)
block|{
comment|// The call frame needs to be at least big enough for linkage and 8 args.
return|return
name|getLinkageSize
argument_list|(
name|LP64
argument_list|,
name|isMacho
argument_list|)
operator|+
name|getMinCallArgumentsSize
argument_list|(
name|LP64
argument_list|,
name|isMacho
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

