begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Functions to support general ended bitmaps.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_BITMAP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_BITMAP_H
end_define

begin_comment
comment|/* Number of words to use for each element in the linked list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BITMAP_ELEMENT_WORDS
end_ifndef

begin_define
define|#
directive|define
name|BITMAP_ELEMENT_WORDS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in each actual element of a bitmap.  We get slightly better    code for bit % BITMAP_ELEMENT_ALL_BITS and bit / BITMAP_ELEMENT_ALL_BITS if    bits is unsigned, assuming it is a power of 2.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_ELEMENT_ALL_BITS
define|\
value|((unsigned) (BITMAP_ELEMENT_WORDS * HOST_BITS_PER_WIDE_INT))
end_define

begin_comment
comment|/* Bitmap set element.  We use a linked list to hold only the bits that    are set.  This allows for use to grow the bitset dynamically without    having to realloc and copy a giant bit array.  The `prev' field is    undefined for an element on the free list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bitmap_element_def
block|{
name|struct
name|bitmap_element_def
modifier|*
name|next
decl_stmt|;
comment|/* Next element.  */
name|struct
name|bitmap_element_def
modifier|*
name|prev
decl_stmt|;
comment|/* Previous element.  */
name|unsigned
name|int
name|indx
decl_stmt|;
comment|/* regno/BITMAP_ELEMENT_ALL_BITS.  */
name|unsigned
name|HOST_WIDE_INT
name|bits
index|[
name|BITMAP_ELEMENT_WORDS
index|]
decl_stmt|;
comment|/* Bits that are set.  */
block|}
name|bitmap_element
typedef|;
end_typedef

begin_comment
comment|/* Head of bitmap linked list.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bitmap_head_def
block|{
name|bitmap_element
modifier|*
name|first
decl_stmt|;
comment|/* First element in linked list.  */
name|bitmap_element
modifier|*
name|current
decl_stmt|;
comment|/* Last element looked at.  */
name|unsigned
name|int
name|indx
decl_stmt|;
comment|/* Index of last element looked at.  */
block|}
name|bitmap_head
operator|,
typedef|*
name|bitmap
typedef|;
end_typedef

begin_comment
comment|/* Enumeration giving the various operations we support.  */
end_comment

begin_enum
enum|enum
name|bitmap_bits
block|{
name|BITMAP_AND
block|,
comment|/* TO = FROM1& FROM2 */
name|BITMAP_AND_COMPL
block|,
comment|/* TO = FROM1& ~ FROM2 */
name|BITMAP_IOR
block|,
comment|/* TO = FROM1 | FROM2 */
name|BITMAP_XOR
block|,
comment|/* TO = FROM1 ^ FROM2 */
name|BITMAP_IOR_COMPL
comment|/* TO = FROM1 | ~FROM2 */
block|}
enum|;
end_enum

begin_comment
comment|/* Global data */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap_element
name|bitmap_zero_bits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero bitmap element */
end_comment

begin_comment
comment|/* Clear a bitmap by freeing up the linked list.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_clear
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copy a bitmap to another bitmap.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_copy
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if two bitmaps are identical.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bitmap_equal_p
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform an operation on two bitmaps, yielding a third.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bitmap_operation
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|bitmap
operator|,
name|bitmap
operator|,
expr|enum
name|bitmap_bits
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* `or' into one bitmap the `and' of a second bitmap witih the complement    of a third.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_ior_and_compl
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|bitmap
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear a single register in a register set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_clear_bit
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set a single register in a register set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_set_bit
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return true if a register is set in a register set.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bitmap_bit_p
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug functions to print a bitmap linked list.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|debug_bitmap
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_bitmap_file
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a bitmap */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_print
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|bitmap
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize a bitmap header.  */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
name|bitmap_initialize
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Release all memory held by bitmaps.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bitmap_release_memory
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A few compatibility/functions macros for compatibility with sbitmaps */
end_comment

begin_define
define|#
directive|define
name|dump_bitmap
parameter_list|(
name|file
parameter_list|,
name|bitmap
parameter_list|)
value|bitmap_print (file, bitmap, "", "\n")
end_define

begin_define
define|#
directive|define
name|bitmap_zero
parameter_list|(
name|a
parameter_list|)
value|bitmap_clear (a)
end_define

begin_define
define|#
directive|define
name|bitmap_a_or_b
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bitmap_operation (a, b, c, BITMAP_IOR)
end_define

begin_define
define|#
directive|define
name|bitmap_a_and_b
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bitmap_operation (a, b, c, BITMAP_AND)
end_define

begin_decl_stmt
specifier|extern
name|int
name|bitmap_union_of_diff
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|,
name|bitmap
operator|,
name|bitmap
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bitmap_first_set_bit
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bitmap_last_set_bit
name|PARAMS
argument_list|(
operator|(
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate a bitmap with oballoc.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_OBSTACK_ALLOC
parameter_list|(
name|OBSTACK
parameter_list|)
define|\
value|bitmap_initialize ((bitmap) obstack_alloc (OBSTACK, sizeof (bitmap_head)))
end_define

begin_comment
comment|/* Allocate a bitmap with alloca.  Note alloca cannot be passed as an    argument to a function, so we set a temporary variable to the value    returned by alloca and pass that variable to bitmap_initialize().    PTR is then set to the value returned from bitmap_initialize() to    avoid having it appear more than once in case it has side effects.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_ALLOCA
parameter_list|(
name|PTR
parameter_list|)
define|\
value|do { \   bitmap temp_bitmap_ = (bitmap) alloca (sizeof (bitmap_head)); \   (PTR) = bitmap_initialize (temp_bitmap_); \ } while (0)
end_define

begin_comment
comment|/* Allocate a bitmap with xmalloc.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_XMALLOC
parameter_list|()
define|\
value|bitmap_initialize ((bitmap) xmalloc (sizeof (bitmap_head)))
end_define

begin_comment
comment|/* Do any cleanup needed on a bitmap when it is no longer used.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_FREE
parameter_list|(
name|BITMAP
parameter_list|)
define|\
value|do {						\   if (BITMAP)					\     {						\       bitmap_clear (BITMAP);			\       (BITMAP) = 0;				\     }						\ } while (0)
end_define

begin_comment
comment|/* Do any cleanup needed on an xmalloced bitmap when it is no longer used.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_XFREE
parameter_list|(
name|BITMAP
parameter_list|)
define|\
value|do {						\   if (BITMAP)					\     {						\       bitmap_clear (BITMAP);			\       free (BITMAP);				\       (BITMAP) = 0;				\     }						\ } while (0)
end_define

begin_comment
comment|/* Do any one-time initializations needed for bitmaps.  */
end_comment

begin_define
define|#
directive|define
name|BITMAP_INIT_ONCE
parameter_list|()
end_define

begin_comment
comment|/* Loop over all bits in BITMAP, starting with MIN, setting BITNUM to the    bit number and executing CODE for all bits that are set.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_SET_IN_BITMAP
parameter_list|(
name|BITMAP
parameter_list|,
name|MIN
parameter_list|,
name|BITNUM
parameter_list|,
name|CODE
parameter_list|)
define|\
value|do {									\   bitmap_element *ptr_ = (BITMAP)->first;				\   unsigned int indx_ = (MIN) / BITMAP_ELEMENT_ALL_BITS;			\   unsigned bit_num_ = (MIN) % ((unsigned) HOST_BITS_PER_WIDE_INT);	\   unsigned word_num_ = (((MIN) / ((unsigned) HOST_BITS_PER_WIDE_INT))	\ 			% BITMAP_ELEMENT_WORDS);			\ 									\ 									\
comment|/* Find the block the minimum bit is in.  */
value|\   while (ptr_ != 0&& ptr_->indx< indx_)				\     ptr_ = ptr_->next;							\ 									\   if (ptr_ != 0&& ptr_->indx != indx_)					\     {									\       bit_num_ = 0;							\       word_num_ = 0;							\     }									\ 									\   for (; ptr_ != 0; ptr_ = ptr_->next)					\     {									\       for (; word_num_< BITMAP_ELEMENT_WORDS; word_num_++)		\ 	{								\ 	  unsigned HOST_WIDE_INT word_ = ptr_->bits[word_num_];		\ 									\ 	  if (word_ != 0)						\ 	    {								\ 	      for (; bit_num_< HOST_BITS_PER_WIDE_INT; bit_num_++)	\ 		{							\ 		  unsigned HOST_WIDE_INT mask_				\ 		    = ((unsigned HOST_WIDE_INT) 1)<< bit_num_;		\ 									\ 		  if ((word_& mask_) != 0)				\ 		    {							\ 		      word_&= ~ mask_;					\ 		      (BITNUM) = (ptr_->indx * BITMAP_ELEMENT_ALL_BITS  \ 				  + word_num_ * HOST_BITS_PER_WIDE_INT  \ 				  + bit_num_);				\ 		      CODE;						\ 									\ 		      if (word_ == 0)					\ 			break;						\ 		    }							\ 		}							\ 	    }								\ 									\ 	  bit_num_ = 0;							\ 	}								\ 									\       word_num_ = 0;							\     }									\ } while (0)
end_define

begin_comment
comment|/* Loop over all bits in BITMAP1 and BITMAP2, starting with MIN, setting    BITNUM to the bit number and executing CODE for all bits that are set in    the first bitmap and not set in the second.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_AND_COMPL_IN_BITMAP
parameter_list|(
name|BITMAP1
parameter_list|,
name|BITMAP2
parameter_list|,
name|MIN
parameter_list|,
name|BITNUM
parameter_list|,
name|CODE
parameter_list|)
define|\
value|do {									\   bitmap_element *ptr1_ = (BITMAP1)->first;				\   bitmap_element *ptr2_ = (BITMAP2)->first;				\   unsigned int indx_ = (MIN) / BITMAP_ELEMENT_ALL_BITS;			\   unsigned bit_num_ = (MIN) % ((unsigned) HOST_BITS_PER_WIDE_INT);	\   unsigned word_num_ = (((MIN) / ((unsigned) HOST_BITS_PER_WIDE_INT))	\ 			% BITMAP_ELEMENT_WORDS);			\ 									\
comment|/* Find the block the minimum bit is in in the first bitmap.  */
value|\   while (ptr1_ != 0&& ptr1_->indx< indx_)				\     ptr1_ = ptr1_->next;						\ 									\   if (ptr1_ != 0&& ptr1_->indx != indx_)				\     {									\       bit_num_ = 0;							\       word_num_ = 0;							\     }									\ 									\   for (; ptr1_ != 0 ; ptr1_ = ptr1_->next)				\     {									\
comment|/* Advance BITMAP2 to the equivalent link, using an all		\ 	 zero element if an equivalent link doesn't exist.  */
value|\       bitmap_element *tmp2_;						\ 									\       while (ptr2_ != 0&& ptr2_->indx< ptr1_->indx)			\ 	ptr2_ = ptr2_->next;						\ 									\       tmp2_ = ((ptr2_ != 0&& ptr2_->indx == ptr1_->indx)		\ 	       ? ptr2_ :&bitmap_zero_bits); 				\ 									\       for (; word_num_< BITMAP_ELEMENT_WORDS; word_num_++)		\ 	{								\ 	  unsigned HOST_WIDE_INT word_ = (ptr1_->bits[word_num_]	\& ~ tmp2_->bits[word_num_]);	\ 	  if (word_ != 0)						\ 	    {								\ 	      for (; bit_num_< HOST_BITS_PER_WIDE_INT; bit_num_++)	\ 		{							\ 		  unsigned HOST_WIDE_INT mask_				\ 		    = ((unsigned HOST_WIDE_INT)1)<< bit_num_;		\ 									\ 		  if ((word_& mask_) != 0)				\ 		    {							\ 		      word_&= ~ mask_;					\ 		      (BITNUM) = (ptr1_->indx * BITMAP_ELEMENT_ALL_BITS \ 				  + word_num_ * HOST_BITS_PER_WIDE_INT  \ 				  + bit_num_);				\ 									\ 		      CODE;						\ 		      if (word_ == 0)					\ 			break;						\ 		    }							\ 		}							\ 	    }								\ 									\ 	  bit_num_ = 0;							\ 	}								\ 									\       word_num_ = 0;							\     }									\ } while (0)
end_define

begin_comment
comment|/* Loop over all bits in BITMAP1 and BITMAP2, starting with MIN, setting    BITNUM to the bit number and executing CODE for all bits that are set in    the both bitmaps.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_AND_IN_BITMAP
parameter_list|(
name|BITMAP1
parameter_list|,
name|BITMAP2
parameter_list|,
name|MIN
parameter_list|,
name|BITNUM
parameter_list|,
name|CODE
parameter_list|)
define|\
value|do {									\   bitmap_element *ptr1_ = (BITMAP1)->first;				\   bitmap_element *ptr2_ = (BITMAP2)->first;				\   unsigned int indx_ = (MIN) / BITMAP_ELEMENT_ALL_BITS;			\   unsigned bit_num_ = (MIN) % ((unsigned) HOST_BITS_PER_WIDE_INT);	\   unsigned word_num_ = (((MIN) / ((unsigned) HOST_BITS_PER_WIDE_INT))	\ 			% BITMAP_ELEMENT_WORDS);			\ 									\
comment|/* Find the block the minimum bit is in in the first bitmap.  */
value|\   while (ptr1_ != 0&& ptr1_->indx< indx_)				\     ptr1_ = ptr1_->next;						\ 									\   if (ptr1_ != 0&& ptr1_->indx != indx_)				\     {									\       bit_num_ = 0;							\       word_num_ = 0;							\     }									\ 									\   for (; ptr1_ != 0 ; ptr1_ = ptr1_->next)				\     {									\
comment|/* Advance BITMAP2 to the equivalent link */
value|\       while (ptr2_ != 0&& ptr2_->indx< ptr1_->indx)			\ 	ptr2_ = ptr2_->next;						\ 									\       if (ptr2_ == 0)							\ 	{								\
comment|/* If there are no more elements in BITMAP2, exit loop now.  */
value|\ 	  ptr1_ = (bitmap_element *)0;					\ 	  break;							\ 	}								\       else if (ptr2_->indx> ptr1_->indx)				\ 	{								\ 	  bit_num_ = word_num_ = 0;					\ 	  continue;							\ 	}								\ 									\       for (; word_num_< BITMAP_ELEMENT_WORDS; word_num_++)		\ 	{								\ 	  unsigned HOST_WIDE_INT word_ = (ptr1_->bits[word_num_]	\& ptr2_->bits[word_num_]);	\ 	  if (word_ != 0)						\ 	    {								\ 	      for (; bit_num_< HOST_BITS_PER_WIDE_INT; bit_num_++)	\ 		{							\ 		  unsigned HOST_WIDE_INT mask_				\ 		    = ((unsigned HOST_WIDE_INT)1)<< bit_num_;		\ 									\ 		  if ((word_& mask_) != 0)				\ 		    {							\ 		      word_&= ~ mask_;					\ 		      (BITNUM) = (ptr1_->indx * BITMAP_ELEMENT_ALL_BITS \ 				  + word_num_ * HOST_BITS_PER_WIDE_INT  \ 				  + bit_num_);				\ 									\ 		      CODE;						\ 		      if (word_ == 0)					\ 			break;						\ 		    }							\ 		}							\ 	    }								\ 									\ 	  bit_num_ = 0;							\ 	}								\ 									\       word_num_ = 0;							\     }									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_BITMAP_H */
end_comment

end_unit

