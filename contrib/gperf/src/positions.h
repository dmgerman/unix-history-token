begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* A set of byte positions.     Copyright (C) 1989-1998, 2000, 2002, 2005 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|positions_h
end_ifndef

begin_define
define|#
directive|define
name|positions_h
value|1
end_define

begin_comment
comment|/* Classes defined below.  */
end_comment

begin_decl_stmt
name|class
name|PositionIterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PositionReverseIterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This class denotes a set of byte positions, used to access a keyword.  */
end_comment

begin_decl_stmt
name|class
name|Positions
block|{
name|friend
name|class
name|PositionIterator
decl_stmt|;
name|friend
name|class
name|PositionReverseIterator
decl_stmt|;
name|public
label|:
comment|/* Denotes the last char of a keyword, depending on the keyword's length.  */
enum|enum
block|{
name|LASTCHAR
init|=
operator|-
literal|1
block|}
enum|;
comment|/* Maximum key position specifiable by the user, 1-based.      Note that MAX_KEY_POS-1 must fit into the element type of _positions[],      below.  */
enum|enum
block|{
name|MAX_KEY_POS
init|=
literal|255
block|}
enum|;
comment|/* Maximum possible size.  Since duplicates are eliminated and the possible      0-based positions are -1 .. MAX_KEY_POS-1, this is:  */
enum|enum
block|{
name|MAX_SIZE
init|=
name|MAX_KEY_POS
operator|+
literal|1
block|}
enum|;
comment|/* Constructors.  */
name|Positions
argument_list|()
expr_stmt|;
name|Positions
argument_list|(
argument|int pos1
argument_list|)
empty_stmt|;
name|Positions
argument_list|(
argument|int pos1
argument_list|,
argument|int pos2
argument_list|)
empty_stmt|;
comment|/* Copy constructor.  */
name|Positions
argument_list|(
specifier|const
name|Positions
operator|&
name|src
argument_list|)
expr_stmt|;
comment|/* Assignment operator.  */
name|Positions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Positions
operator|&
name|src
operator|)
decl_stmt|;
comment|/* Accessors.  */
name|bool
name|is_useall
argument_list|()
specifier|const
expr_stmt|;
name|int
name|operator
index|[]
argument_list|(
name|unsigned
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|int
name|get_size
argument_list|()
specifier|const
expr_stmt|;
comment|/* Write access.  */
name|void
name|set_useall
parameter_list|(
name|bool
name|useall
parameter_list|)
function_decl|;
name|int
modifier|*
name|pointer
parameter_list|()
function_decl|;
name|void
name|set_size
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
comment|/* Sorts the array in reverse order.      Returns true if there are no duplicates, false otherwise.  */
name|bool
name|sort
parameter_list|()
function_decl|;
comment|/* Creates an iterator, returning the positions in descending order.  */
name|PositionIterator
name|iterator
argument_list|()
specifier|const
expr_stmt|;
comment|/* Creates an iterator, returning the positions in descending order,      that apply to strings of length<= maxlen.  */
name|PositionIterator
name|iterator
argument_list|(
name|int
name|maxlen
argument_list|)
decl|const
decl_stmt|;
comment|/* Creates an iterator, returning the positions in ascending order.  */
name|PositionReverseIterator
name|reviterator
argument_list|()
specifier|const
expr_stmt|;
comment|/* Creates an iterator, returning the positions in ascending order,      that apply to strings of length<= maxlen.  */
name|PositionReverseIterator
name|reviterator
argument_list|(
name|int
name|maxlen
argument_list|)
decl|const
decl_stmt|;
comment|/* Set operations.  Assumes the array is in reverse order.  */
name|bool
name|contains
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|void
name|add
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
comment|/* Output in external syntax.  */
name|void
name|print
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/* The special case denoted by '*'.  */
name|bool
name|_useall
decl_stmt|;
comment|/* Number of positions.  */
name|unsigned
name|int
name|_size
decl_stmt|;
comment|/* Array of positions.  0 for the first char, 1 for the second char etc.,      LASTCHAR for the last char.  */
name|int
name|_positions
index|[
name|MAX_SIZE
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* This class denotes an iterator through a set of byte positions.  */
end_comment

begin_decl_stmt
name|class
name|PositionIterator
block|{
name|friend
name|class
name|Positions
decl_stmt|;
name|public
label|:
comment|/* Copy constructor.  */
name|PositionIterator
argument_list|(
specifier|const
name|PositionIterator
operator|&
name|src
argument_list|)
expr_stmt|;
comment|/* End of iteration marker.  */
enum|enum
block|{
name|EOS
init|=
operator|-
literal|2
block|}
enum|;
comment|/* Retrieves the next position, or EOS past the end.  */
name|int
name|next
parameter_list|()
function_decl|;
comment|/* Returns the number of remaining positions, i.e. how often next() will      return a value != EOS.  */
name|unsigned
name|int
name|remaining
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/* Initializes an iterator through POSITIONS.  */
name|PositionIterator
argument_list|(
name|Positions
specifier|const
operator|&
name|positions
argument_list|)
expr_stmt|;
comment|/* Initializes an iterator through POSITIONS, ignoring positions>= maxlen.  */
name|PositionIterator
argument_list|(
argument|Positions const& positions
argument_list|,
argument|int maxlen
argument_list|)
empty_stmt|;
specifier|const
name|Positions
modifier|&
name|_set
decl_stmt|;
name|unsigned
name|int
name|_index
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* This class denotes an iterator in reverse direction through a set of    byte positions.  */
end_comment

begin_decl_stmt
name|class
name|PositionReverseIterator
block|{
name|friend
name|class
name|Positions
decl_stmt|;
name|public
label|:
comment|/* Copy constructor.  */
name|PositionReverseIterator
argument_list|(
specifier|const
name|PositionReverseIterator
operator|&
name|src
argument_list|)
expr_stmt|;
comment|/* End of iteration marker.  */
enum|enum
block|{
name|EOS
init|=
operator|-
literal|2
block|}
enum|;
comment|/* Retrieves the next position, or EOS past the end.  */
name|int
name|next
parameter_list|()
function_decl|;
comment|/* Returns the number of remaining positions, i.e. how often next() will      return a value != EOS.  */
name|unsigned
name|int
name|remaining
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/* Initializes an iterator through POSITIONS.  */
name|PositionReverseIterator
argument_list|(
name|Positions
specifier|const
operator|&
name|positions
argument_list|)
expr_stmt|;
comment|/* Initializes an iterator through POSITIONS, ignoring positions>= maxlen.  */
name|PositionReverseIterator
argument_list|(
argument|Positions const& positions
argument_list|,
argument|int maxlen
argument_list|)
empty_stmt|;
specifier|const
name|Positions
modifier|&
name|_set
decl_stmt|;
name|unsigned
name|int
name|_index
decl_stmt|;
name|unsigned
name|int
name|_minindex
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

begin_include
include|#
directive|include
file|<string.h>
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
file|"positions.icc"
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

