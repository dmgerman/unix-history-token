begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic support for remote debugging interfaces.     Copyright 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"serial.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"dcache.h"
end_include

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
name|serial_t
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
value|{ \     if (sr_settings.device) free(sr_settings.device); \     sr_settings.device = (newval); \ }
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
comment|/* This is our data cache. */
name|DCACHE
modifier|*
name|dcache
decl_stmt|;
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
argument_list|(
argument|*clear_all_breakpoints
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|memxferfunc
name|readfunc
decl_stmt|;
name|memxferfunc
name|writefunc
decl_stmt|;
name|void
argument_list|(
argument|*checkin
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
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
comment|/* get and set dcache. */
end_comment

begin_define
define|#
directive|define
name|gr_get_dcache
parameter_list|()
value|(gr_settings->dcache)
end_define

begin_define
define|#
directive|define
name|gr_set_dcache
parameter_list|(
name|newval
parameter_list|)
value|(gr_settings->dcache = (newval))
end_define

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

begin_decl_stmt
name|int
name|gr_fetch_word
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gr_multi_scan
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|list
index|[]
operator|,
name|int
name|passthrough
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sr_get_hex_digit
name|PARAMS
argument_list|(
operator|(
name|int
name|ignore_space
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sr_pollchar
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sr_readchar
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sr_timed_read
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|sr_get_hex_word
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_close
name|PARAMS
argument_list|(
operator|(
name|int
name|quitting
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_create_inferior
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|execfile
operator|,
name|char
operator|*
name|args
operator|,
name|char
operator|*
operator|*
name|env
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_detach
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_files_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|target_ops
operator|*
name|ops
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_generic_checkin
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_kill
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_mourn
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_prepare_to_store
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_store_word
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|,
name|int
name|word
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sr_expect
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sr_get_hex_byte
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|byt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sr_scan_args
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|proto
operator|,
name|char
operator|*
name|args
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sr_write
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|a
operator|,
name|int
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sr_write_cr
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|,
name|int
name|from_tty
operator|,
expr|struct
name|gr_settings
operator|*
name|gr_settings
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gr_load_image
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REMOTE_UTILS_H */
end_comment

end_unit

