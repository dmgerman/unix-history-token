begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dpx2.h - Bull DPX/2 200 and 300 systems (m68k, SysVr3)  */
end_comment

begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_include
include|#
directive|include
file|"svr3.h"
end_include

begin_comment
comment|/* See m68k.h.  7 means 68020 with 68881.   * We really have 68030 and 68882,  * but this will get us going.    */
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

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_PREDEFINES
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * define all the things the compiler should  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ncl_mr
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dbull -DDPX2 -DSVR3 -Dmc68000 -Dmc68020 -Dncl_mr=1"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ncl_el
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dbull -DDPX2 -DSVR3 -Dmc68000 -Dmc68020 -Dncl_el"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Dbull -DDPX2 -DSVR3 -Dmc68000 -Dmc68020"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_comment
comment|/*  * use -ansi to imply POSIX and XOPEN and BULL source  * no -ansi implies _SYSV  */
end_comment

begin_comment
comment|/*  * you can't get a DPX/2 without a 68882 but allow it  * to be ignored...  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{ansi:-D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BULL_SOURCE}\  %{!ansi:-D_SYSV}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__HAVE_68881__
value|1
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!msoft-float:-D__HAVE_68881__ }\  %{ansi:-D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BULL_SOURCE}\  %{!ansi:-D_SYSV}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_LONG
end_undef

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long"
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_comment
comment|/* don't use svr3.h version */
end_comment

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_DTORS_BODY
end_undef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Should be no need now that svr3.h defines BSS_SECTION_FUNCTION.  */
end_comment

begin_comment
comment|/*   * svr3.h says to use BSS_SECTION_FUNCTION  * but no one appears to, and there is  * no definition for m68k.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSS_SECTION_FUNCTION
end_ifndef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CONST_SECTION_FUNCTION		\   INIT_SECTION_FUNCTION			\   FINI_SECTION_FUNCTION
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
comment|/* 0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GAS
end_ifndef

begin_comment
comment|/*  * handle the native assembler.  * this does NOT yet work, there is much left to do.  * use GAS for now...  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_FILENAME
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|NA
parameter_list|)
define|\
value|do { fprintf ((FILE), "\t.file\t'%s'\n", (NA)); } while (0)
end_define

begin_comment
comment|/*   * we don't seem to support any of:  * .globl  * .even  * .align  * .ascii  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GLOBALIZE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|asm_out_file
parameter_list|,
name|align
parameter_list|)
value|while (0)
end_define

begin_define
define|#
directive|define
name|STRING_LIMIT
value|(0)
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
value|""
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
value|""
end_define

begin_comment
comment|/*  * dc.b 'hello, world!'  * dc.b 10,0  * is how we have to output "hello, world!\n"  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|asm_out_file
parameter_list|,
name|p
parameter_list|,
name|thissize
parameter_list|)
define|\
value|do { register int i, c, f=0;			\   for (i = 0; i< thissize; i++) { 		\     c = p[i];					\     if (c == '\'' || c< ' ' || c> 127) {	\       switch(f) {				\       case 0:
comment|/* need to output dc.b etc */
value|\ 	fprintf(asm_out_file, "\tdc.b %d", c);	\ 	f=1;					\ 	break;					\       case 1:					\ 	fprintf(asm_out_file, ",%d", c);	\ 	break;					\       default:					\
comment|/* close a string */
value|\ 	fprintf(asm_out_file, "'\n\tdc.b %d", c); \ 	f=1;					\ 	break;					\       }						\     } else {					\       switch(f) {				\       case 0:					\ 	fprintf(asm_out_file, "\tdc.b '%c", c);	\ 	f=2;					\ 	break;					\       case 2:					\ 	fprintf(asm_out_file, "%c", c);		\ 	break;					\       default:					\ 	fprintf(asm_out_file, "\n\tdc.b '%c", c); \ 	f=2;					\ 	break;					\       }						\     }						\   }						\   if (f==2)					\     putc('\'', asm_out_file);			\   putc('\n', asm_out_file); } while (0)
end_define

begin_comment
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_PUSH
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmove.l %s,-(sp)\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_REG_POP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmove.l (sp)+,%s\n", reg_names[REGNO])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! use gas */
end_comment

end_unit

