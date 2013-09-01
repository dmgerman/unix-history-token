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
file|<list>
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
name|virtual
operator|~
name|EventDataBytes
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Member functions
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
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
block|;  }
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// lldb::Event
comment|//----------------------------------------------------------------------
name|class
name|Event
block|{
name|friend
name|class
name|Broadcaster
decl_stmt|;
name|friend
name|class
name|Listener
decl_stmt|;
name|friend
name|class
name|EventData
decl_stmt|;
name|public
label|:
name|Event
argument_list|(
argument|Broadcaster *broadcaster
argument_list|,
argument|uint32_t event_type
argument_list|,
argument|EventData *data = NULL
argument_list|)
empty_stmt|;
name|Event
argument_list|(
argument|uint32_t event_type
argument_list|,
argument|EventData *data = NULL
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
name|m_data_ap
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
name|m_data_ap
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
name|m_data_ap
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
return|return
name|m_broadcaster
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
return|return
name|broadcaster
operator|==
name|m_broadcaster
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_data_ap
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
name|m_broadcaster
operator|=
name|broadcaster
expr_stmt|;
block|}
name|Broadcaster
modifier|*
name|m_broadcaster
decl_stmt|;
comment|// The broadcaster that sent this event
name|uint32_t
name|m_type
decl_stmt|;
comment|// The bit describing this event
name|std
operator|::
name|unique_ptr
operator|<
name|EventData
operator|>
name|m_data_ap
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

