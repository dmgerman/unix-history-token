begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machdep.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR32
end_ifdef

begin_define
define|#
directive|define
name|pushaddr
value|push4
end_define

begin_define
define|#
directive|define
name|popaddr
value|(char *)pop4
end_define

begin_endif
endif|#
directive|endif
endif|ADDR32
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADDR16
end_ifdef

begin_define
define|#
directive|define
name|pushaddr
value|push2
end_define

begin_define
define|#
directive|define
name|popaddr
value|(char *)pop2
end_define

begin_endif
endif|#
directive|endif
endif|ADDR16
end_endif

end_unit

