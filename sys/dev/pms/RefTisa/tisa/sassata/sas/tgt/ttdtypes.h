begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE  ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * $RCSfile: ttdtypes.h,v $  *  * Copyright 2006 PMC-Sierra, Inc.  *  * $Author: hasungwo $  * $Revision: 112322 $  * $Date: 2012-01-04 19:23:42 -0800 (Wed, 04 Jan 2012) $  *  * data structures for SAS target in SAS/SATA TD layer  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|tdsaContext_s
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|ttdssOperatingOption_s
block|{
name|bit32
name|numXchgs
decl_stmt|;
name|bit32
name|UsecsPerTick
decl_stmt|;
comment|/* in micro seconds */
comment|/* bad name but to be consistent with configuration file */
name|bit32
name|MaxTargets
decl_stmt|;
name|bit32
name|BlockSize
decl_stmt|;
block|}
name|ttdssOperatingOption_t
typedef|;
end_typedef

end_unit

