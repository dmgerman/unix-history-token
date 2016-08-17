begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PDBASTParser.h ------------------------------------------*- C++ -*-===//
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
name|LLDB_PLUGINS_SYMBOLFILE_PDB_PDBASTPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_PLUGINS_SYMBOLFILE_PDB_PDBASTPARSER_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTImporter.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CharUnits
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangASTContext
decl_stmt|;
name|class
name|CompilerType
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|PDBSymbol
decl_stmt|;
name|class
name|PDBSymbolData
decl_stmt|;
name|class
name|PDBSymbolTypeBuiltin
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|class
name|PDBASTParser
block|{
name|public
label|:
name|PDBASTParser
argument_list|(
name|lldb_private
operator|::
name|ClangASTContext
operator|&
name|ast
argument_list|)
expr_stmt|;
operator|~
name|PDBASTParser
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|TypeSP
name|CreateLLDBTypeFromPDBType
argument_list|(
specifier|const
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbol
operator|&
name|type
argument_list|)
expr_stmt|;
name|private
label|:
name|bool
name|AddEnumValue
argument_list|(
name|lldb_private
operator|::
name|CompilerType
name|enum_type
argument_list|,
specifier|const
name|llvm
operator|::
name|pdb
operator|::
name|PDBSymbolData
operator|&
name|data
argument_list|)
decl|const
decl_stmt|;
name|lldb_private
operator|::
name|ClangASTContext
operator|&
name|m_ast
expr_stmt|;
name|lldb_private
operator|::
name|ClangASTImporter
name|m_ast_importer
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SymbolFileDWARF_DWARFASTParserClang_h_
end_comment

end_unit

