begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** errno.h ** ** Emulation of the Unix errno.h header file for PRIMOS ** ** Author: Peter Eriksson<pen@lysator.liu.se> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ERRNO_H__
end_ifndef

begin_define
define|#
directive|define
name|__ERRNO_H__
end_define

begin_include
include|#
directive|include
file|<errd.h>
end_include

begin_define
define|#
directive|define
name|ENOENT
value|e$fntf
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

