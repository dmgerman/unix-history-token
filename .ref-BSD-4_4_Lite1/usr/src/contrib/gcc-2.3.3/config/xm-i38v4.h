begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running System V Release 4.  */
end_comment

begin_include
include|#
directive|include
file|"xm-i386.h"
end_include

begin_include
include|#
directive|include
file|"xm-svr4.h"
end_include

begin_comment
comment|/* If compiled with GNU C, use the built-in alloca.  */
end_comment

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

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

