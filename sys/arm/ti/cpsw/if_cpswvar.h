begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CPSWVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CPSWVAR_H
end_define

begin_define
define|#
directive|define
name|CPSW_INTR_COUNT
value|4
end_define

begin_comment
comment|/* MII BUS  */
end_comment

begin_define
define|#
directive|define
name|CPSW_MIIBUS_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|CPSW_MIIBUS_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|CPSW_MAX_ALE_ENTRIES
value|1024
end_define

begin_define
define|#
directive|define
name|CPSW_SYSCTL_COUNT
value|34
end_define

begin_struct
struct|struct
name|cpsw_slot
block|{
name|uint32_t
name|bd_offset
decl_stmt|;
comment|/* Offset of corresponding BD within CPPI RAM. */
name|bus_dmamap_t
name|dmamap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|cpsw_slot
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cpsw_slots
argument_list|,
name|cpsw_slot
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cpsw_queue
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
name|int
name|running
decl_stmt|;
name|struct
name|cpsw_slots
name|active
decl_stmt|;
name|struct
name|cpsw_slots
name|avail
decl_stmt|;
name|uint32_t
name|queue_adds
decl_stmt|;
comment|/* total bufs added */
name|uint32_t
name|queue_removes
decl_stmt|;
comment|/* total bufs removed */
name|uint32_t
name|queue_removes_at_last_tick
decl_stmt|;
comment|/* Used by watchdog */
name|int
name|queue_slots
decl_stmt|;
name|int
name|active_queue_len
decl_stmt|;
name|int
name|max_active_queue_len
decl_stmt|;
name|int
name|avail_queue_len
decl_stmt|;
name|int
name|max_avail_queue_len
decl_stmt|;
name|int
name|longest_chain
decl_stmt|;
comment|/* Largest # segments in a single packet. */
name|int
name|hdp_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpsw_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|bintime
name|attach_uptime
decl_stmt|;
comment|/* system uptime when attach happened. */
name|struct
name|bintime
name|init_uptime
decl_stmt|;
comment|/* system uptime when init happened. */
comment|/* TODO: We should set up a child structure for each port; 	   store mac, phy information, etc, in that structure. */
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
comment|/* We expect 1 memory resource and 4 interrupts from the device tree. */
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
operator|+
name|CPSW_INTR_COUNT
index|]
decl_stmt|;
comment|/* Interrupts get recorded here as we initialize them. */
comment|/* Interrupt teardown just walks this list. */
struct|struct
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|ih_cookie
decl_stmt|;
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
name|interrupts
index|[
name|CPSW_INTR_COUNT
index|]
struct|;
name|int
name|interrupt_count
decl_stmt|;
name|uint32_t
name|cpsw_if_flags
decl_stmt|;
name|int
name|cpsw_media_status
decl_stmt|;
struct|struct
block|{
name|int
name|resets
decl_stmt|;
name|int
name|timer
decl_stmt|;
name|struct
name|callout
name|callout
decl_stmt|;
block|}
name|watchdog
struct|;
name|bus_dma_tag_t
name|mbuf_dtag
decl_stmt|;
comment|/* An mbuf full of nulls for TX padding. */
name|bus_dmamap_t
name|null_mbuf_dmamap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|null_mbuf
decl_stmt|;
name|bus_addr_t
name|null_mbuf_paddr
decl_stmt|;
comment|/* RX and TX buffer tracking */
name|struct
name|cpsw_queue
name|rx
decl_stmt|,
name|tx
decl_stmt|;
comment|/* 64-bit versions of 32-bit hardware statistics counters */
name|uint64_t
name|shadow_stats
index|[
name|CPSW_SYSCTL_COUNT
index|]
decl_stmt|;
comment|/* CPPI STATERAM has 512 slots for building TX/RX queues. */
comment|/* TODO: Size here supposedly varies with different versions 	   of the controller.  Check DaVinci specs and find a good 	   way to adjust this.  One option is to have a separate 	   Device Tree parameter for number slots; another option 	   is to calculate it from the memory size in the device tree. */
name|struct
name|cpsw_slot
name|_slots
index|[
name|CPSW_CPPI_RAM_SIZE
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|cpsw_cpdma_bd
argument_list|)
index|]
decl_stmt|;
name|struct
name|cpsw_slots
name|avail
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_IF_CPSWVAR_H */
end_comment

end_unit

