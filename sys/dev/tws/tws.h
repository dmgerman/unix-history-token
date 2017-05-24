begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010, LSI Corp.  * All rights reserved.  * Author : Manjunath Ranganathaiah  * Support: freebsdraid@lsi.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of the<ORGANIZATION> nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* defines used in kernel.h */
end_comment

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* types used in module initialization */
end_comment

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* cdevsw struct */
end_comment

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_comment
comment|/* uio struct */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/* structs, prototypes for pci bus stuff */
end_comment

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

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_comment
comment|/* For pci_get macros! */
end_comment

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|TWS_PULL_MODE_ENABLE
value|1
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TWS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* externs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tws_queue_depth
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TWS_DRIVER_VERSION_STRING
value|"10.80.00.005"
end_define

begin_define
define|#
directive|define
name|TWS_MAX_NUM_UNITS
value|65
end_define

begin_define
define|#
directive|define
name|TWS_MAX_NUM_LUNS
value|32
end_define

begin_define
define|#
directive|define
name|TWS_MAX_IRQS
value|2
end_define

begin_define
define|#
directive|define
name|TWS_SCSI_INITIATOR_ID
value|66
end_define

begin_define
define|#
directive|define
name|TWS_MAX_IO_SIZE
value|0x20000
end_define

begin_comment
comment|/* 128kB */
end_comment

begin_define
define|#
directive|define
name|TWS_SECTOR_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|TWS_POLL_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|TWS_IO_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|TWS_IOCTL_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|TWS_RESET_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|TWS_PCI_BAR0
value|0x10
end_define

begin_define
define|#
directive|define
name|TWS_PCI_BAR1
value|0x14
end_define

begin_define
define|#
directive|define
name|TWS_PCI_BAR2
value|0x1C
end_define

begin_define
define|#
directive|define
name|TWS_VENDOR_ID
value|0x13C1
end_define

begin_define
define|#
directive|define
name|TWS_DEVICE_ID
value|0x1010
end_define

begin_define
define|#
directive|define
name|TWS_INVALID_REQID
value|0xFFFF
end_define

begin_comment
comment|/* bus tag related */
end_comment

begin_define
define|#
directive|define
name|TWS_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|TWS_IN_MF_ALIGNMENT
value|16
end_define

begin_define
define|#
directive|define
name|TWS_OUT_MF_ALIGNMENT
value|4
end_define

begin_define
define|#
directive|define
name|TWS_MAX_32BIT_SG_ELEMENTS
value|93
end_define

begin_comment
comment|/* max 32-bit sg elements */
end_comment

begin_define
define|#
directive|define
name|TWS_MAX_64BIT_SG_ELEMENTS
value|46
end_define

begin_comment
comment|/* max 64-bit sg elements */
end_comment

begin_define
define|#
directive|define
name|TWS_MAX_QS
value|4
end_define

begin_define
define|#
directive|define
name|TWS_MAX_REQS
value|256
end_define

begin_define
define|#
directive|define
name|TWS_RESERVED_REQS
value|4
end_define

begin_comment
comment|/* Request states */
end_comment

begin_define
define|#
directive|define
name|TWS_REQ_STATE_FREE
value|0
end_define

begin_define
define|#
directive|define
name|TWS_REQ_STATE_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|TWS_REQ_STATE_TRAN
value|2
end_define

begin_define
define|#
directive|define
name|TWS_REQ_STATE_COMPLETE
value|3
end_define

begin_comment
comment|/* Request types */
end_comment

begin_define
define|#
directive|define
name|TWS_REQ_TYPE_INTERNAL_CMD
value|0x0
end_define

begin_define
define|#
directive|define
name|TWS_REQ_TYPE_AEN_FETCH
value|0x1
end_define

begin_define
define|#
directive|define
name|TWS_REQ_TYPE_PASSTHRU
value|0x2
end_define

begin_define
define|#
directive|define
name|TWS_REQ_TYPE_GETSET_PARAM
value|0x3
end_define

begin_define
define|#
directive|define
name|TWS_REQ_TYPE_SCSI_IO
value|0x4
end_define

begin_comment
comment|/* Driver states */
end_comment

begin_enum
enum|enum
name|tws_states
block|{
name|TWS_INIT
init|=
literal|50
block|,
name|TWS_UNINIT
block|,
name|TWS_OFFLINE
block|,
name|TWS_ONLINE
block|,
name|TWS_RESET
block|, }
enum|;
end_enum

begin_comment
comment|/* events */
end_comment

begin_enum
enum|enum
name|tws_events
block|{
name|TWS_INIT_START
init|=
literal|100
block|,
name|TWS_INIT_COMPLETE
block|,
name|TWS_UNINIT_START
block|,
name|TWS_RESET_START
block|,
name|TWS_RESET_COMPLETE
block|,
name|TWS_SCAN_FAILURE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|tws_req_flags
block|{
name|TWS_DIR_UNKNOWN
init|=
literal|0x1
block|,
name|TWS_DIR_IN
init|=
literal|0x2
block|,
name|TWS_DIR_OUT
init|=
literal|0x4
block|,
name|TWS_DIR_NONE
init|=
literal|0x8
block|,
name|TWS_DATA_CCB
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|tws_intrs
block|{
name|TWS_INTx
block|,
name|TWS_MSI
block|,
name|TWS_MSIX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|tws_msix_info
block|{
name|int
name|tbl_res_id
decl_stmt|;
name|bus_space_tag_t
name|tbl_tag
decl_stmt|;
name|bus_space_handle_t
name|tbl_handle
decl_stmt|;
name|struct
name|resource
modifier|*
name|tbl_res
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_ioctl_lock
block|{
name|u_int32_t
name|lock
decl_stmt|;
name|time_t
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TWS_TRACE_FNAME_LEN
value|10
end_define

begin_define
define|#
directive|define
name|TWS_TRACE_FUNC_LEN
value|15
end_define

begin_define
define|#
directive|define
name|TWS_TRACE_DESC_LEN
value|10
end_define

begin_struct
struct|struct
name|tws_trace_rec
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|char
name|fname
index|[
name|TWS_TRACE_FNAME_LEN
index|]
decl_stmt|;
name|char
name|func
index|[
name|TWS_TRACE_FUNC_LEN
index|]
decl_stmt|;
name|int
name|linenum
decl_stmt|;
name|char
name|desc
index|[
name|TWS_TRACE_DESC_LEN
index|]
decl_stmt|;
name|u_int64_t
name|val1
decl_stmt|;
name|u_int64_t
name|val2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_circular_q
block|{
specifier|volatile
name|int16_t
name|head
decl_stmt|;
specifier|volatile
name|int16_t
name|tail
decl_stmt|;
name|u_int16_t
name|depth
decl_stmt|;
name|u_int8_t
name|overflow
decl_stmt|;
name|void
modifier|*
name|q
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_stats
block|{
name|u_int64_t
name|reqs_in
decl_stmt|;
name|u_int64_t
name|reqs_out
decl_stmt|;
name|u_int64_t
name|reqs_errored
decl_stmt|;
name|u_int64_t
name|spurios_intrs
decl_stmt|;
name|u_int64_t
name|num_intrs
decl_stmt|;
name|u_int64_t
name|num_aens
decl_stmt|;
name|u_int64_t
name|ioctls
decl_stmt|;
name|u_int64_t
name|scsi_ios
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tws_init_connect_info
block|{
name|u_int16_t
name|working_srl
decl_stmt|;
name|u_int16_t
name|working_branch
decl_stmt|;
name|u_int16_t
name|working_build
decl_stmt|;
name|u_int16_t
name|fw_on_ctlr_srl
decl_stmt|;
name|u_int16_t
name|fw_on_ctlr_branch
decl_stmt|;
name|u_int16_t
name|fw_on_ctlr_build
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ------------ boolean types ------------------- */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__bool_true_false_are_defined
end_ifndef

begin_typedef
typedef|typedef
enum|enum
name|_boolean
block|{
name|false
block|,
name|true
block|}
name|boolean
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|boolean
value|bool
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|err
block|{
name|SUCCESS
block|,
name|FAILURE
block|}
enum|;
end_enum

begin_comment
comment|/* ----------- per instance data ---------------- */
end_comment

begin_comment
comment|/* The softc holds our per-instance data. */
end_comment

begin_struct
struct|struct
name|tws_softc
block|{
name|device_t
name|tws_dev
decl_stmt|;
comment|/* bus device */
name|struct
name|cdev
modifier|*
name|tws_cdev
decl_stmt|;
comment|/* controller device */
name|u_int32_t
name|device_id
decl_stmt|;
comment|/* device id */
name|u_int32_t
name|subvendor_id
decl_stmt|;
comment|/* device id */
name|u_int32_t
name|subdevice_id
decl_stmt|;
comment|/* device id */
name|u_int8_t
name|tws_state
decl_stmt|;
comment|/* driver state */
name|u_int8_t
name|tws_prev_state
decl_stmt|;
comment|/* driver prev state */
name|struct
name|sysctl_ctx_list
name|tws_clist
decl_stmt|;
comment|/* sysctl context */
name|struct
name|sysctl_oid
modifier|*
name|tws_oidp
decl_stmt|;
comment|/* sysctl context */
name|struct
name|resource
modifier|*
name|reg_res
decl_stmt|;
comment|/* register interface window */
name|struct
name|resource
modifier|*
name|mfa_res
decl_stmt|;
comment|/* mfa interface window */
name|int
name|reg_res_id
decl_stmt|;
comment|/* register resource id */
name|int
name|mfa_res_id
decl_stmt|;
comment|/* register resource id */
name|bus_space_handle_t
name|bus_handle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_handle_t
name|bus_mfa_handle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|bus_tag
decl_stmt|;
comment|/* bus space tag */
name|bus_space_tag_t
name|bus_mfa_tag
decl_stmt|;
comment|/* bus space tag for mfa's */
name|u_int64_t
name|mfa_base
decl_stmt|;
comment|/* mfa base address */
name|struct
name|resource
modifier|*
name|irq_res
index|[
name|TWS_MAX_IRQS
index|]
decl_stmt|;
comment|/* interrupt resource */
name|int
name|irq_res_id
index|[
name|TWS_MAX_IRQS
index|]
decl_stmt|;
comment|/* intr resource id */
name|void
modifier|*
name|intr_handle
index|[
name|TWS_MAX_IRQS
index|]
decl_stmt|;
comment|/* interrupt handle */
name|int
name|irqs
decl_stmt|;
comment|/* intrs used */
name|struct
name|tws_msix_info
name|msix
decl_stmt|;
comment|/* msix info */
name|struct
name|cam_sim
modifier|*
name|sim
decl_stmt|;
comment|/* sim for this controller */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* Ctlr path to CAM */
name|struct
name|mtx
name|q_lock
decl_stmt|;
comment|/* queue lock */
name|struct
name|mtx
name|sim_lock
decl_stmt|;
comment|/* sim lock */
name|struct
name|mtx
name|gen_lock
decl_stmt|;
comment|/* general driver  lock */
name|struct
name|mtx
name|io_lock
decl_stmt|;
comment|/* IO  lock */
name|struct
name|tws_ioctl_lock
name|ioctl_lock
decl_stmt|;
comment|/* ioctl lock */
name|u_int32_t
name|seq_id
decl_stmt|;
comment|/* Sequence id */
name|struct
name|tws_circular_q
name|aen_q
decl_stmt|;
comment|/* aen q */
name|struct
name|tws_circular_q
name|trace_q
decl_stmt|;
comment|/* trace q */
name|struct
name|tws_stats
name|stats
decl_stmt|;
comment|/* I/O stats */
name|struct
name|tws_init_connect_info
name|cinfo
decl_stmt|;
comment|/* compatibility info */
name|boolean
name|is64bit
decl_stmt|;
comment|/* True - 64bit else 32bit */
name|u_int8_t
name|intr_type
decl_stmt|;
comment|/* Interrupt type used */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* parent DMA tag */
name|bus_dma_tag_t
name|cmd_tag
decl_stmt|;
comment|/* command DMA tag */
name|bus_dmamap_t
name|cmd_map
decl_stmt|;
comment|/* command map */
name|void
modifier|*
name|dma_mem
decl_stmt|;
comment|/* pointer to dmable memory */
name|u_int64_t
name|dma_mem_phys
decl_stmt|;
comment|/* phy addr */
name|bus_dma_tag_t
name|data_tag
decl_stmt|;
comment|/* data DMA tag */
name|void
modifier|*
name|ioctl_data_mem
decl_stmt|;
comment|/* ioctl dmable memory */
name|bus_dmamap_t
name|ioctl_data_map
decl_stmt|;
comment|/* ioctl data map */
name|struct
name|tws_request
modifier|*
name|reqs
decl_stmt|;
comment|/* pointer to requests */
name|struct
name|tws_sense
modifier|*
name|sense_bufs
decl_stmt|;
comment|/* pointer to sense buffers */
name|boolean
name|obfl_q_overrun
decl_stmt|;
comment|/* OBFL overrun flag  */
name|union
name|ccb
modifier|*
name|scan_ccb
decl_stmt|;
comment|/* pointer to a ccb */
name|struct
name|tws_request
modifier|*
name|q_head
index|[
name|TWS_MAX_QS
index|]
decl_stmt|;
comment|/* head pointers to q's */
name|struct
name|tws_request
modifier|*
name|q_tail
index|[
name|TWS_MAX_QS
index|]
decl_stmt|;
comment|/* tail pointers to q's */
name|struct
name|callout
name|stats_timer
decl_stmt|;
block|}
struct|;
end_struct

end_unit

