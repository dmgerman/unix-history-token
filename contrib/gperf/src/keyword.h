begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Keyword data.     Copyright (C) 1989-1998, 2000, 2002 Free Software Foundation, Inc.    Written by Douglas C. Schmidt<schmidt@ics.uci.edu>    and Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|keyword_h
end_ifndef

begin_define
define|#
directive|define
name|keyword_h
value|1
end_define

begin_comment
comment|/* Class defined in "positions.h".  */
end_comment

begin_decl_stmt
name|class
name|Positions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An instance of this class is a keyword, as specified in the input file.  */
end_comment

begin_struct
struct|struct
name|Keyword
block|{
comment|/* Constructor.  */
name|Keyword
argument_list|(
argument|const char *allchars
argument_list|,
argument|int allchars_length
argument_list|,
argument|const char *rest
argument_list|)
empty_stmt|;
comment|/* Data members defined immediately by the input file.  */
comment|/* The keyword as a string, possibly containing NUL bytes.  */
specifier|const
name|char
modifier|*
specifier|const
name|_allchars
decl_stmt|;
name|int
specifier|const
name|_allchars_length
decl_stmt|;
comment|/* Additional stuff seen on the same line of the input file.  */
specifier|const
name|char
modifier|*
specifier|const
name|_rest
decl_stmt|;
comment|/* Line number of this keyword in the input file.  */
name|unsigned
name|int
name|_lineno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A keyword, in the context of a given keyposition list.  */
end_comment

begin_decl_stmt
name|struct
name|KeywordExt
range|:
name|public
name|Keyword
block|{
comment|/* Constructor.  */
name|KeywordExt
argument_list|(
argument|const char *allchars
argument_list|,
argument|int allchars_length
argument_list|,
argument|const char *rest
argument_list|)
block|;
comment|/* Data members depending on the keyposition list.  */
comment|/* The selected characters that participate for the hash function,      selected according to the keyposition list, as a canonically reordered      multiset.  */
specifier|const
name|unsigned
name|int
operator|*
name|_selchars
block|;
name|int
name|_selchars_length
block|;
comment|/* Chained list of keywords having the same _selchars and      - if !option[NOLENGTH] - also the same _allchars_length.      Note that these duplicates are not members of the main keyword list.  */
name|KeywordExt
operator|*
name|_duplicate_link
block|;
comment|/* Methods depending on the keyposition list.  */
comment|/* Initializes selchars and selchars_length, without reordering.  */
name|void
name|init_selchars_tuple
argument_list|(
argument|const Positions& positions
argument_list|,
argument|const unsigned int *alpha_unify
argument_list|)
block|;
comment|/* Initializes selchars and selchars_length, with reordering.  */
name|void
name|init_selchars_multiset
argument_list|(
argument|const Positions& positions
argument_list|,
argument|const unsigned int *alpha_unify
argument_list|,
argument|const unsigned int *alpha_inc
argument_list|)
block|;
comment|/* Deletes selchars.  */
name|void
name|delete_selchars
argument_list|()
block|;
comment|/* Data members used by the algorithm.  */
name|int
name|_hash_value
block|;
comment|/* Hash value for the keyword.  */
comment|/* Data members used by the output routines.  */
name|int
name|_final_index
block|;
name|private
operator|:
name|unsigned
name|int
operator|*
name|init_selchars_low
argument_list|(
argument|const Positions& positions
argument_list|,
argument|const unsigned int *alpha_unify
argument_list|,
argument|const unsigned int *alpha_inc
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An abstract factory for creating Keyword instances.    This factory is used to make the Input class independent of the concrete    class KeywordExt.  */
end_comment

begin_decl_stmt
name|class
name|Keyword_Factory
block|{
name|public
label|:
comment|/* Constructor.  */
name|Keyword_Factory
argument_list|()
expr_stmt|;
comment|/* Destructor.  */
name|virtual
operator|~
name|Keyword_Factory
argument_list|()
expr_stmt|;
comment|/* Creates a new Keyword.  */
name|virtual
comment|/*abstract*/
name|Keyword
modifier|*
name|create_keyword
parameter_list|(
specifier|const
name|char
modifier|*
name|allchars
parameter_list|,
name|int
name|allchars_length
parameter_list|,
specifier|const
name|char
modifier|*
name|rest
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A statically allocated empty string.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|empty_string
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_include
include|#
directive|include
file|"keyword.icc"
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

