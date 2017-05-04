begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * Copyright (c) 2012 Michihiro NAKAJIMA  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
argument|test_option_b64encode
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|size_t
name|s
decl_stmt|;
comment|/* Create a file. */
name|assertMakeFile
argument_list|(
literal|"f"
argument_list|,
literal|0644
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
comment|/* Archive it with compress compression and uuencode. */
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|systemf
argument_list|(
literal|"echo f | %s -o -Z --b64encode>archive.out 2>archive.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Check that the archive file has an uuencode signature. */
name|p
operator|=
name|slurpfile
argument_list|(
operator|&
name|s
argument_list|,
literal|"archive.out"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|s
operator|>
literal|2
argument_list|)
expr_stmt|;
name|assertEqualMem
argument_list|(
name|p
argument_list|,
literal|"begin-base64 644"
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Archive it with uuencode only. */
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|systemf
argument_list|(
literal|"echo f | %s -o --b64encode>archive.out 2>archive.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Check that the archive file has an uuencode signature. */
name|p
operator|=
name|slurpfile
argument_list|(
operator|&
name|s
argument_list|,
literal|"archive.out"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|s
operator|>
literal|2
argument_list|)
expr_stmt|;
name|assertEqualMem
argument_list|(
name|p
argument_list|,
literal|"begin-base64 644"
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

