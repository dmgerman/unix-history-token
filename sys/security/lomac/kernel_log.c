begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|"lomacfs.h"
end_include

begin_include
include|#
directive|include
file|"kernel_interface.h"
end_include

begin_comment
comment|/* The following definition sets the global log verbosity level. */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|lomac
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"LOMAC"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern_lomac
argument_list|,
name|OID_AUTO
argument_list|,
name|verbose
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"LOMAC verbosity"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VERBOSITY_SETTING
parameter_list|(
name|level
parameter_list|)
define|\
value|unsigned int lomac_verbose_##level## = 1;			\ 	SYSCTL_UINT(_kern_lomac_verbose, OID_AUTO, level,		\ 	    CTLFLAG_RW,&lomac_verbose_##level##, 1, "")
end_define

begin_include
include|#
directive|include
file|"kernel_log.h"
end_include

begin_comment
comment|/* sbuf_start()  *  * in:     nothing  * out:    nothing  * return: struct sbuf * to pass to later callers  *  */
end_comment

begin_function
name|lomac_log_t
modifier|*
name|log_start
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|sbuf
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|sbuf_new
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|,
name|PATH_MAX
operator|*
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|s
operator|!=
name|NULL
argument_list|,
operator|(
literal|"sbuf uses M_WAITOK -- must not return NULL!"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_comment
comment|/* log_start() */
end_comment

begin_comment
comment|/* log_append_string()  *  * in:     s - a struct sbuf *  * in:     data_s - null-terminated string to append to log  * out:    nothing, see description for side-effects  * return: nothing  *  *     This function appends `data_s' to `log_s', being careful to ensure  * that there is sufficient room in `log_s' for the data and a null   * terminator.  If there is insufficient room in `log_s' for the entire  * `data_s' string, this function will append only the prefix of `data_s'  * which fits.  *  */
end_comment

begin_function
name|void
name|log_append_string
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|data_s
parameter_list|)
block|{
operator|(
name|void
operator|)
name|sbuf_cat
argument_list|(
name|s
argument_list|,
name|data_s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* log_append_string */
end_comment

begin_comment
comment|/* log_append_int()  *  * in:     data - integer value to append to log  * out:    nothing, see description for side-effects  * return: nothing  *  *     This function determines the ASCII representation of the integer  * value in `data' and, if there is sufficient room, appends this  * ASCII representation to `log_s'.  If there is insufficient room,  * this function behaves as log_append_string().  *  */
end_comment

begin_function
name|void
name|log_append_int
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
name|int
name|data
parameter_list|)
block|{
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"%d"
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* log_append_int() */
end_comment

begin_comment
comment|/* log_append_subject_id()  *  * in:     p_subject - subject whose ID we want to append to the log message  * out:    nothing, see description for side-effects  * return: nothing  *  *    This function appends a string describing the identity of `p_subject'  * to `log_s'.  If there is insufficient room in `log_s' for the entire  * ID string, only a (possibly empty) prefix of the ID string will be  * appended.  *  */
end_comment

begin_function
name|void
name|log_append_subject_id
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|)
block|{
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"p%dg%du%d:%s"
argument_list|,
name|p_subject
operator|->
name|p_pid
argument_list|,
name|p_subject
operator|->
name|p_pgrp
operator|->
name|pg_id
argument_list|,
name|p_subject
operator|->
name|p_ucred
operator|->
name|cr_uid
argument_list|,
name|p_subject
operator|->
name|p_comm
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* log_append_subject_id() */
end_comment

begin_comment
comment|/* log_append_object_id()  *  * in:     p_object - object whose ID we want to append to the log message  * out:    nothing, see description for side-effects  * return: nothing  *  *    This function appends a string describing the identity of `p_object'  * to `log_s'.  If there is insufficient room in `log_s' for the entire  * ID string, only a (possibly empty) prefix of the ID string will be  * appended.  *  */
end_comment

begin_function
name|void
name|log_append_object_id
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
block|{
name|struct
name|lomac_node
modifier|*
name|ln
decl_stmt|;
switch|switch
condition|(
name|p_object
operator|->
name|lo_type
condition|)
block|{
case|case
name|LO_TYPE_UVNODE
case|:
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"vp %p"
argument_list|,
name|p_object
operator|->
name|lo_object
operator|.
name|vnode
argument_list|)
expr_stmt|;
break|break;
case|case
name|LO_TYPE_LVNODE
case|:
name|ln
operator|=
name|VTOLOMAC
argument_list|(
name|p_object
operator|->
name|lo_object
operator|.
name|vnode
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LOMAC_DEBUG_INCNAME
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"named \"%s\""
argument_list|,
name|ln
operator|->
name|ln_name
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|ln
operator|->
name|ln_entry
operator|!=
name|NULL
condition|)
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"named \"%s\""
argument_list|,
name|ln
operator|->
name|ln_entry
operator|->
name|ln_path
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"under \"%s\""
argument_list|,
name|ln
operator|->
name|ln_underpolicy
operator|->
name|ln_path
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|LO_TYPE_PIPE
case|:
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"pipe %p"
argument_list|,
name|p_object
operator|->
name|lo_object
operator|.
name|pipe
argument_list|)
expr_stmt|;
break|break;
case|case
name|LO_TYPE_SOCKETPAIR
case|:
operator|(
name|void
operator|)
name|sbuf_printf
argument_list|(
name|s
argument_list|,
literal|"socket %p"
argument_list|,
name|p_object
operator|->
name|lo_object
operator|.
name|socket
argument_list|)
expr_stmt|;
break|break;
default|default:
name|panic
argument_list|(
literal|"invalid LOMAC object type"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* log_append_object_id() */
end_comment

begin_comment
comment|/* log_print()  *  * in:     nothing  * out:    nothing  * return: nothing  *  *     This function prints `log_s' to the system log.  *  */
end_comment

begin_function
name|void
name|log_print
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|)
block|{
name|sbuf_finish
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"%s"
argument_list|,
name|sbuf_data
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|sbuf_delete
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* log_print() */
end_comment

end_unit

