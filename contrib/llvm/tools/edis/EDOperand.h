begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-EDOperand.h - LLVM Enhanced Disassembler ------------------*- C++ -*-===//
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
comment|// operand class.  The operand is responsible for allowing evaluation given a
end_comment

begin_comment
comment|// particular register context.
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
name|EDOperand_
end_ifndef

begin_define
define|#
directive|define
name|EDOperand_
end_define

begin_include
include|#
directive|include
file|"llvm-c/EnhancedDisassembly.h"
end_include

begin_comment
comment|/// EDOperand - Encapsulates a single operand, which can be evaluated by the
end_comment

begin_comment
comment|///   client
end_comment

begin_struct
struct|struct
name|EDOperand
block|{
comment|/// The parent disassembler
specifier|const
name|EDDisassembler
modifier|&
name|Disassembler
decl_stmt|;
comment|/// The parent instruction
specifier|const
name|EDInst
modifier|&
name|Inst
decl_stmt|;
comment|/// The index of the operand in the EDInst
name|unsigned
name|int
name|OpIndex
decl_stmt|;
comment|/// The index of the first component of the operand in the MCInst
name|unsigned
name|int
name|MCOpIndex
decl_stmt|;
comment|/// Constructor - Initializes an EDOperand
comment|///
comment|/// @arg disassembler - The disassembler responsible for the operand
comment|/// @arg inst         - The instruction containing this operand
comment|/// @arg opIndex      - The index of the operand in inst
comment|/// @arg mcOpIndex    - The index of the operand in the original MCInst
name|EDOperand
argument_list|(
argument|const EDDisassembler&disassembler
argument_list|,
argument|const EDInst&inst
argument_list|,
argument|unsigned int opIndex
argument_list|,
argument|unsigned int&mcOpIndex
argument_list|)
empty_stmt|;
operator|~
name|EDOperand
argument_list|()
expr_stmt|;
comment|/// evaluate - Returns the numeric value of an operand to the extent possible,
comment|///   returning 0 on success or -1 if there was some problem (such as a
comment|///   register not being readable)
comment|///
comment|/// @arg result   - A reference whose target is filled in with the value of
comment|///                 the operand (the address if it is a memory operand)
comment|/// @arg callback - A function to call to obtain register values
comment|/// @arg arg      - An opaque argument to pass to callback
name|int
name|evaluate
parameter_list|(
name|uint64_t
modifier|&
name|result
parameter_list|,
name|EDRegisterReaderCallback
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/// isRegister - Returns 1 if the operand is a register or 0 otherwise
name|int
name|isRegister
parameter_list|()
function_decl|;
comment|/// regVal - Returns the register value.
name|unsigned
name|regVal
parameter_list|()
function_decl|;
comment|/// isImmediate - Returns 1 if the operand is an immediate or 0 otherwise
name|int
name|isImmediate
parameter_list|()
function_decl|;
comment|/// immediateVal - Returns the immediate value.
name|uint64_t
name|immediateVal
parameter_list|()
function_decl|;
comment|/// isMemory - Returns 1 if the operand is a memory location or 0 otherwise
name|int
name|isMemory
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|__BLOCKS__
comment|/// evaluate - Like evaluate for a callback, but uses a block instead
name|int
name|evaluate
parameter_list|(
name|uint64_t
modifier|&
name|result
parameter_list|,
name|EDRegisterBlock_t
name|regBlock
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

