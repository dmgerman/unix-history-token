begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_comment
comment|/* This file simply performs the include magic necessary for using select */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_BSDTYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/bsdtypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xtime.h"
end_include

begin_if
if|#
directive|if
name|HAVE_SYS_SELECT_H
end_if

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

