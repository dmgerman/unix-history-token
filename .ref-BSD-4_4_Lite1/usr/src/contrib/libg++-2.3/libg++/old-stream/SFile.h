begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988, 1992 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SFile_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_SFile_h
value|1
end_define

begin_include
include|#
directive|include
file|<File.h>
end_include

begin_decl_stmt
name|class
name|SFile
range|:
name|public
name|File
block|{
name|protected
operator|:
name|int
name|sz
block|;
comment|// unit size for structured binary IO
name|public
operator|:
name|SFile
argument_list|()
block|;
name|SFile
argument_list|(
argument|const char* filename
argument_list|,
argument|int size
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|SFile
argument_list|(
argument|const char* filename
argument_list|,
argument|int size
argument_list|,
argument|const char* m
argument_list|)
block|;
name|SFile
argument_list|(
argument|int filedesc
argument_list|,
argument|int size
argument_list|,
argument|io_mode m
argument_list|)
block|;
name|SFile
argument_list|(
argument|FILE* fileptr
argument_list|,
argument|int size
argument_list|)
block|;
operator|~
name|SFile
argument_list|()
block|;
name|int
name|size
argument_list|()
block|;
name|int
name|setsize
argument_list|(
argument|int s
argument_list|)
block|;
name|SFile
operator|&
name|get
argument_list|(
name|void
operator|*
name|x
argument_list|)
block|;
name|SFile
operator|&
name|put
argument_list|(
name|void
operator|*
name|x
argument_list|)
block|;
name|SFile
operator|&
name|operator
index|[]
operator|(
name|long
name|i
operator|)
block|; }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OPTIMIZE__
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_LIBGXX_INLINES
argument_list|)
end_if

begin_expr_stmt
specifier|inline
name|int
name|SFile
operator|::
name|size
argument_list|()
block|{
return|return
name|sz
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|SFile
operator|::
name|setsize
argument_list|(
argument|int s
argument_list|)
block|{
name|int
name|old
operator|=
name|sz
block|;
name|sz
operator|=
name|s
block|;
return|return
name|old
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|get
argument_list|(
argument|void* x
argument_list|)
block|{
name|read
argument_list|(
name|x
argument_list|,
name|sz
argument_list|,
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|put
argument_list|(
argument|void* x
argument_list|)
block|{
name|write
argument_list|(
name|x
argument_list|,
name|sz
argument_list|,
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|operator
index|[]
operator|(
name|long
name|i
operator|)
block|{
name|seek
argument_list|(
name|i
operator|*
name|sz
argument_list|,
literal|0
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

