begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Simple lookup table abstraction implemented as an Iteration Number Array.     Copyright (C) 1989-1998, 2002 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bool_array_h
end_ifndef

begin_define
define|#
directive|define
name|bool_array_h
value|1
end_define

begin_comment
comment|/* A Bool_Array instance is a bit array of fixed size, optimized for being    filled sparsely and cleared frequently.  For example, when processing    tests/chill.gperf, the array will be:      - of size 15391,      - clear will be called 3509 times,      - set_bit will be called 300394 times.    With a conventional bit array implementation, clear would be too slow.    With a tree/hash based bit array implementation, set_bit would be slower. */
end_comment

begin_decl_stmt
name|class
name|Bool_Array
block|{
name|public
label|:
comment|/* Initializes the bit array with room for SIZE bits, numbered from      0 to SIZE-1. */
name|Bool_Array
argument_list|(
argument|unsigned int size
argument_list|)
empty_stmt|;
comment|/* Frees this object.  */
operator|~
name|Bool_Array
argument_list|()
expr_stmt|;
comment|/* Resets all bits to zero.  */
name|void
name|clear
parameter_list|()
function_decl|;
comment|/* Sets the specified bit to true.      Returns its previous value (false or true).  */
name|bool
name|set_bit
parameter_list|(
name|unsigned
name|int
name|index
parameter_list|)
function_decl|;
name|private
label|:
comment|/* Size of array.  */
name|unsigned
name|int
specifier|const
name|_size
decl_stmt|;
comment|/* Current iteration number.  Always nonzero.  Starts out as 1, and is      incremented each time clear() is called.  */
name|unsigned
name|int
name|_iteration_number
decl_stmt|;
comment|/* For each index, we store in storage_array[index] the iteration_number at      the time set_bit(index) was last called.  */
name|unsigned
name|int
modifier|*
specifier|const
name|_storage_array
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_comment
comment|/* efficiency hack! */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_include
include|#
directive|include
file|"bool-array.icc"
end_include

begin_undef
undef|#
directive|undef
name|INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

