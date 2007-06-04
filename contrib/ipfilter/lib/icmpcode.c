begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000-2006 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: icmpcode.c,v 1.7.2.5 2006/06/16 17:21:02 darrenr Exp $  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|icmpcodes
index|[
name|MAX_ICMPCODE
operator|+
literal|1
index|]
init|=
block|{
literal|"net-unr"
block|,
literal|"host-unr"
block|,
literal|"proto-unr"
block|,
literal|"port-unr"
block|,
literal|"needfrag"
block|,
literal|"srcfail"
block|,
literal|"net-unk"
block|,
literal|"host-unk"
block|,
literal|"isolate"
block|,
literal|"net-prohib"
block|,
literal|"host-prohib"
block|,
literal|"net-tos"
block|,
literal|"host-tos"
block|,
literal|"filter-prohib"
block|,
literal|"host-preced"
block|,
literal|"preced-cutoff"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

