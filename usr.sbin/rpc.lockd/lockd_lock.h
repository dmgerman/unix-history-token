begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lockd_lock.h,v 1.2 2000/06/09 14:00:54 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/* Headers and function declarations for file-locking utilities */
end_comment

begin_function_decl
name|struct
name|nlm4_holder
modifier|*
name|testlock
parameter_list|(
name|struct
name|nlm4_lock
modifier|*
name|lock
parameter_list|,
name|bool_t
name|exclusive
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|nlm_stats
name|getlock
parameter_list|(
name|nlm4_lockargs
modifier|*
name|lckarg
parameter_list|,
name|struct
name|svc_req
modifier|*
name|rqstp
parameter_list|,
specifier|const
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|nlm_stats
name|unlock
parameter_list|(
name|nlm4_lock
modifier|*
name|lock
parameter_list|,
specifier|const
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lock_answer
parameter_list|(
name|int
name|pid
parameter_list|,
name|netobj
modifier|*
name|netcookie
parameter_list|,
name|int
name|result
parameter_list|,
name|int
modifier|*
name|pid_p
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|notify
parameter_list|(
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flags for testlock, getlock& unlock */
end_comment

begin_define
define|#
directive|define
name|LOCK_ASYNC
value|0x01
end_define

begin_comment
comment|/* async version (getlock only) */
end_comment

begin_define
define|#
directive|define
name|LOCK_V4
value|0x02
end_define

begin_comment
comment|/* v4 version */
end_comment

begin_define
define|#
directive|define
name|LOCK_MON
value|0x04
end_define

begin_comment
comment|/* monitored lock (getlock only) */
end_comment

begin_define
define|#
directive|define
name|LOCK_CANCEL
value|0x08
end_define

begin_comment
comment|/* cancel, not unlock request (unlock only) */
end_comment

begin_comment
comment|/* callbacks from lock_proc.c */
end_comment

begin_function_decl
name|void
name|transmit_result
parameter_list|(
name|int
parameter_list|,
name|nlm_res
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|transmit4_result
parameter_list|(
name|int
parameter_list|,
name|nlm4_res
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CLIENT
modifier|*
name|get_client
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

