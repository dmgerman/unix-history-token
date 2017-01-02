begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBEnumChildren.h - base interface for child enumerator -*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBENUMCHILDREN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBENUMCHILDREN_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|template
operator|<
name|typename
name|ChildType
operator|>
name|class
name|IPDBEnumChildren
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|ChildType
operator|>
name|ChildTypePtr
expr_stmt|;
typedef|typedef
name|IPDBEnumChildren
operator|<
name|ChildType
operator|>
name|MyType
expr_stmt|;
name|virtual
operator|~
name|IPDBEnumChildren
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|uint32_t
name|getChildCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|ChildTypePtr
name|getChildAtIndex
argument_list|(
name|uint32_t
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|ChildTypePtr
name|getNext
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|reset
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|MyType
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace pdb
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_IPDBENUMCHILDREN_H
end_comment

end_unit

