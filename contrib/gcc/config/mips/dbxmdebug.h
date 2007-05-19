begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for MIPS running IRIX 5    or IRIX 6 (O32 ABI) using the GNU assembler with stabs-in-mdebug.  */
end_comment

begin_comment
comment|/* Override iris5gas.h version again to retain mips.h default.  */
end_comment

begin_undef
undef|#
directive|undef
name|MDEBUG_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|MDEBUG_ASM_SPEC
value|"%{!gdwarf*:-mdebug} %{gdwarf*:-no-mdebug}"
end_define

end_unit

