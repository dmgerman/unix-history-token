begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|B_H
end_ifndef

begin_define
define|#
directive|define
name|B_H
end_define

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_decl_stmt
name|class
name|B
range|:
name|virtual
name|public
name|A
block|{
name|virtual
name|void
name|x
argument_list|()
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|b
parameter_list|(
name|A
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|x
argument_list|()
expr_stmt|;
comment|// Instantiating a class that virtually inherits 'A'
comment|// triggers calculation of the vtable offsets in 'A'.
name|B
name|b
decl_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

