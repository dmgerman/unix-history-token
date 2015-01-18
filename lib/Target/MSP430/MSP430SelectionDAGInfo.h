begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MSP430SelectionDAGInfo.h - MSP430 SelectionDAG Info -----*- C++ -*-===//
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
comment|// This file defines the MSP430 subclass for TargetSelectionDAGInfo.
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
name|LLVM_LIB_TARGET_MSP430_MSP430SELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MSP430_MSP430SELECTIONDAGINFO_H
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
name|MSP430TargetMachine
decl_stmt|;
name|class
name|MSP430SelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
name|public
operator|:
name|explicit
name|MSP430SelectionDAGInfo
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
block|;
operator|~
name|MSP430SelectionDAGInfo
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

