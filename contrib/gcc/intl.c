begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Message translation utilities.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"intl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_comment
comment|/* Initialize the translation library for GCC.  This performs the    appropriate sequence of calls - setlocale, bindtextdomain,    textdomain.  LC_CTYPE determines the character set used by the    terminal, so it has be set to output messages correctly.  */
end_comment

begin_function
name|void
name|gcc_init_libintl
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_LC_MESSAGES
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|setlocale
argument_list|(
name|LC_MESSAGES
argument_list|,
literal|""
argument_list|)
expr_stmt|;
else|#
directive|else
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|bindtextdomain
argument_list|(
literal|"gcc"
argument_list|,
name|LOCALEDIR
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|textdomain
argument_list|(
literal|"gcc"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

