begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StoppointLocation.h -------------------------------------*- C++ -*-===//
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
name|liblldb_StoppointLocation_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StoppointLocation_h_
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
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_comment
comment|// #include "lldb/Breakpoint/BreakpointOptions.h"
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StoppointLocation
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|StoppointLocation
argument_list|(
argument|lldb::break_id_t bid
argument_list|,
argument|lldb::addr_t m_addr
argument_list|,
argument|bool hardware
argument_list|)
empty_stmt|;
name|StoppointLocation
argument_list|(
argument|lldb::break_id_t bid
argument_list|,
argument|lldb::addr_t m_addr
argument_list|,
argument|uint32_t byte_size
argument_list|,
argument|bool hardware
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|StoppointLocation
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|// Methods
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|()
specifier|const
block|{
return|return
name|m_addr
return|;
block|}
name|virtual
name|void
name|SetLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
block|{
name|m_addr
operator|=
name|addr
expr_stmt|;
block|}
name|uint32_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_byte_size
return|;
block|}
name|uint32_t
name|GetHitCount
argument_list|()
specifier|const
block|{
return|return
name|m_hit_count
return|;
block|}
name|uint32_t
name|GetHardwareIndex
argument_list|()
specifier|const
block|{
return|return
name|m_hardware_index
return|;
block|}
name|bool
name|HardwareRequired
argument_list|()
specifier|const
block|{
return|return
name|m_hardware
return|;
block|}
name|virtual
name|bool
name|IsHardware
argument_list|()
specifier|const
block|{
return|return
name|m_hardware_index
operator|!=
name|LLDB_INVALID_INDEX32
return|;
block|}
name|virtual
name|bool
name|ShouldStop
parameter_list|(
name|StoppointCallbackContext
modifier|*
name|context
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|stream
argument_list|)
decl|const
block|{}
name|void
name|SetHardwareIndex
parameter_list|(
name|uint32_t
name|index
parameter_list|)
block|{
name|m_hardware_index
operator|=
name|index
expr_stmt|;
block|}
name|lldb
operator|::
name|break_id_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_loc_id
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from StoppointLocation can see and modify these
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|break_id_t
name|m_loc_id
expr_stmt|;
comment|// Stoppoint location ID
name|lldb
operator|::
name|addr_t
name|m_addr
expr_stmt|;
comment|// The load address of this stop point. The base Stoppoint doesn't
comment|// store a full Address since that's not needed for the breakpoint sites.
name|bool
name|m_hardware
decl_stmt|;
comment|// True if this point has been is required to use hardware
comment|// (which may fail due to lack of resources)
name|uint32_t
name|m_hardware_index
decl_stmt|;
comment|// The hardware resource index for this
comment|// breakpoint/watchpoint
name|uint32_t
name|m_byte_size
decl_stmt|;
comment|// The size in bytes of stop location.  e.g. the length
comment|// of the trap opcode for
comment|// software breakpoints, or the optional length in bytes for
comment|// hardware breakpoints, or the length of the watchpoint.
name|uint32_t
name|m_hit_count
decl_stmt|;
comment|// Number of times this breakpoint/watchpoint has been hit
comment|// If you override this, be sure to call the base class to increment the
comment|// internal counter.
name|void
name|IncrementHitCount
parameter_list|()
block|{
operator|++
name|m_hit_count
expr_stmt|;
block|}
name|void
name|DecrementHitCount
parameter_list|()
function_decl|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For StoppointLocation only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StoppointLocation
argument_list|)
expr_stmt|;
name|StoppointLocation
argument_list|()
expr_stmt|;
comment|// Disallow default constructor
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
comment|// liblldb_StoppointLocation_h_
end_comment

end_unit

