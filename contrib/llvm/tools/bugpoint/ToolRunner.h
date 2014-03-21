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
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SystemUtils.h"
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
name|LLC
decl_stmt|;
comment|//===---------------------------------------------------------------------===//
comment|// GCC abstraction
comment|//
name|class
name|GCC
block|{
name|std
operator|::
name|string
name|GCCPath
expr_stmt|;
comment|// The path to the gcc executable.
name|std
operator|::
name|string
name|RemoteClientPath
expr_stmt|;
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
expr_stmt|;
comment|// GCC-specific arguments.
name|GCC
argument_list|(
argument|StringRef gccPath
argument_list|,
argument|StringRef RemotePath
argument_list|,
argument|const std::vector<std::string> *GCCArgs
argument_list|)
block|:
name|GCCPath
argument_list|(
name|gccPath
argument_list|)
operator|,
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
label|:
enum|enum
name|FileType
block|{
name|AsmFile
block|,
name|ObjectFile
block|,
name|CFile
block|}
enum|;
specifier|static
name|GCC
modifier|*
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
name|string
operator|&
name|GCCBinary
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
decl_stmt|;
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
specifier|const
name|std
operator|::
name|string
operator|&
name|ProgramFile
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
name|Args
argument_list|,
name|FileType
name|fileType
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|InputFile
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutputFile
argument_list|,
name|std
operator|::
name|string
operator|*
name|Error
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
operator|&
name|GCCArgs
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
argument_list|,
name|unsigned
name|Timeout
operator|=
literal|0
argument_list|,
name|unsigned
name|MemoryLimit
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// MakeSharedObject - This compiles the specified file (which is either a .c
comment|/// file or a .s file) into a shared object.
comment|///
name|int
name|MakeSharedObject
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InputFile
argument_list|,
name|FileType
name|fileType
argument_list|,
name|std
operator|::
name|string
operator|&
name|OutputFile
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
name|ArgsForGCC
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|//===---------------------------------------------------------------------===//
comment|/// AbstractInterpreter Class - Subclasses of this class are used to execute
comment|/// LLVM bitcode in a variety of ways.  This abstract interface hides this
comment|/// complexity behind a simple interface.
comment|///
name|class
name|AbstractInterpreter
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
specifier|static
name|LLC
modifier|*
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
name|string
operator|&
name|GCCBinary
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
argument_list|,
name|bool
name|UseIntegratedAssembler
operator|=
name|false
argument_list|)
decl_stmt|;
specifier|static
name|AbstractInterpreter
modifier|*
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
decl_stmt|;
specifier|static
name|AbstractInterpreter
modifier|*
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
decl_stmt|;
specifier|static
name|AbstractInterpreter
modifier|*
name|createCustomCompiler
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
name|CompileCommandLine
argument_list|)
decl_stmt|;
specifier|static
name|AbstractInterpreter
modifier|*
name|createCustomExecutor
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
decl_stmt|;
name|virtual
operator|~
name|AbstractInterpreter
argument_list|()
block|{}
comment|/// compileProgram - Compile the specified program from bitcode to executable
comment|/// code.  This does not produce any output, it is only used when debugging
comment|/// the code generator.  It returns false if the code generator fails.
name|virtual
name|void
name|compileProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|std::string *Error
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|{}
comment|/// OutputCode - Compile the specified program from bitcode to code
comment|/// understood by the GCC driver (either C or asm).  If the code generator
comment|/// fails, it sets Error, otherwise, this function returns the type of code
comment|/// emitted.
name|virtual
name|GCC
operator|::
name|FileType
name|OutputCode
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|std::string&OutFile
argument_list|,
argument|std::string&Error
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|{
name|Error
operator|=
literal|"OutputCode not supported by this AbstractInterpreter!"
block|;
return|return
name|GCC
operator|::
name|AsmFile
return|;
block|}
comment|/// ExecuteProgram - Run the specified bitcode file, emitting output to the
comment|/// specified filename.  This sets RetVal to the exit code of the program or
comment|/// returns false if a problem was encountered that prevented execution of
comment|/// the program.
comment|///
name|virtual
name|int
name|ExecuteProgram
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Bitcode
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
name|Args
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|InputFile
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutputFile
argument_list|,
name|std
operator|::
name|string
operator|*
name|Error
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
name|GCCArgs
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
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
name|SharedLibs
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|(
operator|)
argument_list|,
name|unsigned
name|Timeout
operator|=
literal|0
argument_list|,
name|unsigned
name|MemoryLimit
operator|=
literal|0
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|//===---------------------------------------------------------------------===//
comment|// LLC Implementation of AbstractIntepreter interface
comment|//
name|class
name|LLC
range|:
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
name|GCC
operator|*
name|gcc
block|;
name|bool
name|UseIntegratedAssembler
block|;
name|public
operator|:
name|LLC
argument_list|(
argument|const std::string&llcPath
argument_list|,
argument|GCC *Gcc
argument_list|,
argument|const std::vector<std::string> *Args
argument_list|,
argument|bool useIntegratedAssembler
argument_list|)
operator|:
name|LLCPath
argument_list|(
name|llcPath
argument_list|)
block|,
name|gcc
argument_list|(
name|Gcc
argument_list|)
block|,
name|UseIntegratedAssembler
argument_list|(
argument|useIntegratedAssembler
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
name|LLC
argument_list|()
block|{
name|delete
name|gcc
block|; }
comment|/// compileProgram - Compile the specified program from bitcode to executable
comment|/// code.  This does not produce any output, it is only used when debugging
comment|/// the code generator.  Returns false if the code generator fails.
name|virtual
name|void
name|compileProgram
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|std::string *Error
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
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
argument|std::string *Error
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
comment|/// OutputCode - Compile the specified program from bitcode to code
comment|/// understood by the GCC driver (either C or asm).  If the code generator
comment|/// fails, it sets Error, otherwise, this function returns the type of code
comment|/// emitted.
name|virtual
name|GCC
operator|::
name|FileType
name|OutputCode
argument_list|(
argument|const std::string&Bitcode
argument_list|,
argument|std::string&OutFile
argument_list|,
argument|std::string&Error
argument_list|,
argument|unsigned Timeout =
literal|0
argument_list|,
argument|unsigned MemoryLimit =
literal|0
argument_list|)
block|; }
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

