begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header for a pass computing data for optimizing stdarg functions.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by Jakub Jelinek<jakub@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_STDARG_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_STDARG_H
value|1
end_define

begin_struct
struct|struct
name|stdarg_info
block|{
name|bitmap
name|va_list_vars
decl_stmt|,
name|va_list_escape_vars
decl_stmt|;
name|basic_block
name|bb
decl_stmt|;
name|int
name|compute_sizes
decl_stmt|,
name|va_start_count
decl_stmt|;
name|bool
name|va_list_escapes
decl_stmt|;
name|int
modifier|*
name|offsets
decl_stmt|;
comment|/* These 2 fields are only meaningful if va_start_count == 1.  */
name|basic_block
name|va_start_bb
decl_stmt|;
name|tree
name|va_start_ap
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

