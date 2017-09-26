begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointSite.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointSite_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointSite_h_
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
file|<mutex>
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
file|"lldb/Breakpoint/BreakpointLocationCollection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/StoppointLocation.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointSite BreakpointSite.h "lldb/Breakpoint/BreakpointSite.h"
comment|/// @brief Class that manages the actual breakpoint that will be inserted
comment|/// into the running program.
comment|///
comment|/// The BreakpointSite class handles the physical breakpoint that is
comment|/// actually inserted in the target program.  As such, it is also the
comment|/// one that  gets hit, when the program stops. It keeps a list of all
comment|/// BreakpointLocations that share this physical site. When the
comment|/// breakpoint is hit, all the locations are informed by the breakpoint
comment|/// site. Breakpoint sites are owned by the process.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointSite
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|BreakpointSite
operator|>
decl_stmt|,
name|public
name|StoppointLocation
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|eSoftware
block|,
comment|// Breakpoint opcode has been written to memory and
comment|// m_saved_opcode
comment|// and m_trap_opcode contain the saved and written opcode.
name|eHardware
block|,
comment|// Breakpoint site is set as a hardware breakpoint
name|eExternal
comment|// Breakpoint site is managed by an external debug nub or
comment|// debug interface where memory reads transparently will not
comment|// display any breakpoint opcodes.
block|}
enum|;
operator|~
name|BreakpointSite
argument_list|()
name|override
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// This section manages the breakpoint traps
comment|//----------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// Returns the Opcode Bytes for this breakpoint
comment|//------------------------------------------------------------------
name|uint8_t
modifier|*
name|GetTrapOpcodeBytes
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the Opcode Bytes for this breakpoint - const version
comment|//------------------------------------------------------------------
specifier|const
name|uint8_t
operator|*
name|GetTrapOpcodeBytes
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the size of the trap opcode for this address
comment|//------------------------------------------------------------------
name|size_t
name|GetTrapOpcodeMaxByteSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets the trap opcode
comment|//------------------------------------------------------------------
name|bool
name|SetTrapOpcode
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|trap_opcode
parameter_list|,
name|uint32_t
name|trap_opcode_size
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the original instruction bytes that were overwritten by the trap
comment|//------------------------------------------------------------------
name|uint8_t
modifier|*
name|GetSavedOpcodeBytes
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the original instruction bytes that were overwritten by the trap
comment|/// const version
comment|//------------------------------------------------------------------
specifier|const
name|uint8_t
operator|*
name|GetSavedOpcodeBytes
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Says whether \a addr and size \a size intersects with the address \a
comment|/// intersect_addr
comment|//------------------------------------------------------------------
name|bool
name|IntersectsRange
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|,
name|lldb
operator|::
name|addr_t
operator|*
name|intersect_addr
argument_list|,
name|size_t
operator|*
name|intersect_size
argument_list|,
name|size_t
operator|*
name|opcode_offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Tells whether the current breakpoint site is enabled or not
comment|///
comment|/// This is a low-level enable bit for the breakpoint sites.  If a
comment|/// breakpoint site has no enabled owners, it should just get
comment|/// removed.  This enable/disable is for the low-level target code
comment|/// to enable and disable breakpoint sites when single stepping,
comment|/// etc.
comment|//------------------------------------------------------------------
name|bool
name|IsEnabled
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets whether the current breakpoint site is enabled or not
comment|///
comment|/// @param[in] enabled
comment|///    \b true if the breakpoint is enabled, \b false otherwise.
comment|//------------------------------------------------------------------
name|void
name|SetEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Enquires of the breakpoint locations that produced this breakpoint site
comment|/// whether
comment|/// we should stop at this location.
comment|///
comment|/// @param[in] context
comment|///    This contains the information about this stop.
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
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Standard Dump method
comment|///
comment|/// @param[in] context
comment|///    The stream to dump this output.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// The "Owners" are the breakpoint locations that share this
comment|/// breakpoint site. The method adds the \a owner to this breakpoint
comment|/// site's owner list.
comment|///
comment|/// @param[in] context
comment|///    \a owner is the Breakpoint Location to add.
comment|//------------------------------------------------------------------
name|void
name|AddOwner
argument_list|(
specifier|const
name|lldb
operator|::
name|BreakpointLocationSP
operator|&
name|owner
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// This method returns the number of breakpoint locations currently
comment|/// located at this breakpoint site.
comment|///
comment|/// @return
comment|///    The number of owners.
comment|//------------------------------------------------------------------
name|size_t
name|GetNumberOfOwners
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This method returns the breakpoint location at index \a index
comment|/// located at this breakpoint site.  The owners are listed ordinally
comment|/// from 0 to GetNumberOfOwners() - 1 so you can use this method to iterate
comment|/// over the owners
comment|///
comment|/// @param[in] index
comment|///     The index in the list of owners for which you wish the owner location.
comment|/// @return
comment|///    A shared pointer to the breakpoint location at that index.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|BreakpointLocationSP
name|GetOwnerAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// This method copies the breakpoint site's owners into a new collection.
comment|/// It does this while the owners mutex is locked.
comment|///
comment|/// @param[out] out_collection
comment|///    The BreakpointLocationCollection into which to put the owners
comment|///    of this breakpoint site.
comment|///
comment|/// @return
comment|///    The number of elements copied into out_collection.
comment|//------------------------------------------------------------------
name|size_t
name|CopyOwnersList
parameter_list|(
name|BreakpointLocationCollection
modifier|&
name|out_collection
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check whether the owners of this breakpoint site have any
comment|/// thread specifiers, and if yes, is \a thread contained in any
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
comment|/// Print a description of this breakpoint site to the stream \a s.
comment|/// GetDescription tells you about the breakpoint site's owners.
comment|/// Use BreakpointSite::Dump(Stream *) to get information about the
comment|/// breakpoint site itself.
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
comment|/// Tell whether a breakpoint has a location at this site.
comment|///
comment|/// @param[in] bp_id
comment|///     The breakpoint id to query.
comment|///
comment|/// @result
comment|///     \b true if bp_id has a location that is at this site,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsBreakpointAtThisSite
argument_list|(
name|lldb
operator|::
name|break_id_t
name|bp_id
argument_list|)
decl_stmt|;
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
name|BreakpointSite
operator|::
name|Type
name|GetType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|void
name|SetType
argument_list|(
name|BreakpointSite
operator|::
name|Type
name|type
argument_list|)
block|{
name|m_type
operator|=
name|type
expr_stmt|;
block|}
name|private
label|:
name|friend
name|class
name|Process
decl_stmt|;
name|friend
name|class
name|BreakpointLocation
decl_stmt|;
comment|// The StopInfoBreakpoint knows when it is processing a hit for a thread for a
comment|// site, so let it be the
comment|// one to manage setting the location hit count once and only once.
name|friend
name|class
name|StopInfoBreakpoint
decl_stmt|;
name|void
name|BumpHitCounts
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// The method removes the owner at \a break_loc_id from this breakpoint list.
comment|///
comment|/// @param[in] context
comment|///    \a break_loc_id is the Breakpoint Location to remove.
comment|//------------------------------------------------------------------
name|size_t
name|RemoveOwner
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
name|BreakpointSite
operator|::
name|Type
name|m_type
expr_stmt|;
comment|///< The type of this breakpoint site.
name|uint8_t
name|m_saved_opcode
index|[
literal|8
index|]
decl_stmt|;
comment|///< The saved opcode bytes if this breakpoint site
comment|///uses trap opcodes.
name|uint8_t
name|m_trap_opcode
index|[
literal|8
index|]
decl_stmt|;
comment|///< The opcode that was used to create the
comment|///breakpoint if it is a software breakpoint site.
name|bool
name|m_enabled
decl_stmt|;
comment|///< Boolean indicating if this breakpoint site enabled or not.
comment|// Consider adding an optimization where if there is only one
comment|// owner, we don't store a list.  The usual case will be only one owner...
name|BreakpointLocationCollection
name|m_owners
decl_stmt|;
comment|///< This has the BreakpointLocations
comment|///that share this breakpoint site.
name|std
operator|::
name|recursive_mutex
name|m_owners_mutex
expr_stmt|;
comment|///< This mutex protects the owners collection.
specifier|static
name|lldb
operator|::
name|break_id_t
name|GetNextID
argument_list|()
expr_stmt|;
comment|// Only the Process can create breakpoint sites in
comment|// Process::CreateBreakpointSite (lldb::BreakpointLocationSP&, bool).
name|BreakpointSite
argument_list|(
argument|BreakpointSiteList *list
argument_list|,
argument|const lldb::BreakpointLocationSP&owner
argument_list|,
argument|lldb::addr_t m_addr
argument_list|,
argument|bool use_hardware
argument_list|)
empty_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointSite
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
comment|// liblldb_BreakpointSite_h_
end_comment

end_unit

