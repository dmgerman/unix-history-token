begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointLocationCollection.h --------------------------*- C++ -*-===//
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
name|liblldb_BreakpointLocationCollection_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointLocationCollection_h_
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
file|"lldb/Utility/Iterable.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|BreakpointLocationCollection
block|{
name|public
label|:
name|BreakpointLocationCollection
argument_list|()
expr_stmt|;
operator|~
name|BreakpointLocationCollection
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add the breakpoint \a bp_loc_sp to the list.
comment|///
comment|/// @param[in] bp_sp
comment|///     Shared pointer to the breakpoint location that will get added
comment|///     to the list.
comment|///
comment|/// @result
comment|///     Returns breakpoint location id.
comment|//------------------------------------------------------------------
name|void
name|Add
argument_list|(
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
operator|&
name|bp_loc_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Removes the breakpoint location given by \b breakID from this
comment|/// list.
comment|///
comment|/// @param[in] break_id
comment|///     The breakpoint index to remove.
comment|///
comment|/// @param[in] break_loc_id
comment|///     The breakpoint location index in break_id to remove.
comment|///
comment|/// @result
comment|///     \b true if the breakpoint was in the list.
comment|//------------------------------------------------------------------
name|bool
name|Remove
argument_list|(
name|lldb
operator|::
name|break_id_t
name|break_id
argument_list|,
name|lldb
operator|::
name|break_id_t
name|break_loc_id
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with id \a
comment|/// breakID.
comment|///
comment|/// @param[in] break_id
comment|///     The breakpoint  ID to seek for.
comment|///
comment|/// @param[in] break_loc_id
comment|///     The breakpoint location ID in \a break_id to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|FindByIDPair
argument_list|(
argument|lldb::break_id_t break_id
argument_list|,
argument|lldb::break_id_t break_loc_id
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with id \a
comment|/// breakID, const version.
comment|///
comment|/// @param[in] breakID
comment|///     The breakpoint location ID to seek for.
comment|///
comment|/// @param[in] break_loc_id
comment|///     The breakpoint location ID in \a break_id to seek for.
comment|///
comment|/// @result
comment|///     A shared pointer to the breakpoint.  May contain a NULL
comment|///     pointer if the breakpoint doesn't exist.
comment|//------------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
name|FindByIDPair
argument_list|(
argument|lldb::break_id_t break_id
argument_list|,
argument|lldb::break_id_t break_loc_id
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a shared pointer to the breakpoint location with index
comment|/// \a i.
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
name|m_break_loc_collection
operator|.
name|size
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Enquires of all the breakpoint locations in this list whether
comment|/// we should stop at a hit at \a breakID.
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
parameter_list|(
name|StoppointCallbackContext
modifier|*
name|context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Print a description of the breakpoint locations in this list
comment|/// to the stream \a s.
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
comment|//------------------------------------------------------------------
comment|/// Check whether this collection of breakpoint locations have any
comment|/// thread specifiers, and if yes, is \a thread_id contained in any
comment|/// of these specifiers.
comment|///
comment|/// @param[in] thread
comment|///     The thread against which to test.
comment|///
comment|/// return
comment|///     \b true if the collection contains at least one location that
comment|///     would be valid for this thread, false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ValidForThisThread
parameter_list|(
name|Thread
modifier|*
name|thread
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tell whether ALL the breakpoints in the location collection are internal.
comment|///
comment|/// @result
comment|///     \b true if all breakpoint locations are owned by internal breakpoints,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsInternal
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from BreakpointLocationCollection can see
comment|// and modify these
comment|//------------------------------------------------------------------
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For BreakpointLocationCollection only
comment|//------------------------------------------------------------------
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
name|collection
operator|::
name|iterator
name|GetIDPairIterator
argument_list|(
argument|lldb::break_id_t break_id
argument_list|,
argument|lldb::break_id_t break_loc_id
argument_list|)
expr_stmt|;
name|collection
operator|::
name|const_iterator
name|GetIDPairConstIterator
argument_list|(
argument|lldb::break_id_t break_id
argument_list|,
argument|lldb::break_id_t break_loc_id
argument_list|)
specifier|const
expr_stmt|;
name|collection
name|m_break_loc_collection
decl_stmt|;
name|public
label|:
typedef|typedef
name|AdaptedIterable
operator|<
name|collection
operator|,
name|lldb
operator|::
name|BreakpointLocationSP
operator|,
name|vector_adapter
operator|>
name|BreakpointLocationCollectionIterable
expr_stmt|;
name|BreakpointLocationCollectionIterable
name|BreakpointLocations
parameter_list|()
block|{
return|return
name|BreakpointLocationCollectionIterable
argument_list|(
name|m_break_loc_collection
argument_list|)
return|;
block|}
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
comment|// liblldb_BreakpointLocationCollection_h_
end_comment

end_unit

