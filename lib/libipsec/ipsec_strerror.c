begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipsec_strerror.c,v 1.7 2000/07/30 00:45:12 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, 1998, and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ipsec.h>
end_include

begin_include
include|#
directive|include
file|"ipsec_strerror.h"
end_include

begin_decl_stmt
name|int
name|__ipsec_errcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ipsec_errlist
index|[]
init|=
block|{
literal|"Success"
block|,
comment|/*EIPSEC_NO_ERROR*/
literal|"Not supported"
block|,
comment|/*EIPSEC_NOT_SUPPORTED*/
literal|"Invalid argument"
block|,
comment|/*EIPSEC_INVAL_ARGUMENT*/
literal|"Invalid sadb message"
block|,
comment|/*EIPSEC_INVAL_SADBMSG*/
literal|"Invalid version"
block|,
comment|/*EIPSEC_INVAL_VERSION*/
literal|"Invalid security policy"
block|,
comment|/*EIPSEC_INVAL_POLICY*/
literal|"Invalid address specification"
block|,
comment|/*EIPSEC_INVAL_ADDRESS*/
literal|"Invalid ipsec protocol"
block|,
comment|/*EIPSEC_INVAL_PROTO*/
literal|"Invalid ipsec mode"
block|,
comment|/*EIPSEC_INVAL_MODE*/
literal|"Invalid ipsec level"
block|,
comment|/*EIPSEC_INVAL_LEVEL*/
literal|"Invalid SA type"
block|,
comment|/*EIPSEC_INVAL_SATYPE*/
literal|"Invalid message type"
block|,
comment|/*EIPSEC_INVAL_MSGTYPE*/
literal|"Invalid extension type"
block|,
comment|/*EIPSEC_INVAL_EXTTYPE*/
literal|"Invalid algorithm type"
block|,
comment|/*EIPSEC_INVAL_ALGS*/
literal|"Invalid key length"
block|,
comment|/*EIPSEC_INVAL_KEYLEN*/
literal|"Invalid address family"
block|,
comment|/*EIPSEC_INVAL_FAMILY*/
literal|"Invalid prefix length"
block|,
comment|/*EIPSEC_INVAL_PREFIXLEN*/
literal|"Invalid direciton"
block|,
comment|/*EIPSEC_INVAL_DIR*/
literal|"SPI range violation"
block|,
comment|/*EIPSEC_INVAL_SPI*/
literal|"No protocol specified"
block|,
comment|/*EIPSEC_NO_PROTO*/
literal|"No algorithm specified"
block|,
comment|/*EIPSEC_NO_ALGS*/
literal|"No buffers available"
block|,
comment|/*EIPSEC_NO_BUFS*/
literal|"Must get supported algorithms list first"
block|,
comment|/*EIPSEC_DO_GET_SUPP_LIST*/
literal|"Protocol mismatch"
block|,
comment|/*EIPSEC_PROTO_MISMATCH*/
literal|"Family mismatch"
block|,
comment|/*EIPSEC_FAMILY_MISMATCH*/
literal|"Too few arguments"
block|,
comment|/*EIPSEC_FEW_ARGUMENTS*/
name|NULL
block|,
comment|/*EIPSEC_SYSTEM_ERROR*/
literal|"Unknown error"
block|,
comment|/*EIPSEC_MAX*/
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|ipsec_strerror
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|__ipsec_errcode
operator|<
literal|0
operator|||
name|__ipsec_errcode
operator|>
name|EIPSEC_MAX
condition|)
name|__ipsec_errcode
operator|=
name|EIPSEC_MAX
expr_stmt|;
return|return
name|ipsec_errlist
index|[
name|__ipsec_errcode
index|]
return|;
block|}
end_function

begin_function
name|void
name|__ipsec_set_strerror
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|__ipsec_errcode
operator|=
name|EIPSEC_SYSTEM_ERROR
expr_stmt|;
name|ipsec_errlist
index|[
name|EIPSEC_SYSTEM_ERROR
index|]
operator|=
name|str
expr_stmt|;
return|return;
block|}
end_function

end_unit

