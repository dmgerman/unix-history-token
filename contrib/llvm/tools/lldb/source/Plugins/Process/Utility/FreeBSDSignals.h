begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FreeBSDSignals.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_FreeBSDSignals_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FreeBSDSignals_H_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/UnixSignals.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|/// FreeBSD specific set of Unix signals.
name|class
name|FreeBSDSignals
range|:
name|public
name|UnixSignals
block|{
name|public
operator|:
name|FreeBSDSignals
argument_list|()
block|;
name|private
operator|:
name|void
name|Reset
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
comment|// liblldb_FreeBSDSignals_H_
end_comment

end_unit

