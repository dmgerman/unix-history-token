begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Signal handler definitions for GDB, the GNU Debugger.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  This file is almost the same as including<signal.h> except that it     eliminates certain signal names when job control is not supported,     (or, on some systems, when job control is there but doesn't work     the way GDB expects it to work).  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NO_JOB_CONTROL
end_ifdef

begin_undef
undef|#
directive|undef
name|SIGTSTP
end_undef

begin_undef
undef|#
directive|undef
name|SIGSTOP
end_undef

begin_undef
undef|#
directive|undef
name|SIGCONT
end_undef

begin_undef
undef|#
directive|undef
name|SIGTTIN
end_undef

begin_undef
undef|#
directive|undef
name|SIGTTOU
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

