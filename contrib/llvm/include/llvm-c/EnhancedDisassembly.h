begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/EnhancedDisassembly.h - Disassembler C Interface ---*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to EnhancedDisassembly.so, which      *| |* implements a disassembler with the ability to extract operand values and   *| |* individual tokens from assembly instructions.                              *| |*                                                                            *| |* The header declares additional interfaces if the host compiler supports    *| |* the blocks API.                                                            *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_ENHANCEDDISASSEMBLY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_ENHANCEDDISASSEMBLY_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*!  @typedef EDByteReaderCallback  Interface to memory from which instructions may be read.  @param byte A pointer whose target should be filled in with the data returned.  @param address The address of the byte to be read.  @param arg An anonymous argument for client use.  @result 0 on success; -1 otherwise.  */
typedef|typedef
name|int
function_decl|(
modifier|*
name|EDByteReaderCallback
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
name|byte
parameter_list|,
name|uint64_t
name|address
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/*!  @typedef EDRegisterReaderCallback  Interface to registers from which registers may be read.  @param value A pointer whose target should be filled in with the value of the    register.  @param regID The LLVM register identifier for the register to read.  @param arg An anonymous argument for client use.  @result 0 if the register could be read; -1 otherwise.  */
typedef|typedef
name|int
function_decl|(
modifier|*
name|EDRegisterReaderCallback
function_decl|)
parameter_list|(
name|uint64_t
modifier|*
name|value
parameter_list|,
name|unsigned
name|regID
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/*!  @typedef EDAssemblySyntax_t  An assembly syntax for use in tokenizing instructions.  */
enum|enum
block|{
comment|/*! @constant kEDAssemblySyntaxX86Intel Intel syntax for i386 and x86_64. */
name|kEDAssemblySyntaxX86Intel
init|=
literal|0
block|,
comment|/*! @constant kEDAssemblySyntaxX86ATT AT&T syntax for i386 and x86_64. */
name|kEDAssemblySyntaxX86ATT
init|=
literal|1
block|,
name|kEDAssemblySyntaxARMUAL
init|=
literal|2
block|}
enum|;
typedef|typedef
name|unsigned
name|EDAssemblySyntax_t
typedef|;
comment|/*!  @typedef EDDisassemblerRef  Encapsulates a disassembler for a single CPU architecture.  */
typedef|typedef
name|void
modifier|*
name|EDDisassemblerRef
typedef|;
comment|/*!  @typedef EDInstRef  Encapsulates a single disassembled instruction in one assembly syntax.  */
typedef|typedef
name|void
modifier|*
name|EDInstRef
typedef|;
comment|/*!  @typedef EDTokenRef  Encapsulates a token from the disassembly of an instruction.  */
typedef|typedef
name|void
modifier|*
name|EDTokenRef
typedef|;
comment|/*!  @typedef EDOperandRef  Encapsulates an operand of an instruction.  */
typedef|typedef
name|void
modifier|*
name|EDOperandRef
typedef|;
comment|/*!  @functiongroup Getting a disassembler  */
comment|/*!  @function EDGetDisassembler  Gets the disassembler for a given target.  @param disassembler A pointer whose target will be filled in with the     disassembler.  @param triple Identifies the target.  Example: "x86_64-apple-darwin10"  @param syntax The assembly syntax to use when decoding instructions.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetDisassembler
parameter_list|(
name|EDDisassemblerRef
modifier|*
name|disassembler
parameter_list|,
specifier|const
name|char
modifier|*
name|triple
parameter_list|,
name|EDAssemblySyntax_t
name|syntax
parameter_list|)
function_decl|;
comment|/*!  @functiongroup Generic architectural queries  */
comment|/*!  @function EDGetRegisterName  Gets the human-readable name for a given register.  @param regName A pointer whose target will be pointed at the name of the    register.  The name does not need to be deallocated and will be   @param disassembler The disassembler to query for the name.  @param regID The register identifier, as returned by EDRegisterTokenValue.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetRegisterName
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|regName
parameter_list|,
name|EDDisassemblerRef
name|disassembler
parameter_list|,
name|unsigned
name|regID
parameter_list|)
function_decl|;
comment|/*!  @function EDRegisterIsStackPointer  Determines if a register is one of the platform's stack-pointer registers.  @param disassembler The disassembler to query.  @param regID The register identifier, as returned by EDRegisterTokenValue.  @result 1 if true; 0 otherwise.  */
name|int
name|EDRegisterIsStackPointer
parameter_list|(
name|EDDisassemblerRef
name|disassembler
parameter_list|,
name|unsigned
name|regID
parameter_list|)
function_decl|;
comment|/*!  @function EDRegisterIsProgramCounter  Determines if a register is one of the platform's stack-pointer registers.  @param disassembler The disassembler to query.  @param regID The register identifier, as returned by EDRegisterTokenValue.  @result 1 if true; 0 otherwise.  */
name|int
name|EDRegisterIsProgramCounter
parameter_list|(
name|EDDisassemblerRef
name|disassembler
parameter_list|,
name|unsigned
name|regID
parameter_list|)
function_decl|;
comment|/*!  @functiongroup Creating and querying instructions  */
comment|/*!  @function EDCreateInst  Gets a set of contiguous instructions from a disassembler.  @param insts A pointer to an array that will be filled in with the    instructions.  Must have at least count entries.  Entries not filled in will     be set to NULL.  @param count The maximum number of instructions to fill in.  @param disassembler The disassembler to use when decoding the instructions.  @param byteReader The function to use when reading the instruction's machine    code.  @param address The address of the first byte of the instruction.  @param arg An anonymous argument to be passed to byteReader.  @result The number of instructions read on success; 0 otherwise.  */
name|unsigned
name|int
name|EDCreateInsts
parameter_list|(
name|EDInstRef
modifier|*
name|insts
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|,
name|EDDisassemblerRef
name|disassembler
parameter_list|,
name|EDByteReaderCallback
name|byteReader
parameter_list|,
name|uint64_t
name|address
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/*!  @function EDReleaseInst  Frees the memory for an instruction.  The instruction can no longer be accessed  after this call.  @param inst The instruction to be freed.  */
name|void
name|EDReleaseInst
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDInstByteSize  @param inst The instruction to be queried.  @result The number of bytes in the instruction's machine-code representation.  */
name|int
name|EDInstByteSize
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDGetInstString  Gets the disassembled text equivalent of the instruction.  @param buf A pointer whose target will be filled in with a pointer to the    string.  (The string becomes invalid when the instruction is released.)  @param inst The instruction to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetInstString
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDInstID  @param instID A pointer whose target will be filled in with the LLVM identifier    for the instruction.  @param inst The instruction to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDInstID
parameter_list|(
name|unsigned
modifier|*
name|instID
parameter_list|,
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDInstIsBranch  @param inst The instruction to be queried.  @result 1 if the instruction is a branch instruction; 0 if it is some other    type of instruction; -1 if there was an error.  */
name|int
name|EDInstIsBranch
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDInstIsMove  @param inst The instruction to be queried.  @result 1 if the instruction is a move instruction; 0 if it is some other    type of instruction; -1 if there was an error.  */
name|int
name|EDInstIsMove
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDBranchTargetID  @param inst The instruction to be queried.  @result The ID of the branch target operand, suitable for use with     EDCopyOperand.  -1 if no such operand exists.  */
name|int
name|EDBranchTargetID
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDMoveSourceID  @param inst The instruction to be queried.  @result The ID of the move source operand, suitable for use with     EDCopyOperand.  -1 if no such operand exists.  */
name|int
name|EDMoveSourceID
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDMoveTargetID  @param inst The instruction to be queried.  @result The ID of the move source operand, suitable for use with     EDCopyOperand.  -1 if no such operand exists.  */
name|int
name|EDMoveTargetID
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @functiongroup Creating and querying tokens  */
comment|/*!  @function EDNumTokens  @param inst The instruction to be queried.  @result The number of tokens in the instruction, or -1 on error.  */
name|int
name|EDNumTokens
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDGetToken  Retrieves a token from an instruction.  The token is valid until the  instruction is released.  @param token A pointer to be filled in with the token.  @param inst The instruction to be queried.  @param index The index of the token in the instruction.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetToken
parameter_list|(
name|EDTokenRef
modifier|*
name|token
parameter_list|,
name|EDInstRef
name|inst
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*!  @function EDGetTokenString  Gets the disassembled text for a token.  @param buf A pointer whose target will be filled in with a pointer to the    string.  (The string becomes invalid when the token is released.)  @param token The token to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetTokenString
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDOperandIndexForToken  Returns the index of the operand to which a token belongs.  @param token The token to be queried.  @result The operand index on success; -1 otherwise  */
name|int
name|EDOperandIndexForToken
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsWhitespace  @param token The token to be queried.  @result 1 if the token is whitespace; 0 if not; -1 on error.  */
name|int
name|EDTokenIsWhitespace
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsPunctuation  @param token The token to be queried.  @result 1 if the token is punctuation; 0 if not; -1 on error.  */
name|int
name|EDTokenIsPunctuation
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsOpcode  @param token The token to be queried.  @result 1 if the token is opcode; 0 if not; -1 on error.  */
name|int
name|EDTokenIsOpcode
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsLiteral  @param token The token to be queried.  @result 1 if the token is a numeric literal; 0 if not; -1 on error.  */
name|int
name|EDTokenIsLiteral
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsRegister  @param token The token to be queried.  @result 1 if the token identifies a register; 0 if not; -1 on error.  */
name|int
name|EDTokenIsRegister
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDTokenIsNegativeLiteral  @param token The token to be queried.  @result 1 if the token is a negative signed literal; 0 if not; -1 on error.  */
name|int
name|EDTokenIsNegativeLiteral
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDLiteralTokenAbsoluteValue  @param value A pointer whose target will be filled in with the absolute value    of the literal.  @param token The token to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDLiteralTokenAbsoluteValue
parameter_list|(
name|uint64_t
modifier|*
name|value
parameter_list|,
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @function EDRegisterTokenValue  @param registerID A pointer whose target will be filled in with the LLVM     register identifier for the token.  @param token The token to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDRegisterTokenValue
parameter_list|(
name|unsigned
modifier|*
name|registerID
parameter_list|,
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*!  @functiongroup Creating and querying operands  */
comment|/*!  @function EDNumOperands  @param inst The instruction to be queried.  @result The number of operands in the instruction, or -1 on error.  */
name|int
name|EDNumOperands
parameter_list|(
name|EDInstRef
name|inst
parameter_list|)
function_decl|;
comment|/*!  @function EDGetOperand  Retrieves an operand from an instruction.  The operand is valid until the  instruction is released.  @param operand A pointer to be filled in with the operand.  @param inst The instruction to be queried.  @param index The index of the operand in the instruction.  @result 0 on success; -1 otherwise.  */
name|int
name|EDGetOperand
parameter_list|(
name|EDOperandRef
modifier|*
name|operand
parameter_list|,
name|EDInstRef
name|inst
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
comment|/*!  @function EDOperandIsRegister  @param operand The operand to be queried.  @result 1 if the operand names a register; 0 if not; -1 on error.  */
name|int
name|EDOperandIsRegister
parameter_list|(
name|EDOperandRef
name|operand
parameter_list|)
function_decl|;
comment|/*!  @function EDOperandIsImmediate  @param operand The operand to be queried.  @result 1 if the operand specifies an immediate value; 0 if not; -1 on error.  */
name|int
name|EDOperandIsImmediate
parameter_list|(
name|EDOperandRef
name|operand
parameter_list|)
function_decl|;
comment|/*!  @function EDOperandIsMemory  @param operand The operand to be queried.  @result 1 if the operand specifies a location in memory; 0 if not; -1 on error.  */
name|int
name|EDOperandIsMemory
parameter_list|(
name|EDOperandRef
name|operand
parameter_list|)
function_decl|;
comment|/*!  @function EDRegisterOperandValue  @param value A pointer whose target will be filled in with the LLVM register ID    of the register named by the operand.    @param operand The operand to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDRegisterOperandValue
parameter_list|(
name|unsigned
modifier|*
name|value
parameter_list|,
name|EDOperandRef
name|operand
parameter_list|)
function_decl|;
comment|/*!  @function EDImmediateOperandValue  @param value A pointer whose target will be filled in with the value of the    immediate.  @param operand The operand to be queried.  @result 0 on success; -1 otherwise.  */
name|int
name|EDImmediateOperandValue
parameter_list|(
name|uint64_t
modifier|*
name|value
parameter_list|,
name|EDOperandRef
name|operand
parameter_list|)
function_decl|;
comment|/*!  @function EDEvaluateOperand  Evaluates an operand using a client-supplied register state accessor.  Register  operands are evaluated by reading the value of the register; immediate operands  are evaluated by reporting the immediate value; memory operands are evaluated  by computing the target address (with only those relocations applied that were  already applied to the original bytes).  @param result A pointer whose target is to be filled with the result of    evaluating the operand.  @param operand The operand to be evaluated.  @param regReader The function to use when reading registers from the register    state.  @param arg An anonymous argument for client use.  @result 0 if the operand could be evaluated; -1 otherwise.  */
name|int
name|EDEvaluateOperand
parameter_list|(
name|uint64_t
modifier|*
name|result
parameter_list|,
name|EDOperandRef
name|operand
parameter_list|,
name|EDRegisterReaderCallback
name|regReader
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__BLOCKS__
comment|/*!  @typedef EDByteBlock_t  Block-based interface to memory from which instructions may be read.  @param byte A pointer whose target should be filled in with the data returned.  @param address The address of the byte to be read.  @result 0 on success; -1 otherwise.  */
typedef|typedef
name|int
function_decl|(
modifier|^
name|EDByteBlock_t
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
name|byte
parameter_list|,
name|uint64_t
name|address
parameter_list|)
function_decl|;
comment|/*!  @typedef EDRegisterBlock_t  Block-based interface to registers from which registers may be read.  @param value A pointer whose target should be filled in with the value of the    register.  @param regID The LLVM register identifier for the register to read.  @result 0 if the register could be read; -1 otherwise.  */
typedef|typedef
name|int
function_decl|(
modifier|^
name|EDRegisterBlock_t
function_decl|)
parameter_list|(
name|uint64_t
modifier|*
name|value
parameter_list|,
name|unsigned
name|regID
parameter_list|)
function_decl|;
comment|/*!  @typedef EDTokenVisitor_t  Block-based handler for individual tokens.  @param token The current token being read.  @result 0 to continue; 1 to stop normally; -1 on error.  */
typedef|typedef
name|int
function_decl|(
modifier|^
name|EDTokenVisitor_t
function_decl|)
parameter_list|(
name|EDTokenRef
name|token
parameter_list|)
function_decl|;
comment|/*! @functiongroup Block-based interfaces */
comment|/*!  @function EDBlockCreateInsts  Gets a set of contiguous instructions from a disassembler, using a block to  read memory.  @param insts A pointer to an array that will be filled in with the    instructions.  Must have at least count entries.  Entries not filled in will     be set to NULL.  @param count The maximum number of instructions to fill in.  @param disassembler The disassembler to use when decoding the instructions.  @param byteBlock The block to use when reading the instruction's machine    code.  @param address The address of the first byte of the instruction.  @result The number of instructions read on success; 0 otherwise.  */
name|unsigned
name|int
name|EDBlockCreateInsts
parameter_list|(
name|EDInstRef
modifier|*
name|insts
parameter_list|,
name|int
name|count
parameter_list|,
name|EDDisassemblerRef
name|disassembler
parameter_list|,
name|EDByteBlock_t
name|byteBlock
parameter_list|,
name|uint64_t
name|address
parameter_list|)
function_decl|;
comment|/*!  @function EDBlockEvaluateOperand  Evaluates an operand using a block to read registers.  @param result A pointer whose target is to be filled with the result of    evaluating the operand.  @param operand The operand to be evaluated.  @param regBlock The block to use when reading registers from the register    state.  @result 0 if the operand could be evaluated; -1 otherwise.  */
name|int
name|EDBlockEvaluateOperand
parameter_list|(
name|uint64_t
modifier|*
name|result
parameter_list|,
name|EDOperandRef
name|operand
parameter_list|,
name|EDRegisterBlock_t
name|regBlock
parameter_list|)
function_decl|;
comment|/*!  @function EDBlockVisitTokens  Visits every token with a visitor.  @param inst The instruction with the tokens to be visited.  @param visitor The visitor.  @result 0 if the visit ended normally; -1 if the visitor encountered an error    or there was some other error.  */
name|int
name|EDBlockVisitTokens
parameter_list|(
name|EDInstRef
name|inst
parameter_list|,
name|EDTokenVisitor_t
name|visitor
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

