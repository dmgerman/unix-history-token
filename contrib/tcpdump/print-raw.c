begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

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
file|"interface.h"
end_include

begin_comment
comment|/*  * The DLT_RAW packet has no header. It contains a raw IP packet.  */
end_comment

begin_function
name|u_int
name|raw_if_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
name|ndo
operator|->
name|ndo_eflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ip: "
operator|)
argument_list|)
expr_stmt|;
name|ipN_print
argument_list|(
name|ndo
argument_list|,
name|p
argument_list|,
name|h
operator|->
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

