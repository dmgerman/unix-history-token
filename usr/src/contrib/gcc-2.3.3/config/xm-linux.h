begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running Linux.  *  * Written by H.J. Lu (hlu@eecs.wsu.edu)  */
end_comment

begin_include
include|#
directive|include
file|"xm-i386.h"
end_include

begin_include
include|#
directive|include
file|"xm-svr3.h"
end_include

begin_undef
undef|#
directive|undef
name|BSTRING
end_undef

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_undef
undef|#
directive|undef
name|bcmp
end_undef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_undef
undef|#
directive|undef
name|index
end_undef

begin_undef
undef|#
directive|undef
name|rindex
end_undef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These conflict with stdlib.h in protoize, it is said, 	 and there's no evidence they are actually needed.  */
end_comment

begin_undef
undef|#
directive|undef
name|malloc
name|(
name|n
name|)
end_undef

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|n
parameter_list|)
value|malloc ((n) ? (n) : 1)
end_define

begin_undef
undef|#
directive|undef
name|calloc
name|(
name|n
name|,
name|e
name|)
end_undef

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|e
parameter_list|)
value|calloc (((n) ? (n) : 1), ((e) ? (e) : 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

