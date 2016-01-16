begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanCallFunctionUsingABI.h --------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanCallFunctionUsingABI_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanCallFunctionUsingABI_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ABI.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadPlanCallFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanCallFunctionUsingABI
range|:
name|public
name|ThreadPlanCallFunction
block|{
comment|// Create a thread plan to call a function at the address passed in the "function"
comment|// argument, this function is executed using register manipulation instead of JIT.
comment|// Class derives from ThreadPlanCallFunction and differs by calling a alternative
comment|// ABI interface ABI::PrepareTrivialCall() which provides more detailed information.
name|public
operator|:
name|ThreadPlanCallFunctionUsingABI
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
specifier|const
name|Address
operator|&
name|function_address
argument_list|,
name|llvm
operator|::
name|Type
operator|&
name|function_prototype
argument_list|,
name|llvm
operator|::
name|Type
operator|&
name|return_type
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|ABI
operator|::
name|CallArgument
operator|>
name|args
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|)
block|;
operator|~
name|ThreadPlanCallFunctionUsingABI
argument_list|()
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|SetReturnValue
argument_list|()
name|override
block|;
name|private
operator|:
name|llvm
operator|::
name|Type
operator|&
name|m_return_type
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ThreadPlanCallFunctionUsingABI
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadPlanCallFunctionUsingABI_h_
end_comment

end_unit

