begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb_port.h,v 1.23 2000/03/24 22:03:32 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/*   * Macro's to cope with the differences between operating systems.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_comment
comment|/*  * NetBSD  */
end_comment

begin_include
include|#
directive|include
file|"opt_usbverbose.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USB_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|UHID_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|OHCI_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UGEN_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UHCI_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UHUB_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|ULPT_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UAUDIO_DEBUG
value|1
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

begin_typedef
typedef|typedef
name|struct
name|proc
modifier|*
name|usb_proc_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|device
modifier|*
name|device_ptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USBBASEDEVICE
value|struct device
end_define

begin_define
define|#
directive|define
name|USBDEV
parameter_list|(
name|bdev
parameter_list|)
value|(&(bdev))
end_define

begin_define
define|#
directive|define
name|USBDEVNAME
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_xname)
end_define

begin_define
define|#
directive|define
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_unit)
end_define

begin_define
define|#
directive|define
name|USBDEVPTRNAME
parameter_list|(
name|bdevptr
parameter_list|)
value|((bdevptr)->dv_xname)
end_define

begin_define
define|#
directive|define
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_unit)
end_define

begin_define
define|#
directive|define
name|DECLARE_USB_DMA_T
define|\
value|struct usb_dma_block; \ 	typedef struct { \ 		struct usb_dma_block *block; \ 		u_int offs; \ 	} usb_dma_t
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
value|callout_handle_init(&(h))
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
value|((h) = timeout((f), (d), (t)))
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
value|untimeout((f), (d))
end_define

begin_typedef
typedef|typedef
name|int
name|usb_malloc_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|logprintf
value|printf
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER
parameter_list|(
name|dname
parameter_list|)
define|\
value|int __CONCAT(dname,_match)(struct device *, struct cfdata *, void *); \ void __CONCAT(dname,_attach)(struct device *, struct device *, void *); \ int __CONCAT(dname,_detach)(struct device *, int); \ int __CONCAT(dname,_activate)(struct device *, enum devact); \ \ extern struct cfdriver __CONCAT(dname,_cd); \ \ struct cfattach __CONCAT(dname,_ca) = { \ 	sizeof(struct __CONCAT(dname,_softc)), \ 	__CONCAT(dname,_match), \ 	__CONCAT(dname,_attach), \ 	__CONCAT(dname,_detach), \ 	__CONCAT(dname,_activate), \ }
end_define

begin_define
define|#
directive|define
name|USB_MATCH
parameter_list|(
name|dname
parameter_list|)
define|\
value|int \ __CONCAT(dname,_match)(parent, match, aux) \ 	struct device *parent; \ 	struct cfdata *match; \ 	void *aux;
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
value|struct usb_attach_arg *uaa = aux
end_define

begin_define
define|#
directive|define
name|USB_MATCH_SETUP
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|USB_ATTACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|void \ __CONCAT(dname,_attach)(parent, self, aux) \ 	struct device *parent; \ 	struct device *self; \ 	void *aux;
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
value|struct __CONCAT(dname,_softc) *sc = \ 		(struct __CONCAT(dname,_softc) *)self; \ 	struct usb_attach_arg *uaa = aux
end_define

begin_comment
comment|/* Returns from attach */
end_comment

begin_define
define|#
directive|define
name|USB_ATTACH_ERROR_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SUCCESS_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SETUP
value|printf("\n")
end_define

begin_define
define|#
directive|define
name|USB_DETACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|int \ __CONCAT(dname,_detach)(self, flags) \ 	struct device *self; \ 	int flags;
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
value|struct __CONCAT(dname,_softc) *sc = \ 		(struct __CONCAT(dname,_softc) *)self
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
value|if (unit>= __CONCAT(dname,_cd).cd_ndevs) \ 		return (ENXIO); \ 	sc = __CONCAT(dname,_cd).cd_devs[unit]; \ 	if (!sc) \ 		return (ENXIO)
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
value|sc = __CONCAT(dname,_cd).cd_devs[unit]
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
value|(config_found_sm(parent, args, print, sub))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif

begin_comment
comment|/*  * OpenBSD  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|UHID_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|OHCI_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UGEN_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UHCI_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UHUB_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|ULPT_DEBUG
value|1
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

begin_typedef
typedef|typedef
name|struct
name|proc
modifier|*
name|usb_proc_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy((s),(d),(l))
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|l
parameter_list|)
value|bzero((d),(l))
end_define

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|x
parameter_list|)
value|swap32(x)
end_define

begin_define
define|#
directive|define
name|kthread_create1
value|kthread_create
end_define

begin_define
define|#
directive|define
name|kthread_create
value|kthread_create_deferred
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
name|int
name|usb_malloc_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|usbpoll
value|usbselect
end_define

begin_define
define|#
directive|define
name|uhidpoll
value|uhidselect
end_define

begin_define
define|#
directive|define
name|ugenpoll
value|ugenselect
end_define

begin_define
define|#
directive|define
name|PWR_RESUME
value|0
end_define

begin_define
define|#
directive|define
name|PWR_SUSPEND
value|1
end_define

begin_typedef
typedef|typedef
name|struct
name|device
name|device_ptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USBBASEDEVICE
value|struct device
end_define

begin_define
define|#
directive|define
name|USBDEV
parameter_list|(
name|bdev
parameter_list|)
value|(&(bdev))
end_define

begin_define
define|#
directive|define
name|USBDEVNAME
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_xname)
end_define

begin_define
define|#
directive|define
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_unit)
end_define

begin_define
define|#
directive|define
name|USBDEVPTRNAME
parameter_list|(
name|bdevptr
parameter_list|)
value|((bdevptr)->dv_xname)
end_define

begin_define
define|#
directive|define
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_unit)
end_define

begin_define
define|#
directive|define
name|DECLARE_USB_DMA_T
define|\
value|struct usb_dma_block; \ 	typedef struct { \ 		struct usb_dma_block *block; \ 		u_int offs; \ 	} usb_dma_t
end_define

begin_typedef
typedef|typedef
name|char
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
value|timeout((f), (d), (t))
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
value|untimeout((f), (d))
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER
parameter_list|(
name|dname
parameter_list|)
define|\
value|int __CONCAT(dname,_match)(struct device *, void *, void *); \ void __CONCAT(dname,_attach)(struct device *, struct device *, void *); \ int __CONCAT(dname,_detach)(struct device *, int); \ int __CONCAT(dname,_activate)(struct device *, enum devact); \ \ struct cfdriver __CONCAT(dname,_cd) = { \ 	NULL, #dname, DV_DULL \ }; \ \ struct cfattach __CONCAT(dname,_ca) = { \ 	sizeof(struct __CONCAT(dname,_softc)), \ 	__CONCAT(dname,_match), \ 	__CONCAT(dname,_attach), \ 	__CONCAT(dname,_detach), \ 	__CONCAT(dname,_activate), \ }
end_define

begin_define
define|#
directive|define
name|USB_MATCH
parameter_list|(
name|dname
parameter_list|)
define|\
value|int \ __CONCAT(dname,_match)(parent, match, aux) \ 	struct device *parent; \ 	void *match; \ 	void *aux;
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
value|struct usb_attach_arg *uaa = aux
end_define

begin_define
define|#
directive|define
name|USB_MATCH_SETUP
end_define

begin_comment
comment|/* nop */
end_comment

begin_define
define|#
directive|define
name|USB_ATTACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|void \ __CONCAT(dname,_attach)(parent, self, aux) \ 	struct device *parent; \ 	struct device *self; \ 	void *aux;
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
value|struct __CONCAT(dname,_softc) *sc = \ 		(struct __CONCAT(dname,_softc) *)self; \ 	struct usb_attach_arg *uaa = aux
end_define

begin_comment
comment|/* Returns from attach */
end_comment

begin_define
define|#
directive|define
name|USB_ATTACH_ERROR_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SUCCESS_RETURN
value|return
end_define

begin_define
define|#
directive|define
name|USB_ATTACH_SETUP
value|printf("\n")
end_define

begin_define
define|#
directive|define
name|USB_DETACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|int \ __CONCAT(dname,_detach)(self, flags) \ 	struct device *self; \ 	int flags;
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
value|struct __CONCAT(dname,_softc) *sc = \ 		(struct __CONCAT(dname,_softc) *)self
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
value|if (unit>= __CONCAT(dname,_cd).cd_ndevs) \ 		return (ENXIO); \ 	sc = __CONCAT(dname,_cd).cd_devs[unit]; \ 	if (!sc) \ 		return (ENXIO)
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
value|sc = __CONCAT(dname,_cd).cd_devs[unit]
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
value|(config_found_sm(parent, args, print, sub))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/*  * FreeBSD  */
end_comment

begin_include
include|#
directive|include
file|"opt_usb.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBDEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBHC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USBVERBOSE
end_define

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
name|USBDEVUNIT
parameter_list|(
name|bdev
parameter_list|)
value|device_get_unit(bdev)
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
name|DECLARE_USB_DMA_T
value|typedef char * usb_dma_t
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

begin_comment
comment|/* XXX Change this when FreeBSD has memset */
end_comment

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy((s),(d),(l))
end_define

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|l
parameter_list|)
value|bzero((d),(l))
end_define

begin_define
define|#
directive|define
name|kthread_create1
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
value|kthread_create((f), (s), (p), RFHIGHPID, (a0), (a1))
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
name|PWR_RESUME
value|0
end_define

begin_define
define|#
directive|define
name|PWR_SUSPEND
value|1
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
value|Static device_probe_t __CONCAT(dname,_match); \ Static device_attach_t __CONCAT(dname,_attach); \ Static device_detach_t __CONCAT(dname,_detach); \ \ Static devclass_t __CONCAT(dname,_devclass); \ \ Static device_method_t __CONCAT(dname,_methods)[] = { \         DEVMETHOD(device_probe, __CONCAT(dname,_match)), \         DEVMETHOD(device_attach, __CONCAT(dname,_attach)), \         DEVMETHOD(device_detach, __CONCAT(dname,_detach)), \ 	init, \         {0,0} \ }; \ \ Static driver_t __CONCAT(dname,_driver) = { \         #dname, \         __CONCAT(dname,_methods), \         sizeof(struct __CONCAT(dname,_softc)) \ }; \ MODULE_DEPEND(dname, usb, 1, 1, 1)
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
value|Static int \ __CONCAT(dname,_match)(device_t self)
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
value|Static int \ __CONCAT(dname,_attach)(device_t self)
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
value|sc->sc_dev = self; \ 	device_set_desc_copy(self, devinfo)
end_define

begin_define
define|#
directive|define
name|USB_DETACH
parameter_list|(
name|dname
parameter_list|)
define|\
value|Static int \ __CONCAT(dname,_detach)(device_t self)
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
value|sc = devclass_get_softc(__CONCAT(dname,_devclass), unit); \ 	if (!sc) \ 		return (ENXIO)
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

begin_comment
comment|/* XXX In FreeBSD SIMPLEQ_REMOVE_HEAD only removes the head element.  */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_REMOVE_HEAD
parameter_list|(
name|h
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|do {				\ 		if ( (e) != SIMPLEQ_FIRST((h)) )			\ 			panic("Removing other than first element");	\ 		STAILQ_REMOVE_HEAD(h, f);				\ } while (0)
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
comment|/* __FreeBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_PORT_H */
end_comment

end_unit

