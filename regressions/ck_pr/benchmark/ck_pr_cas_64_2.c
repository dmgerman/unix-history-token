begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CK_F_PR_CAS_64_2
end_ifdef

begin_define
define|#
directive|define
name|ATOMIC
value|{ uint64_t z[2] = {1, 2}; ck_pr_cas_64_2(object, z, z); }
end_define

begin_define
define|#
directive|define
name|ATOMIC_STRING
value|"ck_pr_cas_64_2"
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unsupported.\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

