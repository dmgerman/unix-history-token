begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* svn_debug.h : handy little debug tools for the SVN developers  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DEBUG_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SVN_DBG__PROTOTYPES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DBG__PROTOTYPES
end_ifdef

begin_define
define|#
directive|define
name|APR_WANT_STDIO
end_define

begin_include
include|#
directive|include
file|<apr_want.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* __cplusplus */
ifdef|#
directive|ifdef
name|SVN_DBG__PROTOTYPES
comment|/* A few helper functions for the macros below.  */
name|void
name|svn_dbg__preamble
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|long
name|line
parameter_list|,
name|FILE
modifier|*
name|output
parameter_list|)
function_decl|;
name|void
name|svn_dbg__printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|svn_dbg__print_props
parameter_list|(
name|apr_hash_t
modifier|*
name|props
parameter_list|,
specifier|const
name|char
modifier|*
name|header_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Only available when SVN_DEBUG is defined (ie. svn developers). Note that    we do *not* provide replacement macros/functions for proper releases.    The debug stuff should be removed before a commit.     ### maybe we will eventually decide to allow certain debug stuff to    ### remain in the code. at that point, we can rejigger this header.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DEBUG
end_ifdef

begin_comment
comment|/* Print to stdout. Edit this line if you need stderr.  */
end_comment

begin_define
define|#
directive|define
name|SVN_DBG_OUTPUT
value|stdout
end_define

begin_comment
comment|/* Defining this symbol in the source file, BEFORE INCLUDING THIS HEADER,    will switch off the output. Calls will still be made to svn_dbg__preamble()    for breakpoints.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DBG_QUIET
end_ifdef

begin_define
define|#
directive|define
name|SVN_DBG
parameter_list|(
name|ARGS
parameter_list|)
value|svn_dbg__preamble(__FILE__, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|SVN_DBG_PROPS
parameter_list|(
name|ARGS
parameter_list|)
value|svn_dbg__preamble(__FILE__, __LINE__, NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/** Debug aid macro that prints the file:line of the call and printf-like  * arguments to the #SVN_DBG_OUTPUT stdio stream (#stdout by default).  Typical  * usage:  *  *<pre>  *   SVN_DBG(("rev=%ld kind=%s\n", revnum, svn_node_kind_to_word(kind)));  *</pre>  *  * outputs:  *  *<pre>  *   DBG: kitchensink.c: 42: rev=3141592 kind=file  *</pre>  *  * Note that these output lines are filtered by our test suite automatically,  * so you don't have to worry about throwing off expected output.  */
end_comment

begin_define
define|#
directive|define
name|SVN_DBG
parameter_list|(
name|ARGS
parameter_list|)
value|(svn_dbg__preamble(__FILE__, __LINE__, SVN_DBG_OUTPUT), \                        svn_dbg__printf ARGS)
end_define

begin_define
define|#
directive|define
name|SVN_DBG_PROPS
parameter_list|(
name|ARGS
parameter_list|)
value|(svn_dbg__preamble(__FILE__, __LINE__, \                                                SVN_DBG_OUTPUT), \                              svn_dbg__print_props ARGS)
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
comment|/* SVN_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_DEBUG_H */
end_comment

end_unit

