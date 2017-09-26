begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeCollection.h - A collection of CodeView type records -*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPECOLLECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPECOLLECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeCollection
block|{
name|public
label|:
name|virtual
operator|~
name|TypeCollection
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|empty
parameter_list|()
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
name|virtual
name|Optional
operator|<
name|TypeIndex
operator|>
name|getFirst
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|Optional
operator|<
name|TypeIndex
operator|>
name|getNext
argument_list|(
argument|TypeIndex Prev
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|CVType
name|getType
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getTypeName
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|contains
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|uint32_t
name|size
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|uint32_t
name|capacity
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

