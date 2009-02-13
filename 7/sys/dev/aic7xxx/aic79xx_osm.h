begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * FreeBSD platform specific driver option settings, data structures,  * function declarations and includes.  *  * Copyright (c) 1994-2001 Justin T. Gibbs.  * Copyright (c) 2001-2002 Adaptec Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: //depot/aic7xxx/freebsd/dev/aic7xxx/aic79xx_osm.h#23 $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIC79XX_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIC79XX_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<opt_aic79xx.h>
end_include

begin_comment
comment|/* for config options */
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
file|<sys/bus.h>
end_include

begin_comment
comment|/* For device_t */
end_comment

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
file|<sys/endian.h>
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|AIC_PCI_CONFIG
value|1
end_define

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
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
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
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
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
file|<cam/cam_debug.h>
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
file|<cam/scsi/scsi_iu.h>
end_include

begin_comment
comment|/****************************** Platform Macros *******************************/
end_comment

begin_define
define|#
directive|define
name|SIM_IS_SCSIBUS_B
parameter_list|(
name|ahd
parameter_list|,
name|sim
parameter_list|)
define|\
value|(0)
end_define

begin_define
define|#
directive|define
name|SIM_CHANNEL
parameter_list|(
name|ahd
parameter_list|,
name|sim
parameter_list|)
define|\
value|('A')
end_define

begin_define
define|#
directive|define
name|SIM_SCSI_ID
parameter_list|(
name|ahd
parameter_list|,
name|sim
parameter_list|)
define|\
value|(ahd->our_id)
end_define

begin_define
define|#
directive|define
name|SIM_PATH
parameter_list|(
name|ahd
parameter_list|,
name|sim
parameter_list|)
define|\
value|(ahd->platform_data->path)
end_define

begin_define
define|#
directive|define
name|BUILD_SCSIID
parameter_list|(
name|ahd
parameter_list|,
name|sim
parameter_list|,
name|target_id
parameter_list|,
name|our_id
parameter_list|)
define|\
value|((((target_id)<< TID_SHIFT)& TID) | (our_id))
end_define

begin_define
define|#
directive|define
name|SCB_GET_SIM
parameter_list|(
name|ahd
parameter_list|,
name|scb
parameter_list|)
define|\
value|((ahd)->platform_data->sim)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************ Tunable Driver Parameters  **************************/
end_comment

begin_comment
comment|/*  * The number of dma segments supported.  The sequencer can handle any number  * of physically contiguous S/G entrys.  To reduce the driver's memory  * consumption, we limit the number supported to be sufficient to handle  * the largest mapping supported by the kernel, MAXPHYS.  Assuming the  * transfer is as fragmented as possible and unaligned, this turns out to  * be the number of paged sized transfers in MAXPHYS plus an extra element  * to handle any unaligned residual.  The sequencer fetches SG elements  * in cacheline sized chucks, so make the number per-transaction an even  * multiple of 16 which should align us on even the largest of cacheline  * boundaries.   */
end_comment

begin_define
define|#
directive|define
name|AHD_NSEG
value|(roundup(btoc(MAXPHYS) + 1, 16))
end_define

begin_comment
comment|/* This driver supports target mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_YET
end_ifdef

begin_define
define|#
directive|define
name|AHD_TARGET_MODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************** Softc/SCB Platform Data ***************************/
end_comment

begin_struct
struct|struct
name|ahd_platform_data
block|{
comment|/* 	 * Hooks into the XPT. 	 */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|int
name|regs_res_type
index|[
literal|2
index|]
decl_stmt|;
name|int
name|regs_res_id
index|[
literal|2
index|]
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|eventhandler_tag
name|eh
decl_stmt|;
name|struct
name|proc
modifier|*
name|recovery_thread
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scb_platform_data
block|{ }
struct|;
end_struct

begin_comment
comment|/***************************** Core Includes **********************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AHD_REG_PRETTY_PRINT
end_ifdef

begin_define
define|#
directive|define
name|AIC_DEBUG_REGISTERS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AIC_DEBUG_REGISTERS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AIC_CORE_INCLUDE
value|<dev/aic7xxx/aic79xx.h>
end_define

begin_define
define|#
directive|define
name|AIC_LIB_PREFIX
value|ahd
end_define

begin_define
define|#
directive|define
name|AIC_CONST_PREFIX
value|AHD
end_define

begin_include
include|#
directive|include
file|<dev/aic7xxx/aic_osm_lib.h>
end_include

begin_comment
comment|/*************************** Device Access ************************************/
end_comment

begin_define
define|#
directive|define
name|ahd_inb
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((ahd)->tags[(port)>> 8],		\ 			 (ahd)->bshs[(port)>> 8], (port)& 0xFF)
end_define

begin_define
define|#
directive|define
name|ahd_outb
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((ahd)->tags[(port)>> 8],		\ 			  (ahd)->bshs[(port)>> 8], (port)& 0xFF, value)
end_define

begin_define
define|#
directive|define
name|ahd_inw_atomic
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|)
define|\
value|aic_le16toh(bus_space_read_2((ahd)->tags[(port)>> 8],	\ 				     (ahd)->bshs[(port)>> 8], (port)& 0xFF))
end_define

begin_define
define|#
directive|define
name|ahd_outw_atomic
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2((ahd)->tags[(port)>> 8],		\ 			  (ahd)->bshs[(port)>> 8],		\ 			  (port& 0xFF), aic_htole16(value))
end_define

begin_define
define|#
directive|define
name|ahd_outsb
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((ahd)->tags[(port)>> 8],	\ 				(ahd)->bshs[(port)>> 8],	\ 				(port& 0xFF), valp, count)
end_define

begin_define
define|#
directive|define
name|ahd_insb
parameter_list|(
name|ahd
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((ahd)->tags[(port)>> 8],	\ 			       (ahd)->bshs[(port)>> 8],	\ 			       (port& 0xFF), valp, count)
end_define

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_flush_device_writes
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahd_flush_device_writes
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{
comment|/* XXX Is this sufficient for all architectures??? */
name|ahd_inb
argument_list|(
name|ahd
argument_list|,
name|INTSTAT
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************** Locking Primitives ******************************/
end_comment

begin_comment
comment|/* Lock protecting internal data structures */
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_lockinit
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_lock
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_unlock
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahd_lockinit
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{
name|mtx_init
argument_list|(
operator|&
name|ahd
operator|->
name|platform_data
operator|->
name|mtx
argument_list|,
literal|"ahd_lock"
argument_list|,
name|NULL
argument_list|,
name|MTX_DEF
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahd_lock
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|ahd
operator|->
name|platform_data
operator|->
name|mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahd_unlock
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|ahd
operator|->
name|platform_data
operator|->
name|mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/********************************** PCI ***************************************/
end_comment

begin_function_decl
name|int
name|ahd_pci_map_registers
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_pci_map_int
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************** Transaction Operations ****************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|aic_freeze_simq
parameter_list|(
name|struct
name|aic_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|aic_release_simq
parameter_list|(
name|struct
name|aic_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|aic_freeze_simq
parameter_list|(
name|struct
name|aic_softc
modifier|*
name|aic
parameter_list|)
block|{
name|xpt_freeze_simq
argument_list|(
name|aic
operator|->
name|platform_data
operator|->
name|sim
argument_list|,
comment|/*count*/
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|aic_release_simq
parameter_list|(
name|struct
name|aic_softc
modifier|*
name|aic
parameter_list|)
block|{
name|xpt_release_simq
argument_list|(
name|aic
operator|->
name|platform_data
operator|->
name|sim
argument_list|,
comment|/*run queue*/
name|TRUE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/********************************* Debug **************************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_print_path
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|scb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_platform_dump_card_state
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahd_print_path
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
block|{
name|xpt_print_path
argument_list|(
name|scb
operator|->
name|io_ctx
operator|->
name|ccb_h
operator|.
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ahd_platform_dump_card_state
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{
comment|/* Nothing to do here for FreeBSD */
block|}
end_function

begin_comment
comment|/**************************** Transfer Settings *******************************/
end_comment

begin_function_decl
name|void
name|ahd_notify_xfer_settings_change
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_platform_set_tags
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|struct
name|ahd_devinfo
modifier|*
parameter_list|,
name|int
comment|/*enable*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************* Initialization/Teardown ****************************/
end_comment

begin_function_decl
name|int
name|ahd_platform_alloc
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|void
modifier|*
name|platform_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_platform_free
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_map_int
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_attach
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_softc_comp
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|lahd
parameter_list|,
name|struct
name|ahd_softc
modifier|*
name|rahd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahd_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ahd_platform_init
parameter_list|(
name|arg
parameter_list|)
end_define

begin_comment
comment|/****************************** Interrupts ************************************/
end_comment

begin_function_decl
name|void
name|ahd_platform_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahd_platform_flushwork
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahd_platform_flushwork
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|)
block|{ }
end_function

begin_comment
comment|/************************ Misc Function Declarations **************************/
end_comment

begin_function_decl
name|void
name|ahd_done
parameter_list|(
name|struct
name|ahd_softc
modifier|*
name|ahd
parameter_list|,
name|struct
name|scb
modifier|*
name|scb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahd_send_async
parameter_list|(
name|struct
name|ahd_softc
modifier|*
parameter_list|,
name|char
comment|/*channel*/
parameter_list|,
name|u_int
comment|/*target*/
parameter_list|,
name|u_int
comment|/*lun*/
parameter_list|,
name|ac_code
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIC79XX_FREEBSD_H_ */
end_comment

end_unit

