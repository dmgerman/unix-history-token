begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* actions1.c - VTPM: FSM sector 1 actions */
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
literal|"$Header: /f/osi/vt/RCS/actions1.c,v 7.2 91/02/22 09:47:52 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/actions1.c,v 7.2 91/02/22 09:47:52 mrose Interim $  *  *  * $Log:	actions1.c,v $  * Revision 7.2  91/02/22  09:47:52  mrose  * Interim 6.8  *   * Revision 7.1  90/10/23  20:44:45  mrose  * update  *   * Revision 7.0  89/11/23  22:31:26  mrose  * Release 6.0  *   */
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
comment|/*	VT Protocol machine is in a Sector 1 state and a protocol	*/
end_comment

begin_comment
comment|/*	event occurs.  The state transition matrix is specified in	*/
end_comment

begin_comment
comment|/*	Table 32 of ISO 9041 (July 1987 version).  The actions which	*/
end_comment

begin_comment
comment|/*	this collection of functions perform are specified in Table 33	*/
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

begin_define
define|#
directive|define
name|invalid_result
parameter_list|(
name|str
parameter_list|,
name|pe
parameter_list|)
define|\
value|adios (NULLCP, "%s: invalid result (%s)", (str), \ 	       pe_error ((p) -> pe_errno))
end_define

begin_function
name|int
name|a1_0
parameter_list|(
name|pe
parameter_list|)
comment|/*NDQ-ntr in states 50B or 51Q (Release awaiting peer)*/
comment|/*Also RTQ in state 51T (Release awaiting peer)*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*If quarantined data delivery were supported, we would do: 	/*	++vnt; 	/*	enque(pe); 	/*For now, only supporting simple or no delivery control, so give pe 	/*to application here. 	*/
name|vdatind
argument_list|(
name|SEQUENCED
argument_list|,
name|pe
argument_list|)
expr_stmt|;
comment|/*Deliver the NDQ to application*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_1
parameter_list|(
name|pe
parameter_list|)
comment|/*NDQ-tr in states 50B or 51Q (Release Awaiting Peer)*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/* Same comment as in a1_0 above */
name|vdatind
argument_list|(
name|SEQUENCED
argument_list|,
name|pe
argument_list|)
expr_stmt|;
comment|/*Deliver the NDQ to application*/
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

begin_escape
end_escape

begin_function
name|int
name|a1_2
parameter_list|(
name|pe
parameter_list|)
comment|/*VASSreq from user in state 01 (No Association)*/
name|PE
name|pe
decl_stmt|;
block|{
name|dr_pm_st
operator|=
name|DEFINED
expr_stmt|;
comment|/*Draft-VTE param. status = Defined 				/*(SetVTPmS(P) in 9041) */
comment|/*Set draft-VTE parameter values per profile (SetVTPmV(P) in 9041)*/
name|asq
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/*Send the ASQ PDU*/
name|vsmd
operator|=
literal|0
expr_stmt|;
comment|/*Very TEMPORARY -- A-Mode only 				  Should be done in VT-user or application call 				*/
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S1_02S
expr_stmt|;
else|else
name|state
operator|=
name|S1_02B
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_3
parameter_list|(
name|pe
parameter_list|)
comment|/*VASSrsp from user in state 03B (Associate -- Awaiting user)*/
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|p
decl_stmt|;
name|vrsl
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|p
operator|=
name|first_member
argument_list|(
name|pe
argument_list|)
init|;
name|p
condition|;
name|p
operator|=
name|next_member
argument_list|(
name|pe
argument_list|,
name|p
argument_list|)
control|)
comment|/*Step through elements in sequence*/
block|{
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|PE_ID
argument_list|(
name|PE_CLASS_CONT
argument_list|,
literal|2
argument_list|)
condition|)
comment|/*If the result element*/
block|{
if|if
condition|(
operator|(
name|vrsl
operator|=
name|prim2num
argument_list|(
name|p
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|invalid_result
argument_list|(
literal|"a1_3"
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|vrsl
operator|<
literal|0
condition|)
comment|/*If no result field*/
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_3: no result field"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|FAILURE
condition|)
block|{
name|clear_vte
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|asr
argument_list|(
name|pe
argument_list|,
name|FAILURE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/*Set draft-VTE parameters according to list in primitive 		/* (SetVTPmV(L) in 9041) 		/*Set status of draft-VTE parameters above to defined 		/* (SetVTPmSDe(L) 		/*Set current VTE from draft VTE (SetCuVTE) */
name|vena
operator|=
name|TRUE
expr_stmt|;
comment|/*Current VTE agreed to*/
name|waca
operator|=
name|TRUE
expr_stmt|;
operator|(
name|void
operator|)
name|asr
argument_list|(
name|pe
argument_list|,
name|SUCCESS
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
name|state
operator|=
name|S5_400B
expr_stmt|;
block|}
else|else
name|state
operator|=
name|S1_10B
expr_stmt|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_4
parameter_list|(
name|pe
parameter_list|)
comment|/*VASSrsp from user in state 03S (Associate -- Awaiting user)*/
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|p
decl_stmt|;
name|vrsl
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|p
operator|=
name|first_member
argument_list|(
name|pe
argument_list|)
init|;
name|p
condition|;
name|p
operator|=
name|next_member
argument_list|(
name|pe
argument_list|,
name|p
argument_list|)
control|)
comment|/*Step through elements in sequence*/
block|{
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|PE_ID
argument_list|(
name|PE_CLASS_CONT
argument_list|,
literal|2
argument_list|)
condition|)
comment|/*If the result element*/
block|{
if|if
condition|(
operator|(
name|vrsl
operator|=
name|prim2num
argument_list|(
name|p
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|invalid_result
argument_list|(
literal|"a1_4"
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|vrsl
operator|<
literal|0
condition|)
comment|/*If no result field*/
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_4: no result field"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|FAILURE
condition|)
block|{
name|clear_vte
argument_list|()
expr_stmt|;
comment|/*Discard VTE (DisVTE)*/
operator|(
name|void
operator|)
name|asr
argument_list|(
name|pe
argument_list|,
name|FAILURE
argument_list|)
expr_stmt|;
comment|/*Send the ASR to peer*/
block|}
else|else
block|{
comment|/*Set draft-VTE parameters according to list in primitive 		/* (SetVTPmV(L) in 9041) 		/*Set status of draft-VTE parameters above to defined 		/* (SetVTPmSDe(L) 		/*Set current VTE from draft VTE (SetCuVTE) */
name|vena
operator|=
name|TRUE
expr_stmt|;
comment|/*Current VTE agreed to*/
operator|(
name|void
operator|)
name|asr
argument_list|(
name|pe
argument_list|,
name|SUCCESS
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
if|if
condition|(
name|vtok
condition|)
name|state
operator|=
name|S5_40T
expr_stmt|;
else|else
name|state
operator|=
name|S5_40N
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|vtok
condition|)
name|state
operator|=
name|S1_10T
expr_stmt|;
else|else
name|state
operator|=
name|S1_10N
expr_stmt|;
block|}
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_5
parameter_list|(
name|pe
parameter_list|)
comment|/*RTQ (Token Request) in state 10B 			  (Environment not agreed)*/
name|PE
name|pe
decl_stmt|;
block|{
name|give_token
argument_list|()
expr_stmt|;
comment|/*Need a call to lower layer in ISODE to do this*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_6
parameter_list|(
name|pe
parameter_list|)
comment|/*VGVTreq from user in 10T*/
name|PE
name|pe
decl_stmt|;
block|{
name|give_token
argument_list|()
expr_stmt|;
comment|/*Need a call to lower layer in ISODE to do this*/
name|state
operator|=
name|S1_10N
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_7
parameter_list|(
name|pe
parameter_list|)
comment|/*VRELreq from user in state 10B (Env. not agreed)*/
comment|/*GTQ in 50B*/
name|PE
name|pe
decl_stmt|;
block|{
if|if
condition|(
name|vtok
condition|)
block|{
name|vt_disconnect
argument_list|()
expr_stmt|;
comment|/*May be only TEMP*/
name|state
operator|=
name|S1_51Q
expr_stmt|;
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
comment|/*Probably need to release the NULL PE for VRELreq that got us here*/
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_8
parameter_list|(
name|pe
parameter_list|)
comment|/*VRELreq in 10T*/
name|PE
name|pe
decl_stmt|;
block|{
name|vt_disconnect
argument_list|()
expr_stmt|;
comment|/*May be only TEMP--check function*/
name|state
operator|=
name|S1_51T
expr_stmt|;
comment|/*Release NULL PE from VT USER*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_9
parameter_list|(
name|pe
parameter_list|)
comment|/*VRELrsp in 51R& 51N (Release -- Awaiting User)*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*	vrsl = -1; /*	for(p = first_member(pe); p; p = next_member(pe,p) ) /*			/*Get Result parameter*/
comment|/*	{ /*		if(PE_ID(p->pe_class,p->pe_id) == PE_ID(PE_CLASS_CONT,0) ) /*		{ /*			if( (vrsl = prim2num(p)) == NOTOK) /*			    invalid_result ("a1_9", p); /*			break; /*		} /*	} /*	if(vrsl< 0) /*		adios(NULLCP,"a1_9: no result field"); /*	 /*	we should look in the pdu and see what the result is, but /*	since we know our vt-user is an agreeable fellow, we can /*	assume success */
name|vrsl
operator|=
name|SUCCESS
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
if|if
condition|(
name|vns
operator|>
literal|0
condition|)
comment|/*If data left to send*/
block|{
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"Sending remaining data (a1_9() )"
argument_list|)
expr_stmt|;
name|send_all
argument_list|()
expr_stmt|;
comment|/*Send remaining data (NDQseq(Vns)-ntr)*/
name|vns
operator|=
literal|0
expr_stmt|;
block|}
name|send_rlr
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/*Send the RLR which User built*/
name|clear_vte
argument_list|()
expr_stmt|;
comment|/*Erase the Environment*/
name|state
operator|=
name|S1_01
expr_stmt|;
comment|/*		system("reset");	*/
name|finalbye
argument_list|()
expr_stmt|;
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"association released by terminal service"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
comment|/*Result was failure*/
block|{
name|send_rlr
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/*Send the RLR*/
if|if
condition|(
name|vena
condition|)
comment|/*If agreement on VTE*/
block|{
name|sector
operator|=
literal|5
expr_stmt|;
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S5_40N
expr_stmt|;
comment|/*If S-Mode*/
else|else
name|state
operator|=
name|S5_400B
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S1_10N
expr_stmt|;
else|else
name|state
operator|=
name|S1_10B
expr_stmt|;
block|}
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_10
parameter_list|(
name|pe
parameter_list|)
comment|/*VRQTreq(request token) n state 10N*/
name|PE
name|pe
decl_stmt|;
block|{
name|request_token
argument_list|()
expr_stmt|;
comment|/*TEMP -- Need an ISODE call to really do this 				  since there is no VTP PDU*/
comment|/*Probably need to free the NullPE that triggered this*/
name|state
operator|=
name|S1_10N
expr_stmt|;
comment|/*Should be here already.  Do this to follow 				  the spec literally*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_11
parameter_list|(
name|pe
parameter_list|)
comment|/*VSNEGreq (User Start Negotiation)*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*MIN not implemented*/
comment|/*Probably need to send back a negative Acknowledgement*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_12
parameter_list|(
name|pe
parameter_list|)
comment|/*VSNEGreq*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*MIN not implemented*/
comment|/*Probably need to send back a Negative Acknowledgement*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_13
parameter_list|(
name|pe
parameter_list|)
comment|/*VSWPreq (User Switch profile request)*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Switch Profile not implemented*/
comment|/*Should probably send back a negative acknowledgement*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_14
parameter_list|(
name|pe
parameter_list|)
comment|/*VSWPreq*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Switch Profile not implented*/
comment|/*Should Probably send back a negative acknowledgement*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_15
parameter_list|(
name|pe
parameter_list|)
comment|/*ASR in state 2B (Assoc. awaiting target) */
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|p
decl_stmt|;
name|vrsl
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|p
operator|=
name|first_member
argument_list|(
name|pe
argument_list|)
init|;
name|p
condition|;
name|p
operator|=
name|next_member
argument_list|(
name|pe
argument_list|,
name|p
argument_list|)
control|)
block|{
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|PE_ID
argument_list|(
name|PE_CLASS_CONT
argument_list|,
literal|2
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|vrsl
operator|=
name|prim2num
argument_list|(
name|p
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|invalid_result
argument_list|(
literal|"a1_15"
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|vrsl
operator|<
literal|0
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_15: no result field"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|FAILURE
condition|)
block|{
name|clear_vte
argument_list|()
expr_stmt|;
name|state
operator|=
name|S1_01
expr_stmt|;
return|return
operator|(
name|FAILURE
operator|)
return|;
comment|/*Notify user of ASR (VASScnf)*/
block|}
else|else
block|{
comment|/*Set draft-VTE param. according to list in primitive or protocol 	/*element (SetVTPmV(L)). 	/*Set status of draft-VTE params. listed in primitive or protocol 	/*element to defined (SetVTPmSDe(L)) 	/*Set current-VTE from draft-VTE (SetCuVTE) */
name|vena
operator|=
literal|1
expr_stmt|;
name|waci
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
name|state
operator|=
name|S5_400B
expr_stmt|;
block|}
else|else
name|state
operator|=
name|S1_10B
expr_stmt|;
block|}
return|return
operator|(
name|SUCCESS
operator|)
return|;
comment|/*Notify user of ASR (VASScnf)*/
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_16
parameter_list|(
name|pe
parameter_list|)
comment|/*ASR in state 2S (Assoc. awaiting target) */
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|p
decl_stmt|;
name|vrsl
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|p
operator|=
name|first_member
argument_list|(
name|pe
argument_list|)
init|;
name|p
condition|;
name|p
operator|=
name|next_member
argument_list|(
name|pe
argument_list|,
name|p
argument_list|)
control|)
block|{
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|PE_ID
argument_list|(
name|PE_CLASS_CONT
argument_list|,
literal|2
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|vrsl
operator|=
name|prim2num
argument_list|(
name|p
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|invalid_result
argument_list|(
literal|"a1_16"
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|vrsl
operator|<
literal|0
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_16: no result field"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|FAILURE
condition|)
block|{
name|clear_vte
argument_list|()
expr_stmt|;
name|state
operator|=
name|S1_01
expr_stmt|;
return|return
operator|(
name|FAILURE
operator|)
return|;
comment|/*Notify user of ASR (VASScnf)*/
block|}
else|else
block|{
comment|/*Set draft-VTE param. according to list in primitive or protocol 	/*element (SetVTPmV(L)). 	/*Set status of draft-VTE params. listed in primitive or protocol 	/*element to defined (SetVTPmSDe(L)) 	/*Set current-VTE from draft-VTE (SetCuVTE) */
name|vena
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
if|if
condition|(
name|vtok
condition|)
name|state
operator|=
name|S5_40T
expr_stmt|;
else|else
name|state
operator|=
name|S5_40N
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|vtok
condition|)
name|state
operator|=
name|S1_10T
expr_stmt|;
else|else
name|state
operator|=
name|S1_10N
expr_stmt|;
block|}
block|}
return|return
operator|(
name|SUCCESS
operator|)
return|;
comment|/*Notify user of ASR (VASScnf) */
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_17
parameter_list|(
name|pe
parameter_list|)
comment|/*ASQ in state 01 (No Association)*/
name|PE
name|pe
decl_stmt|;
block|{
name|int
name|result
decl_stmt|;
name|result
operator|=
name|read_asq
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/*Unpack ASQ*/
if|if
condition|(
name|result
operator|==
name|PROFILE_NG
condition|)
block|{
operator|(
name|void
operator|)
name|send_bad_asr
argument_list|(
name|PROFILE_NG
argument_list|)
expr_stmt|;
comment|/*Send Failure ASR with reason*/
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|send_bad_asr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*Send failure ASR w/ no reason*/
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
comment|/*SetVTPmS(P)*/
comment|/*SetVTPmV(P)*/
name|dr_pm_st
operator|=
name|DEFINED
expr_stmt|;
name|vsmd
operator|=
literal|0
expr_stmt|;
name|vtok
operator|=
literal|1
expr_stmt|;
comment|/*For Telnet& transparent profiles*/
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S1_03S
expr_stmt|;
comment|/*If S-Mode*/
else|else
name|state
operator|=
name|S1_03B
expr_stmt|;
name|result
operator|=
name|vassind
argument_list|(
name|pe
argument_list|)
expr_stmt|;
comment|/*doesn't really use pe but for consistency 				  with version 1*/
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_18
parameter_list|(
name|pe
parameter_list|)
comment|/*UDQ (uncontrolled data) in 51T (Release Awaiting Peer)*/
name|PE
name|pe
decl_stmt|;
block|{
name|vdatind
argument_list|(
name|SEQUENCED
argument_list|,
name|pe
argument_list|)
expr_stmt|;
comment|/*Want to do VDATind-h but this is all that's 				  now available*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_19
parameter_list|(
name|pe
parameter_list|)
comment|/*GTQ in 10N or VRTQreq in 10T*/
name|PE
name|pe
decl_stmt|;
block|{
name|vtok
operator|=
name|TRUE
expr_stmt|;
name|vgvt_ind
argument_list|()
expr_stmt|;
comment|/*VGVTind -- Tell user we have token (as if he cares)*/
name|state
operator|=
name|S1_10T
expr_stmt|;
empty_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_20
parameter_list|(
name|pe
parameter_list|)
comment|/*RLR (Release Response) in 51Q or 51T (Release Awaiting Peer)*/
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|p
decl_stmt|;
name|vrsl
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|p
operator|=
name|first_member
argument_list|(
name|pe
argument_list|)
init|;
name|p
condition|;
name|p
operator|=
name|next_member
argument_list|(
name|pe
argument_list|,
name|p
argument_list|)
control|)
block|{
if|if
condition|(
name|PE_ID
argument_list|(
name|p
operator|->
name|pe_class
argument_list|,
name|p
operator|->
name|pe_id
argument_list|)
operator|==
name|PE_ID
argument_list|(
name|PE_CLASS_CONT
argument_list|,
literal|0
argument_list|)
condition|)
comment|/*If result element*/
block|{
if|if
condition|(
operator|(
name|vrsl
operator|=
name|prim2num
argument_list|(
name|p
argument_list|)
operator|)
operator|==
name|NOTOK
condition|)
name|invalid_result
argument_list|(
literal|"a1_20"
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|vrsl
operator|<
literal|0
condition|)
comment|/*if no result field*/
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_20: no result field"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vrsl
operator|==
name|SUCCESS
condition|)
block|{
comment|/*VRELcnf -- Confirm the release to user -- for now, use the 		  original mechanism (closing TELNET) -- should be changed 		  especially for forms mode*/
name|vrelcnf
argument_list|()
expr_stmt|;
if|if
condition|(
name|vnt
operator|>
literal|0
condition|)
comment|/*Should never happen until Quarantined Delivery 			  supported*/
block|{
comment|/*VDATind-n(Vnt)*/
name|vnt
operator|=
literal|0
expr_stmt|;
block|}
name|clear_vte
argument_list|()
expr_stmt|;
name|state
operator|=
name|S1_01
expr_stmt|;
block|}
else|else
comment|/*Release Failed*/
block|{
if|if
condition|(
name|vena
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S5_40T
expr_stmt|;
else|else
name|state
operator|=
name|S5_400B
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|vsmd
condition|)
name|state
operator|=
name|S1_10T
expr_stmt|;
else|else
name|state
operator|=
name|S1_10B
expr_stmt|;
block|}
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_function
name|int
name|a1_21
parameter_list|(
name|pe
parameter_list|)
comment|/*DLQ (Deliver Request) in 50B or 51Q (Release Awaiting Peer)*/
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
name|NULLCP
argument_list|,
literal|"a1_21: incorrect DLQ"
argument_list|)
expr_stmt|;
if|if
condition|(
name|vra
condition|)
block|{
name|vrsl
operator|=
name|FAILURE
expr_stmt|;
name|vrea
operator|=
name|COLL_DET
expr_stmt|;
comment|/*VRELcnf required in spec but there's really nothing to tell 		  the user*/
block|}
if|if
condition|(
name|vnt
operator|>
literal|0
condition|)
comment|/*Should not happen unless Quarantine Delivery supported*/
block|{
comment|/*VDATind-n(Vnt)*/
name|vnt
operator|=
literal|0
expr_stmt|;
block|}
name|vdelind
argument_list|(
name|pe
argument_list|,
name|vra
argument_list|)
expr_stmt|;
comment|/*Also irrelevant without Quarantine*/
if|if
condition|(
name|vra
condition|)
block|{
name|sector
operator|=
literal|5
expr_stmt|;
name|state
operator|=
name|S5_402B
expr_stmt|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_22
parameter_list|(
name|pe
parameter_list|)
comment|/*RLQ (Release Request) in 50B*/
name|PE
name|pe
decl_stmt|;
block|{
name|vrsl
operator|=
name|FAILURE
expr_stmt|;
name|vrea
operator|=
name|COLL_DET
expr_stmt|;
comment|/*VRELcnf -- Confirm to user telling of failure due to collision -- 	  but user can't do anything now anyway. */
if|if
condition|(
name|vnt
operator|>
literal|0
condition|)
comment|/*Shouldn't happen without Quarantine Delivery Ctrl*/
block|{
comment|/*VDATind-n(Vnt)*/
name|vnt
operator|=
literal|0
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|vrelind
argument_list|()
expr_stmt|;
comment|/*Tell user that peer requested release*/
name|state
operator|=
name|S1_51R
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_23
parameter_list|(
name|pe
parameter_list|)
comment|/*SNQ (Start negotiation) in 50B*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Switch Negotiation not implemented. 	  Should probably send back negative acknowledgement. */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_24
parameter_list|(
name|pe
parameter_list|)
comment|/*SPQ (Switch Profile Request) in state 50B*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Profile Switch not implemented. 	  Should probably send back negative acknowledgement. */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_25
parameter_list|(
name|pe
parameter_list|)
comment|/*RLQ (Release Request) in 10B (Environment not agreed) */
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|vrelind
argument_list|()
expr_stmt|;
name|state
operator|=
name|S1_51R
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
name|a1_26
parameter_list|(
name|pe
parameter_list|)
comment|/*RLQ (Release Request) in state 10N*/
name|PE
name|pe
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|vrelind
argument_list|()
expr_stmt|;
name|state
operator|=
name|S1_51R
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_27
parameter_list|(
name|pe
parameter_list|)
comment|/*RTQ (Request Token) in state 10T*/
name|PE
name|pe
decl_stmt|;
block|{
name|vrtq_ind
argument_list|()
expr_stmt|;
comment|/*Tell Application that peer requested token*/
comment|/*Probably some ISODE call to give token directly instead of telling 	  user */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_28
parameter_list|(
name|pe
parameter_list|)
comment|/*SNQ (Start Negotiation) in 10N*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*MIN not implemented. 	  Need to return NAK. */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_29
parameter_list|(
name|pe
parameter_list|)
comment|/*SNQ (Start Negotiation) in 10B*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*MIN not implemented. 	  Need to send NAK to peer. */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_30
parameter_list|(
name|pe
parameter_list|)
comment|/*SPQ (Switch Profile Request) in 10B& 10N*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Switch Profile not implemented. 	  Should send NAK to peer. */
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_100
parameter_list|(
name|pe
parameter_list|)
comment|/*APQ (VT-P-ABORT -- Abort from VTPM) in any state*/
name|PE
name|pe
decl_stmt|;
block|{
name|state
operator|=
name|S1_01
expr_stmt|;
comment|/*For rigor*/
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"protocol abort -- association terminated"
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_101
parameter_list|(
name|pe
parameter_list|)
comment|/*AUQ (VT-U-ABORT -- Abort from VT User) in any state*/
name|PE
name|pe
decl_stmt|;
block|{
name|state
operator|=
name|S1_01
expr_stmt|;
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"user abort -- association terminated"
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_102
parameter_list|(
name|pe
parameter_list|)
comment|/*VUABreq (Abort by User) in any state*/
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|pe_auq
decl_stmt|;
name|char
modifier|*
name|reason
init|=
literal|"Association Closed by User"
decl_stmt|;
name|pe_auq
operator|=
name|str2prim
argument_list|(
name|reason
argument_list|,
name|strlen
argument_list|(
name|reason
argument_list|)
argument_list|,
name|PE_CLASS_CONT
argument_list|,
name|AUQ_PDU
argument_list|)
expr_stmt|;
if|if
condition|(
name|pe_auq
operator|==
name|NULLPE
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_102: AUQ build failure (out of memory)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|AcUAbortRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|pe_auq
argument_list|,
literal|1
argument_list|,
name|aci
argument_list|)
operator|==
name|NOTOK
condition|)
name|acs_adios
argument_list|(
operator|&
name|aci
operator|->
name|aci_abort
argument_list|,
literal|"A-ABORT.REQUEST"
argument_list|)
expr_stmt|;
name|state
operator|=
name|S1_01
expr_stmt|;
name|finalbye
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_103
parameter_list|(
name|pe
parameter_list|)
comment|/*VTAB (Irrecoverable exception condition) in any state*/
name|PE
name|pe
decl_stmt|;
block|{
name|PE
name|pe_apq
decl_stmt|;
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"Irrecoverable Exception Condition -- Aborting\n"
argument_list|)
expr_stmt|;
name|pe_apq
operator|=
name|num2prim
argument_list|(
operator|(
name|integer
operator|)
literal|1
argument_list|,
name|PE_CLASS_CONT
argument_list|,
name|APQ_PDU
argument_list|)
expr_stmt|;
comment|/*1 is value for Local Error.  0 if for Protocol 			  Error.  Assume 1 for now. */
if|if
condition|(
name|pe_apq
operator|==
name|NULLPE
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"a1_103: APQ build failure (out of memory)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|AcUAbortRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|pe_apq
argument_list|,
literal|1
argument_list|,
name|aci
argument_list|)
operator|==
name|NOTOK
condition|)
name|acs_adios
argument_list|(
operator|&
name|aci
operator|->
name|aci_abort
argument_list|,
literal|"A-ABORT.REQUEST"
argument_list|)
expr_stmt|;
name|state
operator|=
name|S1_01
expr_stmt|;
comment|/*For completeness*/
name|finalbye
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|a1_107
parameter_list|(
name|pe
parameter_list|)
comment|/*Generic Action*/
name|PE
name|pe
decl_stmt|;
block|{
comment|/*Stay in this state*/
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

