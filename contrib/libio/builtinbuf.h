begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BUILTINBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_BUILTINBUF_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
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

begin_if
if|#
directive|if
operator|!
name|_IO_UNIFIED_JUMPTABLES
end_if

begin_comment
comment|// A builtinbuf is a streambuf where all the virtual operations
end_comment

begin_comment
comment|// call the _IO_jump_t table.
end_comment

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|builtinbuf
range|:
name|public
name|streambuf
block|{
name|friend
name|ios
block|;
name|virtual
name|int
name|overflow
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|int
name|underflow
argument_list|()
block|;
name|virtual
name|streamsize
name|xsgetn
argument_list|(
name|char
operator|*
argument_list|,
name|streamsize
argument_list|)
block|;
name|virtual
name|streamsize
name|xsputn
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|streamsize
argument_list|)
block|;
name|virtual
name|streambuf
operator|*
name|setbuf
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
block|;
name|virtual
name|int
name|doallocate
argument_list|()
block|;
name|virtual
operator|~
name|builtinbuf
argument_list|()
block|;
name|virtual
name|int
name|sync
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
name|pbackfail
argument_list|(
argument|int c
argument_list|)
block|;
name|virtual
name|streamsize
name|sys_read
argument_list|(
argument|char* buf
argument_list|,
argument|streamsize size
argument_list|)
block|;
name|virtual
name|streampos
name|sys_seek
argument_list|(
name|streamoff
argument_list|,
name|_seek_dir
argument_list|)
block|;
name|virtual
name|streamsize
name|sys_write
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|streamsize
argument_list|)
block|;
name|virtual
name|int
name|sys_stat
argument_list|(
name|void
operator|*
argument_list|)
block|;
comment|// Actually, a (struct stat*)
name|virtual
name|int
name|sys_close
argument_list|()
block|;
if|#
directive|if
literal|0
block|virtual int get_column();   virtual int set_column(int);
endif|#
directive|endif
name|private
operator|:
name|builtinbuf
argument_list|()
block|{ }
block|}
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BUILTINBUF_H */
end_comment

end_unit

