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
name|_SFile_h
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
name|_SFile_h
value|1
end_define

begin_include
include|#
directive|include
file|<File.h>
end_include

begin_decl_stmt
name|class
name|SFile
range|:
name|public
name|File
block|{
name|protected
operator|:
name|int
name|sz
block|;
comment|// unit size for structured binary IO
name|public
operator|:
name|SFile
argument_list|()
block|;
name|SFile
argument_list|(
argument|const char* filename
argument_list|,
argument|int size
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
block|;
name|SFile
argument_list|(
argument|const char* filename
argument_list|,
argument|int size
argument_list|,
argument|const char* m
argument_list|)
block|;
name|SFile
argument_list|(
argument|int filedesc
argument_list|,
argument|int size
argument_list|,
argument|io_mode m
argument_list|)
block|;
name|SFile
argument_list|(
argument|FILE* fileptr
argument_list|,
argument|int size
argument_list|)
block|;
operator|~
name|SFile
argument_list|()
block|;
name|int
name|size
argument_list|()
block|;
name|int
name|setsize
argument_list|(
argument|int s
argument_list|)
block|;
name|SFile
operator|&
name|get
argument_list|(
name|void
operator|*
name|x
argument_list|)
block|;
name|SFile
operator|&
name|put
argument_list|(
name|void
operator|*
name|x
argument_list|)
block|;
name|SFile
operator|&
name|operator
index|[]
operator|(
name|long
name|i
operator|)
block|; }
decl_stmt|;
end_decl_stmt

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
name|SFile
operator|::
name|size
argument_list|()
block|{
return|return
name|sz
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|SFile
operator|::
name|setsize
argument_list|(
argument|int s
argument_list|)
block|{
name|int
name|old
operator|=
name|sz
block|;
name|sz
operator|=
name|s
block|;
return|return
name|old
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|get
argument_list|(
argument|void* x
argument_list|)
block|{
name|read
argument_list|(
name|x
argument_list|,
name|sz
argument_list|,
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|put
argument_list|(
argument|void* x
argument_list|)
block|{
name|write
argument_list|(
name|x
argument_list|,
name|sz
argument_list|,
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|SFile
operator|&
name|SFile
operator|::
name|operator
index|[]
operator|(
name|long
name|i
operator|)
block|{
name|seek
argument_list|(
name|i
operator|*
name|sz
argument_list|,
literal|0
argument_list|)
block|;
return|return
operator|*
name|this
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

