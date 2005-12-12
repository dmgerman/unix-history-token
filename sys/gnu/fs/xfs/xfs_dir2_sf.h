begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_SF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_SF_H__
end_define

begin_comment
comment|/*  * Directory layout when stored internal to an inode.  *  * Small directories are packed as tightly as possible so as to  * fit into the literal area of the inode.  */
end_comment

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dabuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dir2_block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Maximum size of a shortform directory.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_SF_MAX_SIZE
define|\
value|(XFS_DINODE_MAX_SIZE - (uint)sizeof(xfs_dinode_core_t) - \ 	 (uint)sizeof(xfs_agino_t))
end_define

begin_comment
comment|/*  * Inode number stored as 8 8-bit values.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__uint8_t
name|i
index|[
literal|8
index|]
decl_stmt|;
block|}
name|xfs_dir2_ino8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INO8_ARCH
parameter_list|(
name|di
parameter_list|,
name|arch
parameter_list|)
define|\
value|(xfs_ino_t)(DIRINO_GET_ARCH(&di,arch))
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INO8
parameter_list|(
name|di
parameter_list|)
define|\
value|XFS_DIR2_SF_GET_INO8_ARCH(di,ARCH_NOCONVERT)
end_define

begin_comment
comment|/*  * Inode number stored as 4 8-bit values.  * Works a lot of the time, when all the inode numbers in a directory  * fit in 32 bits.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__uint8_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|xfs_dir2_ino4_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INO4_ARCH
parameter_list|(
name|di
parameter_list|,
name|arch
parameter_list|)
define|\
value|(xfs_ino_t)(DIRINO4_GET_ARCH(&di,arch))
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INO4
parameter_list|(
name|di
parameter_list|)
define|\
value|XFS_DIR2_SF_GET_INO4_ARCH(di,ARCH_NOCONVERT)
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|xfs_dir2_ino8_t
name|i8
decl_stmt|;
name|xfs_dir2_ino4_t
name|i4
decl_stmt|;
block|}
name|xfs_dir2_inou_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR2_MAX_SHORT_INUM
value|((xfs_ino_t)0xffffffffULL)
end_define

begin_comment
comment|/*  * Normalized offset (in a data block) of the entry, really xfs_dir2_data_off_t.  * Only need 16 bits, this is the byte offset into the single block form.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|__uint8_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|xfs_dir2_sf_off_t
typedef|;
end_typedef

begin_comment
comment|/*  * The parent directory has a dedicated field, and the self-pointer must  * be calculated on the fly.  *  * Entries are packed toward the top as tightly as possible.  The header  * and the elements must be memcpy'd out into a work area to get correct  * alignment for the inode number fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_sf_hdr
block|{
name|__uint8_t
name|count
decl_stmt|;
comment|/* count of entries */
name|__uint8_t
name|i8count
decl_stmt|;
comment|/* count of 8-byte inode #s */
name|xfs_dir2_inou_t
name|parent
decl_stmt|;
comment|/* parent dir inode number */
block|}
name|xfs_dir2_sf_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_sf_entry
block|{
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* actual name length */
name|xfs_dir2_sf_off_t
name|offset
decl_stmt|;
comment|/* saved offset */
name|__uint8_t
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name, variable size */
name|xfs_dir2_inou_t
name|inumber
decl_stmt|;
comment|/* inode number, var. offset */
block|}
name|xfs_dir2_sf_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_sf
block|{
name|xfs_dir2_sf_hdr_t
name|hdr
decl_stmt|;
comment|/* shortform header */
name|xfs_dir2_sf_entry_t
name|list
index|[
literal|1
index|]
decl_stmt|;
comment|/* shortform entries */
block|}
name|xfs_dir2_sf_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_HDR_SIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_dir2_sf_hdr_size
parameter_list|(
name|int
name|i8count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_HDR_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_HDR_SIZE
parameter_list|(
name|i8count
parameter_list|)
value|xfs_dir2_sf_hdr_size(i8count)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_HDR_SIZE
parameter_list|(
name|i8count
parameter_list|)
define|\
value|((uint)sizeof(xfs_dir2_sf_hdr_t) - \ 	 ((i8count) == 0) * \ 	 ((uint)sizeof(xfs_dir2_ino8_t) - (uint)sizeof(xfs_dir2_ino4_t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_INUMBERP
operator|)
end_if

begin_function_decl
name|xfs_dir2_inou_t
modifier|*
name|xfs_dir2_sf_inumberp
parameter_list|(
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_INUMBERP
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_INUMBERP
parameter_list|(
name|sfep
parameter_list|)
value|xfs_dir2_sf_inumberp(sfep)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_INUMBERP
parameter_list|(
name|sfep
parameter_list|)
define|\
value|((xfs_dir2_inou_t *)&(sfep)->name[(sfep)->namelen])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_GET_INUMBER
operator|)
end_if

begin_function_decl
name|xfs_intino_t
name|xfs_dir2_sf_get_inumber_arch
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|,
name|xfs_dir2_inou_t
modifier|*
name|from
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_GET_INUMBER
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INUMBER_ARCH
parameter_list|(
name|sfp
parameter_list|,
name|from
parameter_list|,
name|arch
parameter_list|)
define|\
value|xfs_dir2_sf_get_inumber_arch(sfp, from, arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_INUMBER_ARCH
parameter_list|(
name|sfp
parameter_list|,
name|from
parameter_list|,
name|arch
parameter_list|)
define|\
value|((sfp)->hdr.i8count == 0 ? \ 		(xfs_intino_t)XFS_DIR2_SF_GET_INO4_ARCH(*(from), arch) : \ 		(xfs_intino_t)XFS_DIR2_SF_GET_INO8_ARCH(*(from), arch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_PUT_INUMBER
operator|)
end_if

begin_function_decl
name|void
name|xfs_dir2_sf_put_inumber_arch
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|,
name|xfs_ino_t
modifier|*
name|from
parameter_list|,
name|xfs_dir2_inou_t
modifier|*
name|to
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_PUT_INUMBER
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_PUT_INUMBER_ARCH
parameter_list|(
name|sfp
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|,
name|arch
parameter_list|)
define|\
value|xfs_dir2_sf_put_inumber_arch(sfp,from,to,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_PUT_INUMBER_ARCH
parameter_list|(
name|sfp
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|,
name|arch
parameter_list|)
define|\
value|if ((sfp)->hdr.i8count == 0) { \ 	    DIRINO4_COPY_ARCH(from,to,arch); \ 	} else { \ 	    DIRINO_COPY_ARCH(from,to,arch); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_GET_OFFSET
operator|)
end_if

begin_function_decl
name|xfs_dir2_data_aoff_t
name|xfs_dir2_sf_get_offset_arch
parameter_list|(
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_dir2_data_aoff_t
name|xfs_dir2_sf_get_offset
parameter_list|(
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_GET_OFFSET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_OFFSET_ARCH
parameter_list|(
name|sfep
parameter_list|,
name|arch
parameter_list|)
define|\
value|xfs_dir2_sf_get_offset_arch(sfep,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_GET_OFFSET_ARCH
parameter_list|(
name|sfep
parameter_list|,
name|arch
parameter_list|)
define|\
value|INT_GET_UNALIGNED_16_ARCH(&(sfep)->offset.i,arch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_PUT_OFFSET
operator|)
end_if

begin_function_decl
name|void
name|xfs_dir2_sf_put_offset_arch
parameter_list|(
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|,
name|xfs_dir2_data_aoff_t
name|off
parameter_list|,
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_PUT_OFFSET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_PUT_OFFSET_ARCH
parameter_list|(
name|sfep
parameter_list|,
name|off
parameter_list|,
name|arch
parameter_list|)
define|\
value|xfs_dir2_sf_put_offset_arch(sfep,off,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_PUT_OFFSET_ARCH
parameter_list|(
name|sfep
parameter_list|,
name|off
parameter_list|,
name|arch
parameter_list|)
define|\
value|INT_SET_UNALIGNED_16_ARCH(&(sfep)->offset.i,off,arch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_ENTSIZE_BYNAME
operator|)
end_if

begin_function_decl
name|int
name|xfs_dir2_sf_entsize_byname
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_ENTSIZE_BYNAME
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_ENTSIZE_BYNAME
parameter_list|(
name|sfp
parameter_list|,
name|len
parameter_list|)
define|\
value|xfs_dir2_sf_entsize_byname(sfp,len)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_ENTSIZE_BYNAME
parameter_list|(
name|sfp
parameter_list|,
name|len
parameter_list|)
comment|/* space a name uses */
define|\
value|((uint)sizeof(xfs_dir2_sf_entry_t) - 1 + (len) - \ 	 ((sfp)->hdr.i8count == 0) * \ 	 ((uint)sizeof(xfs_dir2_ino8_t) - (uint)sizeof(xfs_dir2_ino4_t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_ENTSIZE_BYENTRY
operator|)
end_if

begin_function_decl
name|int
name|xfs_dir2_sf_entsize_byentry
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|,
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_ENTSIZE_BYENTRY
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_ENTSIZE_BYENTRY
parameter_list|(
name|sfp
parameter_list|,
name|sfep
parameter_list|)
define|\
value|xfs_dir2_sf_entsize_byentry(sfp,sfep)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_ENTSIZE_BYENTRY
parameter_list|(
name|sfp
parameter_list|,
name|sfep
parameter_list|)
comment|/* space an entry uses */
define|\
value|((uint)sizeof(xfs_dir2_sf_entry_t) - 1 + (sfep)->namelen - \ 	 ((sfp)->hdr.i8count == 0) * \ 	 ((uint)sizeof(xfs_dir2_ino8_t) - (uint)sizeof(xfs_dir2_ino4_t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_FIRSTENTRY
operator|)
end_if

begin_function_decl
name|xfs_dir2_sf_entry_t
modifier|*
name|xfs_dir2_sf_firstentry
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_FIRSTENTRY
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_FIRSTENTRY
parameter_list|(
name|sfp
parameter_list|)
value|xfs_dir2_sf_firstentry(sfp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_FIRSTENTRY
parameter_list|(
name|sfp
parameter_list|)
comment|/* first entry in struct */
define|\
value|((xfs_dir2_sf_entry_t *) \ 	 ((char *)(sfp) + XFS_DIR2_SF_HDR_SIZE(sfp->hdr.i8count)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_NEXTENTRY
operator|)
end_if

begin_function_decl
name|xfs_dir2_sf_entry_t
modifier|*
name|xfs_dir2_sf_nextentry
parameter_list|(
name|xfs_dir2_sf_t
modifier|*
name|sfp
parameter_list|,
name|xfs_dir2_sf_entry_t
modifier|*
name|sfep
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_SF_NEXTENTRY
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_DIR2_SF_NEXTENTRY
parameter_list|(
name|sfp
parameter_list|,
name|sfep
parameter_list|)
value|xfs_dir2_sf_nextentry(sfp,sfep)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_SF_NEXTENTRY
parameter_list|(
name|sfp
parameter_list|,
name|sfep
parameter_list|)
comment|/* next entry in struct */
define|\
value|((xfs_dir2_sf_entry_t *) \ 		((char *)(sfep) + XFS_DIR2_SF_ENTSIZE_BYENTRY(sfp,sfep)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Functions.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_block_sfsize
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|xfs_dir2_block
modifier|*
name|block
parameter_list|,
name|xfs_dir2_sf_hdr_t
modifier|*
name|sfhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_block_to_sf
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|int
name|size
parameter_list|,
name|xfs_dir2_sf_hdr_t
modifier|*
name|sfhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_addname
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_create
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_ino_t
name|pino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_getdents
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
modifier|*
name|eofp
parameter_list|,
name|struct
name|xfs_dirent
modifier|*
name|dbp
parameter_list|,
name|xfs_dir2_put_t
name|put
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_lookup
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_removename
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_sf_replace
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_SF_H__ */
end_comment

end_unit

