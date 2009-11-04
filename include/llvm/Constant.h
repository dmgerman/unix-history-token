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
name|LLVM_CONSTANT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CONSTANT_H
end_define

begin_include
include|#
directive|include
file|"llvm/User.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|LLVMContext
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
name|void
name|operator
operator|=
operator|(
specifier|const
name|Constant
operator|&
operator|)
block|;
comment|// Do not implement
name|Constant
argument_list|(
specifier|const
name|Constant
operator|&
argument_list|)
block|;
comment|// Do not implement
name|protected
operator|:
name|Constant
argument_list|(
argument|const Type *ty
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
name|void
name|destroyConstantImpl
argument_list|()
block|;
name|void
name|setOperand
argument_list|(
argument|unsigned i
argument_list|,
argument|Value *V
argument_list|)
block|{
name|User
operator|::
name|setOperand
argument_list|(
name|i
argument_list|,
name|V
argument_list|)
block|;   }
name|public
operator|:
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// isNegativeZeroValue - Return true if the value is what would be returned
comment|/// by getZeroValueForNegation.
name|virtual
name|bool
name|isNegativeZeroValue
argument_list|()
specifier|const
block|{
return|return
name|isNullValue
argument_list|()
return|;
block|}
comment|/// canTrap - Return true if evaluation of this constant could trap.  This is
comment|/// true for things like constant expressions that could divide by zero.
name|bool
name|canTrap
argument_list|()
specifier|const
block|;
comment|/// isConstantUsed - Return true if the constant has users other than constant
comment|/// exprs and other dangling things.
name|bool
name|isConstantUsed
argument_list|()
specifier|const
block|;      enum
name|PossibleRelocationsTy
block|{
name|NoRelocation
operator|=
literal|0
block|,
name|LocalRelocation
operator|=
literal|1
block|,
name|GlobalRelocations
operator|=
literal|2
block|}
block|;
comment|/// getRelocationInfo - This method classifies the entry according to
comment|/// whether or not it may generate a relocation entry.  This must be
comment|/// conservative, so if it might codegen to a relocatable entry, it should say
comment|/// so.  The return values are:
comment|///
comment|///  NoRelocation: This constant pool entry is guaranteed to never have a
comment|///     relocation applied to it (because it holds a simple constant like
comment|///     '4').
comment|///  LocalRelocation: This entry has relocations, but the entries are
comment|///     guaranteed to be resolvable by the static linker, so the dynamic
comment|///     linker will never see them.
comment|///  GlobalRelocations: This entry may have arbitrary relocations.
comment|///
comment|/// FIXME: This really should not be in VMCore.
name|PossibleRelocationsTy
name|getRelocationInfo
argument_list|()
specifier|const
block|;
comment|// Specialize get/setOperand for Users as their operands are always
comment|// constants or BasicBlocks as well.
name|User
operator|*
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|User
operator|*
operator|>
operator|(
name|User
operator|::
name|getOperand
argument_list|(
name|i
argument_list|)
operator|)
return|;
block|}
specifier|const
name|User
operator|*
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|User
operator|*
operator|>
operator|(
name|User
operator|::
name|getOperand
argument_list|(
name|i
argument_list|)
operator|)
return|;
block|}
comment|/// getVectorElements - This method, which is only valid on constant of vector
comment|/// type, returns the elements of the vector in the specified smallvector.
comment|/// This handles breaking down a vector undef into undef elements, etc.  For
comment|/// constant exprs and other cases we can't handle, we return an empty vector.
name|void
name|getVectorElements
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|SmallVectorImpl<Constant*>&Elts
argument_list|)
specifier|const
block|;
comment|/// destroyConstant - Called if some element of this constant is no longer
comment|/// valid.  At this point only other constants may be on the use_list for this
comment|/// constant.  Any constants on our Use list must also be destroy'd.  The
comment|/// implementation must be sure to remove the constant from the list of
comment|/// available cached constants.  Implementations should call
comment|/// destroyConstantImpl as the last thing they do, to destroy all users and
comment|/// delete this.
name|virtual
name|void
name|destroyConstant
argument_list|()
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Not reached!"
argument_list|)
block|; }
comment|//// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Constant *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const GlobalValue *
argument_list|)
block|{
return|return
name|true
return|;
block|}
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
comment|/// replaceUsesOfWithOnConstant - This method is a special form of
comment|/// User::replaceUsesOfWith (which does not work on constants) that does work
comment|/// on constants.  Basically this method goes through the trouble of building
comment|/// a new constant that is equivalent to the current one, with all uses of
comment|/// From replaced with uses of To.  After this construction is completed, all
comment|/// of the users of 'this' are replaced to use the new constant, and then
comment|/// 'this' is deleted.  In general, you should not call this method, instead,
comment|/// use Value::replaceAllUsesWith, which automatically dispatches to this
comment|/// method as needed.
comment|///
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
argument|Value *
argument_list|,
argument|Value *
argument_list|,
argument|Use *
argument_list|)
block|{
comment|// Provide a default implementation for constants (like integers) that
comment|// cannot use any other values.  This cannot be called at runtime, but needs
comment|// to be here to avoid link errors.
name|assert
argument_list|(
name|getNumOperands
argument_list|()
operator|==
literal|0
operator|&&
literal|"replaceUsesOfWithOnConstant must be "
literal|"implemented for all constants that have operands!"
argument_list|)
block|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"Constants that do not have operands cannot be using 'From'!"
argument_list|)
block|;   }
specifier|static
name|Constant
operator|*
name|getNullValue
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// @returns the value for an integer constant of the given type that has all
comment|/// its bits set to true.
comment|/// @brief Get the all ones value
specifier|static
name|Constant
operator|*
name|getAllOnesValue
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getIntegerValue - Return the value for an integer or pointer constant,
comment|/// or a vector thereof, with the given scalar value.
specifier|static
name|Constant
operator|*
name|getIntegerValue
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|APInt
operator|&
name|V
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

