begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Low level interface to ptrace, for GDB when running under Unix.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFLOW_H
end_ifndef

begin_define
define|#
directive|define
name|INFLOW_H
end_define

begin_include
include|#
directive|include
file|"terminal.h"
end_include

begin_comment
comment|/* For HAVE_TERMIOS et.al.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS
end_ifdef

begin_define
define|#
directive|define
name|PROCESS_GROUP_TYPE
value|pid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIO
end_ifdef

begin_define
define|#
directive|define
name|PROCESS_GROUP_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SGTTY
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_PGRP
end_ifdef

begin_comment
comment|/* This is only used for the ultra.  Does it have pid_t?  */
end_comment

begin_define
define|#
directive|define
name|PROCESS_GROUP_TYPE
value|short
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROCESS_GROUP_TYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgtty */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROCESS_GROUP_TYPE
end_ifdef

begin_comment
comment|/* Process group for us and the inferior.  Saved and restored just like    {our,inferior}_ttystate.  */
end_comment

begin_decl_stmt
specifier|extern
name|PROCESS_GROUP_TYPE
name|our_process_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PROCESS_GROUP_TYPE
name|inferior_process_group
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

