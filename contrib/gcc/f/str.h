begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* str.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       str.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STR_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STR_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_define
define|#
directive|define
name|FFESTR_F90
value|0
end_define

begin_comment
comment|/* Unsupported F90 stuff. */
end_comment

begin_define
define|#
directive|define
name|FFESTR_VXT
value|0
end_define

begin_comment
comment|/* Unsupported VXT stuff. */
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
file|"lex.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAKING_DEPENDENCIES
end_ifndef

begin_include
include|#
directive|include
file|"str-1t.h"
end_include

begin_include
include|#
directive|include
file|"str-fo.h"
end_include

begin_include
include|#
directive|include
file|"str-io.h"
end_include

begin_include
include|#
directive|include
file|"str-nq.h"
end_include

begin_include
include|#
directive|include
file|"str-ot.h"
end_include

begin_include
include|#
directive|include
file|"str-op.h"
end_include

begin_include
include|#
directive|include
file|"str-2t.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|ffestrFirst
name|ffestr_first
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrFormat
name|ffestr_format
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrGenio
name|ffestr_genio
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrInquire
name|ffestr_inquire
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrOpen
name|ffestr_open
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrOther
name|ffestr_other
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestrSecond
name|ffestr_second
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestr_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestr_terminate_4
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
comment|/* ! GCC_F_STR_H */
end_comment

end_unit

