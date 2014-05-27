begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_INHERIT_H
end_ifndef

begin_define
define|#
directive|define
name|APR_INHERIT_H
end_define

begin_comment
comment|/**  * @file apr_inherit.h   * @brief APR File Handle Inheritance Helpers  * @remark This internal header includes internal declaration helpers   * for other headers to declare apr_foo_inherit_[un]set functions.  */
end_comment

begin_comment
comment|/**  * Prototype for type-specific declarations of apr_foo_inherit_set   * functions.    * @remark Doxygen unwraps this macro (via doxygen.conf) to provide   * actual help for each specific occurrence of apr_foo_inherit_set.  * @remark the linkage is specified for APR. It would be possible to expand  *       the macros to support other linkages.  */
end_comment

begin_define
define|#
directive|define
name|APR_DECLARE_INHERIT_SET
parameter_list|(
name|type
parameter_list|)
define|\
value|APR_DECLARE(apr_status_t) apr_##type##_inherit_set( \                                           apr_##type##_t *the##type)
end_define

begin_comment
comment|/**  * Prototype for type-specific declarations of apr_foo_inherit_unset   * functions.    * @remark Doxygen unwraps this macro (via doxygen.conf) to provide   * actual help for each specific occurrence of apr_foo_inherit_unset.  * @remark the linkage is specified for APR. It would be possible to expand  *       the macros to support other linkages.  */
end_comment

begin_define
define|#
directive|define
name|APR_DECLARE_INHERIT_UNSET
parameter_list|(
name|type
parameter_list|)
define|\
value|APR_DECLARE(apr_status_t) apr_##type##_inherit_unset( \                                           apr_##type##_t *the##type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_INHERIT_H */
end_comment

end_unit

