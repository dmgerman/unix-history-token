begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Virtual array support.    Copyright (C) 1998 Free Software Foundation, Inc.    Contributed by Cygnus Solutions.     This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU CC is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to the Free    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VARRAY_H_
end_ifndef

begin_define
define|#
directive|define
name|_VARRAY_H_
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
name|__GCC_SYSTEM_H__
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
name|rtx
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
name|GENERIC_PTR
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
name|PROTO
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
value|va = varray_init (num, sizeof (GENERIC_PTR), name)
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
value|do { if (vp) { free (vp); vp = (varray_type)0; } } while (0)
end_define

begin_comment
comment|/* Grow/shrink the virtual array VA to N elements.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|varray_grow
name|PROTO
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

begin_comment
comment|/* Check for VARRAY_xxx macros being in bound, return N for use as an    index.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_define
define|#
directive|define
name|VARRAY_CHECK
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
define|\
value|((((size_t)(N)< (VA)->num_elements)					\   ? 0									\   : (fatal ("Virtual array %s element %ld out of bounds, at %s:%d",	\ 	    (VA)->name, (long)(N), __FILE__, __LINE__), 0)),		\  (N))
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
parameter_list|)
value|(N)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VARRAY_CHAR
parameter_list|(
name|VA
parameter_list|,
name|N
parameter_list|)
value|((VA)->data.c[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.uc[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.s[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.us[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.i[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.u[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.l[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.ul[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.hint[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.uhint[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.generic[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.cptr[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.rtx[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.rtvec[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.tree[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.bitmap[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.sched[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.reg[ VARRAY_CHECK (VA, N) ])
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
value|((VA)->data.const_equiv[VARRAY_CHECK (VA, N)])
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
value|((VA)->data.bb[ VARRAY_CHECK (VA, N) ])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VARRAY_H_ */
end_comment

end_unit

