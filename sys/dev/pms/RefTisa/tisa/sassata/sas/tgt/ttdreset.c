begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<osenv.h>
end_include

begin_include
include|#
directive|include
file|<ostypes.h>
end_include

begin_include
include|#
directive|include
file|<osdebug.h>
end_include

begin_include
include|#
directive|include
file|<sa.h>
end_include

begin_include
include|#
directive|include
file|<saapi.h>
end_include

begin_include
include|#
directive|include
file|<saosapi.h>
end_include

begin_include
include|#
directive|include
file|<titypes.h>
end_include

begin_include
include|#
directive|include
file|<ostiapi.h>
end_include

begin_include
include|#
directive|include
file|<tiapi.h>
end_include

begin_include
include|#
directive|include
file|<tiglobal.h>
end_include

begin_include
include|#
directive|include
file|<tdtypes.h>
end_include

begin_include
include|#
directive|include
file|<osstring.h>
end_include

begin_include
include|#
directive|include
file|<tdutil.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
end_ifdef

begin_include
include|#
directive|include
file|<itdtypes.h>
end_include

begin_include
include|#
directive|include
file|<itddefs.h>
end_include

begin_include
include|#
directive|include
file|<itdglobl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DRIVER
end_ifdef

begin_include
include|#
directive|include
file|"ttdglobl.h"
end_include

begin_include
include|#
directive|include
file|"ttdtxchg.h"
end_include

begin_include
include|#
directive|include
file|"ttdtypes.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tdsatypes.h>
end_include

begin_include
include|#
directive|include
file|<tdproto.h>
end_include

end_unit

