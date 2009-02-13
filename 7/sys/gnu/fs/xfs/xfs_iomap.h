begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_IOMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_IOMAP_H__
end_define

begin_define
define|#
directive|define
name|IOMAP_DADDR_NULL
value|((xfs_daddr_t) (-1LL))
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* iomap_flags values */
name|IOMAP_EOF
init|=
literal|0x01
block|,
comment|/* mapping contains EOF   */
name|IOMAP_HOLE
init|=
literal|0x02
block|,
comment|/* mapping covers a hole  */
name|IOMAP_DELAY
init|=
literal|0x04
block|,
comment|/* mapping covers delalloc region  */
name|IOMAP_REALTIME
init|=
literal|0x10
block|,
comment|/* mapping on the realtime device  */
name|IOMAP_UNWRITTEN
init|=
literal|0x20
block|,
comment|/* mapping covers allocated */
comment|/* but uninitialized file data  */
name|IOMAP_NEW
init|=
literal|0x40
comment|/* just allocate */
block|}
name|iomap_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* base extent manipulation calls */
name|BMAPI_READ
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/* read extents */
name|BMAPI_WRITE
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* create extents */
name|BMAPI_ALLOCATE
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* delayed allocate to real extents */
name|BMAPI_UNWRITTEN
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/* unwritten extents to real extents */
comment|/* modifiers */
name|BMAPI_IGNSTATE
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
comment|/* ignore unwritten state on read */
name|BMAPI_DIRECT
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
comment|/* direct instead of buffered write */
name|BMAPI_MMAP
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/* allocate for mmap write */
name|BMAPI_SYNC
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|/* sync write to flush delalloc space */
name|BMAPI_TRYLOCK
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
comment|/* non-blocking request */
name|BMAPI_DEVICE
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
comment|/* we only want to know the device */
block|}
name|bmapi_flags_t
typedef|;
end_typedef

begin_comment
comment|/*  * xfs_iomap_t:  File system I/O map  *  * The iomap_bn field is expressed in 512-byte blocks, and is where the  * mapping starts on disk.  *  * The iomap_offset, iomap_bsize and iomap_delta fields are in bytes.  * iomap_offset is the offset of the mapping in the file itself.  * iomap_bsize is the size of the mapping,  iomap_delta is the  * desired data's offset into the mapping, given the offset supplied  * to the file I/O map routine.  *  * When a request is made to read beyond the logical end of the object,  * iomap_size may be set to 0, but iomap_offset and iomap_length should be set  * to the actual amount of underlying storage that has been allocated, if any.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_iomap
block|{
name|xfs_daddr_t
name|iomap_bn
decl_stmt|;
comment|/* first 512b blk of mapping */
name|xfs_buftarg_t
modifier|*
name|iomap_target
decl_stmt|;
name|xfs_off_t
name|iomap_offset
decl_stmt|;
comment|/* offset of mapping, bytes */
name|xfs_off_t
name|iomap_bsize
decl_stmt|;
comment|/* size of mapping, bytes */
name|xfs_off_t
name|iomap_delta
decl_stmt|;
comment|/* offset into mapping, bytes */
name|iomap_flags_t
name|iomap_flags
decl_stmt|;
block|}
name|xfs_iomap_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|xfs_iocore
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_irec
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|xfs_iomap
parameter_list|(
name|struct
name|xfs_iocore
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|ssize_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_iomap
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_iomap_write_direct
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_bmbt_irec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_iomap_write_delay
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_bmbt_irec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_iomap_write_allocate
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|xfs_bmbt_irec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_iomap_write_unwritten
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|xfs_off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_IOMAP_H__*/
end_comment

end_unit

