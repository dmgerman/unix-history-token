begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemInitializerCommon.h -------------------------------*- C++ -*-===//
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
name|LLDB_INITIALIZATION_SYSTEM_INITIALIZER_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_INITIALIZATION_SYSTEM_INITIALIZER_COMMON_H
end_define

begin_include
include|#
directive|include
file|"SystemInitializer.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|/// Initializes common lldb functionality.
comment|///
comment|/// This class is responsible for initializing a subset of lldb
comment|/// useful to both debug servers and debug clients.  Debug servers
comment|/// do not use all of LLDB and desire small binary sizes, so this
comment|/// functionality is separate.  This class is used by constructing
comment|/// an instance of SystemLifetimeManager with this class passed to
comment|/// the constructor.
comment|//------------------------------------------------------------------
name|class
name|SystemInitializerCommon
range|:
name|public
name|SystemInitializer
block|{
name|public
operator|:
name|SystemInitializerCommon
argument_list|()
block|;
operator|~
name|SystemInitializerCommon
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
comment|// LLDB_INITIALIZATION_SYSTEM_INITIALIZER_COMMON_H
end_comment

end_unit

