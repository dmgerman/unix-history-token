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
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmFixup
decl_stmt|;
name|class
name|MCDataFragment
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|Target
decl_stmt|;
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
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
name|unsigned
name|HasAbsolutizedSet
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasReliableSymbolDifference
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasScatteredSymbols
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
specifier|const
name|Target
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
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
comment|/// hasAbsolutizedSet - Check whether this target "absolutizes"
comment|/// assignments. That is, given code like:
comment|///   a:
comment|///   ...
comment|///   b:
comment|///   tmp = a - b
comment|///       .long tmp
comment|/// will the value of 'tmp' be a relocatable expression, or the assembly time
comment|/// value of L0 - L1. This distinction is only relevant for platforms that
comment|/// support scattered symbols, since in the absence of scattered symbols (a -
comment|/// b) cannot change after assembly.
name|bool
name|hasAbsolutizedSet
argument_list|()
specifier|const
block|{
return|return
name|HasAbsolutizedSet
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
comment|/// eventually should be eliminated. See also \see hasAbsolutizedSet.
name|bool
name|hasReliableSymbolDifference
argument_list|()
specifier|const
block|{
return|return
name|HasReliableSymbolDifference
return|;
block|}
comment|/// hasScatteredSymbols - Check whether this target supports scattered
comment|/// symbols. If so, the assembler should assume that atoms can be scattered by
comment|/// the linker. In particular, this means that the offsets between symbols
comment|/// which are in distinct atoms is not known at link time, and the assembler
comment|/// must generate fixups and relocations appropriately.
comment|///
comment|/// Note that the assembler currently does not reason about atoms, instead it
comment|/// assumes all temporary symbols reside in the "current atom".
name|bool
name|hasScatteredSymbols
argument_list|()
specifier|const
block|{
return|return
name|HasScatteredSymbols
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
comment|/// isVirtualSection - Check whether the given section is "virtual", that is
comment|/// has no actual object file contents.
name|virtual
name|bool
name|isVirtualSection
argument_list|(
specifier|const
name|MCSection
operator|&
name|Section
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// ApplyFixup - Apply the \arg Value for given \arg Fixup into the provided
comment|/// data fragment, at the offset specified by the fixup and following the
comment|/// fixup kind as appropriate.
name|virtual
name|void
name|ApplyFixup
argument_list|(
specifier|const
name|MCAsmFixup
operator|&
name|Fixup
argument_list|,
name|MCDataFragment
operator|&
name|Fragment
argument_list|,
name|uint64_t
name|Value
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

