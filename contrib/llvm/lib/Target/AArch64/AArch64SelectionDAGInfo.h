begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64SelectionDAGInfo.h - AArch64 SelectionDAG Info ---*- C++ -*-===//
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
comment|// This file defines the AArch64 subclass for TargetSelectionDAGInfo.
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
name|LLVM_AARCH64SELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64SELECTIONDAGINFO_H
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
name|AArch64TargetMachine
decl_stmt|;
name|class
name|AArch64SelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
specifier|const
name|AArch64Subtarget
operator|*
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|AArch64SelectionDAGInfo
argument_list|(
specifier|const
name|AArch64TargetMachine
operator|&
name|TM
argument_list|)
block|;
operator|~
name|AArch64SelectionDAGInfo
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

