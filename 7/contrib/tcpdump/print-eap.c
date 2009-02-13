begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 - Michael Richardson<mcr@xelerance.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Format and print bootp packets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-eap.c,v 1.3 2004/04/23 19:03:39 mcr Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"ether.h"
end_include

begin_struct
struct|struct
name|eap_packet_t
block|{
name|unsigned
name|char
name|code
decl_stmt|;
name|unsigned
name|char
name|id
decl_stmt|;
name|unsigned
name|char
name|length
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Print bootp requests  */
end_comment

begin_function
name|void
name|eap_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
name|u_int
name|length
name|_U_
parameter_list|)
block|{
specifier|const
name|struct
name|eap_packet_t
modifier|*
name|eap
decl_stmt|;
name|eap
operator|=
operator|(
specifier|const
expr|struct
name|eap_packet_t
operator|*
operator|)
name|cp
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|eap
operator|->
name|data
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"EAP code=%u id=%u length=%u "
operator|,
name|eap
operator|->
name|code
operator|,
name|eap
operator|->
name|id
operator|,
operator|(
name|eap
operator|->
name|length
index|[
literal|0
index|]
operator|<<
literal|8
operator|)
operator|+
name|eap
operator|->
name|length
index|[
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ndo
operator|->
name|ndo_vflag
condition|)
return|return;
name|trunc
label|:
empty_stmt|;
block|}
end_function

end_unit

