begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_define
define|#
directive|define
name|EON_986_VERSION
value|0x3
end_define

begin_define
define|#
directive|define
name|EON_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|EON_CACHESIZE
value|30
end_define

begin_define
define|#
directive|define
name|E_FREE
value|1
end_define

begin_define
define|#
directive|define
name|E_LINK
value|2
end_define

begin_define
define|#
directive|define
name|E_ES
value|3
end_define

begin_define
define|#
directive|define
name|E_IS
value|4
end_define

begin_comment
comment|/*   * this overlays a sockaddr_iso  */
end_comment

begin_struct
struct|struct
name|sockaddr_eon
block|{
name|short
name|seon_family
decl_stmt|;
comment|/* AF_ISO */
name|u_short
name|seon_status
decl_stmt|;
comment|/* overlays transport suffix */
define|#
directive|define
name|EON_ESLINK_UP
value|0x1
define|#
directive|define
name|EON_ESLINK_DOWN
value|0x2
define|#
directive|define
name|EON_ISLINK_UP
value|0x10
define|#
directive|define
name|EON_ISLINK_DOWN
value|0x20
comment|/* no change is neither up or down */
name|u_char
name|seon_afi
decl_stmt|;
comment|/* 47 */
name|u_char
name|seon_idi
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0006 */
name|u_char
name|seon_vers
decl_stmt|;
comment|/* 03 */
comment|/* right now ip addr is  aligned  -- be careful -- 		 * future revisions may have it u_char[4] 		 */
name|u_int
name|seon_ipaddr
decl_stmt|;
comment|/* a.b.c.d */
name|u_char
name|seon_protoid
index|[
literal|1
index|]
decl_stmt|;
comment|/* */
name|u_char
name|seon_adrlen
decl_stmt|;
name|u_short
name|seon_netype
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|sockaddr_eon
name|eon_template
init|=
block|{
name|AF_ISO
block|,
literal|0
block|,
literal|0x47
block|,
literal|0x0
block|,
literal|0x6
block|,
literal|0x3
block|,
literal|0
block|,
literal|0
block|,
literal|0xa
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DOWNBITS
value|( EON_ESLINK_DOWN | EON_ISLINK_DOWN )
end_define

begin_define
define|#
directive|define
name|UPBITS
value|( EON_ESLINK_UP | EON_ISLINK_UP )
end_define

begin_struct
struct|struct
name|eon_hdr
block|{
name|u_char
name|eonh_vers
decl_stmt|;
comment|/* value 1 */
name|u_char
name|eonh_class
decl_stmt|;
comment|/* address multicast class, below */
define|#
directive|define
name|EON_NORMAL_ADDR
value|0x0
define|#
directive|define
name|EON_MULTICAST_ES
value|0x1
define|#
directive|define
name|EON_MULTICAST_IS
value|0x2
define|#
directive|define
name|EON_BROADCAST
value|0x3
name|u_short
name|eonh_csum
decl_stmt|;
comment|/* osi checksum (choke)*/
block|}
struct|;
end_struct

begin_comment
comment|/* stole these 2 fields of the flags for I-am-ES and I-am-IS */
end_comment

begin_define
define|#
directive|define
name|IFF_ES
value|0x400
end_define

begin_define
define|#
directive|define
name|IFF_IS
value|0x800
end_define

begin_struct
struct|struct
name|eon_stat
block|{
name|int
name|es_in_multi_es
decl_stmt|;
name|int
name|es_in_multi_is
decl_stmt|;
name|int
name|es_in_broad
decl_stmt|;
name|int
name|es_in_normal
decl_stmt|;
name|int
name|es_out_multi_es
decl_stmt|;
name|int
name|es_out_multi_is
decl_stmt|;
name|int
name|es_out_broad
decl_stmt|;
name|int
name|es_out_normal
decl_stmt|;
name|int
name|es_ipout
decl_stmt|;
name|int
name|es_icmp
index|[
name|PRC_NCMDS
index|]
decl_stmt|;
comment|/* errors */
name|int
name|es_badcsum
decl_stmt|;
name|int
name|es_badhdr
decl_stmt|;
block|}
name|eonstat
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|IncStat
end_undef

begin_define
define|#
directive|define
name|IncStat
parameter_list|(
name|xxx
parameter_list|)
value|eonstat.xxx++
end_define

end_unit

