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

begin_decl_stmt
name|struct
name|nlm4_holder
modifier|*
name|testlock
name|__P
argument_list|(
operator|(
expr|struct
name|nlm4_lock
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|nlm_stats
name|getlock
name|__P
argument_list|(
operator|(
name|nlm4_lockargs
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|nlm_stats
name|unlock
name|__P
argument_list|(
operator|(
name|nlm4_lock
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|notify
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|transmit_result
name|__P
argument_list|(
operator|(
name|int
operator|,
name|nlm_res
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|transmit4_result
name|__P
argument_list|(
operator|(
name|int
operator|,
name|nlm4_res
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CLIENT
modifier|*
name|get_client
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

