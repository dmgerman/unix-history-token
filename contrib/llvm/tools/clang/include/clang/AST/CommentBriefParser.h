begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommentBriefParser.h - Dumb comment parser -------------*- C++ -*-===//
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
comment|//  This file defines a very simple Doxygen comment parser.
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
name|LLVM_CLANG_AST_COMMENTBRIEFPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_COMMENTBRIEFPARSER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CommentLexer.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|comments
block|{
comment|/// A very simple comment parser that extracts "a brief description".
comment|///
comment|/// Due to a variety of comment styles, it considers the following as "a brief
comment|/// description", in order of priority:
comment|/// \li a \\brief or \\short command,
comment|/// \li the first paragraph,
comment|/// \li a \\result or \\return or \\returns paragraph.
name|class
name|BriefParser
block|{
name|Lexer
modifier|&
name|L
decl_stmt|;
specifier|const
name|CommandTraits
modifier|&
name|Traits
decl_stmt|;
comment|/// Current lookahead token.
name|Token
name|Tok
decl_stmt|;
name|SourceLocation
name|ConsumeToken
parameter_list|()
block|{
name|SourceLocation
name|Loc
init|=
name|Tok
operator|.
name|getLocation
argument_list|()
decl_stmt|;
name|L
operator|.
name|lex
argument_list|(
name|Tok
argument_list|)
expr_stmt|;
return|return
name|Loc
return|;
block|}
name|public
label|:
name|BriefParser
argument_list|(
name|Lexer
operator|&
name|L
argument_list|,
specifier|const
name|CommandTraits
operator|&
name|Traits
argument_list|)
expr_stmt|;
comment|/// Return the best "brief description" we can find.
name|std
operator|::
name|string
name|Parse
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace comments
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

