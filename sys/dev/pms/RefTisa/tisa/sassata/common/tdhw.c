begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* ** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * This file contains hardware related functions  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<dev/pms/config.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/ostypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osdebug.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/saapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/saosapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/titypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/ostiapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/api/tiglobal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_SM
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/sm.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/smapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sat/api/tdsmapi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FDS_DM
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/dm.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/dmapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/discovery/api/tddmapi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/common/tdtypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osstring.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdutil.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INITIATOR_DRIVER
end_ifdef

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/ini/itdtypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/ini/itddefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/ini/itdglobl.h>
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
file|<dev/pms/RefTisa/tisa/sassata/sas/tgt/ttdglobl.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/tgt/ttdxchg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/sas/tgt/ttdtypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdsatypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/tdproto.h>
end_include

begin_comment
comment|/***************************************************************************** *! \biref tdsaReadHardwareInfo * *  Purpose:  This function reads the hardware information. This includes, *            PCI DeviceID, PCI VendorID, PCI Chip Revision, PCI Function *            Number. * *  \param  tiRoot:            Pointer to driver/port instance. * *  \return: None *  \note - just a place holder for now *****************************************************************************/
end_comment

begin_function
name|osGLOBAL
name|void
name|tdsaReadHardwareInfo
parameter_list|(
name|tiRoot_t
modifier|*
name|tiRoot
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

