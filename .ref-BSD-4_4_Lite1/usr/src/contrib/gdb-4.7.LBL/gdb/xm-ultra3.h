begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host definitions for GDB running on a 29k NYU Ultracomputer    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.    Contributed by David Wood (wood@lab.ultra.nyu.edu).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Here at NYU we have what we call an ULTRA3 PE board.  So    ifdefs for ULTRA3 are my doing.  At this point in time,    I don't know of any other Unixi running on the 29k.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|L_SET
end_ifndef

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_comment
comment|/* set the seek pointer */
end_comment

begin_define
define|#
directive|define
name|L_INCR
value|1
end_define

begin_comment
comment|/* increment the seek pointer */
end_comment

begin_define
define|#
directive|define
name|L_XTND
value|2
end_define

begin_comment
comment|/* extend the file size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* System doesn't provide siginterrupt().  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_comment
comment|/* System uses a `short' to hold a process group ID.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_PGRP
end_define

end_unit

