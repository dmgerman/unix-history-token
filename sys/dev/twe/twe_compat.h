begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2003 Paul Saab  * Copyright (c) 2003 Vinod Kashyap  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Portability and compatibility interfaces.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/******************************************************************************  * FreeBSD  */
end_comment

begin_define
define|#
directive|define
name|TWE_SUPPORTED_PLATFORM
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom_disk.h>
end_include

begin_define
define|#
directive|define
name|TWE_DRIVER_NAME
value|twe
end_define

begin_define
define|#
directive|define
name|TWED_DRIVER_NAME
value|twed
end_define

begin_define
define|#
directive|define
name|TWE_MALLOC_CLASS
value|M_TWE
end_define

begin_comment
comment|/*   * Wrappers for bus-space actions  */
end_comment

begin_define
define|#
directive|define
name|TWE_CONTROL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((sc)->twe_io, 0x0, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_STATUS
parameter_list|(
name|sc
parameter_list|)
value|(u_int32_t)bus_read_4((sc)->twe_io, 0x4)
end_define

begin_define
define|#
directive|define
name|TWE_COMMAND_QUEUE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((sc)->twe_io, 0x8, (u_int32_t)val)
end_define

begin_define
define|#
directive|define
name|TWE_RESPONSE_QUEUE
parameter_list|(
name|sc
parameter_list|)
value|(TWE_Response_Queue)bus_read_4((sc)->twe_io, 0xc)
end_define

begin_comment
comment|/*  * FreeBSD-specific softc elements  */
end_comment

begin_define
define|#
directive|define
name|TWE_PLATFORM_SOFTC
define|\
value|bus_dmamap_t		twe_cmdmap;
comment|/* DMA map for command */
value|\     u_int32_t			twe_cmdphys;
comment|/* address of command in controller space */
value|\     device_t			twe_dev;
comment|/* bus device */
value|\     struct cdev *twe_dev_t;
comment|/* control device */
value|\     struct resource		*twe_io;
comment|/* register interface window */
value|\     bus_dma_tag_t		twe_parent_dmat;
comment|/* parent DMA tag */
value|\     bus_dma_tag_t		twe_buffer_dmat;
comment|/* data buffer DMA tag */
value|\     bus_dma_tag_t		twe_cmd_dmat;
comment|/* command buffer DMA tag */
value|\     bus_dma_tag_t		twe_immediate_dmat;
comment|/* command buffer DMA tag */
value|\     struct resource		*twe_irq;
comment|/* interrupt */
value|\     void			*twe_intr;
comment|/* interrupt handle */
value|\     struct intr_config_hook	twe_ich;
comment|/* delayed-startup hook */
value|\     void			*twe_cmd;
comment|/* command structures */
value|\     void			*twe_immediate;
comment|/* immediate commands */
value|\     bus_dmamap_t		twe_immediate_map;					\     struct mtx			twe_io_lock;						\     struct sx			twe_config_lock;
end_define

begin_comment
comment|/*  * FreeBSD-specific request elements  */
end_comment

begin_define
define|#
directive|define
name|TWE_PLATFORM_REQUEST
define|\
value|bus_dmamap_t		tr_dmamap;
comment|/* DMA map for data */
value|\     u_int32_t			tr_dataphys;
end_define

begin_comment
comment|/* data buffer base address in controller space */
end_comment

begin_comment
comment|/*  * Output identifying the controller/disk  */
end_comment

begin_define
define|#
directive|define
name|twe_printf
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(sc->twe_dev, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|twed_printf
parameter_list|(
name|twed
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(twed->twed_dev, fmt , ##args)
end_define

begin_define
define|#
directive|define
name|TWE_IO_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->twe_io_lock)
end_define

begin_define
define|#
directive|define
name|TWE_IO_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->twe_io_lock)
end_define

begin_define
define|#
directive|define
name|TWE_IO_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->twe_io_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|TWE_CONFIG_LOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xlock(&(sc)->twe_config_lock)
end_define

begin_define
define|#
directive|define
name|TWE_CONFIG_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|sx_xunlock(&(sc)->twe_config_lock)
end_define

begin_define
define|#
directive|define
name|TWE_CONFIG_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|sx_assert(&(sc)->twe_config_lock, SA_XLOCKED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TWE_SUPPORTED_PLATFORM
end_ifndef

begin_error
error|#
directive|error
error|platform not supported
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

