begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/OperandTraits.h - OperandTraits class definition ---*- C++ -*-===//
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
comment|// This file defines the traits classes that are handy for enforcing the correct
end_comment

begin_comment
comment|// layout of various User subclasses. It also provides the means for accessing
end_comment

begin_comment
comment|// the operands in the most efficient manner.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_OPERAND_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPERAND_TRAITS_H
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
comment|//===----------------------------------------------------------------------===//
comment|//                          FixedNumOperands Trait Class
comment|//===----------------------------------------------------------------------===//
comment|/// FixedNumOperandTraits - determine the allocation regime of the Use array
comment|/// when it is a prefix to the User object, and the number of Use objects is
comment|/// known at compile time.
name|template
operator|<
name|unsigned
name|ARITY
operator|>
expr|struct
name|FixedNumOperandTraits
block|{
specifier|static
name|Use
operator|*
name|op_begin
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|>
operator|(
name|U
operator|)
operator|-
name|ARITY
return|;
block|}
specifier|static
name|Use
operator|*
name|op_end
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|>
operator|(
name|U
operator|)
return|;
block|}
specifier|static
name|unsigned
name|operands
argument_list|(
argument|const User*
argument_list|)
block|{
return|return
name|ARITY
return|;
block|}
expr|struct
name|prefix
block|{
name|Use
name|Ops
index|[
name|ARITY
index|]
block|;
name|prefix
argument_list|()
block|;
comment|// DO NOT IMPLEMENT
block|}
block|;
name|template
operator|<
name|class
name|U
operator|>
expr|struct
name|Layout
block|{     struct
name|overlay
operator|:
name|public
name|prefix
block|,
name|public
name|U
block|{
name|overlay
argument_list|()
block|;
comment|// DO NOT IMPLEMENT
block|}
block|;   }
block|; }
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                          OptionalOperands Trait Class
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|unsigned
name|ARITY
operator|=
literal|1
operator|>
expr|struct
name|OptionalOperandTraits
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|ARITY
operator|>
block|{
specifier|static
name|unsigned
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                          VariadicOperand Trait Class
comment|//===----------------------------------------------------------------------===//
comment|/// VariadicOperandTraits - determine the allocation regime of the Use array
comment|/// when it is a prefix to the User object, and the number of Use objects is
comment|/// only known at allocation time.
name|template
operator|<
name|unsigned
name|MINARITY
operator|=
literal|0
operator|>
expr|struct
name|VariadicOperandTraits
block|{
specifier|static
name|Use
operator|*
name|op_begin
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|>
operator|(
name|U
operator|)
operator|-
name|U
operator|->
name|getNumOperands
argument_list|()
return|;
block|}
specifier|static
name|Use
operator|*
name|op_end
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Use
operator|*
operator|>
operator|(
name|U
operator|)
return|;
block|}
specifier|static
name|unsigned
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|//                          HungoffOperand Trait Class
comment|//===----------------------------------------------------------------------===//
comment|/// HungoffOperandTraits - determine the allocation regime of the Use array
comment|/// when it is not a prefix to the User object, but allocated at an unrelated
comment|/// heap address.
comment|/// Assumes that the User subclass that is determined by this traits class
comment|/// has an OperandList member of type User::op_iterator. [Note: this is now
comment|/// trivially satisfied, because User has that member for historic reasons.]
comment|///
comment|/// This is the traits class that is needed when the Use array must be
comment|/// resizable.
name|template
operator|<
name|unsigned
name|MINARITY
operator|=
literal|1
operator|>
expr|struct
name|HungoffOperandTraits
block|{
specifier|static
name|Use
operator|*
name|op_begin
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|U
operator|->
name|OperandList
return|;
block|}
specifier|static
name|Use
operator|*
name|op_end
argument_list|(
argument|User* U
argument_list|)
block|{
return|return
name|U
operator|->
name|OperandList
operator|+
name|U
operator|->
name|getNumOperands
argument_list|()
return|;
block|}
specifier|static
name|unsigned
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
expr|}
block|;
comment|/// Macro for generating in-class operand accessor declarations.
comment|/// It should only be called in the public section of the interface.
comment|///
define|#
directive|define
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
parameter_list|(
name|VALUECLASS
parameter_list|)
define|\
value|public: \   inline VALUECLASS *getOperand(unsigned) const; \   inline void setOperand(unsigned, VALUECLASS*); \   inline op_iterator op_begin(); \   inline const_op_iterator op_begin() const; \   inline op_iterator op_end(); \   inline const_op_iterator op_end() const; \   protected: \   template<int> inline Use&Op(); \   template<int> inline const Use&Op() const; \   public: \   inline unsigned getNumOperands() const
comment|/// Macro for generating out-of-class operand accessor definitions
define|#
directive|define
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
parameter_list|(
name|CLASS
parameter_list|,
name|VALUECLASS
parameter_list|)
define|\
value|CLASS::op_iterator CLASS::op_begin() { \   return OperandTraits<CLASS>::op_begin(this); \ } \ CLASS::const_op_iterator CLASS::op_begin() const { \   return OperandTraits<CLASS>::op_begin(const_cast<CLASS*>(this)); \ } \ CLASS::op_iterator CLASS::op_end() { \   return OperandTraits<CLASS>::op_end(this); \ } \ CLASS::const_op_iterator CLASS::op_end() const { \   return OperandTraits<CLASS>::op_end(const_cast<CLASS*>(this)); \ } \ VALUECLASS *CLASS::getOperand(unsigned i_nocapture) const { \   assert(i_nocapture< OperandTraits<CLASS>::operands(this) \&& "getOperand() out of range!"); \   return static_cast<VALUECLASS*>( \     OperandTraits<CLASS>::op_begin(const_cast<CLASS*>(this))[i_nocapture]); \ } \ void CLASS::setOperand(unsigned i_nocapture, VALUECLASS *Val_nocapture) { \   assert(i_nocapture< OperandTraits<CLASS>::operands(this) \&& "setOperand() out of range!"); \   OperandTraits<CLASS>::op_begin(this)[i_nocapture] = Val_nocapture; \ } \ unsigned CLASS::getNumOperands() const { \   return OperandTraits<CLASS>::operands(this);  \ } \ template<int Idx_nocapture> Use&CLASS::Op() { \   return this->OpFrom<Idx_nocapture>(this); \ } \ template<int Idx_nocapture> const Use&CLASS::Op() const { \   return this->OpFrom<Idx_nocapture>(this); \ }
comment|/// Macro for generating out-of-class operand accessor
comment|/// definitions with casted result
define|#
directive|define
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
parameter_list|(
name|CLASS
parameter_list|,
name|VALUECLASS
parameter_list|)
define|\
value|CLASS::op_iterator CLASS::op_begin() { \   return OperandTraits<CLASS>::op_begin(this); \ } \ CLASS::const_op_iterator CLASS::op_begin() const { \   return OperandTraits<CLASS>::op_begin(const_cast<CLASS*>(this)); \ } \ CLASS::op_iterator CLASS::op_end() { \   return OperandTraits<CLASS>::op_end(this); \ } \ CLASS::const_op_iterator CLASS::op_end() const { \   return OperandTraits<CLASS>::op_end(const_cast<CLASS*>(this)); \ } \ VALUECLASS *CLASS::getOperand(unsigned i_nocapture) const { \   assert(i_nocapture< OperandTraits<CLASS>::operands(this) \&& "getOperand() out of range!"); \   return cast<VALUECLASS>( \     OperandTraits<CLASS>::op_begin(const_cast<CLASS*>(this))[i_nocapture]); \ } \ void CLASS::setOperand(unsigned i_nocapture, VALUECLASS *Val_nocapture) { \   assert(i_nocapture< OperandTraits<CLASS>::operands(this) \&& "setOperand() out of range!"); \   OperandTraits<CLASS>::op_begin(this)[i_nocapture] = Val_nocapture; \ } \ unsigned CLASS::getNumOperands() const { \   return OperandTraits<CLASS>::operands(this); \ } \ template<int Idx_nocapture> Use&CLASS::Op() { \   return this->OpFrom<Idx_nocapture>(this); \ } \ template<int Idx_nocapture> const Use&CLASS::Op() const { \   return this->OpFrom<Idx_nocapture>(this); \ }
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

