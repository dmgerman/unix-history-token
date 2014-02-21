begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for the front-end -------------*- C++ -*-===//
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
comment|//  This header contains miscellaneous utilities for various front-end actions.
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
name|LLVM_CLANG_FRONTEND_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_UTILS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/OptSpecifier.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_fd_ostream
decl_stmt|;
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
name|ASTConsumer
decl_stmt|;
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DependencyOutputOptions
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|IdentifierTable
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|PreprocessorOutputOptions
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|FrontendOptions
decl_stmt|;
comment|/// Apply the header search options to get given HeaderSearch object.
name|void
name|ApplyHeaderSearchOptions
argument_list|(
name|HeaderSearch
operator|&
name|HS
argument_list|,
specifier|const
name|HeaderSearchOptions
operator|&
name|HSOpts
argument_list|,
specifier|const
name|LangOptions
operator|&
name|Lang
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// InitializePreprocessor - Initialize the preprocessor getting it and the
comment|/// environment ready to process a single file.
name|void
name|InitializePreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|PreprocessorOptions
modifier|&
name|PPOpts
parameter_list|,
specifier|const
name|HeaderSearchOptions
modifier|&
name|HSOpts
parameter_list|,
specifier|const
name|FrontendOptions
modifier|&
name|FEOpts
parameter_list|)
function_decl|;
comment|/// ProcessWarningOptions - Initialize the diagnostic client and process the
comment|/// warning options specified on the command line.
name|void
name|ProcessWarningOptions
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|Diags
parameter_list|,
specifier|const
name|DiagnosticOptions
modifier|&
name|Opts
parameter_list|,
name|bool
name|ReportDiags
init|=
name|true
parameter_list|)
function_decl|;
comment|/// DoPrintPreprocessedInput - Implement -E mode.
name|void
name|DoPrintPreprocessedInput
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|,
specifier|const
name|PreprocessorOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
comment|/// AttachDependencyFileGen - Create a dependency file generator, and attach
comment|/// it to the given preprocessor.  This takes ownership of the output stream.
name|void
name|AttachDependencyFileGen
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|DependencyOutputOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
comment|/// AttachDependencyGraphGen - Create a dependency graph generator, and attach
comment|/// it to the given preprocessor.
name|void
name|AttachDependencyGraphGen
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|StringRef
name|OutputFile
parameter_list|,
name|StringRef
name|SysRoot
parameter_list|)
function_decl|;
comment|/// AttachHeaderIncludeGen - Create a header include list generator, and attach
comment|/// it to the given preprocessor.
comment|///
comment|/// \param ShowAllHeaders - If true, show all header information instead of just
comment|/// headers following the predefines buffer. This is useful for making sure
comment|/// includes mentioned on the command line are also reported, but differs from
comment|/// the default behavior used by -H.
comment|/// \param OutputPath - If non-empty, a path to write the header include
comment|/// information to, instead of writing to stderr.
comment|/// \param ShowDepth - Whether to indent to show the nesting of the includes.
comment|/// \param MSStyle - Whether to print in cl.exe /showIncludes style.
name|void
name|AttachHeaderIncludeGen
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|bool
name|ShowAllHeaders
init|=
name|false
parameter_list|,
name|StringRef
name|OutputPath
init|=
literal|""
parameter_list|,
name|bool
name|ShowDepth
init|=
name|true
parameter_list|,
name|bool
name|MSStyle
init|=
name|false
parameter_list|)
function_decl|;
comment|/// CacheTokens - Cache tokens for use with PCH. Note that this requires
comment|/// a seekable stream.
name|void
name|CacheTokens
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|llvm
operator|::
name|raw_fd_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
comment|/// createInvocationFromCommandLine - Construct a compiler invocation object for
comment|/// a command line argument vector.
comment|///
comment|/// \return A CompilerInvocation, or 0 if none was built for the given
comment|/// argument vector.
name|CompilerInvocation
modifier|*
name|createInvocationFromCommandLine
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diags
operator|=
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
comment|/// Return the value of the last argument as an integer, or a default. If Diags
comment|/// is non-null, emits an error if the argument is given, but non-integral.
name|int
name|getLastArgIntValue
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|OptSpecifier
name|Id
argument_list|,
name|int
name|Default
argument_list|,
name|DiagnosticsEngine
operator|*
name|Diags
operator|=
literal|0
argument_list|)
decl_stmt|;
specifier|inline
name|int
name|getLastArgIntValue
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|OptSpecifier
name|Id
argument_list|,
name|int
name|Default
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
block|{
return|return
name|getLastArgIntValue
argument_list|(
name|Args
argument_list|,
name|Id
argument_list|,
name|Default
argument_list|,
operator|&
name|Diags
argument_list|)
return|;
block|}
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

