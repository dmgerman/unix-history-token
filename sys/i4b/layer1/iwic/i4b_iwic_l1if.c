begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Dave Boyce. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_iwic - isdn4bsd Winbond W6692 driver  *      ----------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Jan 21 11:09:33 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"iwic.h"
end_include

begin_include
include|#
directive|include
file|"opt_i4b.h"
end_include

begin_include
include|#
directive|include
file|"pci.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NIWIC
operator|>
literal|0
operator|)
operator|&&
operator|(
name|NPCI
operator|>
literal|0
operator|)
end_if

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
file|<machine/i4b_debug.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_trace.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_global.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_l1.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/iwic/i4b_iwic.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/iwic/i4b_iwic_ext.h>
end_include

begin_comment
comment|/* jump table for multiplex routines */
end_comment

begin_decl_stmt
name|struct
name|i4b_l1mux_func
name|iwic_l1mux_func
init|=
block|{
name|iwic_ret_linktab
block|,
name|iwic_set_linktab
block|,
name|iwic_mph_command_req
block|,
name|iwic_ph_data_req
block|,
name|iwic_ph_activate_req
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------------------------*  *  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|iwic_ph_data_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|freeflag
parameter_list|)
block|{
name|struct
name|iwic_softc
modifier|*
name|sc
init|=
name|iwic_find_sc
argument_list|(
name|unit
argument_list|)
decl_stmt|;
return|return
name|iwic_dchan_data_req
argument_list|(
name|sc
argument_list|,
name|m
argument_list|,
name|freeflag
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|iwic_ph_activate_req
parameter_list|(
name|int
name|unit
parameter_list|)
block|{
name|struct
name|iwic_softc
modifier|*
name|sc
init|=
name|iwic_find_sc
argument_list|(
name|unit
argument_list|)
decl_stmt|;
name|iwic_next_state
argument_list|(
name|sc
argument_list|,
name|EV_PHAR
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|iwic_mph_command_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|command
parameter_list|,
name|void
modifier|*
name|parm
parameter_list|)
block|{
name|struct
name|iwic_softc
modifier|*
name|sc
init|=
name|iwic_find_sc
argument_list|(
name|unit
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|command
condition|)
block|{
case|case
name|CMR_DOPEN
case|:
comment|/* Daemon running */
name|NDBGL1
argument_list|(
name|L1_PRIM
argument_list|,
literal|"CMR_DOPEN"
argument_list|)
expr_stmt|;
name|sc
operator|->
name|enabled
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
name|CMR_DCLOSE
case|:
comment|/* Daemon not running */
name|NDBGL1
argument_list|(
name|L1_PRIM
argument_list|,
literal|"CMR_DCLOSE"
argument_list|)
expr_stmt|;
name|sc
operator|->
name|enabled
operator|=
name|FALSE
expr_stmt|;
break|break;
case|case
name|CMR_SETTRACE
case|:
name|NDBGL1
argument_list|(
name|L1_PRIM
argument_list|,
literal|"CMR_SETTRACE, parm = %d"
argument_list|,
operator|(
name|unsigned
name|int
operator|)
name|parm
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_trace
operator|=
operator|(
name|unsigned
name|int
operator|)
name|parm
expr_stmt|;
break|break;
default|default:
name|NDBGL1
argument_list|(
name|L1_PRIM
argument_list|,
literal|"unknown command = %d"
argument_list|,
name|command
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|isdn_link_t
modifier|*
name|iwic_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
block|{
name|struct
name|iwic_softc
modifier|*
name|sc
init|=
name|iwic_find_sc
argument_list|(
name|unit
argument_list|)
decl_stmt|;
name|struct
name|iwic_bchan
modifier|*
name|bchan
init|=
operator|&
name|sc
operator|->
name|sc_bchan
index|[
name|channel
index|]
decl_stmt|;
return|return
operator|&
name|bchan
operator|->
name|iwic_isdn_linktab
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|iwic_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|drvr_link_t
modifier|*
name|dlt
parameter_list|)
block|{
name|struct
name|iwic_softc
modifier|*
name|sc
init|=
name|iwic_find_sc
argument_list|(
name|unit
argument_list|)
decl_stmt|;
name|struct
name|iwic_bchan
modifier|*
name|bchan
init|=
operator|&
name|sc
operator|->
name|sc_bchan
index|[
name|channel
index|]
decl_stmt|;
name|bchan
operator|->
name|iwic_drvr_linktab
operator|=
name|dlt
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

