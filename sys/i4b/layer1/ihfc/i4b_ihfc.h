begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_ihfc.h - ihfc common header file  *	------------------------------------  *  *	last edit-date: [Wed Jul 19 09:40:45 2000]  *  *	$Id: i4b_ihfc.h,v 1.9 2000/09/19 13:50:36 hm Exp $  *  * $FreeBSD$  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IHFC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IHFC_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *	global stuff						(HFC-1/S/SP)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DCH_MAX_LEN
value|264
end_define

begin_comment
comment|/* max length of a D frame */
end_comment

begin_define
define|#
directive|define
name|IHFC_ACTIVATION_TIMEOUT
value|3*hz
end_define

begin_comment
comment|/* S0-bus must activate before this time */
end_comment

begin_define
define|#
directive|define
name|IHFC_IO_BASES
value|1
end_define

begin_define
define|#
directive|define
name|IHFC_DISBUSYTO
value|500
end_define

begin_comment
comment|/* do at least 500 inb's before giving up */
end_comment

begin_define
define|#
directive|define
name|IHFC_NONBUSYTO
value|8000
end_define

begin_comment
comment|/* do at least 8000 inb's before giving up */
end_comment

begin_define
define|#
directive|define
name|IHFC_NTMODE
value|0
end_define

begin_comment
comment|/* use TE-mode as default 	 */
end_comment

begin_define
define|#
directive|define
name|IHFC_DLP
value|0
end_define

begin_comment
comment|/* use (8/9) priority as default */
end_comment

begin_define
define|#
directive|define
name|IHFC_MAXUNIT
value|4
end_define

begin_comment
comment|/* #define IHFC_DEBUG	internal debugging enabled  *  * #undef  IHFC_DEBUG	internal debugging disabled */
end_comment

begin_comment
comment|/* chan:           *  * 0 - D1 (tx)     *  * 1 - D1 (rx)     *  * 2 - B1 (tx)     *  * 3 - B1 (rx)     *  * 4 - B2 (tx)     *  * 5 - B2 (rx)     */
end_comment

begin_define
define|#
directive|define
name|HFC_1
value|0x01
end_define

begin_comment
comment|/* HFC		2B	*/
end_comment

begin_define
define|#
directive|define
name|HFC_S
value|0x02
end_define

begin_comment
comment|/* HFC - S	2BDS0	*/
end_comment

begin_define
define|#
directive|define
name|HFC_SP
value|0x04
end_define

begin_comment
comment|/* HFC - SP	2BDS0	*/
end_comment

begin_define
define|#
directive|define
name|HFC_SPCI
value|0x08
end_define

begin_comment
comment|/* HFC - SPCI	2BDS0 X */
end_comment

begin_define
define|#
directive|define
name|HFC_S2M
value|0x10
end_define

begin_comment
comment|/* HFC - S2M	2BDS0 X */
end_comment

begin_define
define|#
directive|define
name|HFC_USB
value|0x20
end_define

begin_comment
comment|/* HFC - USB	2BDS0 X */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	"Help Fix Corruption" macros				(HFC-1/S/SP)  *  *	NOTE: If the code does not run at splhigh, we will sporadically  *	lose bytes. On fast PC's (200 Mhz), this is very little noticable.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|HFC_VAR
value|int _s_
end_define

begin_comment
comment|/* declare variable	*/
end_comment

begin_define
define|#
directive|define
name|HFC_BEG
value|_s_ = splhigh()
end_define

begin_comment
comment|/* save spl		*/
end_comment

begin_define
define|#
directive|define
name|HFC_END
value|splx(_s_)
end_define

begin_comment
comment|/* restore spl		*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	macros related to i4b linking				(HFC-1/S/SP)  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|S_BLINK
value|sc->sc_blinktab[(chan> 3) ? 1 : 0]
end_define

begin_define
define|#
directive|define
name|S_BDRVLINK
value|sc->sc_bdrvlinktab[(chan> 3) ? 1 : 0]
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	macros related to ihfc_sc				(HFC-1/S/SP)  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* statemachine */
end_comment

begin_define
define|#
directive|define
name|S_IOM2
value|(sc->sc_config.i_adf2& 0x80)
end_define

begin_comment
comment|/* 0x80: IOM2 mode selected */
end_comment

begin_define
define|#
directive|define
name|S_DLP
value|(sc->sc_config.dlp)
end_define

begin_define
define|#
directive|define
name|S_NTMODE
value|(sc->sc_config.ntmode)
end_define

begin_define
define|#
directive|define
name|S_STDEL
value|(sc->sc_config.stdel)
end_define

begin_define
define|#
directive|define
name|S_PHSTATE
value|sc->sc_statemachine.state
end_define

begin_define
define|#
directive|define
name|S_STM_T3
value|sc->sc_statemachine.T3
end_define

begin_define
define|#
directive|define
name|S_STM_T3CALLOUT
value|sc->sc_statemachine.T3callout
end_define

begin_comment
comment|/* unitnumbers */
end_comment

begin_define
define|#
directive|define
name|S_UNIT
value|sc->sc_unit
end_define

begin_define
define|#
directive|define
name|S_FLAG
value|sc->sc_flag
end_define

begin_define
define|#
directive|define
name|S_I4BUNIT
value|sc->sc_i4bunit
end_define

begin_define
define|#
directive|define
name|S_I4BFLAG
value|sc->sc_i4bflag
end_define

begin_comment
comment|/* ISA bus setup */
end_comment

begin_define
define|#
directive|define
name|S_IOBASE
value|sc->sc_resources.io_base
end_define

begin_define
define|#
directive|define
name|S_IORID
value|sc->sc_resources.io_rid
end_define

begin_define
define|#
directive|define
name|S_IRQ
value|sc->sc_resources.irq
end_define

begin_define
define|#
directive|define
name|S_IRQRID
value|sc->sc_resources.irq_rid
end_define

begin_comment
comment|/* hardware setup */
end_comment

begin_define
define|#
directive|define
name|S_HFC
value|sc->sc_config.chiptype
end_define

begin_define
define|#
directive|define
name|S_IIO
value|sc->sc_config.iio
end_define

begin_define
define|#
directive|define
name|S_IIRQ
value|sc->sc_config.iirq
end_define

begin_comment
comment|/* registers of the HFC-S/SP	(write only) */
end_comment

begin_define
define|#
directive|define
name|S_HFC_CONFIG
value|sc->sc_config.cirm
end_define

begin_define
define|#
directive|define
name|S_CIRM
value|sc->sc_config.cirm
end_define

begin_define
define|#
directive|define
name|S_CTMT
value|sc->sc_config.ctmt
end_define

begin_define
define|#
directive|define
name|S_TEST
value|sc->sc_config.test
end_define

begin_define
define|#
directive|define
name|S_SCTRL
value|sc->sc_config.sctrl
end_define

begin_define
define|#
directive|define
name|S_CLKDEL
value|sc->sc_config.clkdel
end_define

begin_define
define|#
directive|define
name|S_INT_M1
value|sc->sc_config.int_m1
end_define

begin_define
define|#
directive|define
name|S_INT_M2
value|sc->sc_config.int_m2
end_define

begin_define
define|#
directive|define
name|S_CONNECT
value|sc->sc_config.connect
end_define

begin_define
define|#
directive|define
name|S_SCTRL_R
value|sc->sc_config.sctrl_r
end_define

begin_define
define|#
directive|define
name|S_MST_MODE
value|sc->sc_config.mst_mode
end_define

begin_comment
comment|/* registers of the HFC-S/SP 	(read only) */
end_comment

begin_define
define|#
directive|define
name|S_INT_S1
value|sc->sc_config.int_s1
end_define

begin_comment
comment|/* registers of the ISAC 	(write only) */
end_comment

begin_define
define|#
directive|define
name|S_ISAC_CONFIG
value|sc->sc_config.i_adf2
end_define

begin_define
define|#
directive|define
name|S_ADF1
value|sc->sc_config.i_adf1
end_define

begin_define
define|#
directive|define
name|S_ADF2
value|sc->sc_config.i_adf2
end_define

begin_define
define|#
directive|define
name|S_MASK
value|sc->sc_config.i_mask
end_define

begin_define
define|#
directive|define
name|S_MODE
value|sc->sc_config.i_mode
end_define

begin_define
define|#
directive|define
name|S_SPCR
value|sc->sc_config.i_spcr
end_define

begin_define
define|#
directive|define
name|S_SQXR
value|sc->sc_config.i_sqxr
end_define

begin_define
define|#
directive|define
name|S_STCR
value|sc->sc_config.i_stcr
end_define

begin_define
define|#
directive|define
name|S_STAR2
value|sc->sc_config.i_star2
end_define

begin_comment
comment|/* registers of the ISAC 	(read only) */
end_comment

begin_define
define|#
directive|define
name|S_ISTA
value|sc->sc_config.i_ista
end_define

begin_comment
comment|/* state of the softc */
end_comment

begin_define
define|#
directive|define
name|S_ENABLED
value|sc->sc_enabled
end_define

begin_define
define|#
directive|define
name|S_INTR_ACTIVE
value|sc->sc_intr_active
end_define

begin_comment
comment|/* SOFT-HDLC */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_IB
value|sc->sc_fifo.chan[chan].hdlc.ib
end_define

begin_comment
comment|/* u_short */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_CRC
value|sc->sc_fifo.chan[chan].hdlc.crc
end_define

begin_comment
comment|/* u_short */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_TMP
value|sc->sc_fifo.chan[chan].hdlc.tmp
end_define

begin_comment
comment|/* u_int   */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_FLAG
value|sc->sc_fifo.chan[chan].hdlc.flag
end_define

begin_comment
comment|/* u_char  */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_BLEVEL
value|sc->sc_fifo.chan[chan].hdlc.blevel
end_define

begin_comment
comment|/* u_short */
end_comment

begin_comment
comment|/* stats */
end_comment

begin_define
define|#
directive|define
name|S_BYTES
value|sc->sc_fifo.chan[chan].bytes
end_define

begin_comment
comment|/* "Z"-values */
end_comment

begin_define
define|#
directive|define
name|S_HDLC_DZ_TAB
value|sc->sc_fifo.dztable
end_define

begin_comment
comment|/* filters */
end_comment

begin_define
define|#
directive|define
name|S_PROT
value|sc->sc_fifo.chan[chan].prot
end_define

begin_define
define|#
directive|define
name|S_FILTER
value|sc->sc_fifo.chan[chan].filter
end_define

begin_define
define|#
directive|define
name|S_ACTIVITY
value|sc->sc_fifo.chan[chan].activity
end_define

begin_define
define|#
directive|define
name|S_LAST_CHAN
value|sc->sc_fifo.last_chan
end_define

begin_comment
comment|/* soft reset */
end_comment

begin_define
define|#
directive|define
name|RESET_SOFT_CHAN
parameter_list|(
name|sc
parameter_list|,
name|chan
parameter_list|)
value|bzero(&sc->sc_fifo.chan[chan], sizeof(sc->sc_fifo.chan[0]))
end_define

begin_comment
comment|/* trace */
end_comment

begin_define
define|#
directive|define
name|S_TRACE
value|sc->sc_trace
end_define

begin_define
define|#
directive|define
name|S_DTRACECOUNT
value|sc->sc_Dtracecount
end_define

begin_define
define|#
directive|define
name|S_BTRACECOUNT
value|sc->sc_Btracecount
end_define

begin_comment
comment|/* mbuf */
end_comment

begin_define
define|#
directive|define
name|S_MBUF
value|sc->sc_fifo.chan[chan].buffer.mbuf
end_define

begin_define
define|#
directive|define
name|S_MBUFDUMMY
value|sc->sc_fifo.chan[chan].buffer.mbufdummy
end_define

begin_define
define|#
directive|define
name|S_MBUFLEN
value|sc->sc_fifo.chan[chan].buffer.mbuf->m_len
end_define

begin_define
define|#
directive|define
name|S_MBUFPKTHDR
value|sc->sc_fifo.chan[chan].buffer.mbuf->m_pkthdr
end_define

begin_define
define|#
directive|define
name|S_MBUFDATA
value|sc->sc_fifo.chan[chan].buffer.mbuf->m_data
end_define

begin_define
define|#
directive|define
name|S_MBUFDAT
value|sc->sc_fifo.chan[chan].buffer.mbuf->m_dat
end_define

begin_define
define|#
directive|define
name|S_IFQUEUE
value|sc->sc_fifo.chan[chan].buffer.ifqueue
end_define

begin_comment
comment|/* hfc control */
end_comment

begin_define
define|#
directive|define
name|HFC_INIT
value|ihfc_init
end_define

begin_define
define|#
directive|define
name|HFC_INTR
value|((S_HFC& HFC_1) ? ihfc_intr1 : ihfc_intr2)
end_define

begin_define
define|#
directive|define
name|HFC_FSM
value|ihfc_fsm
end_define

begin_define
define|#
directive|define
name|HFC_CONTROL
value|ihfc_control
end_define

begin_comment
comment|/* softc parts */
end_comment

begin_struct_decl
struct_decl|struct
name|ihfc_sc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sc_resources
block|{
name|struct
name|resource
modifier|*
name|io_base
index|[
name|IHFC_IO_BASES
index|]
decl_stmt|;
name|int
name|io_rid
index|[
name|IHFC_IO_BASES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdlc
block|{
name|u_char
name|flag
decl_stmt|;
name|u_short
name|blevel
decl_stmt|;
name|u_short
name|crc
decl_stmt|;
name|u_short
name|ib
decl_stmt|;
name|u_int
name|tmp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buffer
block|{
name|struct
name|ifqueue
name|ifqueue
decl_stmt|;
comment|/* data queue	*/
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* current mbuf	*/
name|struct
name|mbuf
modifier|*
name|mbufdummy
decl_stmt|;
comment|/* temporary	*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chan
block|{
name|struct
name|hdlc
name|hdlc
decl_stmt|;
name|u_int
name|bytes
decl_stmt|;
name|u_int
name|prot
decl_stmt|;
name|struct
name|buffer
name|buffer
decl_stmt|;
name|void
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
name|struct
name|ihfc_sc
modifier|*
name|sc
parameter_list|,
name|u_char
name|chan
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sc_fifo
block|{
name|struct
name|chan
name|chan
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|dztable
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|last_chan
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sc_config
block|{
comment|/* software only: */
name|u_short
name|chiptype
decl_stmt|;
comment|/* chiptype (eg. HFC_1)	*/
name|u_char
name|dlp
decl_stmt|;
comment|/* D-priority		*/
name|u_short
name|iio
decl_stmt|;
comment|/* internal IO		*/
name|u_char
name|iirq
decl_stmt|;
comment|/* internal IRQ		*/
name|u_char
name|ntmode
decl_stmt|;
comment|/* mode 		*/
name|u_char
name|stdel
decl_stmt|;
comment|/* S/T delay		*/
comment|/* write only: */
name|u_char
name|cirm
decl_stmt|;
name|u_char
name|ctmt
decl_stmt|;
name|u_char
name|int_m1
decl_stmt|;
name|u_char
name|int_m2
decl_stmt|;
name|u_char
name|mst_mode
decl_stmt|;
name|u_char
name|clkdel
decl_stmt|;
name|u_char
name|sctrl
decl_stmt|;
name|u_char
name|connect
decl_stmt|;
name|u_char
name|test
decl_stmt|;
name|u_char
name|sctrl_r
decl_stmt|;
comment|/* isac write only - hfc-1: */
name|u_char
name|i_adf2
decl_stmt|;
name|u_char
name|i_spcr
decl_stmt|;
name|u_char
name|i_sqxr
decl_stmt|;
name|u_char
name|i_adf1
decl_stmt|;
name|u_char
name|i_stcr
decl_stmt|;
name|u_char
name|i_mode
decl_stmt|;
name|u_char
name|i_mask
decl_stmt|;
name|u_char
name|i_star2
decl_stmt|;
comment|/* read only: */
name|u_char
name|int_s1
decl_stmt|;
comment|/* isac read only - hfc-1: */
name|u_char
name|i_ista
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sc_statemachine
block|{
name|u_char
name|state
decl_stmt|;
comment|/* see i4b_ihfc_drv.h */
name|u_char
name|usync
decl_stmt|;
name|u_char
name|T3
decl_stmt|;
comment|/* T3 running 	      */
name|struct
name|callout_handle
name|T3callout
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	HFC softc  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ihfc_sc
block|{
name|int
name|sc_unit
decl_stmt|;
name|int
name|sc_flag
decl_stmt|;
name|int
name|sc_i4bunit
decl_stmt|;
comment|/* L0IHFCUNIT(sc_unit)	 */
name|int
name|sc_i4bflag
decl_stmt|;
comment|/* FLAG_TEL_S0_16_3C ..	 */
name|u_char
name|sc_enabled
decl_stmt|;
comment|/* daemon running if set */
name|u_char
name|sc_intr_active
decl_stmt|;
comment|/* interrupt is active	 */
name|int
name|sc_trace
decl_stmt|;
name|u_int
name|sc_Btracecount
decl_stmt|;
name|u_int
name|sc_Dtracecount
decl_stmt|;
name|struct
name|sc_config
name|sc_config
decl_stmt|;
name|struct
name|sc_resources
name|sc_resources
decl_stmt|;
name|struct
name|sc_statemachine
name|sc_statemachine
decl_stmt|;
name|isdn_link_t
name|sc_blinktab
index|[
literal|2
index|]
decl_stmt|;
name|drvr_link_t
modifier|*
name|sc_bdrvlinktab
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|sc_fifo
name|sc_fifo
decl_stmt|;
block|}
name|ihfc_sc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ihfc_sc_t
name|ihfc_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IHFC_H_ */
end_comment

end_unit

