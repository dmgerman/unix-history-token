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
comment|/*  * This first test does basic sanity checks on the environment.  For  * most of these, we just exit on failure.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEV_NULL
value|"/dev/null"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEV_NULL
value|"NUL"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_0
argument_list|)
end_macro

begin_block
block|{
name|struct
name|stat
name|st
decl_stmt|;
name|failure
argument_list|(
literal|"File %s does not exist?!"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|assertEqualInt
argument_list|(
literal|0
argument_list|,
name|stat
argument_list|(
name|testprogfile
argument_list|,
operator|&
name|st
argument_list|)
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nFile %s does not exist; aborting test.\n\n"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|failure
argument_list|(
literal|"%s is not executable?!"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|assert
argument_list|(
operator|(
name|st
operator|.
name|st_mode
operator|&
literal|0111
operator|)
operator|!=
literal|0
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nFile %s not executable; aborting test.\n\n"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Try to successfully run the program; this requires that 	 * we know some option that will succeed. 	 */
if|if
condition|(
literal|0
operator|==
name|systemf
argument_list|(
literal|"%s --version>"
name|DEV_NULL
argument_list|,
name|testprog
argument_list|)
condition|)
block|{
comment|/* This worked. */
block|}
elseif|else
if|if
condition|(
literal|0
operator|==
name|systemf
argument_list|(
literal|"%s -W version>"
name|DEV_NULL
argument_list|,
name|testprog
argument_list|)
condition|)
block|{
comment|/* This worked. */
block|}
else|else
block|{
name|failure
argument_list|(
literal|"Unable to successfully run any of the following:\n"
literal|"  * %s --version\n"
literal|"  * %s -W version\n"
argument_list|,
name|testprog
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* TODO: Ensure that our reference files are available. */
block|}
end_block

end_unit

