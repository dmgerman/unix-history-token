begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamCallback.h -----------------------------------*- C++ -*-===//
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
name|liblldb_StreamCallback_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamCallback_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamCallback
range|:
name|public
name|llvm
operator|::
name|raw_ostream
block|{
name|public
operator|:
name|StreamCallback
argument_list|(
argument|lldb::LogOutputCallback callback
argument_list|,
argument|void *baton
argument_list|)
block|;
operator|~
name|StreamCallback
argument_list|()
name|override
operator|=
expr|default
block|;
name|private
operator|:
name|lldb
operator|::
name|LogOutputCallback
name|m_callback
block|;
name|void
operator|*
name|m_baton
block|;
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
name|uint64_t
name|current_pos
argument_list|()
specifier|const
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
comment|// liblldb_StreamCallback_h
end_comment

end_unit

