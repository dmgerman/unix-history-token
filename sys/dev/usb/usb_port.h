begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb_port.h,v 1.5 1999/01/08 11:58:25 augustss Exp $	*/
end_comment

begin_comment
comment|/*	FreeBSD $Id: usb_port.h,v 1.8 1999/01/07 23:31:38 n_hibma Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Macro's to cope with the differences between operating systems.  */
end_comment

begin_comment
comment|/*  * NetBSD  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_usbverbose.h"
end_include

begin_define
define|#
directive|define
name|USBDEVNAME
parameter_list|(
name|bdev
parameter_list|)
value|((bdev).dv_xname)
end_define

begin_typedef
typedef|typedef
name|struct
name|device
name|bdevice
typedef|;
end_typedef

begin_comment
comment|/* base device */
end_comment

begin_define
define|#
directive|define
name|usb_timeout
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|)
value|timeout((f), (d), (t))
end_define

begin_define
define|#
directive|define
name|usb_untimeout
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|)
value|untimeout((f), (d))
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER_NAME_INIT
parameter_list|(
name|_1
parameter_list|,
name|dname
parameter_list|,
name|_2
parameter_list|)
define|\
value|int __CONCAT(dname,_match) __P((struct device *, struct cfdata *, void *)); \ void __CONCAT(dname,_attach) __P((struct device *, struct device *, void *)); \ \ extern struct cfdriver __CONCAT(dname,_cd); \ \ struct cfattach __CONCAT(dname,_ca) = { \ 	sizeof(struct __CONCAT(dname,_softc)), \ 	__CONCAT(dname,_match), \ 	__CONCAT(dname,_attach) \ }
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
name|USB_GET_SC_OPEN
parameter_list|(
name|dname
parameter_list|,
name|unit
parameter_list|,
name|sc
parameter_list|)
define|\
value|struct __CONCAT(dname,_softc) *sc; \ 	if (unit>= __CONCAT(dname,_cd).cd_ndevs) \ 		return (ENXIO); \ 	sc = __CONCAT(dname,_cd).cd_devs[unit]; \ 	if (!sc) \ 		return (ENXIO)
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
value|struct __CONCAT(dname,_softc) *sc = __CONCAT(dname,_cd).cd_devs[unit]
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
value|((dev)->softc = config_found_sm(parent, args, print, sub))
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

begin_comment
comment|/*  * The following is not a type def to avoid error messages  * because of includes in the wrong order.  */
end_comment

begin_define
define|#
directive|define
name|bdevice
value|device_t
end_define

begin_define
define|#
directive|define
name|USBDEVNAME
parameter_list|(
name|bdev
parameter_list|)
value|usbd_devname(&bdev)
end_define

begin_comment
comment|/* XXX Change this when FreeBSD has memset  */
end_comment

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|do{			\ 		if ((v) == 0)		\ 			bzero((d), (s));	\ 		else			\ 			panic("Non zero filler for memset, cannot handle!"); \ 		} while (0)
end_define

begin_define
define|#
directive|define
name|usb_timeout
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|,
name|h
parameter_list|)
value|((h) = timeout((f), (d), (t)))
end_define

begin_define
define|#
directive|define
name|usb_untimeout
parameter_list|(
name|f
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|)
value|untimeout((f), (d), (h))
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER_NAME_INIT
parameter_list|(
name|name
parameter_list|,
name|dname
parameter_list|,
name|init
modifier|...
parameter_list|)
define|\
value|static device_probe_t __CONCAT(dname,_match); \ static device_attach_t __CONCAT(dname,_attach); \ static device_detach_t __CONCAT(dname,_detach); \ \ static devclass_t __CONCAT(dname,_devclass); \ \ static device_method_t __CONCAT(dname,_methods)[] = { \         DEVMETHOD(device_probe, __CONCAT(dname,_match)), \         DEVMETHOD(device_attach, __CONCAT(dname,_attach)), \         DEVMETHOD(device_detach, __CONCAT(dname,_detach)), \ 	init, \         {0,0} \ }; \ \ static driver_t __CONCAT(dname,_driver) = { \         name, \         __CONCAT(dname,_methods), \         DRIVER_TYPE_MISC, \         sizeof(struct __CONCAT(dname,_softc)) \ }
end_define

begin_define
define|#
directive|define
name|USB_MATCH
parameter_list|(
name|dname
parameter_list|)
define|\
value|static int \ __CONCAT(dname,_match)(device_t device)
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
value|struct usb_attach_arg *uaa = device_get_ivars(device)
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
value|usbd_device_set_desc(self, devinfo); \ 	sc->sc_dev = self
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
value|struct __CONCAT(dname,_softc) *sc = \ 		devclass_get_softc(__CONCAT(dname,_devclass), unit); \ 	if (!sc) \ 		return (ENXIO)
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
value|struct __CONCAT(dname,_softc) *sc = \ 		devclass_get_softc(__CONCAT(dname,_devclass), unit)
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
value|(device_probe_and_attach((bdev)) == 0 ? ((dev)->softc = (bdev)) : 0)
end_define

begin_comment
comment|/* conversion from one type of queue to the other */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_REMOVE_HEAD
value|STAILQ_REMOVE_HEAD_UNTIL
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
name|SIMPLEQ_ENTRY
value|STAILQ_ENTRY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER_NAME
parameter_list|(
name|name
parameter_list|,
name|dname
parameter_list|)
define|\
value|USB_DECLARE_DRIVER_NAME_INIT(#name, dname, {0,0} )
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER_INIT
parameter_list|(
name|dname
parameter_list|,
name|init
parameter_list|)
define|\
value|USB_DECLARE_DRIVER_NAME_INIT(#dname, dname, init )
end_define

begin_define
define|#
directive|define
name|USB_DECLARE_DRIVER
parameter_list|(
name|dname
parameter_list|)
define|\
value|USB_DECLARE_DRIVER_NAME_INIT(#dname, dname, {0,0} )
end_define

end_unit

