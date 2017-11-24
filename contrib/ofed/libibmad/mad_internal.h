begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAD_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MAD_INTERNAL_H_
end_define

begin_define
define|#
directive|define
name|MAX_CLASS
value|256
end_define

begin_struct
struct|struct
name|ibmad_port
block|{
name|int
name|port_id
decl_stmt|;
comment|/* file descriptor returned by umad_open() */
name|int
name|class_agents
index|[
name|MAX_CLASS
index|]
decl_stmt|;
comment|/* class2agent mapper */
name|int
name|timeout
decl_stmt|,
name|retries
decl_stmt|;
name|uint64_t
name|smp_mkey
decl_stmt|;
name|char
name|ca_name
index|[
name|UMAD_CA_NAME_LEN
index|]
decl_stmt|;
name|int
name|portnum
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ibmad_port
modifier|*
name|ibmp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|madrpc_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|madrpc_retries
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAD_INTERNAL_H_ */
end_comment

end_unit

