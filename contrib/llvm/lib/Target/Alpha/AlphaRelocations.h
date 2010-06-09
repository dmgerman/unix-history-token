begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AlphaRelocations.h - Alpha Code Relocations --------------*- C++ -*-===//
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
comment|// This file defines the Alpha target-specific relocation types.
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
name|ALPHARELOCATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHARELOCATIONS_H
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
name|Alpha
block|{
enum|enum
name|RelocationType
block|{
name|reloc_literal
block|,
name|reloc_gprellow
block|,
name|reloc_gprelhigh
block|,
name|reloc_gpdist
block|,
name|reloc_bsr
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

