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
name|_OHCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_OHCI_H_
end_define

begin_define
define|#
directive|define
name|OHCI_MAX_DEVICES
value|MIN(USB_MAX_DEVICES, 128)
end_define

begin_define
define|#
directive|define
name|OHCI_NO_INTRS
value|32
end_define

begin_define
define|#
directive|define
name|OHCI_HCCA_SIZE
value|256
end_define

begin_comment
comment|/* Structures alignment (bytes) */
end_comment

begin_define
define|#
directive|define
name|OHCI_HCCA_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|OHCI_ED_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|OHCI_TD_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|OHCI_ITD_ALIGN
value|32
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE
parameter_list|(
name|x
parameter_list|)
value|((x)&~ 0xfff)
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_define
define|#
directive|define
name|OHCI_PAGE_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|USB_PAGE_SIZE
operator|<
name|OHCI_ED_ALIGN
operator|)
operator|||
operator|(
name|OHCI_ED_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|OHCI_TD_ALIGN
operator|)
operator|||
operator|(
name|OHCI_TD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|OHCI_ITD_ALIGN
operator|)
operator|||
operator|(
name|OHCI_ITD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|OHCI_PAGE_SIZE
operator|)
operator|||
operator|(
name|OHCI_PAGE_SIZE
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

begin_define
define|#
directive|define
name|OHCI_VIRTUAL_FRAMELIST_COUNT
value|128
end_define

begin_comment
comment|/* dummy */
end_comment

begin_if
if|#
directive|if
operator|(
name|OHCI_VIRTUAL_FRAMELIST_COUNT
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
name|ohci_hcca
block|{
specifier|volatile
name|uint32_t
name|hcca_interrupt_table
index|[
name|OHCI_NO_INTRS
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|hcca_frame_number
decl_stmt|;
specifier|volatile
name|uint32_t
name|hcca_done_head
decl_stmt|;
define|#
directive|define
name|OHCI_DONE_INTRS
value|1
block|}
name|__aligned
argument_list|(
name|OHCI_HCCA_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ohci_hcca
name|ohci_hcca_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ohci_ed
block|{
specifier|volatile
name|uint32_t
name|ed_flags
decl_stmt|;
define|#
directive|define
name|OHCI_ED_GET_FA
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x7f)
define|#
directive|define
name|OHCI_ED_ADDRMASK
value|0x0000007f
define|#
directive|define
name|OHCI_ED_SET_FA
parameter_list|(
name|s
parameter_list|)
value|(s)
define|#
directive|define
name|OHCI_ED_GET_EN
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 7)& 0xf)
define|#
directive|define
name|OHCI_ED_SET_EN
parameter_list|(
name|s
parameter_list|)
value|((s)<< 7)
define|#
directive|define
name|OHCI_ED_DIR_MASK
value|0x00001800
define|#
directive|define
name|OHCI_ED_DIR_TD
value|0x00000000
define|#
directive|define
name|OHCI_ED_DIR_OUT
value|0x00000800
define|#
directive|define
name|OHCI_ED_DIR_IN
value|0x00001000
define|#
directive|define
name|OHCI_ED_SPEED
value|0x00002000
define|#
directive|define
name|OHCI_ED_SKIP
value|0x00004000
define|#
directive|define
name|OHCI_ED_FORMAT_GEN
value|0x00000000
define|#
directive|define
name|OHCI_ED_FORMAT_ISO
value|0x00008000
define|#
directive|define
name|OHCI_ED_GET_MAXP
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 16)& 0x07ff)
define|#
directive|define
name|OHCI_ED_SET_MAXP
parameter_list|(
name|s
parameter_list|)
value|((s)<< 16)
define|#
directive|define
name|OHCI_ED_MAXPMASK
value|(0x7ff<< 16)
specifier|volatile
name|uint32_t
name|ed_tailp
decl_stmt|;
specifier|volatile
name|uint32_t
name|ed_headp
decl_stmt|;
define|#
directive|define
name|OHCI_HALTED
value|0x00000001
define|#
directive|define
name|OHCI_TOGGLECARRY
value|0x00000002
define|#
directive|define
name|OHCI_HEADMASK
value|0xfffffffc
specifier|volatile
name|uint32_t
name|ed_next
decl_stmt|;
comment|/*  * Extra information needed:  */
name|struct
name|ohci_ed
modifier|*
name|next
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|prev
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|ed_self
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|OHCI_ED_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ohci_ed
name|ohci_ed_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ohci_td
block|{
specifier|volatile
name|uint32_t
name|td_flags
decl_stmt|;
define|#
directive|define
name|OHCI_TD_R
value|0x00040000
comment|/* Buffer Rounding  */
define|#
directive|define
name|OHCI_TD_DP_MASK
value|0x00180000
comment|/* Direction / PID */
define|#
directive|define
name|OHCI_TD_SETUP
value|0x00000000
define|#
directive|define
name|OHCI_TD_OUT
value|0x00080000
define|#
directive|define
name|OHCI_TD_IN
value|0x00100000
define|#
directive|define
name|OHCI_TD_GET_DI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 7)
comment|/* Delay Interrupt */
define|#
directive|define
name|OHCI_TD_SET_DI
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
define|#
directive|define
name|OHCI_TD_NOINTR
value|0x00e00000
define|#
directive|define
name|OHCI_TD_INTR_MASK
value|0x00e00000
define|#
directive|define
name|OHCI_TD_TOGGLE_CARRY
value|0x00000000
define|#
directive|define
name|OHCI_TD_TOGGLE_0
value|0x02000000
define|#
directive|define
name|OHCI_TD_TOGGLE_1
value|0x03000000
define|#
directive|define
name|OHCI_TD_TOGGLE_MASK
value|0x03000000
define|#
directive|define
name|OHCI_TD_GET_EC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 3)
comment|/* Error Count */
define|#
directive|define
name|OHCI_TD_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
comment|/* Condition Code */
define|#
directive|define
name|OHCI_TD_SET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
define|#
directive|define
name|OHCI_TD_NOCC
value|0xf0000000
specifier|volatile
name|uint32_t
name|td_cbp
decl_stmt|;
comment|/* Current Buffer Pointer */
specifier|volatile
name|uint32_t
name|td_next
decl_stmt|;
comment|/* Next TD */
define|#
directive|define
name|OHCI_TD_NEXT_END
value|0
specifier|volatile
name|uint32_t
name|td_be
decl_stmt|;
comment|/* Buffer End */
comment|/*  * Extra information needed:  */
name|struct
name|ohci_td
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|ohci_td
modifier|*
name|alt_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
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
name|OHCI_TD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ohci_td
name|ohci_td_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ohci_itd
block|{
specifier|volatile
name|uint32_t
name|itd_flags
decl_stmt|;
define|#
directive|define
name|OHCI_ITD_GET_SF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0000ffff)
define|#
directive|define
name|OHCI_ITD_SET_SF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
define|#
directive|define
name|OHCI_ITD_GET_DI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 7)
comment|/* Delay Interrupt */
define|#
directive|define
name|OHCI_ITD_SET_DI
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
define|#
directive|define
name|OHCI_ITD_NOINTR
value|0x00e00000
define|#
directive|define
name|OHCI_ITD_GET_FC
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 24)& 7)+1)
comment|/* Frame Count */
define|#
directive|define
name|OHCI_ITD_SET_FC
parameter_list|(
name|x
parameter_list|)
value|(((x)-1)<< 24)
define|#
directive|define
name|OHCI_ITD_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
comment|/* Condition Code */
define|#
directive|define
name|OHCI_ITD_NOCC
value|0xf0000000
define|#
directive|define
name|OHCI_ITD_NOFFSET
value|8
specifier|volatile
name|uint32_t
name|itd_bp0
decl_stmt|;
comment|/* Buffer Page 0 */
specifier|volatile
name|uint32_t
name|itd_next
decl_stmt|;
comment|/* Next ITD */
specifier|volatile
name|uint32_t
name|itd_be
decl_stmt|;
comment|/* Buffer End */
specifier|volatile
name|uint16_t
name|itd_offset
index|[
name|OHCI_ITD_NOFFSET
index|]
decl_stmt|;
comment|/* Buffer offsets and 							 * Status */
define|#
directive|define
name|OHCI_ITD_PAGE_SELECT
value|0x00001000
define|#
directive|define
name|OHCI_ITD_MK_OFFS
parameter_list|(
name|len
parameter_list|)
value|(0xe000 | ((len)& 0x1fff))
define|#
directive|define
name|OHCI_ITD_PSW_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
comment|/* Transfer length */
define|#
directive|define
name|OHCI_ITD_PSW_GET_CC
parameter_list|(
name|x
parameter_list|)
value|((x)>> 12)
comment|/* Condition Code */
comment|/*  * Extra information needed:  */
name|struct
name|ohci_itd
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|itd_self
decl_stmt|;
name|uint8_t
name|frames
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|OHCI_ITD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ohci_itd
name|ohci_itd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OHCI_CC_NO_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|OHCI_CC_CRC
value|1
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BIT_STUFFING
value|2
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_TOGGLE_MISMATCH
value|3
end_define

begin_define
define|#
directive|define
name|OHCI_CC_STALL
value|4
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DEVICE_NOT_RESPONDING
value|5
end_define

begin_define
define|#
directive|define
name|OHCI_CC_PID_CHECK_FAILURE
value|6
end_define

begin_define
define|#
directive|define
name|OHCI_CC_UNEXPECTED_PID
value|7
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_OVERRUN
value|8
end_define

begin_define
define|#
directive|define
name|OHCI_CC_DATA_UNDERRUN
value|9
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BUFFER_OVERRUN
value|12
end_define

begin_define
define|#
directive|define
name|OHCI_CC_BUFFER_UNDERRUN
value|13
end_define

begin_define
define|#
directive|define
name|OHCI_CC_NOT_ACCESSED
value|15
end_define

begin_comment
comment|/* Some delay needed when changing certain registers. */
end_comment

begin_define
define|#
directive|define
name|OHCI_ENABLE_POWER_DELAY
value|5
end_define

begin_define
define|#
directive|define
name|OHCI_READ_DESC_DELAY
value|5
end_define

begin_define
define|#
directive|define
name|OHCI_NO_EDS
value|(2*OHCI_NO_INTRS)
end_define

begin_struct
struct|struct
name|ohci_hw_softc
block|{
name|struct
name|usb_page_cache
name|hcca_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|ctrl_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|bulk_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|isoc_start_pc
decl_stmt|;
name|struct
name|usb_page_cache
name|intr_start_pc
index|[
name|OHCI_NO_EDS
index|]
decl_stmt|;
name|struct
name|usb_page
name|hcca_pg
decl_stmt|;
name|struct
name|usb_page
name|ctrl_start_pg
decl_stmt|;
name|struct
name|usb_page
name|bulk_start_pg
decl_stmt|;
name|struct
name|usb_page
name|isoc_start_pg
decl_stmt|;
name|struct
name|usb_page
name|intr_start_pg
index|[
name|OHCI_NO_EDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ohci_config_desc
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
name|ohci_hub_desc
block|{
name|struct
name|usb_status
name|stat
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
name|struct
name|usb_hub_descriptor
name|hubd
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

begin_typedef
typedef|typedef
struct|struct
name|ohci_softc
block|{
name|struct
name|ohci_hw_softc
name|sc_hw
decl_stmt|;
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
comment|/* base device */
name|struct
name|usb_callout
name|sc_tmo_rhsc
decl_stmt|;
name|union
name|ohci_hub_desc
name|sc_hub_desc
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|OHCI_MAX_DEVICES
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
name|struct
name|ohci_hcca
modifier|*
name|sc_hcca_p
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|sc_ctrl_p_last
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|sc_bulk_p_last
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|sc_isoc_p_last
decl_stmt|;
name|struct
name|ohci_ed
modifier|*
name|sc_intr_p_last
index|[
name|OHCI_NO_EDS
index|]
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
name|sc_eintrs
decl_stmt|;
comment|/* enabled interrupts */
name|uint32_t
name|sc_control
decl_stmt|;
comment|/* Preserved during suspend/standby */
name|uint32_t
name|sc_intre
decl_stmt|;
name|uint16_t
name|sc_intr_stat
index|[
name|OHCI_NO_EDS
index|]
decl_stmt|;
name|uint16_t
name|sc_id_vendor
decl_stmt|;
name|uint8_t
name|sc_noport
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
name|sc_hub_idata
index|[
literal|32
index|]
decl_stmt|;
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ohci_softc_t
typedef|;
end_typedef

begin_decl_stmt
name|usb_bus_mem_cb_t
name|ohci_iterate_hw_softc
decl_stmt|;
end_decl_stmt

begin_function_decl
name|usb_error_t
name|ohci_init
parameter_list|(
name|ohci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ohci_detach
parameter_list|(
name|struct
name|ohci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ohci_suspend
parameter_list|(
name|ohci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ohci_resume
parameter_list|(
name|ohci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ohci_interrupt
parameter_list|(
name|ohci_softc_t
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
comment|/* _OHCI_H_ */
end_comment

end_unit

