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
name|proc
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

begin_decl_stmt
name|int
name|krpc_call
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
name|_sin
operator|,
name|u_int
name|prog
operator|,
name|u_int
name|vers
operator|,
name|u_int
name|func
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|data
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|from
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krpc_portmap
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
name|_sin
operator|,
name|u_int
name|prog
operator|,
name|u_int
name|vers
operator|,
name|u_int16_t
operator|*
name|portp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|xdr_string_encode
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

