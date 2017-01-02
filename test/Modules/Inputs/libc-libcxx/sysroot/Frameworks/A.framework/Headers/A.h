begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__my_a
end_ifndef

begin_define
define|#
directive|define
name|__my_a
end_define

begin_include
include|#
directive|include
file|<A/int.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

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
typedef|typedef
name|int_fast32_t
name|my_a
typedef|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

