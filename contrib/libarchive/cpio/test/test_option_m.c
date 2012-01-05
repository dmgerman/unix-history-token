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
argument|test_option_m
argument_list|)
end_macro

begin_block
block|{
name|int
name|r
decl_stmt|;
comment|/* 	 * The reference archive has one file with an mtime in 1970, 1 	 * second after the start of the epoch. 	 */
comment|/* Restored without -m, the result should have a current mtime. */
name|assertMakeDir
argument_list|(
literal|"without-m"
argument_list|,
literal|0755
argument_list|)
expr_stmt|;
name|assertChdir
argument_list|(
literal|"without-m"
argument_list|)
expr_stmt|;
name|extract_reference_file
argument_list|(
literal|"test_option_m.cpio"
argument_list|)
expr_stmt|;
name|r
operator|=
name|systemf
argument_list|(
literal|"%s --no-preserve-owner -i< test_option_m.cpio>out 2>err"
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
name|assertEmptyFile
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"1 block\n"
argument_list|,
literal|"err"
argument_list|)
expr_stmt|;
comment|/* Should have been created within the last few seconds. */
name|assertFileMtimeRecent
argument_list|(
literal|"file"
argument_list|)
expr_stmt|;
comment|/* With -m, it should have an mtime in 1970. */
name|assertChdir
argument_list|(
literal|".."
argument_list|)
expr_stmt|;
name|assertMakeDir
argument_list|(
literal|"with-m"
argument_list|,
literal|0755
argument_list|)
expr_stmt|;
name|assertChdir
argument_list|(
literal|"with-m"
argument_list|)
expr_stmt|;
name|extract_reference_file
argument_list|(
literal|"test_option_m.cpio"
argument_list|)
expr_stmt|;
name|r
operator|=
name|systemf
argument_list|(
literal|"%s --no-preserve-owner -im< test_option_m.cpio>out 2>err"
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
name|assertEmptyFile
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"1 block\n"
argument_list|,
literal|"err"
argument_list|)
expr_stmt|;
comment|/* 	 * mtime in reference archive is '1' == 1 second after 	 * midnight Jan 1, 1970 UTC. 	 */
name|assertFileMtime
argument_list|(
literal|"file"
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

