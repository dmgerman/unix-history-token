begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadPlanTracer.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadPlanTracer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadPlanTracer_h_
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
file|"lldb/Core/RegisterValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TaggedASTType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadPlanTracer
block|{
name|friend
name|class
name|ThreadPlan
decl_stmt|;
name|public
label|:
typedef|typedef
enum|enum
name|ThreadPlanTracerStyle
block|{
name|eLocation
init|=
literal|0
block|,
name|eStateChange
block|,
name|eCheckFrames
block|,
name|ePython
block|}
name|ThreadPlanTracerStyle
typedef|;
name|ThreadPlanTracer
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
expr_stmt|;
name|ThreadPlanTracer
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|ThreadPlanTracer
argument_list|()
block|{     }
name|virtual
name|void
name|TracingStarted
argument_list|()
block|{          }
name|virtual
name|void
name|TracingEnded
argument_list|()
block|{          }
name|bool
name|EnableTracing
argument_list|(
argument|bool value
argument_list|)
block|{
name|bool
name|old_value
operator|=
name|m_enabled
block|;
name|m_enabled
operator|=
name|value
block|;
if|if
condition|(
name|old_value
operator|==
name|false
operator|&&
name|value
operator|==
name|true
condition|)
name|TracingStarted
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|old_value
operator|==
name|true
operator|&&
name|value
operator|==
name|false
condition|)
name|TracingEnded
argument_list|()
expr_stmt|;
return|return
name|old_value
return|;
block|}
name|bool
name|TracingEnabled
parameter_list|()
block|{
return|return
name|m_enabled
return|;
block|}
name|bool
name|EnableSingleStep
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|bool
name|old_value
init|=
name|m_single_step
decl_stmt|;
name|m_single_step
operator|=
name|value
expr_stmt|;
return|return
name|old_value
return|;
block|}
name|bool
name|SingleStepEnabled
parameter_list|()
block|{
return|return
name|m_single_step
return|;
block|}
name|protected
label|:
name|Thread
modifier|&
name|m_thread
decl_stmt|;
name|Stream
modifier|*
name|GetLogStream
parameter_list|()
function_decl|;
name|virtual
name|void
name|Log
parameter_list|()
function_decl|;
name|private
label|:
name|bool
name|TracerExplainsStop
parameter_list|()
function_decl|;
name|bool
name|m_single_step
decl_stmt|;
name|bool
name|m_enabled
decl_stmt|;
name|lldb
operator|::
name|StreamSP
name|m_stream_sp
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ThreadPlanAssemblyTracer
range|:
name|public
name|ThreadPlanTracer
block|{
name|public
operator|:
name|ThreadPlanAssemblyTracer
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|StreamSP
operator|&
name|stream_sp
argument_list|)
block|;
name|ThreadPlanAssemblyTracer
argument_list|(
name|Thread
operator|&
name|thread
argument_list|)
block|;
name|virtual
operator|~
name|ThreadPlanAssemblyTracer
argument_list|()
block|;
name|virtual
name|void
name|TracingStarted
argument_list|()
block|;
name|virtual
name|void
name|TracingEnded
argument_list|()
block|;
name|virtual
name|void
name|Log
argument_list|()
block|;
name|private
operator|:
name|Disassembler
operator|*
name|GetDisassembler
argument_list|()
block|;
name|TypeFromUser
name|GetIntPointerType
argument_list|()
block|;
name|lldb
operator|::
name|DisassemblerSP
name|m_disassembler_sp
block|;
name|TypeFromUser
name|m_intptr_type
block|;
name|std
operator|::
name|vector
operator|<
name|RegisterValue
operator|>
name|m_register_values
block|;
name|lldb
operator|::
name|DataBufferSP
name|m_buffer_sp
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ThreadPlanTracer_h_
end_comment

end_unit

