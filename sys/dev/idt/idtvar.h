begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000, 2001 Richard Hodges and Matriplex, inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *	must display the following acknowledgement:  *	This product includes software developed by Matriplex, inc.  * 4. The name of the author may not be used to endorse or promote products  *	derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************  *  * This driver is derived from the Nicstar driver by Mark Tinguely, and  * some of the original driver still exists here.  Those portions are...  *   Copyright (c) 1996, 1997, 1998, 1999 Mark Tinguely  *   All rights reserved.  *  ******************************************************************************  *  *  This driver supports the Fore LE155, LE25, and IDT 77211 cards.  *  *  ATM CBR connections are supported, and bandwidth is allocated in  *  slots of 64k each.  Three VBR queues handle traffic for VBR and  *  UBR.  Two UBR queues prioritize UBR traffic.  ILMI and signalling  *  get the higher priority queue, as well as UBR traffic that specifies  *  a peak cell rate.  All other UBR traffic goes into the lower queue.  *  ******************************************************************************  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*******************************************************************************  *  *  New data types  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mbuf
modifier|*
name|mget
decl_stmt|;
comment|/* head of mbuf queue, pull mbufs from here */
name|struct
name|mbuf
modifier|*
modifier|*
name|mput
decl_stmt|;
comment|/* tail (ptr to m_nextpkt)  put mbufs here */
name|u_long
name|scd
decl_stmt|;
comment|/* segmentation channel descriptor address */
name|u_long
modifier|*
name|scq_base
decl_stmt|;
comment|/* segmentation channel queue base address */
name|u_long
modifier|*
name|scq_next
decl_stmt|;
comment|/* next address */
name|u_long
modifier|*
name|scq_last
decl_stmt|;
comment|/* last address written */
name|int
name|scq_len
decl_stmt|;
comment|/* size of SCQ buffer (64 or 512) */
name|int
name|scq_cur
decl_stmt|;
comment|/* current number entries in SCQ buffer */
name|int
name|rate
decl_stmt|;
comment|/* cells per second allocated to this queue */
name|int
name|vbr_m
decl_stmt|;
comment|/* VBR m/n = max duty cycle for queue */
name|int
name|vbr_n
decl_stmt|;
comment|/* 1<= m<= 7 and 1<= n<= 127 */
block|}
name|TX_QUEUE
typedef|;
end_typedef

begin_comment
comment|/*  To avoid expensive SRAM reads, scq_cur tracks the number of SCQ entries  *  in use.  Only idt_transmit_top may increase this, and only idt_intr_tsq  *  may decrease it.  */
end_comment

begin_comment
comment|/*  mbuf chains on the queue use the fields:  *  m_next     is the usual pointer to next mbuf  *  m_nextpkt  is the next packet on the queue  *  m_pkthdr.rcvif is a pointer to the connection  *  m_pkthdr.header is a pointer to the TX queue  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|vccb
modifier|*
name|vccinf
decl_stmt|;
name|char
name|status
decl_stmt|;
comment|/* zero if closed */
name|char
name|vpi
decl_stmt|;
name|u_short
name|vci
decl_stmt|;
name|TX_QUEUE
modifier|*
name|queue
decl_stmt|;
comment|/* transmit queue for this connection */
name|struct
name|mbuf
modifier|*
name|recv
decl_stmt|;
comment|/* current receive mbuf, or NULL */
name|int
name|rlen
decl_stmt|;
comment|/* current receive length */
name|int
name|maxpdu
decl_stmt|;
comment|/* largest PDU we will ever see */
name|int
name|traf_pcr
decl_stmt|;
comment|/* peak cell rate */
name|int
name|traf_scr
decl_stmt|;
comment|/* sustained cell rate */
name|u_char
name|aal
decl_stmt|;
comment|/* AAL for this connection */
name|u_char
name|class
decl_stmt|;
comment|/* T_ATM_CBR, T_ATM_VBR, or T_ATM_UBR */
name|u_char
name|flg_mpeg2ts
range|:
literal|1
decl_stmt|;
comment|/* send data as 2 TS == 8 AAL5 cells */
name|u_char
name|flg_clp
range|:
literal|1
decl_stmt|;
comment|/* CLP flag for outbound cells */
block|}
name|CONNECTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_CONNECTION
value|4096
end_define

begin_comment
comment|/* max number of connections */
end_comment

begin_define
define|#
directive|define
name|GET_RDTSC
parameter_list|(
name|var
parameter_list|)
value|{__asm__ volatile("rdtsc":"=A"(var)); }
end_define

begin_comment
comment|/*******************************************************************************  *  *  Device softc structure  */
end_comment

begin_struct
struct|struct
name|idt_softc
block|{
comment|/* HARP data */
comment|/* XXX: must be first member of struct. */
name|Cmn_unit
name|iu_cmn
decl_stmt|;
comment|/* Common unit stuff */
if|#
directive|if
literal|0
block|struct arpcom		idt_ac;
comment|/* ifnet for device */
endif|#
directive|endif
comment|/* Device data */
name|device_t
name|dev
decl_stmt|;
name|int
name|debug
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|int
name|mem_type
decl_stmt|;
name|bus_space_tag_t
name|bustag
decl_stmt|;
name|bus_space_handle_t
name|bushandle
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|irq_ih
decl_stmt|;
name|struct
name|callout_handle
name|ch
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|vm_offset_t
name|virt_baseaddr
decl_stmt|;
comment|/* nicstar register virtual address */
name|vm_offset_t
name|cmd_reg
decl_stmt|;
comment|/* command register offset 0x14 */
name|vm_offset_t
name|stat_reg
decl_stmt|;
comment|/* status register offset 0x60 */
name|vm_offset_t
name|fixbuf
decl_stmt|;
comment|/* buffer that holds TSQ, RSQ, variable SCQ */
name|u_long
name|timer_wrap
decl_stmt|;
comment|/* keep track of wrapped timers */
name|u_long
name|rsqh
decl_stmt|;
comment|/* Recieve Status Queue, reg is write-only */
name|CONNECTION
modifier|*
name|connection
decl_stmt|;
comment|/* connection table */
name|int
name|conn_maxvpi
decl_stmt|;
comment|/* number of VPI values */
name|int
name|conn_maxvci
decl_stmt|;
comment|/* number of VCI values */
name|int
name|cellrate_rmax
decl_stmt|;
comment|/* max RX cells per second */
name|int
name|cellrate_tmax
decl_stmt|;
comment|/* max TX cells per second */
name|int
name|cellrate_rcur
decl_stmt|;
comment|/* current committed RX cellrate */
name|int
name|cellrate_tcur
decl_stmt|;
comment|/* current committed TX cellrate */
name|int
name|txslots_max
decl_stmt|;
comment|/* number of CBR TX slots for interface */
name|int
name|txslots_cur
decl_stmt|;
comment|/* current CBR TX slots in use */
name|TX_QUEUE
name|cbr_txqb
index|[
name|IDT_MAX_CBRQUEUE
index|]
decl_stmt|;
name|TX_QUEUE
modifier|*
name|cbr_slot
index|[
name|IDT_MAX_CBRSLOTS
index|]
decl_stmt|;
name|TX_QUEUE
modifier|*
name|cbr_free
index|[
name|IDT_MAX_CBRQUEUE
index|]
decl_stmt|;
name|TX_QUEUE
name|queue_vbr
decl_stmt|;
name|TX_QUEUE
name|queue_abr
decl_stmt|;
name|TX_QUEUE
name|queue_ubr
decl_stmt|;
name|vm_offset_t
name|cbr_base
decl_stmt|;
comment|/* base of memory for CBR TX queues */
name|int
name|cbr_size
decl_stmt|;
comment|/* size of memory for CBR TX queues */
name|int
name|cbr_freect
decl_stmt|;
name|u_long
name|raw_headp
decl_stmt|;
comment|/* head of raw cell queue, physical */
name|struct
name|mbuf
modifier|*
name|raw_headm
decl_stmt|;
comment|/* head of raw cell queue, virtual */
name|u_long
modifier|*
name|tsq_base
decl_stmt|;
comment|/* virtual TSQ base address */
name|u_long
modifier|*
name|tsq_head
decl_stmt|;
comment|/* virtual TSQ head pointer */
name|int
name|tsq_size
decl_stmt|;
comment|/* number of TSQ entries (1024) */
specifier|volatile
name|u_long
modifier|*
name|reg_cfg
decl_stmt|;
specifier|volatile
name|u_long
modifier|*
name|reg_cmd
decl_stmt|;
specifier|volatile
name|u_long
modifier|*
name|reg_data
decl_stmt|;
specifier|volatile
name|u_long
modifier|*
name|reg_tsqh
decl_stmt|;
specifier|volatile
name|u_long
modifier|*
name|reg_gp
decl_stmt|;
specifier|volatile
name|u_long
modifier|*
name|reg_stat
decl_stmt|;
name|struct
name|mbuf
modifier|*
modifier|*
name|mcheck
decl_stmt|;
name|int
name|sram
decl_stmt|;
comment|/* amount of SRAM */
name|int
name|pci_rev
decl_stmt|;
comment|/* hardware revision ID */
name|char
modifier|*
name|hardware
decl_stmt|;
comment|/* hardware description string */
name|u_char
name|flg_le25
range|:
literal|1
decl_stmt|;
comment|/* flag indicates LE25 instead of LE155 */
name|u_char
name|flg_igcrc
range|:
literal|1
decl_stmt|;
comment|/* ignore receive CRC errors */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|idt_softc
name|nicstar_reg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|idt_softc
name|IDT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|iu_pif
value|iu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|stats_ipdus
value|iu_pif.pif_ipdus
end_define

begin_define
define|#
directive|define
name|stats_opdus
value|iu_pif.pif_opdus
end_define

begin_define
define|#
directive|define
name|stats_ibytes
value|iu_pif.pif_ibytes
end_define

begin_define
define|#
directive|define
name|stats_obytes
value|iu_pif.pif_obytes
end_define

begin_define
define|#
directive|define
name|stats_ierrors
value|iu_pif.pif_ierrors
end_define

begin_define
define|#
directive|define
name|stats_oerrors
value|iu_pif.pif_oerrors
end_define

begin_define
define|#
directive|define
name|stats_cmderrors
value|iu_pif.pif_cmderrors
end_define

begin_comment
comment|/*  * Device VCC Entry  *   * Contains the common and IDT-specific information for each VCC  * which is opened through an IDT device.  */
end_comment

begin_struct
struct|struct
name|nidt_vcc
block|{
name|struct
name|cmn_vcc
name|iv_cmn
decl_stmt|;
comment|/* Common VCC stuff */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nidt_vcc
name|Idt_vcc
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|idt_sysctl_logvcs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|idt_sysctl_vbriscbr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|nicstar_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|phys_init
parameter_list|(
name|nicstar_reg_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicstar_init
parameter_list|(
name|nicstar_reg_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idt_harp_init
parameter_list|(
name|nicstar_reg_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idt_device_stop
parameter_list|(
name|IDT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idt_release_mem
parameter_list|(
name|IDT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CONNECTION
modifier|*
name|idt_connect_find
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|idt_mbuf_base
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idt_slots_cbr
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idt_connect_opencls
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|CONNECTION
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idt_connect_txopen
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|CONNECTION
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|idt_connect_txclose
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|CONNECTION
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicstar_eeprom_rd
parameter_list|(
name|nicstar_reg_t
modifier|*
specifier|const
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idt_receive
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|idt_transmit
parameter_list|(
name|IDT
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

