begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SoftwareBreakpoint.h ------------------------------------*- C++ -*-===//
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
name|liblldb_SoftwareBreakpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SoftwareBreakpoint_h_
end_define

begin_include
include|#
directive|include
file|"NativeBreakpoint.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SoftwareBreakpoint
range|:
name|public
name|NativeBreakpoint
block|{
name|friend
name|class
name|NativeBreakpointList
block|;
name|public
operator|:
specifier|static
name|Status
name|CreateSoftwareBreakpoint
argument_list|(
argument|NativeProcessProtocol&process
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|size_t size_hint
argument_list|,
argument|NativeBreakpointSP&breakpoint_spn
argument_list|)
block|;
name|SoftwareBreakpoint
argument_list|(
argument|NativeProcessProtocol&process
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|const uint8_t *saved_opcodes
argument_list|,
argument|const uint8_t *trap_opcodes
argument_list|,
argument|size_t opcode_size
argument_list|)
block|;
name|protected
operator|:
name|Status
name|DoEnable
argument_list|()
name|override
block|;
name|Status
name|DoDisable
argument_list|()
name|override
block|;
name|bool
name|IsSoftwareBreakpoint
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
comment|/// Max number of bytes that a software trap opcode sequence can occupy.
specifier|static
specifier|const
name|size_t
name|MAX_TRAP_OPCODE_SIZE
operator|=
literal|8
block|;
name|NativeProcessProtocol
operator|&
name|m_process
block|;
name|uint8_t
name|m_saved_opcodes
index|[
name|MAX_TRAP_OPCODE_SIZE
index|]
block|;
name|uint8_t
name|m_trap_opcodes
index|[
name|MAX_TRAP_OPCODE_SIZE
index|]
block|;
specifier|const
name|size_t
name|m_opcode_size
block|;
specifier|static
name|Status
name|EnableSoftwareBreakpoint
argument_list|(
argument|NativeProcessProtocol&process
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|size_t bp_opcode_size
argument_list|,
argument|const uint8_t *bp_opcode_bytes
argument_list|,
argument|uint8_t *saved_opcode_bytes
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_SoftwareBreakpoint_h_
end_comment

end_unit

