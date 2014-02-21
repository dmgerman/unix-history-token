begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed at the Centre for Advanced Internet  * Architectures, Swinburne University of Technology, Melbourne, Australia by  * Lawrence Stewart under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This example Khelp module uses the helper hook points available in the TCP  * stack to calculate a per-connection count of inbound and outbound packets  * when the connection is in the established state. The code is verbosely  * documented in an attempt to explain how everything fits together.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/hhook.h>
end_include

begin_include
include|#
directive|include
file|<sys/khelp.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/module_khelp.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_var.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/*  * Function prototype for our helper hook (man 9 hhook) compatible hook  * function.  */
end_comment

begin_function_decl
specifier|static
name|int
name|example_hook
parameter_list|(
name|int
name|hhook_type
parameter_list|,
name|int
name|hhook_id
parameter_list|,
name|void
modifier|*
name|udata
parameter_list|,
name|void
modifier|*
name|ctx_data
parameter_list|,
name|void
modifier|*
name|hdata
parameter_list|,
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Our per-connection persistent data storage struct.  */
end_comment

begin_struct
struct|struct
name|example
block|{
name|uint32_t
name|est_in_count
decl_stmt|;
name|uint32_t
name|est_out_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fill in the required bits of our module's struct helper (defined in  *<sys/module_khelp.h>).  *  * - Our helper will be storing persistent state for each TCP connection, so we  * request the use the Object Specific Data (OSD) feature from the framework by  * setting the HELPER_NEEDS_OSD flag.  *  * - Our helper is related to the TCP subsystem, so tell the Khelp framework  * this by setting an appropriate class for the module. When a new TCP  * connection is created, the Khelp framework takes care of associating helper  * modules of the appropriate class with the new connection.  */
end_comment

begin_decl_stmt
name|struct
name|helper
name|example_helper
init|=
block|{
operator|.
name|h_flags
operator|=
name|HELPER_NEEDS_OSD
block|,
operator|.
name|h_classes
operator|=
name|HELPER_CLASS_TCP
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Set which helper hook points our module wants to hook by creating an array of  * hookinfo structs (defined in<sys/hhook.h>). We hook the TCP established  * inbound/outbound hook points (TCP hhook points are defined in  *<netinet/tcp_var.h>) with our example_hook() function. We don't require a user  * data pointer to be passed to our hook function when called, so we set it to  * NULL.  */
end_comment

begin_decl_stmt
name|struct
name|hookinfo
name|example_hooks
index|[]
init|=
block|{
block|{
operator|.
name|hook_type
operator|=
name|HHOOK_TYPE_TCP
block|,
operator|.
name|hook_id
operator|=
name|HHOOK_TCP_EST_IN
block|,
operator|.
name|hook_udata
operator|=
name|NULL
block|,
operator|.
name|hook_func
operator|=
operator|&
name|example_hook
block|}
block|,
block|{
operator|.
name|hook_type
operator|=
name|HHOOK_TYPE_TCP
block|,
operator|.
name|hook_id
operator|=
name|HHOOK_TCP_EST_OUT
block|,
operator|.
name|hook_udata
operator|=
name|NULL
block|,
operator|.
name|hook_func
operator|=
operator|&
name|example_hook
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Very simple helper hook function. Here's a quick run through the arguments:  *  * - hhook_type and hhook_id are useful if you use a single function with many  * hook points and want to know which hook point called the function.  *  * - udata will be NULL, because we didn't elect to pass a pointer in either of  * the hookinfo structs we instantiated above in the example_hooks array.  *  * - ctx_data contains context specific data from the hook point call site. The  * data type passed is subsystem dependent. In the case of TCP, the hook points  * pass a pointer to a "struct tcp_hhook_data" (defined in<netinet/tcp_var.h>).  *  * - hdata is a pointer to the persistent per-object storage for our module. The  * pointer is allocated automagically by the Khelp framework when the connection  * is created, and comes from a dedicated UMA zone. It will never be NULL.  *  * - hosd can be used with the Khelp framework's khelp_get_osd() function to  * access data belonging to a different Khelp module.  */
end_comment

begin_function
specifier|static
name|int
name|example_hook
parameter_list|(
name|int
name|hhook_type
parameter_list|,
name|int
name|hhook_id
parameter_list|,
name|void
modifier|*
name|udata
parameter_list|,
name|void
modifier|*
name|ctx_data
parameter_list|,
name|void
modifier|*
name|hdata
parameter_list|,
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
block|{
name|struct
name|example
modifier|*
name|data
decl_stmt|;
name|data
operator|=
name|hdata
expr_stmt|;
if|if
condition|(
name|hhook_id
operator|==
name|HHOOK_TCP_EST_IN
condition|)
name|data
operator|->
name|est_in_count
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|hhook_id
operator|==
name|HHOOK_TCP_EST_OUT
condition|)
name|data
operator|->
name|est_out_count
operator|++
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * We use a convenient macro which handles registering our module with the Khelp  * framework. Note that Khelp modules which set the HELPER_NEEDS_OSD flag (i.e.  * require persistent per-object storage) must use the KHELP_DECLARE_MOD_UMA()  * macro. If you don't require per-object storage, use the KHELP_DECLARE_MOD()  * macro instead.  */
end_comment

begin_expr_stmt
name|KHELP_DECLARE_MOD_UMA
argument_list|(
name|example
argument_list|,
operator|&
name|example_helper
argument_list|,
name|example_hooks
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|example
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

