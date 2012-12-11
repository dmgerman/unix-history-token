begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- HTMLRewrite.h - Translate source code into prettified HTML ---*- C++ -*-//
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
comment|//  This file defines a set of functions used for translating source code
end_comment

begin_comment
comment|//  into beautified HTML.
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
name|LLVM_CLANG_HTMLREWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_HTMLREWRITER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Rewriter
decl_stmt|;
name|class
name|RewriteBuffer
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|namespace
name|html
block|{
comment|/// HighlightRange - Highlight a range in the source code with the specified
comment|/// start/end tags.  B/E must be in the same file.  This ensures that
comment|/// start/end tags are placed at the start/end of each line if the range is
comment|/// multiline.
name|void
name|HighlightRange
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|SourceLocation
name|B
parameter_list|,
name|SourceLocation
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|StartTag
parameter_list|,
specifier|const
name|char
modifier|*
name|EndTag
parameter_list|)
function_decl|;
comment|/// HighlightRange - Highlight a range in the source code with the specified
comment|/// start/end tags.  The Start/end of the range must be in the same file.
comment|/// This ensures that start/end tags are placed at the start/end of each line
comment|/// if the range is multiline.
specifier|inline
name|void
name|HighlightRange
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|char
modifier|*
name|StartTag
parameter_list|,
specifier|const
name|char
modifier|*
name|EndTag
parameter_list|)
block|{
name|HighlightRange
argument_list|(
name|R
argument_list|,
name|Range
operator|.
name|getBegin
argument_list|()
argument_list|,
name|Range
operator|.
name|getEnd
argument_list|()
argument_list|,
name|StartTag
argument_list|,
name|EndTag
argument_list|)
expr_stmt|;
block|}
comment|/// HighlightRange - This is the same as the above method, but takes
comment|/// decomposed file locations.
name|void
name|HighlightRange
parameter_list|(
name|RewriteBuffer
modifier|&
name|RB
parameter_list|,
name|unsigned
name|B
parameter_list|,
name|unsigned
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|BufferStart
parameter_list|,
specifier|const
name|char
modifier|*
name|StartTag
parameter_list|,
specifier|const
name|char
modifier|*
name|EndTag
parameter_list|)
function_decl|;
comment|/// EscapeText - HTMLize a specified file so that special characters are
comment|/// are translated so that they are not interpreted as HTML tags.
name|void
name|EscapeText
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|FileID
name|FID
parameter_list|,
name|bool
name|EscapeSpaces
init|=
name|false
parameter_list|,
name|bool
name|ReplaceTabs
init|=
name|false
parameter_list|)
function_decl|;
comment|/// EscapeText - HTMLized the provided string so that special characters
comment|///  in 's' are not interpreted as HTML tags.  Unlike the version of
comment|///  EscapeText that rewrites a file, this version by default replaces tabs
comment|///  with spaces.
name|std
operator|::
name|string
name|EscapeText
argument_list|(
argument|const std::string& s
argument_list|,
argument|bool EscapeSpaces = false
argument_list|,
argument|bool ReplaceTabs = false
argument_list|)
expr_stmt|;
name|void
name|AddLineNumbers
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|FileID
name|FID
parameter_list|)
function_decl|;
name|void
name|AddHeaderFooterInternalBuiltinCSS
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|FileID
name|FID
parameter_list|,
specifier|const
name|char
modifier|*
name|title
init|=
name|NULL
parameter_list|)
function_decl|;
comment|/// SyntaxHighlight - Relex the specified FileID and annotate the HTML with
comment|/// information about keywords, comments, etc.
name|void
name|SyntaxHighlight
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|FileID
name|FID
parameter_list|,
specifier|const
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
comment|/// HighlightMacros - This uses the macro table state from the end of the
comment|/// file, to reexpand macros and insert (into the HTML) information about the
comment|/// macro expansions.  This won't be perfectly perfect, but it will be
comment|/// reasonably close.
name|void
name|HighlightMacros
parameter_list|(
name|Rewriter
modifier|&
name|R
parameter_list|,
name|FileID
name|FID
parameter_list|,
specifier|const
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
block|}
comment|// end html namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

