begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * iwn ioctl API.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|"net80211/ieee80211_ioctl.h"
end_include

begin_include
include|#
directive|include
file|"net80211/ieee80211_radiotap.h"
end_include

begin_include
include|#
directive|include
file|"if_iwn_ioctl.h"
end_include

begin_comment
comment|/*  * This contains the register definitions for iwn; including  * the statistics definitions.  */
end_comment

begin_include
include|#
directive|include
file|"if_iwnreg.h"
end_include

begin_include
include|#
directive|include
file|"iwnstats.h"
end_include

begin_include
include|#
directive|include
file|"iwn_ioctl.h"
end_include

begin_function
name|void
name|iwn_setifname
parameter_list|(
name|struct
name|iwnstats
modifier|*
name|is
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
block|{
name|strncpy
argument_list|(
name|is
operator|->
name|ifr
operator|.
name|ifr_name
argument_list|,
name|ifname
argument_list|,
sizeof|sizeof
argument_list|(
name|is
operator|->
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|iwn_zerostats
parameter_list|(
name|struct
name|iwnstats
modifier|*
name|is
parameter_list|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|is
operator|->
name|s
argument_list|,
name|SIOCZIWNSTATS
argument_list|,
operator|&
name|is
operator|->
name|ifr
argument_list|)
operator|<
literal|0
condition|)
name|err
argument_list|(
operator|-
literal|1
argument_list|,
literal|"ioctl: %s"
argument_list|,
name|is
operator|->
name|ifr
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|iwn_collect
parameter_list|(
name|struct
name|iwnstats
modifier|*
name|is
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|is
operator|->
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|is
operator|->
name|st
expr_stmt|;
name|err
operator|=
name|ioctl
argument_list|(
name|is
operator|->
name|s
argument_list|,
name|SIOCGIWNSTATS
argument_list|,
operator|&
name|is
operator|->
name|ifr
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|<
literal|0
condition|)
name|warn
argument_list|(
literal|"ioctl: %s"
argument_list|,
name|is
operator|->
name|ifr
operator|.
name|ifr_name
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

end_unit

