begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * USB Device Port register definitions, copied from ATMEGA  * documentation provided by ATMEL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATMEGADCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATMEGADCI_H_
end_define

begin_define
define|#
directive|define
name|ATMEGA_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ATMEGA_HAVE_BUS_SPACE
end_ifndef

begin_define
define|#
directive|define
name|ATMEGA_HAVE_BUS_SPACE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATMEGA_UEINT
value|0xF4
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINT_MASK
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_comment
comment|/* endpoint interrupt mask */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEBCHX
value|0xF3
end_define

begin_comment
comment|/* FIFO byte count high */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEBCLX
value|0xF2
end_define

begin_comment
comment|/* FIFO byte count low */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEDATX
value|0xF1
end_define

begin_comment
comment|/* FIFO data */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEIENX
value|0xF0
end_define

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_TXINE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_STALLEDE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_RXOUTE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_RXSTPE
value|(1<< 3)
end_define

begin_comment
comment|/* received SETUP packet */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_NAKOUTE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_NAKINE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEIENX_FLERRE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UESTA1X
value|0xEF
end_define

begin_define
define|#
directive|define
name|ATMEGA_UESTA1X_CURRBK
value|(3<< 0)
end_define

begin_comment
comment|/* current bank */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UESTA1X_CTRLDIR
value|(1<< 2)
end_define

begin_comment
comment|/* control endpoint direction */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X
value|0xEE
end_define

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X_NBUSYBK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X_DTSEQ
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X_UNDERFI
value|(1<< 5)
end_define

begin_comment
comment|/* underflow */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X_OVERFI
value|(1<< 6)
end_define

begin_comment
comment|/* overflow */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UESTA0X_CFGOK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X
value|0xED
end_define

begin_comment
comment|/* endpoint config register */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_ALLOC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_EPBK0
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_EPBK1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_EPBK2
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_EPBK3
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG1X_EPSIZE
parameter_list|(
name|n
parameter_list|)
value|((n)<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X
value|0xEC
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X_EPDIR
value|(1<< 0)
end_define

begin_comment
comment|/* endpoint direction */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X_EPTYPE0
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X_EPTYPE1
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X_EPTYPE2
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECFG0X_EPTYPE3
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECONX
value|0xEB
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECONX_EPEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECONX_RSTDT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UECONX_STALLRQC
value|(1<< 4)
end_define

begin_comment
comment|/* stall request clear */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UECONX_STALLRQ
value|(1<< 5)
end_define

begin_comment
comment|/* stall request set */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UERST
value|0xEA
end_define

begin_comment
comment|/* endpoint reset register */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UERST_MASK
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|ATMEGA_UENUM
value|0xE9
end_define

begin_comment
comment|/* endpoint number */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEINTX
value|0xE8
end_define

begin_comment
comment|/* interrupt register */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_TXINI
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_STALLEDI
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_RXOUTI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_RXSTPI
value|(1<< 3)
end_define

begin_comment
comment|/* received setup packet */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_NAKOUTI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_RWAL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_NAKINI
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UEINTX_FIFOCON
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDMFN
value|0xE6
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDMFN_FNCERR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDFNUMH
value|0xE5
end_define

begin_comment
comment|/* frame number high */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDFNUMH_MASK
value|7
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDFNUML
value|0xE4
end_define

begin_comment
comment|/* frame number low */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDFNUML_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|ATMEGA_FRAME_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDADDR
value|0xE3
end_define

begin_comment
comment|/* USB address */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDADDR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDADDR_ADDEN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDIEN
value|0xE2
end_define

begin_comment
comment|/* USB device interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDINT_SUSPE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_MSOFE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_SOFE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_EORSTE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_WAKEUPE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_EORSME
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_UPRSME
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT
value|0xE1
end_define

begin_comment
comment|/* USB device interrupt status */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDINT_SUSPI
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_MSOFI
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_SOFI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_EORSTI
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_WAKEUPI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_EORSMI
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDINT_UPRSMI
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDCON
value|0xE0
end_define

begin_comment
comment|/* USB device connection register */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_UDCON_DETACH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDCON_RMWKUP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDCON_LSM
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UDCON_RSTCPU
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBINT
value|0xDA
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBINT_VBUSTI
value|(1<< 0)
end_define

begin_comment
comment|/* USB VBUS interrupt */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_USBSTA
value|0xD9
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBSTA_VBUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBSTA_ID
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBCON
value|0xD8
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBCON_VBUSTE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBCON_OTGPADE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBCON_FRZCLK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ATMEGA_USBCON_USBE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UHWCON
value|0xD7
end_define

begin_define
define|#
directive|define
name|ATMEGA_UHWCON_UVREGE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UHWCON_UVCONE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UHWCON_UIDE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ATMEGA_UHWCON_UIMOD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ATMEGA_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg)
end_define

begin_define
define|#
directive|define
name|ATMEGA_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, data)
end_define

begin_define
define|#
directive|define
name|ATMEGA_WRITE_MULTI_1
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
value|bus_space_write_multi_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, ptr, len)
end_define

begin_define
define|#
directive|define
name|ATMEGA_READ_MULTI_1
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
value|bus_space_read_multi_1((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, ptr, len)
end_define

begin_comment
comment|/*  * Maximum number of endpoints supported:  */
end_comment

begin_define
define|#
directive|define
name|ATMEGA_EP_MAX
value|7
end_define

begin_struct_decl
struct_decl|struct
name|atmegadci_td
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|atmegadci_cmd_t
function_decl|)
parameter_list|(
name|struct
name|atmegadci_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|atmegadci_clocks_t
function_decl|)
parameter_list|(
name|struct
name|usb2_bus
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|atmegadci_td
block|{
name|struct
name|atmegadci_td
modifier|*
name|obj_next
decl_stmt|;
name|atmegadci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb2_page_cache
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
name|atmegadci_std_temp
block|{
name|atmegadci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|atmegadci_td
modifier|*
name|td
decl_stmt|;
name|struct
name|atmegadci_td
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
name|short_pkt
decl_stmt|;
comment|/*          * short_pkt = 0: transfer should be short terminated          * short_pkt = 1: transfer should not be short terminated          */
name|uint8_t
name|setup_alt_next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmegadci_config_desc
block|{
name|struct
name|usb2_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb2_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb2_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|atmegadci_hub_temp
block|{
name|uWord
name|wValue
decl_stmt|;
name|struct
name|usb2_port_status
name|ps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|atmegadci_flags
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
name|atmegadci_softc
block|{
name|struct
name|usb2_bus
name|sc_bus
decl_stmt|;
name|union
name|atmegadci_hub_temp
name|sc_hub_temp
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|usb2_xfer
argument_list|)
name|sc_interrupt_list_head
expr_stmt|;
name|struct
name|usb2_sw_transfer
name|sc_root_ctrl
decl_stmt|;
name|struct
name|usb2_sw_transfer
name|sc_root_intr
decl_stmt|;
comment|/* must be set by by the bus interface layer */
name|atmegadci_clocks_t
modifier|*
name|sc_clocks_on
decl_stmt|;
name|atmegadci_clocks_t
modifier|*
name|sc_clocks_off
decl_stmt|;
name|struct
name|usb2_device
modifier|*
name|sc_devices
index|[
name|ATMEGA_MAX_DEVICES
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
if|#
directive|if
operator|(
name|ATMEGA_HAVE_BUS_SPACE
operator|!=
literal|0
operator|)
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
endif|#
directive|endif
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
name|atmegadci_flags
name|sc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|usb2_error_t
name|atmegadci_init
parameter_list|(
name|struct
name|atmegadci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atmegadci_uninit
parameter_list|(
name|struct
name|atmegadci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atmegadci_suspend
parameter_list|(
name|struct
name|atmegadci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atmegadci_resume
parameter_list|(
name|struct
name|atmegadci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atmegadci_interrupt
parameter_list|(
name|struct
name|atmegadci_softc
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
comment|/* _ATMEGADCI_H_ */
end_comment

end_unit

