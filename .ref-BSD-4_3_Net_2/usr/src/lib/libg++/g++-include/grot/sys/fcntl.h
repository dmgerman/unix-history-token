begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|sys_fcntl_h
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_extern
extern|extern
literal|"C"
block|{
define|#
directive|define
name|KERNEL
ifdef|#
directive|ifdef
name|VMS
include|#
directive|include
file|"GNU_CC_INCLUDE:[sys]fcntl.h"
else|#
directive|else
include|#
directive|include
file|"//usr/include/sys/fcntl.h"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|sys_fcntl_h
define|#
directive|define
name|sys_fcntl_h
value|1
endif|#
directive|endif
undef|#
directive|undef
name|KERNEL
block|}
end_extern

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

