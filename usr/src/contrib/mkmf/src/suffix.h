begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: suffix.h,v 4.2 91/11/25 19:45:47 nicklin Exp $  *  * Suffix/include definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUFFIX_H
end_ifndef

begin_define
define|#
directive|define
name|SUFFIX_H
end_define

begin_comment
comment|/*  * Suffix types   */
end_comment

begin_define
define|#
directive|define
name|SFXHEAD
value|'h'
end_define

begin_comment
comment|/* header file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXOBJ
value|'o'
end_define

begin_comment
comment|/* object file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXOUT
value|'x'
end_define

begin_comment
comment|/* executable file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXSRC
value|'s'
end_define

begin_comment
comment|/* source file name suffix */
end_comment

begin_define
define|#
directive|define
name|SFXNULL
value|0
end_define

begin_comment
comment|/* null suffix */
end_comment

begin_comment
comment|/*  * Suffix/include table structs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_mapinclude
block|{
name|char
modifier|*
name|incspec
decl_stmt|;
comment|/* user spec for include files */
name|int
name|inctyp
decl_stmt|;
comment|/* type of included file */
block|}
name|MAPINCLUDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_suffix
block|{
name|char
modifier|*
name|suffix
decl_stmt|;
comment|/* points to a suffix */
name|int
name|sfxtyp
decl_stmt|;
comment|/* type of file name suffix */
name|int
name|inctyp
decl_stmt|;
comment|/* type of included file */
name|char
modifier|*
name|incspec
decl_stmt|;
comment|/* default included file user spec */
block|}
name|SUFFIX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_sfxblk
block|{
name|SUFFIX
name|sfx
decl_stmt|;
comment|/* suffix struct */
name|struct
name|_sfxblk
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next suffix list block */
block|}
name|SFXBLK
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUFFIX_H */
end_comment

end_unit

