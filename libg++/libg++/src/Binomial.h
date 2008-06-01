begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Dirk Grunwald (grunwald@cs.uiuc.edu)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Binomial_h
end_ifndef

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

begin_define
define|#
directive|define
name|_Binomial_h
value|1
end_define

begin_include
include|#
directive|include
file|<Random.h>
end_include

begin_decl_stmt
name|class
name|Binomial
range|:
name|public
name|Random
block|{
name|protected
operator|:
name|int
name|pN
block|;
name|double
name|pU
block|;
name|public
operator|:
name|Binomial
argument_list|(
argument|int n
argument_list|,
argument|double u
argument_list|,
argument|RNG *gen
argument_list|)
block|;
name|int
name|n
argument_list|()
block|;
name|int
name|n
argument_list|(
argument|int xn
argument_list|)
block|;
name|double
name|u
argument_list|()
block|;
name|double
name|u
argument_list|(
argument|double xu
argument_list|)
block|;
name|virtual
name|double
name|operator
argument_list|()
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|Binomial
operator|::
name|Binomial
argument_list|(
argument|int n
argument_list|,
argument|double u
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
name|Random
argument_list|(
argument|gen
argument_list|)
block|{
name|pN
operator|=
name|n
block|;
name|pU
operator|=
name|u
block|; }
specifier|inline
name|int
name|Binomial
operator|::
name|n
argument_list|()
block|{
return|return
name|pN
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|Binomial
operator|::
name|n
argument_list|(
argument|int xn
argument_list|)
block|{
name|int
name|tmp
operator|=
name|pN
block|;
name|pN
operator|=
name|xn
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|Binomial
operator|::
name|u
argument_list|()
block|{
return|return
name|pU
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|Binomial
operator|::
name|u
argument_list|(
argument|double xu
argument_list|)
block|{
name|double
name|tmp
operator|=
name|pU
block|;
name|pU
operator|=
name|xu
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

