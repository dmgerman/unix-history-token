begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Assembler-independent definitions for an Intel 386 running    Interactive Unix System V. Specifically, this is for recent versions    that support POSIX.  */
end_comment

begin_comment
comment|/* Use crt1.o, not crt0.o, as a startup file, and crtn.o as a closing file. */
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
value|"%{!shlib:%{posix:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{Xp:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{!posix:%{!Xp:%{pg:mcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}\    %{p:-L/lib/libp} %{pg:-L/lib/libp}}}}\    %{shlib:%{Xp:crtp1.o%s}%{posix:crtp1.o%s}%{!posix:%{!Xp:crt1.o%s}}}\    crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Library spec */
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
value|"%{shlib:-lc_s} %{posix:-lcposix} %{Xp:-lcposix} -lc -lg"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE} %{Xp:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* ISC 2.2 uses `char' for `wchar_t'.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"char"
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
value|BITS_PER_UNIT
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This is apparently not true: ISC versions up to 3.0, at least, use    the standard calling sequence in which the called function pops the    extra arg.  */
end_comment

begin_comment
comment|/* caller has to pop the extra argument passed to functions that return    structures. */
end_comment

begin_undef
undef|#
directive|undef
name|RETURN_POPS_ARGS
end_undef

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((FUNDECL)&& TREE_CODE (FUNDECL) == IDENTIFIER_NODE ? 0	\    : (TARGET_RTD						\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\ 	  || (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\ 	      == void_type_node))) ? (SIZE)			\    : 0)
end_define

begin_comment
comment|/* On other 386 systems, the last line looks like this:    : (aggregate_value_p (TREE_TYPE (FUNTYPE))) ? GET_MODE_SIZE (Pmode) : 0)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle #pragma pack and #pragma weak.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387, ie,    (TARGET_80387 | TARGET_FLOAT_RETURNS_IN_80387)     ISC's software emulation of a 387 fails to handle the `fucomp'    opcode.  fucomp is only used when generating IEEE compliant code.    So don't make TARGET_IEEE_FP default for ISC. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_80387 | MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/* The ISC 2.0.2 software FPU emulator apparently can't handle    80-bit XFmode insns, so don't generate them.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* The ISC assembler does not like a .file directive with a name    longer than 14 characters.  Truncating it will not permit    debugging to work properly, but at least we won't get an error    message.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {							\     int len = strlen (main_input_filename);		\     char *na = main_input_filename + len;		\     char shorter[15];					\
comment|/* NA gets MAIN_INPUT_FILENAME sans directory names.  */
value|\     while (na> main_input_filename)			\       {							\ 	if (na[-1] == '/')				\ 	  break;					\ 	na--;						\       }							\     strncpy (shorter, na, 14);				\     shorter[14] = 0;					\     fprintf (FILE, "\t.file\t");			\     output_quoted_string (FILE, shorter);		\     fprintf (FILE, "\n");				\   } while (0)
end_define

begin_comment
comment|/* Work around assembler forward label references generated in exception    handling code. */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

end_unit

