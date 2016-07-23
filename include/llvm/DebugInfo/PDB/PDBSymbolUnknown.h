begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbolUnknown.h - unknown symbol type -----------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLUNKNOWN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLUNKNOWN_H
end_define

begin_include
include|#
directive|include
file|"PDBSymbol.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|PDBSymbolUnknown
range|:
name|public
name|PDBSymbol
block|{
name|public
operator|:
name|PDBSymbolUnknown
argument_list|(
specifier|const
name|IPDBSession
operator|&
name|PDBSession
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBRawSymbol
operator|>
name|UnknownSymbol
argument_list|)
block|;
name|void
name|dump
argument_list|(
argument|PDBSymDumper&Dumper
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const PDBSymbol *S
argument_list|)
block|{
return|return
operator|(
name|S
operator|->
name|getSymTag
argument_list|()
operator|==
name|PDB_SymType
operator|::
name|None
operator|||
name|S
operator|->
name|getSymTag
argument_list|()
operator|>=
name|PDB_SymType
operator|::
name|Max
operator|)
return|;
block|}
expr|}
block|;  }
comment|// namespace llvm
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_PDBSYMBOLUNKNOWN_H
end_comment

end_unit

