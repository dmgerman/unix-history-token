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
name|_Random_h
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
file|<math.h>
end_include

begin_include
include|#
directive|include
file|"RNG.h"
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

