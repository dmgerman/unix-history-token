begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Some OpenFirmware helper functions that are likely machine dependent.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<machine/idprom.h>
end_include

begin_include
include|#
directive|include
file|<machine/ofw_machdep.h>
end_include

begin_function
name|void
name|OF_getetheraddr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
modifier|*
name|addr
parameter_list|)
block|{
name|phandle_t
name|node
decl_stmt|;
name|struct
name|idprom
name|idp
decl_stmt|;
name|node
operator|=
name|OF_peer
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|<=
literal|0
operator|||
name|OF_getprop
argument_list|(
name|node
argument_list|,
literal|"idprom"
argument_list|,
operator|&
name|idp
argument_list|,
sizeof|sizeof
argument_list|(
name|idp
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|panic
argument_list|(
literal|"Could not determine the machine ethernet address"
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|idp
operator|.
name|id_ether
argument_list|,
name|addr
argument_list|,
name|ETHER_ADDR_LEN
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

