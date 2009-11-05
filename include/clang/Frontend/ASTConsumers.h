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
name|DRIVER_ASTCONSUMERS_H
end_ifndef

begin_define
define|#
directive|define
name|DRIVER_ASTCONSUMERS_H
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
name|class
name|Module
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
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
name|ASTConsumer
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|CompileOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|// AST pretty-printer: prints out the AST in a format that is close to the
comment|// original C code.  The output is intended to be in a format such that
comment|// clang could re-parse the output back into the same AST, but the
comment|// implementation is still incomplete.
name|ASTConsumer
modifier|*
name|CreateASTPrinter
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|// AST XML-printer: prints out the AST in a XML format
comment|// The output is intended to be in a format such that
comment|// clang or any other tool could re-parse the output back into the same AST,
comment|// but the implementation is still incomplete.
name|ASTConsumer
modifier|*
name|CreateASTPrinterXML
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|// AST dumper: dumps the raw AST in human-readable form to stderr; this is
comment|// intended for debugging.
name|ASTConsumer
modifier|*
name|CreateASTDumper
parameter_list|()
function_decl|;
comment|// Graphical AST viewer: for each function definition, creates a graph of
comment|// the AST and displays it with the graph viewer "dotty".  Also outputs
comment|// function declarations to stderr.
name|ASTConsumer
modifier|*
name|CreateASTViewer
parameter_list|()
function_decl|;
comment|// DeclContext printer: prints out the DeclContext tree in human-readable form
comment|// to stderr; this is intended for debugging.
name|ASTConsumer
modifier|*
name|CreateDeclContextPrinter
parameter_list|()
function_decl|;
comment|// RecordLayout dumper: prints out the record layout information for all records
comment|// in the translation unit; this is intended for debugging.
name|ASTConsumer
modifier|*
name|CreateRecordLayoutDumper
parameter_list|()
function_decl|;
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
comment|// LLVM code generator: uses the code generation backend to generate LLVM
comment|// assembly. This runs optimizations depending on the CompileOptions
comment|// parameter. The output depends on the Action parameter.
enum|enum
name|BackendAction
block|{
name|Backend_EmitAssembly
block|,
comment|// Emit native assembly
name|Backend_EmitBC
block|,
comment|// Emit LLVM bitcode file
name|Backend_EmitLL
block|,
comment|// Emit human-readable LLVM assembly
name|Backend_EmitNothing
comment|// Don't emit anything (benchmarking mode)
block|}
enum|;
name|ASTConsumer
modifier|*
name|CreateBackendConsumer
argument_list|(
name|BackendAction
name|Action
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Features
argument_list|,
specifier|const
name|CompileOptions
operator|&
name|CompileOpts
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ModuleID
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
name|llvm
operator|::
name|LLVMContext
operator|&
name|C
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
comment|// PCH generator: generates a precompiled header file; this file can be
comment|// used later with the PCHReader (clang-cc option -include-pch)
comment|// to speed up compile times.
name|ASTConsumer
modifier|*
name|CreatePCHGenerator
argument_list|(
specifier|const
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|// Block rewriter: rewrites code using the Apple blocks extension to pure
comment|// C code.  Output is always sent to stdout.
name|ASTConsumer
modifier|*
name|CreateBlockRewriter
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InFile
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
decl_stmt|;
comment|// Inheritance viewer: for C++ code, creates a graph of the inheritance
comment|// tree for the given class and displays it with "dotty".
name|ASTConsumer
modifier|*
name|CreateInheritanceViewer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|clsname
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

