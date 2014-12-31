begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_xdr.c,v 1.1 2011/01/08 06:59:37 pgoyette Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Ben Harris.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Ben Harris  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
literal|"$NetBSD: t_xdr.c,v 1.1 2011/01/08 06:59:37 pgoyette Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"h_testbits.h"
end_include

begin_decl_stmt
name|char
name|xdrdata
index|[]
init|=
block|{
literal|0x3f
block|,
literal|0xf0
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* double 1.0 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x01
block|,
comment|/* enum smallenum SE_ONE */
literal|0xff
block|,
literal|0xff
block|,
literal|0xfb
block|,
literal|0x2e
block|,
comment|/* enum medenum ME_NEG */
literal|0x00
block|,
literal|0x12
block|,
literal|0xd6
block|,
literal|0x87
block|,
comment|/* enum bigenum BE_LOTS */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ATF_TC
argument_list|(
name|xdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|xdr
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
literal|"Checks encoding/decoding of doubles and enumerations"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|xdr
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|XDR
name|x
decl_stmt|;
name|double
name|d
decl_stmt|;
name|smallenum
name|s
decl_stmt|;
name|medenum
name|m
decl_stmt|;
name|bigenum
name|b
decl_stmt|;
name|char
name|newdata
index|[
sizeof|sizeof
argument_list|(
name|xdrdata
argument_list|)
index|]
decl_stmt|;
name|xdrmem_create
argument_list|(
operator|&
name|x
argument_list|,
name|xdrdata
argument_list|,
sizeof|sizeof
argument_list|(
name|xdrdata
argument_list|)
argument_list|,
name|XDR_DECODE
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_double
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|d
argument_list|)
argument_list|,
literal|"xdr_double DECODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|d
argument_list|,
literal|1.0
argument_list|,
literal|"double 1.0 decoded as %g"
argument_list|,
name|d
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_smallenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|s
argument_list|)
argument_list|,
literal|"xdr_smallenum DECODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|s
argument_list|,
name|SE_ONE
argument_list|,
literal|"SE_ONE decoded as %d"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_medenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|m
argument_list|)
argument_list|,
literal|"xdr_medenum DECODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|m
argument_list|,
name|ME_NEG
argument_list|,
literal|"ME_NEG decoded as %d"
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_bigenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|b
argument_list|)
argument_list|,
literal|"xdr_bigenum DECODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
name|b
argument_list|,
name|BE_LOTS
argument_list|,
literal|"BE_LOTS decoded as %d"
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|xdr_destroy
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
name|xdrmem_create
argument_list|(
operator|&
name|x
argument_list|,
name|newdata
argument_list|,
sizeof|sizeof
argument_list|(
name|newdata
argument_list|)
argument_list|,
name|XDR_ENCODE
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_double
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|d
argument_list|)
argument_list|,
literal|"xdr_double ENCODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_smallenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|s
argument_list|)
argument_list|,
literal|"xdr_smallenum ENCODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_medenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|m
argument_list|)
argument_list|,
literal|"xdr_medenum ENCODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|xdr_bigenum
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|b
argument_list|)
argument_list|,
literal|"xdr_bigenum ENCODE failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|memcmp
argument_list|(
name|newdata
argument_list|,
name|xdrdata
argument_list|,
sizeof|sizeof
argument_list|(
name|xdrdata
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|,
literal|"xdr ENCODE result differs"
argument_list|)
expr_stmt|;
name|xdr_destroy
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
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
name|xdr
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

