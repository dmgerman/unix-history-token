begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing -*- C++ -*- input/output.
end_comment

begin_comment
comment|//    Copyright (C) 1992 Per Bothner.
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
name|_STDIOSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|_STDIOSTREAM_H
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
file|<streambuf.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|class
name|stdiobuf
range|:
name|public
name|filebuf
block|{
name|protected
operator|:
name|FILE
operator|*
name|_file
block|;
name|public
operator|:
name|FILE
operator|*
name|stdiofile
argument_list|()
specifier|const
block|{
return|return
name|_file
return|;
block|}
name|stdiobuf
argument_list|(
name|FILE
operator|*
name|f
argument_list|)
block|;
name|virtual
name|_G_ssize_t
name|sys_read
argument_list|(
argument|char* buf
argument_list|,
argument|_G_size_t size
argument_list|)
block|;
name|virtual
name|fpos_t
name|sys_seek
argument_list|(
name|fpos_t
argument_list|,
name|_seek_dir
argument_list|)
block|;
name|virtual
name|_G_ssize_t
name|sys_write
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
name|long
argument_list|)
block|;
name|virtual
name|int
name|sys_close
argument_list|()
block|;
name|virtual
name|int
name|sync
argument_list|()
block|;
name|virtual
name|int
name|overflow
argument_list|(
argument|int c = EOF
argument_list|)
block|;
name|virtual
name|int
name|xsputn
argument_list|(
argument|const char* s
argument_list|,
argument|int n
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDIOSTREAM_H */
end_comment

end_unit

