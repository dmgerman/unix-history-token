begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_l2.h - ISDN layer 2 (Q.921) definitions  *	---------------------------------------------  *  *	$Id: i4b_l2.h,v 1.23 2000/08/24 11:48:58 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Sat Mar 18 10:28:22 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L2_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L2_H_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* unit number this entry is for */
name|int
name|Q921_state
decl_stmt|;
comment|/* state according to Q.921 */
name|u_char
name|last_ril
decl_stmt|;
comment|/* last reference number from TEI management */
name|u_char
name|last_rih
decl_stmt|;
name|int
name|tei_valid
decl_stmt|;
comment|/* tei is valid flag */
define|#
directive|define
name|TEI_INVALID
value|0
define|#
directive|define
name|TEI_VALID
value|1
name|int
name|tei
decl_stmt|;
comment|/* tei, if tei flag valid */
name|int
name|ph_active
decl_stmt|;
comment|/* Layer 1 active flag */
define|#
directive|define
name|PH_INACTIVE
value|0
comment|/* layer 1 inactive */
define|#
directive|define
name|PH_ACTIVEPEND
value|1
comment|/* already tried to activate */
define|#
directive|define
name|PH_ACTIVE
value|2
comment|/* layer 1 active */
name|int
name|T200
decl_stmt|;
comment|/* Multiframe timeout timer */
name|int
name|T201
decl_stmt|;
comment|/* min time between TEI ID check */
name|int
name|T202
decl_stmt|;
comment|/* min time between TEI ID Req messages */
name|int
name|N202
decl_stmt|;
comment|/* TEI ID Req tx counter */
name|void
function_decl|(
modifier|*
name|T202func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* function to be called when T202 expires */
name|int
name|T203
decl_stmt|;
comment|/* max line idle time */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|callout_handle
name|T200_callout
decl_stmt|;
name|struct
name|callout_handle
name|T202_callout
decl_stmt|;
name|struct
name|callout_handle
name|T203_callout
decl_stmt|;
name|struct
name|callout_handle
name|IFQU_callout
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|__NetBSD_Version__
operator|>=
literal|104230000
name|struct
name|callout
name|T200_callout
decl_stmt|;
name|struct
name|callout
name|T202_callout
decl_stmt|;
name|struct
name|callout
name|T203_callout
decl_stmt|;
name|struct
name|callout
name|IFQU_callout
decl_stmt|;
endif|#
directive|endif
comment|/*  * i4b_iframe.c, i4b_i_frame_queued_up(): value of IFQU_DLY  * some experimentation Gary did showed a minimal value of (hz/20) was  * possible to let this work, Gary suggested using (hz/10) but i settled  * down to using (hz/5) for now (-hm).  */
define|#
directive|define
name|IFQU_DLY
value|(hz/5)
comment|/* reschedule I-FRAME-QUEUED-UP 0.2 sec */
name|int
name|vr
decl_stmt|;
comment|/* receive sequence frame counter */
name|int
name|vs
decl_stmt|;
comment|/* transmit sequence frame counter */
name|int
name|va
decl_stmt|;
comment|/* acknowledge sequence frame counter */
name|int
name|ack_pend
decl_stmt|;
comment|/* acknowledge pending */
name|int
name|rej_excpt
decl_stmt|;
comment|/* reject exception */
name|int
name|peer_busy
decl_stmt|;
comment|/* peer receiver busy */
name|int
name|own_busy
decl_stmt|;
comment|/* own receiver busy */
name|int
name|l3initiated
decl_stmt|;
comment|/* layer 3 initiated */
name|struct
name|ifqueue
name|i_queue
decl_stmt|;
comment|/* queue of outgoing i frames */
define|#
directive|define
name|IQUEUE_MAXLEN
value|20
comment|/* this implementation only supports a k-value of 1 !!! */
name|struct
name|mbuf
modifier|*
name|ua_frame
decl_stmt|;
comment|/* last unacked frame */
name|int
name|ua_num
decl_stmt|;
comment|/* last unacked frame number */
define|#
directive|define
name|UA_EMPTY
value|(-1)
comment|/* ua_frame is unused	*/
name|int
name|rxd_CR
decl_stmt|;
comment|/* received Command Response bit */
name|int
name|rxd_PF
decl_stmt|;
comment|/* received Poll/Final bit */
name|int
name|rxd_NR
decl_stmt|;
comment|/* received N(R) field */
name|int
name|RC
decl_stmt|;
comment|/* Retry Counter */
name|int
name|iframe_sent
decl_stmt|;
comment|/* check if i frame acked by another i frame */
name|int
function_decl|(
modifier|*
name|postfsmfunc
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* function to be called at fsm exit */
name|int
name|postfsmarg
decl_stmt|;
comment|/* argument for above function */
comment|/* statistics */
name|lapdstat_t
name|stat
decl_stmt|;
comment|/* lapd protocol statistics */
block|}
name|l2_softc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|l2_softc_t
name|l2_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Q.912 system parameters (Q.921 03/93 pp 43) */
end_comment

begin_define
define|#
directive|define
name|MAX_K_VALUE
value|1
end_define

begin_comment
comment|/* BRI - # of outstanding frames 	*/
end_comment

begin_define
define|#
directive|define
name|N200
value|3
end_define

begin_comment
comment|/* max no of retransmissions */
end_comment

begin_define
define|#
directive|define
name|N201DEF
value|260
end_define

begin_comment
comment|/* max no of octetts in information field */
end_comment

begin_define
define|#
directive|define
name|N202DEF
value|3
end_define

begin_comment
comment|/* max no of TEI ID Request message transmissions */
end_comment

begin_define
define|#
directive|define
name|T200DEF
value|(hz*1)
end_define

begin_comment
comment|/* default T200 timer value = 1 second	*/
end_comment

begin_define
define|#
directive|define
name|T201DEF
value|T200DEF
end_define

begin_comment
comment|/* default T201 timer value = T200DEF	*/
end_comment

begin_define
define|#
directive|define
name|T202DEF
value|(hz*2)
end_define

begin_comment
comment|/* default T202 timer value = 2 seconds */
end_comment

begin_define
define|#
directive|define
name|T203DEF
value|(hz*10)
end_define

begin_comment
comment|/* default T203 timer value = 10 seconds*/
end_comment

begin_comment
comment|/* modulo 128 operations */
end_comment

begin_define
define|#
directive|define
name|M128INC
parameter_list|(
name|v
parameter_list|)
value|(v)++;		\ 			if((v)>127)	\ 			{		\ 				v = 0;	\ 			}
end_define

begin_define
define|#
directive|define
name|M128DEC
parameter_list|(
name|v
parameter_list|)
value|(v)--;		\ 			if((v)<0)	\ 			{		\ 				v = 127;\ 			}
end_define

begin_comment
comment|/* P-bit values */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|P0
block|,
name|P1
block|}
name|pbit_t
typedef|;
end_typedef

begin_comment
comment|/* F-bit values */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|F0
block|,
name|F1
block|}
name|fbit_t
typedef|;
end_typedef

begin_comment
comment|/* CR-bit values to NT */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CR_CMD_TO_NT
block|,
name|CR_RSP_TO_NT
block|}
name|crbit_to_nt_t
typedef|;
end_typedef

begin_comment
comment|/* CR-bit values from NT */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CR_RSP_FROM_NT
block|,
name|CR_CMD_FROM_NT
block|}
name|crbit_from_nt_t
typedef|;
end_typedef

begin_comment
comment|/* address field - octett 2 */
end_comment

begin_define
define|#
directive|define
name|OFF_SAPI
value|0
end_define

begin_comment
comment|/* SAPI offset, HDLC flag is eaten by L1 */
end_comment

begin_define
define|#
directive|define
name|SAPI_CCP
value|0
end_define

begin_comment
comment|/* SAPI = 0 - call control procedures */
end_comment

begin_define
define|#
directive|define
name|SAPI_X25
value|16
end_define

begin_comment
comment|/* SAPI = 16 - X.25 packet procedures */
end_comment

begin_define
define|#
directive|define
name|SAPI_L2M
value|63
end_define

begin_comment
comment|/* SAPI = 63 - Layer 2 management procedures */
end_comment

begin_comment
comment|/* extract and insert macros for SAPI octett */
end_comment

begin_define
define|#
directive|define
name|GETSAPI
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 2)& 0x3f)
end_define

begin_define
define|#
directive|define
name|PUTSAPI
parameter_list|(
name|sapi
parameter_list|,
name|cr
parameter_list|,
name|octett
parameter_list|)
value|((octett) = (((sapi<< 2)& 0xfc) | ((cr& 0x01)<< 1)))
end_define

begin_define
define|#
directive|define
name|GETCR
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x01)
end_define

begin_define
define|#
directive|define
name|GETEA
parameter_list|(
name|octett
parameter_list|)
value|((octett)& 0x01)
end_define

begin_comment
comment|/* address field - octett 3 */
end_comment

begin_define
define|#
directive|define
name|OFF_TEI
value|1
end_define

begin_comment
comment|/* TEI offset */
end_comment

begin_define
define|#
directive|define
name|GETTEI
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x7f)
end_define

begin_define
define|#
directive|define
name|PUTTEI
parameter_list|(
name|tei
parameter_list|,
name|octett
parameter_list|)
value|((octett) = ((((tei)<< 1)& 0xfe)) | 0x01)
end_define

begin_define
define|#
directive|define
name|GROUP_TEI
value|127
end_define

begin_comment
comment|/* broadcast TEI for LME */
end_comment

begin_comment
comment|/* control field - octett 4 */
end_comment

begin_define
define|#
directive|define
name|OFF_CNTL
value|2
end_define

begin_comment
comment|/* 1st byte of control field */
end_comment

begin_comment
comment|/* S frames */
end_comment

begin_define
define|#
directive|define
name|S_FRAME_LEN
value|4
end_define

begin_comment
comment|/* lenght of a U-frame */
end_comment

begin_define
define|#
directive|define
name|OFF_SRCR
value|2
end_define

begin_comment
comment|/* 1st byte of control field,	*/
end_comment

begin_comment
comment|/* R-commands and R-responses	*/
end_comment

begin_define
define|#
directive|define
name|OFF_SNR
value|3
end_define

begin_comment
comment|/* 2nd byte of control field, N(R) and PF */
end_comment

begin_define
define|#
directive|define
name|SPFBIT
value|0x01
end_define

begin_comment
comment|/* poll/final bit mask */
end_comment

begin_define
define|#
directive|define
name|SPBITSET
value|SPFBIT
end_define

begin_define
define|#
directive|define
name|SFBITSET
value|SPFBIT
end_define

begin_define
define|#
directive|define
name|GETSNR
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x7f)
end_define

begin_define
define|#
directive|define
name|GETSPF
parameter_list|(
name|octett
parameter_list|)
value|((octett)& SPFBIT)
end_define

begin_define
define|#
directive|define
name|RR
value|0x01
end_define

begin_comment
comment|/* RR and bit 0 set */
end_comment

begin_define
define|#
directive|define
name|RNR
value|0x05
end_define

begin_comment
comment|/* RNR and bit 0 set */
end_comment

begin_define
define|#
directive|define
name|REJ
value|0x09
end_define

begin_comment
comment|/* REJ and bit 0 set */
end_comment

begin_comment
comment|/* U frames */
end_comment

begin_define
define|#
directive|define
name|UI_HDR_LEN
value|3
end_define

begin_comment
comment|/* length of UI header in front of L3 frame */
end_comment

begin_define
define|#
directive|define
name|U_FRAME_LEN
value|3
end_define

begin_comment
comment|/* lenght of a U-frame */
end_comment

begin_define
define|#
directive|define
name|UPFBIT
value|0x10
end_define

begin_comment
comment|/* poll/final bit mask */
end_comment

begin_define
define|#
directive|define
name|UPBITSET
value|UPFBIT
end_define

begin_define
define|#
directive|define
name|UFBITSET
value|UPFBIT
end_define

begin_define
define|#
directive|define
name|GETUPF
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 4)& 0x01)
end_define

begin_comment
comment|/* commands/responses with pf bit set to 0 */
end_comment

begin_define
define|#
directive|define
name|SABME
value|0x6f
end_define

begin_define
define|#
directive|define
name|DM
value|0x0f
end_define

begin_define
define|#
directive|define
name|UI
value|0x03
end_define

begin_define
define|#
directive|define
name|DISC
value|0x43
end_define

begin_define
define|#
directive|define
name|UA
value|0x63
end_define

begin_define
define|#
directive|define
name|FRMR
value|0x87
end_define

begin_define
define|#
directive|define
name|XID
value|0xaf
end_define

begin_comment
comment|/* control field - octett 3 */
end_comment

begin_define
define|#
directive|define
name|OFF_MEI
value|3
end_define

begin_comment
comment|/* 2nd byte of control field */
end_comment

begin_comment
comment|/* control field - octett 4,5 */
end_comment

begin_define
define|#
directive|define
name|OFF_RIL
value|4
end_define

begin_comment
comment|/* Ri low byte */
end_comment

begin_define
define|#
directive|define
name|OFF_RIH
value|5
end_define

begin_comment
comment|/* Ri high byte */
end_comment

begin_comment
comment|/* control field - octett 6 */
end_comment

begin_define
define|#
directive|define
name|OFF_MT
value|6
end_define

begin_comment
comment|/* Message Type */
end_comment

begin_define
define|#
directive|define
name|OFF_AI
value|7
end_define

begin_comment
comment|/* Action Indicator  */
end_comment

begin_define
define|#
directive|define
name|GET_TEIFROMAI
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x7f)
end_define

begin_comment
comment|/* I frame */
end_comment

begin_define
define|#
directive|define
name|I_HDR_LEN
value|4
end_define

begin_comment
comment|/* length of I header in front of L3 frame */
end_comment

begin_define
define|#
directive|define
name|OFF_INS
value|2
end_define

begin_comment
comment|/* transmit sequence number */
end_comment

begin_define
define|#
directive|define
name|OFF_INR
value|3
end_define

begin_comment
comment|/* receive sequence number */
end_comment

begin_define
define|#
directive|define
name|IPFBIT
value|0x01
end_define

begin_comment
comment|/* poll/final bit mask */
end_comment

begin_define
define|#
directive|define
name|IPBITSET
value|0x01
end_define

begin_define
define|#
directive|define
name|GETINR
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x7f)
end_define

begin_define
define|#
directive|define
name|GETINS
parameter_list|(
name|octett
parameter_list|)
value|(((octett)>> 1)& 0x7f)
end_define

begin_define
define|#
directive|define
name|GETIP
parameter_list|(
name|octett
parameter_list|)
value|((octett)& IPFBIT)
end_define

begin_comment
comment|/* structure of a TEI management frame */
end_comment

begin_define
define|#
directive|define
name|TEI_MGMT_FRM_LEN
value|8
end_define

begin_comment
comment|/* frame length */
end_comment

begin_define
define|#
directive|define
name|TEIM_SAPIO
value|0x00
end_define

begin_comment
comment|/* SAPI, CR, EA */
end_comment

begin_define
define|#
directive|define
name|TEIM_TEIO
value|0x01
end_define

begin_comment
comment|/* TEI, EA */
end_comment

begin_define
define|#
directive|define
name|TEIM_UIO
value|0x02
end_define

begin_comment
comment|/* frame type = UI = 0x03 */
end_comment

begin_define
define|#
directive|define
name|TEIM_MEIO
value|0x03
end_define

begin_comment
comment|/* management entity id = 0x0f */
end_comment

begin_define
define|#
directive|define
name|MEI
value|0x0f
end_define

begin_define
define|#
directive|define
name|TEIM_RILO
value|0x04
end_define

begin_comment
comment|/* reference number, low  */
end_comment

begin_define
define|#
directive|define
name|TEIM_RIHO
value|0x05
end_define

begin_comment
comment|/* reference number, high */
end_comment

begin_define
define|#
directive|define
name|TEIM_MTO
value|0x06
end_define

begin_comment
comment|/* message type */
end_comment

begin_define
define|#
directive|define
name|MT_ID_REQEST
value|0x01
end_define

begin_define
define|#
directive|define
name|MT_ID_ASSIGN
value|0x02
end_define

begin_define
define|#
directive|define
name|MT_ID_DENY
value|0x03
end_define

begin_define
define|#
directive|define
name|MT_ID_CHK_REQ
value|0x04
end_define

begin_define
define|#
directive|define
name|MT_ID_CHK_RSP
value|0x05
end_define

begin_define
define|#
directive|define
name|MT_ID_REMOVE
value|0x06
end_define

begin_define
define|#
directive|define
name|MT_ID_VERIFY
value|0x07
end_define

begin_define
define|#
directive|define
name|TEIM_AIO
value|0x07
end_define

begin_comment
comment|/* action indicator */
end_comment

begin_comment
comment|/* i4b_mdl_error_ind codes */
end_comment

begin_enum
enum|enum
name|MDL_ERROR_CODES
block|{
name|MDL_ERR_A
block|,
name|MDL_ERR_B
block|,
name|MDL_ERR_C
block|,
name|MDL_ERR_D
block|,
name|MDL_ERR_E
block|,
name|MDL_ERR_F
block|,
name|MDL_ERR_G
block|,
name|MDL_ERR_H
block|,
name|MDL_ERR_I
block|,
name|MDL_ERR_J
block|,
name|MDL_ERR_K
block|,
name|MDL_ERR_L
block|,
name|MDL_ERR_M
block|,
name|MDL_ERR_N
block|,
name|MDL_ERR_O
block|,
name|MDL_ERR_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* forward decl */
end_comment

begin_function_decl
specifier|extern
name|void
name|i4b_acknowledge_pending
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|i4b_build_s_frame
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|crbit_to_nt_t
name|crbit
parameter_list|,
name|pbit_t
name|pbit
parameter_list|,
name|u_char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|i4b_build_u_frame
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|crbit_to_nt_t
name|crbit
parameter_list|,
name|pbit_t
name|pbit
parameter_list|,
name|u_char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_clear_exception_conditions
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_dl_data_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_dl_establish_req
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_dl_release_req
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_dl_unit_data_req
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_enquiry_response
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_establish_data_link
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_invoke_retransmission
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|int
name|nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_i_frame_queued_up
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_l1_activate
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_l2_nr_ok
parameter_list|(
name|int
name|nr
parameter_list|,
name|int
name|va
parameter_list|,
name|int
name|vs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_make_rand_ri
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_mdl_assign_ind
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_mph_status_ind
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|status
parameter_list|,
name|int
name|parm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_next_l2state
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_nr_error_recovery
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_ph_activate_ind
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_ph_deactivate_ind
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i4b_ph_data_ind
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_print_frame
parameter_list|(
name|int
name|len
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|i4b_print_l2state
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_print_l2var
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_rxd_ack
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|int
name|nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_rxd_i_frame
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_rxd_s_frame
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_rxd_u_frame
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T200_restart
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T200_start
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T200_stop
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T202_start
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T202_stop
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T203_restart
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T203_start
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_T203_stop
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tei_assign
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tei_chkresp
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tei_rxframe
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tei_verify
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_transmit_enquire
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_disc
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|pbit_t
name|pbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_dm
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_frmr
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_rej_response
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_rnr_command
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|pbit_t
name|pbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_rnr_response
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_rr_command
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|pbit_t
name|pbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_rr_response
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_sabme
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|pbit_t
name|pbit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i4b_tx_ua
parameter_list|(
name|l2_softc_t
modifier|*
name|l2sc
parameter_list|,
name|fbit_t
name|fbit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_L2_H_ */
end_comment

end_unit

