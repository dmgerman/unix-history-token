begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FixItRewriter.h - Fix-It Rewriter Diagnostic Client ----*- C++ -*-===//
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
comment|// This is a diagnostic client adaptor that performs rewrites as
end_comment

begin_comment
comment|// suggested by code modification hints attached to diagnostics. It
end_comment

begin_comment
comment|// then forwards any diagnostics to the adapted diagnostic client.
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
name|LLVM_CLANG_FRONTEND_FIX_IT_REWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_FIX_IT_REWRITER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/Rewriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
comment|/// \brief Stores a source location in the form that it shows up on
comment|/// the Clang command line, e.g., file:line:column.
comment|///
comment|/// FIXME: Would prefer to use real SourceLocations, but I don't see a
comment|/// good way to resolve them during parsing.
struct|struct
name|RequestedSourceLocation
block|{
specifier|const
name|FileEntry
modifier|*
name|File
decl_stmt|;
name|unsigned
name|Line
decl_stmt|;
name|unsigned
name|Column
decl_stmt|;
block|}
struct|;
name|class
name|FixItRewriter
range|:
name|public
name|DiagnosticClient
block|{
comment|/// \brief The diagnostics machinery.
name|Diagnostic
operator|&
name|Diags
block|;
comment|/// \brief The rewriter used to perform the various code
comment|/// modifications.
name|Rewriter
name|Rewrite
block|;
comment|/// \brief The diagnostic client that performs the actual formatting
comment|/// of error messages.
name|DiagnosticClient
operator|*
name|Client
block|;
comment|/// \brief The number of rewriter failures.
name|unsigned
name|NumFailures
block|;
comment|/// \brief Locations at which we should perform fix-its.
comment|///
comment|/// When empty, perform fix-it modifications everywhere.
name|llvm
operator|::
name|SmallVector
operator|<
name|RequestedSourceLocation
block|,
literal|4
operator|>
name|FixItLocations
block|;
name|public
operator|:
comment|/// \brief Initialize a new fix-it rewriter.
name|FixItRewriter
argument_list|(
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
block|;
comment|/// \brief Destroy the fix-it rewriter.
operator|~
name|FixItRewriter
argument_list|()
block|;
comment|/// \brief Add a location where fix-it modifications should be
comment|/// performed.
name|void
name|addFixItLocation
argument_list|(
argument|RequestedSourceLocation Loc
argument_list|)
block|{
name|FixItLocations
operator|.
name|push_back
argument_list|(
name|Loc
argument_list|)
block|;   }
comment|/// \brief Write the modified source file.
comment|///
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|WriteFixedFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InFileName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutFileName
operator|=
name|std
operator|::
name|string
argument_list|()
argument_list|)
block|;
comment|/// IncludeInDiagnosticCounts - This method (whose default implementation
comment|///  returns true) indicates whether the diagnostics handled by this
comment|///  DiagnosticClient should be included in the number of diagnostics
comment|///  reported by Diagnostic.
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
block|;
comment|/// HandleDiagnostic - Handle this diagnostic, reporting it to the user or
comment|/// capturing it to a log as needed.
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
argument|Diagnostic::Level DiagLevel
argument_list|,
argument|const DiagnosticInfo&Info
argument_list|)
block|;
comment|/// \brief Emit a diagnostic via the adapted diagnostic client.
name|void
name|Diag
argument_list|(
argument|FullSourceLoc Loc
argument_list|,
argument|unsigned DiagID
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_FRONTEND_FIX_IT_REWRITER_H
end_comment

end_unit

