begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------*  *  *	i4b_l1.h - isdn4bsd layer 1 header file  *	---------------------------------------  *  * $FreeBSD$   *  *      last edit-date: [Mon Jul  5 15:32:02 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_L1_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_L1_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISA_NPORT_CHECK
end_ifndef

begin_comment
comment|/* Double yuck XXX */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/isavar.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------  *	kernel config file flags definition  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|FLAG_TELES_S0_8
value|1
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_16
value|2
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_163
value|3
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_A1
value|4
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_163_PnP
value|5
end_define

begin_define
define|#
directive|define
name|FLAG_CREATIX_S0_PnP
value|6
end_define

begin_define
define|#
directive|define
name|FLAG_USR_ISDN_TA_INT
value|7
end_define

begin_define
define|#
directive|define
name|FLAG_DRN_NGO
value|8
end_define

begin_define
define|#
directive|define
name|FLAG_SWS
value|9
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_A1_PCMCIA
value|10
end_define

begin_define
define|#
directive|define
name|FLAG_DYNALINK
value|11
end_define

begin_define
define|#
directive|define
name|FLAG_BLMASTER
value|12
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_QS1P_ISA
value|13
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_QS1P_PCI
value|14
end_define

begin_define
define|#
directive|define
name|FLAG_SIEMENS_ITALK
value|15
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_MLIMC
value|16
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_MLMCALL
value|17
end_define

begin_define
define|#
directive|define
name|FLAG_ITK_IX1
value|18
end_define

begin_define
define|#
directive|define
name|FLAG_AVMA1PCI
value|19
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_PCC16
value|20
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_PNP
value|21
end_define

begin_define
define|#
directive|define
name|FLAG_SIEMENS_ISURF2
value|22
end_define

begin_define
define|#
directive|define
name|FLAG_ASUSCOM_IPAC
value|23
end_define

begin_define
define|#
directive|define
name|SEC_DELAY
value|1000000
end_define

begin_comment
comment|/* one second DELAY for DELAY*/
end_comment

begin_define
define|#
directive|define
name|MAX_DFRAME_LEN
value|264
end_define

begin_comment
comment|/* max length of a D frame */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__bsdi__
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_comment
comment|/* We try to map as few as possible as small as possible io and/or    memory regions. Each card defines its own interpretation of this    mapping array. At probe time we have a fixed size array, later    (when the card type is known) we allocate a minimal array    dynamically. */
end_comment

begin_define
define|#
directive|define
name|ISIC_MAX_IO_MAPS
value|49
end_define

begin_comment
comment|/* no cardtype needs more yet */
end_comment

begin_comment
comment|/* one entry in mapping array */
end_comment

begin_struct
struct|struct
name|isic_io_map
block|{
name|bus_space_tag_t
name|t
decl_stmt|;
comment|/* which bus-space is this? */
name|bus_space_handle_t
name|h
decl_stmt|;
comment|/* handle of mapped bus space region */
name|bus_size_t
name|offset
decl_stmt|;
comment|/* offset into region */
name|bus_size_t
name|size
decl_stmt|;
comment|/* size of region, zero if not ours  				   (i.e.: don't ever unmap it!) */
block|}
struct|;
end_struct

begin_comment
comment|/* this is passed around at probe time (no struct isic_softc yet) */
end_comment

begin_struct
struct|struct
name|isic_attach_args
block|{
name|int
name|ia_flags
decl_stmt|;
comment|/* flags from config file */
name|int
name|ia_num_mappings
decl_stmt|;
comment|/* number of io mappings provided */
name|struct
name|isic_io_map
name|ia_maps
index|[
name|ISIC_MAX_IO_MAPS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|next_isic_unit
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	isic_Bchan: the state of one B channel  *---------------------------------------------------------------------------*/
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
name|caddr_t
name|hscx
decl_stmt|;
comment|/* HSCX address		*/
endif|#
directive|endif
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
name|isdn_linktab
decl_stmt|;
comment|/* b channel addresses	*/
name|drvr_link_t
modifier|*
name|drvr_linktab
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
name|isic_Bchan_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	isic_softc: the state of the layer 1 of the D channel  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|isic_softc
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
comment|/* We are inherited from this class. All drivers must have this 	   as their first entry in struct softc. */
name|struct
name|device
name|sc_dev
decl_stmt|;
endif|#
directive|endif
name|int
name|sc_unit
decl_stmt|;
comment|/* unit number		*/
name|int
name|sc_irq
decl_stmt|;
comment|/* interrupt vector	*/
ifdef|#
directive|ifdef
name|__FreeBSD__
name|int
name|sc_port
decl_stmt|;
comment|/* port base address	*/
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
name|struct
name|isadev
name|sc_id
decl_stmt|;
comment|/* ISA/PCI device */
name|struct
name|intrhand
name|sc_ih
decl_stmt|;
comment|/* interrupt vectoring */
name|int
name|sc_flags
decl_stmt|;
name|int
name|sc_port
decl_stmt|;
name|caddr_t
name|sc_maddr
decl_stmt|;
name|int
name|sc_abustype
decl_stmt|;
comment|/* PCI, ISA etcetera */
else|#
directive|else
name|u_int
name|sc_maddr
decl_stmt|;
comment|/* "memory address" for card config register */
name|int
name|sc_num_mappings
decl_stmt|;
comment|/* number of io mappings provided */
name|struct
name|isic_io_map
modifier|*
name|sc_maps
decl_stmt|;
define|#
directive|define
name|MALLOC_MAPS
parameter_list|(
name|sc
parameter_list|)
define|\
value|(sc)->sc_maps = (struct isic_io_map*)malloc(sizeof((sc)->sc_maps[0])*(sc)->sc_num_mappings, M_DEVBUF, 0)
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
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
endif|#
directive|endif
name|u_char
name|sc_isac_mask
decl_stmt|;
comment|/* ISAC IRQ mask	*/
define|#
directive|define
name|ISAC_IMASK
value|(sc->sc_isac_mask)
name|isic_Bchan_t
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
name|sc_I430state
decl_stmt|;
comment|/* I.430 state F3 .... F8 */
name|int
name|sc_I430T3
decl_stmt|;
comment|/* I.430 Timer T3 running */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300001
name|struct
name|callout_handle
name|sc_T3_callout
decl_stmt|;
endif|#
directive|endif
name|int
name|sc_I430T4
decl_stmt|;
comment|/* Timer T4 running */
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
name|struct
name|callout_handle
name|sc_T4_callout
decl_stmt|;
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
name|u_char
function_decl|(
modifier|*
name|readreg
function_decl|)
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|writereg
function_decl|)
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|readfifo
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|writefifo
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clearirq
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|ISAC_READ
parameter_list|(
name|r
parameter_list|)
value|(*sc->readreg)(ISAC_BASE, (r))
define|#
directive|define
name|ISAC_WRITE
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(*sc->writereg)(ISAC_BASE, (r), (v));
define|#
directive|define
name|ISAC_RDFIFO
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->readfifo)((b), ISAC_BASE, (s))
define|#
directive|define
name|ISAC_WRFIFO
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|(*sc->writefifo)(ISAC_BASE, (b), (s))
define|#
directive|define
name|HSCX_READ
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
value|(*sc->readreg)(sc->sc_chan[(n)].hscx, (r))
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
value|(*sc->writereg)(sc->sc_chan[(n)].hscx, (r), (v))
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
value|(*sc->readfifo)((b), sc->sc_chan[(n)].hscx, (s))
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
value|(*sc->writefifo)(sc->sc_chan[(n)].hscx, (b), (s))
define|#
directive|define
name|IPAC_READ
parameter_list|(
name|r
parameter_list|)
value|(*sc->readreg)(IPAC_BASE, (r))
define|#
directive|define
name|IPAC_WRITE
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|(*sc->writereg)(IPAC_BASE, (r), (v));
else|#
directive|else
comment|/* ! __FreeBSD__ */
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
argument_list|(
argument|*readreg
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|bus_size_t
name|offs
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*writereg
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|bus_size_t
name|offs
operator|,
name|u_int8_t
name|data
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*readfifo
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
name|void
operator|*
name|buf
operator|,
name|size_t
name|size
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*writefifo
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|what
operator|,
specifier|const
name|void
operator|*
name|data
operator|,
name|size_t
name|size
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clearirq
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
expr_stmt|;
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
endif|#
directive|endif
comment|/* __FreeBSD__ */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|isic_softc
name|isic_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|isic_recover
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_realattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_avma1
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_fritzpcmcia
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Cs0P
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Dyn
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s016
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s0163
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s0163P
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s08
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_usrtai
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_itkix1
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_drnngo
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_sws
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Eqs1pi
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_avm_pnp
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_siemens_isurf
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Eqs1pp
parameter_list|(
name|int
name|unit
parameter_list|,
name|unsigned
name|int
name|iobase1
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_asi
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
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
name|int
name|isic_hscx_fifo
parameter_list|(
name|isic_Bchan_t
modifier|*
parameter_list|,
name|struct
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|void
name|isic_init_linktab
parameter_list|(
name|struct
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avma1
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avma1_pcmcia
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avm_pnp
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_siemens_isurf
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Cs0P
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Dyn
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s016
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s0163
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s0163P
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s08
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_usrtai
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_itkix1
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_drnngo
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_sws
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Eqs1pi
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_asi
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|iobase2
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

begin_decl_stmt
specifier|extern
name|struct
name|isic_softc
modifier|*
name|isic_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isic_find_sc
parameter_list|(
name|unit
parameter_list|)
value|(isic_sc[(unit)])
end_define

begin_define
define|#
directive|define
name|ATTACHARGS
value|struct device *, struct device *, struct isa_attach_args *
end_define

begin_define
define|#
directive|define
name|MATCHARGS
value|struct device *, struct cfdata *, struct isa_attach_args *
end_define

begin_function_decl
specifier|extern
name|int
name|isa_isicmatch
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isa_isicattach
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isicintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isic_recover
parameter_list|(
name|struct
name|isic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_realattach
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_avma1
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_fritzpcmcia
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Cs0P
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Dyn
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s016
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s0163
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s0163P
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_s08
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_usrtai
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_itkix1
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_drnngo
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_sws
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Eqs1pi
parameter_list|(
name|ATTACHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_attach_Eqs1pp
parameter_list|(
name|ATTACHARGS
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
name|isic_hscx_init
parameter_list|(
name|struct
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|void
name|isic_init_linktab
parameter_list|(
name|struct
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
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
name|isic_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avma1
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_avma1_pcmcia
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Cs0P
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Dyn
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s016
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s0163
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s0163P
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_s08
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_usrtai
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_itkix1
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_drnngo
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_sws
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isic_probe_Eqs1pi
parameter_list|(
name|MATCHARGS
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|MATCHARGS
end_undef

begin_undef
undef|#
directive|undef
name|ATTACHARGS
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not FreeBSD/__bsdi__ */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|isic_recover
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isicattach
name|__P
argument_list|(
operator|(
name|int
name|flags
operator|,
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isicintr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isicprobe
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_avma1
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_s016
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_s0163
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_s08
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_usrtai
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_attach_itkix1
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_bchannel_setup
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|int
name|hscx_channel
operator|,
name|int
name|bprot
operator|,
name|int
name|activate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_hscx_init
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|hscx_channel
operator|,
name|int
name|activate
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_hscx_irq
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|u_char
name|ista
operator|,
name|int
name|hscx_channel
operator|,
name|u_char
name|ex_irq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_hscx_silence
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
name|data
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_hscx_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|h_chan
operator|,
name|unsigned
name|char
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_hscx_waitxfw
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|h_chan
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_init_linktab
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_isac_init
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_isac_irq
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_isac_l1_cmd
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|command
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|isic_next_state
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|,
name|int
name|event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|isic_printstate
name|__P
argument_list|(
operator|(
expr|struct
name|isic_softc
operator|*
name|sc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_avma1
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_s016
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_s0163
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_s08
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_usrtai
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isic_probe_itkix1
name|__P
argument_list|(
operator|(
expr|struct
name|isic_attach_args
operator|*
name|ia
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|isic_softc
modifier|*
name|isic_sc
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isic_find_sc
parameter_list|(
name|unit
parameter_list|)
value|(isic_sc[(unit)])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_L1_H_ */
end_comment

end_unit

