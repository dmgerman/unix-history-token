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
name|_Weibull_h
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
name|_Weibull_h
end_define

begin_include
include|#
directive|include
file|<Random.h>
end_include

begin_decl_stmt
name|class
name|Weibull
range|:
name|public
name|Random
block|{
name|protected
operator|:
name|double
name|pAlpha
block|;
name|double
name|pInvAlpha
block|;
name|double
name|pBeta
block|;
name|void
name|setState
argument_list|()
block|;
name|public
operator|:
name|Weibull
argument_list|(
argument|double alpha
argument_list|,
argument|double beta
argument_list|,
argument|RNG *gen
argument_list|)
block|;
name|double
name|alpha
argument_list|()
block|;
name|double
name|alpha
argument_list|(
argument|double x
argument_list|)
block|;
name|double
name|beta
argument_list|()
block|;
name|double
name|beta
argument_list|(
argument|double x
argument_list|)
block|;
name|virtual
name|double
name|operator
argument_list|()
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|void
name|Weibull
operator|::
name|setState
argument_list|()
block|{
name|pInvAlpha
operator|=
literal|1.0
operator|/
name|pAlpha
block|; }
specifier|inline
name|Weibull
operator|::
name|Weibull
argument_list|(
argument|double alpha
argument_list|,
argument|double beta
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
name|Random
argument_list|(
argument|gen
argument_list|)
block|{
name|pAlpha
operator|=
name|alpha
block|;
name|pBeta
operator|=
name|beta
block|;
name|setState
argument_list|()
block|; }
specifier|inline
name|double
name|Weibull
operator|::
name|alpha
argument_list|()
block|{
return|return
name|pAlpha
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|Weibull
operator|::
name|alpha
argument_list|(
argument|double x
argument_list|)
block|{
name|double
name|tmp
operator|=
name|pAlpha
block|;
name|pAlpha
operator|=
name|x
block|;
name|setState
argument_list|()
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|Weibull
operator|::
name|beta
argument_list|()
block|{
return|return
name|pBeta
return|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|double
name|Weibull
operator|::
name|beta
argument_list|(
argument|double x
argument_list|)
block|{
name|double
name|tmp
operator|=
name|pBeta
block|;
name|pBeta
operator|=
name|x
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

