begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostThreadFreeBSD.h -------------------------------------*- C++ -*-===//
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
name|lldb_Host_freebsd_HostThreadFreeBSD_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_freebsd_HostThreadFreeBSD_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/posix/HostThreadPosix.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostThreadFreeBSD
range|:
name|public
name|HostThreadPosix
block|{
name|public
operator|:
name|HostThreadFreeBSD
argument_list|()
block|;
name|HostThreadFreeBSD
argument_list|(
argument|lldb::thread_t thread
argument_list|)
block|;
specifier|static
name|void
name|GetName
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|llvm::SmallVectorImpl<char>&name
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

