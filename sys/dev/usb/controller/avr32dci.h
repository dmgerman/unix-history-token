begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AVR32DCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_AVR32DCI_H_
end_define

begin_define
define|#
directive|define
name|AVR32_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_comment
comment|/* Register definitions */
end_comment

begin_define
define|#
directive|define
name|AVR32_CTRL
value|0x00
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|AVR32_CTRL_DEV_ADDR
value|0x7F
end_define

begin_define
define|#
directive|define
name|AVR32_CTRL_DEV_FADDR_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|AVR32_CTRL_DEV_EN_USBA
value|0x100
end_define

begin_define
define|#
directive|define
name|AVR32_CTRL_DEV_DETACH
value|0x200
end_define

begin_define
define|#
directive|define
name|AVR32_CTRL_DEV_REWAKEUP
value|0x400
end_define

begin_define
define|#
directive|define
name|AVR32_FNUM
value|0x04
end_define

begin_comment
comment|/* Frame Number */
end_comment

begin_define
define|#
directive|define
name|AVR32_FNUM_MASK
value|0x3FFF
end_define

begin_define
define|#
directive|define
name|AVR32_FRAME_MASK
value|0x7FF
end_define

begin_comment
comment|/* 0x08 - 0x0C Reserved */
end_comment

begin_define
define|#
directive|define
name|AVR32_IEN
value|0x10
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|AVR32_INTSTA
value|0x14
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|AVR32_CLRINT
value|0x18
end_define

begin_comment
comment|/* Clear Interrupt */
end_comment

begin_define
define|#
directive|define
name|AVR32_INT_SPEED
value|0x00000001
end_define

begin_comment
comment|/* set if High Speed else Full Speed */
end_comment

begin_define
define|#
directive|define
name|AVR32_INT_DET_SUSPD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AVR32_INT_MICRO_SOF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AVR32_INT_INT_SOF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AVR32_INT_ENDRESET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AVR32_INT_WAKE_UP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AVR32_INT_ENDOFRSM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AVR32_INT_UPSTR_RES
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AVR32_INT_EPT_INT
parameter_list|(
name|n
parameter_list|)
value|(0x00000100<< (n))
end_define

begin_define
define|#
directive|define
name|AVR32_INT_DMA_INT
parameter_list|(
name|n
parameter_list|)
value|(0x01000000<< (n))
end_define

begin_define
define|#
directive|define
name|AVR32_EPTRST
value|0x1C
end_define

begin_comment
comment|/* Endpoints Reset */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTRST_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x00000001<< (n))
end_define

begin_comment
comment|/* 0x20 - 0xCC Reserved */
end_comment

begin_define
define|#
directive|define
name|AVR32_TSTSOFCNT
value|0xD0
end_define

begin_comment
comment|/* Test SOF Counter */
end_comment

begin_define
define|#
directive|define
name|AVR32_TSTCNTA
value|0xD4
end_define

begin_comment
comment|/* Test A Counter */
end_comment

begin_define
define|#
directive|define
name|AVR32_TSTCNTB
value|0xD8
end_define

begin_comment
comment|/* Test B Counter */
end_comment

begin_define
define|#
directive|define
name|AVR32_TSTMODEREG
value|0xDC
end_define

begin_comment
comment|/* Test Mode */
end_comment

begin_define
define|#
directive|define
name|AVR32_TST
value|0xE0
end_define

begin_comment
comment|/* Test */
end_comment

begin_define
define|#
directive|define
name|AVR32_TST_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AVR32_TST_HS_ONLY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AVR32_TST_FS_ONLY
value|0x00000003
end_define

begin_comment
comment|/* 0xE4 - 0xE8 Reserved */
end_comment

begin_define
define|#
directive|define
name|AVR32_IPPADDRSIZE
value|0xEC
end_define

begin_comment
comment|/* PADDRSIZE */
end_comment

begin_define
define|#
directive|define
name|AVR32_IPNAME1
value|0xF0
end_define

begin_comment
comment|/* Name1 */
end_comment

begin_define
define|#
directive|define
name|AVR32_IPNAME2
value|0xF4
end_define

begin_comment
comment|/* Name2 */
end_comment

begin_define
define|#
directive|define
name|AVR32_IPFEATURES
value|0xF8
end_define

begin_comment
comment|/* Features */
end_comment

begin_define
define|#
directive|define
name|AVR32_IPFEATURES_NEP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF) ? ((x)& 0xF) : 0x10)
end_define

begin_define
define|#
directive|define
name|AVR32_IPVERSION
value|0xFC
end_define

begin_comment
comment|/* IP Version */
end_comment

begin_define
define|#
directive|define
name|_A
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|)
value|((base) + (0x20*(n)))
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG
parameter_list|(
name|n
parameter_list|)
value|_A(0x100, n)
end_define

begin_comment
comment|/* Endpoint Configuration */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCFG_EPSIZE
parameter_list|(
name|n
parameter_list|)
value|((n)-3)
end_define

begin_comment
comment|/* power of two */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCFG_EPDIR_OUT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_EPDIR_IN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_TYPE_CTRL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_TYPE_ISOC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_TYPE_BULK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_TYPE_INTR
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_NBANK
parameter_list|(
name|n
parameter_list|)
value|(0x00000400*(n))
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_NB_TRANS
parameter_list|(
name|n
parameter_list|)
value|(0x00001000*(n))
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCFG_EPT_MAPD
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTLENB
parameter_list|(
name|n
parameter_list|)
value|_A(0x104, n)
end_define

begin_comment
comment|/* Endpoint Control Enable */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCTLDIS
parameter_list|(
name|n
parameter_list|)
value|_A(0x108, n)
end_define

begin_comment
comment|/* Endpoint Control Disable */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCTL
parameter_list|(
name|n
parameter_list|)
value|_A(0x10C, n)
end_define

begin_comment
comment|/* Endpoint Control */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCTL_EPT_ENABL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_AUTO_VALID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_INTDIS_DMA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_NYET_DIS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_DATAX_RX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_MDATA_RX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_ERR_OVFLW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_RX_BK_RDY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_TX_COMPLT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_TX_PK_RDY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_RX_SETUP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_STALL_SNT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_NAK_IN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_NAK_OUT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_BUSY_BANK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTCTL_SHORT_PCKT
value|0x80000000
end_define

begin_comment
comment|/* 0x110 Reserved */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTSETSTA
parameter_list|(
name|n
parameter_list|)
value|_A(0x114, n)
end_define

begin_comment
comment|/* Endpoint Set Status */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTCLRSTA
parameter_list|(
name|n
parameter_list|)
value|_A(0x118, n)
end_define

begin_comment
comment|/* Endpoint Clear Status */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTSTA
parameter_list|(
name|n
parameter_list|)
value|_A(0x11C, n)
end_define

begin_comment
comment|/* Endpoint Status */
end_comment

begin_define
define|#
directive|define
name|AVR32_EPTSTA_FRCESTALL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_TOGGLESQ_STA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_TOGGLESQ
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_ERR_OVFLW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_RX_BK_RDY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_TX_COMPLT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_TX_PK_RDY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_RX_SETUP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_STALL_SNT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_NAK_IN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_NAK_OUT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_CURRENT_BANK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x00030000)>> 16)
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_BUSY_BANK_STA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x000C0000)>> 18)
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_BYTE_COUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FF00000)>> 20)
end_define

begin_define
define|#
directive|define
name|AVR32_EPTSTA_SHRT_PCKT
value|0x80000000
end_define

begin_comment
comment|/* 0x300 - 0x30C Reserved */
end_comment

begin_define
define|#
directive|define
name|AVR32_DMANXTDSC
value|0x310
end_define

begin_comment
comment|/* DMA Next Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|AVR32_DMAADDRESS
value|0x314
end_define

begin_comment
comment|/* DMA Channel Address */
end_comment

begin_define
define|#
directive|define
name|AVR32_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg)
end_define

begin_define
define|#
directive|define
name|AVR32_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, data)
end_define

begin_define
define|#
directive|define
name|AVR32_WRITE_MULTI_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|)
define|\
value|bus_space_write_multi_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, ptr, len)
end_define

begin_define
define|#
directive|define
name|AVR32_READ_MULTI_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|)
define|\
value|bus_space_read_multi_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, ptr, len)
end_define

begin_comment
comment|/*  * Maximum number of endpoints supported:  */
end_comment

begin_define
define|#
directive|define
name|AVR32_EP_MAX
value|7
end_define

begin_struct_decl
struct_decl|struct
name|avr32dci_td
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|avr32dci_cmd_t
function_decl|)
parameter_list|(
name|struct
name|avr32dci_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|avr32dci_clocks_t
function_decl|)
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|avr32dci_td
block|{
name|struct
name|avr32dci_td
modifier|*
name|obj_next
decl_stmt|;
name|avr32dci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|remainder
decl_stmt|;
name|uint16_t
name|max_packet_size
decl_stmt|;
name|uint8_t
name|bank_shift
decl_stmt|;
name|uint8_t
name|error
range|:
literal|1
decl_stmt|;
name|uint8_t
name|alt_next
range|:
literal|1
decl_stmt|;
name|uint8_t
name|short_pkt
range|:
literal|1
decl_stmt|;
name|uint8_t
name|support_multi_buffer
range|:
literal|1
decl_stmt|;
name|uint8_t
name|did_stall
range|:
literal|1
decl_stmt|;
name|uint8_t
name|ep_no
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|avr32dci_std_temp
block|{
name|avr32dci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|avr32dci_td
modifier|*
name|td
decl_stmt|;
name|struct
name|avr32dci_td
modifier|*
name|td_next
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint8_t
name|bank_shift
decl_stmt|;
name|uint8_t
name|short_pkt
decl_stmt|;
comment|/*          * short_pkt = 0: transfer should be short terminated          * short_pkt = 1: transfer should not be short terminated          */
name|uint8_t
name|setup_alt_next
decl_stmt|;
name|uint8_t
name|did_stall
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|avr32dci_config_desc
block|{
name|struct
name|usb_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|avr32dci_hub_temp
block|{
name|uWord
name|wValue
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|avr32dci_flags
block|{
name|uint8_t
name|change_connect
range|:
literal|1
decl_stmt|;
name|uint8_t
name|change_suspend
range|:
literal|1
decl_stmt|;
name|uint8_t
name|status_suspend
range|:
literal|1
decl_stmt|;
comment|/* set if suspended */
name|uint8_t
name|status_vbus
range|:
literal|1
decl_stmt|;
comment|/* set if present */
name|uint8_t
name|status_bus_reset
range|:
literal|1
decl_stmt|;
comment|/* set if reset complete */
name|uint8_t
name|remote_wakeup
range|:
literal|1
decl_stmt|;
name|uint8_t
name|self_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|clocks_off
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_enabled
range|:
literal|1
decl_stmt|;
name|uint8_t
name|d_pulled_up
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|avr32dci_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|avr32dci_hub_temp
name|sc_hub_temp
decl_stmt|;
comment|/* must be set by by the bus interface layer */
name|avr32dci_clocks_t
modifier|*
name|sc_clocks_on
decl_stmt|;
name|avr32dci_clocks_t
modifier|*
name|sc_clocks_off
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|AVR32_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|uint8_t
modifier|*
name|physdata
decl_stmt|;
name|uint8_t
name|sc_rt_addr
decl_stmt|;
comment|/* root hub address */
name|uint8_t
name|sc_dv_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root hub config */
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|avr32dci_flags
name|sc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|usb_error_t
name|avr32dci_init
parameter_list|(
name|struct
name|avr32dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|avr32dci_uninit
parameter_list|(
name|struct
name|avr32dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|avr32dci_interrupt
parameter_list|(
name|struct
name|avr32dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|avr32dci_vbus_interrupt
parameter_list|(
name|struct
name|avr32dci_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|is_on
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AVR32DCI_H_ */
end_comment

end_unit

