begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995, David Greenman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_ED_IF_EDVAR_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_ED_IF_EDVAR_H
end_define

begin_comment
comment|/*  * ed_softc: per line info and status  */
end_comment

begin_struct
struct|struct
name|ed_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* Media info */
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
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
name|chip_type
decl_stmt|;
comment|/* the type of chip (one of ED_CHIP_TYPE_*) */
name|u_char
name|isa16bit
decl_stmt|;
comment|/* width of access to card 0=8 or 1=16 */
name|u_char
name|mem_shared
decl_stmt|;
comment|/* NIC memory is shared with host */
name|u_char
name|xmit_busy
decl_stmt|;
comment|/* transmitter is busy */
name|u_char
name|enaddr
index|[
literal|6
index|]
decl_stmt|;
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
name|struct
name|resource
modifier|*
name|port_res2
decl_stmt|;
comment|/* resource for port range */
name|bus_space_tag_t
name|port_bst
decl_stmt|;
name|bus_space_handle_t
name|port_bsh
decl_stmt|;
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
name|bus_space_tag_t
name|mem_bst
decl_stmt|;
name|bus_space_handle_t
name|mem_bsh
decl_stmt|;
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
name|int
function_decl|(
modifier|*
name|sc_media_ioctl
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ifreq
modifier|*
name|ifr
parameter_list|,
name|u_long
name|command
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_mediachg
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
name|device_t
name|miibus
decl_stmt|;
comment|/* MII bus for cards with MII. */
name|void
function_decl|(
modifier|*
name|mii_writebits
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|mii_readbits
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|struct
name|callout
name|tick_ch
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sc_tick
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|readmem
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
name|sc
parameter_list|,
name|bus_size_t
name|src
parameter_list|,
name|uint8_t
modifier|*
name|dst
parameter_list|,
name|uint16_t
name|amount
parameter_list|)
function_decl|;
name|u_short
function_decl|(
modifier|*
name|sc_write_mbufs
function_decl|)
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
name|int
name|tx_timer
decl_stmt|;
name|int
name|nic_offset
decl_stmt|;
comment|/* NIC (DS8390) I/O bus address offset */
name|int
name|asic_offset
decl_stmt|;
comment|/* ASIC I/O bus address offset */
comment|/*  * The following 'proto' variable is part of a work-around for 8013EBT asics  *	being write-only. It's sort of a prototype/shadow of the real thing.  */
name|u_char
name|wd_laar_proto
decl_stmt|;
name|u_char
name|cr_proto
decl_stmt|;
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
name|bus_size_t
name|mem_start
decl_stmt|;
comment|/* NIC memory start address */
name|bus_size_t
name|mem_end
decl_stmt|;
comment|/* NIC memory end address */
name|uint32_t
name|mem_size
decl_stmt|;
comment|/* total NIC memory size */
name|bus_size_t
name|mem_ring
decl_stmt|;
comment|/* start of RX ring-buffer (in NIC mem) */
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
name|u_int
name|tx_mem
decl_stmt|;
comment|/* Total amount of RAM for tx */
name|u_int
name|rx_mem
decl_stmt|;
comment|/* Total amount of RAM for rx */
name|struct
name|ifmib_iso_8802_3
name|mibdata
decl_stmt|;
comment|/* stuff for network mgmt */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ed_nic_inb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1(sc->port_bst, sc->port_bsh, (sc)->nic_offset + (port))
end_define

begin_define
define|#
directive|define
name|ed_nic_outb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1(sc->port_bst, sc->port_bsh, \ 	    (sc)->nic_offset + (port), (value))
end_define

begin_define
define|#
directive|define
name|ed_nic_inw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2(sc->port_bst, sc->port_bsh, (sc)->nic_offset + (port))
end_define

begin_define
define|#
directive|define
name|ed_nic_outw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2(sc->port_bst, sc->port_bsh, \ 	    (sc)->nic_offset + (port), (value))
end_define

begin_define
define|#
directive|define
name|ed_nic_insb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1(sc->port_bst,  sc->port_bsh, \ 		(sc)->nic_offset + (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_nic_outsb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1(sc->port_bst, sc->port_bsh, \ 		(sc)->nic_offset + (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_nic_insw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_2(sc->port_bst, sc->port_bsh, \ 		(sc)->nic_offset + (port), (uint16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_nic_outsw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_2(sc->port_bst, sc->port_bsh, \ 		(sc)->nic_offset + (port), (uint16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_nic_insl
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_4(sc->port_bst, sc->port_bsh, \ 		(sc)->nic_offset + (port), (uint32_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_nic_outsl
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_4(sc->port_bst, sc->port_bsh, \ 		(sc)->nic_offset + (port), (uint32_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_inb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1(sc->port_bst, sc->port_bsh, \ 	    (sc)->asic_offset + (port))
end_define

begin_define
define|#
directive|define
name|ed_asic_outb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1(sc->port_bst, sc->port_bsh, \ 	    (sc)->asic_offset + (port), (value))
end_define

begin_define
define|#
directive|define
name|ed_asic_inw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2(sc->port_bst, sc->port_bsh, \ 	    (sc)->asic_offset + (port))
end_define

begin_define
define|#
directive|define
name|ed_asic_outw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2(sc->port_bst, sc->port_bsh, \ 	    (sc)->asic_offset + (port), (value))
end_define

begin_define
define|#
directive|define
name|ed_asic_insb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_outsb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_insw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_2(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (uint16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_outsw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_2(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (uint16_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_insl
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_4(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (uint32_t *)(addr), (count))
end_define

begin_define
define|#
directive|define
name|ed_asic_outsl
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_4(sc->port_bst, sc->port_bsh, \ 		(sc)->asic_offset + (port), (uint32_t *)(addr), (count))
end_define

begin_function_decl
name|void
name|ed_release_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_alloc_port
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_alloc_memory
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_alloc_irq
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_probe_generic8390
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_probe_WD80x3
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_probe_WD80x3_generic
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uint16_t
modifier|*
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_probe_RTL80x9
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ED_3C503
end_ifdef

begin_function_decl
name|int
name|ed_probe_3Com
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ED_SIC
end_ifdef

begin_function_decl
name|int
name|ed_probe_SIC
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ed_probe_Novell_generic
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_probe_Novell
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_Novell_read_mac
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ED_HPP
end_ifdef

begin_function_decl
name|int
name|ed_probe_HP_pclanp
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ed_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_clear_memory
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ed_isa_mem_ok
parameter_list|(
name|device_t
parameter_list|,
name|u_long
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX isa specific */
end_comment

begin_function_decl
name|void
name|ed_stop
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_shmem_readmem16
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_shmem_readmem8
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|ed_shmem_write_mbufs
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_pio_readmem
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_pio_writemem
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|ed_pio_write_mbufs
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_disable_16bit_access
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_enable_16bit_access
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ed_gen_ifmedia_init
parameter_list|(
name|struct
name|ed_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_intr_t
name|edintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|ed_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vendor types  */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_WD_SMC
value|0x00
end_define

begin_comment
comment|/* Western Digital/SMC */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_3COM
value|0x01
end_define

begin_comment
comment|/* 3Com */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_NOVELL
value|0x02
end_define

begin_comment
comment|/* Novell */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_HP
value|0x03
end_define

begin_comment
comment|/* Hewlett Packard */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_SIC
value|0x04
end_define

begin_comment
comment|/* Allied-Telesis SIC */
end_comment

begin_comment
comment|/*  * Configure time flags  */
end_comment

begin_comment
comment|/*  * this sets the default for enabling/disabling the transceiver  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_DISABLE_TRANCEIVER
value|0x0001
end_define

begin_comment
comment|/*  * This forces the board to be used in 8/16bit mode even if it  *	autoconfigs differently  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_8BIT_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_16BIT_MODE
value|0x0004
end_define

begin_comment
comment|/*  * This disables the use of double transmit buffers.  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_NO_MULTI_BUFFERING
value|0x0008
end_define

begin_comment
comment|/*  * This forces all operations with the NIC memory to use Programmed  *	I/O (i.e. not via shared memory)  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_PIO
value|0x0010
end_define

begin_comment
comment|/*  * This forces a PC Card, and disables ISA memory range checks  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_PCCARD
value|0x0020
end_define

begin_comment
comment|/*  * These are flags describing the chip type.  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_TOSH_ETHER
value|0x10000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_GWETHER
value|0x20000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_GETTYPE
parameter_list|(
name|flg
parameter_list|)
value|((flg)& 0xff0000)
end_define

begin_define
define|#
directive|define
name|ED_MUTEX
parameter_list|(
name|_sc
parameter_list|)
value|(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ED_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(ED_MUTEX(_sc))
end_define

begin_define
define|#
directive|define
name|ED_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(ED_MUTEX(_sc))
end_define

begin_define
define|#
directive|define
name|ED_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(ED_MUTEX(_sc), device_get_nameunit(_sc->dev), \ 	    MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ED_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(ED_MUTEX(_sc));
end_define

begin_define
define|#
directive|define
name|ED_ASSERT_LOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(ED_MUTEX(_sc), MA_OWNED);
end_define

begin_define
define|#
directive|define
name|ED_ASSERT_UNLOCKED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(ED_MUTEX(_sc), MA_NOTOWNED);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_DEV_ED_IF_EDVAR_H */
end_comment

end_unit

