begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vtpm.c - VTPM: FSM */
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
literal|"$Header: /f/osi/vt/RCS/vtpm.c,v 7.1 91/02/22 09:48:30 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/vtpm.c,v 7.1 91/02/22 09:48:30 mrose Interim $  *  *  * $Log:	vtpm.c,v $  * Revision 7.1  91/02/22  09:48:30  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:31:57  mrose  * Release 6.0  *   */
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
file|"eventmsg.h"
end_include

begin_include
include|#
directive|include
file|"sector1.h"
end_include

begin_undef
undef|#
directive|undef
name|PEPYPARM
end_undef

begin_define
define|#
directive|define
name|PEPYPARM
value|int *
end_define

begin_decl_stmt
name|int
name|cmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Session descriptor for this association*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|SSAPref
name|sfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|SSAPref
modifier|*
name|sf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPaddr
modifier|*
name|pa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPconnect
name|accs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPconnect
modifier|*
name|acc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPrelease
name|acrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPrelease
modifier|*
name|acr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPindication
name|acis
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPindication
modifier|*
name|aci
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPabort
modifier|*
name|aca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AEI
name|aei
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OID
name|ctx
decl_stmt|,
name|pci
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPstart
name|acss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|AcSAPstart
modifier|*
name|acs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPstart
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPindication
name|pi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPdata
name|px
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPfinish
modifier|*
name|pf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* GET EVENT - attempt to read a PDU from the presentation connection	    */
end_comment

begin_comment
comment|/*		   designated by "sd", determine			    */
end_comment

begin_comment
comment|/*		   which imcoming event has ocurred,			    */
end_comment

begin_comment
comment|/*		   and process the event with "do_event"		    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*		   A non-blocking read is done and OK is returned if there  */
end_comment

begin_comment
comment|/*		   is nothing to read.					    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*  PARAMETERS - 							    */
end_comment

begin_comment
comment|/*		FD - the presentation ID for the connection to read from    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*		PE - a pointer to the presentation element that is read     */
end_comment

begin_comment
comment|/*		(note that what is passed is a pointer to a pointer to      */
end_comment

begin_comment
comment|/*		data structure so that the address of the PE		    */
end_comment

begin_comment
comment|/*		that is read can be returned in this parameter)		    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*	RETURNS -  the number of the incoming event associated with reading */
end_comment

begin_comment
comment|/*		this PE from the network				    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_function
name|int
name|get_event
parameter_list|(
name|dd
parameter_list|,
name|pe
parameter_list|)
name|int
name|dd
decl_stmt|;
name|PE
modifier|*
name|pe
decl_stmt|;
block|{
name|int
name|result
decl_stmt|,
name|event
decl_stmt|;
name|PE
name|nullpe
decl_stmt|;
name|result
operator|=
name|PReadRequest
argument_list|(
name|dd
argument_list|,
operator|&
name|px
argument_list|,
name|OK
argument_list|,
operator|&
name|pi
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|result
condition|)
block|{
case|case
name|NOTOK
case|:
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_EXCEPTIONS
argument_list|,
name|NULLCP
argument_list|,
literal|"P-READ REQUEST returned NOTOK"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
case|case
name|DONE
case|:
if|if
condition|(
name|pi
operator|.
name|pi_type
operator|==
name|PI_FINISH
condition|)
block|{
name|pf
operator|=
operator|&
name|pi
operator|.
name|pi_finish
expr_stmt|;
name|event
operator|=
name|RLQ
expr_stmt|;
name|nullpe
operator|=
name|NULLPE
expr_stmt|;
name|pe
operator|=
operator|&
name|nullpe
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pi
operator|.
name|pi_type
operator|==
name|PI_SYNC
condition|)
block|{
return|return
operator|(
name|pn_ind
argument_list|(
name|dd
argument_list|,
operator|&
name|pi
operator|.
name|pi_sync
argument_list|)
operator|)
return|;
block|}
else|else
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"PReadRequest returned DONE, but event unknown (%d)"
argument_list|,
name|pi
operator|.
name|pi_type
argument_list|)
expr_stmt|;
break|break;
case|case
name|OK
case|:
if|if
condition|(
name|px
operator|.
name|px_ninfo
operator|>
literal|1
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"read more than one PE from network!\n"
argument_list|)
expr_stmt|;
name|pe
operator|=
operator|&
operator|(
name|px
operator|.
name|px_info
index|[
literal|0
index|]
operator|)
expr_stmt|;
comment|/* we are assuming here that you can only get one PDU per P-DATA. 		*/
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
operator|*
name|pe
argument_list|,
name|NULLCP
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|pe
operator|)
operator|->
name|pe_class
operator|!=
name|PE_CLASS_CONT
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"read pe of class %d"
argument_list|,
operator|(
operator|*
name|pe
operator|)
operator|->
name|pe_class
argument_list|)
expr_stmt|;
switch|switch
condition|(
operator|(
operator|*
name|pe
operator|)
operator|->
name|pe_id
condition|)
block|{
case|case
operator|(
name|ASQ_PDU
operator|)
case|:
block|{
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got ASQ_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|ASQ
expr_stmt|;
block|}
case|case
name|ASR_PDU
case|:
block|{
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got ASR_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|ASR
expr_stmt|;
block|}
case|case
name|AUQ_PDU
case|:
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got AUQ_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|AUQ
expr_stmt|;
break|break;
case|case
name|DAQ_PDU
case|:
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got DAQ_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|DAQ
expr_stmt|;
break|break;
case|case
name|DLQ_PDU
case|:
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got DLQ_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|DLQ
expr_stmt|;
break|break;
case|case
name|NDQ_PDU
case|:
block|{
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"got NDQ_PDU"
argument_list|)
expr_stmt|;
name|event
operator|=
name|NDQ_tr
expr_stmt|;
comment|/*See comment below*/
comment|/*	We're supposed to find out if the NDQ contains an 		update to a triggered control object or not to determine 		what kind of event we have.  Right now we'll assume that 		we do have such an update in all cases.  Note that this may 		be a problem if we use quarantine delivery control in the 		future. 	   		for each update, find out if the update is for a display object 		or for a control object. if it's a control object get the name  		of it and find out if it has a trigger 	 	*/
break|break;
block|}
case|case
name|UDQ_PDU
case|:
block|{
name|event
operator|=
name|UDQ
expr_stmt|;
break|break;
block|}
case|case
name|HDQ_PDU
case|:
block|{
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"Got HDQ"
argument_list|)
expr_stmt|;
name|event
operator|=
name|HDQ
expr_stmt|;
break|break;
block|}
case|case
name|RLR_PDU
case|:
name|event
operator|=
name|RLR
expr_stmt|;
break|break;
default|default:
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"unknown PDU type %d"
argument_list|,
operator|(
operator|*
name|pe
operator|)
operator|->
name|pe_id
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
name|do_event
argument_list|(
name|event
argument_list|,
operator|*
name|pe
argument_list|)
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_define
define|#
directive|define
name|SECTORS
value|6
end_define

begin_comment
comment|/* number of states in each sector */
end_comment

begin_decl_stmt
name|unsigned
name|max_state
index|[
name|SECTORS
index|]
init|=
block|{
literal|0
block|,
literal|13
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|10
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|s0
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|NULL
block|}
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|s1
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|s1_01
operator|,
comment|/* states in the first sector  */
function_decl|s1_02B
operator|,
function_decl|s1_02S
operator|,
function_decl|s1_03B
operator|,
function_decl|s1_03S
operator|,
function_decl|s1_10B
operator|,
function_decl|s1_10N
operator|,
function_decl|s1_10T
operator|,
function_decl|s1_50B
operator|,
function_decl|s1_51Q
operator|,
function_decl|s1_51R
operator|,
function_decl|s1_51N
operator|,
function_decl|s1_51T
end_function_decl

begin_function_decl
unit|};
name|int
function_decl|(
modifier|*
name|s2
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|NULL
block|}
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|s3
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|NULL
block|}
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|s4
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|NULL
block|}
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|s5
index|[]
function_decl|)
parameter_list|()
init|=
block|{
name|s5_400B
operator|,
function_decl|s5_402B
operator|,
function_decl|s5_420B
operator|,
function_decl|s5_422B
operator|,
function_decl|s5_40N
operator|,
function_decl|s5_40T
operator|,
function_decl|s5_42N
operator|,
function_decl|s5_42T
operator|,
function_decl|s5_61
operator|,
function_decl|s5_62
end_function_decl

begin_expr_stmt
unit|};
name|int
argument_list|(
call|(
modifier|*
modifier|*
name|sectors
index|[]
call|)
argument_list|()
argument_list|)
operator|=
block|{
name|s0
block|,
name|s1
block|,
name|s2
block|,
name|s3
block|,
name|s4
block|,
name|s5
block|}
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_decl_stmt
name|unsigned
name|state
init|=
literal|0
decl_stmt|,
name|sector
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|do_event
argument_list|(
argument|event
argument_list|,
argument|pe
argument_list|)
end_macro

begin_decl_stmt
name|int
name|event
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PE
name|pe
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"in do_event, sector is %d, state is %d, event is %d (%s)"
argument_list|,
name|sector
argument_list|,
name|state
argument_list|,
name|event
argument_list|,
name|event
operator|>=
literal|0
operator|&&
name|event
operator|<
sizeof|sizeof
name|eventname
operator|/
sizeof|sizeof
name|eventname
index|[
literal|0
index|]
condition|?
name|eventname
index|[
name|event
index|]
else|:
literal|"INVALID"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sector
operator|>=
name|SECTORS
operator|||
name|state
operator|>=
name|max_state
index|[
name|sector
index|]
condition|)
return|return
operator|(
name|NOTOK
operator|)
return|;
return|return
operator|(
name|sectors
index|[
name|sector
index|]
index|[
name|state
index|]
operator|(
name|event
operator|,
name|pe
operator|)
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|pn_ind
argument_list|(
argument|dd
argument_list|,
argument|psync
argument_list|)
end_macro

begin_comment
comment|/* sync indications */
end_comment

begin_decl_stmt
name|int
name|dd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PSAPsync
modifier|*
name|psync
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|psync
operator|->
name|pn_type
condition|)
block|{
case|case
name|SN_MAJORIND
case|:
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"vt: got SN_MAJORIND"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SN_MAJORCNF
case|:
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"vt: got SN_MAJORCNF"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SN_MINORIND
case|:
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"vt: got SN_MINORIND"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SN_MINORCNF
case|:
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"vt: got SN_MINORCNF"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SN_RESETIND
case|:
comment|/*			advise(LLOG_DEBUG,NULLCP,  "vt: resetind: SN_RESETIND"); */
if|if
condition|(
name|psync
operator|->
name|pn_options
operator|!=
name|SYNC_RESTART
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"resetind: bad options params"
argument_list|)
expr_stmt|;
if|if
condition|(
name|psync
operator|->
name|pn_ninfo
operator|>
literal|0
condition|)
return|return
operator|(
name|do_event
argument_list|(
name|BKQ
argument_list|,
name|psync
operator|->
name|pn_info
index|[
literal|0
index|]
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|do_event
argument_list|(
name|BKQ
argument_list|,
name|NULLPE
argument_list|)
operator|)
return|;
case|case
name|SN_RESETCNF
case|:
comment|/*			advise(LLOG_DEBUG,NULLCP,  "vt: got SN_RESETCNF\n"); */
if|if
condition|(
name|psync
operator|->
name|pn_options
operator|!=
name|SYNC_RESTART
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"resetind: bad options params"
argument_list|)
expr_stmt|;
if|if
condition|(
name|psync
operator|->
name|pn_ninfo
operator|>
literal|0
condition|)
return|return
operator|(
name|do_event
argument_list|(
name|BKR
argument_list|,
name|psync
operator|->
name|pn_info
index|[
literal|0
index|]
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|do_event
argument_list|(
name|BKR
argument_list|,
name|NULLPE
argument_list|)
operator|)
return|;
default|default:
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"received bad sync type"
argument_list|)
expr_stmt|;
block|}
name|PNFREE
argument_list|(
name|psync
argument_list|)
expr_stmt|;
return|return
operator|(
name|NOTOK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_escape
end_escape

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* P_DATA - send a PDU via PDataRequest					     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/* RETURNS - OK or exits on error					     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*  PARAMETERS - 							     */
end_comment

begin_comment
comment|/*		PDU - a PE containing the PDU to be sent		     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*  CLASSIFICATION - utility function for VTPM (used only in processing	     */
end_comment

begin_comment
comment|/*			outgoing events that are mapped to P_DATA)	     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_macro
name|p_data
argument_list|(
argument|pdu
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PDataRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-DATA.REQUEST"
argument_list|)
expr_stmt|;
name|pe_free
argument_list|(
name|pdu
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* P_MAJOR_SYNC.REQUEST - send a PDU via PMajSyncRequest		    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   RETURNS - OK or exits on error					    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   PARAMETERS - 							    */
end_comment

begin_comment
comment|/*			PDU - a PE containing the PDU to be sent	    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*  CLASSIFICATION - utility function for VTPM (used only in processing	    */
end_comment

begin_comment
comment|/*		outgoing events that are mapped to P_MAJOR_SYNC.REQUEST)    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_macro
name|p_maj_sync_req
argument_list|(
argument|pdu
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|ssn
decl_stmt|;
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PMajSyncRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|ssn
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-MAJOR-SYNC.REQUEST"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* P_MAJOR_SYNC.RESPONSE - send a PDU via PMajSyncResponse		    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   RETURNS - OK or exits on error					    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*  PARAMETERS - 							    */
end_comment

begin_comment
comment|/*			PDU - a PE containing the PDU to be sent	    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*  CLASSIFICATION - utility function for VTPM (used only in processing     */
end_comment

begin_comment
comment|/*		   outgoing events that are mapped to P_MAJOR_SYNC.RESPONSE)*/
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_macro
name|p_maj_sync_resp
argument_list|(
argument|pdu
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PMajSyncResponse
argument_list|(
name|sd
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-MAJOR-SYNC.RESPONSE"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* P_TYPED_DATA  - send a PDU via PTypedRequest				   */
end_comment

begin_comment
comment|/*									   */
end_comment

begin_comment
comment|/*  RETURNS - OK or exits on error					   */
end_comment

begin_comment
comment|/*									   */
end_comment

begin_comment
comment|/*  PARAMETERS - 							   */
end_comment

begin_comment
comment|/*			PDU - a PE containing the PDU to be sent	   */
end_comment

begin_comment
comment|/*									   */
end_comment

begin_comment
comment|/*  CLASSIFICATION - utility function for VTPM (used only in processing    */
end_comment

begin_comment
comment|/*			outgoing events that are mapped to P_TYPED_DATA)   */
end_comment

begin_comment
comment|/*									   */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_macro
name|p_typed_data
argument_list|(
argument|pdu
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PTypedRequest
argument_list|(
name|sd
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-TYPED-DATA.REQUEST"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* P_RESYNCHRONIZE.REQUEST - send a PDU via PReSyncRequest		     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*  RETURNS - OK or exits on error					     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*  PARAMETERS -							     */
end_comment

begin_comment
comment|/*	 PDU - a PE containing the (break) PDU to be sent		     */
end_comment

begin_comment
comment|/*									     */
end_comment

begin_comment
comment|/*  CLASSIFICATION - utility function for VTPM (used only in processing	     */
end_comment

begin_comment
comment|/*			outgoing events that are mapped to P_RESYNC.REQUEST) */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_macro
name|p_resync_req
argument_list|(
argument|pdu
argument_list|,
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|ssn
init|=
literal|0
decl_stmt|;
comment|/* should be made a global at some time */
name|int
name|settings
init|=
name|ST_INIT_VALUE
decl_stmt|;
define|#
directive|define
name|VTKP_REQ
value|0x00
comment|/* setting values, see ssap.h */
define|#
directive|define
name|VTKP_ACC
value|0x15
define|#
directive|define
name|VTKP_CHO
value|0x2a
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PReSyncRequest
argument_list|(
name|sd
argument_list|,
name|type
argument_list|,
name|ssn
argument_list|,
name|settings
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
comment|/*	if (PReSyncRequest(sd, type, 0, 0, (PE *)NULL, 0,&pi) != OK) */
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-RESYNCHRONIZE.REQUEST"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* P_RESYNC.RESPONSE - send a PDU via PReSyncResponse			    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   RETURNS - OK or exits on error					    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   PARAMETERS - 							    */
end_comment

begin_comment
comment|/*		PDU - a PE containing the PDU to be sent		    */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*   CLASSIFICATION - utility function for VTPM (used only in processing    */
end_comment

begin_comment
comment|/*	  	      outgoing events that are mapped to P_RESYNC.RESPONSE) */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_macro
name|p_resync_resp
argument_list|(
argument|pdu
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pdu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|ssn
init|=
literal|0
decl_stmt|;
comment|/* should be made a global at some time */
name|int
name|settings
init|=
name|ST_INIT_VALUE
decl_stmt|;
name|PLOG
argument_list|(
name|vt_log
argument_list|,
name|print_VT_PDUs
argument_list|,
name|pdu
argument_list|,
name|NULLCP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|PReSyncResponse
argument_list|(
name|sd
argument_list|,
name|ssn
argument_list|,
name|settings
argument_list|,
operator|&
name|pdu
argument_list|,
literal|1
argument_list|,
operator|&
name|pi
argument_list|)
operator|!=
name|OK
condition|)
name|ps_adios
argument_list|(
operator|&
name|pi
operator|.
name|pi_abort
argument_list|,
literal|"P-RESYNCHRONIZE.RESPONSE"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*	ASR - generate an ASR event. (that is send an ASR PDU which is	    */
end_comment

begin_comment
comment|/*	      passed in as a parameter as user data on the AcAssocResponse.)*/
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*	PARAMETERS: 	PE - a vt ASR PDU				    */
end_comment

begin_comment
comment|/*			status (SUCCESS or FAILURE)		            */
end_comment

begin_comment
comment|/*									    */
end_comment

begin_comment
comment|/*	RETURNS:		OK					    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_macro
name|asr
argument_list|(
argument|pe
argument_list|,
argument|status
argument_list|)
end_macro

begin_decl_stmt
name|PE
name|pe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*	include "pe" as user data on the AcAssocResponse */
name|struct
name|PSAPctxlist
modifier|*
name|pl
init|=
operator|&
name|ps
operator|->
name|ps_ctxlist
decl_stmt|;
name|int
name|s_requirements
decl_stmt|;
name|long
name|isn
decl_stmt|;
name|int
name|reason
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
name|debug
operator|>
literal|2
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|pl
operator|->
name|pc_nctx
condition|;
name|i
operator|++
control|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|" ctx %d: %d %s %d"
argument_list|,
name|i
argument_list|,
name|pl
operator|->
name|pc_ctx
index|[
name|i
index|]
operator|.
name|pc_id
argument_list|,
name|sprintoid
argument_list|(
name|pl
operator|->
name|pc_ctx
index|[
name|i
index|]
operator|.
name|pc_asn
argument_list|)
argument_list|,
name|pl
operator|->
name|pc_ctx
index|[
name|i
index|]
operator|.
name|pc_result
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|debug
condition|)
block|{
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"in asr.\n"
argument_list|)
expr_stmt|;
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"about to call AcAssocResp, sd is %d, pe->pe_id is %d\n"
argument_list|,
name|sd
argument_list|,
name|pe
operator|->
name|pe_id
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|status
operator|==
name|SUCCESS
condition|)
block|{
name|status
operator|=
name|ACS_ACCEPT
expr_stmt|;
name|reason
operator|=
name|ACS_USER_NULL
expr_stmt|;
block|}
else|else
block|{
name|status
operator|=
name|ACS_PERMANENT
expr_stmt|;
name|reason
operator|=
name|ACS_USER_NOREASON
expr_stmt|;
block|}
name|s_requirements
operator|=
name|SR_DUPLEX
operator||
name|SR_RESYNC
operator||
name|SR_TYPEDATA
expr_stmt|;
name|isn
operator|=
literal|0
expr_stmt|;
name|pe
operator|->
name|pe_context
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|AcAssocResponse
argument_list|(
name|sd
argument_list|,
name|status
argument_list|,
name|reason
argument_list|,
name|NULLOID
argument_list|,
name|NULLAEI
argument_list|,
name|NULLPA
argument_list|,
operator|&
name|ps
operator|->
name|ps_ctxlist
argument_list|,
name|ps
operator|->
name|ps_defctxresult
argument_list|,
name|ps
operator|->
name|ps_prequirements
argument_list|,
name|s_requirements
argument_list|,
name|isn
argument_list|,
name|ps
operator|->
name|ps_settings
argument_list|,
operator|&
name|ps
operator|->
name|ps_connect
argument_list|,
operator|&
name|pe
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
name|aca
argument_list|,
literal|"A-ASSOCIATE.RESPONSE"
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"sent AcAssociate Response\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_macro
name|send_bad_asr
argument_list|(
argument|reason
argument_list|)
end_macro

begin_comment
comment|/*Compose and send ASR with result = failure.  Encode 			  ASR-FailureReason using the reason parameter 			  (0 means no reason). 			*/
end_comment

begin_decl_stmt
name|int
name|reason
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|PE
name|asr_pe
decl_stmt|;
name|ASR_MSG
name|ud
decl_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|ud
argument_list|,
sizeof|sizeof
name|ud
argument_list|)
expr_stmt|;
if|if
condition|(
name|reason
condition|)
block|{
name|ud
operator|.
name|valid_reason
operator|=
literal|1
expr_stmt|;
name|ud
operator|.
name|reason
operator|.
name|type
operator|=
literal|1
expr_stmt|;
name|ud
operator|.
name|reason
operator|.
name|provider_reason
operator|=
name|reason
expr_stmt|;
block|}
else|else
name|ud
operator|.
name|valid_reason
operator|=
literal|0
expr_stmt|;
name|ud
operator|.
name|result
operator|=
literal|0
expr_stmt|;
comment|/*Failure code*/
name|ud
operator|.
name|valid_imp
operator|=
literal|0
expr_stmt|;
name|ud
operator|.
name|valid_coll
operator|=
literal|0
expr_stmt|;
name|ud
operator|.
name|valid_arg_list
operator|=
literal|0
expr_stmt|;
name|ud
operator|.
name|version
operator|.
name|bitstring
operator|=
literal|0x00
expr_stmt|;
name|ud
operator|.
name|version
operator|.
name|bitcount
operator|=
literal|5
expr_stmt|;
if|if
condition|(
name|build_ASRPDU_ASRpdu
argument_list|(
operator|&
name|asr_pe
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|,
name|NULLCP
argument_list|,
operator|(
name|PEPYPARM
operator|)
operator|&
name|ud
argument_list|)
operator|==
name|NOTOK
condition|)
name|adios
argument_list|(
name|NULLCP
argument_list|,
literal|"ASR build failure (%s)"
argument_list|,
name|PY_pepy
argument_list|)
expr_stmt|;
return|return
operator|(
name|asr
argument_list|(
name|asr_pe
argument_list|,
name|FAILURE
argument_list|)
operator|)
return|;
comment|/*Send the PDU thru Association control*/
block|}
end_block

begin_escape
end_escape

begin_macro
name|send_rlr
argument_list|(
argument|pe
argument_list|)
end_macro

begin_comment
comment|/*Send RLR (Release Response) PDU to peer.  The RLR is 		  built by vrelrsp().  It is sent by a call to Association 		  Control. 		*/
end_comment

begin_decl_stmt
name|PE
name|pe
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|pe
operator|->
name|pe_context
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|AcRelResponse
argument_list|(
name|sd
argument_list|,
name|ACS_ACCEPT
argument_list|,
name|ACR_NORMAL
argument_list|,
operator|&
name|pe
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
literal|"A-RELEASE.RESPONSE"
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_macro
name|clear_vte
argument_list|()
end_macro

begin_comment
comment|/*Clear VT Environment.  */
end_comment

begin_block
block|{
comment|/*Nothing to do for now since we have no formalized environment 	  and we exit VTP when association ends. 	*/
block|}
end_block

begin_escape
end_escape

begin_macro
name|vgvt_ind
argument_list|()
end_macro

begin_comment
comment|/*Indication to User that peer has given the token*/
end_comment

begin_block
block|{
comment|/*Don't know how to indicate this to user yet*/
block|}
end_block

begin_escape
end_escape

begin_macro
name|vrtq_ind
argument_list|()
end_macro

begin_comment
comment|/*Indicate to User that peer has requested token*/
end_comment

begin_block
block|{
comment|/*Don't know how to give indication to user. 	  Synchronous?  Asynch interrupt??? */
block|}
end_block

begin_escape
end_escape

begin_macro
name|give_token
argument_list|()
end_macro

begin_comment
comment|/*Transfer Token to peer.  For VTP, all tokens are given 		  at once so no need to discriminate between them. 		*/
end_comment

begin_block
block|{
name|int
name|vt_tokens
decl_stmt|;
name|struct
name|PSAPindication
name|vt_pi
decl_stmt|;
name|vt_tokens
operator|=
name|ST_RLS_TOKEN
expr_stmt|;
if|if
condition|(
name|PGTokenRequest
argument_list|(
name|sd
argument_list|,
name|vt_tokens
argument_list|,
operator|&
name|vt_pi
argument_list|)
operator|==
name|NOTOK
operator|&&
name|vt_pi
operator|.
name|pi_abort
operator|.
name|pa_reason
operator|!=
name|PC_OPERATION
condition|)
name|ps_adios
argument_list|(
operator|&
name|vt_pi
operator|.
name|pi_abort
argument_list|,
literal|"P-GIVE-TOKENS.REQUEST"
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_macro
name|request_token
argument_list|()
end_macro

begin_comment
comment|/*Request Tokens from peer*/
end_comment

begin_block
block|{
name|int
name|vt_tokens
decl_stmt|;
name|struct
name|PSAPindication
name|vt_pi
decl_stmt|;
name|vt_tokens
operator|=
name|ST_RLS_TOKEN
expr_stmt|;
if|if
condition|(
name|PPTokenRequest
argument_list|(
name|sd
argument_list|,
name|vt_tokens
argument_list|,
name|NULLPEP
argument_list|,
literal|0
argument_list|,
operator|&
name|vt_pi
argument_list|)
operator|==
name|NOTOK
operator|&&
name|vt_pi
operator|.
name|pi_abort
operator|.
name|pa_reason
operator|!=
name|PC_OPERATION
condition|)
name|ps_adios
argument_list|(
operator|&
name|vt_pi
operator|.
name|pi_abort
argument_list|,
literal|"P-PLEASE-TOKENS.REQUEST"
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_macro
name|send_all
argument_list|()
end_macro

begin_comment
comment|/*TEMP -- Should be supplied by Sector 5 actions*/
end_comment

begin_block
block|{
name|advise
argument_list|(
name|LLOG_DEBUG
argument_list|,
name|NULLCP
argument_list|,
literal|"send_all dummy routine"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|void
name|acs_adios
parameter_list|(
name|aa
parameter_list|,
name|event
parameter_list|)
specifier|register
name|struct
name|AcSAPabort
modifier|*
name|aa
decl_stmt|;
name|char
modifier|*
name|event
decl_stmt|;
block|{
name|acs_advise
argument_list|(
name|aa
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|finalbye
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|acs_advise
parameter_list|(
name|aa
parameter_list|,
name|event
parameter_list|)
specifier|register
name|struct
name|AcSAPabort
modifier|*
name|aa
decl_stmt|;
name|char
modifier|*
name|event
decl_stmt|;
block|{
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|aa
operator|->
name|aca_cc
operator|>
literal|0
condition|)
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"[%s] %*.*s"
argument_list|,
name|AcErrString
argument_list|(
name|aa
operator|->
name|aca_reason
argument_list|)
argument_list|,
name|aa
operator|->
name|aca_cc
argument_list|,
name|aa
operator|->
name|aca_cc
argument_list|,
name|aa
operator|->
name|aca_data
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"[%s]"
argument_list|,
name|AcErrString
argument_list|(
name|aa
operator|->
name|aca_reason
argument_list|)
argument_list|)
expr_stmt|;
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"%s: %s (source %d)"
argument_list|,
name|event
argument_list|,
name|buffer
argument_list|,
name|aa
operator|->
name|aca_source
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ps_adios
parameter_list|(
name|pab
parameter_list|,
name|event
parameter_list|)
specifier|register
name|struct
name|PSAPabort
modifier|*
name|pab
decl_stmt|;
name|char
modifier|*
name|event
decl_stmt|;
block|{
name|ps_advise
argument_list|(
name|pab
argument_list|,
name|event
argument_list|)
expr_stmt|;
name|finalbye
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|ps_advise
parameter_list|(
name|pab
parameter_list|,
name|event
parameter_list|)
specifier|register
name|struct
name|PSAPabort
modifier|*
name|pab
decl_stmt|;
name|char
modifier|*
name|event
decl_stmt|;
block|{
name|char
name|buffer
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
name|pab
operator|->
name|pa_cc
operator|>
literal|0
condition|)
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"[%s] %*.*s"
argument_list|,
name|PErrString
argument_list|(
name|pab
operator|->
name|pa_reason
argument_list|)
argument_list|,
name|pab
operator|->
name|pa_cc
argument_list|,
name|pab
operator|->
name|pa_cc
argument_list|,
name|pab
operator|->
name|pa_data
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"[%s]"
argument_list|,
name|PErrString
argument_list|(
name|pab
operator|->
name|pa_reason
argument_list|)
argument_list|)
expr_stmt|;
name|advise
argument_list|(
name|LLOG_NOTICE
argument_list|,
name|NULLCP
argument_list|,
literal|"%s: %s%s"
argument_list|,
name|event
argument_list|,
name|buffer
argument_list|,
name|pab
operator|->
name|pa_peer
condition|?
literal|" (peer initiated)"
else|:
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

