begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m-news-risc.h is for the "RISC News".  */
end_comment

begin_include
include|#
directive|include
file|"m-mips.h"
end_include

begin_undef
undef|#
directive|undef
name|LIBS_MACHINE
end_undef

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lmld
end_define

begin_define
define|#
directive|define
name|COFF
end_define

begin_undef
undef|#
directive|undef
name|LD_SWITCH_MACHINE
end_undef

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-x -D 800000
end_define

begin_comment
comment|/* #define C_OPTIMIZE_SWITCH -O2 */
end_comment

begin_define
define|#
directive|define
name|C_OPTIMIZE_SWITCH
value|-O
end_define

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-g3
end_define

begin_undef
undef|#
directive|undef
name|TERMINFO
end_undef

end_unit

