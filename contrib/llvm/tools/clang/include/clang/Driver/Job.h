begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Job.h - Commands to Execute ----------------------------*- C++ -*-===//
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
name|LLVM_CLANG_DRIVER_JOB_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_JOB_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Option.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|Command
decl_stmt|;
name|class
name|Tool
decl_stmt|;
name|class
name|InputInfo
decl_stmt|;
comment|// Re-export this as clang::driver::ArgStringList.
name|using
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
expr_stmt|;
struct|struct
name|CrashReportInfo
block|{
name|StringRef
name|Filename
decl_stmt|;
name|StringRef
name|VFSPath
decl_stmt|;
name|CrashReportInfo
argument_list|(
argument|StringRef Filename
argument_list|,
argument|StringRef VFSPath
argument_list|)
block|:
name|Filename
argument_list|(
name|Filename
argument_list|)
operator|,
name|VFSPath
argument_list|(
argument|VFSPath
argument_list|)
block|{}
block|}
struct|;
comment|/// Command - An executable path/name and argument vector to
comment|/// execute.
name|class
name|Command
block|{
comment|/// Source - The action which caused the creation of this job.
specifier|const
name|Action
modifier|&
name|Source
decl_stmt|;
comment|/// Tool - The tool which caused the creation of this job.
specifier|const
name|Tool
modifier|&
name|Creator
decl_stmt|;
comment|/// The executable to run.
specifier|const
name|char
modifier|*
name|Executable
decl_stmt|;
comment|/// The list of program arguments (not including the implicit first
comment|/// argument, which will be the executable).
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|Arguments
expr_stmt|;
comment|/// The list of program arguments which are inputs.
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|InputFilenames
expr_stmt|;
comment|/// Response file name, if this command is set to use one, or nullptr
comment|/// otherwise
specifier|const
name|char
modifier|*
name|ResponseFile
decl_stmt|;
comment|/// The input file list in case we need to emit a file list instead of a
comment|/// proper response file
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|InputFileList
expr_stmt|;
comment|/// String storage if we need to create a new argument to specify a response
comment|/// file
name|std
operator|::
name|string
name|ResponseFileFlag
expr_stmt|;
comment|/// See Command::setEnvironment
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|Environment
expr_stmt|;
comment|/// When a response file is needed, we try to put most arguments in an
comment|/// exclusive file, while others remains as regular command line arguments.
comment|/// This functions fills a vector with the regular command line arguments,
comment|/// argv, excluding the ones passed in a response file.
name|void
name|buildArgvForResponseFile
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
comment|/// Encodes an array of C strings into a single string separated by whitespace.
comment|/// This function will also put in quotes arguments that have whitespaces and
comment|/// will escape the regular backslashes (used in Windows paths) and quotes.
comment|/// The results are the contents of a response file, written into a raw_ostream.
name|void
name|writeResponseFile
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|Command
argument_list|(
specifier|const
name|Action
operator|&
name|Source
argument_list|,
specifier|const
name|Tool
operator|&
name|Creator
argument_list|,
specifier|const
name|char
operator|*
name|Executable
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|Arguments
argument_list|,
name|ArrayRef
operator|<
name|InputInfo
operator|>
name|Inputs
argument_list|)
expr_stmt|;
comment|// FIXME: This really shouldn't be copyable, but is currently copied in some
comment|// error handling in Driver::generateCompilationDiagnostics.
name|Command
argument_list|(
specifier|const
name|Command
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|Command
argument_list|()
block|{}
name|virtual
name|void
name|Print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|,
argument|const char *Terminator
argument_list|,
argument|bool Quote
argument_list|,
argument|CrashReportInfo *CrashInfo = nullptr
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|int
name|Execute
argument_list|(
specifier|const
name|StringRef
operator|*
operator|*
name|Redirects
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|,
name|bool
operator|*
name|ExecutionFailed
argument_list|)
decl|const
decl_stmt|;
comment|/// getSource - Return the Action which caused the creation of this job.
specifier|const
name|Action
operator|&
name|getSource
argument_list|()
specifier|const
block|{
return|return
name|Source
return|;
block|}
comment|/// getCreator - Return the Tool which caused the creation of this job.
specifier|const
name|Tool
operator|&
name|getCreator
argument_list|()
specifier|const
block|{
return|return
name|Creator
return|;
block|}
comment|/// Set to pass arguments via a response file when launching the command
name|void
name|setResponseFile
parameter_list|(
specifier|const
name|char
modifier|*
name|FileName
parameter_list|)
function_decl|;
comment|/// Set an input file list, necessary if we need to use a response file but
comment|/// the tool being called only supports input files lists.
name|void
name|setInputFileList
argument_list|(
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|List
argument_list|)
block|{
name|InputFileList
operator|=
name|std
operator|::
name|move
argument_list|(
name|List
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Sets the environment to be used by the new process.
comment|/// \param NewEnvironment An array of environment variables.
comment|/// \remark If the environment remains unset, then the environment
comment|///         from the parent process will be used.
name|void
name|setEnvironment
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|NewEnvironment
argument_list|)
decl_stmt|;
specifier|const
name|char
operator|*
name|getExecutable
argument_list|()
specifier|const
block|{
return|return
name|Executable
return|;
block|}
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|getArguments
argument_list|()
specifier|const
block|{
return|return
name|Arguments
return|;
block|}
comment|/// Print a command argument, and optionally quote it.
specifier|static
name|void
name|printArg
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|,
name|StringRef
name|Arg
argument_list|,
name|bool
name|Quote
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Like Command, but with a fallback which is executed in case
comment|/// the primary command crashes.
name|class
name|FallbackCommand
range|:
name|public
name|Command
block|{
name|public
operator|:
name|FallbackCommand
argument_list|(
specifier|const
name|Action
operator|&
name|Source_
argument_list|,
specifier|const
name|Tool
operator|&
name|Creator_
argument_list|,
specifier|const
name|char
operator|*
name|Executable_
argument_list|,
specifier|const
name|ArgStringList
operator|&
name|Arguments_
argument_list|,
name|ArrayRef
operator|<
name|InputInfo
operator|>
name|Inputs
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
name|Fallback_
argument_list|)
block|;
name|void
name|Print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|,
argument|const char *Terminator
argument_list|,
argument|bool Quote
argument_list|,
argument|CrashReportInfo *CrashInfo = nullptr
argument_list|)
specifier|const
name|override
block|;
name|int
name|Execute
argument_list|(
argument|const StringRef **Redirects
argument_list|,
argument|std::string *ErrMsg
argument_list|,
argument|bool *ExecutionFailed
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
name|Fallback
block|; }
decl_stmt|;
comment|/// Like Command, but always pretends that the wrapped command succeeded.
name|class
name|ForceSuccessCommand
range|:
name|public
name|Command
block|{
name|public
operator|:
name|ForceSuccessCommand
argument_list|(
specifier|const
name|Action
operator|&
name|Source_
argument_list|,
specifier|const
name|Tool
operator|&
name|Creator_
argument_list|,
specifier|const
name|char
operator|*
name|Executable_
argument_list|,
specifier|const
name|ArgStringList
operator|&
name|Arguments_
argument_list|,
name|ArrayRef
operator|<
name|InputInfo
operator|>
name|Inputs
argument_list|)
block|;
name|void
name|Print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|,
argument|const char *Terminator
argument_list|,
argument|bool Quote
argument_list|,
argument|CrashReportInfo *CrashInfo = nullptr
argument_list|)
specifier|const
name|override
block|;
name|int
name|Execute
argument_list|(
argument|const StringRef **Redirects
argument_list|,
argument|std::string *ErrMsg
argument_list|,
argument|bool *ExecutionFailed
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// JobList - A sequence of jobs to perform.
name|class
name|JobList
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
operator|,
literal|4
operator|>
name|list_type
expr_stmt|;
typedef|typedef
name|list_type
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|pointee_iterator
operator|<
name|list_type
operator|::
name|iterator
operator|>
name|iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|pointee_iterator
operator|<
name|list_type
operator|::
name|const_iterator
operator|>
name|const_iterator
expr_stmt|;
name|private
label|:
name|list_type
name|Jobs
decl_stmt|;
name|public
label|:
name|void
name|Print
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|char
operator|*
name|Terminator
argument_list|,
name|bool
name|Quote
argument_list|,
name|CrashReportInfo
operator|*
name|CrashInfo
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Add a job to the list (taking ownership).
name|void
name|addJob
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Command
operator|>
name|J
argument_list|)
block|{
name|Jobs
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|J
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Clear the job list.
name|void
name|clear
parameter_list|()
function_decl|;
specifier|const
name|list_type
operator|&
name|getJobs
argument_list|()
specifier|const
block|{
return|return
name|Jobs
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Jobs
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|Jobs
operator|.
name|size
argument_list|()
return|;
block|}
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Jobs
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Jobs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Jobs
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Jobs
operator|.
name|end
argument_list|()
return|;
block|}
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

