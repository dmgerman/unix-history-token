begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1990 Free Software Foundation     adapted from a submission from John Reidl<riedl@cs.purdue.edu>   GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RandomInteger_h
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
name|_RandomInteger_h
value|1
end_define

begin_comment
comment|// RandomInteger uses a random number generator to generate an integer
end_comment

begin_comment
comment|// in a specified range.  By default the range is 0..1.  Since in my
end_comment

begin_comment
comment|// experience random numbers are often needed for a wide variety of
end_comment

begin_comment
comment|// ranges in the same program, this generator accepts a new low or high value
end_comment

begin_comment
comment|// as an argument to the asLong and operator() methods to temporarily
end_comment

begin_comment
comment|// override stored values
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<RNG.h>
end_include

begin_decl_stmt
name|class
name|RandomInteger
block|{
name|protected
label|:
name|RNG
modifier|*
name|pGenerator
decl_stmt|;
name|long
name|pLow
decl_stmt|;
name|long
name|pHigh
decl_stmt|;
name|long
name|_asLong
parameter_list|(
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
name|public
label|:
name|RandomInteger
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
empty_stmt|;
name|RandomInteger
argument_list|(
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
empty_stmt|;
name|RandomInteger
argument_list|(
name|RNG
operator|*
name|gen
argument_list|)
expr_stmt|;
comment|// read params
name|long
name|low
argument_list|()
specifier|const
expr_stmt|;
name|long
name|high
argument_list|()
specifier|const
expr_stmt|;
name|RNG
operator|*
name|generator
argument_list|()
specifier|const
expr_stmt|;
comment|// change params
name|long
name|low
parameter_list|(
name|long
name|x
parameter_list|)
function_decl|;
name|long
name|high
parameter_list|(
name|long
name|x
parameter_list|)
function_decl|;
name|RNG
modifier|*
name|generator
parameter_list|(
name|RNG
modifier|*
name|gen
parameter_list|)
function_decl|;
comment|// get a random number
name|long
name|asLong
parameter_list|()
function_decl|;
name|long
name|operator
argument_list|()
argument_list|()
expr_stmt|;
comment|// synonym for asLong
name|int
name|asInt
parameter_list|()
function_decl|;
comment|// (possibly) truncate as int
comment|// override params for one shot
name|long
name|asLong
parameter_list|(
name|long
name|high
parameter_list|)
function_decl|;
name|long
name|asLong
parameter_list|(
name|long
name|low
parameter_list|,
name|long
name|high
parameter_list|)
function_decl|;
name|long
name|operator
argument_list|()
operator|(
name|long
name|high
operator|)
expr_stmt|;
comment|// synonyms
name|long
name|operator
argument_list|()
operator|(
name|long
name|low
operator|,
name|long
name|high
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|RandomInteger
operator|::
name|RandomInteger
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
name|pGenerator
argument_list|(
name|gen
argument_list|)
operator|,
name|pLow
argument_list|(
operator|(
name|low
operator|<
name|high
operator|)
condition|?
name|low
else|:
name|high
argument_list|)
operator|,
name|pHigh
argument_list|(
argument|(low< high) ? high : low
argument_list|)
block|{}
specifier|inline
name|RandomInteger
operator|::
name|RandomInteger
argument_list|(
argument|long high
argument_list|,
argument|RNG *gen
argument_list|)
operator|:
name|pGenerator
argument_list|(
name|gen
argument_list|)
operator|,
name|pLow
argument_list|(
operator|(
literal|0
operator|<
name|high
operator|)
condition|?
literal|0
else|:
name|high
argument_list|)
operator|,
name|pHigh
argument_list|(
argument|(
literal|0
argument|< high) ? high :
literal|0
argument_list|)
block|{}
specifier|inline
name|RandomInteger
operator|::
name|RandomInteger
argument_list|(
name|RNG
operator|*
name|gen
argument_list|)
operator|:
name|pGenerator
argument_list|(
name|gen
argument_list|)
operator|,
name|pLow
argument_list|(
literal|0
argument_list|)
operator|,
name|pHigh
argument_list|(
literal|1
argument_list|)
block|{}
specifier|inline
name|RNG
operator|*
name|RandomInteger
operator|::
name|generator
argument_list|()
specifier|const
block|{
return|return
name|pGenerator
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|low
argument_list|()
specifier|const
block|{
return|return
name|pLow
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|high
argument_list|()
specifier|const
block|{
return|return
name|pHigh
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|RNG
operator|*
name|RandomInteger
operator|::
name|generator
argument_list|(
argument|RNG *gen
argument_list|)
block|{
name|RNG
operator|*
name|tmp
operator|=
name|pGenerator
block|;
name|pGenerator
operator|=
name|gen
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
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
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
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
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|_asLong
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|)
block|{
return|return
operator|(
name|pGenerator
operator|->
name|asLong
argument_list|()
operator|%
operator|(
name|high
operator|-
name|low
operator|+
literal|1
operator|)
operator|)
operator|+
name|low
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|asLong
argument_list|()
block|{
return|return
name|_asLong
argument_list|(
name|pLow
argument_list|,
name|pHigh
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|asLong
argument_list|(
argument|long high
argument_list|)
block|{
return|return
name|_asLong
argument_list|(
name|pLow
argument_list|,
name|high
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|asLong
argument_list|(
argument|long low
argument_list|,
argument|long high
argument_list|)
block|{
return|return
name|_asLong
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|operator
argument_list|()
operator|(
operator|)
block|{
return|return
name|_asLong
argument_list|(
name|pLow
argument_list|,
name|pHigh
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|operator
argument_list|()
operator|(
name|long
name|high
operator|)
block|{
return|return
name|_asLong
argument_list|(
name|pLow
argument_list|,
name|high
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|long
name|RandomInteger
operator|::
name|operator
argument_list|()
operator|(
name|long
name|low
operator|,
name|long
name|high
operator|)
block|{
return|return
name|_asLong
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|int
name|RandomInteger
operator|::
name|asInt
argument_list|()
block|{
return|return
name|int
argument_list|(
name|asLong
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

