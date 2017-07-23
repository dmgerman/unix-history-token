begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeBreakpoint.h --------------------------------------*- C++ -*-===//
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
name|liblldb_NativeBreakpoint_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeBreakpoint_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|NativeBreakpointList
decl_stmt|;
name|class
name|NativeBreakpoint
block|{
name|friend
name|class
name|NativeBreakpointList
decl_stmt|;
name|public
label|:
comment|// The assumption is that derived breakpoints are enabled when created.
name|NativeBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|NativeBreakpoint
argument_list|()
expr_stmt|;
name|Status
name|Enable
parameter_list|()
function_decl|;
name|Status
name|Disable
parameter_list|()
function_decl|;
name|lldb
operator|::
name|addr_t
name|GetAddress
argument_list|()
specifier|const
block|{
return|return
name|m_addr
return|;
block|}
name|bool
name|IsEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_enabled
return|;
block|}
name|virtual
name|bool
name|IsSoftwareBreakpoint
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
specifier|const
name|lldb
operator|::
name|addr_t
name|m_addr
expr_stmt|;
name|int32_t
name|m_ref_count
decl_stmt|;
name|virtual
name|Status
name|DoEnable
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|Status
name|DoDisable
parameter_list|()
init|=
literal|0
function_decl|;
name|private
label|:
name|bool
name|m_enabled
decl_stmt|;
comment|// -----------------------------------------------------------
comment|// interface for NativeBreakpointList
comment|// -----------------------------------------------------------
name|void
name|AddRef
parameter_list|()
function_decl|;
name|int32_t
name|DecRef
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef liblldb_NativeBreakpoint_h_
end_comment

end_unit

