begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
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

begin_typedef
typedef|typedef
name|void
operator|*
operator|(
operator|*
name|_IO_alloc_type
operator|)
name|__P
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
name|__P
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
comment|/* The current length is max(_len, _IO_write_ptr-_IO_write_base). */
name|_IO_size_t
name|_len
decl_stmt|;
name|_IO_alloc_type
name|_allocate_buffer
decl_stmt|;
name|_IO_free_type
name|_free_buffer
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
name|_IO_FILE
name|_f
decl_stmt|;
specifier|const
name|void
modifier|*
name|_vtable
decl_stmt|;
name|struct
name|_IO_str_fields
name|_s
decl_stmt|;
block|}
name|_IO_strfile
typedef|;
end_typedef

end_unit

