begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: macro.h,v 4.4 91/11/25 19:45:47 nicklin Exp $  *  * General macro function definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|"stringx.h"
end_include

begin_undef
undef|#
directive|undef
name|CHDIR
end_undef

begin_define
define|#
directive|define
name|CHDIR
parameter_list|(
name|d
parameter_list|)
define|\
value|(chdir(d) == 0)
end_define

begin_comment
comment|/* change directory */
end_comment

begin_undef
undef|#
directive|undef
name|DOTDIR
end_undef

begin_define
define|#
directive|define
name|DOTDIR
parameter_list|(
name|dp
parameter_list|)
define|\
value|(dp->d_name[0] == '.'&& dp->d_name[1] == '\0')
end_define

begin_comment
comment|/* current directory? */
end_comment

begin_undef
undef|#
directive|undef
name|DOTDOTDIR
end_undef

begin_define
define|#
directive|define
name|DOTDOTDIR
parameter_list|(
name|dp
parameter_list|)
define|\
value|(dp->d_name[0] == '.'&& dp->d_name[1] == '.'&& dp->d_name[2] == '\0')
end_define

begin_comment
comment|/* parent directory? */
end_comment

begin_undef
undef|#
directive|undef
name|EQUAL
end_undef

begin_define
define|#
directive|define
name|EQUAL
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|(strcmp(s1,s2) == 0)
end_define

begin_comment
comment|/* string comparison */
end_comment

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)< (b)) ? (a) : (b))
end_define

begin_comment
comment|/* minimum of two values */
end_comment

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)> (b)) ? (a) : (b))
end_define

begin_comment
comment|/* maximum of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
define|\
value|((m& S_IFMT) == S_IFDIR)
end_define

begin_comment
comment|/* test for directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|WHITESPACE
end_undef

begin_define
define|#
directive|define
name|WHITESPACE
parameter_list|(
name|c
parameter_list|)
define|\
value|(c == ' ' || c == '\t')
end_define

begin_comment
comment|/* unseen space in a file */
end_comment

end_unit

