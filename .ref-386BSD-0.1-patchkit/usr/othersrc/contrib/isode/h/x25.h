begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* x25.h - X.25 abstractions */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/RCS/x25.h,v 7.6 91/03/09 11:54:12 mrose Exp $  *  * Contributed by John Pavel, Department of Trade and Industry/National  * Physical Laboratory in the UK  *  *  * $Log:	x25.h,v $  * Revision 7.6  91/03/09  11:54:12  mrose  * update  *   * Revision 7.5  91/02/22  09:25:18  mrose  * Interim 6.8  *   * Revision 7.4  91/01/10  16:12:30  mrose  * bsd44  *   * Revision 7.3  91/01/07  12:39:34  mrose  * update  *   * Revision 7.2  90/11/21  11:32:16  mrose  * sun  *   * Revision 7.1  89/12/07  01:08:00  mrose  * queued writes  *   * Revision 7.0  89/11/23  21:56:10  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X25_
end_ifndef

begin_define
define|#
directive|define
name|_X25_
end_define

begin_comment
comment|/*  *  * #defines for generic addressing& TSEL encoded addresses.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTERNET_
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

begin_ifdef
ifdef|#
directive|ifdef
name|SUN_X25
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sundev/syncstat.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_pk.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_ctl.h>
end_include

begin_include
include|#
directive|include
file|<netx25/x25_ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CAMTEC
end_ifdef

begin_include
include|#
directive|include
file|<cci.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|ccontrolp
name|CONN_DB
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|NTPUV
end_undef

begin_define
define|#
directive|define
name|NTPUV
value|2
end_define

begin_comment
comment|/* CAMTEC allows only 2 iov's per read/write */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CAMTEC_CCL
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<netccl/ccl.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|ccliovec
name|CONN_DB
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UBC_X25
end_ifdef

begin_include
include|#
directive|include
file|<netccitt/x25_sockaddr.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|X25_PACKETSIZE
value|128
end_define

begin_typedef
typedef|typedef
name|struct
name|x25_sockaddr
name|CONN_DB
typedef|;
end_typedef

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
name|SUN_X25
end_ifdef

begin_define
define|#
directive|define
name|close_x25_socket
value|close
end_define

begin_define
define|#
directive|define
name|select_x25_socket
value|selsocket
end_define

begin_define
define|#
directive|define
name|read_x25_socket
value|read
end_define

begin_define
define|#
directive|define
name|write_x25_socket
value|write
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UBC_X25
argument_list|)
operator|||
name|defined
argument_list|(
name|CAMTEC_CCL
argument_list|)
end_if

begin_define
define|#
directive|define
name|close_x25_socket
value|close
end_define

begin_define
define|#
directive|define
name|select_x25_socket
value|selsocket
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUN_X25
end_ifndef

begin_define
define|#
directive|define
name|RECV_DIAG
value|0
end_define

begin_define
define|#
directive|define
name|DIAG_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|WAIT_CONFIRMATION
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|start_x25_client
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_x25_server
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|join_x25_client
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|join_x25_server
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_x25_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_x25_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close_x25_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select_x25_socket
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|NSAPaddr
modifier|*
name|if2gen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|CONN_DB
modifier|*
name|gen2if
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ADDR_LOCAL
value|0
end_define

begin_define
define|#
directive|define
name|ADDR_REMOTE
value|1
end_define

begin_define
define|#
directive|define
name|ADDR_LISTEN
value|2
end_define

begin_define
define|#
directive|define
name|SEPARATOR
value|':'
end_define

begin_define
define|#
directive|define
name|MAXNSDU
value|2048
end_define

begin_comment
comment|/* must be equal to largest TP0 TPDU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

