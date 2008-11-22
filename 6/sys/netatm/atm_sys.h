begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * General system definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_SYS_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_SYS_H
end_define

begin_comment
comment|/*  * Software Version  */
end_comment

begin_define
define|#
directive|define
name|ATM_VERSION
value|0x00030000
end_define

begin_comment
comment|/* Version 3.0 */
end_comment

begin_define
define|#
directive|define
name|ATM_VERS_MAJ
parameter_list|(
name|v
parameter_list|)
value|((v)>> 16)
end_define

begin_define
define|#
directive|define
name|ATM_VERS_MIN
parameter_list|(
name|v
parameter_list|)
value|((v)& 0xffff)
end_define

begin_comment
comment|/*  * Misc system defines  */
end_comment

begin_define
define|#
directive|define
name|ATM_CALLQ_MAX
value|100
end_define

begin_comment
comment|/* Maximum length of call queue */
end_comment

begin_define
define|#
directive|define
name|ATM_INTRQ_MAX
value|1000
end_define

begin_comment
comment|/* Maximum length of interrupt queue */
end_comment

begin_comment
comment|/*  * ATM address manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|ATM_ADDR_EQUAL
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|(((a1)->address_format == (a2)->address_format)&& 		\ 	 ((a1)->address_length == (a2)->address_length)&& 		\ 	 (bcmp((caddr_t)(a1)->address, (caddr_t)(a2)->address,	 	\ 		(a1)->address_length) == 0))
end_define

begin_define
define|#
directive|define
name|ATM_ADDR_SEL_EQUAL
parameter_list|(
name|a1
parameter_list|,
name|s1
parameter_list|,
name|a2
parameter_list|)
define|\
value|(((a1)->address_format == (a2)->address_format)&& 		\ 	 ((a1)->address_length == (a2)->address_length)&& 		\ 	 (((((a1)->address_format == T_ATM_ENDSYS_ADDR) ||		\ 	    ((a1)->address_format == T_ATM_NSAP_ADDR))&&		\ 	   (bcmp((caddr_t)(a1)->address, (caddr_t)(a2)->address, 	\ 		(a1)->address_length - 1) == 0)&&			\ 	   ((s1) == ((struct atm_addr_nsap *)(a2)->address)->aan_sel)) || \ 	  (((a1)->address_format != T_ATM_ENDSYS_ADDR)&&		\ 	   ((a1)->address_format != T_ATM_NSAP_ADDR)&&			\ 	   (bcmp((caddr_t)(a1)->address, (caddr_t)(a2)->address, 	\ 		(a1)->address_length) == 0))))
end_define

begin_define
define|#
directive|define
name|ATM_ADDR_COPY
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|{									\ 	(a2)->address_format = (a1)->address_format;			\ 	(a2)->address_length = (a1)->address_length;			\ 	bcopy((caddr_t)(a1)->address, (caddr_t)(a2)->address,		\ 		(a1)->address_length);					\ }
end_define

begin_define
define|#
directive|define
name|ATM_ADDR_SEL_COPY
parameter_list|(
name|a1
parameter_list|,
name|s1
parameter_list|,
name|a2
parameter_list|)
define|\
value|{									\ 	(a2)->address_format = (a1)->address_format;			\ 	(a2)->address_length = (a1)->address_length;			\ 	if (((a1)->address_format == T_ATM_ENDSYS_ADDR) || 		\ 	    ((a1)->address_format == T_ATM_NSAP_ADDR)) {		\ 		bcopy((caddr_t)(a1)->address, (caddr_t)(a2)->address,	\ 			(a1)->address_length - 1);			\ 		((struct atm_addr_nsap *)(a2)->address)->aan_sel = (s1);\ 	} else {							\ 		bcopy((caddr_t)(a1)->address, (caddr_t)(a2)->address,	\ 			(a1)->address_length);				\ 	}								\ }
end_define

begin_comment
comment|/*  * ATM Cell Header definitions  */
end_comment

begin_comment
comment|/*  * These macros assume that the cell header (minus the HEC)  * is contained in the least-significant 32-bits of a word  */
end_comment

begin_define
define|#
directive|define
name|ATM_HDR_SET_VPI
parameter_list|(
name|vpi
parameter_list|)
value|(((vpi)& 0xff)<< 20)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_SET_VCI
parameter_list|(
name|vci
parameter_list|)
value|(((vci)& 0xffff)<< 4)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_SET_PT
parameter_list|(
name|pt
parameter_list|)
value|(((pt)& 0x7)<< 1)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_SET_CLP
parameter_list|(
name|clp
parameter_list|)
value|((clp)& 0x1)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_SET
parameter_list|(
name|vpi
parameter_list|,
name|vci
parameter_list|,
name|pt
parameter_list|,
name|clp
parameter_list|)
value|(ATM_HDR_SET_VPI(vpi) | \ 					ATM_HDR_SET_VCI(vci) | \ 					ATM_HDR_SET_PT(pt) | \ 					ATM_HDR_SET_CLP(clp))
end_define

begin_define
define|#
directive|define
name|ATM_HDR_GET_VPI
parameter_list|(
name|hdr
parameter_list|)
value|(((hdr)>> 20)& 0xff)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_GET_VCI
parameter_list|(
name|hdr
parameter_list|)
value|(((hdr)>> 4)& 0xffff)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_GET_PT
parameter_list|(
name|hdr
parameter_list|)
value|(((hdr)>> 1)& 0x7)
end_define

begin_define
define|#
directive|define
name|ATM_HDR_GET_CLP
parameter_list|(
name|hdr
parameter_list|)
value|((hdr)& 0x1)
end_define

begin_comment
comment|/*  * Payload Type Identifier (3 bits)  */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_USER_SDU0
value|0x0
end_define

begin_comment
comment|/* User, no congestion, sdu type 0 */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_USER_SDU1
value|0x1
end_define

begin_comment
comment|/* User, no congestion, sdu type 1 */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_USER_CONG_SDU0
value|0x2
end_define

begin_comment
comment|/* User, congestion, sdu type 0 */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_USER_CONG_SDU1
value|0x3
end_define

begin_comment
comment|/* User, congestion, sdu type 1 */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_NONUSER
value|0x4
end_define

begin_comment
comment|/* User/non-user differentiator */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_OAMF5_SEG
value|0x4
end_define

begin_comment
comment|/* OAM F5 segment flow */
end_comment

begin_define
define|#
directive|define
name|ATM_PT_OAMF5_E2E
value|0x5
end_define

begin_comment
comment|/* OAM F5 end-to-end flow */
end_comment

begin_comment
comment|/*  * AAL (ATM Adaptation Layer) codes  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|Aal_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATM_AAL0
value|0
end_define

begin_comment
comment|/* AAL0 - Cell service */
end_comment

begin_define
define|#
directive|define
name|ATM_AAL1
value|1
end_define

begin_comment
comment|/* AAL1 */
end_comment

begin_define
define|#
directive|define
name|ATM_AAL2
value|2
end_define

begin_comment
comment|/* AAL2 */
end_comment

begin_define
define|#
directive|define
name|ATM_AAL3_4
value|3
end_define

begin_comment
comment|/* AAL3/4 */
end_comment

begin_define
define|#
directive|define
name|ATM_AAL5
value|5
end_define

begin_comment
comment|/* AAL5 */
end_comment

begin_comment
comment|/*  * VCC Encapsulation codes  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|Encaps_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATM_ENC_NULL
value|1
end_define

begin_comment
comment|/* Null encapsulation */
end_comment

begin_define
define|#
directive|define
name|ATM_ENC_LLC
value|2
end_define

begin_comment
comment|/* LLC encapsulation */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * ATM timer control block.  Used to schedule a timeout via atm_timeout().  * This control block will typically be embedded in a processing-specific  * control block.  */
end_comment

begin_struct
struct|struct
name|atm_time
block|{
name|u_short
name|ti_ticks
decl_stmt|;
comment|/* Delta of ticks until timeout */
name|u_char
name|ti_flag
decl_stmt|;
comment|/* Timer flag bits (see below) */
name|void
function_decl|(
modifier|*
name|ti_func
function_decl|)
comment|/* Call at timeout expiration */
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
name|struct
name|atm_time
modifier|*
name|ti_next
decl_stmt|;
comment|/* Next on queue */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Timer Flags  */
end_comment

begin_define
define|#
directive|define
name|TIF_QUEUED
value|0x01
end_define

begin_comment
comment|/* Control block on timer queue */
end_comment

begin_define
define|#
directive|define
name|ATM_HZ
value|2
end_define

begin_comment
comment|/* Time ticks per second */
end_comment

begin_comment
comment|/*  * Debugging  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|ATM_TIME
define|\
value|struct timeval now, delta;					\ 	KT_TIME(now);							\ 	delta.tv_sec = now.tv_sec - atm_debugtime.tv_sec;		\ 	delta.tv_usec = now.tv_usec - atm_debugtime.tv_usec;		\ 	atm_debugtime = now;						\ 	if (delta.tv_usec< 0) {					\ 		delta.tv_sec--;						\ 		delta.tv_usec += 1000000;				\ 	}								\ 	printf("%3ld.%6ld: ", delta.tv_sec, delta.tv_usec);
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG0
parameter_list|(
name|f
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN0
parameter_list|(
name|f
parameter_list|)
value|if (atm_debug) {printf(f);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG1
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f, a1);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN1
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|)
value|if (atm_debug) {printf(f, a1);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG2
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f, a1, a2);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN2
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|if (atm_debug) {printf(f, a1, a2);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG3
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f, a1, a2, a3);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN3
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|if (atm_debug) {printf(f, a1, a2, a3);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG4
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f, a1, a2, a3, a4);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN4
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
value|if (atm_debug) {printf(f, a1, a2, a3, a4);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG5
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
value|if (atm_debug) {ATM_TIME; printf(f, a1, a2, a3, a4, a5);}
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN5
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
value|if (atm_debug) {printf(f, a1, a2, a3, a4, a5);}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATM_DEBUG0
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN0
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG1
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN1
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG2
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN2
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG3
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN3
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG4
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN4
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUG5
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ATM_DEBUGN5
parameter_list|(
name|f
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* _NETATM_ATM_SYS_H */
end_comment

end_unit

