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
name|LLVM_CLANG_REWRITE_FRONTEND_FIXITREWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_FRONTEND_FIXITREWRITER_H
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
file|"clang/Edit/EditedSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/Core/Rewriter.h"
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
name|class
name|FixItOptions
block|{
name|public
label|:
name|FixItOptions
argument_list|()
operator|:
name|FixWhatYouCan
argument_list|(
name|false
argument_list|)
operator|,
name|FixOnlyWarnings
argument_list|(
name|false
argument_list|)
operator|,
name|Silent
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|FixItOptions
argument_list|()
expr_stmt|;
comment|/// \brief This file is about to be rewritten. Return the name of the file
comment|/// that is okay to write to.
comment|///
comment|/// \param fd out parameter for file descriptor. After the call it may be set
comment|/// to an open file descriptor for the returned filename, or it will be -1
comment|/// otherwise.
comment|///
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
argument_list|,
name|int
operator|&
name|fd
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Whether to abort fixing a file when not all errors could be fixed.
name|bool
name|FixWhatYouCan
decl_stmt|;
comment|/// \brief Whether to only fix warnings and not errors.
name|bool
name|FixOnlyWarnings
decl_stmt|;
comment|/// \brief If true, only pass the diagnostic to the actual diagnostic consumer
comment|/// if it is an error or a fixit was applied as part of the diagnostic.
comment|/// It basically silences warnings without accompanying fixits.
name|bool
name|Silent
decl_stmt|;
block|}
empty_stmt|;
name|class
name|FixItRewriter
range|:
name|public
name|DiagnosticConsumer
block|{
comment|/// \brief The diagnostics machinery.
name|DiagnosticsEngine
operator|&
name|Diags
block|;
name|edit
operator|::
name|EditedSource
name|Editor
block|;
comment|/// \brief The rewriter used to perform the various code
comment|/// modifications.
name|Rewriter
name|Rewrite
block|;
comment|/// \brief The diagnostic client that performs the actual formatting
comment|/// of error messages.
name|DiagnosticConsumer
operator|*
name|Client
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|DiagnosticConsumer
operator|>
name|Owner
block|;
comment|/// \brief Turn an input path into an output path. NULL implies overwriting
comment|/// the original.
name|FixItOptions
operator|*
name|FixItOpts
block|;
comment|/// \brief The number of rewriter failures.
name|unsigned
name|NumFailures
block|;
comment|/// \brief Whether the previous diagnostic was not passed to the consumer.
name|bool
name|PrevDiagSilenced
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
name|DiagnosticsEngine
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
name|FixItOptions
operator|*
name|FixItOpts
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
name|nullptr
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
parameter_list|(
name|FileID
name|ID
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Write the modified source files.
comment|///
comment|/// \returns true if there was an error, false otherwise.
name|bool
name|WriteFixedFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|std
operator|::
name|string
operator|>
expr|>
operator|*
name|RewrittenFiles
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// IncludeInDiagnosticCounts - This method (whose default implementation
comment|/// returns true) indicates whether the diagnostics handled by this
comment|/// DiagnosticConsumer should be included in the number of diagnostics
comment|/// reported by DiagnosticsEngine.
name|bool
name|IncludeInDiagnosticCounts
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|/// HandleDiagnostic - Handle this diagnostic, reporting it to the user or
comment|/// capturing it to a log as needed.
name|void
name|HandleDiagnostic
argument_list|(
name|DiagnosticsEngine
operator|::
name|Level
name|DiagLevel
argument_list|,
specifier|const
name|Diagnostic
operator|&
name|Info
argument_list|)
name|override
decl_stmt|;
comment|/// \brief Emit a diagnostic via the adapted diagnostic client.
name|void
name|Diag
parameter_list|(
name|SourceLocation
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

end_unit

