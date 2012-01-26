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
comment|/*  * As reported by Bernd Walter:  Some people are in the habit of  * using "find -d" to generate a list for cpio -p because that  * copies the top-level dir last, which preserves owner and mode  * information.  That's not necessary for bsdcpio (libarchive defers  * restoring directory information), but bsdcpio should still generate  * the correct results with this usage.  */
end_comment

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_passthrough_reverse
argument_list|)
end_macro

begin_block
block|{
name|int
name|r
decl_stmt|;
name|FILE
modifier|*
name|filelist
decl_stmt|;
name|assertUmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Create an assortment of files on disk. 	 */
name|filelist
operator|=
name|fopen
argument_list|(
literal|"filelist"
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* Directory. */
name|assertMakeDir
argument_list|(
literal|"dir"
argument_list|,
literal|0743
argument_list|)
expr_stmt|;
comment|/* File with 10 bytes content. */
name|assertMakeFile
argument_list|(
literal|"dir/file"
argument_list|,
literal|0644
argument_list|,
literal|"1234567890"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|filelist
argument_list|,
literal|"dir/file\n"
argument_list|)
expr_stmt|;
comment|/* Write dir last. */
name|fprintf
argument_list|(
name|filelist
argument_list|,
literal|"dir\n"
argument_list|)
expr_stmt|;
comment|/* All done. */
name|fclose
argument_list|(
name|filelist
argument_list|)
expr_stmt|;
comment|/* 	 * Use cpio passthrough mode to copy files to another directory. 	 */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s -pdvm out<filelist>stdout 2>stderr"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"Error invoking %s -pd out"
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
name|assertChdir
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
comment|/* Verify stderr and stdout. */
name|assertTextFileContents
argument_list|(
literal|"out/dir/file\nout/dir\n1 block\n"
argument_list|,
literal|"../stderr"
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"../stdout"
argument_list|)
expr_stmt|;
comment|/* dir */
name|assertIsDir
argument_list|(
literal|"dir"
argument_list|,
literal|0743
argument_list|)
expr_stmt|;
comment|/* Regular file. */
name|assertIsReg
argument_list|(
literal|"dir/file"
argument_list|,
literal|0644
argument_list|)
expr_stmt|;
name|assertFileSize
argument_list|(
literal|"dir/file"
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|assertFileNLinks
argument_list|(
literal|"dir/file"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

