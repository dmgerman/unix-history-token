begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDBM_PAIR_H
end_ifndef

begin_define
define|#
directive|define
name|SDBM_PAIR_H
end_define

begin_comment
comment|/* Mini EMBED (pair.c) */
end_comment

begin_define
define|#
directive|define
name|chkpage
value|apu__sdbm_chkpage
end_define

begin_define
define|#
directive|define
name|delpair
value|apu__sdbm_delpair
end_define

begin_define
define|#
directive|define
name|duppair
value|apu__sdbm_duppair
end_define

begin_define
define|#
directive|define
name|fitpair
value|apu__sdbm_fitpair
end_define

begin_define
define|#
directive|define
name|getnkey
value|apu__sdbm_getnkey
end_define

begin_define
define|#
directive|define
name|getpair
value|apu__sdbm_getpair
end_define

begin_define
define|#
directive|define
name|putpair
value|apu__sdbm_putpair
end_define

begin_define
define|#
directive|define
name|splpage
value|apu__sdbm_splpage
end_define

begin_function_decl
name|int
name|fitpair
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putpair
parameter_list|(
name|char
modifier|*
parameter_list|,
name|apr_sdbm_datum_t
parameter_list|,
name|apr_sdbm_datum_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_sdbm_datum_t
name|getpair
parameter_list|(
name|char
modifier|*
parameter_list|,
name|apr_sdbm_datum_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|delpair
parameter_list|(
name|char
modifier|*
parameter_list|,
name|apr_sdbm_datum_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkpage
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_sdbm_datum_t
name|getnkey
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|splpage
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|duppair
parameter_list|(
name|char
modifier|*
parameter_list|,
name|apr_sdbm_datum_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDBM_PAIR_H */
end_comment

end_unit

