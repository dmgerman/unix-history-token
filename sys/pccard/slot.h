begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Slot structures for PC-CARD interface.  *	Each slot has a controller specific structure  *	attached to it. A slot number allows  *	mapping from the character device to the  *	slot structure. This is separate to the  *	controller slot number to allow multiple controllers  *	to be accessed.  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_SLOT_H
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_SLOT_H
end_define

begin_comment
comment|/*  * Normally we shouldn't include stuff here, but we're trying to be  * compatible with the long, dark hand of the past.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Controller data - Specific to each slot controller.  */
end_comment

begin_struct_decl
struct_decl|struct
name|slot
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|slot_ctrl
block|{
name|void
function_decl|(
modifier|*
name|mapirq
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Map irq */
name|int
function_decl|(
modifier|*
name|mapmem
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Map memory */
name|int
function_decl|(
modifier|*
name|mapio
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Map io */
name|void
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* init */
name|void
function_decl|(
modifier|*
name|disable
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
comment|/* Disable slot */
name|int
function_decl|(
modifier|*
name|power
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
comment|/* Set power values */
name|int
function_decl|(
modifier|*
name|ioctl
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
comment|/* ioctl to lower level */
name|void
function_decl|(
modifier|*
name|resume
function_decl|)
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
comment|/* suspend/resume support */
name|int
name|maxmem
decl_stmt|;
comment|/* Number of allowed memory windows */
name|int
name|maxio
decl_stmt|;
comment|/* Number of allowed I/O windows */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Device structure for cards. Each card may have one  *	or more pccard drivers attached to it; each driver is assumed  *	to require at most one interrupt handler, one I/O block  *	and one memory block. This structure is used to link the different  *	devices together.  */
end_comment

begin_struct
struct|struct
name|pccard_devinfo
block|{
name|u_char
name|name
index|[
literal|128
index|]
decl_stmt|;
name|int
name|running
decl_stmt|;
comment|/* Current state of driver */
name|u_char
name|misc
index|[
literal|128
index|]
decl_stmt|;
comment|/* For any random info */
name|struct
name|slot
modifier|*
name|slt
decl_stmt|;
comment|/* Back pointer to slot */
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Per-slot structure.  */
end_comment

begin_struct
struct|struct
name|slot
block|{
name|int
name|slotnum
decl_stmt|;
comment|/* Slot number */
name|int
name|flags
decl_stmt|;
comment|/* Slot flags (see below) */
name|int
name|rwmem
decl_stmt|;
comment|/* Read/write flags */
name|int
name|irq
decl_stmt|;
comment|/* IRQ allocated (0 = none) */
comment|/* 	 *	flags. 	 */
name|unsigned
name|int
name|insert_seq
decl_stmt|;
comment|/* Firing up under the card */
name|struct
name|callout_handle
name|insert_ch
decl_stmt|;
comment|/* Insert event timeout handle */
name|struct
name|callout_handle
name|poff_ch
decl_stmt|;
comment|/* Power Off timeout handle */
name|enum
name|cardstate
name|state
decl_stmt|,
name|laststate
decl_stmt|;
comment|/* Current/last card states */
name|struct
name|selinfo
name|selp
decl_stmt|;
comment|/* Info for select */
name|struct
name|mem_desc
name|mem
index|[
name|NUM_MEM_WINDOWS
index|]
decl_stmt|;
comment|/* Memory windows */
name|struct
name|io_desc
name|io
index|[
name|NUM_IO_WINDOWS
index|]
decl_stmt|;
comment|/* I/O windows */
name|struct
name|power
name|pwr
decl_stmt|;
comment|/* Power values */
name|struct
name|slot_ctrl
modifier|*
name|ctrl
decl_stmt|;
comment|/* Per-controller data */
name|void
modifier|*
name|cdata
decl_stmt|;
comment|/* Controller specific data */
name|int
name|pwr_off_pending
decl_stmt|;
comment|/* Power status of slot */
name|device_t
name|dev
decl_stmt|;
comment|/* Config system device. */
name|dev_t
name|d
decl_stmt|;
comment|/* fs device */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCCARD_DEVICE2SOFTC
parameter_list|(
name|d
parameter_list|)
value|((struct slot *) device_get_softc(d))
end_define

begin_define
define|#
directive|define
name|PCCARD_DEV2SOFTC
parameter_list|(
name|d
parameter_list|)
value|((struct slot *) (d)->si_drv1)
end_define

begin_enum
enum|enum
name|card_event
block|{
name|card_removed
block|,
name|card_inserted
block|,
name|card_deactivated
block|}
enum|;
end_enum

begin_function_decl
name|struct
name|slot
modifier|*
name|pccard_init_slot
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|slot_ctrl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pccard_event
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|,
name|enum
name|card_event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_suspend
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pccard_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCCARD_SLOT_H */
end_comment

end_unit

