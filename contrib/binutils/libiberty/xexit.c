begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xexit.c -- Run any exit handlers, then exit.    Copyright (C) 1994, 95, 1997 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* This variable is set by xatexit if it is called.  This way, xmalloc    doesn't drag xatexit into the link.  */
end_comment

begin_macro
name|void
argument_list|(
argument|*_xexit_cleanup
argument_list|)
end_macro

begin_expr_stmt
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|xexit
parameter_list|(
name|code
parameter_list|)
name|int
name|code
decl_stmt|;
block|{
if|if
condition|(
name|_xexit_cleanup
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|_xexit_cleanup
call|)
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

