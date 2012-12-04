begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AttributesImpl.h - Attributes Internals -----------------*- C++ -*-===//
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
comment|// This file defines various helper methods and classes used by LLVMContextImpl
end_comment

begin_comment
comment|// for creating and managing attributes.
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
name|LLVM_ATTRIBUTESIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTESIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AttributesImpl
range|:
name|public
name|FoldingSetNode
block|{
name|uint64_t
name|Bits
block|;
comment|// FIXME: We will be expanding this.
name|public
operator|:
name|AttributesImpl
argument_list|(
argument|uint64_t bits
argument_list|)
operator|:
name|Bits
argument_list|(
argument|bits
argument_list|)
block|{}
name|bool
name|hasAttribute
argument_list|(
argument|uint64_t A
argument_list|)
specifier|const
block|;
name|bool
name|hasAttributes
argument_list|()
specifier|const
block|;
name|bool
name|hasAttributes
argument_list|(
argument|const Attributes&A
argument_list|)
specifier|const
block|;
name|uint64_t
name|getAlignment
argument_list|()
specifier|const
block|;
name|uint64_t
name|getStackAlignment
argument_list|()
specifier|const
block|;
name|uint64_t
name|Raw
argument_list|()
specifier|const
block|{
return|return
name|Bits
return|;
block|}
comment|// FIXME: Remove.
specifier|static
name|uint64_t
name|getAttrMask
argument_list|(
argument|uint64_t Val
argument_list|)
block|;
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Bits
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|,
argument|uint64_t Bits
argument_list|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Bits
argument_list|)
block|;   }
block|}
decl_stmt|;
name|class
name|AttributeListImpl
range|:
name|public
name|FoldingSetNode
block|{
comment|// AttributesList is uniqued, these should not be publicly available.
name|void
name|operator
operator|=
operator|(
specifier|const
name|AttributeListImpl
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|AttributeListImpl
argument_list|(
argument|const AttributeListImpl&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
name|SmallVector
operator|<
name|AttributeWithIndex
block|,
literal|4
operator|>
name|Attrs
block|;
name|AttributeListImpl
argument_list|(
name|ArrayRef
operator|<
name|AttributeWithIndex
operator|>
name|attrs
argument_list|)
operator|:
name|Attrs
argument_list|(
argument|attrs.begin()
argument_list|,
argument|attrs.end()
argument_list|)
block|{}
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
block|{
name|Profile
argument_list|(
name|ID
argument_list|,
name|Attrs
argument_list|)
block|;   }
specifier|static
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|,
argument|ArrayRef<AttributeWithIndex> Attrs
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Attrs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|ID
operator|.
name|AddInteger
argument_list|(
name|Attrs
index|[
name|i
index|]
operator|.
name|Attrs
operator|.
name|Raw
argument_list|()
argument_list|)
expr_stmt|;
name|ID
operator|.
name|AddInteger
argument_list|(
name|Attrs
index|[
name|i
index|]
operator|.
name|Index
argument_list|)
expr_stmt|;
block|}
block|}
block|}
decl_stmt|;
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

