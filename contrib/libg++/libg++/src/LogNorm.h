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
name|_LogNormal_h
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
name|_LogNormal_h
end_define

begin_include
include|#
directive|include
file|<Normal.h>
end_include

begin_decl_stmt
name|class
name|LogNormal
range|:
name|public
name|Normal
block|{
name|protected
operator|:
name|double
name|logMean
block|;
name|double
name|logVariance
block|;
name|void
name|setState
argument_list|()
block|;
name|public
operator|:
name|LogNormal
argument_list|(
argument|double mean
argument_list|,
argument|double variance
argument_list|,
argument|RNG *gen
argument_list|)
block|;
name|double
name|mean
argument_list|()
block|;
name|double
name|mean
argument_list|(
argument|double x
argument_list|)
block|;
name|double
name|variance
argument_list|()
block|;
name|double
name|variance
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
name|LogNormal
operator|::
name|setState
argument_list|()
block|{
name|double
name|m2
operator|=
name|logMean
operator|*
name|logMean
block|;
name|pMean
operator|=
name|log
argument_list|(
name|m2
operator|/
name|sqrt
argument_list|(
name|logVariance
operator|+
name|m2
argument_list|)
argument_list|)
block|;
comment|// from ch@heike.informatik.uni-dortmund.de:
comment|// (was   pVariance = log((sqrt(logVariance + m2)/m2 )); )
name|pStdDev
operator|=
name|sqrt
argument_list|(
name|log
argument_list|(
operator|(
name|logVariance
operator|+
name|m2
operator|)
operator|/
name|m2
argument_list|)
argument_list|)
block|;  }
specifier|inline
name|LogNormal
operator|::
name|LogNormal
argument_list|(
argument|double mean
argument_list|,
argument|double variance
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
name|Normal
argument_list|(
argument|mean
argument_list|,
argument|variance
argument_list|,
argument|gen
argument_list|)
block|{
name|logMean
operator|=
name|mean
block|;
name|logVariance
operator|=
name|variance
block|;
name|setState
argument_list|()
block|; }
specifier|inline
name|double
name|LogNormal
operator|::
name|mean
argument_list|()
block|{
return|return
name|logMean
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|LogNormal
operator|::
name|mean
argument_list|(
argument|double x
argument_list|)
block|{
name|double
name|t
operator|=
name|logMean
block|;
name|logMean
operator|=
name|x
block|;
name|setState
argument_list|()
block|;
return|return
name|t
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|LogNormal
operator|::
name|variance
argument_list|()
block|{
return|return
name|logVariance
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|double
name|LogNormal
operator|::
name|variance
argument_list|(
argument|double x
argument_list|)
block|{
name|double
name|t
operator|=
name|logVariance
block|;
name|logVariance
operator|=
name|x
block|;
name|setState
argument_list|()
block|;
return|return
name|t
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

