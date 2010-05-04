begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/Target/TargetSelectionDAGInfo.h - SelectionDAG Info --*- C++ -*-==//
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
comment|// This file declares the TargetSelectionDAGInfo class, which targets can
end_comment

begin_comment
comment|// subclass to parameterize the SelectionDAG lowering and instruction
end_comment

begin_comment
comment|// selection process.
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
name|LLVM_TARGET_TARGETSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETSELECTIONDAGINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|/// TargetSelectionDAGLowering - Targets can subclass this to parameterize the
comment|/// SelectionDAG lowering and instruction selection process.
comment|///
name|class
name|TargetSelectionDAGInfo
block|{
name|TargetSelectionDAGInfo
argument_list|(
specifier|const
name|TargetSelectionDAGInfo
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetSelectionDAGInfo
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|TargetSelectionDAGInfo
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|TargetSelectionDAGInfo
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

