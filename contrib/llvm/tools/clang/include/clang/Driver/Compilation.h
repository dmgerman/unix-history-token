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
name|CLANG_DRIVER_COMPILATION_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_COMPILATION_H_
end_define

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
file|"llvm/ADT/SmallVector.h"
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
name|DerivedArgList
decl_stmt|;
name|class
name|Driver
decl_stmt|;
name|class
name|InputArgList
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
comment|/// The original (untranslated) input argument list.
name|InputArgList
modifier|*
name|Args
decl_stmt|;
comment|/// The list of actions.
name|ActionList
name|Actions
decl_stmt|;
comment|/// The root list of jobs.
name|JobList
name|Jobs
decl_stmt|;
comment|/// Cache of translated arguments for a particular tool chain.
name|llvm
operator|::
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|ToolChain
operator|*
operator|,
specifier|const
name|char
operator|*
operator|>
operator|,
name|DerivedArgList
operator|*
operator|>
name|TCArgs
expr_stmt|;
comment|/// Temporary files which should be removed on exit.
name|ArgStringList
name|TempFiles
decl_stmt|;
comment|/// Result files which should be removed on failure.
name|ArgStringList
name|ResultFiles
decl_stmt|;
name|public
label|:
name|Compilation
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|ToolChain
operator|&
name|DefaultToolChain
argument_list|,
name|InputArgList
operator|*
name|Args
argument_list|)
expr_stmt|;
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
specifier|const
name|InputArgList
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Args
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
specifier|const
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
name|ArgStringList
operator|&
name|getResultFiles
argument_list|()
specifier|const
block|{
return|return
name|ResultFiles
return|;
block|}
comment|/// getArgsForToolChain - Return the derived argument list for the
comment|/// tool chain \arg TC (or the default tool chain, if TC is not
comment|/// specified).
comment|///
comment|/// \param BoundArch - The bound architecture name, or 0.
specifier|const
name|DerivedArgList
modifier|&
name|getArgsForToolChain
parameter_list|(
specifier|const
name|ToolChain
modifier|*
name|TC
parameter_list|,
specifier|const
name|char
modifier|*
name|BoundArch
parameter_list|)
function_decl|;
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
parameter_list|)
block|{
name|ResultFiles
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
comment|/// CleanupFileList - Remove the files in the given list.
comment|///
comment|/// \param IssueErrors - Report failures as errors.
comment|/// \return Whether all files were removed successfully.
name|bool
name|CleanupFileList
argument_list|(
specifier|const
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
comment|/// PrintJob - Print one job in -### format.
comment|///
comment|/// \param OS - The stream to print on.
comment|/// \param J - The job to print.
comment|/// \param Terminator - A string to print at the end of the line.
comment|/// \param Quote - Should separate arguments be quoted.
name|void
name|PrintJob
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|Job
operator|&
name|J
argument_list|,
specifier|const
name|char
operator|*
name|Terminator
argument_list|,
name|bool
name|Quote
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
comment|/// \param FailingCommand - For non-zero results, this will be set to the
comment|/// Command which failed.
comment|/// \return The accumulated result code of the job.
name|int
name|ExecuteJob
argument_list|(
specifier|const
name|Job
operator|&
name|J
argument_list|,
specifier|const
name|Command
operator|*
operator|&
name|FailingCommand
argument_list|)
decl|const
decl_stmt|;
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

