begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilThreadBaseStd.h -----------------------------------*- C++ -*-===//
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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<thread>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIDataTypes.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Handle thread mutual exclusion.
end_comment

begin_comment
comment|//          Embed Mutexes in your Active Object and then use them through Locks.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilThreadMutex
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilThreadMutex
argument_list|()
block|{}
comment|//
name|void
name|Lock
parameter_list|()
function_decl|;
comment|// Wait until mutex can be obtained
name|void
name|Unlock
parameter_list|()
function_decl|;
comment|// Release the mutex
name|bool
name|TryLock
parameter_list|()
function_decl|;
comment|// Gain the lock if available
comment|// Overrideable:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilThreadMutex
argument_list|()
block|{}
comment|// Attributes:
name|private
operator|:
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Thread object.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilThread
block|{
comment|// Typedef:
name|public
label|:
typedef|typedef
name|MIuint
function_decl|(
modifier|*
name|FnThreadProc
function_decl|)
parameter_list|(
name|void
modifier|*
name|vpThisClass
parameter_list|)
function_decl|;
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilThread
argument_list|()
expr_stmt|;
comment|//
name|bool
name|Start
parameter_list|(
name|FnThreadProc
name|vpFn
parameter_list|,
name|void
modifier|*
name|vpArg
parameter_list|)
function_decl|;
comment|// Start execution of this thread
name|bool
name|Join
parameter_list|()
function_decl|;
comment|// Wait for this thread to stop
name|bool
name|IsActive
parameter_list|()
function_decl|;
comment|// Returns true if this thread is running
name|void
name|Finish
parameter_list|()
function_decl|;
comment|// Finish this thread
comment|// Overrideable:
name|public
label|:
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilThread
argument_list|()
expr_stmt|;
comment|// Methods:
name|private
label|:
name|CMIUtilThreadMutex
name|m_mutex
decl_stmt|;
name|std
operator|::
name|thread
operator|*
name|m_pThread
expr_stmt|;
name|bool
name|m_bIsActive
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Base class for a worker thread active
end_comment

begin_comment
comment|//          object. Runs an 'captive thread'.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilThreadActiveObjBase
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilThreadActiveObjBase
argument_list|()
expr_stmt|;
comment|//
name|bool
name|Acquire
parameter_list|()
function_decl|;
comment|// Obtain a reference to this object
name|bool
name|Release
parameter_list|()
function_decl|;
comment|// Release a reference to this object
name|bool
name|ThreadIsActive
parameter_list|()
function_decl|;
comment|// Return true if this object is running
name|bool
name|ThreadJoin
parameter_list|()
function_decl|;
comment|// Wait for this thread to stop running
name|bool
name|ThreadKill
parameter_list|()
function_decl|;
comment|// Force this thread to stop, regardless of references
name|bool
name|ThreadExecute
parameter_list|()
function_decl|;
comment|// Start this objects execution in another thread
name|void
name|ThreadManage
parameter_list|()
function_decl|;
comment|// Overrideable:
name|public
label|:
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilThreadActiveObjBase
argument_list|()
expr_stmt|;
comment|//
comment|// Each thread object must supple a unique name that can be used to locate it
name|virtual
specifier|const
name|CMIUtilString
operator|&
name|ThreadGetName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Statics:
name|protected
label|:
specifier|static
name|MIuint
name|ThreadEntry
parameter_list|(
name|void
modifier|*
name|vpThisClass
parameter_list|)
function_decl|;
comment|// Thread entry point
comment|// Overrideable:
name|protected
label|:
name|virtual
name|bool
name|ThreadRun
parameter_list|(
name|bool
modifier|&
name|vrIsAlive
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Call the main worker method
name|virtual
name|bool
name|ThreadFinish
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Finish of what you were doing
comment|// Attributes:
name|protected
label|:
specifier|volatile
name|MIuint
name|m_references
decl_stmt|;
comment|// Stores the current lifetime state of this
comment|// thread, 0 = running,> 0 = shutting down
specifier|volatile
name|bool
name|m_bHasBeenKilled
decl_stmt|;
comment|// Set to true when this thread has been killed
name|CMIUtilThread
name|m_thread
decl_stmt|;
comment|// The execution thread
name|CMIUtilThreadMutex
name|m_mutex
decl_stmt|;
comment|// This mutex allows us to safely communicate with
comment|// this thread object across the interface from
comment|// multiple threads
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Handle thread resource locking.
end_comment

begin_comment
comment|//          Put Locks inside all the methods of your Active Object that access
end_comment

begin_comment
comment|//          data shared with the captive thread.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilThreadLock
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilThreadLock
argument_list|(
name|CMIUtilThreadMutex
operator|&
name|vMutex
argument_list|)
operator|:
name|m_rMutex
argument_list|(
argument|vMutex
argument_list|)
block|{
name|m_rMutex
operator|.
name|Lock
argument_list|()
block|;   }
comment|// Overrideable:
name|public
operator|:
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilThreadLock
argument_list|()
block|{
name|m_rMutex
operator|.
name|Unlock
argument_list|()
block|; }
comment|// Attributes:
name|private
operator|:
name|CMIUtilThreadMutex
operator|&
name|m_rMutex
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

