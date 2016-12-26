begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86FixupKinds.h - X86 Specific Fixup Entries ------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_X86_MCTARGETDESC_X86FIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_MCTARGETDESC_X86FIXUPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|X86
block|{
enum|enum
name|Fixups
block|{
name|reloc_riprel_4byte
init|=
name|FirstTargetFixupKind
block|,
comment|// 32-bit rip-relative
name|reloc_riprel_4byte_movq_load
block|,
comment|// 32-bit rip-relative in movq
name|reloc_riprel_4byte_relax
block|,
comment|// 32-bit rip-relative in relaxable
comment|// instruction
name|reloc_riprel_4byte_relax_rex
block|,
comment|// 32-bit rip-relative in relaxable
comment|// instruction with rex prefix
name|reloc_signed_4byte
block|,
comment|// 32-bit signed. Unlike FK_Data_4
comment|// this will be sign extended at
comment|// runtime.
name|reloc_signed_4byte_relax
block|,
comment|// like reloc_signed_4byte, but
comment|// in a relaxable instruction.
name|reloc_global_offset_table
block|,
comment|// 32-bit, relative to the start
comment|// of the instruction. Used only
comment|// for _GLOBAL_OFFSET_TABLE_.
name|reloc_global_offset_table8
block|,
comment|// 64-bit variant.
comment|// Marker
name|LastTargetFixupKind
block|,
name|NumTargetFixupKinds
init|=
name|LastTargetFixupKind
operator|-
name|FirstTargetFixupKind
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

