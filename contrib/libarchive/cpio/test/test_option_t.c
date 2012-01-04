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
argument|test_option_t
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
comment|/* List reference archive, make sure the TOC is correct. */
name|extract_reference_file
argument_list|(
literal|"test_option_t.cpio"
argument_list|)
expr_stmt|;
name|r
operator|=
name|systemf
argument_list|(
literal|"%s -it< test_option_t.cpio>it.out 2>it.err"
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
literal|"it.err"
argument_list|)
expr_stmt|;
name|extract_reference_file
argument_list|(
literal|"test_option_t.stdout"
argument_list|)
expr_stmt|;
name|p
operator|=
name|slurpfile
argument_list|(
name|NULL
argument_list|,
literal|"test_option_t.stdout"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
name|p
argument_list|,
literal|"it.out"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* We accept plain "-t" as a synonym for "-it" */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s -t< test_option_t.cpio>t.out 2>t.err"
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
literal|"t.err"
argument_list|)
expr_stmt|;
name|extract_reference_file
argument_list|(
literal|"test_option_t.stdout"
argument_list|)
expr_stmt|;
name|p
operator|=
name|slurpfile
argument_list|(
name|NULL
argument_list|,
literal|"test_option_t.stdout"
argument_list|)
expr_stmt|;
name|assertTextFileContents
argument_list|(
name|p
argument_list|,
literal|"t.out"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* But "-ot" is an error. */
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -ot< test_option_t.cpio>ot.out 2>ot.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"ot.out"
argument_list|)
expr_stmt|;
comment|/* List reference archive verbosely, make sure the TOC is correct. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s -itv< test_option_t.cpio>tv.out 2>tv.err"
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
literal|"tv.err"
argument_list|)
expr_stmt|;
name|extract_reference_file
argument_list|(
literal|"test_option_tv.stdout"
argument_list|)
expr_stmt|;
comment|/* This doesn't work because the usernames on different systems 	 * are different and cpio now looks up numeric UIDs on 	 * the local system. */
comment|/* assertEqualFile("tv.out", "test_option_tv.stdout"); */
comment|/* List reference archive with numeric IDs, verify TOC is correct. */
name|r
operator|=
name|systemf
argument_list|(
literal|"%s -itnv< test_option_t.cpio>itnv.out 2>itnv.err"
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
literal|"itnv.err"
argument_list|)
expr_stmt|;
name|p
operator|=
name|slurpfile
argument_list|(
name|NULL
argument_list|,
literal|"itnv.out"
argument_list|)
expr_stmt|;
comment|/* Since -n uses numeric UID/GID, this part should be the 	 * same on every system. */
name|assertEqualMem
argument_list|(
name|p
argument_list|,
literal|"-rw-r--r--   1 1000     1000            0 "
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|/* Date varies depending on local timezone. */
if|if
condition|(
name|memcmp
argument_list|(
name|p
operator|+
literal|42
argument_list|,
literal|"Dec 31  1969"
argument_list|,
literal|12
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* East of Greenwich we get Dec 31, 1969. */
block|}
else|else
block|{
comment|/* West of Greenwich get Jan 1, 1970 */
name|assertEqualMem
argument_list|(
name|p
operator|+
literal|42
argument_list|,
literal|"Jan "
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* Some systems format "Jan 01", some "Jan  1" */
name|assert
argument_list|(
name|p
index|[
literal|46
index|]
operator|==
literal|' '
operator|||
name|p
index|[
literal|46
index|]
operator|==
literal|'0'
argument_list|)
expr_stmt|;
name|assertEqualMem
argument_list|(
name|p
operator|+
literal|47
argument_list|,
literal|"1  1970 "
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
name|assertEqualMem
argument_list|(
name|p
operator|+
literal|54
argument_list|,
literal|" file"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* But "-n" without "-t" is an error. */
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -in< test_option_t.cpio>in.out 2>in.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"in.out"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

