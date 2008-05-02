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
argument|test_stdio
argument_list|)
end_macro

begin_block
block|{
name|int
name|fd
decl_stmt|;
name|int
name|filelist
decl_stmt|;
name|int
name|oldumask
decl_stmt|;
name|int
name|r
decl_stmt|;
name|oldumask
operator|=
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * Create a couple of files on disk. 	 */
name|filelist
operator|=
name|open
argument_list|(
literal|"filelist"
argument_list|,
name|O_CREAT
operator||
name|O_WRONLY
argument_list|,
literal|0644
argument_list|)
expr_stmt|;
comment|/* File */
name|fd
operator|=
name|open
argument_list|(
literal|"f"
argument_list|,
name|O_CREAT
operator||
name|O_WRONLY
argument_list|,
literal|0644
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|fd
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|fd
argument_list|,
literal|"f\n"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|filelist
argument_list|,
literal|"f\n"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* Link to above file. */
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|link
argument_list|(
literal|"f"
argument_list|,
literal|"l"
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|filelist
argument_list|,
literal|"l\n"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|filelist
argument_list|)
expr_stmt|;
comment|/* 	 * Archive/dearchive with a variety of options, verifying 	 * stdio paths. 	 */
comment|/* 'cf' should generate no output unless there's an error. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s cf archive f l>cf.out 2>cf.err"
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
literal|"cf.out"
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"cf.err"
argument_list|)
expr_stmt|;
comment|/* 'cvf' should generate file list on stderr, empty stdout. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s cvf archive f l>cvf.out 2>cvf.err"
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
name|failure
argument_list|(
literal|"'cv' writes filenames to stderr, nothing to stdout (SUSv2)\n"
literal|"Note that GNU tar writes the file list to stdout by default."
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"cvf.out"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify cvf.err has file list in SUSv2-prescribed format. */
comment|/* 'cvf -' should generate file list on stderr, archive on stdout. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s cvf - f l>cvf-.out 2>cvf-.err"
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
name|failure
argument_list|(
literal|"cvf - should write archive to stdout"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify cvf-.out has archive. */
name|failure
argument_list|(
literal|"cvf - should write file list to stderr (SUSv2)"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify cvf-.err has verbose file list. */
comment|/* 'tf' should generate file list on stdout, empty stderr. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s tf archive>tf.out 2>tf.err"
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
literal|"tf.err"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"'t' mode should write results to stdout"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify tf.out has file list. */
comment|/* 'tvf' should generate file list on stdout, empty stderr. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s tvf archive>tvf.out 2>tvf.err"
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
literal|"tvf.err"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"'tv' mode should write results to stdout"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify tvf.out has file list. */
comment|/* 'tvf -' uses stdin, file list on stdout, empty stderr. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s tvf -< archive>tvf-.out 2>tvf-.err"
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
literal|"tvf-.err"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify tvf-.out has file list. */
comment|/* Basic 'xf' should generate no output on stdout or stderr. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s xf archive>xf.out 2>xf.err"
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
literal|"xf.err"
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"xf.out"
argument_list|)
expr_stmt|;
comment|/* 'xvf' should generate list on stderr, empty stdout. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s xvf archive>xvf.out 2>xvf.err"
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
literal|"xvf.out"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify xvf.err */
comment|/* 'xvOf' should generate list on stderr, file contents on stdout. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s xvOf archive>xvOf.out 2>xvOf.err"
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
comment|/* TODO: Verify xvOf.out */
comment|/* TODO: Verify xvf.err */
comment|/* 'xvf -' should generate list on stderr, empty stdout. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s xvf -< archive>xvf-.out 2>xvf-.err"
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
literal|"xvf-.out"
argument_list|)
expr_stmt|;
comment|/* TODO: Verify xvf-.err */
name|umask
argument_list|(
name|oldumask
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

