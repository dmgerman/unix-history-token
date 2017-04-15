begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"utils/Range.h"
end_include

begin_include
include|#
directive|include
file|<array>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_decl_stmt
name|namespace
name|pzstd
block|{
comment|/**  * We put a skippable frame before each frame.  * It contains a skippable frame magic number, the size of the skippable frame,  * and the size of the next frame.  * Each skippable frame is exactly 12 bytes in little endian format.  * The first 8 bytes are for compatibility with the ZSTD format.  * If we have N threads, the output will look like  *  * [0x184D2A50|4|size1] [frame1 of size size1]  * [0x184D2A50|4|size2] [frame2 of size size2]  * ...  * [0x184D2A50|4|sizeN] [frameN of size sizeN]  *  * Each sizeX is 4 bytes.  *  * These skippable frames should allow us to skip through the compressed file  * and only load at most N pages.  */
name|class
name|SkippableFrame
block|{
name|public
label|:
specifier|static
name|constexpr
name|std
operator|::
name|size_t
name|kSize
operator|=
literal|12
expr_stmt|;
name|private
label|:
name|std
operator|::
name|uint32_t
name|frameSize_
expr_stmt|;
name|std
operator|::
name|array
operator|<
name|std
operator|::
name|uint8_t
operator|,
name|kSize
operator|>
name|data_
expr_stmt|;
specifier|static
name|constexpr
name|std
operator|::
name|uint32_t
name|kSkippableFrameMagicNumber
operator|=
literal|0x184D2A50
expr_stmt|;
comment|// Could be improved if the size fits in less bytes
specifier|static
name|constexpr
name|std
operator|::
name|uint32_t
name|kFrameContentsSize
operator|=
name|kSize
operator|-
literal|8
expr_stmt|;
name|public
label|:
comment|// Write the skippable frame to data_ in LE format.
name|explicit
name|SkippableFrame
argument_list|(
name|std
operator|::
name|uint32_t
name|size
argument_list|)
decl_stmt|;
comment|// Read the skippable frame from bytes in LE format.
specifier|static
name|std
operator|::
name|size_t
name|tryRead
argument_list|(
argument|ByteRange bytes
argument_list|)
expr_stmt|;
name|ByteRange
name|data
argument_list|()
specifier|const
block|{
return|return
block|{
name|data_
operator|.
name|data
argument_list|()
block|,
name|data_
operator|.
name|size
argument_list|()
block|}
return|;
block|}
comment|// Size of the next frame.
name|std
operator|::
name|size_t
name|frameSize
argument_list|()
specifier|const
block|{
return|return
name|frameSize_
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

end_unit

