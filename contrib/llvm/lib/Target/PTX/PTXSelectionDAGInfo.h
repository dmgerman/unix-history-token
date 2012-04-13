begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PTXSelectionDAGInfo.h - PTX SelectionDAG Info -----------*- C++ -*-===//
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
comment|// This file defines the PTX subclass for TargetSelectionDAGInfo.
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
name|PTXSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|PTXSELECTIONDAGINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetSelectionDAGInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PTXSelectionDAGInfo - TargetSelectionDAGInfo sub-class for the PTX target.
comment|/// At the moment, this is mostly just a copy of ARMSelectionDAGInfo.
name|class
name|PTXSelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
comment|/// Subtarget - Keep a pointer to the PTXSubtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|PTXSubtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|PTXSelectionDAGInfo
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|PTXSelectionDAGInfo
argument_list|()
block|;
name|virtual
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dst
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool isVolatile
argument_list|,
argument|bool AlwaysInline
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|EmitTargetCodeForMemset
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Op1
argument_list|,
argument|SDValue Op2
argument_list|,
argument|SDValue Op3
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool isVolatile
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

