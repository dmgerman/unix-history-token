begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/*    a very simple implementation of a class to output unix "plot"   format plotter files. See corresponding unix man pages for   more details.     written by Doug Lea (dl@rocky.oswego.edu)   converted to use iostream library by Per Bothner (bothner@cygnus.com) */
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
file|<fstream.h>
end_include

begin_comment
comment|/*       Some plot libraries have the `box' command to draw boxes. Some don't.    `box' is included here via moves& lines to allow both possiblilties. */
end_comment

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|PlotFile
range|:
name|public
name|ofstream
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
operator|:
name|ofstream
argument_list|()
block|{ }
name|PlotFile
argument_list|(
argument|int fd
argument_list|)
operator|:
name|ofstream
argument_list|(
argument|fd
argument_list|)
block|{ }
name|PlotFile
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::out
argument_list|,
argument|int prot=
literal|0664
argument_list|)
operator|:
name|ofstream
argument_list|(
argument|name
argument_list|,
argument|mode
argument_list|,
argument|prot
argument_list|)
block|{ }
comment|//  PlotFile& remove() { ofstream::remove(); return *this; }
comment|//  int           filedesc() { return ofstream::filedesc(); }
comment|//  const char*   name() { return File::name(); }
comment|//  void          setname(const char* newname) { File::setname(newname); }
comment|//  int           iocount() { return File::iocount(); }
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
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

