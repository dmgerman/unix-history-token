begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sysconf.c: A (partial) replacement for the sysconf function  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.          History:  	Created by cmetz for OPIE 2.3. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PARAM_H */
end_comment

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_function
name|long
name|sysconf
parameter_list|(
name|int
name|name
parameter_list|)
block|{
switch|switch
condition|(
name|name
condition|)
block|{
case|case
name|_SC_OPEN_MAX
case|:
if|#
directive|if
name|HAVE_GETDTABLESIZE
return|return
name|getdtablesize
argument_list|()
return|;
else|#
directive|else
comment|/* HAVE_GETDTABLESIZE */
error|#
directive|error
error|Need getdtablesize() to build a replacement sysconf()
endif|#
directive|endif
comment|/* HAVE_GETDTABLESIZE */
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

