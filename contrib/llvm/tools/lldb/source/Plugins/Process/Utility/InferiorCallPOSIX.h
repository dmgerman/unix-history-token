begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InferiorCallPOSIX.h -------------------------------------*- C++ -*-===//
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
name|lldb_InferiorCallPOSIX_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_InferiorCallPOSIX_h_
end_define

begin_comment
comment|// Inferior execution of POSIX functions.
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Process
decl_stmt|;
enum|enum
name|MmapProt
block|{
name|eMmapProtNone
init|=
literal|0
block|,
name|eMmapProtExec
init|=
literal|1
block|,
name|eMmapProtRead
init|=
literal|2
block|,
name|eMmapProtWrite
init|=
literal|4
block|}
enum|;
enum|enum
name|MmapFlags
block|{
name|eMmapFlagsPrivate
init|=
literal|1
block|,
name|eMmapFlagsAnon
init|=
literal|2
block|}
enum|;
name|bool
name|InferiorCallMmap
argument_list|(
name|Process
operator|*
name|proc
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|allocated_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|length
argument_list|,
name|unsigned
name|prot
argument_list|,
name|unsigned
name|flags
argument_list|,
name|lldb
operator|::
name|addr_t
name|fd
argument_list|,
name|lldb
operator|::
name|addr_t
name|offset
argument_list|)
decl_stmt|;
name|bool
name|InferiorCallMunmap
argument_list|(
name|Process
operator|*
name|proc
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|length
argument_list|)
decl_stmt|;
name|bool
name|InferiorCall
argument_list|(
name|Process
operator|*
name|proc
argument_list|,
specifier|const
name|Address
operator|*
name|address
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|returned_func
argument_list|)
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
comment|// lldb_InferiorCallPOSIX_h_
end_comment

end_unit

