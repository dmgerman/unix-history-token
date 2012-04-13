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
comment|/*  * Test the command-line parsing.  */
end_comment

begin_macro
name|DEFINE_TEST
argument_list|(
argument|test_cmdline
argument_list|)
end_macro

begin_block
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
comment|/* Create an empty file. */
name|f
operator|=
name|fopen
argument_list|(
literal|"empty"
argument_list|,
literal|"wb"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|f
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-Q is an invalid option on every cpio program I know of"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i -Q<empty>1.out 2>1.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"1.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-f requires an argument"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -if<empty>2.out 2>2.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"2.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-f requires an argument"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i -f<empty>3.out 2>3.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"3.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"--format requires an argument"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i --format<empty>4.out 2>4.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"4.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"--badopt is an invalid option"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i --badop<empty>5.out 2>5.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"5.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"--badopt is an invalid option"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i --badopt<empty>6.out 2>6.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"6.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"--n is ambiguous"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i --n<empty>7.out 2>7.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"7.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"--create forbids an argument"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s --create=arg<empty>8.out 2>8.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"8.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-i with empty input should succeed"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|systemf
argument_list|(
literal|"%s -i<empty>9.out 2>9.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"9.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-o with empty input should succeed"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|==
name|systemf
argument_list|(
literal|"%s -o<empty>10.out 2>10.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-i -p is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i -p<empty>11.out 2>11.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"11.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-p -i is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -p -i<empty>12.out 2>12.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"12.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-i -o is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -i -o<empty>13.out 2>13.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"13.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-o -i is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -o -i<empty>14.out 2>14.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"14.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-o -p is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -o -p<empty>15.out 2>15.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"15.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-p -o is nonsense"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -p -o<empty>16.out 2>16.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"16.out"
argument_list|)
expr_stmt|;
name|failure
argument_list|(
literal|"-p with empty input should fail"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|!=
name|systemf
argument_list|(
literal|"%s -p<empty>17.out 2>17.err"
argument_list|,
name|testprog
argument_list|)
argument_list|)
expr_stmt|;
name|assertEmptyFile
argument_list|(
literal|"17.out"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

