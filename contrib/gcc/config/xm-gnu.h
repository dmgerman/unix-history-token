begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for hosts running GNU.    Copyright (C) 1994, 1995, 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file defines machine-independent things specific to a host    running GNU.  This file should not be specified as $xm_file itself;    instead $xm_file should be CPU/xm-gnu.h, which should include both    CPU/xm-CPU.h and this file xm-gnu.h.  */
end_comment

begin_define
define|#
directive|define
name|POSIX
end_define

begin_comment
comment|/* GNU complies to POSIX.1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|inhibit_libc
end_ifndef

begin_comment
comment|/* Get a definition of O_RDONLY; some of the GCC files don't include this    properly and will define it themselves to be zero. */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

