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
name|LLVM_MC_MCDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbolizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRelocationInfo.h"
end_include

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
name|Symbolizer
argument_list|(
literal|0
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
name|OwningPtr
operator|<
name|MCSymbolizer
operator|>
name|Symbolizer
expr_stmt|;
name|public
label|:
comment|// Helpers around MCSymbolizer
name|bool
name|tryAddingSymbolicOperand
argument_list|(
name|MCInst
operator|&
name|Inst
argument_list|,
name|int64_t
name|Value
argument_list|,
name|uint64_t
name|Address
argument_list|,
name|bool
name|IsBranch
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|uint64_t
name|InstSize
argument_list|)
decl|const
decl_stmt|;
name|void
name|tryAddingPcLoadReferenceComment
argument_list|(
name|int64_t
name|Value
argument_list|,
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
comment|/// Set \p Symzer as the current symbolizer.
comment|/// This takes ownership of \p Symzer, and deletes the previously set one.
name|void
name|setSymbolizer
argument_list|(
name|OwningPtr
operator|<
name|MCSymbolizer
operator|>
operator|&
name|Symzer
argument_list|)
decl_stmt|;
comment|/// Sets up an external symbolizer that uses the C API callbacks.
name|void
name|setupForSymbolicDisassembly
argument_list|(
name|LLVMOpInfoCallback
name|GetOpInfo
argument_list|,
name|LLVMSymbolLookupCallback
name|SymbolLookUp
argument_list|,
name|void
operator|*
name|DisInfo
argument_list|,
name|MCContext
operator|*
name|Ctx
argument_list|,
name|OwningPtr
operator|<
name|MCRelocationInfo
operator|>
operator|&
name|RelInfo
argument_list|)
decl_stmt|;
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
specifier|const
name|MCSubtargetInfo
operator|&
name|getSubtargetInfo
argument_list|()
specifier|const
block|{
return|return
name|STI
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

