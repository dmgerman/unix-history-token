begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM socket protocol definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_PCB_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_PCB_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * ATM Socket PCB  *  * Common structure for all ATM protocol sockets.  This control block  * will be used for all ATM socket types.  */
end_comment

begin_struct
struct|struct
name|atm_pcb
block|{
name|struct
name|socket
modifier|*
name|atp_socket
decl_stmt|;
comment|/* Socket */
name|Atm_connection
modifier|*
name|atp_conn
decl_stmt|;
comment|/* Connection manager token */
name|u_char
name|atp_type
decl_stmt|;
comment|/* Protocol type (see below) */
name|u_char
name|atp_flags
decl_stmt|;
comment|/* Protocol flags (see below) */
name|Atm_attributes
name|atp_attr
decl_stmt|;
comment|/* Socket's call attributes */
name|char
name|atp_name
index|[
name|T_ATM_APP_NAME_LEN
index|]
decl_stmt|;
comment|/* Owner's name */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_pcb
name|Atm_pcb
typedef|;
end_typedef

begin_comment
comment|/*  * Protocol Types  */
end_comment

begin_define
define|#
directive|define
name|ATPT_AAL5
value|0
end_define

begin_comment
comment|/* AAL type 5 protocol */
end_comment

begin_define
define|#
directive|define
name|ATPT_SSCOP
value|1
end_define

begin_comment
comment|/* SSCOP protocol */
end_comment

begin_define
define|#
directive|define
name|ATPT_NUM
value|2
end_define

begin_comment
comment|/* Number of protocols */
end_comment

begin_comment
comment|/*  * PCB Flags  */
end_comment

begin_comment
comment|/*  * Handy macros  */
end_comment

begin_define
define|#
directive|define
name|sotoatmpcb
parameter_list|(
name|so
parameter_list|)
value|((Atm_pcb *)(so)->so_pcb)
end_define

begin_comment
comment|/*  * ATM Socket Statistics  */
end_comment

begin_struct
struct|struct
name|atm_sock_stat
block|{
name|u_long
name|as_connreq
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Connection requests */
name|u_long
name|as_inconn
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Incoming connection requests */
name|u_long
name|as_conncomp
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Connections completed */
name|u_long
name|as_connfail
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Connections failed */
name|u_long
name|as_connrel
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Connections released */
name|u_long
name|as_connclr
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Connections cleared */
name|u_long
name|as_indrop
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Input packets dropped */
name|u_long
name|as_outdrop
index|[
name|ATPT_NUM
index|]
decl_stmt|;
comment|/* Output packets dropped */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_PCB_H */
end_comment

end_unit

