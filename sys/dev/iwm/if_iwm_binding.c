begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_iwm.c,v 1.39 2015/03/23 00:35:19 jsg Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 genua mbh<info@genua.de>  * Copyright (c) 2014 Fixup Software Ltd.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  * Driver version we are currently based off of is  * Linux 3.14.3 (tag id a2df521e42b1d9a23f620ac79dbfe8655a8391dd)  *  ***********************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2007 - 2013 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<ilw@linux.intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2013 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007-2010 Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|"opt_wlan.h"
end_include

begin_include
include|#
directive|include
file|"opt_iwm.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/firmware.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_regdomain.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_ratectl.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/iwm/if_iwmreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/iwm/if_iwmvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/iwm/if_iwm_debug.h>
end_include

begin_include
include|#
directive|include
file|<dev/iwm/if_iwm_util.h>
end_include

begin_include
include|#
directive|include
file|<dev/iwm/if_iwm_binding.h>
end_include

begin_comment
comment|/*  * BEGIN iwlwifi/mvm/binding.c  */
end_comment

begin_function
name|int
name|iwm_mvm_binding_cmd
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_vap
modifier|*
name|ivp
parameter_list|,
name|uint32_t
name|action
parameter_list|)
block|{
name|struct
name|iwm_binding_cmd
name|cmd
decl_stmt|;
name|struct
name|iwm_mvm_phy_ctxt
modifier|*
name|phyctxt
init|=
name|ivp
operator|->
name|phy_ctxt
decl_stmt|;
name|int
name|i
decl_stmt|,
name|ret
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|memset
argument_list|(
operator|&
name|cmd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|cmd
argument_list|)
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|id_and_color
operator|=
name|htole32
argument_list|(
name|IWM_FW_CMD_ID_AND_COLOR
argument_list|(
name|phyctxt
operator|->
name|id
argument_list|,
name|phyctxt
operator|->
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|action
operator|=
name|htole32
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|phy
operator|=
name|htole32
argument_list|(
name|IWM_FW_CMD_ID_AND_COLOR
argument_list|(
name|phyctxt
operator|->
name|id
argument_list|,
name|phyctxt
operator|->
name|color
argument_list|)
argument_list|)
expr_stmt|;
name|cmd
operator|.
name|macs
index|[
literal|0
index|]
operator|=
name|htole32
argument_list|(
name|IWM_FW_CMD_ID_AND_COLOR
argument_list|(
name|IWM_DEFAULT_MACID
argument_list|,
name|IWM_DEFAULT_COLOR
argument_list|)
argument_list|)
expr_stmt|;
comment|/* We use MACID 0 here.. */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|IWM_MAX_MACS_IN_BINDING
condition|;
name|i
operator|++
control|)
name|cmd
operator|.
name|macs
index|[
name|i
index|]
operator|=
name|htole32
argument_list|(
name|IWM_FW_CTXT_INVALID
argument_list|)
expr_stmt|;
name|status
operator|=
literal|0
expr_stmt|;
name|ret
operator|=
name|iwm_mvm_send_cmd_pdu_status
argument_list|(
name|sc
argument_list|,
name|IWM_BINDING_CONTEXT_CMD
argument_list|,
sizeof|sizeof
argument_list|(
name|cmd
argument_list|)
argument_list|,
operator|&
name|cmd
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|IWM_DPRINTF
argument_list|(
name|sc
argument_list|,
name|IWM_DEBUG_CMD
operator||
name|IWM_DEBUG_RESET
argument_list|,
literal|"%s: Failed to send binding (action:%d): %d\n"
argument_list|,
name|__func__
argument_list|,
name|action
argument_list|,
name|ret
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
if|if
condition|(
name|status
condition|)
block|{
name|IWM_DPRINTF
argument_list|(
name|sc
argument_list|,
name|IWM_DEBUG_CMD
operator||
name|IWM_DEBUG_RESET
argument_list|,
literal|"%s: Binding command failed: %u\n"
argument_list|,
name|__func__
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|ret
operator|=
name|EIO
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function

begin_function
name|int
name|iwm_mvm_binding_update
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_vap
modifier|*
name|ivp
parameter_list|)
block|{
return|return
name|iwm_mvm_binding_cmd
argument_list|(
name|sc
argument_list|,
name|ivp
argument_list|,
name|IWM_FW_CTXT_ACTION_MODIFY
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|iwm_mvm_binding_add_vif
parameter_list|(
name|struct
name|iwm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|iwm_vap
modifier|*
name|ivp
parameter_list|)
block|{
return|return
name|iwm_mvm_binding_cmd
argument_list|(
name|sc
argument_list|,
name|ivp
argument_list|,
name|IWM_FW_CTXT_ACTION_ADD
argument_list|)
return|;
block|}
end_function

end_unit

