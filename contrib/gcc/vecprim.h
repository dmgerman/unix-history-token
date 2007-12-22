begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* VEC types for primitive types    Copyright (C) 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_VECPRIM_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_VECPRIM_H
end_define

begin_expr_stmt
name|DEF_VEC_I
argument_list|(
name|char
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_I
argument_list|(
name|char
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_I
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_I
argument_list|(
name|int
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_VECPRIM_H */
end_comment

end_unit

