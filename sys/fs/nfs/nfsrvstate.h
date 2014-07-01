begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSRVSTATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSRVSTATE_H_
end_define

begin_comment
comment|/*  * Definitions for NFS V4 server state handling.  */
end_comment

begin_comment
comment|/*  * List heads for nfsclient, nfsstate and nfslockfile.  * (Some systems seem to like to dynamically size these things, but I  *  don't see any point in doing so for these ones.)  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsclienthashhead
argument_list|,
name|nfsclient
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsstatehead
argument_list|,
name|nfsstate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfslockhead
argument_list|,
name|nfslock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfslockhashhead
argument_list|,
name|nfslockfile
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfssessionhead
argument_list|,
name|nfsdsession
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfssessionhashhead
argument_list|,
name|nfsdsession
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * List head for nfsusrgrp.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|nfsuserhashhead
argument_list|,
name|nfsusrgrp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nfsuserlruhead
argument_list|,
name|nfsusrgrp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NFSCLIENTHASH
parameter_list|(
name|id
parameter_list|)
define|\
value|(&nfsclienthash[(id).lval[1] % NFSCLIENTHASHSIZE])
end_define

begin_define
define|#
directive|define
name|NFSSTATEHASH
parameter_list|(
name|clp
parameter_list|,
name|id
parameter_list|)
define|\
value|(&((clp)->lc_stateid[(id).other[2] % NFSSTATEHASHSIZE]))
end_define

begin_define
define|#
directive|define
name|NFSUSERHASH
parameter_list|(
name|id
parameter_list|)
define|\
value|(&nfsuserhash[(id) % NFSUSERHASHSIZE])
end_define

begin_define
define|#
directive|define
name|NFSUSERNAMEHASH
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|(&nfsusernamehash[((l)>=4?(*(p)+*((p)+1)+*((p)+2)+*((p)+3)):*(p)) \ 		% NFSUSERHASHSIZE])
end_define

begin_define
define|#
directive|define
name|NFSGROUPHASH
parameter_list|(
name|id
parameter_list|)
define|\
value|(&nfsgrouphash[(id) % NFSGROUPHASHSIZE])
end_define

begin_define
define|#
directive|define
name|NFSGROUPNAMEHASH
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
define|\
value|(&nfsgroupnamehash[((l)>=4?(*(p)+*((p)+1)+*((p)+2)+*((p)+3)):*(p)) \ 		% NFSGROUPHASHSIZE])
end_define

begin_struct
struct|struct
name|nfssessionhash
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|nfssessionhashhead
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NFSSESSIONHASH
parameter_list|(
name|f
parameter_list|)
define|\
value|(&nfssessionhash[nfsrv_hashsessionid(f) % NFSSESSIONHASHSIZE])
end_define

begin_comment
comment|/*  * Client server structure for V4. It is doubly linked into two lists.  * The first is a hash table based on the clientid and the second is a  * list of all clients maintained in LRU order.  * The actual size malloc'd is large enough to accomodate the id string.  */
end_comment

begin_struct
struct|struct
name|nfsclient
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsclient
argument_list|)
name|lc_hash
expr_stmt|;
comment|/* Clientid hash list */
name|struct
name|nfsstatehead
name|lc_stateid
index|[
name|NFSSTATEHASHSIZE
index|]
decl_stmt|;
comment|/* stateid hash */
name|struct
name|nfsstatehead
name|lc_open
decl_stmt|;
comment|/* Open owner list */
name|struct
name|nfsstatehead
name|lc_deleg
decl_stmt|;
comment|/* Delegations */
name|struct
name|nfsstatehead
name|lc_olddeleg
decl_stmt|;
comment|/* and old delegations */
name|struct
name|nfssessionhead
name|lc_session
decl_stmt|;
comment|/* List of NFSv4.1 sessions */
name|time_t
name|lc_expiry
decl_stmt|;
comment|/* Expiry time (sec) */
name|time_t
name|lc_delegtime
decl_stmt|;
comment|/* Old deleg expiry (sec) */
name|nfsquad_t
name|lc_clientid
decl_stmt|;
comment|/* 64 bit clientid */
name|nfsquad_t
name|lc_confirm
decl_stmt|;
comment|/* 64 bit confirm value */
name|u_int32_t
name|lc_program
decl_stmt|;
comment|/* RPC Program # */
name|u_int32_t
name|lc_callback
decl_stmt|;
comment|/* Callback id */
name|u_int32_t
name|lc_stateindex
decl_stmt|;
comment|/* Current state index# */
name|u_int32_t
name|lc_statemaxindex
decl_stmt|;
comment|/* Max state index# */
name|u_int32_t
name|lc_cbref
decl_stmt|;
comment|/* Cnt of callbacks */
name|uid_t
name|lc_uid
decl_stmt|;
comment|/* User credential */
name|gid_t
name|lc_gid
decl_stmt|;
name|u_int16_t
name|lc_namelen
decl_stmt|;
name|u_char
modifier|*
name|lc_name
decl_stmt|;
name|struct
name|nfssockreq
name|lc_req
decl_stmt|;
comment|/* Callback info */
name|u_short
name|lc_idlen
decl_stmt|;
comment|/* Length of id string */
name|u_int32_t
name|lc_flags
decl_stmt|;
comment|/* LCL_ flag bits */
name|u_char
name|lc_verf
index|[
name|NFSX_VERF
index|]
decl_stmt|;
comment|/* client verifier */
name|u_char
name|lc_id
index|[
literal|1
index|]
decl_stmt|;
comment|/* Malloc'd correct size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CLOPS_CONFIRM
value|0x0001
end_define

begin_define
define|#
directive|define
name|CLOPS_RENEW
value|0x0002
end_define

begin_define
define|#
directive|define
name|CLOPS_RENEWOP
value|0x0004
end_define

begin_comment
comment|/*  * Structure for an NFSv4.1 session.  * Locking rules for this structure.  * To add/delete one of these structures from the lists, you must lock  * both: NFSLOCKSESSION(session hashhead) and NFSLOCKSTATE() in that order.  * To traverse the lists looking for one of these, you must hold one  * of these two locks.  * The exception is if the thread holds the exclusive root sleep lock.  * In this case, all other nfsd threads are blocked, so locking the  * mutexes isn't required.  * When manipulating sess_refcnt, NFSLOCKSTATE() must be locked.  * When manipulating the fields withinsess_cbsess except nfsess_xprt,  * sess_cbsess.nfsess_mtx must be locked.  * When manipulating sess_slots and sess_cbsess.nfsess_xprt,  * NFSLOCKSESSION(session hashhead) must be locked.  */
end_comment

begin_struct
struct|struct
name|nfsdsession
block|{
name|uint64_t
name|sess_refcnt
decl_stmt|;
comment|/* Reference count. */
name|LIST_ENTRY
argument_list|(
argument|nfsdsession
argument_list|)
name|sess_hash
expr_stmt|;
comment|/* Hash list of sessions. */
name|LIST_ENTRY
argument_list|(
argument|nfsdsession
argument_list|)
name|sess_list
expr_stmt|;
comment|/* List of client sessions. */
name|struct
name|nfsslot
name|sess_slots
index|[
name|NFSV4_SLOTS
index|]
decl_stmt|;
name|struct
name|nfsclient
modifier|*
name|sess_clp
decl_stmt|;
comment|/* Associated clientid. */
name|uint32_t
name|sess_crflags
decl_stmt|;
name|uint32_t
name|sess_cbprogram
decl_stmt|;
name|uint32_t
name|sess_maxreq
decl_stmt|;
name|uint32_t
name|sess_maxresp
decl_stmt|;
name|uint32_t
name|sess_maxrespcached
decl_stmt|;
name|uint32_t
name|sess_maxops
decl_stmt|;
name|uint32_t
name|sess_maxslots
decl_stmt|;
name|uint32_t
name|sess_cbmaxreq
decl_stmt|;
name|uint32_t
name|sess_cbmaxresp
decl_stmt|;
name|uint32_t
name|sess_cbmaxrespcached
decl_stmt|;
name|uint32_t
name|sess_cbmaxops
decl_stmt|;
name|uint8_t
name|sess_sessionid
index|[
name|NFSX_V4SESSIONID
index|]
decl_stmt|;
name|struct
name|nfsclsession
name|sess_cbsess
decl_stmt|;
comment|/* Callback session. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Nfs state structure. I couldn't resist overloading this one, since  * it makes cleanup, etc. simpler. These structures are used in four ways:  * - open_owner structures chained off of nfsclient  * - open file structures chained off an open_owner structure  * - lock_owner structures chained off an open file structure  * - delegated file structures chained off of nfsclient and nfslockfile  * - the ls_list field is used for the chain it is in  * - the ls_head structure is used to chain off the sibling structure  *   (it is a union between an nfsstate and nfslock structure head)  *    If it is a lockowner stateid, nfslock structures hang off it.  * For the open file and lockowner cases, it is in the hash table in  * nfsclient for stateid.  */
end_comment

begin_struct
struct|struct
name|nfsstate
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsstate
argument_list|)
name|ls_hash
expr_stmt|;
comment|/* Hash list entry */
name|LIST_ENTRY
argument_list|(
argument|nfsstate
argument_list|)
name|ls_list
expr_stmt|;
comment|/* List of opens/delegs */
name|LIST_ENTRY
argument_list|(
argument|nfsstate
argument_list|)
name|ls_file
expr_stmt|;
comment|/* Opens/Delegs for a file */
union|union
block|{
name|struct
name|nfsstatehead
name|open
decl_stmt|;
comment|/* Opens list */
name|struct
name|nfslockhead
name|lock
decl_stmt|;
comment|/* Locks list */
block|}
name|ls_head
union|;
name|nfsv4stateid_t
name|ls_stateid
decl_stmt|;
comment|/* The state id */
name|u_int32_t
name|ls_seq
decl_stmt|;
comment|/* seq id */
name|uid_t
name|ls_uid
decl_stmt|;
comment|/* uid of locker */
name|u_int32_t
name|ls_flags
decl_stmt|;
comment|/* Type of lock, etc. */
union|union
block|{
name|struct
name|nfsstate
modifier|*
name|openowner
decl_stmt|;
comment|/* Open only */
name|u_int32_t
name|opentolockseq
decl_stmt|;
comment|/* Lock call only */
name|u_int32_t
name|noopens
decl_stmt|;
comment|/* Openowner only */
struct|struct
block|{
name|u_quad_t
name|filerev
decl_stmt|;
comment|/* Delegations only */
name|time_t
name|expiry
decl_stmt|;
name|time_t
name|limit
decl_stmt|;
name|u_int64_t
name|compref
decl_stmt|;
block|}
name|deleg
struct|;
block|}
name|ls_un
union|;
name|struct
name|nfslockfile
modifier|*
name|ls_lfp
decl_stmt|;
comment|/* Back pointer */
name|struct
name|nfsrvcache
modifier|*
name|ls_op
decl_stmt|;
comment|/* Op cache reference */
name|struct
name|nfsclient
modifier|*
name|ls_clp
decl_stmt|;
comment|/* Back pointer */
name|u_short
name|ls_ownerlen
decl_stmt|;
comment|/* Length of ls_owner */
name|u_char
name|ls_owner
index|[
literal|1
index|]
decl_stmt|;
comment|/* malloc'd the correct size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ls_lock
value|ls_head.lock
end_define

begin_define
define|#
directive|define
name|ls_open
value|ls_head.open
end_define

begin_define
define|#
directive|define
name|ls_opentolockseq
value|ls_un.opentolockseq
end_define

begin_define
define|#
directive|define
name|ls_openowner
value|ls_un.openowner
end_define

begin_define
define|#
directive|define
name|ls_openstp
value|ls_un.openowner
end_define

begin_define
define|#
directive|define
name|ls_noopens
value|ls_un.noopens
end_define

begin_define
define|#
directive|define
name|ls_filerev
value|ls_un.deleg.filerev
end_define

begin_define
define|#
directive|define
name|ls_delegtime
value|ls_un.deleg.expiry
end_define

begin_define
define|#
directive|define
name|ls_delegtimelimit
value|ls_un.deleg.limit
end_define

begin_define
define|#
directive|define
name|ls_compref
value|ls_un.deleg.compref
end_define

begin_comment
comment|/*  * Nfs lock structure.  * This structure is chained off of the nfsstate (the lockowner) and  * nfslockfile (the file) structures, for the file and owner it  * refers to. It holds flags and a byte range.  * It also has back pointers to the associated lock_owner and lockfile.  */
end_comment

begin_struct
struct|struct
name|nfslock
block|{
name|LIST_ENTRY
argument_list|(
argument|nfslock
argument_list|)
name|lo_lckowner
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|nfslock
argument_list|)
name|lo_lckfile
expr_stmt|;
name|struct
name|nfsstate
modifier|*
name|lo_stp
decl_stmt|;
name|struct
name|nfslockfile
modifier|*
name|lo_lfp
decl_stmt|;
name|u_int64_t
name|lo_first
decl_stmt|;
name|u_int64_t
name|lo_end
decl_stmt|;
name|u_int32_t
name|lo_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to return a conflicting lock. (Must be large  * enough for the largest lock owner we can have.)  */
end_comment

begin_struct
struct|struct
name|nfslockconflict
block|{
name|nfsquad_t
name|cl_clientid
decl_stmt|;
name|u_int64_t
name|cl_first
decl_stmt|;
name|u_int64_t
name|cl_end
decl_stmt|;
name|u_int32_t
name|cl_flags
decl_stmt|;
name|u_short
name|cl_ownerlen
decl_stmt|;
name|u_char
name|cl_owner
index|[
name|NFSV4_OPAQUELIMIT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used to keep track of local locks that might need  * to be rolled back.  */
end_comment

begin_struct
struct|struct
name|nfsrollback
block|{
name|LIST_ENTRY
argument_list|(
argument|nfsrollback
argument_list|)
name|rlck_list
expr_stmt|;
name|uint64_t
name|rlck_first
decl_stmt|;
name|uint64_t
name|rlck_end
decl_stmt|;
name|int
name|rlck_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure refers to a file for which lock(s) and/or open(s) exist.  * Searched via hash table on file handle or found via the back pointer from an  * open or lock owner.  */
end_comment

begin_struct
struct|struct
name|nfslockfile
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsstate
argument_list|)
name|lf_open
expr_stmt|;
comment|/* Open list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsstate
argument_list|)
name|lf_deleg
expr_stmt|;
comment|/* Delegation list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfslock
argument_list|)
name|lf_lock
expr_stmt|;
comment|/* Lock list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfslock
argument_list|)
name|lf_locallock
expr_stmt|;
comment|/* Local lock list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsrollback
argument_list|)
name|lf_rollback
expr_stmt|;
comment|/* Local lock rollback list */
name|LIST_ENTRY
argument_list|(
argument|nfslockfile
argument_list|)
name|lf_hash
expr_stmt|;
comment|/* Hash list entry */
name|fhandle_t
name|lf_fh
decl_stmt|;
comment|/* The file handle */
name|struct
name|nfsv4lock
name|lf_locallock_lck
decl_stmt|;
comment|/* serialize local locking */
name|int
name|lf_usecount
decl_stmt|;
comment|/* Ref count for locking */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is malloc'd an chained off hash lists for user/group  * names.  */
end_comment

begin_struct
struct|struct
name|nfsusrgrp
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsusrgrp
argument_list|)
name|lug_lru
expr_stmt|;
comment|/* LRU list */
name|LIST_ENTRY
argument_list|(
argument|nfsusrgrp
argument_list|)
name|lug_numhash
expr_stmt|;
comment|/* Hash by id# */
name|LIST_ENTRY
argument_list|(
argument|nfsusrgrp
argument_list|)
name|lug_namehash
expr_stmt|;
comment|/* and by name */
name|time_t
name|lug_expiry
decl_stmt|;
comment|/* Expiry time in sec */
union|union
block|{
name|uid_t
name|un_uid
decl_stmt|;
comment|/* id# */
name|gid_t
name|un_gid
decl_stmt|;
block|}
name|lug_un
union|;
name|int
name|lug_namelen
decl_stmt|;
comment|/* Name length */
name|u_char
name|lug_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* malloc'd correct length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lug_uid
value|lug_un.un_uid
end_define

begin_define
define|#
directive|define
name|lug_gid
value|lug_un.un_gid
end_define

begin_comment
comment|/*  * These structures are used for the stable storage restart stuff.  */
end_comment

begin_comment
comment|/*  * Record at beginning of file.  */
end_comment

begin_struct
struct|struct
name|nfsf_rec
block|{
name|u_int32_t
name|lease
decl_stmt|;
comment|/* Lease duration */
name|u_int32_t
name|numboots
decl_stmt|;
comment|/* Number of boottimes */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_function_decl
name|void
name|nfsrv_cleanclient
parameter_list|(
name|struct
name|nfsclient
modifier|*
parameter_list|,
name|NFSPROC_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_freedeleglist
parameter_list|(
name|struct
name|nfsstatehead
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSRVSTATE_H_ */
end_comment

end_unit

