begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Event.h -------------------------------------------------*- C++ -*-===//
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
name|liblldb_Event_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Event_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

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
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// lldb::EventData
comment|//----------------------------------------------------------------------
name|class
name|EventData
block|{
name|friend
name|class
name|Event
decl_stmt|;
name|public
label|:
name|EventData
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|EventData
argument_list|()
expr_stmt|;
name|virtual
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|virtual
name|void
name|DoOnRemoval
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
block|{     }
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|EventData
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// lldb::EventDataBytes
comment|//----------------------------------------------------------------------
name|class
name|EventDataBytes
range|:
name|public
name|EventData
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors
comment|//------------------------------------------------------------------
name|EventDataBytes
argument_list|()
block|;
name|EventDataBytes
argument_list|(
specifier|const
name|char
operator|*
name|cstr
argument_list|)
block|;
name|EventDataBytes
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|)
block|;
operator|~
name|EventDataBytes
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Member functions
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
name|override
block|;
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|void
operator|*
name|GetBytes
argument_list|()
specifier|const
block|;
name|size_t
name|GetByteSize
argument_list|()
specifier|const
block|;
name|void
name|SetBytes
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|)
block|;
name|void
name|SwapBytes
argument_list|(
name|std
operator|::
name|string
operator|&
name|new_bytes
argument_list|)
block|;
name|void
name|SetBytesFromCString
argument_list|(
specifier|const
name|char
operator|*
name|cstr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Static functions
comment|//------------------------------------------------------------------
specifier|static
specifier|const
name|EventDataBytes
operator|*
name|GetEventDataFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
specifier|const
name|void
operator|*
name|GetBytesFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|size_t
name|GetByteSizeFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|string
name|m_bytes
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|EventDataBytes
argument_list|)
block|; }
decl_stmt|;
name|class
name|EventDataReceipt
range|:
name|public
name|EventData
block|{
name|public
operator|:
name|EventDataReceipt
argument_list|()
operator|:
name|EventData
argument_list|()
block|,
name|m_predicate
argument_list|(
argument|false
argument_list|)
block|{     }
operator|~
name|EventDataReceipt
argument_list|()
name|override
block|{     }
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|{
specifier|static
name|ConstString
name|g_flavor
argument_list|(
literal|"Process::ProcessEventData"
argument_list|)
block|;
return|return
name|g_flavor
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetFlavorString
argument_list|()
return|;
block|}
name|bool
name|WaitForEventReceived
argument_list|(
argument|const TimeValue *abstime = nullptr
argument_list|,
argument|bool *timed_out = nullptr
argument_list|)
block|{
return|return
name|m_predicate
operator|.
name|WaitForValueEqualTo
argument_list|(
name|true
argument_list|,
name|abstime
argument_list|,
name|timed_out
argument_list|)
return|;
block|}
name|private
operator|:
name|Predicate
operator|<
name|bool
operator|>
name|m_predicate
block|;
name|void
name|DoOnRemoval
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|{
name|m_predicate
operator|.
name|SetValue
argument_list|(
name|true
argument_list|,
name|eBroadcastAlways
argument_list|)
block|;     }
block|}
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// lldb::Event
comment|//----------------------------------------------------------------------
name|class
name|Event
block|{
name|friend
name|class
name|Listener
decl_stmt|;
name|friend
name|class
name|EventData
decl_stmt|;
name|friend
name|class
name|Broadcaster
operator|::
name|BroadcasterImpl
expr_stmt|;
name|public
label|:
name|Event
argument_list|(
argument|Broadcaster *broadcaster
argument_list|,
argument|uint32_t event_type
argument_list|,
argument|EventData *data = nullptr
argument_list|)
empty_stmt|;
name|Event
argument_list|(
argument|Broadcaster *broadcaster
argument_list|,
argument|uint32_t event_type
argument_list|,
argument|const lldb::EventDataSP&event_data_sp
argument_list|)
empty_stmt|;
name|Event
argument_list|(
argument|uint32_t event_type
argument_list|,
argument|EventData *data = nullptr
argument_list|)
empty_stmt|;
name|Event
argument_list|(
argument|uint32_t event_type
argument_list|,
argument|const lldb::EventDataSP&event_data_sp
argument_list|)
empty_stmt|;
operator|~
name|Event
argument_list|()
expr_stmt|;
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|EventData
modifier|*
name|GetData
parameter_list|()
block|{
return|return
name|m_data_sp
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|EventData
operator|*
name|GetData
argument_list|()
specifier|const
block|{
return|return
name|m_data_sp
operator|.
name|get
argument_list|()
return|;
block|}
name|void
name|SetData
parameter_list|(
name|EventData
modifier|*
name|new_data
parameter_list|)
block|{
name|m_data_sp
operator|.
name|reset
argument_list|(
name|new_data
argument_list|)
expr_stmt|;
block|}
name|uint32_t
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|void
name|SetType
parameter_list|(
name|uint32_t
name|new_type
parameter_list|)
block|{
name|m_type
operator|=
name|new_type
expr_stmt|;
block|}
name|Broadcaster
operator|*
name|GetBroadcaster
argument_list|()
specifier|const
block|{
name|Broadcaster
operator|::
name|BroadcasterImplSP
name|broadcaster_impl_sp
operator|=
name|m_broadcaster_wp
operator|.
name|lock
argument_list|()
block|;
if|if
condition|(
name|broadcaster_impl_sp
condition|)
return|return
name|broadcaster_impl_sp
operator|->
name|GetBroadcaster
argument_list|()
return|;
else|else
return|return
name|nullptr
return|;
block|}
name|bool
name|BroadcasterIs
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|)
block|{
name|Broadcaster
operator|::
name|BroadcasterImplSP
name|broadcaster_impl_sp
operator|=
name|m_broadcaster_wp
operator|.
name|lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|broadcaster_impl_sp
condition|)
return|return
name|broadcaster_impl_sp
operator|->
name|GetBroadcaster
argument_list|()
operator|==
name|broadcaster
return|;
else|else
return|return
name|false
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_data_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|private
label|:
comment|// This is only called by Listener when it pops an event off the queue for
comment|// the listener.  It calls the Event Data's DoOnRemoval() method, which is
comment|// virtual and can be overridden by the specific data classes.
name|void
name|DoOnRemoval
parameter_list|()
function_decl|;
comment|// Called by Broadcaster::BroadcastEvent prior to letting all the listeners
comment|// know about it update the contained broadcaster so that events can be
comment|// popped off one queue and re-broadcast to others.
name|void
name|SetBroadcaster
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|)
block|{
name|m_broadcaster_wp
operator|=
name|broadcaster
operator|->
name|GetBroadcasterImpl
argument_list|()
expr_stmt|;
block|}
name|Broadcaster
operator|::
name|BroadcasterImplWP
name|m_broadcaster_wp
expr_stmt|;
comment|// The broadcaster that sent this event
name|uint32_t
name|m_type
decl_stmt|;
comment|// The bit describing this event
name|lldb
operator|::
name|EventDataSP
name|m_data_sp
expr_stmt|;
comment|// User specific data for this event
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Event
argument_list|)
expr_stmt|;
name|Event
argument_list|()
expr_stmt|;
comment|// Disallow default constructor
block|}
empty_stmt|;
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
comment|// liblldb_Event_h_
end_comment

end_unit

