begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1989 by Kenneth Almquist.  All rights reserved.  * This file is part of ash, which is distributed under the terms specified  * by the Ash General Public License.  See the file named LICENSE.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|error
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
block|{
else|#
directive|else
name|error
argument_list|(
argument|msg
argument_list|)
name|char
modifier|*
name|msg
decl_stmt|;
block|{
endif|#
directive|endif
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"test: %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

