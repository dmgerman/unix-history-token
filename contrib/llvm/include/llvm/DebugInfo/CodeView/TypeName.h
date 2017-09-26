begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeName.h --------------------------------------------- *- C++ --*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_CODEVIEW_TYPENAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPENAME_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeCollection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|std
operator|::
name|string
name|computeTypeName
argument_list|(
argument|TypeCollection&Types
argument_list|,
argument|TypeIndex Index
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

