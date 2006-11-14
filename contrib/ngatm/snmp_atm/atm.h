begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004  *	Deutsches Zentrum fuer Luft- und Raumfahrt.  *	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/snmp_atm/atm.h,v 1.3 2005/05/23 11:46:46 brandt_h Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_mib.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/snmpmod.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/snmp_mibII.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/snmp_atm.h>
end_include

begin_comment
comment|/*  * Event registrations  */
end_comment

begin_struct
struct|struct
name|atmif_reg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|atmif_reg
argument_list|)
name|link
expr_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|atmif_event_f
name|func
decl_stmt|;
specifier|const
name|struct
name|lmodule
modifier|*
name|mod
decl_stmt|;
name|struct
name|atmif_priv
modifier|*
name|aif
decl_stmt|;
comment|/* back pointer */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|atmif_reg_list
argument_list|,
name|atmif_reg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Interface data  */
end_comment

begin_struct
struct|struct
name|atmif_priv
block|{
name|struct
name|atmif
name|pub
decl_stmt|;
comment|/* public part, must be first */
name|TAILQ_ENTRY
argument_list|(
argument|atmif_priv
argument_list|)
name|link
expr_stmt|;
name|u_int
name|index
decl_stmt|;
comment|/* if_index */
name|void
modifier|*
name|ifpreg
decl_stmt|;
name|struct
name|atmif_sys
modifier|*
name|sys
decl_stmt|;
name|struct
name|atmif_reg_list
name|notify
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|atmif_list
argument_list|,
name|atmif_priv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* list of all (known) ATM interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|atmif_list
name|atmif_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lmodule
modifier|*
name|module
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check the carrier state of the interface */
end_comment

begin_function_decl
name|void
name|atmif_check_carrier
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Send notification to all listeners. */
end_comment

begin_function_decl
name|void
name|atmif_send_notification
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|,
name|enum
name|atmif_notify
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the interface point for a table access */
end_comment

begin_function_decl
name|int
name|atmif_get_aif
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|,
name|struct
name|atmif_priv
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Destroy system dependend stuff. */
end_comment

begin_function_decl
name|void
name|atmif_sys_destroy
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attach to an ATM interface */
end_comment

begin_function_decl
name|int
name|atmif_sys_attach_if
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get vendor string */
end_comment

begin_function_decl
name|int
name|atm_sys_get_hw_vendor
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get device string */
end_comment

begin_function_decl
name|int
name|atm_sys_get_hw_device
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract the ATM MIB from the interface's private MIB */
end_comment

begin_function_decl
name|void
name|atmif_sys_fill_mib
parameter_list|(
name|struct
name|atmif_priv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

