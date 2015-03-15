begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- EndianStream.h - Stream ops with endian specific data ----*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines utilities for operating on streams that have endian
end_comment

begin_comment
comment|// specific data.
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
name|LLVM_SUPPORT_ENDIANSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ENDIANSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|support
block|{
name|namespace
name|endian
block|{
comment|/// Adapter to write values to a stream in a particular byte order.
name|template
operator|<
name|endianness
name|endian
operator|>
expr|struct
name|Writer
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|Writer
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|template
operator|<
name|typename
name|value_type
operator|>
name|void
name|write
argument_list|(
argument|value_type Val
argument_list|)
block|{
name|Val
operator|=
name|byte_swap
operator|<
name|value_type
block|,
name|endian
operator|>
operator|(
name|Val
operator|)
block|;
name|OS
operator|.
name|write
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
operator|&
name|Val
argument_list|,
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
argument_list|)
block|;   }
block|}
expr_stmt|;
block|}
comment|// end namespace endian
block|}
comment|// end namespace support
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

