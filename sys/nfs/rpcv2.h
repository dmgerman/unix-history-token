begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rpcv2.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_RPCV2_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_RPCV2_H_
end_define

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
name|RPCAUTH_KERB4
value|4
end_define

begin_define
define|#
directive|define
name|RPCAUTH_NQNFS
value|300000
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
name|RPCVERF_MAXSIZ
value|12
end_define

begin_comment
comment|/* For Kerb, can actually be 400 */
end_comment

begin_define
define|#
directive|define
name|RPCAUTH_UNIXGIDS
value|16
end_define

begin_comment
comment|/*  * Constants associated with authentication flavours.  */
end_comment

begin_define
define|#
directive|define
name|RPCAKN_FULLNAME
value|0
end_define

begin_define
define|#
directive|define
name|RPCAKN_NICKNAME
value|1
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
name|RPCMNT_VER3
value|3
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

begin_comment
comment|/*  * Structures used for RPCAUTH_KERB4.  */
end_comment

begin_struct
struct|struct
name|nfsrpc_fullverf
block|{
name|u_int32_t
name|t1
decl_stmt|;
name|u_int32_t
name|t2
decl_stmt|;
name|u_int32_t
name|w2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsrpc_fullblock
block|{
name|u_int32_t
name|t1
decl_stmt|;
name|u_int32_t
name|t2
decl_stmt|;
name|u_int32_t
name|w1
decl_stmt|;
name|u_int32_t
name|w2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsrpc_nickverf
block|{
name|u_int32_t
name|kind
decl_stmt|;
name|struct
name|nfsrpc_fullverf
name|verf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * and their sizes in bytes.. If sizeof (struct nfsrpc_xx) != these  * constants, well then things will break in mount_nfs and nfsd.  */
end_comment

begin_define
define|#
directive|define
name|RPCX_FULLVERF
value|12
end_define

begin_define
define|#
directive|define
name|RPCX_FULLBLOCK
value|16
end_define

begin_define
define|#
directive|define
name|RPCX_NICKVERF
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NFSKERB
end_ifdef

begin_macro
name|XXX
end_macro

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_char
name|NFSKERBKEY_T
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|NFSKERBKEYSCHED_T
index|[
literal|2
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFS_KERBSRV
value|"rcmd"
end_define

begin_comment
comment|/* Kerberos Service for NFS */
end_comment

begin_define
define|#
directive|define
name|NFS_KERBTTL
value|(30 * 60)
end_define

begin_comment
comment|/* Credential ttl (sec) */
end_comment

begin_define
define|#
directive|define
name|NFS_KERBCLOCKSKEW
value|(5 * 60)
end_define

begin_comment
comment|/* Clock skew (sec) */
end_comment

begin_define
define|#
directive|define
name|NFS_KERBW1
parameter_list|(
name|t
parameter_list|)
value|(*((u_long *)(&((t).dat[((t).length + 3)& ~0x3]))))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

