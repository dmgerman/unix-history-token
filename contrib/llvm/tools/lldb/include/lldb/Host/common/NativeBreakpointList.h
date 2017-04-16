begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeBreakpointList.h ----------------------------------*- C++ -*-===//
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
name|liblldb_NativeBreakpointList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeBreakpointList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_comment
comment|// #include "lldb/Host/NativeBreakpoint.h"
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct|struct
name|HardwareBreakpoint
block|{
name|lldb
operator|::
name|addr_t
name|m_addr
expr_stmt|;
name|size_t
name|m_size
decl_stmt|;
block|}
struct|;
name|using
name|HardwareBreakpointMap
init|=
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
decl_stmt|,
name|HardwareBreakpoint
decl|>
decl_stmt|;
name|class
name|NativeBreakpointList
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|Error
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size_hint
argument_list|,
argument|bool hardware
argument_list|,
argument|NativeBreakpointSP&breakpoint_sp
argument_list|)
operator|>
name|CreateBreakpointFunc
expr_stmt|;
name|NativeBreakpointList
argument_list|()
expr_stmt|;
name|Error
name|AddRef
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size_hint
argument_list|,
name|bool
name|hardware
argument_list|,
name|CreateBreakpointFunc
name|create_func
argument_list|)
decl_stmt|;
name|Error
name|DecRef
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
name|Error
name|EnableBreakpoint
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
name|Error
name|DisableBreakpoint
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
name|Error
name|GetBreakpoint
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|NativeBreakpointSP
operator|&
name|breakpoint_sp
argument_list|)
decl_stmt|;
name|Error
name|RemoveTrapsFromBuffer
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|buf
argument_list|,
name|size_t
name|size
argument_list|)
decl|const
decl_stmt|;
name|private
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
name|NativeBreakpointSP
operator|>
name|BreakpointMap
expr_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|BreakpointMap
name|m_breakpoints
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef liblldb_NativeBreakpointList_h_
end_comment

end_unit

