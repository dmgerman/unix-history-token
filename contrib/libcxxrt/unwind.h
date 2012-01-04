begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|UNWIND_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|UNWIND_H_INCLUDED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__arm__
include|#
directive|include
file|"unwind-arm.h"
else|#
directive|else
include|#
directive|include
file|"unwind-itanium.h"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

