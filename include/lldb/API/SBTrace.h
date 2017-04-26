begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBTrace.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBTrace_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBTrace_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
end_include

begin_decl_stmt
name|class
name|TraceImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBTrace
block|{
name|public
label|:
name|SBTrace
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Obtain the trace data as raw bytes.
comment|///
comment|/// @param[out] error
comment|///     An error explaining what went wrong.
comment|///
comment|/// @param[in] buf
comment|///     Buffer to write the trace data to.
comment|///
comment|/// @param[in] size
comment|///     The size of the buffer used to read the data. This is
comment|///     also the size of the data intended to read. It is also
comment|///     possible to partially read the trace data for some trace
comment|///     technologies by specifying a smaller buffer.
comment|///
comment|/// @param[in] offset
comment|///     The start offset to begin reading the trace data.
comment|///
comment|/// @param[in] thread_id
comment|///     Tracing could be started for the complete process or a
comment|///     single thread, in the first case the uid obtained would
comment|///     map to all the threads existing within the process and the
comment|///     ones spawning later. The thread_id parameter can be used in
comment|///     such a scenario to select the trace data for a specific
comment|///     thread.
comment|///
comment|/// @return
comment|///     The size of the trace data effectively read by the API call.
comment|//------------------------------------------------------------------
name|size_t
name|GetTraceData
argument_list|(
name|SBError
operator|&
name|error
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
operator|=
name|LLDB_INVALID_THREAD_ID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Obtain any meta data as raw bytes for the tracing instance.
comment|/// The input parameter definition is similar to the previous
comment|/// function.
comment|//------------------------------------------------------------------
name|size_t
name|GetMetaData
argument_list|(
name|SBError
operator|&
name|error
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
operator|=
name|LLDB_INVALID_THREAD_ID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Stop the tracing instance. Stopping the trace will also
comment|/// lead to deletion of any gathered trace data.
comment|///
comment|/// @param[out] error
comment|///     An error explaining what went wrong.
comment|///
comment|/// @param[in] thread_id
comment|///     The user id could map to a tracing instance for a thread
comment|///     or could also map to a group of threads being traced with
comment|///     the same trace options. A thread_id is normally optional
comment|///     except in the case of tracing a complete process and tracing
comment|///     needs to switched off on a particular thread.
comment|///     A situation could occur where initially a thread (lets say
comment|///     thread A) is being individually traced with a particular uid
comment|///     and then tracing is started on the complete process, in this
comment|///     case thread A will continue without any change. All newly
comment|///     spawned threads would be traced with the uid of the process.
comment|///     Now if the StopTrace API is called for the whole process,
comment|///     thread A will not be stopped and must be stopped separately.
comment|//------------------------------------------------------------------
name|void
name|StopTrace
argument_list|(
name|SBError
operator|&
name|error
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
operator|=
name|LLDB_INVALID_THREAD_ID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the trace configuration being used for the trace instance.
comment|/// The threadid in the SBTraceOptions needs to be set when the
comment|/// configuration used by a specific thread is being requested.
comment|///
comment|/// @param[out] options
comment|///     The trace options actually used by the trace instance
comment|///     would be filled by the API.
comment|///
comment|/// @param[out] error
comment|///     An error explaining what went wrong.
comment|//------------------------------------------------------------------
name|void
name|GetTraceConfig
parameter_list|(
name|SBTraceOptions
modifier|&
name|options
parameter_list|,
name|SBError
modifier|&
name|error
parameter_list|)
function_decl|;
name|lldb
operator|::
name|user_id_t
name|GetTraceUID
argument_list|()
expr_stmt|;
name|bool
name|IsValid
parameter_list|()
function_decl|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|TraceImpl
operator|>
name|TraceImplSP
expr_stmt|;
name|friend
name|class
name|SBProcess
decl_stmt|;
name|void
name|SetTraceUID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
decl_stmt|;
name|TraceImplSP
name|m_trace_impl_sp
decl_stmt|;
name|lldb
operator|::
name|ProcessSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetSP
parameter_list|(
specifier|const
name|ProcessSP
modifier|&
name|process_sp
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ProcessWP
name|m_opaque_wp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBTrace_h_
end_comment

end_unit

