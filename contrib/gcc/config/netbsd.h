begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NETBSD_NATIVE is defined when gcc is integrated into the NetBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETBSD_NATIVE
end_ifdef

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_undef
undef|#
directive|undef
name|GCC_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_undef
undef|#
directive|undef
name|INCLUDE_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{						\     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },	\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },		\     { 0, 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under NetBSD, the normal location of the compiler back ends is the    /usr/libexec directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|"/usr/libexec/"
end_define

begin_comment
comment|/* Under NetBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a CPP_SPEC appropriate for NetBSD.  Current we just deal with    the GCC option `-posix'.  */
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
value|"%{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide an ASM_SPEC appropriate for NetBSD.  Currently we only deal    with the options for generating PIC code.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %| %{fpic:-k} %{fPIC:-k -K}"
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for NetBSD.  Just select the appropriate    libc, depending on whether we're doing profiling.  */
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
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for NetBSD.  Here we provide support    for the special GCC options -static, -assert, and -nostdlib.  */
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
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{R*} %{static:-Bstatic} %{assert*}"
end_define

begin_comment
comment|/* This defines which switch letters take arguments. */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR) \    || (CHAR) == 'R')
end_define

begin_comment
comment|/* We have atexit(3).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Some imports from svr4.h in support of shared libraries.  * Currently, we need the DECLARE_OBJECT_SIZE stuff.  */
end_comment

begin_comment
comment|/* Define the strings used for the .type, .size, and .set directives.    These strings generally do not vary from one system running netbsd    to another, but if a given system needs to use different pseudo-op    names for these, they may be overridden in the file which includes    this one.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

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
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_WEAKEN_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.globl\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); \        fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms for this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending upon the particulars of your assembler).  */
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
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

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
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));	\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set    by ASM_DECLARE_OBJECT_NAME when it was run for the same decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TOP_LEVEL
parameter_list|,
name|AT_END
parameter_list|)
define|\
value|do {									 \      char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);			 \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		 \&& ! AT_END&& TOP_LEVEL					 \&& DECL_INITIAL (DECL) == error_mark_node			 \&& !size_directive_output)					 \        {								 \ 	 size_directive_output = 1;					 \ 	 fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);			 \ 	 assemble_name (FILE, name);					 \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL))); \        }								 \    } while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
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
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

end_unit

