begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Sean Purcell  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
argument|test_extract_cpio_zstd
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
name|reffile
init|=
literal|"test_extract.cpio.zst"
decl_stmt|;
name|int
name|f
decl_stmt|;
name|extract_reference_file
argument_list|(
name|reffile
argument_list|)
expr_stmt|;
name|f
operator|=
name|systemf
argument_list|(
literal|"%s -it< %s>test.out 2>test.err"
argument_list|,
name|testprog
argument_list|,
name|reffile
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|==
literal|0
operator|||
name|canZstd
argument_list|()
condition|)
block|{
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|systemf
argument_list|(
literal|"%s -i< %s>test.out 2>test.err"
argument_list|,
name|testprog
argument_list|,
name|reffile
argument_list|)
argument_list|)
expr_stmt|;
name|assertFileExists
argument_list|(
literal|"file1"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"contents of file1.\n"
argument_list|,
literal|"file1"
argument_list|)
expr_stmt|;
name|assertFileExists
argument_list|(
literal|"file2"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"contents of file2.\n"
argument_list|,
literal|"file2"
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"test.out"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
literal|"1 block\n"
argument_list|,
literal|"test.err"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|skipping
argument_list|(
literal|"It seems zstd is not supported on this platform"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

