begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: uhcivar.h,v 1.28 2000/04/06 23:44:21 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * To avoid having 1024 TDs for each isochronous transfer we introduce  * a virtual frame list.  Every UHCI_VFRAMELIST_COUNT entries in the real  * frame list points to a non-active TD.  These, in turn, form the   * starts of the virtual frame list.  This also has the advantage that it   * simplifies linking in/out of TDs/QHs in the schedule.  * Furthermore, initially each of the inactive TDs point to an inactive  * QH that forms the start of the interrupt traffic for that slot.  * Each of these QHs point to the same QH that is the start of control  * traffic.  This QH points at another QH which is the start of the  * bulk traffic.  *  * UHCI_VFRAMELIST_COUNT should be a power of 2 and<= UHCI_FRAMELIST_COUNT.  */
end_comment

begin_define
define|#
directive|define
name|UHCI_VFRAMELIST_COUNT
value|128
end_define

begin_typedef
typedef|typedef
name|struct
name|uhci_soft_qh
name|uhci_soft_qh_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|uhci_soft_td
name|uhci_soft_td_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|uhci_soft_qh
modifier|*
name|sqh
decl_stmt|;
name|struct
name|uhci_soft_td
modifier|*
name|std
decl_stmt|;
block|}
name|uhci_soft_td_qh_t
typedef|;
end_typedef

begin_comment
comment|/*  * An interrupt info struct contains the information needed to  * execute a requested routine when the controller generates an  * interrupt.  Since we cannot know which transfer generated  * the interrupt all structs are linked together so they can be  * searched at interrupt time.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|uhci_intr_info
block|{
name|struct
name|uhci_softc
modifier|*
name|sc
decl_stmt|;
name|usbd_xfer_handle
name|xfer
decl_stmt|;
name|uhci_soft_td_t
modifier|*
name|stdstart
decl_stmt|;
name|uhci_soft_td_t
modifier|*
name|stdend
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|uhci_intr_info
argument_list|)
name|list
expr_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|int
name|isdone
decl_stmt|;
endif|#
directive|endif
block|}
name|uhci_intr_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|uhci_xfer
block|{
name|struct
name|usbd_xfer
name|xfer
decl_stmt|;
name|uhci_intr_info_t
name|iinfo
decl_stmt|;
name|int
name|curframe
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UXFER
parameter_list|(
name|xfer
parameter_list|)
value|((struct uhci_xfer *)(xfer))
end_define

begin_comment
comment|/*  * Extra information that we need for a TD.  */
end_comment

begin_struct
struct|struct
name|uhci_soft_td
block|{
name|uhci_td_t
name|td
decl_stmt|;
comment|/* The real TD, must be first */
name|uhci_soft_td_qh_t
name|link
decl_stmt|;
comment|/* soft version of the td_link field */
name|uhci_physaddr_t
name|physaddr
decl_stmt|;
comment|/* TD's physical address. */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Make the size such that it is a multiple of UHCI_TD_ALIGN.  This way  * we can pack a number of soft TD together and have the real TD well  * aligned.  * NOTE: Minimum size is 32 bytes.  */
end_comment

begin_define
define|#
directive|define
name|UHCI_STD_SIZE
value|((sizeof (struct uhci_soft_td) + UHCI_TD_ALIGN - 1) / UHCI_TD_ALIGN * UHCI_TD_ALIGN)
end_define

begin_define
define|#
directive|define
name|UHCI_STD_CHUNK
value|128
end_define

begin_comment
comment|/*(PAGE_SIZE / UHCI_TD_SIZE)*/
end_comment

begin_comment
comment|/*  * Extra information that we need for a QH.  */
end_comment

begin_struct
struct|struct
name|uhci_soft_qh
block|{
name|uhci_qh_t
name|qh
decl_stmt|;
comment|/* The real QH, must be first */
name|uhci_soft_qh_t
modifier|*
name|hlink
decl_stmt|;
comment|/* soft version of qh_hlink */
name|uhci_soft_td_t
modifier|*
name|elink
decl_stmt|;
comment|/* soft version of qh_elink */
name|uhci_physaddr_t
name|physaddr
decl_stmt|;
comment|/* QH's physical address. */
name|int
name|pos
decl_stmt|;
comment|/* Timeslot position */
block|}
struct|;
end_struct

begin_comment
comment|/* See comment about UHCI_STD_SIZE. */
end_comment

begin_define
define|#
directive|define
name|UHCI_SQH_SIZE
value|((sizeof (struct uhci_soft_qh) + UHCI_QH_ALIGN - 1) / UHCI_QH_ALIGN * UHCI_QH_ALIGN)
end_define

begin_define
define|#
directive|define
name|UHCI_SQH_CHUNK
value|128
end_define

begin_comment
comment|/*(PAGE_SIZE / UHCI_QH_SIZE)*/
end_comment

begin_comment
comment|/*  * Information about an entry in the virtual frame list.  */
end_comment

begin_struct
struct|struct
name|uhci_vframe
block|{
name|uhci_soft_td_t
modifier|*
name|htd
decl_stmt|;
comment|/* pointer to dummy TD */
name|uhci_soft_td_t
modifier|*
name|etd
decl_stmt|;
comment|/* pointer to last TD */
name|uhci_soft_qh_t
modifier|*
name|hqh
decl_stmt|;
comment|/* pointer to dummy QH */
name|uhci_soft_qh_t
modifier|*
name|eqh
decl_stmt|;
comment|/* pointer to last QH */
name|u_int
name|bandwidth
decl_stmt|;
comment|/* max bandwidth used by this frame */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|uhci_softc
block|{
name|struct
name|usbd_bus
name|sc_bus
decl_stmt|;
comment|/* base device */
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|void
modifier|*
name|ih
decl_stmt|;
name|struct
name|resource
modifier|*
name|io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
endif|#
directive|endif
name|uhci_physaddr_t
modifier|*
name|sc_pframes
decl_stmt|;
name|usb_dma_t
name|sc_dma
decl_stmt|;
name|struct
name|uhci_vframe
name|sc_vframes
index|[
name|UHCI_VFRAMELIST_COUNT
index|]
decl_stmt|;
name|uhci_soft_qh_t
modifier|*
name|sc_lctl_start
decl_stmt|;
comment|/* dummy QH for low speed control */
name|uhci_soft_qh_t
modifier|*
name|sc_lctl_end
decl_stmt|;
comment|/* last control QH */
name|uhci_soft_qh_t
modifier|*
name|sc_hctl_start
decl_stmt|;
comment|/* dummy QH for high speed control */
name|uhci_soft_qh_t
modifier|*
name|sc_hctl_end
decl_stmt|;
comment|/* last control QH */
name|uhci_soft_qh_t
modifier|*
name|sc_bulk_start
decl_stmt|;
comment|/* dummy QH for bulk */
name|uhci_soft_qh_t
modifier|*
name|sc_bulk_end
decl_stmt|;
comment|/* last bulk transfer */
name|uhci_soft_qh_t
modifier|*
name|sc_last_qh
decl_stmt|;
comment|/* dummy QH at the end */
name|u_int32_t
name|sc_loops
decl_stmt|;
comment|/* number of QHs that wants looping */
name|uhci_soft_td_t
modifier|*
name|sc_freetds
decl_stmt|;
comment|/* TD free list */
name|uhci_soft_qh_t
modifier|*
name|sc_freeqhs
decl_stmt|;
comment|/* QH free list */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|usbd_xfer
argument_list|)
name|sc_free_xfers
expr_stmt|;
comment|/* free xfers */
name|u_int8_t
name|sc_addr
decl_stmt|;
comment|/* device address */
name|u_int8_t
name|sc_conf
decl_stmt|;
comment|/* device configuration */
name|u_int8_t
name|sc_saved_sof
decl_stmt|;
name|u_int16_t
name|sc_saved_frnum
decl_stmt|;
name|char
name|sc_isreset
decl_stmt|;
name|char
name|sc_suspend
decl_stmt|;
name|char
name|sc_dying
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uhci_intr_info
argument_list|)
name|sc_intrhead
expr_stmt|;
comment|/* Info for the root hub interrupt channel. */
name|int
name|sc_ival
decl_stmt|;
comment|/* time between root hub intrs */
name|usbd_xfer_handle
name|sc_intr_xfer
decl_stmt|;
comment|/* root hub interrupt transfer */
name|usb_callout_t
name|sc_poll_handle
decl_stmt|;
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
comment|/* vendor string for root hub */
name|int
name|sc_id_vendor
decl_stmt|;
comment|/* vendor ID for root hub */
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|void
modifier|*
name|sc_powerhook
decl_stmt|;
comment|/* cookie from power hook */
name|void
modifier|*
name|sc_shutdownhook
decl_stmt|;
comment|/* cookie from shutdown hook */
endif|#
directive|endif
name|device_ptr_t
name|sc_child
decl_stmt|;
comment|/* /dev/usb# device */
block|}
name|uhci_softc_t
typedef|;
end_typedef

begin_function_decl
name|usbd_status
name|uhci_init
parameter_list|(
name|uhci_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uhci_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_function_decl
name|int
name|uhci_detach
parameter_list|(
name|uhci_softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uhci_activate
parameter_list|(
name|device_ptr_t
parameter_list|,
name|enum
name|devact
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|uhci_shutdown
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhci_power
parameter_list|(
name|int
name|state
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

end_unit

