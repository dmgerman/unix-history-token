begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Breakpoint.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_Breakpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Breakpoint_h_
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

begin_include
include|#
directive|include
file|<unordered_set>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/Breakpoint/BreakpointID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointLocationCollection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointLocationList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointOptions.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/Stoppoint.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/SearchFilter.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Breakpoint Breakpoint.h "lldb/Breakpoint/Breakpoint.h"
comment|/// @brief Class that manages logical breakpoint setting.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// A breakpoint has four main parts, a filter, a resolver, the list of
comment|/// breakpoint
comment|/// locations that have been determined for the filter/resolver pair, and
comment|/// finally
comment|/// a set of options for the breakpoint.
comment|///
comment|/// \b Filter:
comment|/// This is an object derived from SearchFilter.  It manages the search
comment|/// for breakpoint location matches through the symbols in the module list of
comment|/// the target
comment|/// that owns it.  It also filters out locations based on whatever logic it
comment|/// wants.
comment|///
comment|/// \b Resolver:
comment|/// This is an object derived from BreakpointResolver.  It provides a
comment|/// callback to the filter that will find breakpoint locations.  How it does
comment|/// this is
comment|/// determined by what kind of resolver it is.
comment|///
comment|/// The Breakpoint class also provides constructors for the common breakpoint
comment|/// cases
comment|/// which make the appropriate filter and resolver for you.
comment|///
comment|/// \b Location List:
comment|/// This stores the breakpoint locations that have been determined
comment|/// to date.  For a given breakpoint, there will be only one location with a
comment|/// given
comment|/// address.  Adding a location at an already taken address will just return the
comment|/// location
comment|/// already at that address.  Locations can be looked up by ID, or by address.
comment|///
comment|/// \b Options:
comment|/// This includes:
comment|///    \b Enabled/Disabled
comment|///    \b Ignore Count
comment|///    \b Callback
comment|///    \b Condition
comment|/// Note, these options can be set on the breakpoint, and they can also be set
comment|/// on the
comment|/// individual locations.  The options set on the breakpoint take precedence
comment|/// over the
comment|/// options set on the individual location.
comment|/// So for instance disabling the breakpoint will cause NONE of the locations to
comment|/// get hit.
comment|/// But if the breakpoint is enabled, then the location's enabled state will be
comment|/// checked
comment|/// to determine whether to insert that breakpoint location.
comment|/// Similarly, if the breakpoint condition says "stop", we won't check the
comment|/// location's condition.
comment|/// But if the breakpoint condition says "continue", then we will check the
comment|/// location for whether
comment|/// to actually stop or not.
comment|/// One subtle point worth observing here is that you don't actually stop at a
comment|/// Breakpoint, you
comment|/// always stop at one of its locations.  So the "should stop" tests are done by
comment|/// the location,
comment|/// not by the breakpoint.
comment|//----------------------------------------------------------------------
name|class
name|Breakpoint
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Breakpoint
operator|>
decl_stmt|,
name|public
name|Stoppoint
block|{
name|public
label|:
specifier|static
specifier|const
name|ConstString
modifier|&
name|GetEventIdentifier
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// An enum specifying the match style for breakpoint settings.  At
comment|/// present only used for function name style breakpoints.
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
block|{
name|Exact
block|,
name|Regexp
block|,
name|Glob
block|}
name|MatchType
typedef|;
name|private
label|:
name|enum
name|class
name|OptionNames
range|:
name|uint32_t
block|{
name|Names
operator|=
literal|0
block|,
name|Hardware
block|,
name|LastOptionName
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_option_names
index|[
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|OptionNames
operator|::
name|LastOptionName
operator|)
index|]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetKey
parameter_list|(
name|OptionNames
name|enum_value
parameter_list|)
block|{
return|return
name|g_option_names
index|[
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|enum_value
operator|)
index|]
return|;
block|}
name|public
label|:
name|class
name|BreakpointEventData
range|:
name|public
name|EventData
block|{
name|public
operator|:
name|BreakpointEventData
argument_list|(
argument|lldb::BreakpointEventType sub_type
argument_list|,
argument|const lldb::BreakpointSP&new_breakpoint_sp
argument_list|)
block|;
operator|~
name|BreakpointEventData
argument_list|()
name|override
block|;
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
name|override
block|;
name|lldb
operator|::
name|BreakpointEventType
name|GetBreakpointEventType
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|BreakpointSP
operator|&
name|GetBreakpoint
argument_list|()
block|;
name|BreakpointLocationCollection
operator|&
name|GetBreakpointLocationCollection
argument_list|()
block|{
return|return
name|m_locations
return|;
block|}
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|lldb
operator|::
name|BreakpointEventType
name|GetBreakpointEventTypeFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|BreakpointSP
name|GetBreakpointFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|BreakpointLocationSP
name|GetBreakpointLocationAtIndexFromEvent
argument_list|(
argument|const lldb::EventSP&event_sp
argument_list|,
argument|uint32_t loc_idx
argument_list|)
block|;
specifier|static
name|size_t
name|GetNumBreakpointLocationsFromEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|EventSP
operator|&
name|event_sp
argument_list|)
block|;
specifier|static
specifier|const
name|BreakpointEventData
operator|*
name|GetEventDataFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_sp
argument_list|)
block|;
name|private
operator|:
name|lldb
operator|::
name|BreakpointEventType
name|m_breakpoint_event
block|;
name|lldb
operator|::
name|BreakpointSP
name|m_new_breakpoint_sp
block|;
name|BreakpointLocationCollection
name|m_locations
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointEventData
argument_list|)
block|;   }
decl_stmt|;
name|class
name|BreakpointPrecondition
block|{
name|public
label|:
name|virtual
operator|~
name|BreakpointPrecondition
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|bool
name|EvaluatePrecondition
parameter_list|(
name|StoppointCallbackContext
modifier|&
name|context
parameter_list|)
function_decl|;
name|virtual
name|Error
name|ConfigurePrecondition
parameter_list|(
name|Args
modifier|&
name|options
parameter_list|)
function_decl|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|&
name|stream
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|BreakpointPrecondition
operator|>
name|BreakpointPreconditionSP
expr_stmt|;
comment|// Saving& restoring breakpoints:
specifier|static
name|lldb
operator|::
name|BreakpointSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|data_object_sp
argument_list|,
name|Error
operator|&
name|error
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|SerializedBreakpointMatchesNames
argument_list|(
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|bkpt_object_sp
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|names
argument_list|)
decl_stmt|;
name|virtual
name|StructuredData
operator|::
name|ObjectSP
name|SerializeToStructuredData
argument_list|()
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetSerializationKey
parameter_list|()
block|{
return|return
literal|"Breakpoint"
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is not virtual since there should be no reason to subclass
comment|/// breakpoints.  The varieties of breakpoints are specified instead by
comment|/// providing different resolvers& filters.
comment|//------------------------------------------------------------------
operator|~
name|Breakpoint
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Methods
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Tell whether this breakpoint is an "internal" breakpoint.
comment|/// @return
comment|///     Returns \b true if this is an internal breakpoint, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsInternal
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Standard "Dump" method.  At present it does nothing.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// The next set of methods provide ways to tell the breakpoint to update
comment|// it's location list - usually done when modules appear or disappear.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Tell this breakpoint to clear all its breakpoint sites.  Done
comment|/// when the process holding the breakpoint sites is destroyed.
comment|//------------------------------------------------------------------
name|void
name|ClearAllBreakpointSites
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tell this breakpoint to scan it's target's module list and resolve any
comment|/// new locations that match the breakpoint's specifications.
comment|//------------------------------------------------------------------
name|void
name|ResolveBreakpoint
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tell this breakpoint to scan a given module list and resolve any
comment|/// new locations that match the breakpoint's specifications.
comment|///
comment|/// @param[in] module_list
comment|///    The list of modules to look in for new locations.
comment|///
comment|/// @param[in]  send_event
comment|///     If \b true, send a breakpoint location added event for non-internal
comment|///     breakpoints.
comment|//------------------------------------------------------------------
name|void
name|ResolveBreakpointInModules
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|,
name|bool
name|send_event
init|=
name|true
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tell this breakpoint to scan a given module list and resolve any
comment|/// new locations that match the breakpoint's specifications.
comment|///
comment|/// @param[in] changed_modules
comment|///    The list of modules to look in for new locations.
comment|///
comment|/// @param[in]  new_locations
comment|///     Fills new_locations with the new locations that were made.
comment|//------------------------------------------------------------------
name|void
name|ResolveBreakpointInModules
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|,
name|BreakpointLocationCollection
modifier|&
name|new_locations
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Like ResolveBreakpointInModules, but allows for "unload" events, in
comment|/// which case we will remove any locations that are in modules that got
comment|/// unloaded.
comment|///
comment|/// @param[in] changedModules
comment|///    The list of modules to look in for new locations.
comment|/// @param[in] load_event
comment|///    If \b true then the modules were loaded, if \b false, unloaded.
comment|/// @param[in] delete_locations
comment|///    If \b true then the modules were unloaded delete any locations in the
comment|///    changed modules.
comment|//------------------------------------------------------------------
name|void
name|ModulesChanged
parameter_list|(
name|ModuleList
modifier|&
name|changed_modules
parameter_list|,
name|bool
name|load_event
parameter_list|,
name|bool
name|delete_locations
init|=
name|false
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tells the breakpoint the old module \a old_module_sp has been
comment|/// replaced by new_module_sp (usually because the underlying file has been
comment|/// rebuilt, and the old version is gone.)
comment|///
comment|/// @param[in] old_module_sp
comment|///    The old module that is going away.
comment|/// @param[in] new_module_sp
comment|///    The new module that is replacing it.
comment|//------------------------------------------------------------------
name|void
name|ModuleReplaced
argument_list|(
name|lldb
operator|::
name|ModuleSP
name|old_module_sp
argument_list|,
name|lldb
operator|::
name|ModuleSP
name|new_module_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// The next set of methods provide access to the breakpoint locations
comment|// for this breakpoint.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Add a location to the breakpoint's location list.  This is only meant
comment|/// to be called by the breakpoint's resolver.  FIXME: how do I ensure that?
comment|///
comment|/// @param[in] addr
comment|///    The Address specifying the new location.
comment|/// @param[out] new_location
comment|///    Set to \b true if a new location was created, to \b false if there
comment|///    already was a location at this Address.
comment|/// @return
comment|///    Returns a pointer to the new location.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|AddLocation
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|bool
operator|*
name|new_location
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a breakpoint location by Address.
comment|///
comment|/// @param[in] addr
comment|///    The Address specifying the location.
comment|/// @return
comment|///    Returns a shared pointer to the location at \a addr.  The pointer
comment|///    in the shared pointer will be nullptr if there is no location at that
comment|///    address.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|FindLocationByAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a breakpoint location ID by Address.
comment|///
comment|/// @param[in] addr
comment|///    The Address specifying the location.
comment|/// @return
comment|///    Returns the UID of the location at \a addr, or \b LLDB_INVALID_ID if
comment|///    there is no breakpoint location at that address.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|FindLocationIDByAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a breakpoint location for a given breakpoint location ID.
comment|///
comment|/// @param[in] bp_loc_id
comment|///    The ID specifying the location.
comment|/// @return
comment|///    Returns a shared pointer to the location with ID \a bp_loc_id.  The
comment|///    pointer
comment|///    in the shared pointer will be nullptr if there is no location with that
comment|///    ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|FindLocationByID
argument_list|(
argument|lldb::break_id_t bp_loc_id
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get breakpoint locations by index.
comment|///
comment|/// @param[in] index
comment|///    The location index.
comment|///
comment|/// @return
comment|///     Returns a shared pointer to the location with index \a
comment|///     index. The shared pointer might contain nullptr if \a index is
comment|///     greater than then number of actual locations.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|GetLocationAtIndex
argument_list|(
argument|size_t index
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes all invalid breakpoint locations.
comment|///
comment|/// Removes all breakpoint locations with architectures that aren't
comment|/// compatible with \a arch. Also remove any breakpoint locations
comment|/// with whose locations have address where the section has been
comment|/// deleted (module and object files no longer exist).
comment|///
comment|/// This is typically used after the process calls exec, or anytime
comment|/// the architecture of the target changes.
comment|///
comment|/// @param[in] arch
comment|///     If valid, check the module in each breakpoint to make sure
comment|///     they are compatible, otherwise, ignore architecture.
comment|//------------------------------------------------------------------
name|void
name|RemoveInvalidLocations
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// The next section deals with various breakpoint options.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// If \a enable is \b true, enable the breakpoint, if \b false disable it.
comment|//------------------------------------------------------------------
name|void
name|SetEnabled
argument_list|(
name|bool
name|enable
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check the Enable/Disable state.
comment|/// @return
comment|///     \b true if the breakpoint is enabled, \b false if disabled.
comment|//------------------------------------------------------------------
name|bool
name|IsEnabled
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint to ignore the next \a count breakpoint hits.
comment|/// @param[in] count
comment|///    The number of breakpoint hits to ignore.
comment|//------------------------------------------------------------------
name|void
name|SetIgnoreCount
parameter_list|(
name|uint32_t
name|count
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the current ignore count/
comment|/// @return
comment|///     The number of breakpoint hits to be ignored.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetIgnoreCount
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the current hit count for all locations.
comment|/// @return
comment|///     The current hit count for all locations.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetHitCount
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// If \a one_shot is \b true, breakpoint will be deleted on first hit.
comment|//------------------------------------------------------------------
name|void
name|SetOneShot
parameter_list|(
name|bool
name|one_shot
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check the OneShot state.
comment|/// @return
comment|///     \b true if the breakpoint is one shot, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsOneShot
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the valid thread to be checked when the breakpoint is hit.
comment|/// @param[in] thread_id
comment|///    If this thread hits the breakpoint, we stop, otherwise not.
comment|//------------------------------------------------------------------
name|void
name|SetThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the current stop thread value.
comment|/// @return
comment|///     The thread id for which the breakpoint hit will stop,
comment|///     LLDB_INVALID_THREAD_ID for all threads.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetThreadIndex
parameter_list|(
name|uint32_t
name|index
parameter_list|)
function_decl|;
name|uint32_t
name|GetThreadIndex
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetThreadName
parameter_list|(
specifier|const
name|char
modifier|*
name|thread_name
parameter_list|)
function_decl|;
specifier|const
name|char
operator|*
name|GetThreadName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetQueueName
parameter_list|(
specifier|const
name|char
modifier|*
name|queue_name
parameter_list|)
function_decl|;
specifier|const
name|char
operator|*
name|GetQueueName
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the callback action invoked when the breakpoint is hit.
comment|///
comment|/// @param[in] callback
comment|///    The method that will get called when the breakpoint is hit.
comment|/// @param[in] baton
comment|///    A void * pointer that will get passed back to the callback function.
comment|/// @param[in] is_synchronous
comment|///    If \b true the callback will be run on the private event thread
comment|///    before the stop event gets reported.  If false, the callback will get
comment|///    handled on the public event thread after the stop has been posted.
comment|///
comment|/// @return
comment|///    \b true if the process should stop when you hit the breakpoint.
comment|///    \b false if it should continue.
comment|//------------------------------------------------------------------
name|void
name|SetCallback
parameter_list|(
name|BreakpointHitCallback
name|callback
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|bool
name|is_synchronous
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|SetCallback
argument_list|(
name|BreakpointHitCallback
name|callback
argument_list|,
specifier|const
name|lldb
operator|::
name|BatonSP
operator|&
name|callback_baton_sp
argument_list|,
name|bool
name|is_synchronous
operator|=
name|false
argument_list|)
decl_stmt|;
name|void
name|ClearCallback
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint's condition.
comment|///
comment|/// @param[in] condition
comment|///    The condition expression to evaluate when the breakpoint is hit.
comment|///    Pass in nullptr to clear the condition.
comment|//------------------------------------------------------------------
name|void
name|SetCondition
parameter_list|(
specifier|const
name|char
modifier|*
name|condition
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return a pointer to the text of the condition expression.
comment|///
comment|/// @return
comment|///    A pointer to the condition expression text, or nullptr if no
comment|//     condition has been set.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetConditionText
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// The next section are various utility functions.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Return the number of breakpoint locations that have resolved to
comment|/// actual breakpoint sites.
comment|///
comment|/// @return
comment|///     The number locations resolved breakpoint sites.
comment|//------------------------------------------------------------------
name|size_t
name|GetNumResolvedLocations
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the number of breakpoint locations.
comment|///
comment|/// @return
comment|///     The number breakpoint locations.
comment|//------------------------------------------------------------------
name|size_t
name|GetNumLocations
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Put a description of this breakpoint into the stream \a s.
comment|///
comment|/// @param[in] s
comment|///     Stream into which to dump the description.
comment|///
comment|/// @param[in] level
comment|///     The description level that indicates the detail level to
comment|///     provide.
comment|///
comment|/// @see lldb::DescriptionLevel
comment|//------------------------------------------------------------------
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|bool
name|show_locations
operator|=
name|false
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the "kind" description for a breakpoint.  If the breakpoint is hit
comment|/// the stop info will show this "kind" description instead of the breakpoint
comment|/// number.  Mostly useful for internal breakpoints, where the breakpoint
comment|/// number
comment|/// doesn't have meaning to the user.
comment|///
comment|/// @param[in] kind
comment|///     New "kind" description.
comment|//------------------------------------------------------------------
name|void
name|SetBreakpointKind
parameter_list|(
specifier|const
name|char
modifier|*
name|kind
parameter_list|)
block|{
name|m_kind_description
operator|.
name|assign
argument_list|(
name|kind
argument_list|)
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the "kind" description for a breakpoint.
comment|///
comment|/// @return
comment|///     The breakpoint kind, or nullptr if none is set.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetBreakpointKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind_description
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Accessor for the breakpoint Target.
comment|/// @return
comment|///     This breakpoint's Target.
comment|//------------------------------------------------------------------
name|Target
modifier|&
name|GetTarget
parameter_list|()
block|{
return|return
name|m_target
return|;
block|}
specifier|const
name|Target
operator|&
name|GetTarget
argument_list|()
specifier|const
block|{
return|return
name|m_target
return|;
block|}
specifier|const
name|lldb
operator|::
name|TargetSP
name|GetTargetSP
argument_list|()
expr_stmt|;
name|void
name|GetResolverDescription
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find breakpoint locations which match the (filename, line_number)
comment|/// description.
comment|/// The breakpoint location collection is to be filled with the matching
comment|/// locations.
comment|/// It should be initialized with 0 size by the API client.
comment|///
comment|/// @return
comment|///     True if there is a match
comment|///
comment|///     The locations which match the filename and line_number in loc_coll.
comment|///     If its
comment|///     size is 0 and true is returned, it means the breakpoint fully matches
comment|///     the
comment|///     description.
comment|//------------------------------------------------------------------
name|bool
name|GetMatchingFileLine
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|filename
parameter_list|,
name|uint32_t
name|line_number
parameter_list|,
name|BreakpointLocationCollection
modifier|&
name|loc_coll
parameter_list|)
function_decl|;
name|void
name|GetFilterDescription
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the BreakpointOptions structure set at the breakpoint level.
comment|///
comment|/// Meant to be used by the BreakpointLocation class.
comment|///
comment|/// @return
comment|///     A pointer to this breakpoint's BreakpointOptions.
comment|//------------------------------------------------------------------
name|BreakpointOptions
modifier|*
name|GetOptions
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Invoke the callback action when the breakpoint is hit.
comment|///
comment|/// Meant to be used by the BreakpointLocation class.
comment|///
comment|/// @param[in] context
comment|///     Described the breakpoint event.
comment|///
comment|/// @param[in] bp_loc_id
comment|///     Which breakpoint location hit this breakpoint.
comment|///
comment|/// @return
comment|///     \b true if the target should stop at this breakpoint and \b false not.
comment|//------------------------------------------------------------------
name|bool
name|InvokeCallback
argument_list|(
name|StoppointCallbackContext
operator|*
name|context
argument_list|,
name|lldb
operator|::
name|break_id_t
name|bp_loc_id
argument_list|)
decl_stmt|;
name|bool
name|IsHardware
argument_list|()
specifier|const
block|{
return|return
name|m_hardware
return|;
block|}
name|lldb
operator|::
name|BreakpointResolverSP
name|GetResolver
argument_list|()
block|{
return|return
name|m_resolver_sp
return|;
block|}
name|lldb
operator|::
name|SearchFilterSP
name|GetSearchFilter
argument_list|()
block|{
return|return
name|m_filter_sp
return|;
block|}
name|bool
name|AddName
parameter_list|(
specifier|const
name|char
modifier|*
name|new_name
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|void
name|RemoveName
parameter_list|(
specifier|const
name|char
modifier|*
name|name_to_remove
parameter_list|)
block|{
if|if
condition|(
name|name_to_remove
condition|)
name|m_name_list
operator|.
name|erase
argument_list|(
name|name_to_remove
argument_list|)
expr_stmt|;
block|}
name|bool
name|MatchesName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|m_name_list
operator|.
name|find
argument_list|(
name|name
argument_list|)
operator|!=
name|m_name_list
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|GetNames
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|names
argument_list|)
block|{
name|names
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|auto
name|name
range|:
name|m_name_list
control|)
block|{
name|names
operator|.
name|push_back
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
block|}
comment|//------------------------------------------------------------------
comment|/// Set a pre-condition filter that overrides all user provided
comment|/// filters/callbacks etc.
comment|///
comment|/// Used to define fancy breakpoints that can do dynamic hit detection without
comment|/// taking up the condition slot -
comment|/// which really belongs to the user anyway...
comment|///
comment|/// The Precondition should not continue the target, it should return true if
comment|/// the condition says to stop and
comment|/// false otherwise.
comment|///
comment|//------------------------------------------------------------------
name|void
name|SetPrecondition
parameter_list|(
name|BreakpointPreconditionSP
name|precondition_sp
parameter_list|)
block|{
name|m_precondition_sp
operator|=
name|precondition_sp
expr_stmt|;
block|}
name|bool
name|EvaluatePrecondition
parameter_list|(
name|StoppointCallbackContext
modifier|&
name|context
parameter_list|)
function_decl|;
name|BreakpointPreconditionSP
name|GetPrecondition
parameter_list|()
block|{
return|return
name|m_precondition_sp
return|;
block|}
name|protected
label|:
name|friend
name|class
name|Target
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Protected Methods
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Constructors and Destructors
comment|/// Only the Target can make a breakpoint, and it owns the breakpoint
comment|/// lifespans.
comment|/// The constructor takes a filter and a resolver.  Up in Target there are
comment|/// convenience
comment|/// variants that make breakpoints for some common cases.
comment|///
comment|/// @param[in] target
comment|///    The target in which the breakpoint will be set.
comment|///
comment|/// @param[in] filter_sp
comment|///    Shared pointer to the search filter that restricts the search domain of
comment|///    the breakpoint.
comment|///
comment|/// @param[in] resolver_sp
comment|///    Shared pointer to the resolver object that will determine breakpoint
comment|///    matches.
comment|///
comment|/// @param hardware
comment|///    If true, request a hardware breakpoint to be used to implement the
comment|///    breakpoint locations.
comment|///
comment|/// @param resolve_indirect_symbols
comment|///    If true, and the address of a given breakpoint location in this
comment|///    breakpoint is set on an
comment|///    indirect symbol (i.e. Symbol::IsIndirect returns true) then the actual
comment|///    breakpoint site will
comment|///    be set on the target of the indirect symbol.
comment|//------------------------------------------------------------------
comment|// This is the generic constructor
name|Breakpoint
argument_list|(
argument|Target&target
argument_list|,
argument|lldb::SearchFilterSP&filter_sp
argument_list|,
argument|lldb::BreakpointResolverSP&resolver_sp
argument_list|,
argument|bool hardware
argument_list|,
argument|bool resolve_indirect_symbols = true
argument_list|)
empty_stmt|;
name|friend
name|class
name|BreakpointLocation
decl_stmt|;
comment|// To call the following two when determining
comment|// whether to stop.
name|void
name|DecrementIgnoreCount
parameter_list|()
function_decl|;
comment|// BreakpointLocation::IgnoreCountShouldStop&
comment|// Breakpoint::IgnoreCountShouldStop can only be called once per stop,
comment|// and BreakpointLocation::IgnoreCountShouldStop should be tested first, and
comment|// if it returns false we should
comment|// continue, otherwise we should test Breakpoint::IgnoreCountShouldStop.
name|bool
name|IgnoreCountShouldStop
parameter_list|()
function_decl|;
name|void
name|IncrementHitCount
parameter_list|()
block|{
name|m_hit_count
operator|++
expr_stmt|;
block|}
name|void
name|DecrementHitCount
parameter_list|()
block|{
name|assert
argument_list|(
name|m_hit_count
operator|>
literal|0
argument_list|)
expr_stmt|;
name|m_hit_count
operator|--
expr_stmt|;
block|}
name|private
label|:
comment|// This one should only be used by Target to copy breakpoints from target to
comment|// target - primarily from the dummy
comment|// target to prime new targets.
name|Breakpoint
argument_list|(
name|Target
operator|&
name|new_target
argument_list|,
name|Breakpoint
operator|&
name|bp_to_copy_from
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// For Breakpoint only
comment|//------------------------------------------------------------------
name|bool
name|m_being_created
decl_stmt|;
name|bool
name|m_hardware
decl_stmt|;
comment|// If this breakpoint is required to use a hardware breakpoint
name|Target
modifier|&
name|m_target
decl_stmt|;
comment|// The target that holds this breakpoint.
name|std
operator|::
name|unordered_set
operator|<
name|std
operator|::
name|string
operator|>
name|m_name_list
expr_stmt|;
comment|// If not empty, this is the name
comment|// of this breakpoint (many
comment|// breakpoints can share the same
comment|// name.)
name|lldb
operator|::
name|SearchFilterSP
name|m_filter_sp
expr_stmt|;
comment|// The filter that constrains the breakpoint's domain.
name|lldb
operator|::
name|BreakpointResolverSP
name|m_resolver_sp
expr_stmt|;
comment|// The resolver that defines this breakpoint.
name|BreakpointPreconditionSP
name|m_precondition_sp
decl_stmt|;
comment|// The precondition is a
comment|// breakpoint-level hit filter
comment|// that can be used
comment|// to skip certain breakpoint hits.  For instance, exception breakpoints
comment|// use this to limit the stop to certain exception classes, while leaving
comment|// the condition& callback free for user specification.
name|std
operator|::
name|unique_ptr
operator|<
name|BreakpointOptions
operator|>
name|m_options_up
expr_stmt|;
comment|// Settable breakpoint options
name|BreakpointLocationList
name|m_locations
decl_stmt|;
comment|// The list of locations currently found for this breakpoint.
name|std
operator|::
name|string
name|m_kind_description
expr_stmt|;
name|bool
name|m_resolve_indirect_symbols
decl_stmt|;
name|uint32_t
name|m_hit_count
decl_stmt|;
comment|// Number of times this breakpoint/watchpoint has been
comment|// hit.  This is kept
comment|// separately from the locations hit counts, since locations can go away when
comment|// their backing library gets unloaded, and we would lose hit counts.
name|void
name|SendBreakpointChangedEvent
argument_list|(
name|lldb
operator|::
name|BreakpointEventType
name|eventKind
argument_list|)
decl_stmt|;
name|void
name|SendBreakpointChangedEvent
parameter_list|(
name|BreakpointEventData
modifier|*
name|data
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Breakpoint
argument_list|)
expr_stmt|;
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
comment|// liblldb_Breakpoint_h_
end_comment

end_unit

