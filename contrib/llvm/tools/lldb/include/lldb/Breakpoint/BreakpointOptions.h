begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointOptions.h -------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointOptions_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointOptions_h_
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
file|"lldb/Core/StructuredData.h"
end_include

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
comment|/// @class BreakpointOptions BreakpointOptions.h
comment|/// "lldb/Breakpoint/BreakpointOptions.h"
comment|/// @brief Class that manages the options on a breakpoint or breakpoint
comment|/// location.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointOptions
block|{
name|public
label|:
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
name|interpreter
argument_list|(
name|lldb
operator|::
name|eScriptLanguageNone
argument_list|)
operator|,
name|stop_on_error
argument_list|(
argument|true
argument_list|)
block|{}
name|CommandData
argument_list|(
argument|const StringList&user_source
argument_list|,
argument|lldb::ScriptLanguage interp
argument_list|)
operator|:
name|user_source
argument_list|(
name|user_source
argument_list|)
operator|,
name|script_source
argument_list|()
operator|,
name|interpreter
argument_list|(
name|interp
argument_list|)
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
specifier|static
specifier|const
name|char
modifier|*
name|GetSerializationKey
parameter_list|()
block|{
return|return
literal|"BKPTCMDData"
return|;
block|}
name|StructuredData
operator|::
name|ObjectSP
name|SerializeToStructuredData
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|CommandData
operator|>
name|CreateFromStructuredData
argument_list|(
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|options_dict
argument_list|,
name|Status
operator|&
name|error
argument_list|)
expr_stmt|;
name|StringList
name|user_source
decl_stmt|;
name|std
operator|::
name|string
name|script_source
expr_stmt|;
block|enum
name|lldb
operator|::
name|ScriptLanguage
name|interpreter
expr_stmt|;
comment|// eScriptLanguageNone means command interpreter.
name|bool
name|stop_on_error
decl_stmt|;
name|private
label|:
name|enum
name|class
name|OptionNames
range|:
name|uint32_t
block|{
name|UserSource
operator|=
literal|0
block|,
name|Interpreter
block|,
name|StopOnError
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
name|explicit
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
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|CommandBaton
operator|>
name|CommandBatonSP
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Default constructor.  The breakpoint is enabled, and has no condition,
comment|/// callback, ignore count, etc...
comment|//------------------------------------------------------------------
name|BreakpointOptions
argument_list|()
expr_stmt|;
name|BreakpointOptions
argument_list|(
specifier|const
name|BreakpointOptions
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|static
name|BreakpointOptions
modifier|*
name|CopyOptionsNoCallback
parameter_list|(
name|BreakpointOptions
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This constructor allows you to specify all the breakpoint options
comment|/// except the callback.  That one is more complicated, and better
comment|/// to do by hand.
comment|///
comment|/// @param[in] condition
comment|///    The expression which if it evaluates to \b true if we are to stop
comment|///
comment|/// @param[in] enabled
comment|///    Is this breakpoint enabled.
comment|///
comment|/// @param[in] ignore
comment|///    How many breakpoint hits we should ignore before stopping.
comment|///
comment|//------------------------------------------------------------------
name|BreakpointOptions
argument_list|(
argument|const char *condition
argument_list|,
argument|bool enabled = true
argument_list|,
argument|int32_t ignore =
literal|0
argument_list|,
argument|bool one_shot = false
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|BreakpointOptions
argument_list|()
expr_stmt|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|BreakpointOptions
operator|>
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
argument_list|,
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|data_dict
argument_list|,
name|Status
operator|&
name|error
argument_list|)
expr_stmt|;
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
literal|"BKPTOptions"
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|BreakpointOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|BreakpointOptions
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Callbacks
comment|//
comment|// Breakpoint callbacks come in two forms, synchronous and asynchronous.
comment|// Synchronous callbacks will get
comment|// run before any of the thread plans are consulted, and if they return false
comment|// the target will continue
comment|// "under the radar" of the thread plans.  There are a couple of restrictions
comment|// to synchronous callbacks:
comment|// 1) They should NOT resume the target themselves.  Just return false if you
comment|// want the target to restart.
comment|// 2) Breakpoints with synchronous callbacks can't have conditions (or rather,
comment|// they can have them, but they
comment|//    won't do anything.  Ditto with ignore counts, etc...  You are supposed
comment|//    to control that all through the
comment|//    callback.
comment|// Asynchronous callbacks get run as part of the "ShouldStop" logic in the
comment|// thread plan.  The logic there is:
comment|//   a) If the breakpoint is thread specific and not for this thread, continue
comment|//   w/o running the callback.
comment|//      NB. This is actually enforced underneath the breakpoint system, the
comment|//      Process plugin is expected to
comment|//      call BreakpointSite::IsValidForThread, and set the thread's StopInfo
comment|//      to "no reason".  That way,
comment|//      thread displays won't show stops for breakpoints not for that
comment|//      thread...
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
comment|/// Adds a callback to the breakpoint option set.
comment|///
comment|/// @param[in] callback
comment|///    The function to be called when the breakpoint gets hit.
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
name|BreakpointHitCallback
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
name|void
name|SetCallback
argument_list|(
name|BreakpointHitCallback
name|callback
argument_list|,
specifier|const
name|BreakpointOptions
operator|::
name|CommandBatonSP
operator|&
name|command_baton_sp
argument_list|,
name|bool
name|synchronous
operator|=
name|false
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the command line commands for the callback on this breakpoint.
comment|///
comment|/// @param[out] command_list
comment|///    The commands will be appended to this list.
comment|///
comment|/// @return
comment|///    \btrue if the command callback is a command-line callback,
comment|///    \bfalse otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetCommandLineCallbacks
parameter_list|(
name|StringList
modifier|&
name|command_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Remove the callback from this option set.
comment|//------------------------------------------------------------------
name|void
name|ClearCallback
parameter_list|()
function_decl|;
comment|// The rest of these functions are meant to be used only within the breakpoint
comment|// handling mechanism.
comment|//------------------------------------------------------------------
comment|/// Use this function to invoke the callback for a specific stop.
comment|///
comment|/// @param[in] context
comment|///    The context in which the callback is to be invoked.  This includes the
comment|///    stop event, the
comment|///    execution context of the stop (since you might hit the same breakpoint
comment|///    on multiple threads) and
comment|///    whether we are currently executing synchronous or asynchronous
comment|///    callbacks.
comment|///
comment|/// @param[in] break_id
comment|///    The breakpoint ID that owns this option set.
comment|///
comment|/// @param[in] break_loc_id
comment|///    The breakpoint location ID that owns this option set.
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
name|break_id
argument_list|,
name|lldb
operator|::
name|user_id_t
name|break_loc_id
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
argument_list|()
specifier|const
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
comment|// Condition
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint option's condition.
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
comment|//------------------------------------------------------------------
comment|// Enabled/Ignore Count
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Check the Enable/Disable state.
comment|/// @return
comment|///     \b true if the breakpoint is enabled, \b false if disabled.
comment|//------------------------------------------------------------------
name|bool
name|IsEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// If \a enable is \b true, enable the breakpoint, if \b false disable it.
comment|//------------------------------------------------------------------
name|void
name|SetEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|m_enabled
operator|=
name|enabled
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Check the One-shot state.
comment|/// @return
comment|///     \b true if the breakpoint is one-shot, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsOneShot
argument_list|()
specifier|const
block|{
return|return
name|m_one_shot
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// If \a enable is \b true, enable the breakpoint, if \b false disable it.
comment|//------------------------------------------------------------------
name|void
name|SetOneShot
parameter_list|(
name|bool
name|one_shot
parameter_list|)
block|{
name|m_one_shot
operator|=
name|one_shot
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the breakpoint to ignore the next \a count breakpoint hits.
comment|/// @param[in] count
comment|///    The number of breakpoint hits to ignore.
comment|//------------------------------------------------------------------
name|void
name|SetIgnoreCount
parameter_list|(
name|uint32_t
name|n
parameter_list|)
block|{
name|m_ignore_count
operator|=
name|n
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the current Ignore Count.
comment|/// @return
comment|///     The number of breakpoint hits to be ignored.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetIgnoreCount
argument_list|()
specifier|const
block|{
return|return
name|m_ignore_count
return|;
block|}
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
comment|/// Returns true if the breakpoint option has a callback set.
comment|//------------------------------------------------------------------
name|bool
name|HasCallback
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// This is the default empty callback.
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
name|break_id
argument_list|,
name|lldb
operator|::
name|user_id_t
name|break_loc_id
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set a callback based on BreakpointOptions::CommandData.
comment|/// @param[in] cmd_data
comment|///     A UP holding the new'ed CommandData object.
comment|///     The breakpoint will take ownership of pointer held by this object.
comment|//------------------------------------------------------------------
name|void
name|SetCommandDataCallback
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|CommandData
operator|>
operator|&
name|cmd_data
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from BreakpointOptions can see and modify these
comment|//------------------------------------------------------------------
name|enum
name|class
name|OptionNames
block|{
name|ConditionText
operator|=
literal|0
operator|,
name|IgnoreCount
operator|,
name|EnabledState
operator|,
name|OneShotState
operator|,
name|LastOptionName
block|}
empty_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_option_names
index|[
operator|(
name|size_t
operator|)
name|OptionNames
operator|::
name|LastOptionName
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
operator|(
name|size_t
operator|)
name|enum_value
index|]
return|;
block|}
specifier|static
name|bool
name|BreakpointOptionsCallbackFunction
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
name|break_id
argument_list|,
name|lldb
operator|::
name|user_id_t
name|break_loc_id
argument_list|)
decl_stmt|;
name|void
name|SetThreadSpec
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ThreadSpec
operator|>
operator|&
name|thread_spec_up
argument_list|)
decl_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For BreakpointOptions only
comment|//------------------------------------------------------------------
name|BreakpointHitCallback
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
name|m_baton_is_command_baton
decl_stmt|;
name|bool
name|m_callback_is_synchronous
decl_stmt|;
name|bool
name|m_enabled
decl_stmt|;
name|bool
name|m_one_shot
decl_stmt|;
name|uint32_t
name|m_ignore_count
decl_stmt|;
comment|// Number of times to ignore this breakpoint
name|std
operator|::
name|unique_ptr
operator|<
name|ThreadSpec
operator|>
name|m_thread_spec_ap
expr_stmt|;
comment|// Thread for which this breakpoint will take
name|std
operator|::
name|string
name|m_condition_text
expr_stmt|;
comment|// The condition to test.
name|size_t
name|m_condition_text_hash
decl_stmt|;
comment|// Its hash, so that locations know when the
comment|// condition is updated.
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
comment|// liblldb_BreakpointOptions_h_
end_comment

end_unit

