begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Compression.h ---Compression----------------*- C++ -*-===//
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
comment|// This file contains basic functions for compression/uncompression.
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
name|LLVM_SUPPORT_COMPRESSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_COMPRESSION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|Error
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|namespace
name|zlib
block|{
enum|enum
name|CompressionLevel
block|{
name|NoCompression
block|,
name|DefaultCompression
block|,
name|BestSpeedCompression
block|,
name|BestSizeCompression
block|}
enum|;
name|bool
name|isAvailable
parameter_list|()
function_decl|;
name|Error
name|compress
argument_list|(
name|StringRef
name|InputBuffer
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|CompressedBuffer
argument_list|,
name|CompressionLevel
name|Level
operator|=
name|DefaultCompression
argument_list|)
decl_stmt|;
name|Error
name|uncompress
parameter_list|(
name|StringRef
name|InputBuffer
parameter_list|,
name|char
modifier|*
name|UncompressedBuffer
parameter_list|,
name|size_t
modifier|&
name|UncompressedSize
parameter_list|)
function_decl|;
name|Error
name|uncompress
argument_list|(
name|StringRef
name|InputBuffer
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|UncompressedBuffer
argument_list|,
name|size_t
name|UncompressedSize
argument_list|)
decl_stmt|;
name|uint32_t
name|crc32
parameter_list|(
name|StringRef
name|Buffer
parameter_list|)
function_decl|;
block|}
comment|// End of namespace zlib
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

