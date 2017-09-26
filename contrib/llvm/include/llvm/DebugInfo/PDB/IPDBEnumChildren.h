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
name|using
name|ChildTypePtr
operator|=
name|std
operator|::
name|unique_ptr
operator|<
name|ChildType
operator|>
block|;
name|using
name|MyType
operator|=
name|IPDBEnumChildren
operator|<
name|ChildType
operator|>
block|;
name|virtual
operator|~
name|IPDBEnumChildren
argument_list|()
operator|=
expr|default
block|;
name|virtual
name|uint32_t
name|getChildCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|ChildTypePtr
name|getChildAtIndex
argument_list|(
argument|uint32_t Index
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|ChildTypePtr
name|getNext
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|reset
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|MyType
operator|*
name|clone
argument_list|()
specifier|const
operator|=
literal|0
block|; }
expr_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
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

