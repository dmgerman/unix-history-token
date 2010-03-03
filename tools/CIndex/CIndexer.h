begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CIndexer.h - Clang-C Source Indexing Library -----------------------===//
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
comment|// This file defines CIndexer, a subclass of Indexer that provides extra
end_comment

begin_comment
comment|// functionality needed by the CIndex library.
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
name|LLVM_CLANG_CINDEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CINDEXER_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInstance.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/ASTUnit.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|using
name|namespace
name|clang
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cxstring
block|{
name|CXString
name|createCXString
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|bool
name|DupString
init|=
name|false
parameter_list|)
function_decl|;
name|CXString
name|createCXString
argument_list|(
name|llvm
operator|::
name|StringRef
name|String
argument_list|,
name|bool
name|DupString
operator|=
name|true
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|class
name|CIndexer
block|{
name|bool
name|UseExternalASTGeneration
decl_stmt|;
name|bool
name|OnlyLocalDecls
decl_stmt|;
name|bool
name|DisplayDiagnostics
decl_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|Path
name|ClangPath
expr_stmt|;
name|public
label|:
name|CIndexer
argument_list|()
operator|:
name|UseExternalASTGeneration
argument_list|(
name|false
argument_list|)
operator|,
name|OnlyLocalDecls
argument_list|(
name|false
argument_list|)
operator|,
name|DisplayDiagnostics
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// \brief Whether we only want to see "local" declarations (that did not
comment|/// come from a previous precompiled header). If false, we want to see all
comment|/// declarations.
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
name|void
name|setOnlyLocalDecls
parameter_list|(
name|bool
name|Local
init|=
name|true
parameter_list|)
block|{
name|OnlyLocalDecls
operator|=
name|Local
expr_stmt|;
block|}
name|bool
name|getDisplayDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|DisplayDiagnostics
return|;
block|}
name|void
name|setDisplayDiagnostics
parameter_list|(
name|bool
name|Display
init|=
name|true
parameter_list|)
block|{
name|DisplayDiagnostics
operator|=
name|Display
expr_stmt|;
block|}
name|bool
name|getUseExternalASTGeneration
argument_list|()
specifier|const
block|{
return|return
name|UseExternalASTGeneration
return|;
block|}
name|void
name|setUseExternalASTGeneration
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UseExternalASTGeneration
operator|=
name|Value
expr_stmt|;
block|}
comment|/// \brief Get the path of the clang binary.
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|&
name|getClangPath
argument_list|()
expr_stmt|;
comment|/// \brief Get the path of the clang resource files.
name|std
operator|::
name|string
name|getClangResourcesPath
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/**    * \brief Given a set of "unsaved" files, create temporary files and     * construct the clang -cc1 argument list needed to perform the remapping.    *    * \returns true if an error occurred.    */
name|bool
name|RemapFiles
argument_list|(
name|unsigned
name|num_unsaved_files
argument_list|,
expr|struct
name|CXUnsavedFile
operator|*
name|unsaved_files
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|RemapArgs
argument_list|,
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|>
operator|&
name|TemporaryFiles
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

