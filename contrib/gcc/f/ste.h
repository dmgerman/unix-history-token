begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ste.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       ste.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STE_H
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
file|"sts.h"
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
name|ffeste_do
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_end_R807
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_labeldef_branch
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_labeldef_format
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R737A
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
name|ffeste_R803
parameter_list|(
name|ffestw
name|block
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R804
parameter_list|(
name|ffestw
name|block
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R805
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R806
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R807
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R809
parameter_list|(
name|ffestw
name|block
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R810
parameter_list|(
name|ffestw
name|block
parameter_list|,
name|unsigned
name|long
name|casenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R811
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R819A
parameter_list|(
name|ffestw
name|block
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
name|ffeste_R819B
parameter_list|(
name|ffestw
name|block
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
name|ffeste_R825
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R834
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R835
parameter_list|(
name|ffestw
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R836
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R837
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
name|ffeste_R838
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
name|ffeste_R839
parameter_list|(
name|ffebld
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R840
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
name|ffeste_R841
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R842
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R843
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R904
parameter_list|(
name|ffestpOpenStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R907
parameter_list|(
name|ffestpCloseStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R909_start
parameter_list|(
name|ffestpReadStmt
modifier|*
name|info
parameter_list|,
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
name|ffeste_R909_item
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
name|ffeste_R909_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R910_start
parameter_list|(
name|ffestpWriteStmt
modifier|*
name|info
parameter_list|,
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
name|ffeste_R910_item
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
name|ffeste_R910_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R911_start
parameter_list|(
name|ffestpPrintStmt
modifier|*
name|info
parameter_list|,
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R911_item
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
name|ffeste_R911_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R919
parameter_list|(
name|ffestpBeruStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R920
parameter_list|(
name|ffestpBeruStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R921
parameter_list|(
name|ffestpBeruStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R923A
parameter_list|(
name|ffestpInquireStmt
modifier|*
name|info
parameter_list|,
name|bool
name|by_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R923B_start
parameter_list|(
name|ffestpInquireStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R923B_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R923B_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1001
parameter_list|(
name|ffests
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1103
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1112
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1212
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1221
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1225
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1226
parameter_list|(
name|ffesymbol
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_R1227
parameter_list|(
name|ffestw
name|block
parameter_list|,
name|ffebld
name|expr
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
name|ffeste_V018_start
parameter_list|(
name|ffestpRewriteStmt
modifier|*
name|info
parameter_list|,
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V018_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V018_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V019_start
parameter_list|(
name|ffestpAcceptStmt
modifier|*
name|info
parameter_list|,
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V019_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V019_finish
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
name|ffeste_V020_start
parameter_list|(
name|ffestpTypeStmt
modifier|*
name|info
parameter_list|,
name|ffestvFormat
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V020_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V020_finish
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
name|ffeste_V021
parameter_list|(
name|ffestpDeleteStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V022
parameter_list|(
name|ffestpBeruStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V023_start
parameter_list|(
name|ffestpVxtcodeStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V023_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V023_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V024_start
parameter_list|(
name|ffestpVxtcodeStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V024_item
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V024_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V025_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V025_item
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
name|ffeste_V025_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeste_V026
parameter_list|(
name|ffestpFindStmt
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffeste_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_filename
parameter_list|()
value|input_filename
end_define

begin_define
define|#
directive|define
name|ffeste_filelinenum
parameter_list|()
value|lineno
end_define

begin_define
define|#
directive|define
name|ffeste_set_line
parameter_list|(
name|name
parameter_list|,
name|num
parameter_list|)
define|\
value|(input_filename = (name), lineno = (num))
end_define

begin_define
define|#
directive|define
name|ffeste_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_terminate_1
parameter_list|()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_function_decl
name|void
name|ffeste_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ffeste_terminate_2
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffeste_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeste_terminate_4
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
comment|/* ! GCC_F_STE_H */
end_comment

end_unit

