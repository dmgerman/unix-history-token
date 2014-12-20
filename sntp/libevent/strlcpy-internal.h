begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|STRLCPY_INTERNAL_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|STRLCPY_INTERNAL_H_INCLUDED_
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
include|#
directive|include
file|"event2/event-config.h"
include|#
directive|include
file|"evconfig-private.h"
ifndef|#
directive|ifndef
name|EVENT__HAVE_STRLCPY
include|#
directive|include
file|<string.h>
name|size_t
name|event_strlcpy_
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|siz
parameter_list|)
function_decl|;
define|#
directive|define
name|strlcpy
value|event_strlcpy_
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

