begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TokenAnalyzer.h - Analyze Token Streams ----------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares an abstract TokenAnalyzer, and associated helper
end_comment

begin_comment
comment|/// classes. TokenAnalyzer can be extended to generate replacements based on
end_comment

begin_comment
comment|/// an annotated and pre-processed token stream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LIB_FORMAT_TOKENANALYZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_TOKENANALYZER_H
end_define

begin_include
include|#
directive|include
file|"AffectedRangeManager.h"
end_include

begin_include
include|#
directive|include
file|"Encoding.h"
end_include

begin_include
include|#
directive|include
file|"FormatToken.h"
end_include

begin_include
include|#
directive|include
file|"FormatTokenLexer.h"
end_include

begin_include
include|#
directive|include
file|"TokenAnnotator.h"
end_include

begin_include
include|#
directive|include
file|"UnwrappedLineParser.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Format/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
name|class
name|Environment
block|{
name|public
label|:
name|Environment
argument_list|(
argument|SourceManager&SM
argument_list|,
argument|FileID ID
argument_list|,
argument|ArrayRef<CharSourceRange> Ranges
argument_list|)
block|:
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|CharRanges
argument_list|(
name|Ranges
operator|.
name|begin
argument_list|()
argument_list|,
name|Ranges
operator|.
name|end
argument_list|()
argument_list|)
operator|,
name|SM
argument_list|(
argument|SM
argument_list|)
block|{}
name|Environment
argument_list|(
argument|FileID ID
argument_list|,
argument|std::unique_ptr<FileManager> FileMgr
argument_list|,
argument|std::unique_ptr<SourceManager> VirtualSM
argument_list|,
argument|std::unique_ptr<DiagnosticsEngine> Diagnostics
argument_list|,
argument|const std::vector<CharSourceRange>&CharRanges
argument_list|)
operator|:
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|CharRanges
argument_list|(
name|CharRanges
operator|.
name|begin
argument_list|()
argument_list|,
name|CharRanges
operator|.
name|end
argument_list|()
argument_list|)
operator|,
name|SM
argument_list|(
operator|*
name|VirtualSM
argument_list|)
operator|,
name|FileMgr
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|FileMgr
argument_list|)
argument_list|)
operator|,
name|VirtualSM
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|VirtualSM
argument_list|)
argument_list|)
operator|,
name|Diagnostics
argument_list|(
argument|std::move(Diagnostics)
argument_list|)
block|{}
comment|// This sets up an virtual file system with file \p FileName containing \p
comment|// Code.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|Environment
operator|>
name|CreateVirtualEnvironment
argument_list|(
argument|StringRef Code
argument_list|,
argument|StringRef FileName
argument_list|,
argument|ArrayRef<tooling::Range> Ranges
argument_list|)
expr_stmt|;
name|FileID
name|getFileID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|getCharRanges
argument_list|()
specifier|const
block|{
return|return
name|CharRanges
return|;
block|}
specifier|const
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SM
return|;
block|}
name|private
label|:
name|FileID
name|ID
decl_stmt|;
name|SmallVector
operator|<
name|CharSourceRange
operator|,
literal|8
operator|>
name|CharRanges
expr_stmt|;
name|SourceManager
modifier|&
name|SM
decl_stmt|;
comment|// The order of these fields are important - they should be in the same order
comment|// as they are created in `CreateVirtualEnvironment` so that they can be
comment|// deleted in the reverse order as they are created.
name|std
operator|::
name|unique_ptr
operator|<
name|FileManager
operator|>
name|FileMgr
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SourceManager
operator|>
name|VirtualSM
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DiagnosticsEngine
operator|>
name|Diagnostics
expr_stmt|;
block|}
empty_stmt|;
name|class
name|TokenAnalyzer
range|:
name|public
name|UnwrappedLineConsumer
block|{
name|public
operator|:
name|TokenAnalyzer
argument_list|(
specifier|const
name|Environment
operator|&
name|Env
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|)
block|;
name|tooling
operator|::
name|Replacements
name|process
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|tooling
operator|::
name|Replacements
name|analyze
argument_list|(
name|TokenAnnotator
operator|&
name|Annotator
argument_list|,
name|SmallVectorImpl
operator|<
name|AnnotatedLine
operator|*
operator|>
operator|&
name|AnnotatedLines
argument_list|,
name|FormatTokenLexer
operator|&
name|Tokens
argument_list|)
operator|=
literal|0
block|;
name|void
name|consumeUnwrappedLine
argument_list|(
argument|const UnwrappedLine&TheLine
argument_list|)
name|override
block|;
name|void
name|finishRun
argument_list|()
name|override
block|;
name|FormatStyle
name|Style
block|;
comment|// Stores Style, FileID and SourceManager etc.
specifier|const
name|Environment
operator|&
name|Env
block|;
comment|// AffectedRangeMgr stores ranges to be fixed.
name|AffectedRangeManager
name|AffectedRangeMgr
block|;
name|SmallVector
operator|<
name|SmallVector
operator|<
name|UnwrappedLine
block|,
literal|16
operator|>
block|,
literal|2
operator|>
name|UnwrappedLines
block|;
name|encoding
operator|::
name|Encoding
name|Encoding
block|; }
decl_stmt|;
block|}
comment|// end namespace format
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

