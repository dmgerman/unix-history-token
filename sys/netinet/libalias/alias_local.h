begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Charles Mott<cm@linktel.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Alias_local.h contains the function prototypes for alias.c,  * alias_db.c, alias_util.c and alias_ftp.c, alias_irc.c (as well  * as any future add-ons).  It also includes macros, globals and  * struct definitions shared by more than one alias*.c file.  *  * This include file is intended to be used only within the aliasing  * software.  Outside world interfaces are defined in alias.h  *  * This software is placed into the public domain with no restrictions  * on its distribution.  *  * Initial version:  August, 1996  (cjm)  *  *<updated several times by original author and Eivind Eklund>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_LOCAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* XXX: LibAliasSetTarget() uses this constant. */
end_comment

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sizes of input and output link tables */
end_comment

begin_define
define|#
directive|define
name|LINK_TABLE_OUT_SIZE
value|101
end_define

begin_define
define|#
directive|define
name|LINK_TABLE_IN_SIZE
value|4001
end_define

begin_struct_decl
struct_decl|struct
name|proxy_entry
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|libalias
block|{
name|LIST_ENTRY
argument_list|(
argument|libalias
argument_list|)
name|instancelist
expr_stmt|;
name|int
name|packetAliasMode
decl_stmt|;
comment|/* Mode flags                      */
comment|/* - documented in alias.h  */
name|struct
name|in_addr
name|aliasAddress
decl_stmt|;
comment|/* Address written onto source     */
comment|/* field of IP packet.           */
name|struct
name|in_addr
name|targetAddress
decl_stmt|;
comment|/* IP address incoming packets     */
comment|/* are sent to if no aliasing    */
comment|/* link already exists           */
name|struct
name|in_addr
name|nullAddress
decl_stmt|;
comment|/* Used as a dummy parameter for   */
comment|/* some function calls           */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|alias_link
argument_list|)
name|linkTableOut
index|[
name|LINK_TABLE_OUT_SIZE
index|]
expr_stmt|;
comment|/* Lookup table of pointers to     */
comment|/* chains of link records. Each  */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|alias_link
argument_list|)
name|linkTableIn
index|[
name|LINK_TABLE_IN_SIZE
index|]
expr_stmt|;
comment|/* link record is doubly indexed */
comment|/* into input and output lookup  */
comment|/* tables.                       */
comment|/* Link statistics                 */
name|int
name|icmpLinkCount
decl_stmt|;
name|int
name|udpLinkCount
decl_stmt|;
name|int
name|tcpLinkCount
decl_stmt|;
name|int
name|pptpLinkCount
decl_stmt|;
name|int
name|protoLinkCount
decl_stmt|;
name|int
name|fragmentIdLinkCount
decl_stmt|;
name|int
name|fragmentPtrLinkCount
decl_stmt|;
name|int
name|sockCount
decl_stmt|;
name|int
name|cleanupIndex
decl_stmt|;
comment|/* Index to chain of link table    */
comment|/* being inspected for old links   */
name|int
name|timeStamp
decl_stmt|;
comment|/* System time in seconds for      */
comment|/* current packet                  */
name|int
name|lastCleanupTime
decl_stmt|;
comment|/* Last time 						 * IncrementalCleanup()  */
comment|/* was called                      */
name|int
name|houseKeepingResidual
decl_stmt|;
comment|/* used by HouseKeeping()          */
name|int
name|deleteAllLinks
decl_stmt|;
comment|/* If equal to zero, DeleteLink()  */
comment|/* will not remove permanent links */
comment|/* log descriptor        */
ifdef|#
directive|ifdef
name|_KERNEL
name|char
modifier|*
name|logDesc
decl_stmt|;
else|#
directive|else
name|FILE
modifier|*
name|logDesc
decl_stmt|;
endif|#
directive|endif
comment|/* statistics monitoring */
name|int
name|newDefaultLink
decl_stmt|;
comment|/* Indicates if a new aliasing     */
comment|/* link has been created after a   */
comment|/* call to PacketAliasIn/Out().    */
ifndef|#
directive|ifndef
name|NO_FW_PUNCH
name|int
name|fireWallFD
decl_stmt|;
comment|/* File descriptor to be able to   */
comment|/* control firewall.  Opened by    */
comment|/* PacketAliasSetMode on first     */
comment|/* setting the PKT_ALIAS_PUNCH_FW  */
comment|/* flag.                           */
name|int
name|fireWallBaseNum
decl_stmt|;
comment|/* The first firewall entry 						 * free for our use */
name|int
name|fireWallNumNums
decl_stmt|;
comment|/* How many entries can we 						 * use? */
name|int
name|fireWallActiveNum
decl_stmt|;
comment|/* Which entry did we last 						 * use? */
name|char
modifier|*
name|fireWallField
decl_stmt|;
comment|/* bool array for entries */
endif|#
directive|endif
name|unsigned
name|int
name|skinnyPort
decl_stmt|;
comment|/* TCP port used by the Skinny     */
comment|/* protocol.                       */
name|struct
name|proxy_entry
modifier|*
name|proxyList
decl_stmt|;
name|struct
name|in_addr
name|true_addr
decl_stmt|;
comment|/* in network byte order. */
name|u_short
name|true_port
decl_stmt|;
comment|/* in host byte order. */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/*  	 * avoid races in libalias: every public function has to use it. 	 */
name|struct
name|mtx
name|mutex
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Macros */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_INIT
parameter_list|(
name|l
parameter_list|)
define|\
value|mtx_init(&l->mutex, "per-instance libalias mutex", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_ASSERT
parameter_list|(
name|l
parameter_list|)
value|mtx_assert(&l->mutex, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK
parameter_list|(
name|l
parameter_list|)
value|mtx_lock(&l->mutex)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_UNLOCK
parameter_list|(
name|l
parameter_list|)
value|mtx_unlock(&l->mutex)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_DESTROY
parameter_list|(
name|l
parameter_list|)
value|mtx_destroy(&l->mutex)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_INIT
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_ASSERT
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_UNLOCK
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LIBALIAS_LOCK_DESTROY
parameter_list|(
name|l
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following macro is used to update an  * internet checksum.  "delta" is a 32-bit  * accumulation of all the changes to the  * checksum (adding in new 16-bit words and  * subtracting out old words), and "cksum"  * is the checksum value to be updated.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_CHECKSUM
parameter_list|(
name|acc
parameter_list|,
name|cksum
parameter_list|)
define|\
value|do { \ 		acc += cksum; \ 		if (acc< 0) { \ 			acc = -acc; \ 			acc = (acc>> 16) + (acc& 0xffff); \ 			acc += acc>> 16; \ 			cksum = (u_short) ~acc; \ 		} else { \ 			acc = (acc>> 16) + (acc& 0xffff); \ 			acc += acc>> 16; \ 			cksum = (u_short) acc; \ 		} \ 	} while (0)
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_comment
comment|/*  * We do not calculate TCP checksums when libalias is a kernel  * module, since it has no idea about checksum offloading.  * If TCP data has changed, then we just set checksum to zero,  * and caller must recalculate it himself.  * In case if libalias will edit UDP data, the same approach  * should be used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|u_short
name|IpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
name|_pip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|TcpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
name|_pip
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|DifferentialChecksum
parameter_list|(
name|u_short
modifier|*
name|_cksum
parameter_list|,
name|void
modifier|*
name|_new
parameter_list|,
name|void
modifier|*
name|_old
parameter_list|,
name|int
name|_n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Internal data access */
end_comment

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpIn
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_short
name|_id_alias
parameter_list|,
name|int
name|_create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpOut
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_short
name|_id
parameter_list|,
name|int
name|_create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn1
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_short
name|_ip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn2
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_short
name|_ip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|AddFragmentPtrLink
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_short
name|_ip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentPtr
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_short
name|_ip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindProtoIn
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_char
name|_proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindProtoOut
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_char
name|_proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindUdpTcpIn
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_short
name|_dst_port
parameter_list|,
name|u_short
name|_alias_port
parameter_list|,
name|u_char
name|_proto
parameter_list|,
name|int
name|_create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindUdpTcpOut
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_short
name|_src_port
parameter_list|,
name|u_short
name|_dst_port
parameter_list|,
name|u_char
name|_proto
parameter_list|,
name|int
name|_create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|AddPptp
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_int16_t
name|_src_call_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpOutByCallId
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_int16_t
name|_src_call_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpInByCallId
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_int16_t
name|_dst_call_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpOutByPeerCallId
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_int16_t
name|_dst_call_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpInByPeerCallId
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_int16_t
name|_alias_call_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindRtspOut
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|u_short
name|_src_port
parameter_list|,
name|u_short
name|_alias_port
parameter_list|,
name|u_char
name|_proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|FindOriginalAddress
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|FindAliasAddress
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_original_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* External data access/modification */
end_comment

begin_function_decl
name|int
name|FindNewPortGroup
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_dst_addr
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|,
name|u_short
name|_src_port
parameter_list|,
name|u_short
name|_dst_port
parameter_list|,
name|u_short
name|_port_count
parameter_list|,
name|u_char
name|_proto
parameter_list|,
name|u_char
name|_align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|struct
name|in_addr
modifier|*
name|_src_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|struct
name|in_addr
name|_src_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|char
modifier|*
modifier|*
name|_fptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|char
modifier|*
name|fptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|int
name|_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|int
name|_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetOriginalAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDestAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetAliasAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDefaultAliasAddress
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDefaultAliasAddress
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|in_addr
name|_alias_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetOriginalPort
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetAliasPort
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetProxyAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetProxyAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|struct
name|in_addr
name|_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetProxyPort
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetProxyPort
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|u_short
name|_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaAckIn
parameter_list|(
name|struct
name|ip
modifier|*
name|_pip
parameter_list|,
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaSeqOut
parameter_list|(
name|struct
name|ip
modifier|*
name|_pip
parameter_list|,
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddSeq
parameter_list|(
name|struct
name|ip
modifier|*
name|_pip
parameter_list|,
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|int
name|_delta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetExpire
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|int
name|_expire
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ClearCheckNewLink
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetProtocolFlags
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|int
name|_pflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetProtocolFlags
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDestCallId
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|u_int16_t
name|_cid
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FW_PUNCH
end_ifndef

begin_function_decl
name|void
name|PunchFWHole
parameter_list|(
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Housekeeping function */
end_comment

begin_function_decl
name|void
name|HouseKeeping
parameter_list|(
name|struct
name|libalias
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tcp specfic routines */
end_comment

begin_comment
comment|/* lint -save -library Suppress flexelint warnings */
end_comment

begin_comment
comment|/* Transparent proxy routines */
end_comment

begin_function_decl
name|int
name|ProxyCheck
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|ip
modifier|*
name|_pip
parameter_list|,
name|struct
name|in_addr
modifier|*
name|_proxy_server_addr
parameter_list|,
name|u_short
modifier|*
name|_proxy_server_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ProxyModify
parameter_list|(
name|struct
name|libalias
modifier|*
name|la
parameter_list|,
name|struct
name|alias_link
modifier|*
name|_lnk
parameter_list|,
name|struct
name|ip
modifier|*
name|_pip
parameter_list|,
name|int
name|_maxpacketsize
parameter_list|,
name|int
name|_proxy_type
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|alias_tcp_state
block|{
name|ALIAS_TCP_STATE_NOT_CONNECTED
block|,
name|ALIAS_TCP_STATE_CONNECTED
block|,
name|ALIAS_TCP_STATE_DISCONNECTED
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETINET_IP_H_
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ip_next
parameter_list|(
name|struct
name|ip
modifier|*
name|iphdr
parameter_list|)
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|iphdr
decl_stmt|;
return|return
operator|(
operator|&
name|p
index|[
name|iphdr
operator|->
name|ip_hl
operator|*
literal|4
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETINET_TCP_H_
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|tcp_next
parameter_list|(
name|struct
name|tcphdr
modifier|*
name|tcphdr
parameter_list|)
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|tcphdr
decl_stmt|;
return|return
operator|(
operator|&
name|p
index|[
name|tcphdr
operator|->
name|th_off
operator|*
literal|4
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETINET_UDP_H_
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|udp_next
parameter_list|(
name|struct
name|udphdr
modifier|*
name|udphdr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
name|udphdr
operator|+
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALIAS_LOCAL_H_ */
end_comment

end_unit

