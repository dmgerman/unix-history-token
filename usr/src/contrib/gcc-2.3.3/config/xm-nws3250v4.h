begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|USG
end_define

begin_include
include|#
directive|include
file|"xm-mips.h"
end_include

begin_comment
comment|/* If compiling with mips compiler, we are probably using alloca.c,    so help it work right.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

