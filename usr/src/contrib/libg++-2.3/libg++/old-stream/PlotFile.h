begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988, 1992 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/*     a very simple implementation of a class to output unix "plot"    format plotter files. See corresponding unix man pages for    more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PlotFile_h
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
name|_PlotFile_h
end_define

begin_include
include|#
directive|include
file|<File.h>
end_include

begin_comment
comment|/*       Some plot libraries have the `box' command to draw boxes. Some don't.    `box' is included here via moves& lines to allow both possiblilties. */
end_comment

begin_decl_stmt
name|class
name|PlotFile
range|:
name|private
name|File
block|{
name|protected
operator|:
name|PlotFile
operator|&
name|cmd
argument_list|(
argument|char c
argument_list|)
block|;
name|PlotFile
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|int
name|x
operator|)
block|;
name|PlotFile
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|s
operator|)
block|;
name|public
operator|:
name|PlotFile
argument_list|()
block|;
name|PlotFile
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
block|;
name|PlotFile
argument_list|(
argument|const char* filename
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|PlotFile
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
name|PlotFile
argument_list|(
argument|int filedesc
argument_list|,
argument|const io_mode m = io_writeonly
argument_list|)
block|;
name|PlotFile
argument_list|(
name|FILE
operator|*
name|fileptr
argument_list|)
block|;
operator|~
name|PlotFile
argument_list|()
block|;
name|operator
name|void
operator|*
operator|(
operator|)
block|;
name|PlotFile
operator|&
name|close
argument_list|()
block|{
name|File
operator|::
name|close
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|PlotFile
operator|&
name|remove
argument_list|()
block|{
name|File
operator|::
name|remove
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|int
name|filedesc
argument_list|()
block|{
return|return
name|File
operator|::
name|filedesc
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|name
argument_list|()
block|{
return|return
name|File
operator|::
name|name
argument_list|()
return|;
block|}
name|void
name|setname
argument_list|(
argument|const char* newname
argument_list|)
block|{
name|File
operator|::
name|setname
argument_list|(
name|newname
argument_list|)
block|; }
name|int
name|iocount
argument_list|()
block|{
return|return
name|File
operator|::
name|iocount
argument_list|()
return|;
block|}
name|int
name|rdstate
argument_list|()
block|{
return|return
name|File
operator|::
name|rdstate
argument_list|()
return|;
block|}
name|int
name|eof
argument_list|()
block|{
return|return
name|File
operator|::
name|eof
argument_list|()
return|;
block|}
name|int
name|fail
argument_list|()
block|{
return|return
name|File
operator|::
name|fail
argument_list|()
return|;
block|}
name|int
name|bad
argument_list|()
block|{
return|return
name|File
operator|::
name|bad
argument_list|()
return|;
block|}
name|int
name|good
argument_list|()
block|{
return|return
name|File
operator|::
name|good
argument_list|()
return|;
block|}
comment|// other status queries
name|int
name|readable
argument_list|()
block|{
return|return
name|File
operator|::
name|readable
argument_list|()
return|;
block|}
name|int
name|writable
argument_list|()
block|{
return|return
name|File
operator|::
name|writable
argument_list|()
return|;
block|}
name|int
name|is_open
argument_list|()
block|{
return|return
name|File
operator|::
name|is_open
argument_list|()
return|;
block|}
name|void
name|error
argument_list|()
block|{
name|File
operator|::
name|error
argument_list|()
block|; }
name|void
name|clear
argument_list|(
argument|state_value f = _good
argument_list|)
block|{
name|File
operator|::
name|clear
argument_list|(
name|f
argument_list|)
block|; }
name|void
name|set
argument_list|(
argument|state_value f
argument_list|)
block|{
name|File
operator|::
name|set
argument_list|(
name|f
argument_list|)
block|; }
name|void
name|unset
argument_list|(
argument|state_value f
argument_list|)
block|{
name|File
operator|::
name|unset
argument_list|(
name|f
argument_list|)
block|; }
name|PlotFile
operator|&
name|failif
argument_list|(
argument|int cond
argument_list|)
block|{
name|File
operator|::
name|failif
argument_list|(
name|cond
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|void
name|check_state
argument_list|()
block|{
name|File
operator|::
name|check_state
argument_list|()
block|; }
name|PlotFile
operator|&
name|raw
argument_list|()
block|{
name|File
operator|::
name|raw
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|PlotFile
operator|&
name|open
argument_list|(
argument|const char* filename
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|PlotFile
operator|&
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
name|PlotFile
operator|&
name|open
argument_list|(
argument|int  filedesc
argument_list|,
argument|io_mode m
argument_list|)
block|;
name|PlotFile
operator|&
name|open
argument_list|(
name|FILE
operator|*
name|fileptr
argument_list|)
block|;
name|PlotFile
operator|&
name|setbuf
argument_list|(
argument|const int buffer_kind
argument_list|)
block|;
comment|// vals: _IONBF, _IOFBF, _IOLBF
name|PlotFile
operator|&
name|setbuf
argument_list|(
argument|const int size
argument_list|,
argument|char* buf
argument_list|)
block|;
name|PlotFile
operator|&
name|arc
argument_list|(
argument|const int xi
argument_list|,
argument|const int yi
argument_list|,
argument|const int x0
argument_list|,
argument|const int y0
argument_list|,
argument|const int x1
argument_list|,
argument|const int y1
argument_list|)
block|;
name|PlotFile
operator|&
name|box
argument_list|(
argument|const int x0
argument_list|,
argument|const int y0
argument_list|,
argument|const int x1
argument_list|,
argument|const int y1
argument_list|)
block|;
name|PlotFile
operator|&
name|circle
argument_list|(
argument|const int x
argument_list|,
argument|const int y
argument_list|,
argument|const int r
argument_list|)
block|;
name|PlotFile
operator|&
name|cont
argument_list|(
argument|const int xi
argument_list|,
argument|const int yi
argument_list|)
block|;
name|PlotFile
operator|&
name|dot
argument_list|(
argument|const int xi
argument_list|,
argument|const int yi
argument_list|,
argument|const int dx
argument_list|,
argument|int n
argument_list|,
argument|const int* pat
argument_list|)
block|;
name|PlotFile
operator|&
name|erase
argument_list|()
block|;
name|PlotFile
operator|&
name|label
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
name|PlotFile
operator|&
name|line
argument_list|(
argument|const int x0
argument_list|,
argument|const int y0
argument_list|,
argument|const int x1
argument_list|,
argument|const int y1
argument_list|)
block|;
name|PlotFile
operator|&
name|linemod
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|)
block|;
name|PlotFile
operator|&
name|move
argument_list|(
argument|const int xi
argument_list|,
argument|const int yi
argument_list|)
block|;
name|PlotFile
operator|&
name|point
argument_list|(
argument|const int xi
argument_list|,
argument|const int yi
argument_list|)
block|;
name|PlotFile
operator|&
name|space
argument_list|(
argument|const int x0
argument_list|,
argument|const int y0
argument_list|,
argument|const int x1
argument_list|,
argument|const int y1
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

