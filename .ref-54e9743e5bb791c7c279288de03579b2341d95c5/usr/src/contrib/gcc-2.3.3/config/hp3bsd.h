begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"m68k.h"
end_include

begin_comment
comment|/* See m68k.h.  7 means 68020 with 68881.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_comment
comment|/* Define __HAVE_68881__ in preprocessor, unless -msoft-float is specified.    This will control the use of inline 68881 insns in certain macros.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!msoft-float:-D__HAVE_68881__ -D__HAVE_FPU__}"
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dmc68020 -Dhp300 -Dhp9000 -Dunix"
end_define

begin_comment
comment|/* Link with libg.a when debugging, for dbx's sake.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g:-lgnulib} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Do not break .stabs pseudos into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* This is the char to use for continuation (in case we need to turn    continuation back on).  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

begin_comment
comment|/* Don't use the `xsfoo;' construct in DBX output; this system    doesn't support it.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
end_define

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Don't attempt to use mcrt0.o for 'cc -p'. */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:gcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

end_unit

