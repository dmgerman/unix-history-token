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
name|_Random_h
end_ifndef

begin_define
define|#
directive|define
name|_Random_h
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
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<RNG.h>
end_include

begin_decl_stmt
name|class
name|Random
block|{
name|protected
label|:
name|RNG
modifier|*
name|pGenerator
decl_stmt|;
name|public
label|:
name|Random
argument_list|(
name|RNG
operator|*
name|generator
argument_list|)
expr_stmt|;
name|virtual
name|double
name|operator
argument_list|()
argument_list|()
operator|=
literal|0
expr_stmt|;
name|RNG
modifier|*
name|generator
parameter_list|()
function_decl|;
name|void
name|generator
parameter_list|(
name|RNG
modifier|*
name|p
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|Random
operator|::
name|Random
argument_list|(
argument|RNG *gen
argument_list|)
block|{
name|pGenerator
operator|=
name|gen
block|; }
specifier|inline
name|RNG
operator|*
name|Random
operator|::
name|generator
argument_list|()
block|{
return|return
operator|(
name|pGenerator
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Random
operator|::
name|generator
argument_list|(
argument|RNG *p
argument_list|)
block|{
name|pGenerator
operator|=
name|p
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

