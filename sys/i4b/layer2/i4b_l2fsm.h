begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_l2fsm.h - layer 2 FSM  *      -------------------------  *  *	$Id: i4b_l2fsm.h,v 1.6 2000/03/18 09:33:48 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Sat Mar 18 10:28:37 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L2FSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L2FSM_H_
end_define

begin_enum
enum|enum
name|Q921_states
block|{
name|ST_TEI_UNAS
block|,
comment|/* TEI unassigned */
name|ST_ASG_AW_TEI
block|,
comment|/* assign awaiting TEI */
name|ST_EST_AW_TEI
block|,
comment|/* establish awaiting TEI */
name|ST_TEI_ASGD
block|,
comment|/* TEI assigned */
name|ST_AW_EST
block|,
comment|/* awaiting establishment */
name|ST_AW_REL
block|,
comment|/* awaiting release */
name|ST_MULTIFR
block|,
comment|/* multiple frame established */
name|ST_TIMREC
block|,
comment|/* timer recovery */
name|ST_SUBSET
block|,
comment|/* SUBroutine SETs new state */
name|ST_ILL
block|,
comment|/* illegal state */
name|N_STATES
comment|/* number of states */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|Q921_events
block|{
name|EV_DLESTRQ
block|,
comment|/* dl establish req */
name|EV_DLUDTRQ
block|,
comment|/* dl unit data req */
name|EV_MDASGRQ
block|,
comment|/* mdl assign req */
name|EV_MDERRRS
block|,
comment|/* mdl error response */
name|EV_PSDEACT
block|,
comment|/* persistent deactivation */
name|EV_MDREMRQ
block|,
comment|/* mdl remove req */
name|EV_RXSABME
block|,
comment|/* rx'd SABME */
name|EV_RXDISC
block|,
comment|/* rx'd DISC */
name|EV_RXUA
block|,
comment|/* rx'd UA */
name|EV_RXDM
block|,
comment|/* rx'd DM */
name|EV_T200EXP
block|,
comment|/* T200 expired */
name|EV_DLDATRQ
block|,
comment|/* dl data req */
name|EV_DLRELRQ
block|,
comment|/* dl release req */
name|EV_T203EXP
block|,
comment|/* T203 expired */
name|EV_OWNBUSY
block|,
comment|/* set own rx busy */
name|EV_OWNRDY
block|,
comment|/* clear own rx busy */
name|EV_RXRR
block|,
comment|/* rx'd RR */
name|EV_RXREJ
block|,
comment|/* rx'd REJ */
name|EV_RXRNR
block|,
comment|/* rx'd RNR */
name|EV_RXFRMR
block|,
comment|/* rx'd FRMR */
name|EV_ILL
block|,
comment|/* Illegal */
name|N_EVENTS
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_L2FSM_H_ */
end_comment

end_unit

