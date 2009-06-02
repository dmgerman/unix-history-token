begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Metadata.h - Constant class subclass definitions ---*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// This file contains the declarations for the subclasses of Constant,
end_comment

begin_comment
comment|/// which represent the different flavors of constant values that live in LLVM.
end_comment

begin_comment
comment|/// Note that Constants are immutable (once created they never change) and are
end_comment

begin_comment
comment|/// fully shared by structural equivalence.  This means that two structurally
end_comment

begin_comment
comment|/// equivalent constants will always have the same address.  Constant's are
end_comment

begin_comment
comment|/// created on demand as needed and never deleted: thus clients don't have to
end_comment

begin_comment
comment|/// worry about the lifetime of the objects.
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
name|LLVM_MDNODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MDNODE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|/// MDNode - a tuple of other values.
comment|/// These contain a list of the Constants that represent the metadata. The
comment|/// operand list is always empty, query the element list instead.
comment|///
comment|/// This class will attempt to keep track of values as they are modified. When
comment|/// a value is replaced the element will be replaced with it, and when the
comment|/// value is deleted the element is set to a null pointer. In order to preserve
comment|/// structural equivalence while the elements mutate, the MDNode may call
comment|/// replaceAllUsesWith on itself. Because of this, users of MDNode must use a
comment|/// WeakVH or CallbackVH to hold the node pointer if there is a chance that one
comment|/// of the elements held by the node may change.
comment|///
name|class
name|MDNode
range|:
name|public
name|Constant
decl_stmt|,
name|public
name|FoldingSetNode
block|{
name|MDNode
argument_list|(
specifier|const
name|MDNode
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|ElementVH
decl_stmt|;
name|struct
name|ElementVH
range|:
name|public
name|CallbackVH
block|{
name|MDNode
operator|*
name|OwningNode
block|;
name|ElementVH
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|MDNode
operator|*
name|Parent
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|V
argument_list|)
block|,
name|OwningNode
argument_list|(
argument|Parent
argument_list|)
block|{}
operator|~
name|ElementVH
argument_list|()
block|{}
comment|/// deleted - Set this entry in the MDNode to 'null'. This will reallocate
comment|/// the MDNode.
name|virtual
name|void
name|deleted
argument_list|()
block|{
name|OwningNode
operator|->
name|replaceElement
argument_list|(
argument|this->operator Value*()
argument_list|,
literal|0
argument_list|)
block|;     }
comment|/// allUsesReplacedWith - Modify the MDNode by replacing this entry with
comment|/// new_value. This will reallocate the MDNode.
name|virtual
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *new_value
argument_list|)
block|{
name|OwningNode
operator|->
name|replaceElement
argument_list|(
argument|this->operator Value*()
argument_list|,
argument|new_value
argument_list|)
block|;     }
block|}
decl_stmt|;
name|void
name|replaceElement
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|)
function_decl|;
name|SmallVector
operator|<
name|ElementVH
operator|,
literal|4
operator|>
name|Node
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ElementVH
operator|>
operator|::
name|iterator
name|elem_iterator
expr_stmt|;
name|protected
label|:
name|explicit
name|MDNode
parameter_list|(
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|)
function_decl|;
name|public
label|:
typedef|typedef
name|SmallVectorImpl
operator|<
name|ElementVH
operator|>
operator|::
name|const_iterator
name|const_elem_iterator
expr_stmt|;
comment|/// get() - Static factory methods - Return objects of the specified value.
comment|///
specifier|static
name|MDNode
modifier|*
name|get
parameter_list|(
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|)
function_decl|;
name|Value
modifier|*
name|getElement
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|Node
index|[
name|i
index|]
return|;
block|}
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|elem_empty
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|empty
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_begin
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_end
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// getType() specialization - Type is always MetadataTy.
comment|///
specifier|inline
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
operator|::
name|MetadataTy
return|;
block|}
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because getNullValue will never
comment|/// produce metadata.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Profile - calculate a unique identifier for this MDNode to collapse
comment|/// duplicates
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|destroyConstant
parameter_list|()
function_decl|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|,
name|Use
modifier|*
name|U
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"This should never be called because MDNodes have no ops"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|MDNode
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|MDNodeVal
return|;
block|}
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

