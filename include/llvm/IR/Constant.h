begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Constant.h - Constant class definition -------------*- C++ -*-===//
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
comment|// This file contains the declaration of the Constant class.
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
name|LLVM_IR_CONSTANT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_CONSTANT_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
comment|/// This is an important base class in LLVM. It provides the common facilities
comment|/// of all constant values in an LLVM program. A constant is a value that is
comment|/// immutable at runtime. Functions are constants because their address is
comment|/// immutable. Same with global variables.
comment|///
comment|/// All constants share the capabilities provided in this class. All constants
comment|/// can have a null value. They can have an operand list. Constants can be
comment|/// simple (integer and floating point values), complex (arrays and structures),
comment|/// or expression based (computations yielding a constant value composed of
comment|/// only certain operators and other constant values).
comment|///
comment|/// Note that Constants are immutable (once created they never change)
comment|/// and are fully shared by structural equivalence.  This means that two
comment|/// structurally equivalent constants will always have the same address.
comment|/// Constants are created on demand as needed and never deleted: thus clients
comment|/// don't have to worry about the lifetime of the objects.
comment|/// @brief LLVM Constant Representation
name|class
name|Constant
range|:
name|public
name|User
block|{
name|protected
operator|:
name|Constant
argument_list|(
argument|Type *ty
argument_list|,
argument|ValueTy vty
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|)
operator|:
name|User
argument_list|(
argument|ty
argument_list|,
argument|vty
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|)
block|{}
name|public
operator|:
name|void
name|operator
operator|=
operator|(
specifier|const
name|Constant
operator|&
operator|)
operator|=
name|delete
block|;
name|Constant
argument_list|(
specifier|const
name|Constant
operator|&
argument_list|)
operator|=
name|delete
block|;
comment|/// Return true if this is the value that would be returned by getNullValue.
name|bool
name|isNullValue
argument_list|()
specifier|const
block|;
comment|/// Returns true if the value is one.
name|bool
name|isOneValue
argument_list|()
specifier|const
block|;
comment|/// Return true if this is the value that would be returned by
comment|/// getAllOnesValue.
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|;
comment|/// Return true if the value is what would be returned by
comment|/// getZeroValueForNegation.
name|bool
name|isNegativeZeroValue
argument_list|()
specifier|const
block|;
comment|/// Return true if the value is negative zero or null value.
name|bool
name|isZeroValue
argument_list|()
specifier|const
block|;
comment|/// Return true if the value is not the smallest signed value.
name|bool
name|isNotMinSignedValue
argument_list|()
specifier|const
block|;
comment|/// Return true if the value is the smallest signed value.
name|bool
name|isMinSignedValue
argument_list|()
specifier|const
block|;
comment|/// Return true if evaluation of this constant could trap. This is true for
comment|/// things like constant expressions that could divide by zero.
name|bool
name|canTrap
argument_list|()
specifier|const
block|;
comment|/// Return true if the value can vary between threads.
name|bool
name|isThreadDependent
argument_list|()
specifier|const
block|;
comment|/// Return true if the value is dependent on a dllimport variable.
name|bool
name|isDLLImportDependent
argument_list|()
specifier|const
block|;
comment|/// Return true if the constant has users other than constant expressions and
comment|/// other dangling things.
name|bool
name|isConstantUsed
argument_list|()
specifier|const
block|;
comment|/// This method classifies the entry according to whether or not it may
comment|/// generate a relocation entry.  This must be conservative, so if it might
comment|/// codegen to a relocatable entry, it should say so.
comment|///
comment|/// FIXME: This really should not be in IR.
name|bool
name|needsRelocation
argument_list|()
specifier|const
block|;
comment|/// For aggregates (struct/array/vector) return the constant that corresponds
comment|/// to the specified element if possible, or null if not. This can return null
comment|/// if the element index is a ConstantExpr, or if 'this' is a constant expr.
name|Constant
operator|*
name|getAggregateElement
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|;
name|Constant
operator|*
name|getAggregateElement
argument_list|(
argument|Constant *Elt
argument_list|)
specifier|const
block|;
comment|/// If this is a splat vector constant, meaning that all of the elements have
comment|/// the same value, return that value. Otherwise return 0.
name|Constant
operator|*
name|getSplatValue
argument_list|()
specifier|const
block|;
comment|/// If C is a constant integer then return its value, otherwise C must be a
comment|/// vector of constant integers, all equal, and the common value is returned.
specifier|const
name|APInt
operator|&
name|getUniqueInteger
argument_list|()
specifier|const
block|;
comment|/// Called if some element of this constant is no longer valid.
comment|/// At this point only other constants may be on the use_list for this
comment|/// constant.  Any constants on our Use list must also be destroy'd.  The
comment|/// implementation must be sure to remove the constant from the list of
comment|/// available cached constants.  Implementations should implement
comment|/// destroyConstantImpl to remove constants from any pools/maps they are
comment|/// contained it.
name|void
name|destroyConstant
argument_list|()
block|;
comment|//// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|>=
name|ConstantFirstVal
operator|&&
name|V
operator|->
name|getValueID
argument_list|()
operator|<=
name|ConstantLastVal
return|;
block|}
comment|/// This method is a special form of User::replaceUsesOfWith
comment|/// (which does not work on constants) that does work
comment|/// on constants.  Basically this method goes through the trouble of building
comment|/// a new constant that is equivalent to the current one, with all uses of
comment|/// From replaced with uses of To.  After this construction is completed, all
comment|/// of the users of 'this' are replaced to use the new constant, and then
comment|/// 'this' is deleted.  In general, you should not call this method, instead,
comment|/// use Value::replaceAllUsesWith, which automatically dispatches to this
comment|/// method as needed.
comment|///
name|void
name|handleOperandChange
argument_list|(
name|Value
operator|*
argument_list|,
name|Value
operator|*
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNullValue
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// @returns the value for an integer or vector of integer constant of the
comment|/// given type that has all its bits set to true.
comment|/// @brief Get the all ones value
specifier|static
name|Constant
operator|*
name|getAllOnesValue
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// Return the value for an integer or pointer constant, or a vector thereof,
comment|/// with the given scalar value.
specifier|static
name|Constant
operator|*
name|getIntegerValue
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|APInt
operator|&
name|V
argument_list|)
block|;
comment|/// If there are any dead constant users dangling off of this constant, remove
comment|/// them. This method is useful for clients that want to check to see if a
comment|/// global is unused, but don't want to deal with potentially dead constants
comment|/// hanging off of the globals.
name|void
name|removeDeadConstantUsers
argument_list|()
specifier|const
block|;
specifier|const
name|Constant
operator|*
name|stripPointerCasts
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Constant
operator|>
operator|(
name|Value
operator|::
name|stripPointerCasts
argument_list|()
operator|)
return|;
block|}
name|Constant
operator|*
name|stripPointerCasts
argument_list|()
block|{
return|return
name|const_cast
operator|<
name|Constant
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|Constant
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripPointerCasts
argument_list|()
operator|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_CONSTANT_H
end_comment

end_unit

