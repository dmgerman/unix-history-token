begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcRelocations.h - Sparc Code Relocations -------------*- C++ -*-===//
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
comment|// This file defines the Sparc target-specific relocation types
end_comment

begin_comment
comment|// (for relocation-model=static).
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
name|SPARC_RELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|SPARC_RELOCATIONS_H
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
name|SP
block|{
enum|enum
name|RelocationType
block|{
comment|// reloc_sparc_hi - upper 22 bits
name|reloc_sparc_hi
init|=
literal|1
block|,
comment|// reloc_sparc_lo - lower 10 bits
name|reloc_sparc_lo
init|=
literal|2
block|,
comment|// reloc_sparc_pc30 - pc rel. 30 bits for call
name|reloc_sparc_pc30
init|=
literal|3
block|,
comment|// reloc_sparc_pc22 - pc rel. 22 bits for branch
name|reloc_sparc_pc22
init|=
literal|4
block|,
comment|// reloc_sparc_pc22 - pc rel. 19 bits for branch with icc/xcc
name|reloc_sparc_pc19
init|=
literal|5
block|,
comment|// reloc_sparc_h44 - 43-22 bits
name|reloc_sparc_h44
init|=
literal|6
block|,
comment|// reloc_sparc_m44 - 21-12 bits
name|reloc_sparc_m44
init|=
literal|7
block|,
comment|// reloc_sparc_l44 - lower 12 bits
name|reloc_sparc_l44
init|=
literal|8
block|,
comment|// reloc_sparc_hh - 63-42 bits
name|reloc_sparc_hh
init|=
literal|9
block|,
comment|// reloc_sparc_hm - 41-32 bits
name|reloc_sparc_hm
init|=
literal|10
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

