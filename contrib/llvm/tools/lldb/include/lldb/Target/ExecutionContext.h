begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExecutionContext.h --------------------------------------*- C++ -*-===//
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

begin_comment
comment|/// Execution context objects refer to objects in the execution of the
end_comment

begin_comment
comment|/// program that is being debugged. The consist of one or more of the
end_comment

begin_comment
comment|/// following objects: target, process, thread, and frame. Many objects
end_comment

begin_comment
comment|/// in the debugger need to track different executions contexts. For
end_comment

begin_comment
comment|/// example, a local function variable might have an execution context
end_comment

begin_comment
comment|/// that refers to a stack frame. A global or static variable might
end_comment

begin_comment
comment|/// refer to a target since a stack frame isn't required in order to
end_comment

begin_comment
comment|/// evaluate a global or static variable (a process isn't necessarily
end_comment

begin_comment
comment|/// needed for a global variable since we might be able to read the
end_comment

begin_comment
comment|/// variable value from a data section in one of the object files in
end_comment

begin_comment
comment|/// a target). There are two types of objects that hold onto execution
end_comment

begin_comment
comment|/// contexts: ExecutionContextRef and ExecutionContext. Both of these
end_comment

begin_comment
comment|/// objects are deascribed below.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Not all objects in an ExectionContext objects will be valid. If you want
end_comment

begin_comment
comment|/// to refer stronly (ExectionContext) or weakly (ExectionContextRef) to
end_comment

begin_comment
comment|/// a process, then only the process and target references will be valid.
end_comment

begin_comment
comment|/// For threads, only the thread, process and target references will be
end_comment

begin_comment
comment|/// filled in. For frames, all of the objects will be filled in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These classes are designed to be used as baton objects that get passed
end_comment

begin_comment
comment|/// to a wide variety of functions that require execution contexts.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ExecutionContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ExecutionContext_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ExecutionContextRef ExecutionContext.h "lldb/Target/ExecutionContext.h"
comment|/// @brief A class that holds a weak reference to an execution context.
comment|///
comment|/// ExecutionContextRef objects are designed to hold onto an execution
comment|/// context that might change over time. For example, if an object wants
comment|/// to refer to a stack frame, it should hold onto an ExecutionContextRef
comment|/// to a frame object. The backing object that represents the stack frame
comment|/// might change over time and instaces of this object can track the logical
comment|/// object that refers to a frame even if it does change.
comment|///
comment|/// These objects also don't keep execution objects around longer than they
comment|/// should since they use weak pointers. For example if an object refers
comment|/// to a stack frame and a stack frame is no longer in a thread, then a
comment|/// ExecutionContextRef object that refers to that frame will not be able
comment|/// to get a shared pointer to those objects since they are no longer around.
comment|///
comment|/// ExecutionContextRef objects can also be used as objects in classes
comment|/// that want to track a "previous execution context". Since the weak
comment|/// references to the execution objects (target, process, thread and frame)
comment|/// don't keep these objects around, they are safe to keep around.
comment|///
comment|/// The general rule of thumb is all long lived objects that want to
comment|/// refer to execution contexts should use ExecutionContextRef objcts.
comment|/// The ExecutionContext class is used to temporarily get shared
comment|/// pointers to any execution context objects that are still around
comment|/// so they are guaranteed to exist during a function that requires the
comment|/// objects. ExecutionContext objects should NOT be used for long term
comment|/// storage since they will keep objects alive with extra shared pointer
comment|/// references to these  objects.
comment|//----------------------------------------------------------------------
name|class
name|ExecutionContextRef
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default Constructor.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy Constructor.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
specifier|const
name|ExecutionContextRef
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct using an ExecutionContext object that might be NULL.
comment|///
comment|/// If \a exe_ctx_ptr is valid, then make weak references to any
comment|/// valid objects in the ExecutionContext, othewise no weak
comment|/// references to any execution context objects will be made.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
specifier|const
name|ExecutionContext
operator|*
name|exe_ctx_ptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct using an ExecutionContext object.
comment|///
comment|/// Make weak references to any valid objects in the ExecutionContext.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
specifier|const
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator
comment|///
comment|/// Copy all weak refernces in \a rhs.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ExecutionContextRef
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator from a ExecutionContext
comment|///
comment|/// Make weak refernces to any stringly referenced objects in \a exe_ctx.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ExecutionContext
operator|&
name|exe_ctx
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct using the target and all the selected items inside of it
comment|/// (the process and its selected thread, and the thread's selected
comment|/// frame). If there is no selected thread, default to the first thread
comment|/// If there is no selected frame, default to the first frame.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
argument|Target *target
argument_list|,
argument|bool adopt_selected
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct using an execution context scope.
comment|///
comment|/// If the ExecutionContextScope object is valid and refers to a frame,
comment|/// make weak refernces too the frame, thread, process and target.
comment|/// If the ExecutionContextScope object is valid and refers to a thread,
comment|/// make weak refernces too the thread, process and target.
comment|/// If the ExecutionContextScope object is valid and refers to a process,
comment|/// make weak refernces too the process and target.
comment|/// If the ExecutionContextScope object is valid and refers to a target,
comment|/// make weak refernces too the target.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct using an execution context scope.
comment|///
comment|/// If the ExecutionContextScope object refers to a frame,
comment|/// make weak refernces too the frame, thread, process and target.
comment|/// If the ExecutionContextScope object refers to a thread,
comment|/// make weak refernces too the thread, process and target.
comment|/// If the ExecutionContextScope object refers to a process,
comment|/// make weak refernces too the process and target.
comment|/// If the ExecutionContextScope object refers to a target,
comment|/// make weak refernces too the target.
comment|//------------------------------------------------------------------
name|ExecutionContextRef
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|)
expr_stmt|;
operator|~
name|ExecutionContextRef
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the process and thread to NULL, and the frame index to an
comment|/// invalid value.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set accessor that creates a weak reference to the target
comment|/// referenced in \a target_sp.
comment|///
comment|/// If \a target_sp is valid this object will create a weak
comment|/// reference to that object, otherwise any previous target weak
comment|/// reference contained in this object will be reset.
comment|///
comment|/// Only the weak reference to the target will be updated, no other
comment|/// weak references will be modified. If you want this execution
comment|/// context to make a weak reference to the target's process, use
comment|/// the ExecutionContextRef::SetContext() functions.
comment|///
comment|/// @see ExecutionContextRef::SetContext(const lldb::TargetSP&, bool)
comment|//------------------------------------------------------------------
name|void
name|SetTargetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor that creates a weak reference to the process
comment|/// referenced in \a process_sp.
comment|///
comment|/// If \a process_sp is valid this object will create a weak
comment|/// reference to that object, otherwise any previous process weak
comment|/// reference contained in this object will be reset.
comment|///
comment|/// Only the weak reference to the process will be updated, no other
comment|/// weak references will be modified. If you want this execution
comment|/// context to make a weak reference to the target, use the
comment|/// ExecutionContextRef::SetContext() functions.
comment|///
comment|/// @see ExecutionContextRef::SetContext(const lldb::ProcessSP&)
comment|//------------------------------------------------------------------
name|void
name|SetProcessSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor that creates a weak reference to the thread
comment|/// referenced in \a thread_sp.
comment|///
comment|/// If \a thread_sp is valid this object will create a weak
comment|/// reference to that object, otherwise any previous thread weak
comment|/// reference contained in this object will be reset.
comment|///
comment|/// Only the weak reference to the thread will be updated, no other
comment|/// weak references will be modified. If you want this execution
comment|/// context to make a weak reference to the thread's process and
comment|/// target, use the ExecutionContextRef::SetContext() functions.
comment|///
comment|/// @see ExecutionContextRef::SetContext(const lldb::ThreadSP&)
comment|//------------------------------------------------------------------
name|void
name|SetThreadSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor that creates a weak reference to the frame
comment|/// referenced in \a frame_sp.
comment|///
comment|/// If \a frame_sp is valid this object will create a weak
comment|/// reference to that object, otherwise any previous frame weak
comment|/// reference contained in this object will be reset.
comment|///
comment|/// Only the weak reference to the frame will be updated, no other
comment|/// weak references will be modified. If you want this execution
comment|/// context to make a weak reference to the frame's thread, process
comment|/// and target, use the ExecutionContextRef::SetContext() functions.
comment|///
comment|/// @see ExecutionContextRef::SetContext(const lldb::StackFrameSP&)
comment|//------------------------------------------------------------------
name|void
name|SetFrameSP
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
decl_stmt|;
name|void
name|SetTargetPtr
parameter_list|(
name|Target
modifier|*
name|target
parameter_list|,
name|bool
name|adopt_selected
parameter_list|)
function_decl|;
name|void
name|SetProcessPtr
parameter_list|(
name|Process
modifier|*
name|process
parameter_list|)
function_decl|;
name|void
name|SetThreadPtr
parameter_list|(
name|Thread
modifier|*
name|thread
parameter_list|)
function_decl|;
name|void
name|SetFramePtr
parameter_list|(
name|StackFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor that creates a strong reference from the weak target
comment|/// reference contained in this object.
comment|///
comment|/// @returns
comment|///     A shared pointer to a target that is not guaranteed to be valid.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|GetTargetSP
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor that creates a strong reference from the weak process
comment|/// reference contained in this object.
comment|///
comment|/// @returns
comment|///     A shared pointer to a process that is not guaranteed to be valid.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ProcessSP
name|GetProcessSP
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor that creates a strong reference from the weak thread
comment|/// reference contained in this object.
comment|///
comment|/// @returns
comment|///     A shared pointer to a thread that is not guaranteed to be valid.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadSP
name|GetThreadSP
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor that creates a strong reference from the weak frame
comment|/// reference contained in this object.
comment|///
comment|/// @returns
comment|///     A shared pointer to a frame that is not guaranteed to be valid.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|StackFrameSP
name|GetFrameSP
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Create an ExecutionContext object from this object.
comment|///
comment|/// Create strong references to any execution context objects that
comment|/// are still valid. Any of the returned shared pointers in the
comment|/// ExecutionContext objects is not guaranteed to be valid.
comment|/// @returns
comment|///     An execution context object that has strong references to
comment|///     any valid weak references in this object.
comment|//------------------------------------------------------------------
name|ExecutionContext
name|Lock
argument_list|(
name|bool
name|thread_and_frame_only_if_stopped
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true if this object has a weak reference to a thread.
comment|/// The return value is only an indication of wether this object has
comment|/// a weak reference and does not indicate wether the weak rerference
comment|/// is valid or not.
comment|//------------------------------------------------------------------
name|bool
name|HasThreadRef
argument_list|()
specifier|const
block|{
return|return
name|m_tid
operator|!=
name|LLDB_INVALID_THREAD_ID
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns true if this object has a weak reference to a frame.
comment|/// The return value is only an indication of wether this object has
comment|/// a weak reference and does not indicate wether the weak rerference
comment|/// is valid or not.
comment|//------------------------------------------------------------------
name|bool
name|HasFrameRef
argument_list|()
specifier|const
block|{
return|return
name|m_stack_id
operator|.
name|IsValid
argument_list|()
return|;
block|}
name|void
name|ClearThread
parameter_list|()
block|{
name|m_thread_wp
operator|.
name|reset
argument_list|()
expr_stmt|;
name|m_tid
operator|=
name|LLDB_INVALID_THREAD_ID
expr_stmt|;
block|}
name|void
name|ClearFrame
parameter_list|()
block|{
name|m_stack_id
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetWP
name|m_target_wp
expr_stmt|;
comment|///< A weak reference to a target
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
comment|///< A weak reference to a process
name|mutable
name|lldb
operator|::
name|ThreadWP
name|m_thread_wp
expr_stmt|;
comment|///< A weak reference to a thread
name|lldb
operator|::
name|tid_t
name|m_tid
expr_stmt|;
comment|///< The thread ID that this object refers to in case the backing object changes
name|StackID
name|m_stack_id
decl_stmt|;
comment|///< The stack ID that this object refers to in case the backing object changes
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ExecutionContext ExecutionContext.h "lldb/Target/ExecutionContext.h"
comment|/// @brief A class that contains an execution context.
comment|///
comment|/// This baton object can be passed into any function that requires
comment|/// a context that specifies a target, process, thread and frame.
comment|/// These objects are designed to be used for short term execution
comment|/// context object storage while a function might be trying to evaluate
comment|/// something that requires a thread or frame. ExecutionContextRef
comment|/// objects can be used to initialize one of these objects to turn
comment|/// the weak execution context object references to the target, process,
comment|/// thread and frame into strong references (shared pointers) so that
comment|/// functions can guarantee that these objects won't go away in the
comment|/// middle of a function.
comment|///
comment|/// ExecutionContext objects should be used as short lived objects
comment|/// (typically on the stack) in order to lock down an execution context
comment|/// for local use and for passing down to other functions that also
comment|/// require specific contexts. They should NOT be used for long term
comment|/// storage, for long term storage use ExecutionContextRef objects.
comment|//----------------------------------------------------------------------
name|class
name|ExecutionContext
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default Constructor.
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Copy constructor
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
specifier|const
name|ExecutionContext
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Adopt the target and optionally its current context.
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
argument|Target* t
argument_list|,
argument|bool fill_current_process_thread_frame = true
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|// Create execution contexts from shared pointers
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
argument|const lldb::TargetSP&target_sp
argument_list|,
argument|bool get_process
argument_list|)
empty_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Create execution contexts from weak pointers
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
argument|const lldb::TargetWP&target_wp
argument_list|,
argument|bool get_process
argument_list|)
empty_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessWP
operator|&
name|process_wp
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadWP
operator|&
name|thread_wp
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameWP
operator|&
name|frame_wp
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|ExecutionContextRef
operator|&
name|exe_ctx_ref
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
argument|const ExecutionContextRef *exe_ctx_ref
argument_list|,
argument|bool thread_and_frame_only_if_stopped = false
argument_list|)
empty_stmt|;
comment|// These two variants take in a locker, and grab the target, lock the API mutex into locker, then
comment|// fill in the rest of the shared pointers.
name|ExecutionContext
argument_list|(
specifier|const
name|ExecutionContextRef
operator|&
name|exe_ctx_ref
argument_list|,
name|Mutex
operator|::
name|Locker
operator|&
name|locker
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
specifier|const
name|ExecutionContextRef
operator|*
name|exe_ctx_ref
argument_list|,
name|Mutex
operator|::
name|Locker
operator|&
name|locker
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Create execution contexts from execution context scopes
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|)
expr_stmt|;
name|ExecutionContext
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|)
expr_stmt|;
name|ExecutionContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ExecutionContext
operator|&
name|rhs
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ExecutionContext
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ExecutionContext
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with process, thread, and frame index.
comment|///
comment|/// Initialize with process \a p, thread \a t, and frame index \a f.
comment|///
comment|/// @param[in] process
comment|///     The process for this execution context.
comment|///
comment|/// @param[in] thread
comment|///     The thread for this execution context.
comment|///
comment|/// @param[in] frame
comment|///     The frame index for this execution context.
comment|//------------------------------------------------------------------
name|ExecutionContext
argument_list|(
name|Process
operator|*
name|process
argument_list|,
name|Thread
operator|*
name|thread
operator|=
name|NULL
argument_list|,
name|StackFrame
operator|*
name|frame
operator|=
name|NULL
argument_list|)
expr_stmt|;
operator|~
name|ExecutionContext
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the process and thread to NULL, and the frame index to an
comment|/// invalid value.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
name|RegisterContext
operator|*
name|GetRegisterContext
argument_list|()
specifier|const
expr_stmt|;
name|ExecutionContextScope
operator|*
name|GetBestExecutionContextScope
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a pointer to the target object.
comment|///
comment|/// The returned pointer might be NULL. Calling HasTargetScope(),
comment|/// HasProcessScope(), HasThreadScope(), or HasFrameScope()
comment|/// can help to pre-validate this pointer so that this accessor can
comment|/// freely be used without having to check for NULL each time.
comment|///
comment|/// @see ExecutionContext::HasTargetScope() const
comment|/// @see ExecutionContext::HasProcessScope() const
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Target
operator|*
name|GetTargetPtr
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a pointer to the process object.
comment|///
comment|/// The returned pointer might be NULL. Calling HasProcessScope(),
comment|/// HasThreadScope(), or HasFrameScope()  can help to pre-validate
comment|/// this pointer so that this accessor can freely be used without
comment|/// having to check for NULL each time.
comment|///
comment|/// @see ExecutionContext::HasProcessScope() const
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Process
operator|*
name|GetProcessPtr
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a pointer to the thread object.
comment|///
comment|/// The returned pointer might be NULL. Calling HasThreadScope() or
comment|/// HasFrameScope() can help to pre-validate this pointer so that
comment|/// this accessor can freely be used without having to check for
comment|/// NULL each time.
comment|///
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Thread
operator|*
name|GetThreadPtr
argument_list|()
specifier|const
block|{
return|return
name|m_thread_sp
operator|.
name|get
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns a pointer to the frame object.
comment|///
comment|/// The returned pointer might be NULL. Calling HasFrameScope(),
comment|/// can help to pre-validate this pointer so that this accessor can
comment|/// freely be used without having to check for NULL each time.
comment|///
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|StackFrame
operator|*
name|GetFramePtr
argument_list|()
specifier|const
block|{
return|return
name|m_frame_sp
operator|.
name|get
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns a reference to the target object.
comment|///
comment|/// Clients should call HasTargetScope(), HasProcessScope(),
comment|/// HasThreadScope(), or HasFrameScope() prior to calling this
comment|/// function to ensure that this ExecutionContext object contains
comment|/// a valid target.
comment|///
comment|/// @see ExecutionContext::HasTargetScope() const
comment|/// @see ExecutionContext::HasProcessScope() const
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Target
operator|&
name|GetTargetRef
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a reference to the process object.
comment|///
comment|/// Clients should call HasProcessScope(), HasThreadScope(), or
comment|/// HasFrameScope() prior to calling this  function to ensure that
comment|/// this ExecutionContext object contains a valid target.
comment|///
comment|/// @see ExecutionContext::HasProcessScope() const
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Process
operator|&
name|GetProcessRef
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a reference to the thread object.
comment|///
comment|/// Clients should call HasThreadScope(), or  HasFrameScope() prior
comment|/// to calling this  function to ensure that  this ExecutionContext
comment|/// object contains a valid target.
comment|///
comment|/// @see ExecutionContext::HasThreadScope() const
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|Thread
operator|&
name|GetThreadRef
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a reference to the thread object.
comment|///
comment|/// Clients should call HasFrameScope() prior to calling this
comment|/// function to ensure that  this ExecutionContext object contains
comment|/// a valid target.
comment|///
comment|/// @see ExecutionContext::HasFrameScope() const
comment|//------------------------------------------------------------------
name|StackFrame
operator|&
name|GetFrameRef
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor to get the target shared pointer.
comment|///
comment|/// The returned shared pointer is not guaranteed to be valid.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|GetTargetSP
argument_list|()
specifier|const
block|{
return|return
name|m_target_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor to get the process shared pointer.
comment|///
comment|/// The returned shared pointer is not guaranteed to be valid.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|GetProcessSP
argument_list|()
specifier|const
block|{
return|return
name|m_process_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor to get the thread shared pointer.
comment|///
comment|/// The returned shared pointer is not guaranteed to be valid.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|GetThreadSP
argument_list|()
specifier|const
block|{
return|return
name|m_thread_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor to get the frame shared pointer.
comment|///
comment|/// The returned shared pointer is not guaranteed to be valid.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|GetFrameSP
argument_list|()
specifier|const
block|{
return|return
name|m_frame_sp
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the target shared pointer.
comment|//------------------------------------------------------------------
name|void
name|SetTargetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the process shared pointer.
comment|//------------------------------------------------------------------
name|void
name|SetProcessSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the thread shared pointer.
comment|//------------------------------------------------------------------
name|void
name|SetThreadSP
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the frame shared pointer.
comment|//------------------------------------------------------------------
name|void
name|SetFrameSP
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the target shared pointer from a target
comment|/// pointer.
comment|//------------------------------------------------------------------
name|void
name|SetTargetPtr
parameter_list|(
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the process shared pointer from a
comment|/// process pointer.
comment|//------------------------------------------------------------------
name|void
name|SetProcessPtr
parameter_list|(
name|Process
modifier|*
name|process
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the thread shared pointer from a thread
comment|/// pointer.
comment|//------------------------------------------------------------------
name|void
name|SetThreadPtr
parameter_list|(
name|Thread
modifier|*
name|thread
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set accessor to set only the frame shared pointer from a frame
comment|/// pointer.
comment|//------------------------------------------------------------------
name|void
name|SetFramePtr
parameter_list|(
name|StackFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Set the execution context using a target shared pointer.
comment|//
comment|// If "target_sp" is valid, sets the target context to match and
comment|// if "get_process" is true, sets the process shared pointer if
comment|// the target currently has a process.
comment|//------------------------------------------------------------------
name|void
name|SetContext
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|bool
name|get_process
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Set the execution context using a process shared pointer.
comment|//
comment|// If "process_sp" is valid, then set the process and target in this
comment|// context. Thread and frame contexts will be cleared.
comment|// If "process_sp" is not valid, all shared pointers are reset.
comment|//------------------------------------------------------------------
name|void
name|SetContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Set the execution context using a thread shared pointer.
comment|//
comment|// If "thread_sp" is valid, then set the thread, process and target
comment|// in this context. The frame context will be cleared.
comment|// If "thread_sp" is not valid, all shared pointers are reset.
comment|//------------------------------------------------------------------
name|void
name|SetContext
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Set the execution context using a frame shared pointer.
comment|//
comment|// If "frame_sp" is valid, then set the frame, thread, process and
comment|// target in this context
comment|// If "frame_sp" is not valid, all shared pointers are reset.
comment|//------------------------------------------------------------------
name|void
name|SetContext
argument_list|(
specifier|const
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true the ExecutionContext object contains a valid
comment|/// target.
comment|///
comment|/// This function can be called after initializing an ExecutionContext
comment|/// object, and if it returns true, calls to GetTargetPtr() and
comment|/// GetTargetRef() do not need to be checked for validity.
comment|//------------------------------------------------------------------
name|bool
name|HasTargetScope
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true the ExecutionContext object contains a valid
comment|/// target and process.
comment|///
comment|/// This function can be called after initializing an ExecutionContext
comment|/// object, and if it returns true, calls to GetTargetPtr() and
comment|/// GetTargetRef(), GetProcessPtr(), and GetProcessRef(), do not
comment|/// need to be checked for validity.
comment|//------------------------------------------------------------------
name|bool
name|HasProcessScope
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true the ExecutionContext object contains a valid
comment|/// target, process, and thread.
comment|///
comment|/// This function can be called after initializing an ExecutionContext
comment|/// object, and if it returns true, calls to GetTargetPtr(),
comment|/// GetTargetRef(), GetProcessPtr(), GetProcessRef(), GetThreadPtr(),
comment|/// and GetThreadRef() do not need to be checked for validity.
comment|//------------------------------------------------------------------
name|bool
name|HasThreadScope
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true the ExecutionContext object contains a valid
comment|/// target, process, thread and frame.
comment|///
comment|/// This function can be called after initializing an ExecutionContext
comment|/// object, and if it returns true, calls to GetTargetPtr(),
comment|/// GetTargetRef(), GetProcessPtr(), GetProcessRef(), GetThreadPtr(),
comment|/// GetThreadRef(), GetFramePtr(), and GetFrameRef() do not need
comment|/// to be checked for validity.
comment|//------------------------------------------------------------------
name|bool
name|HasFrameScope
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|m_target_sp
expr_stmt|;
comment|///< The target that owns the process/thread/frame
name|lldb
operator|::
name|ProcessSP
name|m_process_sp
expr_stmt|;
comment|///< The process that owns the thread/frame
name|lldb
operator|::
name|ThreadSP
name|m_thread_sp
expr_stmt|;
comment|///< The thread that owns the frame
name|lldb
operator|::
name|StackFrameSP
name|m_frame_sp
expr_stmt|;
comment|///< The stack frame in thread.
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
comment|// liblldb_ExecutionContext_h_
end_comment

end_unit

