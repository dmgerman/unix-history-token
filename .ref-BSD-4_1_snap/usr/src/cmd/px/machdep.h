begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static char sccsid[] = "@(#)machdep.h 1.2 3/6/81"; */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
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

begin_else
else|#
directive|else
end_else

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
endif|VAX
end_endif

end_unit

