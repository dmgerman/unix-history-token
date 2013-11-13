begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointSiteList.h ------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointSiteList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointSiteList_h_
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<functional>
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
file|"lldb/Breakpoint/BreakpointSite.h"
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
comment|/// @class BreakpointSiteList BreakpointSiteList.h "lldb/Breakpoint/BreakpointSiteList.h"
comment|/// @brief Class that manages lists of BreakpointSite shared pointers.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointSiteList
block|{
comment|// At present Process directly accesses the map of BreakpointSites so it can
comment|// do quick lookups into the map (using GetMap).
comment|// FIXME: Find a better interface for this.
name|friend
name|class
name|Process
decl_stmt|;
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor makes an empty list.
comment|//------------------------------------------------------------------
name|BreakpointSiteList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor, currently does nothing.
comment|//------------------------------------------------------------------
operator|~
name|BreakpointSiteList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a BreakpointSite to the list.
comment|///
comment|/// @param[in] bp_site_sp
comment|///    A shared pointer to a breakpoint site being added to the list.
comment|///
comment|/// @return
comment|///    The ID of the BreakpointSite in the list.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|Add
argument_list|(
specifier|const
name|lldb
operator|::
name|BreakpointSiteSP
operator|&
name|bp_site_sp
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Standard Dump routine, doesn't do anything at present.
comment|/// @param[in] s
comment|///     Stream into which to dump the description.
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
comment|/// Returns a shared pointer to the breakpoint site at address
comment|/// \a addr.
comment|///
comment|/// @param[in] addr
comment|///     The address to look for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint site. May contain a NULL
comment|///     pointer if no breakpoint site exists with a matching address.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointSiteSP
name|FindByAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint site with id \a breakID.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint site ID to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint site.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointSiteSP
name|FindByID
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint site with id \a breakID - const version.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint site ID to seek for.
comment|///
comment|/// @result
comment|///   A shared pointer to the breakpoint site.  May contain a NULL pointer if the
comment|///   breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointSiteSP
name|FindByID
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the breakpoint site id to the breakpoint site at address \a addr.
comment|///
comment|/// @param[in] addr
comment|///   The address to match.
comment|///
comment|/// @result
comment|///   The ID of the breakpoint site, or LLDB_INVALID_BREAK_ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|FindIDByAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns whether the breakpoint site \a bp_site_id has \a bp_id
comment|//  as one of its owners.
comment|///
comment|/// @param[in] bp_site_id
comment|///   The breakpoint site id to query.
comment|///
comment|/// @param[in] bp_id
comment|///   The breakpoint id to look for in \a bp_site_id.
comment|///
comment|/// @result
comment|///   True if \a bp_site_id exists in the site list AND \a bp_id is one of the
comment|///   owners of that site.
comment|//------------------------------------------------------------------
name|bool
name|BreakpointSiteContainsBreakpoint
argument_list|(
name|lldb
operator|::
name|break_id_t
name|bp_site_id
argument_list|,
name|lldb
operator|::
name|break_id_t
name|bp_id
argument_list|)
decl_stmt|;
name|void
name|ForEach
argument_list|(
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|BreakpointSite
operator|*
argument_list|)
operator|>
specifier|const
operator|&
name|callback
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes the breakpoint site given by \b breakID from this list.
comment|///
comment|/// @param[in] breakID
comment|///   The breakpoint site index to remove.
comment|///
comment|/// @result
comment|///   \b true if the breakpoint site \a breakID was in the list.
comment|//------------------------------------------------------------------
name|bool
name|Remove
argument_list|(
name|lldb
operator|::
name|break_id_t
name|breakID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes the breakpoint site at address \a addr from this list.
comment|///
comment|/// @param[in] addr
comment|///   The address from which to remove a breakpoint site.
comment|///
comment|/// @result
comment|///   \b true if \a addr had a breakpoint site to remove from the list.
comment|//------------------------------------------------------------------
name|bool
name|RemoveByAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
name|bool
name|FindInRange
argument_list|(
name|lldb
operator|::
name|addr_t
name|lower_bound
argument_list|,
name|lldb
operator|::
name|addr_t
name|upper_bound
argument_list|,
name|BreakpointSiteList
operator|&
name|bp_site_list
argument_list|)
decl|const
decl_stmt|;
typedef|typedef
name|void
argument_list|(
operator|*
name|BreakpointSiteSPMapFunc
argument_list|)
argument_list|(
name|lldb
operator|::
name|BreakpointSiteSP
operator|&
name|bp
argument_list|,
name|void
operator|*
name|baton
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Enquires of the breakpoint site on in this list with ID \a breakID whether
comment|/// we should stop for the breakpoint or not.
comment|///
comment|/// @param[in] context
comment|///    This contains the information about this stop.
comment|///
comment|/// @param[in] breakID
comment|///    This break ID that we hit.
comment|///
comment|/// @return
comment|///    \b true if we should stop, \b false otherwise.
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
name|break_id_t
name|breakID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of elements in the list.
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
name|m_bp_site_list
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|IsEmpty
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
name|m_bp_site_list
operator|.
name|empty
argument_list|()
return|;
block|}
name|protected
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|BreakpointSiteSP
operator|>
name|collection
expr_stmt|;
name|collection
operator|::
name|iterator
name|GetIDIterator
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
expr_stmt|;
name|collection
operator|::
name|const_iterator
name|GetIDConstIterator
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
specifier|const
expr_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|collection
name|m_bp_site_list
decl_stmt|;
comment|// The breakpoint site list.
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
comment|// liblldb_BreakpointSiteList_h_
end_comment

end_unit

