begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_error.h  * @brief Common exception handling for Subversion.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_ERROR_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_size_t */
end_comment

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_comment
comment|/* APR's error system */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOXYGEN_SHOULD_SKIP_THIS
end_ifndef

begin_define
define|#
directive|define
name|APR_WANT_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<apr_want.h>
end_include

begin_comment
comment|/* for FILE* */
end_comment

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/* For the Subversion developers, this #define turns on extended "stack    traces" of any errors that get thrown. See the SVN_ERR() macro.  */
ifdef|#
directive|ifdef
name|SVN_DEBUG
define|#
directive|define
name|SVN_ERR__TRACING
endif|#
directive|endif
comment|/** the best kind of (@c svn_error_t *) ! */
define|#
directive|define
name|SVN_NO_ERROR
value|0
comment|/* The actual error codes are kept in a separate file; see comments    there for the reasons why. */
include|#
directive|include
file|"svn_error_codes.h"
comment|/** Put an English description of @a statcode into @a buf and return @a buf,  * NULL-terminated. @a statcode is either an svn error or apr error.  */
name|char
modifier|*
name|svn_strerror
parameter_list|(
name|apr_status_t
name|statcode
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|apr_size_t
name|bufsize
parameter_list|)
function_decl|;
comment|/**  * Return the symbolic name of an error code.  If the error code  * is in svn_error_codes.h, return the name of the macro as a string.  * If the error number is not recognised, return @c NULL.  *  * An error number may not be recognised because it was defined in a future  * version of Subversion (e.g., a 1.9.x server may transmit a defined-in-1.9.0  * error number to a 1.8.x client).  *  * An error number may be recognised @em incorrectly if the @c apr_status_t  * value originates in another library (such as libserf) which also uses APR.  * (This is a theoretical concern only: the @c apr_err member of #svn_error_t  * should never contain a "foreign" @c apr_status_t value, and  * in any case Subversion and Serf use non-overlapping subsets of the  * @c APR_OS_START_USERERR range.)  *  * Support for error codes returned by APR itself (i.e., not in the  * @c APR_OS_START_USERERR range, as defined in apr_errno.h) may be implemented  * in the future.  *  * @note In rare cases, a single numeric code has more than one symbolic name.  * (For example, #SVN_ERR_WC_NOT_DIRECTORY and #SVN_ERR_WC_NOT_WORKING_COPY).  * In those cases, it is not guaranteed which symbolic name is returned.  *  * @since New in 1.8.  */
specifier|const
name|char
modifier|*
name|svn_error_symbolic_name
parameter_list|(
name|apr_status_t
name|statcode
parameter_list|)
function_decl|;
comment|/** If @a err has a custom error message, return that, otherwise  * store the generic error string associated with @a err->apr_err into  * @a buf (terminating with NULL) and return @a buf.  *  * @since New in 1.4.  *  * @note @a buf and @a bufsize are provided in the interface so that  * this function is thread-safe and yet does no allocation.  */
specifier|const
name|char
modifier|*
name|svn_err_best_message
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|apr_size_t
name|bufsize
parameter_list|)
function_decl|;
comment|/** SVN error creation and destruction.  *  * @defgroup svn_error_error_creation_destroy Error creation and destruction  * @{  */
comment|/** Create a nested exception structure.  *  * Input:  an APR or SVN custom error code,  *         a "child" error to wrap,  *         a specific message  *  * Returns:  a new error structure (containing the old one).  *  * @note Errors are always allocated in a subpool of the global pool,  *        since an error's lifetime is generally not related to the  *        lifetime of any convenient pool.  Errors must be freed  *        with svn_error_clear().  The specific message should be @c NULL  *        if there is nothing to add to the general message associated  *        with the error code.  *  *        If creating the "bottommost" error in a chain, pass @c NULL for  *        the child argument.  */
name|svn_error_t
modifier|*
name|svn_error_create
parameter_list|(
name|apr_status_t
name|apr_err
parameter_list|,
name|svn_error_t
modifier|*
name|child
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
comment|/** Create an error structure with the given @a apr_err and @a child,  * with a printf-style error message produced by passing @a fmt, using  * apr_psprintf().  */
name|svn_error_t
modifier|*
name|svn_error_createf
parameter_list|(
name|apr_status_t
name|apr_err
parameter_list|,
name|svn_error_t
modifier|*
name|child
parameter_list|,
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
function_decl|3
operator|,
function_decl|4
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** Wrap a @a status from an APR function.  If @a fmt is NULL, this is  * equivalent to svn_error_create(status,NULL,NULL).  Otherwise,  * the error message is constructed by formatting @a fmt and the  * following arguments according to apr_psprintf(), and then  * appending ": " and the error message corresponding to @a status.  * (If UTF-8 translation of the APR error message fails, the ": " and  * APR error are not appended to the error message.)  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_wrap_apr
parameter_list|(
name|apr_status_t
name|status
parameter_list|,
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
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/** A quick n' easy way to create a wrapped exception with your own  * message, before throwing it up the stack.  (It uses all of the  * @a child's fields.)  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_quick_wrap
parameter_list|(
name|svn_error_t
modifier|*
name|child
parameter_list|,
specifier|const
name|char
modifier|*
name|new_msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Compose two errors, returning the composition as a brand new error  * and consuming the original errors.  Either or both of @a err1 and  * @a err2 may be @c SVN_NO_ERROR.  If both are not @c SVN_NO_ERROR,  * @a err2 will follow @a err1 in the chain of the returned error.  *  * Either @a err1 or @a err2 can be functions that return svn_error_t*  * but if both are functions they can be evaluated in either order as  * per the C language rules.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_compose_create
parameter_list|(
name|svn_error_t
modifier|*
name|err1
parameter_list|,
name|svn_error_t
modifier|*
name|err2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Add @a new_err to the end of @a chain's chain of errors.  The @a new_err  * chain will be copied into @a chain's pool and destroyed, so @a new_err  * itself becomes invalid after this function.  *  * Either @a chain or @a new_err can be functions that return svn_error_t*  * but if both are functions they can be evaluated in either order as  * per the C language rules.  */
end_comment

begin_function_decl
name|void
name|svn_error_compose
parameter_list|(
name|svn_error_t
modifier|*
name|chain
parameter_list|,
name|svn_error_t
modifier|*
name|new_err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return the root cause of @a err by finding the last error in its  * chain (e.g. it or its children).  @a err may be @c SVN_NO_ERROR, in  * which case @c SVN_NO_ERROR is returned.  *  * @since New in 1.5.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_root_cause
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Return the first error in @a err's chain that has an error code @a  * apr_err or #SVN_NO_ERROR if there is no error with that code.  The  * returned error should @em not be cleared as it shares memory with @a err.  *  * If @a err is #SVN_NO_ERROR, return #SVN_NO_ERROR.  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_find_cause
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|apr_status_t
name|apr_err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Create a new error that is a deep copy of @a err and return it.  *  * @since New in 1.2.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_dup
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Free the memory used by @a error, as well as all ancestors and  * descendants of @a error.  *  * Unlike other Subversion objects, errors are managed explicitly; you  * MUST clear an error if you are ignoring it, or you are leaking memory.  * For convenience, @a error may be @c NULL, in which case this function does  * nothing; thus, svn_error_clear(svn_foo(...)) works as an idiom to  * ignore errors.  */
end_comment

begin_function_decl
name|void
name|svn_error_clear
parameter_list|(
name|svn_error_t
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVN_ERR__TRACING
argument_list|)
end_if

begin_comment
comment|/** Set the error location for debug mode. */
end_comment

begin_function_decl
name|void
name|svn_error__locate
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|long
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wrapper macros to collect file and line information */
end_comment

begin_define
define|#
directive|define
name|svn_error_create
define|\
value|(svn_error__locate(__FILE__,__LINE__), (svn_error_create))
end_define

begin_define
define|#
directive|define
name|svn_error_createf
define|\
value|(svn_error__locate(__FILE__,__LINE__), (svn_error_createf))
end_define

begin_define
define|#
directive|define
name|svn_error_wrap_apr
define|\
value|(svn_error__locate(__FILE__,__LINE__), (svn_error_wrap_apr))
end_define

begin_define
define|#
directive|define
name|svn_error_quick_wrap
define|\
value|(svn_error__locate(__FILE__,__LINE__), (svn_error_quick_wrap))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Very basic default error handler: print out error stack @a error to the  * stdio stream @a stream, with each error prefixed by @a prefix; quit and  * clear @a error iff the @a fatal flag is set.  Allocations are performed  * in the @a error's pool.  *  * If you're not sure what prefix to pass, just pass "svn: ".  That's  * what code that used to call svn_handle_error() and now calls  * svn_handle_error2() does.  *  * @since New in 1.2.  */
end_comment

begin_function_decl
name|void
name|svn_handle_error2
parameter_list|(
name|svn_error_t
modifier|*
name|error
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|,
name|svn_boolean_t
name|fatal
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Like svn_handle_error2() but with @c prefix set to "svn: "  *  * @deprecated Provided for backward compatibility with the 1.1 API.  */
end_comment

begin_function_decl
name|SVN_DEPRECATED
name|void
name|svn_handle_error
parameter_list|(
name|svn_error_t
modifier|*
name|error
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|,
name|svn_boolean_t
name|fatal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Very basic default warning handler: print out the error @a error to the  * stdio stream @a stream, prefixed by @a prefix.  Allocations are  * performed in the error's pool.  *  * @a error may not be @c NULL.  *  * @since New in 1.2.  */
end_comment

begin_function_decl
name|void
name|svn_handle_warning2
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|svn_error_t
modifier|*
name|error
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Like svn_handle_warning2() but with @c prefix set to "svn: "  *  * @deprecated Provided for backward compatibility with the 1.1 API.  */
end_comment

begin_function_decl
name|SVN_DEPRECATED
name|void
name|svn_handle_warning
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|svn_error_t
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** A statement macro for checking error values.  *  * Evaluate @a expr.  If it yields an error, return that error from the  * current function.  Otherwise, continue.  *  * The<tt>do { ... } while (0)</tt> wrapper has no semantic effect,  * but it makes this macro syntactically equivalent to the expression  * statement it resembles.  Without it, statements like  *  * @code  *   if (a)  *     SVN_ERR(some operation);  *   else  *     foo;  * @endcode  *  * would not mean what they appear to.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                          \     svn_error_t *svn_err__temp = (expr);        \     if (svn_err__temp)                          \       return svn_error_trace(svn_err__temp);    \   } while (0)
end_define

begin_comment
comment|/**  * A macro for wrapping an error in a source-location trace message.  *  * This macro can be used when directly returning an already created  * error (when not using SVN_ERR, svn_error_create(), etc.) to ensure  * that the call stack is recorded correctly.  *  * @since New in 1.7.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_ERR__TRACING
end_ifdef

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error__trace
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|long
name|line
parameter_list|,
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|svn_error_trace
parameter_list|(
name|expr
parameter_list|)
value|svn_error__trace(__FILE__, __LINE__, (expr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|svn_error_trace
parameter_list|(
name|expr
parameter_list|)
value|(expr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Returns an error chain that is based on @a err's error chain but  * does not include any error tracing placeholders.  @a err is not  * modified, except for any allocations using its pool.  *  * The returned error chain is allocated from @a err's pool and shares  * its message and source filename character arrays.  The returned  * error chain should *not* be cleared because it is not a fully  * fledged error chain, only clearing @a err should be done to clear  * the returned error chain.  If @a err is cleared, then the returned  * error chain is unusable.  *  * @a err can be #SVN_NO_ERROR.  If @a err is not #SVN_NO_ERROR, then  * the last link in the error chain must be a non-tracing error, i.e,  * a real error.  *  * @since New in 1.7.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_purge_tracing
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** A statement macro, very similar to @c SVN_ERR.  *  * This macro will wrap the error with the specified text before  * returning the error.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_W
parameter_list|(
name|expr
parameter_list|,
name|wrap_msg
parameter_list|)
define|\
value|do {                                                      \     svn_error_t *svn_err__temp = (expr);                    \     if (svn_err__temp)                                      \       return svn_error_quick_wrap(svn_err__temp, wrap_msg); \   } while (0)
end_define

begin_comment
comment|/** A statement macro, similar to @c SVN_ERR, but returns an integer.  *  * Evaluate @a expr. If it yields an error, handle that error and  * return @c EXIT_FAILURE.  */
end_comment

begin_define
define|#
directive|define
name|SVN_INT_ERR
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                                           \     svn_error_t *svn_err__temp = (expr);                         \     if (svn_err__temp) {                                         \       svn_handle_error2(svn_err__temp, stderr, FALSE, "svn: ");  \       svn_error_clear(svn_err__temp);                            \       return EXIT_FAILURE; }                                     \   } while (0)
end_define

begin_comment
comment|/** @} */
end_comment

begin_escape
end_escape

begin_comment
comment|/** Error groups  *  * @defgroup svn_error_error_groups Error groups  * @{  */
end_comment

begin_comment
comment|/**  * Return TRUE if @a err is an error specifically related to locking a  * path in the repository, FALSE otherwise.  *  * SVN_ERR_FS_OUT_OF_DATE and SVN_ERR_FS_NOT_FOUND are in here because it's a  * non-fatal error that can be thrown when attempting to lock an item.  *  * @since New in 1.2.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_IS_LOCK_ERROR
parameter_list|(
name|err
parameter_list|)
define|\
value|(err->apr_err == SVN_ERR_FS_PATH_ALREADY_LOCKED ||        \    err->apr_err == SVN_ERR_FS_NOT_FOUND           ||        \    err->apr_err == SVN_ERR_FS_OUT_OF_DATE         ||        \    err->apr_err == SVN_ERR_FS_BAD_LOCK_TOKEN)
end_define

begin_comment
comment|/**  * Return TRUE if @a err is an error specifically related to unlocking  * a path in the repository, FALSE otherwise.  *  * @since New in 1.2.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_IS_UNLOCK_ERROR
parameter_list|(
name|err
parameter_list|)
define|\
value|(err->apr_err == SVN_ERR_FS_PATH_NOT_LOCKED ||            \    err->apr_err == SVN_ERR_FS_BAD_LOCK_TOKEN ||             \    err->apr_err == SVN_ERR_FS_LOCK_OWNER_MISMATCH ||        \    err->apr_err == SVN_ERR_FS_NO_SUCH_LOCK ||               \    err->apr_err == SVN_ERR_RA_NOT_LOCKED ||                 \    err->apr_err == SVN_ERR_FS_LOCK_EXPIRED)
end_define

begin_comment
comment|/** Evaluates to @c TRUE iff @a apr_err (of type apr_status_t) is in the given  * @a category, which should be one of the @c SVN_ERR_*_CATEGORY_START  * constants.  *  * @since New in 1.7.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERROR_IN_CATEGORY
parameter_list|(
name|apr_err
parameter_list|,
name|category
parameter_list|)
define|\
value|((category) == ((apr_err) / SVN_ERR_CATEGORY_SIZE) * SVN_ERR_CATEGORY_SIZE)
end_define

begin_comment
comment|/** @} */
end_comment

begin_escape
end_escape

begin_comment
comment|/** Internal malfunctions and assertions  *  * @defgroup svn_error_malfunction_assertion Malfunctions and assertions  * @{  */
end_comment

begin_comment
comment|/** Report that an internal malfunction has occurred, and possibly terminate  * the program.  *  * Act as determined by the current "malfunction handler" which may have  * been specified by a call to svn_error_set_malfunction_handler() or else  * is the default handler as specified in that function's documentation. If  * the malfunction handler returns, then cause the function using this macro  * to return the error object that it generated.  *  * @note The intended use of this macro is where execution reaches a point  * that cannot possibly be reached unless there is a bug in the program.  *  * @since New in 1.6.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_MALFUNCTION
parameter_list|()
define|\
value|do {                                                             \     return svn_error_trace(svn_error__malfunction(                 \                                  TRUE, __FILE__, __LINE__, NULL)); \   } while (0)
end_define

begin_comment
comment|/** Similar to SVN_ERR_MALFUNCTION(), but without the option of returning  * an error to the calling function.  *  * If possible you should use SVN_ERR_MALFUNCTION() instead.  *  * @since New in 1.6.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_MALFUNCTION_NO_RETURN
parameter_list|()
define|\
value|do {                                                       \     svn_error__malfunction(FALSE, __FILE__, __LINE__, NULL); \     abort();                                                 \   } while (1)
end_define

begin_comment
comment|/** Like SVN_ERR_ASSERT(), but append ERR to the returned error chain.  *  * If EXPR is false, return a malfunction error whose chain includes ERR.  * If EXPR is true, do nothing.  (In particular, this does not clear ERR.)  *  * Types: (svn_boolean_t expr, svn_error_t *err)  *  * @since New in 1.8.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__clang_analyzer__
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/* Just ignore ERR.  If the assert triggers, it'll be our least concern. */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_ASSERT_E
parameter_list|(
name|expr
parameter_list|,
name|err
parameter_list|)
value|assert((expr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SVN_ERR_ASSERT_E
parameter_list|(
name|expr
parameter_list|,
name|err
parameter_list|)
define|\
value|do {                                                                  \     if (!(expr)) {                                                      \       return svn_error_compose_create(                                  \                svn_error__malfunction(TRUE, __FILE__, __LINE__, #expr), \                (err));                                                  \     }                                                                   \   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Check that a condition is true: if not, report an error and possibly  * terminate the program.  *  * If the Boolean expression @a expr is true, do nothing. Otherwise,  * act as determined by the current "malfunction handler" which may have  * been specified by a call to svn_error_set_malfunction_handler() or else  * is the default handler as specified in that function's documentation. If  * the malfunction handler returns, then cause the function using this macro  * to return the error object that it generated.  *  * @note The intended use of this macro is to check a condition that cannot  * possibly be false unless there is a bug in the program.  *  * @note The condition to be checked should not be computationally expensive  * if it is reached often, as, unlike traditional "assert" statements, the  * evaluation of this expression is not compiled out in release-mode builds.  *  * @since New in 1.6.  *  * @see SVN_ERR_ASSERT_E()  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__clang_analyzer__
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|SVN_ERR_ASSERT
parameter_list|(
name|expr
parameter_list|)
value|assert((expr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SVN_ERR_ASSERT
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                                                  \     if (!(expr))                                                        \       SVN_ERR(svn_error__malfunction(TRUE, __FILE__, __LINE__, #expr)); \   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Similar to SVN_ERR_ASSERT(), but without the option of returning  * an error to the calling function.  *  * If possible you should use SVN_ERR_ASSERT() instead.  *  * @since New in 1.6.  */
end_comment

begin_define
define|#
directive|define
name|SVN_ERR_ASSERT_NO_RETURN
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {                                                          \     if (!(expr)) {                                              \       svn_error__malfunction(FALSE, __FILE__, __LINE__, #expr); \       abort();                                                  \     }                                                           \   } while (0)
end_define

begin_comment
comment|/** Report a "Not implemented" malfunction.  Internal use only. */
end_comment

begin_define
define|#
directive|define
name|SVN__NOT_IMPLEMENTED
parameter_list|()
define|\
value|return svn_error__malfunction(TRUE, __FILE__, __LINE__, "Not implemented.")
end_define

begin_comment
comment|/** A helper function for the macros that report malfunctions. Handle a  * malfunction by calling the current "malfunction handler" which may have  * been specified by a call to svn_error_set_malfunction_handler() or else  * is the default handler as specified in that function's documentation.  *  * Pass all of the parameters to the handler. The error occurred in the  * source file @a file at line @a line, and was an assertion failure of the  * expression @a expr, or, if @a expr is null, an unconditional error.  *  * If @a can_return is true, the handler can return an error object  * that is returned by the caller. If @a can_return is false the  * method should never return. (The caller will call abort())  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error__malfunction
parameter_list|(
name|svn_boolean_t
name|can_return
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** A type of function that handles an assertion failure or other internal  * malfunction detected within the Subversion libraries.  *  * The error occurred in the source file @a file at line @a line, and was an  * assertion failure of the expression @a expr, or, if @a expr is null, an  * unconditional error.  *  * If @a can_return is false a function of this type must never return.  *  * If @a can_return is true a function of this type must do one of:  *   - Return an error object describing the error, using an error code in  *     the category SVN_ERR_MALFUNC_CATEGORY_START.  *   - Never return.  *  * The function may alter its behaviour according to compile-time  * and run-time and even interactive conditions.  *  * @see SVN_ERROR_IN_CATEGORY()  *  * @since New in 1.6.  */
end_comment

begin_typedef
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_error_malfunction_handler_t
function_decl|)
parameter_list|(
name|svn_boolean_t
name|can_return
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|expr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** Cause subsequent malfunctions to be handled by @a func.  * Return the handler that was previously in effect.  *  * @a func may not be null.  *  * @note The default handler is svn_error_abort_on_malfunction().  *  * @note This function must be called in a single-threaded context.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_malfunction_handler_t
name|svn_error_set_malfunction_handler
parameter_list|(
name|svn_error_malfunction_handler_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Handle a malfunction by returning an error object that describes it.  *  * When @a can_return is false, abort()  *  * This function implements @c svn_error_malfunction_handler_t.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_raise_on_malfunction
parameter_list|(
name|svn_boolean_t
name|can_return
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Handle a malfunction by printing a message to stderr and aborting.  *  * This function implements @c svn_error_malfunction_handler_t.  *  * @since New in 1.6.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_error_abort_on_malfunction
parameter_list|(
name|svn_boolean_t
name|can_return
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
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
comment|/* SVN_ERROR_H */
end_comment

end_unit

