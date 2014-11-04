begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DPV_H_
end_ifndef

begin_define
define|#
directive|define
name|_DPV_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Data to process */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|long
name|dpv_overall_read
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interrupt flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dpv_interrupt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to TRUE in interrupt handler */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dpv_abort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to true in callback to abort */
end_comment

begin_comment
comment|/*  * Display types for use with display_type member of dpv_config structure  */
end_comment

begin_enum
enum|enum
name|dpv_display
block|{
name|DPV_DISPLAY_LIBDIALOG
init|=
literal|0
block|,
comment|/* Display using dialog(3) (default) */
name|DPV_DISPLAY_STDOUT
block|,
comment|/* Display on stdout */
name|DPV_DISPLAY_DIALOG
block|,
comment|/* Display using spawned dialog(1) */
name|DPV_DISPLAY_XDIALOG
block|,
comment|/* Display using spawned Xdialog(1) */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Output types for use with output_type member of dpv_config structure  */
end_comment

begin_enum
enum|enum
name|dpv_output
block|{
name|DPV_OUTPUT_NONE
init|=
literal|0
block|,
comment|/* No output (default) */
name|DPV_OUTPUT_FILE
block|,
comment|/* Read `output' member as file path */
name|DPV_OUTPUT_SHELL
block|,
comment|/* Read `output' member as shell cmd */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Activity types for use with status member of dpv_file_node structure.  * If you set a status other than DPV_STATUS_RUNNING on the current file in the  * action callback of dpv_config structure, you'll end callbacks for that  * dpv_file_node.  */
end_comment

begin_enum
enum|enum
name|dpv_status
block|{
name|DPV_STATUS_RUNNING
init|=
literal|0
block|,
comment|/* Running (default) */
name|DPV_STATUS_DONE
block|,
comment|/* Completed */
name|DPV_STATUS_FAILED
block|,
comment|/* Oops, something went wrong */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Anatomy of file option; pass an array of these as dpv() file_list argument  * terminated with a NULL pointer.  */
end_comment

begin_struct
struct|struct
name|dpv_file_node
block|{
name|enum
name|dpv_status
name|status
decl_stmt|;
comment|/* status of read operation */
name|char
modifier|*
name|msg
decl_stmt|;
comment|/* display instead of "Done/Fail" */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of file to read */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* path to file */
name|long
name|long
name|length
decl_stmt|;
comment|/* expected size */
name|long
name|long
name|read
decl_stmt|;
comment|/* number units read (e.g., bytes) */
name|struct
name|dpv_file_node
modifier|*
name|next
decl_stmt|;
comment|/* pointer to next (end with NULL) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Anatomy of config option to pass as dpv() config argument  */
end_comment

begin_struct
struct|struct
name|dpv_config
block|{
name|enum
name|dpv_display
name|display_type
decl_stmt|;
comment|/* Display (default TYPE_LIBDIALOG) */
name|enum
name|dpv_output
name|output_type
decl_stmt|;
comment|/* Output (default TYPE_NONE) */
name|int
name|debug
decl_stmt|;
comment|/* Enable debugging output on stderr */
name|int
name|display_limit
decl_stmt|;
comment|/* Files per `page'. Default -1 */
name|int
name|label_size
decl_stmt|;
comment|/* Label size. Default 28 */
name|int
name|pbar_size
decl_stmt|;
comment|/* Mini-progress size. See dpv(3) */
name|int
name|dialog_updates_per_second
decl_stmt|;
comment|/* Progress updates/s. Default 16 */
name|int
name|status_updates_per_second
decl_stmt|;
comment|/* dialog(3) status updates/second. 	   	                            * Default 2 */
name|uint16_t
name|options
decl_stmt|;
comment|/* Special options. Default 0 */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* widget title */
name|char
modifier|*
name|backtitle
decl_stmt|;
comment|/* Widget backtitle */
name|char
modifier|*
name|aprompt
decl_stmt|;
comment|/* Prompt append. Default NULL */
name|char
modifier|*
name|pprompt
decl_stmt|;
comment|/* Prompt prefix. Default NULL */
name|char
modifier|*
name|msg_done
decl_stmt|;
comment|/* Progress text. Default `Done' */
name|char
modifier|*
name|msg_fail
decl_stmt|;
comment|/* Progress text. Default `Fail' */
name|char
modifier|*
name|msg_pending
decl_stmt|;
comment|/* Progress text. Default `Pending' */
name|char
modifier|*
name|output
decl_stmt|;
comment|/* Output format string; see dpv(3) */
specifier|const
name|char
modifier|*
name|status_solo
decl_stmt|;
comment|/* dialog(3) solo-status format. 	                          * Default DPV_STATUS_SOLO */
specifier|const
name|char
modifier|*
name|status_many
decl_stmt|;
comment|/* dialog(3) many-status format. 	                          * Default DPV_STATUS_MANY */
comment|/* 	 * Function pointer; action to perform data transfer 	 */
name|int
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|struct
name|dpv_file_node
modifier|*
name|file
parameter_list|,
name|int
name|out
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros for dpv() options bitmask argument  */
end_comment

begin_define
define|#
directive|define
name|DPV_TEST_MODE
value|0x0001
end_define

begin_comment
comment|/* Test mode (fake reading data) */
end_comment

begin_define
define|#
directive|define
name|DPV_WIDE_MODE
value|0x0002
end_define

begin_comment
comment|/* prefix/append bump dialog width */
end_comment

begin_define
define|#
directive|define
name|DPV_NO_LABELS
value|0x0004
end_define

begin_comment
comment|/* Hide file_node.name labels */
end_comment

begin_define
define|#
directive|define
name|DPV_USE_COLOR
value|0x0008
end_define

begin_comment
comment|/* Override to force color output */
end_comment

begin_define
define|#
directive|define
name|DPV_NO_OVERRUN
value|0x0010
end_define

begin_comment
comment|/* Stop transfers when they hit 100% */
end_comment

begin_comment
comment|/*  * Limits (modify with extreme care)  */
end_comment

begin_define
define|#
directive|define
name|DPV_APROMPT_MAX
value|4096
end_define

begin_comment
comment|/* Buffer size for `-a text' */
end_comment

begin_define
define|#
directive|define
name|DPV_DISPLAY_LIMIT
value|10
end_define

begin_comment
comment|/* Max file progress lines */
end_comment

begin_define
define|#
directive|define
name|DPV_PPROMPT_MAX
value|4096
end_define

begin_comment
comment|/* Buffer size for `-p text' */
end_comment

begin_define
define|#
directive|define
name|DPV_STATUS_FORMAT_MAX
value|80
end_define

begin_comment
comment|/* Buffer size for `-u format' */
end_comment

begin_comment
comment|/*  * Extra display information  */
end_comment

begin_define
define|#
directive|define
name|DPV_STATUS_SOLO
value|"%'10lli bytes read @ %'9.1f bytes/sec."
end_define

begin_define
define|#
directive|define
name|DPV_STATUS_MANY
value|(DPV_STATUS_SOLO " [%i/%i busy/wait]")
end_define

begin_comment
comment|/*  * Strings  */
end_comment

begin_define
define|#
directive|define
name|DPV_DONE_DEFAULT
value|"Done"
end_define

begin_define
define|#
directive|define
name|DPV_FAIL_DEFAULT
value|"Fail"
end_define

begin_define
define|#
directive|define
name|DPV_PENDING_DEFAULT
value|"Pending"
end_define

begin_function_decl
name|__BEGIN_DECLS
name|void
name|dpv_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dpv
parameter_list|(
name|struct
name|dpv_config
modifier|*
name|_config
parameter_list|,
name|struct
name|dpv_file_node
modifier|*
name|_file_list
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DPV_H_ */
end_comment

end_unit

