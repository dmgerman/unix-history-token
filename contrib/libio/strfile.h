begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1993, 1997, 1998 Free Software Foundation, Inc.    This file is part of the GNU IO Library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this library; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.     As a special exception, if you link this library with files    compiled with a GNU compiler to produce an executable, this does    not cause the resulting executable to be covered by the GNU General    Public License.  This exception does not however invalidate any    other reasons why the executable file might be covered by the GNU    General Public License.  */
end_comment

begin_include
include|#
directive|include
file|<libio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TODO
end_ifdef

begin_expr_stmt
name|Merge
name|into
name|libio
operator|.
name|h
condition|?
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__PMT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__PMT
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PMT
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!__P*/
end_comment

begin_typedef
typedef|typedef
name|void
operator|*
operator|(
operator|*
name|_IO_alloc_type
operator|)
name|__PMT
argument_list|(
operator|(
name|_IO_size_t
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*_IO_free_type
argument_list|)
name|__PMT
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|_IO_str_fields
block|{
name|_IO_alloc_type
name|_allocate_buffer
decl_stmt|;
name|_IO_free_type
name|_free_buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is needed for the Irix6 N32 ABI, which has a 64 bit off_t type,    but a 32 bit pointer type.  In this case, we get 4 bytes of padding    after the vtable pointer.  Putting them in a structure together solves    this problem.  */
end_comment

begin_struct
struct|struct
name|_IO_streambuf
block|{
name|struct
name|_IO_FILE
name|_f
decl_stmt|;
specifier|const
name|void
modifier|*
name|_vtable
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_IO_strfile_
block|{
name|struct
name|_IO_streambuf
name|_sbf
decl_stmt|;
name|struct
name|_IO_str_fields
name|_s
decl_stmt|;
block|}
name|_IO_strfile
typedef|;
end_typedef

begin_comment
comment|/* dynamic: set when the array object is allocated (or reallocated)  as    necessary to hold a character sequence that can change in length. */
end_comment

begin_define
define|#
directive|define
name|_IO_STR_DYNAMIC
parameter_list|(
name|FP
parameter_list|)
value|((FP)->_s._allocate_buffer != (_IO_alloc_type)0)
end_define

begin_comment
comment|/* frozen: set when the program has requested that the array object not    be altered, reallocated, or freed. */
end_comment

begin_define
define|#
directive|define
name|_IO_STR_FROZEN
parameter_list|(
name|FP
parameter_list|)
value|((FP)->_f._IO_file_flags& _IO_USER_BUF)
end_define

end_unit

