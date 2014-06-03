begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZSelectionDAGInfo.h - SystemZ SelectionDAG Info ---*- C++ -*-===//
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
comment|// This file defines the SystemZ subclass for TargetSelectionDAGInfo.
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
name|SYSTEMZSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZSELECTIONDAGINFO_H
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
name|class
name|SystemZTargetMachine
decl_stmt|;
name|class
name|SystemZSelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
name|public
operator|:
name|explicit
name|SystemZSelectionDAGInfo
argument_list|(
specifier|const
name|SystemZTargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|SystemZSelectionDAGInfo
argument_list|()
block|;
name|virtual
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
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
argument|bool IsVolatile
argument_list|,
argument|bool AlwaysInline
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|SDValue
name|EmitTargetCodeForMemset
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dst
argument_list|,
argument|SDValue Byte
argument_list|,
argument|SDValue Size
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool IsVolatile
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForMemcmp
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src1
argument_list|,
argument|SDValue Src2
argument_list|,
argument|SDValue Size
argument_list|,
argument|MachinePointerInfo Op1PtrInfo
argument_list|,
argument|MachinePointerInfo Op2PtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForMemchr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue Char
argument_list|,
argument|SDValue Length
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForStrcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Dest
argument_list|,
argument|SDValue Src
argument_list|,
argument|MachinePointerInfo DestPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|,
argument|bool isStpcpy
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForStrcmp
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src1
argument_list|,
argument|SDValue Src2
argument_list|,
argument|MachinePointerInfo Op1PtrInfo
argument_list|,
argument|MachinePointerInfo Op2PtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForStrlen
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|;
name|virtual
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|EmitTargetCodeForStrnlen
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Src
argument_list|,
argument|SDValue MaxLength
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

