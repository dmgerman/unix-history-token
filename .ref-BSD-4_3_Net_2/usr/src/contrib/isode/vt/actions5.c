begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* actions5.c - VTPM: FSM sector 5 actions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/vt/RCS/actions5.c,v 7.1 91/02/22 09:47:54 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/actions5.c,v 7.1 91/02/22 09:47:54 mrose Interim $  *  *  * $Log:	actions5.c,v $  * Revision 7.1  91/02/22  09:47:54  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:31:27  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"vtpm.h"
end_include

begin_include
include|#
directive|include
file|"sector1.h"
end_include

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*	This file contains the functions that are executed when the	*/
end_comment

begin_comment
comment|/*	VT Protocol machine is in a Sector 5 state and a protocol	*/
end_comment

begin_comment
comment|/*	event occurs.  The state transition matrix is specified in	*/
end_comment

begin_comment
comment|/*	Table 32 of ISO 9041 (July 1987 version).  The actions which	*/
end_comment

begin_comment
comment|/*	this collection of functions perform are specified in Table 40	*/
end_comment

begin_comment
comment|/*	of ISO 9041.							*/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Global Session Descriptor (ISODE) */
end_comment

begin_comment
comment|/*  xx1x xxxx = awaiting ack from peer i.e., 420 */
end_comment

begin_comment
comment|/*  xxxx xx1x = awaiting ack from user */
end_comment

begin_comment
comment|/* T = got token, N = no got token */
end_comment

begin_comment
comment|/*  		   req: usr==>vtpm 		   ind: vtpm==>usr 		*/
end_comment

begin_function
name|int
name|ce_104
parameter_list|(
name|pe
parameter_list|)
comment|/* common event 104 */
name|PE
name|pe
decl_stmt|;
block|{
comment|/* if (vnt> 0) */
if|if
condition|(
name|pe
operator|!=
name|NULLPE
condition|)
name|vdatind
argument_list|(
name|SEQUENCED
argument_list|,
name|pe
argument_list|)
expr_stmt|;
name|vnt
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ce_105
parameter_list|()
comment|/* common event 105 */
block|{
comment|/* if (vns> 0)  for(... */
if|if
condition|(
name|p_ondq
operator|!=
name|NULLPE
condition|)
operator|(
name|void
operator|)
name|p_data
argument_list|(
name|p_ondq
argument_list|)
expr_stmt|;
comment|/* send NDQ	*/
name|vns
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a5_0
parameter_list|(
name|pe
parameter_list|)
comment|/*VDATreq-sqtr in states 400B or 402B */
comment|/* V data request addressing sequenced trigger co */
name|PE
name|pe
decl_stmt|;
block|{
return|return
operator|(
name|ce_105
argument_list|()
operator|)
return|;
comment|/* 	==> SAMESTATE; */
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a5_1
parameter_list|(
name|pe
parameter_list|)
comment|/*VDATreq-n in states 400B, 402B or 40T */
comment|/* V data request addressing sequenced trigger co */
name|PE
name|pe
decl_stmt|;
block|{
comment|/* 	vns++; 	==> SAMESTATE 	*/
return|return
operator|(
name|ce_105
argument_list|()
operator|)
return|;
comment|/*Autonomous Event to Ship it*/
block|}
end_function

begin_function
name|int
name|a5_2
parameter_list|(
name|pe
parameter_list|)
comment|/*NDQ-tr in states 400B, 420B */
name|PE
name|pe
decl_stmt|;
block|{
comment|/* 	vnt++; 	*/
return|return
operator|(
name|ce_104
argument_list|(
name|pe
argument_list|)
operator|)
return|;
comment|/* 	==> SAMESTATE 	*/
block|}
end_function

begin_function
name|int
name|a5_3
parameter_list|(
name|pe
parameter_list|)
comment|/*NDQ-ntr in states 400B, 420B */
name|PE
name|pe
decl_stmt|;
block|{
comment|/* 	vnt++; 	*/
comment|/* 	==> SAMESTATE 	*/
return|return
operator|(
name|ce_104
argument_list|(
name|pe
argument_list|)
operator|)
return|;
comment|/*Autonomous Event to Deliver to User*/
block|}
end_function

begin_function
name|int
name|a5_5
parameter_list|(
name|pe
parameter_list|)
comment|/* VBRKreq  */
name|PE
name|pe
decl_stmt|;
block|{
name|vtok
operator|=
literal|0
expr_stmt|;
comment|/* giving the token away */
name|vnt
operator|=
literal|0
expr_stmt|;
name|vns
operator|=
literal|0
expr_stmt|;
comment|/* vtkp was set in vbrkreq so it could be coded in to the pe */
operator|(
name|void
operator|)
name|p_resync_req
argument_list|(
name|pe
argument_list|,
name|SYNC_RESTART
argument_list|)
expr_stmt|;
comment|/* send break request */
name|state
operator|=
name|S5_61
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_6
parameter_list|(
name|pe
parameter_list|)
comment|/* VBRKrsp in state 62 */
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|p_resync_resp
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/* send out break response */
if|if
condition|(
name|vsmd
operator|&&
name|vtok
condition|)
name|state
operator|=
name|S5_40T
expr_stmt|;
elseif|else
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S5_40N
expr_stmt|;
else|else
block|{
name|vtkp
operator|=
name|INITIATOR
expr_stmt|;
if|if
condition|(
name|vtok
condition|)
name|vtkp
operator|=
name|ACCEPTOR
expr_stmt|;
name|state
operator|=
name|S5_400B
expr_stmt|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_9
parameter_list|(
name|pe
parameter_list|)
comment|/*VDELreq in states 400B, 402B */
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|dcno
condition|)
comment|/* no delivery control */
block|{
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"a5_9: dcno hasn't been set"
argument_list|)
expr_stmt|;
comment|/* ==> SAMESTATE */
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
operator|(
name|void
operator|)
name|ce_105
argument_list|()
expr_stmt|;
comment|/* send out dlq */
comment|/* this will be replace by the new-fangled pepy schtuff; 		will use this now for compatability */
operator|(
name|void
operator|)
name|p_data
argument_list|(
name|pe
argument_list|)
expr_stmt|;
name|state
operator|=
operator|(
name|vra
operator|)
condition|?
name|state
operator|+
literal|2
else|:
name|state
expr_stmt|;
comment|/* pretty neeto eh? */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_11
parameter_list|(
name|pe
parameter_list|)
comment|/*HDQ request in 400B*/
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|p_typed_data
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|a5_17
parameter_list|(
name|pe
parameter_list|)
comment|/*VRELreq in states 400B */
name|PE
name|pe
decl_stmt|;
block|{
comment|/*	ce_105(); */
name|sector
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|vtok
condition|)
block|{
name|state
operator|=
name|S1_51Q
expr_stmt|;
comment|/*Must change state first because 					  vt_disconnect gets RLR& calls 					  state machine again. */
name|vt_disconnect
argument_list|()
expr_stmt|;
comment|/*May be only TEMP*/
block|}
else|else
block|{
name|request_token
argument_list|()
expr_stmt|;
comment|/*Need call to ISODE to request token*/
name|state
operator|=
name|S1_50B
expr_stmt|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_28
parameter_list|(
name|pe
parameter_list|)
comment|/*UDQ request in 400B*/
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|p_typed_data
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_31
parameter_list|(
name|pe
parameter_list|)
comment|/* BKR in 61 */
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|vsmd
operator|&&
name|vtok
condition|)
name|state
operator|=
name|S5_40T
expr_stmt|;
elseif|else
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S5_40N
expr_stmt|;
else|else
name|state
operator|=
name|S5_400B
expr_stmt|;
name|vbrkcnf
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_32
parameter_list|(
name|pe
parameter_list|)
comment|/* BKQ could occur in any state except 62 */
name|PE
name|pe
decl_stmt|;
block|{
name|vnt
operator|=
literal|0
expr_stmt|;
name|vns
operator|=
literal|0
expr_stmt|;
comment|/* 	   vbrkind clears queues etc. 	   and then map the break character to user 	   and sets vtok to 1 	   (we should have received the token)  	*/
name|state
operator|=
name|S5_62
expr_stmt|;
name|vbrkind
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_34
parameter_list|(
name|pe
parameter_list|)
comment|/*UDQ in 400B*/
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|pe
operator|!=
name|NULLPE
condition|)
name|vudatind
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_35
parameter_list|(
name|pe
parameter_list|)
comment|/* DEL in states 400B, 420B */
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
operator|(
name|vra
operator|=
name|prim2flag
argument_list|(
name|pe
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|adios
argument_list|(
literal|"a5_35: bogus PDU (%s)"
argument_list|,
name|pe_error
argument_list|(
name|pe
operator|->
name|pe_errno
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ce_104
argument_list|(
name|NULLPE
argument_list|)
expr_stmt|;
name|vdelind
argument_list|(
name|pe
argument_list|,
name|vra
argument_list|)
expr_stmt|;
name|state
operator|=
operator|(
name|vra
operator|)
condition|?
name|state
operator|+
literal|2
else|:
name|state
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_38
parameter_list|(
name|pe
parameter_list|)
comment|/* RLQ in states 400B */
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|ce_104
argument_list|(
name|pe
argument_list|)
expr_stmt|;
name|sector
operator|=
literal|1
expr_stmt|;
name|state
operator|=
name|S1_51R
expr_stmt|;
operator|(
name|void
operator|)
name|vrelind
argument_list|()
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_function
name|int
name|a5_106
parameter_list|(
name|pe
parameter_list|)
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|pe
operator|!=
name|NULLPE
condition|)
name|vhdatind
argument_list|(
name|pe
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

