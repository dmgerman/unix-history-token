begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FrontendAction.h - Generic Frontend Action Interface ----*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_FRONTENDACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_FRONTENDACTION_H
end_define

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
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|ASTMergeAction
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
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
name|IK_CUDA
block|,
name|IK_AST
block|,
name|IK_LLVM_IR
block|}
enum|;
comment|/// FrontendAction - Abstract base class for actions which can be performed by
comment|/// the frontend.
name|class
name|FrontendAction
block|{
name|std
operator|::
name|string
name|CurrentFile
expr_stmt|;
name|InputKind
name|CurrentFileKind
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTUnit
operator|>
name|CurrentASTUnit
expr_stmt|;
name|CompilerInstance
modifier|*
name|Instance
decl_stmt|;
name|friend
name|class
name|ASTMergeAction
decl_stmt|;
name|private
label|:
name|ASTConsumer
modifier|*
name|CreateWrappedASTConsumer
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|,
name|llvm
operator|::
name|StringRef
name|InFile
argument_list|)
decl_stmt|;
name|protected
label|:
comment|/// @name Implementation Action Interface
comment|/// @{
comment|/// CreateASTConsumer - Create the AST consumer object for this action, if
comment|/// supported.
comment|///
comment|/// This routine is called as part of \see BeginSourceAction(), which will
comment|/// fail if the AST consumer cannot be created. This will not be called if the
comment|/// action has indicated that it only uses the preprocessor.
comment|///
comment|/// \param CI - The current compiler instance, provided as a convenience, \see
comment|/// getCompilerInstance().
comment|///
comment|/// \param InFile - The current input file, provided as a convenience, \see
comment|/// getCurrentFile().
comment|///
comment|/// \return The new AST consumer, or 0 on failure.
name|virtual
name|ASTConsumer
modifier|*
name|CreateASTConsumer
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|,
name|llvm
operator|::
name|StringRef
name|InFile
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// BeginSourceFileAction - Callback at the start of processing a single
comment|/// input.
comment|///
comment|/// \return True on success; on failure \see ExecutionAction() and
comment|/// EndSourceFileAction() will not be called.
name|virtual
name|bool
name|BeginSourceFileAction
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|,
name|llvm
operator|::
name|StringRef
name|Filename
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// ExecuteAction - Callback to run the program action, using the initialized
comment|/// compiler instance.
comment|///
comment|/// This routine is guaranteed to only be called between \see
comment|/// BeginSourceFileAction() and \see EndSourceFileAction().
name|virtual
name|void
name|ExecuteAction
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// EndSourceFileAction - Callback at the end of processing a single input;
comment|/// this is guaranteed to only be called following a successful call to
comment|/// BeginSourceFileAction (and BeingSourceFile).
name|virtual
name|void
name|EndSourceFileAction
parameter_list|()
block|{}
comment|/// @}
name|public
label|:
name|FrontendAction
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|FrontendAction
argument_list|()
expr_stmt|;
comment|/// @name Compiler Instance Access
comment|/// @{
name|CompilerInstance
operator|&
name|getCompilerInstance
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Instance
operator|&&
literal|"Compiler instance not registered!"
argument_list|)
block|;
return|return
operator|*
name|Instance
return|;
block|}
name|void
name|setCompilerInstance
parameter_list|(
name|CompilerInstance
modifier|*
name|Value
parameter_list|)
block|{
name|Instance
operator|=
name|Value
expr_stmt|;
block|}
comment|/// @}
comment|/// @name Current File Information
comment|/// @{
name|bool
name|isCurrentFileAST
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentFile
operator|.
name|empty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
name|CurrentASTUnit
operator|!=
literal|0
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getCurrentFile
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentFile
operator|.
name|empty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
name|CurrentFile
return|;
block|}
name|InputKind
name|getCurrentFileKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentFile
operator|.
name|empty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
name|CurrentFileKind
return|;
block|}
name|ASTUnit
operator|&
name|getCurrentASTUnit
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CurrentASTUnit
operator|&&
literal|"No current AST unit!"
argument_list|)
block|;
return|return
operator|*
name|CurrentASTUnit
return|;
block|}
name|ASTUnit
modifier|*
name|takeCurrentASTUnit
parameter_list|()
block|{
return|return
name|CurrentASTUnit
operator|.
name|take
argument_list|()
return|;
block|}
name|void
name|setCurrentFile
argument_list|(
name|llvm
operator|::
name|StringRef
name|Value
argument_list|,
name|InputKind
name|Kind
argument_list|,
name|ASTUnit
operator|*
name|AST
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Supported Modes
comment|/// @{
comment|/// usesPreprocessorOnly - Does this action only use the preprocessor? If so
comment|/// no AST context will be created and this action will be invalid with AST
comment|/// file inputs.
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// usesCompleteTranslationUnit - For AST based actions, should the
comment|/// translation unit be completed?
name|virtual
name|bool
name|usesCompleteTranslationUnit
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// hasPCHSupport - Does this action support use with PCH?
name|virtual
name|bool
name|hasPCHSupport
argument_list|()
specifier|const
block|{
return|return
operator|!
name|usesPreprocessorOnly
argument_list|()
return|;
block|}
comment|/// hasASTFileSupport - Does this action support use with AST files?
name|virtual
name|bool
name|hasASTFileSupport
argument_list|()
specifier|const
block|{
return|return
operator|!
name|usesPreprocessorOnly
argument_list|()
return|;
block|}
comment|/// hasIRSupport - Does this action support use with IR files?
name|virtual
name|bool
name|hasIRSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// hasCodeCompletionSupport - Does this action support use with code
comment|/// completion?
name|virtual
name|bool
name|hasCodeCompletionSupport
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// @}
comment|/// @name Public Action Interface
comment|/// @{
comment|/// BeginSourceFile - Prepare the action for processing the input file \arg
comment|/// Filename; this is run after the options and frontend have been
comment|/// initialized, but prior to executing any per-file processing.
comment|///
comment|/// \param CI - The compiler instance this action is being run from. The
comment|/// action may store and use this object up until the matching EndSourceFile
comment|/// action.
comment|///
comment|/// \param Filename - The input filename, which will be made available to
comment|/// clients via \see getCurrentFile().
comment|///
comment|/// \param InputKind - The type of input. Some input kinds are handled
comment|/// specially, for example AST inputs, since the AST file itself contains
comment|/// several objects which would normally be owned by the
comment|/// CompilerInstance. When processing AST input files, these objects should
comment|/// generally not be initialized in the CompilerInstance -- they will
comment|/// automatically be shared with the AST file in between \see
comment|/// BeginSourceFile() and \see EndSourceFile().
comment|///
comment|/// \return True on success; the compilation of this file should be aborted
comment|/// and neither Execute nor EndSourceFile should be called.
name|bool
name|BeginSourceFile
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|,
name|llvm
operator|::
name|StringRef
name|Filename
argument_list|,
name|InputKind
name|Kind
argument_list|)
decl_stmt|;
comment|/// Execute - Set the source managers main input file, and run the action.
name|void
name|Execute
parameter_list|()
function_decl|;
comment|/// EndSourceFile - Perform any per-file post processing, deallocate per-file
comment|/// objects, and run statistics and output file cleanup code.
name|void
name|EndSourceFile
parameter_list|()
function_decl|;
comment|/// @}
block|}
empty_stmt|;
comment|/// ASTFrontendAction - Abstract base class to use for AST consumer based
comment|/// frontend actions.
name|class
name|ASTFrontendAction
range|:
name|public
name|FrontendAction
block|{
name|protected
operator|:
comment|/// ExecuteAction - Implement the ExecuteAction interface by running Sema on
comment|/// the already initialized AST consumer.
comment|///
comment|/// This will also take care of instantiating a code completion consumer if
comment|/// the user requested it and the action supports it.
name|virtual
name|void
name|ExecuteAction
argument_list|()
block|;
name|public
operator|:
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|}
block|;
name|class
name|PluginASTAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|protected
operator|:
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
operator|=
literal|0
block|;
name|public
operator|:
comment|/// ParseArgs - Parse the given plugin command line arguments.
comment|///
comment|/// \param CI - The compiler instance, for use in reporting diagnostics.
comment|/// \return True if the parsing succeeded; otherwise the plugin will be
comment|/// destroyed and no action run. The plugin is responsible for using the
comment|/// CompilerInstance's Diagnostic object to report errors.
name|virtual
name|bool
name|ParseArgs
argument_list|(
specifier|const
name|CompilerInstance
operator|&
name|CI
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|arg
argument_list|)
operator|=
literal|0
block|; }
block|;
comment|/// PreprocessorFrontendAction - Abstract base class to use for preprocessor
comment|/// based frontend actions.
name|class
name|PreprocessorFrontendAction
operator|:
name|public
name|FrontendAction
block|{
name|protected
operator|:
comment|/// CreateASTConsumer - Provide a default implementation which returns aborts,
comment|/// this method should never be called by FrontendAction clients.
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|llvm::StringRef InFile
argument_list|)
block|;
name|public
operator|:
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

