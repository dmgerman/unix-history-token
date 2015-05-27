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
file|"llvm/IR/Instructions.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallInst
decl_stmt|;
name|class
name|InvokeInst
decl_stmt|;
name|template
operator|<
name|typename
name|FunTy
operator|=
specifier|const
name|Function
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
comment|/// CallSiteBase::get - This static method is sort of like a constructor.  It
comment|/// will create an appropriate call site for a Call or Invoke instruction, but
comment|/// it can also create a null initialized CallSiteBase object for something
comment|/// which is NOT a call site.
comment|///
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
comment|/// isCall - true if a CallInst is enclosed.
comment|/// Note that !isCall() does not mean it is an InvokeInst enclosed,
comment|/// it also could signify a NULL Instruction pointer.
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
comment|/// isInvoke - true if a InvokeInst is enclosed.
comment|///
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
comment|/// getCalledValue - Return the pointer to function that is being called.
comment|///
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
comment|/// getCalledFunction - Return the function being called if this is a direct
comment|/// call, otherwise return null (if it's an indirect call).
comment|///
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
comment|/// setCalledFunction - Set the callee to the specified value.
comment|///
name|void
name|setCalledFunction
argument_list|(
argument|Value *V
argument_list|)
block|{
name|assert
argument_list|(
name|getInstruction
argument_list|()
operator|&&
literal|"Not a call or invoke instruction!"
argument_list|)
block|;
operator|*
name|getCallee
argument_list|()
operator|=
name|V
block|;   }
comment|/// isCallee - Determine whether the passed iterator points to the
comment|/// callee operand's Use.
name|bool
name|isCallee
argument_list|(
argument|Value::const_user_iterator UI
argument_list|)
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
comment|/// Determine whether this Use is the callee operand's Use.
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
comment|/// Given a value use iterator, returns the argument that corresponds to it.
comment|/// Iterator must actually correspond to an argument.
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
comment|/// Given a use for an argument, get the argument number that corresponds to
comment|/// it.
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
name|arg_begin
argument_list|()
operator|<=
name|U
operator|&&
name|U
operator|<
name|arg_end
argument_list|()
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
comment|/// arg_iterator - The type of iterator to use when looping over actual
comment|/// arguments at this call site.
typedef|typedef
name|IterTy
name|arg_iterator
typedef|;
comment|/// arg_begin/arg_end - Return iterators corresponding to the actual argument
comment|/// list for a call site.
name|IterTy
name|arg_begin
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
comment|// Skip non-arguments
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
name|IterTy
name|arg_end
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|)
operator|->
name|op_end
argument_list|()
operator|-
name|getArgumentEndOffset
argument_list|()
return|;
block|}
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
comment|/// getType - Return the type of the instruction that generated this call site
comment|///
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
comment|/// getCaller - Return the caller function for this call site
comment|///
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
comment|/// \brief Tests if this call site must be tail call optimized.  Only a
comment|/// CallInst can be tail call optimized.
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
comment|/// \brief Tests if this call site is marked as a tail call.
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
define|#
directive|define
name|CALLSITE_DELEGATE_GETTER
parameter_list|(
name|METHOD
parameter_list|)
define|\
value|InstrTy *II = getInstruction();    \   return isCall()                        \     ? cast<CallInst>(II)->METHOD         \     : cast<InvokeInst>(II)->METHOD
define|#
directive|define
name|CALLSITE_DELEGATE_SETTER
parameter_list|(
name|METHOD
parameter_list|)
define|\
value|InstrTy *II = getInstruction();    \   if (isCall())                          \     cast<CallInst>(II)->METHOD;          \   else                                   \     cast<InvokeInst>(II)->METHOD
comment|/// getCallingConv/setCallingConv - get or set the calling convention of the
comment|/// call.
name|CallingConv
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
comment|/// getAttributes/setAttributes - get or set the parameter attributes of
comment|/// the call.
specifier|const
name|AttributeSet
operator|&
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
name|void
name|setAttributes
argument_list|(
argument|const AttributeSet&PAL
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
comment|/// \brief Return true if this function has the given attribute.
name|bool
name|hasFnAttr
argument_list|(
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|hasFnAttr
argument_list|(
name|A
argument_list|)
argument_list|)
block|;   }
comment|/// \brief Return true if the call or the callee has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
argument|unsigned i
argument_list|,
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
name|CALLSITE_DELEGATE_GETTER
argument_list|(
name|paramHasAttr
argument_list|(
name|i
argument_list|,
name|A
argument_list|)
argument_list|)
block|;   }
comment|/// @brief Extract the alignment for a call or parameter (0=unknown).
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
comment|/// @brief Extract the number of dereferenceable bytes for a call or
comment|/// parameter (0=unknown).
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
comment|/// @brief Extract the number of dereferenceable_or_null bytes for a call or
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
comment|/// \brief Return true if the call should not be treated as a call to a
comment|/// builtin.
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
comment|/// @brief Return true if the call should not be inlined.
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
comment|/// @brief Determine if the call does not access memory.
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
comment|/// @brief Determine if the call does not access or only reads memory.
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
comment|/// @brief Determine if the call cannot return.
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
comment|/// @brief Determine if the call cannot unwind.
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
undef|#
directive|undef
name|CALLSITE_DELEGATE_GETTER
undef|#
directive|undef
name|CALLSITE_DELEGATE_SETTER
comment|/// @brief Determine whether this argument is not captured.
name|bool
name|doesNotCapture
argument_list|(
argument|unsigned ArgNo
argument_list|)
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
name|ArgNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|NoCapture
argument_list|)
return|;
block|}
comment|/// @brief Determine whether this argument is passed by value.
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
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ByVal
argument_list|)
return|;
block|}
comment|/// @brief Determine whether this argument is passed in an alloca.
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
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
comment|/// @brief Determine whether this argument is passed by value or in an alloca.
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
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ByVal
argument_list|)
operator|||
name|paramHasAttr
argument_list|(
name|ArgNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
comment|/// @brief Determine if there are is an inalloca argument.  Only the last
comment|/// argument can have the inalloca attribute.
name|bool
name|hasInAllocaArgument
argument_list|()
specifier|const
block|{
return|return
name|paramHasAttr
argument_list|(
name|arg_size
argument_list|()
argument_list|,
name|Attribute
operator|::
name|InAlloca
argument_list|)
return|;
block|}
name|bool
name|doesNotAccessMemory
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
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
name|bool
name|onlyReadsMemory
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
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadOnly
argument_list|)
operator|||
name|paramHasAttr
argument_list|(
name|ArgNo
operator|+
literal|1
argument_list|,
name|Attribute
operator|::
name|ReadNone
argument_list|)
return|;
block|}
comment|/// @brief Return true if the return value is known to be not null.
comment|/// This may be because it has the nonnull attribute, or because at least
comment|/// one byte is dereferenceable and the pointer is in addrspace(0).
name|bool
name|isReturnNonNull
argument_list|()
specifier|const
block|{
if|if
condition|(
name|paramHasAttr
argument_list|(
literal|0
argument_list|,
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
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// hasArgument - Returns true if this CallSite passes the given Value* as an
end_comment

begin_comment
comment|/// argument to the called function.
end_comment

begin_decl_stmt
name|bool
name|hasArgument
argument_list|(
specifier|const
name|Value
operator|*
name|Arg
argument_list|)
decl|const
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
return|return
name|false
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|unsigned
name|getArgumentEndOffset
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isCall
argument_list|()
condition|)
return|return
literal|1
return|;
comment|// Skip Callee
else|else
return|return
literal|3
return|;
comment|// Skip BB, BB, Callee
block|}
end_expr_stmt

begin_expr_stmt
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
name|Value
decl_stmt|,
name|User
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
block|{}
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

begin_comment
comment|/// ImmutableCallSite - establish a view to a call site for examination
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
block|{}
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

