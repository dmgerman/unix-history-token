begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Isilon Inc http://www.isilon.com/  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  *  * Main header for failpoint facility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FAIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FAIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/**  * Failpoint return codes, used internally.  * @ingroup failpoint_private  */
end_comment

begin_enum
enum|enum
name|fail_point_return_code
block|{
name|FAIL_POINT_RC_CONTINUE
init|=
literal|0
block|,
comment|/**< Continue with normal execution */
name|FAIL_POINT_RC_RETURN
block|,
comment|/**< FP evaluated to 'return' */
name|FAIL_POINT_RC_QUEUED
block|,
comment|/**< sleep_fn will be called */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|fail_point_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fail_point_setting
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Internal failpoint structure, tracking all the current details of the  * failpoint.  This structure is the core component shared between the  * failure-injection code and the user-interface.  * @ingroup failpoint_private  */
end_comment

begin_struct
struct|struct
name|fail_point
block|{
specifier|const
name|char
modifier|*
name|fp_name
decl_stmt|;
comment|/* name of fail point */
specifier|const
name|char
modifier|*
name|fp_location
decl_stmt|;
comment|/* file:line of fail point */
specifier|volatile
name|int
name|fp_ref_cnt
decl_stmt|;
comment|/** 	                             * protects fp_setting: while holding 	                             * a ref, fp_setting points to an 	                             * unfreed fail_point_setting 	                             */
name|struct
name|fail_point_setting
modifier|*
specifier|volatile
name|fp_setting
decl_stmt|;
name|int
name|fp_flags
decl_stmt|;
comment|/**< Function to call before sleep or pause */
name|void
function_decl|(
modifier|*
name|fp_pre_sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**< Arg for fp_pre_sleep_fn */
name|void
modifier|*
name|fp_pre_sleep_arg
decl_stmt|;
comment|/**< Function to call after waking from sleep or pause */
name|void
function_decl|(
modifier|*
name|fp_post_sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**< Arg for fp_post_sleep_fn */
name|void
modifier|*
name|fp_post_sleep_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FAIL_POINT_DYNAMIC_NAME
value|0x01
end_define

begin_comment
comment|/**< Must free name on destroy */
end_comment

begin_comment
comment|/**< Use timeout path for sleep instead of msleep */
end_comment

begin_define
define|#
directive|define
name|FAIL_POINT_USE_TIMEOUT_PATH
value|0x02
end_define

begin_comment
comment|/**< If fail point is set to sleep, replace the sleep call with delay */
end_comment

begin_define
define|#
directive|define
name|FAIL_POINT_NONSLEEPABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|FAIL_POINT_CV_DESC
value|"fp cv no iterators"
end_define

begin_define
define|#
directive|define
name|FAIL_POINT_IS_OFF
parameter_list|(
name|fp
parameter_list|)
value|(__predict_true((fp)->fp_setting == NULL) || \         __predict_true(fail_point_is_off(fp)))
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/* Private failpoint eval function -- use fail_point_eval() instead. */
name|enum
name|fail_point_return_code
name|fail_point_eval_nontrivial
parameter_list|(
name|struct
name|fail_point
modifier|*
parameter_list|,
name|int
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @addtogroup failpoint  * @{  */
end_comment

begin_comment
comment|/*  * Initialize a fail-point.  The name is formed in printf-like fashion  * from "fmt" and the subsequent arguments.  * Pair with fail_point_destroy().  */
end_comment

begin_function_decl
name|void
name|fail_point_init
parameter_list|(
name|struct
name|fail_point
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Return true iff this fail point is set to off, false otherwise */
end_comment

begin_function_decl
name|bool
name|fail_point_is_off
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the pre-sleep function for a fail point  * If fp_post_sleep_fn is specified, then FAIL_POINT_SLEEP will result in a  * (*fp->fp_pre_sleep_fn)(fp->fp_pre_sleep_arg) call by the thread.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|fail_point_sleep_set_pre_func
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|void
function_decl|(
modifier|*
name|sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|fp
operator|->
name|fp_pre_sleep_fn
operator|=
name|sleep_fn
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|fail_point_sleep_set_pre_arg
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|void
modifier|*
name|sleep_arg
parameter_list|)
block|{
name|fp
operator|->
name|fp_pre_sleep_arg
operator|=
name|sleep_arg
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Set the post-sleep function.  This will be passed to timeout if we take  * the timeout path. This must be set if you sleep using the timeout path.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|fail_point_sleep_set_post_func
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|void
function_decl|(
modifier|*
name|sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|fp
operator|->
name|fp_post_sleep_fn
operator|=
name|sleep_fn
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|fail_point_sleep_set_post_arg
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|void
modifier|*
name|sleep_arg
parameter_list|)
block|{
name|fp
operator|->
name|fp_post_sleep_arg
operator|=
name|sleep_arg
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * If the FAIL_POINT_USE_TIMEOUT flag is set on a failpoint, then  * FAIL_POINT_SLEEP will result in a call to timeout instead of  * msleep. Note that if you sleep while this flag is set, you must  * set fp_post_sleep_fn or an error will occur upon waking.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|fail_point_use_timeout_path
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|bool
name|use_timeout
parameter_list|,
name|void
function_decl|(
modifier|*
name|post_sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|KASSERT
argument_list|(
operator|!
name|use_timeout
operator|||
name|post_sleep_fn
operator|!=
name|NULL
operator|||
operator|(
name|post_sleep_fn
operator|==
name|NULL
operator|&&
name|fp
operator|->
name|fp_post_sleep_fn
operator|!=
name|NULL
operator|)
argument_list|,
operator|(
literal|"Setting fp to use timeout, but not setting post_sleep_fn\n"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|use_timeout
condition|)
name|fp
operator|->
name|fp_flags
operator||=
name|FAIL_POINT_USE_TIMEOUT_PATH
expr_stmt|;
else|else
name|fp
operator|->
name|fp_flags
operator|&=
operator|~
name|FAIL_POINT_USE_TIMEOUT_PATH
expr_stmt|;
if|if
condition|(
name|post_sleep_fn
operator|!=
name|NULL
condition|)
name|fp
operator|->
name|fp_post_sleep_fn
operator|=
name|post_sleep_fn
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Free the resources used by a fail-point.  Pair with fail_point_init().  */
end_comment

begin_function_decl
name|void
name|fail_point_destroy
parameter_list|(
name|struct
name|fail_point
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Evaluate a failpoint.  */
end_comment

begin_function
specifier|static
specifier|inline
name|enum
name|fail_point_return_code
name|fail_point_eval
parameter_list|(
name|struct
name|fail_point
modifier|*
name|fp
parameter_list|,
name|int
modifier|*
name|ret
parameter_list|)
block|{
if|if
condition|(
name|__predict_true
argument_list|(
name|fp
operator|->
name|fp_setting
operator|==
name|NULL
argument_list|)
condition|)
return|return
operator|(
name|FAIL_POINT_RC_CONTINUE
operator|)
return|;
return|return
operator|(
name|fail_point_eval_nontrivial
argument_list|(
name|fp
argument_list|,
name|ret
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|__END_DECLS
comment|/* Declare a fail_point and its sysctl in a function. */
define|#
directive|define
name|_FAIL_POINT_NAME
parameter_list|(
name|name
parameter_list|)
value|_fail_point_##name
define|#
directive|define
name|_FAIL_POINT_LOCATION
parameter_list|()
value|"(" __FILE__ ":" __XSTRING(__LINE__) ")"
define|#
directive|define
name|_FAIL_POINT_INIT
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|flags
parameter_list|)
define|\
value|static struct fail_point _FAIL_POINT_NAME(name) = { \ 	        .fp_name = #name, \ 	        .fp_location = _FAIL_POINT_LOCATION(), \ 	        .fp_ref_cnt = 0, \ 	        .fp_setting = NULL, \ 	        .fp_flags = (flags), \ 	        .fp_pre_sleep_fn = NULL, \ 	        .fp_pre_sleep_arg = NULL, \ 	        .fp_post_sleep_fn = NULL, \ 	        .fp_post_sleep_arg = NULL, \ 	}; \ 	SYSCTL_OID(parent, OID_AUTO, name, \ 	        CTLTYPE_STRING | CTLFLAG_RW | CTLFLAG_MPSAFE, \&_FAIL_POINT_NAME(name), 0, fail_point_sysctl, \ 	        "A", ""); \ 	SYSCTL_OID(parent, OID_AUTO, status_##name, \ 	        CTLTYPE_STRING | CTLFLAG_RD | CTLFLAG_MPSAFE, \&_FAIL_POINT_NAME(name), 0, \ 	        fail_point_sysctl_status, "A", "");
define|#
directive|define
name|_FAIL_POINT_EVAL
parameter_list|(
name|name
parameter_list|,
name|cond
parameter_list|,
name|code
modifier|...
parameter_list|)
define|\
value|int RETURN_VALUE; \  \ 	if (__predict_false(cond&& \ 	        fail_point_eval(&_FAIL_POINT_NAME(name),&RETURN_VALUE))) { \  \ 		code; \  \ 	}
comment|/**  * Instantiate a failpoint which returns "RETURN_VALUE" from the function  * when triggered.  * @param parent  The parent sysctl under which to locate the fp's sysctl  * @param name    The name of the failpoint in the sysctl tree (and printouts)  * @return        Instantly returns the RETURN_VALUE specified in the  *                failpoint, if triggered.  */
define|#
directive|define
name|KFAIL_POINT_RETURN
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|)
define|\
value|KFAIL_POINT_CODE(parent, name, return RETURN_VALUE)
comment|/**  * Instantiate a failpoint which returns (void) from the function when  * triggered.  * @param parent  The parent sysctl under which to locate the sysctl  * @param name    The name of the failpoint in the sysctl tree (and printouts)  * @return        Instantly returns void, if triggered in the failpoint.  */
define|#
directive|define
name|KFAIL_POINT_RETURN_VOID
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|)
define|\
value|KFAIL_POINT_CODE(parent, name, return)
comment|/**  * Instantiate a failpoint which sets an error when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and  *                   printouts)  * @param error_var  A variable to set to the failpoint's specified  *                   return-value when triggered  */
define|#
directive|define
name|KFAIL_POINT_ERROR
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|error_var
parameter_list|)
define|\
value|KFAIL_POINT_CODE(parent, name, (error_var) = RETURN_VALUE)
comment|/**  * Instantiate a failpoint which sets an error and then goes to a  * specified label in the function when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and  *                   printouts)  * @param error_var  A variable to set to the failpoint's specified  *                   return-value when triggered  * @param label      The location to goto when triggered.  */
define|#
directive|define
name|KFAIL_POINT_GOTO
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|error_var
parameter_list|,
name|label
parameter_list|)
define|\
value|KFAIL_POINT_CODE(parent, name, (error_var) = RETURN_VALUE; goto label)
comment|/**  * Instantiate a failpoint which sets its pre- and post-sleep callback  * mechanisms.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and  *                   printouts)  * @param pre_func   Function pointer to the pre-sleep function, which will be  *                   called directly before going to sleep.  * @param pre_arg    Argument to the pre-sleep function  * @param post_func  Function pointer to the pot-sleep function, which will be  *                   called directly before going to sleep.  * @param post_arg   Argument to the post-sleep function  */
define|#
directive|define
name|KFAIL_POINT_SLEEP_CALLBACKS
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|pre_func
parameter_list|,
name|pre_arg
parameter_list|, \
name|post_func
parameter_list|,
name|post_arg
parameter_list|)
define|\
value|KFAIL_POINT_CODE_SLEEP_CALLBACKS(parent, name, pre_func, \ 	    pre_arg, post_func, post_arg, return RETURN_VALUE)
comment|/**  * Instantiate a failpoint which runs arbitrary code when triggered, and sets  * its pre- and post-sleep callback mechanisms  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and  *                   printouts)  * @param pre_func   Function pointer to the pre-sleep function, which will be  *                   called directly before going to sleep.  * @param pre_arg    Argument to the pre-sleep function  * @param post_func  Function pointer to the pot-sleep function, which will be  *                   called directly before going to sleep.  * @param post_arg   Argument to the post-sleep function  * @param code       The arbitrary code to run when triggered.  Can reference  *                   "RETURN_VALUE" if desired to extract the specified  *                   user return-value when triggered.  Note that this is  *                   implemented with a do-while loop so be careful of  *                   break and continue statements.  */
define|#
directive|define
name|KFAIL_POINT_CODE_SLEEP_CALLBACKS
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|pre_func
parameter_list|,
name|pre_arg
parameter_list|, \
name|post_func
parameter_list|,
name|post_arg
parameter_list|,
name|code
modifier|...
parameter_list|)
define|\
value|do { \ 		_FAIL_POINT_INIT(parent, name) \ 		_FAIL_POINT_NAME(name).fp_pre_sleep_fn = pre_func; \ 		_FAIL_POINT_NAME(name).fp_pre_sleep_arg = pre_arg; \ 		_FAIL_POINT_NAME(name).fp_post_sleep_fn = post_func; \ 		_FAIL_POINT_NAME(name).fp_post_sleep_arg = post_arg; \ 		_FAIL_POINT_EVAL(name, true, code) \ 	} while (0)
comment|/**  * Instantiate a failpoint which runs arbitrary code when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree  *                   (and printouts)  * @param code       The arbitrary code to run when triggered.  Can reference  *                   "RETURN_VALUE" if desired to extract the specified  *                   user return-value when triggered.  Note that this is  *                   implemented with a do-while loop so be careful of  *                   break and continue statements.  */
define|#
directive|define
name|KFAIL_POINT_CODE
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|code
modifier|...
parameter_list|)
define|\
value|do { \ 		_FAIL_POINT_INIT(parent, name, 0) \ 		_FAIL_POINT_EVAL(name, true, code) \ 	} while (0)
define|#
directive|define
name|KFAIL_POINT_CODE_FLAGS
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|flags
parameter_list|,
name|code
modifier|...
parameter_list|)
define|\
value|do { \ 		_FAIL_POINT_INIT(parent, name, flags) \ 		_FAIL_POINT_EVAL(name, true, code) \ 	} while (0)
define|#
directive|define
name|KFAIL_POINT_CODE_COND
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|cond
parameter_list|,
name|flags
parameter_list|,
name|code
modifier|...
parameter_list|)
define|\
value|do { \ 		_FAIL_POINT_INIT(parent, name, flags) \ 		_FAIL_POINT_EVAL(name, cond, code) \ 	} while (0)
comment|/**  * @}  * (end group failpoint)  */
ifdef|#
directive|ifdef
name|_KERNEL
name|int
name|fail_point_sysctl
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fail_point_sysctl_status
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The fail point sysctl tree. */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_debug_fail_point
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DEBUG_FP
value|_debug_fail_point
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
comment|/* _SYS_FAIL_H_ */
end_comment

end_unit

