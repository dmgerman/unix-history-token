begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SETDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SETDEFS_H_
end_define

begin_comment
comment|/*  * This file contains declarations for each linker set that can possibly  * be included in the system.  Every linker set must have an entry in this  * file, regardless of whether it happens to be configured into a given  * kernel.  *  * These declarations are unused for a.out, but they are needed for an  * ELF kernel.  ELF does not directly support linker sets, so they are  * simulated by creating a separate section for each set.  This header  * is included by two source files: setdef0.c at the beginning of the  * link (just after locore.s), and setdef1.c at the end of the link.  * The DEFINE_SET macro is defined differently in these two souces, so  * that it emits the leading count word for each set in setdef0.c, and  * the trailing NULL pointer for each set in setdef1.c.  */
end_comment

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|db_show_cmd_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|domain_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|eisadriver_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|execsw_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|netisr_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|pcibus_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|pcidevice_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__debug
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__hw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_ipc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_ntp_pll
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc_pgrp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc_pid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc_ruid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc_tty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__kern_proc_uid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__machdep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_div
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_icmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_igmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_ip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_ip_fw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_ip_portrange
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_raw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_tcp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_inet_udp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_ipx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_ipx_error
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_ipx_ipx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_ipx_spx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link_ether
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link_ether_inet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link_generic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link_generic_ifdata
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_link_generic_system
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_local
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_local_dgram
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_local_stream
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__net_routetable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__sysctl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__sysctl_name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__sysctl_next
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__sysctl_oidfmt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__user
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__vfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__vfs_ffs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__vfs_generic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__vfs_nfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysctl__vm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|sysinit_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|vfs_opv_descs_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_SET
argument_list|(
name|vfs_set
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SETDEFS_H_ */
end_comment

end_unit

