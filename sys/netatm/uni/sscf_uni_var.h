begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCF UNI protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCF_UNI_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCF_UNI_VAR_H
end_define

begin_comment
comment|/*  * Structure containing information for each SSCF UNI connection.  */
end_comment

begin_struct
struct|struct
name|univcc
block|{
name|u_char
name|uv_ustate
decl_stmt|;
comment|/* SSCF-User state (see below) */
name|u_char
name|uv_lstate
decl_stmt|;
comment|/* SSCF-SSCOP state (see below) */
name|u_short
name|uv_flags
decl_stmt|;
comment|/* Connection flags (see below) */
name|enum
name|uni_vers
name|uv_vers
decl_stmt|;
comment|/* UNI version */
comment|/* Stack variables */
name|Atm_connvc
modifier|*
name|uv_connvc
decl_stmt|;
comment|/* Connection vcc for this stack */
name|void
modifier|*
name|uv_toku
decl_stmt|;
comment|/* Stack upper layer's token */
name|void
modifier|*
name|uv_tokl
decl_stmt|;
comment|/* Stack lower layer's token */
name|void
function_decl|(
modifier|*
name|uv_upper
function_decl|)
comment|/* Stack upper layer's interface */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|uv_lower
function_decl|)
comment|/* Stack lower layer's interface */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SSCF to SAAL User (Q.2931) Interface States  */
end_comment

begin_define
define|#
directive|define
name|UVU_INST
value|0
end_define

begin_comment
comment|/* Instantiated, waiting for INIT */
end_comment

begin_define
define|#
directive|define
name|UVU_RELEASED
value|1
end_define

begin_comment
comment|/* Connection released */
end_comment

begin_define
define|#
directive|define
name|UVU_PACTIVE
value|2
end_define

begin_comment
comment|/* Awaiting connection establishment */
end_comment

begin_define
define|#
directive|define
name|UVU_PRELEASE
value|3
end_define

begin_comment
comment|/* Awaiting connection release */
end_comment

begin_define
define|#
directive|define
name|UVU_ACTIVE
value|4
end_define

begin_comment
comment|/* Connection established */
end_comment

begin_define
define|#
directive|define
name|UVU_TERM
value|5
end_define

begin_comment
comment|/* Waiting for TERM */
end_comment

begin_comment
comment|/*  * SSCF to SSCOP Interface States  */
end_comment

begin_define
define|#
directive|define
name|UVL_INST
value|0
end_define

begin_comment
comment|/* Instantiated, waiting for INIT */
end_comment

begin_define
define|#
directive|define
name|UVL_IDLE
value|1
end_define

begin_comment
comment|/* Idle */
end_comment

begin_define
define|#
directive|define
name|UVL_OUTCONN
value|2
end_define

begin_comment
comment|/* Outgoing connection pending */
end_comment

begin_define
define|#
directive|define
name|UVL_INCONN
value|3
end_define

begin_comment
comment|/* Incoming connection pending */
end_comment

begin_define
define|#
directive|define
name|UVL_OUTDISC
value|4
end_define

begin_comment
comment|/* Outgoing disconnection pending */
end_comment

begin_define
define|#
directive|define
name|UVL_OUTRESYN
value|5
end_define

begin_comment
comment|/* Outgoing resynchronization pending */
end_comment

begin_define
define|#
directive|define
name|UVL_INRESYN
value|6
end_define

begin_comment
comment|/* Incoming resynchornization pending */
end_comment

begin_define
define|#
directive|define
name|UVL_RECOVERY
value|8
end_define

begin_comment
comment|/* Recovery pending */
end_comment

begin_define
define|#
directive|define
name|UVL_READY
value|10
end_define

begin_comment
comment|/* Data transfer ready */
end_comment

begin_define
define|#
directive|define
name|UVL_TERM
value|11
end_define

begin_comment
comment|/* Waiting for TERM */
end_comment

begin_comment
comment|/*  * Connection Flags  */
end_comment

begin_define
define|#
directive|define
name|UVF_NOESTIND
value|0x0001
end_define

begin_comment
comment|/* Don't process ESTABLISH_IND */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* sscf_uni.c */
end_comment

begin_function_decl
name|int
name|sscf_uni_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscf_uni_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscf_uni_abort
parameter_list|(
name|struct
name|univcc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscf_uni_pdu_print
parameter_list|(
name|struct
name|univcc
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscf_uni_lower.c */
end_comment

begin_function_decl
name|void
name|sscf_uni_lower
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscf_uni_upper.c */
end_comment

begin_function_decl
name|void
name|sscf_uni_upper
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sscf_uni_vccnt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SSCF_UNI_VAR_H */
end_comment

end_unit

