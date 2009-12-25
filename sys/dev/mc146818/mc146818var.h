begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Izumi Tsutsui.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: mc146818var.h,v 1.7 2008/05/14 13:29:29 tsutsui Exp $  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|mc146818_softc
block|{
name|bus_space_tag_t
name|sc_bst
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sc_bsh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* hardware mutex */
name|u_char
name|sc_rega
decl_stmt|;
comment|/* register A */
name|u_char
name|sc_regb
decl_stmt|;
comment|/* register B */
name|u_int
name|sc_year0
decl_stmt|;
comment|/* year counter offset */
name|u_int
name|sc_flag
decl_stmt|;
comment|/* MD flags */
define|#
directive|define
name|MC146818_NO_CENT_ADJUST
value|0x0001
comment|/* don't adjust century */
define|#
directive|define
name|MC146818_BCD
value|0x0002
comment|/* use BCD mode */
define|#
directive|define
name|MC146818_12HR
value|0x0004
comment|/* use AM/PM mode */
comment|/* MD chip register read/write functions */
name|u_int
function_decl|(
modifier|*
name|sc_mcread
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|reg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_mcwrite
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
comment|/* MD century get/set functions */
name|u_int
function_decl|(
modifier|*
name|sc_getcent
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_setcent
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|cent
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Default read/write functions */
end_comment

begin_function_decl
name|u_int
name|mc146818_def_read
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mc146818_def_write
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Chip attach function */
end_comment

begin_function_decl
name|int
name|mc146818_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Methods for the clock interface */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|int
name|mc146818_getsecs
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|secp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mc146818_gettime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mc146818_settime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

end_unit

