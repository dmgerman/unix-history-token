begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/hptrr/hptrr_config.h>
end_include

begin_comment
comment|/* $Id: os_bsd.h,v 1.18 2006/04/11 08:19:02 gmm Exp $  *  * HighPoint RAID Driver for FreeBSD  * Copyright (C) 2005 HighPoint Technologies, Inc. All Rights Reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OS_BSD_H
end_ifndef

begin_define
define|#
directive|define
name|_OS_BSD_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DBG
end_ifndef

begin_define
define|#
directive|define
name|DBG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/*to support DELAY function under 4.x BSD versions*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<=
literal|500043
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/devicestat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_ccb.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_sim.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|500043
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/bus_private.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_INQUIRYDATA
block|{
name|u_char
name|DeviceType
range|:
literal|5
decl_stmt|;
name|u_char
name|DeviceTypeQualifier
range|:
literal|3
decl_stmt|;
name|u_char
name|DeviceTypeModifier
range|:
literal|7
decl_stmt|;
name|u_char
name|RemovableMedia
range|:
literal|1
decl_stmt|;
name|u_char
name|Versions
decl_stmt|;
name|u_char
name|ResponseDataFormat
decl_stmt|;
name|u_char
name|AdditionalLength
decl_stmt|;
name|u_char
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|SoftReset
range|:
literal|1
decl_stmt|;
name|u_char
name|CommandQueue
range|:
literal|1
decl_stmt|;
name|u_char
name|Reserved2
range|:
literal|1
decl_stmt|;
name|u_char
name|LinkedCommands
range|:
literal|1
decl_stmt|;
name|u_char
name|Synchronous
range|:
literal|1
decl_stmt|;
name|u_char
name|Wide16Bit
range|:
literal|1
decl_stmt|;
name|u_char
name|Wide32Bit
range|:
literal|1
decl_stmt|;
name|u_char
name|RelativeAddressing
range|:
literal|1
decl_stmt|;
name|u_char
name|VendorId
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|ProductId
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|ProductRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|VendorSpecific
index|[
literal|20
index|]
decl_stmt|;
name|u_char
name|Reserved3
index|[
literal|40
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|INQUIRYDATA
operator|,
typedef|*
name|PINQUIRYDATA
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* private headers */
end_comment

begin_include
include|#
directive|include
file|<dev/hptrr/osm.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptrr/him.h>
end_include

begin_include
include|#
directive|include
file|<dev/hptrr/ldm.h>
end_include

begin_comment
comment|/* driver parameters */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|driver_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|driver_name_long
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|driver_ver
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|osm_max_targets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * adapter/vbus extensions:  * each physical controller has an adapter_ext, passed to him.create_adapter()  * each vbus has a vbus_ext passed to ldm_create_vbus().  */
end_comment

begin_define
define|#
directive|define
name|EXT_TYPE_HBA
value|1
end_define

begin_define
define|#
directive|define
name|EXT_TYPE_VBUS
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_hba
block|{
name|int
name|ext_type
decl_stmt|;
name|LDM_ADAPTER
name|ldm_adapter
decl_stmt|;
name|device_t
name|pcidev
decl_stmt|;
name|PCI_ADDRESS
name|pciaddr
decl_stmt|;
name|struct
name|_vbus_ext
modifier|*
name|vbus_ext
decl_stmt|;
name|struct
name|_hba
modifier|*
name|next
decl_stmt|;
struct|struct
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
block|}
name|pcibar
index|[
literal|6
index|]
struct|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
block|}
name|HBA
operator|,
typedef|*
name|PHBA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_os_cmdext
block|{
name|struct
name|_vbus_ext
modifier|*
name|vbus_ext
decl_stmt|;
name|struct
name|_os_cmdext
modifier|*
name|next
decl_stmt|;
name|union
name|ccb
modifier|*
name|ccb
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|SG
name|psg
index|[
name|os_max_sg_descriptors
index|]
decl_stmt|;
block|}
name|OS_CMDEXT
operator|,
typedef|*
name|POS_CMDEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_vbus_ext
block|{
name|int
name|ext_type
decl_stmt|;
name|struct
name|_vbus_ext
modifier|*
name|next
decl_stmt|;
name|PHBA
name|hba_list
decl_stmt|;
name|struct
name|freelist
modifier|*
name|freelist_head
decl_stmt|;
name|struct
name|freelist
modifier|*
name|freelist_dma_head
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
comment|/* sim for this vbus */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* peripheral, path, tgt, lun with this vbus */
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* general purpose lock */
else|#
directive|else
name|int
name|hpt_splx
decl_stmt|;
endif|#
directive|endif
name|bus_dma_tag_t
name|io_dmat
decl_stmt|;
comment|/* I/O buffer DMA tag */
name|POS_CMDEXT
name|cmdext_list
decl_stmt|;
name|OSM_TASK
modifier|*
name|tasks
decl_stmt|;
name|struct
name|task
name|worker
decl_stmt|;
name|struct
name|callout_handle
name|timer
decl_stmt|;
name|eventhandler_tag
name|shutdown_eh
decl_stmt|;
comment|/* the LDM vbus instance continues */
name|unsigned
name|long
name|vbus
index|[
literal|0
index|]
name|__attribute__
decl|((
name|aligned
decl|(sizeof(
name|unsigned
name|long
decl|)
decl_stmt|)
block|)
typedef|);
end_typedef

begin_operator
unit|} VBUS_EXT
operator|,
end_operator

begin_expr_stmt
operator|*
name|PVBUS_EXT
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_define
define|#
directive|define
name|hpt_lock_vbus
parameter_list|(
name|vbus_ext
parameter_list|)
value|mtx_lock(&(vbus_ext)->lock)
end_define

begin_define
define|#
directive|define
name|hpt_unlock_vbus
parameter_list|(
name|vbus_ext
parameter_list|)
value|mtx_unlock(&(vbus_ext)->lock)
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|hpt_lock_vbus
parameter_list|(
name|PVBUS_EXT
name|vbus_ext
parameter_list|)
block|{
name|vbus_ext
operator|->
name|hpt_splx
operator|=
name|splcam
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|hpt_unlock_vbus
parameter_list|(
name|PVBUS_EXT
name|vbus_ext
parameter_list|)
block|{
name|splx
argument_list|(
name|vbus_ext
operator|->
name|hpt_splx
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HPT_OSM_TIMEOUT
value|(20*hz)
end_define

begin_comment
comment|/* timeout value for OS commands */
end_comment

begin_define
define|#
directive|define
name|HPT_DO_IOCONTROL
value|_IOW('H', 0, HPT_IOCTL_PARAM)
end_define

begin_define
define|#
directive|define
name|HPT_SCAN_BUS
value|_IO('H', 1)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|501000
end_if

begin_define
define|#
directive|define
name|TASK_ENQUEUE
parameter_list|(
name|task
parameter_list|)
value|taskqueue_enqueue(taskqueue_swi_giant,(task));
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TASK_ENQUEUE
parameter_list|(
name|task
parameter_list|)
value|taskqueue_enqueue(taskqueue_swi,(task));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_function
specifier|static
name|__inline
name|int
name|hpt_sleep
parameter_list|(
name|PVBUS_EXT
name|vbus_ext
parameter_list|,
name|void
modifier|*
name|ident
parameter_list|,
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|)
block|{
return|return
name|msleep
argument_list|(
name|ident
argument_list|,
operator|&
name|vbus_ext
operator|->
name|lock
argument_list|,
name|priority
argument_list|,
name|wmesg
argument_list|,
name|timo
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|int
name|hpt_sleep
parameter_list|(
name|PVBUS_EXT
name|vbus_ext
parameter_list|,
name|void
modifier|*
name|ident
parameter_list|,
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|)
block|{
name|int
name|retval
init|=
literal|0
decl_stmt|;
name|asleep
argument_list|(
name|ident
argument_list|,
name|priority
argument_list|,
name|wmesg
argument_list|,
name|timo
argument_list|)
expr_stmt|;
name|hpt_unlock_vbus
argument_list|(
name|vbus_ext
argument_list|)
expr_stmt|;
name|retval
operator|=
name|await
argument_list|(
name|priority
argument_list|,
name|timo
argument_list|)
expr_stmt|;
name|hpt_lock_vbus
argument_list|(
name|vbus_ext
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|501000
end_if

begin_define
define|#
directive|define
name|READ_16
value|0x88
end_define

begin_define
define|#
directive|define
name|WRITE_16
value|0x8a
end_define

begin_define
define|#
directive|define
name|SERVICE_ACTION_IN
value|0x9e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HPT_DEV_MAJOR
value|200
end_define

end_unit

