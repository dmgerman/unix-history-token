begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* name.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       name.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_NAME_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_NAME_H
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
name|_ffename_
modifier|*
name|ffename
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffename_space_
modifier|*
name|ffenameSpace
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffename_
block|{
name|ffename
name|next
decl_stmt|;
name|ffename
name|previous
decl_stmt|;
name|ffelexToken
name|t
decl_stmt|;
union|union
block|{
name|ffesymbol
name|s
decl_stmt|;
name|ffeglobal
name|g
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffename_space_
block|{
name|ffename
name|first
decl_stmt|;
name|ffename
name|last
decl_stmt|;
name|mallocPool
name|pool
decl_stmt|;
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
name|ffename
name|ffename_find
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffename_kill
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|,
name|ffename
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffename
name|ffename_lookup
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffename_space_drive_global
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|,
name|ffeglobal
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffeglobal
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffename_space_drive_symbol
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|,
name|ffesymbol
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffesymbol
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffename_space_kill
parameter_list|(
name|ffenameSpace
name|ns
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffenameSpace
name|ffename_space_new
parameter_list|(
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffename_first_token
parameter_list|(
name|n
parameter_list|)
value|((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_global
parameter_list|(
name|n
parameter_list|)
value|((n)->u.g)
end_define

begin_define
define|#
directive|define
name|ffename_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_set_global
parameter_list|(
name|n
parameter_list|,
name|glob
parameter_list|)
value|((n)->u.g = (glob))
end_define

begin_define
define|#
directive|define
name|ffename_set_symbol
parameter_list|(
name|n
parameter_list|,
name|sym
parameter_list|)
value|((n)->u.s = (sym))
end_define

begin_define
define|#
directive|define
name|ffename_symbol
parameter_list|(
name|n
parameter_list|)
value|((n)->u.s)
end_define

begin_define
define|#
directive|define
name|ffename_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffename_text
parameter_list|(
name|n
parameter_list|)
value|ffelex_token_text((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_token
parameter_list|(
name|n
parameter_list|)
value|((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_where_filename
parameter_list|(
name|n
parameter_list|)
value|ffelex_token_where_filename((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_where_filelinenum
parameter_list|(
name|n
parameter_list|)
value|ffelex_token_where_filelinenum((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_where_line
parameter_list|(
name|n
parameter_list|)
value|ffelex_token_where_line((n)->t)
end_define

begin_define
define|#
directive|define
name|ffename_where_column
parameter_list|(
name|n
parameter_list|)
value|ffelex_token_where_column((n)->t)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_NAME_H */
end_comment

end_unit

