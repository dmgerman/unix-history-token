begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vm.h	4.1	11/9/80	*/
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
file|"../h/vmparam.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmclust.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmtune.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmmac.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmmeter.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmtotal.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmsystm.h"
end_include

begin_include
include|#
directive|include
file|"../h/vmklust.h"
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
file|<sys/vmclust.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmtune.h>
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
file|<sys/vmtotal.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmsystm.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmklust.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

