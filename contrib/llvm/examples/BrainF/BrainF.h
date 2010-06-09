begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BrainF.h - BrainF compiler class ----------------------*- C++ -*-===//
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
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class stores the data for the BrainF compiler so it doesn't have
end_comment

begin_comment
comment|// to pass all of it around.  The main method is parse.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BRAINF_H
end_ifndef

begin_define
define|#
directive|define
name|BRAINF_H
end_define

begin_include
include|#
directive|include
file|"llvm/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/IRBuilder.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This class provides a parser for the BrainF language.
end_comment

begin_comment
comment|/// The class itself is made to store values during
end_comment

begin_comment
comment|/// parsing so they don't have to be passed around
end_comment

begin_comment
comment|/// as much.
end_comment

begin_decl_stmt
name|class
name|BrainF
block|{
name|public
label|:
comment|/// Options for how BrainF should compile
enum|enum
name|CompileFlags
block|{
name|flag_off
init|=
literal|0
block|,
name|flag_arraybounds
init|=
literal|1
block|}
enum|;
comment|/// This is the main method.  It parses BrainF from in1
comment|/// and returns the module with a function
comment|/// void brainf()
comment|/// containing the resulting code.
comment|/// On error, it calls abort.
comment|/// The caller must delete the returned module.
name|Module
modifier|*
name|parse
argument_list|(
name|std
operator|::
name|istream
operator|*
name|in1
argument_list|,
name|int
name|mem
argument_list|,
name|CompileFlags
name|cf
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
decl_stmt|;
name|protected
label|:
comment|/// The different symbols in the BrainF language
enum|enum
name|Symbol
block|{
name|SYM_NONE
block|,
name|SYM_READ
block|,
name|SYM_WRITE
block|,
name|SYM_MOVE
block|,
name|SYM_CHANGE
block|,
name|SYM_LOOP
block|,
name|SYM_ENDLOOP
block|,
name|SYM_EOF
block|}
enum|;
comment|/// Names of the different parts of the language.
comment|/// Tape is used for reading and writing the tape.
comment|/// headreg is used for the position of the head.
comment|/// label is used for the labels for the BasicBlocks.
comment|/// testreg is used for testing the loop exit condition.
specifier|static
specifier|const
name|char
modifier|*
name|tapereg
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|headreg
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|label
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|testreg
decl_stmt|;
comment|/// Put the brainf function preamble and other fixed pieces of code
name|void
name|header
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|/// The main loop for parsing.  It calls itself recursively
comment|/// to handle the depth of nesting of "[]".
name|void
name|readloop
parameter_list|(
name|PHINode
modifier|*
name|phi
parameter_list|,
name|BasicBlock
modifier|*
name|oldbb
parameter_list|,
name|BasicBlock
modifier|*
name|testbb
parameter_list|,
name|LLVMContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// Constants during parsing
name|int
name|memtotal
decl_stmt|;
name|CompileFlags
name|comflag
decl_stmt|;
name|std
operator|::
name|istream
operator|*
name|in
expr_stmt|;
name|Module
modifier|*
name|module
decl_stmt|;
name|Function
modifier|*
name|brainf_func
decl_stmt|;
name|Function
modifier|*
name|getchar_func
decl_stmt|;
name|Function
modifier|*
name|putchar_func
decl_stmt|;
name|Value
modifier|*
name|ptr_arr
decl_stmt|;
name|Value
modifier|*
name|ptr_arrmax
decl_stmt|;
name|BasicBlock
modifier|*
name|endbb
decl_stmt|;
name|BasicBlock
modifier|*
name|aberrorbb
decl_stmt|;
comment|/// Variables
name|IRBuilder
operator|<
operator|>
operator|*
name|builder
expr_stmt|;
name|Value
modifier|*
name|curhead
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

