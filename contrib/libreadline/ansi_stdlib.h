begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ansi_stdlib.h -- An ANSI Standard stdlib.h. */
end_comment

begin_comment
comment|/* A minimal stdlib.h containing extern declarations for those functions    that bash uses. */
end_comment

begin_comment
comment|/* Copyright (C) 1993 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     Bash is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License along    with Bash; see the file COPYING.  If not, write to the Free Software    Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_STDLIB_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_STDLIB_H_
value|1
end_define

begin_comment
comment|/* String conversion functions. */
end_comment

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|int
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Memory allocation functions. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Other miscellaneous functions. */
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qsort
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDLIB_H  */
end_comment

end_unit

