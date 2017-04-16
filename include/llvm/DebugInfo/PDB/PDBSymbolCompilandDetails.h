begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBSymbolCompilandDetails.h - PDB compiland details ------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLCOMPILANDDETAILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBSYMBOLCOMPILANDDETAILS_H
end_define

begin_include
include|#
directive|include
file|"PDBSymbol.h"
end_include

begin_include
include|#
directive|include
file|"PDBTypes.h"
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
name|PDBSymbolCompilandDetails
range|:
name|public
name|PDBSymbol
block|{
name|public
operator|:
name|PDBSymbolCompilandDetails
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
name|Symbol
argument_list|)
block|;
name|DECLARE_PDB_SYMBOL_CONCRETE_TYPE
argument_list|(
argument|PDB_SymType::CompilandDetails
argument_list|)
name|void
name|dump
argument_list|(
argument|PDBSymDumper&Dumper
argument_list|)
specifier|const
name|override
block|;
name|void
name|getFrontEndVersion
argument_list|(
argument|VersionInfo&Version
argument_list|)
specifier|const
block|{
name|RawSymbol
operator|->
name|getFrontEndVersion
argument_list|(
name|Version
argument_list|)
block|;   }
name|void
name|getBackEndVersion
argument_list|(
argument|VersionInfo&Version
argument_list|)
specifier|const
block|{
name|RawSymbol
operator|->
name|getBackEndVersion
argument_list|(
name|Version
argument_list|)
block|;   }
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getCompilerName
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isEditAndContinueEnabled
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasDebugInfo
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasManagedCode
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|hasSecurityChecks
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isCVTCIL
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isDataAligned
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isHotpatchable
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isLTCG
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|isMSILNetmodule
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getLanguage
argument_list|)
name|FORWARD_SYMBOL_ID_METHOD
argument_list|(
argument|getLexicalParent
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getPlatform
argument_list|)
name|FORWARD_SYMBOL_METHOD
argument_list|(
argument|getSourceFileName
argument_list|)
block|}
decl_stmt|;
block|}
comment|// namespace llvm
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_PDBFUNCTION_H
end_comment

end_unit

