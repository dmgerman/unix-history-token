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

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_option_B_upper
argument_list|)
end_macro

begin_block
block|{
name|struct
name|stat
name|st
decl_stmt|;
name|int
name|r
decl_stmt|;
comment|/* 	 * Create a file on disk. 	 */
name|assertMakeFile
argument_list|(
literal|"file"
argument_list|,
literal|0644
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Create an archive without -B; this should be 512 bytes. */
name|r
operator|=
name|systemf
argument_list|(
literal|"echo file | %s -o> small.cpio 2>small.err"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
name|r
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"1 block\n"
argument_list|,
literal|"small.err"
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|stat
argument_list|(
literal|"small.cpio"
argument_list|,
operator|&
name|st
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|512
argument_list|,
name|st
operator|.
name|st_size
argument_list|)
expr_stmt|;
comment|/* Create an archive with -B; this should be 5120 bytes. */
name|r
operator|=
name|systemf
argument_list|(
literal|"echo file | %s -oB> large.cpio 2>large.err"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
name|r
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"1 block\n"
argument_list|,
literal|"large.err"
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|stat
argument_list|(
literal|"large.cpio"
argument_list|,
operator|&
name|st
argument_list|)
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
literal|5120
argument_list|,
name|st
operator|.
name|st_size
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

