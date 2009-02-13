begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2002  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  * Copyright (c) 2003-2004  *	Hartmut Brandt  *	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/snmp_atm/snmp_atm.h,v 1.2 2004/08/06 17:30:40 brandt Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSNMP_SNMP_ATM_H
end_ifndef

begin_define
define|#
directive|define
name|_BSNMP_SNMP_ATM_H
end_define

begin_enum
enum|enum
name|atmif_notify
block|{
name|ATMIF_NOTIFY_DESTROY
block|,
comment|/* interface has been destroyed */
name|ATMIF_NOTIFY_CARRIER
block|,
comment|/* carriere change */
name|ATMIF_NOTIFY_VCC
comment|/* VCC change */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|atmif_carrier_state
block|{
name|ATMIF_CARRIER_ON
init|=
literal|1
block|,
name|ATMIF_CARRIER_OFF
init|=
literal|2
block|,
name|ATMIF_CARRIER_UNKNOWN
init|=
literal|3
block|,
name|ATMIF_CARRIER_NONE
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|atmif_suni_mode
block|{
name|ATMIF_SUNI_MODE_SONET
init|=
literal|1
block|,
name|ATMIF_SUNI_MODE_SDH
init|=
literal|2
block|,
name|ATMIF_SUNI_MODE_UNKNOWN
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|atmif
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|atmif_event_f
function_decl|)
parameter_list|(
name|struct
name|atmif
modifier|*
parameter_list|,
name|enum
name|atmif_notify
parameter_list|,
name|uintptr_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|atmif_mib
block|{
name|u_int
name|version
decl_stmt|;
comment|/* currently 0 */
name|u_int
name|device
decl_stmt|;
comment|/* type of hardware (system specific) */
name|u_int
name|serial
decl_stmt|;
comment|/* card serial number (device specific) */
name|u_int
name|hw_version
decl_stmt|;
comment|/* card version (device specific) */
name|u_int
name|sw_version
decl_stmt|;
comment|/* firmware version (device specific) */
name|u_int
name|media
decl_stmt|;
comment|/* physical media (see MIB) */
name|u_char
name|esi
index|[
literal|6
index|]
decl_stmt|;
comment|/* end system identifier (MAC) */
name|u_int
name|pcr
decl_stmt|;
comment|/* supported peak cell rate */
name|u_int
name|vpi_bits
decl_stmt|;
comment|/* number of used bits in VPI field */
name|u_int
name|vci_bits
decl_stmt|;
comment|/* number of used bits in VCI field */
name|u_int
name|max_vpcs
decl_stmt|;
comment|/* maximum number of VPCs */
name|u_int
name|max_vccs
decl_stmt|;
comment|/* maximum number of VCCs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmif
block|{
name|struct
name|mibif
modifier|*
name|ifp
decl_stmt|;
comment|/* common interface data */
name|struct
name|atmif_mib
modifier|*
name|mib
decl_stmt|;
comment|/* ATM MIB */
name|enum
name|atmif_carrier_state
name|carrier
decl_stmt|;
name|enum
name|atmif_suni_mode
name|mode
decl_stmt|;
comment|/* SUNI mode SDH or SONET */
block|}
struct|;
end_struct

begin_comment
comment|/* find an ATM interface by name */
end_comment

begin_function_decl
name|struct
name|atmif
modifier|*
name|atm_find_if_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get the interface from the interface index */
end_comment

begin_function_decl
name|struct
name|atmif
modifier|*
name|atm_find_if
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register for notifications */
end_comment

begin_function_decl
name|void
modifier|*
name|atm_notify_aif
parameter_list|(
name|struct
name|atmif
modifier|*
parameter_list|,
specifier|const
name|struct
name|lmodule
modifier|*
name|mod
parameter_list|,
name|atmif_event_f
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_unnotify_aif
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return the If for a system-specific node number */
end_comment

begin_function_decl
name|struct
name|atmif
modifier|*
name|atm_node2if
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return the node id for the if */
end_comment

begin_function_decl
name|u_int
name|atm_if2node
parameter_list|(
name|struct
name|atmif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

