begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: path.h,v 4.2 91/11/25 19:45:47 nicklin Exp $  *  * Pathname definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_H
end_ifndef

begin_define
define|#
directive|define
name|PATH_H
end_define

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|ALIASSIZE
value|30
end_define

begin_comment
comment|/* project directory alias size */
end_comment

begin_define
define|#
directive|define
name|TYPESIZE
value|30
end_define

begin_comment
comment|/* project directory type label size */
end_comment

begin_define
define|#
directive|define
name|DIRDESCSIZE
value|128
end_define

begin_comment
comment|/* project directory description size */
end_comment

begin_define
define|#
directive|define
name|P_BUFSIZE
value|1024
end_define

begin_comment
comment|/* pathname buffer size */
end_comment

begin_define
define|#
directive|define
name|PATHSIZE
value|1024
end_define

begin_comment
comment|/* maximum pathname length */
end_comment

begin_define
define|#
directive|define
name|PPATHSIZE
value|256
end_define

begin_comment
comment|/* maximum project pathname length */
end_comment

begin_define
define|#
directive|define
name|TYPBUFSIZE
value|256
end_define

begin_comment
comment|/* directory type labels buffer */
end_comment

begin_comment
comment|/*   * Nomenclature (WARNING: Check definition usage BEFORE changing)  */
end_comment

begin_define
define|#
directive|define
name|_CDIRC
value|'.'
end_define

begin_comment
comment|/* current directory character */
end_comment

begin_define
define|#
directive|define
name|_HDIRC
value|'~'
end_define

begin_comment
comment|/* home directory character */
end_comment

begin_define
define|#
directive|define
name|_PDIRC
value|'^'
end_define

begin_comment
comment|/* project root directory character */
end_comment

begin_define
define|#
directive|define
name|_PDTSC
value|'/'
end_define

begin_comment
comment|/* project dir type labels sep char */
end_comment

begin_define
define|#
directive|define
name|_PPSC
value|'^'
end_define

begin_comment
comment|/* project path separator character */
end_comment

begin_define
define|#
directive|define
name|_PSC
value|'/'
end_define

begin_comment
comment|/* pathname separator character */
end_comment

begin_define
define|#
directive|define
name|_RDIRC
value|'/'
end_define

begin_comment
comment|/* root directory character */
end_comment

begin_define
define|#
directive|define
name|CURDIR
value|"."
end_define

begin_comment
comment|/* current directory */
end_comment

begin_define
define|#
directive|define
name|PARENTDIR
value|".."
end_define

begin_comment
comment|/* parent directory */
end_comment

begin_define
define|#
directive|define
name|PATHSEP
value|"/"
end_define

begin_comment
comment|/* pathname separator */
end_comment

begin_define
define|#
directive|define
name|PPATHSEP
value|"^"
end_define

begin_comment
comment|/* project pathname separator */
end_comment

begin_define
define|#
directive|define
name|ROOTDIR
value|"/"
end_define

begin_comment
comment|/* root directory */
end_comment

begin_define
define|#
directive|define
name|ROOTPROJECT
value|"^"
end_define

begin_comment
comment|/* root project */
end_comment

begin_define
define|#
directive|define
name|USERPROJECT
value|"~"
end_define

begin_comment
comment|/* user's root project */
end_comment

begin_comment
comment|/*  * Pathname types  */
end_comment

begin_define
define|#
directive|define
name|P_IFMT
value|0xf0000
end_define

begin_comment
comment|/* project pathname mask */
end_comment

begin_define
define|#
directive|define
name|P_IFNEW
value|0x00000
end_define

begin_comment
comment|/* new directory or file */
end_comment

begin_define
define|#
directive|define
name|P_IFREG
value|0x10000
end_define

begin_comment
comment|/* regular directory or file */
end_comment

begin_define
define|#
directive|define
name|P_IFHOME
value|0x20000
end_define

begin_comment
comment|/* root project root directory */
end_comment

begin_define
define|#
directive|define
name|P_IFPDIR
value|0x30000
end_define

begin_comment
comment|/* project directory */
end_comment

begin_define
define|#
directive|define
name|P_IFPROOT
value|0x40000
end_define

begin_comment
comment|/* project root directory */
end_comment

begin_comment
comment|/*  * Pathname struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_path
block|{
name|unsigned
name|long
name|p_mode
decl_stmt|;
comment|/* type of pathname */
name|char
modifier|*
name|p_alias
decl_stmt|;
comment|/* pathname alias */
name|char
modifier|*
name|p_path
decl_stmt|;
comment|/* pathname */
name|char
modifier|*
name|p_type
decl_stmt|;
comment|/* project directory type labels */
name|char
modifier|*
name|p_desc
decl_stmt|;
comment|/* project directory description */
name|char
name|p_buf
index|[
name|P_BUFSIZE
index|]
decl_stmt|;
comment|/* pathname buffer */
name|char
name|p_project
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* pathname's project */
block|}
name|PATH
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATH_H */
end_comment

end_unit

