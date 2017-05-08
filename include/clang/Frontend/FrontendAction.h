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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::FrontendAction interface and various convenience
end_comment

begin_comment
comment|/// abstract classes (clang::ASTFrontendAction, clang::PluginASTAction,
end_comment

begin_comment
comment|/// clang::PreprocessorFrontendAction, and clang::WrapperFrontendAction)
end_comment

begin_comment
comment|/// derived from it.
end_comment

begin_comment
comment|///
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
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/ASTUnit.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTMergeAction
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
comment|/// Abstract base class for actions which can be performed by the frontend.
name|class
name|FrontendAction
block|{
name|FrontendInputFile
name|CurrentInput
decl_stmt|;
name|std
operator|::
name|unique_ptr
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
name|friend
name|class
name|WrapperFrontendAction
decl_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateWrappedASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
expr_stmt|;
name|protected
label|:
comment|/// @name Implementation Action Interface
comment|/// @{
comment|/// \brief Create the AST consumer object for this action, if supported.
comment|///
comment|/// This routine is called as part of BeginSourceFile(), which will
comment|/// fail if the AST consumer cannot be created. This will not be called if the
comment|/// action has indicated that it only uses the preprocessor.
comment|///
comment|/// \param CI - The current compiler instance, provided as a convenience, see
comment|/// getCompilerInstance().
comment|///
comment|/// \param InFile - The current input file, provided as a convenience, see
comment|/// getCurrentFile().
comment|///
comment|/// \return The new AST consumer, or null on failure.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Callback before starting processing a single input, giving the
comment|/// opportunity to modify the CompilerInvocation or do some other action
comment|/// before BeginSourceFileAction is called.
comment|///
comment|/// \return True on success; on failure BeginSourceFileAction(),
comment|/// ExecuteAction() and EndSourceFileAction() will not be called.
name|virtual
name|bool
name|BeginInvocation
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Callback at the start of processing a single input.
comment|///
comment|/// \return True on success; on failure ExecutionAction() and
comment|/// EndSourceFileAction() will not be called.
name|virtual
name|bool
name|BeginSourceFileAction
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|,
name|StringRef
name|Filename
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Callback to run the program action, using the initialized
comment|/// compiler instance.
comment|///
comment|/// This is guaranteed to only be called between BeginSourceFileAction()
comment|/// and EndSourceFileAction().
name|virtual
name|void
name|ExecuteAction
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// \brief Callback at the end of processing a single input.
comment|///
comment|/// This is guaranteed to only be called following a successful call to
comment|/// BeginSourceFileAction (and BeginSourceFile).
name|virtual
name|void
name|EndSourceFileAction
parameter_list|()
block|{}
comment|/// \brief Callback at the end of processing a single input, to determine
comment|/// if the output files should be erased or not.
comment|///
comment|/// By default it returns true if a compiler error occurred.
comment|/// This is guaranteed to only be called following a successful call to
comment|/// BeginSourceFileAction (and BeginSourceFile).
name|virtual
name|bool
name|shouldEraseOutputFiles
parameter_list|()
function_decl|;
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
name|CurrentInput
operator|.
name|isEmpty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
operator|(
name|bool
operator|)
name|CurrentASTUnit
return|;
block|}
specifier|const
name|FrontendInputFile
operator|&
name|getCurrentInput
argument_list|()
specifier|const
block|{
return|return
name|CurrentInput
return|;
block|}
specifier|const
name|StringRef
name|getCurrentFile
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentInput
operator|.
name|isEmpty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
name|CurrentInput
operator|.
name|getFile
argument_list|()
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
name|CurrentInput
operator|.
name|isEmpty
argument_list|()
operator|&&
literal|"No current file!"
argument_list|)
block|;
return|return
name|CurrentInput
operator|.
name|getKind
argument_list|()
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
name|Module
operator|*
name|getCurrentModule
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|takeCurrentASTUnit
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|CurrentASTUnit
argument_list|)
return|;
block|}
name|void
name|setCurrentInput
argument_list|(
specifier|const
name|FrontendInputFile
operator|&
name|CurrentInput
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|AST
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Supported Modes
comment|/// @{
comment|/// \brief Is this action invoked on a model file?
comment|///
comment|/// Model files are incomplete translation units that relies on type
comment|/// information from another translation unit. Check ParseModelFileAction for
comment|/// details.
name|virtual
name|bool
name|isModelParsingAction
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Does this action only use the preprocessor?
comment|///
comment|/// If so no AST context will be created and this action will be invalid
comment|/// with AST file inputs.
name|virtual
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief For AST-based actions, the kind of translation unit we're handling.
name|virtual
name|TranslationUnitKind
name|getTranslationUnitKind
parameter_list|()
block|{
return|return
name|TU_Complete
return|;
block|}
comment|/// \brief Does this action support use with PCH?
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
comment|/// \brief Does this action support use with AST files?
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
comment|/// \brief Does this action support use with IR files?
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
comment|/// \brief Does this action support use with code completion?
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
comment|/// \brief Prepare the action for processing the input file \p Input.
comment|///
comment|/// This is run after the options and frontend have been initialized,
comment|/// but prior to executing any per-file processing.
comment|///
comment|/// \param CI - The compiler instance this action is being run from. The
comment|/// action may store and use this object up until the matching EndSourceFile
comment|/// action.
comment|///
comment|/// \param Input - The input filename and kind. Some input kinds are handled
comment|/// specially, for example AST inputs, since the AST file itself contains
comment|/// several objects which would normally be owned by the
comment|/// CompilerInstance. When processing AST input files, these objects should
comment|/// generally not be initialized in the CompilerInstance -- they will
comment|/// automatically be shared with the AST file in between
comment|/// BeginSourceFile() and EndSourceFile().
comment|///
comment|/// \return True on success; on failure the compilation of this file should
comment|/// be aborted and neither Execute() nor EndSourceFile() should be called.
name|bool
name|BeginSourceFile
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|,
specifier|const
name|FrontendInputFile
modifier|&
name|Input
parameter_list|)
function_decl|;
comment|/// \brief Set the source manager's main input file, and run the action.
name|bool
name|Execute
parameter_list|()
function_decl|;
comment|/// \brief Perform any per-file post processing, deallocate per-file
comment|/// objects, and run statistics and output file cleanup code.
name|void
name|EndSourceFile
parameter_list|()
function_decl|;
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Abstract base class to use for AST consumer-based frontend actions.
name|class
name|ASTFrontendAction
range|:
name|public
name|FrontendAction
block|{
name|protected
operator|:
comment|/// \brief Implement the ExecuteAction interface by running Sema on
comment|/// the already-initialized AST consumer.
comment|///
comment|/// This will also take care of instantiating a code completion consumer if
comment|/// the user requested it and the action supports it.
name|void
name|ExecuteAction
argument_list|()
name|override
block|;
name|public
operator|:
name|ASTFrontendAction
argument_list|()
block|{}
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
name|override
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
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
operator|=
literal|0
block|;
comment|/// \brief Parse the given plugin command line arguments.
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
block|;    enum
name|ActionType
block|{
name|Cmdline
block|,
comment|///< Action is determined by the cc1 command-line
name|ReplaceAction
block|,
comment|///< Replace the main action
name|AddBeforeMainAction
block|,
comment|///< Execute the action before the main action
name|AddAfterMainAction
comment|///< Execute the action after the main action
block|}
block|;
comment|/// \brief Get the action type for this plugin
comment|///
comment|/// \return The action type. If the type is Cmdline then by default the
comment|/// plugin does nothing and what it does is determined by the cc1
comment|/// command-line.
name|virtual
name|ActionType
name|getActionType
argument_list|()
block|{
return|return
name|Cmdline
return|;
block|}
expr|}
block|;
comment|/// \brief Abstract base class to use for preprocessor-based frontend actions.
name|class
name|PreprocessorFrontendAction
operator|:
name|public
name|FrontendAction
block|{
name|protected
operator|:
comment|/// \brief Provide a default implementation which returns aborts;
comment|/// this method should never be called by FrontendAction clients.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
block|;
name|public
operator|:
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief A frontend action which simply wraps some other runtime-specified
comment|/// frontend action.
comment|///
comment|/// Deriving from this class allows an action to inject custom logic around
comment|/// some existing action's behavior. It implements every virtual method in
comment|/// the FrontendAction interface by forwarding to the wrapped action.
name|class
name|WrapperFrontendAction
operator|:
name|public
name|FrontendAction
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendAction
operator|>
name|WrappedAction
block|;
name|protected
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
block|;
name|bool
name|BeginInvocation
argument_list|(
argument|CompilerInstance&CI
argument_list|)
name|override
block|;
name|bool
name|BeginSourceFileAction
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef Filename
argument_list|)
name|override
block|;
name|void
name|ExecuteAction
argument_list|()
name|override
block|;
name|void
name|EndSourceFileAction
argument_list|()
name|override
block|;
name|public
operator|:
comment|/// Construct a WrapperFrontendAction from an existing action, taking
comment|/// ownership of it.
name|WrapperFrontendAction
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendAction
operator|>
name|WrappedAction
argument_list|)
block|;
name|bool
name|usesPreprocessorOnly
argument_list|()
specifier|const
name|override
block|;
name|TranslationUnitKind
name|getTranslationUnitKind
argument_list|()
name|override
block|;
name|bool
name|hasPCHSupport
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasASTFileSupport
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasIRSupport
argument_list|()
specifier|const
name|override
block|;
name|bool
name|hasCodeCompletionSupport
argument_list|()
specifier|const
name|override
block|; }
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

