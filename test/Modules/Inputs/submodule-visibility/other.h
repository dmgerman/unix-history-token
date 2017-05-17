begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"c.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OTHER_H
end_ifndef

begin_define
define|#
directive|define
name|OTHER_H
end_define

begin_decl_stmt
name|namespace
name|N
block|{
struct|struct
name|C
block|{
name|template
operator|<
name|typename
name|U
operator|>
specifier|static
name|void
name|f
argument_list|(
argument|U
argument_list|)
block|{}
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

