begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* yesno.c -- read a yes/no response from stdin    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Read one line from standard input    and return nonzero if that line begins with y or Y,    otherwise return 0. */
end_comment

begin_function
name|int
name|yesno
parameter_list|()
block|{
name|int
name|c
decl_stmt|;
name|int
name|rv
decl_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
name|rv
operator|=
operator|(
name|c
operator|==
literal|'y'
operator|)
operator|||
operator|(
name|c
operator|==
literal|'Y'
operator|)
expr_stmt|;
while|while
condition|(
name|c
operator|!=
name|EOF
operator|&&
name|c
operator|!=
literal|'\n'
condition|)
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
return|return
name|rv
return|;
block|}
end_function

end_unit

