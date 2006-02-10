begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems Inc.<ambrisko@ironport.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|IPMI_MAX_ADDR_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|IPMI_MAX_RX
value|1024
end_define

begin_define
define|#
directive|define
name|IPMI_BMC_SLAVE_ADDR
value|0x20
end_define

begin_comment
comment|/* Linux Default slave address */
end_comment

begin_define
define|#
directive|define
name|IPMI_BMC_CHANNEL
value|0x0f
end_define

begin_comment
comment|/* Linux BMC channel */
end_comment

begin_define
define|#
directive|define
name|IPMI_BMC_SMS_LUN
value|0x02
end_define

begin_define
define|#
directive|define
name|IPMI_SYSTEM_INTERFACE_ADDR_TYPE
value|0x0c
end_define

begin_define
define|#
directive|define
name|IPMI_IPMB_ADDR_TYPE
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_IPMB_BROADCAST_ADDR_TYPE
value|0x41
end_define

begin_define
define|#
directive|define
name|IPMI_IOC_MAGIC
value|'i'
end_define

begin_define
define|#
directive|define
name|IPMICTL_RECEIVE_MSG_TRUNC
value|_IOWR(IPMI_IOC_MAGIC, 11, struct ipmi_recv)
end_define

begin_define
define|#
directive|define
name|IPMICTL_RECEIVE_MSG
value|_IOWR(IPMI_IOC_MAGIC, 12, struct ipmi_recv)
end_define

begin_define
define|#
directive|define
name|IPMICTL_SEND_COMMAND
value|_IOW(IPMI_IOC_MAGIC, 13, struct ipmi_req)
end_define

begin_define
define|#
directive|define
name|IPMICTL_REGISTER_FOR_CMD
value|_IOW(IPMI_IOC_MAGIC, 14, struct ipmi_cmdspec)
end_define

begin_define
define|#
directive|define
name|IPMICTL_UNREGISTER_FOR_CMD
value|_IOW(IPMI_IOC_MAGIC, 15, struct ipmi_cmdspec)
end_define

begin_define
define|#
directive|define
name|IPMICTL_SET_GETS_EVENTS_CMD
value|_IOW(IPMI_IOC_MAGIC, 16, int)
end_define

begin_define
define|#
directive|define
name|IPMICTL_SET_MY_ADDRESS_CMD
value|_IOW(IPMI_IOC_MAGIC, 17, unsigned int)
end_define

begin_define
define|#
directive|define
name|IPMICTL_GET_MY_ADDRESS_CMD
value|_IOR(IPMI_IOC_MAGIC, 18, unsigned int)
end_define

begin_define
define|#
directive|define
name|IPMICTL_SET_MY_LUN_CMD
value|_IOW(IPMI_IOC_MAGIC, 19, unsigned int)
end_define

begin_define
define|#
directive|define
name|IPMICTL_GET_MY_LUN_CMD
value|_IOR(IPMI_IOC_MAGIC, 20, unsigned int)
end_define

begin_define
define|#
directive|define
name|IPMI_RESPONSE_RECV_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|IPMI_ASYNC_EVENT_RECV_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|IPMI_CMD_RECV_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|IPMI_APP_REQUEST
value|0x06
end_define

begin_define
define|#
directive|define
name|IPMI_GET_DEVICE_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_CLEAR_FLAGS
value|0x30
end_define

begin_define
define|#
directive|define
name|IPMI_GET_MSG_FLAGS
value|0x31
end_define

begin_define
define|#
directive|define
name|IPMI_MSG_AVAILABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_MSG_BUFFER_FULL
value|0x02
end_define

begin_define
define|#
directive|define
name|IPMI_WDT_PRE_TIMEOUT
value|0x08
end_define

begin_define
define|#
directive|define
name|IPMI_GET_MSG
value|0x33
end_define

begin_define
define|#
directive|define
name|IPMI_SEND_MSG
value|0x34
end_define

begin_define
define|#
directive|define
name|IPMI_GET_CHANNEL_INFO
value|0x42
end_define

begin_define
define|#
directive|define
name|IPMI_RESET_WDOG
value|0x22
end_define

begin_define
define|#
directive|define
name|IPMI_SET_WDOG
value|0x24
end_define

begin_define
define|#
directive|define
name|IPMI_GET_WDOG
value|0x25
end_define

begin_define
define|#
directive|define
name|IPMI_SET_WD_TIMER_SMS_OS
value|0x04
end_define

begin_define
define|#
directive|define
name|IPMI_SET_WD_TIMER_DONT_STOP
value|0x40
end_define

begin_define
define|#
directive|define
name|IPMI_SET_WD_ACTION_RESET
value|0x01
end_define

begin_struct
struct|struct
name|ipmi_msg
block|{
name|unsigned
name|char
name|netfn
decl_stmt|;
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|short
name|data_len
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_req
block|{
name|unsigned
name|char
modifier|*
name|addr
decl_stmt|;
name|unsigned
name|int
name|addr_len
decl_stmt|;
name|long
name|msgid
decl_stmt|;
name|struct
name|ipmi_msg
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_recv
block|{
name|int
name|recv_type
decl_stmt|;
name|unsigned
name|char
modifier|*
name|addr
decl_stmt|;
name|unsigned
name|int
name|addr_len
decl_stmt|;
name|long
name|msgid
decl_stmt|;
name|struct
name|ipmi_msg
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_cmdspec
block|{
name|unsigned
name|char
name|netfn
decl_stmt|;
name|unsigned
name|char
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_addr
block|{
name|int
name|addr_type
decl_stmt|;
name|short
name|channel
decl_stmt|;
name|unsigned
name|char
name|data
index|[
name|IPMI_MAX_ADDR_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_system_interface_addr
block|{
name|int
name|addr_type
decl_stmt|;
name|short
name|channel
decl_stmt|;
name|unsigned
name|char
name|lun
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipmi_ipmb_addr
block|{
name|int
name|addr_type
decl_stmt|;
name|short
name|channel
decl_stmt|;
name|unsigned
name|char
name|slave_addr
decl_stmt|;
name|unsigned
name|char
name|lun
decl_stmt|;
block|}
struct|;
end_struct

end_unit

