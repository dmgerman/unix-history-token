begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allocate and clear storage for bison,    Copyright (C) 1984, 1989 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_CALLOC
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_CALLOC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_REALLOC
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_DECLARATION_REALLOC */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xmalloc
name|PARAMS
argument_list|(
operator|(
specifier|register
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xrealloc
name|PARAMS
argument_list|(
operator|(
specifier|register
name|char
operator|*
operator|,
specifier|register
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|done
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
specifier|register
name|unsigned
name|n
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|block
decl_stmt|;
comment|/* Avoid uncertainty about what an arg of 0 will do.  */
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
name|block
operator|=
name|calloc
argument_list|(
name|n
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|block
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"%s: memory exhausted\n"
argument_list|)
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|block
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|xrealloc
parameter_list|(
specifier|register
name|char
modifier|*
name|block
parameter_list|,
specifier|register
name|unsigned
name|n
parameter_list|)
block|{
comment|/* Avoid uncertainty about what an arg of 0 will do.  */
if|if
condition|(
name|n
operator|==
literal|0
condition|)
name|n
operator|=
literal|1
expr_stmt|;
name|block
operator|=
name|realloc
argument_list|(
name|block
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|block
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"%s: memory exhausted\n"
argument_list|)
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
name|done
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|block
operator|)
return|;
block|}
end_function

end_unit

