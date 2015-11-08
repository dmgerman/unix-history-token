begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $OpenBSD: sprintf_test.c,v 1.3 2004/09/16 20:22:26 otto Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Theo de Raadt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_decl_stmt
specifier|const
name|char
name|correct
index|[]
init|=
literal|"|xx 01 02 03 04\n"
literal|"|xx 05 06 07 08\n"
literal|"|xx 09 10 11 12\n"
literal|"|xx 13 14 15 16\n"
literal|"|xx 17 18 19 20\n"
literal|"|xx 21 22 23 24\n"
literal|"|xx 25 26 27 28\n"
literal|"|xx 29 30 31 32\n"
literal|"|xx 33 34 35 36\n"
literal|"|xx 37 38 39 40\n"
literal|"|xx 41 42 43 44\n"
literal|"|xx 45 -1 1 -1 1\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|correct2
index|[]
init|=
literal|"b bs BSD"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|wchar_t
name|wbuf1
index|[
literal|1024
index|]
decl_stmt|,
name|wbuf2
index|[
literal|1024
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|temp
decl_stmt|;
name|printf
argument_list|(
literal|"1..4\n"
argument_list|)
expr_stmt|;
comment|/* Test positional arguments */
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"|xx %1$s %2$s %3$s %4$s\n"
literal|"|xx %5$s %6$s %7$s %8$s\n"
literal|"|xx %9$s %10$s %11$s %12$s\n"
literal|"|xx %13$s %14$s %15$s %16$s\n"
literal|"|xx %17$s %18$s %19$s %20$s\n"
literal|"|xx %21$s %22$s %23$s %24$s\n"
literal|"|xx %25$s %26$s %27$s %28$s\n"
literal|"|xx %29$s %30$s %31$s %32$s\n"
literal|"|xx %33$s %34$s %35$s %36$s\n"
literal|"|xx %37$s %38$s %39$s %40$s\n"
literal|"|xx %41$s %42$s %43$s %44$s\n"
literal|"|xx %45$d %46$ld %47$lld %48$d %49$lld\n"
argument_list|,
literal|"01"
argument_list|,
literal|"02"
argument_list|,
literal|"03"
argument_list|,
literal|"04"
argument_list|,
literal|"05"
argument_list|,
literal|"06"
argument_list|,
literal|"07"
argument_list|,
literal|"08"
argument_list|,
literal|"09"
argument_list|,
literal|"10"
argument_list|,
literal|"11"
argument_list|,
literal|"12"
argument_list|,
literal|"13"
argument_list|,
literal|"14"
argument_list|,
literal|"15"
argument_list|,
literal|"16"
argument_list|,
literal|"17"
argument_list|,
literal|"18"
argument_list|,
literal|"19"
argument_list|,
literal|"20"
argument_list|,
literal|"21"
argument_list|,
literal|"22"
argument_list|,
literal|"23"
argument_list|,
literal|"24"
argument_list|,
literal|"25"
argument_list|,
literal|"26"
argument_list|,
literal|"27"
argument_list|,
literal|"28"
argument_list|,
literal|"29"
argument_list|,
literal|"30"
argument_list|,
literal|"31"
argument_list|,
literal|"32"
argument_list|,
literal|"33"
argument_list|,
literal|"34"
argument_list|,
literal|"35"
argument_list|,
literal|"36"
argument_list|,
literal|"37"
argument_list|,
literal|"38"
argument_list|,
literal|"39"
argument_list|,
literal|"40"
argument_list|,
literal|"41"
argument_list|,
literal|"42"
argument_list|,
literal|"43"
argument_list|,
literal|"44"
argument_list|,
literal|45
argument_list|,
operator|-
literal|1L
argument_list|,
literal|1LL
argument_list|,
operator|-
literal|1
argument_list|,
literal|1LL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%sok 1 - print-positional normal\n"
argument_list|,
name|strcmp
argument_list|(
name|buf
argument_list|,
name|correct
argument_list|)
operator|==
literal|0
condition|?
literal|""
else|:
literal|"not "
argument_list|)
expr_stmt|;
name|swprintf
argument_list|(
name|wbuf1
argument_list|,
sizeof|sizeof
name|wbuf1
argument_list|,
literal|L"|xx %1$s %2$s %3$s %4$s\n"
literal|"|xx %5$s %6$s %7$s %8$s\n"
literal|"|xx %9$s %10$s %11$s %12$s\n"
literal|"|xx %13$s %14$s %15$s %16$s\n"
literal|"|xx %17$s %18$s %19$s %20$s\n"
literal|"|xx %21$s %22$s %23$s %24$s\n"
literal|"|xx %25$s %26$s %27$s %28$s\n"
literal|"|xx %29$s %30$s %31$s %32$s\n"
literal|"|xx %33$s %34$s %35$s %36$s\n"
literal|"|xx %37$s %38$s %39$s %40$s\n"
literal|"|xx %41$s %42$s %43$s %44$s\n"
literal|"|xx %45$d %46$ld %47$lld %48$d %49$lld\n"
argument_list|,
literal|"01"
argument_list|,
literal|"02"
argument_list|,
literal|"03"
argument_list|,
literal|"04"
argument_list|,
literal|"05"
argument_list|,
literal|"06"
argument_list|,
literal|"07"
argument_list|,
literal|"08"
argument_list|,
literal|"09"
argument_list|,
literal|"10"
argument_list|,
literal|"11"
argument_list|,
literal|"12"
argument_list|,
literal|"13"
argument_list|,
literal|"14"
argument_list|,
literal|"15"
argument_list|,
literal|"16"
argument_list|,
literal|"17"
argument_list|,
literal|"18"
argument_list|,
literal|"19"
argument_list|,
literal|"20"
argument_list|,
literal|"21"
argument_list|,
literal|"22"
argument_list|,
literal|"23"
argument_list|,
literal|"24"
argument_list|,
literal|"25"
argument_list|,
literal|"26"
argument_list|,
literal|"27"
argument_list|,
literal|"28"
argument_list|,
literal|"29"
argument_list|,
literal|"30"
argument_list|,
literal|"31"
argument_list|,
literal|"32"
argument_list|,
literal|"33"
argument_list|,
literal|"34"
argument_list|,
literal|"35"
argument_list|,
literal|"36"
argument_list|,
literal|"37"
argument_list|,
literal|"38"
argument_list|,
literal|"39"
argument_list|,
literal|"40"
argument_list|,
literal|"41"
argument_list|,
literal|"42"
argument_list|,
literal|"43"
argument_list|,
literal|"44"
argument_list|,
literal|45
argument_list|,
operator|-
literal|1L
argument_list|,
literal|1LL
argument_list|,
operator|-
literal|1
argument_list|,
literal|1LL
argument_list|)
expr_stmt|;
name|temp
operator|=
name|correct
expr_stmt|;
name|mbsrtowcs
argument_list|(
name|wbuf2
argument_list|,
operator|&
name|temp
argument_list|,
sizeof|sizeof
name|wbuf2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%sok 2 - print-positional wide\n"
argument_list|,
name|wcscmp
argument_list|(
name|wbuf1
argument_list|,
name|wbuf2
argument_list|)
operator|==
literal|0
condition|?
literal|""
else|:
literal|"not "
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"%2$.*4$s %2$.*3$s %1$s"
argument_list|,
literal|"BSD"
argument_list|,
literal|"bsd"
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%sok 3 - print-positional precision\n"
argument_list|,
name|strcmp
argument_list|(
name|buf
argument_list|,
name|correct2
argument_list|)
operator|==
literal|0
condition|?
literal|""
else|:
literal|"not "
argument_list|)
expr_stmt|;
name|swprintf
argument_list|(
name|wbuf1
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|L"%2$.*4$s %2$.*3$s %1$s"
argument_list|,
literal|"BSD"
argument_list|,
literal|"bsd"
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|temp
operator|=
name|correct2
expr_stmt|;
name|mbsrtowcs
argument_list|(
name|wbuf2
argument_list|,
operator|&
name|temp
argument_list|,
sizeof|sizeof
name|wbuf2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%sok 4 - print-positional precision wide\n"
argument_list|,
name|wcscmp
argument_list|(
name|wbuf1
argument_list|,
name|wbuf2
argument_list|)
operator|==
literal|0
condition|?
literal|""
else|:
literal|"not "
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

