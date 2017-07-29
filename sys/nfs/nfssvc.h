begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSSVC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSSVC_H_
end_define

begin_comment
comment|/*  * Flags for nfssvc() system call.  */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_OLDNFSD
value|0x004
end_define

begin_define
define|#
directive|define
name|NFSSVC_ADDSOCK
value|0x008
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSD
value|0x010
end_define

begin_comment
comment|/*  * and ones for nfsv4.  */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_NOPUBLICFH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSSVC_STABLERESTART
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSDNFSD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSDADDSOCK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSSVC_IDNAME
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSSVC_GSSDDELETEALL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSSVC_GSSDADDPORT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSUSERDPORT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSUSERDDELPORT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NFSSVC_V4ROOTEXPORT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NFSSVC_ADMINREVOKE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NFSSVC_DUMPCLIENTS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSSVC_DUMPLOCKS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSSVC_GSSDADDFIRST
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSSVC_PUBLICFH
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSSVC_NFSCBD
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSSVC_CBADDSOCK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NFSSVC_GETSTATS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NFSSVC_BACKUPSTABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NFSSVC_ZEROCLTSTATS
value|0x01000000
end_define

begin_comment
comment|/* modifier for GETSTATS */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_ZEROSRVSTATS
value|0x02000000
end_define

begin_comment
comment|/* modifier for GETSTATS */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_SUSPENDNFSD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NFSSVC_RESUMENFSD
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NFSSVC_DUMPMNTOPTS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NFSSVC_NEWSTRUCT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NFSSVC_FORCEDISM
value|0x40000000
end_define

begin_comment
comment|/* Argument structure for NFSSVC_DUMPMNTOPTS. */
end_comment

begin_struct
struct|struct
name|nfscl_dumpmntopts
block|{
name|char
modifier|*
name|ndmnt_fname
decl_stmt|;
comment|/* File Name */
name|size_t
name|ndmnt_blen
decl_stmt|;
comment|/* Size of buffer */
name|void
modifier|*
name|ndmnt_buf
decl_stmt|;
comment|/* and the buffer */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSSVC_H */
end_comment

end_unit

