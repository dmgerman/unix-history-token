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
value|"%{!shlib:%{posix:%{pg:mcrtp1.o%s}%{!pg:%{p:mcrtp1.o%s}%{!p:crtp1.o%s}}}\    %{!posix:%{pg:mcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}\    %{p:-L/lib/libp} %{pg:-L/lib/libp}}}\    %{shlib:%{posix:crtp1.o%s}%{!posix:crt1.o%s}} crtbegin.o%s"
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
value|"%{posix:-lcposix} %{shlib:-lc_s} -lc -lg"
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
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|(TREE_CODE (FUNTYPE) == IDENTIFIER_NODE ? 0			\    : (TARGET_RTD						\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\ 	  || (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\ 	      == void_type_node))) ? (SIZE)			\    : 0)
end_define

begin_comment
comment|/* On other 386 systems, the last line looks like this:    : (aggregate_value_p (FUNTYPE)) ? GET_MODE_SIZE (Pmode) : 0)  */
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
value|0201
end_define

end_unit

