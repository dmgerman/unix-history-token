begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_include
include|#
directive|include
file|"quipu/malloc.h"
end_include

begin_comment
comment|/* Could turn this all into a macro ! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AttrT_cpy
end_ifdef

begin_undef
undef|#
directive|undef
name|AttrT_cpy
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|AttributeType
name|AttrT_cpy
parameter_list|(
name|x
parameter_list|)
specifier|register
name|AttributeType
name|x
decl_stmt|;
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

