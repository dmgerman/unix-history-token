begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_lme.c - layer management entity  *	-------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sat Mar  9 17:49:42 2002]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"i4bq921.h"
end_include

begin_if
if|#
directive|if
name|NI4BQ921
operator|>
literal|0
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
file|<i4b/layer2/i4b_l2.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *	mdl assign indication handler  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_mdl_assign_ind
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
block|{
name|NDBGL2
argument_list|(
name|L2_PRIM
argument_list|,
literal|"unit %d"
argument_list|,
name|l2sc
operator|->
name|unit
argument_list|)
expr_stmt|;
name|i4b_l1_activate
argument_list|(
name|l2sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|l2sc
operator|->
name|tei_valid
operator|==
name|TEI_VALID
condition|)
block|{
name|l2sc
operator|->
name|T202func
operator|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
name|i4b_tei_verify
expr_stmt|;
name|l2sc
operator|->
name|N202
operator|=
name|N202DEF
expr_stmt|;
name|i4b_tei_verify
argument_list|(
name|l2sc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|l2sc
operator|->
name|T202func
operator|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
name|i4b_tei_assign
expr_stmt|;
name|l2sc
operator|->
name|N202
operator|=
name|N202DEF
expr_stmt|;
name|i4b_tei_assign
argument_list|(
name|l2sc
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	i4b_mdl_error_ind handler (Q.921 01/94 pp 156)  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_mdl_error_ind
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|char
modifier|*
name|where
parameter_list|,
name|int
name|errorcode
parameter_list|)
block|{
if|#
directive|if
name|DO_I4B_DEBUG
specifier|static
name|char
modifier|*
name|error_text
index|[]
init|=
block|{
literal|"MDL_ERR_A: rx'd unsolicited response - supervisory (F=1)"
block|,
literal|"MDL_ERR_B: rx'd unsolicited response - DM (F=1)"
block|,
literal|"MDL_ERR_C: rx'd unsolicited response - UA (F=1)"
block|,
literal|"MDL_ERR_D: rx'd unsolicited response - UA (F=0)"
block|,
literal|"MDL_ERR_E: rx'd unsolicited response - DM (F=0)"
block|,
literal|"MDL_ERR_F: peer initiated re-establishment - SABME"
block|,
literal|"MDL_ERR_G: unsuccessful transmission N200times - SABME"
block|,
literal|"MDL_ERR_H: unsuccessful transmission N200times - DIS"
block|,
literal|"MDL_ERR_I: unsuccessful transmission N200times - Status ENQ"
block|,
literal|"MDL_ERR_J: other error - N(R) error"
block|,
literal|"MDL_ERR_K: other error - rx'd FRMR response"
block|,
literal|"MDL_ERR_L: other error - rx'd undefined frame"
block|,
literal|"MDL_ERR_M: other error - receipt of I field not permitted"
block|,
literal|"MDL_ERR_N: other error - rx'd frame with wrong size"
block|,
literal|"MDL_ERR_O: other error - N201 error"
block|,
literal|"MDL_ERR_MAX: i4b_mdl_error_ind called with wrong parameter!!!"
block|}
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|errorcode
operator|>
name|MDL_ERR_MAX
condition|)
name|errorcode
operator|=
name|MDL_ERR_MAX
expr_stmt|;
name|NDBGL2
argument_list|(
name|L2_ERROR
argument_list|,
literal|"unit = %d, location = %s"
argument_list|,
name|l2sc
operator|->
name|unit
argument_list|,
name|where
argument_list|)
expr_stmt|;
name|NDBGL2
argument_list|(
name|L2_ERROR
argument_list|,
literal|"error = %s"
argument_list|,
name|error_text
index|[
name|errorcode
index|]
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|errorcode
condition|)
block|{
case|case
name|MDL_ERR_A
case|:
case|case
name|MDL_ERR_B
case|:
break|break;
case|case
name|MDL_ERR_C
case|:
case|case
name|MDL_ERR_D
case|:
name|i4b_tei_verify
argument_list|(
name|l2sc
argument_list|)
expr_stmt|;
break|break;
case|case
name|MDL_ERR_E
case|:
case|case
name|MDL_ERR_F
case|:
break|break;
case|case
name|MDL_ERR_G
case|:
case|case
name|MDL_ERR_H
case|:
name|i4b_tei_verify
argument_list|(
name|l2sc
argument_list|)
expr_stmt|;
break|break;
case|case
name|MDL_ERR_I
case|:
case|case
name|MDL_ERR_J
case|:
case|case
name|MDL_ERR_K
case|:
case|case
name|MDL_ERR_L
case|:
case|case
name|MDL_ERR_M
case|:
case|case
name|MDL_ERR_N
case|:
case|case
name|MDL_ERR_O
case|:
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NI4BQ921> 0 */
end_comment

end_unit

