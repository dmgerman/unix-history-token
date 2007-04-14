begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Kai Wang  * Copyright (c) 2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * This "archive" is created by "GNU ar". Here we try to verify  * our GNU format handling functionality.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|archive
index|[]
init|=
block|{
literal|'!'
block|,
literal|'<'
block|,
literal|'a'
block|,
literal|'r'
block|,
literal|'c'
block|,
literal|'h'
block|,
literal|'>'
block|,
literal|10
block|,
literal|'/'
block|,
literal|'/'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'4'
block|,
literal|'0'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'`'
block|,
literal|10
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'y'
block|,
literal|'t'
block|,
literal|'t'
block|,
literal|'t'
block|,
literal|'s'
block|,
literal|'s'
block|,
literal|'s'
block|,
literal|'a'
block|,
literal|'a'
block|,
literal|'a'
block|,
literal|'f'
block|,
literal|'f'
block|,
literal|'f'
block|,
literal|'.'
block|,
literal|'o'
block|,
literal|'/'
block|,
literal|10
block|,
literal|'h'
block|,
literal|'h'
block|,
literal|'h'
block|,
literal|'h'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'l'
block|,
literal|'l'
block|,
literal|'l'
block|,
literal|'.'
block|,
literal|'o'
block|,
literal|'/'
block|,
literal|10
block|,
literal|10
block|,
literal|'/'
block|,
literal|'0'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'1'
block|,
literal|'7'
block|,
literal|'5'
block|,
literal|'4'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'2'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'1'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'0'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'6'
block|,
literal|'4'
block|,
literal|'4'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'8'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'`'
block|,
literal|10
block|,
literal|'5'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'8'
block|,
literal|'g'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'h'
block|,
literal|'.'
block|,
literal|'o'
block|,
literal|'/'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'1'
block|,
literal|'7'
block|,
literal|'5'
block|,
literal|'4'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'6'
block|,
literal|'8'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'1'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'0'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'6'
block|,
literal|'4'
block|,
literal|'4'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'4'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'`'
block|,
literal|10
block|,
literal|'3'
block|,
literal|'3'
block|,
literal|'3'
block|,
literal|'3'
block|,
literal|'/'
block|,
literal|'1'
block|,
literal|'9'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'1'
block|,
literal|'7'
block|,
literal|'5'
block|,
literal|'4'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'7'
block|,
literal|'1'
block|,
literal|'3'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'1'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'0'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'1'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'6'
block|,
literal|'4'
block|,
literal|'4'
block|,
literal|' '
block|,
literal|' '
block|,
literal|'9'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'`'
block|,
literal|10
block|,
literal|'9'
block|,
literal|'8'
block|,
literal|'7'
block|,
literal|'6'
block|,
literal|'5'
block|,
literal|'4'
block|,
literal|'3'
block|,
literal|'2'
block|,
literal|'1'
block|,
literal|10
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buff
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_read_format_ar
argument_list|)
end_macro

begin_block
block|{
name|struct
name|archive_entry
modifier|*
name|ae
decl_stmt|;
name|struct
name|archive
modifier|*
name|a
decl_stmt|;
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
name|assertA
argument_list|(
literal|0
operator|==
name|archive_read_open_memory
argument_list|(
name|a
argument_list|,
name|archive
argument_list|,
sizeof|sizeof
argument_list|(
name|archive
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Filename table.  */
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
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
literal|"//"
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_mtime
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_uid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_gid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|40
argument_list|,
name|archive_entry_size
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualIntA
argument_list|(
name|a
argument_list|,
literal|40
argument_list|,
name|archive_read_data
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|memcmp
argument_list|(
name|buff
argument_list|,
literal|"yyytttsssaaafff.o/\nhhhhjjjjkkkkllll.o/\n\n"
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
comment|/* First Entry */
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
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
literal|"yyytttsssaaafff.o"
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1175465652
argument_list|,
name|archive_entry_mtime
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1001
argument_list|,
name|archive_entry_uid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_gid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|8
operator|==
name|archive_entry_size
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|8
operator|==
name|archive_read_data
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|memcmp
argument_list|(
name|buff
argument_list|,
literal|"55667788"
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Second Entry */
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
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
literal|"gghh.o"
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1175465668
argument_list|,
name|archive_entry_mtime
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1001
argument_list|,
name|archive_entry_uid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_gid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|4
operator|==
name|archive_entry_size
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|4
operator|==
name|archive_read_data
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|memcmp
argument_list|(
name|buff
argument_list|,
literal|"3333"
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Third Entry */
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
name|assert
argument_list|(
literal|0
operator|==
name|strcmp
argument_list|(
literal|"hhhhjjjjkkkkllll.o"
argument_list|,
name|archive_entry_pathname
argument_list|(
name|ae
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1175465713
argument_list|,
name|archive_entry_mtime
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|1001
argument_list|,
name|archive_entry_uid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|archive_entry_gid
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|9
operator|==
name|archive_entry_size
argument_list|(
name|ae
argument_list|)
argument_list|)
expr_stmt|;
name|assertA
argument_list|(
literal|9
operator|==
name|archive_read_data
argument_list|(
name|a
argument_list|,
name|buff
argument_list|,
literal|9
argument_list|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|memcmp
argument_list|(
name|buff
argument_list|,
literal|"987654321"
argument_list|,
literal|9
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Test EOF */
name|assertA
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
if|#
directive|if
name|ARCHIVE_API_VERSION
operator|>
literal|1
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
else|#
directive|else
name|archive_read_finish
argument_list|(
name|a
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

