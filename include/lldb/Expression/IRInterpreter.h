begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRInterpreter.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_IRInterpreter_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IRInterpreter_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangExpressionDeclMap
decl_stmt|;
name|class
name|IRMemoryMap
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class IRInterpreter IRInterpreter.h "lldb/Expression/IRInterpreter.h"
end_comment

begin_comment
comment|/// @brief Attempt to interpret the function's code if it does not require
end_comment

begin_comment
comment|///        running the target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In some cases, the IR for an expression can be evaluated entirely
end_comment

begin_comment
comment|/// in the debugger, manipulating variables but not executing any code
end_comment

begin_comment
comment|/// in the target.  The IRInterpreter attempts to do this.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|IRInterpreter
block|{
name|public
label|:
specifier|static
name|bool
name|CanInterpret
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|module
argument_list|,
name|llvm
operator|::
name|Function
operator|&
name|function
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|,
specifier|const
name|bool
name|support_function_calls
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|Interpret
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|module
argument_list|,
name|llvm
operator|::
name|Function
operator|&
name|function
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|args
argument_list|,
name|lldb_private
operator|::
name|IRExecutionUnit
operator|&
name|execution_unit
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|,
name|lldb
operator|::
name|addr_t
name|stack_frame_bottom
argument_list|,
name|lldb
operator|::
name|addr_t
name|stack_frame_top
argument_list|,
name|lldb_private
operator|::
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|bool
name|supportsFunction
argument_list|(
name|llvm
operator|::
name|Function
operator|&
name|llvm_function
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|err
argument_list|)
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

