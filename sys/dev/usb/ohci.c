begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ohci.c,v 1.43 1999/09/11 08:19:26 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * USB Open Host Controller driver.  *  * OHCI spec: ftp://ftp.compaq.com/pub/supportinformation/papers/hcir1_0a.exe  * USB spec: http://www.usb.org/developers/data/usb11.pdf  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

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

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_mem.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_quirks.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/ohcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/ohcivar.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_define
define|#
directive|define
name|delay
parameter_list|(
name|d
parameter_list|)
value|DELAY(d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OHCI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
value|if (ohcidebug) logprintf x
end_define

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|if (ohcidebug>(n)) logprintf x
end_define

begin_decl_stmt
name|int
name|ohcidebug
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cfdriver
name|ohci_cd
init|=
block|{
name|NULL
block|,
literal|"ohci"
block|,
name|DV_DULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The OHCI controller is little endian, so on big endian machines  * the data strored in memory needs to be swapped.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|LE
parameter_list|(
name|x
parameter_list|)
value|(bswap32(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LE
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ohci_pipe
struct_decl|;
end_struct_decl

begin_decl_stmt
name|ohci_soft_ed_t
modifier|*
name|ohci_alloc_sed
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
name|void
name|ohci_free_sed
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_soft_ed_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ohci_soft_td_t
modifier|*
name|ohci_alloc_std
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
name|void
name|ohci_free_std
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_soft_td_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_power
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_open
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_poll
name|__P
argument_list|(
operator|(
expr|struct
name|usbd_bus
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_waitintr
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_rhsc
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_process_done
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_physaddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_request
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_add_ed
name|__P
argument_list|(
operator|(
name|ohci_soft_ed_t
operator|*
operator|,
name|ohci_soft_ed_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_rem_ed
name|__P
argument_list|(
operator|(
name|ohci_soft_ed_t
operator|*
operator|,
name|ohci_soft_ed_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_hash_add_td
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_soft_td_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_hash_rem_td
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_soft_td_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ohci_soft_td_t
modifier|*
name|ohci_hash_find_td
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
operator|,
name|ohci_physaddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_allocm
name|__P
argument_list|(
operator|(
expr|struct
name|usbd_bus
operator|*
operator|,
name|usb_dma_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_freem
name|__P
argument_list|(
operator|(
expr|struct
name|usbd_bus
operator|*
operator|,
name|usb_dma_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_root_ctrl_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_root_ctrl_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_root_ctrl_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_root_ctrl_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_root_intr_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_root_intr_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_root_intr_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_root_intr_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_root_intr_done
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_ctrl_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_ctrl_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_ctrl_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_ctrl_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_ctrl_done
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_bulk_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_bulk_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_bulk_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_bulk_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_bulk_done
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_intr_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_intr_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_intr_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_intr_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_intr_done
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_isoc_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_isoc_start
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_isoc_abort
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_isoc_close
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_isoc_done
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|ohci_device_setintr
name|__P
argument_list|(
operator|(
name|ohci_softc_t
operator|*
name|sc
operator|,
expr|struct
name|ohci_pipe
operator|*
name|pipe
operator|,
name|int
name|ival
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ohci_str
name|__P
argument_list|(
operator|(
name|usb_string_descriptor_t
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_timeout
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_rhsc_able
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
name|void
name|ohci_close_pipe
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|,
name|ohci_soft_ed_t
operator|*
name|head
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_abort_req
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|,
name|usbd_status
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_abort_req_end
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_device_clear_toggle
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_noop
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OHCI_DEBUG
end_ifdef

begin_decl_stmt
name|ohci_softc_t
modifier|*
name|thesc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_dumpregs
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
name|void
name|ohci_dump_tds
name|__P
argument_list|(
operator|(
name|ohci_soft_td_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_dump_td
name|__P
argument_list|(
operator|(
name|ohci_soft_td_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ohci_dump_ed
name|__P
argument_list|(
operator|(
name|ohci_soft_ed_t
operator|*
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
name|OWRITE4
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|,
name|x
parameter_list|)
value|bus_space_write_4((sc)->iot, (sc)->ioh, (r), (x))
end_define

begin_define
define|#
directive|define
name|OREAD4
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|)
value|bus_space_read_4((sc)->iot, (sc)->ioh, (r))
end_define

begin_define
define|#
directive|define
name|OREAD2
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|)
value|bus_space_read_2((sc)->iot, (sc)->ioh, (r))
end_define

begin_comment
comment|/* Reverse the bits in a value 0 .. 31 */
end_comment

begin_decl_stmt
specifier|static
name|u_int8_t
name|revbits
index|[
name|OHCI_NO_INTRS
index|]
init|=
block|{
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x18
block|,
literal|0x04
block|,
literal|0x14
block|,
literal|0x0c
block|,
literal|0x1c
block|,
literal|0x02
block|,
literal|0x12
block|,
literal|0x0a
block|,
literal|0x1a
block|,
literal|0x06
block|,
literal|0x16
block|,
literal|0x0e
block|,
literal|0x1e
block|,
literal|0x01
block|,
literal|0x11
block|,
literal|0x09
block|,
literal|0x19
block|,
literal|0x05
block|,
literal|0x15
block|,
literal|0x0d
block|,
literal|0x1d
block|,
literal|0x03
block|,
literal|0x13
block|,
literal|0x0b
block|,
literal|0x1b
block|,
literal|0x07
block|,
literal|0x17
block|,
literal|0x0f
block|,
literal|0x1f
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ohci_pipe
block|{
name|struct
name|usbd_pipe
name|pipe
decl_stmt|;
name|ohci_soft_ed_t
modifier|*
name|sed
decl_stmt|;
name|ohci_soft_td_t
modifier|*
name|tail
decl_stmt|;
comment|/* Info needed for different pipe kinds. */
union|union
block|{
comment|/* Control pipe */
struct|struct
block|{
name|usb_dma_t
name|reqdma
decl_stmt|;
name|u_int
name|length
decl_stmt|;
name|ohci_soft_td_t
modifier|*
name|setup
decl_stmt|,
modifier|*
name|xfer
decl_stmt|,
modifier|*
name|stat
decl_stmt|;
block|}
name|ctl
struct|;
comment|/* Interrupt pipe */
struct|struct
block|{
name|int
name|nslots
decl_stmt|;
name|int
name|pos
decl_stmt|;
block|}
name|intr
struct|;
comment|/* Bulk pipe */
struct|struct
block|{
name|u_int
name|length
decl_stmt|;
name|int
name|isread
decl_stmt|;
block|}
name|bulk
struct|;
comment|/* Iso pipe */
struct|struct
name|iso
block|{
name|int
name|xxxxx
decl_stmt|;
block|}
name|iso
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OHCI_INTR_ENDPT
value|1
end_define

begin_decl_stmt
name|struct
name|usbd_bus_methods
name|ohci_bus_methods
init|=
block|{
name|ohci_open
block|,
name|ohci_poll
block|,
name|ohci_allocm
block|,
name|ohci_freem
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_pipe_methods
name|ohci_root_ctrl_methods
init|=
block|{
name|ohci_root_ctrl_transfer
block|,
name|ohci_root_ctrl_start
block|,
name|ohci_root_ctrl_abort
block|,
name|ohci_root_ctrl_close
block|,
name|ohci_noop
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_pipe_methods
name|ohci_root_intr_methods
init|=
block|{
name|ohci_root_intr_transfer
block|,
name|ohci_root_intr_start
block|,
name|ohci_root_intr_abort
block|,
name|ohci_root_intr_close
block|,
name|ohci_noop
block|,
name|ohci_root_intr_done
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_pipe_methods
name|ohci_device_ctrl_methods
init|=
block|{
name|ohci_device_ctrl_transfer
block|,
name|ohci_device_ctrl_start
block|,
name|ohci_device_ctrl_abort
block|,
name|ohci_device_ctrl_close
block|,
name|ohci_noop
block|,
name|ohci_device_ctrl_done
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_pipe_methods
name|ohci_device_intr_methods
init|=
block|{
name|ohci_device_intr_transfer
block|,
name|ohci_device_intr_start
block|,
name|ohci_device_intr_abort
block|,
name|ohci_device_intr_close
block|,
name|ohci_device_clear_toggle
block|,
name|ohci_device_intr_done
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_pipe_methods
name|ohci_device_bulk_methods
init|=
block|{
name|ohci_device_bulk_transfer
block|,
name|ohci_device_bulk_start
block|,
name|ohci_device_bulk_abort
block|,
name|ohci_device_bulk_close
block|,
name|ohci_device_clear_toggle
block|,
name|ohci_device_bulk_done
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|struct usbd_pipe_methods ohci_device_isoc_methods = { 	ohci_device_isoc_transfer, 	ohci_device_isoc_start, 	ohci_device_isoc_abort, 	ohci_device_isoc_close, 	ohci_noop, 	ohci_device_isoc_done, };
endif|#
directive|endif
end_endif

begin_function
name|ohci_soft_ed_t
modifier|*
name|ohci_alloc_sed
parameter_list|(
name|sc
parameter_list|)
name|ohci_softc_t
modifier|*
name|sc
decl_stmt|;
block|{
name|ohci_soft_ed_t
modifier|*
name|sed
decl_stmt|;
name|usbd_status
name|r
decl_stmt|;
name|int
name|i
decl_stmt|,
name|offs
decl_stmt|;
name|usb_dma_t
name|dma
decl_stmt|;
if|if
condition|(
operator|!
name|sc
operator|->
name|sc_freeeds
condition|)
block|{
name|DPRINTFN
argument_list|(
literal|2
argument_list|,
operator|(
literal|"ohci_alloc_sed: allocating chunk\n"
operator|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|usb_allocmem
argument_list|(
name|sc
operator|->
name|sc_dmatag
argument_list|,
name|OHCI_SED_SIZE
operator|*
name|OHCI_SED_CHUNK
argument_list|,
name|OHCI_ED_ALIGN
argument_list|,
operator|&
name|dma
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|USBD_NORMAL_COMPLETION
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|OHCI_SED_CHUNK
condition|;
name|i
operator|++
control|)
block|{
name|offs
operator|=
name|i
operator|*
name|OHCI_SED_SIZE
expr_stmt|;
name|sed
operator|=
operator|(
name|ohci_soft_ed_t
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|KERNADDR
argument_list|(
operator|&
name|dma
argument_list|)
operator|+
name|offs
operator|)
expr_stmt|;
name|sed
operator|->
name|physaddr
operator|=
name|DMAADDR
argument_list|(
operator|&
name|dma
argument_list|)
operator|+
name|offs
expr_stmt|;
name|sed
operator|->
name|next
operator|=
name|sc
operator|->
name|sc_freeeds
expr_stmt|;
name|sc
operator|->
name|sc_freeeds
operator|=
name|sed
expr_stmt|;
block|}
block|}
name|sed
operator|=
name|sc
operator|->
name|sc_freeeds
expr_stmt|;
name|sc
operator|->
name|sc_freeeds
operator|=
name|sed
operator|->
name|next
expr_stmt|;
name|memset
argument_list|(
operator|&
name|sed
operator|->
name|ed
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ohci_ed_t
argument_list|)
argument_list|)
expr_stmt|;
name|sed
operator|->
name|next
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|sed
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ohci_free_sed
parameter_list|(
name|sc
parameter_list|,
name|sed
parameter_list|)
name|ohci_softc_t
modifier|*
name|sc
decl_stmt|;
name|ohci_soft_ed_t
modifier|*
name|sed
decl_stmt|;
block|{
name|sed
operator|->
name|next
operator|=
name|sc
operator|->
name|sc_freeeds
expr_stmt|;
name|sc
operator|->
name|sc_freeeds
operator|=
name|sed
expr_stmt|;
block|}
end_function

begin_function
name|ohci_soft_td_t
modifier|*
name|ohci_alloc_std
parameter_list|(
name|sc
parameter_list|)
name|ohci_softc_t
modifier|*
name|sc
decl_stmt|;
block|{
name|ohci_soft_td_t
modifier|*
name|std
decl_stmt|;
name|usbd_status
name|r
decl_stmt|;
name|int
name|i
decl_stmt|,
name|offs
decl_stmt|;
name|usb_dma_t
name|dma
decl_stmt|;
if|if
condition|(
operator|!
name|sc
operator|->
name|sc_freetds
condition|)
block|{
name|DPRINTFN
argument_list|(
literal|2
argument_list|,
operator|(
literal|"ohci_alloc_std: allocating chunk\n"
operator|)
argument_list|)
expr_stmt|;
name|r
operator|=
name|usb_allocmem
argument_list|(
name|sc
operator|->
name|sc_dmatag
argument_list|,
name|OHCI_STD_SIZE
operator|*
name|OHCI_STD_CHUNK
argument_list|,
name|OHCI_TD_ALIGN
argument_list|,
operator|&
name|dma
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|USBD_NORMAL_COMPLETION
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|OHCI_STD_CHUNK
condition|;
name|i
operator|++
control|)
block|{
name|offs
operator|=
name|i
operator|*
name|OHCI_STD_SIZE
expr_stmt|;
name|std
operator|=
operator|(
name|ohci_soft_td_t
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|KERNADDR
argument_list|(
operator|&
name|dma
argument_list|)
operator|+
name|offs
operator|)
expr_stmt|;
name|std
operator|->
name|physaddr
operator|=
name|DMAADDR
argument_list|(
operator|&
name|dma
argument_list|)
operator|+
name|offs
expr_stmt|;
name|std
operator|->
name|nexttd
operator|=
name|sc
operator|->
name|sc_freetds
expr_stmt|;
name|sc
operator|->
name|sc_freetds
operator|=
name|std
expr_stmt|;
block|}
block|}
name|std
operator|=
name|sc
operator|->
name|sc_freetds
expr_stmt|;
name|sc
operator|->
name|sc_freetds
operator|=
name|std
operator|->
name|nexttd
expr_stmt|;
name|memset
argument_list|(
operator|&
name|std
operator|->
name|td
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|ohci_td_t
argument_list|)
argument_list|)
expr_stmt|;
name|std
operator|->
name|nexttd
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|std
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ohci_free_std
parameter_list|(
name|sc
parameter_list|,
name|std
parameter_list|)
name|ohci_softc_t
modifier|*
name|sc
decl_stmt|;
name|ohci_soft_td_t
modifier|*
name|std
decl_stmt|;
block|{
name|std
operator|->
name|nexttd
operator|=
name|sc
operator|->
name|sc_freetds
expr_stmt|;
name|sc
operator|->
name|sc_freetds
operator|=
name|std
expr_stmt|;
block|}
end_function

begin_function
name|usbd_status
name|ohci_init
parameter_list|(
name|sc
parameter_list|)
name|ohci_softc_t
modifier|*
name|sc
decl_stmt|;
block|{
name|ohci_soft_ed_t
modifier|*
name|sed
decl_stmt|,
modifier|*
name|psed
decl_stmt|;
name|usbd_status
name|r
decl_stmt|;
name|int
name|rev
decl_stmt|;
name|int
name|i
decl_stmt|;
name|u_int32_t
name|s
decl_stmt|,
name|ctl
decl_stmt|,
name|ival
decl_stmt|,
name|hcr
decl_stmt|,
name|fm
decl_stmt|,
name|per
decl_stmt|;
name|DPRINTF
argument_list|(
operator|(
literal|"ohci_init: start\n"
operator|)
argument_list|)
expr_stmt|;
name|rev
operator|=
name|OREAD4
argument_list|(
name|sc
argument_list|,
name|OHCI_REVISION
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|printf
argument_list|(
literal|", OHCI version %d.%d%s\n"
argument_list|,
else|#
directive|else
argument|printf(
literal|"%s: OHCI version %d.%d%s\n"
argument|, USBDEVNAME(sc->sc_bus.bdev),
endif|#
directive|endif
argument|OHCI_REV_HI(rev), OHCI_REV_LO(rev), 	       OHCI_REV_LEGACY(rev) ?
literal|", legacy support"
argument|:
literal|""
argument|); 	if (OHCI_REV_HI(rev) !=
literal|1
argument||| OHCI_REV_LO(rev) !=
literal|0
argument|) { 		printf(
literal|"%s: unsupported OHCI revision\n"
argument|,  		       USBDEVNAME(sc->sc_bus.bdev)); 		return (USBD_INVAL); 	}  	for (i =
literal|0
argument|; i< OHCI_HASH_SIZE; i++) 		LIST_INIT(&sc->sc_hash_tds[i]);
comment|/* Allocate the HCCA area. */
argument|r = usb_allocmem(sc->sc_dmatag, OHCI_HCCA_SIZE,  			 OHCI_HCCA_ALIGN,&sc->sc_hccadma); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	sc->sc_hcca = (struct ohci_hcca *)KERNADDR(&sc->sc_hccadma); 	memset(sc->sc_hcca,
literal|0
argument|, OHCI_HCCA_SIZE);  	sc->sc_eintrs = OHCI_NORMAL_INTRS;  	sc->sc_ctrl_head = ohci_alloc_sed(sc); 	if (!sc->sc_ctrl_head) { 		r = USBD_NOMEM; 		goto bad1; 	} 	sc->sc_ctrl_head->ed.ed_flags |= LE(OHCI_ED_SKIP);  	sc->sc_bulk_head = ohci_alloc_sed(sc); 	if (!sc->sc_bulk_head) { 		r = USBD_NOMEM; 		goto bad2; 	} 	sc->sc_bulk_head->ed.ed_flags |= LE(OHCI_ED_SKIP);
comment|/* Allocate all the dummy EDs that make up the interrupt tree. */
argument|for (i =
literal|0
argument|; i< OHCI_NO_EDS; i++) { 		sed = ohci_alloc_sed(sc); 		if (!sed) { 			while (--i>=
literal|0
argument|) 				ohci_free_sed(sc, sc->sc_eds[i]); 			r = USBD_NOMEM; 			goto bad3; 		}
comment|/* All ED fields are set to 0. */
argument|sc->sc_eds[i] = sed; 		sed->ed.ed_flags |= LE(OHCI_ED_SKIP); 		if (i !=
literal|0
argument|) { 			psed = sc->sc_eds[(i-
literal|1
argument|) /
literal|2
argument|]; 			sed->next = psed; 			sed->ed.ed_nexted = LE(psed->physaddr); 		} 	}
comment|/*  	 * Fill HCCA interrupt table.  The bit reversal is to get 	 * the tree set up properly to spread the interrupts. 	 */
argument|for (i =
literal|0
argument|; i< OHCI_NO_INTRS; i++) 		sc->sc_hcca->hcca_interrupt_table[revbits[i]] =  			LE(sc->sc_eds[OHCI_NO_EDS-OHCI_NO_INTRS+i]->physaddr);
comment|/* Determine in what context we are running. */
argument|ctl = OREAD4(sc, OHCI_CONTROL); 	if (ctl& OHCI_IR) {
comment|/* SMM active, request change */
argument|DPRINTF((
literal|"ohci_init: SMM active, request owner change\n"
argument|)); 		s = OREAD4(sc, OHCI_COMMAND_STATUS); 		OWRITE4(sc, OHCI_COMMAND_STATUS, s | OHCI_OCR); 		for (i =
literal|0
argument|; i<
literal|100
argument|&& (ctl& OHCI_IR); i++) { 			delay(
literal|1000
argument|); 			ctl = OREAD4(sc, OHCI_CONTROL); 		} 		if ((ctl& OHCI_IR) ==
literal|0
argument|) { 			printf(
literal|"%s: SMM does not respond, resetting\n"
argument|, 			       USBDEVNAME(sc->sc_bus.bdev)); 			OWRITE4(sc, OHCI_CONTROL, OHCI_HCFS_RESET); 			goto reset; 		} 	} else if ((ctl& OHCI_HCFS_MASK) != OHCI_HCFS_RESET) {
comment|/* BIOS started controller. */
argument|DPRINTF((
literal|"ohci_init: BIOS active\n"
argument|)); 		if ((ctl& OHCI_HCFS_MASK) != OHCI_HCFS_OPERATIONAL) { 			OWRITE4(sc, OHCI_CONTROL, OHCI_HCFS_OPERATIONAL); 			delay(USB_RESUME_DELAY *
literal|1000
argument|); 		} 	} else { 		DPRINTF((
literal|"ohci_init: cold started\n"
argument|)); 	reset:
comment|/* Controller was cold started. */
argument|delay(USB_BUS_RESET_DELAY *
literal|1000
argument|); 	}
comment|/* 	 * This reset should not be necessary according to the OHCI spec, but 	 * without it some controllers do not start. 	 */
argument|DPRINTF((
literal|"%s: resetting\n"
argument|, USBDEVNAME(sc->sc_bus.bdev))); 	OWRITE4(sc, OHCI_CONTROL, OHCI_HCFS_RESET); 	delay(USB_BUS_RESET_DELAY *
literal|1000
argument|);
comment|/* We now own the host controller and the bus has been reset. */
argument|ival = OHCI_GET_IVAL(OREAD4(sc, OHCI_FM_INTERVAL));  	OWRITE4(sc, OHCI_COMMAND_STATUS, OHCI_HCR);
comment|/* Reset HC */
comment|/* Nominal time for a reset is 10 us. */
argument|for (i =
literal|0
argument|; i<
literal|10
argument|; i++) { 		delay(
literal|10
argument|); 		hcr = OREAD4(sc, OHCI_COMMAND_STATUS)& OHCI_HCR; 		if (!hcr) 			break; 	} 	if (hcr) { 		printf(
literal|"%s: reset timeout\n"
argument|, USBDEVNAME(sc->sc_bus.bdev)); 		r = USBD_IOERROR; 		goto bad3; 	}
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|thesc = sc; 	if (ohcidebug>
literal|15
argument|) 		ohci_dumpregs(sc);
endif|#
directive|endif
comment|/* The controller is now in suspend state, we have 2ms to finish. */
comment|/* Set up HC registers. */
argument|OWRITE4(sc, OHCI_HCCA, DMAADDR(&sc->sc_hccadma)); 	OWRITE4(sc, OHCI_CONTROL_HEAD_ED, sc->sc_ctrl_head->physaddr); 	OWRITE4(sc, OHCI_BULK_HEAD_ED, sc->sc_bulk_head->physaddr); 	OWRITE4(sc, OHCI_INTERRUPT_DISABLE, OHCI_ALL_INTRS); 	OWRITE4(sc, OHCI_INTERRUPT_ENABLE, sc->sc_eintrs | OHCI_MIE); 	ctl = OREAD4(sc, OHCI_CONTROL); 	ctl&= ~(OHCI_CBSR_MASK | OHCI_LES | OHCI_HCFS_MASK | OHCI_IR); 	ctl |= OHCI_PLE | OHCI_IE | OHCI_CLE | OHCI_BLE | 		OHCI_RATIO_1_4 | OHCI_HCFS_OPERATIONAL;
comment|/* And finally start it! */
argument|OWRITE4(sc, OHCI_CONTROL, ctl);
comment|/* 	 * The controller is now OPERATIONAL.  Set a some final 	 * registers that should be set earlier, but that the 	 * controller ignores when in the SUSPEND state. 	 */
argument|fm = (OREAD4(sc, OHCI_FM_INTERVAL)& OHCI_FIT) ^ OHCI_FIT; 	fm |= OHCI_FSMPS(ival) | ival; 	OWRITE4(sc, OHCI_FM_INTERVAL, fm); 	per = OHCI_PERIODIC(ival);
comment|/* 90% periodic */
argument|OWRITE4(sc, OHCI_PERIODIC_START, per);  	OWRITE4(sc, OHCI_RH_STATUS, OHCI_LPSC);
comment|/* Enable port power */
argument|sc->sc_noport = OHCI_GET_NDP(OREAD4(sc, OHCI_RH_DESCRIPTOR_A));
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|5
argument|) 		ohci_dumpregs(sc);
endif|#
directive|endif
comment|/* Set up the bus struct. */
argument|sc->sc_bus.methods =&ohci_bus_methods; 	sc->sc_bus.pipe_size = sizeof(struct ohci_pipe);
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
argument|powerhook_establish(ohci_power, sc);
endif|#
directive|endif
argument|return (USBD_NORMAL_COMPLETION);   bad3: 	ohci_free_sed(sc, sc->sc_ctrl_head);  bad2: 	ohci_free_sed(sc, sc->sc_bulk_head);  bad1: 	usb_freemem(sc->sc_dmatag,&sc->sc_hccadma); 	return (r); }  usbd_status ohci_allocm(bus, dma, size) 	struct usbd_bus *bus; 	usb_dma_t *dma; 	u_int32_t size; {
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
argument|struct ohci_softc *sc = (struct ohci_softc *)bus;
endif|#
directive|endif
argument|return (usb_allocmem(sc->sc_dmatag, size,
literal|0
argument|, dma)); }  void ohci_freem(bus, dma) 	struct usbd_bus *bus; 	usb_dma_t *dma; {
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
argument|struct ohci_softc *sc = (struct ohci_softc *)bus;
endif|#
directive|endif
argument|usb_freemem(sc->sc_dmatag, dma); }
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
argument|void ohci_power(why, v) 	int why; 	void *v; {
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|ohci_softc_t *sc = v;  	DPRINTF((
literal|"ohci_power: sc=%p, why=%d\n"
argument|, sc, why));
comment|/* XXX should suspend/resume */
argument|ohci_dumpregs(sc);
endif|#
directive|endif
argument|}
endif|#
directive|endif
comment|/* !defined(__OpenBSD__) */
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|void ohcidump(void); void ohcidump(void) { ohci_dumpregs(thesc); }  void ohci_dumpregs(sc) 	ohci_softc_t *sc; { 	DPRINTF((
literal|"ohci_dumpregs: rev=0x%08x control=0x%08x command=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_REVISION), 		 OREAD4(sc, OHCI_CONTROL), 		 OREAD4(sc, OHCI_COMMAND_STATUS))); 	DPRINTF((
literal|"               intrstat=0x%08x intre=0x%08x intrd=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_INTERRUPT_STATUS), 		 OREAD4(sc, OHCI_INTERRUPT_ENABLE), 		 OREAD4(sc, OHCI_INTERRUPT_DISABLE))); 	DPRINTF((
literal|"               hcca=0x%08x percur=0x%08x ctrlhd=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_HCCA), 		 OREAD4(sc, OHCI_PERIOD_CURRENT_ED), 		 OREAD4(sc, OHCI_CONTROL_HEAD_ED))); 	DPRINTF((
literal|"               ctrlcur=0x%08x bulkhd=0x%08x bulkcur=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_CONTROL_CURRENT_ED), 		 OREAD4(sc, OHCI_BULK_HEAD_ED), 		 OREAD4(sc, OHCI_BULK_CURRENT_ED))); 	DPRINTF((
literal|"               done=0x%08x fmival=0x%08x fmrem=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_DONE_HEAD), 		 OREAD4(sc, OHCI_FM_INTERVAL), 		 OREAD4(sc, OHCI_FM_REMAINING))); 	DPRINTF((
literal|"               fmnum=0x%08x perst=0x%08x lsthrs=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_FM_NUMBER), 		 OREAD4(sc, OHCI_PERIODIC_START), 		 OREAD4(sc, OHCI_LS_THRESHOLD))); 	DPRINTF((
literal|"               desca=0x%08x descb=0x%08x stat=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_RH_DESCRIPTOR_A), 		 OREAD4(sc, OHCI_RH_DESCRIPTOR_B), 		 OREAD4(sc, OHCI_RH_STATUS))); 	DPRINTF((
literal|"               port1=0x%08x port2=0x%08x\n"
argument|, 		 OREAD4(sc, OHCI_RH_PORT_STATUS(
literal|1
argument|)), 		 OREAD4(sc, OHCI_RH_PORT_STATUS(
literal|2
argument|)))); 	DPRINTF((
literal|"         HCCA: frame_number=0x%04x done_head=0x%08x\n"
argument|, 		 LE(sc->sc_hcca->hcca_frame_number), 		 LE(sc->sc_hcca->hcca_done_head))); }
endif|#
directive|endif
argument|int ohci_intr(p) 	void *p; { 	ohci_softc_t *sc = p; 	u_int32_t intrs
argument_list|,
argument|eintrs; 	ohci_physaddr_t done;
comment|/* In case the interrupt occurs before initialization has completed. */
argument|if (sc == NULL || sc->sc_hcca == NULL) {
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|printf(
literal|"ohci_intr: sc->sc_hcca == NULL\n"
argument|);
endif|#
directive|endif
argument|return (
literal|0
argument|); 	}          intrs =
literal|0
argument|; 	done = LE(sc->sc_hcca->hcca_done_head); 	if (done !=
literal|0
argument|) { 		sc->sc_hcca->hcca_done_head =
literal|0
argument|; 		if (done& ~OHCI_DONE_INTRS) 			intrs = OHCI_WDH; 		if (done& OHCI_DONE_INTRS) 			intrs |= OREAD4(sc, OHCI_INTERRUPT_STATUS); 	} else 		intrs = OREAD4(sc, OHCI_INTERRUPT_STATUS); 	if (!intrs) 		return (
literal|0
argument|); 	intrs&= ~OHCI_MIE; 	OWRITE4(sc, OHCI_INTERRUPT_STATUS, intrs);
comment|/* Acknowledge */
argument|eintrs = intrs& sc->sc_eintrs; 	if (!eintrs) 		return (
literal|0
argument|);  	sc->sc_intrs++; 	DPRINTFN(
literal|7
argument|, (
literal|"ohci_intr: sc=%p intrs=%x(%x) eintr=%x\n"
argument|,  		     sc, (u_int)intrs, OREAD4(sc, OHCI_INTERRUPT_STATUS), 		     (u_int)eintrs));  	if (eintrs& OHCI_SO) { 		printf(
literal|"%s: scheduling overrun\n"
argument|,USBDEVNAME(sc->sc_bus.bdev));
comment|/* XXX do what */
argument|intrs&= ~OHCI_SO; 	} 	if (eintrs& OHCI_WDH) { 		ohci_process_done(sc, done&~ OHCI_DONE_INTRS); 		intrs&= ~OHCI_WDH; 	} 	if (eintrs& OHCI_RD) { 		printf(
literal|"%s: resume detect\n"
argument|, USBDEVNAME(sc->sc_bus.bdev));
comment|/* XXX process resume detect */
argument|} 	if (eintrs& OHCI_UE) { 		printf(
literal|"%s: unrecoverable error, controller halted\n"
argument|, 		       USBDEVNAME(sc->sc_bus.bdev)); 		OWRITE4(sc, OHCI_CONTROL, OHCI_HCFS_RESET);
comment|/* XXX what else */
argument|} 	if (eintrs& OHCI_RHSC) { 		ohci_rhsc(sc, sc->sc_intrreqh); 		intrs&= ~OHCI_RHSC;
comment|/*  		 * Disable RHSC interrupt for now, because it will be 		 * on until the port has been reset. 		 */
argument|ohci_rhsc_able(sc,
literal|0
argument|); 	}
comment|/* Block unprocessed interrupts. XXX */
argument|OWRITE4(sc, OHCI_INTERRUPT_DISABLE, intrs); 	sc->sc_eintrs&= ~intrs;  	return (
literal|1
argument|); }  void ohci_rhsc_able(sc, on) 	ohci_softc_t *sc; 	int on; { 	DPRINTFN(
literal|4
argument|, (
literal|"ohci_rhsc_able: on=%d\n"
argument|, on)); 	if (on) { 		sc->sc_eintrs |= OHCI_RHSC; 		OWRITE4(sc, OHCI_INTERRUPT_ENABLE, OHCI_RHSC); 	} else { 		sc->sc_eintrs&= ~OHCI_RHSC; 		OWRITE4(sc, OHCI_INTERRUPT_DISABLE, OHCI_RHSC); 	} }
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|char *ohci_cc_strs[] = {
literal|"NO_ERROR"
argument_list|,
literal|"CRC"
argument_list|,
literal|"BIT_STUFFING"
argument_list|,
literal|"DATA_TOGGLE_MISMATCH"
argument_list|,
literal|"STALL"
argument_list|,
literal|"DEVICE_NOT_RESPONDING"
argument_list|,
literal|"PID_CHECK_FAILURE"
argument_list|,
literal|"UNEXPECTED_PID"
argument_list|,
literal|"DATA_OVERRUN"
argument_list|,
literal|"DATA_UNDERRUN"
argument_list|,
literal|"BUFFER_OVERRUN"
argument_list|,
literal|"BUFFER_UNDERRUN"
argument_list|,
literal|"NOT_ACCESSED"
argument_list|,
argument|};
endif|#
directive|endif
argument|void ohci_process_done(sc, done) 	ohci_softc_t *sc; 	ohci_physaddr_t done; { 	ohci_soft_td_t *std
argument_list|,
argument|*sdone; 	usbd_request_handle reqh; 	int len
argument_list|,
argument|cc;  	DPRINTFN(
literal|10
argument|,(
literal|"ohci_process_done: done=0x%08lx\n"
argument|, (u_long)done));
comment|/* Reverse the done list. */
argument|for (sdone =
literal|0
argument|; done; done = LE(std->td.td_nexttd)) { 		std = ohci_hash_find_td(sc, done); 		std->dnext = sdone; 		sdone = std; 	}
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|10
argument|) { 		DPRINTF((
literal|"ohci_process_done: TD done:\n"
argument|)); 		ohci_dump_tds(sdone); 	}
endif|#
directive|endif
argument|for (std = sdone; std; std = std->dnext) { 		reqh = std->reqh; 		DPRINTFN(
literal|10
argument|, (
literal|"ohci_process_done: std=%p reqh=%p hcpriv=%p\n"
argument|, 				std, reqh, reqh->hcpriv)); 		cc = OHCI_TD_GET_CC(LE(std->td.td_flags)); 		usb_untimeout(ohci_timeout, reqh, reqh->timo_handle); 		if (reqh->status == USBD_CANCELLED || 		    reqh->status == USBD_TIMEOUT) { 			DPRINTF((
literal|"ohci_process_done: cancel/timeout %p\n"
argument|, 				 reqh));
comment|/* Handled by abort routine. */
argument|continue; 		} else if (cc == OHCI_CC_NO_ERROR) { 			len = std->len; 			if (std->td.td_cbp !=
literal|0
argument|) 				len -= LE(std->td.td_be) - 				       LE(std->td.td_cbp) +
literal|1
argument|; 			if (std->flags& OHCI_SET_LEN) 				reqh->actlen = len; 			if (std->flags& OHCI_CALL_DONE) { 				reqh->status = USBD_NORMAL_COMPLETION; 				usb_transfer_complete(reqh); 			} 		} else { 			ohci_soft_td_t *p
argument_list|,
argument|*n; 			struct ohci_pipe *opipe =  				(struct ohci_pipe *)reqh->pipe; 			DPRINTFN(-
literal|1
argument|,(
literal|"ohci_process_done: error cc=%d (%s)\n"
argument|, 			 OHCI_TD_GET_CC(LE(std->td.td_flags)), 			 ohci_cc_strs[OHCI_TD_GET_CC(LE(std->td.td_flags))]));
comment|/* 			 * Endpoint is halted.  First unlink all the TDs 			 * belonging to the failed transfer, and then restart 			 * the endpoint. 			 */
argument|for (p = std->nexttd; p->reqh == reqh; p = n) { 				n = p->nexttd; 				ohci_hash_rem_td(sc, p); 				ohci_free_std(sc, p); 			}
comment|/* clear halt */
argument|opipe->sed->ed.ed_headp = LE(p->physaddr); 			OWRITE4(sc, OHCI_COMMAND_STATUS, OHCI_CLF); 			 			if (cc == OHCI_CC_STALL) 				reqh->status = USBD_STALLED; 			else 				reqh->status = USBD_IOERROR; 			usb_transfer_complete(reqh); 		} 		ohci_hash_rem_td(sc, std); 		ohci_free_std(sc, std); 	} }  void ohci_device_ctrl_done(reqh) 	usbd_request_handle reqh; { 	DPRINTFN(
literal|10
argument|,(
literal|"ohci_ctrl_done: reqh=%p\n"
argument|, reqh));
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (!(reqh->rqflags& URQ_REQUEST)) { 		panic(
literal|"ohci_ctrl_done: not a request\n"
argument|); 	}
endif|#
directive|endif
argument|reqh->hcpriv =
literal|0
argument|; }  void ohci_device_intr_done(reqh) 	usbd_request_handle reqh; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	ohci_softc_t *sc = (ohci_softc_t *)opipe->pipe.device->bus; 	ohci_soft_ed_t *sed = opipe->sed; 	ohci_soft_td_t *xfer
argument_list|,
argument|*tail;   	DPRINTFN(
literal|10
argument|,(
literal|"ohci_intr_done: reqh=%p, actlen=%d\n"
argument|,  		     reqh, reqh->actlen));  	reqh->hcpriv =
literal|0
argument|;  	if (reqh->pipe->repeat) { 		xfer = opipe->tail; 		tail = ohci_alloc_std(sc);
comment|/* XXX should reuse TD */
argument|if (!tail) { 			reqh->status = USBD_NOMEM; 			return; 		} 		tail->reqh =
literal|0
argument|; 		 		xfer->td.td_flags = LE( 			OHCI_TD_IN | OHCI_TD_NOCC |  			OHCI_TD_SET_DI(
literal|1
argument|) | OHCI_TD_TOGGLE_CARRY); 		if (reqh->flags& USBD_SHORT_XFER_OK) 			xfer->td.td_flags |= LE(OHCI_TD_R); 		xfer->td.td_cbp = LE(DMAADDR(&reqh->dmabuf)); 		xfer->nexttd = tail; 		xfer->td.td_nexttd = LE(tail->physaddr); 		xfer->td.td_be = LE(LE(xfer->td.td_cbp) + reqh->length -
literal|1
argument|); 		xfer->len = reqh->length; 		xfer->reqh = reqh; 		xfer->flags = OHCI_CALL_DONE | OHCI_SET_LEN; 		reqh->hcpriv = xfer;  		ohci_hash_add_td(sc, xfer); 		sed->ed.ed_tailp = LE(tail->physaddr); 		opipe->tail = tail; 	} }  void ohci_device_bulk_done(reqh) 	usbd_request_handle reqh; { 	DPRINTFN(
literal|10
argument|,(
literal|"ohci_bulk_done: reqh=%p, actlen=%d\n"
argument|,  		     reqh, reqh->actlen));  	reqh->hcpriv =
literal|0
argument|; }  void ohci_rhsc(sc, reqh) 	ohci_softc_t *sc; 	usbd_request_handle reqh; { 	usbd_pipe_handle pipe; 	struct ohci_pipe *opipe; 	u_char *p; 	int i
argument_list|,
argument|m; 	int hstatus;  	hstatus = OREAD4(sc, OHCI_RH_STATUS); 	DPRINTF((
literal|"ohci_rhsc: sc=%p reqh=%p hstatus=0x%08x\n"
argument|,  		 sc, reqh, hstatus));  	if (reqh ==
literal|0
argument|) {
comment|/* Just ignore the change. */
argument|return; 	}  	pipe = reqh->pipe; 	opipe = (struct ohci_pipe *)pipe;  	p = KERNADDR(&reqh->dmabuf); 	m = min(sc->sc_noport, reqh->length *
literal|8
argument|-
literal|1
argument|); 	memset(p,
literal|0
argument|, reqh->length); 	for (i =
literal|1
argument|; i<= m; i++) { 		if (OREAD4(sc, OHCI_RH_PORT_STATUS(i))>>
literal|16
argument|) 			p[i/
literal|8
argument|] |=
literal|1
argument|<< (i%
literal|8
argument|); 	} 	DPRINTF((
literal|"ohci_rhsc: change=0x%02x\n"
argument|, *p)); 	reqh->actlen = reqh->length; 	reqh->status = USBD_NORMAL_COMPLETION;  	usb_transfer_complete(reqh); }  void ohci_root_intr_done(reqh) 	usbd_request_handle reqh; { 	reqh->hcpriv =
literal|0
argument|; }
comment|/*  * Wait here until controller claims to have an interrupt.  * Then call ohci_intr and return.  Use timeout to avoid waiting  * too long.  */
argument|void ohci_waitintr(sc, reqh) 	ohci_softc_t *sc; 	usbd_request_handle reqh; { 	int timo = reqh->timeout; 	int usecs; 	u_int32_t intrs;  	reqh->status = USBD_IN_PROGRESS; 	for (usecs = timo *
literal|1000000
argument|/ hz; usecs>
literal|0
argument|; usecs -=
literal|1000
argument|) { 		usb_delay_ms(&sc->sc_bus,
literal|1
argument|); 		intrs = OREAD4(sc, OHCI_INTERRUPT_STATUS)& sc->sc_eintrs; 		DPRINTFN(
literal|15
argument|,(
literal|"ohci_waitintr: 0x%04x\n"
argument|, intrs));
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|15
argument|) 			ohci_dumpregs(sc);
endif|#
directive|endif
argument|if (intrs) { 			ohci_intr(sc); 			if (reqh->status != USBD_IN_PROGRESS) 				return; 		} 	}
comment|/* Timeout */
argument|DPRINTF((
literal|"ohci_waitintr: timeout\n"
argument|)); 	reqh->status = USBD_TIMEOUT; 	usb_transfer_complete(reqh);
comment|/* XXX should free TD */
argument|}  void ohci_poll(bus) 	struct usbd_bus *bus; { 	ohci_softc_t *sc = (ohci_softc_t *)bus;  	if (OREAD4(sc, OHCI_INTERRUPT_STATUS)& sc->sc_eintrs) 		ohci_intr(sc); }  usbd_status ohci_device_request(reqh) 	usbd_request_handle reqh; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	usb_device_request_t *req =&reqh->request; 	usbd_device_handle dev = opipe->pipe.device; 	ohci_softc_t *sc = (ohci_softc_t *)dev->bus; 	int addr = dev->address; 	ohci_soft_td_t *setup
argument_list|,
argument|*xfer =
literal|0
argument_list|,
argument|*stat
argument_list|,
argument|*next
argument_list|,
argument|*tail; 	ohci_soft_ed_t *sed; 	int isread; 	int len; 	usbd_status r; 	int s;  	isread = req->bmRequestType& UT_READ; 	len = UGETW(req->wLength);  	DPRINTFN(
literal|3
argument|,(
literal|"ohci_device_control type=0x%02x, request=0x%02x, "
literal|"wValue=0x%04x, wIndex=0x%04x len=%d, addr=%d, endpt=%d\n"
argument|, 		    req->bmRequestType, req->bRequest, UGETW(req->wValue), 		    UGETW(req->wIndex), len, addr,  		    opipe->pipe.endpoint->edesc->bEndpointAddress));  	setup = opipe->tail; 	stat = ohci_alloc_std(sc); 	if (!stat) { 		r = USBD_NOMEM; 		goto bad1; 	} 	tail = ohci_alloc_std(sc); 	if (!tail) { 		r = USBD_NOMEM; 		goto bad2; 	} 	tail->reqh =
literal|0
argument|;  	sed = opipe->sed; 	opipe->u.ctl.length = len;
comment|/* Update device address and length since they may have changed. */
comment|/* XXX This only needs to be done once, but it's too early in open. */
argument|sed->ed.ed_flags = LE( 	 (LE(sed->ed.ed_flags)& ~(OHCI_ED_ADDRMASK | OHCI_ED_MAXPMASK)) | 	 OHCI_ED_SET_FA(addr) | 	 OHCI_ED_SET_MAXP(UGETW(opipe->pipe.endpoint->edesc->wMaxPacketSize)));
comment|/* Set up data transaction */
argument|if (len !=
literal|0
argument|) { 		xfer = ohci_alloc_std(sc); 		if (!xfer) { 			r = USBD_NOMEM; 			goto bad3; 		} 		xfer->td.td_flags = LE( 			(isread ? OHCI_TD_IN : OHCI_TD_OUT) | OHCI_TD_NOCC | 			OHCI_TD_TOGGLE_1 | OHCI_TD_NOINTR | 			(reqh->flags& USBD_SHORT_XFER_OK ? OHCI_TD_R :
literal|0
argument|)); 		xfer->td.td_cbp = LE(DMAADDR(&reqh->dmabuf)); 		xfer->nexttd = stat; 		xfer->td.td_nexttd = LE(stat->physaddr); 		xfer->td.td_be = LE(LE(xfer->td.td_cbp) + len -
literal|1
argument|); 		xfer->len = len; 		xfer->reqh = reqh; 		xfer->flags = OHCI_SET_LEN;  		next = xfer; 		stat->flags = OHCI_CALL_DONE; 	} else { 		next = stat; 		stat->flags = OHCI_CALL_DONE | OHCI_SET_LEN; 	}  	memcpy(KERNADDR(&opipe->u.ctl.reqdma), req, sizeof *req);  	setup->td.td_flags = LE(OHCI_TD_SETUP | OHCI_TD_NOCC | 				 OHCI_TD_TOGGLE_0 | OHCI_TD_NOINTR); 	setup->td.td_cbp = LE(DMAADDR(&opipe->u.ctl.reqdma)); 	setup->nexttd = next; 	setup->td.td_nexttd = LE(next->physaddr); 	setup->td.td_be = LE(LE(setup->td.td_cbp) + sizeof *req -
literal|1
argument|); 	setup->len =
literal|0
argument|;
comment|/* XXX The number of byte we count */
argument|setup->reqh = reqh; 	setup->flags =
literal|0
argument|; 	reqh->hcpriv = setup;  	stat->td.td_flags = LE( 		(isread ? OHCI_TD_OUT : OHCI_TD_IN) | OHCI_TD_NOCC | 		OHCI_TD_TOGGLE_1 | OHCI_TD_SET_DI(
literal|1
argument|)); 	stat->td.td_cbp =
literal|0
argument|; 	stat->nexttd = tail; 	stat->td.td_nexttd = LE(tail->physaddr); 	stat->td.td_be =
literal|0
argument|; 	stat->len =
literal|0
argument|; 	stat->reqh = reqh;
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|5
argument|) { 		DPRINTF((
literal|"ohci_device_request:\n"
argument|)); 		ohci_dump_ed(sed); 		ohci_dump_tds(setup); 	}
endif|#
directive|endif
comment|/* Insert ED in schedule */
argument|s = splusb(); 	ohci_hash_add_td(sc, setup); 	if (len !=
literal|0
argument|) 		ohci_hash_add_td(sc, xfer); 	ohci_hash_add_td(sc, stat); 	sed->ed.ed_tailp = LE(tail->physaddr); 	opipe->tail = tail; 	OWRITE4(sc, OHCI_COMMAND_STATUS, OHCI_CLF); 	if (reqh->timeout&& !sc->sc_bus.use_polling) {                 usb_timeout(ohci_timeout, reqh, 			    MS_TO_TICKS(reqh->timeout), reqh->timo_handle); 	} 	splx(s);
if|#
directive|if
literal|0
argument|This goes horribly wrong, printing thousands of descriptors, 	because false references are followed due to the fact that the 	TD is gone.
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug> 5) { 		delay(5000); 		DPRINTF(("ohci_device_request: status=%x\n", 			 OREAD4(sc, OHCI_COMMAND_STATUS))); 		ohci_dump_ed(sed); 		ohci_dump_tds(setup); 	}
endif|#
directive|endif
endif|#
directive|endif
argument|return (USBD_NORMAL_COMPLETION);   bad3: 	ohci_free_std(sc, tail);  bad2: 	ohci_free_std(sc, stat);  bad1: 	return (r); }
comment|/*  * Add an ED to the schedule.  Called at splusb().  */
argument|void ohci_add_ed(sed, head) 	ohci_soft_ed_t *sed;  	ohci_soft_ed_t *head;  { 	sed->next = head->next; 	sed->ed.ed_nexted = head->ed.ed_nexted; 	head->next = sed; 	head->ed.ed_nexted = LE(sed->physaddr); }
comment|/*  * Remove an ED from the schedule.  Called at splusb().  */
argument|void ohci_rem_ed(sed, head) 	ohci_soft_ed_t *sed;  	ohci_soft_ed_t *head;  { 	ohci_soft_ed_t *p;
comment|/* XXX */
argument|for (p = head; p&& p->next != sed; p = p->next) 		; 	if (!p) 		panic(
literal|"ohci_rem_ed: ED not found\n"
argument|); 	p->next = sed->next; 	p->ed.ed_nexted = sed->ed.ed_nexted; }
comment|/*  * When a transfer is completed the TD is added to the done queue by  * the host controller.  This queue is the processed by software.  * Unfortunately the queue contains the physical address of the TD  * and we have no simple way to translate this back to a kernel address.  * To make the translation possible (and fast) we use a hash table of  * TDs currently in the schedule.  The physical address is used as the  * hash value.  */
define|#
directive|define
name|HASH
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 4) % OHCI_HASH_SIZE)
comment|/* Called at splusb() */
argument|void ohci_hash_add_td(sc, std) 	ohci_softc_t *sc; 	ohci_soft_td_t *std; { 	int h = HASH(std->physaddr);  	LIST_INSERT_HEAD(&sc->sc_hash_tds[h], std, hnext); }
comment|/* Called at splusb() */
argument|void ohci_hash_rem_td(sc, std) 	ohci_softc_t *sc; 	ohci_soft_td_t *std; { 	LIST_REMOVE(std, hnext); }  ohci_soft_td_t * ohci_hash_find_td(sc, a) 	ohci_softc_t *sc; 	ohci_physaddr_t a; { 	int h = HASH(a); 	ohci_soft_td_t *std;  	for (std = LIST_FIRST(&sc->sc_hash_tds[h]);  	     std !=
literal|0
argument|;  	     std = LIST_NEXT(std, hnext)) 		if (std->physaddr == a) 			return (std); 	panic(
literal|"ohci_hash_find_td: addr 0x%08lx not found\n"
argument|, (u_long)a); }  void ohci_timeout(addr) 	void *addr; { 	usbd_request_handle reqh = addr;  	DPRINTF((
literal|"ohci_timeout: reqh=%p\n"
argument|, reqh)); 	ohci_abort_req(reqh, USBD_TIMEOUT); }
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|void ohci_dump_tds(std) 	ohci_soft_td_t *std; { 	for (; std; std = std->nexttd) 		ohci_dump_td(std); }  void ohci_dump_td(std) 	ohci_soft_td_t *std; { 	DPRINTF((
literal|"TD(%p) at %08lx: %b delay=%d ec=%d cc=%d\ncbp=0x%08lx "
literal|"nexttd=0x%08lx be=0x%08lx\n"
argument|,  		 std, (u_long)std->physaddr, 		 (int)LE(std->td.td_flags),
literal|"\20\23R\24OUT\25IN\31TOG1\32SETTOGGLE"
argument|, 		 OHCI_TD_GET_DI(LE(std->td.td_flags)), 		 OHCI_TD_GET_EC(LE(std->td.td_flags)), 		 OHCI_TD_GET_CC(LE(std->td.td_flags)), 		 (u_long)LE(std->td.td_cbp), 		 (u_long)LE(std->td.td_nexttd), (u_long)LE(std->td.td_be))); }  void ohci_dump_ed(sed) 	ohci_soft_ed_t *sed; { 	DPRINTF((
literal|"ED(%p) at %08lx: addr=%d endpt=%d maxp=%d %b\ntailp=0x%08lx "
literal|"headp=%b nexted=0x%08lx\n"
argument|, 		 sed, (u_long)sed->physaddr,  		 OHCI_ED_GET_FA(LE(sed->ed.ed_flags)), 		 OHCI_ED_GET_EN(LE(sed->ed.ed_flags)), 		 OHCI_ED_GET_MAXP(LE(sed->ed.ed_flags)), 		 (int)LE(sed->ed.ed_flags),
literal|"\20\14OUT\15IN\16LOWSPEED\17SKIP\20ISO"
argument|, 		 (u_long)LE(sed->ed.ed_tailp), 		 (int)LE(sed->ed.ed_headp),
literal|"\20\1HALT\2CARRY"
argument|, 		 (u_long)LE(sed->ed.ed_nexted))); }
endif|#
directive|endif
argument|usbd_status ohci_open(pipe) 	usbd_pipe_handle pipe; { 	usbd_device_handle dev = pipe->device; 	ohci_softc_t *sc = (ohci_softc_t *)dev->bus; 	usb_endpoint_descriptor_t *ed = pipe->endpoint->edesc; 	struct ohci_pipe *opipe = (struct ohci_pipe *)pipe; 	u_int8_t addr = dev->address; 	ohci_soft_ed_t *sed; 	ohci_soft_td_t *std; 	usbd_status r; 	int s;  	DPRINTFN(
literal|1
argument|, (
literal|"ohci_open: pipe=%p, addr=%d, endpt=%d (%d)\n"
argument|, 		     pipe, addr, ed->bEndpointAddress, sc->sc_addr)); 	if (addr == sc->sc_addr) { 		switch (ed->bEndpointAddress) { 		case USB_CONTROL_ENDPOINT: 			pipe->methods =&ohci_root_ctrl_methods; 			break; 		case UE_DIR_IN | OHCI_INTR_ENDPT: 			pipe->methods =&ohci_root_intr_methods; 			break; 		default: 			return (USBD_INVAL); 		} 	} else { 		sed = ohci_alloc_sed(sc); 		if (sed ==
literal|0
argument|) 			goto bad0; 	        std = ohci_alloc_std(sc); 		if (std ==
literal|0
argument|) 			goto bad1; 		opipe->sed = sed; 		opipe->tail = std; 		sed->ed.ed_flags = LE( 			OHCI_ED_SET_FA(addr) |  			OHCI_ED_SET_EN(ed->bEndpointAddress) | 			OHCI_ED_DIR_TD |  			(dev->lowspeed ? OHCI_ED_SPEED :
literal|0
argument|) |  			((ed->bmAttributes& UE_XFERTYPE) == UE_ISOCHRONOUS ? 			 OHCI_ED_FORMAT_ISO : OHCI_ED_FORMAT_GEN) | 			OHCI_ED_SET_MAXP(UGETW(ed->wMaxPacketSize))); 		sed->ed.ed_headp = sed->ed.ed_tailp = LE(std->physaddr);  		switch (ed->bmAttributes& UE_XFERTYPE) { 		case UE_CONTROL: 			pipe->methods =&ohci_device_ctrl_methods; 			r = usb_allocmem(sc->sc_dmatag,  					 sizeof(usb_device_request_t),
literal|0
argument|,&opipe->u.ctl.reqdma); 			if (r != USBD_NORMAL_COMPLETION) 				goto bad; 			s = splusb(); 			ohci_add_ed(sed, sc->sc_ctrl_head); 			splx(s); 			break; 		case UE_INTERRUPT: 			pipe->methods =&ohci_device_intr_methods; 			return (ohci_device_setintr(sc, opipe, ed->bInterval)); 		case UE_ISOCHRONOUS: 			printf(
literal|"ohci_open: open iso unimplemented\n"
argument|); 			return (USBD_INVAL); 		case UE_BULK: 			pipe->methods =&ohci_device_bulk_methods; 			s = splusb(); 			ohci_add_ed(sed, sc->sc_bulk_head); 			splx(s); 			break; 		} 	} 	return (USBD_NORMAL_COMPLETION);   bad: 	ohci_free_std(sc, std);  bad1: 	ohci_free_sed(sc, sed);  bad0: 	return (USBD_NOMEM); 	 }
comment|/*  * Close a reqular pipe.  * Assumes that there are no pending transactions.  */
argument|void ohci_close_pipe(pipe, head) 	usbd_pipe_handle pipe; 	ohci_soft_ed_t *head; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)pipe; 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus; 	ohci_soft_ed_t *sed = opipe->sed; 	int s;  	s = splusb();
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|sed->ed.ed_flags |= LE(OHCI_ED_SKIP); 	if ((sed->ed.ed_tailp& LE(OHCI_TAILMASK)) !=  	    (sed->ed.ed_headp& LE(OHCI_TAILMASK))) { 		ohci_physaddr_t td = sed->ed.ed_headp; 		ohci_soft_td_t *std; 		for (std = LIST_FIRST(&sc->sc_hash_tds[HASH(td)]);  		     std !=
literal|0
argument|;  		     std = LIST_NEXT(std, hnext)) 		    if (std->physaddr == td) 			break; 		printf(
literal|"ohci_close_pipe: pipe not empty sed=%p hd=0x%x "
literal|"tl=0x%x pipe=%p, std=%p\n"
argument|, sed, 		       (int)LE(sed->ed.ed_headp), (int)LE(sed->ed.ed_tailp), 		       pipe, std); 		usb_delay_ms(&sc->sc_bus,
literal|2
argument|); 		if ((sed->ed.ed_tailp& LE(OHCI_TAILMASK)) !=  		    (sed->ed.ed_headp& LE(OHCI_TAILMASK))) 			printf(
literal|"ohci_close_pipe: pipe still not empty\n"
argument|); 	}
endif|#
directive|endif
argument|ohci_rem_ed(sed, head); 	splx(s); 	ohci_free_std(sc, opipe->tail); 	ohci_free_sed(sc, opipe->sed); }
comment|/*   * Abort a device request.  * If this routine is called at splusb() it guarantees that the request  * will be removed from the hardware scheduling and that the callback  * for it will be called with USBD_CANCELLED status.  * It's impossible to guarantee that the requested transfer will not  * have happened since the hardware runs concurrently.  * If the transaction has already happened we rely on the ordinary  * interrupt processing to process it.  */
argument|void ohci_abort_req(reqh, status) 	usbd_request_handle reqh; 	usbd_status status; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	ohci_soft_ed_t *sed;  	DPRINTF((
literal|"ohci_abort_req: reqh=%p pipe=%p\n"
argument|, reqh, opipe));  	reqh->status = status;  	usb_untimeout(ohci_timeout, reqh, reqh->timo_handle);  	sed = opipe->sed; 	DPRINTFN(
literal|1
argument|,(
literal|"ohci_abort_req: stop ed=%p\n"
argument|, sed)); 	sed->ed.ed_flags |= LE(OHCI_ED_SKIP);
comment|/* force hardware skip */
argument|if (curproc) { 		usb_delay_ms(opipe->pipe.device->bus,
literal|1
argument|); 		ohci_abort_req_end(reqh); 	} else { 		timeout(ohci_abort_req_end, reqh, hz / USB_FRAMES_PER_SECOND); 	} }  void ohci_abort_req_end(v) 	void *v; { 	usbd_request_handle reqh = v; 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	ohci_softc_t *sc = (ohci_softc_t *)opipe->pipe.device->bus; 	ohci_soft_ed_t *sed; 	ohci_soft_td_t *p
argument_list|,
argument|*n; 	int s;  	s = splusb();  	p = reqh->hcpriv;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (!p) { 		printf(
literal|"ohci_abort_req: hcpriv==0\n"
argument|); 		return; 	}
endif|#
directive|endif
argument|for (; p->reqh == reqh; p = n) { 		n = p->nexttd; 		ohci_hash_rem_td(sc, p); 		ohci_free_std(sc, p); 	}  	sed = opipe->sed; 	DPRINTFN(
literal|2
argument|,(
literal|"ohci_abort_req: set hd=%x, tl=%x\n"
argument|, 		    (int)LE(p->physaddr), (int)LE(sed->ed.ed_tailp))); 	sed->ed.ed_headp = p->physaddr;
comment|/* unlink TDs */
argument|sed->ed.ed_flags&= LE(~OHCI_ED_SKIP);
comment|/* remove hardware skip */
argument|usb_transfer_complete(reqh);  	splx(s); }
comment|/*  * Data structures and routines to emulate the root hub.  */
argument|usb_device_descriptor_t ohci_devd = { 	USB_DEVICE_DESCRIPTOR_SIZE
argument_list|,
argument|UDESC_DEVICE
argument_list|,
comment|/* type */
argument|{
literal|0x00
argument_list|,
literal|0x01
argument|}
argument_list|,
comment|/* USB version */
argument|UCLASS_HUB
argument_list|,
comment|/* class */
argument|USUBCLASS_HUB
argument_list|,
comment|/* subclass */
literal|0
argument_list|,
comment|/* protocol */
literal|64
argument_list|,
comment|/* max packet */
argument|{
literal|0
argument|}
argument_list|,
argument|{
literal|0
argument|}
argument_list|,
argument|{
literal|0x00
argument_list|,
literal|0x01
argument|}
argument_list|,
comment|/* device id */
literal|1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
comment|/* string indicies */
literal|1
comment|/* # of configurations */
argument|};  usb_config_descriptor_t ohci_confd = { 	USB_CONFIG_DESCRIPTOR_SIZE
argument_list|,
argument|UDESC_CONFIG
argument_list|,
argument|{USB_CONFIG_DESCRIPTOR_SIZE + 	 USB_INTERFACE_DESCRIPTOR_SIZE + 	 USB_ENDPOINT_DESCRIPTOR_SIZE}
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
argument|UC_SELF_POWERED
argument_list|,
literal|0
comment|/* max power */
argument|};  usb_interface_descriptor_t ohci_ifcd = { 	USB_INTERFACE_DESCRIPTOR_SIZE
argument_list|,
argument|UDESC_INTERFACE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
argument|UCLASS_HUB
argument_list|,
argument|USUBCLASS_HUB
argument_list|,
literal|0
argument_list|,
literal|0
argument|};  usb_endpoint_descriptor_t ohci_endpd = { 	USB_ENDPOINT_DESCRIPTOR_SIZE
argument_list|,
argument|UDESC_ENDPOINT
argument_list|,
argument|UE_DIR_IN | OHCI_INTR_ENDPT
argument_list|,
argument|UE_INTERRUPT
argument_list|,
argument|{
literal|8
argument_list|,
literal|0
argument|}
argument_list|,
comment|/* max packet */
literal|255
argument|};  usb_hub_descriptor_t ohci_hubd = { 	USB_HUB_DESCRIPTOR_SIZE
argument_list|,
argument|UDESC_HUB
argument_list|,
literal|0
argument_list|,
argument|{
literal|0
argument_list|,
literal|0
argument|}
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|{
literal|0
argument|}
argument_list|,
argument|};  int ohci_str(p, l, s) 	usb_string_descriptor_t *p; 	int l; 	char *s; { 	int i;  	if (l ==
literal|0
argument|) 		return (
literal|0
argument|); 	p->bLength =
literal|2
argument|* strlen(s) +
literal|2
argument|; 	if (l ==
literal|1
argument|) 		return (
literal|1
argument|); 	p->bDescriptorType = UDESC_STRING; 	l -=
literal|2
argument|; 	for (i =
literal|0
argument|; s[i]&& l>
literal|1
argument|; i++, l -=
literal|2
argument|) 		USETW2(p->bString[i],
literal|0
argument|, s[i]); 	return (
literal|2
argument|*i+
literal|2
argument|); }
comment|/*  * Simulate a hardware hub by handling all the necessary requests.  */
argument|usbd_status ohci_root_ctrl_transfer(reqh) 	usbd_request_handle reqh; { 	usbd_status r;  	r = usb_insert_transfer(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	else 		return (ohci_root_ctrl_start(reqh)); }  usbd_status ohci_root_ctrl_start(reqh) 	usbd_request_handle reqh; { 	ohci_softc_t *sc = (ohci_softc_t *)reqh->pipe->device->bus; 	usb_device_request_t *req; 	void *buf = NULL; 	int port
argument_list|,
argument|i; 	int len
argument_list|,
argument|value
argument_list|,
argument|index
argument_list|,
argument|l
argument_list|,
argument|totlen =
literal|0
argument|; 	usb_port_status_t ps; 	usb_hub_descriptor_t hubd; 	usbd_status r; 	u_int32_t v;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (!(reqh->rqflags& URQ_REQUEST))
comment|/* XXX panic */
argument|return (USBD_INVAL);
endif|#
directive|endif
argument|req =&reqh->request;  	DPRINTFN(
literal|4
argument|,(
literal|"ohci_root_ctrl_control type=0x%02x request=%02x\n"
argument|,  		    req->bmRequestType, req->bRequest));  	len = UGETW(req->wLength); 	value = UGETW(req->wValue); 	index = UGETW(req->wIndex);  	if (len !=
literal|0
argument|) 		buf = KERNADDR(&reqh->dmabuf);
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) | ((y)<< 8))
argument|switch(C(req->bRequest, req->bmRequestType)) { 	case C(UR_CLEAR_FEATURE, UT_WRITE_DEVICE): 	case C(UR_CLEAR_FEATURE, UT_WRITE_INTERFACE): 	case C(UR_CLEAR_FEATURE, UT_WRITE_ENDPOINT):
comment|/*  		 * DEVICE_REMOTE_WAKEUP and ENDPOINT_HALT are no-ops 		 * for the integrated root hub. 		 */
argument|break; 	case C(UR_GET_CONFIG, UT_READ_DEVICE): 		if (len>
literal|0
argument|) { 			*(u_int8_t *)buf = sc->sc_conf; 			totlen =
literal|1
argument|; 		} 		break; 	case C(UR_GET_DESCRIPTOR, UT_READ_DEVICE): 		DPRINTFN(
literal|8
argument|,(
literal|"ohci_root_ctrl_control wValue=0x%04x\n"
argument|, value)); 		switch(value>>
literal|8
argument|) { 		case UDESC_DEVICE: 			if ((value&
literal|0xff
argument|) !=
literal|0
argument|) { 				r = USBD_IOERROR; 				goto ret; 			} 			totlen = l = min(len, USB_DEVICE_DESCRIPTOR_SIZE); 			USETW(ohci_devd.idVendor, sc->sc_id_vendor); 			memcpy(buf,&ohci_devd, l); 			break; 		case UDESC_CONFIG: 			if ((value&
literal|0xff
argument|) !=
literal|0
argument|) { 				r = USBD_IOERROR; 				goto ret; 			} 			totlen = l = min(len, USB_CONFIG_DESCRIPTOR_SIZE); 			memcpy(buf,&ohci_confd, l); 			buf = (char *)buf + l; 			len -= l; 			l = min(len, USB_INTERFACE_DESCRIPTOR_SIZE); 			totlen += l; 			memcpy(buf,&ohci_ifcd, l); 			buf = (char *)buf + l; 			len -= l; 			l = min(len, USB_ENDPOINT_DESCRIPTOR_SIZE); 			totlen += l; 			memcpy(buf,&ohci_endpd, l); 			break; 		case UDESC_STRING: 			if (len ==
literal|0
argument|) 				break; 			*(u_int8_t *)buf =
literal|0
argument|; 			totlen =
literal|1
argument|; 			switch (value&
literal|0xff
argument|) { 			case
literal|1
argument|:
comment|/* Vendor */
argument|totlen = ohci_str(buf, len, sc->sc_vendor); 				break; 			case
literal|2
argument|:
comment|/* Product */
argument|totlen = ohci_str(buf, len,
literal|"OHCI root hub"
argument|); 				break; 			} 			break; 		default: 			r = USBD_IOERROR; 			goto ret; 		} 		break; 	case C(UR_GET_INTERFACE, UT_READ_INTERFACE): 		if (len>
literal|0
argument|) { 			*(u_int8_t *)buf =
literal|0
argument|; 			totlen =
literal|1
argument|; 		} 		break; 	case C(UR_GET_STATUS, UT_READ_DEVICE): 		if (len>
literal|1
argument|) { 			USETW(((usb_status_t *)buf)->wStatus,UDS_SELF_POWERED); 			totlen =
literal|2
argument|; 		} 		break; 	case C(UR_GET_STATUS, UT_READ_INTERFACE): 	case C(UR_GET_STATUS, UT_READ_ENDPOINT): 		if (len>
literal|1
argument|) { 			USETW(((usb_status_t *)buf)->wStatus,
literal|0
argument|); 			totlen =
literal|2
argument|; 		} 		break; 	case C(UR_SET_ADDRESS, UT_WRITE_DEVICE): 		if (value>= USB_MAX_DEVICES) { 			r = USBD_IOERROR; 			goto ret; 		} 		sc->sc_addr = value; 		break; 	case C(UR_SET_CONFIG, UT_WRITE_DEVICE): 		if (value !=
literal|0
argument|&& value !=
literal|1
argument|) { 			r = USBD_IOERROR; 			goto ret; 		} 		sc->sc_conf = value; 		break; 	case C(UR_SET_DESCRIPTOR, UT_WRITE_DEVICE): 		break; 	case C(UR_SET_FEATURE, UT_WRITE_DEVICE): 	case C(UR_SET_FEATURE, UT_WRITE_INTERFACE): 	case C(UR_SET_FEATURE, UT_WRITE_ENDPOINT): 		r = USBD_IOERROR; 		goto ret; 	case C(UR_SET_INTERFACE, UT_WRITE_INTERFACE): 		break; 	case C(UR_SYNCH_FRAME, UT_WRITE_ENDPOINT): 		break;
comment|/* Hub requests */
argument|case C(UR_CLEAR_FEATURE, UT_WRITE_CLASS_DEVICE): 		break; 	case C(UR_CLEAR_FEATURE, UT_WRITE_CLASS_OTHER): 		DPRINTFN(
literal|8
argument|, (
literal|"ohci_root_ctrl_control: UR_CLEAR_PORT_FEATURE "
literal|"port=%d feature=%d\n"
argument|, 			     index, value)); 		if (index<
literal|1
argument||| index> sc->sc_noport) { 			r = USBD_IOERROR; 			goto ret; 		} 		port = OHCI_RH_PORT_STATUS(index); 		switch(value) { 		case UHF_PORT_ENABLE: 			OWRITE4(sc, port, UPS_CURRENT_CONNECT_STATUS); 			break; 		case UHF_PORT_SUSPEND: 			OWRITE4(sc, port, UPS_OVERCURRENT_INDICATOR); 			break; 		case UHF_PORT_POWER: 			OWRITE4(sc, port, UPS_LOW_SPEED); 			break; 		case UHF_C_PORT_CONNECTION: 			OWRITE4(sc, port, UPS_C_CONNECT_STATUS<<
literal|16
argument|); 			break; 		case UHF_C_PORT_ENABLE: 			OWRITE4(sc, port, UPS_C_PORT_ENABLED<<
literal|16
argument|); 			break; 		case UHF_C_PORT_SUSPEND: 			OWRITE4(sc, port, UPS_C_SUSPEND<<
literal|16
argument|); 			break; 		case UHF_C_PORT_OVER_CURRENT: 			OWRITE4(sc, port, UPS_C_OVERCURRENT_INDICATOR<<
literal|16
argument|); 			break; 		case UHF_C_PORT_RESET: 			OWRITE4(sc, port, UPS_C_PORT_RESET<<
literal|16
argument|); 			break; 		default: 			r = USBD_IOERROR; 			goto ret; 		} 		switch(value) { 		case UHF_C_PORT_CONNECTION: 		case UHF_C_PORT_ENABLE: 		case UHF_C_PORT_SUSPEND: 		case UHF_C_PORT_OVER_CURRENT: 		case UHF_C_PORT_RESET:
comment|/* Enable RHSC interrupt if condition is cleared. */
argument|if ((OREAD4(sc, port)>>
literal|16
argument|) ==
literal|0
argument|) 				ohci_rhsc_able(sc,
literal|1
argument|); 			break; 		default: 			break; 		} 		break; 	case C(UR_GET_DESCRIPTOR, UT_READ_CLASS_DEVICE): 		if (value !=
literal|0
argument|) { 			r = USBD_IOERROR; 			goto ret; 		} 		v = OREAD4(sc, OHCI_RH_DESCRIPTOR_A); 		hubd = ohci_hubd; 		hubd.bNbrPorts = sc->sc_noport; 		USETW(hubd.wHubCharacteristics, 		      (v& OHCI_NPS ? UHD_PWR_NO_SWITCH :  		       v& OHCI_PSM ? UHD_PWR_GANGED : UHD_PWR_INDIVIDUAL)
comment|/* XXX overcurrent */
argument|); 		hubd.bPwrOn2PwrGood = OHCI_GET_POTPGT(v); 		v = OREAD4(sc, OHCI_RH_DESCRIPTOR_B); 		for (i =
literal|0
argument|, l = sc->sc_noport; l>
literal|0
argument|; i++, l -=
literal|8
argument|, v>>=
literal|8
argument|)  			hubd.DeviceRemovable[i++] = (u_int8_t)v; 		hubd.bDescLength = USB_HUB_DESCRIPTOR_SIZE + i; 		l = min(len, hubd.bDescLength); 		totlen = l; 		memcpy(buf,&hubd, l); 		break; 	case C(UR_GET_STATUS, UT_READ_CLASS_DEVICE): 		if (len !=
literal|4
argument|) { 			r = USBD_IOERROR; 			goto ret; 		} 		memset(buf,
literal|0
argument|, len);
comment|/* ? XXX */
argument|totlen = len; 		break; 	case C(UR_GET_STATUS, UT_READ_CLASS_OTHER): 		DPRINTFN(
literal|8
argument|,(
literal|"ohci_root_ctrl_transfer: get port status i=%d\n"
argument|, 			    index)); 		if (index<
literal|1
argument||| index> sc->sc_noport) { 			r = USBD_IOERROR; 			goto ret; 		} 		if (len !=
literal|4
argument|) { 			r = USBD_IOERROR; 			goto ret; 		} 		v = OREAD4(sc, OHCI_RH_PORT_STATUS(index)); 		DPRINTFN(
literal|8
argument|,(
literal|"ohci_root_ctrl_transfer: port status=0x%04x\n"
argument|, 			    v)); 		USETW(ps.wPortStatus, v); 		USETW(ps.wPortChange, v>>
literal|16
argument|); 		l = min(len, sizeof ps); 		memcpy(buf,&ps, l); 		totlen = l; 		break; 	case C(UR_SET_DESCRIPTOR, UT_WRITE_CLASS_DEVICE): 		r = USBD_IOERROR; 		goto ret; 	case C(UR_SET_FEATURE, UT_WRITE_CLASS_DEVICE): 		break; 	case C(UR_SET_FEATURE, UT_WRITE_CLASS_OTHER): 		if (index<
literal|1
argument||| index> sc->sc_noport) { 			r = USBD_IOERROR; 			goto ret; 		} 		port = OHCI_RH_PORT_STATUS(index); 		switch(value) { 		case UHF_PORT_ENABLE: 			OWRITE4(sc, port, UPS_PORT_ENABLED); 			break; 		case UHF_PORT_SUSPEND: 			OWRITE4(sc, port, UPS_SUSPEND); 			break; 		case UHF_PORT_RESET: 			DPRINTFN(
literal|5
argument|,(
literal|"ohci_root_ctrl_transfer: reset port %d\n"
argument|, 				    index)); 			OWRITE4(sc, port, UPS_RESET); 			for (i =
literal|0
argument|; i<
literal|10
argument|; i++) { 				usb_delay_ms(&sc->sc_bus,
literal|10
argument|); 				if ((OREAD4(sc, port)& UPS_RESET) ==
literal|0
argument|) 					break; 			} 			DPRINTFN(
literal|8
argument|,(
literal|"ohci port %d reset, status = 0x%04x\n"
argument|, 				    index, OREAD4(sc, port))); 			break; 		case UHF_PORT_POWER: 			DPRINTFN(
literal|2
argument|,(
literal|"ohci_root_ctrl_transfer: set port power "
literal|"%d\n"
argument|, index)); 			OWRITE4(sc, port, UPS_PORT_POWER); 			break; 		default: 			r = USBD_IOERROR; 			goto ret; 		} 		break; 	default: 		r = USBD_IOERROR; 		goto ret; 	} 	reqh->actlen = totlen; 	r = USBD_NORMAL_COMPLETION;  ret: 	reqh->status = r; 	usb_transfer_complete(reqh); 	return (USBD_IN_PROGRESS); }
comment|/* Abort a root control request. */
argument|void ohci_root_ctrl_abort(reqh) 	usbd_request_handle reqh; {
comment|/* Nothing to do, all transfers are synchronous. */
argument|}
comment|/* Close the root pipe. */
argument|void ohci_root_ctrl_close(pipe) 	usbd_pipe_handle pipe; { 	DPRINTF((
literal|"ohci_root_ctrl_close\n"
argument|));
comment|/* Nothing to do. */
argument|}  usbd_status ohci_root_intr_transfer(reqh) 	usbd_request_handle reqh; { 	usbd_status r;  	r = usb_insert_transfer(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	else 		return (ohci_root_intr_start(reqh)); }  usbd_status ohci_root_intr_start(reqh) 	usbd_request_handle reqh; { 	usbd_pipe_handle pipe = reqh->pipe; 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus;  	sc->sc_intrreqh = reqh;  	return (USBD_IN_PROGRESS); }
comment|/* Abort a root interrupt request. */
argument|void ohci_root_intr_abort(reqh) 	usbd_request_handle reqh; {
comment|/* No need to abort. */
argument|}
comment|/* Close the root pipe. */
argument|void ohci_root_intr_close(pipe) 	usbd_pipe_handle pipe; { 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus; 	 	DPRINTF((
literal|"ohci_root_intr_close\n"
argument|));  	sc->sc_intrreqh =
literal|0
argument|; }
comment|/************************/
argument|usbd_status ohci_device_ctrl_transfer(reqh) 	usbd_request_handle reqh; { 	usbd_status r;  	r = usb_insert_transfer(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	else 		return (ohci_device_ctrl_start(reqh)); }  usbd_status ohci_device_ctrl_start(reqh) 	usbd_request_handle reqh; { 	ohci_softc_t *sc = (ohci_softc_t *)reqh->pipe->device->bus; 	usbd_status r;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (!(reqh->rqflags& URQ_REQUEST)) {
comment|/* XXX panic */
argument|printf(
literal|"ohci_device_ctrl_transfer: not a request\n"
argument|); 		return (USBD_INVAL); 	}
endif|#
directive|endif
argument|r = ohci_device_request(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r);  	if (sc->sc_bus.use_polling) 		ohci_waitintr(sc, reqh); 	return (USBD_IN_PROGRESS); }
comment|/* Abort a device control request. */
argument|void ohci_device_ctrl_abort(reqh) 	usbd_request_handle reqh; { 	DPRINTF((
literal|"ohci_device_ctrl_abort: reqh=%p\n"
argument|, reqh)); 	ohci_abort_req(reqh, USBD_CANCELLED); }
comment|/* Close a device control pipe. */
argument|void ohci_device_ctrl_close(pipe) 	usbd_pipe_handle pipe; { 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus;  	DPRINTF((
literal|"ohci_device_ctrl_close: pipe=%p\n"
argument|, pipe)); 	ohci_close_pipe(pipe, sc->sc_ctrl_head); }
comment|/************************/
argument|void ohci_device_clear_toggle(pipe) 	usbd_pipe_handle pipe; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)pipe;  	opipe->sed->ed.ed_tailp&= LE(~OHCI_TOGGLECARRY); }  void ohci_noop(pipe) 	usbd_pipe_handle pipe; { }  usbd_status ohci_device_bulk_transfer(reqh) 	usbd_request_handle reqh; { 	usbd_status r;  	r = usb_insert_transfer(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	else 		return (ohci_device_bulk_start(reqh)); }  usbd_status ohci_device_bulk_start(reqh) 	usbd_request_handle reqh; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	usbd_device_handle dev = opipe->pipe.device; 	ohci_softc_t *sc = (ohci_softc_t *)dev->bus; 	int addr = dev->address; 	ohci_soft_td_t *xfer
argument_list|,
argument|*tail; 	ohci_soft_ed_t *sed; 	int s
argument_list|,
argument|len
argument_list|,
argument|isread
argument_list|,
argument|endpt;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (reqh->rqflags& URQ_REQUEST) {
comment|/* XXX panic */
argument|printf(
literal|"ohci_device_bulk_start: a request\n"
argument|); 		return (USBD_INVAL); 	}
endif|#
directive|endif
argument|len = reqh->length; 	endpt = reqh->pipe->endpoint->edesc->bEndpointAddress; 	isread = UE_GET_DIR(endpt) == UE_DIR_IN; 	sed = opipe->sed;  	DPRINTFN(
literal|4
argument|,(
literal|"ohci_device_bulk_start: reqh=%p len=%d isread=%d "
literal|"flags=%d endpt=%d\n"
argument|, reqh, len, isread, reqh->flags, 		    endpt));  	opipe->u.bulk.isread = isread; 	opipe->u.bulk.length = len;  	tail = ohci_alloc_std(sc); 	if (!tail) 		return (USBD_NOMEM); 	tail->reqh =
literal|0
argument|;
comment|/* Update device address */
argument|sed->ed.ed_flags = LE( 		(LE(sed->ed.ed_flags)& ~OHCI_ED_ADDRMASK) | 		OHCI_ED_SET_FA(addr));
comment|/* Set up data transaction */
argument|xfer = opipe->tail; 	xfer->td.td_flags = LE( 		(isread ? OHCI_TD_IN : OHCI_TD_OUT) | OHCI_TD_NOCC | 		OHCI_TD_SET_DI(
literal|1
argument|) | OHCI_TD_TOGGLE_CARRY | 		(reqh->flags& USBD_SHORT_XFER_OK ? OHCI_TD_R :
literal|0
argument|)); 	xfer->td.td_cbp = LE(DMAADDR(&reqh->dmabuf)); 	xfer->nexttd = tail; 	xfer->td.td_nexttd = LE(tail->physaddr); 	xfer->td.td_be = LE(LE(xfer->td.td_cbp) + len -
literal|1
argument|); 	xfer->len = len; 	xfer->reqh = reqh; 	xfer->flags = OHCI_CALL_DONE | OHCI_SET_LEN; 	reqh->hcpriv = xfer;  	DPRINTFN(
literal|4
argument|,(
literal|"ohci_device_bulk_start: ed_flags=0x%08x td_flags=0x%08x "
literal|"td_cbp=0x%08x td_be=0x%08x\n"
argument|, 		    (int)LE(sed->ed.ed_flags), (int)LE(xfer->td.td_flags), 		    (int)LE(xfer->td.td_cbp), (int)LE(xfer->td.td_be)));
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|4
argument|) { 		ohci_dump_ed(sed); 		ohci_dump_tds(xfer); 	}
endif|#
directive|endif
comment|/* Insert ED in schedule */
argument|s = splusb(); 	ohci_hash_add_td(sc, xfer); 	sed->ed.ed_tailp = LE(tail->physaddr); 	opipe->tail = tail; 	sed->ed.ed_flags&= LE(~OHCI_ED_SKIP); 	OWRITE4(sc, OHCI_COMMAND_STATUS, OHCI_BLF); 	if (reqh->timeout&& !sc->sc_bus.use_polling) {                 usb_timeout(ohci_timeout, reqh, 			    MS_TO_TICKS(reqh->timeout), reqh->timo_handle); 	}
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|5
argument|) { 		delay(
literal|5000
argument|); 		DPRINTF((
literal|"ohci_device_intr_transfer: status=%x\n"
argument|, 			 OREAD4(sc, OHCI_COMMAND_STATUS))); 		ohci_dump_ed(sed); 		ohci_dump_tds(xfer); 	}
endif|#
directive|endif
argument|splx(s);  	return (USBD_IN_PROGRESS); }  void ohci_device_bulk_abort(reqh) 	usbd_request_handle reqh; { 	DPRINTF((
literal|"ohci_device_bulk_abort: reqh=%p\n"
argument|, reqh)); 	ohci_abort_req(reqh, USBD_CANCELLED); }
comment|/*   * Close a device bulk pipe.  */
argument|void ohci_device_bulk_close(pipe) 	usbd_pipe_handle pipe; { 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus;  	DPRINTF((
literal|"ohci_device_bulk_close: pipe=%p\n"
argument|, pipe)); 	ohci_close_pipe(pipe, sc->sc_bulk_head); }
comment|/************************/
argument|usbd_status ohci_device_intr_transfer(reqh) 	usbd_request_handle reqh; { 	usbd_status r;  	r = usb_insert_transfer(reqh); 	if (r != USBD_NORMAL_COMPLETION) 		return (r); 	else 		return (ohci_device_intr_start(reqh)); }  usbd_status ohci_device_intr_start(reqh) 	usbd_request_handle reqh; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)reqh->pipe; 	usbd_device_handle dev = opipe->pipe.device; 	ohci_softc_t *sc = (ohci_softc_t *)dev->bus; 	ohci_soft_ed_t *sed = opipe->sed; 	ohci_soft_td_t *xfer
argument_list|,
argument|*tail; 	int len; 	int s;  	DPRINTFN(
literal|3
argument|, (
literal|"ohci_device_intr_transfer: reqh=%p len=%d "
literal|"flags=%d priv=%p\n"
argument|, 		     reqh, reqh->length, reqh->flags, reqh->priv));
ifdef|#
directive|ifdef
name|DIAGNOSTIC
argument|if (reqh->rqflags& URQ_REQUEST) 		panic(
literal|"ohci_device_intr_transfer: a request\n"
argument|);
endif|#
directive|endif
argument|len = reqh->length;  	xfer = opipe->tail; 	tail = ohci_alloc_std(sc); 	if (!tail) 		return (USBD_NOMEM); 	tail->reqh =
literal|0
argument|;  	xfer->td.td_flags = LE( 		OHCI_TD_IN | OHCI_TD_NOCC |  		OHCI_TD_SET_DI(
literal|1
argument|) | OHCI_TD_TOGGLE_CARRY); 	if (reqh->flags& USBD_SHORT_XFER_OK) 		xfer->td.td_flags |= LE(OHCI_TD_R); 	xfer->td.td_cbp = LE(DMAADDR(&reqh->dmabuf)); 	xfer->nexttd = tail; 	xfer->td.td_nexttd = LE(tail->physaddr); 	xfer->td.td_be = LE(LE(xfer->td.td_cbp) + len -
literal|1
argument|); 	xfer->len = len; 	xfer->reqh = reqh; 	xfer->flags = OHCI_CALL_DONE | OHCI_SET_LEN; 	reqh->hcpriv = xfer;
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug>
literal|5
argument|) { 		DPRINTF((
literal|"ohci_device_intr_transfer:\n"
argument|)); 		ohci_dump_ed(sed); 		ohci_dump_tds(xfer); 	}
endif|#
directive|endif
comment|/* Insert ED in schedule */
argument|s = splusb(); 	ohci_hash_add_td(sc, xfer); 	sed->ed.ed_tailp = LE(tail->physaddr); 	opipe->tail = tail; 	sed->ed.ed_flags&= LE(~OHCI_ED_SKIP);
if|#
directive|if
literal|0
argument|this goes wrong if we are too slow with dumping the TDs
ifdef|#
directive|ifdef
name|OHCI_DEBUG
argument|if (ohcidebug> 5) { 		delay(5000); 		DPRINTF(("ohci_device_intr_transfer: status=%x\n", 			 OREAD4(sc, OHCI_COMMAND_STATUS))); 		ohci_dump_ed(sed); 		ohci_dump_tds(xfer); 	}
endif|#
directive|endif
endif|#
directive|endif
argument|splx(s);  	return (USBD_IN_PROGRESS); }
comment|/* Abort a device control request. */
argument|void ohci_device_intr_abort(reqh) 	usbd_request_handle reqh; { 	if (reqh->pipe->intrreqh == reqh) { 		DPRINTF((
literal|"ohci_device_intr_abort: remove\n"
argument|)); 		reqh->pipe->intrreqh =
literal|0
argument|; 	} 	ohci_abort_req(reqh, USBD_CANCELLED); }
comment|/* Close a device interrupt pipe. */
argument|void ohci_device_intr_close(pipe) 	usbd_pipe_handle pipe; { 	struct ohci_pipe *opipe = (struct ohci_pipe *)pipe; 	ohci_softc_t *sc = (ohci_softc_t *)pipe->device->bus; 	int nslots = opipe->u.intr.nslots; 	int pos = opipe->u.intr.pos; 	int j; 	ohci_soft_ed_t *p
argument_list|,
argument|*sed = opipe->sed; 	int s;  	DPRINTFN(
literal|1
argument|,(
literal|"ohci_device_intr_close: pipe=%p nslots=%d pos=%d\n"
argument|, 		    pipe, nslots, pos)); 	s = splusb(); 	sed->ed.ed_flags |= LE(OHCI_ED_SKIP); 	if ((sed->ed.ed_tailp& LE(OHCI_TAILMASK)) !=  	    (sed->ed.ed_headp& LE(OHCI_TAILMASK))) 		usb_delay_ms(&sc->sc_bus,
literal|2
argument|);  	for (p = sc->sc_eds[pos]; p&& p->next != sed; p = p->next) 		; 	if (!p) 		panic(
literal|"ohci_device_intr_close: ED not found\n"
argument|); 	p->next = sed->next; 	p->ed.ed_nexted = sed->ed.ed_nexted; 	splx(s);  	for (j =
literal|0
argument|; j< nslots; j++) 		--sc->sc_bws[(pos * nslots + j) % OHCI_NO_INTRS];  	ohci_free_std(sc, opipe->tail); 	ohci_free_sed(sc, opipe->sed); }  usbd_status ohci_device_setintr(sc, opipe, ival) 	ohci_softc_t *sc; 	struct ohci_pipe *opipe; 	int ival; { 	int i
argument_list|,
argument|j
argument_list|,
argument|s
argument_list|,
argument|best; 	u_int npoll
argument_list|,
argument|slow
argument_list|,
argument|shigh
argument_list|,
argument|nslots; 	u_int bestbw
argument_list|,
argument|bw; 	ohci_soft_ed_t *hsed
argument_list|,
argument|*sed = opipe->sed;  	DPRINTFN(
literal|2
argument|, (
literal|"ohci_setintr: pipe=%p\n"
argument|, opipe)); 	if (ival ==
literal|0
argument|) { 		printf(
literal|"ohci_setintr: 0 interval\n"
argument|); 		return (USBD_INVAL); 	}  	npoll = OHCI_NO_INTRS; 	while (npoll> ival) 		npoll /=
literal|2
argument|; 	DPRINTFN(
literal|2
argument|, (
literal|"ohci_setintr: ival=%d npoll=%d\n"
argument|, ival, npoll));
comment|/* 	 * We now know which level in the tree the ED must go into. 	 * Figure out which slot has most bandwidth left over. 	 * Slots to examine: 	 * npoll 	 * 1	0 	 * 2	1 2 	 * 4	3 4 5 6 	 * 8	7 8 9 10 11 12 13 14 	 * N    (N-1) .. (N-1+N-1) 	 */
argument|slow = npoll-
literal|1
argument|; 	shigh = slow + npoll; 	nslots = OHCI_NO_INTRS / npoll; 	for (best = i = slow, bestbw = ~
literal|0
argument|; i< shigh; i++) { 		bw =
literal|0
argument|; 		for (j =
literal|0
argument|; j< nslots; j++) 			bw += sc->sc_bws[(i * nslots + j) % OHCI_NO_INTRS]; 		if (bw< bestbw) { 			best = i; 			bestbw = bw; 		} 	} 	DPRINTFN(
literal|2
argument|, (
literal|"ohci_setintr: best=%d(%d..%d) bestbw=%d\n"
argument|,  		     best, slow, shigh, bestbw));  	s = splusb(); 	hsed = sc->sc_eds[best]; 	sed->next = hsed->next; 	sed->ed.ed_nexted = hsed->ed.ed_nexted; 	hsed->next = sed; 	hsed->ed.ed_nexted = LE(sed->physaddr); 	splx(s);  	for (j =
literal|0
argument|; j< nslots; j++) 		++sc->sc_bws[(best * nslots + j) % OHCI_NO_INTRS]; 	opipe->u.intr.nslots = nslots; 	opipe->u.intr.pos = best;  	DPRINTFN(
literal|5
argument|, (
literal|"ohci_setintr: returns %p\n"
argument|, opipe)); 	return (USBD_NORMAL_COMPLETION); }
end_function

end_unit

