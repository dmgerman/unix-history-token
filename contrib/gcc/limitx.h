begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This administrivia gets added to the beginning of limits.h    if the system has its own version of limits.h.  */
end_comment

begin_comment
comment|/* We use _GCC_LIMITS_H_ because we want this not to match    any macros that the system's limits.h uses for its own purposes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GCC_LIMITS_H_
end_ifndef

begin_comment
comment|/* Terminated in limity.h.  */
end_comment

begin_define
define|#
directive|define
name|_GCC_LIMITS_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_LIMITS_H_
end_ifndef

begin_comment
comment|/* Use "..." so that we find syslimits.h only in this same directory.  */
end_comment

begin_include
include|#
directive|include
file|"syslimits.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

