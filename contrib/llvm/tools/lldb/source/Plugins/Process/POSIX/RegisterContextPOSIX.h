begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX.h --------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_H_
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

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class RegisterContextPOSIX
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @brief Extends RegisterClass with a few virtual operations useful on POSIX.
end_comment

begin_decl_stmt
name|class
name|RegisterContextPOSIX
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextPOSIX
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
operator|:
name|RegisterContext
argument_list|(
argument|thread
argument_list|,
argument|concrete_frame_idx
argument_list|)
block|{
name|m_watchpoints_initialized
operator|=
name|false
block|; }
comment|/// Updates the register state of the associated thread after hitting a
comment|/// breakpoint (if that make sense for the architecture).  Default
comment|/// implementation simply returns true for architectures which do not
comment|/// require any update.
comment|///
comment|/// @return
comment|///    True if the operation succeeded and false otherwise.
name|virtual
name|bool
name|UpdateAfterBreakpoint
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|/// Determines the index in lldb's register file given a kernel byte offset.
name|virtual
name|unsigned
name|GetRegisterIndexFromOffset
argument_list|(
argument|unsigned offset
argument_list|)
block|{
return|return
name|LLDB_INVALID_REGNUM
return|;
block|}
comment|// Checks to see if a watchpoint specified by hw_index caused the inferior
comment|// to stop.
name|virtual
name|bool
name|IsWatchpointHit
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Resets any watchpoints that have been hit.
name|virtual
name|bool
name|ClearWatchpointHits
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|// Returns the watchpoint address associated with a watchpoint hardware
comment|// index.
name|virtual
name|lldb
operator|::
name|addr_t
name|GetWatchpointAddress
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
name|virtual
name|bool
name|IsWatchpointVacant
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|SetHardwareWatchpointWithIndex
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|uint32_t hw_index
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|protected
operator|:
name|bool
name|m_watchpoints_initialized
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContextPOSIX_H_
end_comment

end_unit

