begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessorTrace.h -------------------------------------- -*- C++ -*-===//
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
name|liblldb_ProcessorTrace_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessorTrace_H_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/TraceOptions.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|<linux/perf_event.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
comment|// ---------------------------------------------------------------------
comment|// This class keeps track of one tracing instance of
comment|// Intel(R) Processor Trace on Linux OS. There is a map keeping track
comment|// of different tracing instances on each thread, which enables trace
comment|// gathering on a per thread level.
comment|//
comment|// The tracing instance is linked with a trace id. The trace id acts like
comment|// a key to the tracing instance and trace manipulations could be
comment|// performed using the trace id.
comment|//
comment|// The traace id could map to trace instances for a group of threads
comment|// (spanning to all the threads in the process) or a single thread.
comment|// The kernel interface for us is the perf_event_open.
comment|// ---------------------------------------------------------------------
name|class
name|ProcessorTraceMonitor
decl_stmt|;
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|ProcessorTraceMonitor
operator|>
name|ProcessorTraceMonitorUP
expr_stmt|;
name|class
name|ProcessorTraceMonitor
block|{
name|class
name|munmap_delete
block|{
name|size_t
name|m_length
decl_stmt|;
name|public
label|:
name|munmap_delete
argument_list|(
argument|size_t length
argument_list|)
block|:
name|m_length
argument_list|(
argument|length
argument_list|)
block|{}
name|void
name|operator
argument_list|()
operator|(
name|void
operator|*
name|ptr
operator|)
block|{
if|if
condition|(
name|m_length
condition|)
name|munmap
argument_list|(
name|ptr
argument_list|,
name|m_length
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
name|class
name|file_close
block|{
name|public
label|:
name|file_close
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|operator
argument_list|()
operator|(
name|int
operator|*
name|ptr
operator|)
block|{
if|if
condition|(
name|ptr
operator|==
name|nullptr
condition|)
return|return;
if|if
condition|(
operator|*
name|ptr
operator|==
operator|-
literal|1
condition|)
return|return;
name|close
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
name|std
operator|::
name|default_delete
operator|<
name|int
operator|>
operator|(
operator|)
operator|(
name|ptr
operator|)
expr_stmt|;
block|}
block|}
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|perf_event_mmap_page
operator|,
name|munmap_delete
operator|>
name|m_mmap_meta
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|uint8_t
operator|,
name|munmap_delete
operator|>
name|m_mmap_aux
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|int
operator|,
name|file_close
operator|>
name|m_fd
expr_stmt|;
comment|// perf_event_mmap_page *m_mmap_base;
name|lldb
operator|::
name|user_id_t
name|m_traceid
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|m_thread_id
expr_stmt|;
comment|// Counter to track trace instances.
specifier|static
name|lldb
operator|::
name|user_id_t
name|m_trace_num
expr_stmt|;
name|void
name|SetTraceID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|traceid
argument_list|)
block|{
name|m_traceid
operator|=
name|traceid
expr_stmt|;
block|}
name|Status
name|StartTrace
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
specifier|const
name|TraceOptions
operator|&
name|config
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|GetAuxBuffer
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|GetDataBuffer
argument_list|()
expr_stmt|;
name|ProcessorTraceMonitor
argument_list|()
operator|:
name|m_mmap_meta
argument_list|(
name|nullptr
argument_list|,
name|munmap_delete
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|,
name|m_mmap_aux
argument_list|(
name|nullptr
argument_list|,
name|munmap_delete
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|,
name|m_fd
argument_list|(
name|nullptr
argument_list|,
name|file_close
argument_list|()
argument_list|)
operator|,
name|m_traceid
argument_list|(
name|LLDB_INVALID_UID
argument_list|)
operator|,
name|m_thread_id
argument_list|(
argument|LLDB_INVALID_THREAD_ID
argument_list|)
block|{}
expr_stmt|;
name|void
name|SetThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
block|{
name|m_thread_id
operator|=
name|tid
expr_stmt|;
block|}
name|public
label|:
specifier|static
name|Status
name|GetCPUType
parameter_list|(
name|TraceOptions
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|static
name|llvm
operator|::
name|Expected
operator|<
name|ProcessorTraceMonitorUP
operator|>
name|Create
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|const TraceOptions&config
argument_list|,
argument|bool useProcessSettings
argument_list|)
expr_stmt|;
name|Status
name|ReadPerfTraceAux
argument_list|(
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|buffer
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|)
decl_stmt|;
name|Status
name|ReadPerfTraceData
argument_list|(
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|buffer
argument_list|,
name|size_t
name|offset
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|ProcessorTraceMonitor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
specifier|const
block|{
return|return
name|m_thread_id
return|;
block|}
name|lldb
operator|::
name|user_id_t
name|GetTraceID
argument_list|()
specifier|const
block|{
return|return
name|m_traceid
return|;
block|}
name|Status
name|GetTraceConfig
argument_list|(
name|TraceOptions
operator|&
name|config
argument_list|)
decl|const
decl_stmt|;
comment|// ---------------------------------------------------------------------
comment|/// Read data from a cyclic buffer
comment|///
comment|/// @param[in] [out] buf
comment|///     Destination buffer, the buffer will be truncated to written size.
comment|///
comment|/// @param[in] src
comment|///     Source buffer which must be a cyclic buffer.
comment|///
comment|/// @param[in] src_cyc_index
comment|///     The index pointer (start of the valid data in the cyclic
comment|///     buffer).
comment|///
comment|/// @param[in] offset
comment|///     The offset to begin reading the data in the cyclic buffer.
comment|// ---------------------------------------------------------------------
specifier|static
name|void
name|ReadCyclicBuffer
argument_list|(
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
operator|&
name|dst
argument_list|,
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|uint8_t
operator|>
name|src
argument_list|,
name|size_t
name|src_cyc_index
argument_list|,
name|size_t
name|offset
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_linux
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

