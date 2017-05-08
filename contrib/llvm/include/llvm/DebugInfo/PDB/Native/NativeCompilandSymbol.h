begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NativeCompilandSymbol.h - native impl for compiland syms -*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVECOMPILANDSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_NATIVECOMPILANDSYMBOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/DbiModuleDescriptor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeRawSymbol.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|NativeCompilandSymbol
range|:
name|public
name|NativeRawSymbol
block|{
name|public
operator|:
name|NativeCompilandSymbol
argument_list|(
argument|NativeSession&Session
argument_list|,
argument|DbiModuleDescriptor MI
argument_list|)
block|;
name|PDB_SymType
name|getSymTag
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isEditAndContinueEnabled
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getLexicalParentId
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getLibraryName
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|DbiModuleDescriptor
name|Module
block|; }
decl_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

