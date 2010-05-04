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
file|"clang/Basic/SourceLocation.h"
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
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

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
name|class
name|FixItPathRewriter
block|{
name|public
label|:
name|virtual
operator|~
name|FixItPathRewriter
argument_list|()
expr_stmt|;
comment|/// \brief This file is about to be rewritten. Return the name of the file
comment|/// that is okay to write to.
name|virtual
name|std
operator|::
name|string
name|RewriteFilename
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
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
comment|/// \brief Turn an input path into an output path. NULL implies overwriting
comment|/// the original.
name|FixItPathRewriter
operator|*
name|PathRewriter
block|;
comment|/// \brief The number of rewriter failures.
name|unsigned
name|NumFailures
block|;
name|public
operator|:
typedef|typedef
name|Rewriter
operator|::
name|buffer_iterator
name|iterator
expr_stmt|;
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
argument_list|,
name|FixItPathRewriter
operator|*
name|PathRewriter
argument_list|)
decl_stmt|;
comment|/// \brief Destroy the fix-it rewriter.
operator|~
name|FixItRewriter
argument_list|()
expr_stmt|;
comment|/// \brief Check whether there are modifications for a given file.
name|bool
name|IsModified
argument_list|(
name|FileID
name|ID
argument_list|)
decl|const
block|{
return|return
name|Rewrite
operator|.
name|getRewriteBufferFor
argument_list|(
name|ID
argument_list|)
operator|!=
name|NULL
return|;
block|}
comment|// Iteration over files with changes.
name|iterator
name|buffer_begin
parameter_list|()
block|{
return|return
name|Rewrite
operator|.
name|buffer_begin
argument_list|()
return|;
block|}
name|iterator
name|buffer_end
parameter_list|()
block|{
return|return
name|Rewrite
operator|.
name|buffer_end
argument_list|()
return|;
block|}
comment|/// \brief Write a single modified source file.
comment|///
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|WriteFixedFile
argument_list|(
name|FileID
name|ID
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|/// \brief Write the modified source files.
comment|///
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|WriteFixedFiles
parameter_list|()
function_decl|;
comment|/// IncludeInDiagnosticCounts - This method (whose default implementation
comment|/// returns true) indicates whether the diagnostics handled by this
comment|/// DiagnosticClient should be included in the number of diagnostics
comment|/// reported by Diagnostic.
name|virtual
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
expr_stmt|;
comment|/// HandleDiagnostic - Handle this diagnostic, reporting it to the user or
comment|/// capturing it to a log as needed.
name|virtual
name|void
name|HandleDiagnostic
argument_list|(
name|Diagnostic
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|DiagnosticInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
comment|/// \brief Emit a diagnostic via the adapted diagnostic client.
name|void
name|Diag
parameter_list|(
name|FullSourceLoc
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_FRONTEND_FIX_IT_REWRITER_H
end_comment

end_unit

