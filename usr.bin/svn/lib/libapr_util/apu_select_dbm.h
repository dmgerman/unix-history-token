begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_SELECT_DBM_H
end_ifndef

begin_define
define|#
directive|define
name|APU_SELECT_DBM_H
end_define

begin_comment
comment|/* ** The following macros control what features APRUTIL will use */
end_comment

begin_define
define|#
directive|define
name|APU_USE_SDBM
value|1
end_define

begin_define
define|#
directive|define
name|APU_USE_NDBM
value|0
end_define

begin_define
define|#
directive|define
name|APU_USE_GDBM
value|0
end_define

begin_define
define|#
directive|define
name|APU_USE_DB
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APU_SELECT_DBM_H */
end_comment

end_unit

