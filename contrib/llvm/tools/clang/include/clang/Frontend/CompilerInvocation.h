begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompilerInvocation.h - Compiler Invocation Helper Data --*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_COMPILERINVOCATION_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMPILERINVOCATION_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/DependencyOutputOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/LangStandard.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/MigratorOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/PreprocessorOutputOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/AnalyzerOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
name|Triple
decl_stmt|;
name|namespace
name|opt
block|{
name|class
name|ArgList
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
comment|/// \brief Fill out Opts based on the options given in Args.
comment|///
comment|/// Args must have been created from the OptTable returned by
comment|/// createCC1OptTable().
comment|///
comment|/// When errors are encountered, return false and, if Diags is non-null,
comment|/// report the error(s).
name|bool
name|ParseDiagnosticArgs
argument_list|(
name|DiagnosticOptions
operator|&
name|Opts
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|DiagnosticsEngine
operator|*
name|Diags
operator|=
name|nullptr
argument_list|,
name|bool
name|DefaultDiagColor
operator|=
name|true
argument_list|,
name|bool
name|DefaultShowOpt
operator|=
name|true
argument_list|)
decl_stmt|;
name|class
name|CompilerInvocationBase
block|{
name|void
name|operator
init|=
operator|(
specifier|const
name|CompilerInvocationBase
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
comment|/// Options controlling the language variant.
name|std
operator|::
name|shared_ptr
operator|<
name|LangOptions
operator|>
name|LangOpts
expr_stmt|;
comment|/// Options controlling the target.
name|std
operator|::
name|shared_ptr
operator|<
name|TargetOptions
operator|>
name|TargetOpts
expr_stmt|;
comment|/// Options controlling the diagnostic engine.
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagnosticOpts
expr_stmt|;
comment|/// Options controlling the \#include directive.
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|HeaderSearchOpts
expr_stmt|;
comment|/// Options controlling the preprocessor (aside from \#include handling).
name|std
operator|::
name|shared_ptr
operator|<
name|PreprocessorOptions
operator|>
name|PreprocessorOpts
expr_stmt|;
name|CompilerInvocationBase
argument_list|()
expr_stmt|;
operator|~
name|CompilerInvocationBase
argument_list|()
expr_stmt|;
name|CompilerInvocationBase
argument_list|(
specifier|const
name|CompilerInvocationBase
operator|&
name|X
argument_list|)
expr_stmt|;
name|LangOptions
modifier|*
name|getLangOpts
parameter_list|()
block|{
return|return
name|LangOpts
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|LangOptions
operator|*
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
operator|.
name|get
argument_list|()
return|;
block|}
name|TargetOptions
modifier|&
name|getTargetOpts
parameter_list|()
block|{
return|return
operator|*
name|TargetOpts
operator|.
name|get
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
operator|*
name|TargetOpts
operator|.
name|get
argument_list|()
return|;
block|}
name|DiagnosticOptions
operator|&
name|getDiagnosticOpts
argument_list|()
specifier|const
block|{
return|return
operator|*
name|DiagnosticOpts
return|;
block|}
name|HeaderSearchOptions
modifier|&
name|getHeaderSearchOpts
parameter_list|()
block|{
return|return
operator|*
name|HeaderSearchOpts
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
operator|*
name|HeaderSearchOpts
return|;
block|}
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|getHeaderSearchOptsPtr
argument_list|()
specifier|const
block|{
return|return
name|HeaderSearchOpts
return|;
block|}
name|std
operator|::
name|shared_ptr
operator|<
name|PreprocessorOptions
operator|>
name|getPreprocessorOptsPtr
argument_list|()
block|{
return|return
name|PreprocessorOpts
return|;
block|}
name|PreprocessorOptions
modifier|&
name|getPreprocessorOpts
parameter_list|()
block|{
return|return
operator|*
name|PreprocessorOpts
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
operator|*
name|PreprocessorOpts
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Helper class for holding the data necessary to invoke the compiler.
comment|///
comment|/// This class is designed to represent an abstract "invocation" of the
comment|/// compiler, including data such as the include paths, the code generation
comment|/// options, the warning flags, and so on.
name|class
name|CompilerInvocation
range|:
name|public
name|CompilerInvocationBase
block|{
comment|/// Options controlling the static analyzer.
name|AnalyzerOptionsRef
name|AnalyzerOpts
block|;
name|MigratorOptions
name|MigratorOpts
block|;
comment|/// Options controlling IRgen and the backend.
name|CodeGenOptions
name|CodeGenOpts
block|;
comment|/// Options controlling dependency output.
name|DependencyOutputOptions
name|DependencyOutputOpts
block|;
comment|/// Options controlling file system operations.
name|FileSystemOptions
name|FileSystemOpts
block|;
comment|/// Options controlling the frontend itself.
name|FrontendOptions
name|FrontendOpts
block|;
comment|/// Options controlling preprocessed output.
name|PreprocessorOutputOptions
name|PreprocessorOutputOpts
block|;
name|public
operator|:
name|CompilerInvocation
argument_list|()
operator|:
name|AnalyzerOpts
argument_list|(
argument|new AnalyzerOptions()
argument_list|)
block|{}
comment|/// @name Utility Methods
comment|/// @{
comment|/// \brief Create a compiler invocation from a list of input options.
comment|/// \returns true on success.
comment|///
comment|/// \param [out] Res - The resulting invocation.
comment|/// \param ArgBegin - The first element in the argument vector.
comment|/// \param ArgEnd - The last element in the argument vector.
comment|/// \param Diags - The diagnostic engine to use for errors.
specifier|static
name|bool
name|CreateFromArgs
argument_list|(
name|CompilerInvocation
operator|&
name|Res
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgEnd
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
block|;
comment|/// \brief Get the directory where the compiler headers
comment|/// reside, relative to the compiler binary (found by the passed in
comment|/// arguments).
comment|///
comment|/// \param Argv0 - The program path (from argv[0]), for finding the builtin
comment|/// compiler path.
comment|/// \param MainAddr - The address of main (or some other function in the main
comment|/// executable), for finding the builtin compiler path.
specifier|static
name|std
operator|::
name|string
name|GetResourcesPath
argument_list|(
specifier|const
name|char
operator|*
name|Argv0
argument_list|,
name|void
operator|*
name|MainAddr
argument_list|)
block|;
comment|/// \brief Set language defaults for the given input language and
comment|/// language standard in the given LangOptions object.
comment|///
comment|/// \param Opts - The LangOptions object to set up.
comment|/// \param IK - The input language.
comment|/// \param T - The target triple.
comment|/// \param PPOpts - The PreprocessorOptions affected.
comment|/// \param LangStd - The input language standard.
specifier|static
name|void
name|setLangDefaults
argument_list|(
argument|LangOptions&Opts
argument_list|,
argument|InputKind IK
argument_list|,
argument|const llvm::Triple&T
argument_list|,
argument|PreprocessorOptions&PPOpts
argument_list|,
argument|LangStandard::Kind LangStd = LangStandard::lang_unspecified
argument_list|)
block|;
comment|/// \brief Retrieve a module hash string that is suitable for uniquely
comment|/// identifying the conditions under which the module was built.
name|std
operator|::
name|string
name|getModuleHash
argument_list|()
specifier|const
block|;
comment|/// @}
comment|/// @name Option Subgroups
comment|/// @{
name|AnalyzerOptionsRef
name|getAnalyzerOpts
argument_list|()
specifier|const
block|{
return|return
name|AnalyzerOpts
return|;
block|}
name|MigratorOptions
operator|&
name|getMigratorOpts
argument_list|()
block|{
return|return
name|MigratorOpts
return|;
block|}
specifier|const
name|MigratorOptions
operator|&
name|getMigratorOpts
argument_list|()
specifier|const
block|{
return|return
name|MigratorOpts
return|;
block|}
name|CodeGenOptions
operator|&
name|getCodeGenOpts
argument_list|()
block|{
return|return
name|CodeGenOpts
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
name|CodeGenOpts
return|;
block|}
name|DependencyOutputOptions
operator|&
name|getDependencyOutputOpts
argument_list|()
block|{
return|return
name|DependencyOutputOpts
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
name|DependencyOutputOpts
return|;
block|}
name|FileSystemOptions
operator|&
name|getFileSystemOpts
argument_list|()
block|{
return|return
name|FileSystemOpts
return|;
block|}
specifier|const
name|FileSystemOptions
operator|&
name|getFileSystemOpts
argument_list|()
specifier|const
block|{
return|return
name|FileSystemOpts
return|;
block|}
name|FrontendOptions
operator|&
name|getFrontendOpts
argument_list|()
block|{
return|return
name|FrontendOpts
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
name|FrontendOpts
return|;
block|}
name|PreprocessorOutputOptions
operator|&
name|getPreprocessorOutputOpts
argument_list|()
block|{
return|return
name|PreprocessorOutputOpts
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
name|PreprocessorOutputOpts
return|;
block|}
comment|/// @}
expr|}
block|;
name|namespace
name|vfs
block|{
name|class
name|FileSystem
block|; }
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|createVFSFromCompilerInvocation
argument_list|(
specifier|const
name|CompilerInvocation
operator|&
name|CI
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
block|;
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|createVFSFromCompilerInvocation
argument_list|(
specifier|const
name|CompilerInvocation
operator|&
name|CI
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|BaseFS
argument_list|)
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

