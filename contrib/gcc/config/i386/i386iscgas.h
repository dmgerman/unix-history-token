begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Interactive Unix System V,    producing stabs-in-coff output (using a slightly modified gas).    Specifically, this is for recent versions that support POSIX;    for version 2.0.2, use configuration option i386-sysv instead.  */
end_comment

begin_comment
comment|/* Underscores are not used on ISC systems (probably not on any COFF    system), despite the comments in i386/gas.h.  If this is not defined,    enquire (for example) will fail to link.  --karl@cs.umb.edu  */
end_comment

begin_define
define|#
directive|define
name|NO_UNDERSCORES
end_define

begin_comment
comment|/* Mostly like other gas-using systems.  */
end_comment

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_comment
comment|/* But with ISC-specific additions.  */
end_comment

begin_include
include|#
directive|include
file|"i386/isc.h"
end_include

begin_comment
comment|/* We do not want to output SDB debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_comment
comment|/* We want to output DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* The function `dbxout_init' in dbxout.c omits the first character of    `ltext_label_name' when outputting the main source directory and main    source filename.  I don't understand why, but rather than making a    system-independent change there, I override dbxout.c's defaults.    Perhaps it would be better to use ".Ltext0" instead of    `ltext_label_name', but we've already generated the label, so we just    use it here.  --karl@cs.umb.edu  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
parameter_list|(
name|asmfile
parameter_list|,
name|cwd
parameter_list|)
define|\
value|do {	fprintf (asmfile, "%s ", ASM_STABS_OP);				\ 	output_quoted_string (asmfile, cwd);				\ 	fprintf (asmfile, ",%d,0,0,%s\n", N_SO, ltext_label_name);	\   } while (0)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILENAME
parameter_list|(
name|asmfile
parameter_list|,
name|input_file_name
parameter_list|)
define|\
value|fprintf (asmfile, "%s ", ASM_STABS_OP);				\   output_quoted_string (input_file_name);				\   fprintf (asmfile, ",%d,0,0,%s\n", N_SO, ltext_label_name);		\   text_section ();							\   ASM_OUTPUT_INTERNAL_LABEL (asmfile, "Ltext", 0)
end_define

begin_comment
comment|/* Because we don't include `svr3.h', we haven't yet defined SIZE_TYPE    and PTRDIFF_TYPE.  ISC's definitions don't match GCC's defaults, so: */
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

begin_comment
comment|/* But we can't use crtbegin.o and crtend.o, because gas 1.38.1 doesn't    grok .section.  The definitions here are otherwise identical to those    in i386/isc.h.  */
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
value|"%{!shlib:%{posix:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{!posix:%{pg:mcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}\    %{p:-L/lib/libp} %{pg:-L/lib/libp}}}\    %{shlib:%{posix:crtp1.o%s}%{!posix:crt1.o%s}}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtn.o%s"
end_define

end_unit

