begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_comment
comment|/* Unfortunately vendors seem to have problems writing a<signal.h> that is correct for C++, so we implement all signal handling in C. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|RETSIGTYPE
name|handle_fatal_signal
parameter_list|(
name|signum
parameter_list|)
name|int
name|signum
decl_stmt|;
block|{
name|signal
argument_list|(
name|signum
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|signum
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|catch_fatal_signals
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SIGHUP
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|handle_fatal_signal
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|handle_fatal_signal
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|handle_fatal_signal
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RENAME
end_ifndef

begin_function
name|void
name|ignore_fatal_signals
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SIGHUP
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_RENAME */
end_comment

end_unit

