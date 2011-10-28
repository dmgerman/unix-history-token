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

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MemoryObject
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
struct_decl|struct
name|EDInstInfo
struct_decl|;
comment|/// MCDisassembler - Superclass for all disassemblers.  Consumes a memory region
comment|///   and provides an array of assembly instructions.
name|class
name|MCDisassembler
block|{
name|public
label|:
comment|/// Ternary decode status. Most backends will just use Fail and
comment|/// Success, however some have a concept of an instruction with
comment|/// understandable semantics but which is architecturally
comment|/// incorrect. An example of this is ARM UNPREDICTABLE instructions
comment|/// which are disassemblable but cause undefined behaviour.
comment|///
comment|/// Because it makes sense to disassemble these instructions, there
comment|/// is a "soft fail" failure mode that indicates the MCInst& is
comment|/// valid but architecturally incorrect.
comment|///
comment|/// The enum numbers are deliberately chosen such that reduction
comment|/// from Success->SoftFail ->Fail can be done with a simple
comment|/// bitwise-AND:
comment|///
comment|///   LEFT& TOP =  | Success       Unpredictable   Fail
comment|///   --------------+-----------------------------------
comment|///   Success       | Success       Unpredictable   Fail
comment|///   Unpredictable | Unpredictable Unpredictable   Fail
comment|///   Fail          | Fail          Fail            Fail
comment|///
comment|/// An easy way of encoding this is as 0b11, 0b01, 0b00 for
comment|/// Success, SoftFail, Fail respectively.
enum|enum
name|DecodeStatus
block|{
name|Fail
init|=
literal|0
block|,
name|SoftFail
init|=
literal|1
block|,
name|Success
init|=
literal|3
block|}
enum|;
comment|/// Constructor     - Performs initial setup for the disassembler.
name|MCDisassembler
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
operator|:
name|GetOpInfo
argument_list|(
literal|0
argument_list|)
operator|,
name|SymbolLookUp
argument_list|(
literal|0
argument_list|)
operator|,
name|DisInfo
argument_list|(
literal|0
argument_list|)
operator|,
name|Ctx
argument_list|(
literal|0
argument_list|)
operator|,
name|STI
argument_list|(
name|STI
argument_list|)
operator|,
name|CommentStream
argument_list|(
literal|0
argument_list|)
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
comment|/// @param cStream  - The stream to print comments and annotations on.
comment|/// @return         - MCDisassembler::Success if the instruction is valid,
comment|///                   MCDisassembler::SoftFail if the instruction was
comment|///                                            disassemblable but invalid,
comment|///                   MCDisassembler::Fail if the instruction was invalid.
name|virtual
name|DecodeStatus
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
argument_list|,
name|raw_ostream
operator|&
name|cStream
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getEDInfo - Returns the enhanced instruction information corresponding to
comment|///   the disassembler.
comment|///
comment|/// @return         - An array of instruction information, with one entry for
comment|///                   each MCInst opcode this disassembler returns.
comment|///                   NULL if there is no info for this target.
name|virtual
name|EDInstInfo
operator|*
name|getEDInfo
argument_list|()
specifier|const
block|{
return|return
operator|(
name|EDInstInfo
operator|*
operator|)
literal|0
return|;
block|}
name|private
label|:
comment|//
comment|// Hooks for symbolic disassembly via the public 'C' interface.
comment|//
comment|// The function to get the symbolic information for operands.
name|LLVMOpInfoCallback
name|GetOpInfo
decl_stmt|;
comment|// The function to lookup a symbol name.
name|LLVMSymbolLookupCallback
name|SymbolLookUp
decl_stmt|;
comment|// The pointer to the block of symbolic information for above call back.
name|void
modifier|*
name|DisInfo
decl_stmt|;
comment|// The assembly context for creating symbols and MCExprs in place of
comment|// immediate operands when there is symbolic information.
name|MCContext
modifier|*
name|Ctx
decl_stmt|;
name|protected
label|:
comment|// Subtarget information, for instruction decoding predicates if required.
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
decl_stmt|;
name|public
label|:
name|void
name|setupForSymbolicDisassembly
parameter_list|(
name|LLVMOpInfoCallback
name|getOpInfo
parameter_list|,
name|LLVMSymbolLookupCallback
name|symbolLookUp
parameter_list|,
name|void
modifier|*
name|disInfo
parameter_list|,
name|MCContext
modifier|*
name|ctx
parameter_list|)
block|{
name|GetOpInfo
operator|=
name|getOpInfo
expr_stmt|;
name|SymbolLookUp
operator|=
name|symbolLookUp
expr_stmt|;
name|DisInfo
operator|=
name|disInfo
expr_stmt|;
name|Ctx
operator|=
name|ctx
expr_stmt|;
block|}
name|LLVMOpInfoCallback
name|getLLVMOpInfoCallback
argument_list|()
specifier|const
block|{
return|return
name|GetOpInfo
return|;
block|}
name|LLVMSymbolLookupCallback
name|getLLVMSymbolLookupCallback
argument_list|()
specifier|const
block|{
return|return
name|SymbolLookUp
return|;
block|}
name|void
operator|*
name|getDisInfoBlock
argument_list|()
specifier|const
block|{
return|return
name|DisInfo
return|;
block|}
name|MCContext
operator|*
name|getMCContext
argument_list|()
specifier|const
block|{
return|return
name|Ctx
return|;
block|}
comment|// Marked mutable because we cache it inside the disassembler, rather than
comment|// having to pass it around as an argument through all the autogenerated code.
name|mutable
name|raw_ostream
modifier|*
name|CommentStream
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

