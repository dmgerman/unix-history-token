begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|USG
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|unos
end_ifndef

begin_define
define|#
directive|define
name|unos
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xm-m68k.h"
end_include

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy (b,a,c)
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|memset (a,0,b)
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcmp (a,b,c)
end_define

begin_comment
comment|/* Avoid conflict with C library by changing name of this symbol.  */
end_comment

begin_define
define|#
directive|define
name|gettime
value|gcc_gettime
end_define

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

