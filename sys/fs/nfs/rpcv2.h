begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/* Authentication flavours */
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
name|RPCAUTH_GSS
value|6
end_define

begin_define
define|#
directive|define
name|RPCAUTH_GSSKRB5
value|390003
end_define

begin_define
define|#
directive|define
name|RPCAUTH_GSSKRB5INTEGRITY
value|390004
end_define

begin_define
define|#
directive|define
name|RPCAUTH_GSSKRB5PRIVACY
value|390005
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

begin_comment
comment|/*  * RPCAUTH_UNIX defs.  */
end_comment

begin_define
define|#
directive|define
name|RPCAUTHUNIX_MINSIZ
value|(5 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|RPCAUTH_UNIXGIDS
value|16
end_define

begin_comment
comment|/*  * RPCAUTH_GSS defs.  */
end_comment

begin_define
define|#
directive|define
name|RPCAUTHGSS_VERS1
value|1
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_DATA
value|0
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_INIT
value|1
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_CONTINIT
value|2
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_DESTROY
value|3
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_SVCNONE
value|1
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_SVCINTEGRITY
value|2
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_SVCPRIVACY
value|3
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_MAXSEQ
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_WINDOW
value|64
end_define

begin_comment
comment|/* # of bits in u_int64_t */
end_comment

begin_define
define|#
directive|define
name|RPCAUTHGSS_SEQWINDOW
value|(RPCAUTHGSS_WINDOW + 1)
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_MIC
value|1
end_define

begin_define
define|#
directive|define
name|RPCAUTHGSS_WRAP
value|2
end_define

begin_comment
comment|/*  * Qop values for the types of security services.  */
end_comment

begin_define
define|#
directive|define
name|GSS_KERBV_QOP
value|0
end_define

begin_comment
comment|/*  * Sizes of GSS stuff.  */
end_comment

begin_define
define|#
directive|define
name|RPCGSS_KEYSIZ
value|8
end_define

begin_define
define|#
directive|define
name|GSSX_AUTHHEAD
value|(5 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|GSSX_MYHANDLE
value|(sizeof (long) + sizeof (u_int64_t))
end_define

begin_define
define|#
directive|define
name|GSSX_RPCHEADER
value|(13 * NFSX_UNSIGNED + GSSX_MYHANDLE)
end_define

begin_define
define|#
directive|define
name|GSSX_MINWRAP
value|(2 * NFSX_UNSIGNED)
end_define

begin_define
define|#
directive|define
name|GSSX_KERBVTOKEN
value|24
end_define

begin_define
define|#
directive|define
name|GSSX_LOCALHANDLE
value|(sizeof (void *))
end_define

begin_comment
comment|/*  * Stuff for the gssd.  */
end_comment

begin_define
define|#
directive|define
name|RPCPROG_GSSD
value|0x20101010
end_define

begin_define
define|#
directive|define
name|RPCGSSD_VERS
value|1
end_define

begin_define
define|#
directive|define
name|RPCGSSD_INIT
value|1
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CONTINIT
value|2
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CONTINITDESTROY
value|3
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLINIT
value|4
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLINITUID
value|5
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLCONT
value|6
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLCONTUID
value|7
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLINITNAME
value|8
end_define

begin_define
define|#
directive|define
name|RPCGSSD_CLCONTNAME
value|9
end_define

begin_comment
comment|/*  * Stuff for the nfsuserd  */
end_comment

begin_define
define|#
directive|define
name|RPCPROG_NFSUSERD
value|0x21010101
end_define

begin_define
define|#
directive|define
name|RPCNFSUSERD_VERS
value|1
end_define

begin_define
define|#
directive|define
name|RPCNFSUSERD_GETUID
value|1
end_define

begin_define
define|#
directive|define
name|RPCNFSUSERD_GETGID
value|2
end_define

begin_define
define|#
directive|define
name|RPCNFSUSERD_GETUSER
value|3
end_define

begin_define
define|#
directive|define
name|RPCNFSUSERD_GETGROUP
value|4
end_define

begin_comment
comment|/*  * Some major status codes.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_GSSAPI_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|GSSAPI_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GSSAPI_GSSAPI_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_RPCSEC_GSS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GSS_S_COMPLETE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GSS_S_CONTINUE_NEEDED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GSS_S_DUPLICATE_TOKEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GSS_S_OLD_TOKEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GSS_S_UNSEQ_TOKEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GSS_S_GAP_TOKEN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_MECH
value|0x00010000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_NAME
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_NAMETYPE
value|0x00030000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_BINDINGS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_STATUS
value|0x00050000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_MIC
value|0x00060000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_SIG
value|0x00060000
end_define

begin_define
define|#
directive|define
name|GSS_S_NO_CRED
value|0x00070000
end_define

begin_define
define|#
directive|define
name|GSS_S_NO_CONTEXT
value|0x00080000
end_define

begin_define
define|#
directive|define
name|GSS_S_DEFECTIVE_TOKEN
value|0x00090000
end_define

begin_define
define|#
directive|define
name|GSS_S_DEFECTIVE_CREDENTIAL
value|0x000a0000
end_define

begin_define
define|#
directive|define
name|GSS_S_CREDENTIALS_EXPIRED
value|0x000b0000
end_define

begin_define
define|#
directive|define
name|GSS_S_CONTEXT_EXPIRED
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|GSS_S_FAILURE
value|0x000d0000
end_define

begin_define
define|#
directive|define
name|GSS_S_BAD_QOP
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|GSS_S_UNAUTHORIZED
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|GSS_S_UNAVAILABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|GSS_S_DUPLICATE_ELEMENT
value|0x00110000
end_define

begin_define
define|#
directive|define
name|GSS_S_NAME_NOT_MN
value|0x00120000
end_define

begin_define
define|#
directive|define
name|GSS_S_CALL_INACCESSIBLE_READ
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GSS_S_CALL_INACCESSIBLE_WRITE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|GSS_S_CALL_BAD_STRUCTURE
value|0x03000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GSSAPI_H_ */
end_comment

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

begin_define
define|#
directive|define
name|AUTH_PROBCRED
value|13
end_define

begin_define
define|#
directive|define
name|AUTH_CTXCRED
value|14
end_define

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
comment|/* Structs for common parts of the rpc's */
end_comment

begin_struct
struct|struct
name|rpcv2_time
block|{
name|u_int32_t
name|rpc_sec
decl_stmt|;
name|u_int32_t
name|rpc_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_RPCV2_H_ */
end_comment

end_unit

