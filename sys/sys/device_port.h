begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * Copyright (c) 1999 Takanori Watanabe<takawata@jp.FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400001
end_if

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macro's to cope with the differences between operating systems and versions.   */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEVPORT_DEVICE
value|struct device
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVNAME
parameter_list|(
name|dev
parameter_list|)
value|(dev).dv_xname
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVUNIT
parameter_list|(
name|dev
parameter_list|)
value|(dev).dv_unit
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
comment|/*  * FreeBSD (compatibility for struct device)  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400001
end_if

begin_define
define|#
directive|define
name|DEVPORT_DEVICE
value|device_t
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVNAME
parameter_list|(
name|dev
parameter_list|)
value|device_get_name(dev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVUNIT
parameter_list|(
name|dev
parameter_list|)
value|device_get_unit(dev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_ALLOC_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|device_get_softc(dev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_GET_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|device_get_softc(dev)
end_define

begin_define
define|#
directive|define
name|UNCONF
value|1
end_define

begin_comment
comment|/* print " not configured\n" */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_DEVICE
value|struct device
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVNAME
parameter_list|(
name|dev
parameter_list|)
value|(dev).dv_xname
end_define

begin_define
define|#
directive|define
name|DEVPORT_DEVUNIT
parameter_list|(
name|dev
parameter_list|)
value|(dev).dv_unit
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEVPORT_ALLOCSOFTCFUNC
end_ifdef

begin_define
define|#
directive|define
name|DEVPORT_ALLOC_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|(DEVPORT_ALLOCSOFTCFUNC)((dev).dv_unit)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_ALLOC_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|DEVPORT_ALLOCSOFTCFUNC_is_not_defined_prior_than_device_port_h
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEVPORT_SOFTCARRAY
end_ifdef

begin_define
define|#
directive|define
name|DEVPORT_GET_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|(DEVPORT_SOFTCARRAY)[(dev).dv_unit]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_GET_SOFTC
parameter_list|(
name|dev
parameter_list|)
value|DEVPORT_SOFTCARRAY_is_not_defined_prior_than_device_port_h
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PC-Card device driver (compatibility for struct pccard_devinfo *)  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400001
end_if

begin_define
define|#
directive|define
name|DEVPORT_PDEVICE
value|device_t
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVUNIT
parameter_list|(
name|pdev
parameter_list|)
value|device_get_unit(pdev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVFLAGS
parameter_list|(
name|pdev
parameter_list|)
value|device_get_flags(pdev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVIOBASE
parameter_list|(
name|pdev
parameter_list|)
value|bus_get_resource_start(pdev, SYS_RES_IOPORT, 0)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVIRQ
parameter_list|(
name|pdev
parameter_list|)
value|bus_get_resource_start(pdev, SYS_RES_IRQ, 0)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVMADDR
parameter_list|(
name|pdev
parameter_list|)
value|bus_get_resource_start(pdev, SYS_RES_MEMORY, 0)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVALLOC_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|device_get_softc(pdev)
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVGET_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|device_get_softc(pdev)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_PDEVICE
value|struct pccard_devinfo *
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVUNIT
parameter_list|(
name|pdev
parameter_list|)
value|(pdev)->pd_unit
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVFLAGS
parameter_list|(
name|pdev
parameter_list|)
value|(pdev)->pd_flags
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVIOBASE
parameter_list|(
name|pdev
parameter_list|)
value|(pdev)->pd_iobase
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVIRQ
parameter_list|(
name|pdev
parameter_list|)
value|(pdev)->pd_irq
end_define

begin_define
define|#
directive|define
name|DEVPORT_PDEVMADDR
parameter_list|(
name|pdev
parameter_list|)
value|(pdev)->pd_maddr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEVPORT_ALLOCSOFTCFUNC
end_ifdef

begin_define
define|#
directive|define
name|DEVPORT_PDEVALLOC_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|(DEVPORT_ALLOCSOFTCFUNC)((pdev)->pd_unit)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_PDEVALLOC_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|DEVPORT_ALLOCSOFTCFUNC_is_not_defined_prior_than_device_port_h
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEVPORT_SOFTCARRAY
end_ifdef

begin_define
define|#
directive|define
name|DEVPORT_PDEVGET_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|(DEVPORT_SOFTCARRAY)[(pdev)->pd_unit]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVPORT_PDEVGET_SOFTC
parameter_list|(
name|pdev
parameter_list|)
value|DEVPORT_SOFTCARRAY_is_not_defined_prior_than_device_port_h
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

end_unit

