begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointLocation.h ------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointLocation_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointLocation_h_
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
file|<mutex>
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
file|"lldb/Breakpoint/StoppointLocation.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointLocation BreakpointLocation.h
comment|/// "lldb/Breakpoint/BreakpointLocation.h"
comment|/// @brief Class that manages one unique (by address) instance of a logical
comment|/// breakpoint.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// A breakpoint location is defined by the breakpoint that produces it,
comment|/// and the address that resulted in this particular instantiation.
comment|/// Each breakpoint location also may have a breakpoint site if its
comment|/// address has been loaded into the program.
comment|/// Finally it has a settable options object.
comment|///
comment|/// FIXME: Should we also store some fingerprint for the location, so
comment|/// we can map one location to the "equivalent location" on rerun?  This
comment|/// would be useful if you've set options on the locations.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointLocation
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|BreakpointLocation
operator|>
decl_stmt|,
name|public
name|StoppointLocation
block|{
name|public
label|:
operator|~
name|BreakpointLocation
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the load address for this breakpoint location
comment|/// @return
comment|///     Returns breakpoint location load address, \b
comment|///     LLDB_INVALID_ADDRESS if not yet set.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the Address for this breakpoint location
comment|/// @return
comment|///     Returns breakpoint location Address.
comment|//------------------------------------------------------------------
name|Address
modifier|&
name|GetAddress
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the Breakpoint that created this breakpoint location
comment|/// @return
comment|///     Returns the owning breakpoint.
comment|//------------------------------------------------------------------
name|Breakpoint
modifier|&
name|GetBreakpoint
parameter_list|()
function_decl|;
name|Target
modifier|&
name|GetTarget
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Determines whether we should stop due to a hit at this
comment|/// breakpoint location.
comment|///
comment|/// Side Effects: This may evaluate the breakpoint condition, and
comment|/// run the callback.  So this command may do a considerable amount
comment|/// of work.
comment|///
comment|/// @return
comment|///     \b true if this breakpoint location thinks we should stop,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ShouldStop
argument_list|(
name|StoppointCallbackContext
operator|*
name|context
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// The next section deals with various breakpoint options.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// If \a enable is \b true, enable the breakpoint, if \b false
comment|/// disable it.
comment|//------------------------------------------------------------------
name|void
name|SetEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check the Enable/Disable state.
comment|///
comment|/// @return
comment|///     \b true if the breakpoint is enabled, \b false if disabled.
comment|//------------------------------------------------------------------
name|bool
name|IsEnabled
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the current Ignore Count.
comment|///
comment|/// @return
comment|///     The number of breakpoint hits to be ignored.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetIgnoreCount
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint to ignore the next \a count breakpoint hits.
comment|///
comment|/// @param[in] count
comment|///    The number of breakpoint hits to ignore.
comment|//------------------------------------------------------------------
name|void
name|SetIgnoreCount
parameter_list|(
name|uint32_t
name|n
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the callback action invoked when the breakpoint is hit.
comment|///
comment|/// The callback will return a bool indicating whether the target
comment|/// should stop at this breakpoint or not.
comment|///
comment|/// @param[in] callback
comment|///     The method that will get called when the breakpoint is hit.
comment|///
comment|/// @param[in] callback_baton_sp
comment|///     A shared pointer to a Baton that provides the void * needed
comment|///     for the callback.
comment|///
comment|/// @see lldb_private::Baton
comment|//------------------------------------------------------------------
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
argument_list|)
decl_stmt|;
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
parameter_list|)
function_decl|;
name|void
name|ClearCallback
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint location's condition.
comment|///
comment|/// @param[in] condition
comment|///    The condition expression to evaluate when the breakpoint is hit.
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
modifier|*
name|GetConditionText
argument_list|(
name|size_t
operator|*
name|hash
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ConditionSaysStop
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the valid thread to be checked when the breakpoint is hit.
comment|///
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
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
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
comment|// The next section deals with this location's breakpoint sites.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Try to resolve the breakpoint site for this location.
comment|///
comment|/// @return
comment|///     \b true if we were successful at setting a breakpoint site,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ResolveBreakpointSite
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Clear this breakpoint location's breakpoint site - for instance
comment|/// when disabling the breakpoint.
comment|///
comment|/// @return
comment|///     \b true if there was a breakpoint site to be cleared, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ClearBreakpointSite
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return whether this breakpoint location has a breakpoint site.
comment|/// @return
comment|///     \b true if there was a breakpoint site for this breakpoint
comment|///     location, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsResolved
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|BreakpointSiteSP
name|GetBreakpointSite
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// The next section are generic report functions.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Print a description of this breakpoint location to the stream
comment|/// \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to print the description.
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
argument_list|)
decl_stmt|;
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
decl|const
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Use this to set location specific breakpoint options.
comment|///
comment|/// It will create a copy of the containing breakpoint's options if
comment|/// that hasn't been done already
comment|///
comment|/// @return
comment|///    A pointer to the breakpoint options.
comment|//------------------------------------------------------------------
name|BreakpointOptions
modifier|*
name|GetLocationOptions
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Use this to access breakpoint options from this breakpoint location.
comment|/// This will point to the owning breakpoint's options unless options have
comment|/// been set specifically on this location.
comment|///
comment|/// @return
comment|///     A pointer to the containing breakpoint's options if this
comment|///     location doesn't have its own copy.
comment|//------------------------------------------------------------------
specifier|const
name|BreakpointOptions
operator|*
name|GetOptionsNoCreate
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|ValidForThisThread
parameter_list|(
name|Thread
modifier|*
name|thread
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Invoke the callback action when the breakpoint is hit.
comment|///
comment|/// Meant to be used by the BreakpointLocation class.
comment|///
comment|/// @param[in] context
comment|///    Described the breakpoint event.
comment|///
comment|/// @param[in] bp_loc_id
comment|///    Which breakpoint location hit this breakpoint.
comment|///
comment|/// @return
comment|///     \b true if the target should stop at this breakpoint and \b
comment|///     false not.
comment|//------------------------------------------------------------------
name|bool
name|InvokeCallback
parameter_list|(
name|StoppointCallbackContext
modifier|*
name|context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns whether we should resolve Indirect functions in setting the
comment|/// breakpoint site
comment|/// for this location.
comment|///
comment|/// @return
comment|///     \b true if the breakpoint SITE for this location should be set on the
comment|///     resolved location for Indirect functions.
comment|//------------------------------------------------------------------
name|bool
name|ShouldResolveIndirectFunctions
parameter_list|()
block|{
return|return
name|m_should_resolve_indirect_functions
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns whether the address set in the breakpoint site for this location
comment|/// was found by resolving
comment|/// an indirect symbol.
comment|///
comment|/// @return
comment|///     \b true or \b false as given in the description above.
comment|//------------------------------------------------------------------
name|bool
name|IsIndirect
parameter_list|()
block|{
return|return
name|m_is_indirect
return|;
block|}
name|void
name|SetIsIndirect
parameter_list|(
name|bool
name|is_indirect
parameter_list|)
block|{
name|m_is_indirect
operator|=
name|is_indirect
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns whether the address set in the breakpoint location was re-routed
comment|/// to the target of a
comment|/// re-exported symbol.
comment|///
comment|/// @return
comment|///     \b true or \b false as given in the description above.
comment|//------------------------------------------------------------------
name|bool
name|IsReExported
parameter_list|()
block|{
return|return
name|m_is_reexported
return|;
block|}
name|void
name|SetIsReExported
parameter_list|(
name|bool
name|is_reexported
parameter_list|)
block|{
name|m_is_reexported
operator|=
name|is_reexported
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns whether the two breakpoint locations might represent "equivalent
comment|/// locations".
comment|/// This is used when modules changed to determine if a Location in the old
comment|/// module might
comment|/// be the "same as" the input location.
comment|///
comment|/// @param[in] location
comment|///    The location to compare against.
comment|///
comment|/// @return
comment|///     \b true or \b false as given in the description above.
comment|//------------------------------------------------------------------
name|bool
name|EquivalentToLocation
parameter_list|(
name|BreakpointLocation
modifier|&
name|location
parameter_list|)
function_decl|;
name|protected
label|:
name|friend
name|class
name|BreakpointSite
decl_stmt|;
name|friend
name|class
name|BreakpointLocationList
decl_stmt|;
name|friend
name|class
name|Process
decl_stmt|;
name|friend
name|class
name|StopInfoBreakpoint
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint site for this location to \a bp_site_sp.
comment|///
comment|/// @param[in] bp_site_sp
comment|///      The breakpoint site we are setting for this location.
comment|///
comment|/// @return
comment|///     \b true if we were successful at setting the breakpoint site,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|SetBreakpointSite
argument_list|(
name|lldb
operator|::
name|BreakpointSiteSP
operator|&
name|bp_site_sp
argument_list|)
decl_stmt|;
name|void
name|DecrementIgnoreCount
parameter_list|()
function_decl|;
name|bool
name|IgnoreCountShouldStop
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|SwapLocation
argument_list|(
name|lldb
operator|::
name|BreakpointLocationSP
name|swap_from
argument_list|)
decl_stmt|;
name|void
name|BumpHitCount
parameter_list|()
function_decl|;
name|void
name|UndoBumpHitCount
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//
comment|// Only the Breakpoint can make breakpoint locations, and it owns
comment|// them.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Constructor.
comment|///
comment|/// @param[in] owner
comment|///     A back pointer to the breakpoint that owns this location.
comment|///
comment|/// @param[in] addr
comment|///     The Address defining this location.
comment|///
comment|/// @param[in] tid
comment|///     The thread for which this breakpoint location is valid, or
comment|///     LLDB_INVALID_THREAD_ID if it is valid for all threads.
comment|///
comment|/// @param[in] hardware
comment|///     \b true if a hardware breakpoint is requested.
comment|//------------------------------------------------------------------
name|BreakpointLocation
argument_list|(
argument|lldb::break_id_t bid
argument_list|,
argument|Breakpoint&owner
argument_list|,
argument|const Address&addr
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|bool hardware
argument_list|,
argument|bool check_for_resolver = true
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|// Data members:
comment|//------------------------------------------------------------------
name|bool
name|m_being_created
decl_stmt|;
name|bool
name|m_should_resolve_indirect_functions
decl_stmt|;
name|bool
name|m_is_reexported
decl_stmt|;
name|bool
name|m_is_indirect
decl_stmt|;
name|Address
name|m_address
decl_stmt|;
comment|///< The address defining this location.
name|Breakpoint
modifier|&
name|m_owner
decl_stmt|;
comment|///< The breakpoint that produced this object.
name|std
operator|::
name|unique_ptr
operator|<
name|BreakpointOptions
operator|>
name|m_options_ap
expr_stmt|;
comment|///< Breakpoint options
comment|///pointer, nullptr if we're
comment|///using our breakpoint's
comment|///options.
name|lldb
operator|::
name|BreakpointSiteSP
name|m_bp_site_sp
expr_stmt|;
comment|///< Our breakpoint site (it may be
comment|///shared by more than one location.)
name|lldb
operator|::
name|UserExpressionSP
name|m_user_expression_sp
expr_stmt|;
comment|///< The compiled expression to
comment|///use in testing our condition.
name|std
operator|::
name|mutex
name|m_condition_mutex
expr_stmt|;
comment|///< Guards parsing and evaluation of the
comment|///condition, which could be evaluated by
comment|/// multiple processes.
name|size_t
name|m_condition_hash
decl_stmt|;
comment|///< For testing whether the condition source code
comment|///changed.
name|void
name|SetShouldResolveIndirectFunctions
parameter_list|(
name|bool
name|do_resolve
parameter_list|)
block|{
name|m_should_resolve_indirect_functions
operator|=
name|do_resolve
expr_stmt|;
block|}
name|void
name|SendBreakpointLocationChangedEvent
argument_list|(
name|lldb
operator|::
name|BreakpointEventType
name|eventKind
argument_list|)
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointLocation
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
comment|// liblldb_BreakpointLocation_h_
end_comment

end_unit

