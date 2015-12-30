begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRMachineFuctionInfo.h - AVR machine function info -----*- C++ -*-===//
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
comment|// This file declares AVR-specific per-machine-function information.
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
name|LLVM_AVR_MACHINE_FUNCTION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_MACHINE_FUNCTION_INFO_H
end_define

begin_include
include|#
directive|include
file|"AVRConfig.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/**  * Contains AVR-specific information for each MachineFunction.  */
name|class
name|AVRMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
comment|/// Indicates if a register has been spilled by the register
comment|/// allocator.
name|bool
name|HasSpills
block|;
comment|/// Indicates if there are any fixed size allocas present.
comment|/// Note that if there are only variable sized allocas this is set to false.
name|bool
name|HasAllocas
block|;
comment|/// Indicates if arguments passed using the stack are being
comment|/// used inside the function.
name|bool
name|HasStackArgs
block|;
comment|/// Size of the callee-saved register portion of the
comment|/// stack frame in bytes.
name|unsigned
name|CalleeSavedFrameSize
block|;
comment|/// FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
block|;
name|public
operator|:
name|AVRMachineFunctionInfo
argument_list|()
operator|:
name|HasSpills
argument_list|(
name|false
argument_list|)
block|,
name|HasAllocas
argument_list|(
name|false
argument_list|)
block|,
name|HasStackArgs
argument_list|(
name|false
argument_list|)
block|,
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AVRMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|HasSpills
argument_list|(
name|false
argument_list|)
block|,
name|HasAllocas
argument_list|(
name|false
argument_list|)
block|,
name|HasStackArgs
argument_list|(
name|false
argument_list|)
block|,
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|getHasSpills
argument_list|()
specifier|const
block|{
return|return
name|HasSpills
return|;
block|}
name|void
name|setHasSpills
argument_list|(
argument|bool B
argument_list|)
block|{
name|HasSpills
operator|=
name|B
block|; }
name|bool
name|getHasAllocas
argument_list|()
specifier|const
block|{
return|return
name|HasAllocas
return|;
block|}
name|void
name|setHasAllocas
argument_list|(
argument|bool B
argument_list|)
block|{
name|HasAllocas
operator|=
name|B
block|; }
name|bool
name|getHasStackArgs
argument_list|()
specifier|const
block|{
return|return
name|HasStackArgs
return|;
block|}
name|void
name|setHasStackArgs
argument_list|(
argument|bool B
argument_list|)
block|{
name|HasStackArgs
operator|=
name|B
block|; }
name|unsigned
name|getCalleeSavedFrameSize
argument_list|()
specifier|const
block|{
return|return
name|CalleeSavedFrameSize
return|;
block|}
name|void
name|setCalleeSavedFrameSize
argument_list|(
argument|unsigned Bytes
argument_list|)
block|{
name|CalleeSavedFrameSize
operator|=
name|Bytes
block|; }
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int Idx
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Idx
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_AVR_MACHINE_FUNCTION_INFO_H
end_comment

end_unit

