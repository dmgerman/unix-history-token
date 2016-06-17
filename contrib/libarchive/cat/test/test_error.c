begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Mike Kazantsev  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_error
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|char
modifier|*
name|reffile
init|=
literal|"test_expand.error"
decl_stmt|;
name|assertFileNotExists
argument_list|(
name|reffile
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s %s>test.out 2>test.err"
argument_list|,
name|testprog
argument_list|,
name|reffile
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"test.out"
argument_list|)
expr_stmt|;
name|assertNonEmptyFile
argument_list|(
literal|"test.err"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

