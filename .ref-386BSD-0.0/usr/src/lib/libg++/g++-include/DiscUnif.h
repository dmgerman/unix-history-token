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
name|_DiscreteUniform_h
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
name|_DiscreteUniform_h
value|1
end_define

begin_include
include|#
directive|include
file|<Random.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|//	The interval [lo..hi)
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|DiscreteUniform
range|:
name|public
name|Random
block|{
name|long
name|pLow
block|;
name|long
name|pHigh
block|;
name|double
name|delta
block|;
name|public
operator|:
name|DiscreteUniform
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
block|;
name|long
name|low
argument_list|()
block|;
name|long
name|low
argument_list|(
argument|long x
argument_list|)
block|;
name|long
name|high
argument_list|()
block|;
name|long
name|high
argument_list|(
argument|long x
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
name|DiscreteUniform
operator|::
name|DiscreteUniform
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
operator|(
name|gen
operator|)
block|{
name|pLow
operator|=
operator|(
name|low
operator|<
name|high
operator|)
operator|?
name|low
operator|:
name|high
block|;
name|pHigh
operator|=
operator|(
name|low
operator|<
name|high
operator|)
condition|?
name|high
else|:
name|low
block|;
name|delta
operator|=
operator|(
name|pHigh
operator|-
name|pLow
operator|)
operator|+
literal|1
block|; }
specifier|inline
name|long
name|DiscreteUniform
operator|::
name|low
argument_list|()
block|{
return|return
name|pLow
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|DiscreteUniform
operator|::
name|low
argument_list|(
argument|long x
argument_list|)
block|{
name|long
name|tmp
operator|=
name|pLow
block|;
name|pLow
operator|=
name|x
block|;
name|delta
operator|=
operator|(
name|pHigh
operator|-
name|pLow
operator|)
operator|+
literal|1
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|DiscreteUniform
operator|::
name|high
argument_list|()
block|{
return|return
name|pHigh
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|DiscreteUniform
operator|::
name|high
argument_list|(
argument|long x
argument_list|)
block|{
name|long
name|tmp
operator|=
name|pHigh
block|;
name|pHigh
operator|=
name|x
block|;
name|delta
operator|=
operator|(
name|pHigh
operator|-
name|pLow
operator|)
operator|+
literal|1
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

