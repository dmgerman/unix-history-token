begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 Hans Petter Selasky<hselasky@FreeBSD.org>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAF1761_OTG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAF1761_OTG_H_
end_define

begin_define
define|#
directive|define
name|SOTG_MAX_DEVICES
value|MIN(USB_MAX_DEVICES, 32)
end_define

begin_define
define|#
directive|define
name|SOTG_FS_MAX_PACKET_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|SOTG_HS_MAX_PACKET_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|SOTG_NUM_PORTS
value|2
end_define

begin_comment
comment|/* one Device and one Host port */
end_comment

begin_define
define|#
directive|define
name|SOTG_HOST_PORT_NUM
value|1
end_define

begin_define
define|#
directive|define
name|SOTG_DEVICE_PORT_NUM
value|2
end_define

begin_define
define|#
directive|define
name|SOTG_HOST_CHANNEL_MAX
value|(3 * 32)
end_define

begin_comment
comment|/* Macros used for reading and writing little endian registers */
end_comment

begin_define
define|#
directive|define
name|SAF1761_READ_LE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|({ uint32_t _temp; \   _temp = bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (reg)); \   le32toh(_temp); })
end_define

begin_define
define|#
directive|define
name|SAF1761_WRITE_LE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
value|do { \   uint32_t _temp = (data); \   bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (reg), htole32(_temp)); \ } while (0)
end_define

begin_comment
comment|/* 90ns delay macro */
end_comment

begin_define
define|#
directive|define
name|SAF1761_90NS_DELAY
parameter_list|(
name|sc
parameter_list|)
value|do { \ 	(void) SAF1761_READ_LE_4(sc, SOTG_VEND_PROD_ID); \ 	(void) SAF1761_READ_LE_4(sc, SOTG_VEND_PROD_ID); \ 	(void) SAF1761_READ_LE_4(sc, SOTG_VEND_PROD_ID); \ 	(void) SAF1761_READ_LE_4(sc, SOTG_VEND_PROD_ID); \ } while (0)
end_define

begin_struct_decl
struct_decl|struct
name|saf1761_otg_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|saf1761_otg_td
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|saf1761_otg_cmd_t
function_decl|)
parameter_list|(
name|struct
name|saf1761_otg_softc
modifier|*
parameter_list|,
name|struct
name|saf1761_otg_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|saf1761_otg_td
block|{
name|struct
name|saf1761_otg_td
modifier|*
name|obj_next
decl_stmt|;
name|saf1761_otg_cmd_t
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
name|uint32_t
name|dw1_value
decl_stmt|;
name|uint16_t
name|max_packet_size
decl_stmt|;
name|uint8_t
name|ep_index
decl_stmt|;
name|uint8_t
name|ep_type
decl_stmt|;
name|uint8_t
name|channel
decl_stmt|;
name|uint8_t
name|uframe
decl_stmt|;
name|uint8_t
name|interval
decl_stmt|;
name|uint8_t
name|error_any
range|:
literal|1
decl_stmt|;
name|uint8_t
name|error_stall
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
name|did_stall
range|:
literal|1
decl_stmt|;
name|uint8_t
name|toggle
range|:
literal|1
decl_stmt|;
name|uint8_t
name|set_toggle
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|saf1761_otg_std_temp
block|{
name|saf1761_otg_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|saf1761_otg_td
modifier|*
name|td
decl_stmt|;
name|struct
name|saf1761_otg_td
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
name|uint8_t
name|did_stall
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|saf1761_otg_config_desc
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
name|saf1761_otg_hub_temp
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
name|saf1761_otg_flags
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
name|saf1761_otg_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|saf1761_otg_hub_temp
name|sc_hub_temp
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|SOTG_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
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
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|uint32_t
name|sc_host_async_map
decl_stmt|;
name|uint32_t
name|sc_host_async_suspend_map
decl_stmt|;
name|uint32_t
name|sc_host_intr_map
decl_stmt|;
name|uint32_t
name|sc_host_intr_suspend_map
decl_stmt|;
name|uint32_t
name|sc_host_isoc_map
decl_stmt|;
name|uint32_t
name|sc_host_isoc_suspend_map
decl_stmt|;
name|uint32_t
name|sc_intr_enable
decl_stmt|;
comment|/* enabled interrupts */
name|uint32_t
name|sc_hw_mode
decl_stmt|;
comment|/* hardware mode */
name|uint32_t
name|sc_interrupt_cfg
decl_stmt|;
comment|/* interrupt configuration */
name|uint32_t
name|sc_xfer_complete
decl_stmt|;
name|uint32_t
name|sc_bounce_buffer
index|[
literal|1024
operator|/
literal|4
index|]
decl_stmt|;
name|uint8_t
name|sc_rt_addr
decl_stmt|;
comment|/* root HUB address */
name|uint8_t
name|sc_dv_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root HUB config */
name|uint8_t
name|sc_isreset
decl_stmt|;
comment|/* host mode */
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|saf1761_otg_flags
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
name|saf1761_otg_init
parameter_list|(
name|struct
name|saf1761_otg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|saf1761_otg_uninit
parameter_list|(
name|struct
name|saf1761_otg_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_filter_t
name|saf1761_otg_filter_interrupt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_intr_t
name|saf1761_otg_interrupt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SAF1761_OTG_H_ */
end_comment

end_unit

