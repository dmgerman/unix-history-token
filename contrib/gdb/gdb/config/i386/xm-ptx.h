begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Sequent Symmetry under ptx, with    Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1992, 1993, 1996    Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Symmetry version by Jay Vosburgh (fubar@sequent.com) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_PTX4_
end_ifdef

begin_include
include|#
directive|include
file|"xm-sysv4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_PTX4_ */
end_comment

begin_comment
comment|/* This machine doesn't have the siginterrupt call.  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_undef
undef|#
directive|undef
name|HAVE_TERMIO
end_undef

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|NEED_POSIX_SETPGID
end_define

begin_define
define|#
directive|define
name|USE_O_NOCTTY
end_define

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

end_unit

