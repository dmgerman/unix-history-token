begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant - Private copy of Linux netlink/rtnetlink definitions.  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PRIV_NETLINK_H
end_ifndef

begin_define
define|#
directive|define
name|PRIV_NETLINK_H
end_define

begin_comment
comment|/*  * This should be replaced with user space header once one is available with C  * library, etc..  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IFF_LOWER_UP
end_ifndef

begin_define
define|#
directive|define
name|IFF_LOWER_UP
value|0x10000
end_define

begin_comment
comment|/* driver signals L1 up         */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFF_DORMANT
end_ifndef

begin_define
define|#
directive|define
name|IFF_DORMANT
value|0x20000
end_define

begin_comment
comment|/* driver signals dormant       */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFLA_IFNAME
end_ifndef

begin_define
define|#
directive|define
name|IFLA_IFNAME
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFLA_WIRELESS
end_ifndef

begin_define
define|#
directive|define
name|IFLA_WIRELESS
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFLA_OPERSTATE
end_ifndef

begin_define
define|#
directive|define
name|IFLA_OPERSTATE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFLA_LINKMODE
end_ifndef

begin_define
define|#
directive|define
name|IFLA_LINKMODE
value|17
end_define

begin_define
define|#
directive|define
name|IF_OPER_DORMANT
value|5
end_define

begin_define
define|#
directive|define
name|IF_OPER_UP
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NLM_F_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|NETLINK_ROUTE
value|0
end_define

begin_define
define|#
directive|define
name|RTMGRP_LINK
value|1
end_define

begin_define
define|#
directive|define
name|RTM_BASE
value|0x10
end_define

begin_define
define|#
directive|define
name|RTM_NEWLINK
value|(RTM_BASE + 0)
end_define

begin_define
define|#
directive|define
name|RTM_DELLINK
value|(RTM_BASE + 1)
end_define

begin_define
define|#
directive|define
name|RTM_SETLINK
value|(RTM_BASE + 3)
end_define

begin_define
define|#
directive|define
name|NLMSG_ALIGNTO
value|4
end_define

begin_define
define|#
directive|define
name|NLMSG_ALIGN
parameter_list|(
name|len
parameter_list|)
value|(((len) + NLMSG_ALIGNTO - 1)& ~(NLMSG_ALIGNTO - 1))
end_define

begin_define
define|#
directive|define
name|NLMSG_LENGTH
parameter_list|(
name|len
parameter_list|)
value|((len) + NLMSG_ALIGN(sizeof(struct nlmsghdr)))
end_define

begin_define
define|#
directive|define
name|NLMSG_DATA
parameter_list|(
name|nlh
parameter_list|)
value|((void*) (((char*) nlh) + NLMSG_LENGTH(0)))
end_define

begin_define
define|#
directive|define
name|RTA_ALIGNTO
value|4
end_define

begin_define
define|#
directive|define
name|RTA_ALIGN
parameter_list|(
name|len
parameter_list|)
value|(((len) + RTA_ALIGNTO - 1)& ~(RTA_ALIGNTO - 1))
end_define

begin_define
define|#
directive|define
name|RTA_OK
parameter_list|(
name|rta
parameter_list|,
name|len
parameter_list|)
define|\
value|((len)> 0&& (rta)->rta_len>= sizeof(struct rtattr)&& \ (rta)->rta_len<= (len))
end_define

begin_define
define|#
directive|define
name|RTA_NEXT
parameter_list|(
name|rta
parameter_list|,
name|attrlen
parameter_list|)
define|\
value|((attrlen) -= RTA_ALIGN((rta)->rta_len), \ (struct rtattr *) (((char *)(rta)) + RTA_ALIGN((rta)->rta_len)))
end_define

begin_define
define|#
directive|define
name|RTA_LENGTH
parameter_list|(
name|len
parameter_list|)
value|(RTA_ALIGN(sizeof(struct rtattr)) + (len))
end_define

begin_define
define|#
directive|define
name|RTA_DATA
parameter_list|(
name|rta
parameter_list|)
value|((void *) (((char *) (rta)) + RTA_LENGTH(0)))
end_define

begin_struct
struct|struct
name|sockaddr_nl
block|{
name|sa_family_t
name|nl_family
decl_stmt|;
name|unsigned
name|short
name|nl_pad
decl_stmt|;
name|u32
name|nl_pid
decl_stmt|;
name|u32
name|nl_groups
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nlmsghdr
block|{
name|u32
name|nlmsg_len
decl_stmt|;
name|u16
name|nlmsg_type
decl_stmt|;
name|u16
name|nlmsg_flags
decl_stmt|;
name|u32
name|nlmsg_seq
decl_stmt|;
name|u32
name|nlmsg_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifinfomsg
block|{
name|unsigned
name|char
name|ifi_family
decl_stmt|;
name|unsigned
name|char
name|__ifi_pad
decl_stmt|;
name|unsigned
name|short
name|ifi_type
decl_stmt|;
name|int
name|ifi_index
decl_stmt|;
name|unsigned
name|ifi_flags
decl_stmt|;
name|unsigned
name|ifi_change
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtattr
block|{
name|unsigned
name|short
name|rta_len
decl_stmt|;
name|unsigned
name|short
name|rta_type
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRIV_NETLINK_H */
end_comment

end_unit

