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
name|class
name|Job
block|{
name|public
label|:
enum|enum
name|JobClass
block|{
name|CommandClass
block|,
name|FallbackCommandClass
block|,
name|JobListClass
block|}
enum|;
name|private
label|:
name|JobClass
name|Kind
decl_stmt|;
name|protected
label|:
name|Job
argument_list|(
argument|JobClass _Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|_Kind
argument_list|)
block|{}
name|public
label|:
name|virtual
operator|~
name|Job
argument_list|()
expr_stmt|;
name|JobClass
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// Print - Print this Job in -### format.
comment|///
comment|/// \param OS - The stream to print on.
comment|/// \param Terminator - A string to print at the end of the line.
comment|/// \param Quote - Should separate arguments be quoted.
comment|/// \param CrashInfo - Details for inclusion in a crash report.
name|virtual
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
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Command - An executable path/name and argument vector to
comment|/// execute.
name|class
name|Command
range|:
name|public
name|Job
block|{
comment|/// Source - The action which caused the creation of this job.
specifier|const
name|Action
operator|&
name|Source
block|;
comment|/// Tool - The tool which caused the creation of this job.
specifier|const
name|Tool
operator|&
name|Creator
block|;
comment|/// The executable to run.
specifier|const
name|char
operator|*
name|Executable
block|;
comment|/// The list of program arguments (not including the implicit first
comment|/// argument, which will be the executable).
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|Arguments
block|;
comment|/// Response file name, if this command is set to use one, or nullptr
comment|/// otherwise
specifier|const
name|char
operator|*
name|ResponseFile
block|;
comment|/// The input file list in case we need to emit a file list instead of a
comment|/// proper response file
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
name|InputFileList
block|;
comment|/// String storage if we need to create a new argument to specify a response
comment|/// file
name|std
operator|::
name|string
name|ResponseFileFlag
block|;
comment|/// When a response file is needed, we try to put most arguments in an
comment|/// exclusive file, while others remains as regular command line arguments.
comment|/// This functions fills a vector with the regular command line arguments,
comment|/// argv, excluding the ones passed in a response file.
name|void
name|buildArgvForResponseFile
argument_list|(
argument|llvm::SmallVectorImpl<const char *>&Out
argument_list|)
specifier|const
block|;
comment|/// Encodes an array of C strings into a single string separated by whitespace.
comment|/// This function will also put in quotes arguments that have whitespaces and
comment|/// will escape the regular backslashes (used in Windows paths) and quotes.
comment|/// The results are the contents of a response file, written into a raw_ostream.
name|void
name|writeResponseFile
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|public
operator|:
name|Command
argument_list|(
specifier|const
name|Action
operator|&
name|_Source
argument_list|,
specifier|const
name|Tool
operator|&
name|_Creator
argument_list|,
specifier|const
name|char
operator|*
name|_Executable
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|_Arguments
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
name|virtual
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
block|;
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
argument_list|(
specifier|const
name|char
operator|*
name|FileName
argument_list|)
block|;
comment|/// Set an input file list, necessary if we need to use a response file but
comment|/// the tool being called only supports input files lists.
name|void
name|setInputFileList
argument_list|(
argument|llvm::opt::ArgStringList List
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
block|;   }
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const Job *J
argument_list|)
block|{
return|return
name|J
operator|->
name|getKind
argument_list|()
operator|==
name|CommandClass
operator|||
name|J
operator|->
name|getKind
argument_list|()
operator|==
name|FallbackCommandClass
return|;
block|}
expr|}
block|;
comment|/// Like Command, but with a fallback which is executed in case
comment|/// the primary command crashes.
name|class
name|FallbackCommand
operator|:
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const Job *J
argument_list|)
block|{
return|return
name|J
operator|->
name|getKind
argument_list|()
operator|==
name|FallbackCommandClass
return|;
block|}
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
block|;
comment|/// JobList - A sequence of jobs to perform.
name|class
name|JobList
operator|:
name|public
name|Job
block|{
name|public
operator|:
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Job
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
name|JobList
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|JobList
argument_list|()
block|{}
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
expr_stmt|;
comment|/// Add a job to the list (taking ownership).
name|void
name|addJob
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Job
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
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Job
modifier|*
name|J
parameter_list|)
block|{
return|return
name|J
operator|->
name|getKind
argument_list|()
operator|==
name|JobListClass
return|;
block|}
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

