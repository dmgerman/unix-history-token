begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * apu.h is generated from apu.h.in by configure -- do not edit apu.h  */
end_comment

begin_comment
comment|/* @file apu.h  * @brief APR-Utility main file  */
end_comment

begin_comment
comment|/**  * @defgroup APR_Util APR Utility Functions  * @{  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_H
end_ifndef

begin_define
define|#
directive|define
name|APU_H
end_define

begin_comment
comment|/**  * APU_DECLARE_EXPORT is defined when building the APR-UTIL dynamic library,  * so that all public symbols are exported.  *  * APU_DECLARE_STATIC is defined when including the APR-UTIL public headers,  * to provide static linkage when the dynamic library may be unavailable.  *  * APU_DECLARE_STATIC and APU_DECLARE_EXPORT are left undefined when  * including the APR-UTIL public headers, to import and link the symbols from   * the dynamic APR-UTIL library and assure appropriate indirection and calling  * conventions at compile time.  */
end_comment

begin_comment
comment|/**  * The public APR-UTIL functions are declared with APU_DECLARE(), so they may  * use the most appropriate calling convention.  Public APR functions with   * variable arguments must use APU_DECLARE_NONSTD().  *  * @deffunc APU_DECLARE(rettype) apr_func(args);  */
end_comment

begin_define
define|#
directive|define
name|APU_DECLARE
parameter_list|(
name|type
parameter_list|)
value|type
end_define

begin_comment
comment|/**  * The public APR-UTIL functions using variable arguments are declared with   * APU_DECLARE_NONSTD(), as they must use the C language calling convention.  *  * @deffunc APU_DECLARE_NONSTD(rettype) apr_func(args, ...);  */
end_comment

begin_define
define|#
directive|define
name|APU_DECLARE_NONSTD
parameter_list|(
name|type
parameter_list|)
value|type
end_define

begin_comment
comment|/**  * The public APR-UTIL variables are declared with APU_DECLARE_DATA.  * This assures the appropriate indirection is invoked at compile time.  *  * @deffunc APU_DECLARE_DATA type apr_variable;  * @tip APU_DECLARE_DATA extern type apr_variable; syntax is required for  * declarations within headers to properly import the variable.  */
end_comment

begin_define
define|#
directive|define
name|APU_DECLARE_DATA
end_define

begin_comment
comment|/*  * we always have SDBM (it's in our codebase)  */
end_comment

begin_define
define|#
directive|define
name|APU_HAVE_SDBM
value|1
end_define

begin_define
define|#
directive|define
name|APU_HAVE_GDBM
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_NDBM
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_DB
value|0
end_define

begin_if
if|#
directive|if
name|APU_HAVE_DB
end_if

begin_define
define|#
directive|define
name|APU_HAVE_DB_VERSION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APU_HAVE_DB */
end_comment

begin_define
define|#
directive|define
name|APU_HAVE_PGSQL
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_MYSQL
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_SQLITE3
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_SQLITE2
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_APR_ICONV
value|0
end_define

begin_define
define|#
directive|define
name|APU_HAVE_ICONV
value|0
end_define

begin_define
define|#
directive|define
name|APR_HAS_XLATE
value|(APU_HAVE_APR_ICONV || APU_HAVE_ICONV)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APU_H */
end_comment

begin_comment
comment|/** @} */
end_comment

end_unit

