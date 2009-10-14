begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/CallSite.h - Abstract Call& Invoke instrs -*- C++ -*-===//
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
comment|// wants to treat Call and Invoke instructions in a generic way.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: This class is supposed to have "value semantics". So it should be
end_comment

begin_comment
comment|// passed by value, not by reference; it should not be "new"ed or "delete"d. It
end_comment

begin_comment
comment|// is efficiently copyable, assignable and constructable, with cost equivalent
end_comment

begin_comment
comment|// to copying a pointer (notice that it has only a single data member).
end_comment

begin_comment
comment|// The internal representation carries a flag which indicates which of the two
end_comment

begin_comment
comment|// variants is enclosed. This allows for cheaper checks when various accessors
end_comment

begin_comment
comment|// of CallSite are employed.
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
name|LLVM_SUPPORT_CALLSITE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CALLSITE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Instruction.h"
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
name|class
name|CallSite
block|{
name|PointerIntPair
operator|<
name|Instruction
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|I
expr_stmt|;
name|public
label|:
name|CallSite
argument_list|()
operator|:
name|I
argument_list|(
literal|0
argument_list|,
argument|false
argument_list|)
block|{}
name|CallSite
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
operator|:
name|I
argument_list|(
argument|reinterpret_cast<Instruction*>(CI)
argument_list|,
argument|true
argument_list|)
block|{}
name|CallSite
argument_list|(
name|InvokeInst
operator|*
name|II
argument_list|)
operator|:
name|I
argument_list|(
argument|reinterpret_cast<Instruction*>(II)
argument_list|,
argument|false
argument_list|)
block|{}
name|CallSite
argument_list|(
name|Instruction
operator|*
name|C
argument_list|)
expr_stmt|;
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
comment|/// CallSite::get - This static method is sort of like a constructor.  It will
comment|/// create an appropriate call site for a Call or Invoke instruction, but it
comment|/// can also create a null initialized CallSite object for something which is
comment|/// NOT a call site.
comment|///
specifier|static
name|CallSite
name|get
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
if|if
condition|(
name|Instruction
modifier|*
name|I
init|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|V
operator|)
condition|)
block|{
if|if
condition|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Call
condition|)
return|return
name|CallSite
argument_list|(
name|reinterpret_cast
operator|<
name|CallInst
operator|*
operator|>
operator|(
name|I
operator|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|I
operator|->
name|getOpcode
argument_list|()
operator|==
name|Instruction
operator|::
name|Invoke
condition|)
return|return
name|CallSite
argument_list|(
name|reinterpret_cast
operator|<
name|InvokeInst
operator|*
operator|>
operator|(
name|I
operator|)
argument_list|)
return|;
block|}
return|return
name|CallSite
argument_list|()
return|;
block|}
comment|/// getCallingConv/setCallingConv - get or set the calling convention of the
comment|/// call.
name|CallingConv
operator|::
name|ID
name|getCallingConv
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCallingConv
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl_stmt|;
comment|/// getAttributes/setAttributes - get or set the parameter attributes of
comment|/// the call.
specifier|const
name|AttrListPtr
operator|&
name|getAttributes
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAttributes
parameter_list|(
specifier|const
name|AttrListPtr
modifier|&
name|PAL
parameter_list|)
function_decl|;
comment|/// paramHasAttr - whether the call or the callee has the given attribute.
name|bool
name|paramHasAttr
argument_list|(
name|uint16_t
name|i
argument_list|,
name|Attributes
name|attr
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Extract the alignment for a call or parameter (0=unknown).
name|uint16_t
name|getParamAlignment
argument_list|(
name|uint16_t
name|i
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Determine if the call does not access memory.
name|bool
name|doesNotAccessMemory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDoesNotAccessMemory
parameter_list|(
name|bool
name|doesNotAccessMemory
init|=
name|true
parameter_list|)
function_decl|;
comment|/// @brief Determine if the call does not access or only reads memory.
name|bool
name|onlyReadsMemory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOnlyReadsMemory
parameter_list|(
name|bool
name|onlyReadsMemory
init|=
name|true
parameter_list|)
function_decl|;
comment|/// @brief Determine if the call cannot return.
name|bool
name|doesNotReturn
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDoesNotReturn
parameter_list|(
name|bool
name|doesNotReturn
init|=
name|true
parameter_list|)
function_decl|;
comment|/// @brief Determine if the call cannot unwind.
name|bool
name|doesNotThrow
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDoesNotThrow
parameter_list|(
name|bool
name|doesNotThrow
init|=
name|true
parameter_list|)
function_decl|;
comment|/// getType - Return the type of the instruction that generated this call site
comment|///
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|->
name|getType
argument_list|()
return|;
block|}
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
comment|/// getInstruction - Return the instruction this call site corresponds to
comment|///
name|Instruction
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
comment|/// getCaller - Return the caller function for this call site
comment|///
name|Function
operator|*
name|getCaller
argument_list|()
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|->
name|getParent
argument_list|()
operator|->
name|getParent
argument_list|()
return|;
block|}
comment|/// getCalledValue - Return the pointer to function that is being called...
comment|///
name|Value
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
name|getInstruction
argument_list|()
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// getCalledFunction - Return the function being called if this is a direct
comment|/// call, otherwise return null (if it's an indirect call).
comment|///
name|Function
operator|*
name|getCalledFunction
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast
operator|<
name|Function
operator|>
operator|(
name|getCalledValue
argument_list|()
operator|)
return|;
block|}
comment|/// setCalledFunction - Set the callee to the specified value...
comment|///
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
name|getInstruction
argument_list|()
operator|->
name|setOperand
argument_list|(
literal|0
argument_list|,
name|V
argument_list|)
expr_stmt|;
block|}
name|Value
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
name|getArgumentOffset
argument_list|()
operator|+
name|ArgNo
argument_list|,
name|newVal
argument_list|)
expr_stmt|;
block|}
comment|/// Given an operand number, returns the argument that corresponds to it.
comment|/// OperandNo must be a valid operand number that actually corresponds to an
comment|/// argument.
name|unsigned
name|getArgumentNo
argument_list|(
name|unsigned
name|OperandNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|OperandNo
operator|>=
name|getArgumentOffset
argument_list|()
operator|&&
literal|"Operand number passed was not "
literal|"a valid argument"
argument_list|)
expr_stmt|;
return|return
name|OperandNo
operator|-
name|getArgumentOffset
argument_list|()
return|;
block|}
comment|/// hasArgument - Returns true if this CallSite passes the given Value* as an
comment|/// argument to the called function.
name|bool
name|hasArgument
argument_list|(
specifier|const
name|Value
operator|*
name|Arg
argument_list|)
decl|const
decl_stmt|;
comment|/// arg_iterator - The type of iterator to use when looping over actual
comment|/// arguments at this call site...
typedef|typedef
name|User
operator|::
name|op_iterator
name|arg_iterator
expr_stmt|;
comment|/// arg_begin/arg_end - Return iterators corresponding to the actual argument
comment|/// list for a call site.
name|arg_iterator
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
name|getInstruction
argument_list|()
operator|->
name|op_begin
argument_list|()
operator|+
name|getArgumentOffset
argument_list|()
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|getInstruction
argument_list|()
operator|->
name|op_end
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
name|bool
name|isCallee
argument_list|(
name|Value
operator|::
name|use_iterator
name|UI
argument_list|)
decl|const
block|{
return|return
name|getInstruction
argument_list|()
operator|->
name|op_begin
argument_list|()
operator|==
operator|&
name|UI
operator|.
name|getUse
argument_list|()
return|;
block|}
name|private
label|:
comment|/// Returns the operand number of the first argument
name|unsigned
name|getArgumentOffset
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
comment|// Skip Function
else|else
return|return
literal|3
return|;
comment|// Skip Function, BB, BB
block|}
block|}
empty_stmt|;
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

