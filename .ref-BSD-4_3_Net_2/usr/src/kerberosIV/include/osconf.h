begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/include/RCS/osconf.h,v $  * $Author: william $  * $Header: /usr/src/kerberosIV/include/RCS/osconf.h,v 4.6 90/12/29 01:30:34 william Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Athena configuration.  */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|hp300
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-bsdtahoe.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !tahoe */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsdvax.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !vax */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-ultmips2.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !Ultrix MIPS-2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ibm032
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsdibm032.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ibm032 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsdapollo.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !apollo */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsdsparc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun but not sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsd386i.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* sun but not (sparc or 386i) */
end_comment

begin_include
include|#
directive|include
file|"conf-bsdm68k.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !sun */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pyr
end_ifdef

begin_include
include|#
directive|include
file|"conf-pyr.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !pyr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_include
include|#
directive|include
file|"conf-bsd386i.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pyr */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ibm032 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mips */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tahoe */
end_comment

end_unit

