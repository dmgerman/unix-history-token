begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86Relocations.h - X86 Code Relocations ------------------*- C++ -*-===//
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
comment|// This file defines the X86 target-specific relocation types.
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
name|X86RELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|X86RELOCATIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRelocation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86
block|{
comment|/// RelocationType - An enum for the x86 relocation codes. Note that
comment|/// the terminology here doesn't follow x86 convention - word means
comment|/// 32-bit and dword means 64-bit. The relocations will be treated
comment|/// by JIT or ObjectCode emitters, this is transparent to the x86 code
comment|/// emitter but JIT and ObjectCode will treat them differently
enum|enum
name|RelocationType
block|{
comment|/// reloc_pcrel_word - PC relative relocation, add the relocated value to
comment|/// the value already in memory, after we adjust it for where the PC is.
name|reloc_pcrel_word
init|=
literal|0
block|,
comment|/// reloc_picrel_word - PIC base relative relocation, add the relocated
comment|/// value to the value already in memory, after we adjust it for where the
comment|/// PIC base is.
name|reloc_picrel_word
init|=
literal|1
block|,
comment|/// reloc_absolute_word - absolute relocation, just add the relocated
comment|/// value to the value already in memory.
name|reloc_absolute_word
init|=
literal|2
block|,
comment|/// reloc_absolute_word_sext - absolute relocation, just add the relocated
comment|/// value to the value already in memory. In object files, it represents a
comment|/// value which must be sign-extended when resolving the relocation.
name|reloc_absolute_word_sext
init|=
literal|3
block|,
comment|/// reloc_absolute_dword - absolute relocation, just add the relocated
comment|/// value to the value already in memory.
name|reloc_absolute_dword
init|=
literal|4
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

