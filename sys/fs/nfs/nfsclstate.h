begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSCLSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSCLSTATE_H_
end_define

begin_comment
comment|/*  * Definitions for NFS V4 client state handling.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclopenhead
argument_list|,
name|nfsclopen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfscllockownerhead
argument_list|,
name|nfscllockowner
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfscllockhead
argument_list|,
name|nfscllock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclhead
argument_list|,
name|nfsclclient
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclownerhead
argument_list|,
name|nfsclowner
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nfscldeleghead
argument_list|,
name|nfscldeleg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfscldeleghash
argument_list|,
name|nfscldeleg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NFSCLDELEGHASHSIZE
value|256
end_define

begin_define
define|#
directive|define
name|NFSCLDELEGHASH
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|(&((c)->nfsc_deleghash[ncl_hash((f), (l)) % NFSCLDELEGHASHSIZE]))
end_define

begin_struct
struct|struct
name|nfsclclient
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclclient
argument_list|)
name|nfsc_list
expr_stmt|;
name|struct
name|nfsclownerhead
name|nfsc_owner
decl_stmt|;
name|struct
name|nfscldeleghead
name|nfsc_deleg
decl_stmt|;
name|struct
name|nfscldeleghash
name|nfsc_deleghash
index|[
name|NFSCLDELEGHASHSIZE
index|]
decl_stmt|;
name|struct
name|nfscllockownerhead
name|nfsc_defunctlockowner
decl_stmt|;
name|struct
name|nfsv4lock
name|nfsc_lock
decl_stmt|;
name|struct
name|proc
modifier|*
name|nfsc_renewthread
decl_stmt|;
name|struct
name|nfsmount
modifier|*
name|nfsc_nmp
decl_stmt|;
name|nfsquad_t
name|nfsc_clientid
decl_stmt|;
name|time_t
name|nfsc_expire
decl_stmt|;
name|u_int32_t
name|nfsc_clientidrev
decl_stmt|;
name|u_int32_t
name|nfsc_renew
decl_stmt|;
name|u_int32_t
name|nfsc_cbident
decl_stmt|;
name|u_int16_t
name|nfsc_flags
decl_stmt|;
name|u_int16_t
name|nfsc_idlen
decl_stmt|;
name|u_int8_t
name|nfsc_id
index|[
literal|1
index|]
decl_stmt|;
comment|/* Malloc'd to correct length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits for nfsc_flags.  */
end_comment

begin_define
define|#
directive|define
name|NFSCLFLAGS_INITED
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_HASCLIENTID
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_RECOVER
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_UMOUNT
value|0x0008
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_HASTHREAD
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_AFINET6
value|0x0020
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_EXPIREIT
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_FIRSTDELEG
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_GOTDELEG
value|0x0100
end_define

begin_define
define|#
directive|define
name|NFSCLFLAGS_RECVRINPROG
value|0x0200
end_define

begin_struct
struct|struct
name|nfsclowner
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclowner
argument_list|)
name|nfsow_list
expr_stmt|;
name|struct
name|nfsclopenhead
name|nfsow_open
decl_stmt|;
name|struct
name|nfsclclient
modifier|*
name|nfsow_clp
decl_stmt|;
name|u_int32_t
name|nfsow_seqid
decl_stmt|;
name|u_int32_t
name|nfsow_defunct
decl_stmt|;
name|struct
name|nfsv4lock
name|nfsow_rwlock
decl_stmt|;
name|u_int8_t
name|nfsow_owner
index|[
name|NFSV4CL_LOCKNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MALLOC'd to the correct length to accommodate the file handle.  */
end_comment

begin_struct
struct|struct
name|nfscldeleg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfscldeleg
argument_list|)
name|nfsdl_list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|nfscldeleg
argument_list|)
name|nfsdl_hash
expr_stmt|;
name|struct
name|nfsclownerhead
name|nfsdl_owner
decl_stmt|;
comment|/* locally issued state */
name|struct
name|nfscllockownerhead
name|nfsdl_lock
decl_stmt|;
name|nfsv4stateid_t
name|nfsdl_stateid
decl_stmt|;
name|struct
name|acl_entry
name|nfsdl_ace
decl_stmt|;
comment|/* Delegation ace */
name|struct
name|nfsclclient
modifier|*
name|nfsdl_clp
decl_stmt|;
name|struct
name|nfsv4lock
name|nfsdl_rwlock
decl_stmt|;
comment|/* for active I/O ops */
name|struct
name|nfscred
name|nfsdl_cred
decl_stmt|;
comment|/* Cred. used for Open */
name|time_t
name|nfsdl_timestamp
decl_stmt|;
comment|/* used for stale cleanup */
name|u_int64_t
name|nfsdl_sizelimit
decl_stmt|;
comment|/* Limit for file growth */
name|u_int64_t
name|nfsdl_size
decl_stmt|;
comment|/* saved copy of file size */
name|u_int64_t
name|nfsdl_change
decl_stmt|;
comment|/* and change attribute */
name|struct
name|timespec
name|nfsdl_modtime
decl_stmt|;
comment|/* local modify time */
name|u_int16_t
name|nfsdl_fhlen
decl_stmt|;
name|u_int8_t
name|nfsdl_flags
decl_stmt|;
name|u_int8_t
name|nfsdl_fh
index|[
literal|1
index|]
decl_stmt|;
comment|/* must be last */
block|}
struct|;
end_struct

begin_comment
comment|/*  * nfsdl_flags bits.  */
end_comment

begin_define
define|#
directive|define
name|NFSCLDL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSCLDL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSCLDL_RECALL
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSCLDL_NEEDRECLAIM
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSCLDL_ZAPPED
value|0x10
end_define

begin_define
define|#
directive|define
name|NFSCLDL_MODTIMESET
value|0x20
end_define

begin_comment
comment|/*  * MALLOC'd to the correct length to accommodate the file handle.  */
end_comment

begin_struct
struct|struct
name|nfsclopen
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclopen
argument_list|)
name|nfso_list
expr_stmt|;
name|struct
name|nfscllockownerhead
name|nfso_lock
decl_stmt|;
name|nfsv4stateid_t
name|nfso_stateid
decl_stmt|;
name|struct
name|nfsclowner
modifier|*
name|nfso_own
decl_stmt|;
name|struct
name|nfscred
name|nfso_cred
decl_stmt|;
comment|/* Cred. used for Open */
name|u_int32_t
name|nfso_mode
decl_stmt|;
name|u_int32_t
name|nfso_opencnt
decl_stmt|;
name|u_int16_t
name|nfso_fhlen
decl_stmt|;
name|u_int8_t
name|nfso_posixlock
decl_stmt|;
comment|/* 1 for POSIX type locking */
name|u_int8_t
name|nfso_fh
index|[
literal|1
index|]
decl_stmt|;
comment|/* must be last */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Return values for nfscl_open(). NFSCLOPEN_OK must == 0.  */
end_comment

begin_define
define|#
directive|define
name|NFSCLOPEN_OK
value|0
end_define

begin_define
define|#
directive|define
name|NFSCLOPEN_DOOPEN
value|1
end_define

begin_define
define|#
directive|define
name|NFSCLOPEN_DOOPENDOWNGRADE
value|2
end_define

begin_define
define|#
directive|define
name|NFSCLOPEN_SETCRED
value|3
end_define

begin_struct
struct|struct
name|nfscllockowner
block|{
name|LIST_ENTRY
argument_list|(
argument|nfscllockowner
argument_list|)
name|nfsl_list
expr_stmt|;
name|struct
name|nfscllockhead
name|nfsl_lock
decl_stmt|;
name|struct
name|nfsclopen
modifier|*
name|nfsl_open
decl_stmt|;
name|NFSPROC_T
modifier|*
name|nfsl_inprog
decl_stmt|;
name|nfsv4stateid_t
name|nfsl_stateid
decl_stmt|;
name|u_int32_t
name|nfsl_seqid
decl_stmt|;
name|u_int32_t
name|nfsl_defunct
decl_stmt|;
name|struct
name|nfsv4lock
name|nfsl_rwlock
decl_stmt|;
name|u_int8_t
name|nfsl_owner
index|[
name|NFSV4CL_LOCKNAMELEN
index|]
decl_stmt|;
name|u_int8_t
name|nfsl_openowner
index|[
name|NFSV4CL_LOCKNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Byte range entry for the above lock owner.  */
end_comment

begin_struct
struct|struct
name|nfscllock
block|{
name|LIST_ENTRY
argument_list|(
argument|nfscllock
argument_list|)
name|nfslo_list
expr_stmt|;
name|u_int64_t
name|nfslo_first
decl_stmt|;
name|u_int64_t
name|nfslo_end
decl_stmt|;
name|short
name|nfslo_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro for incrementing the seqid#.  */
end_comment

begin_define
define|#
directive|define
name|NFSCL_INCRSEQID
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|do { 					\ 	    if (((n)->nd_flag& ND_INCRSEQID))				\ 		(s)++; 							\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSCLSTATE_H_ */
end_comment

end_unit

