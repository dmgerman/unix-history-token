begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tm-next.h:  Definitions for Next as target machine for GNU C compiler.  */
end_comment

begin_include
include|#
directive|include
file|"tm-m68k.h"
end_include

begin_comment
comment|/* Enable recent gcc to compile under the old gcc in Next release 1.0.  */
end_comment

begin_define
define|#
directive|define
name|__inline
value|inline
end_define

begin_comment
comment|/* See tm-m68k.h.  7 means 68020/030 with 68881/882.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_comment
comment|/* These compiler options take an argument.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "Ttext") || !strcmp (STR, "Tdata"))
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -DNeXT -Dunix -D__MACH__"
end_define

begin_comment
comment|/* Machine dependent ccp options.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{bsd:-D__STRICT_BSD__}"
end_define

begin_comment
comment|/* Machine dependent ld options.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{Z} %{M} %{Mach} %{segcreate*} %{seglinkedit}"
end_define

begin_comment
comment|/* Machine dependent libraries.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lsys_s}} %{pg:-lsys_p}"
end_define

begin_comment
comment|/* We specify crt0.o as -lcrt0.o so that ld will search the library path. */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:-lgcrt0.o}%{!pg: \      %{p:%e-p profiling is no longer supported.  Use -pg instead.} \      %{!p:-lcrt0.o}}"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* We want C++ style comments to be supported for Objective-C */
end_comment

begin_define
define|#
directive|define
name|CPLUSPLUS
end_define

begin_comment
comment|/* Why not? */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These pertain to code changes that are not present in 1.36.  */
end_comment

begin_comment
comment|/* Allow Mach -MD and -MMD make depend switches. */
end_comment

begin_define
define|#
directive|define
name|MACH_MAKE_DEPEND
end_define

begin_comment
comment|/* These options take an argument.  Note that we don't support -Ttext or -Tdata.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
value|(!strcmp (STR, "MD") || !strcmp (STR,
end_define

begin_endif
unit|"MMD"))
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* Allow #sscs (but don't do anything). */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* We use Dbx symbol format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(isinf ((VALUE))							\    ? fprintf (FILE, "\t.double 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.double 0r%.20e\n", (VALUE)))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(isinf ((VALUE))							\    ? fprintf (FILE, "\t.single 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.single 0r%.20e\n", (VALUE)))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(isinf ((VALUE))							\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "#0r%.9g", (VALUE)))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE_OPERAND
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(isinf ((VALUE))							\    ? fprintf (FILE, "#0r%s99e999", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "#0r%.20g", (VALUE)))
end_define

end_unit

