begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of various defaults for how to do assembler output    (most of which are designed to be appropriate for GAS or for    some BSD assembler).    Copyright (C) 1992, 1996, 1997, 1998 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable or function named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FORMAT_PRIVATE_NAME
end_ifndef

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|do {									\     int len = strlen (NAME);						\     char *temp = (char *) alloca (len + 3);				\     temp[0] = 'L';							\     strcpy (&temp[1], (NAME));						\     temp[len + 1] = '.';						\     temp[len + 2] = 0;							\     (OUTPUT) = (char *) alloca (strlen (NAME) + 11);			\     ASM_GENERATE_INTERNAL_LABEL (OUTPUT, temp, LABELNO);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_STABD_OP
end_ifndef

begin_define
define|#
directive|define
name|ASM_STABD_OP
value|".stabd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    Some targets don't use this, but we have to define it anyway.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ADDR_VEC_ELT
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { fprintf (FILE, "\t%s\t", ASM_LONG);				\      ASM_OUTPUT_INTERNAL_LABEL (FILE, "L", (VALUE));			\      fputc ('\n', FILE);						\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* choose a reasonable default for ASM_OUTPUT_ASCII.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ASCII
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|MYFILE
parameter_list|,
name|MYSTRING
parameter_list|,
name|MYLENGTH
parameter_list|)
define|\
value|do {									      \     FILE *_hide_asm_out_file = (MYFILE);				      \     unsigned char *_hide_p = (unsigned char *) (MYSTRING);		      \     int _hide_thissize = (MYLENGTH);					      \     {									      \       FILE *asm_out_file = _hide_asm_out_file;				      \       unsigned char *p = _hide_p;					      \       int thissize = _hide_thissize;					      \       int i;								      \       fprintf (asm_out_file, "\t.ascii \"");				      \ 									      \       for (i = 0; i< thissize; i++)					      \ 	{								      \ 	  register int c = p[i];					      \ 	  if (c == '\"' || c == '\\')					      \ 	    putc ('\\', asm_out_file);					      \ 	  if (c>= ' '&& c< 0177)					      \ 	    putc (c, asm_out_file);					      \ 	  else								      \ 	    {								      \ 	      fprintf (asm_out_file, "\\%o", c);			      \
comment|/* After an octal-escape, if a digit follows,		      \ 		 terminate one string constant and start another.	      \ 		 The Vax assembler fails to stop reading the escape	      \ 		 after three digits, so this is the only way we		      \ 		 can get it to parse the data properly.  */
value|\ 	      if (i< thissize - 1					      \&& p[i + 1]>= '0'&& p[i + 1]<= '9')		      \ 		fprintf (asm_out_file, "\"\n\t.ascii \"");		      \ 	  }								      \ 	}								      \       fprintf (asm_out_file, "\"\n");					      \     }									      \   }									      \   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_IDENTIFY_GCC
end_ifndef

begin_comment
comment|/* Default the definition, only if ASM_IDENTIFY_GCC is not set,      because if it is set, we might not want ASM_IDENTIFY_LANGUAGE      outputting labels, if we do want it to, then it must be defined      in the tm.h file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_IDENTIFY_LANGUAGE
end_ifndef

begin_define
define|#
directive|define
name|ASM_IDENTIFY_LANGUAGE
parameter_list|(
name|FILE
parameter_list|)
value|output_lang_identify (FILE);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how we tell the assembler to equate two values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SET_ASM_OP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_DEF
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {	fprintf ((FILE), "\t%s\t", SET_ASM_OP);				\ 	assemble_name (FILE, LABEL1);					\ 	fprintf (FILE, ",");						\ 	assemble_name (FILE, LABEL2);					\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_LABELREF
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|asm_fprintf ((FILE), "%U%s", (NAME))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This determines whether or not we support weak symbols.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORTS_WEAK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_WEAKEN_LABEL
end_ifdef

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the target supports weak symbols, define TARGET_ATTRIBUTE_WEAK to    provide a weak attribute.  Else define it to nothing.      This would normally belong in gansidecl.h, but SUPPORTS_WEAK is    not available at that time.     Note, this is only for use by target files which we know are to be    compiled by GCC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ATTRIBUTE_WEAK
end_ifndef

begin_if
if|#
directive|if
name|SUPPORTS_WEAK
end_if

begin_define
define|#
directive|define
name|TARGET_ATTRIBUTE_WEAK
value|__attribute__ ((weak))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ATTRIBUTE_WEAK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we have a definition of INCOMING_RETURN_ADDR_RTX, assume that    the rest of the DWARF 2 frame unwind support is also provided.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2_UNWIND_INFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|INCOMING_RETURN_ADDR_RTX
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

