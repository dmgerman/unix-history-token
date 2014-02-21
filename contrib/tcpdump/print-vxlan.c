begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Francesco Fondelli (francesco dot fondelli, gmail dot com)  */
end_comment

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_include
include|#
directive|include
file|"udp.h"
end_include

begin_comment
comment|/*  * VXLAN header, draft-mahalingam-dutt-dcops-vxlan-03  *  *     0                   1                   2                   3  *     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |R|R|R|R|I|R|R|R|            Reserved                           |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *    |                VXLAN Network Identifier (VNI) |   Reserved    |  *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   */
end_comment

begin_function
name|void
name|vxlan_print
parameter_list|(
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|u_int8_t
name|flags
decl_stmt|;
name|u_int32_t
name|vni
decl_stmt|;
if|if
condition|(
name|len
operator|<
literal|8
condition|)
block|{
name|printf
argument_list|(
literal|"[|VXLAN]"
argument_list|)
expr_stmt|;
return|return;
block|}
name|flags
operator|=
operator|*
name|bp
expr_stmt|;
name|bp
operator|+=
literal|4
expr_stmt|;
name|vni
operator|=
name|EXTRACT_24BITS
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|bp
operator|+=
literal|4
expr_stmt|;
name|printf
argument_list|(
literal|"VXLAN, "
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"flags ["
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
literal|0x08
condition|)
name|fputs
argument_list|(
literal|"I"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
else|else
name|fputs
argument_list|(
literal|"."
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"] "
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"(0x%02x), "
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"vni %u\n"
argument_list|,
name|vni
argument_list|)
expr_stmt|;
name|ether_print
argument_list|(
name|gndo
argument_list|,
name|bp
argument_list|,
name|len
operator|-
literal|8
argument_list|,
name|len
operator|-
literal|8
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

