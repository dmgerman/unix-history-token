begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*----------------------------------------------------------------------  * key.h :     Declarations and Definitions for Key Engine for BSD.  *  * Copyright 1995 by Bao Phan, Randall Atkinson,& Dan McDonald,  * All Rights Reserved.  All rights have been assigned to the US  * Naval Research Laboratory (NRL).  The NRL Copyright Notice and  * License Agreement governs distribution and use of this software.  *  * Patents are pending on this technology.  NRL grants a license  * to use this technology at no cost under the terms below with  * the additional requirement that software, hardware, and  * documentation relating to use of this technology must include  * the note that:  *    	This product includes technology developed at and  *      licensed from the Information Technology Division,  *	US Naval Research Laboratory.  *  ----------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------- #	@(#)COPYRIGHT	1.1a (NRL) 17 August 1995  COPYRIGHT NOTICE  All of the documentation and software included in this software distribution from the US Naval Research Laboratory (NRL) are copyrighted by their respective developers.  This software and documentation were developed at NRL by various people.  Those developers have each copyrighted the portions that they developed at NRL and have assigned All Rights for those portions to NRL.  Outside the USA, NRL also has copyright on the software developed at NRL. The affected files all contain specific copyright notices and those notices must be retained in any derived work.  NRL LICENSE  NRL grants permission for redistribution and use in source and binary forms, with or without modification, of the software and documentation created at NRL provided that the following conditions are met:  1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright    notice, this list of conditions and the following disclaimer in the    documentation and/or other materials provided with the distribution. 3. All advertising materials mentioning features or use of this software    must display the following acknowledgement:  	This product includes software developed at the Information 	Technology Division, US Naval Research Laboratory.  4. Neither the name of the NRL nor the names of its contributors    may be used to endorse or promote products derived from this software    without specific prior written permission.  THE SOFTWARE PROVIDED BY NRL IS PROVIDED BY NRL AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL NRL OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  The views and conclusions contained in the software and documentation are those of the authors and should not be interpreted as representing official policies, either expressed or implied, of the US Naval Research Laboratory (NRL).  ----------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_netkey_key_h
end_ifndef

begin_define
define|#
directive|define
name|_netkey_key_h
value|1
end_define

begin_comment
comment|/*  * PF_KEY messages  */
end_comment

begin_define
define|#
directive|define
name|KEY_ADD
value|1
end_define

begin_define
define|#
directive|define
name|KEY_DELETE
value|2
end_define

begin_define
define|#
directive|define
name|KEY_UPDATE
value|3
end_define

begin_define
define|#
directive|define
name|KEY_GET
value|4
end_define

begin_define
define|#
directive|define
name|KEY_ACQUIRE
value|5
end_define

begin_define
define|#
directive|define
name|KEY_GETSPI
value|6
end_define

begin_define
define|#
directive|define
name|KEY_REGISTER
value|7
end_define

begin_define
define|#
directive|define
name|KEY_EXPIRE
value|8
end_define

begin_define
define|#
directive|define
name|KEY_DUMP
value|9
end_define

begin_define
define|#
directive|define
name|KEY_FLUSH
value|10
end_define

begin_define
define|#
directive|define
name|KEY_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|POLICY_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|SECURITY_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_AH
value|1
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_ESP
value|2
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_RSVP
value|3
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_OSPF
value|4
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_RIPV2
value|5
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_MIPV4
value|6
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_MIPV6
value|7
end_define

begin_define
define|#
directive|define
name|KEY_TYPE_MAX
value|7
end_define

begin_comment
comment|/*  * Security association state  */
end_comment

begin_define
define|#
directive|define
name|K_USED
value|0x1
end_define

begin_comment
comment|/* Key used/not used */
end_comment

begin_define
define|#
directive|define
name|K_UNIQUE
value|0x2
end_define

begin_comment
comment|/* Key unique/reusable */
end_comment

begin_define
define|#
directive|define
name|K_LARVAL
value|0x4
end_define

begin_comment
comment|/* SPI assigned, but sa incomplete */
end_comment

begin_define
define|#
directive|define
name|K_ZOMBIE
value|0x8
end_define

begin_comment
comment|/* sa expired but still useable */
end_comment

begin_define
define|#
directive|define
name|K_DEAD
value|0x10
end_define

begin_comment
comment|/* sa marked for deletion, ready for reaping */
end_comment

begin_define
define|#
directive|define
name|K_INBOUND
value|0x20
end_define

begin_comment
comment|/* sa for inbound packets, ie. dst=myhost */
end_comment

begin_define
define|#
directive|define
name|K_OUTBOUND
value|0x40
end_define

begin_comment
comment|/* sa for outbound packets, ie. src=myhost */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_SOCKADDR_SZ
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|MAX_SOCKADDR_SZ
value|(sizeof(struct sockaddr_in6))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INET6 */
end_comment

begin_define
define|#
directive|define
name|MAX_SOCKADDR_SZ
value|(sizeof(struct sockaddr_in))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAX_SOCKADDR_SZ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_KEY_SZ
end_ifndef

begin_define
define|#
directive|define
name|MAX_KEY_SZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAX_KEY_SZ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_IV_SZ
end_ifndef

begin_define
define|#
directive|define
name|MAX_IV_SZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAX_IV_SZ */
end_comment

begin_comment
comment|/* Security association data for IP Security */
end_comment

begin_struct
struct|struct
name|key_secassoc
block|{
name|u_int8_t
name|len
decl_stmt|;
comment|/* Length of the data (for radix) */
name|u_int8_t
name|type
decl_stmt|;
comment|/* Type of association */
name|u_int8_t
name|vers
decl_stmt|;
comment|/* Version of association (AH/ESP) */
name|u_int8_t
name|state
decl_stmt|;
comment|/* State of the association */
name|u_int8_t
name|label
decl_stmt|;
comment|/* Sensitivity label (unused) */
name|u_int32_t
name|spi
decl_stmt|;
comment|/* SPI */
name|u_int8_t
name|keylen
decl_stmt|;
comment|/* Key length */
name|u_int8_t
name|ekeylen
decl_stmt|;
comment|/* Extra key length */
name|u_int8_t
name|ivlen
decl_stmt|;
comment|/* Initialization vector length */
name|u_int8_t
name|algorithm
decl_stmt|;
comment|/* Algorithm switch index */
name|u_int8_t
name|lifetype
decl_stmt|;
comment|/* Type of lifetime */
name|caddr_t
name|iv
decl_stmt|;
comment|/* Initialization vector */
name|caddr_t
name|key
decl_stmt|;
comment|/* Key */
name|caddr_t
name|ekey
decl_stmt|;
comment|/* Extra key */
name|u_int32_t
name|lifetime1
decl_stmt|;
comment|/* Lifetime value 1 */
name|u_int32_t
name|lifetime2
decl_stmt|;
comment|/* Lifetime value 2 */
name|struct
name|sockaddr
modifier|*
name|src
decl_stmt|;
comment|/* Source host address */
name|struct
name|sockaddr
modifier|*
name|dst
decl_stmt|;
comment|/* Destination host address */
name|struct
name|sockaddr
modifier|*
name|from
decl_stmt|;
comment|/* Originator of association */
name|int
name|antireplay
decl_stmt|;
comment|/*anti replay flag*/
name|u_int32_t
name|sequence
decl_stmt|;
comment|/*send: sequence number*/
name|u_int32_t
name|replayright
decl_stmt|;
comment|/*receive: replay window, right*/
name|u_int64_t
name|replaywindow
decl_stmt|;
comment|/*receive: replay window*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for key message header. PF_KEY message consists of key_msghdr  * followed by src struct sockaddr, dest struct sockaddr, from struct  * sockaddr, key, and iv. Assumes size of key message header less than MHLEN.  */
end_comment

begin_struct
struct|struct
name|key_msghdr
block|{
name|u_short
name|key_msglen
decl_stmt|;
comment|/* length of message including 					 * src/dst/from/key/iv */
name|u_char
name|key_msgvers
decl_stmt|;
comment|/* key version number */
name|u_char
name|key_msgtype
decl_stmt|;
comment|/* key message type, eg. KEY_ADD */
name|pid_t
name|key_pid
decl_stmt|;
comment|/* process id of message sender */
name|int
name|key_seq
decl_stmt|;
comment|/* message sequence number */
name|int
name|key_errno
decl_stmt|;
comment|/* error code */
name|u_int8_t
name|type
decl_stmt|;
comment|/* type of security association */
name|u_int8_t
name|vers
decl_stmt|;
comment|/* version of sassoc (AH/ESP) */
name|u_int8_t
name|state
decl_stmt|;
comment|/* state of security association */
name|u_int8_t
name|label
decl_stmt|;
comment|/* sensitivity level */
name|u_int8_t
name|pad
decl_stmt|;
comment|/* padding for allignment */
name|u_int32_t
name|spi
decl_stmt|;
comment|/* spi value */
name|u_int8_t
name|keylen
decl_stmt|;
comment|/* key length */
name|u_int8_t
name|ekeylen
decl_stmt|;
comment|/* extra key length */
name|u_int8_t
name|ivlen
decl_stmt|;
comment|/* iv length */
name|u_int8_t
name|algorithm
decl_stmt|;
comment|/* algorithm identifier */
name|u_int8_t
name|lifetype
decl_stmt|;
comment|/* type of lifetime */
name|u_int32_t
name|lifetime1
decl_stmt|;
comment|/* lifetime value 1 */
name|u_int32_t
name|lifetime2
decl_stmt|;
comment|/* lifetime value 2 */
name|int
name|antireplay
decl_stmt|;
comment|/* anti replay flag */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_msgdata
block|{
name|struct
name|sockaddr
modifier|*
name|src
decl_stmt|;
comment|/* source host address */
name|struct
name|sockaddr
modifier|*
name|dst
decl_stmt|;
comment|/* destination host address */
name|struct
name|sockaddr
modifier|*
name|from
decl_stmt|;
comment|/* originator of security association */
name|caddr_t
name|iv
decl_stmt|;
comment|/* initialization vector */
name|caddr_t
name|key
decl_stmt|;
comment|/* key */
name|caddr_t
name|ekey
decl_stmt|;
comment|/* extra key */
name|int
name|ivlen
decl_stmt|;
comment|/* key length */
name|int
name|keylen
decl_stmt|;
comment|/* iv length */
name|int
name|ekeylen
decl_stmt|;
comment|/* extra key length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|policy_msghdr
block|{
name|u_short
name|policy_msglen
decl_stmt|;
comment|/* message length */
name|u_char
name|policy_msgvers
decl_stmt|;
comment|/* message version */
name|u_char
name|policy_msgtype
decl_stmt|;
comment|/* message type */
name|int
name|policy_seq
decl_stmt|;
comment|/* message sequence number */
name|int
name|policy_errno
decl_stmt|;
comment|/* error code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Key engine table structures  */
end_comment

begin_struct
struct|struct
name|socketlist
block|{
name|struct
name|socket
modifier|*
name|socket
decl_stmt|;
comment|/* pointer to socket */
name|struct
name|socketlist
modifier|*
name|next
decl_stmt|;
comment|/* next */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_tblnode
block|{
name|int
name|alloc_count
decl_stmt|;
comment|/* number of sockets allocated to 					 * secassoc */
name|int
name|ref_count
decl_stmt|;
comment|/* number of sockets referencing 					 * secassoc */
name|struct
name|socketlist
modifier|*
name|solist
decl_stmt|;
comment|/* list of sockets allocated to 					 * secassoc */
name|struct
name|key_secassoc
modifier|*
name|secassoc
decl_stmt|;
comment|/* security association */
name|struct
name|key_tblnode
modifier|*
name|next
decl_stmt|;
comment|/* next node */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_allocnode
block|{
name|struct
name|key_tblnode
modifier|*
name|keynode
decl_stmt|;
name|struct
name|key_allocnode
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_so2spinode
block|{
name|struct
name|socket
modifier|*
name|socket
decl_stmt|;
comment|/* socket pointer */
name|struct
name|key_tblnode
modifier|*
name|keynode
decl_stmt|;
comment|/* pointer to tblnode containing 					 * secassoc */
comment|/* info for socket  */
name|struct
name|key_so2spinode
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_registry
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* secassoc type that key mgnt. daemon can 				 * acquire */
name|struct
name|socket
modifier|*
name|socket
decl_stmt|;
comment|/* key management daemon socket pointer */
name|struct
name|key_registry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|key_acquirelist
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* secassoc type to acquire */
name|struct
name|sockaddr
modifier|*
name|target
decl_stmt|;
comment|/* destination address of secassoc */
name|u_int32_t
name|count
decl_stmt|;
comment|/* number of acquire messages sent */
name|u_long
name|expiretime
decl_stmt|;
comment|/* expiration time for acquire message */
name|struct
name|key_acquirelist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|keyso_cb
block|{
name|int
name|ip4_count
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|int
name|ip6_count
decl_stmt|;
endif|#
directive|endif
comment|/*INET6*/
name|int
name|any_count
decl_stmt|;
comment|/* Sum of above counters */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|key_secassoc2msghdr
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|,
expr|struct
name|key_msghdr
operator|*
operator|,
expr|struct
name|key_msgdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_msghdr2secassoc
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|,
expr|struct
name|key_msghdr
operator|*
operator|,
expr|struct
name|key_msgdata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_inittables
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_sodelete
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_add
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_delete
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_get
name|__P
argument_list|(
operator|(
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_int32_t
operator|,
expr|struct
name|key_secassoc
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_flush
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_dump
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_getspi
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_update
name|__P
argument_list|(
operator|(
expr|struct
name|key_secassoc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_register
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_unregister
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_acquire
name|__P
argument_list|(
operator|(
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getassocbyspi
name|__P
argument_list|(
operator|(
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_int32_t
operator|,
expr|struct
name|key_tblnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getassocbysocket
name|__P
argument_list|(
operator|(
name|u_int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|socket
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|key_tblnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_free
name|__P
argument_list|(
operator|(
expr|struct
name|key_tblnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_parse
name|__P
argument_list|(
operator|(
expr|struct
name|key_msghdr
operator|*
operator|*
name|km
operator|,
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _netkey_key_h */
end_comment

end_unit

