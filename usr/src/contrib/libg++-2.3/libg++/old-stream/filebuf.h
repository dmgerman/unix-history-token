begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_filebuf_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_if
if|#
directive|if
operator|(
name|__GNUG__
operator|==
literal|1
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_endif
endif|#
directive|endif
end_endif

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
name|_filebuf_h
value|1
end_define

begin_include
include|#
directive|include
file|<streambuf.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|class
name|filebuf
range|:
name|public
name|streambuf
block|{
name|public
operator|:
name|int
name|fd
block|;
name|char
name|opened
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
name|filebuf
argument_list|()
block|;
name|filebuf
argument_list|(
argument|int newfd
argument_list|)
block|;
name|filebuf
argument_list|(
argument|int newfd
argument_list|,
argument|char* buf
argument_list|,
argument|int buflen
argument_list|)
block|;
operator|~
name|filebuf
argument_list|()
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
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

