begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 by Panasas, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Virtual HBA defines  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_debug.h>
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
file|<cam/cam_xpt.h>
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
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/devicestat.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_periph.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_xpt_periph.h>
end_include

begin_define
define|#
directive|define
name|VHBA_MAXTGT
value|64
end_define

begin_define
define|#
directive|define
name|VHBA_MAXCMDS
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_devq
modifier|*
name|devq
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|actv
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|done
expr_stmt|;
name|void
modifier|*
name|private
decl_stmt|;
block|}
name|vhba_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Each different instantiation of a fake HBA needs to  * provide these as function entry points. It's responsible  * for setting up some thread or regular timeout that will  * dequeue things from the actv queue and put done items  * on the done queue.  */
end_comment

begin_function_decl
name|void
name|vhba_init
parameter_list|(
name|vhba_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vhba_fini
parameter_list|(
name|vhba_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vhba_kick
parameter_list|(
name|vhba_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Support functions  */
end_comment

begin_function_decl
name|void
name|vhba_fill_sense
parameter_list|(
name|struct
name|ccb_scsiio
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vhba_rwparm
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vhba_default_cmd
parameter_list|(
name|struct
name|ccb_scsiio
modifier|*
parameter_list|,
name|lun_id_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vhba_set_status
parameter_list|(
name|struct
name|ccb_hdr
modifier|*
parameter_list|,
name|cam_status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Common module loader function  */
end_comment

begin_function_decl
name|int
name|vhba_modprobe
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * retrofits  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_SENSE
end_ifndef

begin_define
define|#
directive|define
name|MODE_SENSE
value|0x1a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SMS_FORMAT_DEVICE_PAGE
end_ifndef

begin_define
define|#
directive|define
name|SMS_FORMAT_DEVICE_PAGE
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SMS_GEOMETRY_PAGE
end_ifndef

begin_define
define|#
directive|define
name|SMS_GEOMETRY_PAGE
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

