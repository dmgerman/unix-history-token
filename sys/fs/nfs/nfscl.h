begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSCL_H
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSCL_H
end_define

begin_comment
comment|/*  * Extra stuff for a NFSv4 nfsnode.  * MALLOC'd to the correct length for the name and file handle.  * n4_data has the file handle, followed by the file name.  * The macro NFS4NODENAME() returns a pointer to the start of the  * name.  */
end_comment

begin_struct
struct|struct
name|nfsv4node
block|{
name|u_int16_t
name|n4_fhlen
decl_stmt|;
name|u_int16_t
name|n4_namelen
decl_stmt|;
name|u_int8_t
name|n4_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NFS4NODENAME
parameter_list|(
name|n
parameter_list|)
value|(&((n)->n4_data[(n)->n4_fhlen]))
end_define

begin_comment
comment|/*  * Just a macro to convert the nfscl_reqstart arguments.  */
end_comment

begin_define
define|#
directive|define
name|NFSCL_REQSTART
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|nfscl_reqstart((n), (p), VFSTONFS((v)->v_mount), 		\ 	    VTONFS(v)->n_fhp->nfh_fh, VTONFS(v)->n_fhp->nfh_len, NULL, NULL)
end_define

begin_comment
comment|/*  * These two macros convert between a lease duration and renew interval.  * For now, just make the renew interval 1/2 the lease duration.  * (They should be inverse operators.)  */
end_comment

begin_define
define|#
directive|define
name|NFSCL_RENEW
parameter_list|(
name|l
parameter_list|)
value|(((l)< 2) ? 1 : ((l) / 2))
end_define

begin_define
define|#
directive|define
name|NFSCL_LEASE
parameter_list|(
name|r
parameter_list|)
value|((r) * 2)
end_define

begin_comment
comment|/* This macro checks to see if a forced dismount is about to occur. */
end_comment

begin_define
define|#
directive|define
name|NFSCL_FORCEDISM
parameter_list|(
name|m
parameter_list|)
value|(((m)->mnt_kern_flag& MNTK_UNMOUNTF) != 0 || \     (VFSTONFS(m)->nm_privflag& NFSMNTP_FORCEDISM) != 0)
end_define

begin_comment
comment|/*  * These flag bits are used for the argument to nfscl_fillsattr() to  * indicate special handling of the attributes.  */
end_comment

begin_define
define|#
directive|define
name|NFSSATTR_FULL
value|0x1
end_define

begin_define
define|#
directive|define
name|NFSSATTR_SIZE0
value|0x2
end_define

begin_define
define|#
directive|define
name|NFSSATTR_SIZENEG1
value|0x4
end_define

begin_define
define|#
directive|define
name|NFSSATTR_SIZERDEV
value|0x8
end_define

begin_comment
comment|/* Use this macro for debug printfs. */
end_comment

begin_define
define|#
directive|define
name|NFSCL_DEBUG
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 		if (nfscl_debuglevel>= (level))			\ 			printf(__VA_ARGS__);				\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSCL_H */
end_comment

end_unit

