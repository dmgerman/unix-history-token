begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_CAS_64
end_ifdef

begin_define
define|#
directive|define
name|ATOMIC
value|ck_pr_cas_64(object, 1, 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC_STRING
value|"ck_pr_cas_64"
end_define

begin_include
include|#
directive|include
file|"benchmark.h"
end_include

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|Did not find CAS_64 implementation.
end_warning

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

