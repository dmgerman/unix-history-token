begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988, 1992 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)     converted to use iostream library by Per Bothner (bothner@cygnus.com)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
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
file|<fstream.h>
end_include

begin_comment
comment|/*       Some plot libraries have the `box' command to draw boxes. Some don't.    `box' is included here via moves& lines to allow both possiblilties. */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

