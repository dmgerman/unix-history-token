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
name|_G_int32_t
name|initialSeedOne
block|;
name|_G_int32_t
name|initialSeedTwo
block|;
name|_G_int32_t
name|seedOne
block|;
name|_G_int32_t
name|seedTwo
block|;
name|protected
operator|:
name|public
operator|:
name|MLCG
argument_list|(
argument|_G_int32_t seed1 =
literal|0
argument_list|,
argument|_G_int32_t seed2 =
literal|1
argument_list|)
block|;
comment|//
comment|// Return a long-words word of random bits
comment|//
name|virtual
name|_G_uint32_t
name|asLong
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|_G_int32_t
name|seed1
argument_list|()
block|;
name|void
name|seed1
argument_list|(
name|_G_int32_t
argument_list|)
block|;
name|_G_int32_t
name|seed2
argument_list|()
block|;
name|void
name|seed2
argument_list|(
name|_G_int32_t
argument_list|)
block|;
name|void
name|reseed
argument_list|(
name|_G_int32_t
argument_list|,
name|_G_int32_t
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|_G_int32_t
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
argument|_G_int32_t s
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
name|_G_int32_t
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
argument|_G_int32_t s
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
argument|_G_int32_t s1
argument_list|,
argument|_G_int32_t s2
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

end_unit

