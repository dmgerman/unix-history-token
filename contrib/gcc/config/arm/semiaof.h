begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM on semi-hosted platform    AOF Syntax assembler.    Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (richard.earnshaw@armltd.co.uk)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Darm -Dsemi"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{g -g} -arch 4 \ -apcs 3%{mapcs-32:/32bit}%{mapcs-26:/26bit}%{!mapcs-26:%{!macps-32:/32bit}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{Eb: armlib_h.32b%s}%{!Eb: armlib_h.32l%s}"
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/semi-hosted)", stderr);
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|ARM_FLAG_APCS_32
end_define

begin_comment
comment|/* The Norcroft C library defines size_t as "unsigned int" */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|CPP_APCS_PC_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_APCS_PC_DEFAULT_SPEC
value|"-D__APCS_32__"
end_define

end_unit

