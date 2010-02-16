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
comment|/**  * \brief Diagnostic client that translates Clang diagnostics into diagnostics  * for the C interface to Clang.  */
name|class
name|CIndexDiagnosticClient
range|:
name|public
name|DiagnosticClient
block|{
name|CXDiagnosticCallback
name|Callback
block|;
name|CXClientData
name|ClientData
block|;
specifier|const
name|LangOptions
operator|*
name|LangOptsPtr
block|;
name|public
operator|:
name|CIndexDiagnosticClient
argument_list|(
argument|CXDiagnosticCallback Callback
argument_list|,
argument|CXClientData ClientData
argument_list|)
operator|:
name|Callback
argument_list|(
name|Callback
argument_list|)
block|,
name|ClientData
argument_list|(
name|ClientData
argument_list|)
block|,
name|LangOptsPtr
argument_list|(
literal|0
argument_list|)
block|{ }
name|virtual
operator|~
name|CIndexDiagnosticClient
argument_list|()
block|;
name|virtual
name|void
name|BeginSourceFile
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|Preprocessor
operator|*
name|PP
argument_list|)
block|;
name|virtual
name|void
name|EndSourceFile
argument_list|()
block|;
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level DiagLevel
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Given the path to a file that contains binary, serialized
comment|/// diagnostics produced by Clang, emit those diagnostics via the
comment|/// given diagnostic engine.
name|void
name|ReportSerializedDiagnostics
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
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|unsigned
name|num_unsaved_files
argument_list|,
expr|struct
name|CXUnsavedFile
operator|*
name|unsaved_files
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
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

