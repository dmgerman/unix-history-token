begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License.  Written by Per Bothner (bothner@cygnus.com). */
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

begin_extern
extern|extern
literal|"C++"
block|{
comment|// An indirectbuf is one that forwards all of its I/O requests
comment|// to another streambuf.
comment|// All get-related requests are sent to get_stream().
comment|// All put-related requests are sent to put_stream().
comment|// An indirectbuf can be used to implement Common Lisp
comment|// synonym-streams and two-way-streams.
comment|//
comment|// class synonymbuf : public indirectbuf {
comment|//    Symbol *sym;
comment|//    synonymbuf(Symbol *s) { sym = s; }
comment|//    virtual streambuf *lookup_stream(int mode) {
comment|//        return coerce_to_streambuf(lookup_value(sym)); }
comment|// };
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
name|streamsize
name|xsputn
argument_list|(
argument|const char* s
argument_list|,
argument|streamsize n
argument_list|)
block|;
name|virtual
name|streamsize
name|xsgetn
argument_list|(
argument|char* s
argument_list|,
argument|streamsize n
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|int
name|uflow
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
comment|/* !_INDSTREAM_H */
end_comment

end_unit

