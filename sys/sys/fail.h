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

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|fail_point_entries
argument_list|,
name|fail_point_entry
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/**< name of fail point */
specifier|const
name|char
modifier|*
name|fp_location
decl_stmt|;
comment|/**< file:line of fail point */
name|struct
name|fail_point_entries
name|fp_entries
decl_stmt|;
comment|/**< list of entries */
name|int
name|fp_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fp_sleep_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**< Function to call at end of 					 * sleep for sleep failpoints */
name|void
modifier|*
name|fp_sleep_arg
decl_stmt|;
comment|/**< Arg for sleep_fn */
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
comment|/**  * Set the sleep function for a fail point  * If sleep_fn is specified, then FAIL_POINT_SLEEP will result in a  * (*fp->sleep_fn)(fp->sleep_arg) call by the timer thread.  Otherwise,  * if sleep_fn is NULL (default), then FAIL_POINT_SLEEP will result in the  * fail_point_eval() call sleeping.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|fail_point_sleep_set_func
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
name|fp_sleep_fn
operator|=
name|sleep_fn
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * Set the argument for the sleep function for a fail point  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|fail_point_sleep_set_arg
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
name|fp_sleep_arg
operator|=
name|sleep_arg
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
name|__inline
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
name|TAILQ_EMPTY
argument_list|(
operator|&
name|fp
operator|->
name|fp_entries
argument_list|)
condition|)
block|{
return|return
operator|(
name|FAIL_POINT_RC_CONTINUE
operator|)
return|;
block|}
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
comment|/**  * Instantiate a failpoint which returns "value" from the function when triggered.  * @param parent  The parent sysctl under which to locate the sysctl  * @param name    The name of the failpoint in the sysctl tree (and printouts)  * @return        Instantly returns the return("value") specified in the  *                failpoint, if triggered.  */
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
comment|/**  * Instantiate a failpoint which returns (void) from the function when triggered.  * @param parent  The parent sysctl under which to locate the sysctl  * @param name    The name of the failpoint in the sysctl tree (and printouts)  * @return        Instantly returns void, if triggered in the failpoint.  */
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
comment|/**  * Instantiate a failpoint which sets an error when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and printouts)  * @param error_var  A variable to set to the failpoint's specified  *                   return-value when triggered  */
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
comment|/**  * Instantiate a failpoint which sets an error and then goes to a  * specified label in the function when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree (and printouts)  * @param error_var  A variable to set to the failpoint's specified  *                   return-value when triggered  * @param label      The location to goto when triggered.  */
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
comment|/**  * Instantiate a failpoint which runs arbitrary code when triggered.  * @param parent     The parent sysctl under which to locate the sysctl  * @param name       The name of the failpoint in the sysctl tree  *		     (and printouts)  * @param code       The arbitrary code to run when triggered.  Can reference  *                   "RETURN_VALUE" if desired to extract the specified  *                   user return-value when triggered.  Note that this is  *                   implemented with a do-while loop so be careful of  *                   break and continue statements.  */
define|#
directive|define
name|KFAIL_POINT_CODE
parameter_list|(
name|parent
parameter_list|,
name|name
parameter_list|,
name|code
parameter_list|)
define|\
value|do {									\ 	int RETURN_VALUE;						\ 	static struct fail_point _FAIL_POINT_NAME(name) = {		\ 		#name,							\ 		_FAIL_POINT_LOCATION(),					\ 		TAILQ_HEAD_INITIALIZER(_FAIL_POINT_NAME(name).fp_entries), \ 		0,							\ 		NULL, NULL,						\ 	};								\ 	SYSCTL_OID(parent, OID_AUTO, name,				\ 	    CTLTYPE_STRING | CTLFLAG_RW | CTLFLAG_MPSAFE,		\&_FAIL_POINT_NAME(name), 0, fail_point_sysctl,		\ 	    "A", "");							\ 									\ 	if (__predict_false(						\ 	    fail_point_eval(&_FAIL_POINT_NAME(name),&RETURN_VALUE))) {	\ 									\ 		code;							\ 									\ 	}								\ } while (0)
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

