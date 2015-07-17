begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** ** ** Version Control Information: ** ** *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************** **     **   tiscsi.h ** **   Abstract:   This module contains SCSI related data structure definition. **      ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TISCSI_H
end_ifndef

begin_define
define|#
directive|define
name|TISCSI_H
end_define

begin_comment
comment|/*  * SCSI Sense Data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bit8
name|snsRespCode
decl_stmt|;
name|bit8
name|snsSegment
decl_stmt|;
name|bit8
name|senseKey
decl_stmt|;
comment|/* sense key                                */
name|bit8
name|info
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|addSenseLen
decl_stmt|;
comment|/* 11 always                                */
name|bit8
name|cmdSpecific
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|addSenseCode
decl_stmt|;
comment|/* additional sense code                    */
name|bit8
name|senseQual
decl_stmt|;
comment|/* additional sense code qualifier          */
name|bit8
name|fru
decl_stmt|;
name|bit8
name|skeySpecific
index|[
literal|3
index|]
decl_stmt|;
block|}
name|scsiRspSense_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TISCSI_H */
end_comment

end_unit

