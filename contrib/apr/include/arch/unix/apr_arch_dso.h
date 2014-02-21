begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DSO_H
end_ifndef

begin_define
define|#
directive|define
name|DSO_H
end_define

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_dso.h"
end_include

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_DSO
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MACH_O_DYLD_H
end_ifdef

begin_include
include|#
directive|include
file|<mach-o/dyld.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DLFCN_H
end_ifdef

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DL_H
end_ifdef

begin_include
include|#
directive|include
file|<dl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_NOW
end_ifndef

begin_define
define|#
directive|define
name|RTLD_NOW
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|RTLD_GLOBAL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DLSYM_NEEDS_UNDERSCORE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|apr_dso_handle_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
specifier|const
name|char
modifier|*
name|errormsg
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

