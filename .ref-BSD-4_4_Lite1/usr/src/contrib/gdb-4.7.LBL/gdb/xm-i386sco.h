begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for i386, running SCO Unix System V/386 3.2.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"xm-i386v.h"
end_include

begin_comment
comment|/* Apparently there is inconsistency among various System V's about what    the name of this field is.  */
end_comment

begin_define
define|#
directive|define
name|U_FPSTATE
parameter_list|(
name|u
parameter_list|)
value|u.u_fps.u_fpstate
end_define

begin_comment
comment|/* TIOCGETC is defined in System V 3.2 termio.h, but struct tchars    is not.  This makes problems for inflow.c.  */
end_comment

begin_define
define|#
directive|define
name|TIOCGETC_BROKEN
end_define

begin_comment
comment|/* All the job control definitions exist in SCO Unix, but the standard    shells don't use them.  So we must disable job control. */
end_comment

begin_comment
comment|/* This is no longer true with 3.2v2 and later */
end_comment

begin_comment
comment|/* #define NO_JOB_CONTROL */
end_comment

begin_comment
comment|/* SCO's assembler doesn't grok dollar signs in identifiers.    So we use dots instead.  This item must be coordinated with G++. */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUS_MARKER
end_undef

begin_define
define|#
directive|define
name|CPLUS_MARKER
value|'.'
end_define

begin_define
define|#
directive|define
name|HAVE_STRSTR
end_define

begin_comment
comment|/* Use setpgid instead of setpgrp on SCO */
end_comment

begin_define
define|#
directive|define
name|NEED_POSIX_SETPGID
end_define

end_unit

