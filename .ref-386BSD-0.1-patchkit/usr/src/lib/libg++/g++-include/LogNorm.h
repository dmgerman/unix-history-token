begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Dirk Grunwald (grunwald@cs.uiuc.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
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
name|_LogNormal_h
end_define

begin_include
include|#
directive|include
file|"Normal.h"
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
name|pVariance
operator|=
name|log
argument_list|(
operator|(
name|sqrt
argument_list|(
name|logVariance
operator|+
name|m2
argument_list|)
operator|/
name|m2
operator|)
argument_list|)
block|; }
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
operator|(
name|mean
operator|,
name|variance
operator|,
name|gen
operator|)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

