begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Report a memory allocation failure and exit.     Copyright (C) 1997, 1998, 1999, 2000, 2002, 2003, 2004 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_function
name|void
name|xalloc_die
parameter_list|(
name|void
parameter_list|)
block|{
name|error
argument_list|(
name|exit_failure
argument_list|,
literal|0
argument_list|,
literal|"%s"
argument_list|,
name|_
argument_list|(
literal|"memory exhausted"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* The `noreturn' cannot be given to error, since it may return if      its first argument is 0.  To help compilers understand the      xalloc_die does not return, call abort.  Also, the abort is a      safety feature if exit_failure is 0 (which shouldn't happen).  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

