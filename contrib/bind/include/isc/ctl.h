begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CTL_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_CTL_H
end_define

begin_comment
comment|/*  * Copyright (c) 1998,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: ctl.h,v 8.9 1999/08/08 20:16:45 vixie Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventlib.h>
end_include

begin_comment
comment|/* Macros. */
end_comment

begin_define
define|#
directive|define
name|CTL_MORE
value|0x0001
end_define

begin_comment
comment|/* More will be / should be sent. */
end_comment

begin_define
define|#
directive|define
name|CTL_EXIT
value|0x0002
end_define

begin_comment
comment|/* Close connection after this. */
end_comment

begin_define
define|#
directive|define
name|CTL_DATA
value|0x0004
end_define

begin_comment
comment|/* Go into / this is DATA mode. */
end_comment

begin_comment
comment|/* Types. */
end_comment

begin_struct_decl
struct_decl|struct
name|ctl_cctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ctl_sctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ctl_sess
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ctl_verb
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|ctl_severity
block|{
name|ctl_debug
block|,
name|ctl_warning
block|,
name|ctl_error
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_logfunc
function_decl|)
parameter_list|(
name|enum
name|ctl_severity
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_verbfunc
function_decl|)
parameter_list|(
name|struct
name|ctl_sctx
modifier|*
parameter_list|,
name|struct
name|ctl_sess
modifier|*
parameter_list|,
specifier|const
name|struct
name|ctl_verb
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|rest
parameter_list|,
name|u_int
name|respflags
parameter_list|,
name|void
modifier|*
name|respctx
parameter_list|,
name|void
modifier|*
name|uctx
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_srvrdone
function_decl|)
parameter_list|(
name|struct
name|ctl_sctx
modifier|*
parameter_list|,
name|struct
name|ctl_sess
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ctl_clntdone
function_decl|)
parameter_list|(
name|struct
name|ctl_cctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ctl_verb
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|ctl_verbfunc
name|func
decl_stmt|;
specifier|const
name|char
modifier|*
name|help
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* General symbols. */
end_comment

begin_define
define|#
directive|define
name|ctl_logger
value|__ctl_logger
end_define

begin_function_decl
name|void
name|ctl_logger
parameter_list|(
name|enum
name|ctl_severity
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Client symbols. */
end_comment

begin_define
define|#
directive|define
name|ctl_client
value|__ctl_client
end_define

begin_define
define|#
directive|define
name|ctl_endclient
value|__ctl_endclient
end_define

begin_define
define|#
directive|define
name|ctl_command
value|__ctl_command
end_define

begin_function_decl
name|struct
name|ctl_cctx
modifier|*
name|ctl_client
parameter_list|(
name|evContext
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|ctl_clntdone
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|ctl_logfunc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_endclient
parameter_list|(
name|struct
name|ctl_cctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_command
parameter_list|(
name|struct
name|ctl_cctx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|ctl_clntdone
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Server symbols. */
end_comment

begin_define
define|#
directive|define
name|ctl_server
value|__ctl_server
end_define

begin_define
define|#
directive|define
name|ctl_endserver
value|__ctl_endserver
end_define

begin_define
define|#
directive|define
name|ctl_response
value|__ctl_response
end_define

begin_define
define|#
directive|define
name|ctl_sendhelp
value|__ctl_sendhelp
end_define

begin_define
define|#
directive|define
name|ctl_getcsctx
value|__ctl_getcsctx
end_define

begin_define
define|#
directive|define
name|ctl_setcsctx
value|__ctl_setcsctx
end_define

begin_function_decl
name|struct
name|ctl_sctx
modifier|*
name|ctl_server
parameter_list|(
name|evContext
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|ctl_verb
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|ctl_logfunc
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_endserver
parameter_list|(
name|struct
name|ctl_sctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_response
parameter_list|(
name|struct
name|ctl_sess
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|ctl_srvrdone
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_sendhelp
parameter_list|(
name|struct
name|ctl_sess
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ctl_getcsctx
parameter_list|(
name|struct
name|ctl_sess
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ctl_setcsctx
parameter_list|(
name|struct
name|ctl_sess
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*ISC_CTL_H*/
end_comment

end_unit

