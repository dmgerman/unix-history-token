begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|fcntl_h
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
define|#
directive|define
name|KERNEL
include|#
directive|include
file|"/usr/include/fcntl.h"
ifndef|#
directive|ifndef
name|fcntl_h
define|#
directive|define
name|fcntl_h
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

