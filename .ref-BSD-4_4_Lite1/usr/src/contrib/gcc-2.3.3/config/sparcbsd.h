begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sparc.h"
end_include

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

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:gcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_comment
comment|/* SunOS size_t is broken; ours works */
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

begin_comment
comment|/* We have atexit() and should use it in libgcc2 */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/*  * This one is pretty minor, but what the heck.  Simplify the output,  * and use a minimal size.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs ("\t.comm ", (FILE)),		\   assemble_name ((FILE), (NAME)),	\   fprintf ((FILE), ",%u\n", (SIZE ? SIZE : 1)))
end_define

begin_comment
comment|/*  * Want to do the same for .lcomm, but have to use the rounded size  * since gas 1.38 will not align local BSS offsets for us.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs ("\t.lcomm ", (FILE)),		\   assemble_name ((FILE), (NAME)),	\   fprintf ((FILE), ",%u\n", (ROUNDED)))
end_define

begin_comment
comment|/* we are not SunOS; we will try not defining `sun' */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Dunix"
end_define

end_unit

