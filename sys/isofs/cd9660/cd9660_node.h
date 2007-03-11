begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cd9660_node.h	8.6 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Theoretically, directories can be more than 2Gb in length,  * however, in practice this seems unlikely. So, we define  * the type doff_t as a long to keep down the cost of doing  * lookup on a 32-bit machine. If you are porting to a 64-bit  * architecture, you should make doff_t the same as off_t.  */
end_comment

begin_define
define|#
directive|define
name|doff_t
value|long
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|timespec
name|iso_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|iso_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|iso_ctime
decl_stmt|;
comment|/* time file changed */
name|u_short
name|iso_mode
decl_stmt|;
comment|/* files access mode and type */
name|uid_t
name|iso_uid
decl_stmt|;
comment|/* owner user id */
name|gid_t
name|iso_gid
decl_stmt|;
comment|/* owner group id */
name|short
name|iso_links
decl_stmt|;
comment|/* links of file */
name|dev_t
name|iso_rdev
decl_stmt|;
comment|/* Major/Minor number for special */
block|}
name|ISO_RRIP_INODE
typedef|;
end_typedef

begin_struct
struct|struct
name|iso_node
block|{
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
comment|/* vnode associated with this inode */
name|u_long
name|i_flag
decl_stmt|;
comment|/* see below */
name|ino_t
name|i_number
decl_stmt|;
comment|/* the identity of the inode */
comment|/* we use the actual starting block of the file */
name|struct
name|iso_mnt
modifier|*
name|i_mnt
decl_stmt|;
comment|/* filesystem associated with this inode */
name|struct
name|lockf
modifier|*
name|i_lockf
decl_stmt|;
comment|/* head of byte-level lock list */
name|doff_t
name|i_endoff
decl_stmt|;
comment|/* end of useful stuff in directory */
name|doff_t
name|i_diroff
decl_stmt|;
comment|/* offset in dir, where we found last entry */
name|doff_t
name|i_offset
decl_stmt|;
comment|/* offset of free space in directory */
name|ino_t
name|i_ino
decl_stmt|;
comment|/* inode number of found directory */
name|long
name|iso_extent
decl_stmt|;
comment|/* extent of file */
name|unsigned
name|long
name|i_size
decl_stmt|;
name|long
name|iso_start
decl_stmt|;
comment|/* actual start of data of file (may be different */
comment|/* from iso_extent, if file has extended attributes) */
name|ISO_RRIP_INODE
name|inode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_forw
value|i_chain[0]
end_define

begin_define
define|#
directive|define
name|i_back
value|i_chain[1]
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|IN_ACCESS
value|0x0020
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|((struct iso_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|ITOV
parameter_list|(
name|ip
parameter_list|)
value|((ip)->i_vnode)
end_define

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
name|M_ISOFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ISOFSNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_bmap_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_cachedlookup_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_inactive_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_reclaim_args
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Prototypes for ISOFS vnode operations  */
end_comment

begin_function_decl
name|int
name|cd9660_lookup
parameter_list|(
name|struct
name|vop_cachedlookup_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_bmap
parameter_list|(
name|struct
name|vop_bmap_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_blkatoff
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|char
modifier|*
modifier|*
name|res
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_defattr
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
parameter_list|,
name|struct
name|iso_node
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|enum
name|ISO_FTYPE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cd9660_deftstamp
parameter_list|(
name|struct
name|iso_directory_record
modifier|*
parameter_list|,
name|struct
name|iso_node
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|enum
name|ISO_FTYPE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_tstamp_conv7
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|,
name|enum
name|ISO_FTYPE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cd9660_tstamp_conv17
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
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

end_unit

