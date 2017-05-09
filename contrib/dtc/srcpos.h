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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_struct
struct|struct
name|srcfile_state
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|dir
decl_stmt|;
name|int
name|lineno
decl_stmt|,
name|colno
decl_stmt|;
name|struct
name|srcfile_state
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|depfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* = NULL */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|srcfile_state
modifier|*
name|current_srcfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* = NULL */
end_comment

begin_comment
comment|/**  * Open a source file.  *  * If the source file is a relative pathname, then it is searched for in the  * current directory (the directory of the last source file read) and after  * that in the search path.  *  * We work through the search path in order from the first path specified to  * the last.  *  * If the file is not found, then this function does not return, but calls  * die().  *  * @param fname		Filename to search  * @param fullnamep	If non-NULL, it is set to the allocated filename of the  *			file that was opened. The caller is then responsible  *			for freeing the pointer.  * @return pointer to opened FILE  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|srcfile_relative_open
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|char
modifier|*
modifier|*
name|fullnamep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srcfile_push
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|srcfile_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add a new directory to the search path for input files  *  * The new path is added at the end of the list.  *  * @param dirname	Directory to add  */
end_comment

begin_function_decl
name|void
name|srcfile_add_search_path
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|srcpos
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
name|srcfile_state
modifier|*
name|file
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|YYLTYPE
value|struct srcpos
end_define

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
value|do {									\ 		if (N) {							\ 			(Current).first_line = YYRHSLOC(Rhs, 1).first_line;	\ 			(Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\ 			(Current).last_line = YYRHSLOC(Rhs, N).last_line;	\ 			(Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\ 			(Current).file = YYRHSLOC(Rhs, N).file;			\ 		} else {							\ 			(Current).first_line = (Current).last_line =		\ 				YYRHSLOC(Rhs, 0).last_line;			\ 			(Current).first_column = (Current).last_column =	\ 				YYRHSLOC(Rhs, 0).last_column;			\ 			(Current).file = YYRHSLOC (Rhs, 0).file;		\ 		}								\ 	} while (0)
end_define

begin_comment
comment|/*  * Fictional source position used for IR nodes that are  * created without otherwise knowing a true source position.  * For example,constant definitions from the command line.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|srcpos
name|srcpos_empty
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|srcpos_update
parameter_list|(
name|struct
name|srcpos
modifier|*
name|pos
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|srcpos
modifier|*
name|srcpos_copy
parameter_list|(
name|struct
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
name|struct
name|srcpos
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|srcpos_verror
parameter_list|(
name|struct
name|srcpos
modifier|*
name|pos
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|va
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|srcpos_error
parameter_list|(
name|struct
name|srcpos
modifier|*
name|pos
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|srcpos_set_line
parameter_list|(
name|char
modifier|*
name|f
parameter_list|,
name|int
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SRCPOS_H_ */
end_comment

end_unit

