begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/include/RCS/conf-bsdvax.h,v $  * $Author: jtkohl $  * $Header: conf-bsdvax.h,v 4.0 89/01/23 09:58:12 jtkohl Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Machine-type definitions: VAX  */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_define
define|#
directive|define
name|VAX
end_define

begin_define
define|#
directive|define
name|BITS32
end_define

begin_define
define|#
directive|define
name|BIG
end_define

begin_define
define|#
directive|define
name|LSBFIRST
end_define

begin_define
define|#
directive|define
name|BSDUNIX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOASM
end_ifndef

begin_define
define|#
directive|define
name|VAXASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no assembly */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* standard C */
end_comment

end_unit

