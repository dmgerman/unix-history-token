begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: flags.c,v 1.4 2002/11/02 07:16:36 darrenr Exp  */
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
name|char
name|flagset
index|[]
init|=
literal|"FSRPAUEC"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|flags
index|[]
init|=
block|{
name|TH_FIN
block|,
name|TH_SYN
block|,
name|TH_RST
block|,
name|TH_PUSH
block|,
name|TH_ACK
block|,
name|TH_URG
block|,
name|TH_ECN
block|,
name|TH_CWR
block|}
decl_stmt|;
end_decl_stmt

end_unit

