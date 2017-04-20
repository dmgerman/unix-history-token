begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains definitions only intended for use within  * sys/cam/scsi/scsi_enc*.c, and not in other kernel components.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCSI_ENC_INTERNAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__SCSI_ENC_INTERNAL_H__
end_define

begin_typedef
typedef|typedef
struct|struct
name|enc_element
block|{
name|uint32_t
name|enctype
range|:
literal|8
decl_stmt|,
comment|/* enclosure type */
name|subenclosure
range|:
literal|8
decl_stmt|,
comment|/* subenclosure id */
name|svalid
range|:
literal|1
decl_stmt|,
comment|/* enclosure information valid */
name|overall_status_elem
range|:
literal|1
decl_stmt|,
comment|/* 					 * This object represents generic 					 * status about all objects of this 					 * type. 					 */
name|priv
range|:
literal|14
decl_stmt|;
comment|/* private data, per object */
name|uint8_t
name|encstat
index|[
literal|4
index|]
decl_stmt|;
comment|/* state&& stats */
name|uint8_t
modifier|*
name|physical_path
decl_stmt|;
comment|/* Device physical path data. */
name|u_int
name|physical_path_len
decl_stmt|;
comment|/* Length of device path data. */
name|void
modifier|*
name|elm_private
decl_stmt|;
comment|/* per-type object data */
block|}
name|enc_element_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ENC_NONE
block|,
name|ENC_SES_SCSI2
block|,
name|ENC_SES
block|,
name|ENC_SES_PASSTHROUGH
block|,
name|ENC_SEN
block|,
name|ENC_SAFT
block|,
name|ENC_SEMB_SES
block|,
name|ENC_SEMB_SAFT
block|}
name|enctyp
typedef|;
end_typedef

begin_comment
comment|/* Platform Independent Driver Internal Definitions for enclosure devices. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|enc_softc
name|enc_softc_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|enc_fsm_state
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|fsm_fill_handler_t
parameter_list|(
name|enc_softc_t
modifier|*
name|ssc
parameter_list|,
name|struct
name|enc_fsm_state
modifier|*
name|state
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fsm_error_handler_t
parameter_list|(
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|uint32_t
name|cflags
parameter_list|,
name|uint32_t
name|sflags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fsm_done_handler_t
parameter_list|(
name|enc_softc_t
modifier|*
name|ssc
parameter_list|,
name|struct
name|enc_fsm_state
modifier|*
name|state
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|bufp
parameter_list|,
name|int
name|error
parameter_list|,
name|int
name|xfer_len
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|enc_fsm_state
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|page_code
decl_stmt|;
name|size_t
name|buf_size
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
name|fsm_fill_handler_t
modifier|*
name|fill
decl_stmt|;
name|fsm_done_handler_t
modifier|*
name|done
decl_stmt|;
name|fsm_error_handler_t
modifier|*
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_softc_init_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|enc_softc_invalidate_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|enc_softc_cleanup_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_init_enc_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_get_enc_status_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_set_enc_status_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_enc_status_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_get_elm_status_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_elm_status_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_set_elm_status_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_elm_status_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_get_elm_desc_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_elm_desc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_get_elm_devnames_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_elm_devnames_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|enc_handle_string_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|encioc_string_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|enc_device_found_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|enc_poll_status_t
function_decl|)
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|enc_vec
block|{
name|enc_softc_invalidate_t
modifier|*
name|softc_invalidate
decl_stmt|;
name|enc_softc_cleanup_t
modifier|*
name|softc_cleanup
decl_stmt|;
name|enc_init_enc_t
modifier|*
name|init_enc
decl_stmt|;
name|enc_get_enc_status_t
modifier|*
name|get_enc_status
decl_stmt|;
name|enc_set_enc_status_t
modifier|*
name|set_enc_status
decl_stmt|;
name|enc_get_elm_status_t
modifier|*
name|get_elm_status
decl_stmt|;
name|enc_set_elm_status_t
modifier|*
name|set_elm_status
decl_stmt|;
name|enc_get_elm_desc_t
modifier|*
name|get_elm_desc
decl_stmt|;
name|enc_get_elm_devnames_t
modifier|*
name|get_elm_devnames
decl_stmt|;
name|enc_handle_string_t
modifier|*
name|handle_string
decl_stmt|;
name|enc_device_found_t
modifier|*
name|device_found
decl_stmt|;
name|enc_poll_status_t
modifier|*
name|poll_status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|enc_cache
block|{
name|enc_element_t
modifier|*
name|elm_map
decl_stmt|;
comment|/* objects */
name|int
name|nelms
decl_stmt|;
comment|/* number of objects */
name|encioc_enc_status_t
name|enc_status
decl_stmt|;
comment|/* overall status */
name|void
modifier|*
name|private
decl_stmt|;
comment|/* per-type private data */
block|}
name|enc_cache_t
typedef|;
end_typedef

begin_comment
comment|/* Enclosure instance toplevel structure */
end_comment

begin_struct
struct|struct
name|enc_softc
block|{
name|enctyp
name|enc_type
decl_stmt|;
comment|/* type of enclosure */
name|struct
name|enc_vec
name|enc_vec
decl_stmt|;
comment|/* vector to handlers */
name|void
modifier|*
name|enc_private
decl_stmt|;
comment|/* per-type private data */
comment|/** 	 * "Published" configuration and state data available to 	 * external consumers. 	 */
name|enc_cache_t
name|enc_cache
decl_stmt|;
comment|/** 	 * Configuration and state data being actively updated 	 * by the enclosure daemon. 	 */
name|enc_cache_t
name|enc_daemon_cache
decl_stmt|;
name|struct
name|sx
name|enc_cache_lock
decl_stmt|;
name|uint8_t
name|enc_flags
decl_stmt|;
define|#
directive|define
name|ENC_FLAG_INVALID
value|0x01
define|#
directive|define
name|ENC_FLAG_INITIALIZED
value|0x02
define|#
directive|define
name|ENC_FLAG_SHUTDOWN
value|0x04
name|union
name|ccb
name|saved_ccb
decl_stmt|;
name|struct
name|cdev
modifier|*
name|enc_dev
decl_stmt|;
name|struct
name|cam_periph
modifier|*
name|periph
decl_stmt|;
name|int
name|open_count
decl_stmt|;
comment|/* Bitmap of pending operations. */
name|uint32_t
name|pending_actions
decl_stmt|;
comment|/* The action on which the state machine is currently working. */
name|uint32_t
name|current_action
decl_stmt|;
define|#
directive|define
name|ENC_UPDATE_NONE
value|0x00
define|#
directive|define
name|ENC_UPDATE_INVALID
value|0xff
comment|/* Callout for auto-updating enclosure status */
name|struct
name|callout
name|status_updater
decl_stmt|;
name|struct
name|proc
modifier|*
name|enc_daemon
decl_stmt|;
name|struct
name|enc_fsm_state
modifier|*
name|enc_fsm_states
decl_stmt|;
name|struct
name|intr_config_hook
name|enc_boot_hold_ch
decl_stmt|;
define|#
directive|define
name|ENC_ANNOUNCE_SZ
value|400
name|char
name|announce_buf
index|[
name|ENC_ANNOUNCE_SZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|enc_cache_t
modifier|*
name|enc_other_cache
parameter_list|(
name|enc_softc_t
modifier|*
name|enc
parameter_list|,
name|enc_cache_t
modifier|*
name|primary
parameter_list|)
block|{
return|return
operator|(
name|primary
operator|==
operator|&
name|enc
operator|->
name|enc_cache
condition|?
operator|&
name|enc
operator|->
name|enc_daemon_cache
else|:
operator|&
name|enc
operator|->
name|enc_cache
operator|)
return|;
block|}
end_function

begin_comment
comment|/* SES Management mode page - SES2r20 Table 59 */
end_comment

begin_struct
struct|struct
name|ses_mgmt_mode_page
block|{
name|struct
name|scsi_mode_header_6
name|header
decl_stmt|;
name|struct
name|scsi_mode_blk_desc
name|blk_desc
decl_stmt|;
name|uint8_t
name|byte0
decl_stmt|;
comment|/* ps : 1, spf : 1, page_code : 6 */
define|#
directive|define
name|SES_MGMT_MODE_PAGE_CODE
value|0x14
name|uint8_t
name|length
decl_stmt|;
define|#
directive|define
name|SES_MGMT_MODE_PAGE_LEN
value|6
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|byte5
decl_stmt|;
comment|/* reserved : 7, enbltc : 1 */
define|#
directive|define
name|SES_MGMT_TIMED_COMP_EN
value|0x1
name|uint8_t
name|max_comp_time
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Enclosure core interface for sub-drivers */
end_comment

begin_function_decl
name|int
name|enc_runcmd
parameter_list|(
name|struct
name|enc_softc
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enc_log
parameter_list|(
name|struct
name|enc_softc
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|enc_error
parameter_list|(
name|union
name|ccb
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enc_update_request
parameter_list|(
name|enc_softc_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SES Native interface */
end_comment

begin_decl_stmt
name|enc_softc_init_t
name|ses_softc_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SAF-TE interface */
end_comment

begin_decl_stmt
name|enc_softc_init_t
name|safte_softc_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Helper macros */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SCSIENC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ENC_CFLAGS
value|CAM_RETRY_SELTO
end_define

begin_define
define|#
directive|define
name|ENC_FLAGS
value|SF_NO_PRINT | SF_RETRY_UA
end_define

begin_define
define|#
directive|define
name|STRNCMP
value|strncmp
end_define

begin_define
define|#
directive|define
name|PRINTF
value|printf
end_define

begin_define
define|#
directive|define
name|ENC_LOG
value|enc_log
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|ENC_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENC_DLOG
value|enc_log
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENC_DLOG
value|if (0) enc_log
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENC_VLOG
value|if (bootverbose) enc_log
end_define

begin_define
define|#
directive|define
name|ENC_MALLOC
parameter_list|(
name|amt
parameter_list|)
value|malloc(amt, M_SCSIENC, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|ENC_MALLOCZ
parameter_list|(
name|amt
parameter_list|)
value|malloc(amt, M_SCSIENC, M_ZERO|M_NOWAIT)
end_define

begin_comment
comment|/* Cast away const avoiding GCC warnings. */
end_comment

begin_define
define|#
directive|define
name|ENC_FREE
parameter_list|(
name|ptr
parameter_list|)
value|free((void *)((uintptr_t)ptr), M_SCSIENC)
end_define

begin_define
define|#
directive|define
name|ENC_FREE_AND_NULL
parameter_list|(
name|ptr
parameter_list|)
value|do {	\ 	if (ptr != NULL) {		\ 		ENC_FREE(ptr);		\ 		ptr = NULL;		\ 	}				\ } while(0)
end_define

begin_define
define|#
directive|define
name|MEMZERO
value|bzero
end_define

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|amt
parameter_list|)
value|bcopy(src, dest, amt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SCSI_ENC_INTERNAL_H__ */
end_comment

end_unit

