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

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -D____386BSD____ -D__386BSD__ -DBSD_NET2 -Asystem=unix -Asystem=bsd"
end_define

begin_comment
comment|/* Like the default, except no -lg.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
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

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

end_unit

