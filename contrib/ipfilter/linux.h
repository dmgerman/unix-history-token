begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993-1997 by Darren Reed.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and due credit is given  * to the original author and the contributors.  The author accepts no  * responsibility and is not changed in any way.  *  * I hate legaleese, don't you ?  * $Id: linux.h,v 2.0.2.4 1997/09/28 07:12:03 darrenr Exp $  */
end_comment

begin_include
include|#
directive|include
file|<linux/config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MODULE
end_ifdef

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MODULE */
end_comment

begin_include
include|#
directive|include
file|"ip_compat.h"
end_include

end_unit

