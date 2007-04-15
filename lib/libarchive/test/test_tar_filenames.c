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
comment|/*  * Exercise various lengths of filenames in tar archives,  * especially around the magic sizes where ustar breaks  * filenames into prefix/suffix.  */
end_comment

begin_expr_stmt
specifier|static
name|test_filename
argument_list|(
argument|int dlen
argument_list|,
argument|int flen
argument_list|)
block|{
name|char
name|buff
index|[
literal|8192
index|]
block|;
name|char
name|filename
index|[
literal|400
index|]
block|;
name|char
name|dirname
index|[
literal|400
index|]
block|; 	struct
name|archive_entry
operator|*
name|ae
block|; 	struct
name|archive
operator|*
name|a
block|;
name|size_t
name|used
block|;
name|int
name|i
block|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|dlen
condition|;
name|i
operator|++
control|)
name|filename
index|[
name|i
index|]
operator|=
literal|'a'
expr_stmt|;
name|filename
index|[
name|i
operator|++
index|]
operator|=
literal|'/'
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
init|;
name|i
operator|<
name|dlen
operator|+
name|flen
operator|+
literal|1
condition|;
name|i
operator|++
control|)
name|filename
index|[
name|i
index|]
operator|=
literal|'b'
expr_stmt|;
end_for

begin_expr_stmt
name|filename
index|[
name|i
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|strcpy
argument_list|(
name|dirname
argument_list|,
name|filename
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create a new archive in memory. */
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_format_pax_restricted
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_set_bytes_per_block
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/* 	 * Write a file to it. 	 */
end_comment

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|ae
operator|=
name|archive_entry_new
argument_list|()
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_copy_pathname
argument_list|(
name|ae
argument_list|,
name|filename
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_set_mode
argument_list|(
name|ae
argument_list|,
name|S_IFREG
operator||
literal|0755
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Pathname %d/%d"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_header
argument_list|(
name|a
argument_list|,
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_free
argument_list|(
name|ae
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Write a dir to it (without trailing '/'). 	 */
end_comment

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|ae
operator|=
name|archive_entry_new
argument_list|()
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_copy_pathname
argument_list|(
name|ae
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_set_mode
argument_list|(
name|ae
argument_list|,
name|S_IFDIR
operator||
literal|0755
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Dirname %d/%d"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_header
argument_list|(
name|a
argument_list|,
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_free
argument_list|(
name|ae
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Tar adds a '/' to directory names. */
end_comment

begin_expr_stmt
name|strcat
argument_list|(
name|dirname
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Write a dir to it (with trailing '/'). 	 */
end_comment

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|ae
operator|=
name|archive_entry_new
argument_list|()
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_copy_pathname
argument_list|(
name|ae
argument_list|,
name|dirname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_set_mode
argument_list|(
name|ae
argument_list|,
name|S_IFDIR
operator||
literal|0755
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Dirname %d/%d"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_write_header
argument_list|(
name|a
argument_list|,
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|archive_entry_free
argument_list|(
name|ae
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Close out the archive. */
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_if
if|#
directive|if
name|ARCHIVE_API_VERSION
operator|>
literal|1
end_if

begin_expr_stmt
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
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|archive_write_finish
argument_list|(
name|a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Now, read the data back. 	 */
end_comment

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|a
operator|=
name|archive_read_new
argument_list|()
operator|)
operator|!=
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_support_format_all
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_support_compression_all
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_open_memory
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
name|used
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Read the file and check the filename. */
end_comment

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_next_header
argument_list|(
name|a
argument_list|,
operator|&
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Pathname %d/%d: %s"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
name|filename
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|S_IFREG
operator||
literal|0755
operator|)
operator|==
name|archive_entry_mode
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * Read the two dirs and check the names. 	 * 	 * Both dirs should read back with the same name, since 	 * tar should add a trailing '/' to any dir that doesn't 	 * already have one. 	 */
end_comment

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_next_header
argument_list|(
name|a
argument_list|,
operator|&
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Pathname %d/%d: %s"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
name|dirname
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|S_IFDIR
operator||
literal|0755
operator|)
operator|==
name|archive_entry_mode
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_next_header
argument_list|(
name|a
argument_list|,
operator|&
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|failure
argument_list|(
literal|"Pathname %d/%d: %s"
argument_list|,
name|dlen
argument_list|,
name|flen
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
name|dirname
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
operator|(
name|S_IFDIR
operator||
literal|0755
operator|)
operator|==
name|archive_entry_mode
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Verify the end of the archive. */
end_comment

begin_expr_stmt
name|assert
argument_list|(
literal|1
operator|==
name|archive_read_next_header
argument_list|(
name|a
argument_list|,
operator|&
name|ae
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
literal|0
operator|==
name|archive_read_close
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|ARCHIVE_API_VERSION
operator|>
literal|1
end_if

begin_expr_stmt
name|assert
argument_list|(
literal|0
operator|==
name|archive_read_finish
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|archive_read_finish
argument_list|(
name|a
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|}  DEFINE_TEST
operator|(
name|test_tar_filenames
operator|)
block|{
name|int
name|dlen
block|,
name|flen
block|;
comment|/* Repeat the following for a variety of dir/file lengths. */
for|for
control|(
name|dlen
operator|=
literal|40
init|;
name|dlen
operator|<
literal|60
condition|;
name|dlen
operator|++
control|)
block|{
for|for
control|(
name|flen
operator|=
literal|40
init|;
name|flen
operator|<
literal|60
condition|;
name|flen
operator|++
control|)
block|{
name|test_filename
argument_list|(
name|dlen
argument_list|,
name|flen
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}  	for
operator|(
name|dlen
operator|=
literal|140
expr|;
name|dlen
operator|<
literal|160
expr|;
name|dlen
operator|++
operator|)
block|{
for|for
control|(
name|flen
operator|=
literal|90
init|;
name|flen
operator|<
literal|110
condition|;
name|flen
operator|++
control|)
block|{
name|test_filename
argument_list|(
name|dlen
argument_list|,
name|flen
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

unit|} }
end_unit

