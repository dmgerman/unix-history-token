begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointLocationList.h --------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointLocationList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointLocationList_h_
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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
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
comment|/// @class BreakpointLocationList BreakpointLocationList.h "lldb/Breakpoint/BreakpointLocationList.h"
comment|/// @brief This class is used by Breakpoint to manage a list of breakpoint locations,
comment|//  each breakpoint location in the list
comment|/// has a unique ID, and is unique by Address as well.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointLocationList
block|{
comment|// Only Breakpoints can make the location list, or add elements to it.
comment|// This is not just some random collection of locations.  Rather, the act of adding the location
comment|// to this list sets its ID, and implicitly all the locations have the same breakpoint ID as
comment|// well.  If you need a generic container for breakpoint locations, use BreakpointLocationCollection.
name|friend
name|class
name|Breakpoint
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|BreakpointLocationList
argument_list|()
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
comment|/// Returns a shared pointer to the breakpoint location at address
comment|/// \a addr - const version.
comment|///
comment|/// @param[in] addr
comment|///     The address to look for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
name|FindByAddress
argument_list|(
argument|const Address&addr
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with id
comment|/// \a breakID, const version.
comment|///
comment|/// @param[in] breakID
comment|///     The breakpoint location ID to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|FindByID
argument_list|(
argument|lldb::break_id_t breakID
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the breakpoint location id to the breakpoint location
comment|/// at address \a addr.
comment|///
comment|/// @param[in] addr
comment|///     The address to match.
comment|///
comment|/// @result
comment|///     The ID of the breakpoint location, or LLDB_INVALID_BREAK_ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|FindIDByAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a breakpoint location list of the breakpoint locations
comment|/// in the module \a module.  This list is allocated, and owned by
comment|/// the caller.
comment|///
comment|/// @param[in] module
comment|///     The module to seek in.
comment|///
comment|/// @param[in]
comment|///     A breakpoint collection that gets any breakpoint locations
comment|///     that match \a module appended to.
comment|///
comment|/// @result
comment|///     The number of matches
comment|//------------------------------------------------------------------
name|size_t
name|FindInModule
parameter_list|(
name|Module
modifier|*
name|module
parameter_list|,
name|BreakpointLocationCollection
modifier|&
name|bp_loc_list
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with
comment|/// index \a i.
comment|///
comment|/// @param[in] i
comment|///     The breakpoint location index to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|GetByIndex
argument_list|(
argument|size_t i
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with index
comment|/// \a i, const version.
comment|///
comment|/// @param[in] i
comment|///     The breakpoint location index to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
name|GetByIndex
argument_list|(
argument|size_t i
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes all the locations in this list from their breakpoint site
comment|/// owners list.
comment|//------------------------------------------------------------------
name|void
name|ClearAllBreakpointSites
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tells all the breakopint locations in this list to attempt to
comment|/// resolve any possible breakpoint sites.
comment|//------------------------------------------------------------------
name|void
name|ResolveAllBreakpointSites
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of breakpoint locations in this list with
comment|/// resolved breakpoints.
comment|///
comment|/// @result
comment|///     Number of qualifying breakpoint locations.
comment|//------------------------------------------------------------------
name|size_t
name|GetNumResolvedLocations
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number hit count of all locations in this list.
comment|///
comment|/// @result
comment|///     Hit count of all locations in this list.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetHitCount
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Enquires of the breakpoint location in this list with ID \a
comment|/// breakID whether we should stop.
comment|///
comment|/// @param[in] context
comment|///     This contains the information about this stop.
comment|///
comment|/// @param[in] breakID
comment|///     This break ID that we hit.
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
name|break_id_t
name|breakID
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the number of elements in this breakpoint location list.
comment|///
comment|/// @result
comment|///     The number of elements.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_locations
operator|.
name|size
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Print a description of the breakpoint locations in this list to
comment|/// the stream \a s.
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
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// This is the standard constructor.
comment|///
comment|/// It creates an empty breakpoint location list. It is protected
comment|/// here because only Breakpoints are allowed to create the
comment|/// breakpoint location list.
comment|//------------------------------------------------------------------
name|BreakpointLocationList
argument_list|(
name|Breakpoint
operator|&
name|owner
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add the breakpoint \a bp_loc_sp to the list.
comment|///
comment|/// @param[in] bp_sp
comment|///     Shared pointer to the breakpoint location that will get
comment|///     added to the list.
comment|///
comment|/// @result
comment|///     Returns breakpoint location id.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|Create
argument_list|(
argument|const Address&addr
argument_list|,
argument|bool resolve_indirect_symbols
argument_list|)
expr_stmt|;
name|void
name|StartRecordingNewLocations
parameter_list|(
name|BreakpointLocationCollection
modifier|&
name|new_locations
parameter_list|)
function_decl|;
name|void
name|StopRecordingNewLocations
parameter_list|()
function_decl|;
name|lldb
operator|::
name|BreakpointLocationSP
name|AddLocation
argument_list|(
argument|const Address&addr
argument_list|,
argument|bool resolve_indirect_symbols
argument_list|,
argument|bool *new_location = NULL
argument_list|)
expr_stmt|;
name|bool
name|RemoveLocation
argument_list|(
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
operator|&
name|bp_loc_sp
argument_list|)
decl_stmt|;
name|void
name|RemoveInvalidLocations
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|BreakpointLocationSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb_private
operator|::
name|Address
operator|,
name|lldb
operator|::
name|BreakpointLocationSP
operator|,
name|Address
operator|::
name|ModulePointerAndOffsetLessThanFunctionObject
operator|>
name|addr_map
expr_stmt|;
name|Breakpoint
modifier|&
name|m_owner
decl_stmt|;
name|collection
name|m_locations
decl_stmt|;
comment|// Vector of locations, sorted by ID
name|addr_map
name|m_address_to_location
decl_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
name|lldb
operator|::
name|break_id_t
name|m_next_id
expr_stmt|;
name|BreakpointLocationCollection
modifier|*
name|m_new_location_recorder
decl_stmt|;
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
comment|// liblldb_BreakpointLocationList_h_
end_comment

end_unit

