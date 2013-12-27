begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * sdbm - ndbm work-alike hashed database library  * tuning and portability constructs [not nearly enough]  * author: oz@nexus.yorku.ca  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDBM_TUNE_H
end_ifndef

begin_define
define|#
directive|define
name|SDBM_TUNE_H
end_define

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_comment
comment|/* ### this might be better off as sizeof(char *) */
end_comment

begin_define
define|#
directive|define
name|BYTESIZ
value|8
end_define

begin_comment
comment|/*  * misc  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
value|printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDBM_TUNE_H */
end_comment

end_unit

