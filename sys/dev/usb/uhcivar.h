begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: uhcivar.h,v 1.5 1998/12/26 12:53:02 augustss Exp $	*/
end_comment

begin_comment
comment|/*	FreeBSD $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * To avoid having 1024 TDs for each isochronous transfer we introduce  * a virtual frame list.  Every UHCI_VFRAMELIST_COUNT entries in the real  * frame list points to a non-active TD.  These, in turn, which form the   * starts of the virtual frame list.  This also has the advantage that it   * simplifies linking in/out TD/QH in the schedule.  * Furthermore, initially each of the inactive TDs point to an inactive  * QH that forms the start of the interrupt traffic for that slot.  * Each of these QHs point to the same QH that is the start of control  * traffic.  *  * UHCI_VFRAMELIST_COUNT should be a power of 2 and<= UHCI_FRAMELIST_COUNT.  */
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
name|usbd_request_handle
name|reqh
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|callout_handle
name|timeout_handle
decl_stmt|;
endif|#
directive|endif
comment|/* defined(__FreeBSD__) */
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

begin_comment
comment|/*  * Extra information that we need for a TD.  */
end_comment

begin_struct
struct|struct
name|uhci_soft_td
block|{
name|uhci_td_t
modifier|*
name|td
decl_stmt|;
comment|/* The real TD */
name|uhci_physaddr_t
name|physaddr
decl_stmt|;
comment|/* and its physical address. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UHCI_TD_CHUNK
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
modifier|*
name|qh
decl_stmt|;
comment|/* The real QH */
name|uhci_physaddr_t
name|physaddr
decl_stmt|;
comment|/* and its physical address. */
name|int
name|pos
decl_stmt|;
comment|/* Timeslot position */
name|uhci_intr_info_t
modifier|*
name|intr_info
decl_stmt|;
comment|/* Who to call on completion. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UHCI_QH_CHUNK
value|128
end_define

begin_comment
comment|/*(PAGE_SIZE / UHCI_QH_SIZE)*/
end_comment

begin_comment
comment|/* Only used for buffer free list. */
end_comment

begin_struct
struct|struct
name|uhci_buffer
block|{
name|struct
name|uhci_buffer
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UHCI_BUFFER_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|UHCI_BUFFER_CHUNK
value|64
end_define

begin_comment
comment|/*(PAGE_SIZE / UHCI_BUFFER_SIZE)*/
end_comment

begin_comment
comment|/*  * Information about an entry in the virtial frame list.  */
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
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt vectoring */
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmatag
decl_stmt|;
comment|/* DMA tag */
comment|/* XXX should keep track of all DMA memory */
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|int
name|sc_iobase
decl_stmt|;
name|int
name|unit
decl_stmt|;
endif|#
directive|endif
comment|/* defined(__FreeBSD__) */
name|uhci_physaddr_t
modifier|*
name|sc_pframes
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
name|sc_ctl_start
decl_stmt|;
comment|/* dummy QH for control */
name|uhci_soft_qh_t
modifier|*
name|sc_ctl_end
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
name|uhci_soft_td_t
modifier|*
name|sc_freetds
decl_stmt|;
name|uhci_soft_qh_t
modifier|*
name|sc_freeqhs
decl_stmt|;
name|struct
name|uhci_buffer
modifier|*
name|sc_freebuffers
decl_stmt|;
name|u_int8_t
name|sc_addr
decl_stmt|;
comment|/* device address */
name|u_int8_t
name|sc_conf
decl_stmt|;
comment|/* device configuration */
name|char
name|sc_isreset
decl_stmt|;
name|int
name|sc_intrs
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
name|char
name|sc_vflock
decl_stmt|;
define|#
directive|define
name|UHCI_HAS_LOCK
value|1
define|#
directive|define
name|UHCI_WANT_LOCK
value|2
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|usb_dma_t
modifier|*
name|sc_mallocs
decl_stmt|;
endif|#
directive|endif
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
block|}
name|uhci_softc_t
typedef|;
end_typedef

begin_decl_stmt
name|usbd_status
name|uhci_init
name|__P
argument_list|(
operator|(
name|uhci_softc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uhci_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void		uhci_reset __P((void *));
endif|#
directive|endif
end_endif

end_unit

