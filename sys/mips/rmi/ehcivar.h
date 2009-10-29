begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ehcivar.h,v 1.19 2005/04/29 15:04:29 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD: src/sys/dev/usb/ehcivar.h,v 1.9.2.1.8.1 2008/10/02 02:57:24 kensmith Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ehci_soft_qtd
block|{
name|ehci_qtd_t
name|qtd
decl_stmt|;
name|struct
name|ehci_soft_qtd
modifier|*
name|nextqtd
decl_stmt|;
comment|/* mirrors nextqtd in TD */
name|ehci_physaddr_t
name|physaddr
decl_stmt|;
name|usbd_xfer_handle
name|xfer
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ehci_soft_qtd
argument_list|)
name|hnext
expr_stmt|;
name|u_int16_t
name|len
decl_stmt|;
block|}
name|ehci_soft_qtd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EHCI_SQTD_SIZE
value|((sizeof (struct ehci_soft_qtd) + EHCI_QTD_ALIGN - 1) / EHCI_QTD_ALIGN * EHCI_QTD_ALIGN)
end_define

begin_define
define|#
directive|define
name|EHCI_SQTD_CHUNK
value|(EHCI_PAGE_SIZE / EHCI_SQTD_SIZE)
end_define

begin_typedef
typedef|typedef
struct|struct
name|ehci_soft_qh
block|{
name|ehci_qh_t
name|qh
decl_stmt|;
name|struct
name|ehci_soft_qh
modifier|*
name|next
decl_stmt|;
name|struct
name|ehci_soft_qh
modifier|*
name|prev
decl_stmt|;
name|struct
name|ehci_soft_qtd
modifier|*
name|sqtd
decl_stmt|;
name|ehci_physaddr_t
name|physaddr
decl_stmt|;
name|int
name|islot
decl_stmt|;
comment|/* Interrupt list slot. */
block|}
name|ehci_soft_qh_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EHCI_SQH_SIZE
value|((sizeof (struct ehci_soft_qh) + EHCI_QH_ALIGN - 1) / EHCI_QH_ALIGN * EHCI_QH_ALIGN)
end_define

begin_define
define|#
directive|define
name|EHCI_SQH_CHUNK
value|(EHCI_PAGE_SIZE / EHCI_SQH_SIZE)
end_define

begin_struct
struct|struct
name|ehci_xfer
block|{
name|struct
name|usbd_xfer
name|xfer
decl_stmt|;
name|struct
name|usb_task
name|abort_task
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ehci_xfer
argument_list|)
name|inext
expr_stmt|;
comment|/* list of active xfers */
name|ehci_soft_qtd_t
modifier|*
name|sqtdstart
decl_stmt|;
name|ehci_soft_qtd_t
modifier|*
name|sqtdend
decl_stmt|;
name|u_int32_t
name|ehci_xfer_flags
decl_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|int
name|isdone
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EHCI_XFER_ABORTING
value|0x0001
end_define

begin_comment
comment|/* xfer is aborting. */
end_comment

begin_define
define|#
directive|define
name|EHCI_XFER_ABORTWAIT
value|0x0002
end_define

begin_comment
comment|/* abort completion is being awaited. */
end_comment

begin_define
define|#
directive|define
name|EXFER
parameter_list|(
name|xfer
parameter_list|)
value|((struct ehci_xfer *)(xfer))
end_define

begin_comment
comment|/*  * Information about an entry in the interrupt list.  */
end_comment

begin_struct
struct|struct
name|ehci_soft_islot
block|{
name|ehci_soft_qh_t
modifier|*
name|sqh
decl_stmt|;
comment|/* Queue Head. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EHCI_FRAMELIST_MAXCOUNT
value|1024
end_define

begin_define
define|#
directive|define
name|EHCI_IPOLLRATES
value|8
end_define

begin_comment
comment|/* Poll rates (1ms, 2, 4, 8 ... 128) */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTRQHS
value|((1<< EHCI_IPOLLRATES) - 1)
end_define

begin_define
define|#
directive|define
name|EHCI_MAX_POLLRATE
value|(1<< (EHCI_IPOLLRATES - 1))
end_define

begin_define
define|#
directive|define
name|EHCI_IQHIDX
parameter_list|(
name|lev
parameter_list|,
name|pos
parameter_list|)
define|\
value|((((pos)& ((1<< (lev)) - 1)) | (1<< (lev))) - 1)
end_define

begin_define
define|#
directive|define
name|EHCI_ILEV_IVAL
parameter_list|(
name|lev
parameter_list|)
value|(1<< (lev))
end_define

begin_define
define|#
directive|define
name|EHCI_HASH_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|EHCI_COMPANION_MAX
value|8
end_define

begin_define
define|#
directive|define
name|EHCI_SCFLG_DONEINIT
value|0x0001
end_define

begin_comment
comment|/* ehci_init() has been called. */
end_comment

begin_define
define|#
directive|define
name|EHCI_SCFLG_LOSTINTRBUG
value|0x0002
end_define

begin_comment
comment|/* workaround for VIA / ATI chipsets */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ehci_softc
block|{
name|struct
name|usbd_bus
name|sc_bus
decl_stmt|;
comment|/* base device */
name|int
name|sc_flags
decl_stmt|;
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
name|bus_size_t
name|sc_size
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
name|u_int
name|sc_offs
decl_stmt|;
comment|/* offset to operational regs */
name|char
name|sc_vendor
index|[
literal|32
index|]
decl_stmt|;
comment|/* vendor string for root hub */
name|int
name|sc_id_vendor
decl_stmt|;
comment|/* vendor ID for root hub */
name|u_int32_t
name|sc_cmd
decl_stmt|;
comment|/* shadow of cmd reg during suspend */
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
comment|/* cookie from power hook */
name|void
modifier|*
name|sc_shutdownhook
decl_stmt|;
comment|/* cookie from shutdown hook */
endif|#
directive|endif
name|u_int
name|sc_ncomp
decl_stmt|;
name|u_int
name|sc_npcomp
decl_stmt|;
name|struct
name|usbd_bus
modifier|*
name|sc_comps
index|[
name|EHCI_COMPANION_MAX
index|]
decl_stmt|;
name|usb_dma_t
name|sc_fldma
decl_stmt|;
name|ehci_link_t
modifier|*
name|sc_flist
decl_stmt|;
name|u_int
name|sc_flsize
decl_stmt|;
ifndef|#
directive|ifndef
name|__FreeBSD__
name|u_int
name|sc_rand
decl_stmt|;
comment|/* XXX need proper intr scheduling */
endif|#
directive|endif
name|struct
name|ehci_soft_islot
name|sc_islots
index|[
name|EHCI_INTRQHS
index|]
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ehci_xfer
argument_list|)
name|sc_intrhead
expr_stmt|;
name|ehci_soft_qh_t
modifier|*
name|sc_freeqhs
decl_stmt|;
name|ehci_soft_qtd_t
modifier|*
name|sc_freeqtds
decl_stmt|;
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
name|usbd_xfer_handle
name|sc_intrxfer
decl_stmt|;
name|char
name|sc_isreset
decl_stmt|;
ifdef|#
directive|ifdef
name|USB_USE_SOFTINTR
name|char
name|sc_softwake
decl_stmt|;
endif|#
directive|endif
comment|/* USB_USE_SOFTINTR */
name|u_int32_t
name|sc_eintrs
decl_stmt|;
name|ehci_soft_qh_t
modifier|*
name|sc_async_head
decl_stmt|;
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|usbd_xfer
argument_list|)
name|sc_free_xfers
expr_stmt|;
comment|/* free xfers */
name|struct
name|lock
name|sc_doorbell_lock
decl_stmt|;
name|usb_callout_t
name|sc_tmo_pcd
decl_stmt|;
name|usb_callout_t
name|sc_tmo_intrlist
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
name|device_ptr_t
name|sc_child
decl_stmt|;
comment|/* /dev/usb# device */
endif|#
directive|endif
name|char
name|sc_dying
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|struct
name|usb_dma_reserve
name|sc_dma_reserve
decl_stmt|;
endif|#
directive|endif
block|}
name|ehci_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EREAD1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_1((sc)->iot, (sc)->ioh, (a))
end_define

begin_define
define|#
directive|define
name|EREAD2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_2((sc)->iot, (sc)->ioh, (a))
end_define

begin_define
define|#
directive|define
name|EREAD4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_4((sc)->iot, (sc)->ioh, (a))
end_define

begin_define
define|#
directive|define
name|EWRITE1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_1((sc)->iot, (sc)->ioh, (a), (x))
end_define

begin_define
define|#
directive|define
name|EWRITE2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_2((sc)->iot, (sc)->ioh, (a), (x))
end_define

begin_define
define|#
directive|define
name|EWRITE4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_4((sc)->iot, (sc)->ioh, (a), (x))
end_define

begin_define
define|#
directive|define
name|EOREAD1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_1((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOREAD2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_2((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOREAD4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_4((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOWRITE1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_1((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a), (x))
end_define

begin_define
define|#
directive|define
name|EOWRITE2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_2((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a), (x))
end_define

begin_define
define|#
directive|define
name|EOWRITE4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_4((sc)->iot, (sc)->ioh, (sc)->sc_offs+(a), (x))
end_define

begin_function_decl
name|usbd_status
name|ehci_init
parameter_list|(
name|ehci_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ehci_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ehci_detach
parameter_list|(
name|ehci_softc_t
modifier|*
parameter_list|,
name|int
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
name|ehci_activate
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
name|ehci_power
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

begin_function_decl
name|void
name|ehci_shutdown
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

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

