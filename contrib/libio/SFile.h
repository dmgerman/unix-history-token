begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1988, 1992, 1993 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
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
file|<fstream.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|SFile
range|:
name|public
name|fstream
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
operator|:
name|fstream
argument_list|()
block|{ }
name|SFile
argument_list|(
argument|int fd
argument_list|,
argument|int size
argument_list|)
block|;
name|SFile
argument_list|(
argument|const char *name
argument_list|,
argument|int size
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|;
name|void
name|open
argument_list|(
argument|const char *name
argument_list|,
argument|int size
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|;
name|int
name|size
argument_list|()
block|{
return|return
name|sz
return|;
block|}
name|int
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

