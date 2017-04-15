begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2017-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/*     This program uses hard-coded data compressed with Zstd legacy versions     and tests that the API decompresses them correctly */
end_comment

begin_comment
comment|/*=========================================== *   Dependencies *==========================================*/
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* malloc, free */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* fprintf */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* strlen */
end_comment

begin_include
include|#
directive|include
file|"zstd.h"
end_include

begin_include
include|#
directive|include
file|"zstd_errors.h"
end_include

begin_comment
comment|/*=========================================== *   Macros *==========================================*/
end_comment

begin_define
define|#
directive|define
name|DISPLAY
parameter_list|(
modifier|...
parameter_list|)
value|fprintf(stderr, __VA_ARGS__)
end_define

begin_comment
comment|/*=========================================== *   Precompressed frames *==========================================*/
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|COMPRESSED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* content is at end of file */
end_comment

begin_decl_stmt
name|size_t
specifier|const
name|COMPRESSED_SIZE
init|=
literal|917
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|EXPECTED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* content is at end of file */
end_comment

begin_function
name|int
name|testSimpleAPI
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
specifier|const
name|size
init|=
name|strlen
argument_list|(
name|EXPECTED
argument_list|)
decl_stmt|;
name|char
modifier|*
specifier|const
name|output
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|output
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Not enough memory!\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|{
name|size_t
specifier|const
name|ret
init|=
name|ZSTD_decompress
argument_list|(
name|output
argument_list|,
name|size
argument_list|,
name|COMPRESSED
argument_list|,
name|COMPRESSED_SIZE
argument_list|)
decl_stmt|;
if|if
condition|(
name|ZSTD_isError
argument_list|(
name|ret
argument_list|)
condition|)
block|{
if|if
condition|(
name|ret
operator|==
name|ZSTD_error_prefix_unknown
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Invalid frame magic number, was this compiled "
literal|"without legacy support?\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: %s\n"
argument_list|,
name|ZSTD_getErrorName
argument_list|(
name|ret
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
if|if
condition|(
name|ret
operator|!=
name|size
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Wrong decoded size\n"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|memcmp
argument_list|(
name|EXPECTED
argument_list|,
name|output
argument_list|,
name|size
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Wrong decoded output produced\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|free
argument_list|(
name|output
argument_list|)
expr_stmt|;
name|DISPLAY
argument_list|(
literal|"Simple API OK\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|testStreamingAPI
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
specifier|const
name|outBuffSize
init|=
name|ZSTD_DStreamOutSize
argument_list|()
decl_stmt|;
name|char
modifier|*
specifier|const
name|outBuff
init|=
name|malloc
argument_list|(
name|outBuffSize
argument_list|)
decl_stmt|;
name|ZSTD_DStream
modifier|*
specifier|const
name|stream
init|=
name|ZSTD_createDStream
argument_list|()
decl_stmt|;
name|ZSTD_inBuffer
name|input
init|=
block|{
name|COMPRESSED
block|,
name|COMPRESSED_SIZE
block|,
literal|0
block|}
decl_stmt|;
name|size_t
name|outputPos
init|=
literal|0
decl_stmt|;
name|int
name|needsInit
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|outBuff
operator|==
name|NULL
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Could not allocate memory\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|stream
operator|==
name|NULL
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Could not create dstream\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
while|while
condition|(
literal|1
condition|)
block|{
name|ZSTD_outBuffer
name|output
init|=
block|{
name|outBuff
block|,
name|outBuffSize
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
name|needsInit
condition|)
block|{
name|size_t
specifier|const
name|ret
init|=
name|ZSTD_initDStream
argument_list|(
name|stream
argument_list|)
decl_stmt|;
if|if
condition|(
name|ZSTD_isError
argument_list|(
name|ret
argument_list|)
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: %s\n"
argument_list|,
name|ZSTD_getErrorName
argument_list|(
name|ret
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
block|{
name|size_t
specifier|const
name|ret
init|=
name|ZSTD_decompressStream
argument_list|(
name|stream
argument_list|,
operator|&
name|output
argument_list|,
operator|&
name|input
argument_list|)
decl_stmt|;
if|if
condition|(
name|ZSTD_isError
argument_list|(
name|ret
argument_list|)
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: %s\n"
argument_list|,
name|ZSTD_getErrorName
argument_list|(
name|ret
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
block|{
name|needsInit
operator|=
literal|1
expr_stmt|;
block|}
block|}
if|if
condition|(
name|memcmp
argument_list|(
name|outBuff
argument_list|,
name|EXPECTED
operator|+
name|outputPos
argument_list|,
name|output
operator|.
name|pos
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|DISPLAY
argument_list|(
literal|"ERROR: Wrong decoded output produced\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|outputPos
operator|+=
name|output
operator|.
name|pos
expr_stmt|;
if|if
condition|(
name|input
operator|.
name|pos
operator|==
name|input
operator|.
name|size
operator|&&
name|output
operator|.
name|pos
operator|<
name|output
operator|.
name|size
condition|)
block|{
break|break;
block|}
block|}
name|free
argument_list|(
name|outBuff
argument_list|)
expr_stmt|;
name|ZSTD_freeDStream
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|DISPLAY
argument_list|(
literal|"Streaming API OK\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|testSimpleAPI
argument_list|()
expr_stmt|;
if|if
condition|(
name|ret
condition|)
return|return
name|ret
return|;
name|ret
operator|=
name|testStreamingAPI
argument_list|()
expr_stmt|;
if|if
condition|(
name|ret
condition|)
return|return
name|ret
return|;
name|DISPLAY
argument_list|(
literal|"OK\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Consists of the "EXPECTED" string compressed with default settings on     - v0.4.3     - v0.5.0     - v0.6.0     - v0.7.0     - v0.8.0 */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|COMPRESSED
init|=
literal|"\x24\xB5\x2F\xFD\x00\x00\x00\xBB\xB0\x02\xC0\x10\x00\x1E\xB0\x01"
literal|"\x02\x00\x00\x80\x00\xE8\x92\x34\x12\x97\xC8\xDF\xE9\xF3\xEF\x53"
literal|"\xEA\x1D\x27\x4F\x0C\x44\x90\x0C\x8D\xF1\xB4\x89\x17\x00\x18\x00"
literal|"\x18\x00\x3F\xE6\xE2\xE3\x74\xD6\xEC\xC9\x4A\xE0\x71\x71\x42\x3E"
literal|"\x64\x4F\x6A\x45\x4E\x78\xEC\x49\x03\x3F\xC6\x80\xAB\x8F\x75\x5E"
literal|"\x6F\x2E\x3E\x7E\xC6\xDC\x45\x69\x6C\xC5\xFD\xC7\x40\xB8\x84\x8A"
literal|"\x01\xEB\xA8\xD1\x40\x39\x90\x4C\x64\xF8\xEB\x53\xE6\x18\x0B\x67"
literal|"\x12\xAD\xB8\x99\xB3\x5A\x6F\x8A\x19\x03\x01\x50\x67\x56\xF5\x9F"
literal|"\x35\x84\x60\xA0\x60\x91\xC9\x0A\xDC\xAB\xAB\xE0\xE2\x81\xFA\xCF"
literal|"\xC6\xBA\x01\x0E\x00\x54\x00\x00\x19\x00\x00\x54\x14\x00\x24\x24"
literal|"\x04\xFE\x04\x84\x4E\x41\x00\x27\xE2\x02\xC4\xB1\x00\xD2\x51\x00"
literal|"\x79\x58\x41\x28\x00\xE0\x0C\x01\x68\x65\x00\x04\x13\x0C\xDA\x0C"
literal|"\x80\x22\x06\xC0\x00\x00\x25\xB5\x2F\xFD\x00\x00\x00\xAD\x12\xB0"
literal|"\x7D\x1E\xB0\x01\x02\x00\x00\x80\x00\xE8\x92\x34\x12\x97\xC8\xDF"
literal|"\xE9\xF3\xEF\x53\xEA\x1D\x27\x4F\x0C\x44\x90\x0C\x8D\xF1\xB4\x89"
literal|"\x03\x01\x50\x67\x56\xF5\x9F\x35\x84\x60\xA0\x60\x91\xC9\x0A\xDC"
literal|"\xAB\xAB\xE0\xE2\x81\xFA\xCF\xC6\xBA\xEB\xA8\xD1\x40\x39\x90\x4C"
literal|"\x64\xF8\xEB\x53\xE6\x18\x0B\x67\x12\xAD\xB8\x99\xB3\x5A\x6F\x8A"
literal|"\xF9\x63\x0C\xB8\xFA\x58\xE7\xF5\xE6\xE2\xE3\x67\xCC\x5D\x94\xC6"
literal|"\x56\xDC\x7F\x0C\x84\x4B\xA8\xF8\x63\x2E\x3E\x4E\x67\xCD\x9E\xAC"
literal|"\x04\x1E\x17\x27\xE4\x43\xF6\xA4\x56\xE4\x84\xC7\x9E\x34\x0E\x00"
literal|"\x00\x32\x40\x80\xA8\x00\x01\x49\x81\xE0\x3C\x01\x29\x1D\x00\x87"
literal|"\xCE\x80\x75\x08\x80\x72\x24\x00\x7B\x52\x00\x94\x00\x20\xCC\x01"
literal|"\x86\xD2\x00\x81\x09\x83\xC1\x34\xA0\x88\x01\xC0\x00\x00\x26\xB5"
literal|"\x2F\xFD\x42\xEF\x00\x00\xA6\x12\xB0\x7D\x1E\xB0\x01\x02\x00\x00"
literal|"\x54\xA0\xBA\x24\x8D\xC4\x25\xF2\x77\xFA\xFC\xFB\x94\x7A\xC7\xC9"
literal|"\x13\x03\x11\x24\x43\x63\x3C\x6D\x22\x03\x01\x50\x67\x56\xF5\x9F"
literal|"\x35\x84\x60\xA0\x60\x91\xC9\x0A\xDC\xAB\xAB\xE0\xE2\x81\xFA\xCF"
literal|"\xC6\xBA\xEB\xA8\xD1\x40\x39\x90\x4C\x64\xF8\xEB\x53\xE6\x18\x0B"
literal|"\x67\x12\xAD\xB8\x99\xB3\x5A\x6F\x8A\xF9\x63\x0C\xB8\xFA\x58\xE7"
literal|"\xF5\xE6\xE2\xE3\x67\xCC\x5D\x94\xC6\x56\xDC\x7F\x0C\x84\x4B\xA8"
literal|"\xF8\x63\x2E\x3E\x4E\x67\xCD\x9E\xAC\x04\x1E\x17\x27\xE4\x43\xF6"
literal|"\xA4\x56\xE4\x84\xC7\x9E\x34\x0E\x00\x35\x0B\x71\xB5\xC0\x2A\x5C"
literal|"\x26\x94\x22\x20\x8B\x4C\x8D\x13\x47\x58\x67\x15\x6C\xF1\x1C\x4B"
literal|"\x54\x10\x9D\x31\x50\x85\x4B\x54\x0E\x01\x4B\x3D\x01\xC0\x00\x00"
literal|"\x27\xB5\x2F\xFD\x20\xEF\x00\x00\xA6\x12\xE4\x84\x1F\xB0\x01\x10"
literal|"\x00\x00\x00\x35\x59\xA6\xE7\xA1\xEF\x7C\xFC\xBD\x3F\xFF\x9F\xEF"
literal|"\xEE\xEF\x61\xC3\xAA\x31\x1D\x34\x38\x22\x22\x04\x44\x21\x80\x32"
literal|"\xAD\x28\xF3\xD6\x28\x0C\x0A\x0E\xD6\x5C\xAC\x19\x8D\x20\x5F\x45"
literal|"\x02\x2E\x17\x50\x66\x6D\xAC\x8B\x9C\x6E\x07\x73\x46\xBB\x44\x14"
literal|"\xE7\x98\xC3\xB9\x17\x32\x6E\x33\x7C\x0E\x21\xB1\xDB\xCB\x89\x51"
literal|"\x23\x34\xAB\x9D\xBC\x6D\x20\xF5\x03\xA9\x91\x4C\x2E\x1F\x59\xDB"
literal|"\xD9\x35\x67\x4B\x0C\x95\x79\x10\x00\x85\xA6\x96\x95\x2E\xDF\x78"
literal|"\x7B\x4A\x5C\x09\x76\x97\xD1\x5C\x96\x12\x75\x35\xA3\x55\x4A\xD4"
literal|"\x0B\x00\x35\x0B\x71\xB5\xC0\x2A\x5C\xE6\x08\x45\xF1\x39\x43\xF1"
literal|"\x1C\x4B\x54\x10\x9D\x31\x50\x85\x4B\x54\x0E\x01\x4B\x3D\x01\xC0"
literal|"\x00\x00\x28\xB5\x2F\xFD\x24\xEF\x35\x05\x00\x92\x0B\x21\x1F\xB0"
literal|"\x01\x10\x00\x00\x00\x35\x59\xA6\xE7\xA1\xEF\x7C\xFC\xBD\x3F\xFF"
literal|"\x9F\xEF\xEE\xEF\x61\xC3\xAA\x31\x1D\x34\x38\x22\x22\x04\x44\x21"
literal|"\x80\x32\xAD\x28\xF3\xD6\x28\x0C\x0A\x0E\xD6\x5C\xAC\x19\x8D\x20"
literal|"\x5F\x45\x02\x2E\x17\x50\x66\x6D\xAC\x8B\x9C\x6E\x07\x73\x46\xBB"
literal|"\x44\x14\xE7\x98\xC3\xB9\x17\x32\x6E\x33\x7C\x0E\x21\xB1\xDB\xCB"
literal|"\x89\x51\x23\x34\xAB\x9D\xBC\x6D\x20\xF5\x03\xA9\x91\x4C\x2E\x1F"
literal|"\x59\xDB\xD9\x35\x67\x4B\x0C\x95\x79\x10\x00\x85\xA6\x96\x95\x2E"
literal|"\xDF\x78\x7B\x4A\x5C\x09\x76\x97\xD1\x5C\x96\x12\x75\x35\xA3\x55"
literal|"\x4A\xD4\x0B\x00\x35\x0B\x71\xB5\xC0\x2A\x5C\xE6\x08\x45\xF1\x39"
literal|"\x43\xF1\x1C\x4B\x54\x10\x9D\x31\x50\x85\x4B\x54\x0E\x01\x4B\x3D"
literal|"\x01\xD2\x2F\x21\x80"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|EXPECTED
init|=
literal|"snowden is snowed in / he's now then in his snow den / when does the snow end?\n"
literal|"goodbye little dog / you dug some holes in your day / they'll be hard to fill.\n"
literal|"when life shuts a door, / just open it. itâs a door. / that is how doors work.\n"
literal|"snowden is snowed in / he's now then in his snow den / when does the snow end?\n"
literal|"goodbye little dog / you dug some holes in your day / they'll be hard to fill.\n"
literal|"when life shuts a door, / just open it. itâs a door. / that is how doors work.\n"
literal|"snowden is snowed in / he's now then in his snow den / when does the snow end?\n"
literal|"goodbye little dog / you dug some holes in your day / they'll be hard to fill.\n"
literal|"when life shuts a door, / just open it. itâs a door. / that is how doors work.\n"
literal|"snowden is snowed in / he's now then in his snow den / when does the snow end?\n"
literal|"goodbye little dog / you dug some holes in your day / they'll be hard to fill.\n"
literal|"when life shuts a door, / just open it. itâs a door. / that is how doors work.\n"
literal|"snowden is snowed in / he's now then in his snow den / when does the snow end?\n"
literal|"goodbye little dog / you dug some holes in your day / they'll be hard to fill.\n"
literal|"when life shuts a door, / just open it. itâs a door. / that is how doors work.\n"
decl_stmt|;
end_decl_stmt

end_unit

