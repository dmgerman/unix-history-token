begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Mips running RISCOS version 4.  */
end_comment

begin_include
include|#
directive|include
file|"m-mips.h"
end_include

begin_comment
comment|/* Define MIPS2 if you have an R6000 or R4000.  */
end_comment

begin_comment
comment|/* #define MIPS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS2
end_ifdef

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-systype bsd43 -O -Olimit 791 -g3 -mips2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|C_DEBUG_SWITCH
value|-systype bsd43 -O -Olimit 791 -g3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TERMINFO
end_ifdef

begin_undef
undef|#
directive|undef
name|TERMINFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|START_FILES
value|pre-crt0.o /lib/crt1.o
end_define

begin_define
define|#
directive|define
name|LIB_STANDARD
value|-lmld -lc /lib/crtn.o
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
value|-systype bsd43 -g3 -D 800000
end_define

end_unit

