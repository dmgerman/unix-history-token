begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|PEPYPATH
end_ifdef

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/entry.h"
end_include

begin_include
include|#
directive|include
file|"quipu/common.h"
end_include

begin_include
include|#
directive|include
file|"quipu/bind.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<isode/quipu/util.h>
end_include

begin_include
include|#
directive|include
file|<isode/quipu/entry.h>
end_include

begin_include
include|#
directive|include
file|<isode/quipu/common.h>
end_include

begin_include
include|#
directive|include
file|<isode/quipu/bind.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|int2strb_alloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

