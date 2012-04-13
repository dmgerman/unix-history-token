begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EDInst.h - LLVM Enhanced Disassembler -------------------*- C++ -*-===//
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
comment|// This file defines the interface for the Enhanced Disassembly library's
end_comment

begin_comment
comment|// instruction class.  The instruction is responsible for vending the string
end_comment

begin_comment
comment|// representation, individual tokens and operands for a single instruction.
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
name|LLVM_EDINST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EDINST_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
struct_decl|struct
name|EDInstInfo
struct_decl|;
struct_decl|struct
name|EDToken
struct_decl|;
struct_decl|struct
name|EDDisassembler
struct_decl|;
struct_decl|struct
name|EDOperand
struct_decl|;
ifdef|#
directive|ifdef
name|__BLOCKS__
typedef|typedef
name|int
function_decl|(
modifier|^
name|EDTokenVisitor_t
function_decl|)
parameter_list|(
name|EDToken
modifier|*
name|token
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/// CachedResult - Encapsulates the result of a function along with the validity
comment|///   of that result, so that slow functions don't need to run twice
struct|struct
name|CachedResult
block|{
comment|/// True if the result has been obtained by executing the function
name|bool
name|Valid
decl_stmt|;
comment|/// The result last obtained from the function
name|int
name|Result
decl_stmt|;
comment|/// Constructor - Initializes an invalid result
name|CachedResult
argument_list|()
operator|:
name|Valid
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// valid - Returns true if the result has been obtained by executing the
comment|///   function and false otherwise
name|bool
name|valid
argument_list|()
block|{
return|return
name|Valid
return|;
block|}
comment|/// result - Returns the result of the function or an undefined value if
comment|///   valid() is false
name|int
name|result
parameter_list|()
block|{
return|return
name|Result
return|;
block|}
comment|/// setResult - Sets the result of the function and declares it valid
comment|///   returning the result (so that setResult() can be called from inside a
comment|///   return statement)
comment|/// @arg result - The result of the function
name|int
name|setResult
parameter_list|(
name|int
name|result
parameter_list|)
block|{
name|Result
operator|=
name|result
expr_stmt|;
name|Valid
operator|=
name|true
expr_stmt|;
return|return
name|result
return|;
block|}
block|}
struct|;
comment|/// EDInst - Encapsulates a single instruction, which can be queried for its
comment|///   string representation, as well as its operands and tokens
struct|struct
name|EDInst
block|{
comment|/// The parent disassembler
name|EDDisassembler
modifier|&
name|Disassembler
decl_stmt|;
comment|/// The containing MCInst
name|llvm
operator|::
name|MCInst
operator|*
name|Inst
expr_stmt|;
comment|/// The instruction information provided by TableGen for this instruction
specifier|const
name|llvm
operator|::
name|EDInstInfo
operator|*
name|ThisInstInfo
expr_stmt|;
comment|/// The number of bytes for the machine code representation of the instruction
name|uint64_t
name|ByteSize
decl_stmt|;
comment|/// The result of the stringify() function
name|CachedResult
name|StringifyResult
decl_stmt|;
comment|/// The string representation of the instruction
name|std
operator|::
name|string
name|String
expr_stmt|;
comment|/// The order in which operands from the InstInfo's operand information appear
comment|/// in String
specifier|const
name|signed
name|char
modifier|*
name|OperandOrder
decl_stmt|;
comment|/// The result of the parseOperands() function
name|CachedResult
name|ParseResult
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|EDOperand
operator|*
operator|,
literal|5
operator|>
name|opvec_t
expr_stmt|;
comment|/// The instruction's operands
name|opvec_t
name|Operands
decl_stmt|;
comment|/// The operand corresponding to the target, if the instruction is a branch
name|int
name|BranchTarget
decl_stmt|;
comment|/// The operand corresponding to the source, if the instruction is a move
name|int
name|MoveSource
decl_stmt|;
comment|/// The operand corresponding to the target, if the instruction is a move
name|int
name|MoveTarget
decl_stmt|;
comment|/// The result of the tokenize() function
name|CachedResult
name|TokenizeResult
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|EDToken
operator|*
operator|>
name|tokvec_t
expr_stmt|;
comment|/// The instruction's tokens
name|tokvec_t
name|Tokens
decl_stmt|;
comment|/// Constructor - initializes an instruction given the output of the LLVM
comment|///   C++ disassembler
comment|///
comment|/// @arg inst         - The MCInst, which will now be owned by this object
comment|/// @arg byteSize     - The size of the consumed instruction, in bytes
comment|/// @arg disassembler - The parent disassembler
comment|/// @arg instInfo     - The instruction information produced by the table
comment|///                     generator for this instruction
name|EDInst
argument_list|(
argument|llvm::MCInst *inst
argument_list|,
argument|uint64_t byteSize
argument_list|,
argument|EDDisassembler&disassembler
argument_list|,
argument|const llvm::EDInstInfo *instInfo
argument_list|)
empty_stmt|;
operator|~
name|EDInst
argument_list|()
expr_stmt|;
comment|/// byteSize - returns the number of bytes consumed by the machine code
comment|///   representation of the instruction
name|uint64_t
name|byteSize
parameter_list|()
function_decl|;
comment|/// instID - returns the LLVM instruction ID of the instruction
name|unsigned
name|instID
parameter_list|()
function_decl|;
comment|/// stringify - populates the String and AsmString members of the instruction,
comment|///   returning 0 on success or -1 otherwise
name|int
name|stringify
parameter_list|()
function_decl|;
comment|/// getString - retrieves a pointer to the string representation of the
comment|///   instructinon, returning 0 on success or -1 otherwise
comment|///
comment|/// @arg str - A reference to a pointer that, on success, is set to point to
comment|///   the string representation of the instruction; this string is still owned
comment|///   by the instruction and will be deleted when it is
name|int
name|getString
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|str
parameter_list|)
function_decl|;
comment|/// isBranch - Returns true if the instruction is a branch
name|bool
name|isBranch
parameter_list|()
function_decl|;
comment|/// isMove - Returns true if the instruction is a move
name|bool
name|isMove
parameter_list|()
function_decl|;
comment|/// parseOperands - populates the Operands member of the instruction,
comment|///   returning 0 on success or -1 otherwise
name|int
name|parseOperands
parameter_list|()
function_decl|;
comment|/// branchTargetID - returns the ID (suitable for use with getOperand()) of
comment|///   the target operand if the instruction is a branch, or -1 otherwise
name|int
name|branchTargetID
parameter_list|()
function_decl|;
comment|/// moveSourceID - returns the ID of the source operand if the instruction
comment|///   is a move, or -1 otherwise
name|int
name|moveSourceID
parameter_list|()
function_decl|;
comment|/// moveTargetID - returns the ID of the target operand if the instruction
comment|///   is a move, or -1 otherwise
name|int
name|moveTargetID
parameter_list|()
function_decl|;
comment|/// numOperands - returns the number of operands available to retrieve, or -1
comment|///   on error
name|int
name|numOperands
parameter_list|()
function_decl|;
comment|/// getOperand - retrieves an operand from the instruction's operand list by
comment|///   index, returning 0 on success or -1 on error
comment|///
comment|/// @arg operand  - A reference whose target is pointed at the operand on
comment|///                 success, although the operand is still owned by the EDInst
comment|/// @arg index    - The index of the operand in the instruction
name|int
name|getOperand
parameter_list|(
name|EDOperand
modifier|*
modifier|&
name|operand
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
comment|/// tokenize - populates the Tokens member of the instruction, returning 0 on
comment|///   success or -1 otherwise
name|int
name|tokenize
parameter_list|()
function_decl|;
comment|/// numTokens - returns the number of tokens in the instruction, or -1 on
comment|///   error
name|int
name|numTokens
parameter_list|()
function_decl|;
comment|/// getToken - retrieves a token from the instruction's token list by index,
comment|///   returning 0 on success or -1 on error
comment|///
comment|/// @arg token  - A reference whose target is pointed at the token on success,
comment|///               although the token is still owned by the EDInst
comment|/// @arg index  - The index of the token in the instrcutino
name|int
name|getToken
parameter_list|(
name|EDToken
modifier|*
modifier|&
name|token
parameter_list|,
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__BLOCKS__
comment|/// visitTokens - Visits each token in turn and applies a block to it,
comment|///   returning 0 if all blocks are visited and/or the block signals
comment|///   termination by returning 1; returns -1 on error
comment|///
comment|/// @arg visitor  - The visitor block to apply to all tokens.
name|int
name|visitTokens
parameter_list|(
name|EDTokenVisitor_t
name|visitor
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

