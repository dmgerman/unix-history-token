begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)rpcv2.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions for Sun RPC Version 2, from  * "Remote Procedure Call Protocol Specification" in the manual  * "Networking on the Sun Workstation", Part #800-1324-03 Rev. B  */
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
comment|/* Authentication Flavours */
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
name|RPC_AUTHFAIL
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

