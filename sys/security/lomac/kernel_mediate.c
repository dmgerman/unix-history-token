begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file contains functions that make access control decisions  * concerning wether or not given system calls should be allowed  * or denied.  This activity is called "mediation".  These functions  * generally consider both the parameters passed to a system call  * and the current internal state of LOMAC in the course of making  * a decision.  However, they do not modify these parameters or  * LOMAC's internal state.  Functions for modifying LOMAC's internal  * state can be found in lomac_monitor.c.  *  */
end_comment

begin_include
include|#
directive|include
file|"kernel_interface.h"
end_include

begin_include
include|#
directive|include
file|"kernel_mediate.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"lomac_plm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"kernel_log.h"
end_include

begin_comment
comment|/* mediate_subject_level_subject()  *  * in:     op_s          - name of operation to mediate  *         p_subject_one - subject one (for informational purposes only)  *         level_one     - already-known level of the first subject  *         p_subject_two - subject two  * out:    nothing  * return: value   condition  *         -----   ---------  *           0     caller should deny operation  *           1     caller should allow operation  *  *     This function returns 1 if `p_subject_one's level is at least  * as great as `p_subject_two's level.  Otherwise, it logs a permission  * failure on operation `op_s' and returns 0.  *  * This function is used to mediate pgrp changes.  *  */
end_comment

begin_function
name|int
name|mediate_subject_level_subject
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
specifier|const
name|lomac_subject_t
modifier|*
name|p_subject_one
parameter_list|,
name|level_t
name|level_one
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject_two
parameter_list|)
block|{
name|lattr_t
name|lattr_two
decl_stmt|;
comment|/* lattr of `p_subject_two' */
name|int
name|ret_val
decl_stmt|;
comment|/* result to return to caller */
ifdef|#
directive|ifdef
name|NO_MEDIATION
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* no denials, just logging */
else|#
directive|else
name|ret_val
operator|=
literal|0
expr_stmt|;
comment|/* pessimistically assume deny */
endif|#
directive|endif
name|get_subject_lattr
argument_list|(
name|p_subject_two
argument_list|,
operator|&
name|lattr_two
argument_list|)
expr_stmt|;
if|if
condition|(
name|lattr_two
operator|.
name|level
operator|<=
name|level_one
condition|)
block|{
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* OK, allow */
block|}
elseif|else
if|if
condition|(
name|lomac_verbose_demote_deny
condition|)
block|{
name|lomac_log_t
modifier|*
name|logmsg
init|=
name|log_start
argument_list|()
decl_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"LOMAC: denied level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|level_one
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" proc "
argument_list|)
expr_stmt|;
name|log_append_subject_id
argument_list|(
name|logmsg
argument_list|,
name|p_subject_one
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
name|op_s
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" to level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|lattr_two
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" proc "
argument_list|)
expr_stmt|;
name|log_append_subject_id
argument_list|(
name|logmsg
argument_list|,
name|p_subject_two
argument_list|)
expr_stmt|;
name|log_print
argument_list|(
name|logmsg
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret_val
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mediate_subject_subject() */
end_comment

begin_comment
comment|/* mediate_subject_object()  *  * in:     op_s      - string describing operation, like "write" or "writev"  *         p_subject - subject trying to operate on `p_object'.  *         p_object  - object that `p_subject' is trying to operate on.  * out:    nothing  * return: value    condition  *         -----    ---------  *           0      Caller should prevent operation  *           1      Caller should permit operation  *   * This function returns 1 if the level of `p_object' is less than or  * equal to the level of `p_subject'.  Otherwise, it returns 0 and  * logs a permission denial on `op_s'.  *  * This function allows LOMAC to mediate write and writev system calls.  *  */
end_comment

begin_function
name|int
name|mediate_subject_object
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
block|{
name|lattr_t
name|subject_lattr
decl_stmt|;
comment|/* lattr of `p_subject' */
name|lattr_t
name|object_lattr
decl_stmt|;
comment|/* lattr of `p_object' */
name|int
name|ret_val
decl_stmt|;
comment|/* value to return to caller */
ifdef|#
directive|ifdef
name|NO_MEDIATION
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation regardless of decision */
else|#
directive|else
name|ret_val
operator|=
literal|0
expr_stmt|;
comment|/* pessimistically assume deny */
endif|#
directive|endif
comment|/* Get the lattrs of `p_subject' and `p_object' so we can compare them. */
name|get_subject_lattr
argument_list|(
name|p_subject
argument_list|,
operator|&
name|subject_lattr
argument_list|)
expr_stmt|;
name|get_object_lattr
argument_list|(
name|p_object
argument_list|,
operator|&
name|object_lattr
argument_list|)
expr_stmt|;
comment|/* 	 * If `p_subject's level is less than `p_object's level, 	 * we indicate that the operation must not be allowed. 	 */
if|if
condition|(
operator|!
name|lomac_must_deny
argument_list|(
operator|&
name|subject_lattr
argument_list|,
operator|&
name|object_lattr
argument_list|)
operator|||
name|object_lattr
operator|.
name|flags
operator|&
name|LOMAC_ATTR_LOWWRITE
condition|)
block|{
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation */
block|}
elseif|else
if|if
condition|(
name|lomac_verbose_demote_deny
condition|)
block|{
name|lomac_log_t
modifier|*
name|logmsg
init|=
name|log_start
argument_list|()
decl_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"LOMAC: level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|subject_lattr
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" proc "
argument_list|)
expr_stmt|;
name|log_append_subject_id
argument_list|(
name|logmsg
argument_list|,
name|p_subject
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" denied "
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
name|op_s
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" to level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|object_lattr
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" object "
argument_list|)
expr_stmt|;
name|log_append_object_id
argument_list|(
name|logmsg
argument_list|,
name|p_object
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|log_print
argument_list|(
name|logmsg
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret_val
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mediate_subject_object() */
end_comment

begin_comment
comment|/* mediate_subject_object_open()  *  * in:     p_subject - subject trying to operate on `p_object'.  *         p_object  - object that `p_subject' is trying to operate on.  * out:    nothing  * return: value    condition  *         -----    ---------  *           0      Caller should prevent operation  *           1      Caller should permit operation  *   * This function returns 1 if the level of `p_object' is less than or  * equal to the level of `p_subject'.  Otherwise, it returns 0 and  * logs a permission denial on `op_s'.  *  * This function allows LOMAC to mediate open system calls.  *  */
end_comment

begin_function
name|int
name|mediate_subject_object_open
parameter_list|(
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
block|{
name|lattr_t
name|subject_lattr
decl_stmt|;
comment|/* lattr of `p_subject' */
name|lattr_t
name|object_lattr
decl_stmt|;
comment|/* lattr of `p_object' */
name|int
name|ret_val
decl_stmt|;
comment|/* value to return to caller */
ifdef|#
directive|ifdef
name|NO_MEDIATION
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation regardless of decision */
else|#
directive|else
name|ret_val
operator|=
literal|0
expr_stmt|;
comment|/* pessimistically assume deny */
endif|#
directive|endif
comment|/* Get the lattrs of `p_subject' and `p_object' so we can compare them. */
name|get_subject_lattr
argument_list|(
name|p_subject
argument_list|,
operator|&
name|subject_lattr
argument_list|)
expr_stmt|;
name|get_object_lattr
argument_list|(
name|p_object
argument_list|,
operator|&
name|object_lattr
argument_list|)
expr_stmt|;
comment|/* 	 * If `p_subject's level is less than `p_object's level, 	 * we must indicate that the operation should not be allowed. 	 */
if|if
condition|(
name|lomac_must_deny
argument_list|(
operator|&
name|subject_lattr
argument_list|,
operator|&
name|object_lattr
argument_list|)
operator|&&
name|object_lattr
operator|.
name|flags
operator|&
name|LOMAC_ATTR_LOWNOOPEN
condition|)
block|{
if|if
condition|(
name|lomac_verbose_demote_deny
condition|)
block|{
name|lomac_log_t
modifier|*
name|logmsg
init|=
name|log_start
argument_list|()
decl_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"LOMAC: level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|subject_lattr
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" proc "
argument_list|)
expr_stmt|;
name|log_append_subject_id
argument_list|(
name|logmsg
argument_list|,
name|p_subject
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" denied open to level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|object_lattr
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" object "
argument_list|)
expr_stmt|;
name|log_append_object_id
argument_list|(
name|logmsg
argument_list|,
name|p_object
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|log_print
argument_list|(
name|logmsg
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation */
block|}
comment|/* if/else allow/deny */
return|return
operator|(
name|ret_val
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mediate_subject_object() */
end_comment

begin_comment
comment|/* mediate_subject_at_level()  *  * in:     op_s         - name of operation being mediated  *         p_subject    - subject whose level we want to check  *         target_level - level to compare to `p_subject's level  *           * out:    nothing  * return: value   condition  *         -----   ---------  *           0     `p_subject' is not at `target_level'  *           1     `p_subject' is at `target_level'  *  * This function provides a predicate for determining whether or not  * `p_subject' is at the level specified by `target_level'.  This  * function compares `p_subject's level to `target_level'.  If the  * levels match, it retruns 1.  Otherwise, it logs a permission denial  * on `op_s' and returns 0.  *  */
end_comment

begin_function
name|int
name|mediate_subject_at_level
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|level_t
name|target_level
parameter_list|)
block|{
name|lattr_t
name|subject_lattr
decl_stmt|;
comment|/* lattr of `p_subject' */
name|int
name|ret_val
decl_stmt|;
comment|/* value returned to caller */
ifdef|#
directive|ifdef
name|NO_MEDIATION
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation regardless of decision */
else|#
directive|else
name|ret_val
operator|=
literal|0
expr_stmt|;
comment|/* pessimistically assume deny */
endif|#
directive|endif
comment|/* Make `subject_lattr' the lattr of `p_subject'. */
name|get_subject_lattr
argument_list|(
name|p_subject
argument_list|,
operator|&
name|subject_lattr
argument_list|)
expr_stmt|;
comment|/* compare with `target_lattr */
if|if
condition|(
name|subject_lattr
operator|.
name|level
operator|==
name|target_level
condition|)
block|{
name|ret_val
operator|=
literal|1
expr_stmt|;
comment|/* allow operation */
block|}
elseif|else
if|if
condition|(
name|lomac_verbose_demote_deny
condition|)
block|{
name|lomac_log_t
modifier|*
name|logmsg
init|=
name|log_start
argument_list|()
decl_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"LOMAC: denied level-"
argument_list|)
expr_stmt|;
name|log_append_int
argument_list|(
name|logmsg
argument_list|,
name|subject_lattr
operator|.
name|level
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|" proc "
argument_list|)
expr_stmt|;
name|log_append_subject_id
argument_list|(
name|logmsg
argument_list|,
name|p_subject
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|"'s "
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
name|op_s
argument_list|)
expr_stmt|;
name|log_append_string
argument_list|(
name|logmsg
argument_list|,
literal|".\n"
argument_list|)
expr_stmt|;
name|log_print
argument_list|(
name|logmsg
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret_val
operator|)
return|;
block|}
end_function

begin_comment
comment|/* mediate_subject_at_level() */
end_comment

end_unit

