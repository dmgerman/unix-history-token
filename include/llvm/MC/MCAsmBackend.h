begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCAsmBackend.h - MC Asm Backend ------------------*- C++ -*-===//
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
name|LLVM_MC_MCASMBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMBACKEND_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmLayout
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCCFIInstruction
decl_stmt|;
struct_decl|struct
name|MCFixupKindInfo
struct_decl|;
name|class
name|MCFragment
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCRelaxableFragment
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|/// Generic interface to target specific assembler backends.
name|class
name|MCAsmBackend
block|{
name|protected
label|:
comment|// Can only create subclasses.
name|MCAsmBackend
argument_list|()
expr_stmt|;
name|public
label|:
name|MCAsmBackend
argument_list|(
specifier|const
name|MCAsmBackend
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MCAsmBackend
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCAsmBackend
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|MCAsmBackend
argument_list|()
expr_stmt|;
comment|/// lifetime management
name|virtual
name|void
name|reset
parameter_list|()
block|{}
comment|/// Create a new MCObjectWriter instance for use by the assembler backend to
comment|/// emit the final object file.
name|virtual
name|MCObjectWriter
modifier|*
name|createObjectWriter
argument_list|(
name|raw_pwrite_stream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \name Target Fixup Interfaces
comment|/// @{
comment|/// Get the number of target specific fixup kinds.
name|virtual
name|unsigned
name|getNumFixupKinds
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Map a relocation name used in .reloc to a fixup kind.
name|virtual
name|Optional
operator|<
name|MCFixupKind
operator|>
name|getFixupKind
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get information on a fixup kind.
name|virtual
specifier|const
name|MCFixupKindInfo
modifier|&
name|getFixupKindInfo
argument_list|(
name|MCFixupKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// Hook to check if a relocation is needed for some target specific reason.
name|virtual
name|bool
name|shouldForceRelocation
parameter_list|(
specifier|const
name|MCAssembler
modifier|&
name|Asm
parameter_list|,
specifier|const
name|MCFixup
modifier|&
name|Fixup
parameter_list|,
specifier|const
name|MCValue
modifier|&
name|Target
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// Apply the \p Value for given \p Fixup into the provided data fragment, at
comment|/// the offset specified by the fixup and following the fixup kind as
comment|/// appropriate. Errors (such as an out of range fixup value) should be
comment|/// reported via \p Ctx.
name|virtual
name|void
name|applyFixup
argument_list|(
specifier|const
name|MCAssembler
operator|&
name|Asm
argument_list|,
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
specifier|const
name|MCValue
operator|&
name|Target
argument_list|,
name|MutableArrayRef
operator|<
name|char
operator|>
name|Data
argument_list|,
name|uint64_t
name|Value
argument_list|,
name|bool
name|IsResolved
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// @}
comment|/// \name Target Relaxation Interfaces
comment|/// @{
comment|/// Check whether the given instruction may need relaxation.
comment|///
comment|/// \param Inst - The instruction to test.
name|virtual
name|bool
name|mayNeedRelaxation
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Target specific predicate for whether a given fixup requires the
comment|/// associated instruction to be relaxed.
name|virtual
name|bool
name|fixupNeedsRelaxationAdvanced
argument_list|(
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|bool
name|Resolved
argument_list|,
name|uint64_t
name|Value
argument_list|,
specifier|const
name|MCRelaxableFragment
operator|*
name|DF
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
decl_stmt|;
comment|/// Simple predicate for targets where !Resolved implies requiring relaxation
name|virtual
name|bool
name|fixupNeedsRelaxation
argument_list|(
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|uint64_t
name|Value
argument_list|,
specifier|const
name|MCRelaxableFragment
operator|*
name|DF
argument_list|,
specifier|const
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Relax the instruction in the given fragment to the next wider instruction.
comment|///
comment|/// \param Inst The instruction to relax, which may be the same as the
comment|/// output.
comment|/// \param STI the subtarget information for the associated instruction.
comment|/// \param [out] Res On return, the relaxed instruction.
name|virtual
name|void
name|relaxInstruction
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCInst
operator|&
name|Res
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// @}
comment|/// Returns the minimum size of a nop in bytes on this target. The assembler
comment|/// will use this to emit excess padding in situations where the padding
comment|/// required for simple alignment would be less than the minimum nop size.
comment|///
name|virtual
name|unsigned
name|getMinimumNopSize
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Write an (optimal) nop sequence of Count bytes to the given output. If the
comment|/// target cannot generate such a sequence, it should return an error.
comment|///
comment|/// \return - True on success.
name|virtual
name|bool
name|writeNopData
argument_list|(
name|uint64_t
name|Count
argument_list|,
name|MCObjectWriter
operator|*
name|OW
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Give backend an opportunity to finish layout after relaxation
name|virtual
name|void
name|finishLayout
argument_list|(
name|MCAssembler
specifier|const
operator|&
name|Asm
argument_list|,
name|MCAsmLayout
operator|&
name|Layout
argument_list|)
decl|const
block|{}
comment|/// Handle any target-specific assembler flags. By default, do nothing.
name|virtual
name|void
name|handleAssemblerFlag
parameter_list|(
name|MCAssemblerFlag
name|Flag
parameter_list|)
block|{}
comment|/// \brief Generate the compact unwind encoding for the CFI instructions.
name|virtual
name|uint32_t
name|generateCompactUnwindEncoding
argument_list|(
name|ArrayRef
operator|<
name|MCCFIInstruction
operator|>
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
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
comment|// LLVM_MC_MCASMBACKEND_H
end_comment

end_unit

