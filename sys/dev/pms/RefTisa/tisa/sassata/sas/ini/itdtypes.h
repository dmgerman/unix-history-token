begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  *  * data structures for SAS intiator in SAS/SATA TD layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ITDTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ITDTYPES_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/common/tdtypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdlist.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/ini/itddefs.h>
end_include

begin_comment
comment|/** \brief data structure for the options of SAS initiator  *  * This data structure contains options for SAS initiator such as the maximum  * number of allowed targets and DIF capability  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|itdssOperatingOption_s
block|{
name|bit32
name|MaxTargets
decl_stmt|;
comment|/**< the maximum number of allowed targets */
comment|/* this is read from a file or #defined      then passed to TD layer from tiInitiatorResource_t    */
name|bit32
name|UsecsPerTick
decl_stmt|;
comment|/* in micro seconds */
block|}
name|itdssOperatingOption_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ITDTYPES_H__ */
end_comment

end_unit

