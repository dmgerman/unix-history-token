begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC,    for i386/ELF NetBSD systems.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.    Contributed by matthew green<mrg@eterna.com.au>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       NETBSD_OS_CPP_BUILTINS_ELF();		\     }						\   while (0)
end_define

begin_comment
comment|/* Extra specs needed for NetBSD/i386 ELF.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "netbsd_cpp_spec", NETBSD_CPP_SPEC },	\   { "netbsd_entry_point", NETBSD_ENTRY_POINT },
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for a NetBSD/i386 ELF target.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|NETBSD_LINK_SPEC_ELF
end_define

begin_define
define|#
directive|define
name|NETBSD_ENTRY_POINT
value|"__start"
end_define

begin_comment
comment|/* Provide a CPP_SPEC appropriate for NetBSD.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(netbsd_cpp_spec)"
end_define

begin_comment
comment|/* Make gcc agree with<machine/ansi.h> */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
value|svr4_dbx_register_map[n]
end_define

begin_comment
comment|/* Output assembler code to FILE to call the profiler.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_PROFILE_COUNTERS
end_undef

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   if (flag_pic)								\     fprintf (FILE, "\tcall __mcount@PLT\n");				\   else									\     fprintf (FILE, "\tcall __mcount\n");				\ }
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|NAME1
parameter_list|,
name|NAME2
parameter_list|)
define|\
value|do { assemble_name(FILE, NAME1); 	 \        fputs(" = ", FILE);		 \        assemble_name(FILE, NAME2);	 \        fputc('\n', FILE); } while (0)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG) != 0) {							\     if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\     else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We always use gas here, so we don't worry about ECOFF assembler    problems.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_GAS
end_undef

begin_define
define|#
directive|define
name|TARGET_GAS
value|1
end_define

begin_comment
comment|/* Default to pcc-struct-return, because this is the ELF abi and    we don't care about compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|1
end_define

begin_comment
comment|/* Attempt to enable execute permissions on the stack.  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_EXECUTE_STACK
value|NETBSD_ENABLE_EXECUTE_STACK
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (NetBSD/i386 ELF)");
end_define

end_unit

