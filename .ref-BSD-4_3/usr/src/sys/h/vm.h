begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vm.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  *	#include "../h/vm.h"  * or	#include<vm.h>		 in a user program  * is a quick way to include all the vm header files.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"vmparam.h"
end_include

begin_include
include|#
directive|include
file|"vmmac.h"
end_include

begin_include
include|#
directive|include
file|"vmmeter.h"
end_include

begin_include
include|#
directive|include
file|"vmsystm.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmac.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmsystm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

