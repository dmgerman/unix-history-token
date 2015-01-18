begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|FIRSTHEADER
end_ifndef

begin_define
define|#
directive|define
name|FIRSTHEADER
end_define

begin_include
include|#
directive|include
file|"SecondHeader.h"
end_include

begin_comment
comment|// Just a class which gets in the lazy deserialization chain
end_comment

begin_include
include|#
directive|include
file|"stl_map.h"
end_include

begin_include
include|#
directive|include
file|"vector"
end_include

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|int
operator|>
operator|::
name|iterator
name|el
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|void
name|func
parameter_list|()
block|{
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|::
name|func
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

