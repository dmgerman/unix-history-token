begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Endian.h ------------------------------------------------*- C++ -*-===//
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
name|LLDB_UTILITY_ENDIAN_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_ENDIAN_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|endian
block|{
specifier|static
union|union
name|EndianTest
block|{
name|uint32_t
name|num
decl_stmt|;
name|uint8_t
name|bytes
index|[
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
block|}
decl|const
name|endianTest
init|=
block|{
literal|0x01020304
block|}
union|;
specifier|inline
name|lldb
operator|::
name|ByteOrder
name|InlHostByteOrder
argument_list|()
block|{
return|return
operator|(
name|lldb
operator|::
name|ByteOrder
operator|)
name|endianTest
operator|.
name|bytes
index|[
literal|0
index|]
return|;
block|}
comment|//    ByteOrder const InlHostByteOrder = (ByteOrder)endianTest.bytes[0];
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_host_endian_h_
end_comment

end_unit

