begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: krpc.h,v 1.4 1995/12/19 23:07:11 cgd Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$	*/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|krpc_call
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|_sin
parameter_list|,
name|u_int
name|prog
parameter_list|,
name|u_int
name|vers
parameter_list|,
name|u_int
name|func
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|data
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|from
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krpc_portmap
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|_sin
parameter_list|,
name|u_int
name|prog
parameter_list|,
name|u_int
name|vers
parameter_list|,
name|u_int16_t
modifier|*
name|portp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|xdr_string_encode
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * RPC definitions for the portmapper  */
end_comment

begin_define
define|#
directive|define
name|PMAPPORT
value|111
end_define

begin_define
define|#
directive|define
name|PMAPPROG
value|100000
end_define

begin_define
define|#
directive|define
name|PMAPVERS
value|2
end_define

begin_define
define|#
directive|define
name|PMAPPROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|PMAPPROC_SET
value|1
end_define

begin_define
define|#
directive|define
name|PMAPPROC_UNSET
value|2
end_define

begin_define
define|#
directive|define
name|PMAPPROC_GETPORT
value|3
end_define

begin_define
define|#
directive|define
name|PMAPPROC_DUMP
value|4
end_define

begin_define
define|#
directive|define
name|PMAPPROC_CALLIT
value|5
end_define

end_unit

