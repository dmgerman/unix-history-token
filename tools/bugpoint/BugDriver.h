begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BugDriver.h - Top-Level BugPoint class -------------------*- C++ -*-===//
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
comment|// This class contains all of the shared state and information that is used by
end_comment

begin_comment
comment|// the BugPoint tool to track down errors in optimizations.  This class is the
end_comment

begin_comment
comment|// main driver class that invokes all sub-functionality.
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
name|BUGDRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|BUGDRIVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|Value
decl_stmt|;
name|class
name|PassInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|AbstractInterpreter
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DebugCrashes
decl_stmt|;
name|class
name|GCC
decl_stmt|;
specifier|extern
name|bool
name|DisableSimplifyCFG
decl_stmt|;
comment|/// BugpointIsInterrupted - Set to true when the user presses ctrl-c.
comment|///
specifier|extern
name|bool
name|BugpointIsInterrupted
decl_stmt|;
name|class
name|BugDriver
block|{
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
specifier|const
name|char
modifier|*
name|ToolName
decl_stmt|;
comment|// argv[0] of bugpoint
name|std
operator|::
name|string
name|ReferenceOutputFile
expr_stmt|;
comment|// Name of `good' output file
name|Module
modifier|*
name|Program
decl_stmt|;
comment|// The raw program, linked together
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
name|PassesToRun
expr_stmt|;
name|AbstractInterpreter
modifier|*
name|Interpreter
decl_stmt|;
comment|// How to run the program
name|AbstractInterpreter
modifier|*
name|SafeInterpreter
decl_stmt|;
comment|// To generate reference output, etc.
name|GCC
modifier|*
name|gcc
decl_stmt|;
name|bool
name|run_as_child
decl_stmt|;
name|bool
name|run_find_bugs
decl_stmt|;
name|unsigned
name|Timeout
decl_stmt|;
name|unsigned
name|MemoryLimit
decl_stmt|;
comment|// FIXME: sort out public/private distinctions...
name|friend
name|class
name|ReducePassList
decl_stmt|;
name|friend
name|class
name|ReduceMisCodegenFunctions
decl_stmt|;
name|public
label|:
name|BugDriver
argument_list|(
argument|const char *toolname
argument_list|,
argument|bool as_child
argument_list|,
argument|bool find_bugs
argument_list|,
argument|unsigned timeout
argument_list|,
argument|unsigned memlimit
argument_list|,
argument|LLVMContext& ctxt
argument_list|)
empty_stmt|;
specifier|const
name|char
operator|*
name|getToolName
argument_list|()
specifier|const
block|{
return|return
name|ToolName
return|;
block|}
name|LLVMContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
comment|// Set up methods... these methods are used to copy information about the
comment|// command line arguments into instance variables of BugDriver.
comment|//
name|bool
name|addSources
argument_list|(
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
name|FileNames
argument_list|)
decl_stmt|;
name|template
operator|<
name|class
name|It
operator|>
name|void
name|addPasses
argument_list|(
argument|It I
argument_list|,
argument|It E
argument_list|)
block|{
name|PassesToRun
operator|.
name|insert
argument_list|(
name|PassesToRun
operator|.
name|end
argument_list|()
argument_list|,
name|I
argument_list|,
name|E
argument_list|)
block|; }
name|void
name|setPassesToRun
argument_list|(
argument|const std::vector<const PassInfo*>&PTR
argument_list|)
block|{
name|PassesToRun
operator|=
name|PTR
block|;   }
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|getPassesToRun
argument_list|()
specifier|const
block|{
return|return
name|PassesToRun
return|;
block|}
comment|/// run - The top level method that is invoked after all of the instance
comment|/// variables are set up from command line arguments. The \p as_child argument
comment|/// indicates whether the driver is to run in parent mode or child mode.
comment|///
name|bool
name|run
parameter_list|()
function_decl|;
comment|/// debugOptimizerCrash - This method is called when some optimizer pass
comment|/// crashes on input.  It attempts to prune down the testcase to something
comment|/// reasonable, and figure out exactly which pass is crashing.
comment|///
name|bool
name|debugOptimizerCrash
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ID
operator|=
literal|"passes"
argument_list|)
decl_stmt|;
comment|/// debugCodeGeneratorCrash - This method is called when the code generator
comment|/// crashes on an input.  It attempts to reduce the input as much as possible
comment|/// while still causing the code generator to crash.
name|bool
name|debugCodeGeneratorCrash
parameter_list|()
function_decl|;
comment|/// debugMiscompilation - This method is used when the passes selected are not
comment|/// crashing, but the generated output is semantically different from the
comment|/// input.
name|bool
name|debugMiscompilation
parameter_list|()
function_decl|;
comment|/// debugPassMiscompilation - This method is called when the specified pass
comment|/// miscompiles Program as input.  It tries to reduce the testcase to
comment|/// something that smaller that still miscompiles the program.
comment|/// ReferenceOutput contains the filename of the file containing the output we
comment|/// are to match.
comment|///
name|bool
name|debugPassMiscompilation
argument_list|(
specifier|const
name|PassInfo
operator|*
name|ThePass
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ReferenceOutput
argument_list|)
decl_stmt|;
comment|/// compileSharedObject - This method creates a SharedObject from a given
comment|/// BitcodeFile for debugging a code generator.
comment|///
name|std
operator|::
name|string
name|compileSharedObject
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|BitcodeFile
argument_list|)
expr_stmt|;
comment|/// debugCodeGenerator - This method narrows down a module to a function or
comment|/// set of functions, using the CBE as a ``safe'' code generator for other
comment|/// functions that are not under consideration.
name|bool
name|debugCodeGenerator
parameter_list|()
function_decl|;
comment|/// isExecutingJIT - Returns true if bugpoint is currently testing the JIT
comment|///
name|bool
name|isExecutingJIT
parameter_list|()
function_decl|;
comment|/// runPasses - Run all of the passes in the "PassesToRun" list, discard the
comment|/// output, and return true if any of the passes crashed.
name|bool
name|runPasses
parameter_list|(
name|Module
modifier|*
name|M
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|M
operator|==
literal|0
condition|)
name|M
operator|=
name|Program
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|M
argument_list|,
name|Program
argument_list|)
expr_stmt|;
name|bool
name|Result
init|=
name|runPasses
argument_list|(
name|PassesToRun
argument_list|)
decl_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|M
argument_list|,
name|Program
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
name|Module
operator|*
name|getProgram
argument_list|()
specifier|const
block|{
return|return
name|Program
return|;
block|}
comment|/// swapProgramIn - Set the current module to the specified module, returning
comment|/// the old one.
name|Module
modifier|*
name|swapProgramIn
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
block|{
name|Module
modifier|*
name|OldProgram
init|=
name|Program
decl_stmt|;
name|Program
operator|=
name|M
expr_stmt|;
return|return
name|OldProgram
return|;
block|}
name|AbstractInterpreter
modifier|*
name|switchToSafeInterpreter
parameter_list|()
block|{
name|AbstractInterpreter
modifier|*
name|Old
init|=
name|Interpreter
decl_stmt|;
name|Interpreter
operator|=
operator|(
name|AbstractInterpreter
operator|*
operator|)
name|SafeInterpreter
expr_stmt|;
return|return
name|Old
return|;
block|}
name|void
name|switchToInterpreter
parameter_list|(
name|AbstractInterpreter
modifier|*
name|AI
parameter_list|)
block|{
name|Interpreter
operator|=
name|AI
expr_stmt|;
block|}
comment|/// setNewProgram - If we reduce or update the program somehow, call this
comment|/// method to update bugdriver with it.  This deletes the old module and sets
comment|/// the specified one as the current program.
name|void
name|setNewProgram
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// compileProgram - Try to compile the specified module, throwing an
comment|/// exception if an error occurs, or returning normally if not.  This is used
comment|/// for code generation crash testing.
comment|///
name|void
name|compileProgram
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// executeProgram - This method runs "Program", capturing the output of the
comment|/// program to a file, returning the filename of the file.  A recommended
comment|/// filename may be optionally specified.  If there is a problem with the code
comment|/// generator (e.g., llc crashes), this will throw an exception.
comment|///
name|std
operator|::
name|string
name|executeProgram
argument_list|(
argument|std::string RequestedOutputFilename =
literal|""
argument_list|,
argument|std::string Bitcode =
literal|""
argument_list|,
argument|const std::string&SharedObjects =
literal|""
argument_list|,
argument|AbstractInterpreter *AI =
literal|0
argument_list|,
argument|bool *ProgramExitedNonzero =
literal|0
argument_list|)
expr_stmt|;
comment|/// executeProgramSafely - Used to create reference output with the "safe"
comment|/// backend, if reference output is not provided.  If there is a problem with
comment|/// the code generator (e.g., llc crashes), this will throw an exception.
comment|///
name|std
operator|::
name|string
name|executeProgramSafely
argument_list|(
argument|std::string OutputFile =
literal|""
argument_list|)
expr_stmt|;
comment|/// createReferenceFile - calls compileProgram and then records the output
comment|/// into ReferenceOutputFile. Returns true if reference file created, false
comment|/// otherwise. Note: initializeExecutionEnvironment should be called BEFORE
comment|/// this function.
comment|///
name|bool
name|createReferenceFile
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
operator|=
literal|"bugpoint.reference.out"
argument_list|)
decl_stmt|;
comment|/// diffProgram - This method executes the specified module and diffs the
comment|/// output against the file specified by ReferenceOutputFile.  If the output
comment|/// is different, true is returned.  If there is a problem with the code
comment|/// generator (e.g., llc crashes), this will throw an exception.
comment|///
name|bool
name|diffProgram
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|BitcodeFile
operator|=
literal|""
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|SharedObj
operator|=
literal|""
argument_list|,
name|bool
name|RemoveBitcode
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// EmitProgressBitcode - This function is used to output the current Program
comment|/// to a file named "bugpoint-ID.bc".
comment|///
name|void
name|EmitProgressBitcode
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ID
argument_list|,
name|bool
name|NoFlyer
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// deleteInstructionFromProgram - This method clones the current Program and
comment|/// deletes the specified instruction from the cloned module.  It then runs a
comment|/// series of cleanup passes (ADCE and SimplifyCFG) to eliminate any code
comment|/// which depends on the value.  The modified module is then returned.
comment|///
name|Module
modifier|*
name|deleteInstructionFromProgram
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|,
name|unsigned
name|Simp
argument_list|)
decl|const
decl_stmt|;
comment|/// performFinalCleanups - This method clones the current Program and performs
comment|/// a series of cleanups intended to get rid of extra cruft on the module.  If
comment|/// the MayModifySemantics argument is true, then the cleanups is allowed to
comment|/// modify how the code behaves.
comment|///
name|Module
modifier|*
name|performFinalCleanups
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|bool
name|MayModifySemantics
init|=
name|false
parameter_list|)
function_decl|;
comment|/// ExtractLoop - Given a module, extract up to one loop from it into a new
comment|/// function.  This returns null if there are no extractable loops in the
comment|/// program or if the loop extractor crashes.
name|Module
modifier|*
name|ExtractLoop
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// ExtractMappedBlocksFromModule - Extract all but the specified basic blocks
comment|/// into their own functions.  The only detail is that M is actually a module
comment|/// cloned from the one the BBs are in, so some mapping needs to be performed.
comment|/// If this operation fails for some reason (ie the implementation is buggy),
comment|/// this function should return null, otherwise it returns a new Module.
name|Module
modifier|*
name|ExtractMappedBlocksFromModule
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|BBs
argument_list|,
name|Module
operator|*
name|M
argument_list|)
decl_stmt|;
comment|/// runPassesOn - Carefully run the specified set of pass on the specified
comment|/// module, returning the transformed module on success, or a null pointer on
comment|/// failure.  If AutoDebugCrashes is set to true, then bugpoint will
comment|/// automatically attempt to track down a crashing pass if one exists, and
comment|/// this method will never return null.
name|Module
modifier|*
name|runPassesOn
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|Passes
argument_list|,
name|bool
name|AutoDebugCrashes
operator|=
name|false
argument_list|,
name|unsigned
name|NumExtraArgs
operator|=
literal|0
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ExtraArgs
operator|=
name|NULL
argument_list|)
decl_stmt|;
comment|/// runPasses - Run the specified passes on Program, outputting a bitcode
comment|/// file and writting the filename into OutputFile if successful.  If the
comment|/// optimizations fail for some reason (optimizer crashes), return true,
comment|/// otherwise return false.  If DeleteOutput is set to true, the bitcode is
comment|/// deleted on success, and the filename string is undefined.  This prints to
comment|/// outs() a single line message indicating whether compilation was successful
comment|/// or failed, unless Quiet is set.  ExtraArgs specifies additional arguments
comment|/// to pass to the child bugpoint instance.
comment|///
name|bool
name|runPasses
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|PassesToRun
argument_list|,
name|std
operator|::
name|string
operator|&
name|OutputFilename
argument_list|,
name|bool
name|DeleteOutput
operator|=
name|false
argument_list|,
name|bool
name|Quiet
operator|=
name|false
argument_list|,
name|unsigned
name|NumExtraArgs
operator|=
literal|0
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ExtraArgs
operator|=
name|NULL
argument_list|)
decl|const
decl_stmt|;
comment|/// runManyPasses - Take the specified pass list and create different
comment|/// combinations of passes to compile the program with. Compile the program with
comment|/// each set and mark test to see if it compiled correctly. If the passes
comment|/// compiled correctly output nothing and rearrange the passes into a new order.
comment|/// If the passes did not compile correctly, output the command required to
comment|/// recreate the failure. This returns true if a compiler error is found.
comment|///
name|bool
name|runManyPasses
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|AllPasses
argument_list|)
decl_stmt|;
comment|/// writeProgramToFile - This writes the current "Program" to the named
comment|/// bitcode file.  If an error occurs, true is returned.
comment|///
name|bool
name|writeProgramToFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|Module
operator|*
name|M
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// runPasses - Just like the method above, but this just returns true or
comment|/// false indicating whether or not the optimizer crashed on the specified
comment|/// input (true = crashed).
comment|///
name|bool
name|runPasses
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|PassesToRun
argument_list|,
name|bool
name|DeleteOutput
operator|=
name|true
argument_list|)
decl|const
block|{
name|std
operator|::
name|string
name|Filename
expr_stmt|;
return|return
name|runPasses
argument_list|(
name|PassesToRun
argument_list|,
name|Filename
argument_list|,
name|DeleteOutput
argument_list|)
return|;
block|}
comment|/// runAsChild - The actual "runPasses" guts that runs in a child process.
name|int
name|runPassesAsChild
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|PassesToRun
argument_list|)
decl_stmt|;
comment|/// initializeExecutionEnvironment - This method is used to set up the
comment|/// environment for executing LLVM programs.
comment|///
name|bool
name|initializeExecutionEnvironment
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// ParseInputFile - Given a bitcode or assembly input filename, parse and
comment|/// return it, or return null if not possible.
comment|///
name|Module
modifier|*
name|ParseInputFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|InputFilename
argument_list|,
name|LLVMContext
operator|&
name|ctxt
argument_list|)
decl_stmt|;
comment|/// getPassesString - Turn a list of passes into a string which indicates the
comment|/// command line options that must be passed to add the passes.
comment|///
name|std
operator|::
name|string
name|getPassesString
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|&
name|Passes
argument_list|)
expr_stmt|;
comment|/// PrintFunctionList - prints out list of problematic functions
comment|///
name|void
name|PrintFunctionList
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Function
operator|*
operator|>
operator|&
name|Funcs
argument_list|)
decl_stmt|;
comment|/// PrintGlobalVariableList - prints out list of problematic global variables
comment|///
name|void
name|PrintGlobalVariableList
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|GlobalVariable
operator|*
operator|>
operator|&
name|GVs
argument_list|)
decl_stmt|;
comment|// DeleteFunctionBody - "Remove" the function by deleting all of it's basic
comment|// blocks, making it external.
comment|//
name|void
name|DeleteFunctionBody
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// SplitFunctionsOutOfModule - Given a module and a list of functions in the
comment|/// module, split the functions OUT of the specified module, and place them in
comment|/// the new module.
name|Module
modifier|*
name|SplitFunctionsOutOfModule
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Function
operator|*
operator|>
operator|&
name|F
argument_list|,
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
argument_list|,
name|Value
operator|*
operator|>
operator|&
name|ValueMap
argument_list|)
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

