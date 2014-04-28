begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_optional_hooks.h  * @brief Apache optional hook functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_OPTIONAL_HOOK_H
end_ifndef

begin_define
define|#
directive|define
name|APR_OPTIONAL_HOOK_H
end_define

begin_include
include|#
directive|include
file|"apr_tables.h"
end_include

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
comment|/**   * @defgroup APR_Util_OPT_HOOK Optional Hook Functions  * @ingroup APR_Util_Hook  * @{  */
comment|/**  * Function to implement the APR_OPTIONAL_HOOK Macro  * @internal  * @see APR_OPTIONAL_HOOK  *  * @param szName The name of the hook  * @param pfn A pointer to a function that will be called  * @param aszPre a NULL-terminated array of strings that name modules whose hooks should precede this one  * @param aszSucc a NULL-terminated array of strings that name modules whose hooks should succeed this one  * @param nOrder an integer determining order before honouring aszPre and aszSucc (for example HOOK_MIDDLE)  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_optional_hook_add
argument_list|(
argument|const char *szName
argument_list|,
argument|void (*pfn)(void)
argument_list|,
argument|const char * const *aszPre
argument_list|,
argument|const char * const *aszSucc
argument_list|,
argument|int nOrder
argument_list|)
empty_stmt|;
comment|/**  * Hook to an optional hook.  *  * @param ns The namespace prefix of the hook functions  * @param name The name of the hook  * @param pfn A pointer to a function that will be called  * @param aszPre a NULL-terminated array of strings that name modules whose hooks should precede this one  * @param aszSucc a NULL-terminated array of strings that name modules whose hooks should succeed this one  * @param nOrder an integer determining order before honouring aszPre and aszSucc (for example HOOK_MIDDLE)  */
define|#
directive|define
name|APR_OPTIONAL_HOOK
parameter_list|(
name|ns
parameter_list|,
name|name
parameter_list|,
name|pfn
parameter_list|,
name|aszPre
parameter_list|,
name|aszSucc
parameter_list|,
name|nOrder
parameter_list|)
value|do { \   ns##_HOOK_##name##_t *apu__hook = pfn; \   apr_optional_hook_add(#name,(void (*)(void))apu__hook,aszPre, aszSucc, nOrder); \ } while (0)
comment|/**  * @internal  * @param szName - the name of the function  * @return the hook structure for a given hook  */
name|APU_DECLARE
argument_list|(
argument|apr_array_header_t *
argument_list|)
name|apr_optional_hook_get
argument_list|(
specifier|const
name|char
operator|*
name|szName
argument_list|)
expr_stmt|;
comment|/**  * Implement an optional hook that runs until one of the functions  * returns something other than OK or DECLINE.  *  * @param ns The namespace prefix of the hook functions  * @param link The linkage declaration prefix of the hook  * @param ret The type of the return value of the hook  * @param ret The type of the return value of the hook  * @param name The name of the hook  * @param args_decl The declaration of the arguments for the hook  * @param args_use The names for the arguments for the hook  * @param ok Success value  * @param decline Decline value  */
define|#
directive|define
name|APR_IMPLEMENT_OPTIONAL_HOOK_RUN_ALL
parameter_list|(
name|ns
parameter_list|,
name|link
parameter_list|,
name|ret
parameter_list|,
name|name
parameter_list|,
name|args_decl
parameter_list|,
name|args_use
parameter_list|,
name|ok
parameter_list|,
name|decline
parameter_list|)
define|\
value|link##_DECLARE(ret) ns##_run_##name args_decl \     { \     ns##_LINK_##name##_t *pHook; \     int n; \     ret rv; \     apr_array_header_t *pHookArray=apr_optional_hook_get(#name); \ \     if(!pHookArray) \ 	return ok; \ \     pHook=(ns##_LINK_##name##_t *)pHookArray->elts; \     for(n=0 ; n< pHookArray->nelts ; ++n) \ 	{ \ 	rv=(pHook[n].pFunc)args_use; \ \ 	if(rv != ok&& rv != decline) \ 	    return rv; \ 	} \     return ok; \     }
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
comment|/* APR_OPTIONAL_HOOK_H */
end_comment

end_unit

