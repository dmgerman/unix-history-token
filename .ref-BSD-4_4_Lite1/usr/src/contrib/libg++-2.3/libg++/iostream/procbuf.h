begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing input/output for C++.
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

begin_include
include|#
directive|include
file|<streambuf.h>
end_include

begin_decl_stmt
name|class
name|procbuf
range|:
name|public
name|filebuf
block|{
name|_G_pid_t
name|_pid
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
end_decl_stmt

end_unit

