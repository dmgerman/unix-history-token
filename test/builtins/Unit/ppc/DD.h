begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__DD_HEADER
end_ifndef

begin_define
define|#
directive|define
name|__DD_HEADER
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_typedef
typedef|typedef
union|union
block|{
name|long
name|double
name|ld
decl_stmt|;
struct|struct
block|{
name|double
name|hi
decl_stmt|;
name|double
name|lo
decl_stmt|;
block|}
struct|;
block|}
name|DD
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __DD_HEADER
end_comment

end_unit

