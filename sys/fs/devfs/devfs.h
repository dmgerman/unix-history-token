begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2000  *	Poul-Henning Kamp.  All rights reserved.  * Copyright (c) 2002  *	Dima Dorfman.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernfs.h	8.6 (Berkeley) 3/29/95  * From: FreeBSD: src/sys/miscfs/kernfs/kernfs.h 1.14  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_DEVFS_DEVFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_DEVFS_DEVFS_H_
end_define

begin_define
define|#
directive|define
name|DEVFS_MAGIC
value|0xdb0a087a
end_define

begin_comment
comment|/*  * Identifiers.  The ruleset and rule numbers are 16-bit values.  The  * "rule ID" is a combination of the ruleset and rule number; it  * should be able to univocally describe a rule in the system.  In  * this implementation, the upper 16 bits of the rule ID is the  * ruleset number; the lower 16 bits, the rule number within the  * aforementioned ruleset.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|devfs_rnum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|devfs_rsnum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|devfs_rid
typedef|;
end_typedef

begin_comment
comment|/*  * Identifier manipulators.  */
end_comment

begin_define
define|#
directive|define
name|rid2rsn
parameter_list|(
name|rid
parameter_list|)
value|((rid)>> 16)
end_define

begin_define
define|#
directive|define
name|rid2rn
parameter_list|(
name|rid
parameter_list|)
value|((rid)& 0xffff)
end_define

begin_define
define|#
directive|define
name|mkrid
parameter_list|(
name|rsn
parameter_list|,
name|rn
parameter_list|)
value|((rn) | ((rsn)<< 16))
end_define

begin_comment
comment|/*  * Plain DEVFS rule.  This gets shared between kernel and userland  * verbatim, so it shouldn't contain any pointers or other kernel- or  * userland-specific values.  */
end_comment

begin_struct
struct|struct
name|devfs_rule
block|{
name|uint32_t
name|dr_magic
decl_stmt|;
comment|/* Magic number. */
name|devfs_rid
name|dr_id
decl_stmt|;
comment|/* Identifier. */
comment|/* 	 * Conditions under which this rule should be applied.  These 	 * are ANDed together since OR can be simulated by using 	 * multiple rules.  dr_icond determines which of the other 	 * variables we should process. 	 */
name|int
name|dr_icond
decl_stmt|;
define|#
directive|define
name|DRC_DSWFLAGS
value|0x001
define|#
directive|define
name|DRC_PATHPTRN
value|0x002
name|int
name|dr_dswflags
decl_stmt|;
comment|/* cdevsw flags to match. */
define|#
directive|define
name|DEVFS_MAXPTRNLEN
value|200
name|char
name|dr_pathptrn
index|[
name|DEVFS_MAXPTRNLEN
index|]
decl_stmt|;
comment|/* Pattern to match path. */
comment|/* 	 * Things to change.  dr_iacts determines which of the other 	 * variables we should process. 	 */
name|int
name|dr_iacts
decl_stmt|;
define|#
directive|define
name|DRA_BACTS
value|0x001
define|#
directive|define
name|DRA_UID
value|0x002
define|#
directive|define
name|DRA_GID
value|0x004
define|#
directive|define
name|DRA_MODE
value|0x008
define|#
directive|define
name|DRA_INCSET
value|0x010
name|int
name|dr_bacts
decl_stmt|;
comment|/* Boolean (on/off) action. */
define|#
directive|define
name|DRB_HIDE
value|0x001
comment|/* Hide entry (DE_WHITEOUT). */
define|#
directive|define
name|DRB_UNHIDE
value|0x002
comment|/* Unhide entry. */
name|uid_t
name|dr_uid
decl_stmt|;
name|gid_t
name|dr_gid
decl_stmt|;
name|mode_t
name|dr_mode
decl_stmt|;
name|devfs_rsnum
name|dr_incset
decl_stmt|;
comment|/* Included ruleset. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Rule-related ioctls.  */
end_comment

begin_define
define|#
directive|define
name|DEVFSIO_RADD
value|_IOWR('D', 0, struct devfs_rule)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_RDEL
value|_IOW('D', 1, devfs_rid)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_RAPPLY
value|_IOW('D', 2, struct devfs_rule)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_RAPPLYID
value|_IOW('D', 3, devfs_rid)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_RGETNEXT
value|_IOWR('D', 4, struct devfs_rule)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_SUSE
value|_IOW('D', 10, devfs_rsnum)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_SAPPLY
value|_IOW('D', 11, devfs_rsnum)
end_define

begin_define
define|#
directive|define
name|DEVFSIO_SGETNEXT
value|_IOWR('D', 12, devfs_rsnum)
end_define

begin_comment
comment|/* XXX: DEVFSIO_RS_GET_INFO for refcount, active if any, etc. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_DEVFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|devfs_dirent
block|{
name|struct
name|cdev_priv
modifier|*
name|de_cdp
decl_stmt|;
name|int
name|de_inode
decl_stmt|;
name|int
name|de_flags
decl_stmt|;
define|#
directive|define
name|DE_WHITEOUT
value|0x1
define|#
directive|define
name|DE_DOT
value|0x2
define|#
directive|define
name|DE_DOTDOT
value|0x4
name|struct
name|dirent
modifier|*
name|de_dirent
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|devfs_dirent
argument_list|)
name|de_list
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|devfs_dirent
argument_list|)
name|de_dlist
expr_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|de_dir
decl_stmt|;
name|int
name|de_links
decl_stmt|;
name|mode_t
name|de_mode
decl_stmt|;
name|uid_t
name|de_uid
decl_stmt|;
name|gid_t
name|de_gid
decl_stmt|;
name|struct
name|label
modifier|*
name|de_label
decl_stmt|;
name|struct
name|timespec
name|de_atime
decl_stmt|;
name|struct
name|timespec
name|de_mtime
decl_stmt|;
name|struct
name|timespec
name|de_ctime
decl_stmt|;
name|struct
name|vnode
modifier|*
name|de_vnode
decl_stmt|;
name|char
modifier|*
name|de_symlink
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devfs_mount
block|{
name|u_int
name|dm_idx
decl_stmt|;
name|struct
name|mount
modifier|*
name|dm_mount
decl_stmt|;
name|struct
name|devfs_dirent
modifier|*
name|dm_rootdir
decl_stmt|;
name|unsigned
name|dm_generation
decl_stmt|;
name|struct
name|sx
name|dm_lock
decl_stmt|;
name|devfs_rsnum
name|dm_ruleset
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVFS_ROOTINO
value|2
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|devfs_rule_depth
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VFSTODEVFS
parameter_list|(
name|mp
parameter_list|)
value|((struct devfs_mount *)((mp)->mnt_data))
end_define

begin_function_decl
name|void
name|devfs_rules_apply
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|,
name|struct
name|devfs_dirent
modifier|*
name|de
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_rules_cleanup
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devfs_rules_ioctl
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devfs_allocv
parameter_list|(
name|struct
name|devfs_dirent
modifier|*
name|de
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdev
modifier|*
modifier|*
name|devfs_itod
parameter_list|(
name|int
name|inode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
modifier|*
name|devfs_itode
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|,
name|int
name|inode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_delete
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|,
name|struct
name|devfs_dirent
modifier|*
name|de
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_populate
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|devfs_cleanup
parameter_list|(
name|struct
name|devfs_mount
modifier|*
name|dm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
name|devfs_newdirent
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
name|devfs_vmkdir
parameter_list|(
name|struct
name|devfs_mount
modifier|*
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|struct
name|devfs_dirent
modifier|*
name|dotdot
parameter_list|,
name|u_int
name|inode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|devfs_dirent
modifier|*
name|devfs_find
parameter_list|(
name|struct
name|devfs_dirent
modifier|*
name|dd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_DEVFS_DEVFS_H_ */
end_comment

end_unit

