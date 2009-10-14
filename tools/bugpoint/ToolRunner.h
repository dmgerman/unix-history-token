begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tools/bugpoint/ToolRunner.h -----------------------------*- C++ -*-===//
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
comment|// This file exposes an abstraction around a platform C compiler, used to
end_comment

begin_comment
comment|// compile C and assembly code.  It also exposes an "AbstractIntepreter"
end_comment

begin_comment
comment|// interface, which is used to execute code using one of the LLVM execution
end_comment

begin_comment
comment|// engines.
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
name|BUGPOINT_TOOLRUNNER_H
end_ifndef

begin_define
define|#
directive|define
name|BUGPOINT_TOOLRUNNER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SystemUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|<exception>
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
extern|extern cl::opt<bool> SaveTemps;
specifier|extern
name|Triple
name|TargetTriple
decl_stmt|;
name|class
name|CBE
decl_stmt|;
name|class
name|LLC
decl_stmt|;
comment|/// ToolExecutionError - An instance of this class is thrown by the
comment|/// AbstractInterpreter instances if there is an error running a tool (e.g., LLC
comment|/// crashes) which prevents execution of the program.
comment|///
name|class
name|ToolExecutionError
range|:
name|std
operator|::
name|exception
block|{
name|std
operator|::
name|string
name|Message
block|;
name|public
operator|:
name|explicit
name|ToolExecutionError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|M
argument_list|)
operator|:
name|Message
argument_list|(
argument|M
argument_list|)
block|{}
name|virtual
operator|~
name|ToolExecutionError
argument_list|()
name|throw
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|what
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|Message
operator|.
name|c_str
argument_list|()
return|;
block|}
expr|}
block|;
comment|//===---------------------------------------------------------------------===//
comment|// GCC abstraction
comment|//
name|class
name|GCC
block|{
name|sys
operator|::
name|Path
name|GCCPath
block|;
comment|// The path to the gcc executable.
name|sys
operator|::
name|Path
name|RemoteClientPath
block|;
comment|// The path to the rsh / ssh executable.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|gccArgs
block|;
comment|// GCC-specific arguments.
name|GCC
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|gccPath
argument_list|,
specifier|const
name|sys
operator|::
name|Path
operator|&
name|RemotePath
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
operator|*
name|GCCArgs
argument_list|)
operator|:
name|GCCPath
argument_list|(
name|gccPath
argument_list|)
block|,
name|RemoteClientPath
argument_list|(
argument|RemotePath
argument_list|)
block|{
if|if
condition|(
name|GCCArgs
condition|)
name|gccArgs
operator|=
operator|*
name|GCCArgs
expr_stmt|;
block|}
name|public
operator|:
expr|enum
name|FileType
block|{
name|AsmFile
block|,
name|CFile
block|}
block|;
specifier|static
name|GCC
operator|*
name|create
argument_list|(
name|std
operator|::
name|string
operator|&
name|Message
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
operator|*
name|Args
argument_list|)
block|;
comment|/// ExecuteProgram - Execute the program specified by "ProgramFile" (which is
comment|/// either a .s file, or a .c file, specified by FileType), with the specified
comment|/// arguments.  Standard input is specified with InputFile, and standard
comment|/// Output is captured to the specified OutputFile location.  The SharedLibs
comment|/// option specifies optional native shared objects that can be loaded into
comment|/// the program for execution.
comment|///
name|int
name|ExecuteProgram
argument_list|(
argument|const std::string&ProgramFile
argument_list|,
argument|const std::vector<std::string>&Args
argument_list|,
argument|FileType fileType
argument_list|,
argument|const std::string&InputFile
argument_list|,
argument|const std::string&OutputFile
argument_list|,
argument|const std::vector<std::string>&GCCArgs =                          std::vector<std::string>()
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|;
comment|/// MakeSharedObject - This compiles the specified file (which is either a .c
comment|/// file or a .s file) into a shared object.
comment|///
name|int
name|MakeSharedObject
argument_list|(
argument|const std::string&InputFile
argument_list|,
argument|FileType fileType
argument_list|,
argument|std::string&OutputFile
argument_list|,
argument|const std::vector<std::string>&ArgsForGCC
argument_list|)
block|; }
block|;
comment|//===---------------------------------------------------------------------===//
comment|/// AbstractInterpreter Class - Subclasses of this class are used to execute
comment|/// LLVM bitcode in a variety of ways.  This abstract interface hides this
comment|/// complexity behind a simple interface.
comment|///
name|class
name|AbstractInterpreter
block|{
name|public
operator|:
specifier|static
name|CBE
operator|*
name|createCBE
argument_list|(
specifier|const
name|char
operator|*
name|Argv0
argument_list|,
name|std
operator|::
name|string
operator|&
name|Message
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
operator|*
name|Args
operator|=
literal|0
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
operator|*
name|GCCArgs
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|LLC
operator|*
name|createLLC
argument_list|(
specifier|const
name|char
operator|*
name|Argv0
argument_list|,
name|std
operator|::
name|string
operator|&
name|Message
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
operator|*
name|Args
operator|=
literal|0
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
operator|*
name|GCCArgs
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|AbstractInterpreter
operator|*
name|createLLI
argument_list|(
specifier|const
name|char
operator|*
name|Argv0
argument_list|,
name|std
operator|::
name|string
operator|&
name|Message
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
operator|*
name|Args
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|AbstractInterpreter
operator|*
name|createJIT
argument_list|(
specifier|const
name|char
operator|*
name|Argv0
argument_list|,
name|std
operator|::
name|string
operator|&
name|Message
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
operator|*
name|Args
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|AbstractInterpreter
operator|*
name|createCustom
argument_list|(
name|std
operator|::
name|string
operator|&
name|Message
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ExecCommandLine
argument_list|)
block|;
name|virtual
operator|~
name|AbstractInterpreter
argument_list|()
block|{}
comment|/// compileProgram - Compile the specified program from bitcode to executable
comment|/// code.  This does not produce any output, it is only used when debugging
comment|/// the code generator.  If the code generator fails, an exception should be
comment|/// thrown, otherwise, this function will just return.
name|virtual
name|void
name|compileProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|)
block|{}
comment|/// OutputCode - Compile the specified program from bitcode to code
comment|/// understood by the GCC driver (either C or asm).  If the code generator
comment|/// fails, an exception should be thrown, otherwise, this function returns the
comment|/// type of code emitted.
name|virtual
name|GCC
operator|::
name|FileType
name|OutputCode
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|sys::Path&OutFile
argument_list|)
block|{
name|throw
name|std
operator|::
name|string
argument_list|(
literal|"OutputCode not supported by this AbstractInterpreter!"
argument_list|)
block|;   }
comment|/// ExecuteProgram - Run the specified bitcode file, emitting output to the
comment|/// specified filename.  This returns the exit code of the program.
comment|///
name|virtual
name|int
name|ExecuteProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|const std::vector<std::string>&Args
argument_list|,
argument|const std::string&InputFile
argument_list|,
argument|const std::string&OutputFile
argument_list|,
argument|const std::vector<std::string>&GCCArgs =                                std::vector<std::string>()
argument_list|,
argument|const std::vector<std::string>&SharedLibs =                                std::vector<std::string>()
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
operator|=
literal|0
block|; }
block|;
comment|//===---------------------------------------------------------------------===//
comment|// CBE Implementation of AbstractIntepreter interface
comment|//
name|class
name|CBE
operator|:
name|public
name|AbstractInterpreter
block|{
name|sys
operator|::
name|Path
name|LLCPath
block|;
comment|// The path to the `llc' executable.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ToolArgs
block|;
comment|// Extra args to pass to LLC.
name|GCC
operator|*
name|gcc
block|;
name|public
operator|:
name|CBE
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|llcPath
argument_list|,
name|GCC
operator|*
name|Gcc
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
operator|*
name|Args
argument_list|)
operator|:
name|LLCPath
argument_list|(
name|llcPath
argument_list|)
block|,
name|gcc
argument_list|(
argument|Gcc
argument_list|)
block|{
name|ToolArgs
operator|.
name|clear
argument_list|()
block|;
if|if
condition|(
name|Args
condition|)
name|ToolArgs
operator|=
operator|*
name|Args
expr_stmt|;
block|}
operator|~
name|CBE
argument_list|()
block|{
name|delete
name|gcc
block|; }
comment|/// compileProgram - Compile the specified program from bitcode to executable
comment|/// code.  This does not produce any output, it is only used when debugging
comment|/// the code generator.  If the code generator fails, an exception should be
comment|/// thrown, otherwise, this function will just return.
name|virtual
name|void
name|compileProgram
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Bitcode
argument_list|)
block|;
name|virtual
name|int
name|ExecuteProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|const std::vector<std::string>&Args
argument_list|,
argument|const std::string&InputFile
argument_list|,
argument|const std::string&OutputFile
argument_list|,
argument|const std::vector<std::string>&GCCArgs =                                std::vector<std::string>()
argument_list|,
argument|const std::vector<std::string>&SharedLibs =                                std::vector<std::string>()
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|;
comment|/// OutputCode - Compile the specified program from bitcode to code
comment|/// understood by the GCC driver (either C or asm).  If the code generator
comment|/// fails, an exception should be thrown, otherwise, this function returns the
comment|/// type of code emitted.
name|virtual
name|GCC
operator|::
name|FileType
name|OutputCode
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Bitcode
argument_list|,
name|sys
operator|::
name|Path
operator|&
name|OutFile
argument_list|)
block|; }
block|;
comment|//===---------------------------------------------------------------------===//
comment|// LLC Implementation of AbstractIntepreter interface
comment|//
name|class
name|LLC
operator|:
name|public
name|AbstractInterpreter
block|{
name|std
operator|::
name|string
name|LLCPath
block|;
comment|// The path to the LLC executable.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ToolArgs
block|;
comment|// Extra args to pass to LLC.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|gccArgs
block|;
comment|// Extra args to pass to GCC.
name|GCC
operator|*
name|gcc
block|;
name|public
operator|:
name|LLC
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|llcPath
argument_list|,
name|GCC
operator|*
name|Gcc
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
operator|*
name|Args
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
operator|*
name|GCCArgs
argument_list|)
operator|:
name|LLCPath
argument_list|(
name|llcPath
argument_list|)
block|,
name|gcc
argument_list|(
argument|Gcc
argument_list|)
block|{
name|ToolArgs
operator|.
name|clear
argument_list|()
block|;
if|if
condition|(
name|Args
condition|)
name|ToolArgs
operator|=
operator|*
name|Args
expr_stmt|;
if|if
condition|(
name|GCCArgs
condition|)
name|gccArgs
operator|=
operator|*
name|GCCArgs
expr_stmt|;
block|}
operator|~
name|LLC
argument_list|()
block|{
name|delete
name|gcc
block|; }
comment|/// compileProgram - Compile the specified program from bitcode to executable
comment|/// code.  This does not produce any output, it is only used when debugging
comment|/// the code generator.  If the code generator fails, an exception should be
comment|/// thrown, otherwise, this function will just return.
name|virtual
name|void
name|compileProgram
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Bitcode
argument_list|)
block|;
name|virtual
name|int
name|ExecuteProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|const std::vector<std::string>&Args
argument_list|,
argument|const std::string&InputFile
argument_list|,
argument|const std::string&OutputFile
argument_list|,
argument|const std::vector<std::string>&GCCArgs =                                std::vector<std::string>()
argument_list|,
argument|const std::vector<std::string>&SharedLibs =                                 std::vector<std::string>()
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|;
name|virtual
name|GCC
operator|::
name|FileType
name|OutputCode
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Bitcode
argument_list|,
name|sys
operator|::
name|Path
operator|&
name|OutFile
argument_list|)
block|;    }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

