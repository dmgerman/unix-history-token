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
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class POSIXBreakpointProtocol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @brief Extends RegisterClass with a few virtual operations useful on POSIX.
end_comment

begin_decl_stmt
name|class
name|POSIXBreakpointProtocol
block|{
name|public
label|:
name|POSIXBreakpointProtocol
argument_list|()
block|{
name|m_watchpoints_initialized
operator|=
name|false
expr_stmt|;
block|}
name|virtual
operator|~
name|POSIXBreakpointProtocol
argument_list|()
block|{}
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
operator|=
literal|0
expr_stmt|;
comment|/// Determines the index in lldb's register file given a kernel byte offset.
name|virtual
name|unsigned
name|GetRegisterIndexFromOffset
parameter_list|(
name|unsigned
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Checks to see if a watchpoint specified by hw_index caused the inferior
comment|// to stop.
name|virtual
name|bool
name|IsWatchpointHit
parameter_list|(
name|uint32_t
name|hw_index
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Resets any watchpoints that have been hit.
name|virtual
name|bool
name|ClearWatchpointHits
parameter_list|()
init|=
literal|0
function_decl|;
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|IsWatchpointVacant
parameter_list|(
name|uint32_t
name|hw_index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|SetHardwareWatchpointWithIndex
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|,
name|bool
name|read
argument_list|,
name|bool
name|write
argument_list|,
name|uint32_t
name|hw_index
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// From lldb_private::RegisterContext
name|virtual
name|uint32_t
name|NumSupportedHardwareWatchpoints
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Force m_watchpoints_initialized to TRUE
name|void
name|ForceWatchpointsInitialized
parameter_list|()
block|{
name|m_watchpoints_initialized
operator|=
name|true
expr_stmt|;
block|}
name|protected
label|:
name|bool
name|m_watchpoints_initialized
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class RegisterInfoInterface
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @brief RegisterInfo interface to patch RegisterInfo structure for archs.
end_comment

begin_decl_stmt
name|class
name|RegisterInfoInterface
block|{
name|public
label|:
name|RegisterInfoInterface
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
operator|:
name|m_target_arch
argument_list|(
argument|target_arch
argument_list|)
block|{}
name|virtual
operator|~
name|RegisterInfoInterface
argument_list|()
block|{}
name|virtual
name|size_t
name|GetGPRSize
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
operator|=
literal|0
expr_stmt|;
name|public
label|:
name|lldb_private
operator|::
name|ArchSpec
name|m_target_arch
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContextPOSIX_H_
end_comment

end_unit

