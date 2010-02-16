begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86/X86FixupKinds.h - X86 Specific Fixup Entries --------*- C++ -*-===//
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
name|LLVM_X86_X86FIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_X86_X86FIXUPKINDS_H
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
name|reloc_pcrel_4byte
init|=
name|FirstTargetFixupKind
block|,
comment|// 32-bit pcrel, e.g. a branch.
name|reloc_pcrel_1byte
block|,
comment|// 8-bit pcrel, e.g. branch_1
name|reloc_riprel_4byte
comment|// 32-bit rip-relative
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

