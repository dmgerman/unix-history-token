begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TraceOptions.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_TraceOptions_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TraceOptions_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TraceOptions
block|{
name|public
label|:
name|TraceOptions
argument_list|()
operator|:
name|m_trace_params
argument_list|(
argument|new StructuredData::Dictionary()
argument_list|)
block|{}
specifier|const
name|StructuredData
operator|::
name|DictionarySP
operator|&
name|getTraceParams
argument_list|()
specifier|const
block|{
return|return
name|m_trace_params
return|;
block|}
name|lldb
operator|::
name|TraceType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|uint64_t
name|getTraceBufferSize
argument_list|()
specifier|const
block|{
return|return
name|m_trace_buffer_size
return|;
block|}
name|uint64_t
name|getMetaDataBufferSize
argument_list|()
specifier|const
block|{
return|return
name|m_meta_data_buffer_size
return|;
block|}
name|void
name|setTraceParams
argument_list|(
specifier|const
name|StructuredData
operator|::
name|DictionarySP
operator|&
name|dict_obj
argument_list|)
block|{
name|m_trace_params
operator|=
name|dict_obj
expr_stmt|;
block|}
name|void
name|setType
argument_list|(
name|lldb
operator|::
name|TraceType
name|type
argument_list|)
block|{
name|m_type
operator|=
name|type
expr_stmt|;
block|}
name|void
name|setTraceBufferSize
parameter_list|(
name|uint64_t
name|size
parameter_list|)
block|{
name|m_trace_buffer_size
operator|=
name|size
expr_stmt|;
block|}
name|void
name|setMetaDataBufferSize
parameter_list|(
name|uint64_t
name|size
parameter_list|)
block|{
name|m_meta_data_buffer_size
operator|=
name|size
expr_stmt|;
block|}
name|void
name|setThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
block|{
name|m_thread_id
operator|=
name|thread_id
expr_stmt|;
block|}
name|lldb
operator|::
name|tid_t
name|getThreadID
argument_list|()
block|{
return|return
name|m_thread_id
return|;
block|}
name|private
label|:
name|lldb
operator|::
name|TraceType
name|m_type
expr_stmt|;
name|uint64_t
name|m_trace_buffer_size
decl_stmt|;
name|uint64_t
name|m_meta_data_buffer_size
decl_stmt|;
name|lldb
operator|::
name|tid_t
name|m_thread_id
expr_stmt|;
comment|/// m_trace_params is meant to hold any custom parameters
comment|/// apart from meta buffer size and trace size.
comment|/// The interpretation of such parameters is left to
comment|/// the lldb-server.
name|StructuredData
operator|::
name|DictionarySP
name|m_trace_params
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
comment|// liblldb_TraceOptions_h_
end_comment

end_unit

