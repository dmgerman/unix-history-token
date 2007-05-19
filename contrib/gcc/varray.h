begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Virtual array support.    Copyright (C) 1998, 1999, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.    Contributed by Cygnus Solutions.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_VARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_VARRAY_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_WIDE_INT
end_ifndef

begin_include
include|#
directive|include
file|"machmode.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_SYSTEM_H
end_ifndef

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enum indicating what the varray contains.    If this is changed, `element' in varray.c needs to be updated.  */
end_comment

begin_enum
enum|enum
name|varray_data_enum
block|{
name|VARRAY_DATA_C
block|,
name|VARRAY_DATA_UC
block|,
name|VARRAY_DATA_S
block|,
name|VARRAY_DATA_US
block|,
name|VARRAY_DATA_I
block|,
name|VARRAY_DATA_U
block|,
name|VARRAY_DATA_L
block|,
name|VARRAY_DATA_UL
block|,
name|VARRAY_DATA_HINT
block|,
name|VARRAY_DATA_UHINT
block|,
name|VARRAY_DATA_GENERIC
block|,
name|VARRAY_DATA_GENERIC_NOGC
block|,
name|VARRAY_DATA_CPTR
block|,
name|VARRAY_DATA_RTX
block|,
name|VARRAY_DATA_RTVEC
block|,
name|VARRAY_DATA_TREE
block|,
name|VARRAY_DATA_BITMAP
block|,
name|VARRAY_DATA_REG
block|,
name|VARRAY_DATA_BB
block|,
name|VARRAY_DATA_TE
block|,
name|VARRAY_DATA_EDGE
block|,
name|VARRAY_DATA_TREE_PTR
block|,
name|NUM_VARRAY_DATA
block|}
enum|;
end_enum

begin_comment
comment|/* Union of various array types that are used.  */
end_comment

begin_typedef
typedef|typedef
name|union
name|varray_data_tag
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|char
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_C"
argument_list|)
operator|)
argument_list|)
name|vdt_c
index|[
literal|1
index|]
block|;
name|unsigned
name|char
name|GTY
block|((
name|length
block|("%0.num_elements")
operator|,
block|tag ("VARRAY_DATA_UC")
typedef|))
name|vdt_uc
index|[
literal|1
index|]
typedef|;
end_typedef

begin_decl_stmt
name|short
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_S"
argument_list|)
operator|)
argument_list|)
name|vdt_s
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_US"
argument_list|)
operator|)
argument_list|)
name|vdt_us
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_I"
argument_list|)
operator|)
argument_list|)
name|vdt_i
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_U"
argument_list|)
operator|)
argument_list|)
name|vdt_u
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_L"
argument_list|)
operator|)
argument_list|)
name|vdt_l
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_UL"
argument_list|)
operator|)
argument_list|)
name|vdt_ul
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|HOST_WIDE_INT
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_HINT"
argument_list|)
operator|)
argument_list|)
name|vdt_hint
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|HOST_WIDE_INT
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_UHINT"
argument_list|)
operator|)
argument_list|)
name|vdt_uhint
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PTR
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|use_param
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_GENERIC"
argument_list|)
operator|)
argument_list|)
name|vdt_generic
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PTR
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|skip
argument_list|(
literal|""
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_GENERIC_NOGC"
argument_list|)
operator|)
argument_list|)
name|vdt_generic_nogc
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_CPTR"
argument_list|)
operator|)
argument_list|)
name|vdt_cptr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_RTX"
argument_list|)
operator|)
argument_list|)
name|vdt_rtx
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtvec
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_RTVEC"
argument_list|)
operator|)
argument_list|)
name|vdt_rtvec
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_TREE"
argument_list|)
operator|)
argument_list|)
name|vdt_tree
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bitmap_head_def
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_BITMAP"
argument_list|)
operator|)
argument_list|)
name|vdt_bitmap
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|reg_info_def
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|skip
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_REG"
argument_list|)
operator|)
argument_list|)
name|vdt_reg
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|basic_block_def
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|skip
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_BB"
argument_list|)
operator|)
argument_list|)
name|vdt_bb
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|elt_list
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_TE"
argument_list|)
operator|)
argument_list|)
name|vdt_te
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|edge_def
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_EDGE"
argument_list|)
operator|)
argument_list|)
name|vdt_e
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree
modifier|*
name|GTY
argument_list|(
operator|(
name|length
argument_list|(
literal|"%0.num_elements"
argument_list|)
operator|,
name|skip
argument_list|(
literal|""
argument_list|)
operator|,
name|tag
argument_list|(
literal|"VARRAY_DATA_TREE_PTR"
argument_list|)
operator|)
argument_list|)
name|vdt_tp
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|} varray_data
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Virtual array of pointers header.  */
end_comment

begin_decl_stmt
name|struct
name|varray_head_tag
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|size_t
name|num_elements
decl_stmt|;
comment|/* Maximum element number allocated.  */
name|size_t
name|elements_used
decl_stmt|;
comment|/* The number of elements used, if 				   using VARRAY_PUSH/VARRAY_POP.  */
name|enum
name|varray_data_enum
name|type
decl_stmt|;
comment|/* The kind of elements in the varray.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the varray for reporting errors */
name|varray_data
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"%0.type"
argument_list|)
operator|)
argument_list|)
name|data
decl_stmt|;
comment|/* The data elements follow, 						   must be last.  */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|varray_head_tag
modifier|*
name|varray_type
typedef|;
end_typedef

begin_comment
comment|/* Allocate a virtual array with NUM elements, each of which is SIZE bytes    long, named NAME.  Array elements are zeroed.  */
end_comment

begin_function_decl
specifier|extern
name|varray_type
name|varray_init
parameter_list|(
name|size_t
parameter_list|,
name|enum
name|varray_data_enum
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VARRAY_CHAR_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_C, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_UCHAR_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_UC, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_SHORT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_S, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_USHORT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_US, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_INT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_I, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_UINT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_U, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_LONG_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_L, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_ULONG_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_UL, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_WIDE_INT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_HINT, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_UWIDE_INT_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_UHINT, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_GENERIC_PTR_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_GENERIC, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_GENERIC_PTR_NOGC_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_GENERIC_NOGC, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_CHAR_PTR_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_CPTR, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_RTX_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_RTX, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_RTVEC_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_RTVEC, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_TREE_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_TREE, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_BITMAP_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_BITMAP, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_REG_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_REG, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_BB_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_BB, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_ELT_LIST_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_TE, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_EDGE_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_EDGE, name)
end_define

begin_define
define|#
directive|define
name|VARRAY_TREE_PTR_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, VARRAY_DATA_TREE_PTR, name)
end_define

begin_comment
comment|/* Free up memory allocated by the virtual array, but do not free any of the    elements involved.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_FREE
parameter_list|(
name|vp
parameter_list|)
define|\
value|do { if (vp) { free (vp); vp = (varray_type) 0; } } while (0)
end_define

begin_comment
comment|/* Grow/shrink the virtual array VA to N elements.  */
end_comment

begin_function_decl
specifier|extern
name|varray_type
name|varray_grow
parameter_list|(
name|varray_type
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VARRAY_GROW
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|((VA) = varray_grow (VA, N))
end_define

begin_define
define|#
directive|define
name|VARRAY_SIZE
parameter_list|(
name|VA
parameter_list|)
value|((VA)->num_elements)
end_define

begin_define
define|#
directive|define
name|VARRAY_ACTIVE_SIZE
parameter_list|(
name|VA
parameter_list|)
value|((VA)->elements_used)
end_define

begin_define
define|#
directive|define
name|VARRAY_POP_ALL
parameter_list|(
name|VA
parameter_list|)
value|((VA)->elements_used = 0)
end_define

begin_define
define|#
directive|define
name|VARRAY_CLEAR
parameter_list|(
name|VA
parameter_list|)
value|varray_clear(VA)
end_define

begin_function_decl
specifier|extern
name|void
name|varray_clear
parameter_list|(
name|varray_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_varray_statistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check for VARRAY_xxx macros being in bound.  */
end_comment

begin_if
if|#
directive|if
name|defined
name|ENABLE_CHECKING
operator|&&
operator|(
name|GCC_VERSION
operator|>=
literal|2007
operator|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|varray_check_failed
argument_list|(
name|varray_type
argument_list|,
name|size_t
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|varray_underflow
argument_list|(
name|varray_type
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VARRAY_CHECK
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|,
name|T
parameter_list|)
value|__extension__			\ (*({ varray_type const _va = (VA);				\      const size_t _n = (N);					\      if (_n>= _va->num_elements)				\        varray_check_failed (_va, _n, __FILE__, __LINE__, __FUNCTION__);	\&_va->data.T[_n]; }))
end_define

begin_define
define|#
directive|define
name|VARRAY_POP
parameter_list|(
name|VA
parameter_list|)
value|do {					\   varray_type const _va = (VA);					\   if (_va->elements_used == 0)					\     varray_underflow (_va, __FILE__, __LINE__, __FUNCTION__);	\   else								\     _va->elements_used--;					\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VARRAY_CHECK
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|,
name|T
parameter_list|)
value|((VA)->data.T[N])
end_define

begin_comment
comment|/* Pop the top element of VA.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_POP
parameter_list|(
name|VA
parameter_list|)
value|do { ((VA)->elements_used--); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Push X onto VA.  T is the name of the field in varray_data    corresponding to the type of X.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_PUSH
parameter_list|(
name|VA
parameter_list|,
name|T
parameter_list|,
name|X
parameter_list|)
define|\
value|do							\     {							\       if ((VA)->elements_used>= (VA)->num_elements)	\         VARRAY_GROW ((VA), 2 * (VA)->num_elements);	\       (VA)->data.T[(VA)->elements_used++] = (X);	\     }							\   while (0)
end_define

begin_define
define|#
directive|define
name|VARRAY_CHAR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_c)
end_define

begin_define
define|#
directive|define
name|VARRAY_UCHAR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_uc)
end_define

begin_define
define|#
directive|define
name|VARRAY_SHORT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_s)
end_define

begin_define
define|#
directive|define
name|VARRAY_USHORT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_us)
end_define

begin_define
define|#
directive|define
name|VARRAY_INT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_i)
end_define

begin_define
define|#
directive|define
name|VARRAY_UINT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_u)
end_define

begin_define
define|#
directive|define
name|VARRAY_LONG
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_l)
end_define

begin_define
define|#
directive|define
name|VARRAY_ULONG
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_ul)
end_define

begin_define
define|#
directive|define
name|VARRAY_WIDE_INT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_hint)
end_define

begin_define
define|#
directive|define
name|VARRAY_UWIDE_INT
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_uhint)
end_define

begin_define
define|#
directive|define
name|VARRAY_GENERIC_PTR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_generic)
end_define

begin_define
define|#
directive|define
name|VARRAY_GENERIC_PTR_NOGC
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_generic_nogc)
end_define

begin_define
define|#
directive|define
name|VARRAY_CHAR_PTR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_cptr)
end_define

begin_define
define|#
directive|define
name|VARRAY_RTX
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_rtx)
end_define

begin_define
define|#
directive|define
name|VARRAY_RTVEC
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_rtvec)
end_define

begin_define
define|#
directive|define
name|VARRAY_TREE
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_tree)
end_define

begin_define
define|#
directive|define
name|VARRAY_BITMAP
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_bitmap)
end_define

begin_define
define|#
directive|define
name|VARRAY_REG
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_reg)
end_define

begin_define
define|#
directive|define
name|VARRAY_BB
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_bb)
end_define

begin_define
define|#
directive|define
name|VARRAY_ELT_LIST
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_te)
end_define

begin_define
define|#
directive|define
name|VARRAY_EDGE
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_e)
end_define

begin_define
define|#
directive|define
name|VARRAY_TREE_PTR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, vdt_tp)
end_define

begin_comment
comment|/* Push a new element on the end of VA, extending it if necessary.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_PUSH_CHAR
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_c, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_UCHAR
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_uc, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_SHORT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_s, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_USHORT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_us, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_INT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_i, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_UINT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_u, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_LONG
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_l, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_ULONG
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_ul, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_WIDE_INT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_hint, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_UWIDE_INT
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_uhint, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_GENERIC_PTR
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_generic, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_GENERIC_PTR_NOGC
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_generic_nogc, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_CHAR_PTR
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_cptr, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_RTX
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_rtx, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_RTVEC
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_rtvec, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_TREE
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_tree, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_BITMAP
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_bitmap, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_REG
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_reg, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_BB
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_bb, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_EDGE
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_e, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_TREE_PTR
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, vdt_tp, X)
end_define

begin_comment
comment|/* Return the last element of VA.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_TOP
parameter_list|(
name|VA
parameter_list|,
name|T
parameter_list|)
value|VARRAY_CHECK(VA, (VA)->elements_used - 1, T)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_CHAR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_c)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UCHAR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_uc)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_SHORT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_s)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_USHORT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_us)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_i)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UINT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_u)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_LONG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_l)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_ULONG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_ul)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_WIDE_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_hint)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UWIDE_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_uhint)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_GENERIC_PTR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_generic)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_GENERIC_PTR_NOGC
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_generic_nogc)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_CHAR_PTR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_cptr)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_RTX
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_rtx)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_RTVEC
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_rtvec)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_TREE
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_tree)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_BITMAP
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_bitmap)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_REG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_reg)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_BB
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_bb)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_EDGE
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_e)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_TREE_PTR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, vdt_tp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_VARRAY_H */
end_comment

end_unit

