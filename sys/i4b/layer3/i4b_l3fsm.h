begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *      i4b_l3fsm.c - layer 3 FSM  *      -------------------------  *   *	$Id: i4b_l3fsm.h,v 1.8 2000/04/27 09:25:22 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Thu Apr 27 11:07:16 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L3FSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L3FSM_H_
end_define

begin_enum
enum|enum
name|Q931_states
block|{
name|ST_U0
block|,
name|ST_U1
block|,
name|ST_U3
block|,
name|ST_U4
block|,
name|ST_U6
block|,
name|ST_U7
block|,
name|ST_U8
block|,
name|ST_U9
block|,
name|ST_U10
block|,
name|ST_U11
block|,
name|ST_U12
block|,
name|ST_U19
block|,
name|ST_IWA
block|,
comment|/* incoming call, wait establish, then accept */
name|ST_IWR
block|,
comment|/* incoming call, wait establish, then reject */
name|ST_OW
block|,
comment|/* outgoing call, wait establish */
name|ST_IWL
block|,
comment|/* incoming call, wait establish, then alert */
name|ST_SUSE
block|,
comment|/* SUBroutine SETs new state on exit */
name|ST_ILL
block|,
comment|/* Illegal */
name|N_STATES
comment|/* number of states */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|Q931_events
block|{
name|EV_SETUPRQ
block|,
comment|/* setup request from L4		*/
name|EV_DISCRQ
block|,
comment|/* disconnect request from L4		*/
name|EV_RELRQ
block|,
comment|/* release request from L4		*/
name|EV_ALERTRQ
block|,
comment|/* alerting request from L4		*/
name|EV_SETACRS
block|,
comment|/* setup response accept from l4	*/
name|EV_SETRJRS
block|,
comment|/* setup response reject from l4	*/
name|EV_SETDCRS
block|,
comment|/* setup response dontcare from l4	*/
name|EV_SETUP
block|,
comment|/* incoming SETUP message from L2	*/
name|EV_STATUS
block|,
comment|/* incoming STATUS message from L2	*/
name|EV_RELEASE
block|,
comment|/* incoming RELEASE message from L2	*/
name|EV_RELCOMP
block|,
comment|/* incoming RELEASE COMPLETE from L2	*/
name|EV_SETUPAK
block|,
comment|/* incoming SETUP ACK message from L2	*/
name|EV_CALLPRC
block|,
comment|/* incoming CALL PROCEEDING from L2	*/
name|EV_ALERT
block|,
comment|/* incoming ALERT message from L2	*/
name|EV_CONNECT
block|,
comment|/* incoming CONNECT message from L2	*/
name|EV_PROGIND
block|,
comment|/* incoming Progress IND from L2	*/
name|EV_DISCONN
block|,
comment|/* incoming DISCONNECT message from L2	*/
name|EV_CONACK
block|,
comment|/* incoming CONNECT ACK message from L2	*/
name|EV_STATENQ
block|,
comment|/* incoming STATUS ENQ message from L2	*/
name|EV_INFO
block|,
comment|/* incoming INFO message from L2	*/
name|EV_FACILITY
block|,
comment|/* FACILITY message			*/
name|EV_T303EXP
block|,
comment|/* Timer T303 expired			*/
name|EV_T305EXP
block|,
comment|/* Timer T305 expired			*/
name|EV_T308EXP
block|,
comment|/* Timer T308 expired			*/
name|EV_T309EXP
block|,
comment|/* Timer T309 expired			*/
name|EV_T310EXP
block|,
comment|/* Timer T310 expired			*/
name|EV_T313EXP
block|,
comment|/* Timer T313 expired			*/
name|EV_DLESTIN
block|,
comment|/* dl establish indication from l2	*/
name|EV_DLRELIN
block|,
comment|/* dl release indication from l2	*/
name|EV_DLESTCF
block|,
comment|/* dl establish confirm from l2		*/
name|EV_DLRELCF
block|,
comment|/* dl release indication from l2	*/
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
comment|/* _I4B_L3FSM_H_ */
end_comment

end_unit

