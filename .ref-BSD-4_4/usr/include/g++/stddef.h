begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__libgxx_stddef_h
end_ifndef

begin_extern
extern|extern
literal|"C"
block|{
ifdef|#
directive|ifdef
name|__stddef_h_recursive
empty|#include_next<stddef.h>
else|#
directive|else
empty|#include_next<stddef.h>
define|#
directive|define
name|__libgxx_stddef_h
value|1
endif|#
directive|endif
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

