begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 ATMEL  * Copyright (c) 2007 Hans Petter Selasky<hselasky@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * USB Device Port (UDP) register definition, based on "AT91RM9200.h" provided  * by ATMEL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AT9100_DCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_AT9100_DCI_H_
end_define

begin_define
define|#
directive|define
name|AT91_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_define
define|#
directive|define
name|AT91_UDP_FRM
value|0x00
end_define

begin_comment
comment|/* Frame number register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FRM_MASK
value|(0x7FF<<  0)
end_define

begin_comment
comment|/* Frame Number as Defined in 						 * the Packet Field Formats */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FRM_ERR
value|(0x1<< 16)
end_define

begin_comment
comment|/* Frame Error */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FRM_OK
value|(0x1<< 17)
end_define

begin_comment
comment|/* Frame OK */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE
value|0x04
end_define

begin_comment
comment|/* Global state register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE_ADDR
value|(0x1<<  0)
end_define

begin_comment
comment|/* Addressed state */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE_CONFG
value|(0x1<<  1)
end_define

begin_comment
comment|/* Configured */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE_ESR
value|(0x1<<  2)
end_define

begin_comment
comment|/* Enable Send Resume */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE_RSM
value|(0x1<<  3)
end_define

begin_comment
comment|/* A Resume Has Been Sent to 						 * the Host */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_GSTATE_RMW
value|(0x1<<  4)
end_define

begin_comment
comment|/* Remote Wake Up Enable */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FADDR
value|0x08
end_define

begin_comment
comment|/* Function Address Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FADDR_MASK
value|(0x7F<< 0)
end_define

begin_comment
comment|/* Function Address Mask */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FADDR_EN
value|(0x1<<  8)
end_define

begin_comment
comment|/* Function Enable */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_RES0
value|0x0C
end_define

begin_comment
comment|/* Reserved 0 */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_IER
value|0x10
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_IDR
value|0x14
end_define

begin_comment
comment|/* Interrupt Disable Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_IMR
value|0x18
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_ISR
value|0x1C
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_ICR
value|0x20
end_define

begin_comment
comment|/* Interrupt Clear Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_EP
parameter_list|(
name|n
parameter_list|)
value|(0x1<<(n))
end_define

begin_comment
comment|/* Endpoint "n" Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_RXSUSP
value|(0x1<<  8)
end_define

begin_comment
comment|/* USB Suspend Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_RXRSM
value|(0x1<<  9)
end_define

begin_comment
comment|/* USB Resume Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_EXTRSM
value|(0x1<< 10)
end_define

begin_comment
comment|/* USB External Resume Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_SOFINT
value|(0x1<< 11)
end_define

begin_comment
comment|/* USB Start Of frame Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_END_BR
value|(0x1<< 12)
end_define

begin_comment
comment|/* USB End Of Bus Reset Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_WAKEUP
value|(0x1<< 13)
end_define

begin_comment
comment|/* USB Resume Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_INT_BUS
define|\
value|(AT91_UDP_INT_RXSUSP|AT91_UDP_INT_RXRSM| \    AT91_UDP_INT_END_BR)
end_define

begin_define
define|#
directive|define
name|AT91_UDP_INT_EPS
define|\
value|(AT91_UDP_INT_EP(0)|AT91_UDP_INT_EP(1)| \    AT91_UDP_INT_EP(2)|AT91_UDP_INT_EP(3)| \    AT91_UDP_INT_EP(4)|AT91_UDP_INT_EP(5))
end_define

begin_define
define|#
directive|define
name|AT91_UDP_INT_DEFAULT
define|\
value|(AT91_UDP_INT_EPS|AT91_UDP_INT_BUS)
end_define

begin_define
define|#
directive|define
name|AT91_UDP_RES1
value|0x24
end_define

begin_comment
comment|/* Reserved 1 */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_RST
value|0x28
end_define

begin_comment
comment|/* Reset Endpoint Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_RST_EP
parameter_list|(
name|n
parameter_list|)
value|(0x1<<  (n))
end_define

begin_comment
comment|/* Reset Endpoint "n" */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_RES2
value|0x2C
end_define

begin_comment
comment|/* Reserved 2 */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR
parameter_list|(
name|n
parameter_list|)
value|(0x30 + (4*(n)))
end_define

begin_comment
comment|/* Endpoint Control and Status 					 * Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_TXCOMP
value|(0x1<<  0)
end_define

begin_comment
comment|/* Generates an IN packet with data 					 * previously written in the DPR */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_RX_DATA_BK0
value|(0x1<<  1)
end_define

begin_comment
comment|/* Receive Data Bank 0 */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_RXSETUP
value|(0x1<<  2)
end_define

begin_comment
comment|/* Sends STALL to the Host 						 * (Control endpoints) */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ISOERROR
value|(0x1<<  3)
end_define

begin_comment
comment|/* Isochronous error 						 * (Isochronous endpoints) */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_STALLSENT
value|(0x1<<  3)
end_define

begin_comment
comment|/* Stall sent (Control, bulk, 						 * interrupt endpoints) */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_TXPKTRDY
value|(0x1<<  4)
end_define

begin_comment
comment|/* Transmit Packet Ready */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_FORCESTALL
value|(0x1<<  5)
end_define

begin_comment
comment|/* Force Stall (used by 						 * Control, Bulk and 						 * Isochronous endpoints). */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_RX_DATA_BK1
value|(0x1<<  6)
end_define

begin_comment
comment|/* Receive Data Bank 1 (only 						 * used by endpoints with 						 * ping-pong attributes). */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_DIR
value|(0x1<<  7)
end_define

begin_comment
comment|/* Transfer Direction */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_MASK
value|(0x7<<  8)
end_define

begin_comment
comment|/* Endpoint transfer type mask */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_CTRL
value|(0x0<<  8)
end_define

begin_comment
comment|/* Control IN+OUT */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_ISO
value|(0x1<<  8)
end_define

begin_comment
comment|/* Isochronous */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_BULK
value|(0x2<<  8)
end_define

begin_comment
comment|/* Bulk */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_INT
value|(0x3<<  8)
end_define

begin_comment
comment|/* Interrupt */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_DIR_OUT
value|(0x0<<  8)
end_define

begin_comment
comment|/* OUT tokens */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_ET_DIR_IN
value|(0x4<<  8)
end_define

begin_comment
comment|/* IN tokens */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_DTGLE
value|(0x1<< 11)
end_define

begin_comment
comment|/* Data Toggle */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_EPEDS
value|(0x1<< 15)
end_define

begin_comment
comment|/* Endpoint Enable Disable */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_CSR_RXBYTECNT
value|(0x7FF<< 16)
end_define

begin_comment
comment|/* Number Of Bytes Available 						 * in the FIFO */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_FDR
parameter_list|(
name|n
parameter_list|)
value|(0x50 + (4*(n)))
end_define

begin_comment
comment|/* Endpoint FIFO Data Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_RES3
value|0x70
end_define

begin_comment
comment|/* Reserved 3 */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_TXVC
value|0x74
end_define

begin_comment
comment|/* Transceiver Control Register */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_TXVC_DIS
value|(0x1<<  8)
end_define

begin_define
define|#
directive|define
name|AT91_UDP_EP_MAX
value|6
end_define

begin_comment
comment|/* maximum number of endpoints 					 * supported */
end_comment

begin_define
define|#
directive|define
name|AT91_UDP_READ_4
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
name|AT91_UDP_WRITE_4
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

begin_struct_decl
struct_decl|struct
name|at91dci_td
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|at91dci_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|at91dci_cmd_t
function_decl|)
parameter_list|(
name|struct
name|at91dci_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|at91dci_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|at91dci_td
block|{
name|struct
name|at91dci_td
modifier|*
name|obj_next
decl_stmt|;
name|at91dci_cmd_t
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
name|status_reg
decl_stmt|;
name|uint8_t
name|fifo_reg
decl_stmt|;
name|uint8_t
name|fifo_bank
range|:
literal|1
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91dci_std_temp
block|{
name|at91dci_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|at91dci_td
modifier|*
name|td
decl_stmt|;
name|struct
name|at91dci_td
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
name|at91dci_config_desc
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
name|at91dci_hub_temp
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
name|at91dci_ep_flags
block|{
name|uint8_t
name|fifo_bank
range|:
literal|1
decl_stmt|;
comment|/* hardware specific */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91dci_flags
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
name|at91dci_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|at91dci_hub_temp
name|sc_hub_temp
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|AT91_MAX_DEVICES
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
name|void
function_decl|(
modifier|*
name|sc_clocks_on
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_clocks_off
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|sc_clocks_arg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sc_pull_up
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_pull_down
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|sc_pull_arg
decl_stmt|;
name|uint32_t
name|sc_xfer_complete
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
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|at91dci_flags
name|sc_flags
decl_stmt|;
name|struct
name|at91dci_ep_flags
name|sc_ep_flags
index|[
name|AT91_UDP_EP_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|usb_error_t
name|at91dci_init
parameter_list|(
name|struct
name|at91dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|at91dci_uninit
parameter_list|(
name|struct
name|at91dci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|driver_filter_t
name|at91dci_filter_interrupt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_intr_t
name|at91dci_interrupt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|at91dci_vbus_interrupt
parameter_list|(
name|struct
name|at91dci_softc
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
comment|/* _AT9100_DCI_H_ */
end_comment

end_unit

