begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FrontendOptions.h --------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_FRONTEND_FRONTENDOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_FRONTENDOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/CommandLineSourceLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|frontend
block|{
enum|enum
name|ActionKind
block|{
name|ASTDump
block|,
comment|///< Parse ASTs and dump them.
name|ASTPrint
block|,
comment|///< Parse ASTs and print them.
name|ASTPrintXML
block|,
comment|///< Parse ASTs and print them in XML.
name|ASTView
block|,
comment|///< Parse ASTs and view them in Graphviz.
name|DumpRawTokens
block|,
comment|///< Dump out raw tokens.
name|DumpRecordLayouts
block|,
comment|///< Dump record layout information.
name|DumpTokens
block|,
comment|///< Dump out preprocessed tokens.
name|EmitAssembly
block|,
comment|///< Emit a .s file.
name|EmitBC
block|,
comment|///< Emit a .bc file.
name|EmitHTML
block|,
comment|///< Translate input source into HTML.
name|EmitLLVM
block|,
comment|///< Emit a .ll file.
name|EmitLLVMOnly
block|,
comment|///< Generate LLVM IR, but do not
name|FixIt
block|,
comment|///< Parse and apply any fixits to the source.
name|GeneratePCH
block|,
comment|///< Generate pre-compiled header.
name|GeneratePTH
block|,
comment|///< Generate pre-tokenized header.
name|InheritanceView
block|,
comment|///< View C++ inheritance for a specified class.
name|ParseNoop
block|,
comment|///< Parse with noop callbacks.
name|ParsePrintCallbacks
block|,
comment|///< Parse and print each callback.
name|ParseSyntaxOnly
block|,
comment|///< Parse and perform semantic analysis.
name|PluginAction
block|,
comment|///< Run a plugin action, \see ActionName.
name|PrintDeclContext
block|,
comment|///< Print DeclContext and their Decls.
name|PrintPreprocessedInput
block|,
comment|///< -E mode.
name|RewriteBlocks
block|,
comment|///< ObjC->C Rewriter for Blocks.
name|RewriteMacros
block|,
comment|///< Expand macros but not #includes.
name|RewriteObjC
block|,
comment|///< ObjC->C Rewriter.
name|RewriteTest
block|,
comment|///< Rewriter playground
name|RunAnalysis
block|,
comment|///< Run one or more source code analyses.
name|RunPreprocessorOnly
comment|///< Just lex, no output.
block|}
enum|;
block|}
comment|/// FrontendOptions - Options for controlling the behavior of the frontend.
name|class
name|FrontendOptions
block|{
name|public
label|:
enum|enum
name|InputKind
block|{
name|IK_None
block|,
name|IK_Asm
block|,
name|IK_C
block|,
name|IK_CXX
block|,
name|IK_ObjC
block|,
name|IK_ObjCXX
block|,
name|IK_PreprocessedC
block|,
name|IK_PreprocessedCXX
block|,
name|IK_PreprocessedObjC
block|,
name|IK_PreprocessedObjCXX
block|,
name|IK_OpenCL
block|,
name|IK_AST
block|}
enum|;
name|unsigned
name|DebugCodeCompletionPrinter
range|:
literal|1
decl_stmt|;
comment|///< Use the debug printer for code
comment|/// completion results.
name|unsigned
name|DisableFree
range|:
literal|1
decl_stmt|;
comment|///< Disable memory freeing on exit.
name|unsigned
name|EmptyInputOnly
range|:
literal|1
decl_stmt|;
comment|///< Force input files to be treated
comment|/// as if they were empty, for timing
comment|/// the frontend startup.
name|unsigned
name|RelocatablePCH
range|:
literal|1
decl_stmt|;
comment|///< When generating PCH files,
comment|/// instruct the PCH writer to create
comment|/// relocatable PCH files.
name|unsigned
name|ShowMacrosInCodeCompletion
range|:
literal|1
decl_stmt|;
comment|///< Show macros in code completion
comment|/// results.
name|unsigned
name|ShowStats
range|:
literal|1
decl_stmt|;
comment|///< Show frontend performance
comment|/// metrics and statistics.
name|unsigned
name|ShowTimers
range|:
literal|1
decl_stmt|;
comment|///< Show timers for individual
comment|/// actions.
comment|/// The input files and their types.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|InputKind
operator|,
name|std
operator|::
name|string
operator|>
expr|>
name|Inputs
expr_stmt|;
comment|/// The output file, if any.
name|std
operator|::
name|string
name|OutputFile
expr_stmt|;
comment|/// If given, the name for a C++ class to view the inheritance of.
name|std
operator|::
name|string
name|ViewClassInheritance
expr_stmt|;
comment|/// A list of locations to apply fix-its at.
name|std
operator|::
name|vector
operator|<
name|ParsedSourceLocation
operator|>
name|FixItLocations
expr_stmt|;
comment|/// If given, enable code completion at the provided location.
name|ParsedSourceLocation
name|CodeCompletionAt
decl_stmt|;
comment|/// The frontend action to perform.
name|frontend
operator|::
name|ActionKind
name|ProgramAction
expr_stmt|;
comment|/// The name of the action to run when using a plugin action.
name|std
operator|::
name|string
name|ActionName
expr_stmt|;
name|public
label|:
name|FrontendOptions
argument_list|()
block|{
name|DebugCodeCompletionPrinter
operator|=
literal|0
expr_stmt|;
name|DisableFree
operator|=
literal|0
expr_stmt|;
name|EmptyInputOnly
operator|=
literal|0
expr_stmt|;
name|ProgramAction
operator|=
name|frontend
operator|::
name|ParseSyntaxOnly
expr_stmt|;
name|ActionName
operator|=
literal|""
expr_stmt|;
name|RelocatablePCH
operator|=
literal|0
expr_stmt|;
name|ShowMacrosInCodeCompletion
operator|=
literal|0
expr_stmt|;
name|ShowStats
operator|=
literal|0
expr_stmt|;
name|ShowTimers
operator|=
literal|0
expr_stmt|;
block|}
comment|/// getInputKindForExtension - Return the appropriate input kind for a file
comment|/// extension. For example, "c" would return IK_C.
comment|///
comment|/// \return The input kind for the extension, or IK_None if the extension is
comment|/// not recognized.
specifier|static
name|InputKind
name|getInputKindForExtension
argument_list|(
name|llvm
operator|::
name|StringRef
name|Extension
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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

