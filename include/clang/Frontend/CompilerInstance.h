begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerInstance.h - Clang Compiler Instance ------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_COMPILERINSTANCE_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMPILERINSTANCE_H_
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInvocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

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
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_fd_ostream
decl_stmt|;
name|class
name|Timer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|DiagnosticClient
decl_stmt|;
name|class
name|ExternalASTSource
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Source
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
comment|/// CompilerInstance - Helper class for managing a single instance of the Clang
comment|/// compiler.
comment|///
comment|/// The CompilerInstance serves two purposes:
comment|///  (1) It manages the various objects which are necessary to run the compiler,
comment|///      for example the preprocessor, the target information, and the AST
comment|///      context.
comment|///  (2) It provides utility routines for constructing and manipulating the
comment|///      common Clang objects.
comment|///
comment|/// The compiler instance generally owns the instance of all the objects that it
comment|/// manages. However, clients can still share objects by manually setting the
comment|/// object and retaking ownership prior to destroying the CompilerInstance.
comment|///
comment|/// The compiler instance is intended to simplify clients, but not to lock them
comment|/// in to the compiler instance for everything. When possible, utility functions
comment|/// come in two forms; a short form that reuses the CompilerInstance objects,
comment|/// and a long form that takes explicit instances of any required objects.
name|class
name|CompilerInstance
block|{
comment|/// The LLVM context used for this instance.
name|llvm
operator|::
name|LLVMContext
operator|*
name|LLVMContext
expr_stmt|;
name|bool
name|OwnsLLVMContext
decl_stmt|;
comment|/// The options used in this compiler instance.
name|CompilerInvocation
name|Invocation
decl_stmt|;
comment|/// The diagnostics engine instance.
name|llvm
operator|::
name|OwningPtr
operator|<
name|Diagnostic
operator|>
name|Diagnostics
expr_stmt|;
comment|/// The diagnostics client instance.
name|llvm
operator|::
name|OwningPtr
operator|<
name|DiagnosticClient
operator|>
name|DiagClient
expr_stmt|;
comment|/// The target being compiled for.
name|llvm
operator|::
name|OwningPtr
operator|<
name|TargetInfo
operator|>
name|Target
expr_stmt|;
comment|/// The file manager.
name|llvm
operator|::
name|OwningPtr
operator|<
name|FileManager
operator|>
name|FileMgr
expr_stmt|;
comment|/// The source manager.
name|llvm
operator|::
name|OwningPtr
operator|<
name|SourceManager
operator|>
name|SourceMgr
expr_stmt|;
comment|/// The preprocessor.
name|llvm
operator|::
name|OwningPtr
operator|<
name|Preprocessor
operator|>
name|PP
expr_stmt|;
comment|/// The AST context.
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTContext
operator|>
name|Context
expr_stmt|;
comment|/// The AST consumer.
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTConsumer
operator|>
name|Consumer
expr_stmt|;
comment|/// The code completion consumer.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CodeCompleteConsumer
operator|>
name|CompletionConsumer
expr_stmt|;
comment|/// The frontend timer
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|Timer
operator|>
name|FrontendTimer
expr_stmt|;
comment|/// The list of active output files.
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|llvm
operator|::
name|raw_ostream
operator|*
operator|>
expr|>
name|OutputFiles
expr_stmt|;
name|public
label|:
comment|/// Create a new compiler instance with the given LLVM context, optionally
comment|/// taking ownership of it.
name|CompilerInstance
argument_list|(
argument|llvm::LLVMContext *_LLVMContext =
literal|0
argument_list|,
argument|bool _OwnsLLVMContext = true
argument_list|)
empty_stmt|;
operator|~
name|CompilerInstance
argument_list|()
expr_stmt|;
comment|/// @name LLVM Context
comment|/// {
name|bool
name|hasLLVMContext
argument_list|()
specifier|const
block|{
return|return
name|LLVMContext
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|LLVMContext
operator|&&
literal|"Compiler instance has no LLVM context!"
argument_list|)
block|;
return|return
operator|*
name|LLVMContext
return|;
block|}
comment|/// setLLVMContext - Replace the current LLVM context and take ownership of
comment|/// \arg Value.
name|void
name|setLLVMContext
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|Value
argument_list|,
name|bool
name|TakeOwnership
operator|=
name|true
argument_list|)
block|{
name|LLVMContext
operator|=
name|Value
expr_stmt|;
name|OwnsLLVMContext
operator|=
name|TakeOwnership
expr_stmt|;
block|}
comment|/// }
comment|/// @name Compiler Invocation and Options
comment|/// {
name|CompilerInvocation
modifier|&
name|getInvocation
parameter_list|()
block|{
return|return
name|Invocation
return|;
block|}
specifier|const
name|CompilerInvocation
operator|&
name|getInvocation
argument_list|()
specifier|const
block|{
return|return
name|Invocation
return|;
block|}
name|void
name|setInvocation
parameter_list|(
specifier|const
name|CompilerInvocation
modifier|&
name|Value
parameter_list|)
block|{
name|Invocation
operator|=
name|Value
expr_stmt|;
block|}
comment|/// }
comment|/// @name Forwarding Methods
comment|/// {
name|AnalyzerOptions
modifier|&
name|getAnalyzerOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getAnalyzerOpts
argument_list|()
return|;
block|}
specifier|const
name|AnalyzerOptions
operator|&
name|getAnalyzerOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getAnalyzerOpts
argument_list|()
return|;
block|}
name|CodeGenOptions
modifier|&
name|getCodeGenOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getCodeGenOpts
argument_list|()
return|;
block|}
specifier|const
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getCodeGenOpts
argument_list|()
return|;
block|}
name|DependencyOutputOptions
modifier|&
name|getDependencyOutputOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getDependencyOutputOpts
argument_list|()
return|;
block|}
specifier|const
name|DependencyOutputOptions
operator|&
name|getDependencyOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getDependencyOutputOpts
argument_list|()
return|;
block|}
name|DiagnosticOptions
modifier|&
name|getDiagnosticOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getDiagnosticOpts
argument_list|()
return|;
block|}
specifier|const
name|DiagnosticOptions
operator|&
name|getDiagnosticOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getDiagnosticOpts
argument_list|()
return|;
block|}
name|FrontendOptions
modifier|&
name|getFrontendOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getFrontendOpts
argument_list|()
return|;
block|}
specifier|const
name|FrontendOptions
operator|&
name|getFrontendOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getFrontendOpts
argument_list|()
return|;
block|}
name|HeaderSearchOptions
modifier|&
name|getHeaderSearchOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getHeaderSearchOpts
argument_list|()
return|;
block|}
specifier|const
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getHeaderSearchOpts
argument_list|()
return|;
block|}
name|LangOptions
modifier|&
name|getLangOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getLangOpts
argument_list|()
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getLangOpts
argument_list|()
return|;
block|}
name|PreprocessorOptions
modifier|&
name|getPreprocessorOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getPreprocessorOpts
argument_list|()
return|;
block|}
specifier|const
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getPreprocessorOpts
argument_list|()
return|;
block|}
name|PreprocessorOutputOptions
modifier|&
name|getPreprocessorOutputOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getPreprocessorOutputOpts
argument_list|()
return|;
block|}
specifier|const
name|PreprocessorOutputOptions
operator|&
name|getPreprocessorOutputOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getPreprocessorOutputOpts
argument_list|()
return|;
block|}
name|TargetOptions
modifier|&
name|getTargetOpts
parameter_list|()
block|{
return|return
name|Invocation
operator|.
name|getTargetOpts
argument_list|()
return|;
block|}
specifier|const
name|TargetOptions
operator|&
name|getTargetOpts
argument_list|()
specifier|const
block|{
return|return
name|Invocation
operator|.
name|getTargetOpts
argument_list|()
return|;
block|}
comment|/// }
comment|/// @name Diagnostics Engine
comment|/// {
name|bool
name|hasDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|Diagnostics
operator|!=
literal|0
return|;
block|}
name|Diagnostic
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Diagnostics
operator|&&
literal|"Compiler instance has no diagnostics!"
argument_list|)
block|;
return|return
operator|*
name|Diagnostics
return|;
block|}
comment|/// takeDiagnostics - Remove the current diagnostics engine and give ownership
comment|/// to the caller.
name|Diagnostic
modifier|*
name|takeDiagnostics
parameter_list|()
block|{
return|return
name|Diagnostics
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setDiagnostics - Replace the current diagnostics engine; the compiler
comment|/// instance takes ownership of \arg Value.
name|void
name|setDiagnostics
parameter_list|(
name|Diagnostic
modifier|*
name|Value
parameter_list|)
function_decl|;
name|DiagnosticClient
operator|&
name|getDiagnosticClient
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|DiagClient
operator|&&
literal|"Compiler instance has no diagnostic client!"
argument_list|)
block|;
return|return
operator|*
name|DiagClient
return|;
block|}
comment|/// takeDiagnosticClient - Remove the current diagnostics client and give
comment|/// ownership to the caller.
name|DiagnosticClient
modifier|*
name|takeDiagnosticClient
parameter_list|()
block|{
return|return
name|DiagClient
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setDiagnosticClient - Replace the current diagnostics client; the compiler
comment|/// instance takes ownership of \arg Value.
name|void
name|setDiagnosticClient
parameter_list|(
name|DiagnosticClient
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Target Info
comment|/// {
name|bool
name|hasTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
operator|!=
literal|0
return|;
block|}
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Target
operator|&&
literal|"Compiler instance has no target!"
argument_list|)
block|;
return|return
operator|*
name|Target
return|;
block|}
comment|/// takeTarget - Remove the current diagnostics engine and give ownership
comment|/// to the caller.
name|TargetInfo
modifier|*
name|takeTarget
parameter_list|()
block|{
return|return
name|Target
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setTarget - Replace the current diagnostics engine; the compiler
comment|/// instance takes ownership of \arg Value.
name|void
name|setTarget
parameter_list|(
name|TargetInfo
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name File Manager
comment|/// {
name|bool
name|hasFileManager
argument_list|()
specifier|const
block|{
return|return
name|FileMgr
operator|!=
literal|0
return|;
block|}
name|FileManager
operator|&
name|getFileManager
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FileMgr
operator|&&
literal|"Compiler instance has no file manager!"
argument_list|)
block|;
return|return
operator|*
name|FileMgr
return|;
block|}
comment|/// takeFileManager - Remove the current file manager and give ownership to
comment|/// the caller.
name|FileManager
modifier|*
name|takeFileManager
parameter_list|()
block|{
return|return
name|FileMgr
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setFileManager - Replace the current file manager; the compiler instance
comment|/// takes ownership of \arg Value.
name|void
name|setFileManager
parameter_list|(
name|FileManager
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Source Manager
comment|/// {
name|bool
name|hasSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
operator|!=
literal|0
return|;
block|}
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|SourceMgr
operator|&&
literal|"Compiler instance has no source manager!"
argument_list|)
block|;
return|return
operator|*
name|SourceMgr
return|;
block|}
comment|/// takeSourceManager - Remove the current source manager and give ownership
comment|/// to the caller.
name|SourceManager
modifier|*
name|takeSourceManager
parameter_list|()
block|{
return|return
name|SourceMgr
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setSourceManager - Replace the current source manager; the compiler
comment|/// instance takes ownership of \arg Value.
name|void
name|setSourceManager
parameter_list|(
name|SourceManager
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Preprocessor
comment|/// {
name|bool
name|hasPreprocessor
argument_list|()
specifier|const
block|{
return|return
name|PP
operator|!=
literal|0
return|;
block|}
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|PP
operator|&&
literal|"Compiler instance has no preprocessor!"
argument_list|)
block|;
return|return
operator|*
name|PP
return|;
block|}
comment|/// takePreprocessor - Remove the current preprocessor and give ownership to
comment|/// the caller.
name|Preprocessor
modifier|*
name|takePreprocessor
parameter_list|()
block|{
return|return
name|PP
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setPreprocessor - Replace the current preprocessor; the compiler instance
comment|/// takes ownership of \arg Value.
name|void
name|setPreprocessor
parameter_list|(
name|Preprocessor
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name ASTContext
comment|/// {
name|bool
name|hasASTContext
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|!=
literal|0
return|;
block|}
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Context
operator|&&
literal|"Compiler instance has no AST context!"
argument_list|)
block|;
return|return
operator|*
name|Context
return|;
block|}
comment|/// takeASTContext - Remove the current AST context and give ownership to the
comment|/// caller.
name|ASTContext
modifier|*
name|takeASTContext
parameter_list|()
block|{
return|return
name|Context
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setASTContext - Replace the current AST context; the compiler instance
comment|/// takes ownership of \arg Value.
name|void
name|setASTContext
parameter_list|(
name|ASTContext
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name ASTConsumer
comment|/// {
name|bool
name|hasASTConsumer
argument_list|()
specifier|const
block|{
return|return
name|Consumer
operator|!=
literal|0
return|;
block|}
name|ASTConsumer
operator|&
name|getASTConsumer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Consumer
operator|&&
literal|"Compiler instance has no AST consumer!"
argument_list|)
block|;
return|return
operator|*
name|Consumer
return|;
block|}
comment|/// takeASTConsumer - Remove the current AST consumer and give ownership to
comment|/// the caller.
name|ASTConsumer
modifier|*
name|takeASTConsumer
parameter_list|()
block|{
return|return
name|Consumer
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setASTConsumer - Replace the current AST consumer; the compiler instance
comment|/// takes ownership of \arg Value.
name|void
name|setASTConsumer
parameter_list|(
name|ASTConsumer
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Code Completion
comment|/// {
name|bool
name|hasCodeCompletionConsumer
argument_list|()
specifier|const
block|{
return|return
name|CompletionConsumer
operator|!=
literal|0
return|;
block|}
name|CodeCompleteConsumer
operator|&
name|getCodeCompletionConsumer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CompletionConsumer
operator|&&
literal|"Compiler instance has no code completion consumer!"
argument_list|)
block|;
return|return
operator|*
name|CompletionConsumer
return|;
block|}
comment|/// takeCodeCompletionConsumer - Remove the current code completion consumer
comment|/// and give ownership to the caller.
name|CodeCompleteConsumer
modifier|*
name|takeCodeCompletionConsumer
parameter_list|()
block|{
return|return
name|CompletionConsumer
operator|.
name|take
argument_list|()
return|;
block|}
comment|/// setCodeCompletionConsumer - Replace the current code completion consumer;
comment|/// the compiler instance takes ownership of \arg Value.
name|void
name|setCodeCompletionConsumer
parameter_list|(
name|CodeCompleteConsumer
modifier|*
name|Value
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Frontend timer
comment|/// {
name|bool
name|hasFrontendTimer
argument_list|()
specifier|const
block|{
return|return
name|FrontendTimer
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|Timer
operator|&
name|getFrontendTimer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FrontendTimer
operator|&&
literal|"Compiler instance has no frontend timer!"
argument_list|)
block|;
return|return
operator|*
name|FrontendTimer
return|;
block|}
comment|/// }
comment|/// @name Output Files
comment|/// {
comment|/// getOutputFileList - Get the list of (path, output stream) pairs of output
comment|/// files; the path may be empty but the stream will always be non-null.
specifier|const
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|llvm
operator|::
name|raw_ostream
operator|*
operator|>
expr|>
operator|&
name|getOutputFileList
argument_list|()
specifier|const
expr_stmt|;
comment|/// addOutputFile - Add an output file onto the list of tracked output files.
comment|///
comment|/// \param Path - The path to the output file, or empty.
comment|/// \param OS - The output stream, which should be non-null.
name|void
name|addOutputFile
argument_list|(
name|llvm
operator|::
name|StringRef
name|Path
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// ClearOutputFiles - Clear the output file list, destroying the contained
comment|/// output streams.
comment|///
comment|/// \param EraseFiles - If true, attempt to erase the files from disk.
name|void
name|ClearOutputFiles
parameter_list|(
name|bool
name|EraseFiles
parameter_list|)
function_decl|;
comment|/// }
comment|/// @name Construction Utility Methods
comment|/// {
comment|/// Create the diagnostics engine using the invocation's diagnostic options
comment|/// and replace any existing one with it.
comment|///
comment|/// Note that this routine also replaces the diagnostic client.
name|void
name|createDiagnostics
parameter_list|(
name|int
name|Argc
parameter_list|,
name|char
modifier|*
modifier|*
name|Argv
parameter_list|)
function_decl|;
comment|/// Create a Diagnostic object with a the TextDiagnosticPrinter.
comment|///
comment|/// The \arg Argc and \arg Argv arguments are used only for logging purposes,
comment|/// when the diagnostic options indicate that the compiler should output
comment|/// logging information.
comment|///
comment|/// Note that this creates an unowned DiagnosticClient, if using directly the
comment|/// caller is responsible for releasing the returned Diagnostic's client
comment|/// eventually.
comment|///
comment|/// \param Opts - The diagnostic options; note that the created text
comment|/// diagnostic object contains a reference to these options and its lifetime
comment|/// must extend past that of the diagnostic engine.
comment|///
comment|/// \return The new object on success, or null on failure.
specifier|static
name|Diagnostic
modifier|*
name|createDiagnostics
parameter_list|(
specifier|const
name|DiagnosticOptions
modifier|&
name|Opts
parameter_list|,
name|int
name|Argc
parameter_list|,
name|char
modifier|*
modifier|*
name|Argv
parameter_list|)
function_decl|;
comment|/// Create the file manager and replace any existing one with it.
name|void
name|createFileManager
parameter_list|()
function_decl|;
comment|/// Create the source manager and replace any existing one with it.
name|void
name|createSourceManager
parameter_list|()
function_decl|;
comment|/// Create the preprocessor, using the invocation, file, and source managers,
comment|/// and replace any existing one with it.
name|void
name|createPreprocessor
parameter_list|()
function_decl|;
comment|/// Create a Preprocessor object.
comment|///
comment|/// Note that this also creates a new HeaderSearch object which will be owned
comment|/// by the resulting Preprocessor.
comment|///
comment|/// \return The new object on success, or null on failure.
specifier|static
name|Preprocessor
modifier|*
name|createPreprocessor
parameter_list|(
name|Diagnostic
modifier|&
parameter_list|,
specifier|const
name|LangOptions
modifier|&
parameter_list|,
specifier|const
name|PreprocessorOptions
modifier|&
parameter_list|,
specifier|const
name|HeaderSearchOptions
modifier|&
parameter_list|,
specifier|const
name|DependencyOutputOptions
modifier|&
parameter_list|,
specifier|const
name|TargetInfo
modifier|&
parameter_list|,
name|SourceManager
modifier|&
parameter_list|,
name|FileManager
modifier|&
parameter_list|)
function_decl|;
comment|/// Create the AST context.
name|void
name|createASTContext
parameter_list|()
function_decl|;
comment|/// Create an external AST source to read a PCH file and attach it to the AST
comment|/// context.
name|void
name|createPCHExternalASTSource
argument_list|(
name|llvm
operator|::
name|StringRef
name|Path
argument_list|)
decl_stmt|;
comment|/// Create an external AST source to read a PCH file.
comment|///
comment|/// \return - The new object on success, or null on failure.
specifier|static
name|ExternalASTSource
modifier|*
name|createPCHExternalASTSource
argument_list|(
name|llvm
operator|::
name|StringRef
name|Path
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Sysroot
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|)
decl_stmt|;
comment|/// Create a code completion consumer using the invocation; note that this
comment|/// will cause the source manager to truncate the input source file at the
comment|/// completion point.
name|void
name|createCodeCompletionConsumer
parameter_list|()
function_decl|;
comment|/// Create a code completion consumer to print code completion results, at
comment|/// \arg Filename, \arg Line, and \arg Column, to the given output stream \arg
comment|/// OS.
specifier|static
name|CodeCompleteConsumer
modifier|*
name|createCodeCompletionConsumer
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Column
argument_list|,
name|bool
name|UseDebugPrinter
argument_list|,
name|bool
name|ShowMacros
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|/// Create the frontend timer and replace any existing one with it.
name|void
name|createFrontendTimer
parameter_list|()
function_decl|;
comment|/// Create the default output file (from the invocation's options) and add it
comment|/// to the list of tracked output files.
comment|///
comment|/// \return - Null on error.
name|llvm
operator|::
name|raw_fd_ostream
operator|*
name|createDefaultOutputFile
argument_list|(
argument|bool Binary = true
argument_list|,
argument|llvm::StringRef BaseInput =
literal|""
argument_list|,
argument|llvm::StringRef Extension =
literal|""
argument_list|)
expr_stmt|;
comment|/// Create a new output file and add it to the list of tracked output files,
comment|/// optionally deriving the output path name.
comment|///
comment|/// \return - Null on error.
name|llvm
operator|::
name|raw_fd_ostream
operator|*
name|createOutputFile
argument_list|(
argument|llvm::StringRef OutputPath
argument_list|,
argument|bool Binary = true
argument_list|,
argument|llvm::StringRef BaseInput =
literal|""
argument_list|,
argument|llvm::StringRef Extension =
literal|""
argument_list|)
expr_stmt|;
comment|/// Create a new output file, optionally deriving the output path name.
comment|///
comment|/// If \arg OutputPath is empty, then createOutputFile will derive an output
comment|/// path location as \arg BaseInput, with any suffix removed, and \arg
comment|/// Extension appended.
comment|///
comment|/// \param OutputPath - If given, the path to the output file.
comment|/// \param Error [out] - On failure, the error message.
comment|/// \param BaseInput - If \arg OutputPath is empty, the input path name to use
comment|/// for deriving the output path.
comment|/// \param Extension - The extension to use for derived output names.
comment|/// \param Binary - The mode to open the file in.
comment|/// \param ResultPathName [out] - If given, the result path name will be
comment|/// stored here on success.
specifier|static
name|llvm
operator|::
name|raw_fd_ostream
operator|*
name|createOutputFile
argument_list|(
argument|llvm::StringRef OutputPath
argument_list|,
argument|std::string&Error
argument_list|,
argument|bool Binary = true
argument_list|,
argument|llvm::StringRef BaseInput =
literal|""
argument_list|,
argument|llvm::StringRef Extension =
literal|""
argument_list|,
argument|std::string *ResultPathName =
literal|0
argument_list|)
expr_stmt|;
comment|/// }
comment|/// @name Initialization Utility Methods
comment|/// {
comment|/// InitializeSourceManager - Initialize the source manager to set InputFile
comment|/// as the main file.
comment|///
comment|/// \return True on success.
name|bool
name|InitializeSourceManager
argument_list|(
name|llvm
operator|::
name|StringRef
name|InputFile
argument_list|)
decl_stmt|;
comment|/// InitializeSourceManager - Initialize the source manager to set InputFile
comment|/// as the main file.
comment|///
comment|/// \return True on success.
specifier|static
name|bool
name|InitializeSourceManager
argument_list|(
name|llvm
operator|::
name|StringRef
name|InputFile
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|FrontendOptions
operator|&
name|Opts
argument_list|)
decl_stmt|;
comment|/// }
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

