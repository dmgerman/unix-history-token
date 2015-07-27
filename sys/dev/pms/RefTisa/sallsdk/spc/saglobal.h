begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file saglobal.h  *  \brief This file defines global types  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAGLOBAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAGLOBAL_H__
end_define

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
file|<dev/pms/RefTisa/tisa/sassata/common/ossa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/saosapi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/sallist.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/sadefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/sampidefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa_err.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/api/sa_spec.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/sahwreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/samacro.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/spcdefs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/mpi.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/satypes.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/saproto.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/sallsdk/spc/mpidebug.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SAGLOBAL_H__ */
end_comment

end_unit

