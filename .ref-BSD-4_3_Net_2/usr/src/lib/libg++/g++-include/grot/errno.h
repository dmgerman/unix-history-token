begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|errno_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern
literal|"C"
block|{
ifdef|#
directive|ifdef
name|VMS
include|#
directive|include
file|"GNU_CC_INCLUDE:[000000]errno.h"
else|#
directive|else
include|#
directive|include
file|"//usr/include/errno.h"
endif|#
directive|endif
block|}
end_extern

begin_ifndef
ifndef|#
directive|ifndef
name|errno_h
end_ifndef

begin_define
define|#
directive|define
name|errno_h
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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

