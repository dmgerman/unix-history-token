begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//    This is part of the iostream library, providing -*- C++ -*- input/output.
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

begin_decl_stmt
name|class
name|strstreambuf
range|:
name|public
name|backupbuf
block|{
name|_G_size_t
name|_len
block|;
comment|// The current length is max(_len, _pptr-_pbase).
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|_alloc_type
function_decl|)
parameter_list|(
name|_G_size_t
parameter_list|)
function_decl|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|_free_type
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|_alloc_type
name|_allocate_buffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_free_type
name|_free_buffer
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|init_dynamic
parameter_list|(
name|_alloc_type
name|alloc
parameter_list|,
name|_free_type
name|free
parameter_list|,
name|int
name|initial_size
init|=
literal|128
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_static
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|,
name|char
modifier|*
name|pstart
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_static
parameter_list|(
specifier|const
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|int
name|is_static
argument_list|()
specifier|const
block|{
return|return
name|_allocate_buffer
operator|==
operator|(
name|_alloc_type
operator|)
literal|0
return|;
block|}
end_expr_stmt

begin_function_decl
name|virtual
name|int
name|overflow
parameter_list|(
name|int
init|=
name|EOF
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|int
name|underflow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|int
name|pbackfail
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|virtual
operator|~
name|strstreambuf
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|strstreambuf
argument_list|()
end_macro

begin_block
block|{
name|init_dynamic
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|int initial_size
argument_list|)
end_macro

begin_block
block|{
name|init_dynamic
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|initial_size
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|void *(*alloc)(_G_size_t)
argument_list|,
argument|void (*free)(void*)
argument_list|)
end_macro

begin_block
block|{
name|init_dynamic
argument_list|(
name|alloc
argument_list|,
name|free
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|char *ptr
argument_list|,
argument|int size
argument_list|,
argument|char *pstart = NULL
argument_list|)
end_macro

begin_block
block|{
name|init_static
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|,
name|pstart
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|unsigned char *ptr
argument_list|,
argument|int size
argument_list|,
argument|unsigned char *pstart = NULL
argument_list|)
end_macro

begin_block
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
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|const char *ptr
argument_list|,
argument|int size
argument_list|)
end_macro

begin_block
block|{
name|init_static
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|const unsigned char *ptr
argument_list|,
argument|int size
argument_list|)
end_macro

begin_block
block|{
name|init_static
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
expr_stmt|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|_G_BROKEN_SIGNED_CHAR
end_ifndef

begin_macro
name|strstreambuf
argument_list|(
argument|signed char *ptr
argument_list|,
argument|int size
argument_list|,
argument|signed char *pstart = NULL
argument_list|)
end_macro

begin_block
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
expr_stmt|;
block|}
end_block

begin_macro
name|strstreambuf
argument_list|(
argument|const signed char *ptr
argument_list|,
argument|int size
argument_list|)
end_macro

begin_block
block|{
name|init_static
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
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Note: frozen() is always true if is_static().
end_comment

begin_function
name|int
name|frozen
parameter_list|()
block|{
return|return
name|_flags
operator|&
name|_S_USER_BUF
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

begin_function
name|void
name|freeze
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
block|{
if|if
condition|(
operator|!
name|is_static
argument_list|()
condition|)
block|{
if|if
condition|(
name|n
condition|)
name|_flags
operator||=
name|_S_USER_BUF
expr_stmt|;
else|else
name|_flags
operator|&=
operator|~
name|_S_USER_BUF
expr_stmt|;
block|}
block|}
end_function

begin_function_decl
name|_G_size_t
name|pcount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|streampos
name|seekoff
parameter_list|(
name|streamoff
parameter_list|,
name|_seek_dir
parameter_list|,
name|int
name|mode
init|=
name|ios
operator|::
name|in
operator||
name|ios
operator|::
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|};
name|class
name|strstreambase
range|:
name|virtual
name|public
name|ios
block|{
name|public
operator|:
name|strstreambuf
operator|*
name|rdbuf
argument_list|()
block|{
return|return
operator|(
name|strstreambuf
operator|*
operator|)
name|_strbuf
return|;
block|}
name|protected
operator|:
name|strstreambase
argument_list|()
block|{ }
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
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
expr_stmt|;
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
name|_G_size_t
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
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
operator|:
name|strstreambase
argument_list|()
block|{
name|init
argument_list|(
argument|new strstreambuf()
argument_list|)
block|; }
name|strstream
argument_list|(
argument|char *cp
argument_list|,
argument|int n
argument_list|,
argument|int mode=ios::out
argument_list|)
operator|:
name|strstreambase
argument_list|(
argument|cp
argument_list|,
argument|n
argument_list|,
argument|mode
argument_list|)
block|{}
name|_G_size_t
name|pcount
argument_list|()
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!__STRSTREAM_H*/
end_comment

end_unit

