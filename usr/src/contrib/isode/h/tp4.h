begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tp4.h - TP4 abstractions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/tp4.h,v 7.6 91/02/22 09:25:13 mrose Interim $  *  *  * $Log:	tp4.h,v $  * Revision 7.6  91/02/22  09:25:13  mrose  * Interim 6.8  *   * Revision 7.5  91/01/07  12:39:31  mrose  * update  *   * Revision 7.4  90/07/27  08:44:49  mrose  * update  *   * Revision 7.3  90/02/19  13:09:27  mrose  * update  *   * Revision 7.2  89/12/19  22:26:13  mrose  * touch-up  *   * Revision 7.1  89/12/19  16:18:02  mrose  * dgram  *   * Revision 7.0  89/11/23  21:56:06  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TP4_
end_ifndef

begin_define
define|#
directive|define
name|_TP4_
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_TP4
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SOCK_STREAM
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_include
include|#
directive|include
file|<netiso/iso_errno.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_user.h>
end_include

begin_union
union|union
name|sockaddr_osi
block|{
name|struct
name|sockaddr_iso
name|osi_sockaddr
decl_stmt|;
name|char
name|osi_bigaddr
index|[
literal|104
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|osi_control_msg
block|{
struct|struct
block|{
name|struct
name|cmsghdr
name|ocm_cmhdr
decl_stmt|;
name|char
name|ocm_cmdata
index|[
literal|128
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|cmsghdr
argument_list|)
index|]
decl_stmt|;
block|}
name|ocm_control
struct|;
name|char
name|ocm_data
index|[
literal|128
index|]
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|int
name|gen2tp4
argument_list|()
decl_stmt|,
name|tp42gen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CLTS
end_define

begin_comment
comment|/* have CL-mode transport service */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DGRAM_
end_ifndef

begin_include
include|#
directive|include
file|"dgram.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|start_clts_server
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|start_clts_client
value|start_clts_server
end_define

begin_define
define|#
directive|define
name|join_clts_server
parameter_list|(
name|fd
parameter_list|,
name|sock
parameter_list|)
define|\
value|join_dgram_aux ((fd), (struct sockaddr *) (sock), 0)
end_define

begin_define
define|#
directive|define
name|join_clts_client
parameter_list|(
name|fd
parameter_list|,
name|sock
parameter_list|)
define|\
value|join_dgram_aux ((fd), (struct sockaddr *) (sock), 1)
end_define

begin_define
define|#
directive|define
name|read_clts_socket
value|read_dgram_socket
end_define

begin_define
define|#
directive|define
name|write_clts_socket
value|write_dgram_socket
end_define

begin_define
define|#
directive|define
name|close_clts_socket
value|close_dgram_socket
end_define

begin_define
define|#
directive|define
name|select_clts_socket
value|select_dgram_socket
end_define

begin_define
define|#
directive|define
name|check_clts_socket
value|check_dgram_socket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|SunLink OSI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN_TP4
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUNLINK_6_0
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SUNLINK_5_2
argument_list|)
end_if

begin_define
define|#
directive|define
name|SUNLINK_5_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUNLINK_6_0
end_ifndef

begin_include
include|#
directive|include
file|<sys/ieee802.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<net/if_ieee802.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SOCK_STREAM
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netosi/osi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SUNLINK_5_2
end_ifdef

begin_include
include|#
directive|include
file|<netosi/osi_profile.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netosi/osi_addr.h>
end_include

begin_include
include|#
directive|include
file|<netosi/osi_error.h>
end_include

begin_include
include|#
directive|include
file|<netosi/tp_event.h>
end_include

begin_define
define|#
directive|define
name|MSG_OOB
value|0x1
end_define

begin_comment
comment|/* process out-of-band data */
end_comment

begin_struct
struct|struct
name|tp4pkt
block|{
union|union
block|{
name|TP_MSG
name|tp_msg
decl_stmt|;
name|TP_MSG_CONNECT
name|tp_connect
decl_stmt|;
name|TP_MSG_DATA
name|tp_data
decl_stmt|;
name|TP_MSG_X_DATA
name|tp_x_data
decl_stmt|;
name|TP_MSG_DISCONNECT
name|tp_disconnect
decl_stmt|;
block|}
name|tp_un
union|;
define|#
directive|define
name|tp4_event
value|tp_un.tp_msg.tp_event
define|#
directive|define
name|tp4_called
value|tp_un.tp_connect.dst_address
define|#
directive|define
name|tp4_calling
value|tp_un.tp_connect.src_address
define|#
directive|define
name|tp4_expedited
value|tp_un.tp_connect.expedited_selected
define|#
directive|define
name|tp4_qos
value|tp_un.tp_connect.tp_qos
define|#
directive|define
name|tp4_eot
value|tp_un.tp_data.eot
define|#
directive|define
name|tp4_reason
value|tp_un.tp_disconnect.reason
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tp4pkt
modifier|*
name|newtp4pkt
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|freetp4pkt
parameter_list|(
name|tp
parameter_list|)
value|cfree ((char *) (tp))
end_define

begin_decl_stmt
name|int
name|gen2tp4
argument_list|()
decl_stmt|,
name|tp42gen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_TP4
end_ifdef

begin_define
define|#
directive|define
name|close_tp4_socket
value|close
end_define

begin_define
define|#
directive|define
name|select_tp4_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUN_TP4
end_ifdef

begin_define
define|#
directive|define
name|close_tp4_socket
value|close
end_define

begin_define
define|#
directive|define
name|select_tp4_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|close_tp4_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select_tp4_socket
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

