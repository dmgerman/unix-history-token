begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This administrivia gets added to the end of limits.h    if the system has its own version of limits.h.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not _GCC_LIMITS_H_ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_GCC_NEXT_LIMITS_H
end_ifdef

begin_empty
empty|#include_next<limits.h>
end_empty

begin_comment
comment|/* recurse down to the real one */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _GCC_LIMITS_H_ */
end_comment

end_unit

