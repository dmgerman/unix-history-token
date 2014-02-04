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
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
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
file|"lldb/lldb-private.h"
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
name|virtual
operator|~
name|SystemRuntime
argument_list|()
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

