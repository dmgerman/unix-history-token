begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------*  *  *	i4b_l1.h - isdn4bsd layer 1 header file  *	---------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Fri Jan 26 13:55:12 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_ISIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_ISIC_H_
end_define

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/resource.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/isic/i4b_isic_ext.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------  *      isic driver: max no of units  *      Teles/Creatix/Neuhaus cards have a hardware limitation  *      as one is able to set 3 (sometimes 4) different configurations by  *      jumpers so a maximum of 3 (4) cards per ISA bus is possible.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|ISIC_MAXUNIT
value|3
end_define

begin_comment
comment|/* max no of supported units 0..3 */
end_comment

begin_define
define|#
directive|define
name|INFO_IO_BASES
value|50
end_define

begin_comment
comment|/* 49 needed for USR */
end_comment

begin_struct
struct|struct
name|i4b_info
block|{
name|struct
name|resource
modifier|*
name|io_base
index|[
name|INFO_IO_BASES
index|]
decl_stmt|;
name|int
name|io_rid
index|[
name|INFO_IO_BASES
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
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	l1_bchan_state: the state of one B channel  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* cards unit number	*/
name|int
name|channel
decl_stmt|;
comment|/* which channel is this*/
name|caddr_t
name|hscx
decl_stmt|;
comment|/* HSCX address		*/
name|u_char
name|hscx_mask
decl_stmt|;
comment|/* HSCX interrupt mask	*/
name|int
name|bprot
decl_stmt|;
comment|/* B channel protocol	*/
name|int
name|state
decl_stmt|;
comment|/* this channels state	*/
define|#
directive|define
name|HSCX_IDLE
value|0x00
comment|/* channel idle 	*/
define|#
directive|define
name|HSCX_TX_ACTIVE
value|0x01
comment|/* tx running		*/
comment|/* receive data from ISDN */
name|struct
name|ifqueue
name|rx_queue
decl_stmt|;
comment|/* receiver queue	*/
name|int
name|rxcount
decl_stmt|;
comment|/* rx statistics counter*/
name|struct
name|mbuf
modifier|*
name|in_mbuf
decl_stmt|;
comment|/* rx input buffer	*/
name|u_char
modifier|*
name|in_cbptr
decl_stmt|;
comment|/* curr buffer pointer	*/
name|int
name|in_len
decl_stmt|;
comment|/* rx input buffer len	*/
comment|/* transmit data to ISDN */
name|struct
name|ifqueue
name|tx_queue
decl_stmt|;
comment|/* transmitter queue	*/
name|int
name|txcount
decl_stmt|;
comment|/* tx statistics counter*/
name|struct
name|mbuf
modifier|*
name|out_mbuf_head
decl_stmt|;
comment|/* first mbuf in possible chain	*/
name|struct
name|mbuf
modifier|*
name|out_mbuf_cur
decl_stmt|;
comment|/* current mbuf in possbl chain */
name|unsigned
name|char
modifier|*
name|out_mbuf_cur_ptr
decl_stmt|;
comment|/* data pointer into mbuf	*/
name|int
name|out_mbuf_cur_len
decl_stmt|;
comment|/* remaining bytes in mbuf	*/
comment|/* link between b channel and driver */
name|isdn_link_t
name|isic_isdn_linktab
decl_stmt|;
comment|/* b channel addresses	*/
name|drvr_link_t
modifier|*
name|isic_drvr_linktab
decl_stmt|;
comment|/* ptr to driver linktab*/
comment|/* statistics */
comment|/* RSTA */
name|int
name|stat_VFR
decl_stmt|;
comment|/* HSCX RSTA Valid FRame */
name|int
name|stat_RDO
decl_stmt|;
comment|/* HSCX RSTA Rx Data Overflow */
name|int
name|stat_CRC
decl_stmt|;
comment|/* HSCX RSTA CRC */
name|int
name|stat_RAB
decl_stmt|;
comment|/* HSCX RSTA Rx message ABorted */
comment|/* EXIR */
name|int
name|stat_XDU
decl_stmt|;
comment|/* HSCX EXIR tx data underrun */
name|int
name|stat_RFO
decl_stmt|;
comment|/* HSCX EXIR rx frame overflow */
block|}
name|l1_bchan_state_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	l1_softc: the state of the layer 1 of the D channel  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|l1_softc
block|{
name|int
name|sc_unit
decl_stmt|;
comment|/* unit number		*/
name|int
name|sc_irq
decl_stmt|;
comment|/* interrupt vector	*/
name|struct
name|i4b_info
name|sc_resources
decl_stmt|;
name|int
name|sc_port
decl_stmt|;
comment|/* port base address	*/
name|int
name|sc_cardtyp
decl_stmt|;
comment|/* CARD_TYPEP_xxxx	*/
name|int
name|sc_bustyp
decl_stmt|;
comment|/* IOM1 or IOM2		*/
define|#
directive|define
name|BUS_TYPE_IOM1
value|0x01
define|#
directive|define
name|BUS_TYPE_IOM2
value|0x02
name|int
name|sc_trace
decl_stmt|;
comment|/* output protocol data for tracing */
name|unsigned
name|int
name|sc_trace_dcount
decl_stmt|;
comment|/* d channel trace frame counter */
name|unsigned
name|int
name|sc_trace_bcount
decl_stmt|;
comment|/* b channel trace frame counter */
name|int
name|sc_state
decl_stmt|;
comment|/* ISAC state flag	*/
define|#
directive|define
name|ISAC_IDLE
value|0x00
comment|/* state = idle */
define|#
directive|define
name|ISAC_TX_ACTIVE
value|0x01
comment|/* state = transmitter active */
name|int
name|sc_init_tries
decl_stmt|;
comment|/* no of out tries to access S0 */
name|caddr_t
name|sc_vmem_addr
decl_stmt|;
comment|/* card RAM virtual memory base */
name|caddr_t
name|sc_isac
decl_stmt|;
comment|/* ISAC port base addr	*/
define|#
directive|define
name|ISAC_BASE
value|(sc->sc_isac)
name|caddr_t
name|sc_ipacbase
decl_stmt|;
comment|/* IPAC port base addr	*/
define|#
directive|define
name|IPAC_BASE
value|(sc->sc_ipacbase)
name|u_char
name|sc_isac_mask
decl_stmt|;
comment|/* ISAC IRQ mask	*/
define|#
directive|define
name|ISAC_IMASK
value|(sc->sc_isac_mask)
name|l1_bchan_state_t
name|sc_chan
index|[
literal|2
index|]
decl_stmt|;
comment|/* B-channel state	*/
define|#
directive|define
name|HSCX_A_BASE
value|(sc->sc_chan[0].hscx)
define|#
directive|define
name|HSCX_A_IMASK
value|(sc->sc_chan[0].hscx_mask)
define|#
directive|define
name|HSCX_B_BASE
value|(sc->sc_chan[1].hscx)
define|#
directive|define
name|HSCX_B_IMASK
value|(sc->sc_chan[1].hscx_mask)
name|struct
name|mbuf
modifier|*
name|sc_ibuf
decl_stmt|;
comment|/* input buffer mgmt	*/
name|u_short
name|sc_ilen
decl_stmt|;
name|u_char
modifier|*
name|sc_ib
decl_stmt|;
comment|/* this is for the irq TX routine */
name|struct
name|mbuf
modifier|*
name|sc_obuf
decl_stmt|;
comment|/* pointer to an mbuf with TX frame */
name|u_char
modifier|*
name|sc_op
decl_stmt|;
comment|/* ptr to next chunk of frame to tx */
name|int
name|sc_ol
decl_stmt|;
comment|/* length of remaining frame to tx */
name|int
name|sc_freeflag
decl_stmt|;
comment|/* m_freem mbuf if set */
name|struct
name|mbuf
modifier|*
name|sc_obuf2
decl_stmt|;
comment|/* pointer to an mbuf with TX frame */
name|int
name|sc_freeflag2
decl_stmt|;
comment|/* m_freem mbuf if set */
name|int
name|sc_isac_version
decl_stmt|;
comment|/* version number of ISAC */
name|int
name|sc_hscx_version
decl_stmt|;
comment|/* version number of HSCX */
name|int
name|sc_ipac_version
decl_stmt|;
comment|/* version number of IPAC */
name|int
name|sc_I430state
decl_stmt|;
comment|/* I.430 state F3 .... F8 */
name|int
name|sc_I430T3
decl_stmt|;
comment|/* I.430 Timer T3 running */
name|struct
name|callout_handle
name|sc_T3_callout
decl_stmt|;
name|int
name|sc_I430T4
decl_stmt|;
comment|/* Timer T4 running */
name|struct
name|callout_handle
name|sc_T4_callout
decl_stmt|;
comment|/* 	 * byte fields for the AVM Fritz!Card PCI. These are packed into 	 * a u_int in the driver. 	 */
name|u_char
name|avma1pp_cmd
decl_stmt|;
name|u_char
name|avma1pp_txl
decl_stmt|;
name|u_char
name|avma1pp_prot
decl_stmt|;
name|int
name|sc_enabled
decl_stmt|;
comment|/* daemon is running */
name|int
name|sc_ipac
decl_stmt|;
comment|/* flag, running on ipac */
name|int
name|sc_bfifolen
decl_stmt|;
comment|/* length of b channel fifos */
define|#
directive|define
name|ISIC_WHAT_ISAC
value|0
define|#
directive|define
name|ISIC_WHAT_HSCXA
value|1
define|#
directive|define
name|ISIC_WHAT_HSCXB
value|2
define|#
directive|define
name|ISIC_WHAT_IPAC
value|3
name|u_int8_t
function_decl|(
modifier|*
name|readreg
function_decl|)
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|bus_size_t
name|offs
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|writereg
function_decl|)
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|bus_size_t
name|offs
parameter_list|,
name|u_int8_t
name|data
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|readfifo
function_decl|)
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|writefifo
function_decl|)
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clearirq
function_decl|)
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
define|#
directive|define
name|ISAC_READ
parameter_list|(
name|r
parameter_list|)
value|(*sc->readreg)(sc, ISIC_WHAT_ISAC, (r))
define|#
directive|define
name|ISAC_WRITE
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(*sc->writereg)(sc, ISIC_WHAT_ISAC, (r), (v))
define|#
directive|define
name|ISAC_RDFIFO
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->readfifo)(sc, ISIC_WHAT_ISAC, (b), (s))
define|#
directive|define
name|ISAC_WRFIFO
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->writefifo)(sc, ISIC_WHAT_ISAC, (b), (s))
define|#
directive|define
name|HSCX_READ
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
value|(*sc->readreg)(sc, ISIC_WHAT_HSCXA+(n), (r))
define|#
directive|define
name|HSCX_WRITE
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|(*sc->writereg)(sc, ISIC_WHAT_HSCXA+(n), (r), (v))
define|#
directive|define
name|HSCX_RDFIFO
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->readfifo)(sc, ISIC_WHAT_HSCXA+(n), (b), (s))
define|#
directive|define
name|HSCX_WRFIFO
parameter_list|(
name|n
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->writefifo)(sc, ISIC_WHAT_HSCXA+(n), (b), (s))
define|#
directive|define
name|IPAC_READ
parameter_list|(
name|r
parameter_list|)
value|(*sc->readreg)(sc, ISIC_WHAT_IPAC, (r))
define|#
directive|define
name|IPAC_WRITE
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(*sc->writereg)(sc, ISIC_WHAT_IPAC, (r), (v))
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	possible I.430/ISAC states  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|I430states
block|{
name|ST_F3
block|,
comment|/* F3 Deactivated	*/
name|ST_F4
block|,
comment|/* F4 Awaiting Signal	*/
name|ST_F5
block|,
comment|/* F5 Identifying Input */
name|ST_F6
block|,
comment|/* F6 Synchronized	*/
name|ST_F7
block|,
comment|/* F7 Activated		*/
name|ST_F8
block|,
comment|/* F8 Lost Framing	*/
name|ST_ILL
block|,
comment|/* Illegal State	*/
name|N_STATES
block|}
enum|;
end_enum

begin_comment
comment|/*---------------------------------------------------------------------------*  *	possible I.430/ISAC events  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|I430events
block|{
name|EV_PHAR
block|,
comment|/* PH ACTIVATE REQUEST 		*/
name|EV_T3
block|,
comment|/* Timer 3 expired 		*/
name|EV_INFO0
block|,
comment|/* receiving INFO0 		*/
name|EV_RSY
block|,
comment|/* receiving any signal		*/
name|EV_INFO2
block|,
comment|/* receiving INFO2		*/
name|EV_INFO48
block|,
comment|/* receiving INFO4 pri 8/9 	*/
name|EV_INFO410
block|,
comment|/* receiving INFO4 pri 10/11	*/
name|EV_DR
block|,
comment|/* Deactivate Request 		*/
name|EV_PU
block|,
comment|/* Power UP			*/
name|EV_DIS
block|,
comment|/* Disconnected (only 2085) 	*/
name|EV_EI
block|,
comment|/* Error Indication 		*/
name|EV_ILL
block|,
comment|/* Illegal Event 		*/
name|N_EVENTS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|I430commands
block|{
name|CMD_TIM
block|,
comment|/*	Timing				*/
name|CMD_RS
block|,
comment|/*	Reset				*/
name|CMD_AR8
block|,
comment|/*	Activation request pri 8	*/
name|CMD_AR10
block|,
comment|/*	Activation request pri 10	*/
name|CMD_DIU
block|,
comment|/*	Deactivate Indication Upstream	*/
name|CMD_ILL
comment|/*	Illegal command			*/
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_COMMANDS
value|CMD_ILL
end_define

begin_decl_stmt
specifier|extern
name|struct
name|l1_softc
name|l1_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|isicintr
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_common
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_detach_common
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_recover
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_bchannel_setup
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|hscx_channel
parameter_list|,
name|int
name|bprot
parameter_list|,
name|int
name|activate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_init_linktab
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_isac_init
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_isac_irq
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_isac_l1_cmd
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_next_state
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|isic_printstate
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_hscx_fifo
parameter_list|(
name|l1_bchan_state_t
modifier|*
parameter_list|,
name|struct
name|l1_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_hscx_init
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|hscx_channel
parameter_list|,
name|int
name|activate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_hscx_irq
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|u_char
name|ista
parameter_list|,
name|int
name|hscx_channel
parameter_list|,
name|u_char
name|ex_irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_hscx_silence
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_hscx_cmd
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|h_chan
parameter_list|,
name|unsigned
name|char
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_hscx_waitxfw
parameter_list|(
name|struct
name|l1_softc
modifier|*
name|sc
parameter_list|,
name|int
name|h_chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s016
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s016
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s08
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s08
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Epcc16
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Epcc16
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s0163
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s0163
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avma1
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_avma1
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_usrtai
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_usrtai
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_itkix1
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_itkix1
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_drnngo
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Cs0P
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Eqs1pi
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_sws
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_siemens_isurf
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_asi
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Dyn
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_diva
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_diva_ipac
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_ISIC_H_ */
end_comment

end_unit

