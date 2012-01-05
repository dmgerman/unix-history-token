begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*  * Regression test:  We used to get a bogus error message when we  * asked tar to copy entries out of an empty archive.  See  * Issue 51 on libarchive.googlecode.com for details.  */
end_comment

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_empty_mtree
argument_list|)
end_macro

begin_block
block|{
name|int
name|r
decl_stmt|;
name|assertMakeFile
argument_list|(
literal|"test1.mtree"
argument_list|,
literal|0777
argument_list|,
literal|"#mtree\n"
argument_list|)
expr_stmt|;
name|r
operator|=
name|systemf
argument_list|(
literal|"%s cf test1.tar @test1.mtree>test1.out 2>test1.err"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"Error invoking %s cf"
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
literal|"test1.out"
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"test1.err"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

