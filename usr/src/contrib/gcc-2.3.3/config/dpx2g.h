begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dpx2g.h - Bull DPX/2 200 and 300 systems (m68k, SysVr3) with gas  */
end_comment

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_include
include|#
directive|include
file|"dpx2.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USE_COLLECT2
end_ifndef

begin_comment
comment|/* We use set vectors for the constructors/destructors. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

begin_comment
comment|/* Although the gas we use can create .ctor and .dtor sections from N_SETT    stabs, it does not support section directives, so we need to have the loader    define the lists.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
end_define

begin_comment
comment|/* similar to default, but allows for the table defined by ld with gcc.ifile.     nptrs is always 0.  So we need to instead check that __DTOR_LIST__[1] != 0.    The old check is left in so that the same macro can be used if and when      a future version of gas does support section directives. */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
value|{int nptrs = *(int *)__DTOR_LIST__; int i; \   if (nptrs == -1 || (__DTOR_LIST__[0] == 0&& __DTOR_LIST__[1] != 0))  \     for (nptrs = 0; __DTOR_LIST__[nptrs + 1] != 0; nptrs++); 		\   for (i = nptrs; i>= 1; i--)						\     __DTOR_LIST__[i] (); }
end_define

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
value|"%{!r:gcc.ifile%s}\    %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}\   huge.o%s"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USE_COLLECT2 */
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
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}\   huge.o%s"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_COLLECT2 */
end_comment

begin_comment
comment|/* GAS want's DBX debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_DEBUGGING_INFO
end_ifndef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * we are using GAS  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_comment
comment|/* Gas understands dollars in labels. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* GAS does not understand .ident so don't output anything for #ident.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

begin_comment
comment|/*  * put const's in the text section  */
end_comment

begin_define
define|#
directive|define
name|const_section
parameter_list|()
value|text_section()
end_define

begin_define
define|#
directive|define
name|fini_section
parameter_list|()
value|while (0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* this is fixed in 2.1 */
end_comment

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
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)>= 1)			\     fprintf (FILE, "\t.even\n");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.data"
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.data"
end_define

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_comment
comment|/* end of dpx2g.h */
end_comment

end_unit

