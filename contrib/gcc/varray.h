begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Virtual array support.    Copyright (C) 1998, 1999, 2000, 2002 Free Software Foundation, Inc.    Contributed by Cygnus Solutions.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Auxiliary structure used inside the varray structure, used for    function integration data.  */
end_comment

begin_struct
struct|struct
name|const_equiv_data
block|{
comment|/* Map pseudo reg number in calling function to equivalent constant.  We      cannot in general substitute constants into parameter pseudo registers,      since some machine descriptions (many RISCs) won't always handle      the resulting insns.  So if an incoming parameter has a constant      equivalent, we record it here, and if the resulting insn is      recognizable, we go with it.       We also use this mechanism to convert references to incoming arguments      and stacked variables.  copy_rtx_and_substitute will replace the virtual      incoming argument and virtual stacked variables registers with new      pseudos that contain pointers into the replacement area allocated for      this inline instance.  These pseudos are then marked as being equivalent      to the appropriate address and substituted if valid.  */
name|struct
name|rtx_def
modifier|*
name|rtx
decl_stmt|;
comment|/* Record the valid age for each entry.  The entry is invalid if its      age is less than const_age.  */
name|unsigned
name|age
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Union of various array types that are used.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|varray_data_tag
block|{
name|char
name|c
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|uc
index|[
literal|1
index|]
decl_stmt|;
name|short
name|s
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|short
name|us
index|[
literal|1
index|]
decl_stmt|;
name|int
name|i
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|int
name|u
index|[
literal|1
index|]
decl_stmt|;
name|long
name|l
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|long
name|ul
index|[
literal|1
index|]
decl_stmt|;
name|HOST_WIDE_INT
name|hint
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|HOST_WIDE_INT
name|uhint
index|[
literal|1
index|]
decl_stmt|;
name|PTR
name|generic
index|[
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|cptr
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|rtx_def
modifier|*
name|rtx
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|rtvec_def
modifier|*
name|rtvec
index|[
literal|1
index|]
decl_stmt|;
name|union
name|tree_node
modifier|*
name|tree
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|bitmap_head_def
modifier|*
name|bitmap
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|sched_info_tag
modifier|*
name|sched
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|reg_info_def
modifier|*
name|reg
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|const_equiv_data
name|const_equiv
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|basic_block_def
modifier|*
name|bb
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|elt_list
modifier|*
name|te
index|[
literal|1
index|]
decl_stmt|;
block|}
name|varray_data
typedef|;
end_typedef

begin_comment
comment|/* Virtual array of pointers header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|varray_head_tag
block|{
name|size_t
name|num_elements
decl_stmt|;
comment|/* maximum element number allocated */
name|size_t
name|elements_used
decl_stmt|;
comment|/* the number of elements used, if 				   using VARRAY_PUSH/VARRAY_POP.  */
name|size_t
name|element_size
decl_stmt|;
comment|/* size of each data element */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of the varray for reporting errors */
name|varray_data
name|data
decl_stmt|;
comment|/* data elements follow, must be last */
block|}
typedef|*
name|varray_type
typedef|;
end_typedef

begin_comment
comment|/* Allocate a virtual array with NUM elements, each of which is SIZE bytes    long, named NAME.  Array elements are zeroed.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|varray_init
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|va = varray_init (num, sizeof (char), name)
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
value|va = varray_init (num, sizeof (unsigned char), name)
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
value|va = varray_init (num, sizeof (short), name)
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
value|va = varray_init (num, sizeof (unsigned short), name)
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
value|va = varray_init (num, sizeof (int), name)
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
value|va = varray_init (num, sizeof (unsigned int), name)
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
value|va = varray_init (num, sizeof (long), name)
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
value|va = varray_init (num, sizeof (unsigned long), name)
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
value|va = varray_init (num, sizeof (HOST_WIDE_INT), name)
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
value|va = varray_init (num, sizeof (unsigned HOST_WIDE_INT), name)
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
value|va = varray_init (num, sizeof (PTR), name)
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
value|va = varray_init (num, sizeof (char *), name)
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
value|va = varray_init (num, sizeof (struct rtx_def *), name)
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
value|va = varray_init (num, sizeof (struct rtvec_def), name)
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
value|va = varray_init (num, sizeof (union tree_node *), name)
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
value|va = varray_init (num, sizeof (struct bitmap_head_def *), name)
end_define

begin_define
define|#
directive|define
name|VARRAY_SCHED_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, sizeof (struct sched_info_tag *), name)
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
value|va = varray_init (num, sizeof (struct reg_info_def *), name)
end_define

begin_define
define|#
directive|define
name|VARRAY_CONST_EQUIV_INIT
parameter_list|(
name|va
parameter_list|,
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|va = varray_init (num, sizeof (struct const_equiv_data), name)
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
value|va = varray_init (num, sizeof (struct basic_block_def *), name)
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
value|va = varray_init (num, sizeof (struct elt_list *), name)
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

begin_decl_stmt
specifier|extern
name|varray_type
name|varray_grow
name|PARAMS
argument_list|(
operator|(
name|varray_type
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|PARAMS
argument_list|(
operator|(
name|varray_type
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
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
value|__extension__			\ (*({ varray_type _va = VA;					\      size_t _n = N; 						\      if (_n>= _va->num_elements)				\        varray_check_failed (_va, _n, __FILE__, __LINE__, __FUNCTION__);	\&_va->data.T[_n]; }))
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
value|do 							\     {							\       if ((VA)->elements_used>= (VA)->num_elements)	\         VARRAY_GROW ((VA), 2 * (VA)->num_elements);	\       (VA)->data.T[(VA)->elements_used++] = (X);	\     }							\   while (0)
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
define|\
value|((VA)->elements_used--)
end_define

begin_comment
comment|/* Return the top element of VA.  */
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
define|\
value|((VA)->data.T[(VA)->elements_used - 1])
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
value|VARRAY_CHECK (VA, N, c)
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
value|VARRAY_CHECK (VA, N, uc)
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
value|VARRAY_CHECK (VA, N, s)
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
value|VARRAY_CHECK (VA, N, us)
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
value|VARRAY_CHECK (VA, N, i)
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
value|VARRAY_CHECK (VA, N, u)
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
value|VARRAY_CHECK (VA, N, l)
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
value|VARRAY_CHECK (VA, N, ul)
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
value|VARRAY_CHECK (VA, N, hint)
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
value|VARRAY_CHECK (VA, N, uhint)
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
value|VARRAY_CHECK (VA, N, generic)
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
value|VARRAY_CHECK (VA, N, cptr)
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
value|VARRAY_CHECK (VA, N, rtx)
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
value|VARRAY_CHECK (VA, N, rtvec)
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
value|VARRAY_CHECK (VA, N, tree)
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
value|VARRAY_CHECK (VA, N, bitmap)
end_define

begin_define
define|#
directive|define
name|VARRAY_SCHED
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, sched)
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
value|VARRAY_CHECK (VA, N, reg)
end_define

begin_define
define|#
directive|define
name|VARRAY_CONST_EQUIV
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|VARRAY_CHECK (VA, N, const_equiv)
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
value|VARRAY_CHECK (VA, N, bb)
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
value|VARRAY_CHECK (VA, N, te)
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
value|VARRAY_PUSH (VA, c, X)
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
value|VARRAY_PUSH (VA, uc, X)
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
value|VARRAY_PUSH (VA, s, X)
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
value|VARRAY_PUSH (VA, us, X)
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
value|VARRAY_PUSH (VA, i, X)
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
value|VARRAY_PUSH (VA, u, X)
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
value|VARRAY_PUSH (VA, l, X)
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
value|VARRAY_PUSH (VA, ul, X)
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
value|VARRAY_PUSH (VA, hint, X)
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
value|VARRAY_PUSH (VA, uhint, X)
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
value|VARRAY_PUSH (VA, generic, X)
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
value|VARRAY_PUSH (VA, cptr, X)
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
value|VARRAY_PUSH (VA, rtx, X)
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
value|VARRAY_PUSH (VA, rtvec, X)
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
value|VARRAY_PUSH (VA, tree, X)
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
value|VARRAY_PUSH (VA, bitmap, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_SCHED
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, sched, X)
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
value|VARRAY_PUSH (VA, reg, X)
end_define

begin_define
define|#
directive|define
name|VARRAY_PUSH_CONST_EQUIV
parameter_list|(
name|VA
parameter_list|,
name|X
parameter_list|)
value|VARRAY_PUSH (VA, const_equiv, X)
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
value|VARRAY_PUSH (VA, bb, X)
end_define

begin_comment
comment|/* Return the last element of VA.  */
end_comment

begin_define
define|#
directive|define
name|VARRAY_TOP_CHAR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, c)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UCHAR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, uc)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_SHORT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, s)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_USHORT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, us)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, i)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UINT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, u)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_LONG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, l)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_ULONG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, ul)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_WIDE_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, hint)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_UWIDE_INT
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, uhint)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_GENERIC_PTR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, generic)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_CHAR_PTR
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, cptr)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_RTX
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, rtx)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_RTVEC
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, rtvec)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_TREE
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, tree)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_BITMAP
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, bitmap)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_SCHED
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, sched)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_REG
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, reg)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_CONST_EQUIV
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, const_equiv)
end_define

begin_define
define|#
directive|define
name|VARRAY_TOP_BB
parameter_list|(
name|VA
parameter_list|)
value|VARRAY_TOP (VA, bb)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_VARRAY_H */
end_comment

end_unit

