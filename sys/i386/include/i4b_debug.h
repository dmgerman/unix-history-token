begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_debug.h - i4b debug header file  *	-----------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Mon May 21 10:05:34 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|DO_I4B_DEBUG
end_if

begin_define
define|#
directive|define
name|DO_I4B_DEBUG
value|1
end_define

begin_comment
comment|/* default = include debugging code */
end_comment

begin_elif
elif|#
directive|elif
name|DO_I4B_DEBUG
operator|!=
literal|0
end_elif

begin_undef
undef|#
directive|undef
name|DO_I4B_DEBUG
end_undef

begin_define
define|#
directive|define
name|DO_I4B_DEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|DO_I4B_MAXDEBUG
end_undef

begin_comment
comment|/* default = disable ALL debug messages */
end_comment

begin_if
if|#
directive|if
name|DO_I4B_DEBUG
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|i4b_l1_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|i4b_l2_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|i4b_l3_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|i4b_l4_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NDBGL1
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if(bits& i4b_l1_debug)						\ 	{ printf("i4b-L1 %s: " fmt "\n", __FUNCTION__ , ##args ); }
end_define

begin_define
define|#
directive|define
name|NDBGL2
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if(bits& i4b_l2_debug)						\ 	{ printf("i4b-L2 %s: " fmt "\n", __FUNCTION__ , ##args ); }
end_define

begin_define
define|#
directive|define
name|NDBGL3
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if(bits& i4b_l3_debug)						\ 	{ printf("i4b-L3 %s: " fmt "\n", __FUNCTION__ , ##args ); }
end_define

begin_define
define|#
directive|define
name|NDBGL4
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if(bits& i4b_l4_debug)						\ 	{ printf("i4b-L4 %s: " fmt "\n", __FUNCTION__ , ##args ); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DO_I4B_DEBUG */
end_comment

begin_define
define|#
directive|define
name|NDBGL1
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|NDBGL2
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|NDBGL3
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|;
end_define

begin_define
define|#
directive|define
name|NDBGL4
parameter_list|(
name|bits
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DO_I4B_DEBUG */
end_comment

begin_comment
comment|/* Layer 1 */
end_comment

begin_define
define|#
directive|define
name|L1_ERROR
value|0x000001
end_define

begin_comment
comment|/* general error message*/
end_comment

begin_define
define|#
directive|define
name|L1_PRIM
value|0x000002
end_define

begin_comment
comment|/* interlayer primitives*/
end_comment

begin_define
define|#
directive|define
name|L1_BCHAN
value|0x000004
end_define

begin_comment
comment|/* B channel action	*/
end_comment

begin_define
define|#
directive|define
name|L1_H_ERR
value|0x000008
end_define

begin_comment
comment|/* HSCX errors		*/
end_comment

begin_define
define|#
directive|define
name|L1_H_IRQ
value|0x000010
end_define

begin_comment
comment|/* HSCX IRQ messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_I_ERR
value|0x000020
end_define

begin_comment
comment|/* ISAC errors		*/
end_comment

begin_define
define|#
directive|define
name|L1_I_MSG
value|0x000040
end_define

begin_comment
comment|/* ISAC messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_I_SETUP
value|0x000080
end_define

begin_comment
comment|/* ISAC setup messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_F_MSG
value|0x000100
end_define

begin_comment
comment|/* FSM messages		*/
end_comment

begin_define
define|#
directive|define
name|L1_F_ERR
value|0x000200
end_define

begin_comment
comment|/* FSM error messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_T_MSG
value|0x000400
end_define

begin_comment
comment|/* Timer messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_T_ERR
value|0x000800
end_define

begin_comment
comment|/* Timer error messages	*/
end_comment

begin_define
define|#
directive|define
name|L1_H_XFRERR
value|0x001000
end_define

begin_comment
comment|/* HSCX data xfer error */
end_comment

begin_define
define|#
directive|define
name|L1_I_CICO
value|0x002000
end_define

begin_comment
comment|/* ISAC command in/out	*/
end_comment

begin_define
define|#
directive|define
name|L1_S_MSG
value|0x004000
end_define

begin_comment
comment|/* silent messages (soft-HDLC)	*/
end_comment

begin_define
define|#
directive|define
name|L1_S_ERR
value|0x008000
end_define

begin_comment
comment|/* error messages (soft-HDLC)	*/
end_comment

begin_define
define|#
directive|define
name|L1_HFC_DBG
value|0x010000
end_define

begin_comment
comment|/* HFC-S PCI messages */
end_comment

begin_define
define|#
directive|define
name|L1_DEBUG_MAX
value|0x01ffef
end_define

begin_comment
comment|/* all messages on except IRQ!	*/
end_comment

begin_define
define|#
directive|define
name|L1_DEBUG_ERR
value|(L1_S_ERR | L1_H_ERR | L1_I_ERR | L1_F_ERR | L1_T_ERR | L1_ERROR)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|L1_DEBUG_DEFAULT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DO_I4B_MAXDEBUG
end_ifdef

begin_define
define|#
directive|define
name|L1_DEBUG_DEFAULT
value|L1_DEBUG_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L1_DEBUG_DEFAULT
value|L1_DEBUG_ERR
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
comment|/* Layer 2 */
end_comment

begin_define
define|#
directive|define
name|L2_ERROR
value|0x0001
end_define

begin_comment
comment|/* general error message	*/
end_comment

begin_define
define|#
directive|define
name|L2_PRIM
value|0x0002
end_define

begin_comment
comment|/* interlayer primitives	*/
end_comment

begin_define
define|#
directive|define
name|L2_U_MSG
value|0x0004
end_define

begin_comment
comment|/* U frame messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_U_ERR
value|0x0008
end_define

begin_comment
comment|/* U frame error messages	*/
end_comment

begin_define
define|#
directive|define
name|L2_S_MSG
value|0x0010
end_define

begin_comment
comment|/* S frame messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_S_ERR
value|0x0020
end_define

begin_comment
comment|/* S frame error messages	*/
end_comment

begin_define
define|#
directive|define
name|L2_I_MSG
value|0x0040
end_define

begin_comment
comment|/* I frame messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_I_ERR
value|0x0080
end_define

begin_comment
comment|/* I frame error messages	*/
end_comment

begin_define
define|#
directive|define
name|L2_F_MSG
value|0x0100
end_define

begin_comment
comment|/* FSM messages			*/
end_comment

begin_define
define|#
directive|define
name|L2_F_ERR
value|0x0200
end_define

begin_comment
comment|/* FSM error messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_T_MSG
value|0x0400
end_define

begin_comment
comment|/* timer messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_T_ERR
value|0x0800
end_define

begin_comment
comment|/* timer error messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_TEI_MSG
value|0x1000
end_define

begin_comment
comment|/* TEI messages			*/
end_comment

begin_define
define|#
directive|define
name|L2_TEI_ERR
value|0x2000
end_define

begin_comment
comment|/* TEI error messages		*/
end_comment

begin_define
define|#
directive|define
name|L2_DEBUG_MAX
value|0x3fff
end_define

begin_comment
comment|/* all messages on		*/
end_comment

begin_define
define|#
directive|define
name|L2_DEBUG_ERR
value|(L2_ERROR | L2_I_ERR | L2_F_ERR | L2_T_ERR | L2_S_ERR | L2_TEI_ERR | L2_U_ERR )
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|L2_DEBUG_DEFAULT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DO_I4B_MAXDEBUG
end_ifdef

begin_define
define|#
directive|define
name|L2_DEBUG_DEFAULT
value|L2_DEBUG_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L2_DEBUG_DEFAULT
value|L2_DEBUG_ERR
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
comment|/* Layer 3 */
end_comment

begin_define
define|#
directive|define
name|L3_ERR
value|0x0001
end_define

begin_comment
comment|/* general error message	*/
end_comment

begin_define
define|#
directive|define
name|L3_MSG
value|0x0002
end_define

begin_comment
comment|/* general message		*/
end_comment

begin_define
define|#
directive|define
name|L3_F_MSG
value|0x0004
end_define

begin_comment
comment|/* FSM messages			*/
end_comment

begin_define
define|#
directive|define
name|L3_F_ERR
value|0x0008
end_define

begin_comment
comment|/* FSM error messages		*/
end_comment

begin_define
define|#
directive|define
name|L3_T_MSG
value|0x0010
end_define

begin_comment
comment|/* timer messages		*/
end_comment

begin_define
define|#
directive|define
name|L3_T_ERR
value|0x0020
end_define

begin_comment
comment|/* timer error messages		*/
end_comment

begin_define
define|#
directive|define
name|L3_P_MSG
value|0x0040
end_define

begin_comment
comment|/* protocol messages		*/
end_comment

begin_define
define|#
directive|define
name|L3_P_ERR
value|0x0080
end_define

begin_comment
comment|/* protocol error messages	*/
end_comment

begin_define
define|#
directive|define
name|L3_A_MSG
value|0x0100
end_define

begin_comment
comment|/* AOC messages			*/
end_comment

begin_define
define|#
directive|define
name|L3_A_ERR
value|0x0200
end_define

begin_comment
comment|/* AOC error messages		*/
end_comment

begin_define
define|#
directive|define
name|L3_PRIM
value|0x0400
end_define

begin_comment
comment|/* messages exchanged		*/
end_comment

begin_define
define|#
directive|define
name|L3_DEBUG_MAX
value|0x07ff
end_define

begin_comment
comment|/* all messages on	*/
end_comment

begin_define
define|#
directive|define
name|L3_DEBUG_ERR
value|(L3_ERR | L3_F_ERR | L3_T_ERR | L3_P_ERR | L3_A_ERR)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|L3_DEBUG_DEFAULT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DO_I4B_MAXDEBUG
end_ifdef

begin_define
define|#
directive|define
name|L3_DEBUG_DEFAULT
value|L3_DEBUG_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L3_DEBUG_DEFAULT
value|L3_DEBUG_ERR
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
comment|/* Layer 4 */
end_comment

begin_define
define|#
directive|define
name|L4_ERR
value|0x0001
end_define

begin_comment
comment|/* general error message	*/
end_comment

begin_define
define|#
directive|define
name|L4_MSG
value|0x0002
end_define

begin_comment
comment|/* general message		*/
end_comment

begin_define
define|#
directive|define
name|L4_TIMO
value|0x0004
end_define

begin_comment
comment|/* b channel idle timeout msgs	*/
end_comment

begin_define
define|#
directive|define
name|L4_DIALST
value|0x0008
end_define

begin_comment
comment|/* network driver dial states	*/
end_comment

begin_define
define|#
directive|define
name|L4_IPRDBG
value|0x0010
end_define

begin_comment
comment|/* ipr driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_RBCHDBG
value|0x0020
end_define

begin_comment
comment|/* rbch driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_ISPDBG
value|0x0040
end_define

begin_comment
comment|/* isp driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_TELDBG
value|0x0080
end_define

begin_comment
comment|/* tel driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_INGDBG
value|0x0100
end_define

begin_comment
comment|/* ing driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_IAVCDBG
value|0x0200
end_define

begin_comment
comment|/* AVM B1 driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_CAPIDBG
value|0x0400
end_define

begin_comment
comment|/* CAPI driver debug messages	*/
end_comment

begin_define
define|#
directive|define
name|L4_DEBUG_MAX
value|0x0fff
end_define

begin_comment
comment|/* all messages on	*/
end_comment

begin_define
define|#
directive|define
name|L4_DEBUG_ERR
value|L4_ERR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|L4_DEBUG_DEFAULT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DO_I4B_MAXDEBUG
end_ifdef

begin_define
define|#
directive|define
name|L4_DEBUG_DEFAULT
value|L4_DEBUG_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L4_DEBUG_DEFAULT
value|L4_DEBUG_ERR
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
comment|/*---------------------------------------------------------------------------*  * 	ioctl via /dev/i4bctl:  *	get/set current debug bits settings  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|l1
decl_stmt|;
name|unsigned
name|int
name|l2
decl_stmt|;
name|unsigned
name|int
name|l3
decl_stmt|;
name|unsigned
name|int
name|l4
decl_stmt|;
block|}
name|ctl_debug_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CTL_GET_DEBUG
value|_IOR('C', 0, ctl_debug_t)
end_define

begin_define
define|#
directive|define
name|I4B_CTL_SET_DEBUG
value|_IOW('C', 1, ctl_debug_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	generic get chipset statistics  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* for the ihfc-driver: structure for HFC-1/S/SP statistics */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|txframes
decl_stmt|;
name|int
name|rxframes
decl_stmt|;
name|int
name|xdu
decl_stmt|;
name|int
name|rdo
decl_stmt|;
name|int
name|crc
decl_stmt|;
name|int
name|rab
decl_stmt|;
block|}
name|hfcstat_t
typedef|;
end_typedef

begin_comment
comment|/* for the isic-driver: structure for HSCX statistics */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* controller number */
name|int
name|chan
decl_stmt|;
comment|/* channel number */
name|int
name|vfr
decl_stmt|;
name|int
name|rdo
decl_stmt|;
name|int
name|crc
decl_stmt|;
name|int
name|rab
decl_stmt|;
name|int
name|xdu
decl_stmt|;
name|int
name|rfo
decl_stmt|;
block|}
name|hscxstat_t
typedef|;
end_typedef

begin_comment
comment|/* generic statistics structure */
end_comment

begin_struct
struct|struct
name|chipstat
block|{
name|int
name|driver_type
decl_stmt|;
comment|/* type, L1DRVR_XXXX		*/
name|int
name|driver_unit
decl_stmt|;
comment|/* the unit number		*/
name|int
name|driver_bchannel
decl_stmt|;
comment|/* the B-channel		*/
union|union
name|stats
block|{
comment|/* union for all drivers	*/
name|hfcstat_t
name|hfcstat
decl_stmt|;
comment|/* for ihfc driver, L1DRVR_IHFC	*/
name|hscxstat_t
name|hscxstat
decl_stmt|;
comment|/* for isic driver, L1DRVR_ISIC	*/
block|}
name|stats
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* get statistics */
end_comment

begin_define
define|#
directive|define
name|I4B_CTL_GET_CHIPSTAT
value|_IOWR('C', 2, struct chipstat)
end_define

begin_comment
comment|/* clear statistics */
end_comment

begin_define
define|#
directive|define
name|I4B_CTL_CLR_CHIPSTAT
value|_IOW('C', 3, struct chipstat)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	get LAPD/Q.921 statistics  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* transmit */
name|u_long
name|tx_i
decl_stmt|;
comment|/* I 	*/
name|u_long
name|tx_rr
decl_stmt|;
comment|/* RR	*/
name|u_long
name|tx_rnr
decl_stmt|;
comment|/* RNR 	*/
name|u_long
name|tx_rej
decl_stmt|;
comment|/* REJ	*/
name|u_long
name|tx_sabme
decl_stmt|;
comment|/* SABME*/
name|u_long
name|tx_dm
decl_stmt|;
comment|/* DM	*/
name|u_long
name|tx_disc
decl_stmt|;
comment|/* DISC */
name|u_long
name|tx_ua
decl_stmt|;
comment|/* UA	*/
name|u_long
name|tx_frmr
decl_stmt|;
comment|/* FRMR	*/
name|u_long
name|tx_tei
decl_stmt|;
comment|/* TEI	*/
comment|/* receive */
name|u_long
name|rx_i
decl_stmt|;
comment|/* I    */
name|u_long
name|rx_rr
decl_stmt|;
comment|/* RR   */
name|u_long
name|rx_rnr
decl_stmt|;
comment|/* RNR  */
name|u_long
name|rx_rej
decl_stmt|;
comment|/* REJ  */
name|u_long
name|rx_sabme
decl_stmt|;
comment|/* SABME*/
name|u_long
name|rx_tei
decl_stmt|;
comment|/* TEI	*/
name|u_long
name|rx_ui
decl_stmt|;
comment|/* UI	*/
name|u_long
name|rx_disc
decl_stmt|;
comment|/* DISC */
name|u_long
name|rx_xid
decl_stmt|;
comment|/* XID	*/
name|u_long
name|rx_dm
decl_stmt|;
comment|/* DM	*/
name|u_long
name|rx_ua
decl_stmt|;
comment|/* UA	*/
name|u_long
name|rx_frmr
decl_stmt|;
comment|/* FRMR	*/
comment|/* errors */
name|u_long
name|err_rx_len
decl_stmt|;
comment|/* incorrect length */
name|u_long
name|err_rx_badf
decl_stmt|;
comment|/* bad frame type */
name|u_long
name|err_rx_bads
decl_stmt|;
comment|/* bad s frame */
name|u_long
name|err_rx_badu
decl_stmt|;
comment|/* bad u frame */
name|u_long
name|err_rx_badui
decl_stmt|;
comment|/* bad ui frame */
block|}
name|lapdstat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
name|lapdstat_t
name|lapdstat
decl_stmt|;
block|}
name|l2stat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CTL_GET_LAPDSTAT
value|_IOWR('C', 4, l2stat_t)
end_define

begin_define
define|#
directive|define
name|I4B_CTL_CLR_LAPDSTAT
value|_IOW('C', 5, int)
end_define

begin_comment
comment|/* EOF */
end_comment

end_unit

