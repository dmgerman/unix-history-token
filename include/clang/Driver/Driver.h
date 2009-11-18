begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Driver.h - Clang GCC Compatible Driver -----------------*- C++ -*-===//
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
name|CLANG_DRIVER_DRIVER_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_DRIVER_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Phases.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_comment
comment|// FIXME: Kill when CompilationInfo
end_comment

begin_comment
comment|// lands.
end_comment

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<set>
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
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|Action
decl_stmt|;
name|class
name|ArgList
decl_stmt|;
name|class
name|Compilation
decl_stmt|;
name|class
name|HostInfo
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
name|class
name|InputInfo
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
name|class
name|OptTable
decl_stmt|;
name|class
name|PipedJob
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
comment|/// Driver - Encapsulate logic for constructing compilation processes
comment|/// from a set of gcc-driver-like command line arguments.
name|class
name|Driver
block|{
name|OptTable
modifier|*
name|Opts
decl_stmt|;
name|Diagnostic
modifier|&
name|Diags
decl_stmt|;
name|public
label|:
comment|// Diag - Forwarding function for diagnostics.
name|DiagnosticBuilder
name|Diag
argument_list|(
name|unsigned
name|DiagID
argument_list|)
decl|const
block|{
return|return
name|Diags
operator|.
name|Report
argument_list|(
name|DiagID
argument_list|)
return|;
block|}
comment|// FIXME: Privatize once interface is stable.
name|public
label|:
comment|/// The name the driver was invoked as.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// The path the driver executable was in, as invoked from the
comment|/// command line.
name|std
operator|::
name|string
name|Dir
expr_stmt|;
comment|/// Default host triple.
name|std
operator|::
name|string
name|DefaultHostTriple
expr_stmt|;
comment|/// Default name for linked images (e.g., "a.out").
name|std
operator|::
name|string
name|DefaultImageName
expr_stmt|;
comment|/// Host information for the platform the driver is running as. This
comment|/// will generally be the actual host platform, but not always.
specifier|const
name|HostInfo
modifier|*
name|Host
decl_stmt|;
comment|/// Information about the host which can be overriden by the user.
name|std
operator|::
name|string
name|HostBits
operator|,
name|HostMachine
operator|,
name|HostSystem
operator|,
name|HostRelease
expr_stmt|;
comment|/// Whether the driver should follow g++ like behavior.
name|bool
name|CCCIsCXX
range|:
literal|1
decl_stmt|;
comment|/// Echo commands while executing (in -v style).
name|bool
name|CCCEcho
range|:
literal|1
decl_stmt|;
comment|/// Only print tool bindings, don't build any jobs.
name|bool
name|CCCPrintBindings
range|:
literal|1
decl_stmt|;
comment|/// Name to use when calling the generic gcc.
name|std
operator|::
name|string
name|CCCGenericGCCName
expr_stmt|;
name|private
label|:
comment|/// Use the clang compiler where possible.
name|bool
name|CCCUseClang
range|:
literal|1
decl_stmt|;
comment|/// Use clang for handling C++ and Objective-C++ inputs.
name|bool
name|CCCUseClangCXX
range|:
literal|1
decl_stmt|;
comment|/// Use clang as a preprocessor (clang's preprocessor will still be
comment|/// used where an integrated CPP would).
name|bool
name|CCCUseClangCPP
range|:
literal|1
decl_stmt|;
name|public
label|:
comment|/// Use lazy precompiled headers for PCH support.
name|bool
name|CCCUsePCH
decl_stmt|;
name|private
label|:
comment|/// Only use clang for the given architectures (only used when
comment|/// non-empty).
name|std
operator|::
name|set
operator|<
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
operator|>
name|CCCClangArchs
expr_stmt|;
comment|/// Certain options suppress the 'no input files' warning.
name|bool
name|SuppressMissingInputWarning
range|:
literal|1
decl_stmt|;
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|TempFiles
expr_stmt|;
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|ResultFiles
expr_stmt|;
name|public
label|:
name|Driver
argument_list|(
argument|const char *_Name
argument_list|,
argument|const char *_Dir
argument_list|,
argument|const char *_DefaultHostTriple
argument_list|,
argument|const char *_DefaultImageName
argument_list|,
argument|bool IsProduction
argument_list|,
argument|Diagnostic&_Diags
argument_list|)
empty_stmt|;
operator|~
name|Driver
argument_list|()
expr_stmt|;
comment|/// @name Accessors
comment|/// @{
specifier|const
name|OptTable
operator|&
name|getOpts
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Opts
return|;
block|}
specifier|const
name|Diagnostic
operator|&
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
comment|/// @}
comment|/// @name Primary Functionality
comment|/// @{
comment|/// BuildCompilation - Construct a compilation object for a command
comment|/// line argument vector.
comment|///
comment|/// \return A compilation, or 0 if none was built for the given
comment|/// argument vector. A null return value does not necessarily
comment|/// indicate an error condition, the diagnostics should be queried
comment|/// to determine if an error occurred.
name|Compilation
modifier|*
name|BuildCompilation
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|/// @name Driver Steps
comment|/// @{
comment|/// ParseArgStrings - Parse the given list of strings into an
comment|/// ArgList.
name|InputArgList
modifier|*
name|ParseArgStrings
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|ArgBegin
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|ArgEnd
parameter_list|)
function_decl|;
comment|/// BuildActions - Construct the list of actions to perform for the
comment|/// given arguments, which are only done for a single architecture.
comment|///
comment|/// \param Args - The input arguments.
comment|/// \param Actions - The list to store the resulting actions onto.
name|void
name|BuildActions
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|ActionList
operator|&
name|Actions
argument_list|)
decl|const
decl_stmt|;
comment|/// BuildUniversalActions - Construct the list of actions to perform
comment|/// for the given arguments, which may require a universal build.
comment|///
comment|/// \param Args - The input arguments.
comment|/// \param Actions - The list to store the resulting actions onto.
name|void
name|BuildUniversalActions
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|ActionList
operator|&
name|Actions
argument_list|)
decl|const
decl_stmt|;
comment|/// BuildJobs - Bind actions to concrete tools and translate
comment|/// arguments to form the list of jobs to run.
comment|///
comment|/// \arg C - The compilation that is being built.
name|void
name|BuildJobs
argument_list|(
name|Compilation
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// ExecuteCompilation - Execute the compilation according to the command line
comment|/// arguments and return an appropriate exit code.
comment|///
comment|/// This routine handles additional processing that must be done in addition
comment|/// to just running the subprocesses, for example reporting errors, removing
comment|/// temporary files, etc.
name|int
name|ExecuteCompilation
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Helper Methods
comment|/// @{
comment|/// PrintActions - Print the list of actions.
name|void
name|PrintActions
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintHelp - Print the help text.
comment|///
comment|/// \param ShowHidden - Show hidden options.
name|void
name|PrintHelp
argument_list|(
name|bool
name|ShowHidden
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintOptions - Print the list of arguments.
name|void
name|PrintOptions
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintVersion - Print the driver version.
name|void
name|PrintVersion
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|,
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// GetFilePath - Lookup \arg Name in the list of file search paths.
comment|///
comment|/// \arg TC - The tool chain for additional information on
comment|/// directories to search.
comment|//
comment|// FIXME: This should be in CompilationInfo.
name|std
operator|::
name|string
name|GetFilePath
argument_list|(
argument|const char *Name
argument_list|,
argument|const ToolChain&TC
argument_list|)
specifier|const
expr_stmt|;
comment|/// GetProgramPath - Lookup \arg Name in the list of program search
comment|/// paths.
comment|///
comment|/// \arg TC - The provided tool chain for additional information on
comment|/// directories to search.
comment|///
comment|/// \arg WantFile - False when searching for an executable file, otherwise
comment|/// true.  Defaults to false.
comment|//
comment|// FIXME: This should be in CompilationInfo.
name|std
operator|::
name|string
name|GetProgramPath
argument_list|(
argument|const char *Name
argument_list|,
argument|const ToolChain&TC
argument_list|,
argument|bool WantFile = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// HandleImmediateArgs - Handle any arguments which should be
comment|/// treated before building actions or binding tools.
comment|///
comment|/// \return Whether any compilation should be built for this
comment|/// invocation.
name|bool
name|HandleImmediateArgs
parameter_list|(
specifier|const
name|Compilation
modifier|&
name|C
parameter_list|)
function_decl|;
comment|/// ConstructAction - Construct the appropriate action to do for
comment|/// \arg Phase on the \arg Input, taking in to account arguments
comment|/// like -fsyntax-only or --analyze.
name|Action
modifier|*
name|ConstructPhaseAction
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|phases
operator|::
name|ID
name|Phase
argument_list|,
name|Action
operator|*
name|Input
argument_list|)
decl|const
decl_stmt|;
comment|/// BuildJobsForAction - Construct the jobs to perform for the
comment|/// action \arg A.
name|void
name|BuildJobsForAction
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|Action
operator|*
name|A
argument_list|,
specifier|const
name|ToolChain
operator|*
name|TC
argument_list|,
specifier|const
name|char
operator|*
name|BoundArch
argument_list|,
name|bool
name|CanAcceptPipe
argument_list|,
name|bool
name|AtTopLevel
argument_list|,
specifier|const
name|char
operator|*
name|LinkingOutput
argument_list|,
name|InputInfo
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
comment|/// GetNamedOutputPath - Return the name to use for the output of
comment|/// the action \arg JA. The result is appended to the compilation's
comment|/// list of temporary or result files, as appropriate.
comment|///
comment|/// \param C - The compilation.
comment|/// \param JA - The action of interest.
comment|/// \param BaseInput - The original input file that this action was
comment|/// triggered by.
comment|/// \param AtTopLevel - Whether this is a "top-level" action.
specifier|const
name|char
modifier|*
name|GetNamedOutputPath
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|JobAction
operator|&
name|JA
argument_list|,
specifier|const
name|char
operator|*
name|BaseInput
argument_list|,
name|bool
name|AtTopLevel
argument_list|)
decl|const
decl_stmt|;
comment|/// GetTemporaryPath - Return the pathname of a temporary file to
comment|/// use as part of compilation; the file will have the given suffix.
comment|///
comment|/// GCC goes to extra lengths here to be a bit more robust.
name|std
operator|::
name|string
name|GetTemporaryPath
argument_list|(
argument|const char *Suffix
argument_list|)
specifier|const
expr_stmt|;
comment|/// GetHostInfo - Construct a new host info object for the given
comment|/// host triple.
specifier|const
name|HostInfo
modifier|*
name|GetHostInfo
argument_list|(
specifier|const
name|char
operator|*
name|HostTriple
argument_list|)
decl|const
decl_stmt|;
comment|/// ShouldUseClangCompilar - Should the clang compiler be used to
comment|/// handle this action.
name|bool
name|ShouldUseClangCompiler
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|JobAction
operator|&
name|JA
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|ArchName
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// GetReleaseVersion - Parse (([0-9]+)(.([0-9]+)(.([0-9]+)?))?)? and
comment|/// return the grouped values as integers. Numbers which are not
comment|/// provided are set to 0.
comment|///
comment|/// \return True if the entire string was parsed (9.2), or all
comment|/// groups were parsed (10.3.5extrastuff). HadExtra is true if all
comment|/// groups were parsed but extra characters remain at the end.
specifier|static
name|bool
name|GetReleaseVersion
parameter_list|(
specifier|const
name|char
modifier|*
name|Str
parameter_list|,
name|unsigned
modifier|&
name|Major
parameter_list|,
name|unsigned
modifier|&
name|Minor
parameter_list|,
name|unsigned
modifier|&
name|Micro
parameter_list|,
name|bool
modifier|&
name|HadExtra
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace driver
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

