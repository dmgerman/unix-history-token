begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_comment
comment|/* configuration data */
end_comment

begin_comment
comment|/**  * @file apu_want.h  * @brief APR Standard Headers Support  *  *<PRE>  * Features:  *  *   APU_WANT_DB:<db.h>  *  * Typical usage:  *  *   #define APU_WANT_DB  *   #include "apu_want.h"  *  * The appropriate headers will be included.  *  * Note: it is safe to use this in a header (it won't interfere with other  *       headers' or source files' use of apu_want.h)  *</PRE>  */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|APU_WANT_DB
end_ifdef

begin_if
if|#
directive|if
name|APU_HAVE_DB
end_if

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|APU_WANT_DB
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

end_unit

