begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Iris version.    Copyright (C) 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dmips -Dsgi -DSVR3 -Dhost_mips -DMIPSEB -DSYSTYPE_SYSV -DLANGUAGE_C"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} crtn.o%s"
end_define

begin_define
define|#
directive|define
name|SGI_TARGET
value|1
end_define

begin_comment
comment|/* inform other mips files this is SGI */
end_comment

begin_comment
comment|/* Always use 1 for .file number.  I [meissner@osf.org] wonder why    IRIS needs this.  */
end_comment

begin_define
define|#
directive|define
name|SET_FILE_NUMBER
parameter_list|()
value|num_source_filenames = 1
end_define

begin_comment
comment|/* Put out a label after a .loc.  I [meissner@osf.org] wonder why    IRIS needs this.  */
end_comment

begin_define
define|#
directive|define
name|LABEL_AFTER_LOC
parameter_list|(
name|STREAM
parameter_list|)
value|fprintf (STREAM, "LM%d:\n", ++sym_lineno)
end_define

begin_define
define|#
directive|define
name|STACK_ARGS_ADJUST
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|{                                                                       \   SIZE.constant += 4;                                                   \   if (SIZE.constant< 32)						\     SIZE.constant = 32;                                                 \ }
end_define

begin_include
include|#
directive|include
file|"tm-mips.h"
end_include

end_unit

