begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running SCO Unix System V.    Copyright (C) 1988, 92, 94, 95, 96, 1999  Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Mostly it's like AT&T Unix System V. */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv3.h"
end_include

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387, ie,    (TARGET_80387 | TARGET_FLOAT_RETURNS_IN_80387)     SCO's software emulation of a 387 fails to handle the `fucomp'    opcode.  fucomp is only used when generating IEEE compliant code.    So don't make TARGET_IEEE_FP default for SCO. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_80387 | MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/* Let's guess that the SCO software FPU emulator can't handle    80-bit XFmode insns, so don't generate them.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
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
value|"%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Library spec, including SCO international language support. */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp} %{scointl:libintl.a%s} -lc"
end_define

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -DM_UNIX -DM_I386 -DM_COFF -DM_WORDSWAP -Asystem(svr3)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{scointl:-DM_INTERNAT}"
end_define

begin_comment
comment|/* This spec is used for telling cpp whether char is signed or not.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIGNED_CHAR_SPEC
end_undef

begin_if
if|#
directive|if
name|DEFAULT_SIGNED_CHAR
end_if

begin_define
define|#
directive|define
name|SIGNED_CHAR_SPEC
define|\
value|"%{funsigned-char:-D__CHAR_UNSIGNED__ -D_CHAR_UNSIGNED}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGNED_CHAR_SPEC
define|\
value|"%{!fsigned-char:-D__CHAR_UNSIGNED__ -D_CHAR_UNSIGNED}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use atexit for static destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Specify the size_t type.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Not yet certain whether this is needed.  */
end_comment

begin_comment
comment|/* If no 387, use the general regs to return floating values,    since this system does not emulate the 80387.  */
end_comment

begin_undef
undef|#
directive|undef
name|VALUE_REGNO
end_undef

begin_define
define|#
directive|define
name|VALUE_REGNO
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((TARGET_80387
end_define

begin_undef
unit|&& ((MODE) == SFmode || (MODE) == DFmode || (MODE) == XFmode)    ? FIRST_FLOAT_REG : 0)
undef|#
directive|undef
name|HARD_REGNO_MODE_OK
end_undef

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((REGNO)< 2 ? 1							  \    : (REGNO)< 4 ? 1							  \    : FP_REGNO_P (REGNO) ? ((GET_MODE_CLASS (MODE) == MODE_FLOAT		  \                           || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT) \&& TARGET_80387				  \&& GET_MODE_UNIT_SIZE (MODE)<= 8)		  \    : (MODE) != QImode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* caller has to pop the extra argument passed to functions that return    structures. */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_POPS_ARGS
end_undef

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((FUNDECL)&& TREE_CODE (FUNDECL) == IDENTIFIER_NODE ? 0	\    : (TARGET_RTD						\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\ 	  || (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\ 	      == void_type_node))) ? (SIZE)			\    : 0)
end_define

begin_comment
comment|/* On other 386 systems, the last line looks like this:    : (aggregate_value_p (TREE_TYPE (FUNTYPE))) ? GET_MODE_SIZE (Pmode) : 0)  */
end_comment

begin_comment
comment|/* Handle #pragma pack. */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

end_unit

