begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetAsmBackend.h - Target Asm Backend -----*- C++ -*-===//
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
name|LLVM_TARGET_TARGETASMBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETASMBACKEND_H
end_define

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
file|"llvm/MC/MCFixupKindInfo.h"
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
name|MCELFObjectTargetWriter
decl_stmt|;
name|class
name|MCFixup
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// TargetAsmBackend - Generic interface to target specific assembler backends.
name|class
name|TargetAsmBackend
block|{
name|TargetAsmBackend
argument_list|(
specifier|const
name|TargetAsmBackend
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetAsmBackend
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|TargetAsmBackend
argument_list|()
expr_stmt|;
name|unsigned
name|HasReliableSymbolDifference
range|:
literal|1
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|TargetAsmBackend
argument_list|()
expr_stmt|;
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
name|assert
argument_list|(
literal|0
operator|&&
literal|"createELFObjectTargetWriter is not supported by asm backend"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
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
comment|/// @}
comment|/// ApplyFixup - Apply the \arg Value for given \arg Fixup into the provided
comment|/// data fragment, at the offset specified by the fixup and following the
comment|/// fixup kind as appropriate.
name|virtual
name|void
name|ApplyFixup
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
comment|/// MayNeedRelaxation - Check whether the given instruction may need
comment|/// relaxation.
comment|///
comment|/// \param Inst - The instruction to test.
name|virtual
name|bool
name|MayNeedRelaxation
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
comment|/// RelaxInstruction - Relax the instruction in the given fragment to the next
comment|/// wider instruction.
comment|///
comment|/// \param Inst - The instruction to relax, which may be the same as the
comment|/// output.
comment|/// \parm Res [output] - On return, the relaxed instruction.
name|virtual
name|void
name|RelaxInstruction
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
comment|/// WriteNopData - Write an (optimal) nop sequence of Count bytes to the given
comment|/// output. If the target cannot generate such a sequence, it should return an
comment|/// error.
comment|///
comment|/// \return - True on success.
name|virtual
name|bool
name|WriteNopData
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
comment|/// HandleAssemblerFlag - Handle any target-specific assembler flags.
comment|/// By default, do nothing.
name|virtual
name|void
name|HandleAssemblerFlag
parameter_list|(
name|MCAssemblerFlag
name|Flag
parameter_list|)
block|{}
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

