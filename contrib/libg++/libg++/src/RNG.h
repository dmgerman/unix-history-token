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
name|_RNG_h
end_ifndef

begin_define
define|#
directive|define
name|_RNG_h
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
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_union
union|union
name|PrivateRNGSingleType
block|{
comment|// used to access floats as unsigneds
name|float
name|s
decl_stmt|;
name|_G_uint32_t
name|u
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|PrivateRNGDoubleType
block|{
comment|// used to access doubles as unsigneds
name|double
name|d
decl_stmt|;
name|_G_uint32_t
name|u
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|//
end_comment

begin_comment
comment|// Base class for Random Number Generators. See ACG and MLCG for instances.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|RNG
block|{
specifier|static
name|PrivateRNGSingleType
name|singleMantissa
decl_stmt|;
comment|// mantissa bit vector
specifier|static
name|PrivateRNGDoubleType
name|doubleMantissa
decl_stmt|;
comment|// mantissa bit vector
name|public
label|:
name|RNG
argument_list|()
expr_stmt|;
comment|//
comment|// Return a long-words word of random bits
comment|//
name|virtual
name|_G_uint32_t
name|asLong
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|reset
parameter_list|()
init|=
literal|0
function_decl|;
comment|//
comment|// Return random bits converted to either a float or a double
comment|//
name|float
name|asFloat
parameter_list|()
function_decl|;
name|double
name|asDouble
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

