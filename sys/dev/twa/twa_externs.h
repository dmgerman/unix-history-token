begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-04 3ware, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  */
end_comment

begin_comment
comment|/* Global data structures */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|twa_fw_img
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|twa_fw_img_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|twa_message
name|twa_aen_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|twa_aen_severity_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|twa_message
name|twa_error_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in twa.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_setup
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do early driver/controller setup */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_deinit_ctlr
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stop controller */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_interrupt
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ISR */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_ioctl
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* handle user request */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_enable_interrupts
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* enable controller interrupts */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_disable_interrupts
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disable controller interrupts */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_complete_io
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* I/O completion callback */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_reset
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* (soft) reset controller */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_submit_io
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wrapper to twa_start */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_start
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* submit command to controller */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|twa_find_msg_string
parameter_list|(
name|struct
name|twa_message
modifier|*
name|table
parameter_list|,
name|u_int16_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lookup a msg */
end_comment

begin_function_decl
specifier|extern
name|struct
name|twa_request
modifier|*
name|twa_get_request
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get a req pkt from free pool */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_release_request
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* put a req pkt back into free pool */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_describe_controller
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* describe controller info */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_print_controller
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* print controller state */
end_comment

begin_comment
comment|/* Functions in twa_freebsd.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_write_pci_config
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|u_int32_t
name|value
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* write to pci config space */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_alloc_req_pkts
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|int
name|num_reqs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* alloc req& cmd pkts */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_map_request
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* copy cmd pkt& data to DMA'able memory */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_unmap_request
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* undo mapping */
end_comment

begin_comment
comment|/* Functions in twa_cam.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_request_bus_scan
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* request CAM for a bus scan */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_send_scsi_cmd
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* send down a SCSI cmd */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_scsi_complete
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* complete a SCSI cmd by calling CAM */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_drain_busy_queue
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* drain busy queue (during reset) */
end_comment

begin_function_decl
specifier|extern
name|int
name|twa_cam_setup
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* attach to CAM */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_cam_detach
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* detach from CAM */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_allow_new_requests
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|,
name|void
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unfreeze ccb flow from CAM */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_disallow_new_requests
parameter_list|(
name|struct
name|twa_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* freeze ccb flow from CAM */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_set_timer
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a timer to time a given request */
end_comment

begin_function_decl
specifier|extern
name|void
name|twa_unset_timer
parameter_list|(
name|struct
name|twa_request
modifier|*
name|tr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unset a previously set timer */
end_comment

end_unit

