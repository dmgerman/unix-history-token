begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/User.h - User class definition ---------------------*- C++ -*-===//
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
comment|// This class defines the interface that one who uses a Value must implement.
end_comment

begin_comment
comment|// Each instance of the Value class keeps track of what User's have handles
end_comment

begin_comment
comment|// to it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  * Instructions are the largest class of Users.
end_comment

begin_comment
comment|//  * Constants may be users of other constants (think arrays and stuff)
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
name|LLVM_IR_USER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_USER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Compile-time customization of User operands.
comment|///
comment|/// Customizes operand-related allocators and accessors.
name|template
operator|<
name|class
operator|>
expr|struct
name|OperandTraits
expr_stmt|;
name|class
name|User
range|:
name|public
name|Value
block|{
name|User
argument_list|(
specifier|const
name|User
operator|&
argument_list|)
operator|=
name|delete
block|;
name|template
operator|<
name|unsigned
operator|>
name|friend
expr|struct
name|HungoffOperandTraits
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
comment|/// Allocate a User with an operand pointer co-allocated.
comment|///
comment|/// This is used for subclasses which need to allocate a variable number
comment|/// of operands, ie, 'hung off uses'.
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t Size
argument_list|)
block|;
comment|/// Allocate a User with the operands co-allocated.
comment|///
comment|/// This is used for subclasses which have a fixed number of operands.
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t Size
argument_list|,
argument|unsigned Us
argument_list|)
block|;
name|User
argument_list|(
argument|Type *ty
argument_list|,
argument|unsigned vty
argument_list|,
argument|Use *OpList
argument_list|,
argument|unsigned NumOps
argument_list|)
operator|:
name|Value
argument_list|(
argument|ty
argument_list|,
argument|vty
argument_list|)
block|{
name|assert
argument_list|(
name|NumOps
operator|<
operator|(
literal|1u
operator|<<
name|NumUserOperandsBits
operator|)
operator|&&
literal|"Too many operands"
argument_list|)
block|;
name|NumUserOperands
operator|=
name|NumOps
block|;
comment|// If we have hung off uses, then the operand list should initially be
comment|// null.
name|assert
argument_list|(
operator|(
operator|!
name|HasHungOffUses
operator|||
operator|!
name|getOperandList
argument_list|()
operator|)
operator|&&
literal|"Error in initializing hung off uses for User"
argument_list|)
block|;   }
comment|/// \brief Allocate the array of Uses, followed by a pointer
comment|/// (with bottom bit set) to the User.
comment|/// \param IsPhi identifies callers which are phi nodes and which need
comment|/// N BasicBlock* allocated along with N
name|void
name|allocHungoffUses
argument_list|(
argument|unsigned N
argument_list|,
argument|bool IsPhi = false
argument_list|)
block|;
comment|/// \brief Grow the number of hung off uses.  Note that allocHungoffUses
comment|/// should be called if there are no uses.
name|void
name|growHungoffUses
argument_list|(
argument|unsigned N
argument_list|,
argument|bool IsPhi = false
argument_list|)
block|;
name|public
operator|:
operator|~
name|User
argument_list|()
name|override
block|{   }
comment|/// \brief Free memory allocated for User and Use objects.
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|Usr
argument_list|)
block|;
comment|/// \brief Placement delete - required by std, but never called.
name|void
name|operator
name|delete
argument_list|(
argument|void*
argument_list|,
argument|unsigned
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Constructor throws?"
argument_list|)
block|;   }
comment|/// \brief Placement delete - required by std, but never called.
name|void
name|operator
name|delete
argument_list|(
argument|void*
argument_list|,
argument|unsigned
argument_list|,
argument|bool
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Constructor throws?"
argument_list|)
block|;   }
name|protected
operator|:
name|template
operator|<
name|int
name|Idx
block|,
name|typename
name|U
operator|>
specifier|static
name|Use
operator|&
name|OpFrom
argument_list|(
argument|const U *that
argument_list|)
block|{
return|return
name|Idx
operator|<
literal|0
operator|?
name|OperandTraits
operator|<
name|U
operator|>
operator|::
name|op_end
argument_list|(
name|const_cast
operator|<
name|U
operator|*
operator|>
operator|(
name|that
operator|)
argument_list|)
index|[
name|Idx
index|]
operator|:
name|OperandTraits
operator|<
name|U
operator|>
operator|::
name|op_begin
argument_list|(
name|const_cast
operator|<
name|U
operator|*
operator|>
operator|(
name|that
operator|)
argument_list|)
index|[
name|Idx
index|]
return|;
block|}
name|template
operator|<
name|int
name|Idx
operator|>
name|Use
operator|&
name|Op
argument_list|()
block|{
return|return
name|OpFrom
operator|<
name|Idx
operator|>
operator|(
name|this
operator|)
return|;
block|}
name|template
operator|<
name|int
name|Idx
operator|>
specifier|const
name|Use
operator|&
name|Op
argument_list|()
specifier|const
block|{
return|return
name|OpFrom
operator|<
name|Idx
operator|>
operator|(
name|this
operator|)
return|;
block|}
name|private
operator|:
name|Use
operator|*
operator|&
name|getHungOffOperands
argument_list|()
block|{
return|return
operator|*
operator|(
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|*
operator|>
operator|(
name|this
operator|)
operator|-
literal|1
operator|)
return|;
block|}
name|Use
operator|*
name|getIntrusiveOperands
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|>
operator|(
name|this
operator|)
operator|-
name|NumUserOperands
return|;
block|}
name|void
name|setOperandList
argument_list|(
argument|Use *NewList
argument_list|)
block|{
name|assert
argument_list|(
name|HasHungOffUses
operator|&&
literal|"Setting operand list only required for hung off uses"
argument_list|)
block|;
name|getHungOffOperands
argument_list|()
operator|=
name|NewList
block|;   }
name|public
operator|:
name|Use
operator|*
name|getOperandList
argument_list|()
block|{
return|return
name|HasHungOffUses
condition|?
name|getHungOffOperands
argument_list|()
else|:
name|getIntrusiveOperands
argument_list|()
return|;
block|}
specifier|const
name|Use
operator|*
name|getOperandList
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|User
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getOperandList
argument_list|()
return|;
block|}
name|Value
operator|*
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumUserOperands
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|getOperandList
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|void
name|setOperand
argument_list|(
argument|unsigned i
argument_list|,
argument|Value *Val
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumUserOperands
operator|&&
literal|"setOperand() out of range!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|!
name|isa
operator|<
name|Constant
operator|>
operator|(
operator|(
specifier|const
name|Value
operator|*
operator|)
name|this
operator|)
operator|||
name|isa
operator|<
name|GlobalValue
operator|>
operator|(
operator|(
specifier|const
name|Value
operator|*
operator|)
name|this
operator|)
operator|)
operator|&&
literal|"Cannot mutate a constant with setOperand!"
argument_list|)
block|;
name|getOperandList
argument_list|()
index|[
name|i
index|]
operator|=
name|Val
block|;   }
specifier|const
name|Use
operator|&
name|getOperandUse
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumUserOperands
operator|&&
literal|"getOperandUse() out of range!"
argument_list|)
block|;
return|return
name|getOperandList
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|Use
operator|&
name|getOperandUse
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumUserOperands
operator|&&
literal|"getOperandUse() out of range!"
argument_list|)
block|;
return|return
name|getOperandList
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumUserOperands
return|;
block|}
comment|/// Set the number of operands on a GlobalVariable.
comment|///
comment|/// GlobalVariable always allocates space for a single operands, but
comment|/// doesn't always use it.
comment|///
comment|/// FIXME: As that the number of operands is used to find the start of
comment|/// the allocated memory in operator delete, we need to always think we have
comment|/// 1 operand before delete.
name|void
name|setGlobalVariableNumOperands
argument_list|(
argument|unsigned NumOps
argument_list|)
block|{
name|assert
argument_list|(
name|NumOps
operator|<=
literal|1
operator|&&
literal|"GlobalVariable can only have 0 or 1 operands"
argument_list|)
block|;
name|NumUserOperands
operator|=
name|NumOps
block|;   }
comment|/// Set the number of operands on a Function.
comment|///
comment|/// Function always allocates space for a single operands, but
comment|/// doesn't always use it.
comment|///
comment|/// FIXME: As that the number of operands is used to find the start of
comment|/// the allocated memory in operator delete, we need to always think we have
comment|/// 1 operand before delete.
name|void
name|setFunctionNumOperands
argument_list|(
argument|unsigned NumOps
argument_list|)
block|{
name|assert
argument_list|(
name|NumOps
operator|<=
literal|1
operator|&&
literal|"Function can only have 0 or 1 operands"
argument_list|)
block|;
name|NumUserOperands
operator|=
name|NumOps
block|;   }
comment|/// \brief Subclasses with hung off uses need to manage the operand count
comment|/// themselves.  In these instances, the operand count isn't used to find the
comment|/// OperandList, so there's no issue in having the operand count change.
name|void
name|setNumHungOffUseOperands
argument_list|(
argument|unsigned NumOps
argument_list|)
block|{
name|assert
argument_list|(
name|HasHungOffUses
operator|&&
literal|"Must have hung off uses to use this method"
argument_list|)
block|;
name|assert
argument_list|(
name|NumOps
operator|<
operator|(
literal|1u
operator|<<
name|NumUserOperandsBits
operator|)
operator|&&
literal|"Too many operands"
argument_list|)
block|;
name|NumUserOperands
operator|=
name|NumOps
block|;   }
comment|// ---------------------------------------------------------------------------
comment|// Operand Iterator interface...
comment|//
typedef|typedef
name|Use
modifier|*
name|op_iterator
typedef|;
typedef|typedef
specifier|const
name|Use
modifier|*
name|const_op_iterator
typedef|;
typedef|typedef
name|iterator_range
operator|<
name|op_iterator
operator|>
name|op_range
expr_stmt|;
typedef|typedef
name|iterator_range
operator|<
name|const_op_iterator
operator|>
name|const_op_range
expr_stmt|;
name|op_iterator
name|op_begin
parameter_list|()
block|{
return|return
name|getOperandList
argument_list|()
return|;
block|}
name|const_op_iterator
name|op_begin
argument_list|()
specifier|const
block|{
return|return
name|getOperandList
argument_list|()
return|;
block|}
name|op_iterator
name|op_end
parameter_list|()
block|{
return|return
name|getOperandList
argument_list|()
operator|+
name|NumUserOperands
return|;
block|}
name|const_op_iterator
name|op_end
argument_list|()
specifier|const
block|{
return|return
name|getOperandList
argument_list|()
operator|+
name|NumUserOperands
return|;
block|}
name|op_range
name|operands
parameter_list|()
block|{
return|return
name|op_range
argument_list|(
name|op_begin
argument_list|()
argument_list|,
name|op_end
argument_list|()
argument_list|)
return|;
block|}
name|const_op_range
name|operands
argument_list|()
specifier|const
block|{
return|return
name|const_op_range
argument_list|(
name|op_begin
argument_list|()
argument_list|,
name|op_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Iterator for directly iterating over the operand Values.
name|struct
name|value_op_iterator
range|:
name|iterator_adaptor_base
operator|<
name|value_op_iterator
decl_stmt|,
name|op_iterator
decl_stmt|,
name|std
decl|::
name|random_access_iterator_tag
decl_stmt|,
name|Value
modifier|*
decl_stmt|,
name|ptrdiff_t
decl_stmt|,
name|Value
modifier|*
decl_stmt|,
name|Value
modifier|*
decl|>
block|{
name|explicit
name|value_op_iterator
argument_list|(
name|Use
operator|*
name|U
operator|=
name|nullptr
argument_list|)
operator|:
name|iterator_adaptor_base
argument_list|(
argument|U
argument_list|)
block|{}
name|Value
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|I
return|;
block|}
name|Value
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|value_op_iterator
name|value_op_begin
parameter_list|()
block|{
return|return
name|value_op_iterator
argument_list|(
name|op_begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|value_op_iterator
name|value_op_end
parameter_list|()
block|{
return|return
name|value_op_iterator
argument_list|(
name|op_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|iterator_range
operator|<
name|value_op_iterator
operator|>
name|operand_values
argument_list|()
block|{
return|return
name|iterator_range
operator|<
name|value_op_iterator
operator|>
operator|(
name|value_op_begin
argument_list|()
operator|,
name|value_op_end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Drop all references to operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function is in charge of "letting go" of all objects that this User
end_comment

begin_comment
comment|/// refers to.  This allows one to 'delete' a whole class at a time, even
end_comment

begin_comment
comment|/// though there may be circular references...  First all references are
end_comment

begin_comment
comment|/// dropped, and all use counts go to zero.  Then everything is deleted for
end_comment

begin_comment
comment|/// real.  Note that no operations are valid on an object that has "dropped
end_comment

begin_comment
comment|/// all references", except operator delete.
end_comment

begin_function
name|void
name|dropAllReferences
parameter_list|()
block|{
for|for
control|(
name|Use
modifier|&
name|U
range|:
name|operands
argument_list|()
control|)
name|U
operator|.
name|set
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Replace uses of one Value with another.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Replaces all references to the "From" definition with references to the
end_comment

begin_comment
comment|/// "To" definition.
end_comment

begin_function_decl
name|void
name|replaceUsesOfWith
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
end_function_decl

begin_comment
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
end_comment

begin_function
specifier|static
specifier|inline
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
name|isa
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
operator|||
name|isa
operator|<
name|Constant
operator|>
operator|(
name|V
operator|)
return|;
block|}
end_function

begin_comment
unit|};
comment|// Either Use objects, or a Use pointer can be prepended to User.
end_comment

begin_expr_stmt
name|static_assert
argument_list|(
name|AlignOf
operator|<
name|Use
operator|>
operator|::
name|Alignment
operator|>=
name|AlignOf
operator|<
name|User
operator|>
operator|::
name|Alignment
argument_list|,
literal|"Alignment is insufficient after objects prepended to User"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
name|AlignOf
operator|<
name|Use
operator|*
operator|>
operator|::
name|Alignment
operator|>=
name|AlignOf
operator|<
name|User
operator|>
operator|::
name|Alignment
argument_list|,
literal|"Alignment is insufficient after objects prepended to User"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|User
operator|::
name|op_iterator
operator|>
block|{
typedef|typedef
name|Value
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|User::op_iterator&Val
argument_list|)
block|{
return|return
name|Val
operator|->
name|get
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|User
operator|::
name|const_op_iterator
operator|>
block|{
typedef|typedef
comment|/*const*/
name|Value
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|User::const_op_iterator&Val
argument_list|)
block|{
return|return
name|Val
operator|->
name|get
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

