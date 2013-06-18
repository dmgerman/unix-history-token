begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_OPTIONAL_H
end_ifndef

begin_define
define|#
directive|define
name|APR_OPTIONAL_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_comment
comment|/**   * @file apr_optional.h  * @brief APR-UTIL registration of functions exported by modules  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**   * @defgroup APR_Util_Opt Optional Functions  * @ingroup APR_Util  *  * Typesafe registration and retrieval of functions that may not be present  * (i.e. functions exported by optional modules)  * @{  */
comment|/**  * The type of an optional function.  * @param name The name of the function  */
define|#
directive|define
name|APR_OPTIONAL_FN_TYPE
parameter_list|(
name|name
parameter_list|)
value|apr_OFN_##name##_t
comment|/**  * Declare an optional function.  * @param ret The return type of the function  * @param name The name of the function  * @param args The function arguments (including brackets)  */
define|#
directive|define
name|APR_DECLARE_OPTIONAL_FN
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|typedef ret (APR_OPTIONAL_FN_TYPE(name)) args
comment|/**  * XXX: This doesn't belong here, then!  * Private function! DO NOT USE!   * @internal  */
typedef|typedef
name|void
function_decl|(
name|apr_opt_fn_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** @internal */
name|APU_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
name|apr_dynamic_fn_register
argument_list|(
specifier|const
name|char
operator|*
name|szName
argument_list|,
name|apr_opt_fn_t
operator|*
name|pfn
argument_list|)
expr_stmt|;
comment|/**  * Register an optional function. This can be later retrieved, type-safely, by  * name. Like all global functions, the name must be unique. Note that,  * confusingly but correctly, the function itself can be static!  * @param name The name of the function  */
define|#
directive|define
name|APR_REGISTER_OPTIONAL_FN
parameter_list|(
name|name
parameter_list|)
value|do { \   APR_OPTIONAL_FN_TYPE(name) *apu__opt = name; \   apr_dynamic_fn_register(#name,(apr_opt_fn_t *)apu__opt); \ } while (0)
comment|/** @internal  * Private function! DO NOT USE!   */
name|APU_DECLARE
argument_list|(
argument|apr_opt_fn_t *
argument_list|)
name|apr_dynamic_fn_retrieve
argument_list|(
specifier|const
name|char
operator|*
name|szName
argument_list|)
expr_stmt|;
comment|/**  * Retrieve an optional function. Returns NULL if the function is not present.  * @param name The name of the function  */
define|#
directive|define
name|APR_RETRIEVE_OPTIONAL_FN
parameter_list|(
name|name
parameter_list|)
define|\
value|(APR_OPTIONAL_FN_TYPE(name) *)apr_dynamic_fn_retrieve(#name)
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_OPTIONAL_H */
end_comment

end_unit

