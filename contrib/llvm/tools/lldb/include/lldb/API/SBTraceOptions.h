begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBTraceOptions ------------------------------------------*- C++ -*-===//
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
name|SBTRACEOPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|SBTRACEOPTIONS_H_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBTraceOptions
block|{
name|public
label|:
name|SBTraceOptions
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|TraceType
name|getType
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getTraceBufferSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// The trace parameters consist of any custom parameters
comment|/// apart from the generic parameters such as
comment|/// TraceType, trace_buffer_size and meta_data_buffer_size.
comment|/// The returned parameters would be formatted as a JSON Dictionary.
name|lldb
operator|::
name|SBStructuredData
name|getTraceParams
argument_list|(
name|lldb
operator|::
name|SBError
operator|&
name|error
argument_list|)
expr_stmt|;
name|uint64_t
name|getMetaDataBufferSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// SBStructuredData is meant to hold any custom parameters
comment|/// apart from meta buffer size and trace size. They should
comment|/// be formatted as a JSON Dictionary.
name|void
name|setTraceParams
argument_list|(
name|lldb
operator|::
name|SBStructuredData
operator|&
name|params
argument_list|)
decl_stmt|;
name|void
name|setType
argument_list|(
name|lldb
operator|::
name|TraceType
name|type
argument_list|)
decl_stmt|;
name|void
name|setTraceBufferSize
parameter_list|(
name|uint64_t
name|size
parameter_list|)
function_decl|;
name|void
name|setMetaDataBufferSize
parameter_list|(
name|uint64_t
name|size
parameter_list|)
function_decl|;
name|void
name|setThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|tid_t
name|getThreadID
argument_list|()
expr_stmt|;
name|bool
name|IsValid
parameter_list|()
function_decl|;
name|protected
label|:
name|friend
name|class
name|SBProcess
decl_stmt|;
name|friend
name|class
name|SBTrace
decl_stmt|;
name|lldb
operator|::
name|TraceOptionsSP
name|m_traceoptions_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SBTRACEOPTIONS_H_ */
end_comment

end_unit

