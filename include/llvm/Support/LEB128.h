begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/LEB128.h - [SU]LEB128 utility functions -----*- C++ -*-===//
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
comment|// This file declares some utility functions for encoding SLEB128 and
end_comment

begin_comment
comment|// ULEB128 values.
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
name|LLVM_SYSTEM_LEB128_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_LEB128_H
end_define

begin_include
include|#
directive|include
file|<llvm/Support/raw_ostream.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Utility function to encode a SLEB128 value.
specifier|static
specifier|inline
name|void
name|encodeSLEB128
parameter_list|(
name|int64_t
name|Value
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
block|{
name|bool
name|More
decl_stmt|;
do|do
block|{
name|uint8_t
name|Byte
init|=
name|Value
operator|&
literal|0x7f
decl_stmt|;
comment|// NOTE: this assumes that this signed shift is an arithmetic right shift.
name|Value
operator|>>=
literal|7
expr_stmt|;
name|More
operator|=
operator|!
operator|(
operator|(
operator|(
operator|(
name|Value
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|(
name|Byte
operator|&
literal|0x40
operator|)
operator|==
literal|0
operator|)
operator|)
operator|||
operator|(
operator|(
name|Value
operator|==
operator|-
literal|1
operator|)
operator|&&
operator|(
operator|(
name|Byte
operator|&
literal|0x40
operator|)
operator|!=
literal|0
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|More
condition|)
name|Byte
operator||=
literal|0x80
expr_stmt|;
comment|// Mark this byte that that more bytes will follow.
name|OS
operator|<<
name|char
argument_list|(
name|Byte
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|More
condition|)
do|;
block|}
comment|/// Utility function to encode a ULEB128 value.
specifier|static
specifier|inline
name|void
name|encodeULEB128
parameter_list|(
name|uint64_t
name|Value
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|unsigned
name|Padding
init|=
literal|0
parameter_list|)
block|{
do|do
block|{
name|uint8_t
name|Byte
init|=
name|Value
operator|&
literal|0x7f
decl_stmt|;
name|Value
operator|>>=
literal|7
expr_stmt|;
if|if
condition|(
name|Value
operator|!=
literal|0
operator|||
name|Padding
operator|!=
literal|0
condition|)
name|Byte
operator||=
literal|0x80
expr_stmt|;
comment|// Mark this byte that that more bytes will follow.
name|OS
operator|<<
name|char
argument_list|(
name|Byte
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|Value
operator|!=
literal|0
condition|)
do|;
comment|// Pad with 0x80 and emit a null byte at the end.
if|if
condition|(
name|Padding
operator|!=
literal|0
condition|)
block|{
for|for
control|(
init|;
name|Padding
operator|!=
literal|1
condition|;
operator|--
name|Padding
control|)
name|OS
operator|<<
literal|'\x80'
expr_stmt|;
name|OS
operator|<<
literal|'\x00'
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SYSTEM_LEB128_H
end_comment

end_unit

