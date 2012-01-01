begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Check that an "empty" cpio archive is correctly created.  */
end_comment

begin_comment
comment|/* Here's what an empty cpio archive should look like. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ref
index|[]
init|=
literal|"070707"
comment|/* Magic number */
literal|"000000"
comment|/* Dev = 0 */
literal|"000000"
comment|/* ino = 0 */
literal|"000000"
comment|/* mode = 0 */
literal|"000000"
comment|/* uid = 0 */
literal|"000000"
comment|/* gid = 0 */
literal|"000001"
comment|/* nlink = 1 */
literal|"000000"
comment|/* rdev = 0 */
literal|"00000000000"
comment|/* mtime = 0 */
literal|"000013"
comment|/* Namesize = 11 */
literal|"00000000000"
comment|/* filesize = 0 */
literal|"TRAILER!!!\0"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name */
end_comment

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_write_format_cpio_empty
argument_list|)
end_macro

begin_block
block|{
name|struct
name|archive
modifier|*
name|a
decl_stmt|;
name|char
name|buff
index|[
literal|2048
index|]
decl_stmt|;
name|size_t
name|used
decl_stmt|;
comment|/* Create a new archive in memory. */
name|assert
argument_list|(
operator|(
name|a
operator|=
name|archive_write_new
argument_list|()
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_format_cpio
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_compression_none
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 1-byte block size ensures we see only the required bytes. */
comment|/* We're not testing the padding here. */
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_bytes_per_block
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_bytes_in_last_block
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_open_memory
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
sizeof|sizeof
argument_list|(
name|buff
argument_list|)
argument_list|,
operator|&
name|used
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Close out the archive. */
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_close
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|ARCHIVE_VERSION_NUMBER
operator|<
literal|2000000
name|archive_write_finish
argument_list|(
name|a
argument_list|)
expr_stmt|;
else|#
directive|else
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_finish
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|failure
argument_list|(
literal|"Empty cpio archive should be exactly 87 bytes, was %d."
argument_list|,
name|used
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|used
operator|==
literal|87
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"Empty cpio archive is incorrectly formatted."
argument_list|)
expr_stmt|;
name|assertEqualMem
argument_list|(
name|buff
argument_list|,
name|ref
argument_list|,
literal|87
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

