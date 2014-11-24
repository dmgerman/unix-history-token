begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreSelectionDAGInfo.h - XCore SelectionDAG Info -------*- C++ -*-===//
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
comment|// This file defines the XCore subclass for TargetSelectionDAGInfo.
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
name|XCORESELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|XCORESELECTIONDAGINFO_H
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
name|XCoreTargetMachine
decl_stmt|;
name|class
name|XCoreSelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
name|public
operator|:
name|explicit
name|XCoreSelectionDAGInfo
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
block|;
operator|~
name|XCoreSelectionDAGInfo
argument_list|()
block|;
name|SDValue
name|EmitTargetCodeForMemcpy
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDLoc dl
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
argument|bool AlwaysInline
argument_list|,
argument|MachinePointerInfo DstPtrInfo
argument_list|,
argument|MachinePointerInfo SrcPtrInfo
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

