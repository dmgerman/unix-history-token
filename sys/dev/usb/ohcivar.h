begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ohcivar.h,v 1.18 2000/01/18 20:11:00 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ohci_soft_ed
block|{
name|ohci_ed_t
name|ed
decl_stmt|;
name|struct
name|ohci_soft_ed
modifier|*
name|next
decl_stmt|;
name|ohci_physaddr_t
name|physaddr
decl_stmt|;
block|}
name|ohci_soft_ed_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OHCI_SED_SIZE
value|((sizeof (struct ohci_soft_ed) + OHCI_ED_ALIGN - 1) / OHCI_ED_ALIGN * OHCI_ED_ALIGN)
end_define

begin_define
define|#
directive|define
name|OHCI_SED_CHUNK
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|ohci_soft_td
block|{
name|ohci_td_t
name|td
decl_stmt|;
name|struct
name|ohci_soft_td
modifier|*
name|nexttd
decl_stmt|;
comment|/* mirrors nexttd in TD */
name|struct
name|ohci_soft_td
modifier|*
name|dnext
decl_stmt|;
comment|/* next in done list */
name|ohci_physaddr_t
name|physaddr
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ohci_soft_td
argument_list|)
name|hnext
expr_stmt|;
name|usbd_xfer_handle
name|xfer
decl_stmt|;
name|u_int16_t
name|len
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
define|#
directive|define
name|OHCI_CALL_DONE
value|0x0001
define|#
directive|define
name|OHCI_ADD_LEN
value|0x0002
define|#
directive|define
name|OHCI_TD_HANDLED
value|0x0004
comment|/* signal process_done has seen it */
block|}
name|ohci_soft_td_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OHCI_STD_SIZE
value|((sizeof (struct ohci_soft_td) + OHCI_TD_ALIGN - 1) / OHCI_TD_ALIGN * OHCI_TD_ALIGN)
end_define

begin_define
define|#
directive|define
name|OHCI_STD_CHUNK
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|ohci_soft_itd
block|{
name|ohci_itd_t
name|itd
decl_stmt|;
name|struct
name|ohci_soft_itd
modifier|*
name|nextitd
decl_stmt|;
comment|/* mirrors nexttd in ITD */
name|ohci_physaddr_t
name|physaddr
decl_stmt|;
block|}
name|ohci_soft_itd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OHCI_SITD_SIZE
value|((sizeof (struct ohci_soft_itd) + OHCI_ITD_ALIGN - 1) / OHCI_ITD_ALIGN * OHCI_ITD_ALIGN)
end_define

begin_define
define|#
directive|define
name|OHCI_SITD_CHUNK
value|64
end_define

begin_define
define|#
directive|define
name|OHCI_NO_EDS
value|(2*OHCI_NO_INTRS-1)
end_define

begin_define
define|#
directive|define
name|OHCI_HASH_SIZE
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|ohci_softc
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
name|usb_dma_t
name|sc_hccadma
decl_stmt|;
name|struct
name|ohci_hcca
modifier|*
name|sc_hcca
decl_stmt|;
name|ohci_soft_ed_t
modifier|*
name|sc_eds
index|[
name|OHCI_NO_EDS
index|]
decl_stmt|;
name|u_int
name|sc_bws
index|[
name|OHCI_NO_INTRS
index|]
decl_stmt|;
name|u_int32_t
name|sc_eintrs
decl_stmt|;
comment|/* enabled interrupts */
name|ohci_soft_ed_t
modifier|*
name|sc_isoc_head
decl_stmt|;
name|ohci_soft_ed_t
modifier|*
name|sc_ctrl_head
decl_stmt|;
name|ohci_soft_ed_t
modifier|*
name|sc_bulk_head
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ohci_soft_td
argument_list|)
name|sc_hash_tds
index|[
name|OHCI_HASH_SIZE
index|]
expr_stmt|;
name|int
name|sc_noport
decl_stmt|;
name|u_int8_t
name|sc_addr
decl_stmt|;
comment|/* device address */
name|u_int8_t
name|sc_conf
decl_stmt|;
comment|/* device configuration */
name|ohci_soft_ed_t
modifier|*
name|sc_freeeds
decl_stmt|;
name|ohci_soft_td_t
modifier|*
name|sc_freetds
decl_stmt|;
name|ohci_soft_itd_t
modifier|*
name|sc_freeitds
decl_stmt|;
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|usbd_xfer
argument_list|)
name|sc_free_xfers
expr_stmt|;
comment|/* free xfers */
name|usbd_xfer_handle
name|sc_intrxfer
decl_stmt|;
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
name|int
name|sc_id_vendor
decl_stmt|;
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
name|void
modifier|*
name|sc_powerhook
decl_stmt|;
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
block|}
name|ohci_softc_t
typedef|;
end_typedef

begin_decl_stmt
name|usbd_status
name|ohci_init
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ohci_intr
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

begin_decl_stmt
name|int
name|ohci_detach
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ohci_activate
name|__P
argument_list|(
operator|(
name|device_ptr_t
operator|,
expr|enum
name|devact
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MS_TO_TICKS
parameter_list|(
name|ms
parameter_list|)
value|((ms) * hz / 1000)
end_define

end_unit

