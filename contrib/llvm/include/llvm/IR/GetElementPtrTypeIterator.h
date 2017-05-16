begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GetElementPtrTypeIterator.h ------------------------------*- C++ -*-===//
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
comment|// This file implements an iterator for walking through the types indexed by
end_comment

begin_comment
comment|// getelementptr instructions.
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
name|LLVM_IR_GETELEMENTPTRTYPEITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GETELEMENTPTRTYPEITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|ItTy
operator|=
name|User
operator|::
name|const_op_iterator
operator|>
name|class
name|generic_gep_type_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|Type
operator|*
operator|,
name|ptrdiff_t
operator|>
block|{
name|using
name|super
operator|=
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|Type
operator|*
block|,
name|ptrdiff_t
operator|>
block|;
name|ItTy
name|OpIt
block|;
name|PointerUnion
operator|<
name|StructType
operator|*
block|,
name|Type
operator|*
operator|>
name|CurTy
block|;     enum
operator|:
name|uint64_t
block|{
name|Unbounded
operator|=
operator|-
literal|1ull
block|}
block|;
name|uint64_t
name|NumElements
operator|=
name|Unbounded
block|;
name|generic_gep_type_iterator
argument_list|()
operator|=
expr|default
block|;
name|public
operator|:
specifier|static
name|generic_gep_type_iterator
name|begin
argument_list|(
argument|Type *Ty
argument_list|,
argument|ItTy It
argument_list|)
block|{
name|generic_gep_type_iterator
name|I
block|;
name|I
operator|.
name|CurTy
operator|=
name|Ty
block|;
name|I
operator|.
name|OpIt
operator|=
name|It
block|;
return|return
name|I
return|;
block|}
specifier|static
name|generic_gep_type_iterator
name|end
argument_list|(
argument|ItTy It
argument_list|)
block|{
name|generic_gep_type_iterator
name|I
block|;
name|I
operator|.
name|OpIt
operator|=
name|It
block|;
return|return
name|I
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|generic_gep_type_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|OpIt
operator|==
name|x
operator|.
name|OpIt
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|generic_gep_type_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|// FIXME: Make this the iterator's operator*() after the 4.0 release.
comment|// operator*() had a different meaning in earlier releases, so we're
comment|// temporarily not giving this iterator an operator*() to avoid a subtle
comment|// semantics break.
name|Type
operator|*
name|getIndexedType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|T
operator|=
name|CurTy
operator|.
name|dyn_cast
operator|<
name|Type
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|T
return|;
return|return
name|CurTy
operator|.
name|get
operator|<
name|StructType
operator|*
operator|>
operator|(
operator|)
operator|->
name|getTypeAtIndex
argument_list|(
name|getOperand
argument_list|()
argument_list|)
return|;
block|}
name|Value
operator|*
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
operator|&
operator|*
operator|*
name|OpIt
operator|)
return|;
block|}
name|generic_gep_type_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|Type
operator|*
name|Ty
operator|=
name|getIndexedType
argument_list|()
block|;
if|if
condition|(
name|auto
operator|*
name|STy
operator|=
name|dyn_cast
operator|<
name|SequentialType
operator|>
operator|(
name|Ty
operator|)
condition|)
block|{
name|CurTy
operator|=
name|STy
operator|->
name|getElementType
argument_list|()
expr_stmt|;
name|NumElements
operator|=
name|STy
operator|->
name|getNumElements
argument_list|()
expr_stmt|;
block|}
else|else
name|CurTy
operator|=
name|dyn_cast
operator|<
name|StructType
operator|>
operator|(
name|Ty
operator|)
expr_stmt|;
operator|++
name|OpIt
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|generic_gep_type_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|generic_gep_type_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|// All of the below API is for querying properties of the "outer type", i.e.
end_comment

begin_comment
comment|// the type that contains the indexed type. Most of the time this is just
end_comment

begin_comment
comment|// the type that was visited immediately prior to the indexed type, but for
end_comment

begin_comment
comment|// the first element this is an unbounded array of the GEP's source element
end_comment

begin_comment
comment|// type, for which there is no clearly corresponding IR type (we've
end_comment

begin_comment
comment|// historically used a pointer type as the outer type in this case, but
end_comment

begin_comment
comment|// pointers will soon lose their element type).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Most current users of this class are just interested in byte
end_comment

begin_comment
comment|// offsets (a few need to know whether the outer type is a struct because
end_comment

begin_comment
comment|// they are trying to replace a constant with a variable, which is only
end_comment

begin_comment
comment|// legal for arrays, e.g. canReplaceOperandWithVariable in SimplifyCFG.cpp);
end_comment

begin_comment
comment|// we should provide a more minimal API here that exposes not much more than
end_comment

begin_comment
comment|// that.
end_comment

begin_expr_stmt
name|bool
name|isStruct
argument_list|()
specifier|const
block|{
return|return
name|CurTy
operator|.
name|is
operator|<
name|StructType
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isSequential
argument_list|()
specifier|const
block|{
return|return
name|CurTy
operator|.
name|is
operator|<
name|Type
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|StructType
operator|*
name|getStructType
argument_list|()
specifier|const
block|{
return|return
name|CurTy
operator|.
name|get
operator|<
name|StructType
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|StructType
operator|*
name|getStructTypeOrNull
argument_list|()
specifier|const
block|{
return|return
name|CurTy
operator|.
name|dyn_cast
operator|<
name|StructType
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isBoundedSequential
argument_list|()
specifier|const
block|{
return|return
name|isSequential
argument_list|()
operator|&&
name|NumElements
operator|!=
name|Unbounded
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint64_t
name|getSequentialNumElements
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isBoundedSequential
argument_list|()
argument_list|)
block|;
return|return
name|NumElements
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|using
name|gep_type_iterator
init|=
name|generic_gep_type_iterator
operator|<
operator|>
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|gep_type_iterator
name|gep_type_begin
parameter_list|(
specifier|const
name|User
modifier|*
name|GEP
parameter_list|)
block|{
name|auto
operator|*
name|GEPOp
operator|=
name|cast
operator|<
name|GEPOperator
operator|>
operator|(
name|GEP
operator|)
expr_stmt|;
return|return
name|gep_type_iterator
operator|::
name|begin
argument_list|(
name|GEPOp
operator|->
name|getSourceElementType
argument_list|()
argument_list|,
name|GEP
operator|->
name|op_begin
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|gep_type_iterator
name|gep_type_end
parameter_list|(
specifier|const
name|User
modifier|*
name|GEP
parameter_list|)
block|{
return|return
name|gep_type_iterator
operator|::
name|end
argument_list|(
name|GEP
operator|->
name|op_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|gep_type_iterator
name|gep_type_begin
parameter_list|(
specifier|const
name|User
modifier|&
name|GEP
parameter_list|)
block|{
name|auto
operator|&
name|GEPOp
operator|=
name|cast
operator|<
name|GEPOperator
operator|>
operator|(
name|GEP
operator|)
expr_stmt|;
return|return
name|gep_type_iterator
operator|::
name|begin
argument_list|(
name|GEPOp
operator|.
name|getSourceElementType
argument_list|()
argument_list|,
name|GEP
operator|.
name|op_begin
argument_list|()
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|gep_type_iterator
name|gep_type_end
parameter_list|(
specifier|const
name|User
modifier|&
name|GEP
parameter_list|)
block|{
return|return
name|gep_type_iterator
operator|::
name|end
argument_list|(
name|GEP
operator|.
name|op_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|generic_gep_type_iterator
operator|<
specifier|const
name|T
operator|*
operator|>
name|gep_type_begin
argument_list|(
argument|Type *Op0
argument_list|,
argument|ArrayRef<T> A
argument_list|)
block|{
return|return
name|generic_gep_type_iterator
operator|<
specifier|const
name|T
operator|*
operator|>
operator|::
name|begin
argument_list|(
name|Op0
argument_list|,
name|A
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|generic_gep_type_iterator
operator|<
specifier|const
name|T
operator|*
operator|>
name|gep_type_end
argument_list|(
argument|Type *
comment|/*Op0*/
argument_list|,
argument|ArrayRef<T> A
argument_list|)
block|{
return|return
name|generic_gep_type_iterator
operator|<
specifier|const
name|T
operator|*
operator|>
operator|::
name|end
argument_list|(
name|A
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_GETELEMENTPTRTYPEITERATOR_H
end_comment

end_unit

