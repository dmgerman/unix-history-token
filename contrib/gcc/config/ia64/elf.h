begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for embedded ia64-elf target.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) ELF");
end_define

begin_comment
comment|/* Define this to be a string constant containing `-D' options to define the    predefined macros that identify this machine and system.  These macros will    be predefined unless the `-ansi' option is specified.  */
end_comment

begin_comment
comment|/* ??? This is undefed in svr4.h.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dia64 -Amachine=ia64"
end_define

begin_comment
comment|/* A C string constant that tells the GNU CC driver program options to pass to    the assembler.  It can also specify how to translate options you give to GNU    CC into options for GNU CC to pass to the assembler.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|TARGET_CPU_DEFAULT
operator||
name|TARGET_DEFAULT
operator|)
operator|&
name|MASK_GNU_AS
operator|)
operator|!=
literal|0
end_if

begin_comment
comment|/* GNU AS.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{mno-gnu-as:-N so} %{!mno-gnu-as:-x} %{mconstant-gp} %{mauto-pic}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Intel ias.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{!mgnu-as:-N so} %{mgnu-as:-x} %{mconstant-gp:-M const_gp}\    %{mauto-pic:-M no_plabel}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C string constant that tells the GNU CC driver program options to pass to    the linker.  It can also specify how to translate options you give to GNU CC    into options for GNU CC to pass to the linker.  */
end_comment

begin_comment
comment|/* The Intel linker does not support dynamic linking, so we need -dn.    The Intel linker gives annoying messages unless -N so is used.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|TARGET_CPU_DEFAULT
operator||
name|TARGET_DEFAULT
operator|)
operator|&
name|MASK_GNU_LD
operator|)
operator|!=
literal|0
end_if

begin_comment
comment|/* GNU LD.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{mno-gnu-ld:-dn -N so}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Intel ild.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{!mgnu-ld:-dn -N so}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* svr4.h links with crti.o/crtn.o, but elfos.h does not.  We override elfos.h    so that we can use the standard ELF Unix method.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s crtn.o%s"
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
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}\ 			crti.o%s crtbegin.o%s"
end_define

begin_comment
comment|/* End of elf.h */
end_comment

end_unit

