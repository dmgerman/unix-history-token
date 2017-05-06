begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: tmpfs.h,v 1.26 2007/02/22 06:37:00 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005, 2006 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Julio M. Merino Vidal, developed as part of Google's Summer of Code  * 2005 program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_TMPFS_TMPFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_TMPFS_TMPFS_H_
end_define

begin_comment
comment|/* ---------------------------------------------------------------------  * KERNEL-SPECIFIC DEFINITIONS  * --------------------------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|<sys/dirent.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<vm/swap_pager.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TMPFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_TMPFSNAME
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Internal representation of a tmpfs directory entry.  */
end_comment

begin_struct
struct|struct
name|tmpfs_dirent
block|{
name|TAILQ_ENTRY
argument_list|(
argument|tmpfs_dirent
argument_list|)
name|td_entries
expr_stmt|;
comment|/* Length of the name stored in this directory entry.  This avoids 	 * the need to recalculate it every time the name is used. */
name|uint16_t
name|td_namelen
decl_stmt|;
comment|/* The name of the entry, allocated from a string pool.  This 	* string is not required to be zero-terminated; therefore, the 	* td_namelen field must always be used when accessing its value. */
name|char
modifier|*
name|td_name
decl_stmt|;
comment|/* Pointer to the node this entry refers to.  In case this field 	 * is NULL, the node is a whiteout. */
name|struct
name|tmpfs_node
modifier|*
name|td_node
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A directory in tmpfs holds a sorted list of directory entries, which in  * turn point to other files (which can be directories themselves).  *  * In tmpfs, this list is managed by a tail queue, whose head is defined by  * the struct tmpfs_dir type.  *  * It is imporant to notice that directories do not have entries for . and  * .. as other file systems do.  These can be generated when requested  * based on information available by other means, such as the pointer to  * the node itself in the former case or the pointer to the parent directory  * in the latter case.  This is done to simplify tmpfs's code and, more  * importantly, to remove redundancy. */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|tmpfs_dir
argument_list|,
name|tmpfs_dirent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Each entry in a directory has a cookie that identifies it.  Cookies  * supersede offsets within directories because, given how tmpfs stores  * directories in memory, there is no such thing as an offset.  (Emulating  * a real offset could be very difficult.)  *   * The '.', '..' and the end of directory markers have fixed cookies which  * cannot collide with the cookies generated by other entries.  The cookies  * fot the other entries are generated based on the memory address on which  * stores their information is stored.  *  * Ideally, using the entry's memory pointer as the cookie would be enough  * to represent it and it wouldn't cause collisions in any system.  * Unfortunately, this results in "offsets" with very large values which  * later raise problems in the Linux compatibility layer (and maybe in other  * places) as described in PR kern/32034.  Hence we need to workaround this  * with a rather ugly hack.  *  * Linux 32-bit binaries, unless built with _FILE_OFFSET_BITS=64, have off_t  * set to 'long', which is a 32-bit *signed* long integer.  Regardless of  * the macro value, GLIBC (2.3 at least) always uses the getdents64  * system call (when calling readdir) which internally returns off64_t  * offsets.  In order to make 32-bit binaries work, *GLIBC* converts the  * 64-bit values returned by the kernel to 32-bit ones and aborts with  * EOVERFLOW if the conversion results in values that won't fit in 32-bit  * integers (which it assumes is because the directory is extremely large).  * This wouldn't cause problems if we were dealing with unsigned integers,  * but as we have signed integers, this check fails due to sign expansion.  *  * For example, consider that the kernel returns the 0xc1234567 cookie to  * userspace in a off64_t integer.  Later on, GLIBC casts this value to  * off_t (remember, signed) with code similar to:  *     system call returns the offset in kernel_value;  *     off_t casted_value = kernel_value;  *     if (sizeof(off_t) != sizeof(off64_t)&&  *         kernel_value != casted_value)  *             error!  * In this case, casted_value still has 0xc1234567, but when it is compared  * for equality against kernel_value, it is promoted to a 64-bit integer and  * becomes 0xffffffffc1234567, which is different than 0x00000000c1234567.  * Then, GLIBC assumes this is because the directory is very large.  *  * Given that all the above happens in user-space, we have no control over  * it; therefore we must workaround the issue here.  We do this by  * truncating the pointer value to a 32-bit integer and hope that there  * won't be collisions.  In fact, this will not cause any problems in  * 32-bit platforms but some might arise in 64-bit machines (I'm not sure  * if they can happen at all in practice).  *  * XXX A nicer solution shall be attempted. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|TMPFS_DIRCOOKIE_DOT
value|0
end_define

begin_define
define|#
directive|define
name|TMPFS_DIRCOOKIE_DOTDOT
value|1
end_define

begin_define
define|#
directive|define
name|TMPFS_DIRCOOKIE_EOF
value|2
end_define

begin_function
specifier|static
name|__inline
name|off_t
name|tmpfs_dircookie
parameter_list|(
name|struct
name|tmpfs_dirent
modifier|*
name|de
parameter_list|)
block|{
name|off_t
name|cookie
decl_stmt|;
name|cookie
operator|=
operator|(
operator|(
name|off_t
operator|)
operator|(
name|uintptr_t
operator|)
name|de
operator|>>
literal|1
operator|)
operator|&
literal|0x7FFFFFFF
expr_stmt|;
name|MPASS
argument_list|(
name|cookie
operator|!=
name|TMPFS_DIRCOOKIE_DOT
argument_list|)
expr_stmt|;
name|MPASS
argument_list|(
name|cookie
operator|!=
name|TMPFS_DIRCOOKIE_DOTDOT
argument_list|)
expr_stmt|;
name|MPASS
argument_list|(
name|cookie
operator|!=
name|TMPFS_DIRCOOKIE_EOF
argument_list|)
expr_stmt|;
return|return
name|cookie
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Internal representation of a tmpfs file system node.  *  * This structure is splitted in two parts: one holds attributes common  * to all file types and the other holds data that is only applicable to  * a particular type.  The code must be careful to only access those  * attributes that are actually allowed by the node's type.  *  *  * Below is the key of locks used to protected the fields in the following  * structures.  *  */
end_comment

begin_struct
struct|struct
name|tmpfs_node
block|{
comment|/* Doubly-linked list entry which links all existing nodes for a 	 * single file system.  This is provided to ease the removal of 	 * all nodes during the unmount operation. */
name|LIST_ENTRY
argument_list|(
argument|tmpfs_node
argument_list|)
name|tn_entries
expr_stmt|;
comment|/* The node's type.  Any of 'VBLK', 'VCHR', 'VDIR', 'VFIFO', 	 * 'VLNK', 'VREG' and 'VSOCK' is allowed.  The usage of vnode 	 * types instead of a custom enumeration is to make things simpler 	 * and faster, as we do not need to convert between two types. */
name|enum
name|vtype
name|tn_type
decl_stmt|;
comment|/* Node identifier. */
name|ino_t
name|tn_id
decl_stmt|;
comment|/* Node's internal status.  This is used by several file system 	 * operations to do modifications to the node in a delayed 	 * fashion. */
name|int
name|tn_status
decl_stmt|;
define|#
directive|define
name|TMPFS_NODE_ACCESSED
value|(1<< 1)
define|#
directive|define
name|TMPFS_NODE_MODIFIED
value|(1<< 2)
define|#
directive|define
name|TMPFS_NODE_CHANGED
value|(1<< 3)
comment|/* The node size.  It does not necessarily match the real amount 	 * of memory consumed by it. */
name|off_t
name|tn_size
decl_stmt|;
comment|/* Generic node attributes. */
name|uid_t
name|tn_uid
decl_stmt|;
name|gid_t
name|tn_gid
decl_stmt|;
name|mode_t
name|tn_mode
decl_stmt|;
name|int
name|tn_flags
decl_stmt|;
name|nlink_t
name|tn_links
decl_stmt|;
name|struct
name|timespec
name|tn_atime
decl_stmt|;
name|struct
name|timespec
name|tn_mtime
decl_stmt|;
name|struct
name|timespec
name|tn_ctime
decl_stmt|;
name|struct
name|timespec
name|tn_birthtime
decl_stmt|;
name|unsigned
name|long
name|tn_gen
decl_stmt|;
comment|/* As there is a single vnode for each active file within the 	 * system, care has to be taken to avoid allocating more than one 	 * vnode per file.  In order to do this, a bidirectional association 	 * is kept between vnodes and nodes. 	 * 	 * Whenever a vnode is allocated, its v_data field is updated to 	 * point to the node it references.  At the same time, the node's 	 * tn_vnode field is modified to point to the new vnode representing 	 * it.  Further attempts to allocate a vnode for this same node will 	 * result in returning a new reference to the value stored in 	 * tn_vnode. 	 * 	 * May be NULL when the node is unused (that is, no vnode has been 	 * allocated for it or it has been reclaimed). */
name|struct
name|vnode
modifier|*
name|tn_vnode
decl_stmt|;
comment|/* interlock to protect tn_vpstate */
name|struct
name|mtx
name|tn_interlock
decl_stmt|;
comment|/* Identify if current node has vnode assiocate with 	 * or allocating vnode. 	 */
name|int
name|tn_vpstate
decl_stmt|;
comment|/* misc data field for different tn_type node */
union|union
block|{
comment|/* Valid when tn_type == VBLK || tn_type == VCHR. */
name|dev_t
name|tn_rdev
decl_stmt|;
comment|/* Valid when tn_type == VDIR. */
struct|struct
name|tn_dir
block|{
comment|/* Pointer to the parent directory.  The root 			 * directory has a pointer to itself in this field; 			 * this property identifies the root node. */
name|struct
name|tmpfs_node
modifier|*
name|tn_parent
decl_stmt|;
comment|/* Head of a tail-queue that links the contents of 			 * the directory together.  See above for a 			 * description of its contents. */
name|struct
name|tmpfs_dir
name|tn_dirhead
decl_stmt|;
comment|/* Number and pointer of the first directory entry 			 * returned by the readdir operation if it were 			 * called again to continue reading data from the 			 * same directory as before.  This is used to speed 			 * up reads of long directories, assuming that no 			 * more than one read is in progress at a given time. 			 * Otherwise, these values are discarded and a linear 			 * scan is performed from the beginning up to the 			 * point where readdir starts returning values. */
name|off_t
name|tn_readdir_lastn
decl_stmt|;
name|struct
name|tmpfs_dirent
modifier|*
name|tn_readdir_lastp
decl_stmt|;
block|}
name|tn_dir
struct|;
comment|/* Valid when tn_type == VLNK. */
comment|/* The link's target, allocated from a string pool. */
name|char
modifier|*
name|tn_link
decl_stmt|;
comment|/* Valid when tn_type == VREG. */
struct|struct
name|tn_reg
block|{
comment|/* The contents of regular files stored in a tmpfs 			 * file system are represented by a single anonymous 			 * memory object (aobj, for short).  The aobj provides 			 * direct access to any position within the file, 			 * because its contents are always mapped in a 			 * contiguous region of virtual memory.  It is a task 			 * of the memory management subsystem (see uvm(9)) to 			 * issue the required page ins or page outs whenever 			 * a position within the file is accessed. */
name|vm_object_t
name|tn_aobj
decl_stmt|;
name|size_t
name|tn_aobj_pages
decl_stmt|;
block|}
name|tn_reg
struct|;
comment|/* Valid when tn_type = VFIFO */
struct|struct
name|tn_fifo
block|{
name|fo_rdwr_t
modifier|*
name|tn_fo_read
decl_stmt|;
name|fo_rdwr_t
modifier|*
name|tn_fo_write
decl_stmt|;
block|}
name|tn_fifo
struct|;
block|}
name|tn_spec
union|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|tmpfs_node_list
argument_list|,
name|tmpfs_node
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|tn_rdev
value|tn_spec.tn_rdev
end_define

begin_define
define|#
directive|define
name|tn_dir
value|tn_spec.tn_dir
end_define

begin_define
define|#
directive|define
name|tn_link
value|tn_spec.tn_link
end_define

begin_define
define|#
directive|define
name|tn_reg
value|tn_spec.tn_reg
end_define

begin_define
define|#
directive|define
name|tn_fifo
value|tn_spec.tn_fifo
end_define

begin_define
define|#
directive|define
name|TMPFS_NODE_LOCK
parameter_list|(
name|node
parameter_list|)
value|mtx_lock(&(node)->tn_interlock)
end_define

begin_define
define|#
directive|define
name|TMPFS_NODE_UNLOCK
parameter_list|(
name|node
parameter_list|)
value|mtx_unlock(&(node)->tn_interlock)
end_define

begin_define
define|#
directive|define
name|TMPFS_NODE_MTX
parameter_list|(
name|node
parameter_list|)
value|(&(node)->tn_interlock)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|TMPFS_ASSERT_LOCKED
parameter_list|(
name|node
parameter_list|)
value|do {					\ 		MPASS(node != NULL);					\ 		MPASS(node->tn_vnode != NULL);				\ 		if (!VOP_ISLOCKED(node->tn_vnode)&&			\ 		    !mtx_owned(TMPFS_NODE_MTX(node)))			\ 			panic("tmpfs: node is not locked: %p", node);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TMPFS_ASSERT_ELOCKED
parameter_list|(
name|node
parameter_list|)
value|do {					\ 		MPASS((node) != NULL);					\ 		MPASS((node)->tn_vnode != NULL);			\ 		mtx_assert(TMPFS_NODE_MTX(node), MA_OWNED);		\ 		ASSERT_VOP_LOCKED((node)->tn_vnode, "tmpfs");		\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TMPFS_ASSERT_LOCKED
parameter_list|(
name|node
parameter_list|)
value|(void)0
end_define

begin_define
define|#
directive|define
name|TMPFS_ASSERT_ELOCKED
parameter_list|(
name|node
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TMPFS_VNODE_ALLOCATING
value|1
end_define

begin_define
define|#
directive|define
name|TMPFS_VNODE_WANT
value|2
end_define

begin_define
define|#
directive|define
name|TMPFS_VNODE_DOOMED
value|4
end_define

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Internal representation of a tmpfs mount point.  */
end_comment

begin_struct
struct|struct
name|tmpfs_mount
block|{
comment|/* Maximum number of memory pages available for use by the file 	 * system, set during mount time.  This variable must never be 	 * used directly as it may be bigger than the current amount of 	 * free memory; in the extreme case, it will hold the SIZE_MAX 	 * value.  Instead, use the TMPFS_PAGES_MAX macro. */
name|size_t
name|tm_pages_max
decl_stmt|;
comment|/* Number of pages in use by the file system.  Cannot be bigger 	 * than the value returned by TMPFS_PAGES_MAX in any case. */
name|size_t
name|tm_pages_used
decl_stmt|;
comment|/* Pointer to the node representing the root directory of this 	 * file system. */
name|struct
name|tmpfs_node
modifier|*
name|tm_root
decl_stmt|;
comment|/* Maximum number of possible nodes for this file system; set 	 * during mount time.  We need a hard limit on the maximum number 	 * of nodes to avoid allocating too much of them; their objects 	 * cannot be released until the file system is unmounted. 	 * Otherwise, we could easily run out of memory by creating lots 	 * of empty files and then simply removing them. */
name|ino_t
name|tm_nodes_max
decl_stmt|;
comment|/* unrhdr used to allocate inode numbers */
name|struct
name|unrhdr
modifier|*
name|tm_ino_unr
decl_stmt|;
comment|/* Number of nodes currently that are in use. */
name|ino_t
name|tm_nodes_inuse
decl_stmt|;
comment|/* maximum representable file size */
name|u_int64_t
name|tm_maxfilesize
decl_stmt|;
comment|/* Nodes are organized in two different lists.  The used list 	 * contains all nodes that are currently used by the file system; 	 * i.e., they refer to existing files.  The available list contains 	 * all nodes that are currently available for use by new files. 	 * Nodes must be kept in this list (instead of deleting them) 	 * because we need to keep track of their generation number (tn_gen 	 * field). 	 * 	 * Note that nodes are lazily allocated: if the available list is 	 * empty and we have enough space to create more nodes, they will be 	 * created and inserted in the used list.  Once these are released, 	 * they will go into the available list, remaining alive until the 	 * file system is unmounted. */
name|struct
name|tmpfs_node_list
name|tm_nodes_used
decl_stmt|;
comment|/* All node lock to protect the node list and tmp_pages_used */
name|struct
name|mtx
name|allnode_lock
decl_stmt|;
comment|/* Pools used to store file system meta data.  These are not shared 	 * across several instances of tmpfs for the reasons described in 	 * tmpfs_pool.c. */
name|uma_zone_t
name|tm_dirent_pool
decl_stmt|;
name|uma_zone_t
name|tm_node_pool
decl_stmt|;
comment|/* Read-only status. */
name|int
name|tm_ronly
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TMPFS_LOCK
parameter_list|(
name|tm
parameter_list|)
value|mtx_lock(&(tm)->allnode_lock)
end_define

begin_define
define|#
directive|define
name|TMPFS_UNLOCK
parameter_list|(
name|tm
parameter_list|)
value|mtx_unlock(&(tm)->allnode_lock)
end_define

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * This structure maps a file identifier to a tmpfs node.  Used by the  * NFS code.  */
end_comment

begin_struct
struct|struct
name|tmpfs_fid
block|{
name|uint16_t
name|tf_len
decl_stmt|;
name|uint16_t
name|tf_pad
decl_stmt|;
name|ino_t
name|tf_id
decl_stmt|;
name|unsigned
name|long
name|tf_gen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes for tmpfs_subr.c.  */
end_comment

begin_function_decl
name|int
name|tmpfs_alloc_node
parameter_list|(
name|struct
name|tmpfs_mount
modifier|*
parameter_list|,
name|enum
name|vtype
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|dev_t
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_free_node
parameter_list|(
name|struct
name|tmpfs_mount
modifier|*
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_alloc_dirent
parameter_list|(
name|struct
name|tmpfs_mount
modifier|*
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|struct
name|tmpfs_dirent
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_free_dirent
parameter_list|(
name|struct
name|tmpfs_mount
modifier|*
parameter_list|,
name|struct
name|tmpfs_dirent
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_alloc_vp
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_free_vp
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_alloc_file
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|struct
name|componentname
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_dir_attach
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|tmpfs_dirent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_dir_detach
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|tmpfs_dirent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tmpfs_dirent
modifier|*
name|tmpfs_dir_lookup
parameter_list|(
name|struct
name|tmpfs_node
modifier|*
name|node
parameter_list|,
name|struct
name|tmpfs_node
modifier|*
name|f
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_dir_getdotdent
parameter_list|(
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_dir_getdotdotdent
parameter_list|(
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tmpfs_dirent
modifier|*
name|tmpfs_dir_lookupbycookie
parameter_list|(
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_dir_getdents
parameter_list|(
name|struct
name|tmpfs_node
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_dir_whiteout_add
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
name|void
name|tmpfs_dir_whiteout_remove
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
name|tmpfs_reg_resize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_chflags
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
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_chmod
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|mode_t
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
name|tmpfs_chown
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
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
name|tmpfs_chsize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|u_quad_t
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
name|tmpfs_chtimes
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
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
name|void
name|tmpfs_itimes
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tmpfs_update
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tmpfs_truncate
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Convenience macros to simplify some logical expressions.  */
end_comment

begin_define
define|#
directive|define
name|IMPLIES
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!(a) || (b))
end_define

begin_define
define|#
directive|define
name|IFF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(IMPLIES(a, b)&& IMPLIES(b, a))
end_define

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Checks that the directory entry pointed by 'de' matches the name 'name'  * with a length of 'len'.  */
end_comment

begin_define
define|#
directive|define
name|TMPFS_DIRENT_MATCHES
parameter_list|(
name|de
parameter_list|,
name|name
parameter_list|,
name|len
parameter_list|)
define|\
value|(de->td_namelen == (uint16_t)len&& \     bcmp((de)->td_name, (name), (de)->td_namelen) == 0)
end_define

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Ensures that the node pointed by 'node' is a directory and that its  * contents are consistent with respect to directories.  */
end_comment

begin_define
define|#
directive|define
name|TMPFS_VALIDATE_DIR
parameter_list|(
name|node
parameter_list|)
define|\
value|MPASS((node)->tn_type == VDIR); \     MPASS((node)->tn_size % sizeof(struct tmpfs_dirent) == 0); \     MPASS((node)->tn_dir.tn_readdir_lastp == NULL || \ 	tmpfs_dircookie((node)->tn_dir.tn_readdir_lastp) == (node)->tn_dir.tn_readdir_lastn);
end_define

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Memory management stuff.  */
end_comment

begin_comment
comment|/* Amount of memory pages to reserve for the system (e.g., to not use by  * tmpfs).  * XXX: Should this be tunable through sysctl, for instance? */
end_comment

begin_define
define|#
directive|define
name|TMPFS_PAGES_RESERVED
value|(4 * 1024 * 1024 / PAGE_SIZE)
end_define

begin_comment
comment|/*  * Returns information about the number of available memory pages,  * including physical and virtual ones.  *  * Remember to remove TMPFS_PAGES_RESERVED from the returned value to avoid  * excessive memory usage.  *  */
end_comment

begin_function
specifier|static
name|__inline
name|size_t
name|tmpfs_mem_info
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|swap_pager_avail
operator|+
name|cnt
operator|.
name|v_free_count
operator|+
name|cnt
operator|.
name|v_cache_count
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Returns the maximum size allowed for a tmpfs file system.  This macro  * must be used instead of directly retrieving the value from tm_pages_max.  * The reason is that the size of a tmpfs file system is dynamic: it lets  * the user store files as long as there is enough free memory (including  * physical memory and swap space).  Therefore, the amount of memory to be  * used is either the limit imposed by the user during mount time or the  * amount of available memory, whichever is lower.  To avoid consuming all  * the memory for a given mount point, the system will always reserve a  * minimum of TMPFS_PAGES_RESERVED pages, which is also taken into account  * by this macro (see above). */
end_comment

begin_function
specifier|static
name|__inline
name|size_t
name|TMPFS_PAGES_MAX
parameter_list|(
name|struct
name|tmpfs_mount
modifier|*
name|tmp
parameter_list|)
block|{
name|size_t
name|freepages
decl_stmt|;
name|freepages
operator|=
name|tmpfs_mem_info
argument_list|()
expr_stmt|;
name|freepages
operator|-=
name|freepages
operator|<
name|TMPFS_PAGES_RESERVED
condition|?
name|freepages
else|:
name|TMPFS_PAGES_RESERVED
expr_stmt|;
return|return
name|MIN
argument_list|(
name|tmp
operator|->
name|tm_pages_max
argument_list|,
name|freepages
operator|+
name|tmp
operator|->
name|tm_pages_used
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Returns the available space for the given file system. */
end_comment

begin_define
define|#
directive|define
name|TMPFS_META_PAGES
parameter_list|(
name|tmp
parameter_list|)
value|(howmany((tmp)->tm_nodes_inuse * (sizeof(struct tmpfs_node) \ 				+ sizeof(struct tmpfs_dirent)), PAGE_SIZE))
end_define

begin_define
define|#
directive|define
name|TMPFS_FILE_PAGES
parameter_list|(
name|tmp
parameter_list|)
value|((tmp)->tm_pages_used)
end_define

begin_define
define|#
directive|define
name|TMPFS_PAGES_AVAIL
parameter_list|(
name|tmp
parameter_list|)
value|(TMPFS_PAGES_MAX(tmp)> \ 			TMPFS_META_PAGES(tmp)+TMPFS_FILE_PAGES(tmp)? \ 			TMPFS_PAGES_MAX(tmp) - TMPFS_META_PAGES(tmp) \ 			- TMPFS_FILE_PAGES(tmp):0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Macros/functions to convert from generic data structures to tmpfs  * specific ones.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|tmpfs_mount
modifier|*
name|VFS_TO_TMPFS
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
block|{
name|struct
name|tmpfs_mount
modifier|*
name|tmp
decl_stmt|;
name|MPASS
argument_list|(
operator|(
name|mp
operator|)
operator|!=
name|NULL
operator|&&
operator|(
name|mp
operator|)
operator|->
name|mnt_data
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|tmp
operator|=
operator|(
expr|struct
name|tmpfs_mount
operator|*
operator|)
operator|(
name|mp
operator|)
operator|->
name|mnt_data
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|tmpfs_node
modifier|*
name|VP_TO_TMPFS_NODE
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
block|{
name|struct
name|tmpfs_node
modifier|*
name|node
decl_stmt|;
name|MPASS
argument_list|(
operator|(
name|vp
operator|)
operator|!=
name|NULL
operator|&&
operator|(
name|vp
operator|)
operator|->
name|v_data
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|node
operator|=
operator|(
expr|struct
name|tmpfs_node
operator|*
operator|)
name|vp
operator|->
name|v_data
expr_stmt|;
return|return
name|node
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|tmpfs_node
modifier|*
name|VP_TO_TMPFS_DIR
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
block|{
name|struct
name|tmpfs_node
modifier|*
name|node
decl_stmt|;
name|node
operator|=
name|VP_TO_TMPFS_NODE
argument_list|(
name|vp
argument_list|)
expr_stmt|;
name|TMPFS_VALIDATE_DIR
argument_list|(
name|node
argument_list|)
expr_stmt|;
return|return
name|node
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FS_TMPFS_TMPFS_H_ */
end_comment

end_unit

