begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bthid_config.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: bthid_config.h,v 1.3 2004/02/17 22:05:02 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BTHID_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BTHID_CONFIG_H_
value|1
end_define

begin_define
define|#
directive|define
name|BTHIDD_CONFFILE
value|"/etc/bluetooth/bthidd.conf"
end_define

begin_define
define|#
directive|define
name|BTHIDD_HIDSFILE
value|"/var/db/bthidd.hids"
end_define

begin_struct
struct|struct
name|hid_device
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* HID device BDADDR */
name|uint16_t
name|control_psm
decl_stmt|;
comment|/* control PSM */
name|uint16_t
name|interrupt_psm
decl_stmt|;
comment|/* interrupt PSM */
name|unsigned
name|new_device
range|:
literal|1
decl_stmt|;
name|unsigned
name|reconnect_initiate
range|:
literal|1
decl_stmt|;
name|unsigned
name|battery_power
range|:
literal|1
decl_stmt|;
name|unsigned
name|normally_connectable
range|:
literal|1
decl_stmt|;
name|unsigned
name|reserved
range|:
literal|12
decl_stmt|;
name|report_desc_t
name|desc
decl_stmt|;
comment|/* HID report descriptor */
name|LIST_ENTRY
argument_list|(
argument|hid_device
argument_list|)
name|next
expr_stmt|;
comment|/* link to the next */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|hid_device
name|hid_device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hid_device
modifier|*
name|hid_device_p
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|config_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hids_file
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|read_config_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hid_device_p
name|get_hid_device
parameter_list|(
name|bdaddr_p
name|bdaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hid_device_p
name|get_next_hid_device
parameter_list|(
name|hid_device_p
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_hid_device
parameter_list|(
name|hid_device_p
name|hid_device
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_hids_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_hids_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _BTHID_CONFIG_H_ */
end_comment

end_unit

