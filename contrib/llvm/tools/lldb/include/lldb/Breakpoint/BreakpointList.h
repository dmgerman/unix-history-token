begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointList.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointList_h_
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
file|<list>
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
file|"lldb/Breakpoint/Breakpoint.h"
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
comment|/// @class BreakpointList BreakpointList.h "lldb/Breakpoint/BreakpointList.h"
comment|/// @brief This class manages a list of breakpoints.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// Allows adding and removing breakpoints and find by ID and index.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointList
block|{
name|public
label|:
name|BreakpointList
argument_list|(
argument|bool is_internal
argument_list|)
empty_stmt|;
operator|~
name|BreakpointList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add the breakpoint \a bp_sp to the list.
comment|///
comment|/// @param[in] bp_sp
comment|///   Shared pointer to the breakpoint that will get added to the list.
comment|///
comment|/// @result
comment|///   Returns breakpoint id.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|Add
argument_list|(
argument|lldb::BreakpointSP& bp_sp
argument_list|,
argument|bool notify
argument_list|)
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
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint with id \a breakID.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint ID to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointSP
name|FindBreakpointByID
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint with id \a breakID.  Const version.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint ID to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointSP
name|FindBreakpointByID
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint with index \a i.
comment|///
comment|/// @param[in] i
comment|///   The breakpoint index to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointSP
name|GetBreakpointAtIndex
argument_list|(
argument|size_t i
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint with index \a i, const version
comment|///
comment|/// @param[in] i
comment|///   The breakpoint index to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointSP
name|GetBreakpointAtIndex
argument_list|(
argument|size_t i
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of elements in this breakpoint list.
comment|///
comment|/// @result
comment|///   The number of elements.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
name|Mutex
operator|::
name|Locker
name|locker
argument_list|(
name|m_mutex
argument_list|)
block|;
return|return
name|m_breakpoints
operator|.
name|size
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Removes the breakpoint given by \b breakID from this list.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint index to remove.
comment|///
comment|/// @result
comment|///   \b true if the breakpoint \a breakID was in the list.
comment|//------------------------------------------------------------------
name|bool
name|Remove
argument_list|(
name|lldb
operator|::
name|break_id_t
name|breakID
argument_list|,
name|bool
name|notify
argument_list|)
decl_stmt|;
name|void
name|SetEnabledAll
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Removes all the breakpoints from this list.
comment|//------------------------------------------------------------------
name|void
name|RemoveAll
parameter_list|(
name|bool
name|notify
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tell all the breakpoints to update themselves due to a change in the
comment|/// modules in \a module_list.  \a added says whether the module was loaded
comment|/// or unloaded.
comment|///
comment|/// @param[in] module_list
comment|///   The module list that has changed.
comment|///
comment|/// @param[in] load
comment|///   \b true if the modules are loaded, \b false if unloaded.
comment|///
comment|/// @param[in] delete_locations
comment|///   If \a load is \b false, then delete breakpoint locations when
comment|///   when updating breakpoints.
comment|//------------------------------------------------------------------
name|void
name|UpdateBreakpoints
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|,
name|bool
name|load
parameter_list|,
name|bool
name|delete_locations
parameter_list|)
function_decl|;
name|void
name|UpdateBreakpointsWhenModuleIsReplaced
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
name|void
name|ClearAllBreakpointSites
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sets the passed in Locker to hold the Breakpoint List mutex.
comment|///
comment|/// @param[in] locker
comment|///   The locker object that is set.
comment|//------------------------------------------------------------------
name|void
name|GetListMutex
argument_list|(
name|lldb_private
operator|::
name|Mutex
operator|::
name|Locker
operator|&
name|locker
argument_list|)
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|list
operator|<
name|lldb
operator|::
name|BreakpointSP
operator|>
name|bp_collection
expr_stmt|;
name|bp_collection
operator|::
name|iterator
name|GetBreakpointIDIterator
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
expr_stmt|;
name|bp_collection
operator|::
name|const_iterator
name|GetBreakpointIDConstIterator
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
specifier|const
expr_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|bp_collection
name|m_breakpoints
decl_stmt|;
comment|// The breakpoint list, currently a list.
name|lldb
operator|::
name|break_id_t
name|m_next_break_id
expr_stmt|;
name|bool
name|m_is_internal
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointList
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
comment|// liblldb_BreakpointList_h_
end_comment

end_unit

