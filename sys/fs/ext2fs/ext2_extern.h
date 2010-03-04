begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ffs_extern.h	8.3 (Berkeley) 4/16/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_EXTERN_H_
end_define

begin_struct_decl
struct_decl|struct
name|ext2fs_dinode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|indir
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfsconf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ext2_alloc
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_balloc
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_blkatoff
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_blkfree
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|ext2_blkpref
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int
parameter_list|,
name|int32_t
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_bmap
parameter_list|(
name|struct
name|vop_bmap_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_bmaparray
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|int32_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_dirbad
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|doff_t
name|offset
parameter_list|,
name|char
modifier|*
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_ei2i
parameter_list|(
name|struct
name|ext2fs_dinode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_getlbns
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|struct
name|indir
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_i2ei
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|ext2fs_dinode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_itimes
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_reallocblks
parameter_list|(
name|struct
name|vop_reallocblks_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_setblock
parameter_list|(
name|struct
name|m_ext2fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_truncate
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_update
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_valloc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_vfree
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_vinit
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|vop_vector
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_lookup
parameter_list|(
name|struct
name|vop_cachedlookup_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_readdir
parameter_list|(
name|struct
name|vop_readdir_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext2_print_inode
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_direnter
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_dirremove
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_dirrewrite
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_dirempty
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_checkpath
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cg_has_sb
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags to low-level allocation routines. */
end_comment

begin_define
define|#
directive|define
name|B_CLRBUF
value|0x01
end_define

begin_comment
comment|/* Request allocated buffer be cleared. */
end_comment

begin_define
define|#
directive|define
name|B_SYNC
value|0x02
end_define

begin_comment
comment|/* Do all allocations synchronously. */
end_comment

begin_define
define|#
directive|define
name|B_METAONLY
value|0x04
end_define

begin_comment
comment|/* Return indirect block buffer. */
end_comment

begin_define
define|#
directive|define
name|B_NOWAIT
value|0x08
end_define

begin_comment
comment|/* do not sleep to await lock */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|ext2_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|ext2_fifoops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2_EXTERN_H_ */
end_comment

end_unit

