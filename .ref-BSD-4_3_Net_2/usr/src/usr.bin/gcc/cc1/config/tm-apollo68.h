begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Apollo 680X0 version.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m68k.h"
end_include

begin_comment
comment|/* This symbol may be tested in other files for special Apollo handling */
end_comment

begin_define
define|#
directive|define
name|TM_APOLLO
end_define

begin_comment
comment|/* See tm-m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target switches for the Apollo is the same as in tm-m68k.h, except    there is no Sun FPA. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "68020", 5},				\     { "c68020", 5},				\     { "68881", 2},				\     { "bitfield", 4},				\     { "68000", -5},				\     { "c68000", -5},				\     { "soft-float", -0102},			\     { "nobitfield", -4},			\     { "rtd", 8},				\     { "nortd", -8},				\     { "short", 040},				\     { "noshort", -040},				\     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor,    according to the -m flags.    This will control the use of inline 68881 insns in certain macros.    Also inform the program which CPU this is for.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|02
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:%{mfpa:-D__HAVE_FPA__ }%{!mfpa:-D__HAVE_68881__ }}\ %{!ansi:%{m68000:-Dmc68010 }%{mc68000:-Dmc68010 }%{!mc68000:%{!m68000:-Dmc68020 }}\ %{!ansi:-D_APOLLO_SOURCE}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{m68881:-D__HAVE_68881__ }%{mfpa:-D__HAVE_FPA__ }\ %{!ansi:%{m68000:-Dmc68010 }%{mc68000:-Dmc68010 }%{!mc68000:%{!m68000:-Dmc68020 }}\ %{!ansi:-D_APOLLO_SOURCE}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_comment
comment|/* These are the ones defined by Apollo, plus mc68000 for uniformity with    GCC on other 68000 systems.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dapollo -Daegis -Dunix"
end_define

begin_comment
comment|/* cpp has to support a #sccs directive for the /usr/include files */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Allow #ident but output nothing for it.  */
end_comment

begin_define
define|#
directive|define
name|IDENT_DIRECTIVE
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
end_define

begin_comment
comment|/* Allow dollarsigns in identifiers */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|1
end_define

begin_comment
comment|/* -m68000 requires special flags to the assembler.    The -C flag is passed to a modified GNU assembler to cause COFF    modules to be produced.  Remove it if you're not using this.    (See vasta@apollo.com.)  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"-C %{m68000:-mc68010}%{mc68000:-mc68010}%{!mc68000:%{!m68000:-mc68020}}"
end_define

begin_comment
comment|/* STARTFILE_SPEC    Note that includes knowledge of the default specs for gcc, ie. no    args translates to the same effect as -m68881 */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|2
end_if

begin_comment
comment|/* -m68881 is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Specify library to handle `-a' basic block profiling.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} \ %{a:/usr/lib/bb_link.o} "
end_define

begin_comment
comment|/* Debugging is not supported yet */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* Functions which return large structures get the address    to place the wanted value at offset 8 from the frame.  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_STATIC_STRUCT_RETURN
end_undef

begin_undef
undef|#
directive|undef
name|STRUCT_VALUE_REGNUM
end_undef

begin_comment
comment|/* Caller treats address of return area like a parm.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
define|\
value|gen_rtx (MEM, Pmode,					\ 	   gen_rtx (PLUS, SImode, frame_pointer_rtx,	\ 		    gen_rtx (CONST_INT, VOIDmode, 8)))
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_BOUNDARY
end_undef

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* Specify how to pad function arguments.    Arguments are not padded at all; the stack is kept aligned on long    boundaries. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|mode
parameter_list|,
name|size
parameter_list|)
value|none
end_define

begin_comment
comment|/* Short integral argument prototype promotion is not done */
end_comment

begin_undef
undef|#
directive|undef
name|PROMOTE_PROTOTYPES
end_undef

begin_comment
comment|/* The definition of this macro imposes a limit on the size of    an aggregate object which can be treated as if it were a scalar    object. */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.    For Apollo, anything larger than one integer register is returned    using the structure-value mechanism, i.e. objects of DFmode are    returned that way. */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|type
parameter_list|)
define|\
value|(GET_MODE_SIZE (TYPE_MODE (type))> UNITS_PER_WORD)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    In order to link to Apollo libraries, no underscore is prepended to names.    `assemble_name' uses this.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "%s", NAME)
end_define

end_unit

