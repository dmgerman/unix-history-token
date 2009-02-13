begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcv2.h,v 1.1 1996/02/26 23:05:32 gwr Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rpcv2.h	8.1 (Berkeley) 6/10/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for Sun RPC Version 2, from  * "RPC: Remote Procedure Call Protocol Specification" RFC1057  */
end_comment

begin_comment
comment|/* Version # */
end_comment

begin_define
define|#
directive|define
name|RPC_VER2
value|2
end_define

begin_comment
comment|/* Authentication */
end_comment

begin_define
define|#
directive|define
name|RPCAUTH_NULL
value|0
end_define

begin_define
define|#
directive|define
name|RPCAUTH_UNIX
value|1
end_define

begin_define
define|#
directive|define
name|RPCAUTH_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|RPCAUTH_MAXSIZ
value|400
end_define

begin_define
define|#
directive|define
name|RPCAUTH_UNIXGIDS
value|16
end_define

begin_comment
comment|/* Rpc Constants */
end_comment

begin_define
define|#
directive|define
name|RPC_CALL
value|0
end_define

begin_define
define|#
directive|define
name|RPC_REPLY
value|1
end_define

begin_define
define|#
directive|define
name|RPC_MSGACCEPTED
value|0
end_define

begin_define
define|#
directive|define
name|RPC_MSGDENIED
value|1
end_define

begin_define
define|#
directive|define
name|RPC_PROGUNAVAIL
value|1
end_define

begin_define
define|#
directive|define
name|RPC_PROGMISMATCH
value|2
end_define

begin_define
define|#
directive|define
name|RPC_PROCUNAVAIL
value|3
end_define

begin_define
define|#
directive|define
name|RPC_GARBAGE
value|4
end_define

begin_comment
comment|/* I like this one */
end_comment

begin_define
define|#
directive|define
name|RPC_MISMATCH
value|0
end_define

begin_define
define|#
directive|define
name|RPC_AUTHERR
value|1
end_define

begin_comment
comment|/* Authentication failures */
end_comment

begin_define
define|#
directive|define
name|AUTH_BADCRED
value|1
end_define

begin_define
define|#
directive|define
name|AUTH_REJECTCRED
value|2
end_define

begin_define
define|#
directive|define
name|AUTH_BADVERF
value|3
end_define

begin_define
define|#
directive|define
name|AUTH_REJECTVERF
value|4
end_define

begin_define
define|#
directive|define
name|AUTH_TOOWEAK
value|5
end_define

begin_comment
comment|/* Give em wheaties */
end_comment

begin_comment
comment|/* Sizes of rpc header parts */
end_comment

begin_define
define|#
directive|define
name|RPC_SIZ
value|24
end_define

begin_define
define|#
directive|define
name|RPC_REPLYSIZ
value|28
end_define

begin_comment
comment|/* RPC Prog definitions */
end_comment

begin_define
define|#
directive|define
name|RPCPROG_MNT
value|100005
end_define

begin_define
define|#
directive|define
name|RPCMNT_VER1
value|1
end_define

begin_define
define|#
directive|define
name|RPCMNT_MOUNT
value|1
end_define

begin_define
define|#
directive|define
name|RPCMNT_DUMP
value|2
end_define

begin_define
define|#
directive|define
name|RPCMNT_UMOUNT
value|3
end_define

begin_define
define|#
directive|define
name|RPCMNT_UMNTALL
value|4
end_define

begin_define
define|#
directive|define
name|RPCMNT_EXPORT
value|5
end_define

begin_define
define|#
directive|define
name|RPCMNT_NAMELEN
value|255
end_define

begin_define
define|#
directive|define
name|RPCMNT_PATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|RPCPROG_NFS
value|100003
end_define

end_unit

