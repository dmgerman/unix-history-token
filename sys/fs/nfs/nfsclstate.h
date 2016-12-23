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
name|SLIST_HEAD
argument_list|(
name|nfscllockownerfhhead
argument_list|,
name|nfscllockownerfh
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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nfscllayouthead
argument_list|,
name|nfscllayout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfscllayouthash
argument_list|,
name|nfscllayout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclflayouthead
argument_list|,
name|nfsclflayout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfscldevinfohead
argument_list|,
name|nfscldevinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclrecalllayouthead
argument_list|,
name|nfsclrecalllayout
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

begin_define
define|#
directive|define
name|NFSCLLAYOUTHASHSIZE
value|256
end_define

begin_define
define|#
directive|define
name|NFSCLLAYOUTHASH
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|,
name|l
parameter_list|)
define|\
value|(&((c)->nfsc_layouthash[ncl_hash((f), (l)) % NFSCLLAYOUTHASHSIZE]))
end_define

begin_comment
comment|/* Structure for NFSv4.1 session stuff. */
end_comment

begin_struct
struct|struct
name|nfsclsession
block|{
name|struct
name|mtx
name|nfsess_mtx
decl_stmt|;
name|struct
name|nfsslot
name|nfsess_cbslots
index|[
name|NFSV4_CBSLOTS
index|]
decl_stmt|;
name|nfsquad_t
name|nfsess_clientid
decl_stmt|;
name|SVCXPRT
modifier|*
name|nfsess_xprt
decl_stmt|;
comment|/* For backchannel callback */
name|uint32_t
name|nfsess_slotseq
index|[
literal|64
index|]
decl_stmt|;
comment|/* Max for 64bit nm_slots */
name|uint64_t
name|nfsess_slots
decl_stmt|;
name|uint32_t
name|nfsess_sequenceid
decl_stmt|;
name|uint32_t
name|nfsess_maxcache
decl_stmt|;
comment|/* Max size for cached reply. */
name|uint16_t
name|nfsess_foreslots
decl_stmt|;
name|uint16_t
name|nfsess_backslots
decl_stmt|;
name|uint8_t
name|nfsess_sessionid
index|[
name|NFSX_V4SESSIONID
index|]
decl_stmt|;
name|uint8_t
name|nfsess_defunct
decl_stmt|;
comment|/* Non-zero for old sessions */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure holds the session, clientid and related information  * needed for an NFSv4.1 Meta Data Server (MDS) or Data Server (DS).  * It is malloc'd to the correct length.  */
end_comment

begin_struct
struct|struct
name|nfsclds
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsclds
argument_list|)
name|nfsclds_list
expr_stmt|;
name|struct
name|nfsclsession
name|nfsclds_sess
decl_stmt|;
name|struct
name|mtx
name|nfsclds_mtx
decl_stmt|;
name|struct
name|nfssockreq
modifier|*
name|nfsclds_sockp
decl_stmt|;
name|time_t
name|nfsclds_expire
decl_stmt|;
name|uint16_t
name|nfsclds_flags
decl_stmt|;
name|uint16_t
name|nfsclds_servownlen
decl_stmt|;
name|uint8_t
name|nfsclds_verf
index|[
name|NFSX_VERF
index|]
decl_stmt|;
name|uint8_t
name|nfsclds_serverown
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for nfsclds_flags.  */
end_comment

begin_define
define|#
directive|define
name|NFSCLDS_HASWRITEVERF
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFSCLDS_MDS
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFSCLDS_DS
value|0x0004
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
name|nfscllayouthead
name|nfsc_layout
decl_stmt|;
name|struct
name|nfscllayouthash
name|nfsc_layouthash
index|[
name|NFSCLLAYOUTHASHSIZE
index|]
decl_stmt|;
name|struct
name|nfscldevinfohead
name|nfsc_devinfo
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
name|time_t
name|nfsc_expire
decl_stmt|;
name|u_int32_t
name|nfsc_clientidrev
decl_stmt|;
name|u_int32_t
name|nfsc_rev
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

begin_define
define|#
directive|define
name|NFSCLDL_DELEGRET
value|0x40
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
name|int
name|nfsl_lockflags
decl_stmt|;
name|u_int32_t
name|nfsl_seqid
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
comment|/* This structure is used to collect a list of lockowners to free up. */
end_comment

begin_struct
struct|struct
name|nfscllockownerfh
block|{
name|SLIST_ENTRY
argument_list|(
argument|nfscllockownerfh
argument_list|)
name|nfslfh_list
expr_stmt|;
name|struct
name|nfscllockownerhead
name|nfslfh_lock
decl_stmt|;
name|int
name|nfslfh_len
decl_stmt|;
name|uint8_t
name|nfslfh_fh
index|[
name|NFSX_V4FHMAX
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
name|nfscllayout
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfscllayout
argument_list|)
name|nfsly_list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|nfscllayout
argument_list|)
name|nfsly_hash
expr_stmt|;
name|nfsv4stateid_t
name|nfsly_stateid
decl_stmt|;
name|struct
name|nfsv4lock
name|nfsly_lock
decl_stmt|;
name|uint64_t
name|nfsly_filesid
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|nfsly_lastbyte
decl_stmt|;
name|struct
name|nfsclflayouthead
name|nfsly_flayread
decl_stmt|;
name|struct
name|nfsclflayouthead
name|nfsly_flayrw
decl_stmt|;
name|struct
name|nfsclrecalllayouthead
name|nfsly_recall
decl_stmt|;
name|time_t
name|nfsly_timestamp
decl_stmt|;
name|struct
name|nfsclclient
modifier|*
name|nfsly_clp
decl_stmt|;
name|uint16_t
name|nfsly_flags
decl_stmt|;
name|uint16_t
name|nfsly_fhlen
decl_stmt|;
name|uint8_t
name|nfsly_fh
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for nfsly_flags.  */
end_comment

begin_define
define|#
directive|define
name|NFSLY_FILES
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFSLY_BLOCK
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFSLY_OBJECT
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFSLY_RECALL
value|0x0008
end_define

begin_define
define|#
directive|define
name|NFSLY_RECALLFILE
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFSLY_RECALLFSID
value|0x0020
end_define

begin_define
define|#
directive|define
name|NFSLY_RECALLALL
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFSLY_RETONCLOSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFSLY_WRITTEN
value|0x0100
end_define

begin_comment
comment|/* Has been used to write to a DS. */
end_comment

begin_comment
comment|/*  * MALLOC'd to the correct length to accommodate the file handle list.  * These hang off of nfsly_flayread and nfsly_flayrw, sorted in increasing  * offset order.  * The nfsly_flayread list holds the ones with iomode == NFSLAYOUTIOMODE_READ,  * whereas the nfsly_flayrw holds the ones with iomode == NFSLAYOUTIOMODE_RW.  */
end_comment

begin_struct
struct|struct
name|nfsclflayout
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclflayout
argument_list|)
name|nfsfl_list
expr_stmt|;
name|uint8_t
name|nfsfl_dev
index|[
name|NFSX_V4DEVICEID
index|]
decl_stmt|;
name|uint64_t
name|nfsfl_off
decl_stmt|;
name|uint64_t
name|nfsfl_end
decl_stmt|;
name|uint64_t
name|nfsfl_patoff
decl_stmt|;
name|struct
name|nfscldevinfo
modifier|*
name|nfsfl_devp
decl_stmt|;
name|uint32_t
name|nfsfl_iomode
decl_stmt|;
name|uint32_t
name|nfsfl_util
decl_stmt|;
name|uint32_t
name|nfsfl_stripe1
decl_stmt|;
name|uint16_t
name|nfsfl_flags
decl_stmt|;
name|uint16_t
name|nfsfl_fhcnt
decl_stmt|;
name|struct
name|nfsfh
modifier|*
name|nfsfl_fh
index|[
literal|1
index|]
decl_stmt|;
comment|/* FH list for DS */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for nfsfl_flags.  */
end_comment

begin_define
define|#
directive|define
name|NFSFL_RECALL
value|0x0001
end_define

begin_comment
comment|/* File layout has been recalled */
end_comment

begin_comment
comment|/*  * Structure that is used to store a LAYOUTRECALL.  */
end_comment

begin_struct
struct|struct
name|nfsclrecalllayout
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclrecalllayout
argument_list|)
name|nfsrecly_list
expr_stmt|;
name|uint64_t
name|nfsrecly_off
decl_stmt|;
name|uint64_t
name|nfsrecly_len
decl_stmt|;
name|int
name|nfsrecly_recalltype
decl_stmt|;
name|uint32_t
name|nfsrecly_iomode
decl_stmt|;
name|uint32_t
name|nfsrecly_stateseqid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stores the NFSv4.1 Device Info. Malloc'd to the correct length to  * store the list of network connections and list of indices.  * nfsdi_data[] is allocated the following way:  * - nfsdi_addrcnt * struct nfsclds  * - stripe indices, each stored as one byte, since there can be many  *   of them. (This implies a limit of 256 on nfsdi_addrcnt, since the  *   indices select which address.)  */
end_comment

begin_struct
struct|struct
name|nfscldevinfo
block|{
name|LIST_ENTRY
argument_list|(
argument|nfscldevinfo
argument_list|)
name|nfsdi_list
expr_stmt|;
name|uint8_t
name|nfsdi_deviceid
index|[
name|NFSX_V4DEVICEID
index|]
decl_stmt|;
name|struct
name|nfsclclient
modifier|*
name|nfsdi_clp
decl_stmt|;
name|uint32_t
name|nfsdi_refcnt
decl_stmt|;
name|uint32_t
name|nfsdi_layoutrefs
decl_stmt|;
name|uint16_t
name|nfsdi_stripecnt
decl_stmt|;
name|uint16_t
name|nfsdi_addrcnt
decl_stmt|;
name|struct
name|nfsclds
modifier|*
name|nfsdi_data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These inline functions return values from nfsdi_data[]. */
end_comment

begin_comment
comment|/*  * Return a pointer to the address at "pos".  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|nfsclds
operator|*
operator|*
name|nfsfldi_addr
argument_list|(
argument|struct nfscldevinfo *ndi
argument_list|,
argument|int pos
argument_list|)
block|{
if|if
condition|(
name|pos
operator|>=
name|ndi
operator|->
name|nfsdi_addrcnt
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|(
operator|&
name|ndi
operator|->
name|nfsdi_data
index|[
name|pos
index|]
operator|)
return|;
end_return

begin_comment
unit|}
comment|/*  * Return the Nth ("pos") stripe index.  */
end_comment

begin_function
unit|static
name|__inline
name|int
name|nfsfldi_stripeindex
parameter_list|(
name|struct
name|nfscldevinfo
modifier|*
name|ndi
parameter_list|,
name|int
name|pos
parameter_list|)
block|{
name|uint8_t
modifier|*
name|valp
decl_stmt|;
if|if
condition|(
name|pos
operator|>=
name|ndi
operator|->
name|nfsdi_stripecnt
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|valp
operator|=
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|ndi
operator|->
name|nfsdi_data
index|[
name|ndi
operator|->
name|nfsdi_addrcnt
index|]
expr_stmt|;
name|valp
operator|+=
name|pos
expr_stmt|;
return|return
operator|(
operator|(
name|int
operator|)
operator|*
name|valp
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Set the Nth ("pos") stripe index to "val".  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|nfsfldi_setstripeindex
parameter_list|(
name|struct
name|nfscldevinfo
modifier|*
name|ndi
parameter_list|,
name|int
name|pos
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
name|uint8_t
modifier|*
name|valp
decl_stmt|;
if|if
condition|(
name|pos
operator|>=
name|ndi
operator|->
name|nfsdi_stripecnt
condition|)
return|return;
name|valp
operator|=
operator|(
name|uint8_t
operator|*
operator|)
operator|&
name|ndi
operator|->
name|nfsdi_data
index|[
name|ndi
operator|->
name|nfsdi_addrcnt
index|]
expr_stmt|;
name|valp
operator|+=
name|pos
expr_stmt|;
operator|*
name|valp
operator|=
name|val
expr_stmt|;
block|}
end_function

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

