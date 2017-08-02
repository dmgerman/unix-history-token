begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005-2007 Voltaire, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_console_t.  *	This object represents the OpenSM Console object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_CONSOLE_IO_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_CONSOLE_IO_H_
end_define

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_define
define|#
directive|define
name|OSM_DISABLE_CONSOLE
value|"off"
end_define

begin_define
define|#
directive|define
name|OSM_LOCAL_CONSOLE
value|"local"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_OSM_CONSOLE_SOCKET
end_ifdef

begin_define
define|#
directive|define
name|OSM_REMOTE_CONSOLE
value|"socket"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_OSM_CONSOLE_LOOPBACK
end_ifdef

begin_define
define|#
directive|define
name|OSM_LOOPBACK_CONSOLE
value|"loopback"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OSM_CONSOLE_NAME
value|"OSM Console"
end_define

begin_define
define|#
directive|define
name|OSM_DEFAULT_CONSOLE
value|OSM_DISABLE_CONSOLE
end_define

begin_define
define|#
directive|define
name|OSM_DEFAULT_CONSOLE_PORT
value|10000
end_define

begin_define
define|#
directive|define
name|OSM_DAEMON_NAME
value|"opensm"
end_define

begin_define
define|#
directive|define
name|OSM_COMMAND_PROMPT
value|"$ "
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|osm_console
block|{
name|int
name|socket
decl_stmt|;
name|int
name|in_fd
decl_stmt|;
name|int
name|out_fd
decl_stmt|;
name|int
name|authorized
decl_stmt|;
name|FILE
modifier|*
name|in
decl_stmt|;
name|FILE
modifier|*
name|out
decl_stmt|;
name|char
name|client_type
index|[
literal|32
index|]
decl_stmt|;
name|char
name|client_ip
index|[
literal|64
index|]
decl_stmt|;
name|char
name|client_hn
index|[
literal|128
index|]
decl_stmt|;
block|}
name|osm_console_t
typedef|;
end_typedef

begin_function_decl
name|void
name|osm_console_prompt
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osm_console_init
parameter_list|(
name|osm_subn_opt_t
modifier|*
name|opt
parameter_list|,
name|osm_console_t
modifier|*
name|p_oct
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_console_exit
parameter_list|(
name|osm_console_t
modifier|*
name|p_oct
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_console_enabled
parameter_list|(
name|osm_subn_opt_t
modifier|*
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_OSM_CONSOLE_LOOPBACK
end_ifdef

begin_function_decl
name|int
name|cio_open
parameter_list|(
name|osm_console_t
modifier|*
name|p_oct
parameter_list|,
name|int
name|new_fd
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cio_close
parameter_list|(
name|osm_console_t
modifier|*
name|p_oct
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_authorized
parameter_list|(
name|osm_console_t
modifier|*
name|p_oct
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cio_close
parameter_list|(
name|c
parameter_list|,
name|log
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_CONSOLE_IO_H_ */
end_comment

end_unit

