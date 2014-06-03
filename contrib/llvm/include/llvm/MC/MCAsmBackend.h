begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAsmBack.h - MC Asm Backend --------------------*- C++ -*-===//
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
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
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
name|MCELFObjectTargetWriter
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
name|MCRelaxableFragment
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCAsmBackend - Generic interface to target specific assembler backends.
name|class
name|MCAsmBackend
block|{
name|MCAsmBackend
argument_list|(
argument|const MCAsmBackend&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAsmBackend
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
comment|// Can only create subclasses.
name|MCAsmBackend
argument_list|()
expr_stmt|;
name|unsigned
name|HasReliableSymbolDifference
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasDataInCodeSupport
range|:
literal|1
decl_stmt|;
name|public
label|:
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
comment|/// createObjectWriter - Create a new MCObjectWriter instance for use by the
comment|/// assembler backend to emit the final object file.
name|virtual
name|MCObjectWriter
modifier|*
name|createObjectWriter
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// createELFObjectTargetWriter - Create a new ELFObjectTargetWriter to enable
comment|/// non-standard ELFObjectWriters.
name|virtual
name|MCELFObjectTargetWriter
operator|*
name|createELFObjectTargetWriter
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"createELFObjectTargetWriter is not supported by asm "
literal|"backend"
argument_list|)
block|;   }
comment|/// hasReliableSymbolDifference - Check whether this target implements
comment|/// accurate relocations for differences between symbols. If not, differences
comment|/// between symbols will always be relocatable expressions and any references
comment|/// to temporary symbols will be assumed to be in the same atom, unless they
comment|/// reside in a different section.
comment|///
comment|/// This should always be true (since it results in fewer relocations with no
comment|/// loss of functionality), but is currently supported as a way to maintain
comment|/// exact object compatibility with Darwin 'as' (on non-x86_64). It should
comment|/// eventually should be eliminated.
name|bool
name|hasReliableSymbolDifference
argument_list|()
specifier|const
block|{
return|return
name|HasReliableSymbolDifference
return|;
block|}
comment|/// hasDataInCodeSupport - Check whether this target implements data-in-code
comment|/// markers. If not, data region directives will be ignored.
name|bool
name|hasDataInCodeSupport
argument_list|()
specifier|const
block|{
return|return
name|HasDataInCodeSupport
return|;
block|}
comment|/// doesSectionRequireSymbols - Check whether the given section requires that
comment|/// all symbols (even temporaries) have symbol table entries.
name|virtual
name|bool
name|doesSectionRequireSymbols
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// isSectionAtomizable - Check whether the given section can be split into
comment|/// atoms.
comment|///
comment|/// \see MCAssembler::isSymbolLinkerVisible().
name|virtual
name|bool
name|isSectionAtomizable
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// @name Target Fixup Interfaces
comment|/// @{
comment|/// getNumFixupKinds - Get the number of target specific fixup kinds.
name|virtual
name|unsigned
name|getNumFixupKinds
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getFixupKindInfo - Get information on a fixup kind.
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
comment|/// processFixupValue - Target hook to adjust the literal value of a fixup
comment|/// if necessary. IsResolved signals whether the caller believes a relocation
comment|/// is needed; the target can modify the value. The default does nothing.
name|virtual
name|void
name|processFixupValue
parameter_list|(
specifier|const
name|MCAssembler
modifier|&
name|Asm
parameter_list|,
specifier|const
name|MCAsmLayout
modifier|&
name|Layout
parameter_list|,
specifier|const
name|MCFixup
modifier|&
name|Fixup
parameter_list|,
specifier|const
name|MCFragment
modifier|*
name|DF
parameter_list|,
name|MCValue
modifier|&
name|Target
parameter_list|,
name|uint64_t
modifier|&
name|Value
parameter_list|,
name|bool
modifier|&
name|IsResolved
parameter_list|)
block|{}
comment|/// @}
comment|/// applyFixup - Apply the \p Value for given \p Fixup into the provided
comment|/// data fragment, at the offset specified by the fixup and following the
comment|/// fixup kind as appropriate.
name|virtual
name|void
name|applyFixup
argument_list|(
specifier|const
name|MCFixup
operator|&
name|Fixup
argument_list|,
name|char
operator|*
name|Data
argument_list|,
name|unsigned
name|DataSize
argument_list|,
name|uint64_t
name|Value
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// @}
comment|/// @name Target Relaxation Interfaces
comment|/// @{
comment|/// mayNeedRelaxation - Check whether the given instruction may need
comment|/// relaxation.
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
comment|/// fixupNeedsRelaxation - Target specific predicate for whether a given
comment|/// fixup requires the associated instruction to be relaxed.
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
comment|/// RelaxInstruction - Relax the instruction in the given fragment to the next
comment|/// wider instruction.
comment|///
comment|/// \param Inst The instruction to relax, which may be the same as the
comment|/// output.
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
name|MCInst
operator|&
name|Res
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// @}
comment|/// getMinimumNopSize - Returns the minimum size of a nop in bytes on this
comment|/// target. The assembler will use this to emit excess padding in situations
comment|/// where the padding required for simple alignment would be less than the
comment|/// minimum nop size.
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
comment|/// writeNopData - Write an (optimal) nop sequence of Count bytes to the given
comment|/// output. If the target cannot generate such a sequence, it should return an
comment|/// error.
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
comment|/// handleAssemblerFlag - Handle any target-specific assembler flags.
comment|/// By default, do nothing.
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

