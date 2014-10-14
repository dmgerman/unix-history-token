begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|H_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|H_COMMON_H
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|PTHREAD_REQUIRE
parameter_list|(
name|x
parameter_list|)
define|\
value|do { \         int ret = (x); \         ATF_REQUIRE_MSG(ret == 0, "%s: %s", #x, strerror(ret)); \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// H_COMMON_H
end_comment

end_unit

