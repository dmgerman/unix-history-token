begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* malloc_.h */
end_comment

begin_comment
comment|/* Generic substitute for Unix malloc.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_include
include|#
directive|include
file|<alloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|||
name|defined
argument_list|(
name|apollo
argument_list|)
operator|||
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|sequent
argument_list|)
operator|||
name|defined
argument_list|(
name|UTEK
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_HPUX_SOURCE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__386BSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HPUX_SOURCE, ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BSD4_2, ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__TURBOC__ */
end_comment

end_unit

