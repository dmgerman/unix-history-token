begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running system Vr4.    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by James Van Artsdalen, Dell Computer Corporation.    james@bigtex.cactus.org */
end_comment

begin_include
include|#
directive|include
file|"tm-i386v.h"
end_include

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
end_define

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} %{pg:gcrti.o%s}%{!pg:%{p:mcrti.o%s}%{!p:crti.o%s}} values-Xt.o%s"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} -Y P,/usr/ccs/lib:/usr/lib -Qy -lc crtn.o%s"
end_define

begin_comment
comment|/* Brain-damaged v4 include files won't work right if __STDC__ != 0 */
end_comment

begin_define
define|#
directive|define
name|STDC_VALUE
value|0
end_define

begin_comment
comment|/* We do not want to output SDB debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {								\     char *p = (char *) strrchr(main_input_filename, '/');	\     if (!p++)							\       p = main_input_filename;					\     fprintf ((FILE), "\t.file\t\"%s\"\n", p);			\   } while (0)
end_define

end_unit

