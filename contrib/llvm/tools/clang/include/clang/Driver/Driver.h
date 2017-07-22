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
name|LLVM_CLANG_DRIVER_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_DRIVER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Action.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Phases.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
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
name|Arg
decl_stmt|;
name|class
name|ArgList
decl_stmt|;
name|class
name|DerivedArgList
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
name|class
name|OptTable
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|vfs
block|{
name|class
name|FileSystem
decl_stmt|;
block|}
name|namespace
name|driver
block|{
name|class
name|Command
decl_stmt|;
name|class
name|Compilation
decl_stmt|;
name|class
name|InputInfo
decl_stmt|;
name|class
name|JobList
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
name|class
name|SanitizerArgs
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
comment|/// Describes the kind of LTO mode selected via -f(no-)?lto(=.*)? options.
enum|enum
name|LTOKind
block|{
name|LTOK_None
block|,
name|LTOK_Full
block|,
name|LTOK_Thin
block|,
name|LTOK_Unknown
block|}
enum|;
comment|/// Driver - Encapsulate logic for constructing compilation processes
comment|/// from a set of gcc-driver-like command line arguments.
name|class
name|Driver
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|opt
operator|::
name|OptTable
operator|>
name|Opts
expr_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|vfs
operator|::
name|FileSystem
operator|>
name|VFS
expr_stmt|;
enum|enum
name|DriverMode
block|{
name|GCCMode
block|,
name|GXXMode
block|,
name|CPPMode
block|,
name|CLMode
block|}
name|Mode
enum|;
enum|enum
name|SaveTempsMode
block|{
name|SaveTempsNone
block|,
name|SaveTempsCwd
block|,
name|SaveTempsObj
block|}
name|SaveTemps
enum|;
enum|enum
name|BitcodeEmbedMode
block|{
name|EmbedNone
block|,
name|EmbedMarker
block|,
name|EmbedBitcode
block|}
name|BitcodeEmbed
enum|;
comment|/// LTO mode selected via -f(no-)?lto(=.*)? options.
name|LTOKind
name|LTOMode
decl_stmt|;
name|public
label|:
enum|enum
name|OpenMPRuntimeKind
block|{
comment|/// An unknown OpenMP runtime. We can't generate effective OpenMP code
comment|/// without knowing what runtime to target.
name|OMPRT_Unknown
block|,
comment|/// The LLVM OpenMP runtime. When completed and integrated, this will become
comment|/// the default for Clang.
name|OMPRT_OMP
block|,
comment|/// The GNU OpenMP runtime. Clang doesn't support generating OpenMP code for
comment|/// this runtime but can swallow the pragmas, and find and link against the
comment|/// runtime library itself.
name|OMPRT_GOMP
block|,
comment|/// The legacy name for the LLVM OpenMP runtime from when it was the Intel
comment|/// OpenMP runtime. We support this mode for users with existing
comment|/// dependencies on this runtime library name.
name|OMPRT_IOMP5
block|}
enum|;
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
comment|/// The original path to the clang executable.
name|std
operator|::
name|string
name|ClangExecutable
expr_stmt|;
comment|/// The path to the installed clang directory, if any.
name|std
operator|::
name|string
name|InstalledDir
expr_stmt|;
comment|/// The path to the compiler resource directory.
name|std
operator|::
name|string
name|ResourceDir
expr_stmt|;
comment|/// A prefix directory used to emulate a limited subset of GCC's '-Bprefix'
comment|/// functionality.
comment|/// FIXME: This type of customization should be removed in favor of the
comment|/// universal driver when it is ready.
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|4
operator|>
name|prefix_list
expr_stmt|;
name|prefix_list
name|PrefixDirs
decl_stmt|;
comment|/// sysroot, if present
name|std
operator|::
name|string
name|SysRoot
expr_stmt|;
comment|/// Dynamic loader prefix, if present
name|std
operator|::
name|string
name|DyldPrefix
expr_stmt|;
comment|/// If the standard library is used
name|bool
name|UseStdLib
decl_stmt|;
comment|/// Driver title to use with help.
name|std
operator|::
name|string
name|DriverTitle
expr_stmt|;
comment|/// Information about the host which can be overridden by the user.
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
comment|/// The file to log CC_PRINT_OPTIONS output to, if enabled.
specifier|const
name|char
modifier|*
name|CCPrintOptionsFilename
decl_stmt|;
comment|/// The file to log CC_PRINT_HEADERS output to, if enabled.
specifier|const
name|char
modifier|*
name|CCPrintHeadersFilename
decl_stmt|;
comment|/// The file to log CC_LOG_DIAGNOSTICS output to, if enabled.
specifier|const
name|char
modifier|*
name|CCLogDiagnosticsFilename
decl_stmt|;
comment|/// A list of inputs and their types for the given arguments.
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|types
operator|::
name|ID
operator|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
operator|>
operator|,
literal|16
operator|>
name|InputList
expr_stmt|;
comment|/// Whether the driver should follow g++ like behavior.
name|bool
name|CCCIsCXX
argument_list|()
specifier|const
block|{
return|return
name|Mode
operator|==
name|GXXMode
return|;
block|}
comment|/// Whether the driver is just the preprocessor.
name|bool
name|CCCIsCPP
argument_list|()
specifier|const
block|{
return|return
name|Mode
operator|==
name|CPPMode
return|;
block|}
comment|/// Whether the driver should follow gcc like behavior.
name|bool
name|CCCIsCC
argument_list|()
specifier|const
block|{
return|return
name|Mode
operator|==
name|GCCMode
return|;
block|}
comment|/// Whether the driver should follow cl.exe like behavior.
name|bool
name|IsCLMode
argument_list|()
specifier|const
block|{
return|return
name|Mode
operator|==
name|CLMode
return|;
block|}
comment|/// Only print tool bindings, don't build any jobs.
name|unsigned
name|CCCPrintBindings
range|:
literal|1
decl_stmt|;
comment|/// Set CC_PRINT_OPTIONS mode, which is like -v but logs the commands to
comment|/// CCPrintOptionsFilename or to stderr.
name|unsigned
name|CCPrintOptions
range|:
literal|1
decl_stmt|;
comment|/// Set CC_PRINT_HEADERS mode, which causes the frontend to log header include
comment|/// information to CCPrintHeadersFilename or to stderr.
name|unsigned
name|CCPrintHeaders
range|:
literal|1
decl_stmt|;
comment|/// Set CC_LOG_DIAGNOSTICS mode, which causes the frontend to log diagnostics
comment|/// to CCLogDiagnosticsFilename or to stderr, in a stable machine readable
comment|/// format.
name|unsigned
name|CCLogDiagnostics
range|:
literal|1
decl_stmt|;
comment|/// Whether the driver is generating diagnostics for debugging purposes.
name|unsigned
name|CCGenDiagnostics
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|/// Default target triple.
name|std
operator|::
name|string
name|DefaultTargetTriple
expr_stmt|;
comment|/// Name to use when invoking gcc/g++.
name|std
operator|::
name|string
name|CCCGenericGCCName
expr_stmt|;
comment|/// Whether to check that input files exist when constructing compilation
comment|/// jobs.
name|unsigned
name|CheckInputsExist
range|:
literal|1
decl_stmt|;
name|public
label|:
comment|/// Use lazy precompiled headers for PCH support.
name|unsigned
name|CCCUsePCH
range|:
literal|1
decl_stmt|;
comment|/// Force clang to emit reproducer for driver invocation. This is enabled
comment|/// indirectly by setting FORCE_CLANG_DIAGNOSTICS_CRASH environment variable
comment|/// or when using the -gen-reproducer driver flag.
name|unsigned
name|GenReproducer
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|/// Certain options suppress the 'no input files' warning.
name|unsigned
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
comment|/// \brief Cache of all the ToolChains in use by the driver.
comment|///
comment|/// This maps from the string representation of a triple to a ToolChain
comment|/// created targeting that triple. The driver owns all the ToolChain objects
comment|/// stored in it, and will clean them up when torn down.
name|mutable
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ToolChain
operator|>>
name|ToolChains
expr_stmt|;
name|private
label|:
comment|/// TranslateInputArgs - Create a new derived argument list from the input
comment|/// arguments, after applying the standard argument translations.
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|*
name|TranslateInputArgs
argument_list|(
argument|const llvm::opt::InputArgList&Args
argument_list|)
specifier|const
expr_stmt|;
comment|// getFinalPhase - Determine which compilation mode we are in and record
comment|// which option we used to determine the final phase.
name|phases
operator|::
name|ID
name|getFinalPhase
argument_list|(
argument|const llvm::opt::DerivedArgList&DAL
argument_list|,
argument|llvm::opt::Arg **FinalPhaseArg = nullptr
argument_list|)
specifier|const
expr_stmt|;
comment|// Before executing jobs, sets up response files for commands that need them.
name|void
name|setUpResponseFiles
parameter_list|(
name|Compilation
modifier|&
name|C
parameter_list|,
name|Command
modifier|&
name|Cmd
parameter_list|)
function_decl|;
name|void
name|generatePrefixedToolNames
argument_list|(
name|StringRef
name|Tool
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Names
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Find the appropriate .crash diagonostic file for the child crash
comment|/// under this driver and copy it out to a temporary destination with the
comment|/// other reproducer related files (.sh, .cache, etc). If not found, suggest a
comment|/// directory for the user to look at.
comment|///
comment|/// \param ReproCrashFilename The file path to copy the .crash to.
comment|/// \param CrashDiagDir       The suggested directory for the user to look at
comment|///                           in case the search or copy fails.
comment|///
comment|/// \returns If the .crash is found and successfully copied return true,
comment|/// otherwise false and return the suggested directory in \p CrashDiagDir.
name|bool
name|getCrashDiagnosticFile
argument_list|(
name|StringRef
name|ReproCrashFilename
argument_list|,
name|SmallString
operator|<
literal|128
operator|>
operator|&
name|CrashDiagDir
argument_list|)
decl_stmt|;
name|public
label|:
name|Driver
argument_list|(
argument|StringRef ClangExecutable
argument_list|,
argument|StringRef DefaultTargetTriple
argument_list|,
argument|DiagnosticsEngine&Diags
argument_list|,
argument|IntrusiveRefCntPtr<vfs::FileSystem> VFS = nullptr
argument_list|)
empty_stmt|;
comment|/// @name Accessors
comment|/// @{
comment|/// Name to use when invoking gcc/g++.
specifier|const
name|std
operator|::
name|string
operator|&
name|getCCCGenericGCCName
argument_list|()
specifier|const
block|{
return|return
name|CCCGenericGCCName
return|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
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
name|DiagnosticsEngine
operator|&
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
name|vfs
operator|::
name|FileSystem
operator|&
name|getVFS
argument_list|()
specifier|const
block|{
return|return
operator|*
name|VFS
return|;
block|}
name|bool
name|getCheckInputsExist
argument_list|()
specifier|const
block|{
return|return
name|CheckInputsExist
return|;
block|}
name|void
name|setCheckInputsExist
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|CheckInputsExist
operator|=
name|Value
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getTitle
argument_list|()
block|{
return|return
name|DriverTitle
return|;
block|}
name|void
name|setTitle
argument_list|(
name|std
operator|::
name|string
name|Value
argument_list|)
block|{
name|DriverTitle
operator|=
name|std
operator|::
name|move
argument_list|(
name|Value
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the path to the main clang executable.
specifier|const
name|char
operator|*
name|getClangProgramPath
argument_list|()
specifier|const
block|{
return|return
name|ClangExecutable
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|/// \brief Get the path to where the clang executable was installed.
specifier|const
name|char
operator|*
name|getInstalledDir
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|InstalledDir
operator|.
name|empty
argument_list|()
condition|)
return|return
name|InstalledDir
operator|.
name|c_str
argument_list|()
return|;
return|return
name|Dir
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|setInstalledDir
parameter_list|(
name|StringRef
name|Value
parameter_list|)
block|{
name|InstalledDir
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|isSaveTempsEnabled
argument_list|()
specifier|const
block|{
return|return
name|SaveTemps
operator|!=
name|SaveTempsNone
return|;
block|}
name|bool
name|isSaveTempsObj
argument_list|()
specifier|const
block|{
return|return
name|SaveTemps
operator|==
name|SaveTempsObj
return|;
block|}
name|bool
name|embedBitcodeEnabled
argument_list|()
specifier|const
block|{
return|return
name|BitcodeEmbed
operator|!=
name|EmbedNone
return|;
block|}
name|bool
name|embedBitcodeInObject
argument_list|()
specifier|const
block|{
return|return
operator|(
name|BitcodeEmbed
operator|==
name|EmbedBitcode
operator|)
return|;
block|}
name|bool
name|embedBitcodeMarkerOnly
argument_list|()
specifier|const
block|{
return|return
operator|(
name|BitcodeEmbed
operator|==
name|EmbedMarker
operator|)
return|;
block|}
comment|/// Compute the desired OpenMP runtime from the flags provided.
name|OpenMPRuntimeKind
name|getOpenMPRuntime
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Primary Functionality
comment|/// @{
comment|/// CreateOffloadingDeviceToolChains - create all the toolchains required to
comment|/// support offloading devices given the programming models specified in the
comment|/// current compilation. Also, update the host tool chain kind accordingly.
name|void
name|CreateOffloadingDeviceToolChains
parameter_list|(
name|Compilation
modifier|&
name|C
parameter_list|,
name|InputList
modifier|&
name|Inputs
parameter_list|)
function_decl|;
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
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// @name Driver Steps
comment|/// @{
comment|/// ParseDriverMode - Look for and handle the driver mode option in Args.
name|void
name|ParseDriverMode
argument_list|(
name|StringRef
name|ProgramName
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
comment|/// ParseArgStrings - Parse the given list of strings into an
comment|/// ArgList.
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
name|ParseArgStrings
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|,
name|bool
operator|&
name|ContainsError
argument_list|)
expr_stmt|;
comment|/// BuildInputs - Construct the list of inputs and their types from
comment|/// the given arguments.
comment|///
comment|/// \param TC - The default host tool chain.
comment|/// \param Args - The input arguments.
comment|/// \param Inputs - The list to store the resulting compilation
comment|/// inputs onto.
name|void
name|BuildInputs
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|&
name|Args
argument_list|,
name|InputList
operator|&
name|Inputs
argument_list|)
decl|const
decl_stmt|;
comment|/// BuildActions - Construct the list of actions to perform for the
comment|/// given arguments, which are only done for a single architecture.
comment|///
comment|/// \param C - The compilation that is being built.
comment|/// \param Args - The input arguments.
comment|/// \param Actions - The list to store the resulting actions onto.
name|void
name|BuildActions
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|&
name|Args
argument_list|,
specifier|const
name|InputList
operator|&
name|Inputs
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
comment|/// \param C - The compilation that is being built.
comment|/// \param TC - The default host tool chain.
name|void
name|BuildUniversalActions
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|,
specifier|const
name|InputList
operator|&
name|BAInputs
argument_list|)
decl|const
decl_stmt|;
comment|/// BuildJobs - Bind actions to concrete tools and translate
comment|/// arguments to form the list of jobs to run.
comment|///
comment|/// \param C - The compilation that is being built.
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
comment|/// to just running the subprocesses, for example reporting errors, setting
comment|/// up response files, removing temporary files, etc.
name|int
name|ExecuteCompilation
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|int
argument_list|,
specifier|const
name|Command
operator|*
operator|>
expr|>
operator|&
name|FailingCommands
argument_list|)
decl_stmt|;
comment|/// generateCompilationDiagnostics - Generate diagnostics information
comment|/// including preprocessed source file(s).
comment|///
name|void
name|generateCompilationDiagnostics
parameter_list|(
name|Compilation
modifier|&
name|C
parameter_list|,
specifier|const
name|Command
modifier|&
name|FailingCommand
parameter_list|)
function_decl|;
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
comment|/// PrintVersion - Print the driver version.
name|void
name|PrintVersion
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// GetFilePath - Lookup \p Name in the list of file search paths.
comment|///
comment|/// \param TC - The tool chain for additional information on
comment|/// directories to search.
comment|//
comment|// FIXME: This should be in CompilationInfo.
name|std
operator|::
name|string
name|GetFilePath
argument_list|(
argument|StringRef Name
argument_list|,
argument|const ToolChain&TC
argument_list|)
specifier|const
expr_stmt|;
comment|/// GetProgramPath - Lookup \p Name in the list of program search paths.
comment|///
comment|/// \param TC - The provided tool chain for additional information on
comment|/// directories to search.
comment|//
comment|// FIXME: This should be in CompilationInfo.
name|std
operator|::
name|string
name|GetProgramPath
argument_list|(
argument|StringRef Name
argument_list|,
argument|const ToolChain&TC
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
comment|/// \p Phase on the \p Input, taking in to account arguments
comment|/// like -fsyntax-only or --analyze.
name|Action
modifier|*
name|ConstructPhaseAction
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
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
comment|/// BuildJobsForAction - Construct the jobs to perform for the action \p A and
comment|/// return an InputInfo for the result of running \p A.  Will only construct
comment|/// jobs for a given (Action, ToolChain, BoundArch, DeviceKind) tuple once.
name|InputInfo
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
name|StringRef
name|BoundArch
argument_list|,
name|bool
name|AtTopLevel
argument_list|,
name|bool
name|MultipleArchs
argument_list|,
specifier|const
name|char
operator|*
name|LinkingOutput
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Action
operator|*
argument_list|,
name|std
operator|::
name|string
operator|>
argument_list|,
name|InputInfo
operator|>
operator|&
name|CachedResults
argument_list|,
name|Action
operator|::
name|OffloadKind
name|TargetDeviceOffloadKind
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the default name for linked images (e.g., "a.out").
specifier|const
name|char
operator|*
name|getDefaultImageName
argument_list|()
specifier|const
expr_stmt|;
comment|/// GetNamedOutputPath - Return the name to use for the output of
comment|/// the action \p JA. The result is appended to the compilation's
comment|/// list of temporary or result files, as appropriate.
comment|///
comment|/// \param C - The compilation.
comment|/// \param JA - The action of interest.
comment|/// \param BaseInput - The original input file that this action was
comment|/// triggered by.
comment|/// \param BoundArch - The bound architecture.
comment|/// \param AtTopLevel - Whether this is a "top-level" action.
comment|/// \param MultipleArchs - Whether multiple -arch options were supplied.
comment|/// \param NormalizedTriple - The normalized triple of the relevant target.
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
name|StringRef
name|BoundArch
argument_list|,
name|bool
name|AtTopLevel
argument_list|,
name|bool
name|MultipleArchs
argument_list|,
name|StringRef
name|NormalizedTriple
argument_list|)
decl|const
decl_stmt|;
comment|/// GetTemporaryPath - Return the pathname of a temporary file to use
comment|/// as part of compilation; the file will have the given prefix and suffix.
comment|///
comment|/// GCC goes to extra lengths here to be a bit more robust.
name|std
operator|::
name|string
name|GetTemporaryPath
argument_list|(
argument|StringRef Prefix
argument_list|,
argument|StringRef Suffix
argument_list|)
specifier|const
expr_stmt|;
comment|/// Return the pathname of the pch file in clang-cl mode.
name|std
operator|::
name|string
name|GetClPchPath
argument_list|(
argument|Compilation&C
argument_list|,
argument|StringRef BaseName
argument_list|)
specifier|const
expr_stmt|;
comment|/// ShouldUseClangCompiler - Should the clang compiler be used to
comment|/// handle this action.
name|bool
name|ShouldUseClangCompiler
argument_list|(
specifier|const
name|JobAction
operator|&
name|JA
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if we are performing any kind of LTO.
name|bool
name|isUsingLTO
argument_list|()
specifier|const
block|{
return|return
name|LTOMode
operator|!=
name|LTOK_None
return|;
block|}
comment|/// Get the specific kind of LTO being performed.
name|LTOKind
name|getLTOMode
argument_list|()
specifier|const
block|{
return|return
name|LTOMode
return|;
block|}
name|private
label|:
comment|/// Set the driver mode (cl, gcc, etc) from an option string of the form
comment|/// --driver-mode=<mode>.
name|void
name|setDriverModeFromOption
parameter_list|(
name|StringRef
name|Opt
parameter_list|)
function_decl|;
comment|/// Parse the \p Args list for LTO options and record the type of LTO
comment|/// compilation based on which -f(no-)?lto(=.*)? option occurs last.
name|void
name|setLTOMode
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
decl_stmt|;
comment|/// \brief Retrieves a ToolChain for a particular \p Target triple.
comment|///
comment|/// Will cache ToolChains for the life of the driver object, and create them
comment|/// on-demand.
specifier|const
name|ToolChain
modifier|&
name|getToolChain
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
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Target
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// \brief Get bitmasks for which option flags to include and exclude based on
comment|/// the driver mode.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getIncludeExcludeOptionFlagMasks
argument_list|()
specifier|const
expr_stmt|;
comment|/// Helper used in BuildJobsForAction.  Doesn't use the cache when building
comment|/// jobs specifically for the given action, but will use the cache when
comment|/// building jobs for the Action's inputs.
name|InputInfo
name|BuildJobsForActionNoCache
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
name|StringRef
name|BoundArch
argument_list|,
name|bool
name|AtTopLevel
argument_list|,
name|bool
name|MultipleArchs
argument_list|,
specifier|const
name|char
operator|*
name|LinkingOutput
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Action
operator|*
argument_list|,
name|std
operator|::
name|string
operator|>
argument_list|,
name|InputInfo
operator|>
operator|&
name|CachedResults
argument_list|,
name|Action
operator|::
name|OffloadKind
name|TargetDeviceOffloadKind
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
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
name|StringRef
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
comment|/// Parse digits from a string \p Str and fulfill \p Digits with
comment|/// the parsed numbers. This method assumes that the max number of
comment|/// digits to look for is equal to Digits.size().
comment|///
comment|/// \return True if the entire string was parsed and there are
comment|/// no extra characters remaining at the end.
specifier|static
name|bool
name|GetReleaseVersion
argument_list|(
name|StringRef
name|Str
argument_list|,
name|MutableArrayRef
operator|<
name|unsigned
operator|>
name|Digits
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// \return True if the last defined optimization level is -Ofast.
comment|/// And False otherwise.
name|bool
name|isOptimizationLevelFast
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace driver
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

