begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993, 2000 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|_FSTREAM_H
end_define

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

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|fstreambase
range|:
name|virtual
name|public
name|ios
block|{
ifdef|#
directive|ifdef
name|_IO_NEW_STREAMS
name|mutable
name|filebuf
name|__my_fb
block|;
comment|// mutable so rdbuf() can be const
endif|#
directive|endif
name|void
name|__fb_init
argument_list|()
block|;
name|public
operator|:
name|fstreambase
argument_list|()
block|;
name|fstreambase
argument_list|(
argument|int fd
argument_list|)
block|;
name|fstreambase
argument_list|(
argument|int fd
argument_list|,
argument|char *p
argument_list|,
argument|int l
argument_list|)
block|;
comment|/* Deprecated */
name|fstreambase
argument_list|(
argument|const char *name
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|;
name|void
name|close
argument_list|()
block|;
ifdef|#
directive|ifdef
name|_IO_NEW_STREAMS
name|filebuf
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
operator|&
name|__my_fb
return|;
block|}
else|#
directive|else
name|filebuf
operator|*
name|rdbuf
argument_list|()
specifier|const
block|{
return|return
operator|(
name|filebuf
operator|*
operator|)
name|ios
operator|::
name|rdbuf
argument_list|()
return|;
block|}
endif|#
directive|endif
name|void
name|open
argument_list|(
argument|const char *name
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|;
name|int
name|is_open
argument_list|()
specifier|const
block|{
return|return
name|rdbuf
argument_list|()
operator|->
name|is_open
argument_list|()
return|;
block|}
name|void
name|setbuf
argument_list|(
argument|char *ptr
argument_list|,
argument|int len
argument_list|)
block|{
name|rdbuf
argument_list|()
operator|->
name|setbuf
argument_list|(
name|ptr
argument_list|,
name|len
argument_list|)
block|; }
name|void
name|attach
argument_list|(
argument|int fd
argument_list|)
block|;
ifdef|#
directive|ifdef
name|_STREAM_COMPAT
name|int
name|filedesc
argument_list|()
block|{
return|return
name|rdbuf
argument_list|()
operator|->
name|fd
argument_list|()
return|;
block|}
name|fstreambase
operator|&
name|raw
argument_list|()
block|{
name|rdbuf
argument_list|()
operator|->
name|setbuf
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
expr|}
block|;
name|class
name|ifstream
operator|:
name|public
name|fstreambase
block|,
name|public
name|istream
block|{
name|public
operator|:
name|ifstream
argument_list|()
operator|:
name|fstreambase
argument_list|()
block|{ }
name|ifstream
argument_list|(
argument|int fd
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|)
block|{ }
name|ifstream
argument_list|(
argument|int fd
argument_list|,
argument|char *p
argument_list|,
argument|int l
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|,
argument|p
argument_list|,
argument|l
argument_list|)
block|{ }
comment|/*Deprecated*/
name|ifstream
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::in
argument_list|,
argument|int prot=
literal|0664
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|name
argument_list|,
argument|mode | ios::in
argument_list|,
argument|prot
argument_list|)
block|{ }
name|void
name|open
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::in
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|{
name|fstreambase
operator|::
name|open
argument_list|(
name|name
argument_list|,
name|mode
operator||
name|ios
operator|::
name|in
argument_list|,
name|prot
argument_list|)
block|; }
block|}
block|;
name|class
name|ofstream
operator|:
name|public
name|fstreambase
block|,
name|public
name|ostream
block|{
name|public
operator|:
name|ofstream
argument_list|()
operator|:
name|fstreambase
argument_list|()
block|{ }
name|ofstream
argument_list|(
argument|int fd
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|)
block|{ }
name|ofstream
argument_list|(
argument|int fd
argument_list|,
argument|char *p
argument_list|,
argument|int l
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|,
argument|p
argument_list|,
argument|l
argument_list|)
block|{ }
comment|/*Deprecated*/
name|ofstream
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::out
argument_list|,
argument|int prot=
literal|0664
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|name
argument_list|,
argument|mode | ios::out
argument_list|,
argument|prot
argument_list|)
block|{ }
name|void
name|open
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::out
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|{
name|fstreambase
operator|::
name|open
argument_list|(
name|name
argument_list|,
name|mode
operator||
name|ios
operator|::
name|out
argument_list|,
name|prot
argument_list|)
block|; }
block|}
block|;
name|class
name|fstream
operator|:
name|public
name|fstreambase
block|,
name|public
name|iostream
block|{
name|public
operator|:
name|fstream
argument_list|()
operator|:
name|fstreambase
argument_list|()
block|{ }
name|fstream
argument_list|(
argument|int fd
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|)
block|{ }
name|fstream
argument_list|(
argument|const char *name
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|name
argument_list|,
argument|mode
argument_list|,
argument|prot
argument_list|)
block|{ }
name|fstream
argument_list|(
argument|int fd
argument_list|,
argument|char *p
argument_list|,
argument|int l
argument_list|)
operator|:
name|fstreambase
argument_list|(
argument|fd
argument_list|,
argument|p
argument_list|,
argument|l
argument_list|)
block|{ }
comment|/*Deprecated*/
name|void
name|open
argument_list|(
argument|const char *name
argument_list|,
argument|int mode
argument_list|,
argument|int prot=
literal|0664
argument_list|)
block|{
name|fstreambase
operator|::
name|open
argument_list|(
name|name
argument_list|,
name|mode
argument_list|,
name|prot
argument_list|)
block|; }
block|}
block|; }
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_FSTREAM_H*/
end_comment

end_unit

