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
name|_Filebuf_h
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
name|_Filebuf_h
value|1
end_define

begin_include
include|#
directive|include
file|<File.h>
end_include

begin_include
include|#
directive|include
file|<streambuf.h>
end_include

begin_decl_stmt
name|class
name|Filebuf
range|:
name|public
name|streambuf
comment|// libg++ File version
block|{
name|public
operator|:
name|File
operator|*
name|Fp
block|;
name|void
name|init_streambuf_ptrs
argument_list|()
block|;
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
block|;
name|int
name|underflow
argument_list|()
block|;
name|Filebuf
argument_list|()
block|;
name|Filebuf
argument_list|(
argument|const char* filename
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|Filebuf
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|m
argument_list|)
block|;
name|Filebuf
argument_list|(
argument|int filedesc
argument_list|,
argument|io_mode m
argument_list|)
block|;
name|Filebuf
argument_list|(
name|FILE
operator|*
name|fileptr
argument_list|)
block|;
operator|~
name|Filebuf
argument_list|()
block|;
specifier|const
name|char
operator|*
name|name
argument_list|()
block|;
name|streambuf
operator|*
name|setbuf
argument_list|(
argument|char* buf
argument_list|,
argument|int buflen
argument_list|,
argument|int preloaded_count =
literal|0
argument_list|)
block|;
name|streambuf
operator|*
name|open
argument_list|(
argument|const char* name
argument_list|,
argument|open_mode m
argument_list|)
block|;
name|streambuf
operator|*
name|open
argument_list|(
argument|const char* filename
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|streambuf
operator|*
name|open
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|m
argument_list|)
block|;
name|streambuf
operator|*
name|open
argument_list|(
argument|int  filedesc
argument_list|,
argument|io_mode m
argument_list|)
block|;
name|streambuf
operator|*
name|open
argument_list|(
name|FILE
operator|*
name|fileptr
argument_list|)
block|;
name|int
name|is_open
argument_list|()
block|;
name|int
name|close
argument_list|()
block|;
name|void
name|error
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

