begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * IP Over ATM Support  * -------------------  *  * Protocol definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPATM_IPATM_H
end_ifndef

begin_define
define|#
directive|define
name|_IPATM_IPATM_H
end_define

begin_comment
comment|/*  * Protocol Variables  */
end_comment

begin_define
define|#
directive|define
name|IPATM_VCIDLE
value|15
end_define

begin_comment
comment|/* VCC idle time (minutes) */
end_comment

begin_define
define|#
directive|define
name|IPATM_ARP_TIME
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* Wait for ARP answer */
end_comment

begin_define
define|#
directive|define
name|IPATM_SVC_TIME
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* Wait for SVC open answer */
end_comment

begin_define
define|#
directive|define
name|IPATM_IDLE_TIME
value|(60 * ATM_HZ)
end_define

begin_comment
comment|/* VCC idle timer tick */
end_comment

begin_comment
comment|/*  * IP/ATM LLC/SNAP header  */
end_comment

begin_define
define|#
directive|define
name|IPATM_LLC_LEN
value|8
end_define

begin_define
define|#
directive|define
name|IPATM_LLC_HDR
value|{0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IPATM_IPATM_H */
end_comment

end_unit

