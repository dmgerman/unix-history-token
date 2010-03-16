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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSection
decl_stmt|;
name|class
name|Target
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
name|virtual
name|bool
name|hasAbsolutizedSet
argument_list|()
specifier|const
block|{
return|return
name|false
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
name|virtual
name|bool
name|hasScatteredSymbols
argument_list|()
specifier|const
block|{
return|return
name|false
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

