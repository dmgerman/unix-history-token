begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CallSite.h - Abstract Call& Invoke instrs ---------------*- C++ -*-===//
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
comment|// This file defines the CallSite class, which is a handy wrapper for code that
end_comment

begin_comment
comment|// wants to treat Call and Invoke instructions in a generic way. When in non-
end_comment

begin_comment
comment|// mutation context (e.g. an analysis) ImmutableCallSite should be used.
end_comment

begin_comment
comment|// Finally, when some degree of customization is necessary between these two
end_comment

begin_comment
comment|// extremes, CallSiteBase<> can be supplied with fine-tuned parameters.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: These classes are supposed to have "value semantics". So they should be
end_comment

begin_comment
comment|// passed by value, not by reference; they should not be "new"ed or "delete"d.
end_comment

begin_comment
comment|// They are efficiently copyable, assignable and constructable, with cost
end_comment

begin_comment
comment|// equivalent to copying a pointer (notice that they have only a single data
end_comment

begin_comment
comment|// member). The internal representation carries a flag which indicates which of
end_comment

begin_comment
comment|// the two variants is enclosed. This allows for cheaper checks when various
end_comment

begin_comment
comment|// accessors of CallSite are employed.
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
name|LLVM_IR_CALLSITE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_CALLSITE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstrTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Intrinsics.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

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
file|<cassert>
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
name|FunTy
operator|=
specifier|const
name|Function
operator|,
name|typename
name|BBTy
operator|=
specifier|const
name|BasicBlock
operator|,
name|typename
name|ValTy
operator|=
specifier|const
name|Value
operator|,
name|typename
name|UserTy
operator|=
specifier|const
name|User
operator|,
name|typename
name|UseTy
operator|=
specifier|const
name|Use
operator|,
name|typename
name|InstrTy
operator|=
specifier|const
name|Instruction
operator|,
name|typename
name|CallTy
operator|=
specifier|const
name|CallInst
operator|,
name|typename
name|InvokeTy
operator|=
specifier|const
name|InvokeInst
operator|,
name|typename
name|IterTy
operator|=
name|User
operator|::
name|const_op_iterator
operator|>
name|class
name|CallSiteBase
block|{
name|protected
operator|:
name|PointerIntPair
operator|<
name|InstrTy
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|I
block|;
name|CallSiteBase
argument_list|()
operator|:
name|I
argument_list|(
argument|nullptr
argument_list|,
argument|false
argument_list|)
block|{}
name|CallSiteBase
argument_list|(
name|CallTy
operator|*
name|CI
argument_list|)
operator|:
name|I
argument_list|(
argument|CI
argument_list|,
argument|true
argument_list|)
block|{
name|assert
argument_list|(
name|CI
argument_list|)
block|; }
name|CallSiteBase
argument_list|(
name|InvokeTy
operator|*
name|II
argument_list|)
operator|:
name|I
argument_list|(
argument|II
argument_list|,
argument|false
argument_list|)
block|{
name|assert
argument_list|(
name|II
argument_list|)
block|; }
name|explicit
name|CallSiteBase
argument_list|(
argument|ValTy *II
argument_list|)
block|{
operator|*
name|this
operator|=
name|get
argument_list|(
name|II
argument_list|)
block|; }
name|private
operator|:
comment|/// This static method is like a constructor. It will create an appropriate
comment|/// call site for a Call or Invoke instruction, but it can also create a null
comment|/// initialized CallSiteBase object for something which is NOT a call site.
specifier|static
name|CallSiteBase
name|get
argument_list|(
argument|ValTy *V
argument_list|)
block|{
if|if
condition|(
name|InstrTy
modifier|*
name|II
init|=
name|dyn_cast
operator|<
name|InstrTy
operator|>
operator|(
name|V
operator|)
condition|)
block|{
if|if
condition|(
name|II
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Call
condition|)
return|return
name|CallSiteBase
argument_list|(
name|static_cast
operator|<
name|CallTy
operator|*
operator|>
operator|(
name|II
operator|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|II
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Invoke
condition|)
return|return
name|CallSiteBase
argument_list|(
name|static_cast
operator|<
name|InvokeTy
operator|*
operator|>
operator|(
name|II
operator|)
argument_list|)
return|;
block|}
return|return
name|CallSiteBase
argument_list|()
return|;
block|}
name|public
operator|:
comment|/// Return true if a CallInst is enclosed. Note that !isCall() does not mean
comment|/// an InvokeInst is enclosed. It may also signify a NULL instruction pointer.
name|bool
name|isCall
argument_list|()
specifier|const
block|{
return|return
name|I
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// Return true if a InvokeInst is enclosed.
name|bool
name|isInvoke
argument_list|()
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|&&
operator|!
name|I
operator|.
name|getInt
argument_list|()
return|;
block|}
name|InstrTy
operator|*
name|getInstruction
argument_list|()
specifier|const
block|{
return|return
name|I
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|InstrTy
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|I
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|I
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// Get the basic block containing the call site.
name|BBTy
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|->
name|getParent
argument_list|()
return|;
block|}
comment|/// Return the pointer to function that is being called.
name|ValTy
operator|*
name|getCalledValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
block|;
return|return
operator|*
name|getCallee
argument_list|()
return|;
block|}
comment|/// Return the function being called if this is a direct call, otherwise
comment|/// return null (if it's an indirect call).
name|FunTy
operator|*
name|getCalledFunction
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|FunTy
operator|>
operator|(
name|getCalledValue
argument_list|()
operator|)
return|;
block|}
comment|/// Return true if the callsite is an indirect call.
name|bool
name|isIndirectCall
argument_list|()
specifier|const
block|{
name|Value
operator|*
name|V
operator|=
name|getCalledValue
argument_list|()
block|;
if|if
condition|(
operator|!
name|V
condition|)
return|return
name|false
return|;
if|if
condition|(
name|isa
operator|<
name|FunTy
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
condition|)
return|return
name|false
return|;
if|if
condition|(
name|CallInst
modifier|*
name|CI
init|=
name|dyn_cast
operator|<
name|CallInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|CI
operator|->
name|isInlineAsm
argument_list|()
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Set the callee to the specified value.
end_comment

begin_function
name|void
name|setCalledFunction
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
expr_stmt|;
operator|*
name|getCallee
argument_list|()
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Return the intrinsic ID of the intrinsic called by this CallSite,
end_comment

begin_comment
comment|/// or Intrinsic::not_intrinsic if the called function is not an
end_comment

begin_comment
comment|/// intrinsic, or if this CallSite is an indirect call.
end_comment

begin_expr_stmt
name|Intrinsic
operator|::
name|ID
name|getIntrinsicID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|F
operator|=
name|getCalledFunction
argument_list|()
condition|)
return|return
name|F
operator|->
name|getIntrinsicID
argument_list|()
return|;
end_expr_stmt

begin_comment
comment|// Don't use Intrinsic::not_intrinsic, as it will require pulling
end_comment

begin_comment
comment|// Intrinsics.h into every header that uses CallSite.
end_comment

begin_return
return|return
name|static_cast
operator|<
name|Intrinsic
operator|::
name|ID
operator|>
operator|(
literal|0
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// Determine whether the passed iterator points to the callee operand's Use.
end_comment

begin_macro
unit|bool
name|isCallee
argument_list|(
argument|Value::const_user_iterator UI
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|isCallee
argument_list|(
operator|&
name|UI
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Determine whether this Use is the callee operand's Use.
end_comment

begin_decl_stmt
name|bool
name|isCallee
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
return|return
name|getCallee
argument_list|()
operator|==
name|U
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed iterator points to an argument operand.
end_comment

begin_decl_stmt
name|bool
name|isArgOperand
argument_list|(
name|Value
operator|::
name|const_user_iterator
name|UI
argument_list|)
decl|const
block|{
return|return
name|isArgOperand
argument_list|(
operator|&
name|UI
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed use points to an argument operand.
end_comment

begin_decl_stmt
name|bool
name|isArgOperand
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|==
name|U
operator|->
name|getUser
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|arg_begin
argument_list|()
operator|<=
name|U
operator|&&
name|U
operator|<
name|arg_end
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed iterator points to a bundle operand.
end_comment

begin_decl_stmt
name|bool
name|isBundleOperand
argument_list|(
name|Value
operator|::
name|const_user_iterator
name|UI
argument_list|)
decl|const
block|{
return|return
name|isBundleOperand
argument_list|(
operator|&
name|UI
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed use points to a bundle operand.
end_comment

begin_decl_stmt
name|bool
name|isBundleOperand
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|==
name|U
operator|->
name|getUser
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasOperandBundles
argument_list|()
condition|)
return|return
name|false
return|;
name|unsigned
name|OperandNo
init|=
name|U
operator|-
operator|(
operator|*
name|this
operator|)
operator|->
name|op_begin
argument_list|()
decl_stmt|;
return|return
name|getBundleOperandsStartIndex
argument_list|()
operator|<=
name|OperandNo
operator|&&
name|OperandNo
operator|<
name|getBundleOperandsEndIndex
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed iterator points to a data operand.
end_comment

begin_decl_stmt
name|bool
name|isDataOperand
argument_list|(
name|Value
operator|::
name|const_user_iterator
name|UI
argument_list|)
decl|const
block|{
return|return
name|isDataOperand
argument_list|(
operator|&
name|UI
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether the passed use points to a data operand.
end_comment

begin_decl_stmt
name|bool
name|isDataOperand
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
return|return
name|data_operands_begin
argument_list|()
operator|<=
name|U
operator|&&
name|U
operator|<
name|data_operands_end
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|ValTy
modifier|*
name|getArgument
argument_list|(
name|unsigned
name|ArgNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|arg_begin
argument_list|()
operator|+
name|ArgNo
operator|<
name|arg_end
argument_list|()
operator|&&
literal|"Argument # out of range!"
argument_list|)
expr_stmt|;
return|return
operator|*
operator|(
name|arg_begin
argument_list|()
operator|+
name|ArgNo
operator|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setArgument
parameter_list|(
name|unsigned
name|ArgNo
parameter_list|,
name|Value
modifier|*
name|newVal
parameter_list|)
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|arg_begin
argument_list|()
operator|+
name|ArgNo
operator|<
name|arg_end
argument_list|()
operator|&&
literal|"Argument # out of range!"
argument_list|)
expr_stmt|;
name|getInstruction
argument_list|()
operator|->
name|setOperand
argument_list|(
name|ArgNo
argument_list|,
name|newVal
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Given a value use iterator, returns the argument that corresponds to it.
end_comment

begin_comment
comment|/// Iterator must actually correspond to an argument.
end_comment

begin_decl_stmt
name|unsigned
name|getArgumentNo
argument_list|(
name|Value
operator|::
name|const_user_iterator
name|I
argument_list|)
decl|const
block|{
return|return
name|getArgumentNo
argument_list|(
operator|&
name|I
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Given a use for an argument, get the argument number that corresponds to
end_comment

begin_comment
comment|/// it.
end_comment

begin_decl_stmt
name|unsigned
name|getArgumentNo
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|isArgOperand
argument_list|(
name|U
argument_list|)
operator|&&
literal|"Argument # out of range!"
argument_list|)
expr_stmt|;
return|return
name|U
operator|-
name|arg_begin
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// The type of iterator to use when looping over actual arguments at this
end_comment

begin_comment
comment|/// call site.
end_comment

begin_typedef
typedef|typedef
name|IterTy
name|arg_iterator
typedef|;
end_typedef

begin_expr_stmt
name|iterator_range
operator|<
name|IterTy
operator|>
name|args
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|arg_begin
argument_list|()
argument_list|,
name|arg_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|arg_empty
argument_list|()
specifier|const
block|{
return|return
name|arg_end
argument_list|()
operator|==
name|arg_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|arg_size
argument_list|()
specifier|const
block|{
return|return
name|unsigned
argument_list|(
name|arg_end
argument_list|()
operator|-
name|arg_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Given a value use iterator, return the data operand corresponding to it.
end_comment

begin_comment
comment|/// Iterator must actually correspond to a data operand.
end_comment

begin_decl_stmt
name|unsigned
name|getDataOperandNo
argument_list|(
name|Value
operator|::
name|const_user_iterator
name|UI
argument_list|)
decl|const
block|{
return|return
name|getDataOperandNo
argument_list|(
operator|&
name|UI
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Given a use for a data operand, get the data operand number that
end_comment

begin_comment
comment|/// corresponds to it.
end_comment

begin_decl_stmt
name|unsigned
name|getDataOperandNo
argument_list|(
specifier|const
name|Use
operator|*
name|U
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|isDataOperand
argument_list|(
name|U
argument_list|)
operator|&&
literal|"Data operand # out of range!"
argument_list|)
expr_stmt|;
return|return
name|U
operator|-
name|data_operands_begin
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Type of iterator to use when looping over data operands at this call site
end_comment

begin_comment
comment|/// (see below).
end_comment

begin_typedef
typedef|typedef
name|IterTy
name|data_operand_iterator
typedef|;
end_typedef

begin_comment
comment|/// data_operands_begin/data_operands_end - Return iterators iterating over
end_comment

begin_comment
comment|/// the call / invoke argument list and bundle operands.  For invokes, this is
end_comment

begin_comment
comment|/// the set of instruction operands except the invoke target and the two
end_comment

begin_comment
comment|/// successor blocks; and for calls this is the set of instruction operands
end_comment

begin_comment
comment|/// except the call target.
end_comment

begin_expr_stmt
name|IterTy
name|data_operands_begin
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
block|;
return|return
operator|(
operator|*
name|this
operator|)
operator|->
name|op_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|IterTy
name|data_operands_end
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
block|;
return|return
operator|(
operator|*
name|this
operator|)
operator|->
name|op_end
argument_list|()
operator|-
operator|(
name|isCall
argument_list|()
condition|?
literal|1
else|:
literal|3
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|IterTy
operator|>
name|data_ops
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|data_operands_begin
argument_list|()
argument_list|,
name|data_operands_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|data_operands_empty
argument_list|()
specifier|const
block|{
return|return
name|data_operands_end
argument_list|()
operator|==
name|data_operands_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|data_operands_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|data_operands_begin
argument_list|()
argument_list|,
name|data_operands_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the type of the instruction that generated this call site.
end_comment

begin_expr_stmt
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|->
name|getType
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the caller function for this call site.
end_comment

begin_expr_stmt
name|FunTy
operator|*
name|getCaller
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|->
name|getParent
argument_list|()
operator|->
name|getParent
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Tests if this call site must be tail call optimized. Only a CallInst can
end_comment

begin_comment
comment|/// be tail call optimized.
end_comment

begin_expr_stmt
name|bool
name|isMustTailCall
argument_list|()
specifier|const
block|{
return|return
name|isCall
argument_list|()
operator|&&
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
operator|->
name|isMustTailCall
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Tests if this call site is marked as a tail call.
end_comment

begin_expr_stmt
name|bool
name|isTailCall
argument_list|()
specifier|const
block|{
return|return
name|isCall
argument_list|()
operator|&&
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
operator|->
name|isTailCall
argument_list|()
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|CALLSITE_DELEGATE_GETTER
parameter_list|(
name|METHOD
parameter_list|)
define|\
value|InstrTy *II = getInstruction();    \   return isCall()                        \     ? cast<CallInst>(II)->METHOD         \     : cast<InvokeInst>(II)->METHOD
end_define

begin_define
define|#
directive|define
name|CALLSITE_DELEGATE_SETTER
parameter_list|(
name|METHOD
parameter_list|)
define|\
value|InstrTy *II = getInstruction();    \   if (isCall())                          \     cast<CallInst>(II)->METHOD;          \   else                                   \     cast<InvokeInst>(II)->METHOD
end_define

begin_expr_stmt
name|unsigned
name|getNumArgOperands
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getNumArgOperands
argument_list|()
argument_list|)
block|;   }
name|ValTy
operator|*
name|getArgOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getArgOperand
argument_list|(
name|i
argument_list|)
argument_list|)
block|;   }
name|ValTy
operator|*
name|getReturnedArgOperand
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getReturnedArgOperand
argument_list|()
argument_list|)
block|;   }
name|bool
name|isInlineAsm
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isCall
argument_list|()
condition|)
return|return
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
operator|->
name|isInlineAsm
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// Get the calling convention of the call.
end_comment

begin_expr_stmt
unit|CallingConv
operator|::
name|ID
name|getCallingConv
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getCallingConv
argument_list|()
argument_list|)
block|;   }
comment|/// Set the calling convention of the call.
name|void
name|setCallingConv
argument_list|(
argument|CallingConv::ID CC
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setCallingConv
argument_list|(
name|CC
argument_list|)
argument_list|)
block|;   }
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getFunctionType
argument_list|()
argument_list|)
block|;   }
name|void
name|mutateFunctionType
argument_list|(
argument|FunctionType *Ty
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|mutateFunctionType
argument_list|(
name|Ty
argument_list|)
argument_list|)
block|;   }
comment|/// Get the parameter attributes of the call.
name|AttributeList
name|getAttributes
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getAttributes
argument_list|()
argument_list|)
block|;   }
comment|/// Set the parameter attributes of the call.
name|void
name|setAttributes
argument_list|(
argument|AttributeList PAL
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setAttributes
argument_list|(
name|PAL
argument_list|)
argument_list|)
block|;   }
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|addAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|void
name|addAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute Attr
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|addAttribute
argument_list|(
name|i
argument_list|,
name|Attr
argument_list|)
argument_list|)
block|;   }
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|removeAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|void
name|removeAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|removeAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if this function has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|hasFnAttr
argument_list|(
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if this function has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|StringRef Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|hasFnAttr
argument_list|(
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if this return value has the given attribute.
name|bool
name|hasRetAttr
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|hasRetAttr
argument_list|(
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if the call or the callee has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|paramHasAttr
argument_list|(
name|ArgNo
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned i
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getAttribute
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if the data operand at index \p i directly or indirectly has
comment|/// the attribute \p A.
comment|///
comment|/// Normal call or invoke arguments have per operand attributes, as specified
comment|/// in the attribute set attached to this instruction, while operand bundle
comment|/// operands may have some attributes implied by the type of its containing
comment|/// operand bundle.
name|bool
name|dataOperandHasImpliedAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|dataOperandHasImpliedAttr
argument_list|(
name|i
argument_list|,
name|Kind
argument_list|)
argument_list|)
block|;   }
comment|/// Extract the alignment for a call or parameter (0=unknown).
name|uint16_t
name|getParamAlignment
argument_list|(
argument|uint16_t i
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getParamAlignment
argument_list|(
name|i
argument_list|)
argument_list|)
block|;   }
comment|/// Extract the number of dereferenceable bytes for a call or parameter
comment|/// (0=unknown).
name|uint64_t
name|getDereferenceableBytes
argument_list|(
argument|uint16_t i
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getDereferenceableBytes
argument_list|(
name|i
argument_list|)
argument_list|)
block|;   }
comment|/// Extract the number of dereferenceable_or_null bytes for a call or
comment|/// parameter (0=unknown).
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|(
argument|uint16_t i
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getDereferenceableOrNullBytes
argument_list|(
name|i
argument_list|)
argument_list|)
block|;   }
comment|/// Determine if the parameter or return value is marked with NoAlias
comment|/// attribute.
comment|/// @param n The parameter to check. 1 is the first parameter, 0 is the return
name|bool
name|doesNotAlias
argument_list|(
argument|unsigned n
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|doesNotAlias
argument_list|(
name|n
argument_list|)
argument_list|)
block|;   }
comment|/// Return true if the call should not be treated as a call to a builtin.
name|bool
name|isNoBuiltin
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|isNoBuiltin
argument_list|()
argument_list|)
block|;   }
comment|/// Return true if the call should not be inlined.
name|bool
name|isNoInline
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|isNoInline
argument_list|()
argument_list|)
block|;   }
name|void
name|setIsNoInline
argument_list|(
argument|bool Value = true
argument_list|)
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setIsNoInline
argument_list|(
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|doesNotAccessMemory
argument_list|()
argument_list|)
block|;   }
name|void
name|setDoesNotAccessMemory
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setDoesNotAccessMemory
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|onlyReadsMemory
argument_list|()
argument_list|)
block|;   }
name|void
name|setOnlyReadsMemory
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setOnlyReadsMemory
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call does not access or only writes memory.
name|bool
name|doesNotReadMemory
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|doesNotReadMemory
argument_list|()
argument_list|)
block|;   }
name|void
name|setDoesNotReadMemory
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setDoesNotReadMemory
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call can access memmory only using pointers based
comment|/// on its arguments.
name|bool
name|onlyAccessesArgMemory
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|onlyAccessesArgMemory
argument_list|()
argument_list|)
block|;   }
name|void
name|setOnlyAccessesArgMemory
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setOnlyAccessesArgMemory
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|doesNotReturn
argument_list|()
argument_list|)
block|;   }
name|void
name|setDoesNotReturn
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setDoesNotReturn
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|doesNotThrow
argument_list|()
argument_list|)
block|;   }
name|void
name|setDoesNotThrow
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setDoesNotThrow
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call can be duplicated.
name|bool
name|cannotDuplicate
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|cannotDuplicate
argument_list|()
argument_list|)
block|;   }
name|void
name|setCannotDuplicate
argument_list|()
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|setCannotDuplicate
argument_list|()
argument_list|)
block|;   }
comment|/// Determine if the call is convergent.
name|bool
name|isConvergent
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|isConvergent
argument_list|()
argument_list|)
block|;   }
name|void
name|setConvergent
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setConvergent
argument_list|()
argument_list|)
block|;   }
name|void
name|setNotConvergent
argument_list|()
block|{
name|CALLSITE_DELEGATE_SETTER
argument_list|(
name|setNotConvergent
argument_list|()
argument_list|)
block|;   }
name|unsigned
name|getNumOperandBundles
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getNumOperandBundles
argument_list|()
argument_list|)
block|;   }
name|bool
name|hasOperandBundles
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|hasOperandBundles
argument_list|()
argument_list|)
block|;   }
name|unsigned
name|getBundleOperandsStartIndex
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getBundleOperandsStartIndex
argument_list|()
argument_list|)
block|;   }
name|unsigned
name|getBundleOperandsEndIndex
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getBundleOperandsEndIndex
argument_list|()
argument_list|)
block|;   }
name|unsigned
name|getNumTotalBundleOperands
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getNumTotalBundleOperands
argument_list|()
argument_list|)
block|;   }
name|OperandBundleUse
name|getOperandBundleAt
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getOperandBundleAt
argument_list|(
name|Index
argument_list|)
argument_list|)
block|;   }
name|Optional
operator|<
name|OperandBundleUse
operator|>
name|getOperandBundle
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getOperandBundle
argument_list|(
name|Name
argument_list|)
argument_list|)
block|;   }
name|Optional
operator|<
name|OperandBundleUse
operator|>
name|getOperandBundle
argument_list|(
argument|uint32_t ID
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|getOperandBundle
argument_list|(
name|ID
argument_list|)
argument_list|)
block|;   }
name|unsigned
name|countOperandBundlesOfType
argument_list|(
argument|uint32_t ID
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|countOperandBundlesOfType
argument_list|(
name|ID
argument_list|)
argument_list|)
block|;   }
name|bool
name|isBundleOperand
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|isBundleOperand
argument_list|(
name|Idx
argument_list|)
argument_list|)
block|;   }
name|IterTy
name|arg_begin
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|arg_begin
argument_list|()
argument_list|)
block|;   }
name|IterTy
name|arg_end
argument_list|()
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|arg_end
argument_list|()
argument_list|)
block|;   }
undef|#
directive|undef
name|CALLSITE_DELEGATE_GETTER
undef|#
directive|undef
name|CALLSITE_DELEGATE_SETTER
name|void
name|getOperandBundlesAsDefs
argument_list|(
argument|SmallVectorImpl<OperandBundleDef>&Defs
argument_list|)
specifier|const
block|{
specifier|const
name|Instruction
operator|*
name|II
operator|=
name|getInstruction
argument_list|()
block|;
comment|// Since this is actually a getter that "looks like" a setter, don't use the
comment|// above macros to avoid confusion.
if|if
condition|(
name|isCall
argument_list|()
condition|)
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|II
operator|)
operator|->
name|getOperandBundlesAsDefs
argument_list|(
name|Defs
argument_list|)
expr_stmt|;
else|else
name|cast
operator|<
name|InvokeInst
operator|>
operator|(
name|II
operator|)
operator|->
name|getOperandBundlesAsDefs
argument_list|(
name|Defs
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// Determine whether this data operand is not captured.
end_comment

begin_decl_stmt
name|bool
name|doesNotCapture
argument_list|(
name|unsigned
name|OpNo
argument_list|)
decl|const
block|{
return|return
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|NoCapture
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether this argument is passed by value.
end_comment

begin_decl_stmt
name|bool
name|isByValArgument
argument_list|(
name|unsigned
name|ArgNo
argument_list|)
decl|const
block|{
return|return
name|paramHasAttr
argument_list|(
name|ArgNo
argument_list|,
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether this argument is passed in an alloca.
end_comment

begin_decl_stmt
name|bool
name|isInAllocaArgument
argument_list|(
name|unsigned
name|ArgNo
argument_list|)
decl|const
block|{
return|return
name|paramHasAttr
argument_list|(
name|ArgNo
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine whether this argument is passed by value or in an alloca.
end_comment

begin_decl_stmt
name|bool
name|isByValOrInAllocaArgument
argument_list|(
name|unsigned
name|ArgNo
argument_list|)
decl|const
block|{
return|return
name|paramHasAttr
argument_list|(
name|ArgNo
argument_list|,
name|Attribute
operator|::
name|ByVal
argument_list|)
operator|||
name|paramHasAttr
argument_list|(
name|ArgNo
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Determine if there are is an inalloca argument. Only the last argument can
end_comment

begin_comment
comment|/// have the inalloca attribute.
end_comment

begin_expr_stmt
name|bool
name|hasInAllocaArgument
argument_list|()
specifier|const
block|{
return|return
operator|!
name|arg_empty
argument_list|()
operator|&&
name|paramHasAttr
argument_list|(
name|arg_size
argument_list|()
operator|-
literal|1
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|doesNotAccessMemory
argument_list|(
name|unsigned
name|OpNo
argument_list|)
decl|const
block|{
return|return
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|onlyReadsMemory
argument_list|(
name|unsigned
name|OpNo
argument_list|)
decl|const
block|{
return|return
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
operator|||
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|doesNotReadMemory
argument_list|(
name|unsigned
name|OpNo
argument_list|)
decl|const
block|{
return|return
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|WriteOnly
argument_list|)
operator|||
name|dataOperandHasImpliedAttr
argument_list|(
name|OpNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return true if the return value is known to be not null.
end_comment

begin_comment
comment|/// This may be because it has the nonnull attribute, or because at least
end_comment

begin_comment
comment|/// one byte is dereferenceable and the pointer is in addrspace(0).
end_comment

begin_expr_stmt
name|bool
name|isReturnNonNull
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasRetAttr
argument_list|(
name|Attribute
operator|::
name|NonNull
argument_list|)
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|getDereferenceableBytes
argument_list|(
literal|0
argument_list|)
operator|>
literal|0
operator|&&
name|getType
argument_list|()
operator|->
name|getPointerAddressSpace
argument_list|()
operator|==
literal|0
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// Returns true if this CallSite passes the given Value* as an argument to
end_comment

begin_comment
comment|/// the called function.
end_comment

begin_macro
unit|bool
name|hasArgument
argument_list|(
argument|const Value *Arg
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
for|for
control|(
name|arg_iterator
name|AI
init|=
name|this
operator|->
name|arg_begin
argument_list|()
init|,
name|E
init|=
name|this
operator|->
name|arg_end
argument_list|()
init|;
name|AI
operator|!=
name|E
condition|;
operator|++
name|AI
control|)
if|if
condition|(
name|AI
operator|->
name|get
argument_list|()
operator|==
name|Arg
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}  private:
name|IterTy
name|getCallee
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isCall
argument_list|()
condition|)
comment|// Skip Callee
return|return
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
operator|->
name|op_end
argument_list|()
operator|-
literal|1
return|;
else|else
comment|// Skip BB, BB, Callee
return|return
name|cast
operator|<
name|InvokeInst
operator|>
operator|(
name|getInstruction
argument_list|()
operator|)
operator|->
name|op_end
argument_list|()
operator|-
literal|3
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|CallSite
range|:
name|public
name|CallSiteBase
operator|<
name|Function
decl_stmt|,
name|BasicBlock
decl_stmt|,
name|Value
decl_stmt|,
name|User
decl_stmt|,
name|Use
decl_stmt|,
name|Instruction
decl_stmt|,
name|CallInst
decl_stmt|,
name|InvokeInst
decl_stmt|,
name|User
decl|::
name|op_iterator
decl|>
block|{
name|public
label|:
name|CallSite
argument_list|()
operator|=
expr|default
expr_stmt|;
name|CallSite
argument_list|(
argument|CallSiteBase B
argument_list|)
block|:
name|CallSiteBase
argument_list|(
argument|B
argument_list|)
block|{}
name|CallSite
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|CI
argument_list|)
block|{}
name|CallSite
argument_list|(
name|InvokeInst
operator|*
name|II
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|II
argument_list|)
block|{}
name|explicit
name|CallSite
argument_list|(
name|Instruction
operator|*
name|II
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|II
argument_list|)
block|{}
name|explicit
name|CallSite
argument_list|(
name|Value
operator|*
name|V
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|V
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CallSite
operator|&
name|CS
operator|)
specifier|const
block|{
return|return
name|I
operator|==
name|CS
operator|.
name|I
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CallSite
operator|&
name|CS
operator|)
specifier|const
block|{
return|return
name|I
operator|!=
name|CS
operator|.
name|I
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CallSite
operator|&
name|CS
operator|)
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|<
name|CS
operator|.
name|getInstruction
argument_list|()
return|;
block|}
name|private
label|:
name|friend
block|struct
name|DenseMapInfo
operator|<
name|CallSite
operator|>
expr_stmt|;
name|User
operator|::
name|op_iterator
name|getCallee
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|CallSite
operator|>
block|{
name|using
name|BaseInfo
operator|=
name|DenseMapInfo
operator|<
name|decltype
argument_list|(
name|CallSite
operator|::
name|I
argument_list|)
operator|>
block|;
specifier|static
name|CallSite
name|getEmptyKey
argument_list|()
block|{
name|CallSite
name|CS
block|;
name|CS
operator|.
name|I
operator|=
name|BaseInfo
operator|::
name|getEmptyKey
argument_list|()
block|;
return|return
name|CS
return|;
block|}
specifier|static
name|CallSite
name|getTombstoneKey
argument_list|()
block|{
name|CallSite
name|CS
block|;
name|CS
operator|.
name|I
operator|=
name|BaseInfo
operator|::
name|getTombstoneKey
argument_list|()
block|;
return|return
name|CS
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|CallSite
modifier|&
name|CS
parameter_list|)
block|{
return|return
name|BaseInfo
operator|::
name|getHashValue
argument_list|(
name|CS
operator|.
name|I
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|CallSite
modifier|&
name|LHS
parameter_list|,
specifier|const
name|CallSite
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
end_function

begin_comment
unit|};
comment|/// Establish a view to a call site for examination.
end_comment

begin_decl_stmt
name|class
name|ImmutableCallSite
range|:
name|public
name|CallSiteBase
operator|<
operator|>
block|{
name|public
operator|:
name|ImmutableCallSite
argument_list|()
operator|=
expr|default
block|;
name|ImmutableCallSite
argument_list|(
specifier|const
name|CallInst
operator|*
name|CI
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|CI
argument_list|)
block|{}
name|ImmutableCallSite
argument_list|(
specifier|const
name|InvokeInst
operator|*
name|II
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|II
argument_list|)
block|{}
name|explicit
name|ImmutableCallSite
argument_list|(
specifier|const
name|Instruction
operator|*
name|II
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|II
argument_list|)
block|{}
name|explicit
name|ImmutableCallSite
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|V
argument_list|)
block|{}
name|ImmutableCallSite
argument_list|(
argument|CallSite CS
argument_list|)
operator|:
name|CallSiteBase
argument_list|(
argument|CS.getInstruction()
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_CALLSITE_H
end_comment

end_unit

