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
name|_MLCG_h
end_ifndef

begin_define
define|#
directive|define
name|_MLCG_h
value|1
end_define

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

begin_include
include|#
directive|include
file|<RNG.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|//	Multiplicative Linear Conguential Generator
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|MLCG
range|:
name|public
name|RNG
block|{
name|long
name|initialSeedOne
block|;
name|long
name|initialSeedTwo
block|;
name|long
name|seedOne
block|;
name|long
name|seedTwo
block|;
name|protected
operator|:
name|public
operator|:
name|MLCG
argument_list|(
argument|long seed1 =
literal|0
argument_list|,
argument|long seed2 =
literal|1
argument_list|)
block|;
comment|//
comment|// Return a long-words word of random bits
comment|//
name|virtual
name|unsigned
name|long
name|asLong
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|long
name|seed1
argument_list|()
block|;
name|void
name|seed1
argument_list|(
name|long
argument_list|)
block|;
name|long
name|seed2
argument_list|()
block|;
name|void
name|seed2
argument_list|(
name|long
argument_list|)
block|;
name|void
name|reseed
argument_list|(
name|long
argument_list|,
name|long
argument_list|)
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
name|long
name|MLCG
operator|::
name|seed1
argument_list|()
block|{
return|return
operator|(
name|seedOne
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|MLCG
operator|::
name|seed1
argument_list|(
argument|long s
argument_list|)
block|{
name|initialSeedOne
operator|=
name|s
block|;
name|reset
argument_list|()
block|; }
specifier|inline
name|long
name|MLCG
operator|::
name|seed2
argument_list|()
block|{
return|return
operator|(
name|seedTwo
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|MLCG
operator|::
name|seed2
argument_list|(
argument|long s
argument_list|)
block|{
name|initialSeedTwo
operator|=
name|s
block|;
name|reset
argument_list|()
block|; }
specifier|inline
name|void
name|MLCG
operator|::
name|reseed
argument_list|(
argument|long s1
argument_list|,
argument|long s2
argument_list|)
block|{
name|initialSeedOne
operator|=
name|s1
block|;
name|initialSeedTwo
operator|=
name|s2
block|;
name|reset
argument_list|()
block|; }
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

