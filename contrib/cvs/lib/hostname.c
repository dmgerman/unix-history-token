begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hostname.c -- use uname() to get the name of the host    Copyright (C) 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|index
end_ifndef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_comment
comment|/* Put this host's name into NAME, using at most NAMELEN characters */
end_comment

begin_function
name|int
name|gethostname
parameter_list|(
name|name
parameter_list|,
name|namelen
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|namelen
decl_stmt|;
block|{
name|struct
name|utsname
name|ugnm
decl_stmt|;
if|if
condition|(
name|uname
argument_list|(
operator|&
name|ugnm
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|name
argument_list|,
name|ugnm
operator|.
name|nodename
argument_list|,
name|namelen
operator|-
literal|1
argument_list|)
expr_stmt|;
name|name
index|[
name|namelen
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

