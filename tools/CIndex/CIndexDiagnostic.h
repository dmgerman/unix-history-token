begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- CIndexDiagnostic.h - Diagnostics C Interface ------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* Implements the diagnostic functions of the Clang C interface.              *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_CINDEX_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CINDEX_DIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|class
name|Path
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
comment|/// \brief The storage behind a CXDiagnostic
struct|struct
name|CXStoredDiagnostic
block|{
specifier|const
name|StoredDiagnostic
modifier|&
name|Diag
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
name|CXStoredDiagnostic
argument_list|(
specifier|const
name|StoredDiagnostic
operator|&
name|Diag
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
operator|:
name|Diag
argument_list|(
name|Diag
argument_list|)
operator|,
name|LangOpts
argument_list|(
argument|LangOpts
argument_list|)
block|{ }
block|}
struct|;
comment|/// \brief Given the path to a file that contains binary, serialized
comment|/// diagnostics produced by Clang, load those diagnostics.
name|void
name|LoadSerializedDiagnostics
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|&
name|DiagnosticsPath
argument_list|,
name|unsigned
name|num_unsaved_files
argument_list|,
expr|struct
name|CXUnsavedFile
operator|*
name|unsaved_files
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|StoredDiagnostic
operator|>
operator|&
name|Diags
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_CINDEX_DIAGNOSTIC_H
end_comment

end_unit

