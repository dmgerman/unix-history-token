begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running OSF/1 1.3.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_include
include|#
directive|include
file|<machine/machtime.h>
end_include

begin_define
define|#
directive|define
name|HZ
value|DEFAULT_CLK_TCK
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

