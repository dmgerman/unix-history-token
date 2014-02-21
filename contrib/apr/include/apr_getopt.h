begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_GETOPT_H
end_ifndef

begin_define
define|#
directive|define
name|APR_GETOPT_H
end_define

begin_comment
comment|/**  * @file apr_getopt.h  * @brief APR Command Arguments (getopt)  */
end_comment

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/* __cplusplus */
comment|/**  * @defgroup apr_getopt Command Argument Parsing  * @ingroup APR   * @{  */
comment|/**   * An @c apr_getopt_t error callback function.  *  * @a arg is this @c apr_getopt_t's @c errarg member.  */
typedef|typedef
name|void
function_decl|(
name|apr_getopt_err_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|err
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/** @see apr_getopt_t */
typedef|typedef
name|struct
name|apr_getopt_t
name|apr_getopt_t
typedef|;
comment|/**  * Structure to store command line argument information.  */
struct|struct
name|apr_getopt_t
block|{
comment|/** context for processing */
name|apr_pool_t
modifier|*
name|cont
decl_stmt|;
comment|/** function to print error message (NULL == no messages) */
name|apr_getopt_err_fn_t
modifier|*
name|errfn
decl_stmt|;
comment|/** user defined first arg to pass to error message  */
name|void
modifier|*
name|errarg
decl_stmt|;
comment|/** index into parent argv vector */
name|int
name|ind
decl_stmt|;
comment|/** character checked for validity */
name|int
name|opt
decl_stmt|;
comment|/** reset getopt */
name|int
name|reset
decl_stmt|;
comment|/** count of arguments */
name|int
name|argc
decl_stmt|;
comment|/** array of pointers to arguments */
specifier|const
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/** argument associated with option */
name|char
specifier|const
modifier|*
name|place
decl_stmt|;
comment|/** set to nonzero to support interleaving options with regular args */
name|int
name|interleave
decl_stmt|;
comment|/** start of non-option arguments skipped for interleaving */
name|int
name|skip_start
decl_stmt|;
comment|/** end of non-option arguments skipped for interleaving */
name|int
name|skip_end
decl_stmt|;
block|}
struct|;
comment|/** @see apr_getopt_option_t */
typedef|typedef
name|struct
name|apr_getopt_option_t
name|apr_getopt_option_t
typedef|;
comment|/**  * Structure used to describe options that getopt should search for.  */
struct|struct
name|apr_getopt_option_t
block|{
comment|/** long option name, or NULL if option has no long name */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** option letter, or a value greater than 255 if option has no letter */
name|int
name|optch
decl_stmt|;
comment|/** nonzero if option takes an argument */
name|int
name|has_arg
decl_stmt|;
comment|/** a description of the option */
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
comment|/**  * Initialize the arguments for parsing by apr_getopt().  * @param os   The options structure created for apr_getopt()  * @param cont The pool to operate on  * @param argc The number of arguments to parse  * @param argv The array of arguments to parse  * @remark Arguments 3 and 4 are most commonly argc and argv from main(argc, argv)  * The (*os)->errfn is initialized to fprintf(stderr... but may be overridden.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_getopt_init
argument_list|(
argument|apr_getopt_t **os
argument_list|,
argument|apr_pool_t *cont
argument_list|,
argument|int argc
argument_list|,
argument|const char * const *argv
argument_list|)
empty_stmt|;
comment|/**  * Parse the options initialized by apr_getopt_init().  * @param os     The apr_opt_t structure returned by apr_getopt_init()  * @param opts   A string of characters that are acceptable options to the   *               program.  Characters followed by ":" are required to have an   *               option associated  * @param option_ch  The next option character parsed  * @param option_arg The argument following the option character:  * @return There are four potential status values on exit. They are:  *<PRE>  *             APR_EOF      --  No more options to parse  *             APR_BADCH    --  Found a bad option character  *             APR_BADARG   --  No argument followed the option flag  *             APR_SUCCESS  --  The next option was found.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_getopt
argument_list|(
name|apr_getopt_t
operator|*
name|os
argument_list|,
specifier|const
name|char
operator|*
name|opts
argument_list|,
name|char
operator|*
name|option_ch
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|option_arg
argument_list|)
expr_stmt|;
comment|/**  * Parse the options initialized by apr_getopt_init(), accepting long  * options beginning with "--" in addition to single-character  * options beginning with "-".  * @param os     The apr_getopt_t structure created by apr_getopt_init()  * @param opts   A pointer to a list of apr_getopt_option_t structures, which  *               can be initialized with { "name", optch, has_args }.  has_args  *               is nonzero if the option requires an argument.  A structure  *               with an optch value of 0 terminates the list.  * @param option_ch  Receives the value of "optch" from the apr_getopt_option_t  *                   structure corresponding to the next option matched.  * @param option_arg Receives the argument following the option, if any.  * @return There are four potential status values on exit.   They are:  *<PRE>  *             APR_EOF      --  No more options to parse  *             APR_BADCH    --  Found a bad option character  *             APR_BADARG   --  No argument followed the option flag  *             APR_SUCCESS  --  The next option was found.  *</PRE>  * When APR_SUCCESS is returned, os->ind gives the index of the first  * non-option argument.  On error, a message will be printed to stdout unless  * os->err is set to 0.  If os->interleave is set to nonzero, options can come  * after arguments, and os->argv will be permuted to leave non-option arguments  * at the end (the original argv is unaffected).  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_getopt_long
argument_list|(
name|apr_getopt_t
operator|*
name|os
argument_list|,
specifier|const
name|apr_getopt_option_t
operator|*
name|opts
argument_list|,
name|int
operator|*
name|option_ch
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|option_arg
argument_list|)
expr_stmt|;
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
comment|/* ! APR_GETOPT_H */
end_comment

end_unit

