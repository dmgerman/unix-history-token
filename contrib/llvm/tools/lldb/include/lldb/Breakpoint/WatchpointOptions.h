begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WatchpointOptions.h -------------------------------------*- C++ -*-===//
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
name|liblldb_WatchpointOptions_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_WatchpointOptions_h_
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
file|"lldb/Utility/Baton.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StringList.h"
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
comment|/// @class WatchpointOptions WatchpointOptions.h
comment|/// "lldb/Breakpoint/WatchpointOptions.h"
comment|/// @brief Class that manages the options on a watchpoint.
comment|//----------------------------------------------------------------------
name|class
name|WatchpointOptions
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Default constructor.  The watchpoint is enabled, and has no condition,
comment|/// callback, ignore count, etc...
comment|//------------------------------------------------------------------
name|WatchpointOptions
argument_list|()
expr_stmt|;
name|WatchpointOptions
argument_list|(
specifier|const
name|WatchpointOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|static
name|WatchpointOptions
modifier|*
name|CopyOptionsNoCallback
parameter_list|(
name|WatchpointOptions
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This constructor allows you to specify all the watchpoint options.
comment|///
comment|/// @param[in] callback
comment|///    This is the plugin for some code that gets run, returns \b true if we
comment|///    are to stop.
comment|///
comment|/// @param[in] baton
comment|///    Client data that will get passed to the callback.
comment|///
comment|/// @param[in] thread_id
comment|///    Only stop if \a thread_id hits the watchpoint.
comment|//------------------------------------------------------------------
name|WatchpointOptions
argument_list|(
argument|WatchpointHitCallback callback
argument_list|,
argument|void *baton
argument_list|,
argument|lldb::tid_t thread_id = LLDB_INVALID_THREAD_ID
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|WatchpointOptions
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|WatchpointOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|WatchpointOptions
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Callbacks
comment|//
comment|// Watchpoint callbacks come in two forms, synchronous and asynchronous.
comment|// Synchronous callbacks will get
comment|// run before any of the thread plans are consulted, and if they return false
comment|// the target will continue
comment|// "under the radar" of the thread plans.  There are a couple of restrictions
comment|// to synchronous callbacks:
comment|// 1) They should NOT resume the target themselves.  Just return false if you
comment|// want the target to restart.
comment|// 2) Watchpoints with synchronous callbacks can't have conditions (or rather,
comment|// they can have them, but they
comment|//    won't do anything.  Ditto with ignore counts, etc...  You are supposed
comment|//    to control that all through the
comment|//    callback.
comment|// Asynchronous callbacks get run as part of the "ShouldStop" logic in the
comment|// thread plan.  The logic there is:
comment|//   a) If the watchpoint is thread specific and not for this thread, continue
comment|//   w/o running the callback.
comment|//   b) If the ignore count says we shouldn't stop, then ditto.
comment|//   c) If the condition says we shouldn't stop, then ditto.
comment|//   d) Otherwise, the callback will get run, and if it returns true we will
comment|//   stop, and if false we won't.
comment|//  The asynchronous callback can run the target itself, but at present that
comment|//  should be the last action the
comment|//  callback does.  We will relax this condition at some point, but it will
comment|//  take a bit of plumbing to get
comment|//  that to work.
comment|//
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Adds a callback to the watchpoint option set.
comment|///
comment|/// @param[in] callback
comment|///    The function to be called when the watchpoint gets hit.
comment|///
comment|/// @param[in] baton_sp
comment|///    A baton which will get passed back to the callback when it is invoked.
comment|///
comment|/// @param[in] synchronous
comment|///    Whether this is a synchronous or asynchronous callback.  See discussion
comment|///    above.
comment|//------------------------------------------------------------------
name|void
name|SetCallback
argument_list|(
name|WatchpointHitCallback
name|callback
argument_list|,
specifier|const
name|lldb
operator|::
name|BatonSP
operator|&
name|baton_sp
argument_list|,
name|bool
name|synchronous
operator|=
name|false
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Remove the callback from this option set.
comment|//------------------------------------------------------------------
name|void
name|ClearCallback
parameter_list|()
function_decl|;
comment|// The rest of these functions are meant to be used only within the watchpoint
comment|// handling mechanism.
comment|//------------------------------------------------------------------
comment|/// Use this function to invoke the callback for a specific stop.
comment|///
comment|/// @param[in] context
comment|///    The context in which the callback is to be invoked.  This includes the
comment|///    stop event, the
comment|///    execution context of the stop (since you might hit the same watchpoint
comment|///    on multiple threads) and
comment|///    whether we are currently executing synchronous or asynchronous
comment|///    callbacks.
comment|///
comment|/// @param[in] watch_id
comment|///    The watchpoint ID that owns this option set.
comment|///
comment|/// @return
comment|///     The callback return value.
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
name|user_id_t
name|watch_id
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Used in InvokeCallback to tell whether it is the right time to run this
comment|/// kind of callback.
comment|///
comment|/// @return
comment|///     The synchronicity of our callback.
comment|//------------------------------------------------------------------
name|bool
name|IsCallbackSynchronous
parameter_list|()
block|{
return|return
name|m_callback_is_synchronous
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Fetch the baton from the callback.
comment|///
comment|/// @return
comment|///     The baton.
comment|//------------------------------------------------------------------
name|Baton
modifier|*
name|GetBaton
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Fetch  a const version of the baton from the callback.
comment|///
comment|/// @return
comment|///     The baton.
comment|//------------------------------------------------------------------
specifier|const
name|Baton
operator|*
name|GetBaton
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the current thread spec for this option. This will return nullptr
comment|/// if the no thread
comment|/// specifications have been set for this Option yet.
comment|/// @return
comment|///     The thread specification pointer for this option, or nullptr if none
comment|///     has
comment|///     been set yet.
comment|//------------------------------------------------------------------
specifier|const
name|ThreadSpec
operator|*
name|GetThreadSpecNoCreate
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a pointer to the ThreadSpec for this option, creating it.
comment|/// if it hasn't been created already.   This API is used for setting the
comment|/// ThreadSpec items for this option.
comment|//------------------------------------------------------------------
name|ThreadSpec
modifier|*
name|GetThreadSpec
parameter_list|()
function_decl|;
name|void
name|SetThreadID
argument_list|(
name|lldb
operator|::
name|tid_t
name|thread_id
argument_list|)
decl_stmt|;
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
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get description for callback only.
comment|//------------------------------------------------------------------
name|void
name|GetCallbackDescription
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
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true if the watchpoint option has a callback set.
comment|//------------------------------------------------------------------
name|bool
name|HasCallback
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This is the default empty callback.
comment|/// @return
comment|///     The thread id for which the watchpoint hit will stop,
comment|///     LLDB_INVALID_THREAD_ID for all threads.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|NullCallback
argument_list|(
name|void
operator|*
name|baton
argument_list|,
name|StoppointCallbackContext
operator|*
name|context
argument_list|,
name|lldb
operator|::
name|user_id_t
name|watch_id
argument_list|)
decl_stmt|;
struct|struct
name|CommandData
block|{
name|CommandData
argument_list|()
operator|:
name|user_source
argument_list|()
operator|,
name|script_source
argument_list|()
operator|,
name|stop_on_error
argument_list|(
argument|true
argument_list|)
block|{}
operator|~
name|CommandData
argument_list|()
operator|=
expr|default
expr_stmt|;
name|StringList
name|user_source
decl_stmt|;
name|std
operator|::
name|string
name|script_source
expr_stmt|;
name|bool
name|stop_on_error
decl_stmt|;
block|}
struct|;
name|class
name|CommandBaton
range|:
name|public
name|TypedBaton
operator|<
name|CommandData
operator|>
block|{
name|public
operator|:
name|CommandBaton
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|CommandData
operator|>
name|Data
argument_list|)
operator|:
name|TypedBaton
argument_list|(
argument|std::move(Data)
argument_list|)
block|{}
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
specifier|const
name|override
block|;   }
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from WatchpointOptions can see and modify these
comment|//------------------------------------------------------------------
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For WatchpointOptions only
comment|//------------------------------------------------------------------
name|WatchpointHitCallback
name|m_callback
decl_stmt|;
comment|// This is the callback function pointer
name|lldb
operator|::
name|BatonSP
name|m_callback_baton_sp
expr_stmt|;
comment|// This is the client data for the callback
name|bool
name|m_callback_is_synchronous
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ThreadSpec
operator|>
name|m_thread_spec_ap
expr_stmt|;
comment|// Thread for which this watchpoint will take
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
comment|// liblldb_WatchpointOptions_h_
end_comment

end_unit

