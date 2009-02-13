begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992, 2001, 2003, 2004 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin St - Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

begin_comment
comment|/* Unfortunately vendors seem to have problems writing a<signal.h> that is correct for C++, so we implement all signal handling in C. */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|void
name|cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|RETSIGTYPE
name|handle_fatal_signal
parameter_list|(
name|int
name|signum
parameter_list|)
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
ifdef|#
directive|ifdef
name|HAVE_KILL
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|signum
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* MS-DOS and Win32 don't have kill(); the best compromise is      probably to use exit() instead. */
name|exit
argument_list|(
name|signum
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|void
name|catch_fatal_signals
parameter_list|(
name|void
parameter_list|)
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
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

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

