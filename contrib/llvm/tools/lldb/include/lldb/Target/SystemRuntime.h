begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemRuntime.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_SystemRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SystemRuntime_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ModuleList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/QueueItem.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/QueueList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class SystemRuntime SystemRuntime.h "lldb/Target/SystemRuntime.h"
comment|/// @brief A plug-in interface definition class for system runtimes.
comment|///
comment|/// The system runtime plugins can collect information from the system
comment|/// libraries during a Process' lifetime and provide information about
comment|/// how objects/threads were originated.
comment|///
comment|/// For instance, a system runtime plugin use a breakpoint when threads
comment|/// are created to record the backtrace of where that thread was created.
comment|/// Later, when backtracing the created thread, it could extend the backtrace
comment|/// to show where it was originally created from.
comment|///
comment|/// The plugin will insert its own breakpoint when Created and start collecting
comment|/// information.  Later when it comes time to augment a Thread, it can be
comment|/// asked to provide that information.
comment|///
comment|//----------------------------------------------------------------------
name|class
name|SystemRuntime
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Find a system runtime plugin for a given process.
comment|///
comment|/// Scans the installed SystemRuntime plugins and tries to find
comment|/// an instance that can be used to track image changes in \a
comment|/// process.
comment|///
comment|/// @param[in] process
comment|///     The process for which to try and locate a system runtime
comment|///     plugin instance.
comment|//------------------------------------------------------------------
specifier|static
name|SystemRuntime
operator|*
name|FindPlugin
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Construct with a process.
comment|// -----------------------------------------------------------------
name|SystemRuntime
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited by the plug-in instance.
comment|//------------------------------------------------------------------
operator|~
name|SystemRuntime
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching to a process.
comment|///
comment|/// Allow the SystemRuntime plugin to execute some code after attaching
comment|/// to a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Called after launching a process.
comment|///
comment|/// Allow the SystemRuntime plugin to execute some code after launching
comment|/// a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidLaunch
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Called when modules have been loaded in the process.
comment|///
comment|/// Allow the SystemRuntime plugin to enable logging features in the
comment|/// system runtime libraries.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ModulesDidLoad
argument_list|(
name|lldb_private
operator|::
name|ModuleList
operator|&
name|module_list
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Called before detaching from a process.
comment|///
comment|/// This will give a SystemRuntime plugin a chance to free any resources
comment|/// in the inferior process before we detach.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Detach
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Return a list of thread origin extended backtraces that may
comment|/// be available.
comment|///
comment|/// A System Runtime may be able to provide a backtrace of when this
comment|/// thread was originally created.  Furthermore, it may be able to
comment|/// provide that extended backtrace for different styles of creation.
comment|/// On a system with both pthreads and libdispatch, aka Grand Central
comment|/// Dispatch, queues, the system runtime may be able to provide the
comment|/// pthread creation of the thread and it may also be able to provide
comment|/// the backtrace of when this GCD queue work block was enqueued.
comment|/// The caller may request these different origins by name.
comment|///
comment|/// The names will be provided in the order that they are most likely
comment|/// to be requested.  For instance, a most natural order may be to
comment|/// request the GCD libdispatch queue origin.  If there is none, then
comment|/// request the pthread origin.
comment|///
comment|/// @return
comment|///   A vector of ConstStrings with names like "pthread" or "libdispatch".
comment|///   An empty vector may be returned if no thread origin extended
comment|///   backtrace capabilities are available.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
operator|&
name|GetExtendedBacktraceTypes
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Return a Thread which shows the origin of this thread's creation.
comment|///
comment|/// This likely returns a HistoryThread which shows how thread was
comment|/// originally created (e.g. "pthread" type), or how the work that
comment|/// is currently executing on it was originally enqueued (e.g.
comment|/// "libdispatch" type).
comment|///
comment|/// There may be a chain of thread-origins; it may be informative to
comment|/// the end user to query the returned ThreadSP for its origins as
comment|/// well.
comment|///
comment|/// @param [in] thread
comment|///   The thread to examine.
comment|///
comment|/// @param [in] type
comment|///   The type of thread origin being requested.  The types supported
comment|///   are returned from SystemRuntime::GetExtendedBacktraceTypes.
comment|///
comment|/// @return
comment|///   A ThreadSP which will have a StackList of frames.  This Thread will
comment|///   not appear in the Process' list of current threads.  Normal thread
comment|///   operations like stepping will not be available.  This is a historical
comment|///   view thread and may be only useful for showing a backtrace.
comment|///
comment|///   An empty ThreadSP will be returned if no thread origin is available.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceThread
argument_list|(
argument|lldb::ThreadSP thread
argument_list|,
argument|ConstString type
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get the extended backtrace thread for a QueueItem
comment|///
comment|/// A QueueItem represents a function/block that will be executed on
comment|/// a libdispatch queue in the future, or it represents a function/block
comment|/// that is currently executing on a thread.
comment|///
comment|/// This method will report a thread backtrace of the function that
comment|/// enqueued it originally, if possible.
comment|///
comment|/// @param [in] queue_item_sp
comment|///     The QueueItem that we are getting an extended backtrace for.
comment|///
comment|/// @param [in] type
comment|///     The type of extended backtrace to fetch.  The types supported
comment|///     are returned from SystemRuntime::GetExtendedBacktraceTypes.
comment|///
comment|/// @return
comment|///     If an extended backtrace is available, it is returned.  Else
comment|///     an empty ThreadSP is returned.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceForQueueItem
argument_list|(
argument|lldb::QueueItemSP queue_item_sp
argument_list|,
argument|ConstString type
argument_list|)
block|{
return|return
name|lldb
operator|::
name|ThreadSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Populate the Process' QueueList with libdispatch / GCD queues that exist.
comment|///
comment|/// When process execution is paused, the SystemRuntime may be called to fill
comment|/// in the list of Queues that currently exist.
comment|///
comment|/// @param [out] queue_list
comment|///     This QueueList will be cleared, and any queues that currently exist
comment|///     will be added.  An empty QueueList will be returned if no queues
comment|///     exist or if this Systemruntime does not support libdispatch queues.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|PopulateQueueList
argument_list|(
argument|lldb_private::QueueList&queue_list
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Get the queue name for a thread given a thread's dispatch_qaddr.
comment|///
comment|/// On systems using libdispatch queues, a thread may be associated with a
comment|/// queue.
comment|/// There will be a call to get the thread's dispatch_qaddr.  At the
comment|/// dispatch_qaddr
comment|/// we will find the address of this thread's dispatch_queue_t structure.
comment|/// Given the address of the dispatch_queue_t structure for a thread,
comment|/// get the queue name and return it.
comment|///
comment|/// @param [in] dispatch_qaddr
comment|///     The address of the dispatch_qaddr pointer for this thread.
comment|///
comment|/// @return
comment|///     The string of this queue's name.  An empty string is returned if the
comment|///     name could not be found.
comment|//------------------------------------------------------------------
name|virtual
name|std
operator|::
name|string
name|GetQueueNameFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
literal|""
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the QueueID for the libdispatch queue given the thread's
comment|/// dispatch_qaddr.
comment|///
comment|/// On systems using libdispatch queues, a thread may be associated with a
comment|/// queue.
comment|/// There will be a call to get the thread's dispatch_qaddr.  At the
comment|/// dispatch_qaddr
comment|/// we will find the address of this thread's dispatch_queue_t structure.
comment|/// Given the address of the dispatch_queue_t structure for a thread,
comment|/// get the queue ID and return it.
comment|///
comment|/// @param [in] dispatch_qaddr
comment|///     The address of the dispatch_qaddr pointer for this thread.
comment|///
comment|/// @return
comment|///     The queue ID, or if it could not be retrieved, LLDB_INVALID_QUEUE_ID.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|queue_id_t
name|GetQueueIDFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
name|LLDB_INVALID_QUEUE_ID
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the libdispatch_queue_t address for the queue given the thread's
comment|/// dispatch_qaddr.
comment|///
comment|/// On systems using libdispatch queues, a thread may be associated with a
comment|/// queue.
comment|/// There will be a call to get the thread's dispatch_qaddr.
comment|/// Given the thread's dispatch_qaddr, find the libdispatch_queue_t address
comment|/// and
comment|/// return it.
comment|///
comment|/// @param [in] dispatch_qaddr
comment|///     The address of the dispatch_qaddr pointer for this thread.
comment|///
comment|/// @return
comment|///     The libdispatch_queue_t address, or LLDB_INVALID_ADDRESS if
comment|///     unavailable/not found.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetLibdispatchQueueAddressFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Retrieve the Queue kind for the queue at a thread's dispatch_qaddr.
comment|///
comment|/// Retrieve the Queue kind - either eQueueKindSerial or
comment|/// eQueueKindConcurrent, indicating that this queue processes work
comment|/// items serially or concurrently.
comment|///
comment|/// @return
comment|///     The Queue kind, if it could be read, else eQueueKindUnknown.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|QueueKind
name|GetQueueKind
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
block|{
return|return
name|lldb
operator|::
name|eQueueKindUnknown
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the pending work items for a libdispatch Queue
comment|///
comment|/// If this system/process is using libdispatch and the runtime can do so,
comment|/// retrieve the list of pending work items for the specified Queue and
comment|/// add it to the Queue.
comment|///
comment|/// @param [in] queue
comment|///     The queue of interest.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|PopulatePendingItemsForQueue
argument_list|(
argument|lldb_private::Queue *queue
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Complete the fields in a QueueItem
comment|///
comment|/// PopulatePendingItemsForQueue() may not fill in all of the QueueItem
comment|/// details; when the remaining fields are needed, they will be
comment|/// fetched by call this method.
comment|///
comment|/// @param [in] queue_item
comment|///   The QueueItem that we will be completing.
comment|///
comment|/// @param [in] item_ref
comment|///     The item_ref token that is needed to retrieve the rest of the
comment|///     information about the QueueItem.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CompleteQueueItem
argument_list|(
argument|lldb_private::QueueItem *queue_item
argument_list|,
argument|lldb::addr_t item_ref
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Add key-value pairs to the StructuredData dictionary object with
comment|/// information debugserver  may need when constructing the
comment|/// jThreadExtendedInfo
comment|/// packet.
comment|///
comment|/// @param [out] dict
comment|///     Dictionary to which key-value pairs should be added; they will
comment|///     be sent to the remote gdb server stub as arguments in the
comment|///     jThreadExtendedInfo request.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|AddThreadExtendedInfoPacketHints
argument_list|(
argument|lldb_private::StructuredData::ObjectSP dict
argument_list|)
block|{}
comment|/// Determine whether it is safe to run an expression on a given thread
comment|///
comment|/// If a system must not run functions on a thread in some particular state,
comment|/// this method gives a way for it to flag that the expression should not be
comment|/// run.
comment|///
comment|/// @param [in] thread_sp
comment|///     The thread we want to run the expression on.
comment|///
comment|/// @return
comment|///     True will be returned if there are no known problems with running an
comment|///     expression on this thread.  False means that the inferior function
comment|///     call should not be made on this thread.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|SafeToCallFunctionsOnThisThread
argument_list|(
argument|lldb::ThreadSP thread_sp
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Process
operator|*
name|m_process
block|;
name|std
operator|::
name|vector
operator|<
name|ConstString
operator|>
name|m_types
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SystemRuntime
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_SystemRuntime_h_
end_comment

end_unit

