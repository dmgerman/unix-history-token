begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Provides an Iterator for keyword characters.     Copyright (C) 1989-1998 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  */
end_comment

begin_comment
comment|/* Provides an Iterator that expands and decodes a control string containing digits    and ranges, returning an integer every time the generator function is called.    This is used to decode the user's key position requests.  For example:    "-k 1,2,5-10,$"  will return 1, 2, 5, 6, 7, 8, 9, 10, and 0 ( representing    the abstract ``last character of the key'' on successive calls to the    member function operator ().    No errors are handled in these routines, they are passed back to the    calling routines via a user-supplied Error_Value */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|iterator_h
end_ifndef

begin_define
define|#
directive|define
name|iterator_h
value|1
end_define

begin_decl_stmt
name|class
name|Iterator
block|{
name|private
label|:
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
comment|/* A pointer to the string provided by the user. */
name|int
name|end
decl_stmt|;
comment|/* Value returned after last key is processed. */
name|int
name|end_word
decl_stmt|;
comment|/* A value marking the abstract ``end of word'' ( usually '$'). */
name|int
name|error_value
decl_stmt|;
comment|/* Error value returned when input is syntactically erroneous. */
name|int
name|hi_bound
decl_stmt|;
comment|/* Greatest possible value, inclusive. */
name|int
name|lo_bound
decl_stmt|;
comment|/* Smallest possible value, inclusive. */
name|public
label|:
name|Iterator
argument_list|(
argument|const char *s
argument_list|,
argument|int lo
argument_list|,
argument|int hi
argument_list|,
argument|int word_end
argument_list|,
argument|int bad_val
argument_list|,
argument|int key_end
argument_list|)
empty_stmt|;
name|int
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

