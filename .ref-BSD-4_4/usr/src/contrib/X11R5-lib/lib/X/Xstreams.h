begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xstreams.h,v 1.6 91/07/19 23:22:53 gildea Exp $ */
end_comment

begin_comment
comment|/*	Copyright (c) 1990, 1991 UNIX System Laboratories, Inc. */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T */
end_comment

begin_comment
comment|/*	  All Rights Reserved	*/
end_comment

begin_comment
comment|/*  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of AT&T or USL not be used in advertising  * or publicity pertaining to distribution of the software without specific,  * written prior permission.  AT&T and USL make no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * AT&T and USL DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN  * NO EVENT SHALL AT&T or USL BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS  * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XSTREAMS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XSTREAMS_H_
end_define

begin_comment
comment|/*  Xstreams.h (C header file) 	Acc: 575304412 Tue Apr 26 09:46:52 1988 	Mod: 574017273 Tue Apr 26 12:14:33 1988 	Sta: 574017273 Tue Apr 26 12:14:33 1988 	Owner: 2011 	Group: 1985 	Permissions: 644 */
end_comment

begin_comment
comment|/* 	START USER STAMP AREA */
end_comment

begin_comment
comment|/* 	END USER STAMP AREA */
end_comment

begin_define
define|#
directive|define
name|MEM_ALLIGN
parameter_list|(
name|ptr
parameter_list|)
value|((((unsigned) (ptr + 3))>> 2)<< 2)
end_define

begin_define
define|#
directive|define
name|CONNECT_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|MAX_AUTO_BUF_LEN
value|256
end_define

begin_define
define|#
directive|define
name|MAX_DISP_DIGITS
value|20
end_define

begin_define
define|#
directive|define
name|MAX_NETS
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_host
block|{
name|char
name|host_name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|host_len
decl_stmt|;
name|struct
name|_host
modifier|*
name|next
decl_stmt|;
block|}
name|HOST
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for handling multiple connection requests on the same stream.  */
end_comment

begin_struct
struct|struct
name|listenCall
block|{
name|struct
name|t_call
modifier|*
name|CurrentCall
decl_stmt|;
name|struct
name|listenCall
modifier|*
name|NextCall
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|listenQue
block|{
name|struct
name|listenCall
modifier|*
name|QueHead
decl_stmt|;
name|struct
name|listenCall
modifier|*
name|QueTail
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EMPTY
parameter_list|(
name|p
parameter_list|)
value|(p->QueHead == (struct listenCall *) NULL)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|flags
decl_stmt|;
name|char
name|type
decl_stmt|;
name|int
name|display
decl_stmt|;
name|char
modifier|*
name|inputbuf
decl_stmt|;
name|int
name|buflen
decl_stmt|;
name|int
name|bufptr
decl_stmt|;
name|int
name|msglen
decl_stmt|;
block|}
name|IOBUFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|_nnets
decl_stmt|;
ifdef|#
directive|ifdef
name|SVR4
name|struct
name|netconfig
modifier|*
name|_net
index|[
name|MAX_NETS
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|_net
index|[
name|MAX_NETS
index|]
decl_stmt|;
endif|#
directive|endif
name|struct
name|listenQue
name|FreeList
index|[
name|MAX_NETS
index|]
decl_stmt|;
name|struct
name|listenQue
name|PendingQue
index|[
name|MAX_NETS
index|]
decl_stmt|;
name|int
name|_npeers
decl_stmt|;
name|char
modifier|*
modifier|*
name|_peer
decl_stmt|;
name|int
modifier|*
name|_peerlen
decl_stmt|;
name|HOST
modifier|*
name|_validhosts
decl_stmt|;
block|}
name|networkInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Xstream
block|{
name|int
function_decl|(
modifier|*
name|SetupTheListener
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ConnectNewClient
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|CallTheListener
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ReadFromStream
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|BytesCanBeRead
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|WriteToStream
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|CloseStream
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|CreateAddress
function_decl|)
parameter_list|()
function_decl|;
union|union
name|ext
block|{
name|int
function_decl|(
modifier|*
name|NameServer
function_decl|)
parameter_list|()
function_decl|;
name|networkInfo
modifier|*
name|NetInfo
decl_stmt|;
block|}
name|u
union|;
block|}
name|Xstream
typedef|;
end_typedef

begin_comment
comment|/* old shared libraries have the names already fixed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USL_COMPAT
end_ifdef

begin_define
define|#
directive|define
name|_XsStream
value|xstream
end_define

begin_define
define|#
directive|define
name|_XReadV
value|_readv
end_define

begin_define
define|#
directive|define
name|_XWriteV
value|_writev
end_define

begin_define
define|#
directive|define
name|_XSelect
value|XSelect
end_define

begin_define
define|#
directive|define
name|_XsErrorCall
value|ErrorCall
end_define

begin_define
define|#
directive|define
name|_XsSetupLocalStream
value|SetupLocalStream
end_define

begin_define
define|#
directive|define
name|_XsConnectLocalClient
value|ConnectLocalClient
end_define

begin_define
define|#
directive|define
name|_XsOpenSpServer
value|OpenSpServer
end_define

begin_define
define|#
directive|define
name|_XsReadLocalStream
value|ReadLocalStream
end_define

begin_define
define|#
directive|define
name|_XsConnectTliClient
value|ConnectTliClient
end_define

begin_define
define|#
directive|define
name|_XsSetupTliStrean
value|SetupTliStream
end_define

begin_define
define|#
directive|define
name|_XsCallTliServer
value|CallTliServer
end_define

begin_define
define|#
directive|define
name|_XsCallLocalServer
value|CallLocalServer
end_define

begin_define
define|#
directive|define
name|_XsTypeOfStream
value|TypeOfStream
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|_XsSetupNamedStream
value|SetupNamedStream
end_define

begin_define
define|#
directive|define
name|_XsSetupSpStream
value|SetupSpStream
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USL_COMPAT */
end_comment

begin_decl_stmt
specifier|extern
name|Xstream
name|_XsStream
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NO_BUFFERING
value|0
end_define

begin_define
define|#
directive|define
name|BUFFERING
value|1
end_define

begin_comment
comment|/* Network services */
end_comment

begin_define
define|#
directive|define
name|OpenDaemonConnection
value|0
end_define

begin_define
define|#
directive|define
name|PEER_NAME
value|1
end_define

begin_define
define|#
directive|define
name|PEER_ALLOC
value|2
end_define

begin_define
define|#
directive|define
name|PEER_FREE
value|3
end_define

begin_define
define|#
directive|define
name|ConvertNetAddrToName
value|4
end_define

begin_define
define|#
directive|define
name|ConvertNameToNetAddr
value|5
end_define

begin_define
define|#
directive|define
name|ConvertNameToTliCall
value|6
end_define

begin_define
define|#
directive|define
name|ConvertTliCallToName
value|7
end_define

begin_define
define|#
directive|define
name|ConvertNameToTliBind
value|8
end_define

begin_define
define|#
directive|define
name|UNAME_LENGTH
value|14
end_define

begin_define
define|#
directive|define
name|X_LOCAL_STREAM
value|0
end_define

begin_define
define|#
directive|define
name|X_NAMED_STREAM
value|1
end_define

begin_comment
comment|/* Enhanced Application Compatibility Support */
end_comment

begin_define
define|#
directive|define
name|X_SP_STREAM
value|2
end_define

begin_comment
comment|/* End Enhanced Application Compatibility Support */
end_comment

begin_define
define|#
directive|define
name|X_TLI_STREAM
value|3
end_define

begin_define
define|#
directive|define
name|CLOSED_STREAM
value|-1
end_define

begin_comment
comment|/* 	The following are defined in X.h. Any changes to FamilyUname 	should take X.h into consideration. */
end_comment

begin_comment
comment|/* protocol families */
end_comment

begin_comment
comment|/*  		#define FamilyInternet		0 		#define FamilyDECnet		1 		#define FamilyChaos		2  		*/
end_comment

begin_define
define|#
directive|define
name|FamilyUname
value|3
end_define

begin_define
define|#
directive|define
name|X_TCP_PORT
value|6000
end_define

begin_define
define|#
directive|define
name|NAMED_LISTENER
value|"/dev/X/Nserver"
end_define

begin_define
define|#
directive|define
name|LOCAL_LISTENER
value|"/dev/X/server"
end_define

begin_comment
comment|/* Enhanced Application Compatibility Support */
end_comment

begin_comment
comment|/* End Enhanced Application Compatibility Support */
end_comment

begin_define
define|#
directive|define
name|NAME_SERVER_NODE
value|"/dev/X/nameserver"
end_define

begin_define
define|#
directive|define
name|XNETSPECDIR
value|"lib/net"
end_define

begin_define
define|#
directive|define
name|XROOTDIR
value|"/usr/X"
end_define

begin_define
define|#
directive|define
name|MAX_SIMUL_TLI_CALLS
value|20
end_define

begin_define
define|#
directive|define
name|SetupNetworkInfo
parameter_list|()
value|_XsStream[X_LOCAL_STREAM].u.NetInfo =&Network; \ 	_XsStream[X_NAMED_STREAM].u.NetInfo =&Network; \
comment|/* Enhanced Application Compatibility Support */
value|\
comment|/* End Enhanced Application Compatibility Support */
value|\ 	_XsStream[X_TLI_STREAM].u.NameServer = nameserver
end_define

begin_define
define|#
directive|define
name|NetworkInfo
value|(_XsStream[X_LOCAL_STREAM].u.NetInfo)
end_define

begin_define
define|#
directive|define
name|GetNetworkInfo
value|(*_XsStream[X_TLI_STREAM].u.NameServer)
end_define

begin_define
define|#
directive|define
name|validhosts
value|_XsStream[X_LOCAL_STREAM].u.NetInfo->_validhosts
end_define

begin_comment
comment|/*  *	header of messages sent by X to the nameserver   *      1st int: the size of the entire message.  *	2nd int: the size of the header itself.  *  	3rd int: the service number.  *      4th int: the display number.  * 	5th int: the length of the network name.  */
end_comment

begin_define
define|#
directive|define
name|HEADERSIZE
value|(5*sizeof(int))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XSTREAMS_H_ */
end_comment

end_unit

