begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%M%	%I%	%E%	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../vax/pte.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<vax/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../sun/pte.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sun/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

