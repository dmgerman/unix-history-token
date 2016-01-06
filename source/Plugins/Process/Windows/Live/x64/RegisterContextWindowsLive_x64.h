begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextWindowsLive_x64.h ------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextWindowsLive_x64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextWindowsLive_x64_H_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"../../Common/x64/RegisterContextWindows_x64.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Thread
decl_stmt|;
name|class
name|RegisterContextWindowsLive_x64
range|:
name|public
name|RegisterContextWindows_x64
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|RegisterContextWindowsLive_x64
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextWindowsLive_x64
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses must override these functions
comment|//------------------------------------------------------------------
name|bool
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|bool
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContextWindowsLive_x64_H_
end_comment

end_unit

