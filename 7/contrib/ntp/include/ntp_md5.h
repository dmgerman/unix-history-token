begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_md5.h: deal with md5.h headers  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MD5_H
end_ifdef

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"rsa_md5.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

