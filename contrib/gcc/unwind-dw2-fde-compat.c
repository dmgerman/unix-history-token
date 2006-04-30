begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Backward compatibility unwind routines.    Copyright (C) 2004    Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     In addition to the permissions in the GNU General Public License, the    Free Software Foundation gives you unlimited permission to link the    compiled version of this file into combinations with other programs,    and to distribute those combinations without any restriction coming    from the use of this file.  (The General Public License restrictions    do apply in other respects; for example, they cover modification of    the file, and distribution when not linked into a combined    executable.)     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_GAS_SYMVER
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_LIBUNWIND_EXCEPTIONS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"unwind.h"
end_include

begin_include
include|#
directive|include
file|"unwind-dw2-fde.h"
end_include

begin_include
include|#
directive|include
file|"unwind-compat.h"
end_include

begin_function_decl
specifier|extern
specifier|const
name|fde
modifier|*
name|__libunwind__Unwind_Find_FDE
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|dwarf_eh_bases
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|fde
modifier|*
name|_Unwind_Find_FDE
parameter_list|(
name|void
modifier|*
name|pc
parameter_list|,
name|struct
name|dwarf_eh_bases
modifier|*
name|bases
parameter_list|)
block|{
name|__libunwind__Unwind_Find_FDE
argument_list|(
name|pc
argument_list|,
name|bases
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|symver
argument_list|(
name|_Unwind_Find_FDE
argument_list|,
name|GCC_3
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

