begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CIndexer.h - Clang-C Source Indexing Library -------------*- C++ -*-===//
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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CrashRecoveryContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|class
name|CIndexer
block|{
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
name|ResourcesPath
expr_stmt|;
name|std
operator|::
name|string
name|WorkingDir
expr_stmt|;
name|public
label|:
name|CIndexer
argument_list|()
operator|:
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
comment|/// \brief Get the path of the clang resource files.
name|std
operator|::
name|string
name|getClangResourcesPath
argument_list|()
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getWorkingDirectory
argument_list|()
specifier|const
block|{
return|return
name|WorkingDir
return|;
block|}
name|void
name|setWorkingDirectory
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Dir
argument_list|)
block|{
name|WorkingDir
operator|=
name|Dir
expr_stmt|;
block|}
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
comment|/// \brief Return the current size to request for "safety".
name|unsigned
name|GetSafetyThreadStackSize
parameter_list|()
function_decl|;
comment|/// \brief Set the current size to request for "safety" (or 0, if safety
comment|/// threads should not be used).
name|void
name|SetSafetyThreadStackSize
parameter_list|(
name|unsigned
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Execution the given code "safely", using crash recovery or safety
comment|/// threads when possible.
comment|///
comment|/// \return False if a crash was detected.
name|bool
name|RunSafely
argument_list|(
name|llvm
operator|::
name|CrashRecoveryContext
operator|&
name|CRC
argument_list|,
name|void
argument_list|(
operator|*
name|Fn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|UserData
argument_list|,
name|unsigned
name|Size
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

