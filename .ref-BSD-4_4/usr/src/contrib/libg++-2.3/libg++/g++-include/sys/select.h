begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Needed by Interviews for AIX. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__libgxx_sys_select_h
end_ifndef

begin_extern
extern|extern
literal|"C"
block|{
empty|#include_next<sys/select.h>
define|#
directive|define
name|__libgxx_sys_select_h
value|1
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

