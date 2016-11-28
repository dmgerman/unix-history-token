begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../ck_ticket_pb.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|THROUGHPUT
end_ifdef

begin_include
include|#
directive|include
file|"throughput.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|LATENCY
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"latency.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

