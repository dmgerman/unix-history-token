begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FreeBSDThread.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_FreeBSDThread_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FreeBSDThread_H_
end_define

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"POSIXThread.h"
end_include

begin_comment
comment|//------------------------------------------------------------------------------
end_comment

begin_comment
comment|// @class FreeBSDThread
end_comment

begin_comment
comment|// @brief Abstraction of a FreeBSD thread.
end_comment

begin_decl_stmt
name|class
name|FreeBSDThread
range|:
name|public
name|POSIXThread
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and destructors
comment|//------------------------------------------------------------------
name|FreeBSDThread
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
name|virtual
operator|~
name|FreeBSDThread
argument_list|()
block|;
comment|//--------------------------------------------------------------------------
comment|// FreeBSDThread internal API.
comment|// POSIXThread override
name|virtual
name|void
name|WillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_FreeBSDThread_H_
end_comment

end_unit

