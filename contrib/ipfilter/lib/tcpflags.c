begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: tcpflags.c,v 1.3 2002/11/02 07:18:01 darrenr Exp  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_comment
comment|/*  * ECN is a new addition to TCP - RFC 2481  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TH_ECN
end_ifndef

begin_define
define|#
directive|define
name|TH_ECN
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TH_CWR
end_ifndef

begin_define
define|#
directive|define
name|TH_CWR
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|flagset
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|flags
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|u_char
name|tcpflags
parameter_list|(
name|flgs
parameter_list|)
name|char
modifier|*
name|flgs
decl_stmt|;
block|{
name|u_char
name|tcpf
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|t
decl_stmt|;
for|for
control|(
name|s
operator|=
name|flgs
init|;
operator|*
name|s
condition|;
name|s
operator|++
control|)
block|{
if|if
condition|(
operator|*
name|s
operator|==
literal|'W'
condition|)
name|tcpf
operator||=
name|TH_CWR
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|!
operator|(
name|t
operator|=
name|strchr
argument_list|(
name|flagset
argument_list|,
operator|*
name|s
argument_list|)
operator|)
condition|)
block|{
return|return
literal|0
return|;
block|}
name|tcpf
operator||=
name|flags
index|[
name|t
operator|-
name|flagset
index|]
expr_stmt|;
block|}
block|}
return|return
name|tcpf
return|;
block|}
end_function

end_unit

