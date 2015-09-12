begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ *  ********************************************************************************/
end_comment

begin_comment
comment|/********************************************************************************  **  **   tiglobal.h  **  **   Abstract:  **  ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIGLOBAL_H
end_ifndef

begin_define
define|#
directive|define
name|TIGLOBAL_H
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

begin_ifndef
ifndef|#
directive|ifndef
name|TIDEBUG_MSG
end_ifndef

begin_define
define|#
directive|define
name|TIDEBUG_MSG
parameter_list|(
name|mask
parameter_list|,
name|val
parameter_list|,
name|format
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|bit32
name|gTiDebugLevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TI_DBG0
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG0(a)
end_define

begin_comment
comment|/* always print */
end_comment

begin_define
define|#
directive|define
name|TI_DBG1
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,1, a )
end_define

begin_define
define|#
directive|define
name|TI_DBG2
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,2, a )
end_define

begin_define
define|#
directive|define
name|TI_DBG3
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,3, a )
end_define

begin_define
define|#
directive|define
name|TI_DBG4
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,4, a )
end_define

begin_define
define|#
directive|define
name|TI_DBG5
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,5, a )
end_define

begin_comment
comment|/* OsDebugLevel 4 */
end_comment

begin_define
define|#
directive|define
name|TI_DBG6
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugLevel,6, a )
end_define

begin_define
define|#
directive|define
name|TI_DBG7
parameter_list|(
name|a
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|bit32
name|gTiDebugMask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TI_BIT1
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000001, a )
end_define

begin_define
define|#
directive|define
name|TI_BIT2
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000002, a )
end_define

begin_define
define|#
directive|define
name|TI_BIT3
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000004, a )
end_define

begin_define
define|#
directive|define
name|TI_BIT4
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000008, a )
end_define

begin_define
define|#
directive|define
name|TI_BIT5
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000010, a )
end_define

begin_define
define|#
directive|define
name|TI_BIT6
parameter_list|(
name|a
parameter_list|)
value|TIDEBUG_MSG(gTiDebugMask,0x00000020, a )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIGLOBAL_H */
end_comment

end_unit

