begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bluetooth.c  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_bluetooth.c,v 1.3 2003/04/26 22:37:31 max Exp $  * $FreeBSD$  */
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
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<netgraph/bluetooth/include/ng_bluetooth.h>
end_include

begin_comment
comment|/*  * Bluetooth stack sysctl globals  */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_hci_command_timeout_value
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_hci_connect_timeout_value
init|=
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_hci_max_neighbor_age_value
init|=
literal|600
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_l2cap_rtx_timeout_value
init|=
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_l2cap_ertx_timeout_value
init|=
literal|300
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_decl_stmt
specifier|static
name|u_int32_t
name|bluetooth_sco_rtx_timeout_value
init|=
literal|60
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sec */
end_comment

begin_comment
comment|/*  * Define sysctl tree that shared by other parts of Bluetooth stack  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net
argument_list|,
name|OID_AUTO
argument_list|,
name|bluetooth
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_net_bluetooth
argument_list|,
name|OID_AUTO
argument_list|,
name|version
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|SYSCTL_NULL_INT_PTR
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|,
literal|"Version of the stack"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * HCI  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth
argument_list|,
name|OID_AUTO
argument_list|,
name|hci
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth HCI family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|bluetooth_set_hci_command_timeout_value
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int32_t
name|value
decl_stmt|;
name|int
name|error
decl_stmt|;
name|value
operator|=
name|bluetooth_hci_command_timeout_value
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|value
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|value
operator|>
literal|0
condition|)
name|bluetooth_hci_command_timeout_value
operator|=
name|value
expr_stmt|;
else|else
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_set_hci_command_timeout_value */
end_comment

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_bluetooth_hci
argument_list|,
name|OID_AUTO
argument_list|,
name|command_timeout
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_hci_command_timeout_value
argument_list|,
literal|5
argument_list|,
name|bluetooth_set_hci_command_timeout_value
argument_list|,
literal|"I"
argument_list|,
literal|"HCI command timeout (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|bluetooth_set_hci_connect_timeout_value
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int32_t
name|value
decl_stmt|;
name|int
name|error
decl_stmt|;
name|value
operator|=
name|bluetooth_hci_connect_timeout_value
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|value
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
literal|0
operator|<
name|value
operator|&&
name|value
operator|<=
name|bluetooth_l2cap_rtx_timeout_value
condition|)
name|bluetooth_hci_connect_timeout_value
operator|=
name|value
expr_stmt|;
else|else
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_set_hci_connect_timeout_value */
end_comment

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_bluetooth_hci
argument_list|,
name|OID_AUTO
argument_list|,
name|connection_timeout
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_hci_connect_timeout_value
argument_list|,
literal|60
argument_list|,
name|bluetooth_set_hci_connect_timeout_value
argument_list|,
literal|"I"
argument_list|,
literal|"HCI connect timeout (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_net_bluetooth_hci
argument_list|,
name|OID_AUTO
argument_list|,
name|max_neighbor_age
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_hci_max_neighbor_age_value
argument_list|,
literal|600
argument_list|,
literal|"Maximal HCI neighbor cache entry age (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * L2CAP  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth
argument_list|,
name|OID_AUTO
argument_list|,
name|l2cap
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth L2CAP family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|bluetooth_set_l2cap_rtx_timeout_value
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int32_t
name|value
decl_stmt|;
name|int
name|error
decl_stmt|;
name|value
operator|=
name|bluetooth_l2cap_rtx_timeout_value
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|value
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|bluetooth_hci_connect_timeout_value
operator|<=
name|value
operator|&&
name|value
operator|<=
name|bluetooth_l2cap_ertx_timeout_value
condition|)
name|bluetooth_l2cap_rtx_timeout_value
operator|=
name|value
expr_stmt|;
else|else
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_set_l2cap_rtx_timeout_value */
end_comment

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_bluetooth_l2cap
argument_list|,
name|OID_AUTO
argument_list|,
name|rtx_timeout
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_l2cap_rtx_timeout_value
argument_list|,
literal|60
argument_list|,
name|bluetooth_set_l2cap_rtx_timeout_value
argument_list|,
literal|"I"
argument_list|,
literal|"L2CAP RTX timeout (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|bluetooth_set_l2cap_ertx_timeout_value
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int32_t
name|value
decl_stmt|;
name|int
name|error
decl_stmt|;
name|value
operator|=
name|bluetooth_l2cap_ertx_timeout_value
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|value
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|value
operator|>=
name|bluetooth_l2cap_rtx_timeout_value
condition|)
name|bluetooth_l2cap_ertx_timeout_value
operator|=
name|value
expr_stmt|;
else|else
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_set_l2cap_ertx_timeout_value */
end_comment

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_bluetooth_l2cap
argument_list|,
name|OID_AUTO
argument_list|,
name|ertx_timeout
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_l2cap_ertx_timeout_value
argument_list|,
literal|300
argument_list|,
name|bluetooth_set_l2cap_ertx_timeout_value
argument_list|,
literal|"I"
argument_list|,
literal|"L2CAP ERTX timeout (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Return various sysctl values  */
end_comment

begin_function
name|u_int32_t
name|bluetooth_hci_command_timeout
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_hci_command_timeout_value
operator|*
name|hz
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_hci_command_timeout */
end_comment

begin_function
name|u_int32_t
name|bluetooth_hci_connect_timeout
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_hci_connect_timeout_value
operator|*
name|hz
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_hci_connect_timeout */
end_comment

begin_function
name|u_int32_t
name|bluetooth_hci_max_neighbor_age
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_hci_max_neighbor_age_value
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_hci_max_neighbor_age */
end_comment

begin_function
name|u_int32_t
name|bluetooth_l2cap_rtx_timeout
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_l2cap_rtx_timeout_value
operator|*
name|hz
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_l2cap_rtx_timeout */
end_comment

begin_function
name|u_int32_t
name|bluetooth_l2cap_ertx_timeout
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_l2cap_ertx_timeout_value
operator|*
name|hz
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_l2cap_ertx_timeout */
end_comment

begin_function
name|u_int32_t
name|bluetooth_sco_rtx_timeout
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|bluetooth_sco_rtx_timeout_value
operator|*
name|hz
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_sco_rtx_timeout */
end_comment

begin_comment
comment|/*   * RFCOMM  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth
argument_list|,
name|OID_AUTO
argument_list|,
name|rfcomm
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth RFCOMM family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * SCO  */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_net_bluetooth
argument_list|,
name|OID_AUTO
argument_list|,
name|sco
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"Bluetooth SCO family"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|bluetooth_set_sco_rtx_timeout_value
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
name|u_int32_t
name|value
decl_stmt|;
name|int
name|error
decl_stmt|;
name|value
operator|=
name|bluetooth_sco_rtx_timeout_value
expr_stmt|;
name|error
operator|=
name|sysctl_handle_int
argument_list|(
name|oidp
argument_list|,
operator|&
name|value
argument_list|,
literal|0
argument_list|,
name|req
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
operator|&&
name|req
operator|->
name|newptr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|bluetooth_hci_connect_timeout_value
operator|<=
name|value
condition|)
name|bluetooth_sco_rtx_timeout_value
operator|=
name|value
expr_stmt|;
else|else
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_set_sco_rtx_timeout_value */
end_comment

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_net_bluetooth_sco
argument_list|,
name|OID_AUTO
argument_list|,
name|rtx_timeout
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RW
argument_list|,
operator|&
name|bluetooth_sco_rtx_timeout_value
argument_list|,
literal|60
argument_list|,
name|bluetooth_set_sco_rtx_timeout_value
argument_list|,
literal|"I"
argument_list|,
literal|"SCO RTX timeout (sec)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Handle loading and unloading for this code.  */
end_comment

begin_function
specifier|static
name|int
name|bluetooth_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|event
condition|)
block|{
case|case
name|MOD_LOAD
case|:
break|break;
case|case
name|MOD_UNLOAD
case|:
break|break;
default|default:
name|error
operator|=
name|EOPNOTSUPP
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* bluetooth_modevent */
end_comment

begin_comment
comment|/*  * Module  */
end_comment

begin_decl_stmt
specifier|static
name|moduledata_t
name|bluetooth_mod
init|=
block|{
literal|"ng_bluetooth"
block|,
name|bluetooth_modevent
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|ng_bluetooth
argument_list|,
name|bluetooth_mod
argument_list|,
name|SI_SUB_PSEUDO
argument_list|,
name|SI_ORDER_ANY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ng_bluetooth
argument_list|,
name|NG_BLUETOOTH_VERSION
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

