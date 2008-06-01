begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2004, 2006 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MM_MALLOC_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_MM_MALLOC_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* We can't depend on<stdlib.h> since the prototype of posix_memalign    may not be visible.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_function_decl
specifier|extern
name|int
name|posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|int
name|posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|throw
parameter_list|()
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|_mm_malloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
name|alignment
operator|==
literal|1
condition|)
return|return
name|malloc
argument_list|(
name|size
argument_list|)
return|;
if|if
condition|(
name|alignment
operator|==
literal|2
operator|||
operator|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
operator|&&
name|alignment
operator|==
literal|4
operator|)
condition|)
name|alignment
operator|=
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|posix_memalign
argument_list|(
operator|&
name|ptr
argument_list|,
name|alignment
argument_list|,
name|size
argument_list|)
operator|==
literal|0
condition|)
return|return
name|ptr
return|;
else|else
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_mm_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MM_MALLOC_H_INCLUDED */
end_comment

end_unit

