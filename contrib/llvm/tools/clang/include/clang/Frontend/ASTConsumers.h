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
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|CodeGenOptions
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
comment|// AST pretty-printer: prints out the AST in a format that is close to the
comment|// original C code.  The output is intended to be in a format such that
comment|// clang could re-parse the output back into the same AST, but the
comment|// implementation is still incomplete.
name|ASTConsumer
modifier|*
name|CreateASTPrinter
parameter_list|(
name|raw_ostream
modifier|*
name|OS
parameter_list|,
name|StringRef
name|FilterString
parameter_list|)
function_decl|;
comment|// AST dumper: dumps the raw AST in human-readable form to stderr; this is
comment|// intended for debugging.
name|ASTConsumer
modifier|*
name|CreateASTDumper
parameter_list|(
name|StringRef
name|FilterString
parameter_list|)
function_decl|;
comment|// AST Decl node lister: prints qualified names of all filterable AST Decl
comment|// nodes.
name|ASTConsumer
modifier|*
name|CreateASTDeclNodeLister
parameter_list|()
function_decl|;
comment|// AST XML-dumper: dumps out the AST to stderr in a very detailed XML
comment|// format; this is intended for particularly intense debugging.
name|ASTConsumer
modifier|*
name|CreateASTDumperXML
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
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

