begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Compilation.h - Compilation Task Data Structure --------*- C++ -*-===//
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
name|LLVM_CLANG_DRIVER_COMPILATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_COMPILATION_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Action.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Job.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
block|{
name|class
name|DerivedArgList
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
block|}
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
name|Driver
decl_stmt|;
name|class
name|JobList
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
comment|/// Compilation - A set of tasks to perform for a single driver
comment|/// invocation.
name|class
name|Compilation
block|{
comment|/// The driver we were created by.
specifier|const
name|Driver
modifier|&
name|TheDriver
decl_stmt|;
comment|/// The default tool chain.
specifier|const
name|ToolChain
modifier|&
name|DefaultToolChain
decl_stmt|;
comment|/// A mask of all the programming models the host has to support in the
comment|/// current compilation.
name|unsigned
name|ActiveOffloadMask
decl_stmt|;
comment|/// Array with the toolchains of offloading host and devices in the order they
comment|/// were requested by the user. We are preserving that order in case the code
comment|/// generation needs to derive a programming-model-specific semantic out of
comment|/// it.
name|std
operator|::
name|multimap
operator|<
name|Action
operator|::
name|OffloadKind
operator|,
specifier|const
name|ToolChain
operator|*
operator|>
name|OrderedOffloadingToolchains
expr_stmt|;
comment|/// The original (untranslated) input argument list.
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|*
name|Args
expr_stmt|;
comment|/// The driver translated arguments. Note that toolchains may perform their
comment|/// own argument translation.
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|*
name|TranslatedArgs
expr_stmt|;
comment|/// The list of actions we've created via MakeAction.  This is not accessible
comment|/// to consumers; it's here just to manage ownership.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Action
operator|>>
name|AllActions
expr_stmt|;
comment|/// The list of actions.  This is maintained and modified by consumers, via
comment|/// getActions().
name|ActionList
name|Actions
decl_stmt|;
comment|/// The root list of jobs.
name|JobList
name|Jobs
decl_stmt|;
comment|/// Cache of translated arguments for a particular tool chain, bound
comment|/// architecture, and device offload kind.
struct|struct
name|TCArgsKey
name|final
block|{
specifier|const
name|ToolChain
modifier|*
name|TC
init|=
name|nullptr
decl_stmt|;
name|StringRef
name|BoundArch
decl_stmt|;
name|Action
operator|::
name|OffloadKind
name|DeviceOffloadKind
operator|=
name|Action
operator|::
name|OFK_None
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TCArgsKey
operator|&
name|K
operator|)
specifier|const
block|{
if|if
condition|(
name|TC
operator|<
name|K
operator|.
name|TC
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|TC
operator|==
name|K
operator|.
name|TC
operator|&&
name|BoundArch
operator|<
name|K
operator|.
name|BoundArch
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|TC
operator|==
name|K
operator|.
name|TC
operator|&&
name|BoundArch
operator|==
name|K
operator|.
name|BoundArch
operator|&&
name|DeviceOffloadKind
operator|<
name|K
operator|.
name|DeviceOffloadKind
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|TCArgsKey
argument_list|(
specifier|const
name|ToolChain
operator|*
name|TC
argument_list|,
name|StringRef
name|BoundArch
argument_list|,
name|Action
operator|::
name|OffloadKind
name|DeviceOffloadKind
argument_list|)
range|:
name|TC
argument_list|(
name|TC
argument_list|)
struct|,
name|BoundArch
argument_list|(
name|BoundArch
argument_list|)
struct|,
name|DeviceOffloadKind
argument_list|(
name|DeviceOffloadKind
argument_list|)
block|{}
block|}
empty_stmt|;
name|std
operator|::
name|map
operator|<
name|TCArgsKey
operator|,
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|*
operator|>
name|TCArgs
expr_stmt|;
comment|/// Temporary files which should be removed on exit.
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|TempFiles
expr_stmt|;
comment|/// Result files which should be removed on failure.
name|ArgStringMap
name|ResultFiles
decl_stmt|;
comment|/// Result files which are generated correctly on failure, and which should
comment|/// only be removed if we crash.
name|ArgStringMap
name|FailureResultFiles
decl_stmt|;
comment|/// Redirection for stdout, stderr, etc.
specifier|const
name|StringRef
modifier|*
modifier|*
name|Redirects
decl_stmt|;
comment|/// Whether we're compiling for diagnostic purposes.
name|bool
name|ForDiagnostics
decl_stmt|;
comment|/// Whether an error during the parsing of the input args.
name|bool
name|ContainsError
decl_stmt|;
name|public
label|:
name|Compilation
argument_list|(
argument|const Driver&D
argument_list|,
argument|const ToolChain&DefaultToolChain
argument_list|,
argument|llvm::opt::InputArgList *Args
argument_list|,
argument|llvm::opt::DerivedArgList *TranslatedArgs
argument_list|,
argument|bool ContainsError
argument_list|)
empty_stmt|;
operator|~
name|Compilation
argument_list|()
expr_stmt|;
specifier|const
name|Driver
operator|&
name|getDriver
argument_list|()
specifier|const
block|{
return|return
name|TheDriver
return|;
block|}
specifier|const
name|ToolChain
operator|&
name|getDefaultToolChain
argument_list|()
specifier|const
block|{
return|return
name|DefaultToolChain
return|;
block|}
name|unsigned
name|isOffloadingHostKind
argument_list|(
name|Action
operator|::
name|OffloadKind
name|Kind
argument_list|)
decl|const
block|{
return|return
name|ActiveOffloadMask
operator|&
name|Kind
return|;
block|}
comment|/// Iterator that visits device toolchains of a given kind.
typedef|typedef
specifier|const
name|std
operator|::
name|multimap
operator|<
name|Action
operator|::
name|OffloadKind
operator|,
specifier|const
name|ToolChain
operator|*
operator|>
operator|::
name|const_iterator
name|const_offload_toolchains_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|const_offload_toolchains_iterator
operator|,
name|const_offload_toolchains_iterator
operator|>
name|const_offload_toolchains_range
expr_stmt|;
name|template
operator|<
name|Action
operator|::
name|OffloadKind
name|Kind
operator|>
name|const_offload_toolchains_range
name|getOffloadToolChains
argument_list|()
specifier|const
block|{
return|return
name|OrderedOffloadingToolchains
operator|.
name|equal_range
argument_list|(
name|Kind
argument_list|)
return|;
block|}
comment|/// Return true if an offloading tool chain of a given kind exists.
name|template
operator|<
name|Action
operator|::
name|OffloadKind
name|Kind
operator|>
name|bool
name|hasOffloadToolChain
argument_list|()
specifier|const
block|{
return|return
name|OrderedOffloadingToolchains
operator|.
name|find
argument_list|(
name|Kind
argument_list|)
operator|!=
name|OrderedOffloadingToolchains
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Return an offload toolchain of the provided kind. Only one is expected to
comment|/// exist.
name|template
operator|<
name|Action
operator|::
name|OffloadKind
name|Kind
operator|>
specifier|const
name|ToolChain
operator|*
name|getSingleOffloadToolChain
argument_list|()
specifier|const
block|{
name|auto
name|TCs
operator|=
name|getOffloadToolChains
operator|<
name|Kind
operator|>
operator|(
operator|)
block|;
name|assert
argument_list|(
name|TCs
operator|.
name|first
operator|!=
name|TCs
operator|.
name|second
operator|&&
literal|"No tool chains of the selected kind exist!"
argument_list|)
block|;
name|assert
argument_list|(
name|std
operator|::
name|next
argument_list|(
name|TCs
operator|.
name|first
argument_list|)
operator|==
name|TCs
operator|.
name|second
operator|&&
literal|"More than one tool chain of the this kind exist."
argument_list|)
block|;
return|return
name|TCs
operator|.
name|first
operator|->
name|second
return|;
block|}
name|void
name|addOffloadDeviceToolChain
argument_list|(
specifier|const
name|ToolChain
operator|*
name|DeviceToolChain
argument_list|,
name|Action
operator|::
name|OffloadKind
name|OffloadKind
argument_list|)
block|{
name|assert
argument_list|(
name|OffloadKind
operator|!=
name|Action
operator|::
name|OFK_Host
operator|&&
name|OffloadKind
operator|!=
name|Action
operator|::
name|OFK_None
operator|&&
literal|"This is not a device tool chain!"
argument_list|)
expr_stmt|;
comment|// Update the host offload kind to also contain this kind.
name|ActiveOffloadMask
operator||=
name|OffloadKind
expr_stmt|;
name|OrderedOffloadingToolchains
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|OffloadKind
argument_list|,
name|DeviceToolChain
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|&
name|getInputArgs
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Args
return|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TranslatedArgs
return|;
block|}
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|&
name|getArgs
argument_list|()
block|{
return|return
operator|*
name|TranslatedArgs
return|;
block|}
name|ActionList
modifier|&
name|getActions
parameter_list|()
block|{
return|return
name|Actions
return|;
block|}
specifier|const
name|ActionList
operator|&
name|getActions
argument_list|()
specifier|const
block|{
return|return
name|Actions
return|;
block|}
comment|/// Creates a new Action owned by this Compilation.
comment|///
comment|/// The new Action is *not* added to the list returned by getActions().
name|template
operator|<
name|typename
name|T
operator|,
name|typename
operator|...
name|Args
operator|>
name|T
operator|*
name|MakeAction
argument_list|(
argument|Args&&... Arg
argument_list|)
block|{
name|T
operator|*
name|RawPtr
operator|=
name|new
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|Arg
operator|)
operator|...
argument_list|)
block|;
name|AllActions
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Action
operator|>
operator|(
name|RawPtr
operator|)
argument_list|)
block|;
return|return
name|RawPtr
return|;
block|}
name|JobList
modifier|&
name|getJobs
parameter_list|()
block|{
return|return
name|Jobs
return|;
block|}
specifier|const
name|JobList
operator|&
name|getJobs
argument_list|()
specifier|const
block|{
return|return
name|Jobs
return|;
block|}
name|void
name|addCommand
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
name|C
argument_list|)
block|{
name|Jobs
operator|.
name|addJob
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|C
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|getTempFiles
argument_list|()
specifier|const
block|{
return|return
name|TempFiles
return|;
block|}
specifier|const
name|ArgStringMap
operator|&
name|getResultFiles
argument_list|()
specifier|const
block|{
return|return
name|ResultFiles
return|;
block|}
specifier|const
name|ArgStringMap
operator|&
name|getFailureResultFiles
argument_list|()
specifier|const
block|{
return|return
name|FailureResultFiles
return|;
block|}
comment|/// Returns the sysroot path.
name|StringRef
name|getSysRoot
argument_list|()
specifier|const
expr_stmt|;
comment|/// getArgsForToolChain - Return the derived argument list for the
comment|/// tool chain \p TC (or the default tool chain, if TC is not specified).
comment|/// If a device offloading kind is specified, a translation specific for that
comment|/// kind is performed, if any.
comment|///
comment|/// \param BoundArch - The bound architecture name, or 0.
comment|/// \param DeviceOffloadKind - The offload device kind that should be used in
comment|/// the translation, if any.
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|DerivedArgList
operator|&
name|getArgsForToolChain
argument_list|(
argument|const ToolChain *TC
argument_list|,
argument|StringRef BoundArch
argument_list|,
argument|Action::OffloadKind DeviceOffloadKind
argument_list|)
expr_stmt|;
comment|/// addTempFile - Add a file to remove on exit, and returns its
comment|/// argument.
specifier|const
name|char
modifier|*
name|addTempFile
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|TempFiles
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
expr_stmt|;
return|return
name|Name
return|;
block|}
comment|/// addResultFile - Add a file to remove on failure, and returns its
comment|/// argument.
specifier|const
name|char
modifier|*
name|addResultFile
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
specifier|const
name|JobAction
modifier|*
name|JA
parameter_list|)
block|{
name|ResultFiles
index|[
name|JA
index|]
operator|=
name|Name
expr_stmt|;
return|return
name|Name
return|;
block|}
comment|/// addFailureResultFile - Add a file to remove if we crash, and returns its
comment|/// argument.
specifier|const
name|char
modifier|*
name|addFailureResultFile
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
specifier|const
name|JobAction
modifier|*
name|JA
parameter_list|)
block|{
name|FailureResultFiles
index|[
name|JA
index|]
operator|=
name|Name
expr_stmt|;
return|return
name|Name
return|;
block|}
comment|/// CleanupFile - Delete a given file.
comment|///
comment|/// \param IssueErrors - Report failures as errors.
comment|/// \return Whether the file was removed successfully.
name|bool
name|CleanupFile
argument_list|(
specifier|const
name|char
operator|*
name|File
argument_list|,
name|bool
name|IssueErrors
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// CleanupFileList - Remove the files in the given list.
comment|///
comment|/// \param IssueErrors - Report failures as errors.
comment|/// \return Whether all files were removed successfully.
name|bool
name|CleanupFileList
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|Files
argument_list|,
name|bool
name|IssueErrors
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// CleanupFileMap - Remove the files in the given map.
comment|///
comment|/// \param JA - If specified, only delete the files associated with this
comment|/// JobAction.  Otherwise, delete all files in the map.
comment|/// \param IssueErrors - Report failures as errors.
comment|/// \return Whether all files were removed successfully.
name|bool
name|CleanupFileMap
argument_list|(
specifier|const
name|ArgStringMap
operator|&
name|Files
argument_list|,
specifier|const
name|JobAction
operator|*
name|JA
argument_list|,
name|bool
name|IssueErrors
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// ExecuteCommand - Execute an actual command.
comment|///
comment|/// \param FailingCommand - For non-zero results, this will be set to the
comment|/// Command which failed, if any.
comment|/// \return The result code of the subprocess.
name|int
name|ExecuteCommand
argument_list|(
specifier|const
name|Command
operator|&
name|C
argument_list|,
specifier|const
name|Command
operator|*
operator|&
name|FailingCommand
argument_list|)
decl|const
decl_stmt|;
comment|/// ExecuteJob - Execute a single job.
comment|///
comment|/// \param FailingCommands - For non-zero results, this will be a vector of
comment|/// failing commands and their associated result code.
name|void
name|ExecuteJobs
argument_list|(
specifier|const
name|JobList
operator|&
name|Jobs
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
operator|>>
operator|&
name|FailingCommands
argument_list|)
decl|const
decl_stmt|;
comment|/// initCompilationForDiagnostics - Remove stale state and suppress output
comment|/// so compilation can be reexecuted to generate additional diagnostic
comment|/// information (e.g., preprocessed source(s)).
name|void
name|initCompilationForDiagnostics
parameter_list|()
function_decl|;
comment|/// Return true if we're compiling for diagnostics.
name|bool
name|isForDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|ForDiagnostics
return|;
block|}
comment|/// Return whether an error during the parsing of the input args.
name|bool
name|containsError
argument_list|()
specifier|const
block|{
return|return
name|ContainsError
return|;
block|}
comment|/// Redirect - Redirect output of this compilation. Can only be done once.
comment|///
comment|/// \param Redirects - array of pointers to paths. The array
comment|/// should have a size of three. The inferior process's
comment|/// stdin(0), stdout(1), and stderr(2) will be redirected to the
comment|/// corresponding paths. This compilation instance becomes
comment|/// the owner of Redirects and will delete the array and StringRef's.
name|void
name|Redirect
parameter_list|(
specifier|const
name|StringRef
modifier|*
modifier|*
name|Redirects
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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

