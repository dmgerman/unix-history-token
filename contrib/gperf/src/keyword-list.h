begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Keyword list.     Copyright (C) 2002 Free Software Foundation, Inc.    Written by Bruno Haible<bruno@clisp.org>.     This file is part of GNU GPERF.     GNU GPERF is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU GPERF is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation, Inc.,    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|keyword_list_h
end_ifndef

begin_define
define|#
directive|define
name|keyword_list_h
value|1
end_define

begin_include
include|#
directive|include
file|"keyword.h"
end_include

begin_comment
comment|/* List node of a linear list of Keyword.  */
end_comment

begin_decl_stmt
name|class
name|Keyword_List
block|{
name|public
label|:
comment|/* Constructor.  */
name|Keyword_List
argument_list|(
name|Keyword
operator|*
name|car
argument_list|)
expr_stmt|;
comment|/* Access to first element of list.  */
name|Keyword
operator|*
name|first
argument_list|()
specifier|const
expr_stmt|;
comment|/* Access to next element of list.  */
name|Keyword_List
modifier|*
modifier|&
name|rest
parameter_list|()
function_decl|;
name|protected
label|:
name|Keyword_List
modifier|*
name|_cdr
decl_stmt|;
name|Keyword
modifier|*
specifier|const
name|_car
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* List node of a linear list of KeywordExt.  */
end_comment

begin_decl_stmt
name|class
name|KeywordExt_List
range|:
name|public
name|Keyword_List
block|{
name|public
operator|:
comment|/* Constructor.  */
name|KeywordExt_List
argument_list|(
name|KeywordExt
operator|*
name|car
argument_list|)
block|;
comment|/* Access to first element of list.  */
name|KeywordExt
operator|*
name|first
argument_list|()
specifier|const
block|;
comment|/* Access to next element of list.  */
name|KeywordExt_List
operator|*
operator|&
name|rest
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Copies a linear list, sharing the list elements.  */
end_comment

begin_function_decl
specifier|extern
name|Keyword_List
modifier|*
name|copy_list
parameter_list|(
name|Keyword_List
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeywordExt_List
modifier|*
name|copy_list
parameter_list|(
name|KeywordExt_List
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deletes a linear list, keeping the list elements in memory.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|delete_list
parameter_list|(
name|Keyword_List
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sorts a linear list, given a comparison function.    Note: This uses a variant of mergesort that is *not* a stable sorting    algorithm.  */
end_comment

begin_function_decl
specifier|extern
name|Keyword_List
modifier|*
name|mergesort_list
parameter_list|(
name|Keyword_List
modifier|*
name|list
parameter_list|,
name|bool
function_decl|(
modifier|*
name|less
function_decl|)
parameter_list|(
name|Keyword
modifier|*
name|keyword1
parameter_list|,
name|Keyword
modifier|*
name|keyword2
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeywordExt_List
modifier|*
name|mergesort_list
parameter_list|(
name|KeywordExt_List
modifier|*
name|list
parameter_list|,
name|bool
function_decl|(
modifier|*
name|less
function_decl|)
parameter_list|(
name|KeywordExt
modifier|*
name|keyword1
parameter_list|,
name|KeywordExt
modifier|*
name|keyword2
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

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
file|"keyword-list.icc"
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

