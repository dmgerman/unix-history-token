begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DarwinLogCollector.h ------------------------------------*- C++ -*-===//
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
name|DarwinLogCollector_h
end_ifndef

begin_define
define|#
directive|define
name|DarwinLogCollector_h
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|"ActivityStore.h"
end_include

begin_include
include|#
directive|include
file|"ActivityStreamSPI.h"
end_include

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"DarwinLogEvent.h"
end_include

begin_include
include|#
directive|include
file|"DarwinLogInterfaces.h"
end_include

begin_include
include|#
directive|include
file|"JSON.h"
end_include

begin_decl_stmt
name|class
name|DarwinLogCollector
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|DarwinLogCollector
operator|>
name|DarwinLogCollectorSP
expr_stmt|;
end_typedef

begin_decl_stmt
name|class
name|DarwinLogCollector
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|DarwinLogCollector
operator|>
decl_stmt|,
name|public
name|ActivityStore
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Return whether the os_log and activity tracing SPI is available.
comment|///
comment|/// @return \b true if the activity stream support is available,
comment|/// \b false otherwise.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|IsSupported
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return a log function suitable for DNBLog to use as the internal
comment|/// logging function.
comment|///
comment|/// @return a DNBLog-style logging function if IsSupported() returns
comment|///      true; otherwise, returns nullptr.
comment|//------------------------------------------------------------------
specifier|static
name|DNBCallbackLog
name|GetLogFunction
parameter_list|()
function_decl|;
specifier|static
name|bool
name|StartCollectingForProcess
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
specifier|const
name|JSONObject
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|static
name|bool
name|CancelStreamForProcess
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
specifier|static
name|DarwinLogEventVector
name|GetEventsForProcess
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
operator|~
name|DarwinLogCollector
argument_list|()
expr_stmt|;
name|pid_t
name|GetProcessID
argument_list|()
specifier|const
block|{
return|return
name|m_pid
return|;
block|}
comment|//------------------------------------------------------------------
comment|// ActivityStore API
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetActivityForID
argument_list|(
name|os_activity_id_t
name|activity_id
argument_list|)
decl|const
name|override
decl_stmt|;
name|std
operator|::
name|string
name|GetActivityChainForID
argument_list|(
argument|os_activity_id_t activity_id
argument_list|)
specifier|const
name|override
expr_stmt|;
name|private
label|:
name|DarwinLogCollector
argument_list|()
operator|=
name|delete
expr_stmt|;
name|DarwinLogCollector
argument_list|(
specifier|const
name|DarwinLogCollector
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|DarwinLogCollector
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DarwinLogCollector
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|explicit
name|DarwinLogCollector
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
specifier|const
name|LogFilterChainSP
modifier|&
name|filter_chain_sp
parameter_list|)
function_decl|;
name|void
name|SignalDataAvailable
parameter_list|()
function_decl|;
name|void
name|SetActivityStream
parameter_list|(
name|os_activity_stream_t
name|activity_stream
parameter_list|)
function_decl|;
name|bool
name|HandleStreamEntry
parameter_list|(
name|os_activity_stream_entry_t
name|entry
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
name|DarwinLogEventVector
name|RemoveEvents
parameter_list|()
function_decl|;
name|void
name|CancelActivityStream
parameter_list|()
function_decl|;
name|void
name|GetActivityChainForID_internal
argument_list|(
name|os_activity_id_t
name|activity_id
argument_list|,
name|std
operator|::
name|string
operator|&
name|result
argument_list|,
name|size_t
name|depth
argument_list|)
decl|const
decl_stmt|;
struct|struct
name|ActivityInfo
block|{
name|ActivityInfo
argument_list|(
argument|const char *name
argument_list|,
argument|os_activity_id_t activity_id
argument_list|,
argument|os_activity_id_t parent_activity_id
argument_list|)
block|:
name|m_name
argument_list|(
name|name
argument_list|)
operator|,
name|m_id
argument_list|(
name|activity_id
argument_list|)
operator|,
name|m_parent_id
argument_list|(
argument|parent_activity_id
argument_list|)
block|{}
specifier|const
name|std
operator|::
name|string
name|m_name
expr_stmt|;
specifier|const
name|os_activity_id_t
name|m_id
decl_stmt|;
specifier|const
name|os_activity_id_t
name|m_parent_id
decl_stmt|;
block|}
struct|;
name|using
name|ActivityMap
init|=
name|std
operator|::
name|unordered_map
operator|<
name|os_activity_id_t
decl_stmt|,
name|ActivityInfo
decl|>
decl_stmt|;
specifier|const
name|nub_process_t
name|m_pid
decl_stmt|;
name|os_activity_stream_t
name|m_activity_stream
decl_stmt|;
name|DarwinLogEventVector
name|m_events
decl_stmt|;
name|std
operator|::
name|mutex
name|m_events_mutex
expr_stmt|;
name|LogFilterChainSP
name|m_filter_chain_sp
decl_stmt|;
comment|/// Mutex to protect activity info (activity name and parent structures)
name|mutable
name|std
operator|::
name|mutex
name|m_activity_info_mutex
expr_stmt|;
comment|/// Map of activity id to ActivityInfo
name|ActivityMap
name|m_activity_map
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

begin_comment
comment|/* LogStreamCollector_h */
end_comment

end_unit

