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
file|"clang/Basic/LLVM.h"
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
name|ASTConsumer
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
comment|// ObjC rewriter: attempts to rewrite ObjC constructs into pure C code.
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
name|raw_ostream
operator|*
name|OS
argument_list|,
name|DiagnosticsEngine
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
name|ASTConsumer
modifier|*
name|CreateModernObjCRewriter
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InFile
argument_list|,
name|raw_ostream
operator|*
name|OS
argument_list|,
name|DiagnosticsEngine
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
argument_list|,
name|bool
name|LineInfo
argument_list|)
decl_stmt|;
comment|/// CreateHTMLPrinter - Create an AST consumer which rewrites source code to
comment|/// HTML with syntax highlighting suitable for viewing in a web-browser.
name|ASTConsumer
modifier|*
name|CreateHTMLPrinter
parameter_list|(
name|raw_ostream
modifier|*
name|OS
parameter_list|,
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|bool
name|SyntaxHighlight
init|=
name|true
parameter_list|,
name|bool
name|HighlightMacros
init|=
name|true
parameter_list|)
function_decl|;
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

