begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_USE_UNION_WAIT
argument_list|)
end_if

begin_typedef
typedef|typedef
name|union
name|wait
name|WAITER
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WEXITSTATUS
argument_list|)
end_if

begin_define
define|#
directive|define
name|WAITVAL
parameter_list|(
name|x
parameter_list|)
value|(WEXITSTATUS(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WAITVAL
parameter_list|(
name|x
parameter_list|)
value|((x).w_retcode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(WEXITSTATUS) */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|WAITER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WAITVAL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_USE_UNION_WAIT) */
end_comment

begin_function
name|int
name|waitnb
parameter_list|(
name|statusp
parameter_list|)
name|int
modifier|*
name|statusp
decl_stmt|;
block|{
name|WAITER
name|w
decl_stmt|;
name|int
name|pid
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DO_HAVE_WAITPID
argument_list|)
name|pid
operator|=
name|waitpid
argument_list|(
operator|-
literal|1
argument_list|,
operator|&
name|w
argument_list|,
name|WNOHANG
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* defined(DO_HAVE_WAITPID) */
if|#
directive|if
name|defined
argument_list|(
name|DONT_HAVE_WAITPID
argument_list|)
name|pid
operator|=
name|wait3
argument_list|(
operator|&
name|w
argument_list|,
name|WNOHANG
argument_list|,
operator|(
expr|struct
name|rusage
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* defined(DONT_HAVE_WAITPID) */
if|if
condition|(
name|pid
operator|>
literal|0
condition|)
operator|*
name|statusp
operator|=
name|WAITVAL
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|pid
return|;
block|}
end_function

end_unit

