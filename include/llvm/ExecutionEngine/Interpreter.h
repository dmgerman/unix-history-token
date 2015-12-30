begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Interpreter.h - Abstract Execution Engine Interface -----*- C++ -*-===//
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
comment|// This file forces the interpreter to link in on certain operating systems.
end_comment

begin_comment
comment|// (Windows).
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
name|LLVM_EXECUTIONENGINE_INTERPRETER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_INTERPRETER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_extern
extern|extern
literal|"C"
name|void
name|LLVMLinkInInterpreter
parameter_list|()
function_decl|;
end_extern

begin_macro
name|namespace
end_macro

begin_block
block|{
struct|struct
name|ForceInterpreterLinking
block|{
name|ForceInterpreterLinking
argument_list|()
block|{
name|LLVMLinkInInterpreter
argument_list|()
expr_stmt|;
block|}
block|}
name|ForceInterpreterLinking
struct|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

