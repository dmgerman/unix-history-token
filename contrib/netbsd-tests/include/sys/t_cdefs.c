begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_cdefs.c,v 1.3 2013/09/05 09:01:27 gsutre Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_cdefs.c,v 1.3 2013/09/05 09:01:27 gsutre Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_struct
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|intmax_t
name|min
decl_stmt|;
name|intmax_t
name|max
decl_stmt|;
block|}
name|s
index|[]
init|=
block|{
block|{
literal|"signed char"
block|,
name|SCHAR_MIN
block|,
name|SCHAR_MAX
block|}
block|,
block|{
literal|"signed short"
block|,
name|SHRT_MIN
block|,
name|SHRT_MAX
block|}
block|,
block|{
literal|"signed int"
block|,
name|INT_MIN
block|,
name|INT_MAX
block|}
block|,
block|{
literal|"signed long"
block|,
name|LONG_MIN
block|,
name|LONG_MAX
block|}
block|,
block|{
literal|"signed long long"
block|,
name|LLONG_MIN
block|,
name|LLONG_MAX
block|}
block|, }
struct|;
end_struct

begin_struct
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|uintmax_t
name|min
decl_stmt|;
name|uintmax_t
name|max
decl_stmt|;
block|}
name|u
index|[]
init|=
block|{
block|{
literal|"unsigned char"
block|,
literal|0
block|,
name|UCHAR_MAX
block|}
block|,
block|{
literal|"unsigned short"
block|,
literal|0
block|,
name|USHRT_MAX
block|}
block|,
block|{
literal|"unsigned int"
block|,
literal|0
block|,
name|UINT_MAX
block|}
block|,
block|{
literal|"unsigned long"
block|,
literal|0
block|,
name|ULONG_MAX
block|}
block|,
block|{
literal|"unsigned long long"
block|,
literal|0
block|,
name|ULLONG_MAX
block|}
block|, }
struct|;
end_struct

begin_expr_stmt
name|ATF_TC
argument_list|(
name|stypeminmax
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|stypeminmax
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks signed type min/max macros"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|stypeminmax
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ATF_REQUIRE(__type_min(a) == s[b].min); \     ATF_REQUIRE(__type_max(a) == s[b].max)
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|2
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long
argument_list|,
literal|3
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|4
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|utypeminmax
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|utypeminmax
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks unsigned type min/max macros"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|utypeminmax
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ATF_REQUIRE(__type_min(a) == u[b].min); \     ATF_REQUIRE(__type_max(a) == u[b].max)
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|2
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long
argument_list|,
literal|3
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|4
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|sissigned
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|sissigned
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks issigned macro for signed"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|sissigned
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|)
value|ATF_REQUIRE(__type_is_signed(a) == 1)
name|CHECK
argument_list|(
argument|signed char
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|uissigned
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|uissigned
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks issigned macro for unsigned"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|uissigned
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|)
value|ATF_REQUIRE(__type_is_signed(a) == 0)
name|CHECK
argument_list|(
argument|unsigned char
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|utypemask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|utypemask
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks type mask macro for unsigned"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|utypemask
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ATF_REQUIRE(__type_mask(a) == b)
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0xffffffffffffff00ULL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|0xffffffffffff0000ULL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|0xffffffff00000000ULL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|0x0000000000000000ULL
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|stypemask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|stypemask
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks type mask macro for signed"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|stypemask
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ATF_REQUIRE(__type_mask(a) == b)
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0xffffffffffffff00LL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|0xffffffffffff0000LL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|0xffffffff00000000LL
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|0x0000000000000000LL
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|stypefit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|stypefit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks typefit macro for signed"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|stypefit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ATF_REQUIRE(!__type_fit(a, b) == c)
name|CHECK
argument_list|(
argument|signed char
argument_list|,
argument|-
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0x7f
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0x80
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0xff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed char
argument_list|,
literal|0x1ff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
argument|-
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|0x7fff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|0x8000
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|0xffff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed short
argument_list|,
literal|0x1ffff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
argument|-
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|0x7fffffff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|0x80000000
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|0xffffffff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed int
argument_list|,
literal|0x1ffffffffLL
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
argument|-
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|0x7fffffffffffffffLL
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|0x8000000000000000LL
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|signed long long
argument_list|,
literal|0xffffffffffffffffLL
argument_list|,
literal|1
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|utypefit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|utypefit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks typefit macro for unsigned"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|utypefit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
define|#
directive|define
name|CHECK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ATF_REQUIRE(!__type_fit(a, b) == c)
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
argument|-
literal|1
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0x7f
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0x80
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0xff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned char
argument_list|,
literal|0x1ff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
argument|-
literal|1
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|0x7fff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|0x8000
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|0xffff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned short
argument_list|,
literal|0x1ffff
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
argument|-
literal|1
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|0x7fffffff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|0x80000000
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|0xffffffff
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned int
argument_list|,
literal|0x1ffffffffLL
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
argument|-
literal|1
argument_list|,
literal|1
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|0x7fffffffffffffffULL
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|0x8000000000000000ULL
argument_list|,
literal|0
argument_list|)
empty_stmt|;
name|CHECK
argument_list|(
argument|unsigned long long
argument_list|,
literal|0xffffffffffffffffULL
argument_list|,
literal|0
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|CHECK
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|stypeminmax
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|utypeminmax
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|sissigned
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|uissigned
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|stypemask
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|utypemask
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|stypefit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|utypefit
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

