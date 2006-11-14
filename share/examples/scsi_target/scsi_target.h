begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SCSI Target Emulator  *  * Copyright (c) 2002 Nate Lawson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_TARGET_H
end_define

begin_comment
comment|/*  * Maximum number of parallel commands to accept,  * 256 for Fibre Channel (SPI is 16).  */
end_comment

begin_define
define|#
directive|define
name|MAX_INITIATORS
value|256
end_define

begin_define
define|#
directive|define
name|SECTOR_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|MAX_EVENTS
value|(MAX_INITIATORS + 5)
end_define

begin_comment
comment|/* kqueue for AIO, signals */
end_comment

begin_comment
comment|/* Additional SCSI 3 defines for inquiry response */
end_comment

begin_define
define|#
directive|define
name|SID_Addr16
value|0x0100
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|io_queue
argument_list|,
name|ccb_hdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Offset into the private CCB area for storing our descriptor */
end_comment

begin_define
define|#
directive|define
name|targ_descr
value|periph_priv.entries[1].ptr
end_define

begin_comment
comment|/* Descriptor attached to each ATIO */
end_comment

begin_struct
struct|struct
name|atio_descr
block|{
name|off_t
name|base_off
decl_stmt|;
comment|/* Base offset for ATIO */
name|uint
name|total_len
decl_stmt|;
comment|/* Total xfer len for this ATIO */
name|uint
name|init_req
decl_stmt|;
comment|/* Transfer count requested to/from init */
name|uint
name|init_ack
decl_stmt|;
comment|/* Data transferred ok to/from init */
name|uint
name|targ_req
decl_stmt|;
comment|/* Transfer count requested to/from target */
name|uint
name|targ_ack
decl_stmt|;
comment|/* Data transferred ok to/from target */
name|int
name|flags
decl_stmt|;
comment|/* Flags for CTIOs */
name|u_int8_t
modifier|*
name|cdb
decl_stmt|;
comment|/* Pointer to received CDB */
comment|/* List of completed AIO/CTIOs */
name|struct
name|io_queue
name|cmplt_io
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|ATIO_WORK
block|,
name|AIO_DONE
block|,
name|CTIO_DONE
block|}
name|io_ops
typedef|;
end_typedef

begin_comment
comment|/* Descriptor attached to each CTIO */
end_comment

begin_struct
struct|struct
name|ctio_descr
block|{
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* Backing store */
name|off_t
name|offset
decl_stmt|;
comment|/* Position in transfer (for file, */
comment|/* doesn't start at 0) */
name|struct
name|aiocb
name|aiocb
decl_stmt|;
comment|/* AIO descriptor for this CTIO */
name|struct
name|ccb_accept_tio
modifier|*
name|atio
decl_stmt|;
comment|/* ATIO we are satisfying */
name|io_ops
name|event
decl_stmt|;
comment|/* Event that queued this CTIO */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|UA_NONE
init|=
literal|0x00
block|,
name|UA_POWER_ON
init|=
literal|0x01
block|,
name|UA_BUS_RESET
init|=
literal|0x02
block|,
name|UA_BDR
init|=
literal|0x04
block|}
name|ua_types
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|CA_NONE
init|=
literal|0x00
block|,
name|CA_UNIT_ATTN
init|=
literal|0x01
block|,
name|CA_CMD_SENSE
init|=
literal|0x02
block|}
name|ca_types
typedef|;
end_typedef

begin_struct
struct|struct
name|initiator_state
block|{
name|ua_types
name|orig_ua
decl_stmt|;
name|ca_types
name|orig_ca
decl_stmt|;
name|ua_types
name|pending_ua
decl_stmt|;
name|ca_types
name|pending_ca
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global functions */
end_comment

begin_function_decl
specifier|extern
name|cam_status
name|tcmd_init
parameter_list|(
name|u_int16_t
name|req_inq_flags
parameter_list|,
name|u_int16_t
name|sim_inq_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcmd_handle
parameter_list|(
name|struct
name|ccb_accept_tio
modifier|*
name|atio
parameter_list|,
name|struct
name|ccb_scsiio
modifier|*
name|ctio
parameter_list|,
name|io_ops
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcmd_sense
parameter_list|(
name|u_int
name|init_id
parameter_list|,
name|struct
name|ccb_scsiio
modifier|*
name|ctio
parameter_list|,
name|u_int8_t
name|flags
parameter_list|,
name|u_int8_t
name|asc
parameter_list|,
name|u_int8_t
name|ascq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcmd_ua
parameter_list|(
name|u_int
name|init_id
parameter_list|,
name|ua_types
name|new_ua
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|work_atio
parameter_list|(
name|struct
name|ccb_accept_tio
modifier|*
name|atio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|send_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_ccb
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|u_int
name|min
parameter_list|(
name|u_int
name|a
parameter_list|,
name|u_int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_TARGET_H */
end_comment

end_unit

