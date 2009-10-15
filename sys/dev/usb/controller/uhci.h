begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UHCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_UHCI_H_
end_define

begin_define
define|#
directive|define
name|UHCI_MAX_DEVICES
value|MIN(USB_MAX_DEVICES, 128)
end_define

begin_define
define|#
directive|define
name|UHCI_FRAMELIST_COUNT
value|1024
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|UHCI_FRAMELIST_ALIGN
value|4096
end_define

begin_comment
comment|/* bytes */
end_comment

begin_comment
comment|/* Structures alignment (bytes) */
end_comment

begin_define
define|#
directive|define
name|UHCI_TD_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|UHCI_QH_ALIGN
value|16
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|USB_PAGE_SIZE
operator|<
name|UHCI_TD_ALIGN
operator|)
operator|||
operator|(
name|UHCI_TD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|UHCI_QH_ALIGN
operator|)
operator|||
operator|(
name|UHCI_QH_ALIGN
operator|==
literal|0
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Invalid USB page size!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint32_t
name|uhci_physaddr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UHCI_PTR_T
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UHCI_PTR_TD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|UHCI_PTR_QH
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UHCI_PTR_VF
value|0x00000004
end_define

begin_comment
comment|/*  * The Queue Heads (QH) and Transfer Descriptors (TD) are accessed by  * both the CPU and the USB-controller which run concurrently. Great  * care must be taken. When the data-structures are linked into the  * USB controller's frame list, the USB-controller "owns" the  * td_status and qh_elink fields, which will not be written by the  * CPU.  *  */
end_comment

begin_struct
struct|struct
name|uhci_td
block|{
comment|/*  * Data used by the UHCI controller.  * volatile is used in order to mantain struct members ordering.  */
specifier|volatile
name|uint32_t
name|td_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|td_status
decl_stmt|;
define|#
directive|define
name|UHCI_TD_GET_ACTLEN
parameter_list|(
name|s
parameter_list|)
value|(((s) + 1)& 0x3ff)
define|#
directive|define
name|UHCI_TD_ZERO_ACTLEN
parameter_list|(
name|t
parameter_list|)
value|((t) | 0x3ff)
define|#
directive|define
name|UHCI_TD_BITSTUFF
value|0x00020000
define|#
directive|define
name|UHCI_TD_CRCTO
value|0x00040000
define|#
directive|define
name|UHCI_TD_NAK
value|0x00080000
define|#
directive|define
name|UHCI_TD_BABBLE
value|0x00100000
define|#
directive|define
name|UHCI_TD_DBUFFER
value|0x00200000
define|#
directive|define
name|UHCI_TD_STALLED
value|0x00400000
define|#
directive|define
name|UHCI_TD_ACTIVE
value|0x00800000
define|#
directive|define
name|UHCI_TD_IOC
value|0x01000000
define|#
directive|define
name|UHCI_TD_IOS
value|0x02000000
define|#
directive|define
name|UHCI_TD_LS
value|0x04000000
define|#
directive|define
name|UHCI_TD_GET_ERRCNT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 27)& 3)
define|#
directive|define
name|UHCI_TD_SET_ERRCNT
parameter_list|(
name|n
parameter_list|)
value|((n)<< 27)
define|#
directive|define
name|UHCI_TD_SPD
value|0x20000000
specifier|volatile
name|uint32_t
name|td_token
decl_stmt|;
define|#
directive|define
name|UHCI_TD_PID
value|0x000000ff
define|#
directive|define
name|UHCI_TD_PID_IN
value|0x00000069
define|#
directive|define
name|UHCI_TD_PID_OUT
value|0x000000e1
define|#
directive|define
name|UHCI_TD_PID_SETUP
value|0x0000002d
define|#
directive|define
name|UHCI_TD_GET_PID
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
define|#
directive|define
name|UHCI_TD_SET_DEVADDR
parameter_list|(
name|a
parameter_list|)
value|((a)<< 8)
define|#
directive|define
name|UHCI_TD_GET_DEVADDR
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0x7f)
define|#
directive|define
name|UHCI_TD_SET_ENDPT
parameter_list|(
name|e
parameter_list|)
value|(((e)& 0xf)<< 15)
define|#
directive|define
name|UHCI_TD_GET_ENDPT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 15)& 0xf)
define|#
directive|define
name|UHCI_TD_SET_DT
parameter_list|(
name|t
parameter_list|)
value|((t)<< 19)
define|#
directive|define
name|UHCI_TD_GET_DT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 19)& 1)
define|#
directive|define
name|UHCI_TD_SET_MAXLEN
parameter_list|(
name|l
parameter_list|)
value|(((l)-1)<< 21)
define|#
directive|define
name|UHCI_TD_GET_MAXLEN
parameter_list|(
name|s
parameter_list|)
value|((((s)>> 21) + 1)& 0x7ff)
define|#
directive|define
name|UHCI_TD_MAXLEN_MASK
value|0xffe00000
specifier|volatile
name|uint32_t
name|td_buffer
decl_stmt|;
comment|/*  * Extra information needed:  */
name|struct
name|uhci_td
modifier|*
name|next
decl_stmt|;
name|struct
name|uhci_td
modifier|*
name|prev
decl_stmt|;
name|struct
name|uhci_td
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|fix_pc
decl_stmt|;
name|uint32_t
name|td_self
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|UHCI_TD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uhci_td
name|uhci_td_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UHCI_TD_ERROR
value|(UHCI_TD_BITSTUFF | UHCI_TD_CRCTO | 		\ 			UHCI_TD_BABBLE | UHCI_TD_DBUFFER | UHCI_TD_STALLED)
end_define

begin_define
define|#
directive|define
name|UHCI_TD_SETUP
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) |	\ 					UHCI_TD_SET_ENDPT(endp) |	\ 					UHCI_TD_SET_DEVADDR(dev) |	\ 					UHCI_TD_PID_SETUP)
end_define

begin_define
define|#
directive|define
name|UHCI_TD_OUT
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|,
name|dt
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) |	\ 					UHCI_TD_SET_ENDPT(endp) |	\ 					UHCI_TD_SET_DEVADDR(dev) |	\ 					UHCI_TD_PID_OUT | UHCI_TD_SET_DT(dt))
end_define

begin_define
define|#
directive|define
name|UHCI_TD_IN
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|,
name|dt
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) |	\ 					UHCI_TD_SET_ENDPT(endp) |	\ 					UHCI_TD_SET_DEVADDR(dev) |	\ 					UHCI_TD_PID_IN | UHCI_TD_SET_DT(dt))
end_define

begin_struct
struct|struct
name|uhci_qh
block|{
comment|/*  * Data used by the UHCI controller.  */
specifier|volatile
name|uint32_t
name|qh_h_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|qh_e_next
decl_stmt|;
comment|/*  * Extra information needed:  */
name|struct
name|uhci_qh
modifier|*
name|h_next
decl_stmt|;
name|struct
name|uhci_qh
modifier|*
name|h_prev
decl_stmt|;
name|struct
name|uhci_qh
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|uhci_td
modifier|*
name|e_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|qh_self
decl_stmt|;
name|uint16_t
name|intr_pos
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|UHCI_QH_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uhci_qh
name|uhci_qh_t
typedef|;
end_typedef

begin_comment
comment|/* Maximum number of isochronous TD's and QH's interrupt */
end_comment

begin_define
define|#
directive|define
name|UHCI_VFRAMELIST_COUNT
value|128
end_define

begin_define
define|#
directive|define
name|UHCI_IFRAMELIST_COUNT
value|(2 * UHCI_VFRAMELIST_COUNT)
end_define

begin_if
if|#
directive|if
operator|(
operator|(
operator|(
name|UHCI_VFRAMELIST_COUNT
operator|&
operator|(
name|UHCI_VFRAMELIST_COUNT
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
operator|)
operator|||
expr|\
operator|(
name|UHCI_VFRAMELIST_COUNT
operator|>
name|UHCI_FRAMELIST_COUNT
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"UHCI_VFRAMELIST_COUNT is not power of two"
end_error

begin_error
error|#
directive|error
literal|"or UHCI_VFRAMELIST_COUNT> UHCI_FRAMELIST_COUNT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|UHCI_VFRAMELIST_COUNT
operator|<
name|USB_MAX_FS_ISOC_FRAMES_PER_XFER
operator|)
end_if

begin_error
error|#
directive|error
literal|"maximum number of full-speed isochronous frames is higher than supported!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|uhci_config_desc
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
name|uhci_hub_desc
block|{
name|struct
name|usb_status
name|stat
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
name|uint8_t
name|temp
index|[
literal|128
index|]
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|uhci_hw_softc
block|{
name|struct
name|usb_page_cache
name|pframes_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|isoc_start_pc
index|[
name|UHCI_VFRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb_page_cache
name|intr_start_pc
index|[
name|UHCI_IFRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb_page_cache
name|ls_ctl_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|fs_ctl_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|bulk_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|last_qh_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|last_td_pc
decl_stmt|;
name|struct
name|usb_page
name|pframes_pg
decl_stmt|;
name|struct
name|usb_page
name|isoc_start_pg
index|[
name|UHCI_VFRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb_page
name|intr_start_pg
index|[
name|UHCI_IFRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb_page
name|ls_ctl_start_pg
decl_stmt|;
name|struct
name|usb_page
name|fs_ctl_start_pg
decl_stmt|;
name|struct
name|usb_page
name|bulk_start_pg
decl_stmt|;
name|struct
name|usb_page
name|last_qh_pg
decl_stmt|;
name|struct
name|usb_page
name|last_td_pg
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|uhci_softc
block|{
name|struct
name|uhci_hw_softc
name|sc_hw
decl_stmt|;
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
comment|/* base device */
name|union
name|uhci_hub_desc
name|sc_hub_desc
decl_stmt|;
name|struct
name|usb_callout
name|sc_root_intr
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|UHCI_MAX_DEVICES
index|]
decl_stmt|;
comment|/* pointer to last TD for isochronous */
name|struct
name|uhci_td
modifier|*
name|sc_isoc_p_last
index|[
name|UHCI_VFRAMELIST_COUNT
index|]
decl_stmt|;
comment|/* pointer to last QH for interrupt */
name|struct
name|uhci_qh
modifier|*
name|sc_intr_p_last
index|[
name|UHCI_IFRAMELIST_COUNT
index|]
decl_stmt|;
comment|/* pointer to last QH for low speed control */
name|struct
name|uhci_qh
modifier|*
name|sc_ls_ctl_p_last
decl_stmt|;
comment|/* pointer to last QH for full speed control */
name|struct
name|uhci_qh
modifier|*
name|sc_fs_ctl_p_last
decl_stmt|;
comment|/* pointer to last QH for bulk */
name|struct
name|uhci_qh
modifier|*
name|sc_bulk_p_last
decl_stmt|;
name|struct
name|uhci_qh
modifier|*
name|sc_reclaim_qh_p
decl_stmt|;
name|struct
name|uhci_qh
modifier|*
name|sc_last_qh_p
decl_stmt|;
name|struct
name|uhci_td
modifier|*
name|sc_last_td_p
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
name|device_t
name|sc_dev
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
name|sc_loops
decl_stmt|;
comment|/* number of QHs that wants looping */
name|uint16_t
name|sc_intr_stat
index|[
name|UHCI_IFRAMELIST_COUNT
index|]
decl_stmt|;
name|uint16_t
name|sc_saved_frnum
decl_stmt|;
name|uint8_t
name|sc_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* device configuration */
name|uint8_t
name|sc_isreset
decl_stmt|;
comment|/* bits set if a root hub is reset */
name|uint8_t
name|sc_isresumed
decl_stmt|;
comment|/* bits set if a port was resumed */
name|uint8_t
name|sc_saved_sof
decl_stmt|;
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
comment|/* vendor string for root hub */
block|}
name|uhci_softc_t
typedef|;
end_typedef

begin_decl_stmt
name|usb_bus_mem_cb_t
name|uhci_iterate_hw_softc
decl_stmt|;
end_decl_stmt

begin_function_decl
name|usb_error_t
name|uhci_init
parameter_list|(
name|uhci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhci_suspend
parameter_list|(
name|uhci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhci_resume
parameter_list|(
name|uhci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhci_reset
parameter_list|(
name|uhci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhci_interrupt
parameter_list|(
name|uhci_softc_t
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
comment|/* _UHCI_H_ */
end_comment

end_unit

