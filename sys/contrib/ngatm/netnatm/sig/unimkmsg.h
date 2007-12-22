begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/sig/unimkmsg.h,v 1.4 2003/09/19 12:03:34 hbb Exp $  *  * Macros to make messages.  */
end_comment

begin_define
define|#
directive|define
name|MK_MSG_ORIG
parameter_list|(
name|MSG
parameter_list|,
name|TYPE
parameter_list|,
name|CREF
parameter_list|,
name|FLAG
parameter_list|)
define|\
value|do {								\ 	(MSG)->mtype = (TYPE);						\ 	(MSG)->u.hdr.cref.cref = (CREF);				\ 	(MSG)->u.hdr.cref.flag = (FLAG);				\ 	(MSG)->u.hdr.act = UNI_MSGACT_DEFAULT;				\     } while(0)
end_define

begin_define
define|#
directive|define
name|MK_MSG_RESP
parameter_list|(
name|MSG
parameter_list|,
name|TYPE
parameter_list|,
name|CREF
parameter_list|)
define|\
value|do {								\ 	(MSG)->mtype = (TYPE);						\ 	(MSG)->u.hdr.cref.cref = (CREF)->cref;				\ 	(MSG)->u.hdr.cref.flag = !(CREF)->flag;				\ 	(MSG)->u.hdr.act = UNI_MSGACT_DEFAULT;				\     } while(0)
end_define

begin_define
define|#
directive|define
name|MK_IE_CALLSTATE
parameter_list|(
name|IE
parameter_list|,
name|CS
parameter_list|)
define|\
value|do {								\ 	(IE).h.present = 0;						\ 	IE_SETPRESENT(IE);						\ 	(IE).h.coding = UNI_CODING_ITU;					\ 	(IE).h.act = UNI_IEACT_DEFAULT;					\ 	(IE).state = CS;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|MK_IE_EPREF
parameter_list|(
name|IE
parameter_list|,
name|EPREF
parameter_list|,
name|FLAG
parameter_list|)
define|\
value|do {								\ 	(IE).h.present = 0;						\ 	IE_SETPRESENT(IE);						\ 	(IE).h.coding = UNI_CODING_ITU;					\ 	(IE).h.act = UNI_IEACT_DEFAULT;					\ 	(IE).epref = EPREF;						\ 	(IE).flag = FLAG;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|MK_IE_EPSTATE
parameter_list|(
name|IE
parameter_list|,
name|STATE
parameter_list|)
define|\
value|do {								\ 	(IE).h.present = 0;						\ 	IE_SETPRESENT(IE);						\ 	(IE).h.coding = UNI_CODING_ITU;					\ 	(IE).h.act = UNI_IEACT_DEFAULT;					\ 	(IE).state = STATE;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|MK_IE_CAUSE
parameter_list|(
name|IE
parameter_list|,
name|LOC
parameter_list|,
name|CAUSE
parameter_list|)
define|\
value|do {								\ 	(IE).h.present = 0;						\ 	IE_SETPRESENT(IE);						\ 	(IE).h.coding = UNI_CODING_ITU;					\ 	(IE).h.act = UNI_IEACT_DEFAULT;					\ 	(IE).loc = LOC;							\ 	(IE).cause = CAUSE;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|ADD_CAUSE_MTYPE
parameter_list|(
name|IE
parameter_list|,
name|MTYPE
parameter_list|)
define|\
value|do {								\ 	(IE).h.present |= UNI_CAUSE_MTYPE_P;				\ 	(IE).u.mtype = MTYPE;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|ADD_CAUSE_CHANNID
parameter_list|(
name|IE
parameter_list|,
name|VPI
parameter_list|,
name|VCI
parameter_list|)
define|\
value|do {								\ 	(IE).h.present |= UNI_CAUSE_VPCI_P;				\ 	(IE).u.vpci.vpci = VPI;						\ 	(IE).u.vpci.vci = VCI;						\     } while(0)
end_define

begin_define
define|#
directive|define
name|ADD_CAUSE_TIMER
parameter_list|(
name|IE
parameter_list|,
name|TIMER
parameter_list|)
define|\
value|do {								\ 	(IE).h.present |= UNI_CAUSE_TIMER_P;				\ 	(IE).u.timer[0] = (TIMER)[0];					\ 	(IE).u.timer[1] = (TIMER)[1];					\ 	(IE).u.timer[2] = (TIMER)[2];					\     } while(0)
end_define

begin_comment
comment|/************************************************************/
end_comment

begin_define
define|#
directive|define
name|COPY_FROM_RELEASE_COMPL
parameter_list|(
name|U
parameter_list|,
name|DEST
parameter_list|)
define|\
value|do {								\ 	u_int _i, _j;							\ 									\ 	for(_i = _j = 0; _i< 2; _i++)					\ 		if(IE_ISGOOD((U)->u.release_compl.cause[_i]))		\ 			(DEST)->cause[_j++] =				\ 			    (U)->u.release_compl.cause[_i];		\ 	for(_i = _j = 0; _i< UNI_NUM_IE_GIT; _i++)			\ 		if(IE_ISGOOD((U)->u.release_compl.git[_i]))		\ 			(DEST)->git[_j++] =				\ 			    (U)->u.release_compl.git[_i];		\ 	if(IE_ISGOOD((U)->u.release_compl.uu))				\ 		(DEST)->uu = (U)->u.release_compl.uu;			\ 	if(IE_ISGOOD((U)->u.release_compl.crankback))			\ 		(DEST)->crankback = (U)->u.release_compl.crankback;	\     } while(0)
end_define

begin_define
define|#
directive|define
name|COPY_FROM_DROP_ACK
parameter_list|(
name|U
parameter_list|,
name|DEST
parameter_list|)
define|\
value|do {								\ 	u_int _i, _j;							\ 									\ 	if(IE_ISGOOD((U)->u.drop_party_ack.epref))			\ 		(DEST)->epref = (U)->u.drop_party_ack.epref;		\ 	if(IE_ISGOOD((U)->u.drop_party_ack.cause))			\ 		(DEST)->cause = (U)->u.drop_party_ack.cause;		\ 	if(IE_ISGOOD((U)->u.drop_party_ack.uu))				\ 		(DEST)->uu = (U)->u.drop_party_ack.uu;			\ 	for(_i = _j = 0; _i< UNI_NUM_IE_GIT; _i++)			\ 		if(IE_ISGOOD((U)->u.drop_party_ack.git[_i]))		\ 			(DEST)->git[_j++] =				\ 			    (U)->u.drop_party_ack.git[_i];		\     } while(0)
end_define

begin_define
define|#
directive|define
name|COPY_FROM_ADD_REJ
parameter_list|(
name|U
parameter_list|,
name|DEST
parameter_list|)
define|\
value|do {								\ 	u_int _i, _j;							\ 									\ 	if(IE_ISGOOD((U)->u.add_party_rej.epref))			\ 		(DEST)->epref = (U)->u.add_party_rej.epref;		\ 	if(IE_ISGOOD((U)->u.add_party_rej.cause))			\ 		(DEST)->cause = (U)->u.add_party_rej.cause;		\ 	if(IE_ISGOOD((U)->u.add_party_rej.uu))				\ 		(DEST)->uu = (U)->u.add_party_rej.uu;			\ 	for(_i = _j = 0; _i< UNI_NUM_IE_GIT; _i++)			\ 		if(IE_ISGOOD((U)->u.add_party_rej.git[_i]))		\ 			(DEST)->git[_j++] =				\ 			    (U)->u.add_party_rej.git[_i];		\     } while(0)
end_define

end_unit

