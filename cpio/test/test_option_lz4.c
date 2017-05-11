begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Michihiro NAKAJIMA  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
argument|test_option_lz4
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|r
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
comment|/* Archive it with lz4 compression. */
name|r
operator|=
name|systemf
argument_list|(
literal|"echo f | %s -o --lz4>archive.out 2>archive.err"
argument_list|,
name|testprog
argument_list|)
expr_stmt|;
name|p
operator|=
name|slurpfile
argument_list|(
operator|&
name|s
argument_list|,
literal|"archive.err"
argument_list|)
expr_stmt|;
name|p
index|[
name|s
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|r
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|strstr
argument_list|(
name|p
argument_list|,
literal|"compression not available"
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|skipping
argument_list|(
literal|"This version of bsdcpio was compiled "
literal|"without lz4 support"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* POSIX permits different handling of the spawnp 		 * system call used to launch the subsidiary 		 * program: */
comment|/* Some systems fail immediately to spawn the new process. */
if|if
condition|(
name|strstr
argument_list|(
name|p
argument_list|,
literal|"Can't launch"
argument_list|)
operator|!=
name|NULL
operator|&&
operator|!
name|canLz4
argument_list|()
condition|)
block|{
name|skipping
argument_list|(
literal|"This version of bsdcpio uses an external lz4 program "
literal|"but no such program is available on this system."
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Some systems successfully spawn the new process, 		 * but fail to exec a program within that process. 		 * This results in failure at the first attempt to 		 * write. */
if|if
condition|(
name|strstr
argument_list|(
name|p
argument_list|,
literal|"Can't write"
argument_list|)
operator|!=
name|NULL
operator|&&
operator|!
name|canLz4
argument_list|()
condition|)
block|{
name|skipping
argument_list|(
literal|"This version of bsdcpio uses an external lz4 program "
literal|"but no such program is available on this system."
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* On some systems the error won't be detected until closing 		   time, by a 127 exit error returned by waitpid. */
if|if
condition|(
name|strstr
argument_list|(
name|p
argument_list|,
literal|"Error closing"
argument_list|)
operator|!=
name|NULL
operator|&&
operator|!
name|canLz4
argument_list|()
condition|)
block|{
name|skipping
argument_list|(
literal|"This version of bsdcpio uses an external lz4 program "
literal|"but no such program is available on this system."
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return;
block|}
name|failure
argument_list|(
literal|"--lz4 option is broken: %s"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|assertEqualInt
argument_list|(
name|r
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* Check that the archive file has an lz4 signature. */
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
literal|"\x04\x22\x4d\x18"
argument_list|,
literal|4
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

