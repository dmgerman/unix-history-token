begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessWindows.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_Common_ProcessWindows_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_Common_ProcessWindows_H_
end_define

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ProcessWindows
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and destructors
comment|//------------------------------------------------------------------
name|ProcessWindows
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|)
block|;
operator|~
name|ProcessWindows
argument_list|()
block|;
name|size_t
name|GetSTDOUT
argument_list|(
argument|char *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|size_t
name|GetSTDERR
argument_list|(
argument|char *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|size_t
name|PutSTDIN
argument_list|(
argument|const char *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|protected
operator|:
comment|// These decode the page protection bits.
specifier|static
name|bool
name|IsPageReadable
argument_list|(
argument|uint32_t protect
argument_list|)
block|;
specifier|static
name|bool
name|IsPageWritable
argument_list|(
argument|uint32_t protect
argument_list|)
block|;
specifier|static
name|bool
name|IsPageExecutable
argument_list|(
argument|uint32_t protect
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
comment|// liblldb_Plugins_Process_Windows_Common_ProcessWindows_H_
end_comment

end_unit

