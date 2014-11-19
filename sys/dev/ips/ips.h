begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Adaptec Inc.  * All rights reserved.  *  * Written by: David Jeffery  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPS_H
end_ifndef

begin_define
define|#
directive|define
name|_IPS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
file|<sys/module.h>
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSBUF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  IPS MACROS  */
end_comment

begin_define
define|#
directive|define
name|ips_read_1
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bus_read_1(sc->iores, offset)
end_define

begin_define
define|#
directive|define
name|ips_read_2
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bus_read_2(sc->iores, offset)
end_define

begin_define
define|#
directive|define
name|ips_read_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bus_read_4(sc->iores, offset)
end_define

begin_define
define|#
directive|define
name|ips_write_1
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
value|bus_write_1(sc->iores, offset, value)
end_define

begin_define
define|#
directive|define
name|ips_write_2
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
value|bus_write_2(sc->iores, offset, value)
end_define

begin_define
define|#
directive|define
name|ips_write_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
value|bus_write_4(sc->iores, offset, value)
end_define

begin_comment
comment|/* this is ugly.  It zeros the end elements in an ips_command_t struct starting with the status element */
end_comment

begin_define
define|#
directive|define
name|clear_ips_command
parameter_list|(
name|command
parameter_list|)
value|bzero(&((command)->status), (unsigned long)(&(command)[1])-(unsigned long)&((command)->status))
end_define

begin_define
define|#
directive|define
name|ips_read_request
parameter_list|(
name|iobuf
parameter_list|)
value|((iobuf)->bio_cmd == BIO_READ)
end_define

begin_define
define|#
directive|define
name|COMMAND_ERROR
parameter_list|(
name|command
parameter_list|)
value|(((command)->status.fields.basic_status& IPS_GSC_STATUS_MASK)>= IPS_MIN_ERROR)
end_define

begin_define
define|#
directive|define
name|ips_set_error
parameter_list|(
name|command
parameter_list|,
name|error
parameter_list|)
value|do {				\ 	(command)->status.fields.basic_status = IPS_DRV_ERROR;		\ 	(command)->status.fields.reserved = ((error)& 0x0f);		\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IPS_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEVICE_PRINTF
parameter_list|(
name|x
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|x
modifier|...
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVICE_PRINTF
parameter_list|(
name|level
parameter_list|,
name|x
modifier|...
parameter_list|)
value|if(IPS_DEBUG>= level)device_printf(x)
end_define

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|level
parameter_list|,
name|x
modifier|...
parameter_list|)
value|if(IPS_DEBUG>= level)printf(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ips_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|status
index|[
name|IPS_MAX_CMD_NUM
index|]
decl_stmt|;
name|u_int32_t
name|base_phys_addr
decl_stmt|;
name|int
name|nextstatus
decl_stmt|;
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
block|}
name|ips_copper_queue_t
typedef|;
end_typedef

begin_comment
comment|/* used to keep track of current commands to the card */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ips_command
block|{
name|u_int8_t
name|command_number
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
name|u_int8_t
name|timeout
decl_stmt|;
name|struct
name|ips_softc
modifier|*
name|sc
decl_stmt|;
name|bus_dma_tag_t
name|data_dmatag
decl_stmt|;
name|bus_dmamap_t
name|data_dmamap
decl_stmt|;
name|bus_dmamap_t
name|command_dmamap
decl_stmt|;
name|void
modifier|*
name|command_buffer
decl_stmt|;
name|u_int32_t
name|command_phys_addr
decl_stmt|;
comment|/*WARNING! must be changed if 64bit addressing ever used*/
name|ips_cmd_status_t
name|status
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ips_command
argument_list|)
name|next
expr_stmt|;
name|void
modifier|*
name|data_buffer
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|ips_command
modifier|*
name|command
parameter_list|)
function_decl|;
block|}
name|ips_command_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ips_softc
block|{
name|struct
name|resource
modifier|*
name|iores
decl_stmt|;
name|struct
name|resource
modifier|*
name|irqres
decl_stmt|;
name|struct
name|intr_config_hook
name|ips_ich
decl_stmt|;
name|int
name|configured
decl_stmt|;
name|int
name|state
decl_stmt|;
name|int
name|iotype
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|int
name|irqrid
decl_stmt|;
name|void
modifier|*
name|irqcookie
decl_stmt|;
name|bus_dma_tag_t
name|adapter_dmatag
decl_stmt|;
name|bus_dma_tag_t
name|command_dmatag
decl_stmt|;
name|bus_dma_tag_t
name|sg_dmatag
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|device_file
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|u_int16_t
name|adapter_type
decl_stmt|;
name|ips_adapter_info_t
name|adapter_info
decl_stmt|;
name|device_t
name|diskdev
index|[
name|IPS_MAX_NUM_DRIVES
index|]
decl_stmt|;
name|ips_drive_t
name|drives
index|[
name|IPS_MAX_NUM_DRIVES
index|]
decl_stmt|;
name|u_int8_t
name|drivecount
decl_stmt|;
name|u_int16_t
name|ffdc_resetcount
decl_stmt|;
name|struct
name|timeval
name|ffdc_resettime
decl_stmt|;
name|u_int8_t
name|next_drive
decl_stmt|;
name|u_int8_t
name|max_cmds
decl_stmt|;
specifier|volatile
name|u_int8_t
name|used_commands
decl_stmt|;
name|ips_command_t
modifier|*
name|commandarray
decl_stmt|;
name|ips_command_t
modifier|*
name|staticcmd
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument|command_list
argument_list|,
argument|ips_command
argument_list|)
name|free_cmd_list
expr_stmt|;
name|int
function_decl|(
modifier|*
name|ips_adapter_reinit
function_decl|)
parameter_list|(
name|struct
name|ips_softc
modifier|*
name|sc
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ips_adapter_intr
function_decl|)
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ips_issue_cmd
function_decl|)
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ips_poll_cmd
function_decl|)
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
name|ips_copper_queue_t
modifier|*
name|copper_queue
decl_stmt|;
name|struct
name|mtx
name|queue_mtx
decl_stmt|;
name|struct
name|bio_queue_head
name|queue
decl_stmt|;
name|struct
name|sema
name|cmd_sema
decl_stmt|;
block|}
name|ips_softc_t
typedef|;
end_typedef

begin_comment
comment|/* function defines from ips_ioctl.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ips_ioctl_request
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|,
name|u_long
name|ioctl_cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function defines from ips_disk.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|ipsd_finish
parameter_list|(
name|struct
name|bio
modifier|*
name|iobuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function defines from ips_commands.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ips_flush_cache
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_start_io_request
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_get_drive_info
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_get_adapter_info
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_ffdc_reset
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_update_nvram
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_clear_adapter
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* function defines from ips.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ips_get_free_cmd
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|,
name|ips_command_t
modifier|*
modifier|*
name|command
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_insert_free_cmd
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|,
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_adapter_init
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_morpheus_reinit
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_adapter_free
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_morpheus_intr
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_issue_morpheus_cmd
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_morpheus_poll
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ips_copperhead_reinit
parameter_list|(
name|ips_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_copperhead_intr
parameter_list|(
name|void
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_issue_copperhead_cmd
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ips_copperhead_poll
parameter_list|(
name|ips_command_t
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

