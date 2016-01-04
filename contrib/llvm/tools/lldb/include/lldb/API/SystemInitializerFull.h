begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemInitializerFull.h ---------------------------------*- C++ -*-===//
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
name|LLDB_API_SYSTEM_INITIALIZER_FULL_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_API_SYSTEM_INITIALIZER_FULL_H
end_define

begin_include
include|#
directive|include
file|"lldb/Initialization/SystemInitializerCommon.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|/// Initializes lldb.
comment|///
comment|/// This class is responsible for initializing all of lldb system
comment|/// services needed to use the full LLDB application.  This class is
comment|/// not intended to be used externally, but is instead used
comment|/// internally by SBDebugger to initialize the system.
comment|//------------------------------------------------------------------
name|class
name|SystemInitializerFull
range|:
name|public
name|SystemInitializerCommon
block|{
name|public
operator|:
name|SystemInitializerFull
argument_list|()
block|;
operator|~
name|SystemInitializerFull
argument_list|()
name|override
block|;
name|void
name|Initialize
argument_list|()
name|override
block|;
name|void
name|Terminate
argument_list|()
name|override
block|;
name|private
operator|:
name|void
name|InitializeSWIG
argument_list|()
block|; }
decl_stmt|;
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
comment|// LLDB_API_SYSTEM_INITIALIZER_FULL_H
end_comment

end_unit

