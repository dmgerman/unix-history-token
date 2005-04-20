begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Simple bitmaps.    Copyright (C) 1999, 2000, 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_SBITMAP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_SBITMAP_H
end_define

begin_comment
comment|/* It's not clear yet whether using bitmap.[ch] will be a win.    It should be straightforward to convert so for now we keep things simple    while more important issues are dealt with.  */
end_comment

begin_define
define|#
directive|define
name|SBITMAP_ELT_BITS
value|((unsigned) HOST_BITS_PER_WIDE_INT)
end_define

begin_define
define|#
directive|define
name|SBITMAP_ELT_TYPE
value|unsigned HOST_WIDE_INT
end_define

begin_typedef
typedef|typedef
struct|struct
name|simple_bitmap_def
block|{
name|unsigned
name|int
name|n_bits
decl_stmt|;
comment|/* Number of bits.  */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* Size in elements.  */
name|unsigned
name|int
name|bytes
decl_stmt|;
comment|/* Size in bytes.  */
name|SBITMAP_ELT_TYPE
name|elms
index|[
literal|1
index|]
decl_stmt|;
comment|/* The elements.  */
block|}
typedef|*
name|sbitmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SBITMAP_ELT_TYPE
modifier|*
name|sbitmap_ptr
typedef|;
end_typedef

begin_comment
comment|/* Return the set size needed for N elements.  */
end_comment

begin_define
define|#
directive|define
name|SBITMAP_SET_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((N) + SBITMAP_ELT_BITS - 1) / SBITMAP_ELT_BITS)
end_define

begin_comment
comment|/* Set bit number bitno in the bitmap.  */
end_comment

begin_define
define|#
directive|define
name|SET_BIT
parameter_list|(
name|BITMAP
parameter_list|,
name|BITNO
parameter_list|)
define|\
value|((BITMAP)->elms [(BITNO) / SBITMAP_ELT_BITS]			\    |= (SBITMAP_ELT_TYPE) 1<< (BITNO) % SBITMAP_ELT_BITS)
end_define

begin_comment
comment|/* Test if bit number bitno in the bitmap is set.  */
end_comment

begin_define
define|#
directive|define
name|TEST_BIT
parameter_list|(
name|BITMAP
parameter_list|,
name|BITNO
parameter_list|)
define|\
value|((BITMAP)->elms [(BITNO) / SBITMAP_ELT_BITS]>> (BITNO) % SBITMAP_ELT_BITS& 1)
end_define

begin_comment
comment|/* Reset bit number bitno in the bitmap.  */
end_comment

begin_define
define|#
directive|define
name|RESET_BIT
parameter_list|(
name|BITMAP
parameter_list|,
name|BITNO
parameter_list|)
define|\
value|((BITMAP)->elms [(BITNO) / SBITMAP_ELT_BITS]			\&= ~((SBITMAP_ELT_TYPE) 1<< (BITNO) % SBITMAP_ELT_BITS))
end_define

begin_comment
comment|/* Loop over all elements of SBITSET, starting with MIN.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_SET_IN_SBITMAP
parameter_list|(
name|SBITMAP
parameter_list|,
name|MIN
parameter_list|,
name|N
parameter_list|,
name|CODE
parameter_list|)
define|\
value|do {									\   unsigned int word_num_;						\   unsigned int bit_num_ = (MIN) % (unsigned int) SBITMAP_ELT_BITS;	\   unsigned int size_ = (SBITMAP)->size;					\   SBITMAP_ELT_TYPE *ptr_ = (SBITMAP)->elms;				\ 									\   for (word_num_ = (MIN) / (unsigned int) SBITMAP_ELT_BITS;		\        word_num_< size_; word_num_++, bit_num_ = 0)			\     {									\       SBITMAP_ELT_TYPE word_ = ptr_[word_num_];				\ 									\       if (word_ != 0)							\ 	for (; bit_num_< SBITMAP_ELT_BITS; bit_num_++)			\ 	  {								\ 	    SBITMAP_ELT_TYPE _mask = (SBITMAP_ELT_TYPE) 1<< bit_num_;	\ 									\ 	    if ((word_& _mask) != 0)					\ 	      {								\ 		word_&= ~ _mask;					\ 		(N) = word_num_ * SBITMAP_ELT_BITS + bit_num_;		\ 		CODE;							\ 		if (word_ == 0)						\ 		  break;						\ 	      }								\ 	  }								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|EXECUTE_IF_SET_IN_SBITMAP_REV
parameter_list|(
name|SBITMAP
parameter_list|,
name|N
parameter_list|,
name|CODE
parameter_list|)
define|\
value|do {									\   unsigned int word_num_;						\   unsigned int bit_num_;						\   unsigned int size_ = (SBITMAP)->size;					\   SBITMAP_ELT_TYPE *ptr_ = (SBITMAP)->elms;				\ 									\   for (word_num_ = size_; word_num_> 0; word_num_--)			\     {									\       SBITMAP_ELT_TYPE word_ = ptr_[word_num_ - 1];			\ 									\       if (word_ != 0)							\ 	for (bit_num_ = SBITMAP_ELT_BITS; bit_num_> 0; bit_num_--)	\ 	  {								\ 	    SBITMAP_ELT_TYPE _mask = (SBITMAP_ELT_TYPE)1<< (bit_num_ - 1);\ 									\ 	    if ((word_& _mask) != 0)					\ 	      {								\ 		word_&= ~ _mask;					\ 		(N) = (word_num_ - 1) * SBITMAP_ELT_BITS + bit_num_ - 1;\ 		CODE;							\ 		if (word_ == 0)						\ 		  break;						\ 	      }								\ 	  }								\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|sbitmap_free
parameter_list|(
name|MAP
parameter_list|)
value|free(MAP)
end_define

begin_define
define|#
directive|define
name|sbitmap_vector_free
parameter_list|(
name|VEC
parameter_list|)
value|free(VEC)
end_define

begin_struct_decl
struct_decl|struct
name|int_list
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|dump_sbitmap
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_sbitmap_file
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_sbitmap_vector
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sbitmap
name|sbitmap_alloc
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sbitmap
modifier|*
name|sbitmap_vector_alloc
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sbitmap
name|sbitmap_resize
parameter_list|(
name|sbitmap
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_copy
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sbitmap_equal
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_zero
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_ones
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_vector_zero
parameter_list|(
name|sbitmap
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_vector_ones
parameter_list|(
name|sbitmap
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_union_of_diff
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_union_of_diff_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_difference
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_not
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_a_or_b_and_c
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_or_b_and_c_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_a_and_b_or_c
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_and_b_or_c_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_a_and_b
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_and_b_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_a_or_b
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_or_b_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_a_xor_b
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_xor_b_cg
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sbitmap_a_subset_b_p
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sbitmap_first_set_bit
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sbitmap_last_set_bit
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_intersect_of_predsucc
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|int_list
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sbitmap_intersect_of_predecessors
value|sbitmap_intersect_of_predsucc
end_define

begin_define
define|#
directive|define
name|sbitmap_intersect_of_successors
value|sbitmap_intersect_of_predsucc
end_define

begin_function_decl
specifier|extern
name|void
name|sbitmap_union_of_predsucc
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|int_list
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sbitmap_union_of_predecessors
value|sbitmap_union_of_predsucc
end_define

begin_define
define|#
directive|define
name|sbitmap_union_of_successors
value|sbitmap_union_of_predsucc
end_define

begin_comment
comment|/* Intersection and Union of preds/succs using the new flow graph    structure instead of the pred/succ arrays.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|sbitmap_intersection_of_succs
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_intersection_of_preds
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_union_of_succs
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sbitmap_union_of_preds
parameter_list|(
name|sbitmap
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_sbitmap
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_SBITMAP_H */
end_comment

end_unit

