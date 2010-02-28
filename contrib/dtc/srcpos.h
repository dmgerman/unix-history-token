begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2007 Jon Loeliger, Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation; either version 2 of the  * License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *                                                                   USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SRCPOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SRCPOS_H_
end_define

begin_comment
comment|/*  * Augment the standard YYLTYPE with a filenum index into an  * array of all opened filenames.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_struct
struct|struct
name|dtc_file
block|{
name|char
modifier|*
name|dir
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|FILE
modifier|*
name|file
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|YYLTYPE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|YYLTYPE_IS_DECLARED
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|YYLTYPE
block|{
name|int
name|first_line
decl_stmt|;
name|int
name|first_column
decl_stmt|;
name|int
name|last_line
decl_stmt|;
name|int
name|last_column
decl_stmt|;
name|struct
name|dtc_file
modifier|*
name|file
decl_stmt|;
block|}
name|YYLTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYLTYPE_IS_DECLARED
value|1
end_define

begin_define
define|#
directive|define
name|YYLTYPE_IS_TRIVIAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Cater to old parser templates. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYID
end_ifndef

begin_define
define|#
directive|define
name|YYID
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYLLOC_DEFAULT
parameter_list|(
name|Current
parameter_list|,
name|Rhs
parameter_list|,
name|N
parameter_list|)
define|\
value|do									\       if (YYID (N))							\ 	{								\ 	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\ 	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\ 	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\ 	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\ 	  (Current).file         = YYRHSLOC (Rhs, N).file;		\ 	}								\       else								\ 	{								\ 	  (Current).first_line   = (Current).last_line   =		\ 	    YYRHSLOC (Rhs, 0).last_line;				\ 	  (Current).first_column = (Current).last_column =		\ 	    YYRHSLOC (Rhs, 0).last_column;				\ 	  (Current).file         = YYRHSLOC (Rhs, 0).file;		\ 	}								\     while (YYID (0))
end_define

begin_typedef
typedef|typedef
name|YYLTYPE
name|srcpos
typedef|;
end_typedef

begin_comment
comment|/*  * Fictional source position used for IR nodes that are  * created without otherwise knowing a true source position.  * For example,constant definitions from the command line.  */
end_comment

begin_decl_stmt
specifier|extern
name|srcpos
name|srcpos_empty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|dtc_file
modifier|*
name|srcpos_file
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|search_path
block|{
specifier|const
name|char
modifier|*
name|dir
decl_stmt|;
comment|/* NULL for current directory */
name|struct
name|search_path
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|dtc_file
modifier|*
name|dtc_open_file
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
specifier|const
name|struct
name|search_path
modifier|*
name|search
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dtc_close_file
parameter_list|(
name|struct
name|dtc_file
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|srcpos
modifier|*
name|srcpos_copy
parameter_list|(
name|srcpos
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|srcpos_string
parameter_list|(
name|srcpos
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srcpos_dump
parameter_list|(
name|srcpos
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srcpos_error
parameter_list|(
name|srcpos
modifier|*
name|pos
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|srcpos_warn
parameter_list|(
name|srcpos
modifier|*
name|pos
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SRCPOS_H_ */
end_comment

end_unit

