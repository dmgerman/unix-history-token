begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Broadcaster.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_Broadcaster_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Broadcaster_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
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
comment|// for ListenerSP, EventSP, Broadcast...
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_comment
comment|// for uint32_t, UINT32_MAX
end_comment

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
comment|// for shared_ptr, operator==, enable...
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_comment
comment|// for set
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for pair
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Broadcaster
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|EventData
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Listener
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// lldb::BroadcastEventSpec
comment|//
comment|// This class is used to specify a kind of event to register for.  The Debugger
comment|// maintains a list of BroadcastEventSpec's and when it is made
comment|//----------------------------------------------------------------------
name|class
name|BroadcastEventSpec
block|{
name|public
label|:
name|BroadcastEventSpec
argument_list|(
argument|const ConstString&broadcaster_class
argument_list|,
argument|uint32_t event_bits
argument_list|)
block|:
name|m_broadcaster_class
argument_list|(
name|broadcaster_class
argument_list|)
operator|,
name|m_event_bits
argument_list|(
argument|event_bits
argument_list|)
block|{}
name|BroadcastEventSpec
argument_list|(
specifier|const
name|BroadcastEventSpec
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|BroadcastEventSpec
argument_list|()
operator|=
expr|default
expr_stmt|;
specifier|const
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
block|{
return|return
name|m_broadcaster_class
return|;
block|}
name|uint32_t
name|GetEventBits
argument_list|()
specifier|const
block|{
return|return
name|m_event_bits
return|;
block|}
comment|// Tell whether this BroadcastEventSpec is contained in in_spec.
comment|// That is:
comment|// (a) the two spec's share the same broadcaster class
comment|// (b) the event bits of this spec are wholly contained in those of in_spec.
name|bool
name|IsContainedIn
argument_list|(
name|BroadcastEventSpec
name|in_spec
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_broadcaster_class
operator|!=
name|in_spec
operator|.
name|GetBroadcasterClass
argument_list|()
condition|)
return|return
name|false
return|;
name|uint32_t
name|in_bits
init|=
name|in_spec
operator|.
name|GetEventBits
argument_list|()
decl_stmt|;
if|if
condition|(
name|in_bits
operator|==
name|m_event_bits
condition|)
return|return
name|true
return|;
else|else
block|{
if|if
condition|(
operator|(
name|m_event_bits
operator|&
name|in_bits
operator|)
operator|!=
literal|0
operator|&&
operator|(
name|m_event_bits
operator|&
operator|~
name|in_bits
operator|)
operator|==
literal|0
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|BroadcastEventSpec
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|BroadcastEventSpec
modifier|&
name|operator
init|=
operator|(
specifier|const
name|BroadcastEventSpec
operator|&
name|rhs
operator|)
decl_stmt|;
name|private
label|:
name|ConstString
name|m_broadcaster_class
decl_stmt|;
name|uint32_t
name|m_event_bits
decl_stmt|;
block|}
empty_stmt|;
name|class
name|BroadcasterManager
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|BroadcasterManager
operator|>
block|{
name|public
operator|:
name|friend
name|class
name|Listener
block|;
name|protected
operator|:
name|BroadcasterManager
argument_list|()
block|;
name|public
operator|:
comment|// Listeners hold onto weak pointers to their broadcaster managers.  So they
comment|// must be made into shared pointers, which you do with
comment|// MakeBroadcasterManager.
specifier|static
name|lldb
operator|::
name|BroadcasterManagerSP
name|MakeBroadcasterManager
argument_list|()
block|;
operator|~
name|BroadcasterManager
argument_list|()
operator|=
expr|default
block|;
name|uint32_t
name|RegisterListenerForEvents
argument_list|(
argument|const lldb::ListenerSP&listener_sp
argument_list|,
argument|BroadcastEventSpec event_spec
argument_list|)
block|;
name|bool
name|UnregisterListenerForEvents
argument_list|(
argument|const lldb::ListenerSP&listener_sp
argument_list|,
argument|BroadcastEventSpec event_spec
argument_list|)
block|;
name|lldb
operator|::
name|ListenerSP
name|GetListenerForEventSpec
argument_list|(
argument|BroadcastEventSpec event_spec
argument_list|)
specifier|const
block|;
name|void
name|SignUpListenersForBroadcaster
argument_list|(
name|Broadcaster
operator|&
name|broadcaster
argument_list|)
block|;
name|void
name|RemoveListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|)
block|;
name|void
name|RemoveListener
argument_list|(
name|Listener
operator|*
name|listener
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|BroadcastEventSpec
operator|,
name|lldb
operator|::
name|ListenerSP
operator|>
name|event_listener_key
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BroadcastEventSpec
operator|,
name|lldb
operator|::
name|ListenerSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|ListenerSP
operator|>
name|listener_collection
expr_stmt|;
name|collection
name|m_event_map
decl_stmt|;
name|listener_collection
name|m_listeners
decl_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_manager_mutex
expr_stmt|;
comment|// A couple of comparator classes for find_if:
name|class
name|BroadcasterClassMatches
block|{
name|public
label|:
name|BroadcasterClassMatches
argument_list|(
specifier|const
name|ConstString
operator|&
name|broadcaster_class
argument_list|)
operator|:
name|m_broadcaster_class
argument_list|(
argument|broadcaster_class
argument_list|)
block|{}
operator|~
name|BroadcasterClassMatches
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|event_listener_key
name|input
operator|)
specifier|const
block|{
return|return
operator|(
name|input
operator|.
name|first
operator|.
name|GetBroadcasterClass
argument_list|()
operator|==
name|m_broadcaster_class
operator|)
return|;
block|}
name|private
label|:
name|ConstString
name|m_broadcaster_class
decl_stmt|;
block|}
empty_stmt|;
name|class
name|BroadcastEventSpecMatches
block|{
name|public
label|:
name|BroadcastEventSpecMatches
argument_list|(
argument|BroadcastEventSpec broadcaster_spec
argument_list|)
block|:
name|m_broadcaster_spec
argument_list|(
argument|broadcaster_spec
argument_list|)
block|{}
operator|~
name|BroadcastEventSpecMatches
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|event_listener_key
name|input
operator|)
specifier|const
block|{
return|return
operator|(
name|input
operator|.
name|first
operator|.
name|IsContainedIn
argument_list|(
name|m_broadcaster_spec
argument_list|)
operator|)
return|;
block|}
name|private
label|:
name|BroadcastEventSpec
name|m_broadcaster_spec
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ListenerMatchesAndSharedBits
block|{
name|public
label|:
name|explicit
name|ListenerMatchesAndSharedBits
argument_list|(
name|BroadcastEventSpec
name|broadcaster_spec
argument_list|,
specifier|const
name|lldb
operator|::
name|ListenerSP
name|listener_sp
argument_list|)
range|:
name|m_broadcaster_spec
argument_list|(
name|broadcaster_spec
argument_list|)
decl_stmt|,
name|m_listener_sp
argument_list|(
name|listener_sp
argument_list|)
block|{}
operator|~
name|ListenerMatchesAndSharedBits
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|event_listener_key
name|input
operator|)
specifier|const
block|{
return|return
operator|(
name|input
operator|.
name|first
operator|.
name|GetBroadcasterClass
argument_list|()
operator|==
name|m_broadcaster_spec
operator|.
name|GetBroadcasterClass
argument_list|()
operator|&&
operator|(
name|input
operator|.
name|first
operator|.
name|GetEventBits
argument_list|()
operator|&
name|m_broadcaster_spec
operator|.
name|GetEventBits
argument_list|()
operator|)
operator|!=
literal|0
operator|&&
name|input
operator|.
name|second
operator|==
name|m_listener_sp
operator|)
return|;
block|}
name|private
label|:
name|BroadcastEventSpec
name|m_broadcaster_spec
decl_stmt|;
specifier|const
name|lldb
operator|::
name|ListenerSP
name|m_listener_sp
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ListenerMatches
block|{
name|public
label|:
name|explicit
name|ListenerMatches
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
name|in_listener_sp
argument_list|)
range|:
name|m_listener_sp
argument_list|(
argument|in_listener_sp
argument_list|)
block|{}
operator|~
name|ListenerMatches
argument_list|()
operator|=
expr|default
decl_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|event_listener_key
name|input
operator|)
specifier|const
block|{
if|if
condition|(
name|input
operator|.
name|second
operator|==
name|m_listener_sp
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
name|private
label|:
specifier|const
name|lldb
operator|::
name|ListenerSP
name|m_listener_sp
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ListenerMatchesPointer
block|{
name|public
label|:
name|ListenerMatchesPointer
argument_list|(
specifier|const
name|Listener
operator|*
name|in_listener
argument_list|)
operator|:
name|m_listener
argument_list|(
argument|in_listener
argument_list|)
block|{}
operator|~
name|ListenerMatchesPointer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|event_listener_key
name|input
operator|)
specifier|const
block|{
if|if
condition|(
name|input
operator|.
name|second
operator|.
name|get
argument_list|()
operator|==
name|m_listener
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|lldb
operator|::
name|ListenerSP
name|input
operator|)
specifier|const
block|{
if|if
condition|(
name|input
operator|.
name|get
argument_list|()
operator|==
name|m_listener
condition|)
return|return
name|true
return|;
else|else
return|return
name|false
return|;
block|}
name|private
label|:
specifier|const
name|Listener
modifier|*
name|m_listener
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class Broadcaster Broadcaster.h "lldb/Core/Broadcaster.h"
end_comment

begin_comment
comment|/// @brief An event broadcasting class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Broadcaster class is designed to be subclassed by objects that
end_comment

begin_comment
comment|/// wish to vend events in a multi-threaded environment. Broadcaster
end_comment

begin_comment
comment|/// objects can each vend 32 events. Each event is represented by a bit
end_comment

begin_comment
comment|/// in a 32 bit value and these bits can be set:
end_comment

begin_comment
comment|///     @see Broadcaster::SetEventBits(uint32_t)
end_comment

begin_comment
comment|/// or cleared:
end_comment

begin_comment
comment|///     @see Broadcaster::ResetEventBits(uint32_t)
end_comment

begin_comment
comment|/// When an event gets set the Broadcaster object will notify the
end_comment

begin_comment
comment|/// Listener object that is listening for the event (if there is one).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Subclasses should provide broadcast bit definitions for any events
end_comment

begin_comment
comment|/// they vend, typically using an enumeration:
end_comment

begin_comment
comment|///     \code
end_comment

begin_comment
comment|///         class Foo : public Broadcaster
end_comment

begin_comment
comment|///         {
end_comment

begin_comment
comment|///         public:
end_comment

begin_comment
comment|///         //----------------------------------------------------------
end_comment

begin_comment
comment|///         // Broadcaster event bits definitions.
end_comment

begin_comment
comment|///         //----------------------------------------------------------
end_comment

begin_comment
comment|///         enum
end_comment

begin_comment
comment|///         {
end_comment

begin_comment
comment|///             eBroadcastBitOne   = (1<< 0),
end_comment

begin_comment
comment|///             eBroadcastBitTwo   = (1<< 1),
end_comment

begin_comment
comment|///             eBroadcastBitThree = (1<< 2),
end_comment

begin_comment
comment|///             ...
end_comment

begin_comment
comment|///         };
end_comment

begin_comment
comment|///     \endcode
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|Broadcaster
block|{
name|friend
name|class
name|Listener
decl_stmt|;
name|friend
name|class
name|Event
decl_stmt|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with a broadcaster with a name.
comment|///
comment|/// @param[in] name
comment|///     A NULL terminated C string that contains the name of the
comment|///     broadcaster object.
comment|//------------------------------------------------------------------
name|Broadcaster
argument_list|(
argument|lldb::BroadcasterManagerSP manager_sp
argument_list|,
argument|const char *name
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class gets subclassed.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Broadcaster
argument_list|()
expr_stmt|;
name|void
name|CheckInWithManager
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Broadcast an event which has no associated data.
comment|///
comment|/// @param[in] event_type
comment|///     The element from the enum defining this broadcaster's events
comment|///     that is being broadcast.
comment|///
comment|/// @param[in] event_data
comment|///     User event data that will be owned by the lldb::Event that
comment|///     is created internally.
comment|///
comment|/// @param[in] unique
comment|///     If true, then only add an event of this type if there isn't
comment|///     one already in the queue.
comment|///
comment|//------------------------------------------------------------------
name|void
name|BroadcastEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|{
name|m_broadcaster_sp
operator|->
name|BroadcastEvent
argument_list|(
name|event_sp
argument_list|)
expr_stmt|;
block|}
name|void
name|BroadcastEventIfUnique
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|{
name|m_broadcaster_sp
operator|->
name|BroadcastEventIfUnique
argument_list|(
name|event_sp
argument_list|)
expr_stmt|;
block|}
name|void
name|BroadcastEvent
argument_list|(
name|uint32_t
name|event_type
argument_list|,
specifier|const
name|lldb
operator|::
name|EventDataSP
operator|&
name|event_data_sp
argument_list|)
block|{
name|m_broadcaster_sp
operator|->
name|BroadcastEvent
argument_list|(
name|event_type
argument_list|,
name|event_data_sp
argument_list|)
expr_stmt|;
block|}
name|void
name|BroadcastEvent
parameter_list|(
name|uint32_t
name|event_type
parameter_list|,
name|EventData
modifier|*
name|event_data
init|=
name|nullptr
parameter_list|)
block|{
name|m_broadcaster_sp
operator|->
name|BroadcastEvent
argument_list|(
name|event_type
argument_list|,
name|event_data
argument_list|)
expr_stmt|;
block|}
name|void
name|BroadcastEventIfUnique
parameter_list|(
name|uint32_t
name|event_type
parameter_list|,
name|EventData
modifier|*
name|event_data
init|=
name|nullptr
parameter_list|)
block|{
name|m_broadcaster_sp
operator|->
name|BroadcastEventIfUnique
argument_list|(
name|event_type
argument_list|,
name|event_data
argument_list|)
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_broadcaster_sp
operator|->
name|Clear
argument_list|()
expr_stmt|;
block|}
name|virtual
name|void
name|AddInitialEventsToListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|requested_events
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Listen for any events specified by \a event_mask.
comment|///
comment|/// Only one listener can listen to each event bit in a given
comment|/// Broadcaster. Once a listener has acquired an event bit, no
comment|/// other broadcaster will have access to it until it is
comment|/// relinquished by the first listener that gets it. The actual
comment|/// event bits that get acquired by \a listener may be different
comment|/// from what is requested in \a event_mask, and to track this the
comment|/// actual event bits that are acquired get returned.
comment|///
comment|/// @param[in] listener
comment|///     The Listener object that wants to monitor the events that
comment|///     get broadcast by this object.
comment|///
comment|/// @param[in] event_mask
comment|///     A bit mask that indicates which events the listener is
comment|///     asking to monitor.
comment|///
comment|/// @return
comment|///     The actual event bits that were acquired by \a listener.
comment|//------------------------------------------------------------------
name|uint32_t
name|AddListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
argument_list|)
block|{
return|return
name|m_broadcaster_sp
operator|->
name|AddListener
argument_list|(
name|listener_sp
argument_list|,
name|event_mask
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the NULL terminated C string name of this Broadcaster
comment|/// object.
comment|///
comment|/// @return
comment|///     The NULL terminated C string name of this Broadcaster.
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
modifier|&
name|GetBroadcasterName
parameter_list|()
block|{
return|return
name|m_broadcaster_name
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the event name(s) for one or more event bits.
comment|///
comment|/// @param[in] event_mask
comment|///     A bit mask that indicates which events to get names for.
comment|///
comment|/// @return
comment|///     The NULL terminated C string name of this Broadcaster.
comment|//------------------------------------------------------------------
name|bool
name|GetEventNames
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|uint32_t
name|event_mask
argument_list|,
name|bool
name|prefix_with_broadcaster_name
argument_list|)
decl|const
block|{
return|return
name|m_broadcaster_sp
operator|->
name|GetEventNames
argument_list|(
name|s
argument_list|,
name|event_mask
argument_list|,
name|prefix_with_broadcaster_name
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the name for an event bit.
comment|///
comment|/// @param[in] event_mask
comment|///     A bit mask that indicates which events the listener is
comment|///     asking to monitor.
comment|///
comment|/// @return
comment|///     The NULL terminated C string name of this Broadcaster.
comment|//------------------------------------------------------------------
name|void
name|SetEventName
parameter_list|(
name|uint32_t
name|event_mask
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|m_broadcaster_sp
operator|->
name|SetEventName
argument_list|(
name|event_mask
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetEventName
argument_list|(
name|uint32_t
name|event_mask
argument_list|)
decl|const
block|{
return|return
name|m_broadcaster_sp
operator|->
name|GetEventName
argument_list|(
name|event_mask
argument_list|)
return|;
block|}
name|bool
name|EventTypeHasListeners
parameter_list|(
name|uint32_t
name|event_type
parameter_list|)
block|{
return|return
name|m_broadcaster_sp
operator|->
name|EventTypeHasListeners
argument_list|(
name|event_type
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Removes a Listener from this broadcasters list and frees the
comment|/// event bits specified by \a event_mask that were previously
comment|/// acquired by \a listener (assuming \a listener was listening to
comment|/// this object) for other listener objects to use.
comment|///
comment|/// @param[in] listener
comment|///     A Listener object that previously called AddListener.
comment|///
comment|/// @param[in] event_mask
comment|///     The event bits \a listener wishes to relinquish.
comment|///
comment|/// @return
comment|///     \b True if the listener was listening to this broadcaster
comment|///     and was removed, \b false otherwise.
comment|///
comment|/// @see uint32_t Broadcaster::AddListener (Listener*, uint32_t)
comment|//------------------------------------------------------------------
name|bool
name|RemoveListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
operator|=
name|UINT32_MAX
argument_list|)
block|{
return|return
name|m_broadcaster_sp
operator|->
name|RemoveListener
argument_list|(
name|listener_sp
argument_list|,
name|event_mask
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Provides a simple mechanism to temporarily redirect events from
comment|/// broadcaster.  When you call this function passing in a listener and
comment|/// event type mask, all events from the broadcaster matching the mask
comment|/// will now go to the hijacking listener.
comment|/// Only one hijack can occur at a time.  If we need more than this we
comment|/// will have to implement a Listener stack.
comment|///
comment|/// @param[in] listener
comment|///     A Listener object.  You do not need to call StartListeningForEvents
comment|///     for this broadcaster (that would fail anyway since the event bits
comment|///     would most likely be taken by the listener(s) you are usurping.
comment|///
comment|/// @param[in] event_mask
comment|///     The event bits \a listener wishes to hijack.
comment|///
comment|/// @return
comment|///     \b True if the event mask could be hijacked, \b false otherwise.
comment|///
comment|/// @see uint32_t Broadcaster::AddListener (Listener*, uint32_t)
comment|//------------------------------------------------------------------
name|bool
name|HijackBroadcaster
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
operator|=
name|UINT32_MAX
argument_list|)
block|{
return|return
name|m_broadcaster_sp
operator|->
name|HijackBroadcaster
argument_list|(
name|listener_sp
argument_list|,
name|event_mask
argument_list|)
return|;
block|}
name|bool
name|IsHijackedForEvent
parameter_list|(
name|uint32_t
name|event_mask
parameter_list|)
block|{
return|return
name|m_broadcaster_sp
operator|->
name|IsHijackedForEvent
argument_list|(
name|event_mask
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Restore the state of the Broadcaster from a previous hijack attempt.
comment|///
comment|//------------------------------------------------------------------
name|void
name|RestoreBroadcaster
parameter_list|()
block|{
name|m_broadcaster_sp
operator|->
name|RestoreBroadcaster
argument_list|()
expr_stmt|;
block|}
comment|// This needs to be filled in if you are going to register the broadcaster
comment|// with the broadcaster
comment|// manager and do broadcaster class matching.
comment|// FIXME: Probably should make a ManagedBroadcaster subclass with all the bits
comment|// needed to work
comment|// with the BroadcasterManager, so that it is clearer how to add one.
name|virtual
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|BroadcasterManagerSP
name|GetManager
argument_list|()
expr_stmt|;
name|protected
label|:
comment|// BroadcasterImpl contains the actual Broadcaster implementation.  The
comment|// Broadcaster makes a BroadcasterImpl
comment|// which lives as long as it does.  The Listeners& the Events hold a weak
comment|// pointer to the BroadcasterImpl,
comment|// so that they can survive if a Broadcaster they were listening to is
comment|// destroyed w/o their being able to
comment|// unregister from it (which can happen if the Broadcasters& Listeners are
comment|// being destroyed on separate threads
comment|// simultaneously.
comment|// The Broadcaster itself can't be shared out as a weak pointer, because some
comment|// things that are broadcasters
comment|// (e.g. the Target and the Process) are shared in their own right.
comment|//
comment|// For the most part, the Broadcaster functions dispatch to the
comment|// BroadcasterImpl, and are documented in the
comment|// public Broadcaster API above.
name|class
name|BroadcasterImpl
block|{
name|friend
name|class
name|Listener
decl_stmt|;
name|friend
name|class
name|Broadcaster
decl_stmt|;
name|public
label|:
name|BroadcasterImpl
argument_list|(
name|Broadcaster
operator|&
name|broadcaster
argument_list|)
expr_stmt|;
operator|~
name|BroadcasterImpl
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|BroadcastEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|void
name|BroadcastEventIfUnique
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
decl_stmt|;
name|void
name|BroadcastEvent
parameter_list|(
name|uint32_t
name|event_type
parameter_list|,
name|EventData
modifier|*
name|event_data
init|=
name|nullptr
parameter_list|)
function_decl|;
name|void
name|BroadcastEvent
argument_list|(
name|uint32_t
name|event_type
argument_list|,
specifier|const
name|lldb
operator|::
name|EventDataSP
operator|&
name|event_data_sp
argument_list|)
decl_stmt|;
name|void
name|BroadcastEventIfUnique
parameter_list|(
name|uint32_t
name|event_type
parameter_list|,
name|EventData
modifier|*
name|event_data
init|=
name|nullptr
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|uint32_t
name|AddListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
argument_list|)
decl_stmt|;
specifier|const
name|char
operator|*
name|GetBroadcasterName
argument_list|()
specifier|const
block|{
return|return
name|m_broadcaster
operator|.
name|GetBroadcasterName
argument_list|()
operator|.
name|AsCString
argument_list|()
return|;
block|}
name|Broadcaster
modifier|*
name|GetBroadcaster
parameter_list|()
function_decl|;
name|bool
name|GetEventNames
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|uint32_t
name|event_mask
argument_list|,
name|bool
name|prefix_with_broadcaster_name
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetEventName
parameter_list|(
name|uint32_t
name|event_mask
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|m_event_names
index|[
name|event_mask
index|]
operator|=
name|name
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|GetEventName
argument_list|(
name|uint32_t
name|event_mask
argument_list|)
decl|const
block|{
specifier|const
specifier|auto
name|pos
init|=
name|m_event_names
operator|.
name|find
argument_list|(
name|event_mask
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
name|m_event_names
operator|.
name|end
argument_list|()
condition|)
return|return
name|pos
operator|->
name|second
operator|.
name|c_str
argument_list|()
return|;
return|return
name|nullptr
return|;
block|}
name|bool
name|EventTypeHasListeners
parameter_list|(
name|uint32_t
name|event_type
parameter_list|)
function_decl|;
name|bool
name|RemoveListener
argument_list|(
name|lldb_private
operator|::
name|Listener
operator|*
name|listener
argument_list|,
name|uint32_t
name|event_mask
operator|=
name|UINT32_MAX
argument_list|)
decl_stmt|;
name|bool
name|RemoveListener
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
operator|=
name|UINT32_MAX
argument_list|)
decl_stmt|;
name|bool
name|HijackBroadcaster
argument_list|(
specifier|const
name|lldb
operator|::
name|ListenerSP
operator|&
name|listener_sp
argument_list|,
name|uint32_t
name|event_mask
operator|=
name|UINT32_MAX
argument_list|)
decl_stmt|;
name|bool
name|IsHijackedForEvent
parameter_list|(
name|uint32_t
name|event_mask
parameter_list|)
function_decl|;
name|void
name|RestoreBroadcaster
parameter_list|()
function_decl|;
name|protected
label|:
name|void
name|PrivateBroadcastEvent
argument_list|(
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|,
name|bool
name|unique
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetHijackingListenerName
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|//
comment|//------------------------------------------------------------------
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|ListenerWP
operator|,
name|uint32_t
operator|>
operator|,
literal|4
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|std
operator|::
name|string
operator|>
name|event_names_map
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|lldb
operator|::
name|ListenerSP
operator|,
name|uint32_t
operator|&
operator|>
operator|,
literal|4
operator|>
name|GetListeners
argument_list|()
expr_stmt|;
name|Broadcaster
modifier|&
name|m_broadcaster
decl_stmt|;
comment|///< The broadcsater that this implements
name|event_names_map
name|m_event_names
decl_stmt|;
comment|///< Optionally define event names for
comment|///readability and logging for each event bit
name|collection
name|m_listeners
decl_stmt|;
comment|///< A list of Listener / event_mask pairs that are
comment|///listening to this broadcaster.
name|std
operator|::
name|recursive_mutex
name|m_listeners_mutex
expr_stmt|;
comment|///< A mutex that protects \a m_listeners.
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ListenerSP
operator|>
name|m_hijacking_listeners
expr_stmt|;
comment|// A simple mechanism
comment|// to intercept events
comment|// from a broadcaster
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|m_hijacking_masks
expr_stmt|;
comment|// At some point we may want to
comment|// have a stack or Listener
comment|// collections, but for now this is just for private hijacking.
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Broadcaster only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BroadcasterImpl
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|BroadcasterImpl
operator|>
name|BroadcasterImplSP
expr_stmt|;
typedef|typedef
name|std
operator|::
name|weak_ptr
operator|<
name|BroadcasterImpl
operator|>
name|BroadcasterImplWP
expr_stmt|;
name|BroadcasterImplSP
name|GetBroadcasterImpl
parameter_list|()
block|{
return|return
name|m_broadcaster_sp
return|;
block|}
specifier|const
name|char
modifier|*
name|GetHijackingListenerName
parameter_list|()
block|{
return|return
name|m_broadcaster_sp
operator|->
name|GetHijackingListenerName
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Broadcaster can see and modify these
comment|//------------------------------------------------------------------
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Broadcaster only
comment|//------------------------------------------------------------------
name|BroadcasterImplSP
name|m_broadcaster_sp
decl_stmt|;
name|lldb
operator|::
name|BroadcasterManagerSP
name|m_manager_sp
expr_stmt|;
specifier|const
name|ConstString
name|m_broadcaster_name
decl_stmt|;
comment|///< The name of this broadcaster object.
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Broadcaster
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
comment|// liblldb_Broadcaster_h_
end_comment

end_unit

