begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stack allocation routines.  This is intended for machines without support    for the `alloca' function.  Copyright (C) 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_struct
struct|struct
name|tmp_stack
block|{
name|void
modifier|*
name|end
decl_stmt|;
name|void
modifier|*
name|alloc_point
decl_stmt|;
name|struct
name|tmp_stack
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tmp_marker
block|{
name|struct
name|tmp_stack
modifier|*
name|which_chunk
decl_stmt|;
name|void
modifier|*
name|alloc_point
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tmp_marker
name|tmp_marker
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|void
modifier|*
name|__tmp_alloc
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__tmp_mark
parameter_list|(
name|tmp_marker
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__tmp_free
parameter_list|(
name|tmp_marker
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
modifier|*
name|__tmp_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__tmp_mark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__tmp_free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__TMP_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|__TMP_ALIGN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TMP_DECL
parameter_list|(
name|marker
parameter_list|)
value|tmp_marker marker
end_define

begin_define
define|#
directive|define
name|TMP_ALLOC
parameter_list|(
name|size
parameter_list|)
define|\
value|__tmp_alloc (((unsigned long) (size) + __TMP_ALIGN - 1)& -__TMP_ALIGN)
end_define

begin_define
define|#
directive|define
name|TMP_MARK
parameter_list|(
name|marker
parameter_list|)
value|__tmp_mark (&marker)
end_define

begin_define
define|#
directive|define
name|TMP_FREE
parameter_list|(
name|marker
parameter_list|)
value|__tmp_free (&marker)
end_define

end_unit

