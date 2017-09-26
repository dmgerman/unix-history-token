begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- XCoreMachineFunctionInfo.h - XCore machine function info -*- C++ -*-===//
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
comment|// This file declares XCore-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_XCORE_XCOREMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_XCORE_XCOREMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// XCoreFunctionInfo - This class is derived from MachineFunction private
comment|/// XCore target-specific information for each MachineFunction.
name|class
name|XCoreFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|bool
name|LRSpillSlotSet
operator|=
name|false
block|;
name|int
name|LRSpillSlot
block|;
name|bool
name|FPSpillSlotSet
operator|=
name|false
block|;
name|int
name|FPSpillSlot
block|;
name|bool
name|EHSpillSlotSet
operator|=
name|false
block|;
name|int
name|EHSpillSlot
index|[
literal|2
index|]
block|;
name|unsigned
name|ReturnStackOffset
block|;
name|bool
name|ReturnStackOffsetSet
operator|=
name|false
block|;
name|int
name|VarArgsFrameIndex
operator|=
literal|0
block|;
name|mutable
name|int
name|CachedEStackSize
operator|=
operator|-
literal|1
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineBasicBlock
operator|::
name|iterator
block|,
name|CalleeSavedInfo
operator|>>
name|SpillLabels
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|XCoreFunctionInfo
argument_list|()
operator|=
expr|default
block|;
name|explicit
name|XCoreFunctionInfo
argument_list|(
argument|MachineFunction&MF
argument_list|)
block|{}
operator|~
name|XCoreFunctionInfo
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int off
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|off
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
name|int
name|createLRSpillSlot
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|hasLRSpillSlot
argument_list|()
block|{
return|return
name|LRSpillSlotSet
return|;
block|}
name|int
name|getLRSpillSlot
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|LRSpillSlotSet
operator|&&
literal|"LR Spill slot not set"
argument_list|)
block|;
return|return
name|LRSpillSlot
return|;
block|}
name|int
name|createFPSpillSlot
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|hasFPSpillSlot
argument_list|()
block|{
return|return
name|FPSpillSlotSet
return|;
block|}
name|int
name|getFPSpillSlot
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FPSpillSlotSet
operator|&&
literal|"FP Spill slot not set"
argument_list|)
block|;
return|return
name|FPSpillSlot
return|;
block|}
specifier|const
name|int
operator|*
name|createEHSpillSlot
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|bool
name|hasEHSpillSlot
argument_list|()
block|{
return|return
name|EHSpillSlotSet
return|;
block|}
specifier|const
name|int
operator|*
name|getEHSpillSlot
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|EHSpillSlotSet
operator|&&
literal|"EH Spill slot not set"
argument_list|)
block|;
return|return
name|EHSpillSlot
return|;
block|}
name|void
name|setReturnStackOffset
argument_list|(
argument|unsigned value
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|ReturnStackOffsetSet
operator|&&
literal|"Return stack offset set twice"
argument_list|)
block|;
name|ReturnStackOffset
operator|=
name|value
block|;
name|ReturnStackOffsetSet
operator|=
name|true
block|;   }
name|unsigned
name|getReturnStackOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ReturnStackOffsetSet
operator|&&
literal|"Return stack offset not set"
argument_list|)
block|;
return|return
name|ReturnStackOffset
return|;
block|}
name|bool
name|isLargeFrame
argument_list|(
argument|const MachineFunction&MF
argument_list|)
specifier|const
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineBasicBlock
operator|::
name|iterator
block|,
name|CalleeSavedInfo
operator|>>
operator|&
name|getSpillLabels
argument_list|()
block|{
return|return
name|SpillLabels
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_XCORE_XCOREMACHINEFUNCTIONINFO_H
end_comment

end_unit

