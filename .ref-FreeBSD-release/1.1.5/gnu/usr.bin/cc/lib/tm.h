begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running 386BSD as the target machine.  */
end_comment

begin_comment
comment|/* This is tested by i386gas.h.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386/gstabs.h"
end_include

begin_comment
comment|/* Get perform_* macros to build libgcc.a.  */
end_comment

begin_include
include|#
directive|include
file|"i386/perform.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -D__FreeBSD__ -D____386BSD____ -D__386BSD__ -DBSD_NET2"
end_define

begin_comment
comment|/* Like the default, except no -lg and no shared profiling libraries.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p -Bstatic}%{pg:-lc_p -Bstatic}"
end_define

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
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* 386BSD does have atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Redefine this to use %eax instead of %edx.  */
end_comment

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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%eax\n",		\ 	       LPREFIX, (LABELNO));					\       fprintf (FILE, "\tcall *mcount@GOT(%%ebx)\n");			\     }									\   else									\     {									\       fprintf (FILE, "\tmovl $%sP%d,%%eax\n", LPREFIX, (LABELNO));	\       fprintf (FILE, "\tcall mcount\n");				\     }									\ }
end_define

begin_comment
comment|/* There are conflicting reports about whether this system uses    a different assembler syntax.  wilson@cygnus.com says # is right.  */
end_comment

begin_undef
undef|#
directive|undef
name|COMMENT_BEGIN
end_undef

begin_define
define|#
directive|define
name|COMMENT_BEGIN
value|"#"
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

begin_escape
end_escape

begin_comment
comment|/* The following macros are stolen from i386v4.h */
end_comment

begin_comment
comment|/* These have to be defined to get PIC code correct */
end_comment

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    This is only used for PIC code.  See comments by the `casesi' insn in    i386.md for an explanation of the expression this outputs. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.long _GLOBAL_OFFSET_TABLE_+[.-%s%d]\n", LPREFIX, VALUE)
end_define

begin_comment
comment|/* Indicate that jump tables go in the text section.  This is    necessary when compiling PIC code.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/*  * Some imports from svr4.h in support of shared libraries.  * Currently, we need the DECLARE_OBJECT_SIZE stuff.  */
end_comment

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|".type"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|".size"
end_define

begin_define
define|#
directive|define
name|WEAK_ASM_OP
value|".weak"
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms for this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending upon the particulars of your assembler).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"@%s"
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare a function's result.    Most svr4 assemblers don't require any special declaration of the    result value, but there are exceptions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4.  These macros also output    the starting labels for the relevant functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function properly.    Some svr4 assemblers need to also have something extra said about the    function's return value.  We allow for that here.  */
end_comment

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
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     if (!flag_inhibit_size_directive)					\       {									\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (decl)));	\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

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
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

end_unit

