begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* std.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       std.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STD_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STD_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
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

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"stt.h"
end_include

begin_include
include|#
directive|include
file|"stv.h"
end_include

begin_include
include|#
directive|include
file|"stw.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffestd_begin_uses
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_do
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_end_uses
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_end_R740
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_end_R807
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_exec_begin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_exec_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_init_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_labeldef_any
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_labeldef_branch
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_labeldef_format
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_labeldef_useless
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R423A
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R423B
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R424
parameter_list|(
name|ffelexToken
name|access
parameter_list|,
name|ffestrOther
name|access_kw
parameter_list|,
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R425
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R519_start
parameter_list|(
name|ffestrOther
name|intent_kw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R519_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R519_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R520_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R520_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R520_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521A
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Astart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Aitem
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Afinish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521B
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Bstart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Bitem
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R521Bfinish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R522
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R522start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R522item_object
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R522item_cblock
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R522finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R524_start
parameter_list|(
name|bool
name|virtual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R524_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R524_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R525_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R525_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R525_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R526_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R526_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R526_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R527_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R527_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R527_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R537_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R537_item
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R537_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R539
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R539start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R539item
parameter_list|(
name|ffestpType
name|type
parameter_list|,
name|ffebld
name|kind
parameter_list|,
name|ffelexToken
name|kindt
parameter_list|,
name|ffebld
name|len
parameter_list|,
name|ffelexToken
name|lent
parameter_list|,
name|ffesttImpList
name|letters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R539finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R542_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R542_item_nlist
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R542_item_nitem
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R542_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R544_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R544_item
parameter_list|(
name|ffesttExprList
name|exprlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R544_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R547_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R547_item_object
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R547_item_cblock
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R547_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R620
parameter_list|(
name|ffesttExprList
name|exprlist
parameter_list|,
name|ffebld
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R624
parameter_list|(
name|ffesttExprList
name|pointers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R625
parameter_list|(
name|ffesttExprList
name|exprlist
parameter_list|,
name|ffebld
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R737A
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R737B
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R738
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R740
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R742
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R744
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R745
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R803
parameter_list|(
name|ffelexToken
name|construct_name
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R804
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R805
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R806
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R807
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R809
parameter_list|(
name|ffelexToken
name|construct_name
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R810
parameter_list|(
name|unsigned
name|long
name|casenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R811
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R819A
parameter_list|(
name|ffelexToken
name|construct_name
parameter_list|,
name|ffelab
name|label
parameter_list|,
name|ffebld
name|var
parameter_list|,
name|ffebld
name|start
parameter_list|,
name|ffelexToken
name|start_token
parameter_list|,
name|ffebld
name|end
parameter_list|,
name|ffelexToken
name|end_token
parameter_list|,
name|ffebld
name|incr
parameter_list|,
name|ffelexToken
name|incr_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R819B
parameter_list|(
name|ffelexToken
name|construct_name
parameter_list|,
name|ffelab
name|label
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R825
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R834
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R835
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R836
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R837
parameter_list|(
name|ffelab
modifier|*
name|labels
parameter_list|,
name|int
name|count
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R838
parameter_list|(
name|ffelab
name|label
parameter_list|,
name|ffebld
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R839
parameter_list|(
name|ffebld
name|target
parameter_list|,
name|ffelab
modifier|*
name|labels
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R840
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelab
name|neg
parameter_list|,
name|ffelab
name|zero
parameter_list|,
name|ffelab
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R841
parameter_list|(
name|bool
name|in_where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R842
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R843
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R904
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R907
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R909_start
parameter_list|(
name|bool
name|only_format
parameter_list|,
name|ffestvUnit
name|unit
parameter_list|,
name|ffestvFormat
name|format
parameter_list|,
name|bool
name|rec
parameter_list|,
name|bool
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R909_item
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|expr_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R909_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R910_start
parameter_list|(
name|ffestvUnit
name|unit
parameter_list|,
name|ffestvFormat
name|format
parameter_list|,
name|bool
name|rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R910_item
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|expr_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R910_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R911_start
parameter_list|(
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R911_item
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|expr_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R911_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R919
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R920
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R921
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R923A
parameter_list|(
name|bool
name|by_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R923B_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R923B_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R923B_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1001
parameter_list|(
name|ffesttFormatList
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1102
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1103
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R1105
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1106
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1107_start
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|bool
name|only
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1107_item
parameter_list|(
name|ffelexToken
name|local
parameter_list|,
name|ffelexToken
name|use
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1107_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R1111
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1112
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R1202
parameter_list|(
name|ffestpDefinedOperator
name|operator
parameter_list|,
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1203
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1205_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1205_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1205_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R1207_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1207_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1207_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1208_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1208_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1208_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1212
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R1213
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R1219
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|funcname
parameter_list|,
name|ffesttTokenList
name|args
parameter_list|,
name|ffestpType
name|type
parameter_list|,
name|ffebld
name|kind
parameter_list|,
name|ffelexToken
name|kindt
parameter_list|,
name|ffebld
name|len
parameter_list|,
name|ffelexToken
name|lent
parameter_list|,
name|bool
name|recursive
parameter_list|,
name|ffelexToken
name|result
parameter_list|,
name|bool
name|separate_result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1221
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1223
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|subrname
parameter_list|,
name|ffesttTokenList
name|args
parameter_list|,
name|ffelexToken
name|final
parameter_list|,
name|bool
name|recursive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1225
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1226
parameter_list|(
name|ffesymbol
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1227
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|void
name|ffestd_R1228
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_R1229_start
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttTokenList
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_R1229_finish
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_S3P4
parameter_list|(
name|ffebld
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|void
name|ffestd_V003_start
parameter_list|(
name|ffelexToken
name|structure_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V003_item
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V003_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V004
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V009
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V010
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V012
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V013
parameter_list|(
name|bool
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_V014_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V014_item_object
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V014_item_cblock
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V014_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|void
name|ffestd_V016_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V016_item_structure
parameter_list|(
name|ffelexToken
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V016_item_object
parameter_list|(
name|ffelexToken
name|name
parameter_list|,
name|ffesttDimList
name|dims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V016_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V018_start
parameter_list|(
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V018_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V018_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V019_start
parameter_list|(
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V019_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V019_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_V020_start
parameter_list|(
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V020_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V020_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|void
name|ffestd_V021
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V022
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V023_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V023_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V023_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V024_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V024_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V024_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V025_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V025_item
parameter_list|(
name|ffebld
name|u
parameter_list|,
name|ffebld
name|m
parameter_list|,
name|ffebld
name|n
parameter_list|,
name|ffebld
name|asv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V025_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V026
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffestd_V027_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V027_item
parameter_list|(
name|ffelexToken
name|dest_token
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_V027_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestd_any
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestd_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_labeldef_notloop
parameter_list|(
name|l
parameter_list|)
value|ffestd_labeldef_branch(l)
end_define

begin_define
define|#
directive|define
name|ffestd_labeldef_endif
parameter_list|(
name|l
parameter_list|)
value|ffestd_labeldef_branch(l)
end_define

begin_define
define|#
directive|define
name|ffestd_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestd_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_STD_H */
end_comment

end_unit

