begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, David Greenman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ed_softc: per line info and status  */
end_comment

begin_struct
struct|struct
name|ed_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* ethernet common */
name|char
modifier|*
name|type_str
decl_stmt|;
comment|/* pointer to type string */
name|u_char
name|vendor
decl_stmt|;
comment|/* interface vendor */
name|u_char
name|type
decl_stmt|;
comment|/* interface type code */
name|u_char
name|gone
decl_stmt|;
comment|/* HW missing, presumed having a good time */
name|int
name|port_rid
decl_stmt|;
comment|/* resource id for port range */
name|int
name|port_used
decl_stmt|;
comment|/* nonzero if ports used */
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
comment|/* resource for port range */
name|int
name|mem_rid
decl_stmt|;
comment|/* resource id for memory range */
name|int
name|mem_used
decl_stmt|;
comment|/* nonzero if memory used */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
comment|/* resource for memory range */
name|int
name|irq_rid
decl_stmt|;
comment|/* resource id for irq */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* resource for irq */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* handle for irq handler */
name|u_short
name|asic_addr
decl_stmt|;
comment|/* ASIC I/O bus address */
name|u_short
name|nic_addr
decl_stmt|;
comment|/* NIC (DS8390) I/O bus address */
comment|/*  * The following 'proto' variable is part of a work-around for 8013EBT asics  *	being write-only. It's sort of a prototype/shadow of the real thing.  */
name|u_char
name|wd_laar_proto
decl_stmt|;
name|u_char
name|cr_proto
decl_stmt|;
name|u_char
name|isa16bit
decl_stmt|;
comment|/* width of access to card 0=8 or 1=16 */
name|int
name|is790
decl_stmt|;
comment|/* set by the probe code if the card is 790 				 * based */
comment|/*  * HP PC LAN PLUS card support.  */
name|u_short
name|hpp_options
decl_stmt|;
comment|/* flags controlling behaviour of the HP card */
name|u_short
name|hpp_id
decl_stmt|;
comment|/* software revision and other fields */
name|caddr_t
name|hpp_mem_start
decl_stmt|;
comment|/* Memory-mapped IO register address */
name|caddr_t
name|mem_start
decl_stmt|;
comment|/* NIC memory start address */
name|caddr_t
name|mem_end
decl_stmt|;
comment|/* NIC memory end address */
name|u_long
name|mem_size
decl_stmt|;
comment|/* total NIC memory size */
name|caddr_t
name|mem_ring
decl_stmt|;
comment|/* start of RX ring-buffer (in NIC mem) */
name|u_char
name|mem_shared
decl_stmt|;
comment|/* NIC memory is shared with host */
name|u_char
name|xmit_busy
decl_stmt|;
comment|/* transmitter is busy */
name|u_char
name|txb_cnt
decl_stmt|;
comment|/* number of transmit buffers */
name|u_char
name|txb_inuse
decl_stmt|;
comment|/* number of TX buffers currently in-use */
name|u_char
name|txb_new
decl_stmt|;
comment|/* pointer to where new buffer will be added */
name|u_char
name|txb_next_tx
decl_stmt|;
comment|/* pointer to next buffer ready to xmit */
name|u_short
name|txb_len
index|[
literal|8
index|]
decl_stmt|;
comment|/* buffered xmit buffer lengths */
name|u_char
name|tx_page_start
decl_stmt|;
comment|/* first page of TX buffer area */
name|u_char
name|rec_page_start
decl_stmt|;
comment|/* first page of RX ring-buffer */
name|u_char
name|rec_page_stop
decl_stmt|;
comment|/* last page of RX ring-buffer */
name|u_char
name|next_packet
decl_stmt|;
comment|/* pointer to next unread RX packet */
name|struct
name|ifmib_iso_8802_3
name|mibdata
decl_stmt|;
comment|/* stuff for network mgmt */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|ed_release_resources
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_alloc_port
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_alloc_memory
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_alloc_irq
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_generic8390
name|__P
argument_list|(
operator|(
expr|struct
name|ed_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_WD80x3
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_3Com
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_Novell
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_Novell_generic
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_probe_HP_pclanp
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ed_attach
name|__P
argument_list|(
operator|(
expr|struct
name|ed_softc
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ed_stop
name|__P
argument_list|(
operator|(
expr|struct
name|ed_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_intr_t
name|edintr
decl_stmt|;
end_decl_stmt

end_unit

