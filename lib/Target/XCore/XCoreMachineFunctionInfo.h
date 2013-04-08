begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreMachineFuctionInfo.h - XCore machine function info -*- C++ -*-===//
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
name|XCOREMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|XCOREMACHINEFUNCTIONINFO_H
end_define

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
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations
name|class
name|Function
decl_stmt|;
comment|/// XCoreFunctionInfo - This class is derived from MachineFunction private
comment|/// XCore target-specific information for each MachineFunction.
name|class
name|XCoreFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|UsesLR
block|;
name|int
name|LRSpillSlot
block|;
name|int
name|FPSpillSlot
block|;
name|int
name|VarArgsFrameIndex
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
block|,
name|CalleeSavedInfo
operator|>
expr|>
name|SpillLabels
block|;
name|public
operator|:
name|XCoreFunctionInfo
argument_list|()
operator|:
name|UsesLR
argument_list|(
name|false
argument_list|)
block|,
name|LRSpillSlot
argument_list|(
literal|0
argument_list|)
block|,
name|FPSpillSlot
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
name|XCoreFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|UsesLR
argument_list|(
name|false
argument_list|)
block|,
name|LRSpillSlot
argument_list|(
literal|0
argument_list|)
block|,
name|FPSpillSlot
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|XCoreFunctionInfo
argument_list|()
block|{}
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
name|void
name|setUsesLR
argument_list|(
argument|bool val
argument_list|)
block|{
name|UsesLR
operator|=
name|val
block|; }
name|bool
name|getUsesLR
argument_list|()
specifier|const
block|{
return|return
name|UsesLR
return|;
block|}
name|void
name|setLRSpillSlot
argument_list|(
argument|int off
argument_list|)
block|{
name|LRSpillSlot
operator|=
name|off
block|; }
name|int
name|getLRSpillSlot
argument_list|()
specifier|const
block|{
return|return
name|LRSpillSlot
return|;
block|}
name|void
name|setFPSpillSlot
argument_list|(
argument|int off
argument_list|)
block|{
name|FPSpillSlot
operator|=
name|off
block|; }
name|int
name|getFPSpillSlot
argument_list|()
specifier|const
block|{
return|return
name|FPSpillSlot
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
block|,
name|CalleeSavedInfo
operator|>
expr|>
operator|&
name|getSpillLabels
argument_list|()
block|{
return|return
name|SpillLabels
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// XCOREMACHINEFUNCTIONINFO_H
end_comment

end_unit

