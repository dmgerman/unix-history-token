begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Matthew Dillon.  Terms of use and redistribution in all  * forms are covered by the BSD copyright in the file "/usr/src/COPYRIGHT".  *  * Implements bitmap resource lists.  *  *	Usage:  *		blist = blist_create(blocks)  *		(void)  blist_destroy(blist)  *		blkno = blist_alloc(blist, count)  *		(void)  blist_free(blist, blkno, count)  *		(void)  blist_resize(&blist, count, freeextra)  *		  *  *	Notes:  *		on creation, the entire list is marked reserved.  You should  *		first blist_free() the sections you want to make available  *		for allocation before doing general blist_alloc()/free()  *		ops.  *  *		SWAPBLK_NONE is returned on failure.  This module is typically  *		capable of managing up to (2^31) blocks per blist, though  *		the memory utilization would be insane if you actually did  *		that.  Managing something like 512MB worth of 4K blocks   *		eats around 32 KBytes of memory.   *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BLIST_H_
end_define

begin_define
define|#
directive|define
name|LOG2
parameter_list|(
name|v
parameter_list|)
value|(((u_daddr_t)(v)>= 0x80000000U) ? 31 : \ 			((u_daddr_t)(v)>= 0x40000000U) ? 30 : \ 			((u_daddr_t)(v)>= 0x20000000U) ? 29 : \ 			((u_daddr_t)(v)>= 0x10000000U) ? 28 : \ 			((u_daddr_t)(v)>= 0x08000000U) ? 27 : \ 			((u_daddr_t)(v)>= 0x04000000U) ? 26 : \ 			((u_daddr_t)(v)>= 0x02000000U) ? 25 : \ 			((u_daddr_t)(v)>= 0x01000000U) ? 24 : \ 			((u_daddr_t)(v)>= 0x00800000U) ? 23 : \ 			((u_daddr_t)(v)>= 0x00400000U) ? 22 : \ 			((u_daddr_t)(v)>= 0x00200000U) ? 21 : \ 			((u_daddr_t)(v)>= 0x00100000U) ? 20 : \ 			((u_daddr_t)(v)>= 0x00080000U) ? 19 : \ 			((u_daddr_t)(v)>= 0x00040000U) ? 18 : \ 			((u_daddr_t)(v)>= 0x00020000U) ? 17 : \ 			((u_daddr_t)(v)>= 0x00010000U) ? 16 : \ 			((u_daddr_t)(v)>= 0x00008000U) ? 15 : \ 			((u_daddr_t)(v)>= 0x00004000U) ? 14 : \ 			((u_daddr_t)(v)>= 0x00002000U) ? 13 : \ 			((u_daddr_t)(v)>= 0x00001000U) ? 12 : \ 			((u_daddr_t)(v)>= 0x00000800U) ? 11 : \ 			((u_daddr_t)(v)>= 0x00000400U) ? 10 : \ 			((u_daddr_t)(v)>= 0x00000200U) ? 9 : \ 			((u_daddr_t)(v)>= 0x00000100U) ? 8 : \ 			((u_daddr_t)(v)>= 0x00000080U) ? 7 : \ 			((u_daddr_t)(v)>= 0x00000040U) ? 6 : \ 			((u_daddr_t)(v)>= 0x00000020U) ? 5 : \ 			((u_daddr_t)(v)>= 0x00000010U) ? 4 : \ 			((u_daddr_t)(v)>= 0x00000008U) ? 3 : \ 			((u_daddr_t)(v)>= 0x00000004U) ? 2 : \ 			((u_daddr_t)(v)>= 0x00000002U) ? 1 : 0)
end_define

begin_comment
comment|/*  * blmeta and bl_bitmap_t MUST be a power of 2 in size.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|blmeta
block|{
union|union
block|{
name|daddr_t
name|bmu_avail
decl_stmt|;
comment|/* space available under us	*/
name|u_daddr_t
name|bmu_bitmap
decl_stmt|;
comment|/* bitmap if we are a leaf	*/
block|}
name|u
union|;
name|daddr_t
name|bm_bighint
decl_stmt|;
comment|/* biggest contiguous block hint*/
block|}
name|blmeta_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|blist
block|{
name|daddr_t
name|bl_blocks
decl_stmt|;
comment|/* area of coverage		*/
name|daddr_t
name|bl_radix
decl_stmt|;
comment|/* coverage radix		*/
name|daddr_t
name|bl_skip
decl_stmt|;
comment|/* starting skip		*/
name|daddr_t
name|bl_free
decl_stmt|;
comment|/* number of free blocks	*/
name|blmeta_t
modifier|*
name|bl_root
decl_stmt|;
comment|/* root of radix tree		*/
name|daddr_t
name|bl_rootblks
decl_stmt|;
comment|/* daddr_t blks allocated for tree */
block|}
typedef|*
name|blist_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLIST_META_RADIX
value|16
end_define

begin_define
define|#
directive|define
name|BLIST_META_RADIX_SHIFT
value|LOG2(BLIST_META_RADIX)
end_define

begin_define
define|#
directive|define
name|BLIST_BMAP_RADIX
value|(sizeof(u_daddr_t)*8)
end_define

begin_define
define|#
directive|define
name|BLIST_BMAP_RADIX_SHIFT
value|LOG2(BLIST_BMAP_RADIX)
end_define

begin_define
define|#
directive|define
name|BLIST_MAX_ALLOC
value|BLIST_BMAP_RADIX
end_define

begin_function_decl
specifier|extern
name|blist_t
name|blist_create
parameter_list|(
name|daddr_t
name|blocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blist_destroy
parameter_list|(
name|blist_t
name|blist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|daddr_t
name|blist_alloc
parameter_list|(
name|blist_t
name|blist
parameter_list|,
name|daddr_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blist_free
parameter_list|(
name|blist_t
name|blist
parameter_list|,
name|daddr_t
name|blkno
parameter_list|,
name|daddr_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blist_print
parameter_list|(
name|blist_t
name|blist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|blist_resize
parameter_list|(
name|blist_t
modifier|*
name|pblist
parameter_list|,
name|daddr_t
name|count
parameter_list|,
name|int
name|freenew
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_BLIST_H_ */
end_comment

end_unit

