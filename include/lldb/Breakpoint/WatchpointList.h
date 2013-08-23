begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WatchpointList.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_WatchpointList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_WatchpointList_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
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
comment|/// @class WatchpointList WatchpointList.h "lldb/Breakpoint/WatchpointList.h"
comment|/// @brief This class is used by Watchpoint to manage a list of watchpoints,
comment|//  each watchpoint in the list has a unique ID, and is unique by Address as
comment|//  well.
comment|//----------------------------------------------------------------------
name|class
name|WatchpointList
block|{
comment|// Only Target can make the watchpoint list, or add elements to it.
comment|// This is not just some random collection of watchpoints.  Rather, the act of
comment|// adding the watchpoint to this list sets its ID.
name|friend
name|class
name|Watchpoint
decl_stmt|;
name|friend
name|class
name|Target
decl_stmt|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor makes an empty list.
comment|//------------------------------------------------------------------
name|WatchpointList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor, currently does nothing.
comment|//------------------------------------------------------------------
operator|~
name|WatchpointList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a Watchpoint to the list.
comment|///
comment|/// @param[in] wp_sp
comment|///    A shared pointer to a watchpoint being added to the list.
comment|///
comment|/// @return
comment|///    The ID of the Watchpoint in the list.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|watch_id_t
name|Add
argument_list|(
argument|const lldb::WatchpointSP& wp_sp
argument_list|,
argument|bool notify
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Standard "Dump" method.
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
comment|/// Dump with lldb::DescriptionLevel.
comment|//------------------------------------------------------------------
name|void
name|DumpWithLevel
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|description_level
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the watchpoint at address
comment|/// \a addr -
comment|/// const version.
comment|///
comment|/// @param[in] addr
comment|///     The address to look for.
comment|///
comment|/// @result
comment|///     A shared pointer to the watchpoint.  May contain a NULL
comment|///     pointer if the watchpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|WatchpointSP
name|FindByAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the watchpoint with watchpoint spec
comment|/// \a spec -
comment|/// const version.
comment|///
comment|/// @param[in] spec
comment|///     The watchpoint spec to look for.
comment|///
comment|/// @result
comment|///     A shared pointer to the watchpoint.  May contain a NULL
comment|///     pointer if the watchpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|WatchpointSP
name|FindBySpec
argument_list|(
argument|std::string spec
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the watchpoint with id
comment|/// \a watchID, const
comment|/// version.
comment|///
comment|/// @param[in] watchID
comment|///     The watchpoint location ID to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the watchpoint.  May contain a NULL
comment|///     pointer if the watchpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|WatchpointSP
name|FindByID
argument_list|(
argument|lldb::watch_id_t watchID
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the watchpoint id to the watchpoint
comment|/// at address \a addr.
comment|///
comment|/// @param[in] addr
comment|///     The address to match.
comment|///
comment|/// @result
comment|///     The ID of the watchpoint, or LLDB_INVALID_WATCH_ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|watch_id_t
name|FindIDByAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the watchpoint id to the watchpoint
comment|/// with watchpoint spec \a spec.
comment|///
comment|/// @param[in] spec
comment|///     The watchpoint spec to match.
comment|///
comment|/// @result
comment|///     The ID of the watchpoint, or LLDB_INVALID_WATCH_ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|watch_id_t
name|FindIDBySpec
argument_list|(
argument|std::string spec
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the watchpoint with index \a i.
comment|///
comment|/// @param[in] i
comment|///     The watchpoint index to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the watchpoint.  May contain a NULL pointer if
comment|///     the watchpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|WatchpointSP
name|GetByIndex
argument_list|(
argument|uint32_t i
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the watchpoint with index \a i, const
comment|/// version.
comment|///
comment|/// @param[in] i
comment|///     The watchpoint index to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the watchpoint.  May contain a NULL pointer if
comment|///     the watchpoint location doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|WatchpointSP
name|GetByIndex
argument_list|(
argument|uint32_t i
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes the watchpoint given by \b watchID from this list.
comment|///
comment|/// @param[in] watchID
comment|///   The watchpoint ID to remove.
comment|///
comment|/// @result
comment|///   \b true if the watchpoint \a watchID was in the list.
comment|//------------------------------------------------------------------
name|bool
name|Remove
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watchID
argument_list|,
name|bool
name|notify
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number hit count of all watchpoints in this list.
comment|///
comment|/// @result
comment|///     Hit count of all watchpoints in this list.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetHitCount
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Enquires of the watchpoint in this list with ID \a watchID whether we
comment|/// should stop.
comment|///
comment|/// @param[in] context
comment|///     This contains the information about this stop.
comment|///
comment|/// @param[in] watchID
comment|///     This watch ID that we hit.
comment|///
comment|/// @return
comment|///     \b true if we should stop, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ShouldStop
argument_list|(
name|StoppointCallbackContext
operator|*
name|context
argument_list|,
name|lldb
operator|::
name|watch_id_t
name|watchID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of elements in this watchpoint list.
comment|///
comment|/// @result
comment|///     The number of elements.
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
name|m_watchpoints
operator|.
name|size
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Print a description of the watchpoints in this list to the stream \a s.
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
name|void
name|SetEnabledAll
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|void
name|RemoveAll
parameter_list|(
name|bool
name|notify
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sets the passed in Locker to hold the Watchpoint List mutex.
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
name|WatchpointSP
operator|>
name|wp_collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|watch_id_t
operator|>
name|id_vector
expr_stmt|;
name|id_vector
name|GetWatchpointIDs
argument_list|()
specifier|const
expr_stmt|;
name|wp_collection
operator|::
name|iterator
name|GetIDIterator
argument_list|(
argument|lldb::watch_id_t watchID
argument_list|)
expr_stmt|;
name|wp_collection
operator|::
name|const_iterator
name|GetIDConstIterator
argument_list|(
argument|lldb::watch_id_t watchID
argument_list|)
specifier|const
expr_stmt|;
name|wp_collection
name|m_watchpoints
decl_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|lldb
operator|::
name|watch_id_t
name|m_next_wp_id
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
comment|// liblldb_WatchpointList_h_
end_comment

end_unit

