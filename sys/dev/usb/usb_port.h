begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: usb_port.h,v 1.18 2000/09/06 22:42:10 rahnds Exp $ */
end_comment

begin_comment
comment|/*	$NetBSD: usb_port.h,v 1.54 2002/03/28 21:49:19 ichiro Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$       */
end_comment

begin_comment
comment|/* Also already merged from NetBSD:  *	$NetBSD: usb_port.h,v 1.57 2002/09/27 20:42:01 thorpej Exp $  *	$NetBSD: usb_port.h,v 1.58 2002/10/01 01:25:26 thorpej Exp $  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_PORT_H
end_ifndef

begin_define
define|#
directive|define
name|_USB_PORT_H
end_define

begin_comment
comment|/*  * Macro's to cope with the differences between operating systems.  */
end_comment

begin_comment
comment|/*  * FreeBSD  */
end_comment

begin_comment
comment|/* We don't use the soft interrupt code in FreeBSD. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|USB_USE_SOFTINTR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Static
value|static
end_define

begin_define
define|#
directive|define
name|device_ptr_t
value|device_t
end_define

begin_define
define|#
directive|define
name|USBBASEDEVICE
value|device_t
end_define

begin_define
define|#
directive|define
name|USBDEV
parameter_list|(
name|bdev
parameter_list|)
value|(bdev)
end_define

begin_define
define|#
directive|define
name|USBDEVNAME
parameter_list|(
name|bdev
parameter_list|)
value|device_get_nameunit(bdev)
end_define

begin_define
define|#
directive|define
name|USBDEVPTRNAME
parameter_list|(
name|bdev
parameter_list|)
value|device_get_nameunit(bdev)
end_define

begin_define
define|#
directive|define
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|device_get_unit(bdev)
end_define

begin_define
define|#
directive|define
name|USBGETSOFTC
parameter_list|(
name|bdev
parameter_list|)
value|(device_get_softc(bdev))
end_define

begin_define
define|#
directive|define
name|DECLARE_USB_DMA_T
define|\
value|struct usb_dma_block; \ 	typedef struct { \ 		struct usb_dma_block *block; \ 		u_int offs; \ 		u_int len; \ 	} usb_dma_t
end_define

begin_typedef
typedef|typedef
name|struct
name|thread
modifier|*
name|usb_proc_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|uio_procp
value|uio_td
end_define

begin_define
define|#
directive|define
name|usb_kthread_create1
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|a0
parameter_list|,
name|a1
parameter_list|)
define|\
value|kthread_create((f), (s), (p), RFHIGHPID, 0, (a0), (a1))
end_define

begin_define
define|#
directive|define
name|usb_kthread_create2
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|a0
parameter_list|)
define|\
value|kthread_create((f), (s), (p), RFHIGHPID, 0, (a0))
end_define

begin_define
define|#
directive|define
name|usb_kthread_create
value|kthread_create
end_define

begin_define
define|#
directive|define
name|config_pending_incr
parameter_list|()
end_define

begin_define
define|#
directive|define
name|config_pending_decr
parameter_list|()
end_define

begin_typedef
typedef|typedef
name|struct
name|callout
name|usb_callout_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|usb_callout_init
parameter_list|(
name|h
parameter_list|)
value|callout_init(&(h), 0)
end_define

begin_define
define|#
directive|define
name|usb_callout
parameter_list|(
name|h
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|d
parameter_list|)
value|callout_reset(&(h), (t), (f), (d))
end_define

begin_define
define|#
directive|define
name|usb_uncallout
parameter_list|(
name|h
parameter_list|,
name|f
parameter_list|,
name|d
parameter_list|)
value|callout_stop(&(h))
end_define

begin_define
define|#
directive|define
name|usb_uncallout_drain
parameter_list|(
name|h
parameter_list|,
name|f
parameter_list|,
name|d
parameter_list|)
value|callout_drain(&(h))
end_define

begin_define
define|#
directive|define
name|clalloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|,
name|x
parameter_list|)
value|(clist_alloc_cblocks((p), (s), (s)), 0)
end_define

begin_define
define|#
directive|define
name|clfree
parameter_list|(
name|p
parameter_list|)
value|clist_free_cblocks((p))
end_define

begin_define
define|#
directive|define
name|config_detach
parameter_list|(
name|dev
parameter_list|,
name|flag
parameter_list|)
define|\
value|do { \ 		device_detach(dev); \ 		free(device_get_ivars(dev), M_USB); \ 		device_delete_child(device_get_parent(dev), dev); \ 	} while (0);
end_define

begin_typedef
typedef|typedef
name|struct
name|malloc_type
modifier|*
name|usb_malloc_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER_INIT
parameter_list|(
name|dname
parameter_list|,
name|init
modifier|...
parameter_list|)
define|\
value|static device_probe_t __CONCAT(dname,_match); \ static device_attach_t __CONCAT(dname,_attach); \ static device_detach_t __CONCAT(dname,_detach); \ \ static devclass_t __CONCAT(dname,_devclass); \ \ static device_method_t __CONCAT(dname,_methods)[] = { \         DEVMETHOD(device_probe, __CONCAT(dname,_match)), \         DEVMETHOD(device_attach, __CONCAT(dname,_attach)), \         DEVMETHOD(device_detach, __CONCAT(dname,_detach)), \ 	init, \         {0,0} \ }; \ \ static driver_t __CONCAT(dname,_driver) = { \         #dname, \         __CONCAT(dname,_methods), \         sizeof(struct __CONCAT(dname,_softc)) \ }; \ MODULE_DEPEND(dname, usb, 1, 1, 1)
end_define

begin_define
define|#
directive|define
name|METHODS_NONE
value|{0,0}
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER
parameter_list|(
name|dname
parameter_list|)
value|USB_DECLARE_DRIVER_INIT(dname, METHODS_NONE)
end_define

begin_define
define|#
directive|define
name|USB_MATCH
parameter_list|(
name|dname
parameter_list|)
define|\
value|static int \ __CONCAT(dname,_match)(device_t self)
end_define

begin_define
define|#
directive|define
name|USB_MATCH_START
parameter_list|(
name|dname
parameter_list|,
name|uaa
parameter_list|)
define|\
value|struct usb_attach_arg *uaa = device_get_ivars(self)
end_define

begin_define
define|#
directive|define
name|USB_MATCH_SETUP
define|\
value|sc->sc_dev = self
end_define

begin_define
define|#
directive|define
name|USB_ATTACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|static int \ __CONCAT(dname,_attach)(device_t self)
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_START
parameter_list|(
name|dname
parameter_list|,
name|sc
parameter_list|,
name|uaa
parameter_list|)
define|\
value|struct __CONCAT(dname,_softc) *sc = device_get_softc(self); \         struct usb_attach_arg *uaa = device_get_ivars(self)
end_define

begin_comment
comment|/* Returns from attach */
end_comment

begin_define
define|#
directive|define
name|USB_ATTACH_ERROR_RETURN
value|return ENXIO
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SUCCESS_RETURN
value|return 0
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SETUP
define|\
value|sc->sc_dev = self; \  #define USB_DETACH(dname) \ static int \ __CONCAT(dname,_detach)(device_t self)
end_define

begin_define
define|#
directive|define
name|USB_DETACH_START
parameter_list|(
name|dname
parameter_list|,
name|sc
parameter_list|)
define|\
value|struct __CONCAT(dname,_softc) *sc = device_get_softc(self)
end_define

begin_define
define|#
directive|define
name|USB_GET_SC_OPEN
parameter_list|(
name|dname
parameter_list|,
name|unit
parameter_list|,
name|sc
parameter_list|)
define|\
value|sc = devclass_get_softc(__CONCAT(dname,_devclass), unit); \ 	if (sc == NULL) \ 		return (ENXIO)
end_define

begin_define
define|#
directive|define
name|USB_GET_SC
parameter_list|(
name|dname
parameter_list|,
name|unit
parameter_list|,
name|sc
parameter_list|)
define|\
value|sc = devclass_get_softc(__CONCAT(dname,_devclass), unit)
end_define

begin_define
define|#
directive|define
name|USB_DO_ATTACH
parameter_list|(
name|dev
parameter_list|,
name|bdev
parameter_list|,
name|parent
parameter_list|,
name|args
parameter_list|,
name|print
parameter_list|,
name|sub
parameter_list|)
define|\
value|(device_probe_and_attach((bdev)) == 0 ? (bdev) : 0)
end_define

begin_comment
comment|/* conversion from one type of queue to the other */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_REMOVE_HEAD
value|STAILQ_REMOVE_HEAD
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INSERT_HEAD
value|STAILQ_INSERT_HEAD
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INSERT_TAIL
value|STAILQ_INSERT_TAIL
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_NEXT
value|STAILQ_NEXT
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_FIRST
value|STAILQ_FIRST
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_HEAD
value|STAILQ_HEAD
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_EMPTY
value|STAILQ_EMPTY
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_FOREACH
value|STAILQ_FOREACH
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INIT
value|STAILQ_INIT
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_HEAD_INITIALIZER
value|STAILQ_HEAD_INITIALIZER
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_ENTRY
value|STAILQ_ENTRY
end_define

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_comment
comment|/* #define logprintf(args...)	log(LOG_DEBUG, args) */
end_comment

begin_define
define|#
directive|define
name|logprintf
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_PORT_H */
end_comment

end_unit

