begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SA_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SA_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

begin_include
include|#
directive|include
file|<sys/refcount.h>
end_include

begin_include
include|#
directive|include
file|<sys/list.h>
end_include

begin_comment
comment|/*  * Array of known attributes and their  * various characteristics.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sa_attr_table
block|{
name|sa_attr_type_t
name|sa_attr
decl_stmt|;
name|uint8_t
name|sa_registered
decl_stmt|;
name|uint16_t
name|sa_length
decl_stmt|;
name|sa_bswap_type_t
name|sa_byteswap
decl_stmt|;
name|char
modifier|*
name|sa_name
decl_stmt|;
block|}
name|sa_attr_table_t
typedef|;
end_typedef

begin_comment
comment|/*  * Zap attribute format for attribute registration  *  * 64      56      48      40      32      24      16      8       0  * +-------+-------+-------+-------+-------+-------+-------+-------+  * |        unused         |      len      | bswap |   attr num    |  * +-------+-------+-------+-------+-------+-------+-------+-------+  *  * Zap attribute format for layout information.  *  * layout information is stored as an array of attribute numbers  * The name of the attribute is the layout number (0, 1, 2, ...)  *  * 16       0  * +---- ---+  * | attr # |  * +--------+  * | attr # |  * +--- ----+  *  ......  *  */
end_comment

begin_define
define|#
directive|define
name|ATTR_BSWAP
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 16, 8)
end_define

begin_define
define|#
directive|define
name|ATTR_LENGTH
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 24, 16)
end_define

begin_define
define|#
directive|define
name|ATTR_NUM
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 0, 16)
end_define

begin_define
define|#
directive|define
name|ATTR_ENCODE
parameter_list|(
name|x
parameter_list|,
name|attr
parameter_list|,
name|length
parameter_list|,
name|bswap
parameter_list|)
define|\
value|{ \ 	BF64_SET(x, 24, 16, length); \ 	BF64_SET(x, 16, 8, bswap); \ 	BF64_SET(x, 0, 16, attr); \ }
end_define

begin_define
define|#
directive|define
name|TOC_OFF
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 0, 23)
end_define

begin_define
define|#
directive|define
name|TOC_ATTR_PRESENT
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 31, 1)
end_define

begin_define
define|#
directive|define
name|TOC_LEN_IDX
parameter_list|(
name|x
parameter_list|)
value|BF32_GET(x, 24, 4)
end_define

begin_define
define|#
directive|define
name|TOC_ATTR_ENCODE
parameter_list|(
name|x
parameter_list|,
name|len_idx
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ \ 	BF32_SET(x, 31, 1, 1); \ 	BF32_SET(x, 24, 7, len_idx); \ 	BF32_SET(x, 0, 24, offset); \ }
end_define

begin_define
define|#
directive|define
name|SA_LAYOUTS
value|"LAYOUTS"
end_define

begin_define
define|#
directive|define
name|SA_REGISTRY
value|"REGISTRY"
end_define

begin_comment
comment|/*  * Each unique layout will have their own table  * sa_lot (layout_table)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sa_lot
block|{
name|avl_node_t
name|lot_num_node
decl_stmt|;
name|avl_node_t
name|lot_hash_node
decl_stmt|;
name|uint64_t
name|lot_num
decl_stmt|;
name|uint64_t
name|lot_hash
decl_stmt|;
name|sa_attr_type_t
modifier|*
name|lot_attrs
decl_stmt|;
comment|/* array of attr #'s */
name|uint32_t
name|lot_var_sizes
decl_stmt|;
comment|/* how many aren't fixed size */
name|uint32_t
name|lot_attr_count
decl_stmt|;
comment|/* total attr count */
name|list_t
name|lot_idx_tab
decl_stmt|;
comment|/* should be only a couple of entries */
name|int
name|lot_instance
decl_stmt|;
comment|/* used with lot_hash to identify entry */
block|}
name|sa_lot_t
typedef|;
end_typedef

begin_comment
comment|/* index table of offsets */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sa_idx_tab
block|{
name|list_node_t
name|sa_next
decl_stmt|;
name|sa_lot_t
modifier|*
name|sa_layout
decl_stmt|;
name|uint16_t
modifier|*
name|sa_variable_lengths
decl_stmt|;
name|refcount_t
name|sa_refcount
decl_stmt|;
name|uint32_t
modifier|*
name|sa_idx_tab
decl_stmt|;
comment|/* array of offsets */
block|}
name|sa_idx_tab_t
typedef|;
end_typedef

begin_comment
comment|/*  * Since the offset/index information into the actual data  * will usually be identical we can share that information with  * all handles that have the exact same offsets.  *  * You would typically only have a large number of different table of  * contents if you had a several variable sized attributes.  *  * Two AVL trees are used to track the attribute layout numbers.  * one is keyed by number and will be consulted when a DMU_OT_SA  * object is first read.  The second tree is keyed by the hash signature  * of the attributes and will be consulted when an attribute is added  * to determine if we already have an instance of that layout.  Both  * of these tree's are interconnected.  The only difference is that  * when an entry is found in the "hash" tree the list of attributes will  * need to be compared against the list of attributes you have in hand.  * The assumption is that typically attributes will just be updated and  * adding a completely new attribute is a very rare operation.  */
end_comment

begin_struct
struct|struct
name|sa_os
block|{
name|kmutex_t
name|sa_lock
decl_stmt|;
name|boolean_t
name|sa_need_attr_registration
decl_stmt|;
name|boolean_t
name|sa_force_spill
decl_stmt|;
name|uint64_t
name|sa_master_obj
decl_stmt|;
name|uint64_t
name|sa_reg_attr_obj
decl_stmt|;
name|uint64_t
name|sa_layout_attr_obj
decl_stmt|;
name|int
name|sa_num_attrs
decl_stmt|;
name|sa_attr_table_t
modifier|*
name|sa_attr_table
decl_stmt|;
comment|/* private attr table */
name|sa_update_cb_t
modifier|*
name|sa_update_cb
decl_stmt|;
name|avl_tree_t
name|sa_layout_num_tree
decl_stmt|;
comment|/* keyed by layout number */
name|avl_tree_t
name|sa_layout_hash_tree
decl_stmt|;
comment|/* keyed by layout hash value */
name|int
name|sa_user_table_sz
decl_stmt|;
name|sa_attr_type_t
modifier|*
name|sa_user_table
decl_stmt|;
comment|/* user name->attr mapping table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * header for all bonus and spill buffers.  *  * The header has a fixed portion with a variable number  * of "lengths" depending on the number of variable sized  * attributes which are determined by the "layout number"  */
end_comment

begin_define
define|#
directive|define
name|SA_MAGIC
value|0x2F505A
end_define

begin_comment
comment|/* ZFS SA */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sa_hdr_phys
block|{
name|uint32_t
name|sa_magic
decl_stmt|;
comment|/* BEGIN CSTYLED */
comment|/* 	 * Encoded with hdrsize and layout number as follows: 	 * 16      10       0 	 * +--------+-------+ 	 * | hdrsz  |layout | 	 * +--------+-------+ 	 * 	 * Bits 0-10 are the layout number 	 * Bits 11-16 are the size of the header. 	 * The hdrsize is the number * 8 	 * 	 * For example. 	 * hdrsz of 1 ==> 8 byte header 	 *          2 ==> 16 byte header 	 * 	 */
comment|/* END CSTYLED */
name|uint16_t
name|sa_layout_info
decl_stmt|;
name|uint16_t
name|sa_lengths
index|[
literal|1
index|]
decl_stmt|;
comment|/* optional sizes for variable length attrs */
comment|/* ... Data follows the lengths.  */
block|}
name|sa_hdr_phys_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SA_HDR_LAYOUT_NUM
parameter_list|(
name|hdr
parameter_list|)
value|BF32_GET(hdr->sa_layout_info, 0, 10)
end_define

begin_define
define|#
directive|define
name|SA_HDR_SIZE
parameter_list|(
name|hdr
parameter_list|)
value|BF32_GET_SB(hdr->sa_layout_info, 10, 6, 3, 0)
end_define

begin_define
define|#
directive|define
name|SA_HDR_LAYOUT_INFO_ENCODE
parameter_list|(
name|x
parameter_list|,
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|{ \ 	BF32_SET_SB(x, 10, 6, 3, 0, size); \ 	BF32_SET(x, 0, 10, num); \ }
end_define

begin_typedef
typedef|typedef
enum|enum
name|sa_buf_type
block|{
name|SA_BONUS
init|=
literal|1
block|,
name|SA_SPILL
init|=
literal|2
block|}
name|sa_buf_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|sa_data_op
block|{
name|SA_LOOKUP
block|,
name|SA_UPDATE
block|,
name|SA_ADD
block|,
name|SA_REPLACE
block|,
name|SA_REMOVE
block|}
name|sa_data_op_t
typedef|;
end_typedef

begin_comment
comment|/*  * Opaque handle used for most sa functions  *  * This needs to be kept as small as possible.  */
end_comment

begin_struct
struct|struct
name|sa_handle
block|{
name|kmutex_t
name|sa_lock
decl_stmt|;
name|dmu_buf_t
modifier|*
name|sa_bonus
decl_stmt|;
name|dmu_buf_t
modifier|*
name|sa_spill
decl_stmt|;
name|objset_t
modifier|*
name|sa_os
decl_stmt|;
name|void
modifier|*
name|sa_userp
decl_stmt|;
name|sa_idx_tab_t
modifier|*
name|sa_bonus_tab
decl_stmt|;
comment|/* idx of bonus */
name|sa_idx_tab_t
modifier|*
name|sa_spill_tab
decl_stmt|;
comment|/* only present if spill activated */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SA_GET_DB
parameter_list|(
name|hdl
parameter_list|,
name|type
parameter_list|)
define|\
value|(dmu_buf_impl_t *)((type == SA_BONUS) ? hdl->sa_bonus : hdl->sa_spill)
end_define

begin_define
define|#
directive|define
name|SA_GET_HDR
parameter_list|(
name|hdl
parameter_list|,
name|type
parameter_list|)
define|\
value|((sa_hdr_phys_t *)((dmu_buf_impl_t *)(SA_GET_DB(hdl, \ 	type))->db.db_data))
end_define

begin_define
define|#
directive|define
name|SA_IDX_TAB_GET
parameter_list|(
name|hdl
parameter_list|,
name|type
parameter_list|)
define|\
value|(type == SA_BONUS ? hdl->sa_bonus_tab : hdl->sa_spill_tab)
end_define

begin_define
define|#
directive|define
name|IS_SA_BONUSTYPE
parameter_list|(
name|a
parameter_list|)
define|\
value|((a == DMU_OT_SA) ? B_TRUE : B_FALSE)
end_define

begin_define
define|#
directive|define
name|SA_BONUSTYPE_FROM_DB
parameter_list|(
name|db
parameter_list|)
define|\
value|(dmu_get_bonustype((dmu_buf_t *)db))
end_define

begin_define
define|#
directive|define
name|SA_BLKPTR_SPACE
value|(DN_MAX_BONUSLEN - sizeof (blkptr_t))
end_define

begin_define
define|#
directive|define
name|SA_LAYOUT_NUM
parameter_list|(
name|x
parameter_list|,
name|type
parameter_list|)
define|\
value|((!IS_SA_BONUSTYPE(type) ? 0 : (((IS_SA_BONUSTYPE(type))&& \ 	((SA_HDR_LAYOUT_NUM(x)) == 0)) ? 1 : SA_HDR_LAYOUT_NUM(x))))
end_define

begin_define
define|#
directive|define
name|SA_REGISTERED_LEN
parameter_list|(
name|sa
parameter_list|,
name|attr
parameter_list|)
value|sa->sa_attr_table[attr].sa_length
end_define

begin_define
define|#
directive|define
name|SA_ATTR_LEN
parameter_list|(
name|sa
parameter_list|,
name|idx
parameter_list|,
name|attr
parameter_list|,
name|hdr
parameter_list|)
value|((SA_REGISTERED_LEN(sa, attr) == 0) ?\ 	hdr->sa_lengths[TOC_LEN_IDX(idx->sa_idx_tab[attr])] : \ 	SA_REGISTERED_LEN(sa, attr))
end_define

begin_define
define|#
directive|define
name|SA_SET_HDR
parameter_list|(
name|hdr
parameter_list|,
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|{ \ 		hdr->sa_magic = SA_MAGIC; \ 		SA_HDR_LAYOUT_INFO_ENCODE(hdr->sa_layout_info, num, size); \ 	}
end_define

begin_define
define|#
directive|define
name|SA_ATTR_INFO
parameter_list|(
name|sa
parameter_list|,
name|idx
parameter_list|,
name|hdr
parameter_list|,
name|attr
parameter_list|,
name|bulk
parameter_list|,
name|type
parameter_list|,
name|hdl
parameter_list|)
define|\
value|{ \ 		bulk.sa_size = SA_ATTR_LEN(sa, idx, attr, hdr); \ 		bulk.sa_buftype = type; \ 		bulk.sa_addr = \ 		    (void *)((uintptr_t)TOC_OFF(idx->sa_idx_tab[attr]) + \ 		    (uintptr_t)hdr); \ }
end_define

begin_define
define|#
directive|define
name|SA_HDR_SIZE_MATCH_LAYOUT
parameter_list|(
name|hdr
parameter_list|,
name|tb
parameter_list|)
define|\
value|(SA_HDR_SIZE(hdr) == (sizeof (sa_hdr_phys_t) + \ 	(tb->lot_var_sizes> 1 ? P2ROUNDUP((tb->lot_var_sizes - 1) * \ 	sizeof (uint16_t), 8) : 0)))
end_define

begin_function_decl
name|int
name|sa_add_impl
parameter_list|(
name|sa_handle_t
modifier|*
parameter_list|,
name|sa_attr_type_t
parameter_list|,
name|uint32_t
parameter_list|,
name|sa_data_locator_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa_register_update_callback_locked
parameter_list|(
name|objset_t
modifier|*
parameter_list|,
name|sa_update_cb_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sa_size_locked
parameter_list|(
name|sa_handle_t
modifier|*
parameter_list|,
name|sa_attr_type_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa_default_locator
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|boolean_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sa_attr_size
parameter_list|(
name|sa_os_t
modifier|*
parameter_list|,
name|sa_idx_tab_t
modifier|*
parameter_list|,
name|sa_attr_type_t
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|sa_hdr_phys_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SA_IMPL_H */
end_comment

end_unit

