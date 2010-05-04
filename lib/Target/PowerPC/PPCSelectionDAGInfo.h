begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCSelectionDAGInfo.h - PowerPC SelectionDAG Info -------*- C++ -*-===//
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
comment|// This file defines the PowerPC subclass for TargetSelectionDAGInfo.
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
name|POWERPCCSELECTIONDAGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPCCSELECTIONDAGINFO_H
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
name|PPCSelectionDAGInfo
range|:
name|public
name|TargetSelectionDAGInfo
block|{
name|public
operator|:
name|PPCSelectionDAGInfo
argument_list|()
block|;
operator|~
name|PPCSelectionDAGInfo
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

