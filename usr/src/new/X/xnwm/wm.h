begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: wm.h,v 10.3 86/02/01 16:02:05 tony Rel $ */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

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

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_typedef
typedef|typedef
name|XKeyOrButtonEvent
name|BEvent
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MatchUp
parameter_list|(
name|e
parameter_list|,
name|w
parameter_list|)
value|((e).type == ButtonReleased&& (e).detail == (w))
end_define

begin_define
define|#
directive|define
name|MatchDown
parameter_list|(
name|e
parameter_list|,
name|w
parameter_list|)
value|((e).type == ButtonPressed&& (e).detail == (w))
end_define

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

