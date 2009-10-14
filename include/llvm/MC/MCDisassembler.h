begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCDisassembler.h - Disassembler interface -------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|MCDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|MCDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MemoryObject
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCDisassembler - Superclass for all disassemblers.  Consumes a memory region
comment|///   and provides an array of assembly instructions.
name|class
name|MCDisassembler
block|{
name|public
label|:
comment|/// Constructor     - Performs initial setup for the disassembler.
name|MCDisassembler
argument_list|()
block|{}
name|virtual
operator|~
name|MCDisassembler
argument_list|()
expr_stmt|;
comment|/// getInstruction  - Returns the disassembly of a single instruction.
comment|///
comment|/// @param instr    - An MCInst to populate with the contents of the
comment|///                   instruction.
comment|/// @param size     - A value to populate with the size of the instruction, or
comment|///                   the number of bytes consumed while attempting to decode
comment|///                   an invalid instruction.
comment|/// @param region   - The memory object to use as a source for machine code.
comment|/// @param address  - The address, in the memory space of region, of the first
comment|///                   byte of the instruction.
comment|/// @param vStream  - The stream to print warnings and diagnostic messages on.
comment|/// @return         - True if the instruction is valid; false otherwise.
name|virtual
name|bool
name|getInstruction
argument_list|(
name|MCInst
operator|&
name|instr
argument_list|,
name|uint64_t
operator|&
name|size
argument_list|,
specifier|const
name|MemoryObject
operator|&
name|region
argument_list|,
name|uint64_t
name|address
argument_list|,
name|raw_ostream
operator|&
name|vStream
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

