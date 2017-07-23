begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCSymbolizer.h - MCSymbolizer class --------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCSymbolizer class, which is used
end_comment

begin_comment
comment|// to symbolize instructions decoded from an object, that is, transform their
end_comment

begin_comment
comment|// immediate operands to MCExprs.
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
name|LLVM_MC_MCDISASSEMBLER_MCSYMBOLIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCDISASSEMBLER_MCSYMBOLIZER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler/MCRelocationInfo.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Symbolize and annotate disassembled instructions.
comment|///
comment|/// For now this mimics the old symbolization logic (from both ARM and x86), that
comment|/// relied on user-provided (C API) callbacks to do the actual symbol lookup in
comment|/// the object file. This was moved to MCExternalSymbolizer.
comment|/// A better API would not rely on actually calling the two methods here from
comment|/// inside each disassembler, but would use the instr info to determine what
comment|/// operands are actually symbolizable, and in what way. I don't think this
comment|/// information exists right now.
name|class
name|MCSymbolizer
block|{
name|protected
label|:
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MCRelocationInfo
operator|>
name|RelInfo
expr_stmt|;
name|public
label|:
comment|/// \brief Construct an MCSymbolizer, taking ownership of \p RelInfo.
name|MCSymbolizer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MCRelocationInfo
operator|>
name|RelInfo
argument_list|)
operator|:
name|Ctx
argument_list|(
name|Ctx
argument_list|)
operator|,
name|RelInfo
argument_list|(
argument|std::move(RelInfo)
argument_list|)
block|{   }
name|MCSymbolizer
argument_list|(
specifier|const
name|MCSymbolizer
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCSymbolizer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCSymbolizer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|MCSymbolizer
argument_list|()
expr_stmt|;
comment|/// \brief Try to add a symbolic operand instead of \p Value to the MCInst.
comment|///
comment|/// Instead of having a difficult to read immediate, a symbolic operand would
comment|/// represent this immediate in a more understandable way, for instance as a
comment|/// symbol or an offset from a symbol. Relocations can also be used to enrich
comment|/// the symbolic expression.
comment|/// \param Inst      - The MCInst where to insert the symbolic operand.
comment|/// \param cStream   - Stream to print comments and annotations on.
comment|/// \param Value     - Operand value, pc-adjusted by the caller if necessary.
comment|/// \param Address   - Load address of the instruction.
comment|/// \param IsBranch  - Is the instruction a branch?
comment|/// \param Offset    - Byte offset of the operand inside the inst.
comment|/// \param InstSize  - Size of the instruction in bytes.
comment|/// \return Whether a symbolic operand was added.
name|virtual
name|bool
name|tryAddingSymbolicOperand
parameter_list|(
name|MCInst
modifier|&
name|Inst
parameter_list|,
name|raw_ostream
modifier|&
name|cStream
parameter_list|,
name|int64_t
name|Value
parameter_list|,
name|uint64_t
name|Address
parameter_list|,
name|bool
name|IsBranch
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|InstSize
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Try to add a comment on the PC-relative load.
comment|/// For instance, in Mach-O, this is used to add annotations to instructions
comment|/// that use C string literals, as found in __cstring.
name|virtual
name|void
name|tryAddingPcLoadReferenceComment
parameter_list|(
name|raw_ostream
modifier|&
name|cStream
parameter_list|,
name|int64_t
name|Value
parameter_list|,
name|uint64_t
name|Address
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCDISASSEMBLER_MCSYMBOLIZER_H
end_comment

end_unit

