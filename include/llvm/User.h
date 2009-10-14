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
comment|// This class defines the interface that one who 'use's a Value must implement.
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
comment|//  * Instructions are the largest class of User's.
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
name|LLVM_USER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_USER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// OperandTraits - Compile-time customization of
comment|/// operand-related allocators and accessors
comment|/// for use of the User class
name|template
operator|<
name|class
operator|>
expr|struct
name|OperandTraits
expr_stmt|;
name|class
name|User
decl_stmt|;
comment|/// OperandTraits<User> - specialization to User
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|User
operator|>
block|{
specifier|static
specifier|inline
name|Use
operator|*
name|op_begin
argument_list|(
name|User
operator|*
argument_list|)
block|;
specifier|static
specifier|inline
name|Use
operator|*
name|op_end
argument_list|(
name|User
operator|*
argument_list|)
block|;
specifier|static
specifier|inline
name|unsigned
name|operands
argument_list|(
specifier|const
name|User
operator|*
argument_list|)
block|;
name|template
operator|<
name|class
name|U
operator|>
expr|struct
name|Layout
block|{
typedef|typedef
name|U
name|overlay
typedef|;
block|}
block|; }
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
block|;
comment|// Do not implement
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|)
block|;
comment|// Do not implement
name|template
operator|<
name|unsigned
operator|>
name|friend
expr|struct
name|HungoffOperandTraits
block|;
name|protected
operator|:
comment|/// OperandList - This is a pointer to the array of Uses for this User.
comment|/// For nodes of fixed arity (e.g. a binary operator) this array will live
comment|/// prefixed to some derived class instance.  For nodes of resizable variable
comment|/// arity (e.g. PHINodes, SwitchInst etc.), this memory will be dynamically
comment|/// allocated and should be destroyed by the classes' virtual dtor.
name|Use
operator|*
name|OperandList
block|;
comment|/// NumOperands - The number of values used by this User.
comment|///
name|unsigned
name|NumOperands
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|,
argument|unsigned Us
argument_list|)
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|,
argument|unsigned Us
argument_list|,
argument|bool Prefix
argument_list|)
block|;
name|User
argument_list|(
argument|const Type *ty
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
name|ty
argument_list|,
name|vty
argument_list|)
block|,
name|OperandList
argument_list|(
name|OpList
argument_list|)
block|,
name|NumOperands
argument_list|(
argument|NumOps
argument_list|)
block|{}
name|Use
operator|*
name|allocHungoffUses
argument_list|(
argument|unsigned
argument_list|)
specifier|const
block|;
name|void
name|dropHungoffUses
argument_list|(
argument|Use *U
argument_list|)
block|{
if|if
condition|(
name|OperandList
operator|==
name|U
condition|)
block|{
name|OperandList
operator|=
literal|0
expr_stmt|;
name|NumOperands
operator|=
literal|0
expr_stmt|;
block|}
name|Use
operator|::
name|zap
argument_list|(
name|U
argument_list|,
name|U
operator|->
name|getImpliedUser
argument_list|()
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
operator|~
name|User
argument_list|()
block|{
if|if
condition|(
operator|(
name|intptr_t
argument_list|(
name|OperandList
argument_list|)
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
name|Use
operator|::
name|zap
argument_list|(
name|OperandList
argument_list|,
name|OperandList
operator|+
name|NumOperands
argument_list|)
expr_stmt|;
block|}
comment|/// operator delete - free memory allocated for User and Use objects
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|Usr
argument_list|)
block|;
comment|/// placement delete - required by std, but never called.
name|void
name|operator
name|delete
argument_list|(
argument|void*
argument_list|,
argument|unsigned
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Constructor throws?"
argument_list|)
block|;   }
comment|/// placement delete - required by std, but never called.
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
name|assert
argument_list|(
literal|0
operator|&&
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
name|public
operator|:
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
name|NumOperands
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|OperandList
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
name|NumOperands
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
name|OperandList
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
name|NumOperands
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|OperandList
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
name|NumOperands
operator|&&
literal|"getOperand() out of range!"
argument_list|)
block|;
return|return
name|OperandList
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
name|NumOperands
return|;
block|}
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
specifier|inline
name|op_iterator
name|op_begin
parameter_list|()
block|{
return|return
name|OperandList
return|;
block|}
specifier|inline
name|const_op_iterator
name|op_begin
argument_list|()
specifier|const
block|{
return|return
name|OperandList
return|;
block|}
specifier|inline
name|op_iterator
name|op_end
parameter_list|()
block|{
return|return
name|OperandList
operator|+
name|NumOperands
return|;
block|}
specifier|inline
name|const_op_iterator
name|op_end
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|+
name|NumOperands
return|;
block|}
comment|// dropAllReferences() - This function is in charge of "letting go" of all
comment|// objects that this User refers to.  This allows one to
comment|// 'delete' a whole class at a time, even though there may be circular
comment|// references...  First all references are dropped, and all use counts go to
comment|// zero.  Then everything is deleted for real.  Note that no operations are
comment|// valid on an object that has "dropped all references", except operator
comment|// delete.
comment|//
name|void
name|dropAllReferences
parameter_list|()
block|{
for|for
control|(
name|op_iterator
name|i
init|=
name|op_begin
argument_list|()
init|,
name|e
init|=
name|op_end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|i
operator|->
name|set
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/// replaceUsesOfWith - Replaces all references to the "From" definition with
comment|/// references to the "To" definition.
comment|///
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
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|User
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|Use
operator|*
name|OperandTraits
operator|<
name|User
operator|>
operator|::
name|op_begin
argument_list|(
argument|User *U
argument_list|)
block|{
return|return
name|U
operator|->
name|op_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Use
operator|*
name|OperandTraits
operator|<
name|User
operator|>
operator|::
name|op_end
argument_list|(
argument|User *U
argument_list|)
block|{
return|return
name|U
operator|->
name|op_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|OperandTraits
operator|<
name|User
operator|>
operator|::
name|operands
argument_list|(
argument|const User *U
argument_list|)
block|{
return|return
name|U
operator|->
name|getNumOperands
argument_list|()
return|;
block|}
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
argument|const User::op_iterator&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|->
name|get
argument_list|()
operator|)
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
specifier|const
name|User
operator|::
name|op_iterator
operator|>
operator|:
name|public
name|simplify_type
operator|<
name|User
operator|::
name|op_iterator
operator|>
block|{}
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
name|const_op_iterator
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
argument|const User::const_op_iterator&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|->
name|get
argument_list|()
operator|)
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
specifier|const
name|User
operator|::
name|const_op_iterator
operator|>
operator|:
name|public
name|simplify_type
operator|<
name|User
operator|::
name|const_op_iterator
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// value_use_iterator::getOperandNo - Requires the definition of the User class.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|UserTy
operator|>
name|unsigned
name|value_use_iterator
operator|<
name|UserTy
operator|>
operator|::
name|getOperandNo
argument_list|()
specifier|const
block|{
return|return
name|U
operator|-
name|U
operator|->
name|getUser
argument_list|()
operator|->
name|op_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

