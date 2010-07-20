begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTConsumers.h - ASTConsumer implementations -----------*- C++ -*-===//
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
comment|// AST Consumers.
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
name|REWRITE_ASTCONSUMERS_H
end_ifndef

begin_define
define|#
directive|define
name|REWRITE_ASTCONSUMERS_H
end_define

begin_include
include|#
directive|include
file|<string>
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
name|ASTConsumer
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
comment|// ObjC rewriter: attempts tp rewrite ObjC constructs into pure C code.
comment|// This is considered experimental, and only works with Apple's ObjC runtime.
name|ASTConsumer
modifier|*
name|CreateObjCRewriter
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InFile
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LOpts
argument_list|,
name|bool
name|SilenceRewriteMacroWarning
argument_list|)
decl_stmt|;
comment|/// CreateHTMLPrinter - Create an AST consumer which rewrites source code to
comment|/// HTML with syntax highlighting suitable for viewing in a web-browser.
name|ASTConsumer
modifier|*
name|CreateHTMLPrinter
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|,
name|bool
name|SyntaxHighlight
operator|=
name|true
argument_list|,
name|bool
name|HighlightMacros
operator|=
name|true
argument_list|)
decl_stmt|;
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

