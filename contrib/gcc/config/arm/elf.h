begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    For ARM with ELF obj format.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Contributed by Philip Blundell<philb@gnu.org> and    Catherine Moore<clm@cygnus.com>     This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OBJECT_FORMAT_ELF
end_ifndef

begin_error
error|#
directive|error
error|elf.h included before elfos.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|"-D__ELF__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "subtarget_extra_asm_spec",	SUBTARGET_EXTRA_ASM_SPEC },
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{mbig-endian:-EB} \ %{mcpu=*:-m%*} \ %{march=*:-m%*} \ %{mapcs-*:-mapcs-%*} \ %{mapcs-float:-mfloat} \ %{msoft-float:-mno-fpu} \ %{mthumb-interwork:-mthumb-interwork} \ %(subtarget_extra_asm_spec)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The ARM uses @ are a comment character so we need to redefine    TYPE_OPERAND_FMT.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"%s"
end_define

begin_comment
comment|/* We might need a ARM specific header to function declarations.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do							\     {							\       ARM_DECLARE_FUNCTION_NAME (FILE, NAME, DECL);     \       fprintf (FILE, "%s", TYPE_ASM_OP);		\       assemble_name (FILE, NAME);			\       putc (',', FILE);					\       fprintf (FILE, TYPE_OPERAND_FMT, "function");	\       putc ('\n', FILE);				\       ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));	\       ASM_OUTPUT_LABEL(FILE, NAME);			\     }							\   while (0)
end_define

begin_comment
comment|/* We might need an ARM specific trailer for function declarations.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_SIZE
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|FNAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do								\     {								\       ARM_DECLARE_FUNCTION_SIZE (FILE, FNAME, DECL);		\       if (!flag_inhibit_size_directive)				\         {							\           char label[256];					\ 	  static int labelno;					\ 	  labelno ++;						\ 	  ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);	\ 	  ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);	\ 	  fprintf (FILE, "%s", SIZE_ASM_OP);			\ 	  assemble_name (FILE, (FNAME));			\           fprintf (FILE, ",");					\ 	  assemble_name (FILE, label);				\           fprintf (FILE, "-");					\ 	  assemble_name (FILE, (FNAME));			\ 	  putc ('\n', FILE);					\         }							\     }								\   while (0)
end_define

begin_comment
comment|/* Define this macro if jump tables (for `tablejump' insns) should be    output in the text section, along with the assembler instructions.    Otherwise, the readonly data section is used.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{mbig-endian:-EB} -X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (ARM/elf)", stderr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(ARM_FLAG_SOFT_FLOAT | ARM_FLAG_APCS_32 | ARM_FLAG_APCS_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_DEFAULTS
end_ifndef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
define|\
value|{ "marm", "mlittle-endian", "msoft-float", "mapcs-32", "mno-thumb-interwork", "fno-leading-underscore" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* This outputs a lot of .req's to define alias for various registers.    Let's try to avoid this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FILE_START
end_ifndef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do								\     {								\       fprintf (STREAM, "%s Generated by gcc %s for ARM/elf\n",	\ 	       ASM_COMMENT_START, version_string);		\       output_file_directive (STREAM, main_input_filename);	\       fprintf (STREAM, ASM_APP_OFF);				\     }								\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output an internal label definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|do								\     {								\       char * s = (char *) alloca (40 + strlen (PREFIX));	\       extern int arm_target_label, arm_ccfsm_state;		\       extern rtx arm_target_insn;				\ 								\       if (arm_ccfsm_state == 3&& arm_target_label == (NUM)	\&& !strcmp (PREFIX, "L"))				\ 	{							\ 	  arm_ccfsm_state = 0;					\ 	  arm_target_insn = NULL;				\ 	}							\       ASM_GENERATE_INTERNAL_LABEL (s, (PREFIX), (NUM));		\       ASM_OUTPUT_LABEL (STREAM, s);		                \     }								\   while (0)
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|arm_elf_asm_named_section
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do								\     {								\       fprintf (STREAM, "\t.comm\t");				\       assemble_name (STREAM, NAME);				\       fprintf (STREAM, ", %d, %d\n", SIZE, ALIGN);		\     }								\   while (0)
end_define

begin_comment
comment|/* For PIC code we need to explicitly specify (PLT) and (GOT) relocs.  */
end_comment

begin_define
define|#
directive|define
name|NEED_PLT_RELOC
value|flag_pic
end_define

begin_define
define|#
directive|define
name|NEED_GOT_RELOC
value|flag_pic
end_define

begin_comment
comment|/* The ELF assembler handles GOT addressing differently to NetBSD.  */
end_comment

begin_define
define|#
directive|define
name|GOT_PCREL
value|0
end_define

begin_comment
comment|/* Biggest alignment supported by the object file format of this    machine.  Use this macro to limit the alignment which can be    specified using the `__attribute__ ((aligned (N)))' construct.  If    not defined, the default value is `BIGGEST_ALIGNMENT'.  */
end_comment

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|(32768 * 8)
end_define

begin_comment
comment|/* Align output to a power of two.  Note ".align 0" is redundant,    and also GAS will treat it as ".align 2" which we do not want.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|do							\     {							\       if ((POWER)> 0)					\ 	fprintf (STREAM, "\t.align\t%d\n", POWER);	\     }							\   while (0)
end_define

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|1
end_define

end_unit

