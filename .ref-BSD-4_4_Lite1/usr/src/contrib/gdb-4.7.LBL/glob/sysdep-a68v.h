begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System-dependent stuff, for Apollo 68k SysV-under-Domain/OS  systems */
end_comment

begin_include
include|#
directive|include
file|<malloc.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dirent
name|dirent
typedef|;
end_typedef

end_unit

