begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stt.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       stt.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STT_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffest_case_list_
modifier|*
name|ffesttCaseList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_dim_list_
modifier|*
name|ffesttDimList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_expr_list_
modifier|*
name|ffesttExprList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_format_value_
name|ffesttFormatValue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_format_list_
modifier|*
name|ffesttFormatList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_imp_list_
modifier|*
name|ffesttImpList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_token_item_
modifier|*
name|ffesttTokenItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffest_token_list_
modifier|*
name|ffesttTokenList
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"stp.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffest_case_list_
block|{
name|ffesttCaseList
name|next
decl_stmt|;
name|ffesttCaseList
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
name|ffebld
name|expr1
decl_stmt|;
name|ffebld
name|expr2
decl_stmt|;
name|bool
name|range
decl_stmt|;
comment|/* TRUE if "[expr1]:[expr2]", FALSE if 				   "expr1". */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_dim_list_
block|{
name|ffesttDimList
name|next
decl_stmt|;
name|ffesttDimList
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
name|ffebld
name|lower
decl_stmt|;
name|ffebld
name|upper
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_expr_list_
block|{
name|ffesttExprList
name|next
decl_stmt|;
name|ffesttExprList
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
name|ffebld
name|expr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_token_item_
block|{
name|ffesttTokenItem
name|next
decl_stmt|;
name|ffesttTokenItem
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_token_list_
block|{
name|ffesttTokenItem
name|first
decl_stmt|;
name|ffesttTokenItem
name|last
decl_stmt|;
name|int
name|count
decl_stmt|;
comment|/* Number of tokens in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_format_value_
block|{
name|bool
name|present
decl_stmt|;
comment|/* TRUE if value supplied (needed for 				   optional values only). */
name|bool
name|rtexpr
decl_stmt|;
comment|/* FALSE if constant value here, TRUE if 				   run-time expr (VXT). */
name|ffelexToken
name|t
decl_stmt|;
comment|/* The first token, or perhaps just prior if 				   can't get it. */
union|union
block|{
name|ffeUnionLongPtr
name|unused
decl_stmt|;
comment|/* Make sure all the info gets copied. */
name|long
name|signed_val
decl_stmt|;
comment|/* for R1011. */
name|unsigned
name|long
name|unsigned_val
decl_stmt|;
comment|/* For other constant values. */
name|ffebld
name|expr
decl_stmt|;
comment|/* For run-time expression (VXT). */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffest_format_list_
block|{
name|ffesttFormatList
name|next
decl_stmt|;
name|ffesttFormatList
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
comment|/* The NAME, CHARACTER, or HOLLERITH token. */
name|ffestpFormatType
name|type
decl_stmt|;
union|union
name|ffest_format_
block|{
struct|struct
block|{
name|ffesttFormatValue
name|R1004
decl_stmt|;
comment|/* r, the repeat count. */
name|ffesttFormatValue
name|R1006
decl_stmt|;
comment|/* w, the field width. */
name|ffesttFormatValue
name|R1007_or_R1008
decl_stmt|;
comment|/* m, the minimum number of 						   digits; d, the number of 						   decimal digits. */
name|ffesttFormatValue
name|R1009
decl_stmt|;
comment|/* e, the number of exponent digits. */
block|}
name|R1005
struct|;
comment|/* data-edit-desc. */
struct|struct
block|{
name|ffesttFormatValue
name|val
decl_stmt|;
comment|/* r, the repeat count; k, the 					   precision magnitude adjustment; n, 					   the column number (abs or rel). */
block|}
name|R1010
struct|;
comment|/* control-edit-desc. */
struct|struct
block|{
name|ffesttFormatValue
name|R1004
decl_stmt|;
comment|/* r, the repeat count. */
name|ffesttFormatList
name|format
decl_stmt|;
comment|/* the parenthesized 					   format-item-list. */
block|}
name|R1003D
struct|;
comment|/* format-item of for [r](format-item-list). */
struct|struct
block|{
name|ffesttFormatList
name|parent
decl_stmt|;
comment|/* NULL if outer list, else parent 					   item. */
block|}
name|root
struct|;
comment|/* FFESTP_formattypeNone case. */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffestt_caselist_append
parameter_list|(
name|ffesttCaseList
name|list
parameter_list|,
name|bool
name|range
parameter_list|,
name|ffebld
name|case1
parameter_list|,
name|ffebld
name|case2
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttCaseList
name|ffestt_caselist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_caselist_kill
parameter_list|(
name|ffesttCaseList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_dimlist_append
parameter_list|(
name|ffesttDimList
name|list
parameter_list|,
name|ffebld
name|lower
parameter_list|,
name|ffebld
name|upper
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffestt_dimlist_as_expr
parameter_list|(
name|ffesttDimList
name|list
parameter_list|,
name|ffeinfoRank
modifier|*
name|rank
parameter_list|,
name|ffebld
modifier|*
name|array_size
parameter_list|,
name|ffebld
modifier|*
name|extents
parameter_list|,
name|bool
name|is_ugly_assumed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttDimList
name|ffestt_dimlist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_dimlist_kill
parameter_list|(
name|ffesttDimList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestpDimtype
name|ffestt_dimlist_type
parameter_list|(
name|ffesttDimList
name|dims
parameter_list|,
name|bool
name|is_ugly_assumed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_exprlist_append
parameter_list|(
name|ffesttExprList
name|list
parameter_list|,
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttExprList
name|ffestt_exprlist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_exprlist_drive
parameter_list|(
name|ffesttExprList
name|list
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffebld
parameter_list|,
name|ffelexToken
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_exprlist_kill
parameter_list|(
name|ffesttExprList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttFormatList
name|ffestt_formatlist_append
parameter_list|(
name|ffesttFormatList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttFormatList
name|ffestt_formatlist_create
parameter_list|(
name|ffesttFormatList
name|parent
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_formatlist_kill
parameter_list|(
name|ffesttFormatList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_implist_append
parameter_list|(
name|ffesttImpList
name|list
parameter_list|,
name|ffelexToken
name|first
parameter_list|,
name|ffelexToken
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttImpList
name|ffestt_implist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_implist_drive
parameter_list|(
name|ffesttImpList
name|list
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffelexToken
parameter_list|,
name|ffelexToken
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_implist_kill
parameter_list|(
name|ffesttImpList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_tokenlist_append
parameter_list|(
name|ffesttTokenList
name|list
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesttTokenList
name|ffestt_tokenlist_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_tokenlist_drive
parameter_list|(
name|ffesttTokenList
name|list
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffelexToken
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestt_tokenlist_handle
parameter_list|(
name|ffesttTokenList
name|list
parameter_list|,
name|ffelexHandler
name|handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestt_tokenlist_kill
parameter_list|(
name|ffesttTokenList
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestt_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestt_tokenlist_count
parameter_list|(
name|tl
parameter_list|)
value|((tl)->count)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_STT_H */
end_comment

end_unit

