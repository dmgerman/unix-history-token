begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing input/output for C++.
end_comment

begin_comment
comment|//    Copyright (C) 1991 Per Bothner.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is free software; you can redistribute it and/or
end_comment

begin_comment
comment|//    modify it under the terms of the GNU Library General Public
end_comment

begin_comment
comment|//    License as published by the Free Software Foundation; either
end_comment

begin_comment
comment|//    version 2 of the License, or (at your option) any later version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|//    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
end_comment

begin_comment
comment|//    Library General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    You should have received a copy of the GNU Library General Public
end_comment

begin_comment
comment|//    License along with this library; if not, write to the Free
end_comment

begin_comment
comment|//    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
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

begin_decl_stmt
name|class
name|fstreambase
range|:
name|virtual
name|public
name|ios
block|{
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
name|_strbuf
return|;
block|}
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
argument|mode
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
argument|mode
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
block|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!_FSTREAM_H*/
end_comment

end_unit

