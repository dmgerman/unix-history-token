begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)local.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_include
include|#
directive|include
file|"v7.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CORY
end_ifdef

begin_include
include|#
directive|include
file|"c.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INGRES
end_ifdef

begin_include
include|#
directive|include
file|"ing.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_include
include|#
directive|include
file|"v6.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CC
end_ifdef

begin_include
include|#
directive|include
file|"cc.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|V40
end_ifdef

begin_include
include|#
directive|include
file|"40.local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

