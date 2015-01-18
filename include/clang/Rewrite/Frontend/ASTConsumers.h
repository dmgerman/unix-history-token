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
name|LLVM_CLANG_REWRITE_FRONTEND_ASTCONSUMERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_FRONTEND_ASTCONSUMERS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateObjCRewriter
argument_list|(
argument|const std::string&InFile
argument_list|,
argument|raw_ostream *OS
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|,
argument|const LangOptions&LOpts
argument_list|,
argument|bool SilenceRewriteMacroWarning
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateModernObjCRewriter
argument_list|(
argument|const std::string&InFile
argument_list|,
argument|raw_ostream *OS
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|,
argument|const LangOptions&LOpts
argument_list|,
argument|bool SilenceRewriteMacroWarning
argument_list|,
argument|bool LineInfo
argument_list|)
expr_stmt|;
comment|/// CreateHTMLPrinter - Create an AST consumer which rewrites source code to
comment|/// HTML with syntax highlighting suitable for viewing in a web-browser.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateHTMLPrinter
argument_list|(
argument|raw_ostream *OS
argument_list|,
argument|Preprocessor&PP
argument_list|,
argument|bool SyntaxHighlight = true
argument_list|,
argument|bool HighlightMacros = true
argument_list|)
expr_stmt|;
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

