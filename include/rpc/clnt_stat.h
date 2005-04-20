begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991, 1994, 1996, 1997 by Sun Microsystems, Inc.  * All rights reserved.  */
end_comment

begin_comment
comment|/*  * clnt_stat.h - Client side remote procedure call enum  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_CLNT_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_CLNT_STAT_H
end_define

begin_comment
comment|/* #pragma ident	"@(#)clnt_stat.h	1.2	97/04/28 SMI" */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
enum|enum
name|clnt_stat
block|{
name|RPC_SUCCESS
init|=
literal|0
block|,
comment|/* call succeeded */
comment|/* 	 * local errors 	 */
name|RPC_CANTENCODEARGS
init|=
literal|1
block|,
comment|/* can't encode arguments */
name|RPC_CANTDECODERES
init|=
literal|2
block|,
comment|/* can't decode results */
name|RPC_CANTSEND
init|=
literal|3
block|,
comment|/* failure in sending call */
name|RPC_CANTRECV
init|=
literal|4
block|,
comment|/* failure in receiving result */
name|RPC_TIMEDOUT
init|=
literal|5
block|,
comment|/* call timed out */
name|RPC_INTR
init|=
literal|18
block|,
comment|/* call interrupted */
name|RPC_UDERROR
init|=
literal|23
block|,
comment|/* recv got uderr indication */
comment|/* 	 * remote errors 	 */
name|RPC_VERSMISMATCH
init|=
literal|6
block|,
comment|/* rpc versions not compatible */
name|RPC_AUTHERROR
init|=
literal|7
block|,
comment|/* authentication error */
name|RPC_PROGUNAVAIL
init|=
literal|8
block|,
comment|/* program not available */
name|RPC_PROGVERSMISMATCH
init|=
literal|9
block|,
comment|/* program version mismatched */
name|RPC_PROCUNAVAIL
init|=
literal|10
block|,
comment|/* procedure unavailable */
name|RPC_CANTDECODEARGS
init|=
literal|11
block|,
comment|/* decode arguments error */
name|RPC_SYSTEMERROR
init|=
literal|12
block|,
comment|/* generic "other problem" */
comment|/* 	 * rpc_call& clnt_create errors 	 */
name|RPC_UNKNOWNHOST
init|=
literal|13
block|,
comment|/* unknown host name */
name|RPC_UNKNOWNPROTO
init|=
literal|17
block|,
comment|/* unknown protocol */
name|RPC_UNKNOWNADDR
init|=
literal|19
block|,
comment|/* Remote address unknown */
name|RPC_NOBROADCAST
init|=
literal|21
block|,
comment|/* Broadcasting not supported */
comment|/* 	 * rpcbind errors 	 */
name|RPC_RPCBFAILURE
init|=
literal|14
block|,
comment|/* the pmapper failed in its call */
define|#
directive|define
name|RPC_PMAPFAILURE
value|RPC_RPCBFAILURE
name|RPC_PROGNOTREGISTERED
init|=
literal|15
block|,
comment|/* remote program is not registered */
name|RPC_N2AXLATEFAILURE
init|=
literal|22
block|,
comment|/* Name to address translation failed */
comment|/* 	 * Misc error in the TLI library 	 */
name|RPC_TLIERROR
init|=
literal|20
block|,
comment|/* 	 * unspecified error 	 */
name|RPC_FAILED
init|=
literal|16
block|,
comment|/* 	 * asynchronous errors 	 */
name|RPC_INPROGRESS
init|=
literal|24
block|,
name|RPC_STALERACHANDLE
init|=
literal|25
block|,
name|RPC_CANTCONNECT
init|=
literal|26
block|,
comment|/* couldn't make connection (cots) */
name|RPC_XPRTFAILED
init|=
literal|27
block|,
comment|/* received discon from remote (cots) */
name|RPC_CANTCREATESTREAM
init|=
literal|28
comment|/* can't push rpc module (cots) */
block|}
enum|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_CLNT_STAT_H */
end_comment

end_unit

