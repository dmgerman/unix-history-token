begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of libio/iostream, providing -*- C++ -*- input/output. Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/* Written by Per Bothner (bothner@cygnus.com). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROCBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_PROCBUF_H
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

begin_extern
extern|extern
literal|"C++"
block|{
name|class
name|procbuf
range|:
name|public
name|filebuf
block|{
comment|/* Following fields must match those in struct _IO_proc_file */
name|_IO_pid_t
name|_pid
block|;
name|procbuf
operator|*
name|_next
block|;
name|public
operator|:
name|procbuf
argument_list|()
operator|:
name|filebuf
argument_list|()
block|{ }
name|procbuf
argument_list|(
argument|const char *command
argument_list|,
argument|int mode
argument_list|)
block|;
name|procbuf
operator|*
name|open
argument_list|(
argument|const char *command
argument_list|,
argument|int mode
argument_list|)
block|;
name|procbuf
operator|*
name|close
argument_list|()
block|{
return|return
operator|(
name|procbuf
operator|*
operator|)
name|filebuf
operator|::
name|close
argument_list|()
return|;
block|}
name|virtual
name|int
name|sys_close
argument_list|()
block|;
operator|~
name|procbuf
argument_list|()
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
comment|/* !_PROCBUF_H */
end_comment

end_unit

