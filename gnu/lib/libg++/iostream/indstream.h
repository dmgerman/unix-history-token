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
name|_INDSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|_INDSTREAM_H
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

begin_comment
comment|// An indirectbuf is one that forwards all of its I/O requests
end_comment

begin_comment
comment|// to another streambuf.
end_comment

begin_comment
comment|// All get-related requests are sent to get_stream().
end_comment

begin_comment
comment|// All put-related requests are sent to put_stream().
end_comment

begin_comment
comment|// An indirectbuf can be used to implement Common Lisp
end_comment

begin_comment
comment|// synonym-streams and two-way-streams.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// class synonymbuf : public indirectbuf {
end_comment

begin_comment
comment|//    Symbol *sym;
end_comment

begin_comment
comment|//    synonymbuf(Symbol *s) { sym = s; }
end_comment

begin_comment
comment|//    virtual streambuf *lookup_stream(int mode) {
end_comment

begin_comment
comment|//        return coerce_to_streambuf(lookup_value(sym)); }
end_comment

begin_comment
comment|// };
end_comment

begin_decl_stmt
name|class
name|indirectbuf
range|:
name|public
name|streambuf
block|{
name|protected
operator|:
name|streambuf
operator|*
name|_get_stream
block|;
comment|// Optional cache for get_stream().
name|streambuf
operator|*
name|_put_stream
block|;
comment|// Optional cache for put_stream().
name|int
name|_delete_flags
block|;
name|public
operator|:
name|streambuf
operator|*
name|get_stream
argument_list|()
block|{
return|return
name|_get_stream
operator|?
name|_get_stream
operator|:
name|lookup_stream
argument_list|(
name|ios
operator|::
name|in
argument_list|)
return|;
block|}
name|streambuf
operator|*
name|put_stream
argument_list|()
block|{
return|return
name|_put_stream
condition|?
name|_put_stream
else|:
name|lookup_stream
argument_list|(
name|ios
operator|::
name|out
argument_list|)
return|;
block|}
name|virtual
name|streambuf
operator|*
name|lookup_stream
argument_list|(
argument|int
comment|/*mode*/
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
comment|// ERROR!
name|indirectbuf
argument_list|(
argument|streambuf *get=NULL
argument_list|,
argument|streambuf *put=NULL
argument_list|,
argument|int delete_mode=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|indirectbuf
argument_list|()
block|;
name|virtual
name|int
name|xsputn
argument_list|(
argument|const char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|virtual
name|int
name|xsgetn
argument_list|(
argument|char* s
argument_list|,
argument|int n
argument_list|)
block|;
name|virtual
name|int
name|underflow
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
name|streampos
name|seekoff
argument_list|(
argument|streamoff
argument_list|,
argument|_seek_dir
argument_list|,
argument|int mode=ios::in|ios::out
argument_list|)
block|;
name|virtual
name|streampos
name|seekpos
argument_list|(
argument|streampos pos
argument_list|,
argument|int mode = ios::in|ios::out
argument_list|)
block|;
name|virtual
name|int
name|sync
argument_list|()
block|;
name|virtual
name|int
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_INDSTREAM_H */
end_comment

end_unit

