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
argument|int xu
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
operator|(
name|gen
operator|)
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
argument|int xu
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

