begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for hosting on an PowerPC, for GDB, the GNU debugger.    Copyright 1995 Free Software Foundation, Inc.    Contributed by Cygnus Corporation.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The following text is taken from config/rs6000.mh:  * # The IBM version of /usr/include/rpc/rpc.h has a bug -- it says  * # `extern fd_set svc_fdset;' without ever defining the type fd_set.  * # Unfortunately this occurs in the vx-share code, which is not configured  * # like the rest of GDB (e.g. it doesn't include "defs.h").  * # We circumvent this bug by #define-ing fd_set here, but undefining it in  * # the xm-rs6000.h file before ordinary modules try to use it.  FIXME, IBM!  * MH_CFLAGS='-Dfd_set=int'  * So, here we do the undefine...which has to occur before we include  *<sys/select.h> below.  */
end_comment

begin_undef
undef|#
directive|undef
name|fd_set
end_undef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* Big end is at the low address */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* At least as of AIX 3.2, we have termios.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS
value|1
end_define

begin_comment
comment|/* #define HAVE_TERMIO 1 */
end_comment

begin_define
define|#
directive|define
name|USG
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

begin_define
define|#
directive|define
name|FIVE_ARG_PTRACE
end_define

begin_comment
comment|/* AIX declares the mem functions differently than defs.h does.  AIX is    right, but defs.h works on more old systems.  For now, override it.  */
end_comment

begin_define
define|#
directive|define
name|MEM_FNS_DECLARED
value|1
end_define

begin_comment
comment|/* This system requires that we open a terminal with O_NOCTTY for it to    not become our controlling terminal.  */
end_comment

begin_define
define|#
directive|define
name|USE_O_NOCTTY
end_define

begin_comment
comment|/* Brain death inherited from PC's pervades.  */
end_comment

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/* The IBM compiler requires this in order to properly compile alloca().  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_comment
comment|/* There is no vfork.  */
end_comment

begin_define
define|#
directive|define
name|vfork
value|fork
end_define

begin_comment
comment|/* Signal handler for SIGWINCH `window size changed'. */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH_HANDLER
value|aix_resizewindow
end_define

begin_function_decl
specifier|extern
name|void
name|aix_resizewindow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* `lines_per_page' and `chars_per_line' are local to utils.c. Rectify this. */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH_HANDLER_BODY
define|\ 									\
comment|/* Respond to SIGWINCH `window size changed' signal, and reset GDB's	\    window settings approproatelt. */
define|\ 									\
value|void 						\ aix_resizewindow ()				\ {						\   int fd = fileno (stdout);			\   if (isatty (fd)) {				\     int val;					\ 						\     val = atoi (termdef (fd, 'l'));		\     if (val> 0)				\       lines_per_page = val;			\     val = atoi (termdef (fd, 'c'));		\     if (val> 0)				\       chars_per_line = val;			\   }						\ }
end_define

end_unit

