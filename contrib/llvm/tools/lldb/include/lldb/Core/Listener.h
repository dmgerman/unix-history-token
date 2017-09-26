begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Listener.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Select_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Select_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_comment
comment|// for Broadcaster::BroadcasterImplWP
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Timeout.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for BroadcasterManagerWP, EventSP
end_comment

begin_include
include|#
directive|include
file|<condition_variable>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// for owner_less, enable_shared_from_this
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<ratio>
end_include

begin_comment
comment|// for micro
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConstString
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Event
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Listener
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Listener
operator|>
block|{
name|public
operator|:
typedef|typedef
name|bool
argument_list|(
operator|*
name|HandleBroadcastCallback
argument_list|)
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|void
operator|*
name|baton
argument_list|)
expr_stmt|;
name|friend
name|class
name|Broadcaster
decl_stmt|;
name|friend
name|class
name|BroadcasterManager
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
comment|//
comment|// Listeners have to be constructed into shared pointers - at least if you
comment|// want them to listen to Broadcasters,
name|protected
label|:
name|Listener
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
name|lldb
operator|::
name|ListenerSP
name|MakeListener
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
operator|~
name|Listener
argument_list|()
expr_stmt|;
name|void
name|AddEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
block|{
return|return
name|m_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|uint32_t
name|StartListeningForEventSpec
argument_list|(
name|lldb
operator|::
name|BroadcasterManagerSP
name|manager_sp
argument_list|,
specifier|const
name|BroadcastEventSpec
operator|&
name|event_spec
argument_list|)
decl_stmt|;
name|bool
name|StopListeningForEventSpec
argument_list|(
name|lldb
operator|::
name|BroadcasterManagerSP
name|manager_sp
argument_list|,
specifier|const
name|BroadcastEventSpec
operator|&
name|event_spec
argument_list|)
decl_stmt|;
name|uint32_t
name|StartListeningForEvents
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|,
name|uint32_t
name|event_mask
parameter_list|)
function_decl|;
name|uint32_t
name|StartListeningForEvents
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|,
name|uint32_t
name|event_mask
parameter_list|,
name|HandleBroadcastCallback
name|callback
parameter_list|,
name|void
modifier|*
name|callback_user_data
parameter_list|)
function_decl|;
name|bool
name|StopListeningForEvents
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|,
name|uint32_t
name|event_mask
parameter_list|)
function_decl|;
name|Event
modifier|*
name|PeekAtNextEvent
parameter_list|()
function_decl|;
name|Event
modifier|*
name|PeekAtNextEventForBroadcaster
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|)
function_decl|;
name|Event
modifier|*
name|PeekAtNextEventForBroadcasterWithType
parameter_list|(
name|Broadcaster
modifier|*
name|broadcaster
parameter_list|,
name|uint32_t
name|event_type_mask
parameter_list|)
function_decl|;
comment|// Returns true if an event was received, false if we timed out.
name|bool
name|GetEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
decl_stmt|;
name|bool
name|GetEventForBroadcaster
argument_list|(
name|Broadcaster
operator|*
name|broadcaster
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
decl_stmt|;
name|bool
name|GetEventForBroadcasterWithType
argument_list|(
name|Broadcaster
operator|*
name|broadcaster
argument_list|,
name|uint32_t
name|event_type_mask
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
decl_stmt|;
name|size_t
name|HandleBroadcastEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Listener can see and modify these
comment|//------------------------------------------------------------------
struct|struct
name|BroadcasterInfo
block|{
name|BroadcasterInfo
argument_list|(
argument|uint32_t mask
argument_list|,
argument|HandleBroadcastCallback cb = nullptr
argument_list|,
argument|void *ud = nullptr
argument_list|)
block|:
name|event_mask
argument_list|(
name|mask
argument_list|)
operator|,
name|callback
argument_list|(
name|cb
argument_list|)
operator|,
name|callback_user_data
argument_list|(
argument|ud
argument_list|)
block|{}
name|uint32_t
name|event_mask
expr_stmt|;
name|HandleBroadcastCallback
name|callback
decl_stmt|;
name|void
modifier|*
name|callback_user_data
decl_stmt|;
block|}
struct|;
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|Broadcaster
operator|::
name|BroadcasterImplWP
operator|,
name|BroadcasterInfo
operator|,
name|std
operator|::
name|owner_less
operator|<
name|Broadcaster
operator|::
name|BroadcasterImplWP
operator|>>
name|broadcaster_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|lldb
operator|::
name|EventSP
operator|>
name|event_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|BroadcasterManagerWP
operator|>
name|broadcaster_manager_collection
expr_stmt|;
name|bool
name|FindNextEventInternal
argument_list|(
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|mutex
operator|>
operator|&
name|lock
argument_list|,
name|Broadcaster
operator|*
name|broadcaster
argument_list|,
comment|// nullptr for any broadcaster
specifier|const
name|ConstString
operator|*
name|sources
argument_list|,
comment|// nullptr for any event
name|uint32_t
name|num_sources
argument_list|,
name|uint32_t
name|event_type_mask
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|bool
name|remove
argument_list|)
decl_stmt|;
name|bool
name|GetEventInternal
argument_list|(
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|,
name|Broadcaster
operator|*
name|broadcaster
argument_list|,
comment|// nullptr for any broadcaster
specifier|const
name|ConstString
operator|*
name|sources
argument_list|,
comment|// nullptr for any event
name|uint32_t
name|num_sources
argument_list|,
name|uint32_t
name|event_type_mask
argument_list|,
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|m_name
expr_stmt|;
name|broadcaster_collection
name|m_broadcasters
decl_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_broadcasters_mutex
expr_stmt|;
comment|// Protects m_broadcasters
name|event_collection
name|m_events
decl_stmt|;
name|std
operator|::
name|mutex
name|m_events_mutex
expr_stmt|;
comment|// Protects m_broadcasters and m_events
name|std
operator|::
name|condition_variable
name|m_events_condition
expr_stmt|;
name|broadcaster_manager_collection
name|m_broadcaster_managers
decl_stmt|;
name|void
name|BroadcasterWillDestruct
parameter_list|(
name|Broadcaster
modifier|*
parameter_list|)
function_decl|;
name|void
name|BroadcasterManagerWillDestruct
argument_list|(
name|lldb
operator|::
name|BroadcasterManagerSP
name|manager_sp
argument_list|)
decl_stmt|;
comment|//    broadcaster_collection::iterator
comment|//    FindBroadcasterWithMask (Broadcaster *broadcaster,
comment|//                             uint32_t event_mask,
comment|//                             bool exact);
comment|//------------------------------------------------------------------
comment|// For Listener only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Listener
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Select_h_
end_comment

end_unit

