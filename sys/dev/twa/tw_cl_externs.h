begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_CL_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|TW_CL_EXTERNS_H
end_define

begin_comment
comment|/*  * Data structures and functions global to the Common Layer.  */
end_comment

begin_decl_stmt
specifier|extern
name|TW_INT8
name|tw_cli_fw_img
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TW_INT32
name|tw_cli_fw_img_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TW_INT8
modifier|*
name|tw_cli_severity_string_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do controller initialization. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_start_ctlr
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Establish a logical connection with the firmware on the controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_init_connection
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_UINT16
name|message_credits
parameter_list|,
name|TW_UINT32
name|set_features
parameter_list|,
name|TW_UINT16
name|current_fw_srl
parameter_list|,
name|TW_UINT16
name|current_fw_arch_id
parameter_list|,
name|TW_UINT16
name|current_fw_branch
parameter_list|,
name|TW_UINT16
name|current_fw_build
parameter_list|,
name|TW_UINT16
modifier|*
name|fw_on_ctlr_srl
parameter_list|,
name|TW_UINT16
modifier|*
name|fw_on_ctlr_arch_id
parameter_list|,
name|TW_UINT16
modifier|*
name|fw_on_ctlr_branch
parameter_list|,
name|TW_UINT16
modifier|*
name|fw_on_ctlr_build
parameter_list|,
name|TW_UINT32
modifier|*
name|init_connect_result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in tw_cl_io.c */
end_comment

begin_comment
comment|/* Submit a command packet to the firmware on the controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_submit_cmd
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get a firmware parameter. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_get_param
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_INT32
name|table_id
parameter_list|,
name|TW_INT32
name|parameter_id
parameter_list|,
name|TW_VOID
modifier|*
name|param_data
parameter_list|,
name|TW_INT32
name|size
parameter_list|,
name|TW_VOID
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a firmware parameter. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_set_param
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_INT32
name|table_id
parameter_list|,
name|TW_INT32
name|param_id
parameter_list|,
name|TW_INT32
name|param_size
parameter_list|,
name|TW_VOID
modifier|*
name|data
parameter_list|,
name|TW_VOID
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Submit a command to the firmware and poll for completion. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_submit_and_poll_request
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|,
name|TW_UINT32
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Soft reset the controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_soft_reset
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send down a SCSI command to the firmware (usually, an internal Req Sense. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_send_scsi_cmd
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|,
name|TW_INT32
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get an AEN from the firmware (by sending down a Req Sense). */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_get_aen
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill in the scatter/gather list. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_fill_sg_list
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_VOID
modifier|*
name|sgl_src
parameter_list|,
name|TW_VOID
modifier|*
name|sgl_dest
parameter_list|,
name|TW_INT32
name|num_sgl_entries
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in tw_cl_intr.c */
end_comment

begin_comment
comment|/* Process a host interrupt. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_process_host_intr
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Process an attention interrupt. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_process_attn_intr
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Process a command interrupt. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_process_cmd_intr
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Process a response interrupt from the controller. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_process_resp_intr
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Submit any requests in the pending queue to the firmware. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_submit_pending_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Process all requests in the complete queue. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_process_complete_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CL internal callback for SCSI/fw passthru requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_complete_io
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Completion routine for SCSI requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_scsi_complete
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Callback for get/set param requests. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_param_callback
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Callback for Req Sense commands to get AEN's. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_aen_callback
parameter_list|(
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decide what to do with a retrieved AEN. */
end_comment

begin_function_decl
specifier|extern
name|TW_UINT16
name|tw_cli_manage_aen
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|struct
name|tw_cli_req_context
modifier|*
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable controller interrupts. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_enable_interrupts
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable controller interrupts. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_disable_interrupts
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in tw_cl_misc.c */
end_comment

begin_comment
comment|/* Print if dbg_level is appropriate (by calling OS Layer). */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_dbg_printf
parameter_list|(
name|TW_UINT8
name|dbg_level
parameter_list|,
name|struct
name|tw_cl_ctlr_handle
modifier|*
name|ctlr_handle
parameter_list|,
specifier|const
name|TW_INT8
modifier|*
name|cur_func
parameter_list|,
name|TW_INT8
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Describe meaning of each set bit in the given register. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT8
modifier|*
name|tw_cli_describe_bits
parameter_list|(
name|TW_UINT32
name|reg
parameter_list|,
name|TW_INT8
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Complete all requests in the complete queue with a RESET status. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_drain_complete_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Complete all requests in the busy queue with a RESET status. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_drain_busy_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Complete all requests in the pending queue with a RESET status. */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_drain_pending_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drain the controller response queue. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_drain_response_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find a particular response in the controller response queue. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_find_response
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_INT32
name|req_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drain the controller AEN queue. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_drain_aen_queue
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine if a given AEN has been posted by the firmware. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_find_aen
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_UINT16
name|aen_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Poll for a given status to show up in the firmware status register. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_poll_status
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_UINT32
name|status
parameter_list|,
name|TW_UINT32
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get a free CL internal request context packet. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|tw_cli_req_context
modifier|*
name|tw_cli_get_request
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Notify OSL of controller info (fw/BIOS versions, etc.). */
end_comment

begin_function_decl
specifier|extern
name|TW_VOID
name|tw_cli_notify_ctlr_info
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make sure that the firmware status register reports a proper status. */
end_comment

begin_function_decl
specifier|extern
name|TW_INT32
name|tw_cli_check_ctlr_state
parameter_list|(
name|struct
name|tw_cli_ctlr_context
modifier|*
name|ctlr
parameter_list|,
name|TW_UINT32
name|status_reg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_CL_EXTERNS_H */
end_comment

end_unit

