begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: irp.h,v 8.1 1999/01/18 07:46:46 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IRP_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_IRP_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|IRPD_TIMEOUT
value|30
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|IRPD_MAXSESS
value|50
end_define

begin_comment
comment|/* number of simultaneous sessions. */
end_comment

begin_define
define|#
directive|define
name|IRPD_PORT
value|6660
end_define

begin_comment
comment|/* 10 times the number of the beast. */
end_comment

begin_define
define|#
directive|define
name|IRPD_PATH
value|"/var/run/irpd"
end_define

begin_comment
comment|/* af_unix socket path */
end_comment

begin_comment
comment|/* If sets the environment variable IRPDSERVER to an IP address    (e.g. "192.5.5.1"), then that's the host the client expects irpd to be    running on. */
end_comment

begin_define
define|#
directive|define
name|IRPD_HOST_ENV
value|"IRPDSERVER"
end_define

begin_comment
comment|/* Protocol response codes.  */
end_comment

begin_define
define|#
directive|define
name|IRPD_WELCOME_CODE
value|200
end_define

begin_define
define|#
directive|define
name|IRPD_NOT_WELCOME_CODE
value|500
end_define

begin_define
define|#
directive|define
name|IRPD_GETHOST_ERROR
value|510
end_define

begin_define
define|#
directive|define
name|IRPD_GETHOST_NONE
value|210
end_define

begin_define
define|#
directive|define
name|IRPD_GETHOST_OK
value|211
end_define

begin_define
define|#
directive|define
name|IRPD_GETHOST_SETOK
value|212
end_define

begin_define
define|#
directive|define
name|IRPD_GETNET_ERROR
value|520
end_define

begin_define
define|#
directive|define
name|IRPD_GETNET_NONE
value|220
end_define

begin_define
define|#
directive|define
name|IRPD_GETNET_OK
value|221
end_define

begin_define
define|#
directive|define
name|IRPD_GETNET_SETOK
value|222
end_define

begin_define
define|#
directive|define
name|IRPD_GETUSER_ERROR
value|530
end_define

begin_define
define|#
directive|define
name|IRPD_GETUSER_NONE
value|230
end_define

begin_define
define|#
directive|define
name|IRPD_GETUSER_OK
value|231
end_define

begin_define
define|#
directive|define
name|IRPD_GETUSER_SETOK
value|232
end_define

begin_define
define|#
directive|define
name|IRPD_GETGROUP_ERROR
value|540
end_define

begin_define
define|#
directive|define
name|IRPD_GETGROUP_NONE
value|240
end_define

begin_define
define|#
directive|define
name|IRPD_GETGROUP_OK
value|241
end_define

begin_define
define|#
directive|define
name|IRPD_GETGROUP_SETOK
value|242
end_define

begin_define
define|#
directive|define
name|IRPD_GETSERVICE_ERROR
value|550
end_define

begin_define
define|#
directive|define
name|IRPD_GETSERVICE_NONE
value|250
end_define

begin_define
define|#
directive|define
name|IRPD_GETSERVICE_OK
value|251
end_define

begin_define
define|#
directive|define
name|IRPD_GETSERVICE_SETOK
value|252
end_define

begin_define
define|#
directive|define
name|IRPD_GETPROTO_ERROR
value|560
end_define

begin_define
define|#
directive|define
name|IRPD_GETPROTO_NONE
value|260
end_define

begin_define
define|#
directive|define
name|IRPD_GETPROTO_OK
value|261
end_define

begin_define
define|#
directive|define
name|IRPD_GETPROTO_SETOK
value|262
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_ERROR
value|570
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_NONE
value|270
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_OK
value|271
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_NOMORE
value|272
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_MATCHES
value|273
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_NOMATCH
value|274
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_SETOK
value|275
end_define

begin_define
define|#
directive|define
name|IRPD_GETNETGR_SETERR
value|276
end_define

begin_define
define|#
directive|define
name|irs_irp_read_body
value|__irs_irp_read_body
end_define

begin_define
define|#
directive|define
name|irs_irp_read_response
value|__irs_irp_read_response
end_define

begin_define
define|#
directive|define
name|irs_irp_disconnect
value|__irs_irp_disconnect
end_define

begin_define
define|#
directive|define
name|irs_irp_connect
value|__irs_irp_connect
end_define

begin_define
define|#
directive|define
name|irs_irp_connection_setup
value|__irs_irp_connection_setup
end_define

begin_define
define|#
directive|define
name|irs_irp_send_command
value|__irs_irp_send_command
end_define

begin_struct_decl
struct_decl|struct
name|irp_p
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|irs_irp_read_body
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_read_response
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|,
name|char
modifier|*
name|text
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|irs_irp_disconnect
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_connect
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_is_connected
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_connection_setup
parameter_list|(
name|struct
name|irp_p
modifier|*
name|cxndata
parameter_list|,
name|int
modifier|*
name|warned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_send_command
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_get_full_response
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|,
name|int
modifier|*
name|code
parameter_list|,
name|char
modifier|*
name|text
parameter_list|,
name|size_t
name|textlen
parameter_list|,
name|char
modifier|*
modifier|*
name|body
parameter_list|,
name|size_t
modifier|*
name|bodylen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|irs_irp_read_line
parameter_list|(
name|struct
name|irp_p
modifier|*
name|pvt
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

