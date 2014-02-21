begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic support for remote debugging interfaces.     Copyright 1993, 1994, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REMOTE_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|REMOTE_UTILS_H
end_define

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_struct_decl
struct_decl|struct
name|serial
struct_decl|;
end_struct_decl

begin_comment
comment|/* Stuff that should be shared (and handled consistently) among the various    remote targets.  */
end_comment

begin_struct
struct|struct
name|_sr_settings
block|{
name|unsigned
name|int
name|timeout
decl_stmt|;
name|int
name|retries
decl_stmt|;
name|char
modifier|*
name|device
decl_stmt|;
name|struct
name|serial
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_sr_settings
name|sr_settings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get and set debug value. */
end_comment

begin_define
define|#
directive|define
name|sr_get_debug
parameter_list|()
value|(remote_debug)
end_define

begin_define
define|#
directive|define
name|sr_set_debug
parameter_list|(
name|newval
parameter_list|)
value|(remote_debug = (newval))
end_define

begin_comment
comment|/* get and set timeout. */
end_comment

begin_define
define|#
directive|define
name|sr_get_timeout
parameter_list|()
value|(sr_settings.timeout)
end_define

begin_define
define|#
directive|define
name|sr_set_timeout
parameter_list|(
name|newval
parameter_list|)
value|(sr_settings.timeout = (newval))
end_define

begin_comment
comment|/* get and set device. */
end_comment

begin_define
define|#
directive|define
name|sr_get_device
parameter_list|()
value|(sr_settings.device)
end_define

begin_define
define|#
directive|define
name|sr_set_device
parameter_list|(
name|newval
parameter_list|)
define|\
value|{ \     if (sr_settings.device) xfree (sr_settings.device); \     sr_settings.device = (newval); \ }
end_define

begin_comment
comment|/* get and set descriptor value. */
end_comment

begin_define
define|#
directive|define
name|sr_get_desc
parameter_list|()
value|(sr_settings.desc)
end_define

begin_define
define|#
directive|define
name|sr_set_desc
parameter_list|(
name|newval
parameter_list|)
value|(sr_settings.desc = (newval))
end_define

begin_comment
comment|/* get and set retries. */
end_comment

begin_define
define|#
directive|define
name|sr_get_retries
parameter_list|()
value|(sr_settings.retries)
end_define

begin_define
define|#
directive|define
name|sr_set_retries
parameter_list|(
name|newval
parameter_list|)
value|(sr_settings.retries = (newval))
end_define

begin_define
define|#
directive|define
name|sr_is_open
parameter_list|()
value|(sr_settings.desc != NULL)
end_define

begin_define
define|#
directive|define
name|sr_check_open
parameter_list|()
value|{ if (!sr_is_open()) \ 				    error ("Remote device not open"); }
end_define

begin_struct
struct|struct
name|gr_settings
block|{
name|char
modifier|*
name|prompt
decl_stmt|;
name|struct
name|target_ops
modifier|*
name|ops
decl_stmt|;
name|int
function_decl|(
modifier|*
name|clear_all_breakpoints
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|checkin
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|gr_settings
modifier|*
name|gr_settings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get and set prompt. */
end_comment

begin_define
define|#
directive|define
name|gr_get_prompt
parameter_list|()
value|(gr_settings->prompt)
end_define

begin_define
define|#
directive|define
name|gr_set_prompt
parameter_list|(
name|newval
parameter_list|)
value|(gr_settings->prompt = (newval))
end_define

begin_comment
comment|/* get and set ops. */
end_comment

begin_define
define|#
directive|define
name|gr_get_ops
parameter_list|()
value|(gr_settings->ops)
end_define

begin_define
define|#
directive|define
name|gr_set_ops
parameter_list|(
name|newval
parameter_list|)
value|(gr_settings->ops = (newval))
end_define

begin_define
define|#
directive|define
name|gr_clear_all_breakpoints
parameter_list|()
value|((gr_settings->clear_all_breakpoints)())
end_define

begin_define
define|#
directive|define
name|gr_checkin
parameter_list|()
value|((gr_settings->checkin)())
end_define

begin_comment
comment|/* Keep discarding input until we see the prompt.     The convention for dealing with the prompt is that you    o give your command    o *then* wait for the prompt.     Thus the last thing that a procedure does with the serial line    will be an gr_expect_prompt().  Exception:  resume does not    wait for the prompt, because the terminal is being handed over    to the inferior.  However, the next thing which happens after that    is a bug_wait which does wait for the prompt.    Note that this includes abnormal exit, e.g. error().  This is    necessary to prevent getting into states from which we can't    recover.  */
end_comment

begin_define
define|#
directive|define
name|gr_expect_prompt
parameter_list|()
value|sr_expect(gr_get_prompt())
end_define

begin_function_decl
name|int
name|gr_multi_scan
parameter_list|(
name|char
modifier|*
name|list
index|[]
parameter_list|,
name|int
name|passthrough
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_get_hex_digit
parameter_list|(
name|int
name|ignore_space
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_pollchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_readchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sr_timed_read
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|sr_get_hex_word
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_close
parameter_list|(
name|int
name|quitting
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_create_inferior
parameter_list|(
name|char
modifier|*
name|execfile
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|char
modifier|*
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_detach
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_files_info
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_generic_checkin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_kill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_mourn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_prepare_to_store
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sr_expect
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sr_get_hex_byte
parameter_list|(
name|char
modifier|*
name|byt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sr_scan_args
parameter_list|(
name|char
modifier|*
name|proto
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sr_write
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sr_write_cr
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_open
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|from_tty
parameter_list|,
name|struct
name|gr_settings
modifier|*
name|gr_settings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_load_image
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOTE_UTILS_H */
end_comment

end_unit

