begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INHERIT_H
end_ifndef

begin_define
define|#
directive|define
name|INHERIT_H
end_define

begin_include
include|#
directive|include
file|"apr_inherit.h"
end_include

begin_define
define|#
directive|define
name|APR_INHERIT
value|(1<< 24)
end_define

begin_comment
comment|/* Must not conflict with other bits */
end_comment

begin_define
define|#
directive|define
name|APR_IMPLEMENT_INHERIT_SET
parameter_list|(
name|name
parameter_list|,
name|flag
parameter_list|,
name|pool
parameter_list|,
name|cleanup
parameter_list|)
define|\
value|apr_status_t apr_##name##_inherit_set(apr_##name##_t *the##name)    \ {                                                                   \     if (the##name->flag& APR_FOPEN_NOCLEANUP)                      \         return APR_EINVAL;                                          \     if (!(the##name->flag& APR_INHERIT)) {                         \         int flags = fcntl(the##name->name##des, F_GETFD);           \         if (flags == -1)                                            \             return errno;                                           \         flags&= ~(FD_CLOEXEC);                                     \         if (fcntl(the##name->name##des, F_SETFD, flags) == -1)      \             return errno;                                           \         the##name->flag |= APR_INHERIT;                             \         apr_pool_child_cleanup_set(the##name->pool,                 \                                    (void *)the##name,               \                                    cleanup, apr_pool_cleanup_null); \     }                                                               \     return APR_SUCCESS;                                             \ }
end_define

begin_define
define|#
directive|define
name|APR_IMPLEMENT_INHERIT_UNSET
parameter_list|(
name|name
parameter_list|,
name|flag
parameter_list|,
name|pool
parameter_list|,
name|cleanup
parameter_list|)
define|\
value|apr_status_t apr_##name##_inherit_unset(apr_##name##_t *the##name)  \ {                                                                   \     if (the##name->flag& APR_FOPEN_NOCLEANUP)                      \         return APR_EINVAL;                                          \     if (the##name->flag& APR_INHERIT) {                            \         int flags;                                                  \         if ((flags = fcntl(the##name->name##des, F_GETFD)) == -1)   \             return errno;                                           \         flags |= FD_CLOEXEC;                                        \         if (fcntl(the##name->name##des, F_SETFD, flags) == -1)      \             return errno;                                           \         the##name->flag&= ~APR_INHERIT;                            \         apr_pool_child_cleanup_set(the##name->pool,                 \                                    (void *)the##name,               \                                    cleanup, cleanup);               \     }                                                               \     return APR_SUCCESS;                                             \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! INHERIT_H */
end_comment

end_unit

