begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/include/RCS/osconf.h,v $  * $Author: torek $  * $Header: /usr/src/kerberosIV/include/RCS/osconf.h,v 4.10 93/05/25 16:49:56 torek Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Athena configuration.  */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_comment
comment|/* something tells me some of these files should be renamed... */
end_comment

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
operator|||
name|defined
argument_list|(
name|luna68k
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-bsdtahoe.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-ultmips2.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|hp800
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-bsdsparc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun2
argument_list|)
operator|||
name|defined
argument_list|(
name|sun3
argument_list|)
end_if

begin_include
include|#
directive|include
file|"conf-bsdm68k.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

