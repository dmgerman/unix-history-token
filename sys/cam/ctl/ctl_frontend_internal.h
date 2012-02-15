begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_frontend_internal.h#1 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CTL kernel internal frontend target driver.  This allows kernel-level  * clients to send commands into CTL.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_FRONTEND_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_FRONTEND_INTERNAL_H_
end_define

begin_comment
comment|/*  * These are general metatask error codes.  If the error code is CFI_MT_ERROR,   * check any metatask-specific status codes for more detail on the problem.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CFI_MT_NONE
block|,
name|CFI_MT_PORT_OFFLINE
block|,
name|CFI_MT_ERROR
block|,
name|CFI_MT_SUCCESS
block|}
name|cfi_mt_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CFI_TASK_NONE
block|,
name|CFI_TASK_SHUTDOWN
block|,
name|CFI_TASK_STARTUP
block|,
name|CFI_TASK_BBRREAD
block|}
name|cfi_tasktype
typedef|;
end_typedef

begin_struct
struct|struct
name|cfi_task_startstop
block|{
name|int
name|total_luns
decl_stmt|;
name|int
name|luns_complete
decl_stmt|;
name|int
name|luns_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error code description:  * CFI_BBR_SUCCESS          - the read was successful  * CFI_BBR_LUN_UNCONFIG     - CFI probe for this lun hasn't completed  * CFI_BBR_NO_LUN           - this lun doesn't exist, as far as CFI knows  * CFI_BBR_NO_MEM           - memory allocation error  * CFI_BBR_BAD_LEN          - data length isn't a multiple of the blocksize  * CFI_BBR_RESERV_CONFLICT  - another initiator has this lun reserved, so  *                            we can't issue I/O at all.  * CFI_BBR_LUN_STOPPED      - the lun is powered off.  * CFI_BBR_LUN_OFFLINE_CTL  - the lun is offline from a CTL standpoint  * CFI_BBR_LUN_OFFLINE_RC   - the lun is offline from a RAIDCore standpoint.  *                            This is bad, because it basically means we've  *                            had a double failure on the LUN.  * CFI_BBR_SCSI_ERROR       - generic SCSI error, see status byte and sense  *                            data for more resolution if you want it.  * CFI_BBR_ERROR            - the catch-all error code.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CFI_BBR_SUCCESS
block|,
name|CFI_BBR_LUN_UNCONFIG
block|,
name|CFI_BBR_NO_LUN
block|,
name|CFI_BBR_NO_MEM
block|,
name|CFI_BBR_BAD_LEN
block|,
name|CFI_BBR_RESERV_CONFLICT
block|,
name|CFI_BBR_LUN_STOPPED
block|,
name|CFI_BBR_LUN_OFFLINE_CTL
block|,
name|CFI_BBR_LUN_OFFLINE_RC
block|,
name|CFI_BBR_SCSI_ERROR
block|,
name|CFI_BBR_ERROR
block|, }
name|cfi_bbrread_status
typedef|;
end_typedef

begin_struct
struct|struct
name|cfi_task_bbrread
block|{
name|int
name|lun_num
decl_stmt|;
comment|/* lun number */
name|uint64_t
name|lba
decl_stmt|;
comment|/* logical block address */
name|int
name|len
decl_stmt|;
comment|/* length in bytes */
name|cfi_bbrread_status
name|status
decl_stmt|;
comment|/* BBR status */
name|uint8_t
name|scsi_status
decl_stmt|;
comment|/* SCSI status */
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
comment|/* SCSI sense data */
block|}
struct|;
end_struct

begin_union
union|union
name|cfi_taskinfo
block|{
name|struct
name|cfi_task_startstop
name|startstop
decl_stmt|;
name|struct
name|cfi_task_bbrread
name|bbrread
decl_stmt|;
block|}
union|;
end_union

begin_struct_decl
struct_decl|struct
name|cfi_metatask
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|cfi_cb_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|cfi_metatask
modifier|*
name|metatask
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|cfi_metatask
block|{
name|cfi_tasktype
name|tasktype
decl_stmt|;
comment|/* passed to CFI */
name|cfi_mt_status
name|status
decl_stmt|;
comment|/* returned from CFI */
name|union
name|cfi_taskinfo
name|taskinfo
decl_stmt|;
comment|/* returned from CFI */
name|struct
name|ctl_mem_element
modifier|*
name|element
decl_stmt|;
comment|/* used by CFI, don't touch*/
name|cfi_cb_t
name|callback
decl_stmt|;
comment|/* passed to CFI */
name|void
modifier|*
name|callback_arg
decl_stmt|;
comment|/* passed to CFI */
name|STAILQ_ENTRY
argument_list|(
argument|cfi_metatask
argument_list|)
name|links
expr_stmt|;
comment|/* used by CFI, don't touch*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CTL_CFI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This is the API for sending meta commands (commands that are sent to more  * than one LUN) to the internal frontend:  *  - Allocate a metatask using cfi_alloc_metatask().  can_wait == 0 means  *    that you're calling from an interrupt context.  can_wait == 1 means  *    that you're calling from a thread context and don't mind waiting to  *    allocate memory.  *  - Setup the task type, callback and callback argument.  *  - Call cfi_action().  *  - When the callback comes, note the status and any per-command status  *    (see the taskinfo union) and then free the metatask with  *    cfi_free_metatask().  */
end_comment

begin_function_decl
name|struct
name|cfi_metatask
modifier|*
name|cfi_alloc_metatask
parameter_list|(
name|int
name|can_wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfi_free_metatask
parameter_list|(
name|struct
name|cfi_metatask
modifier|*
name|metatask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfi_action
parameter_list|(
name|struct
name|cfi_metatask
modifier|*
name|metatask
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_FRONTEND_INTERNAL_H_ */
end_comment

begin_comment
comment|/*  * vim: ts=8  */
end_comment

end_unit

