begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AbstractSocket.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_AbstractSocket_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AbstractSocket_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/posix/DomainSocket.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AbstractSocket
range|:
name|public
name|DomainSocket
block|{
name|public
operator|:
name|AbstractSocket
argument_list|(
argument|bool child_processes_inherit
argument_list|)
block|;
name|protected
operator|:
name|size_t
name|GetNameOffset
argument_list|()
specifier|const
name|override
block|;
name|void
name|DeleteSocketFile
argument_list|(
argument|llvm::StringRef name
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
comment|// ifndef liblldb_AbstractSocket_h_
end_comment

end_unit

