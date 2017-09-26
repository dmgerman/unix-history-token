begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDB.h ----------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_COFF_PDB_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_PDB_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
union_decl|union
name|DebugInfo
union_decl|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
block|{
name|class
name|SymbolTable
decl_stmt|;
name|void
name|createPDB
argument_list|(
name|SymbolTable
operator|*
name|Symtab
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|SectionTable
argument_list|,
specifier|const
name|llvm
operator|::
name|codeview
operator|::
name|DebugInfo
operator|*
name|DI
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

