begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993, 1999 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/* Written by Per Bothner (bothner@cygnus.com). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|__STRSTREAM_H
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

begin_include
include|#
directive|include
file|<strfile.h>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|strstreambuf
range|:
name|public
name|streambuf
block|{   struct
name|_IO_str_fields
name|_s
block|;
name|friend
name|class
name|istrstream
block|;
name|void
name|init_dynamic
argument_list|(
argument|_IO_alloc_type alloc
argument_list|,
argument|_IO_free_type free
argument_list|,
argument|int initial_size =
literal|0
argument_list|)
block|;
name|void
name|init_static
argument_list|(
argument|char *ptr
argument_list|,
argument|int size
argument_list|,
argument|char *pstart
argument_list|)
block|;
name|void
name|init_readonly
argument_list|(
argument|const char *ptr
argument_list|,
argument|int size
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|int
name|overflow
argument_list|(
name|int
operator|=
name|EOF
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|;
name|public
operator|:
name|virtual
operator|~
name|strstreambuf
argument_list|()
block|;
name|strstreambuf
argument_list|()
block|{
name|init_dynamic
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|int initial_size
argument_list|)
block|{
name|init_dynamic
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|initial_size
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|void *(*__alloc)(_IO_size_t)
argument_list|,
argument|void (*__free)(void*)
argument_list|)
block|{
name|init_dynamic
argument_list|(
name|__alloc
argument_list|,
name|__free
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|char *ptr
argument_list|,
argument|int size
argument_list|,
argument|char *pstart = NULL
argument_list|)
block|{
name|init_static
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|,
name|pstart
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|unsigned char *ptr
argument_list|,
argument|int size
argument_list|,
argument|unsigned char *pstart = NULL
argument_list|)
block|{
name|init_static
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ptr
argument_list|,
name|size
argument_list|,
operator|(
name|char
operator|*
operator|)
name|pstart
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|const char *ptr
argument_list|,
argument|int size
argument_list|)
block|{
name|init_readonly
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|const unsigned char *ptr
argument_list|,
argument|int size
argument_list|)
block|{
name|init_readonly
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|ptr
argument_list|,
name|size
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|signed char *ptr
argument_list|,
argument|int size
argument_list|,
argument|signed char *pstart = NULL
argument_list|)
block|{
name|init_static
argument_list|(
operator|(
name|char
operator|*
operator|)
name|ptr
argument_list|,
name|size
argument_list|,
operator|(
name|char
operator|*
operator|)
name|pstart
argument_list|)
block|; }
name|strstreambuf
argument_list|(
argument|const signed char *ptr
argument_list|,
argument|int size
argument_list|)
block|{
name|init_readonly
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|ptr
argument_list|,
name|size
argument_list|)
block|; }
comment|// Note: frozen() is always true if !_IO_STR_DYNAMIC(this).
name|int
name|frozen
argument_list|()
block|{
return|return
name|_flags
operator|&
name|_IO_USER_BUF
operator|?
literal|1
operator|:
literal|0
return|;
block|}
name|void
name|freeze
argument_list|(
argument|int n=
literal|1
argument_list|)
block|{
if|if
condition|(
name|_IO_STR_DYNAMIC
argument_list|(
name|this
argument_list|)
condition|)
block|{
if|if
condition|(
name|n
condition|)
name|_flags
operator||=
name|_IO_USER_BUF
expr_stmt|;
else|else
name|_flags
operator|&=
operator|~
name|_IO_USER_BUF
expr_stmt|;
block|}
block|}
name|_IO_ssize_t
name|pcount
argument_list|()
block|;
name|char
operator|*
name|str
argument_list|()
block|;
name|virtual
name|streampos
name|seekoff
argument_list|(
argument|streamoff
argument_list|,
argument|_seek_dir
argument_list|,
argument|int mode=ios::in|ios::out
argument_list|)
block|; }
decl_stmt|;
name|class
name|strstreambase
range|:
name|virtual
name|public
name|ios
block|{
name|protected
operator|:
name|strstreambuf
name|__my_sb
block|;
name|public
operator|:
name|strstreambuf
operator|*
name|rdbuf
argument_list|()
block|{
return|return
operator|&
name|__my_sb
return|;
block|}
name|protected
operator|:
name|strstreambase
argument_list|()
block|{
name|init
argument_list|(
operator|&
name|__my_sb
argument_list|)
block|; }
name|strstreambase
argument_list|(
argument|char *cp
argument_list|,
argument|int n
argument_list|,
argument|int mode=ios::out
argument_list|)
block|; }
decl_stmt|;
name|class
name|istrstream
range|:
name|public
name|strstreambase
decl_stmt|,
name|public
name|istream
block|{
name|public
label|:
name|istrstream
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
operator|=
literal|0
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ostrstream
range|:
name|public
name|strstreambase
decl_stmt|,
name|public
name|ostream
block|{
name|public
label|:
name|ostrstream
argument_list|()
block|{ }
name|ostrstream
argument_list|(
argument|char *cp
argument_list|,
argument|int n
argument_list|,
argument|int mode=ios::out
argument_list|)
block|:
name|strstreambase
argument_list|(
argument|cp
argument_list|,
argument|n
argument_list|,
argument|mode
argument_list|)
block|{}
name|_IO_ssize_t
name|pcount
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|pcount
argument_list|()
return|;
block|}
name|char
modifier|*
name|str
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|str
argument_list|()
return|;
block|}
name|void
name|freeze
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|freeze
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
name|int
name|frozen
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|frozen
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|class
name|strstream
range|:
name|public
name|strstreambase
decl_stmt|,
name|public
name|iostream
block|{
name|public
label|:
name|strstream
argument_list|()
block|{ }
name|strstream
argument_list|(
argument|char *cp
argument_list|,
argument|int n
argument_list|,
argument|int mode=ios::out
argument_list|)
block|:
name|strstreambase
argument_list|(
argument|cp
argument_list|,
argument|n
argument_list|,
argument|mode
argument_list|)
block|{}
name|_IO_ssize_t
name|pcount
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|pcount
argument_list|()
return|;
block|}
name|char
modifier|*
name|str
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|str
argument_list|()
return|;
block|}
name|void
name|freeze
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|freeze
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
name|int
name|frozen
parameter_list|()
block|{
return|return
operator|(
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
operator|)
operator|->
name|frozen
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!__STRSTREAM_H*/
end_comment

end_unit

