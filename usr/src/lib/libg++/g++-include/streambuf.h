begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_streambuf_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

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
name|_streambuf_h
value|1
end_define

begin_comment
comment|/* streambufs.     basic streambufs and filebufs are as in Stroustrup, ch 8,    but the base class contains virtual extensions that allow    most capabilities of libg++ Files to be used as streambufs    via `Filebufs'. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<builtin.h>
end_include

begin_include
include|#
directive|include
file|<Fmodes.h>
end_include

begin_comment
comment|// see below for NO_LINE_BUFFER_STREAMBUFS
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_define
define|#
directive|define
name|BUFSIZE
value|BUFSIZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|open_mode
comment|// filebuf open modes
block|{
name|input
init|=
literal|0
block|,
name|output
init|=
literal|1
block|,
name|append
init|=
literal|2
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|streambuf
block|{
name|public
label|:
name|char
modifier|*
name|base
decl_stmt|;
comment|// start of buffer
name|char
modifier|*
name|pptr
decl_stmt|;
comment|// put-pointer (and gptr fence)
name|char
modifier|*
name|gptr
decl_stmt|;
comment|// get-pointer
name|char
modifier|*
name|eptr
decl_stmt|;
comment|// last valid addr in buffer
name|char
name|alloc
decl_stmt|;
comment|// true if we own freestore alloced buffer
name|streambuf
argument_list|()
expr_stmt|;
name|streambuf
argument_list|(
argument|char* buf
argument_list|,
argument|int buflen
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|streambuf
argument_list|()
expr_stmt|;
name|int
name|doallocate
parameter_list|()
function_decl|;
name|int
name|allocate
parameter_list|()
function_decl|;
name|int
name|must_overflow
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
comment|// true if should call overflow
name|virtual
name|int
name|overflow
parameter_list|(
name|int
name|c
init|=
name|EOF
parameter_list|)
function_decl|;
comment|// flush -- return EOF if fail
name|virtual
name|int
name|underflow
parameter_list|()
function_decl|;
comment|// fill -- return EOF if fail
name|int
name|sgetc
parameter_list|()
function_decl|;
comment|// get one char (as int) or EOF
name|int
name|snextc
parameter_list|()
function_decl|;
comment|// get and advance
name|void
name|stossc
parameter_list|()
function_decl|;
comment|// advance only
name|int
name|sputbackc
parameter_list|(
name|char
parameter_list|)
function_decl|;
comment|// unget
name|int
name|sputc
parameter_list|(
name|int
name|c
init|=
name|EOF
parameter_list|)
function_decl|;
comment|// write one char
name|virtual
name|streambuf
modifier|*
name|setbuf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|int
name|preloaded_count
init|=
literal|0
parameter_list|)
function_decl|;
comment|// (not virtual in AT&T)
comment|// the following aren't in AT&T version:
name|int
name|sputs
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
comment|// write null-terminated str
name|int
name|sputsn
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|// write len bytes
name|virtual
specifier|const
name|char
modifier|*
name|name
parameter_list|()
function_decl|;
name|virtual
name|streambuf
modifier|*
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|open_mode
name|m
parameter_list|)
function_decl|;
name|virtual
name|streambuf
modifier|*
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|io_mode
name|m
parameter_list|,
name|access_mode
name|a
parameter_list|)
function_decl|;
name|virtual
name|streambuf
modifier|*
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|m
parameter_list|)
function_decl|;
name|virtual
name|streambuf
modifier|*
name|open
parameter_list|(
name|int
name|filedesc
parameter_list|,
name|io_mode
name|m
parameter_list|)
function_decl|;
name|virtual
name|streambuf
modifier|*
name|open
parameter_list|(
name|FILE
modifier|*
name|fileptr
parameter_list|)
function_decl|;
name|virtual
name|int
name|is_open
parameter_list|()
function_decl|;
name|virtual
name|int
name|close
parameter_list|()
function_decl|;
name|virtual
name|void
name|error
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OPTIMIZE__
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_LIBGXX_INLINES
argument_list|)
end_if

begin_expr_stmt
specifier|inline
name|int
name|streambuf
operator|::
name|must_overflow
argument_list|(
argument|int ch
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NO_LINE_BUFFER_STREAMBUF
return|return
name|pptr
operator|>=
name|eptr
operator|||
name|ch
operator|==
literal|'\n'
return|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_return
return|return
name|pptr
operator|>=
name|eptr
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|}   inline
name|int
name|streambuf
operator|::
name|allocate
argument_list|()
block|{
return|return
operator|(
name|base
operator|==
literal|0
operator|)
operator|?
name|doallocate
argument_list|()
operator|:
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|streambuf
operator|::
name|sgetc
argument_list|()
block|{
return|return
operator|(
name|gptr
operator|>=
name|pptr
operator|)
operator|?
name|underflow
argument_list|()
operator|:
name|int
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|*
name|gptr
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|streambuf
operator|::
name|snextc
argument_list|()
block|{
operator|++
name|gptr
block|;
return|return
operator|(
name|gptr
operator|>=
name|pptr
operator|)
condition|?
name|underflow
argument_list|()
else|:
name|int
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|*
name|gptr
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|streambuf
operator|::
name|stossc
argument_list|()
block|{
if|if
condition|(
name|gptr
operator|>=
name|pptr
condition|)
name|underflow
argument_list|()
expr_stmt|;
else|else
name|gptr
operator|++
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|streambuf
operator|::
name|sputbackc
argument_list|(
argument|char ch
argument_list|)
block|{
return|return
operator|(
name|gptr
operator|>
name|base
operator|)
operator|?
name|int
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|*
operator|--
name|gptr
operator|=
name|ch
argument_list|)
argument_list|)
operator|:
name|EOF
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|streambuf
operator|::
name|sputc
argument_list|(
argument|int ch
argument_list|)
block|{
return|return
name|must_overflow
argument_list|(
name|ch
argument_list|)
operator|?
name|overflow
argument_list|(
name|ch
argument_list|)
operator|:
name|int
argument_list|(
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|*
name|pptr
operator|++
operator|=
name|char
argument_list|(
name|ch
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

