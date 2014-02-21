begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   This software is available to you under a choice of one of two   licenses.  You may choose to be licensed under the terms of the GNU   General Public License (GPL) Version 2, available at<http://www.fsf.org/copyleft/gpl.html>, or the OpenIB.org BSD   license, available in the LICENSE.TXT file accompanying this   software.  These details are also available at<http://openib.org/license.html>.    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   SOFTWARE.    Copyright (c) 2004 Topspin Communications.  All rights reserved.   Copyright (c) 2005-2006 Mellanox Technologies Ltd.  All rights reserved.    $Id$ */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/*  * SDP specific includes  */
end_comment

begin_include
include|#
directive|include
file|"linux/sdp_inet.h"
end_include

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* library static and global variables                                   */
end_comment

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* max string length to store any IPv4/IPv6 address */
end_comment

begin_define
define|#
directive|define
name|MAX_ADDR_STR_LEN
value|49
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|USE_TCP
init|=
literal|1
block|,
name|USE_SDP
block|,
name|USE_BOTH
block|, }
name|use_family_t
typedef|;
end_typedef

begin_comment
comment|/* some state to string functions */
end_comment

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|__sdp_get_family_str
parameter_list|(
name|use_family_t
name|family
parameter_list|)
block|{
switch|switch
condition|(
name|family
condition|)
block|{
case|case
name|USE_TCP
case|:
return|return
literal|"tcp"
return|;
break|break;
case|case
name|USE_SDP
case|:
return|return
literal|"sdp"
return|;
break|break;
case|case
name|USE_BOTH
case|:
return|return
literal|"both"
return|;
break|break;
block|}
return|return
operator|(
literal|"unknown-family"
operator|)
return|;
block|}
end_function

begin_comment
comment|/* data structure for holding address family mapoping rules */
end_comment

begin_comment
comment|/* note we filter non relevant programs during parsing ...  */
end_comment

begin_struct
struct|struct
name|use_family_rule
block|{
name|struct
name|use_family_rule
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|int
name|match_by_addr
decl_stmt|;
comment|/* if 0 ignore address match        */
name|struct
name|in_addr
name|ipv4
decl_stmt|;
comment|/* IPv4 address for mapping         */
name|unsigned
name|char
name|prefixlen
decl_stmt|;
comment|/* length of CIDR prefix (ie /24)   */
name|int
name|match_by_port
decl_stmt|;
comment|/* if 0 ignore port match           */
name|unsigned
name|short
name|sport
decl_stmt|,
name|eport
decl_stmt|;
comment|/* start port - end port, inclusive */
name|use_family_t
name|target_family
decl_stmt|;
comment|/* if match - use this family       */
name|char
modifier|*
name|prog_name_expr
decl_stmt|;
comment|/* expression for program name      */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|use_family_rule
modifier|*
name|__sdp_clients_family_rules_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|use_family_rule
modifier|*
name|__sdp_clients_family_rules_tail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|use_family_rule
modifier|*
name|__sdp_servers_family_rules_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|use_family_rule
modifier|*
name|__sdp_servers_family_rules_tail
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SDP_NETMASK
parameter_list|(
name|n
parameter_list|)
value|((n == 0) ? 0 : ~((1UL<<(32 - n)) - 1))
end_define

begin_comment
comment|/* match.c */
end_comment

begin_function_decl
name|use_family_t
name|__sdp_match_connect
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sin
parameter_list|,
specifier|const
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|use_family_t
name|__sdp_match_listen
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sin
parameter_list|,
specifier|const
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* config.c */
end_comment

begin_function_decl
name|int
name|__sdp_config_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sdp_parse_config
parameter_list|(
specifier|const
name|char
modifier|*
name|config_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|use_family_t
name|__sdp_match_by_program
parameter_list|( 	 )
function_decl|;
end_function_decl

begin_comment
comment|/* log.c */
end_comment

begin_function_decl
name|void
name|__sdp_log
parameter_list|(
name|int
name|level
parameter_list|,
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sdp_log_get_level
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__sdp_log_set_min_level
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sdp_log_set_log_stderr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sdp_log_set_log_syslog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__sdp_log_set_log_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* port.c */
end_comment

begin_function_decl
name|int
name|__sdp_sockaddr_to_sdp
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|addr_in
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|addr_out
parameter_list|,
name|int
modifier|*
name|was_ipv6
parameter_list|)
function_decl|;
end_function_decl

end_unit

