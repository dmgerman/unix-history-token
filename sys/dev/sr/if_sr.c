begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 John Hay.  * Copyright (c) 1996 SDL Communications, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Programming assumptions and other issues.  *  * Only a 16K window will be used.  *  * The descriptors of a DMA channel will fit in a 16K memory window.  *  * The buffers of a transmit DMA channel will fit in a 16K memory window.  *  * When interface is going up, handshaking is set and it is only cleared  * when the interface is down'ed.  *  * There should be a way to set/reset Raw HDLC/PPP, Loopback, DCE/DTE,  * internal/external clock, etc.....  *  */
end_comment

begin_include
include|#
directive|include
file|"sr.h"
end_include

begin_include
include|#
directive|include
file|"opt_netgraph.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_include
include|#
directive|include
file|<i386/isa/if_sr.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_include
include|#
directive|include
file|"sppp.h"
end_include

begin_if
if|#
directive|if
name|NSPPP
operator|<=
literal|0
end_if

begin_error
error|#
directive|error
error|Device 'sr' requires sppp.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH */
end_comment

begin_include
include|#
directive|include
file|<net/if_sppp.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/if_srregs.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/ic/hd64570.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_include
include|#
directive|include
file|<netgraph/ng_message.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/netgraph.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/* #define USE_MODEMCK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_OLDISA
end_ifndef

begin_error
error|#
directive|error
literal|"The sr device requires the old isa compatibility shims"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUGGY
end_ifndef

begin_define
define|#
directive|define
name|BUGGY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_define
define|#
directive|define
name|PPP_HEADER_LEN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/*  * These macros are used to hide the difference between the way the  * ISA N2 cards and the PCI N2 cards access the Hitachi 64570 SCA.  */
end_comment

begin_define
define|#
directive|define
name|SRC_GET8
parameter_list|(
name|base
parameter_list|,
name|off
parameter_list|)
value|(*hc->src_get8)(base,(u_int)&off)
end_define

begin_define
define|#
directive|define
name|SRC_GET16
parameter_list|(
name|base
parameter_list|,
name|off
parameter_list|)
value|(*hc->src_get16)(base,(u_int)&off)
end_define

begin_define
define|#
directive|define
name|SRC_PUT8
parameter_list|(
name|base
parameter_list|,
name|off
parameter_list|,
name|d
parameter_list|)
value|(*hc->src_put8)(base,(u_int)&off,d)
end_define

begin_define
define|#
directive|define
name|SRC_PUT16
parameter_list|(
name|base
parameter_list|,
name|off
parameter_list|,
name|d
parameter_list|)
value|(*hc->src_put16)(base,(u_int)&off,d)
end_define

begin_comment
comment|/*  * These macros enable/disable the DPRAM and select the correct  * DPRAM page.  */
end_comment

begin_define
define|#
directive|define
name|SRC_GET_WIN
parameter_list|(
name|addr
parameter_list|)
value|((addr>> SRC_WIN_SHFT)& SR_PG_MSK)
end_define

begin_define
define|#
directive|define
name|SRC_SET_ON
parameter_list|(
name|iobase
parameter_list|)
value|outb(iobase+SR_PCR,			     \ 					SR_PCR_MEM_WIN | inb(iobase+SR_PCR))
end_define

begin_define
define|#
directive|define
name|SRC_SET_MEM
parameter_list|(
name|iobase
parameter_list|,
name|win
parameter_list|)
value|outb(iobase+SR_PSR, SRC_GET_WIN(win) |	     \ 					(inb(iobase+SR_PSR)& ~SR_PG_MSK))
end_define

begin_define
define|#
directive|define
name|SRC_SET_OFF
parameter_list|(
name|iobase
parameter_list|)
value|outb(iobase+SR_PCR,			     \ 					~SR_PCR_MEM_WIN& inb(iobase+SR_PCR))
end_define

begin_comment
comment|/*  * Define the hardware (card information) structure needed to keep  * track of the device itself... There is only one per card.  */
end_comment

begin_struct
struct|struct
name|sr_hardc
block|{
name|struct
name|sr_hardc
modifier|*
name|next
decl_stmt|;
comment|/* PCI card linkage */
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
comment|/* software channels */
name|int
name|cunit
decl_stmt|;
comment|/* card w/in system */
name|u_short
name|iobase
decl_stmt|;
comment|/* I/O Base Address */
name|int
name|cardtype
decl_stmt|;
name|int
name|numports
decl_stmt|;
comment|/* # of ports on cd */
name|int
name|mempages
decl_stmt|;
name|u_int
name|memsize
decl_stmt|;
comment|/* DPRAM size: bytes */
name|u_int
name|winmsk
decl_stmt|;
name|vm_offset_t
name|sca_base
decl_stmt|;
name|vm_offset_t
name|mem_pstart
decl_stmt|;
comment|/* start of buffer */
name|caddr_t
name|mem_start
decl_stmt|;
comment|/* start of DP RAM */
name|caddr_t
name|mem_end
decl_stmt|;
comment|/* end of DP RAM */
name|caddr_t
name|plx_base
decl_stmt|;
name|sca_regs
modifier|*
name|sca
decl_stmt|;
comment|/* register array */
comment|/* 	 * We vectorize the following functions to allow re-use between the 	 * ISA card's needs and those of the PCI card. 	 */
name|void
function_decl|(
modifier|*
name|src_put8
function_decl|)
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|src_put16
function_decl|)
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|src_get8
function_decl|)
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|src_get16
function_decl|)
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|int
name|next_sc_unit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_decl_stmt
specifier|static
name|int
name|sr_watcher
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|sr_hardc
name|sr_hardc
index|[
name|NSR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sr_hardc
modifier|*
name|sr_hardc_pci
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Define the software interface for the card... There is one for  * every channel (port).  */
end_comment

begin_struct
struct|struct
name|sr_softc
block|{
ifndef|#
directive|ifndef
name|NETGRAPH
name|struct
name|sppp
name|ifsppp
decl_stmt|;
comment|/* PPP service w/in system */
endif|#
directive|endif
comment|/* NETGRAPH */
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|;
comment|/* card-level information */
name|int
name|unit
decl_stmt|;
comment|/* With regard to all sr devices */
name|int
name|subunit
decl_stmt|;
comment|/* With regard to this card */
struct|struct
name|buf_block
block|{
name|u_int
name|txdesc
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|txstart
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|txend
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|txtail
decl_stmt|;
comment|/* # of 1st free gran */
name|u_int
name|txmax
decl_stmt|;
comment|/* # of free grans */
name|u_int
name|txeda
decl_stmt|;
comment|/* err descr addr */
block|}
name|block
index|[
name|SR_TX_BLOCKS
index|]
struct|;
name|char
name|xmit_busy
decl_stmt|;
comment|/* Transmitter is busy */
name|char
name|txb_inuse
decl_stmt|;
comment|/* # of tx grans in use */
name|u_int
name|txb_new
decl_stmt|;
comment|/* ndx to new buffer */
name|u_int
name|txb_next_tx
decl_stmt|;
comment|/* ndx to next gran rdy tx */
name|u_int
name|rxdesc
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|rxstart
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|rxend
decl_stmt|;
comment|/* DPRAM offset */
name|u_int
name|rxhind
decl_stmt|;
comment|/* ndx to the hd of rx bufrs */
name|u_int
name|rxmax
decl_stmt|;
comment|/* # of avail grans */
name|u_int
name|clk_cfg
decl_stmt|;
comment|/* Clock configuration */
name|int
name|scachan
decl_stmt|;
comment|/* channel # on card */
ifdef|#
directive|ifdef
name|NETGRAPH
name|int
name|running
decl_stmt|;
comment|/* something is attached so we are running */
name|int
name|dcd
decl_stmt|;
comment|/* do we have dcd? */
comment|/* ---netgraph bits --- */
name|char
name|nodename
index|[
name|NG_NODELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* store our node name */
name|int
name|datahooks
decl_stmt|;
comment|/* number of data hooks attached */
name|node_p
name|node
decl_stmt|;
comment|/* netgraph node */
name|hook_p
name|hook
decl_stmt|;
comment|/* data hook */
name|hook_p
name|debug_hook
decl_stmt|;
name|struct
name|ifqueue
name|xmitq_hipri
decl_stmt|;
comment|/* hi-priority transmit queue */
name|struct
name|ifqueue
name|xmitq
decl_stmt|;
comment|/* transmit queue */
name|int
name|flags
decl_stmt|;
comment|/* state */
define|#
directive|define
name|SCF_RUNNING
value|0x01
comment|/* board is active */
define|#
directive|define
name|SCF_OACTIVE
value|0x02
comment|/* output is active */
name|int
name|out_dog
decl_stmt|;
comment|/* watchdog cycles output count-down */
if|#
directive|if
operator|(
name|__FreeBSD__
operator|>=
literal|3
operator|)
name|struct
name|callout_handle
name|handle
decl_stmt|;
comment|/* timeout(9) handle */
endif|#
directive|endif
name|u_long
name|inbytes
decl_stmt|,
name|outbytes
decl_stmt|;
comment|/* stats */
name|u_long
name|lastinbytes
decl_stmt|,
name|lastoutbytes
decl_stmt|;
comment|/* a second ago */
name|u_long
name|inrate
decl_stmt|,
name|outrate
decl_stmt|;
comment|/* highest rate seen */
name|u_long
name|inlast
decl_stmt|;
comment|/* last input N secs ago */
name|u_long
name|out_deficit
decl_stmt|;
comment|/* output since last input */
name|u_long
name|oerrors
decl_stmt|,
name|ierrors
index|[
literal|6
index|]
decl_stmt|;
name|u_long
name|opackets
decl_stmt|,
name|ipackets
decl_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_define
define|#
directive|define
name|DOG_HOLDOFF
value|6
end_define

begin_comment
comment|/* dog holds off for 6 secs */
end_comment

begin_define
define|#
directive|define
name|QUITE_A_WHILE
value|300
end_define

begin_comment
comment|/* 5 MINUTES */
end_comment

begin_define
define|#
directive|define
name|LOTS_OF_PACKETS
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/*  * List of valid interrupt numbers for the N2 ISA card.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|sr_irqtable
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
comment|/*  0 */
literal|0
block|,
comment|/*  1 */
literal|0
block|,
comment|/*  2 */
literal|1
block|,
comment|/*  3 */
literal|1
block|,
comment|/*  4 */
literal|1
block|,
comment|/*  5 */
literal|0
block|,
comment|/*  6 */
literal|1
block|,
comment|/*  7 */
literal|0
block|,
comment|/*  8 */
literal|0
block|,
comment|/*  9 */
literal|1
block|,
comment|/* 10 */
literal|1
block|,
comment|/* 11 */
literal|1
block|,
comment|/* 12 */
literal|0
block|,
comment|/* 13 */
literal|0
block|,
comment|/* 14 */
literal|1
comment|/* 15 */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|srprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|srattach_isa
parameter_list|(
name|struct
name|isa_device
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|isa_driver
name|srdriver
init|=
block|{
name|INTR_TYPE_NET
block|,
name|srprobe
block|,
name|srattach_isa
block|,
literal|"sr"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|COMPAT_ISA_DRIVER
argument_list|(
name|sr
argument_list|,
name|srdriver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Baud Rate table for Sync Mode.  * Each entry consists of 3 elements:  * Baud Rate (x100) , TMC, BR  *  * Baud Rate = FCLK / TMC / 2^BR  * Baud table for Crystal freq. of 9.8304 Mhz  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
end_ifdef

begin_struct
struct|struct
name|rate_line
block|{
name|int
name|target
decl_stmt|;
comment|/* target rate/100 */
name|int
name|tmc_reg
decl_stmt|;
comment|/* TMC register value */
name|int
name|br_reg
decl_stmt|;
comment|/* BR (BaudRateClk) selector */
block|}
name|n2_rates
index|[]
init|=
block|{
comment|/* Baudx100	TMC		BR */
block|{
literal|3
block|,
literal|128
block|,
literal|8
block|}
block|,
block|{
literal|6
block|,
literal|128
block|,
literal|7
block|}
block|,
block|{
literal|12
block|,
literal|128
block|,
literal|6
block|}
block|,
block|{
literal|24
block|,
literal|128
block|,
literal|5
block|}
block|,
block|{
literal|48
block|,
literal|128
block|,
literal|4
block|}
block|,
block|{
literal|96
block|,
literal|128
block|,
literal|3
block|}
block|,
block|{
literal|192
block|,
literal|128
block|,
literal|2
block|}
block|,
block|{
literal|384
block|,
literal|128
block|,
literal|1
block|}
block|,
block|{
literal|560
block|,
literal|88
block|,
literal|1
block|}
block|,
block|{
literal|640
block|,
literal|77
block|,
literal|1
block|}
block|,
block|{
literal|1280
block|,
literal|38
block|,
literal|1
block|}
block|,
block|{
literal|2560
block|,
literal|19
block|,
literal|1
block|}
block|,
block|{
literal|5120
block|,
literal|10
block|,
literal|1
block|}
block|,
block|{
literal|10000
block|,
literal|5
block|,
literal|1
block|}
block|,
block|{
literal|15000
block|,
literal|3
block|,
literal|1
block|}
block|,
block|{
literal|25000
block|,
literal|2
block|,
literal|1
block|}
block|,
block|{
literal|50000
block|,
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|sr_test_speed
index|[]
init|=
block|{
name|N2_TEST_SPEED
block|,
name|N2_TEST_SPEED
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|etc0vals
index|[]
init|=
block|{
name|SR_MCR_ETC0
block|,
comment|/* ISA channel 0 */
name|SR_MCR_ETC1
block|,
comment|/* ISA channel 1 */
name|SR_FECR_ETC0
block|,
comment|/* PCI channel 0 */
name|SR_FECR_ETC1
comment|/* PCI channel 1 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|sr_hardc
modifier|*
name|srattach_pci
parameter_list|(
name|int
name|unit
parameter_list|,
name|vm_offset_t
name|plx_vaddr
parameter_list|,
name|vm_offset_t
name|sca_vaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srintr_hc
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|ointhand2_t
name|srintr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|srattach
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_xmit
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_function_decl
specifier|static
name|void
name|srstart
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|srioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|srwatchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|void
name|srstart
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|srwatchdog
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_function_decl
specifier|static
name|int
name|sr_packet_avail
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|u_char
modifier|*
name|rxstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_copy_rxbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_eat_packet
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|,
name|int
name|single
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_get_packets
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_up
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_down
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|src_init
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_init_sca
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_init_msci
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_init_rx_dmac
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_init_tx_dmac
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_dmac_intr
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_char
name|isr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_msci_intr
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_char
name|isr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sr_timer_intr
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_char
name|isr
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_function_decl
specifier|static
name|void
name|sr_modemck
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|static
name|void
name|sr_modemck
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_function_decl
specifier|static
name|u_int
name|src_get8_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int
name|src_get16_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|src_put8_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|src_put16_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int
name|src_get8_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int
name|src_get16_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|src_put8_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|src_put16_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_function_decl
specifier|static
name|void
name|ngsr_watchdog_frame
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ngsr_init
parameter_list|(
name|void
modifier|*
name|ignored
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|ng_constructor_t
name|ngsr_constructor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvmsg_t
name|ngsr_rcvmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_shutdown_t
name|ngsr_rmnode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_newhook_t
name|ngsr_newhook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*static ng_findhook_t	ngsr_findhook; */
end_comment

begin_decl_stmt
specifier|static
name|ng_connect_t
name|ngsr_connect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvdata_t
name|ngsr_rcvdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_disconnect_t
name|ngsr_disconnect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ng_type
name|typestruct
init|=
block|{
name|NG_VERSION
block|,
name|NG_SR_NODE_TYPE
block|,
name|NULL
block|,
name|ngsr_constructor
block|,
name|ngsr_rcvmsg
block|,
name|ngsr_rmnode
block|,
name|ngsr_newhook
block|,
name|NULL
block|,
name|ngsr_connect
block|,
name|ngsr_rcvdata
block|,
name|ngsr_rcvdata
block|,
name|ngsr_disconnect
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ngsr_done_init
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/*  * I/O for ISA N2 card(s)  */
end_comment

begin_define
define|#
directive|define
name|SRC_REG
parameter_list|(
name|iobase
parameter_list|,
name|y
parameter_list|)
value|((((y)& 0xf) + (((y)& 0xf0)<< 6) +       \ 				(iobase)) | 0x8000)
end_define

begin_function
specifier|static
name|u_int
name|src_get8_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
block|{
return|return
name|inb
argument_list|(
name|SRC_REG
argument_list|(
name|base
argument_list|,
name|off
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|u_int
name|src_get16_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
block|{
return|return
name|inw
argument_list|(
name|SRC_REG
argument_list|(
name|base
argument_list|,
name|off
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|src_put8_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
block|{
name|outb
argument_list|(
name|SRC_REG
argument_list|(
name|base
argument_list|,
name|off
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|src_put16_io
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
block|{
name|outw
argument_list|(
name|SRC_REG
argument_list|(
name|base
argument_list|,
name|off
argument_list|)
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * I/O for PCI N2 card(s)  */
end_comment

begin_define
define|#
directive|define
name|SRC_PCI_SCA_REG
parameter_list|(
name|y
parameter_list|)
value|((y& 2) ? ((y& 0xfd) + 0x100) : y)
end_define

begin_function
specifier|static
name|u_int
name|src_get8_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
block|{
return|return
operator|*
operator|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|base
operator|+
name|SRC_PCI_SCA_REG
argument_list|(
name|off
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|u_int
name|src_get16_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|)
block|{
return|return
operator|*
operator|(
operator|(
name|u_short
operator|*
operator|)
operator|(
name|base
operator|+
name|SRC_PCI_SCA_REG
argument_list|(
name|off
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|src_put8_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
block|{
operator|*
operator|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|base
operator|+
name|SRC_PCI_SCA_REG
argument_list|(
name|off
argument_list|)
operator|)
operator|)
operator|=
operator|(
name|u_char
operator|)
name|val
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|src_put16_mem
parameter_list|(
name|u_int
name|base
parameter_list|,
name|u_int
name|off
parameter_list|,
name|u_int
name|val
parameter_list|)
block|{
operator|*
operator|(
operator|(
name|u_short
operator|*
operator|)
operator|(
name|base
operator|+
name|SRC_PCI_SCA_REG
argument_list|(
name|off
argument_list|)
operator|)
operator|)
operator|=
operator|(
name|u_short
operator|)
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Probe for an ISA card. If it is there, size its memory. Then get the  * rest of its information and fill it in.  */
end_comment

begin_function
specifier|static
name|int
name|srprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|id
parameter_list|)
block|{
name|struct
name|sr_hardc
modifier|*
name|hc
init|=
operator|&
name|sr_hardc
index|[
name|id
operator|->
name|id_unit
index|]
decl_stmt|;
name|u_int
name|pgs
decl_stmt|,
name|i
decl_stmt|,
name|tmp
decl_stmt|;
name|u_short
name|port
decl_stmt|;
name|u_short
modifier|*
name|smem
decl_stmt|;
name|u_char
name|mar
decl_stmt|;
name|sca_regs
modifier|*
name|sca
init|=
literal|0
decl_stmt|;
comment|/* 	 * Now see if the card is realy there. 	 */
name|hc
operator|->
name|cardtype
operator|=
name|SR_CRD_N2
expr_stmt|;
comment|/* 	 * We have to fill these in early because the SRC_PUT* and SRC_GET* 	 * macros use them. 	 */
name|hc
operator|->
name|src_get8
operator|=
name|src_get8_io
expr_stmt|;
name|hc
operator|->
name|src_get16
operator|=
name|src_get16_io
expr_stmt|;
name|hc
operator|->
name|src_put8
operator|=
name|src_put8_io
expr_stmt|;
name|hc
operator|->
name|src_put16
operator|=
name|src_put16_io
expr_stmt|;
name|hc
operator|->
name|sca
operator|=
literal|0
expr_stmt|;
name|port
operator|=
name|id
operator|->
name|id_iobase
expr_stmt|;
name|hc
operator|->
name|numports
operator|=
name|NCHAN
expr_stmt|;
comment|/* assumed # of channels on the card */
if|if
condition|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_NCHAN_MSK
condition|)
name|hc
operator|->
name|numports
operator|=
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_NCHAN_MSK
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off the card */
comment|/* 	 * Next, we'll test the Base Address Register to retension of 	 * data... ... seeing if we're *really* talking to an N2. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|0x100
condition|;
name|i
operator|++
control|)
block|{
name|outb
argument_list|(
name|port
operator|+
name|SR_BAR
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|inb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|inb
argument_list|(
name|port
operator|+
name|SR_BAR
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
name|i
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: probe failed BAR %x, %x.\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|i
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
comment|/* 	 * Now see if we can see the SCA. 	 */
name|outb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|,
name|SR_PCR_SCARUN
operator||
name|inb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|)
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|wcrl
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|wcrm
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|wcrh
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|pcr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|msci
index|[
literal|0
index|]
operator|.
name|tmc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|SRC_GET8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|msci
index|[
literal|0
index|]
operator|.
name|tmc
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: Error reading SCA 0, %x\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|SRC_PUT8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|msci
index|[
literal|0
index|]
operator|.
name|tmc
argument_list|,
literal|0x5A
argument_list|)
expr_stmt|;
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|SRC_GET8
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|msci
index|[
literal|0
index|]
operator|.
name|tmc
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0x5A
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: Error reading SCA 0x5A, %x\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|SRC_PUT16
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|dmac
index|[
literal|0
index|]
operator|.
name|cda
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|SRC_GET16
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|dmac
index|[
literal|0
index|]
operator|.
name|cda
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: Error reading SCA 0, %x\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|SRC_PUT16
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|dmac
index|[
literal|0
index|]
operator|.
name|cda
argument_list|,
literal|0x55AA
argument_list|)
expr_stmt|;
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|SRC_GET16
argument_list|(
name|port
argument_list|,
name|sca
operator|->
name|dmac
index|[
literal|0
index|]
operator|.
name|cda
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|!=
literal|0x55AA
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: Error reading SCA 0x55AA, %x\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 	 * OK, the board's interface registers seem to work. Now we'll see 	 * if the Dual-Ported RAM is fully accessible... 	 */
name|outb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|,
name|SR_PCR_EN_VPM
operator||
name|SR_PCR_ISA16
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|,
name|SR_PSR_WIN_16K
argument_list|)
expr_stmt|;
comment|/* 	 * Take the kernel "virtual" address supplied to us and convert 	 * it to a "real" address. Then program the card to use that. 	 */
name|mar
operator|=
operator|(
name|kvtop
argument_list|(
name|id
operator|->
name|id_maddr
argument_list|)
operator|>>
literal|16
operator|)
operator|&
name|SR_PCR_16M_SEL
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|,
name|mar
operator||
name|inb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|)
argument_list|)
expr_stmt|;
name|mar
operator|=
name|kvtop
argument_list|(
name|id
operator|->
name|id_maddr
argument_list|)
operator|>>
literal|12
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
name|SR_BAR
argument_list|,
name|mar
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|,
name|inb
argument_list|(
name|port
operator|+
name|SR_PCR
argument_list|)
operator||
name|SR_PCR_MEM_WIN
argument_list|)
expr_stmt|;
name|smem
operator|=
operator|(
name|u_short
operator|*
operator|)
name|id
operator|->
name|id_maddr
expr_stmt|;
comment|/* DP RAM Address */
comment|/* 	 * Here we will perform the memory scan to size the device. 	 * 	 * This is done by marking each potential page with a magic number. 	 * We then loop through the pages looking for that magic number. As 	 * soon as we no longer see that magic number, we'll quit the scan, 	 * knowing that no more memory is present. This provides the number 	 * of pages present on the card. 	 * 	 * Note: We're sizing 16K memory granules. 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|SR_PSR_PG_SEL
condition|;
name|i
operator|++
control|)
block|{
name|outb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|,
operator|(
name|inb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|)
operator|&
operator|~
name|SR_PSR_PG_SEL
operator|)
operator||
name|i
argument_list|)
expr_stmt|;
operator|*
name|smem
operator|=
literal|0xAA55
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|SR_PSR_PG_SEL
condition|;
name|i
operator|++
control|)
block|{
name|outb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|,
operator|(
name|inb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|)
operator|&
operator|~
name|SR_PSR_PG_SEL
operator|)
operator||
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|smem
operator|!=
literal|0xAA55
condition|)
block|{
comment|/* 			 * If we have less than 64k of memory, give up. That 			 * is 4 x 16k pages. 			 */
if|if
condition|(
name|i
operator|<
literal|4
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: Bad mem page %d, mem %x, %x.\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|i
argument_list|,
literal|0xAA55
argument_list|,
operator|*
name|smem
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
break|break;
block|}
operator|*
name|smem
operator|=
name|i
expr_stmt|;
block|}
name|hc
operator|->
name|mempages
operator|=
name|i
expr_stmt|;
name|hc
operator|->
name|memsize
operator|=
name|i
operator|*
name|SRC_WIN_SIZ
expr_stmt|;
name|hc
operator|->
name|winmsk
operator|=
name|SRC_WIN_MSK
expr_stmt|;
name|pgs
operator|=
name|i
expr_stmt|;
comment|/* final count of 16K pages */
comment|/* 	 * This next loop erases the contents of that page in DPRAM 	 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|pgs
condition|;
name|i
operator|++
control|)
block|{
name|outb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|,
operator|(
name|inb
argument_list|(
name|port
operator|+
name|SR_PSR
argument_list|)
operator|&
operator|~
name|SR_PSR_PG_SEL
operator|)
operator||
name|i
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|smem
argument_list|,
name|SRC_WIN_SIZ
argument_list|)
expr_stmt|;
block|}
name|SRC_SET_OFF
argument_list|(
name|port
argument_list|)
expr_stmt|;
comment|/* 	 * We have a card here, fill in what we can. 	 */
name|id
operator|->
name|id_msize
operator|=
name|SRC_WIN_SIZ
expr_stmt|;
name|hc
operator|->
name|iobase
operator|=
name|id
operator|->
name|id_iobase
expr_stmt|;
name|hc
operator|->
name|sca_base
operator|=
name|id
operator|->
name|id_iobase
expr_stmt|;
name|hc
operator|->
name|mem_start
operator|=
name|id
operator|->
name|id_maddr
expr_stmt|;
name|hc
operator|->
name|mem_end
operator|=
operator|(
name|id
operator|->
name|id_maddr
operator|+
name|id
operator|->
name|id_msize
operator|)
operator|-
literal|1
expr_stmt|;
name|hc
operator|->
name|mem_pstart
operator|=
literal|0
expr_stmt|;
name|hc
operator|->
name|cunit
operator|=
name|id
operator|->
name|id_unit
expr_stmt|;
comment|/* 	 * Do a little sanity check. 	 */
if|if
condition|(
name|sr_irqtable
index|[
name|ffs
argument_list|(
name|id
operator|->
name|id_irq
argument_list|)
operator|-
literal|1
index|]
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"sr%d: Warning: illegal interrupt %d chosen.\n"
argument_list|,
name|id
operator|->
name|id_unit
argument_list|,
name|ffs
argument_list|(
name|id
operator|->
name|id_irq
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* 	 * Bogus card configuration 	 */
if|if
condition|(
operator|(
name|hc
operator|->
name|numports
operator|>
name|NCHAN
operator|)
comment|/* only 2 ports/card */
operator|||
operator|(
name|hc
operator|->
name|memsize
operator|>
operator|(
literal|512
operator|*
literal|1024
operator|)
operator|)
condition|)
comment|/* no more than 256K */
return|return
literal|0
return|;
return|return
name|SRC_IO_SIZ
return|;
comment|/* return the amount of IO addresses used. */
block|}
end_function

begin_comment
comment|/*  * srattach_isa and srattach_pci allocate memory for hardc, softc and  * data buffers. It also does any initialization that is bus specific.  * At the end they call the common srattach() function.  */
end_comment

begin_function
specifier|static
name|int
name|srattach_isa
parameter_list|(
name|struct
name|isa_device
modifier|*
name|id
parameter_list|)
block|{
name|u_char
name|mar
decl_stmt|;
name|struct
name|sr_hardc
modifier|*
name|hc
init|=
operator|&
name|sr_hardc
index|[
name|id
operator|->
name|id_unit
index|]
decl_stmt|;
comment|/* 	 * Allocate the software interface table(s) 	 */
name|MALLOC
argument_list|(
name|hc
operator|->
name|sc
argument_list|,
expr|struct
name|sr_softc
operator|*
argument_list|,
name|hc
operator|->
name|numports
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|sr_softc
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|sc
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|bzero
argument_list|(
name|hc
operator|->
name|sc
argument_list|,
name|hc
operator|->
name|numports
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|sr_softc
argument_list|)
argument_list|)
expr_stmt|;
name|id
operator|->
name|id_ointr
operator|=
name|srintr
expr_stmt|;
name|outb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PCR
argument_list|,
name|inb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PCR
argument_list|)
operator||
name|SR_PCR_SCARUN
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PSR
argument_list|,
name|inb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PSR
argument_list|)
operator||
name|SR_PSR_EN_SCA_DMA
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_MCR
argument_list|,
name|SR_MCR_DTR0
operator||
name|SR_MCR_DTR1
operator||
name|SR_MCR_TE0
operator||
name|SR_MCR_TE1
argument_list|)
expr_stmt|;
name|SRC_SET_ON
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
comment|/* 	 * Configure the card. Mem address, irq, 	 */
name|mar
operator|=
operator|(
name|kvtop
argument_list|(
name|id
operator|->
name|id_maddr
argument_list|)
operator|>>
literal|16
operator|)
operator|&
name|SR_PCR_16M_SEL
expr_stmt|;
name|outb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PCR
argument_list|,
name|mar
operator||
operator|(
name|inb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_PCR
argument_list|)
operator|&
operator|~
name|SR_PCR_16M_SEL
operator|)
argument_list|)
expr_stmt|;
name|mar
operator|=
name|kvtop
argument_list|(
name|id
operator|->
name|id_maddr
argument_list|)
operator|>>
literal|12
expr_stmt|;
name|outb
argument_list|(
name|hc
operator|->
name|iobase
operator|+
name|SR_BAR
argument_list|,
name|mar
argument_list|)
expr_stmt|;
comment|/* 	 * Get the TX clock direction and configuration. The default is a 	 * single external clock which is used by RX and TX. 	 */
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
if|if
condition|(
name|sr_test_speed
index|[
literal|0
index|]
operator|>
literal|0
condition|)
name|hc
operator|->
name|sc
index|[
literal|0
index|]
operator|.
name|clk_cfg
operator|=
name|SR_FLAGS_INT_CLK
expr_stmt|;
elseif|else
if|if
condition|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_0_CLK_MSK
condition|)
name|hc
operator|->
name|sc
index|[
literal|0
index|]
operator|.
name|clk_cfg
operator|=
operator|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_0_CLK_MSK
operator|)
operator|>>
name|SR_FLAGS_CLK_SHFT
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_0_CLK_MSK
condition|)
name|hc
operator|->
name|sc
index|[
literal|0
index|]
operator|.
name|clk_cfg
operator|=
operator|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_0_CLK_MSK
operator|)
operator|>>
name|SR_FLAGS_CLK_SHFT
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hc
operator|->
name|numports
operator|==
literal|2
condition|)
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
if|if
condition|(
name|sr_test_speed
index|[
literal|1
index|]
operator|>
literal|0
condition|)
name|hc
operator|->
name|sc
index|[
literal|0
index|]
operator|.
name|clk_cfg
operator|=
name|SR_FLAGS_INT_CLK
expr_stmt|;
elseif|else
endif|#
directive|endif
if|if
condition|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_1_CLK_MSK
condition|)
name|hc
operator|->
name|sc
index|[
literal|1
index|]
operator|.
name|clk_cfg
operator|=
operator|(
name|id
operator|->
name|id_flags
operator|&
name|SR_FLAGS_1_CLK_MSK
operator|)
operator|>>
operator|(
name|SR_FLAGS_CLK_SHFT
operator|+
name|SR_FLAGS_CLK_CHAN_SHFT
operator|)
expr_stmt|;
return|return
name|srattach
argument_list|(
name|hc
argument_list|)
return|;
block|}
end_function

begin_function
name|struct
name|sr_hardc
modifier|*
name|srattach_pci
parameter_list|(
name|int
name|unit
parameter_list|,
name|vm_offset_t
name|plx_vaddr
parameter_list|,
name|vm_offset_t
name|sca_vaddr
parameter_list|)
block|{
name|int
name|numports
decl_stmt|,
name|pndx
decl_stmt|;
name|u_int
name|fecr
decl_stmt|,
modifier|*
name|fecrp
init|=
operator|(
name|u_int
operator|*
operator|)
operator|(
name|sca_vaddr
operator|+
name|SR_FECR
operator|)
decl_stmt|;
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|,
modifier|*
modifier|*
name|hcp
decl_stmt|;
comment|/* 	 * Configure the PLX. This is magic. I'm doing it just like I'm told 	 * to. :-) 	 *  	 * offset 	 *  0x00 - Map Range    - Mem-mapped to locate anywhere 	 *  0x04 - Re-Map       - PCI address decode enable 	 *  0x18 - Bus Region   - 32-bit bus, ready enable 	 *  0x1c - Master Range - include all 16 MB 	 *  0x20 - Master RAM   - Map SCA Base at 0 	 *  0x28 - Master Remap - direct master memory enable 	 *  0x68 - Interrupt    - Enable interrupt (0 to disable) 	 *  	 * Note: This is "cargo cult" stuff.  - jrc 	 */
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x00
operator|)
operator|)
operator|=
literal|0xfffff000
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x04
operator|)
operator|)
operator|=
literal|1
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x18
operator|)
operator|)
operator|=
literal|0x40030043
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x1c
operator|)
operator|)
operator|=
literal|0xff000000
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x20
operator|)
operator|)
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x28
operator|)
operator|)
operator|=
literal|0xe9
expr_stmt|;
operator|*
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|(
name|plx_vaddr
operator|+
literal|0x68
operator|)
operator|)
operator|=
literal|0x10900
expr_stmt|;
comment|/* 	 * Get info from card. 	 * 	 * Only look for the second port if the first exists. Too many things 	 * will break if we have only a second port. 	 */
name|fecr
operator|=
operator|*
name|fecrp
expr_stmt|;
name|numports
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|fecr
operator|&
name|SR_FECR_ID0
operator|)
operator|>>
name|SR_FE_ID0_SHFT
operator|)
operator|!=
name|SR_FE_ID_NONE
condition|)
block|{
name|numports
operator|++
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|fecr
operator|&
name|SR_FECR_ID1
operator|)
operator|>>
name|SR_FE_ID1_SHFT
operator|)
operator|!=
name|SR_FE_ID_NONE
condition|)
name|numports
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|numports
operator|==
literal|0
condition|)
return|return
name|NULL
return|;
name|hc
operator|=
name|sr_hardc_pci
expr_stmt|;
name|hcp
operator|=
operator|&
name|sr_hardc_pci
expr_stmt|;
while|while
condition|(
name|hc
condition|)
block|{
name|hcp
operator|=
operator|&
name|hc
operator|->
name|next
expr_stmt|;
name|hc
operator|=
name|hc
operator|->
name|next
expr_stmt|;
block|}
name|MALLOC
argument_list|(
name|hc
argument_list|,
expr|struct
name|sr_hardc
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|hc
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|bzero
argument_list|(
name|hc
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|hc
argument_list|)
argument_list|)
expr_stmt|;
name|MALLOC
argument_list|(
name|hc
operator|->
name|sc
argument_list|,
expr|struct
name|sr_softc
operator|*
argument_list|,
name|numports
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|sr_softc
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|sc
operator|==
name|NULL
condition|)
block|{
name|FREE
argument_list|(
name|hc
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|bzero
argument_list|(
name|hc
operator|->
name|sc
argument_list|,
name|numports
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|sr_softc
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|hcp
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|numports
operator|=
name|numports
expr_stmt|;
name|hc
operator|->
name|cunit
operator|=
name|unit
expr_stmt|;
name|hc
operator|->
name|cardtype
operator|=
name|SR_CRD_N2PCI
expr_stmt|;
name|hc
operator|->
name|plx_base
operator|=
operator|(
name|caddr_t
operator|)
name|plx_vaddr
expr_stmt|;
name|hc
operator|->
name|sca_base
operator|=
name|sca_vaddr
expr_stmt|;
name|hc
operator|->
name|src_put8
operator|=
name|src_put8_mem
expr_stmt|;
name|hc
operator|->
name|src_put16
operator|=
name|src_put16_mem
expr_stmt|;
name|hc
operator|->
name|src_get8
operator|=
name|src_get8_mem
expr_stmt|;
name|hc
operator|->
name|src_get16
operator|=
name|src_get16_mem
expr_stmt|;
comment|/* 	 * Malloc area for tx and rx buffers. For now allocate SRC_WIN_SIZ 	 * (16k) for each buffer. 	 * 	 * Allocate the block below 16M because the N2pci card can only access 	 * 16M memory at a time. 	 * 	 * (We could actually allocate a contiguous block above the 16MB limit, 	 * but this would complicate card programming more than we want to 	 * right now -jrc) 	 */
name|hc
operator|->
name|memsize
operator|=
literal|2
operator|*
name|hc
operator|->
name|numports
operator|*
name|SRC_WIN_SIZ
expr_stmt|;
name|hc
operator|->
name|mem_start
operator|=
name|contigmalloc
argument_list|(
name|hc
operator|->
name|memsize
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
argument_list|,
literal|0ul
argument_list|,
literal|0xfffffful
argument_list|,
literal|0x10000
argument_list|,
literal|0x1000000
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|mem_start
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"src%d: pci: failed to allocate buffer space.\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|hc
operator|->
name|winmsk
operator|=
literal|0xffffffff
expr_stmt|;
name|hc
operator|->
name|mem_end
operator|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
name|u_int
operator|)
name|hc
operator|->
name|mem_start
operator|+
name|hc
operator|->
name|memsize
argument_list|)
expr_stmt|;
name|hc
operator|->
name|mem_pstart
operator|=
name|kvtop
argument_list|(
name|hc
operator|->
name|mem_start
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|hc
operator|->
name|mem_start
argument_list|,
name|hc
operator|->
name|memsize
argument_list|)
expr_stmt|;
for|for
control|(
name|pndx
operator|=
literal|0
init|;
name|pndx
operator|<
name|numports
condition|;
name|pndx
operator|++
control|)
block|{
name|int
name|intf_sw
decl_stmt|;
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
operator|&
name|hc
operator|->
name|sc
index|[
name|pndx
index|]
expr_stmt|;
switch|switch
condition|(
name|pndx
condition|)
block|{
case|case
literal|1
case|:
name|intf_sw
operator|=
name|fecr
operator|&
name|SR_FECR_ID1
operator|>>
name|SR_FE_ID1_SHFT
expr_stmt|;
break|break;
case|case
literal|0
case|:
default|default:
name|intf_sw
operator|=
name|fecr
operator|&
name|SR_FECR_ID0
operator|>>
name|SR_FE_ID0_SHFT
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
if|if
condition|(
name|sr_test_speed
index|[
name|pndx
index|]
operator|>
literal|0
condition|)
name|sc
operator|->
name|clk_cfg
operator|=
name|SR_FLAGS_INT_CLK
expr_stmt|;
else|else
endif|#
directive|endif
switch|switch
condition|(
name|intf_sw
condition|)
block|{
default|default:
case|case
name|SR_FE_ID_RS232
case|:
case|case
name|SR_FE_ID_HSSI
case|:
case|case
name|SR_FE_ID_RS422
case|:
case|case
name|SR_FE_ID_TEST
case|:
break|break;
case|case
name|SR_FE_ID_V35
case|:
name|sc
operator|->
name|clk_cfg
operator|=
name|SR_FLAGS_EXT_SEP_CLK
expr_stmt|;
break|break;
case|case
name|SR_FE_ID_X21
case|:
name|sc
operator|->
name|clk_cfg
operator|=
name|SR_FLAGS_EXT_CLK
expr_stmt|;
break|break;
block|}
block|}
operator|*
name|fecrp
operator|=
name|SR_FECR_DTR0
operator||
name|SR_FECR_DTR1
operator||
name|SR_FECR_TE0
operator||
name|SR_FECR_TE1
expr_stmt|;
name|srattach
argument_list|(
name|hc
argument_list|)
expr_stmt|;
return|return
name|hc
return|;
block|}
end_function

begin_comment
comment|/*  * Register the ports on the adapter.  * Fill in the info for each port. #ifndef NETGRAPH  * Attach each port to sppp and bpf. #endif  */
end_comment

begin_function
specifier|static
name|int
name|srattach
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|hc
operator|->
name|sc
decl_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
name|int
name|unit
decl_stmt|;
comment|/* index: channel w/in card */
comment|/* 	 * Report Card configuration information before we start configuring 	 * each channel on the card... 	 */
name|printf
argument_list|(
literal|"src%d: %uK RAM (%d mempages) @ %08x-%08x, %u ports.\n"
argument_list|,
name|hc
operator|->
name|cunit
argument_list|,
name|hc
operator|->
name|memsize
operator|/
literal|1024
argument_list|,
name|hc
operator|->
name|mempages
argument_list|,
operator|(
name|u_int
operator|)
name|hc
operator|->
name|mem_start
argument_list|,
operator|(
name|u_int
operator|)
name|hc
operator|->
name|mem_end
argument_list|,
name|hc
operator|->
name|numports
argument_list|)
expr_stmt|;
name|src_init
argument_list|(
name|hc
argument_list|)
expr_stmt|;
name|sr_init_sca
argument_list|(
name|hc
argument_list|)
expr_stmt|;
comment|/* 	 * Now configure each port on the card. 	 */
for|for
control|(
name|unit
operator|=
literal|0
init|;
name|unit
operator|<
name|hc
operator|->
name|numports
condition|;
name|sc
operator|++
operator|,
name|unit
operator|++
control|)
block|{
name|sc
operator|->
name|hc
operator|=
name|hc
expr_stmt|;
name|sc
operator|->
name|subunit
operator|=
name|unit
expr_stmt|;
name|sc
operator|->
name|unit
operator|=
name|next_sc_unit
expr_stmt|;
name|next_sc_unit
operator|++
expr_stmt|;
name|sc
operator|->
name|scachan
operator|=
name|unit
operator|%
name|NCHAN
expr_stmt|;
name|sr_init_rx_dmac
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sr_init_tx_dmac
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sr_init_msci
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr%d: Adapter %d, port %d.\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|hc
operator|->
name|cunit
argument_list|,
name|sc
operator|->
name|subunit
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|ifp
operator|=
operator|&
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
expr_stmt|;
name|ifp
operator|->
name|if_softc
operator|=
name|sc
expr_stmt|;
name|ifp
operator|->
name|if_unit
operator|=
name|sc
operator|->
name|unit
expr_stmt|;
name|ifp
operator|->
name|if_name
operator|=
literal|"sr"
expr_stmt|;
name|ifp
operator|->
name|if_mtu
operator|=
name|PP_MTU
expr_stmt|;
name|ifp
operator|->
name|if_flags
operator|=
name|IFF_POINTOPOINT
operator||
name|IFF_MULTICAST
expr_stmt|;
name|ifp
operator|->
name|if_ioctl
operator|=
name|srioctl
expr_stmt|;
name|ifp
operator|->
name|if_start
operator|=
name|srstart
expr_stmt|;
name|ifp
operator|->
name|if_watchdog
operator|=
name|srwatchdog
expr_stmt|;
name|sc
operator|->
name|ifsppp
operator|.
name|pp_flags
operator|=
name|PP_KEEPALIVE
expr_stmt|;
name|sppp_attach
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|)
operator|&
name|sc
operator|->
name|ifsppp
argument_list|)
expr_stmt|;
name|if_attach
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|bpfattach
argument_list|(
name|ifp
argument_list|,
name|DLT_PPP
argument_list|,
name|PPP_HEADER_LEN
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
comment|/* 		 * we have found a node, make sure our 'type' is availabe. 		 */
if|if
condition|(
name|ngsr_done_init
operator|==
literal|0
condition|)
name|ngsr_init
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|ng_make_node_common
argument_list|(
operator|&
name|typestruct
argument_list|,
operator|&
name|sc
operator|->
name|node
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|sc
operator|->
name|node
operator|->
name|private
operator|=
name|sc
expr_stmt|;
name|callout_handle_init
argument_list|(
operator|&
name|sc
operator|->
name|handle
argument_list|)
expr_stmt|;
name|sc
operator|->
name|xmitq
operator|.
name|ifq_maxlen
operator|=
name|IFQ_MAXLEN
expr_stmt|;
name|sc
operator|->
name|xmitq_hipri
operator|.
name|ifq_maxlen
operator|=
name|IFQ_MAXLEN
expr_stmt|;
name|sprintf
argument_list|(
name|sc
operator|->
name|nodename
argument_list|,
literal|"%s%d"
argument_list|,
name|NG_SR_NODE_TYPE
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|ng_name_node
argument_list|(
name|sc
operator|->
name|node
argument_list|,
name|sc
operator|->
name|nodename
argument_list|)
condition|)
block|{
name|ng_rmnode
argument_list|(
name|sc
operator|->
name|node
argument_list|)
expr_stmt|;
name|ng_unref
argument_list|(
name|sc
operator|->
name|node
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|sc
operator|->
name|running
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_OFF
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * N2 Interrupt Service Routine  *  * First figure out which SCA gave the interrupt.  * Process it.  * See if there is other interrupts pending.  * Repeat until there no interrupts remain.  */
end_comment

begin_function
specifier|static
name|void
name|srintr
parameter_list|(
name|int
name|unit
parameter_list|)
block|{
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|;
name|hc
operator|=
operator|&
name|sr_hardc
index|[
name|unit
index|]
expr_stmt|;
name|srintr_hc
argument_list|(
name|hc
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|void
name|srintr_hc
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|)
block|{
name|sca_regs
modifier|*
name|sca
init|=
name|hc
operator|->
name|sca
decl_stmt|;
comment|/* MSCI register tree */
name|u_char
name|isr0
decl_stmt|,
name|isr1
decl_stmt|,
name|isr2
decl_stmt|;
comment|/* interrupt statii captured */
if|#
directive|if
name|BUGGY
operator|>
literal|1
name|printf
argument_list|(
literal|"sr: srintr_hc(hc=%08x)\n"
argument_list|,
name|hc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Since multiple interfaces may share this interrupt, we must loop 	 * until no interrupts are still pending service. 	 */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* 		 * Read all three interrupt status registers from the N2 		 * card... 		 */
name|isr0
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|sca
operator|->
name|isr0
argument_list|)
expr_stmt|;
name|isr1
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|sca
operator|->
name|isr1
argument_list|)
expr_stmt|;
name|isr2
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|sca
operator|->
name|isr2
argument_list|)
expr_stmt|;
comment|/* 		 * If all three registers returned 0, we've finished 		 * processing interrupts from this device, so we can quit 		 * this loop... 		 */
if|if
condition|(
operator|(
name|isr0
operator||
name|isr1
operator||
name|isr2
operator|)
operator|==
literal|0
condition|)
break|break;
if|#
directive|if
name|BUGGY
operator|>
literal|2
name|printf
argument_list|(
literal|"src%d: srintr_hc isr0 %x, isr1 %x, isr2 %x\n"
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|unit
argument_list|,
name|isr0
argument_list|,
name|isr1
argument_list|,
name|isr2
argument_list|)
expr_stmt|;
else|#
directive|else
name|hc
operator|->
name|cunit
operator|,
name|isr0
operator|,
name|isr1
operator|,
name|isr2
block|)
empty_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
endif|#
directive|endif
comment|/* 		 * Now we can dispatch the interrupts. Since we don't expect 		 * either MSCI or timer interrupts, we'll test for DMA 		 * interrupts first... 		 */
if|if
condition|(
name|isr1
condition|)
comment|/* DMA-initiated interrupt */
name|sr_dmac_intr
argument_list|(
name|hc
argument_list|,
name|isr1
argument_list|)
expr_stmt|;
if|if
condition|(
name|isr0
condition|)
comment|/* serial part IRQ? */
name|sr_msci_intr
argument_list|(
name|hc
argument_list|,
name|isr0
argument_list|)
expr_stmt|;
if|if
condition|(
name|isr2
condition|)
comment|/* timer-initiated interrupt */
name|sr_timer_intr
argument_list|(
name|hc
argument_list|,
name|isr2
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|}
comment|/*  * This will only start the transmitter. It is assumed that the data  * is already there.  * It is normally called from srstart() or sr_dmac_intr().  */
end_comment

begin_function
unit|static
name|void
name|sr_xmit
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
block|{
name|u_short
name|cda_value
decl_stmt|;
comment|/* starting descriptor */
name|u_short
name|eda_value
decl_stmt|;
comment|/* ending descriptor */
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* O/S Network Services */
endif|#
directive|endif
comment|/* NETGRAPH */
name|dmac_channel
modifier|*
name|dmac
decl_stmt|;
comment|/* DMA channel registers */
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|printf
argument_list|(
literal|"sr: sr_xmit( sc=%08x)\n"
argument_list|,
name|sc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|hc
operator|=
name|sc
operator|->
name|hc
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|ifp
operator|=
operator|&
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
name|dmac
operator|=
operator|&
name|hc
operator|->
name|sca
operator|->
name|dmac
index|[
name|DMAC_TXCH
argument_list|(
name|sc
operator|->
name|scachan
argument_list|)
index|]
expr_stmt|;
comment|/* 	 * Get the starting and ending addresses of the chain to be 	 * transmitted and pass these on to the DMA engine on-chip. 	 */
name|cda_value
operator|=
name|sc
operator|->
name|block
index|[
name|sc
operator|->
name|txb_next_tx
index|]
operator|.
name|txdesc
operator|+
name|hc
operator|->
name|mem_pstart
expr_stmt|;
name|cda_value
operator|&=
literal|0x00ffff
expr_stmt|;
name|eda_value
operator|=
name|sc
operator|->
name|block
index|[
name|sc
operator|->
name|txb_next_tx
index|]
operator|.
name|txeda
operator|+
name|hc
operator|->
name|mem_pstart
expr_stmt|;
name|eda_value
operator|&=
literal|0x00ffff
expr_stmt|;
name|SRC_PUT16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|cda
argument_list|,
name|cda_value
argument_list|)
expr_stmt|;
name|SRC_PUT16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|eda
argument_list|,
name|eda_value
argument_list|)
expr_stmt|;
comment|/* 	 * Now we'll let the DMA status register know about this change 	 */
name|SRC_PUT8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|,
name|SCA_DSR_DE
argument_list|)
expr_stmt|;
name|sc
operator|->
name|xmit_busy
operator|=
literal|1
expr_stmt|;
comment|/* mark transmitter busy */
if|#
directive|if
name|BUGGY
operator|>
literal|2
name|printf
argument_list|(
literal|"sr%d: XMIT  cda=%04x, eda=%4x, rcda=%08lx\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|cda_value
argument_list|,
name|eda_value
argument_list|,
name|sc
operator|->
name|block
index|[
name|sc
operator|->
name|txb_next_tx
index|]
operator|.
name|txdesc
operator|+
name|hc
operator|->
name|mem_pstart
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sc
operator|->
name|txb_next_tx
operator|++
expr_stmt|;
comment|/* update next transmit seq# */
if|if
condition|(
name|sc
operator|->
name|txb_next_tx
operator|==
name|SR_TX_BLOCKS
condition|)
comment|/* handle wrap... */
name|sc
operator|->
name|txb_next_tx
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
comment|/* 	 * Finally, we'll set a timout (which will start srwatchdog()) 	 * within the O/S network services layer... 	 */
name|ifp
operator|->
name|if_timer
operator|=
literal|2
expr_stmt|;
comment|/* Value in seconds. */
else|#
directive|else
comment|/* 	 * Don't time out for a while. 	 */
name|sc
operator|->
name|out_dog
operator|=
name|DOG_HOLDOFF
expr_stmt|;
comment|/* give ourself some breathing space*/
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
end_function

begin_comment
comment|/*  * This function will be called from the upper level when a user add a  * packet to be send, and from the interrupt handler after a finished  * transmit.  *  * NOTE: it should run at spl_imp().  *  * This function only place the data in the oncard buffers. It does not  * start the transmition. sr_xmit() does that.  *  * Transmitter idle state is indicated by the IFF_OACTIVE flag.  * The function that clears that should ensure that the transmitter  * and its DMA is in a "good" idle state.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_function
specifier|static
name|void
name|srstart
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
comment|/* channel control structure */
else|#
directive|else
specifier|static
name|void
name|srstart
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
block|{
endif|#
directive|endif
comment|/* NETGRAPH */
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|;
comment|/* card control/config block */
name|int
name|len
decl_stmt|;
comment|/* total length of a packet */
name|int
name|pkts
decl_stmt|;
comment|/* packets placed in DPRAM */
name|int
name|tlen
decl_stmt|;
comment|/* working length of pkt */
name|u_int
name|i
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mtx
decl_stmt|;
comment|/* message buffer from O/S */
name|u_char
modifier|*
name|txdata
decl_stmt|;
comment|/* buffer address in DPRAM */
name|sca_descriptor
modifier|*
name|txdesc
decl_stmt|;
comment|/* working descriptor pointr */
name|struct
name|buf_block
modifier|*
name|blkp
decl_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|printf
argument_list|(
literal|"sr: srstart( ifp=%08x)\n"
argument_list|,
name|ifp
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sc
operator|=
name|ifp
operator|->
name|if_softc
expr_stmt|;
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
operator|)
operator|==
literal|0
condition|)
return|return;
endif|#
directive|endif
comment|/* NETGRAPH */
name|hc
operator|=
name|sc
operator|->
name|hc
expr_stmt|;
comment|/* 	 * It is OK to set the memory window outside the loop because all tx 	 * buffers and descriptors are assumed to be in the same 16K window. 	 */
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
block|{
name|SRC_SET_ON
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
name|SRC_SET_MEM
argument_list|(
name|hc
operator|->
name|iobase
argument_list|,
name|sc
operator|->
name|block
index|[
literal|0
index|]
operator|.
name|txdesc
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Loop to place packets into DPRAM. 	 * 	 * We stay in this loop until there is nothing in 	 * the TX queue left or the tx buffers are full. 	 */
name|top_srstart
label|:
comment|/* 	 * See if we have space for more packets. 	 */
if|if
condition|(
name|sc
operator|->
name|txb_inuse
operator|==
name|SR_TX_BLOCKS
condition|)
block|{
comment|/* out of space? */
ifndef|#
directive|ifndef
name|NETGRAPH
name|ifp
operator|->
name|if_flags
operator||=
name|IFF_OACTIVE
expr_stmt|;
comment|/* yes, mark active */
else|#
directive|else
comment|/*ifp->if_flags |= IFF_OACTIVE;*/
comment|/* yes, mark active */
endif|#
directive|endif
comment|/* NETGRAPH */
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_OFF
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|9
name|printf
argument_list|(
literal|"sr%d.srstart: sc->txb_inuse=%d; DPRAM full...\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|txb_inuse
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
comment|/* 	 * OK, the card can take more traffic.  Let's see if there's any 	 * pending from the system... 	 * 	 * NOTE: 	 * The architecture of the networking interface doesn't 	 * actually call us like 'write()', providing an address.  We get 	 * started, a lot like a disk strategy routine, and we actually call 	 * back out to the system to get traffic to send... 	 * 	 * NOTE: 	 * If we were gonna run through another layer, we would use a 	 * dispatch table to select the service we're getting a packet 	 * from... 	 */
ifndef|#
directive|ifndef
name|NETGRAPH
name|mtx
operator|=
name|sppp_dequeue
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|IF_DEQUEUE
argument_list|(
operator|&
name|sc
operator|->
name|xmitq_hipri
argument_list|,
name|mtx
argument_list|)
expr_stmt|;
if|if
condition|(
name|mtx
operator|==
name|NULL
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
operator|&
name|sc
operator|->
name|xmitq
argument_list|,
name|mtx
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* NETGRAPH */
if|if
condition|(
operator|!
name|mtx
condition|)
block|{
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_OFF
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * OK, we got a packet from the network services of the O/S. Now we 	 * can move it into the DPRAM (under control of the descriptors) and 	 * fire it off... 	 */
name|pkts
operator|=
literal|0
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
comment|/* counts # of granules used */
name|blkp
operator|=
operator|&
name|sc
operator|->
name|block
index|[
name|sc
operator|->
name|txb_new
index|]
expr_stmt|;
comment|/* address of free granule */
name|txdesc
operator|=
operator|(
name|sca_descriptor
operator|*
operator|)
operator|(
name|hc
operator|->
name|mem_start
operator|+
operator|(
name|blkp
operator|->
name|txdesc
operator|&
name|hc
operator|->
name|winmsk
operator|)
operator|)
expr_stmt|;
name|txdata
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|(
name|hc
operator|->
name|mem_start
operator|+
operator|(
name|blkp
operator|->
name|txstart
operator|&
name|hc
operator|->
name|winmsk
operator|)
operator|)
expr_stmt|;
comment|/* 	 * Now we'll try to install as many packets as possible into the 	 * card's DP RAM buffers. 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* perform actual copy of packet */
name|len
operator|=
name|mtx
operator|->
name|m_pkthdr
operator|.
name|len
expr_stmt|;
comment|/* length of message */
if|#
directive|if
name|BUGGY
operator|>
literal|1
name|printf
argument_list|(
literal|"sr%d.srstart: mbuf @ %08lx, %d bytes\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|mtx
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NETGRAPH
if|if
condition|(
name|ifp
operator|->
name|if_bpf
condition|)
name|bpf_mtap
argument_list|(
name|ifp
argument_list|,
name|mtx
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|outbytes
operator|+=
name|len
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/* 		 * We can perform a straight copy because the tranmit 		 * buffers won't wrap. 		 */
name|m_copydata
argument_list|(
name|mtx
argument_list|,
literal|0
argument_list|,
name|len
argument_list|,
name|txdata
argument_list|)
expr_stmt|;
comment|/* 		 * Now we know how big the message is gonna be.  We must now 		 * construct the descriptors to drive this message out... 		 */
name|tlen
operator|=
name|len
expr_stmt|;
while|while
condition|(
name|tlen
operator|>
name|SR_BUF_SIZ
condition|)
block|{
comment|/* loop for full granules */
name|txdesc
operator|->
name|stat
operator|=
literal|0
expr_stmt|;
comment|/* reset bits */
name|txdesc
operator|->
name|len
operator|=
name|SR_BUF_SIZ
expr_stmt|;
comment|/* size of granule */
name|tlen
operator|-=
name|SR_BUF_SIZ
expr_stmt|;
name|txdesc
operator|++
expr_stmt|;
comment|/* move to next dscr */
name|txdata
operator|+=
name|SR_BUF_SIZ
expr_stmt|;
comment|/* adjust data addr */
name|i
operator|++
expr_stmt|;
block|}
comment|/* 		 * This section handles the setting of the final piece of a 		 * message. 		 */
name|txdesc
operator|->
name|stat
operator|=
name|SCA_DESC_EOM
expr_stmt|;
name|txdesc
operator|->
name|len
operator|=
name|tlen
expr_stmt|;
name|pkts
operator|++
expr_stmt|;
comment|/* 		 * prepare for subsequent packets (if any) 		 */
name|txdesc
operator|++
expr_stmt|;
name|txdata
operator|+=
name|SR_BUF_SIZ
expr_stmt|;
comment|/* next mem granule */
name|i
operator|++
expr_stmt|;
comment|/* count of granules */
comment|/* 		 * OK, we've now placed the message into the DPRAM where it 		 * can be transmitted.  We'll now release the message memory 		 * and update the statistics... 		 */
name|m_freem
argument_list|(
name|mtx
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
operator|++
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_opackets
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|opackets
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/* 		 * Check if we have space for another packet. XXX This is 		 * hardcoded.  A packet can't be larger than 3 buffers (3 x 		 * 512). 		 */
if|if
condition|(
operator|(
name|i
operator|+
literal|3
operator|)
operator|>=
name|blkp
operator|->
name|txmax
condition|)
block|{
comment|/* enough remains? */
if|#
directive|if
name|BUGGY
operator|>
literal|9
name|printf
argument_list|(
literal|"sr%d.srstart: i=%d (%d pkts); card full.\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|i
argument_list|,
name|pkts
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
comment|/* 		 * We'll pull the next message to be sent (if any) 		 */
ifndef|#
directive|ifndef
name|NETGRAPH
name|mtx
operator|=
name|sppp_dequeue
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|IF_DEQUEUE
argument_list|(
operator|&
name|sc
operator|->
name|xmitq_hipri
argument_list|,
name|mtx
argument_list|)
expr_stmt|;
if|if
condition|(
name|mtx
operator|==
name|NULL
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
operator|&
name|sc
operator|->
name|xmitq
argument_list|,
name|mtx
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* NETGRAPH */
if|if
condition|(
operator|!
name|mtx
condition|)
block|{
comment|/* no message?  We're done! */
if|#
directive|if
name|BUGGY
operator|>
literal|9
name|printf
argument_list|(
literal|"sr%d.srstart: pending=0, pkts=%d\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|pkts
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
block|}
name|blkp
operator|->
name|txtail
operator|=
name|i
expr_stmt|;
comment|/* record next free granule */
comment|/* 	 * Mark the last descriptor, so that the SCA know where to stop. 	 */
name|txdesc
operator|--
expr_stmt|;
comment|/* back up to last descriptor in list */
name|txdesc
operator|->
name|stat
operator||=
name|SCA_DESC_EOT
expr_stmt|;
comment|/* mark as end of list */
comment|/* 	 * Now we'll reset the transmit granule's descriptor address so we 	 * can record this in the structure and fire it off w/ the DMA 	 * processor of the serial chip... 	 */
name|txdesc
operator|=
operator|(
name|sca_descriptor
operator|*
operator|)
name|blkp
operator|->
name|txdesc
expr_stmt|;
name|blkp
operator|->
name|txeda
operator|=
call|(
name|u_short
call|)
argument_list|(
operator|(
name|u_int
operator|)
operator|&
name|txdesc
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|txb_inuse
operator|++
expr_stmt|;
comment|/* update inuse status */
name|sc
operator|->
name|txb_new
operator|++
expr_stmt|;
comment|/* new traffic wuz added */
if|if
condition|(
name|sc
operator|->
name|txb_new
operator|==
name|SR_TX_BLOCKS
condition|)
name|sc
operator|->
name|txb_new
operator|=
literal|0
expr_stmt|;
comment|/* 	 * If the tranmitter wasn't marked as "busy" we will force it to be 	 * started... 	 */
if|if
condition|(
name|sc
operator|->
name|xmit_busy
operator|==
literal|0
condition|)
block|{
name|sr_xmit
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|9
name|printf
argument_list|(
literal|"sr%d.srstart: called sr_xmit()\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
goto|goto
name|top_srstart
goto|;
block|}
ifndef|#
directive|ifndef
name|NETGRAPH
comment|/*  * Handle ioctl's at the device level, though we *will* call up  * a layer...  */
if|#
directive|if
name|BUGGY
operator|>
literal|2
specifier|static
name|int
name|bug_splats
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
endif|#
directive|endif
specifier|static
name|int
name|srioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
block|{
name|int
name|s
decl_stmt|,
name|error
decl_stmt|,
name|was_up
decl_stmt|,
name|should_be_up
decl_stmt|;
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|printf
argument_list|(
literal|"sr%d: srioctl(ifp=%08x, cmd=%08x, data=%08x)\n"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|,
name|ifp
argument_list|,
name|cmd
argument_list|,
name|data
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|was_up
operator|=
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
expr_stmt|;
name|error
operator|=
name|sppp_ioctl
argument_list|(
name|ifp
argument_list|,
name|cmd
argument_list|,
name|data
argument_list|)
expr_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|1
name|printf
argument_list|(
literal|"sr%d: ioctl: ifsppp.pp_flags = %08x, if_flags %08x.\n"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|,
operator|(
operator|(
expr|struct
name|sppp
operator|*
operator|)
name|ifp
operator|)
operator|->
name|pp_flags
argument_list|,
name|ifp
operator|->
name|if_flags
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error
condition|)
return|return
name|error
return|;
if|if
condition|(
operator|(
name|cmd
operator|!=
name|SIOCSIFFLAGS
operator|)
operator|&&
operator|(
name|cmd
operator|!=
name|SIOCSIFADDR
operator|)
condition|)
block|{
if|#
directive|if
name|BUGGY
operator|>
literal|2
if|if
condition|(
name|bug_splats
index|[
name|sc
operator|->
name|unit
index|]
operator|++
operator|<
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"sr(%d).if_addrlist = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_addrlist
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_bpf = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_bpf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_init = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_init
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_output = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_output
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_start = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_start
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_done = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_done
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_ioctl = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_ioctl
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_reset = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_reset
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sr(%d).if_watchdog = %08x\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
name|ifp
operator|->
name|if_watchdog
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
literal|0
return|;
block|}
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|should_be_up
operator|=
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
expr_stmt|;
if|if
condition|(
operator|!
name|was_up
operator|&&
name|should_be_up
condition|)
block|{
comment|/* 		 * Interface should be up -- start it. 		 */
name|sr_up
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|srstart
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
comment|/* 		 * XXX Clear the IFF_UP flag so that the link will only go 		 * up after sppp lcp and ipcp negotiation. 		 */
comment|/* ifp->if_flags&= ~IFF_UP; */
block|}
elseif|else
if|if
condition|(
name|was_up
operator|&&
operator|!
name|should_be_up
condition|)
block|{
comment|/* 		 * Interface should be down -- stop it. 		 */
name|sr_down
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sppp_flush
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/*  * This is to catch lost tx interrupts.  */
specifier|static
name|void
ifndef|#
directive|ifndef
name|NETGRAPH
name|srwatchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
else|#
directive|else
function|srwatchdog
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
endif|#
directive|endif
comment|/* NETGRAPH */
block|{
name|int
name|got_st0
decl_stmt|,
name|got_st1
decl_stmt|,
name|got_st3
decl_stmt|,
name|got_dsr
decl_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|ifp
operator|->
name|if_softc
decl_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
name|struct
name|sr_hardc
modifier|*
name|hc
init|=
name|sc
operator|->
name|hc
decl_stmt|;
name|msci_channel
modifier|*
name|msci
init|=
operator|&
name|hc
operator|->
name|sca
operator|->
name|msci
index|[
name|sc
operator|->
name|scachan
index|]
decl_stmt|;
name|dmac_channel
modifier|*
name|dmac
init|=
operator|&
name|sc
operator|->
name|hc
operator|->
name|sca
operator|->
name|dmac
index|[
name|sc
operator|->
name|scachan
index|]
decl_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|0
ifndef|#
directive|ifndef
name|NETGRAPH
name|printf
argument_list|(
literal|"srwatchdog(unit=%d)\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"srwatchdog(unit=%d)\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NETGRAPH
if|if
condition|(
operator|!
operator|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
operator|)
condition|)
return|return;
name|ifp
operator|->
name|if_oerrors
operator|++
expr_stmt|;
comment|/* update output error count */
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|oerrors
operator|++
expr_stmt|;
comment|/* update output error count */
endif|#
directive|endif
comment|/* NETGRAPH */
name|got_st0
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st0
argument_list|)
expr_stmt|;
name|got_st1
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st1
argument_list|)
expr_stmt|;
name|got_st3
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st3
argument_list|)
expr_stmt|;
name|got_dsr
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
if|#
directive|if
literal|0
block|if (ifp->if_flags& IFF_DEBUG)
endif|#
directive|endif
name|printf
argument_list|(
literal|"sr%d: transmit failed, "
else|#
directive|else
comment|/* NETGRAPH */
argument|printf(
literal|"sr%d: transmit failed, "
endif|#
directive|endif
comment|/* NETGRAPH */
literal|"ST0 %02x, ST1 %02x, ST3 %02x, DSR %02x.\n"
argument|, 		       sc->unit, 		       got_st0, got_st1, got_st3, got_dsr);  	if (SRC_GET8(hc->sca_base, msci->st1)& SCA_ST1_UDRN) { 		SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_TXABORT); 		SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_TXENABLE); 		SRC_PUT8(hc->sca_base, msci->st1, SCA_ST1_UDRN); 	} 	sc->xmit_busy =
literal|0
argument|;
ifndef|#
directive|ifndef
name|NETGRAPH
argument|ifp->if_flags&= ~IFF_OACTIVE;
else|#
directive|else
comment|/*ifp->if_flags&= ~IFF_OACTIVE; */
endif|#
directive|endif
comment|/* NETGRAPH */
argument|if (sc->txb_inuse&& --sc->txb_inuse) 		sr_xmit(sc);
ifndef|#
directive|ifndef
name|NETGRAPH
argument|srstart(ifp);
comment|/* restart transmitter */
else|#
directive|else
argument|srstart(sc);
comment|/* restart transmitter */
endif|#
directive|endif
comment|/* NETGRAPH */
argument|}  static void sr_up(struct sr_softc *sc) { 	u_int *fecrp; 	struct sr_hardc *hc = sc->hc; 	sca_regs *sca = hc->sca; 	msci_channel *msci =&sca->msci[sc->scachan];
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_up(sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
comment|/* 	 * Enable transmitter and receiver. Raise DTR and RTS. Enable 	 * interrupts. 	 * 	 * XXX What about using AUTO mode in msci->md0 ??? 	 */
argument|SRC_PUT8(hc->sca_base, msci->ctl, 		 SRC_GET8(hc->sca_base, msci->ctl)& ~SCA_CTL_RTS);  	if (sc->scachan ==
literal|0
argument|) 		switch (hc->cardtype) { 		case SR_CRD_N2: 			outb(hc->iobase + SR_MCR, 			     (inb(hc->iobase + SR_MCR)& ~SR_MCR_DTR0)); 			break; 		case SR_CRD_N2PCI: 			fecrp = (u_int *)(hc->sca_base + SR_FECR); 			*fecrp&= ~SR_FECR_DTR0; 			break; 		} 	else 		switch (hc->cardtype) { 		case SR_CRD_N2: 			outb(hc->iobase + SR_MCR, 			     (inb(hc->iobase + SR_MCR)& ~SR_MCR_DTR1)); 			break; 		case SR_CRD_N2PCI: 			fecrp = (u_int *)(hc->sca_base + SR_FECR); 			*fecrp&= ~SR_FECR_DTR1; 			break; 		}  	if (sc->scachan ==
literal|0
argument|) { 		SRC_PUT8(hc->sca_base, sca->ier0, 			 SRC_GET8(hc->sca_base, sca->ier0) |
literal|0x000F
argument|); 		SRC_PUT8(hc->sca_base, sca->ier1, 			 SRC_GET8(hc->sca_base, sca->ier1) |
literal|0x000F
argument|); 	} else { 		SRC_PUT8(hc->sca_base, sca->ier0, 			 SRC_GET8(hc->sca_base, sca->ier0) |
literal|0x00F0
argument|); 		SRC_PUT8(hc->sca_base, sca->ier1, 			 SRC_GET8(hc->sca_base, sca->ier1) |
literal|0x00F0
argument|); 	}  	SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_RXENABLE); 	inb(hc->iobase);
comment|/* XXX slow it down a bit. */
argument|SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_TXENABLE);
ifndef|#
directive|ifndef
name|NETGRAPH
ifdef|#
directive|ifdef
name|USE_MODEMCK
argument|if (sr_watcher ==
literal|0
argument|) 		sr_modemck(NULL);
endif|#
directive|endif
else|#
directive|else
comment|/* NETGRAPH */
argument|untimeout(ngsr_watchdog_frame, sc, sc->handle); 	sc->handle = timeout(ngsr_watchdog_frame, sc, hz); 	sc->running =
literal|1
argument|;
endif|#
directive|endif
comment|/* NETGRAPH */
argument|}  static void sr_down(struct sr_softc *sc) { 	u_int *fecrp; 	struct sr_hardc *hc = sc->hc; 	sca_regs *sca = hc->sca; 	msci_channel *msci =&sca->msci[sc->scachan];
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_down(sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NETGRAPH
argument|untimeout(ngsr_watchdog_frame, sc, sc->handle); 	sc->running =
literal|0
argument|;
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/* 	 * Disable transmitter and receiver. Lower DTR and RTS. Disable 	 * interrupts. 	 */
argument|SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_RXDISABLE); 	inb(hc->iobase);
comment|/* XXX slow it down a bit. */
argument|SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_TXDISABLE);  	SRC_PUT8(hc->sca_base, msci->ctl, 		 SRC_GET8(hc->sca_base, msci->ctl) | SCA_CTL_RTS);  	if (sc->scachan ==
literal|0
argument|) 		switch (hc->cardtype) { 		case SR_CRD_N2: 			outb(hc->iobase + SR_MCR, 			     (inb(hc->iobase + SR_MCR) | SR_MCR_DTR0)); 			break; 		case SR_CRD_N2PCI: 			fecrp = (u_int *)(hc->sca_base + SR_FECR); 			*fecrp |= SR_FECR_DTR0; 			break; 		} 	else 		switch (hc->cardtype) { 		case SR_CRD_N2: 			outb(hc->iobase + SR_MCR, 			     (inb(hc->iobase + SR_MCR) | SR_MCR_DTR1)); 			break; 		case SR_CRD_N2PCI: 			fecrp = (u_int *)(hc->sca_base + SR_FECR); 			*fecrp |= SR_FECR_DTR1; 			break; 		}  	if (sc->scachan ==
literal|0
argument|) { 		SRC_PUT8(hc->sca_base, sca->ier0, 			 SRC_GET8(hc->sca_base, sca->ier0)& ~
literal|0x0F
argument|); 		SRC_PUT8(hc->sca_base, sca->ier1, 			 SRC_GET8(hc->sca_base, sca->ier1)& ~
literal|0x0F
argument|); 	} else { 		SRC_PUT8(hc->sca_base, sca->ier0, 			 SRC_GET8(hc->sca_base, sca->ier0)& ~
literal|0xF0
argument|); 		SRC_PUT8(hc->sca_base, sca->ier1, 			 SRC_GET8(hc->sca_base, sca->ier1)& ~
literal|0xF0
argument|); 	} }
comment|/*  * Initialize the card, allocate memory for the sr_softc structures  * and fill in the pointers.  */
argument|static void src_init(struct sr_hardc *hc) { 	struct sr_softc *sc = hc->sc; 	int x; 	u_int chanmem; 	u_int bufmem; 	u_int next; 	u_int descneeded;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"src_init(hc=%08x)\n"
argument|, hc);
endif|#
directive|endif
argument|chanmem = hc->memsize / hc->numports; 	next =
literal|0
argument|;  	for (x =
literal|0
argument|; x< hc->numports; x++, sc++) { 		int blk;  		for (blk =
literal|0
argument|; blk< SR_TX_BLOCKS; blk++) { 			sc->block[blk].txdesc = next; 			bufmem = (
literal|16
argument|*
literal|1024
argument|) / SR_TX_BLOCKS; 			descneeded = bufmem / SR_BUF_SIZ;  			sc->block[blk].txstart = sc->block[blk].txdesc 			    + ((((descneeded * sizeof(sca_descriptor)) 				 / SR_BUF_SIZ) +
literal|1
argument|) 			       * SR_BUF_SIZ);  			sc->block[blk].txend = next + bufmem; 			sc->block[blk].txmax = 			    (sc->block[blk].txend - sc->block[blk].txstart) 			    / SR_BUF_SIZ; 			next += bufmem;
if|#
directive|if
name|BUGGY
operator|>
literal|2
argument|printf(
literal|"sr%d: blk %d: txdesc %08x, txstart %08x\n"
argument|, 			       sc->unit, blk, 			       sc->block[blk].txdesc, sc->block[blk].txstart);
endif|#
directive|endif
argument|}  		sc->rxdesc = next; 		bufmem = chanmem - (bufmem * SR_TX_BLOCKS); 		descneeded = bufmem / SR_BUF_SIZ; 		sc->rxstart = sc->rxdesc + 		    ((((descneeded * sizeof(sca_descriptor)) / 		       SR_BUF_SIZ) +
literal|1
argument|) * SR_BUF_SIZ); 		sc->rxend = next + bufmem; 		sc->rxmax = (sc->rxend - sc->rxstart) / SR_BUF_SIZ; 		next += bufmem; 	} }
comment|/*  * The things done here are channel independent.  *  * Configure the sca waitstates.  * Configure the global interrupt registers.  * Enable master dma enable.  */
argument|static void sr_init_sca(struct sr_hardc *hc) { 	sca_regs *sca = hc->sca;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_init_sca(hc=%08x)\n"
argument|, hc);
endif|#
directive|endif
comment|/* 	 * Do the wait registers. Set everything to 0 wait states. 	 */
argument|SRC_PUT8(hc->sca_base, sca->pabr0,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, sca->pabr1,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, sca->wcrl,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, sca->wcrm,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, sca->wcrh,
literal|0
argument|);
comment|/* 	 * Configure the interrupt registers. Most are cleared until the 	 * interface is configured. 	 */
argument|SRC_PUT8(hc->sca_base, sca->ier0,
literal|0x00
argument|);
comment|/* MSCI interrupts. */
argument|SRC_PUT8(hc->sca_base, sca->ier1,
literal|0x00
argument|);
comment|/* DMAC interrupts */
argument|SRC_PUT8(hc->sca_base, sca->ier2,
literal|0x00
argument|);
comment|/* TIMER interrupts. */
argument|SRC_PUT8(hc->sca_base, sca->itcr,
literal|0x00
argument|);
comment|/* Use ivr and no intr 							 * ack */
argument|SRC_PUT8(hc->sca_base, sca->ivr,
literal|0x40
argument|);
comment|/* Interrupt vector. */
argument|SRC_PUT8(hc->sca_base, sca->imvr,
literal|0x40
argument|);
comment|/* 	 * Configure the timers. XXX Later 	 */
comment|/* 	 * Set the DMA channel priority to rotate between all four channels. 	 * 	 * Enable all dma channels. 	 */
argument|SRC_PUT8(hc->sca_base, sca->pcr, SCA_PCR_PR2); 	SRC_PUT8(hc->sca_base, sca->dmer, SCA_DMER_EN); }
comment|/*  * Configure the msci  *  * NOTE: The serial port configuration is hardcoded at the moment.  */
argument|static void sr_init_msci(struct sr_softc *sc) { 	int portndx;
comment|/* on-board port number */
argument|u_int mcr_v;
comment|/* contents of modem control */
argument|u_int *fecrp;
comment|/* pointer for PCI's MCR i/o */
argument|struct sr_hardc *hc = sc->hc; 	msci_channel *msci =&hc->sca->msci[sc->scachan];
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
argument|int br_v;
comment|/* contents for BR divisor */
argument|int etcndx;
comment|/* index into ETC table */
argument|int fifo_v
argument_list|,
argument|gotspeed;
comment|/* final tabled speed found */
argument|int tmc_v;
comment|/* timer control register */
argument|int wanted;
comment|/* speed (bitrate) wanted... */
argument|struct rate_line *rtp;
endif|#
directive|endif
argument|portndx = sc->scachan;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr: sr_init_msci( sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
argument|SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_RESET); 	SRC_PUT8(hc->sca_base, msci->md0, SCA_MD0_CRC_1 | 		 SCA_MD0_CRC_CCITT | 		 SCA_MD0_CRC_ENABLE | 		 SCA_MD0_MODE_HDLC); 	SRC_PUT8(hc->sca_base, msci->md1, SCA_MD1_NOADDRCHK); 	SRC_PUT8(hc->sca_base, msci->md2, SCA_MD2_DUPLEX | SCA_MD2_NRZ);
comment|/* 	 * According to the manual I should give a reset after changing the 	 * mode registers. 	 */
argument|SRC_PUT8(hc->sca_base, msci->cmd, SCA_CMD_RXRESET); 	SRC_PUT8(hc->sca_base, msci->ctl, SCA_CTL_IDLPAT | 		 SCA_CTL_UDRNC | 		 SCA_CTL_RTS);
comment|/* 	 * XXX Later we will have to support different clock settings. 	 */
argument|switch (sc->clk_cfg) { 	default:
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%: clk_cfg=%08x, selected default clock.\n"
argument|, 		       portndx, sc->clk_cfg);
endif|#
directive|endif
comment|/* FALLTHROUGH */
argument|case SR_FLAGS_EXT_CLK:
comment|/* 		 * For now all interfaces are programmed to use the RX clock 		 * for the TX clock. 		 */
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: External Clock Selected.\n"
argument|, portndx);
endif|#
directive|endif
argument|SRC_PUT8(hc->sca_base, msci->rxs,
literal|0
argument|); 		SRC_PUT8(hc->sca_base, msci->txs,
literal|0
argument|); 		break;  	case SR_FLAGS_EXT_SEP_CLK:
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: Split Clocking Selected.\n"
argument|, portndx);
endif|#
directive|endif
if|#
directive|if
literal|1
argument|SRC_PUT8(hc->sca_base, msci->rxs,
literal|0
argument|); 		SRC_PUT8(hc->sca_base, msci->txs,
literal|0
argument|);
else|#
directive|else
argument|SRC_PUT8(hc->sca_base, msci->rxs, 			 SCA_RXS_CLK_RXC0 | SCA_RXS_DIV1);
comment|/* 		 * We need to configure the internal bit clock for the 		 * transmitter's channel... 		 */
argument|SRC_PUT8(hc->sca_base, msci->txs, 			 SCA_TXS_CLK_RX | SCA_TXS_DIV1);
endif|#
directive|endif
argument|break;  	case SR_FLAGS_INT_CLK:
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: Internal Clocking selected.\n"
argument|, portndx);
endif|#
directive|endif
comment|/* 		 * XXX I do need some code to set the baud rate here! 		 */
ifdef|#
directive|ifdef
name|N2_TEST_SPEED
argument|switch (hc->cardtype) { 		case SR_CRD_N2PCI: 			fecrp = (u_int *)(hc->sca_base + SR_FECR); 			mcr_v = *fecrp; 			etcndx =
literal|2
argument|; 			break; 		case SR_CRD_N2: 		default: 			mcr_v = inb(hc->iobase + SR_MCR); 			etcndx =
literal|0
argument|; 		}  		fifo_v =
literal|0x10
argument|;
comment|/* stolen from Linux version */
comment|/* 		 * search for appropriate speed in table, don't calc it: 		 */
argument|wanted = sr_test_speed[portndx]; 		rtp =&n2_rates[
literal|0
argument|];
comment|/* point to first table item */
argument|while ((rtp->target>
literal|0
argument|)
comment|/* search table for speed */
argument|&&(rtp->target != wanted)) 			rtp++;
comment|/* 		 * We've searched the table for a matching speed.  If we've 		 * found the correct rate line, we'll get the pre-calc'd 		 * values for the TMC and baud rate divisor for subsequent 		 * use... 		 */
argument|if (rtp->target>
literal|0
argument|) {
comment|/* use table-provided values */
argument|gotspeed = wanted; 			tmc_v = rtp->tmc_reg; 			br_v = rtp->br_reg; 		} else {
comment|/* otherwise assume 1MBit comm rate */
argument|gotspeed =
literal|10000
argument|; 			tmc_v =
literal|5
argument|; 			br_v =
literal|1
argument|; 		}
comment|/* 		 * Now we mask in the enable clock output for the MCR: 		 */
argument|mcr_v |= etc0vals[etcndx + portndx];
comment|/* 		 * Now we'll program the registers with these speed- related 		 * contents... 		 */
argument|SRC_PUT8(hc->sca_base, msci->tmc, tmc_v); 		SRC_PUT8(hc->sca_base, msci->trc0, fifo_v); 		SRC_PUT8(hc->sca_base, msci->rxs, SCA_RXS_CLK_INT + br_v); 		SRC_PUT8(hc->sca_base, msci->txs, SCA_TXS_CLK_INT + br_v);  		switch (hc->cardtype) { 		case SR_CRD_N2PCI: 			*fecrp = mcr_v; 			break; 		case SR_CRD_N2: 		default: 			outb(hc->iobase + SR_MCR, mcr_v); 		}
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|if (wanted != gotspeed) 			printf(
literal|"sr%d: Speed wanted=%d, found=%d\n"
argument|, 			       wanted, gotspeed);  		printf(
literal|"sr%d: Internal Clock %dx100 BPS, tmc=%d, div=%d\n"
argument|, 		       portndx, gotspeed, tmc_v, br_v);
endif|#
directive|endif
else|#
directive|else
argument|SRC_PUT8(hc->sca_base, msci->rxs, 			 SCA_RXS_CLK_INT | SCA_RXS_DIV1); 		SRC_PUT8(hc->sca_base, msci->txs, 			 SCA_TXS_CLK_INT | SCA_TXS_DIV1);  		SRC_PUT8(hc->sca_base, msci->tmc,
literal|5
argument|);  		if (portndx ==
literal|0
argument|) 			switch (hc->cardtype) { 			case SR_CRD_N2PCI: 				fecrp = (u_int *)(hc->sca_base + SR_FECR); 				*fecrp |= SR_FECR_ETC0; 				break; 			case SR_CRD_N2: 			default: 				mcr_v = inb(hc->iobase + SR_MCR); 				mcr_v |= SR_MCR_ETC0; 				outb(hc->iobase + SR_MCR, mcr_v); 			} 		else 			switch (hc->cardtype) { 			case SR_CRD_N2: 				mcr_v = inb(hc->iobase + SR_MCR); 				mcr_v |= SR_MCR_ETC1; 				outb(hc->iobase + SR_MCR, mcr_v); 				break; 			case SR_CRD_N2PCI: 				fecrp = (u_int *)(hc->sca_base + SR_FECR); 				*fecrp |= SR_FECR_ETC1; 				break; 			}
endif|#
directive|endif
argument|}
comment|/* 	 * XXX Disable all interrupts for now. I think if you are using the 	 * dmac you don't use these interrupts. 	 */
argument|SRC_PUT8(hc->sca_base, msci->ie0,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, msci->ie1,
literal|0x0C
argument|); 	SRC_PUT8(hc->sca_base, msci->ie2,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, msci->fie,
literal|0
argument|);  	SRC_PUT8(hc->sca_base, msci->sa0,
literal|0
argument|); 	SRC_PUT8(hc->sca_base, msci->sa1,
literal|0
argument|);  	SRC_PUT8(hc->sca_base, msci->idl,
literal|0x7E
argument|);
comment|/* set flags value */
argument|SRC_PUT8(hc->sca_base, msci->rrc,
literal|0x0E
argument|); 	SRC_PUT8(hc->sca_base, msci->trc0,
literal|0x10
argument|); 	SRC_PUT8(hc->sca_base, msci->trc1,
literal|0x1F
argument|); }
comment|/*  * Configure the rx dma controller.  */
argument|static void sr_init_rx_dmac(struct sr_softc *sc) { 	struct sr_hardc *hc; 	dmac_channel *dmac; 	sca_descriptor *rxd; 	u_int cda_v
argument_list|,
argument|sarb_v
argument_list|,
argument|rxbuf
argument_list|,
argument|rxda
argument_list|,
argument|rxda_d;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_init_rx_dmac(sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
argument|hc = sc->hc; 	dmac =&hc->sca->dmac[DMAC_RXCH(sc->scachan)];  	if (hc->mempages) 		SRC_SET_MEM(hc->iobase, sc->rxdesc);
comment|/* 	 * This phase initializes the contents of the descriptor table 	 * needed to construct a circular buffer... 	 */
argument|rxd = (sca_descriptor *)(hc->mem_start + (sc->rxdesc& hc->winmsk)); 	rxda_d = (u_int) hc->mem_start - (sc->rxdesc& ~hc->winmsk);  	for (rxbuf = sc->rxstart; 	     rxbuf< sc->rxend; 	     rxbuf += SR_BUF_SIZ, rxd++) {
comment|/* 		 * construct the circular chain... 		 */
argument|rxda = (u_int)& rxd[
literal|1
argument|] - rxda_d + hc->mem_pstart; 		rxd->cp = (u_short)(rxda&
literal|0xffff
argument|);
comment|/* 		 * set the on-card buffer address... 		 */
argument|rxd->bp = (u_short)((rxbuf + hc->mem_pstart)&
literal|0xffff
argument|); 		rxd->bpb = (u_char)(((rxbuf + hc->mem_pstart)>>
literal|16
argument|)&
literal|0xff
argument|);  		rxd->len =
literal|0
argument|;
comment|/* bytes resident w/in granule */
argument|rxd->stat =
literal|0xff
argument|;
comment|/* The sca write here when finished */
argument|}
comment|/* 	 * heal the chain so that the last entry points to the first... 	 */
argument|rxd--; 	rxd->cp = (u_short)((sc->rxdesc + hc->mem_pstart)&
literal|0xffff
argument|);
comment|/* 	 * reset the reception handler's index... 	 */
argument|sc->rxhind =
literal|0
argument|;
comment|/* 	 * We'll now configure the receiver's DMA logic... 	 */
argument|SRC_PUT8(hc->sca_base, dmac->dsr,
literal|0
argument|);
comment|/* Disable DMA transfer */
argument|SRC_PUT8(hc->sca_base, dmac->dcr, SCA_DCR_ABRT);
comment|/* XXX maybe also SCA_DMR_CNTE */
argument|SRC_PUT8(hc->sca_base, dmac->dmr, SCA_DMR_TMOD | SCA_DMR_NF); 	SRC_PUT16(hc->sca_base, dmac->bfl, SR_BUF_SIZ);  	cda_v = (u_short)((sc->rxdesc + hc->mem_pstart)&
literal|0xffff
argument|); 	sarb_v = (u_char)(((sc->rxdesc + hc->mem_pstart)>>
literal|16
argument|)&
literal|0xff
argument|);  	SRC_PUT16(hc->sca_base, dmac->cda, cda_v); 	SRC_PUT8(hc->sca_base, dmac->sarb, sarb_v);  	rxd = (sca_descriptor *)sc->rxstart;  	SRC_PUT16(hc->sca_base, dmac->eda, 		  (u_short)((u_int)& rxd[sc->rxmax -
literal|1
argument|]&
literal|0xffff
argument|));  	SRC_PUT8(hc->sca_base, dmac->dir,
literal|0xF0
argument|);   	SRC_PUT8(hc->sca_base, dmac->dsr, SCA_DSR_DE);
comment|/* Enable DMA */
argument|}
comment|/*  * Configure the TX DMA descriptors.  * Initialize the needed values and chain the descriptors.  */
argument|static void sr_init_tx_dmac(struct sr_softc *sc) { 	int blk; 	u_int txbuf
argument_list|,
argument|txda
argument_list|,
argument|txda_d; 	struct sr_hardc *hc; 	sca_descriptor *txd; 	dmac_channel *dmac; 	struct buf_block *blkp; 	u_int x; 	u_int sarb_v;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_init_tx_dmac(sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
argument|hc = sc->hc; 	dmac =&hc->sca->dmac[DMAC_TXCH(sc->scachan)];  	if (hc->mempages) 		SRC_SET_MEM(hc->iobase, sc->block[
literal|0
argument|].txdesc);
comment|/* 	 * Initialize the array of descriptors for transmission 	 */
argument|for (blk =
literal|0
argument|; blk< SR_TX_BLOCKS; blk++) { 		blkp =&sc->block[blk]; 		txd = (sca_descriptor *)(hc->mem_start 					 + (blkp->txdesc& hc->winmsk)); 		txda_d = (u_int) hc->mem_start 		    - (blkp->txdesc& ~hc->winmsk);  		x =
literal|0
argument|; 		txbuf = blkp->txstart; 		for (; txbuf< blkp->txend; txbuf += SR_BUF_SIZ, txd++) { 			txda = (u_int)& txd[
literal|1
argument|] - txda_d + hc->mem_pstart; 			txd->cp = (u_short)(txda&
literal|0xffff
argument|);  			txd->bp = (u_short)((txbuf + hc->mem_pstart)&
literal|0xffff
argument|); 			txd->bpb = (u_char)(((txbuf + hc->mem_pstart)>>
literal|16
argument|)&
literal|0xff
argument|); 			txd->len =
literal|0
argument|; 			txd->stat =
literal|0
argument|; 			x++; 		}  		txd--; 		txd->cp = (u_short)((blkp->txdesc + hc->mem_pstart)&
literal|0xffff
argument|);  		blkp->txtail = (u_int)txd - (u_int)hc->mem_start; 	}  	SRC_PUT8(hc->sca_base, dmac->dsr,
literal|0
argument|);
comment|/* Disable DMA */
argument|SRC_PUT8(hc->sca_base, dmac->dcr, SCA_DCR_ABRT); 	SRC_PUT8(hc->sca_base, dmac->dmr, SCA_DMR_TMOD | SCA_DMR_NF); 	SRC_PUT8(hc->sca_base, dmac->dir, 		 SCA_DIR_EOT | SCA_DIR_BOF | SCA_DIR_COF);  	sarb_v = (sc->block[
literal|0
argument|].txdesc + hc->mem_pstart)>>
literal|16
argument|; 	sarb_v&=
literal|0x00ff
argument|;  	SRC_PUT8(hc->sca_base, dmac->sarb, (u_char) sarb_v); }
comment|/*  * Look through the descriptors to see if there is a complete packet  * available. Stop if we get to where the sca is busy.  *  * Return the length and status of the packet.  * Return nonzero if there is a packet available.  *  * NOTE:  * It seems that we get the interrupt a bit early. The updateing of  * descriptor values is not always completed when this is called.  */
argument|static int sr_packet_avail(struct sr_softc *sc, int *len, u_char *rxstat) { 	int granules;
comment|/* count of granules in pkt */
argument|int wki
argument_list|,
argument|wko; 	struct sr_hardc *hc; 	sca_descriptor *rxdesc;
comment|/* current descriptor */
argument|sca_descriptor *endp;
comment|/* ending descriptor */
argument|sca_descriptor *cda;
comment|/* starting descriptor */
argument|hc = sc->hc;
comment|/* get card's information */
comment|/* 	 * set up starting descriptor by pulling that info from the DMA half 	 * of the HD chip... 	 */
argument|wki = DMAC_RXCH(sc->scachan); 	wko = SRC_GET16(hc->sca_base, hc->sca->dmac[wki].cda);  	cda = (sca_descriptor *)(hc->mem_start + (wko& hc->winmsk));
if|#
directive|if
name|BUGGY
operator|>
literal|1
argument|printf(
literal|"sr_packet_avail(): wki=%d, wko=%04x, cda=%08x\n"
argument|, 	       wki, wko, cda);
endif|#
directive|endif
comment|/* 	 * open the appropriate memory window and set our expectations... 	 */
argument|if (hc->mempages) { 		SRC_SET_MEM(hc->iobase, sc->rxdesc); 		SRC_SET_ON(hc->iobase); 	} 	rxdesc = (sca_descriptor *) 	    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 	endp = rxdesc; 	rxdesc =&rxdesc[sc->rxhind]; 	endp =&endp[sc->rxmax];  	*len =
literal|0
argument|;
comment|/* reset result total length */
argument|granules =
literal|0
argument|;
comment|/* reset count of granules */
comment|/* 	 * This loop will scan descriptors, but it *will* puke up if we wrap 	 * around to our starting point... 	 */
argument|while (rxdesc != cda) { 		*len += rxdesc->len;
comment|/* increment result length */
argument|granules++;
comment|/* 		 * If we hit a valid packet's completion we'll know we've 		 * got a live one, and that we can deliver the packet. 		 * Since we're only allowed to report a packet available, 		 * somebody else does that... 		 */
argument|if (rxdesc->stat& SCA_DESC_EOM) {
comment|/* End Of Message */
argument|*rxstat = rxdesc->stat;
comment|/* return closing */
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: PKT AVAIL len %d, %x, bufs %u.\n"
argument|, 			       sc->unit, *len, *rxstat, granules);
endif|#
directive|endif
argument|return
literal|1
argument|;
comment|/* indicate success */
argument|}
comment|/* 		 * OK, this packet take up multiple granules.  Move on to 		 * the next descriptor so we can consider it... 		 */
argument|rxdesc++;  		if (rxdesc == endp)
comment|/* recognize& act on wrap point */
argument|rxdesc = (sca_descriptor *) 			    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 	}
comment|/* 	 * Nothing found in the DPRAM.  Let the caller know... 	 */
argument|*len =
literal|0
argument|; 	*rxstat =
literal|0
argument|;  	return
literal|0
argument|; }
comment|/*  * Copy a packet from the on card memory into a provided mbuf.  * Take into account that buffers wrap and that a packet may  * be larger than a buffer.  */
argument|static void sr_copy_rxbuf(struct mbuf *m, struct sr_softc *sc, int len) { 	struct sr_hardc *hc; 	sca_descriptor *rxdesc; 	u_int rxdata; 	u_int rxmax; 	u_int off =
literal|0
argument|; 	u_int tlen;
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_copy_rxbuf(m=%08x,sc=%08x,len=%d)\n"
argument|, 	       m, sc, len);
endif|#
directive|endif
argument|hc = sc->hc;  	rxdata = sc->rxstart + (sc->rxhind * SR_BUF_SIZ); 	rxmax = sc->rxstart + (sc->rxmax * SR_BUF_SIZ);  	rxdesc = (sca_descriptor *) 	    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 	rxdesc =&rxdesc[sc->rxhind];
comment|/* 	 * Using the count of bytes in the received packet, we decrement it 	 * for each granule (controller by an SCA descriptor) to control the 	 * looping... 	 */
argument|while (len) {
comment|/* 		 * tlen gets the length of *this* granule... ...which is 		 * then copied to the target buffer. 		 */
argument|tlen = (len< SR_BUF_SIZ) ? len : SR_BUF_SIZ;  		if (hc->mempages) 			SRC_SET_MEM(hc->iobase, rxdata);  		bcopy(hc->mem_start + (rxdata& hc->winmsk), 		      mtod(m, caddr_t) +off, 		      tlen);  		off += tlen; 		len -= tlen;
comment|/* 		 * now, return to the descriptor's window in DPRAM and reset 		 * the descriptor we've just suctioned... 		 */
argument|if (hc->mempages) 			SRC_SET_MEM(hc->iobase, sc->rxdesc);  		rxdesc->len =
literal|0
argument|; 		rxdesc->stat =
literal|0xff
argument|;
comment|/* 		 * Move on to the next granule.  If we've any remaining 		 * bytes to process we'll just continue in our loop... 		 */
argument|rxdata += SR_BUF_SIZ; 		rxdesc++;  		if (rxdata == rxmax) {
comment|/* handle the wrap point */
argument|rxdata = sc->rxstart; 			rxdesc = (sca_descriptor *) 			    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 		} 	} }
comment|/*  * If single is set, just eat a packet. Otherwise eat everything up to  * where cda points. Update pointers to point to the next packet.  *  * This handles "flushing" of a packet as received...  *  * If the "single" parameter is zero, all pending reeceive traffic will  * be flushed out of existence.  A non-zero value will only drop the  * *next* (currently) pending packet...  */
argument|static void sr_eat_packet(struct sr_softc *sc, int single) { 	struct sr_hardc *hc; 	sca_descriptor *rxdesc;
comment|/* current descriptor being eval'd */
argument|sca_descriptor *endp;
comment|/* last descriptor in chain */
argument|sca_descriptor *cda;
comment|/* current start point */
argument|u_int loopcnt =
literal|0
argument|;
comment|/* count of packets flushed ??? */
argument|u_char stat;
comment|/* captured status byte from descr */
argument|hc = sc->hc; 	cda = (sca_descriptor *)(hc->mem_start + 				 (SRC_GET16(hc->sca_base, 				  hc->sca->dmac[DMAC_RXCH(sc->scachan)].cda)& 				  hc->winmsk));
comment|/* 	 * loop until desc->stat == (0xff || EOM) Clear the status and 	 * length in the descriptor. Increment the descriptor. 	 */
argument|if (hc->mempages) 		SRC_SET_MEM(hc->iobase, sc->rxdesc);  	rxdesc = (sca_descriptor *) 	    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 	endp = rxdesc; 	rxdesc =&rxdesc[sc->rxhind]; 	endp =&endp[sc->rxmax];
comment|/* 	 * allow loop, but abort it if we wrap completely... 	 */
argument|while (rxdesc != cda) { 		loopcnt++;  		if (loopcnt> sc->rxmax) { 			printf(
literal|"sr%d: eat pkt %d loop, cda %x, "
literal|"rxdesc %x, stat %x.\n"
argument|, 			       sc->unit, loopcnt, (u_int) cda, (u_int) rxdesc, 			       rxdesc->stat); 			break; 		} 		stat = rxdesc->stat;  		rxdesc->len =
literal|0
argument|; 		rxdesc->stat =
literal|0xff
argument|;  		rxdesc++; 		sc->rxhind++;  		if (rxdesc == endp) { 			rxdesc = (sca_descriptor *) 			    (hc->mem_start + (sc->rxdesc& hc->winmsk)); 			sc->rxhind =
literal|0
argument|; 		} 		if (single&& (stat == SCA_DESC_EOM)) 			break; 	}
comment|/* 	 * Update the eda to the previous descriptor. 	 */
argument|rxdesc = (sca_descriptor *)sc->rxdesc; 	rxdesc =&rxdesc[(sc->rxhind + sc->rxmax -
literal|2
argument|) % sc->rxmax];  	SRC_PUT16(hc->sca_base, 		  hc->sca->dmac[DMAC_RXCH(sc->scachan)].eda, 		  (u_short)((u_int)(rxdesc + hc->mem_pstart)&
literal|0xffff
argument|)); }
comment|/*  * While there is packets available in the rx buffer, read them out  * into mbufs and ship them off.  */
argument|static void sr_get_packets(struct sr_softc *sc) { 	u_char rxstat;
comment|/* acquired status byte */
argument|int i; 	int pkts;
comment|/* count of packets found */
argument|int rxndx;
comment|/* rcv buffer index */
argument|int tries;
comment|/* settling time counter */
argument|u_int len;
comment|/* length of pending packet */
argument|struct sr_hardc *hc;
comment|/* card-level information */
argument|sca_descriptor *rxdesc;
comment|/* descriptor in memory */
ifndef|#
directive|ifndef
name|NETGRAPH
argument|struct ifnet *ifp;
comment|/* network intf ctl table */
endif|#
directive|endif
comment|/* NETGRAPH */
argument|struct mbuf *m = NULL;
comment|/* message buffer */
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_get_packets(sc=%08x)\n"
argument|, sc);
endif|#
directive|endif
argument|hc = sc->hc;
ifndef|#
directive|ifndef
name|NETGRAPH
argument|ifp =&sc->ifsppp.pp_if;
endif|#
directive|endif
comment|/* NETGRAPH */
argument|if (hc->mempages) { 		SRC_SET_MEM(hc->iobase, sc->rxdesc); 		SRC_SET_ON(hc->iobase);
comment|/* enable shared memory */
argument|} 	pkts =
literal|0
argument|;
comment|/* reset count of found packets */
comment|/* 	 * for each complete packet in the receiving pool, process each 	 * packet... 	 */
argument|while (sr_packet_avail(sc,&len,&rxstat)) {
comment|/* packet pending? */
comment|/* 		 * I have seen situations where we got the interrupt but the 		 * status value wasn't deposited.  This code should allow 		 * the status byte's value to settle... 		 */
argument|tries =
literal|5
argument|;  		while ((rxstat ==
literal|0x00ff
argument|)&& --tries) 			sr_packet_avail(sc,&len,&rxstat);
if|#
directive|if
name|BUGGY
operator|>
literal|1
argument|printf(
literal|"sr_packet_avail() returned len=%d, rxstat=%02ux\n"
argument|, 		       len, rxstat);
endif|#
directive|endif
argument|pkts++;
ifdef|#
directive|ifdef
name|NETGRAPH
argument|sc->inbytes += len; 		sc->inlast =
literal|0
argument|;
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/* 		 * OK, we've settled the incoming message status. We can now 		 * process it... 		 */
argument|if (((rxstat& SCA_DESC_ERRORS) ==
literal|0
argument|)&& (len< MCLBYTES)) {
if|#
directive|if
name|BUGGY
operator|>
literal|1
argument|printf(
literal|"sr%d: sr_get_packet() rxstat=%02x, len=%d\n"
argument|, 			       sc->unit, rxstat, len);
endif|#
directive|endif
argument|MGETHDR(m, M_DONTWAIT, MT_DATA); 			if (m == NULL) {
comment|/* 				 * eat (flush) packet if get mbuf fail!! 				 */
argument|sr_eat_packet(sc,
literal|1
argument|); 				continue; 			}
comment|/* 			 * construct control information for pass-off 			 */
ifndef|#
directive|ifndef
name|NETGRAPH
argument|m->m_pkthdr.rcvif = ifp;
else|#
directive|else
argument|m->m_pkthdr.rcvif = NULL;
endif|#
directive|endif
comment|/* NETGRAPH */
argument|m->m_pkthdr.len = m->m_len = len; 			if (len> MHLEN) { 				MCLGET(m, M_DONTWAIT); 				if ((m->m_flags& M_EXT) ==
literal|0
argument|) {
comment|/* 					 * We couldn't get a big enough 					 * message packet, so we'll send the 					 * packet to /dev/null... 					 */
argument|m_freem(m); 					sr_eat_packet(sc,
literal|1
argument|); 					continue; 				} 			}
comment|/* 			 * OK, we've got a good message buffer.  Now we can 			 * copy the received message into it 			 */
argument|sr_copy_rxbuf(m, sc, len);
comment|/* copy from DPRAM */
ifndef|#
directive|ifndef
name|NETGRAPH
argument|if (ifp->if_bpf) 				bpf_mtap(ifp, m);
if|#
directive|if
name|BUGGY
operator|>
literal|3
argument|{ 				u_char *bp;  				bp = (u_char *)m; 				printf(
literal|"sr%d: rcvd=%02x%02x%02x%02x%02x%02x\n"
argument|, 				       sc->unit, 				       bp[
literal|0
argument|], bp[
literal|1
argument|], bp[
literal|2
argument|], 				       bp[
literal|4
argument|], bp[
literal|5
argument|], bp[
literal|6
argument|]); 			}
endif|#
directive|endif
argument|sppp_input(ifp, m); 			ifp->if_ipackets++;
else|#
directive|else
comment|/* NETGRAPH */
if|#
directive|if
name|BUGGY
operator|>
literal|3
argument|{ 				u_char *bp;  				bp = mtod(m,u_char *); 				printf(
literal|"sr%d: rd=%02x:%02x:%02x:%02x:%02x:%02x"
argument|, 				       sc->unit, 				       bp[
literal|0
argument|], bp[
literal|1
argument|], bp[
literal|2
argument|], 				       bp[
literal|4
argument|], bp[
literal|5
argument|], bp[
literal|6
argument|]); 				printf(
literal|":%02x:%02x:%02x:%02x:%02x:%02x\n"
argument|, 				       bp[
literal|6
argument|], bp[
literal|7
argument|], bp[
literal|8
argument|], 				       bp[
literal|9
argument|], bp[
literal|10
argument|], bp[
literal|11
argument|]); 			}
endif|#
directive|endif
argument|ng_queue_data(sc->hook, m, NULL); 			sc->ipackets++;
endif|#
directive|endif
comment|/* NETGRAPH */
comment|/* 			 * Update the eda to the previous descriptor. 			 */
argument|i = (len + SR_BUF_SIZ -
literal|1
argument|) / SR_BUF_SIZ; 			sc->rxhind = (sc->rxhind + i) % sc->rxmax;  			rxdesc = (sca_descriptor *)sc->rxdesc; 			rxndx = (sc->rxhind + sc->rxmax -
literal|2
argument|) % sc->rxmax; 			rxdesc =&rxdesc[rxndx];  			SRC_PUT16(hc->sca_base, 				  hc->sca->dmac[DMAC_RXCH(sc->scachan)].eda, 				  (u_short)((u_int)(rxdesc + hc->mem_pstart)&
literal|0xffff
argument|));  		} else { 			int got_st3
argument_list|,
argument|got_cda
argument_list|,
argument|got_eda; 			int tries =
literal|5
argument|;  			while((rxstat ==
literal|0xff
argument|)&& --tries) 				sr_packet_avail(sc,&len,&rxstat);
comment|/* 			 * It look like we get an interrupt early 			 * sometimes and then the status is not 			 * filled in yet. 			 */
argument|if(tries&& (tries !=
literal|5
argument|)) 				continue;
comment|/* 			 * This chunk of code handles the error packets. 			 * We'll log them for posterity... 			 */
argument|sr_eat_packet(sc,
literal|1
argument|);
ifndef|#
directive|ifndef
name|NETGRAPH
argument|ifp->if_ierrors++;
else|#
directive|else
argument|sc->ierrors[
literal|0
argument|]++;
endif|#
directive|endif
comment|/* NETGRAPH */
argument|got_st3 = SRC_GET8(hc->sca_base, 				  hc->sca->msci[sc->scachan].st3); 			got_cda = SRC_GET16(hc->sca_base, 				  hc->sca->dmac[DMAC_RXCH(sc->scachan)].cda); 			got_eda = SRC_GET16(hc->sca_base, 				  hc->sca->dmac[DMAC_RXCH(sc->scachan)].eda);
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: Receive error chan %d, "
literal|"stat %02x, msci st3 %02x,"
literal|"rxhind %d, cda %04x, eda %04x.\n"
argument|, 			       sc->unit, sc->scachan, rxstat, 			       got_st3, sc->rxhind, got_cda, got_eda);
endif|#
directive|endif
argument|} 	}
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr%d: sr_get_packets() found %d packet(s)\n"
argument|, 	       sc->unit, pkts);
endif|#
directive|endif
argument|if (hc->mempages) 		SRC_SET_OFF(hc->iobase); }
comment|/*  * All DMA interrupts come here.  *  * Each channel has two interrupts.  * Interrupt A for errors and Interrupt B for normal stuff like end  * of transmit or receive dmas.  */
argument|static void sr_dmac_intr(struct sr_hardc *hc, u_char isr1) { 	u_char dsr;
comment|/* contents of DMA Stat Reg */
argument|u_char dotxstart;
comment|/* enables for tranmit part */
argument|int mch;
comment|/* channel being processed */
argument|struct sr_softc *sc;
comment|/* channel's softc structure */
argument|sca_regs *sca = hc->sca; 	dmac_channel *dmac;
comment|/* dma structure of chip */
if|#
directive|if
name|BUGGY
operator|>
literal|0
argument|printf(
literal|"sr_dmac_intr(hc=%08x,isr1=%04x)\n"
argument|, hc, isr1);
endif|#
directive|endif
argument|mch =
literal|0
argument|;
comment|/* assume chan0 on card */
argument|dotxstart = isr1;
comment|/* copy for xmitter starts */
comment|/* 	 * Shortcut if there is no interrupts for dma channel 0 or 1. 	 * Skip processing for channel 0 if no incoming hit 	 */
argument|if ((isr1&
literal|0x0F
argument|) ==
literal|0
argument|) { 		mch =
literal|1
argument|; 		isr1>>=
literal|4
argument|; 	} 	do { 		sc =&hc->sc[mch];
comment|/* 		 * Transmit channel - DMA Status Register Evaluation 		 */
argument|if (isr1&
literal|0x0C
argument|) { 			dmac =&sca->dmac[DMAC_TXCH(mch)];
comment|/* 			 * get the DMA Status Register contents and write 			 * back to reset interrupt... 			 */
argument|dsr = SRC_GET8(hc->sca_base, dmac->dsr); 			SRC_PUT8(hc->sca_base, dmac->dsr, dsr);
comment|/* 			 * Check for (& process) a Counter overflow 			 */
argument|if (dsr& SCA_DSR_COF) { 				printf(
literal|"sr%d: TX DMA Counter overflow, "
literal|"txpacket no %lu.\n"
argument|,
ifndef|#
directive|ifndef
name|NETGRAPH
argument|sc->unit, sc->ifsppp.pp_if.if_opackets); 				sc->ifsppp.pp_if.if_oerrors++;
else|#
directive|else
argument|sc->unit
argument_list|,
argument|sc->opackets
argument_list|)
empty_stmt|;
name|sc
operator|->
name|oerrors
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
comment|/* 			 * Check for (& process) a Buffer overflow 			 */
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_BOF
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: TX DMA Buffer overflow, "
literal|"txpacket no %lu, dsr %02x, "
literal|"cda %04x, eda %04x.\n"
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_opackets
argument_list|,
else|#
directive|else
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|opackets
argument_list|,
endif|#
directive|endif
comment|/* NETGRAPH */
name|dsr
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|cda
argument_list|)
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|eda
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_oerrors
operator|++
expr_stmt|;
else|#
directive|else
name|sc
operator|->
name|oerrors
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
comment|/* 			 * Check for (& process) an End of Transfer (OK) 			 */
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_EOT
condition|)
block|{
comment|/* 				 * This should be the most common case. 				 * 				 * Clear the IFF_OACTIVE flag. 				 * 				 * Call srstart to start a new transmit if 				 * there is data to transmit. 				 */
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|printf
argument_list|(
literal|"sr%d: TX Completed OK\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sc
operator|->
name|xmit_busy
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_OACTIVE
expr_stmt|;
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_timer
operator|=
literal|0
expr_stmt|;
else|#
directive|else
comment|/* XXX may need to mark tx inactive? */
name|sc
operator|->
name|out_deficit
operator|++
expr_stmt|;
name|sc
operator|->
name|out_dog
operator|=
name|DOG_HOLDOFF
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
if|if
condition|(
name|sc
operator|->
name|txb_inuse
operator|&&
operator|--
name|sc
operator|->
name|txb_inuse
condition|)
name|sr_xmit
argument_list|(
name|sc
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* 		 * Receive channel processing of DMA Status Register 		 */
end_comment

begin_if
if|if
condition|(
name|isr1
operator|&
literal|0x03
condition|)
block|{
name|dmac
operator|=
operator|&
name|sca
operator|->
name|dmac
index|[
name|DMAC_RXCH
argument_list|(
name|mch
argument_list|)
index|]
expr_stmt|;
name|dsr
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|,
name|dsr
argument_list|)
expr_stmt|;
comment|/* 			 * End of frame processing (MSG OK?) 			 */
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_EOM
condition|)
block|{
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|int
name|tt
decl_stmt|,
name|ind
decl_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|tt
operator|=
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|tt
operator|=
name|sc
operator|->
name|ipackets
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
name|ind
operator|=
name|sc
operator|->
name|rxhind
expr_stmt|;
endif|#
directive|endif
name|sr_get_packets
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|0
ifndef|#
directive|ifndef
name|NETGRAPH
if|if
condition|(
name|tt
operator|==
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
condition|)
else|#
directive|else
comment|/* NETGRAPH */
if|if
condition|(
name|tt
operator|==
name|sc
operator|->
name|ipackets
condition|)
endif|#
directive|endif
comment|/* NETGRAPH */
block|{
name|sca_descriptor
modifier|*
name|rxdesc
decl_stmt|;
name|int
name|i
decl_stmt|;
name|printf
argument_list|(
literal|"SR: RXINTR isr1 %x, dsr %x, "
literal|"no data %d pkts, orxind %d.\n"
argument_list|,
name|dotxstart
argument_list|,
name|dsr
argument_list|,
name|tt
argument_list|,
name|ind
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SR: rxdesc %x, rxstart %x, "
literal|"rxend %x, rxhind %d, "
literal|"rxmax %d.\n"
argument_list|,
name|sc
operator|->
name|rxdesc
argument_list|,
name|sc
operator|->
name|rxstart
argument_list|,
name|sc
operator|->
name|rxend
argument_list|,
name|sc
operator|->
name|rxhind
argument_list|,
name|sc
operator|->
name|rxmax
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SR: cda %x, eda %x.\n"
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|cda
argument_list|)
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|eda
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
block|{
name|SRC_SET_ON
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
name|SRC_SET_MEM
argument_list|(
name|hc
operator|->
name|iobase
argument_list|,
name|sc
operator|->
name|rxdesc
argument_list|)
expr_stmt|;
block|}
name|rxdesc
operator|=
operator|(
name|sca_descriptor
operator|*
operator|)
operator|(
name|hc
operator|->
name|mem_start
operator|+
operator|(
name|sc
operator|->
name|rxdesc
operator|&
name|hc
operator|->
name|winmsk
operator|)
operator|)
expr_stmt|;
name|rxdesc
operator|=
operator|&
name|rxdesc
index|[
name|sc
operator|->
name|rxhind
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|3
condition|;
name|i
operator|++
operator|,
name|rxdesc
operator|++
control|)
name|printf
argument_list|(
literal|"SR: rxdesc->stat %x, "
literal|"len %d.\n"
argument_list|,
name|rxdesc
operator|->
name|stat
argument_list|,
name|rxdesc
operator|->
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_OFF
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* BUGGY */
block|}
comment|/* 			 * Check for Counter overflow 			 */
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_COF
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: RX DMA Counter overflow, "
literal|"rxpkts %lu.\n"
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
argument_list|)
expr_stmt|;
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ierrors
operator|++
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|unit
operator|,
name|sc
operator|->
name|ipackets
block|)
empty_stmt|;
name|sc
operator|->
name|ierrors
index|[
literal|1
index|]
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
end_if

begin_comment
comment|/* 			 * Check for Buffer overflow 			 */
end_comment

begin_if
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_BOF
condition|)
block|{
name|printf
argument_list|(
literal|"sr%d: RX DMA Buffer overflow, "
literal|"rxpkts %lu, rxind %d, "
literal|"cda %x, eda %x, dsr %x.\n"
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
argument_list|,
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|unit
argument_list|,
name|sc
operator|->
name|ipackets
argument_list|,
endif|#
directive|endif
comment|/* NETGRAPH */
name|sc
operator|->
name|rxhind
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|cda
argument_list|)
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|eda
argument_list|)
argument_list|,
name|dsr
argument_list|)
expr_stmt|;
comment|/* 				 * Make sure we eat as many as possible. 				 * Then get the system running again. 				 */
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_ON
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
name|sr_eat_packet
argument_list|(
name|sc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ierrors
operator|++
expr_stmt|;
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|ierrors
index|[
literal|2
index|]
operator|++
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
name|SRC_PUT8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|sca
operator|->
name|msci
index|[
name|mch
index|]
operator|.
name|cmd
argument_list|,
name|SCA_CMD_RXMSGREJ
argument_list|)
expr_stmt|;
name|SRC_PUT8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|,
name|SCA_DSR_DE
argument_list|)
expr_stmt|;
if|#
directive|if
name|BUGGY
operator|>
literal|0
name|printf
argument_list|(
literal|"sr%d: RX DMA Buffer overflow, "
literal|"rxpkts %lu, rxind %d, "
literal|"cda %x, eda %x, dsr %x. After\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|ipackets
argument_list|,
else|#
directive|else
comment|/* NETGRAPH */
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
argument_list|,
endif|#
directive|endif
comment|/* NETGRAPH */
name|sc
operator|->
name|rxhind
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|cda
argument_list|)
argument_list|,
name|SRC_GET16
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|eda
argument_list|)
argument_list|,
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|dmac
operator|->
name|dsr
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hc
operator|->
name|mempages
condition|)
name|SRC_SET_OFF
argument_list|(
name|hc
operator|->
name|iobase
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* 			 * End of Transfer 			 */
end_comment

begin_if
if|if
condition|(
name|dsr
operator|&
name|SCA_DSR_EOT
condition|)
block|{
comment|/* 				 * If this happen, it means that we are 				 * receiving faster than what the processor 				 * can handle. 				 *  				 * XXX We should enable the dma again. 				 */
name|printf
argument_list|(
literal|"sr%d: RX End of xfer, rxpkts %lu.\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|,
ifndef|#
directive|ifndef
name|NETGRAPH
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ipackets
argument_list|)
expr_stmt|;
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
operator|.
name|if_ierrors
operator|++
expr_stmt|;
else|#
directive|else
name|sc
operator|->
name|ipackets
block|)
empty_stmt|;
end_if

begin_expr_stmt
name|sc
operator|->
name|ierrors
index|[
literal|3
index|]
operator|++
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_expr_stmt
unit|} 		}
name|isr1
operator|>>=
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* process next half of ISR */
end_comment

begin_expr_stmt
name|mch
operator|++
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* and move to next channel */
end_comment

begin_expr_stmt
unit|} while
operator|(
operator|(
name|mch
operator|<
name|NCHAN
operator|)
operator|&&
name|isr1
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* loop for each chn */
end_comment

begin_comment
comment|/* 	 * Now that we have done all the urgent things, see if we can fill 	 * the transmit buffers. 	 */
end_comment

begin_for
for|for
control|(
name|mch
operator|=
literal|0
init|;
name|mch
operator|<
name|NCHAN
condition|;
name|mch
operator|++
control|)
block|{
if|if
condition|(
name|dotxstart
operator|&
literal|0x0C
condition|)
block|{
comment|/* TX initiation enabled? */
name|sc
operator|=
operator|&
name|hc
operator|->
name|sc
index|[
name|mch
index|]
expr_stmt|;
ifndef|#
directive|ifndef
name|NETGRAPH
name|srstart
argument_list|(
operator|&
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
argument_list|)
expr_stmt|;
else|#
directive|else
name|srstart
argument_list|(
name|sc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETGRAPH */
block|}
name|dotxstart
operator|>>=
literal|4
expr_stmt|;
comment|/* shift for next channel */
block|}
end_for

begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|NETGRAPH
end_ifndef

begin_comment
comment|/*  * Perform timeout on an FR channel   *  * Establish a periodic check of open N2 ports;  If  * a port is open/active, its DCD state is checked  * and a loss of DCD is recognized (and eventually  * processed).  */
end_comment

begin_function
unit|static
name|void
name|sr_modemck
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|u_int
name|s
decl_stmt|;
name|int
name|card
decl_stmt|;
comment|/* card index in table */
name|int
name|cards
decl_stmt|;
comment|/* card list index */
name|int
name|mch
decl_stmt|;
comment|/* channel on card */
name|u_char
name|dcd_v
decl_stmt|;
comment|/* Data Carrier Detect */
name|u_char
name|got_st0
decl_stmt|;
comment|/* contents of ST0 */
name|u_char
name|got_st1
decl_stmt|;
comment|/* contents of ST1 */
name|u_char
name|got_st2
decl_stmt|;
comment|/* contents of ST2 */
name|u_char
name|got_st3
decl_stmt|;
comment|/* contents of ST3 */
name|struct
name|sr_hardc
modifier|*
name|hc
decl_stmt|;
comment|/* card's configuration */
name|struct
name|sr_hardc
modifier|*
name|Card
index|[
literal|16
index|]
decl_stmt|;
comment|/* up to 16 cards in system */
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
comment|/* channel's softc structure */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* interface control table */
name|msci_channel
modifier|*
name|msci
decl_stmt|;
comment|/* regs specific to channel */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|if (sr_opens == 0) {
comment|/* count of "up" channels */
block|sr_watcher = 0;
comment|/* indicate no watcher */
block|splx(s); 		return; 	}
endif|#
directive|endif
name|sr_watcher
operator|=
literal|1
expr_stmt|;
comment|/* mark that we're online */
comment|/* 	 * Now we'll need a list of cards to process.  Since we can handle 	 * both ISA and PCI cards (and I didn't think of making this logic 	 * global YET) we'll generate a single table of card table 	 * addresses. 	 */
name|cards
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|card
operator|=
literal|0
init|;
name|card
operator|<
name|NSR
condition|;
name|card
operator|++
control|)
block|{
name|hc
operator|=
operator|&
name|sr_hardc
index|[
name|card
index|]
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|sc
operator|==
operator|(
name|void
operator|*
operator|)
literal|0
condition|)
continue|continue;
name|Card
index|[
name|cards
operator|++
index|]
operator|=
name|hc
expr_stmt|;
block|}
name|hc
operator|=
name|sr_hardc_pci
expr_stmt|;
while|while
condition|(
name|hc
condition|)
block|{
name|Card
index|[
name|cards
operator|++
index|]
operator|=
name|hc
expr_stmt|;
name|hc
operator|=
name|hc
operator|->
name|next
expr_stmt|;
block|}
comment|/* 	 * OK, we've got work we can do.  Let's do it... (Please note that 	 * this code _only_ deals w/ ISA cards) 	 */
for|for
control|(
name|card
operator|=
literal|0
init|;
name|card
operator|<
name|cards
condition|;
name|card
operator|++
control|)
block|{
name|hc
operator|=
name|Card
index|[
name|card
index|]
expr_stmt|;
comment|/* get card table */
for|for
control|(
name|mch
operator|=
literal|0
init|;
name|mch
operator|<
name|hc
operator|->
name|numports
condition|;
name|mch
operator|++
control|)
block|{
name|sc
operator|=
operator|&
name|hc
operator|->
name|sc
index|[
name|mch
index|]
expr_stmt|;
name|ifp
operator|=
operator|&
name|sc
operator|->
name|ifsppp
operator|.
name|pp_if
expr_stmt|;
comment|/* 			 * if this channel isn't "up", skip it 			 */
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_UP
operator|)
operator|==
literal|0
condition|)
continue|continue;
comment|/* 			 * OK, now we can go looking at this channel's 			 * actual register contents... 			 */
name|msci
operator|=
operator|&
name|hc
operator|->
name|sca
operator|->
name|msci
index|[
name|sc
operator|->
name|scachan
index|]
expr_stmt|;
comment|/* 			 * OK, now we'll look into the actual status of this 			 * channel... 			 *  			 * I suck in more registers than strictly needed 			 */
name|got_st0
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st0
argument_list|)
expr_stmt|;
name|got_st1
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st1
argument_list|)
expr_stmt|;
name|got_st2
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st2
argument_list|)
expr_stmt|;
name|got_st3
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st3
argument_list|)
expr_stmt|;
comment|/* 			 * We want to see if the DCD signal is up (DCD is 			 * true if zero) 			 */
name|dcd_v
operator|=
operator|(
name|got_st3
operator|&
name|SCA_ST3_DCD
operator|)
operator|==
literal|0
expr_stmt|;
if|if
condition|(
name|dcd_v
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"sr%d: DCD lost\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	 * OK, now set up for the next modem signal checking pass... 	 */
name|timeout
argument_list|(
name|sr_modemck
argument_list|,
name|NULL
argument_list|,
name|hz
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/*  * If a port is open/active, it's DCD state is checked  * and a loss of DCD is recognized (and eventually processed?).  */
end_comment

begin_function
specifier|static
name|void
name|sr_modemck
parameter_list|(
name|struct
name|sr_softc
modifier|*
name|sc
parameter_list|)
block|{
name|u_int
name|s
decl_stmt|;
name|u_char
name|got_st3
decl_stmt|;
comment|/* contents of ST3 */
name|struct
name|sr_hardc
modifier|*
name|hc
init|=
name|sc
operator|->
name|hc
decl_stmt|;
comment|/* card's configuration */
name|msci_channel
modifier|*
name|msci
decl_stmt|;
comment|/* regs specific to channel */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|running
operator|==
literal|0
condition|)
return|return;
comment|/* 	 * OK, now we can go looking at this channel's register contents... 	 */
name|msci
operator|=
operator|&
name|hc
operator|->
name|sca
operator|->
name|msci
index|[
name|sc
operator|->
name|scachan
index|]
expr_stmt|;
name|got_st3
operator|=
name|SRC_GET8
argument_list|(
name|hc
operator|->
name|sca_base
argument_list|,
name|msci
operator|->
name|st3
argument_list|)
expr_stmt|;
comment|/* 	 * We want to see if the DCD signal is up (DCD is true if zero) 	 */
name|sc
operator|->
name|dcd
operator|=
operator|(
name|got_st3
operator|&
name|SCA_ST3_DCD
operator|)
operator|==
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_function
specifier|static
name|void
name|sr_msci_intr
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_char
name|isr0
parameter_list|)
block|{
name|printf
argument_list|(
literal|"src%d: SRINTR: MSCI\n"
argument_list|,
name|hc
operator|->
name|cunit
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sr_timer_intr
parameter_list|(
name|struct
name|sr_hardc
modifier|*
name|hc
parameter_list|,
name|u_char
name|isr2
parameter_list|)
block|{
name|printf
argument_list|(
literal|"src%d: SRINTR: TIMER\n"
argument_list|,
name|hc
operator|->
name|cunit
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH
end_ifdef

begin_comment
comment|/*****************************************  * Device timeout/watchdog routine.  * called once per second.  * checks to see that if activity was expected, that it hapenned.  * At present we only look to see if expected output was completed.  */
end_comment

begin_function
specifier|static
name|void
name|ngsr_watchdog_frame
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|arg
decl_stmt|;
name|int
name|s
decl_stmt|;
name|int
name|speed
decl_stmt|;
if|if
condition|(
name|sc
operator|->
name|running
operator|==
literal|0
condition|)
return|return;
comment|/* if we are not running let timeouts die */
comment|/* 	 * calculate the apparent throughputs  	 *  XXX a real hack 	 */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|speed
operator|=
name|sc
operator|->
name|inbytes
operator|-
name|sc
operator|->
name|lastinbytes
expr_stmt|;
name|sc
operator|->
name|lastinbytes
operator|=
name|sc
operator|->
name|inbytes
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|inrate
operator|<
name|speed
condition|)
name|sc
operator|->
name|inrate
operator|=
name|speed
expr_stmt|;
name|speed
operator|=
name|sc
operator|->
name|outbytes
operator|-
name|sc
operator|->
name|lastoutbytes
expr_stmt|;
name|sc
operator|->
name|lastoutbytes
operator|=
name|sc
operator|->
name|outbytes
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|outrate
operator|<
name|speed
condition|)
name|sc
operator|->
name|outrate
operator|=
name|speed
expr_stmt|;
name|sc
operator|->
name|inlast
operator|++
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|sc
operator|->
name|inlast
operator|>
name|QUITE_A_WHILE
operator|)
operator|&&
operator|(
name|sc
operator|->
name|out_deficit
operator|>
name|LOTS_OF_PACKETS
operator|)
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sr%d: No response from remote end\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|sr_down
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sr_up
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|inlast
operator|=
name|sc
operator|->
name|out_deficit
operator|=
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sc
operator|->
name|xmit_busy
condition|)
block|{
comment|/* no TX -> no TX timeouts */
if|if
condition|(
name|sc
operator|->
name|out_dog
operator|==
literal|0
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"sr%d: Transmit failure.. no clock?\n"
argument_list|,
name|sc
operator|->
name|unit
argument_list|)
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|srwatchdog
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|sr_down(sc); 			sr_up(sc);
endif|#
directive|endif
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|sc
operator|->
name|inlast
operator|=
name|sc
operator|->
name|out_deficit
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|sc
operator|->
name|out_dog
operator|--
expr_stmt|;
block|}
block|}
name|sr_modemck
argument_list|(
name|sc
argument_list|)
expr_stmt|;
comment|/* update the DCD status */
name|sc
operator|->
name|handle
operator|=
name|timeout
argument_list|(
name|ngsr_watchdog_frame
argument_list|,
name|sc
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/***********************************************************************  * This section contains the methods for the Netgraph interface  ***********************************************************************/
end_comment

begin_comment
comment|/*  * It is not possible or allowable to create a node of this type.  * If the hardware exists, it will already have created it.  */
end_comment

begin_function
specifier|static
name|int
name|ngsr_constructor
parameter_list|(
name|node_p
modifier|*
name|nodep
parameter_list|)
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * give our ok for a hook to be added...  * If we are not running this should kick the device into life.  * The hook's private info points to our stash of info about that  * channel.  */
end_comment

begin_function
specifier|static
name|int
name|ngsr_newhook
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|node
operator|->
name|private
decl_stmt|;
comment|/* 	 * check if it's our friend the debug hook 	 */
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|NG_SR_HOOK_DEBUG
argument_list|)
operator|==
literal|0
condition|)
block|{
name|hook
operator|->
name|private
operator|=
name|NULL
expr_stmt|;
comment|/* paranoid */
name|sc
operator|->
name|debug_hook
operator|=
name|hook
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * Check for raw mode hook. 	 */
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|NG_SR_HOOK_RAW
argument_list|)
operator|!=
literal|0
condition|)
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|hook
operator|->
name|private
operator|=
name|sc
expr_stmt|;
name|sc
operator|->
name|hook
operator|=
name|hook
expr_stmt|;
name|sc
operator|->
name|datahooks
operator|++
expr_stmt|;
name|sr_up
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * incoming messages.  * Just respond to the generic TEXT_STATUS message  */
end_comment

begin_function
specifier|static
name|int
name|ngsr_rcvmsg
parameter_list|(
name|node_p
name|node
parameter_list|,
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|retaddr
parameter_list|,
name|struct
name|ng_mesg
modifier|*
modifier|*
name|resp
parameter_list|,
name|hook_p
name|lasthook
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|sc
operator|=
name|node
operator|->
name|private
expr_stmt|;
switch|switch
condition|(
name|msg
operator|->
name|header
operator|.
name|typecookie
condition|)
block|{
case|case
name|NG_SR_COOKIE
case|:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
case|case
name|NGM_GENERIC_COOKIE
case|:
switch|switch
condition|(
name|msg
operator|->
name|header
operator|.
name|cmd
condition|)
block|{
case|case
name|NGM_TEXT_STATUS
case|:
block|{
name|char
modifier|*
name|arg
decl_stmt|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
name|int
name|resplen
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|ng_mesg
argument_list|)
operator|+
literal|512
decl_stmt|;
name|MALLOC
argument_list|(
operator|*
name|resp
argument_list|,
expr|struct
name|ng_mesg
operator|*
argument_list|,
name|resplen
argument_list|,
name|M_NETGRAPH
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|resp
operator|==
name|NULL
condition|)
block|{
name|error
operator|=
name|ENOMEM
expr_stmt|;
break|break;
block|}
name|bzero
argument_list|(
operator|*
name|resp
argument_list|,
name|resplen
argument_list|)
expr_stmt|;
name|arg
operator|=
operator|(
operator|*
name|resp
operator|)
operator|->
name|data
expr_stmt|;
comment|/* 			     * Put in the throughput information. 			     */
name|pos
operator|=
name|sprintf
argument_list|(
name|arg
argument_list|,
literal|"%ld bytes in, %ld bytes out\n"
literal|"highest rate seen: %ld B/S in, %ld B/S out\n"
argument_list|,
name|sc
operator|->
name|inbytes
argument_list|,
name|sc
operator|->
name|outbytes
argument_list|,
name|sc
operator|->
name|inrate
argument_list|,
name|sc
operator|->
name|outrate
argument_list|)
expr_stmt|;
name|pos
operator|+=
name|sprintf
argument_list|(
name|arg
operator|+
name|pos
argument_list|,
literal|"%ld output errors\n"
argument_list|,
name|sc
operator|->
name|oerrors
argument_list|)
expr_stmt|;
name|pos
operator|+=
name|sprintf
argument_list|(
name|arg
operator|+
name|pos
argument_list|,
literal|"ierrors = %ld, %ld, %ld, %ld, %ld, %ld\n"
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|0
index|]
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|1
index|]
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|2
index|]
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|3
index|]
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|4
index|]
argument_list|,
name|sc
operator|->
name|ierrors
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|version
operator|=
name|NG_VERSION
expr_stmt|;
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|arglen
operator|=
name|strlen
argument_list|(
name|arg
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|token
operator|=
name|msg
operator|->
name|header
operator|.
name|token
expr_stmt|;
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|typecookie
operator|=
name|NG_SR_COOKIE
expr_stmt|;
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|cmd
operator|=
name|msg
operator|->
name|header
operator|.
name|cmd
expr_stmt|;
name|strncpy
argument_list|(
operator|(
operator|*
name|resp
operator|)
operator|->
name|header
operator|.
name|cmdstr
argument_list|,
literal|"status"
argument_list|,
name|NG_CMDSTRLEN
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
name|free
argument_list|(
name|msg
argument_list|,
name|M_NETGRAPH
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * get data from another node and transmit it to the correct channel  */
end_comment

begin_function
specifier|static
name|int
name|ngsr_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|meta_p
name|meta
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|ret_m
parameter_list|,
name|meta_p
modifier|*
name|ret_meta
parameter_list|)
block|{
name|int
name|s
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|hook
operator|->
name|node
operator|->
name|private
decl_stmt|;
name|struct
name|ifqueue
modifier|*
name|xmitq_p
decl_stmt|;
comment|/* 	 * data doesn't come in from just anywhere (e.g control hook) 	 */
if|if
condition|(
name|hook
operator|->
name|private
operator|==
name|NULL
condition|)
block|{
name|error
operator|=
name|ENETDOWN
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
comment|/*  	 * Now queue the data for when it can be sent 	 */
if|if
condition|(
name|meta
operator|&&
name|meta
operator|->
name|priority
operator|>
literal|0
condition|)
block|{
name|xmitq_p
operator|=
operator|(
operator|&
name|sc
operator|->
name|xmitq_hipri
operator|)
expr_stmt|;
block|}
else|else
block|{
name|xmitq_p
operator|=
operator|(
operator|&
name|sc
operator|->
name|xmitq
operator|)
expr_stmt|;
block|}
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|if
condition|(
name|IF_QFULL
argument_list|(
name|xmitq_p
argument_list|)
condition|)
block|{
name|IF_DROP
argument_list|(
name|xmitq_p
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENOBUFS
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
name|IF_ENQUEUE
argument_list|(
name|xmitq_p
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|srstart
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
name|bad
label|:
comment|/*  	 * It was an error case. 	 * check if we need to free the mbuf, and then return the error 	 */
name|NG_FREE_DATA
argument_list|(
name|m
argument_list|,
name|meta
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * do local shutdown processing..  * this node will refuse to go away, unless the hardware says to..  * don't unref the node, or remove our name. just clear our links up.  */
end_comment

begin_function
specifier|static
name|int
name|ngsr_rmnode
parameter_list|(
name|node_p
name|node
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|node
operator|->
name|private
decl_stmt|;
name|sr_down
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|ng_cutlinks
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|node
operator|->
name|flags
operator|&=
operator|~
name|NG_INVALID
expr_stmt|;
comment|/* bounce back to life */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* already linked */
end_comment

begin_function
specifier|static
name|int
name|ngsr_connect
parameter_list|(
name|hook_p
name|hook
parameter_list|)
block|{
comment|/* be really amiable and just say "YUP that's OK by me! " */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * notify on hook disconnection (destruction)  *  * Invalidate the private data associated with this dlci.  * For this type, removal of the last link resets tries to destroy the node.  * As the device still exists, the shutdown method will not actually  * destroy the node, but reset the device and leave it 'fresh' :)  *  * The node removal code will remove all references except that owned by the  * driver.   */
end_comment

begin_function
specifier|static
name|int
name|ngsr_disconnect
parameter_list|(
name|hook_p
name|hook
parameter_list|)
block|{
name|struct
name|sr_softc
modifier|*
name|sc
init|=
name|hook
operator|->
name|node
operator|->
name|private
decl_stmt|;
name|int
name|s
decl_stmt|;
comment|/* 	 * If it's the data hook, then free resources etc. 	 */
if|if
condition|(
name|hook
operator|->
name|private
condition|)
block|{
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|sc
operator|->
name|datahooks
operator|--
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|datahooks
operator|==
literal|0
condition|)
name|sr_down
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sc
operator|->
name|debug_hook
operator|=
name|NULL
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * called during bootup  * or LKM loading to put this type into the list of known modules  */
end_comment

begin_function
specifier|static
name|void
name|ngsr_init
parameter_list|(
name|void
modifier|*
name|ignored
parameter_list|)
block|{
if|if
condition|(
name|ng_newtype
argument_list|(
operator|&
name|typestruct
argument_list|)
condition|)
name|printf
argument_list|(
literal|"ngsr install failed\n"
argument_list|)
expr_stmt|;
name|ngsr_done_init
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH */
end_comment

begin_comment
comment|/*  ********************************* END ************************************  */
end_comment

end_unit

