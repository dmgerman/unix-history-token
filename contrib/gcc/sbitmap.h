begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Simple bitmaps.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* It's not clear yet whether using bitmap.[ch] will be a win.    It should be straightforward to convert so for now we keep things simple    while more important issues are dealt with.  */
end_comment

begin_define
define|#
directive|define
name|SBITMAP_ELT_BITS
value|HOST_BITS_PER_WIDE_INT
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
comment|/* Number of bits.  */
name|int
name|n_bits
decl_stmt|;
comment|/* Size in elements.  */
name|int
name|size
decl_stmt|;
comment|/* Size in bytes.  */
name|int
name|bytes
decl_stmt|;
comment|/* The elements.  */
name|SBITMAP_ELT_TYPE
name|elms
index|[
literal|1
index|]
decl_stmt|;
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
name|n
parameter_list|)
value|(((n) + SBITMAP_ELT_BITS - 1) / SBITMAP_ELT_BITS)
end_define

begin_comment
comment|/* set bit number bitno in the bitmap */
end_comment

begin_define
define|#
directive|define
name|SET_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]			\    |= (SBITMAP_ELT_TYPE) 1<< (bitno) % SBITMAP_ELT_BITS)
end_define

begin_comment
comment|/* test if bit number bitno in the bitmap is set */
end_comment

begin_define
define|#
directive|define
name|TEST_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]>> (bitno) % SBITMAP_ELT_BITS& 1)
end_define

begin_comment
comment|/* reset bit number bitno in the bitmap  */
end_comment

begin_define
define|#
directive|define
name|RESET_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]			\&= ~((SBITMAP_ELT_TYPE) 1<< (bitno) % SBITMAP_ELT_BITS))
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
value|do {									\   unsigned int bit_num_ = (MIN) % (unsigned) SBITMAP_ELT_BITS;		\   unsigned int word_num_ = (MIN) / (unsigned) SBITMAP_ELT_BITS;		\   unsigned int size_ = (SBITMAP)->size;					\   SBITMAP_ELT_TYPE *ptr_ = (SBITMAP)->elms;				\ 									\   while (word_num_< size_)						\     {									\       SBITMAP_ELT_TYPE word_ = ptr_[word_num_];				\       if (word_ != 0)							\ 	{								\ 	  for (; bit_num_< SBITMAP_ELT_BITS; ++bit_num_)		\ 	    {								\ 	      SBITMAP_ELT_TYPE mask_ = (SBITMAP_ELT_TYPE)1<< bit_num_;	\ 	      if ((word_& mask_) != 0)					\ 		{							\ 		  word_&= ~mask_;					\ 		  (N) = word_num_ * SBITMAP_ELT_BITS + bit_num_;	\ 		  CODE;							\ 		  if (word_ == 0)					\ 		    break;						\ 		}							\ 	    }								\ 	}								\       bit_num_ = 0;							\       word_num_++;							\    }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|sbitmap_free
parameter_list|(
name|map
parameter_list|)
value|free(map)
end_define

begin_define
define|#
directive|define
name|sbitmap_vector_free
parameter_list|(
name|vec
parameter_list|)
value|free(vec)
end_define

begin_decl_stmt
specifier|extern
name|void
name|dump_sbitmap
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_sbitmap_vector
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbitmap
name|sbitmap_alloc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbitmap
modifier|*
name|sbitmap_vector_alloc
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_copy
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_zero
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_ones
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_vector_zero
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_vector_ones
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_union_of_diff
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_difference
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_not
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_or_b_and_c
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_and_b_or_c
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_and_b
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_or_b
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|int_list
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_intersect_of_predsucc
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
expr|struct
name|int_list
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_union_of_predsucc
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
expr|struct
name|int_list
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

end_unit

