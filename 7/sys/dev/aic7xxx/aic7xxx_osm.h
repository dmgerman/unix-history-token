begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * FreeBSD platform specific driver option settings, data structures,  * function declarations and includes.  *  * Copyright (c) 1994-2001 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: //depot/aic7xxx/freebsd/dev/aic7xxx/aic7xxx_osm.h#18 $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AIC7XXX_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_AIC7XXX_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<opt_aic7xxx.h>
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_include
include|#
directive|include
file|<pci.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPCI
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NPCI
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|AIC_PCI_CONFIG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|NPCI
operator|>
literal|0
end_if

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

begin_comment
comment|/*************************** Attachment Bookkeeping ***************************/
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|ahc_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/****************************** Platform Macros *******************************/
end_comment

begin_define
define|#
directive|define
name|SIM_IS_SCSIBUS_B
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|((sim) == ahc->platform_data->sim_b)
end_define

begin_define
define|#
directive|define
name|SIM_CHANNEL
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? 'B' : 'A')
end_define

begin_define
define|#
directive|define
name|SIM_SCSI_ID
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? ahc->our_id_b : ahc->our_id)
end_define

begin_define
define|#
directive|define
name|SIM_PATH
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|)
define|\
value|(((sim) == ahc->platform_data->sim_b) ? ahc->platform_data->path_b \ 					      : ahc->platform_data->path)
end_define

begin_define
define|#
directive|define
name|BUILD_SCSIID
parameter_list|(
name|ahc
parameter_list|,
name|sim
parameter_list|,
name|target_id
parameter_list|,
name|our_id
parameter_list|)
define|\
value|((((target_id)<< TID_SHIFT)& TID) | (our_id) \         | (SIM_IS_SCSIBUS_B(ahc, sim) ? TWIN_CHNLB : 0))
end_define

begin_define
define|#
directive|define
name|SCB_GET_SIM
parameter_list|(
name|ahc
parameter_list|,
name|scb
parameter_list|)
define|\
value|(SCB_GET_CHANNEL(ahc, scb) == 'A' ? (ahc)->platform_data->sim \ 					  : (ahc)->platform_data->sim_b)
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
name|AHC_NSEG
value|(roundup(btoc(MAXPHYS) + 1, 16))
end_define

begin_comment
comment|/* This driver supports target mode */
end_comment

begin_define
define|#
directive|define
name|AHC_TARGET_MODE
value|1
end_define

begin_comment
comment|/************************** Softc/SCB Platform Data ***************************/
end_comment

begin_struct
struct|struct
name|ahc_platform_data
block|{
comment|/* 	 * Hooks into the XPT. 	 */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sim_b
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|path_b
decl_stmt|;
name|int
name|regs_res_type
decl_stmt|;
name|int
name|regs_res_id
decl_stmt|;
name|int
name|irq_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs
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
name|AHC_REG_PRETTY_PRINT
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
value|<dev/aic7xxx/aic7xxx.h>
end_define

begin_define
define|#
directive|define
name|AIC_LIB_PREFIX
value|ahc
end_define

begin_define
define|#
directive|define
name|AIC_CONST_PREFIX
value|AHC
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
name|ahc_inb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((ahc)->tag, (ahc)->bsh, port)
end_define

begin_define
define|#
directive|define
name|ahc_outb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((ahc)->tag, (ahc)->bsh, port, value)
end_define

begin_define
define|#
directive|define
name|ahc_outsb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_define
define|#
directive|define
name|ahc_insb
parameter_list|(
name|ahc
parameter_list|,
name|port
parameter_list|,
name|valp
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((ahc)->tag, (ahc)->bsh, port, valp, count)
end_define

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_flush_device_writes
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_flush_device_writes
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
comment|/* XXX Is this sufficient for all architectures??? */
name|ahc_inb
argument_list|(
name|ahc
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
name|ahc_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_lockinit
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
name|mtx_init
argument_list|(
operator|&
name|ahc
operator|->
name|platform_data
operator|->
name|mtx
argument_list|,
literal|"ahc_lock"
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
name|ahc_lock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|ahc
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
name|ahc_unlock
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|ahc
operator|->
name|platform_data
operator|->
name|mtx
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************* Initialization/Teardown ****************************/
end_comment

begin_function_decl
name|int
name|ahc_platform_alloc
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|void
modifier|*
name|platform_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_platform_free
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_map_int
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_attach
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_softc_comp
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|lahc
parameter_list|,
name|struct
name|ahc_softc
modifier|*
name|rahc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ahc_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************************** PCI ***************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIC_PCI_CONFIG
end_ifdef

begin_function_decl
name|int
name|ahc_pci_map_registers
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ahc_pci_map_int
value|ahc_map_int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*AIC_PCI_CONFIG*/
end_comment

begin_comment
comment|/******************************** VL/EISA *************************************/
end_comment

begin_function_decl
name|int
name|aic7770_map_registers
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|u_int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|aic7770_map_int
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|aic7770_map_int
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|,
name|int
name|irq
parameter_list|)
block|{
comment|/* 	 * The IRQ is unused in the FreeBSD 	 * implementation since the EISA and 	 * ISA attachments register the IRQ 	 * with newbus before the core is called. 	 */
return|return
name|ahc_map_int
argument_list|(
name|ahc
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/********************************* Debug **************************************/
end_comment

begin_function_decl
specifier|static
name|__inline
name|void
name|ahc_print_path
parameter_list|(
name|struct
name|ahc_softc
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
name|ahc_platform_dump_card_state
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_print_path
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_platform_dump_card_state
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_notify_xfer_settings_change
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ahc_platform_set_tags
parameter_list|(
name|struct
name|ahc_softc
modifier|*
parameter_list|,
name|struct
name|ahc_devinfo
modifier|*
parameter_list|,
name|int
comment|/*enable*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************** Interrupts ************************************/
end_comment

begin_function_decl
name|void
name|ahc_platform_intr
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
name|ahc_platform_flushwork
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|ahc_platform_flushwork
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
parameter_list|)
block|{ }
end_function

begin_comment
comment|/************************ Misc Function Declarations **************************/
end_comment

begin_function_decl
name|void
name|ahc_done
parameter_list|(
name|struct
name|ahc_softc
modifier|*
name|ahc
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
name|ahc_send_async
parameter_list|(
name|struct
name|ahc_softc
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
comment|/* _AIC7XXX_FREEBSD_H_ */
end_comment

end_unit

