begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/net_help.h - network help functions   *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to perform network related tasks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NET_HELP_H
end_ifndef

begin_define
define|#
directive|define
name|NET_HELP_H
end_define

begin_include
include|#
directive|include
file|"util/log.h"
end_include

begin_struct_decl
struct_decl|struct
name|sock_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_comment
comment|/** DNS constants for uint16_t style flag manipulation. host byteorder.   *                                1  1  1  1  1  1  *  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+  * |QR|   Opcode  |AA|TC|RD|RA| Z|AD|CD|   RCODE   |  * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+  */
end_comment

begin_comment
comment|/** CD flag */
end_comment

begin_define
define|#
directive|define
name|BIT_CD
value|0x0010
end_define

begin_comment
comment|/** AD flag */
end_comment

begin_define
define|#
directive|define
name|BIT_AD
value|0x0020
end_define

begin_comment
comment|/** Z flag */
end_comment

begin_define
define|#
directive|define
name|BIT_Z
value|0x0040
end_define

begin_comment
comment|/** RA flag */
end_comment

begin_define
define|#
directive|define
name|BIT_RA
value|0x0080
end_define

begin_comment
comment|/** RD flag */
end_comment

begin_define
define|#
directive|define
name|BIT_RD
value|0x0100
end_define

begin_comment
comment|/** TC flag */
end_comment

begin_define
define|#
directive|define
name|BIT_TC
value|0x0200
end_define

begin_comment
comment|/** AA flag */
end_comment

begin_define
define|#
directive|define
name|BIT_AA
value|0x0400
end_define

begin_comment
comment|/** QR flag */
end_comment

begin_define
define|#
directive|define
name|BIT_QR
value|0x8000
end_define

begin_comment
comment|/** get RCODE bits from uint16 flags */
end_comment

begin_define
define|#
directive|define
name|FLAGS_GET_RCODE
parameter_list|(
name|f
parameter_list|)
value|((f)& 0xf)
end_define

begin_comment
comment|/** set RCODE bits in uint16 flags */
end_comment

begin_define
define|#
directive|define
name|FLAGS_SET_RCODE
parameter_list|(
name|f
parameter_list|,
name|r
parameter_list|)
value|(f = (((f)& 0xfff0) | (r)))
end_define

begin_comment
comment|/** timeout in seconds for UDP queries to auth servers. */
end_comment

begin_define
define|#
directive|define
name|UDP_AUTH_QUERY_TIMEOUT
value|4
end_define

begin_comment
comment|/** timeout in seconds for TCP queries to auth servers. */
end_comment

begin_define
define|#
directive|define
name|TCP_AUTH_QUERY_TIMEOUT
value|30
end_define

begin_comment
comment|/** Advertised version of EDNS capabilities */
end_comment

begin_define
define|#
directive|define
name|EDNS_ADVERTISED_VERSION
value|0
end_define

begin_comment
comment|/** Advertised size of EDNS capabilities */
end_comment

begin_decl_stmt
specifier|extern
name|uint16_t
name|EDNS_ADVERTISED_SIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** bits for EDNS bitfield */
end_comment

begin_define
define|#
directive|define
name|EDNS_DO
value|0x8000
end_define

begin_comment
comment|/* Dnssec Ok */
end_comment

begin_comment
comment|/** byte size of ip4 address */
end_comment

begin_define
define|#
directive|define
name|INET_SIZE
value|4
end_define

begin_comment
comment|/** byte size of ip6 address */
end_comment

begin_define
define|#
directive|define
name|INET6_SIZE
value|16
end_define

begin_comment
comment|/** DNSKEY zone sign key flag */
end_comment

begin_define
define|#
directive|define
name|DNSKEY_BIT_ZSK
value|0x0100
end_define

begin_comment
comment|/** DNSKEY secure entry point, KSK flag */
end_comment

begin_define
define|#
directive|define
name|DNSKEY_BIT_SEP
value|0x0001
end_define

begin_comment
comment|/** minimal responses when positive answer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|MINIMAL_RESPONSES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** rrset order roundrobin */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|RRSET_ROUNDROBIN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * See if string is ip4 or ip6.  * @param str: IP specification.  * @return: true if string addr is an ip6 specced address.  */
end_comment

begin_function_decl
name|int
name|str_is_ip6
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set fd nonblocking.  * @param s: file descriptor.  * @return: 0 on error (error is printed to log).  */
end_comment

begin_function_decl
name|int
name|fd_set_nonblock
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set fd (back to) blocking.  * @param s: file descriptor.  * @return: 0 on error (error is printed to log).  */
end_comment

begin_function_decl
name|int
name|fd_set_block
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if number is a power of 2.  * @param num: the value.  * @return: true if the number is a power of 2.  */
end_comment

begin_function_decl
name|int
name|is_pow2
parameter_list|(
name|size_t
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate memory and copy over contents.  * @param data: what to copy over.  * @param len: length of data.  * @return: NULL on malloc failure, or newly malloced data.  */
end_comment

begin_function_decl
name|void
modifier|*
name|memdup
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prints the sockaddr in readable format with log_info. Debug helper.  * @param v: at what verbosity level to print this.  * @param str: descriptive string printed with it.  * @param addr: the sockaddr to print. Can be ip4 or ip6.  * @param addrlen: length of addr.  */
end_comment

begin_function_decl
name|void
name|log_addr
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Prints zone name and sockaddr in readable format with log_info. Debug.  * @param v: at what verbosity level to print this.  * @param str: descriptive string printed with it.  * @param zone: DNS domain name, uncompressed wireformat.  * @param addr: the sockaddr to print. Can be ip4 or ip6.  * @param addrlen: length of addr.  */
end_comment

begin_function_decl
name|void
name|log_name_addr
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert address string, with "@port" appendix, to sockaddr.  * Uses DNS port by default.  * @param str: the string  * @param addr: where to store sockaddr.  * @param addrlen: length of stored sockaddr is returned.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|extstrtoaddr
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert ip address string and port to sockaddr.  * @param ip: ip4 or ip6 address string.  * @param port: port number, host format.  * @param addr: where to store sockaddr.  * @param addrlen: length of stored sockaddr is returned.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|ipstrtoaddr
parameter_list|(
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert ip netblock (ip/netsize) string and port to sockaddr.  * *SLOW*, does a malloc internally to avoid writing over 'ip' string.  * @param ip: ip4 or ip6 address string.  * @param port: port number, host format.  * @param addr: where to store sockaddr.  * @param addrlen: length of stored sockaddr is returned.  * @param net: netblock size is returned.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|netblockstrtoaddr
parameter_list|(
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
modifier|*
name|addrlen
parameter_list|,
name|int
modifier|*
name|net
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print string with neat domain name, type and class.  * @param v: at what verbosity level to print this.  * @param str: string of message.  * @param name: domain name uncompressed wireformat.  * @param type: host format RR type.  * @param dclass: host format RR class.  */
end_comment

begin_function_decl
name|void
name|log_nametypeclass
parameter_list|(
name|enum
name|verbosity_value
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two sockaddrs. Imposes an ordering on the addresses.  * Compares address and port.  * @param addr1: address 1.  * @param len1: lengths of addr1.  * @param addr2: address 2.  * @param len2: lengths of addr2.  * @return: 0 if addr1 == addr2. -1 if addr1 is smaller, +1 if larger.  */
end_comment

begin_function_decl
name|int
name|sockaddr_cmp
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr1
parameter_list|,
name|socklen_t
name|len1
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr2
parameter_list|,
name|socklen_t
name|len2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two sockaddrs. Compares address, not the port.  * @param addr1: address 1.  * @param len1: lengths of addr1.  * @param addr2: address 2.  * @param len2: lengths of addr2.  * @return: 0 if addr1 == addr2. -1 if addr1 is smaller, +1 if larger.  */
end_comment

begin_function_decl
name|int
name|sockaddr_cmp_addr
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr1
parameter_list|,
name|socklen_t
name|len1
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr2
parameter_list|,
name|socklen_t
name|len2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Checkout address family.  * @param addr: the sockaddr to examine.  * @param len: the length of addr.  * @return: true if sockaddr is ip6.  */
end_comment

begin_function_decl
name|int
name|addr_is_ip6
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Make sure the sockaddr ends in zeroes. For tree insertion and subsequent  * comparison.  * @param addr: the ip4 or ip6 addr.  * @param len: length of addr.  * @param net: number of bits to leave untouched, the rest of the netblock  * 	address is zeroed.  */
end_comment

begin_function_decl
name|void
name|addr_mask
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|len
parameter_list|,
name|int
name|net
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See how many bits are shared, equal, between two addrs.  * @param addr1: first addr.  * @param net1: netblock size of first addr.  * @param addr2: second addr.  * @param net2: netblock size of second addr.  * @param addrlen: length of first addr and of second addr.  * 	They must be of the same length (i.e. same type IP4, IP6).  * @return: number of bits the same.  */
end_comment

begin_function_decl
name|int
name|addr_in_common
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr1
parameter_list|,
name|int
name|net1
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr2
parameter_list|,
name|int
name|net2
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Put address into string, works for IPv4 and IPv6.  * @param addr: address  * @param addrlen: length of address  * @param buf: result string stored here  * @param len: length of buf.  * On failure a string with "error" is stored inside.  */
end_comment

begin_function_decl
name|void
name|addr_to_str
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if sockaddr is an ipv6 mapped ipv4 address, "::ffff:0.0.0.0"  * @param addr: address  * @param addrlen: length of address  * @return true if so  */
end_comment

begin_function_decl
name|int
name|addr_is_ip4mapped
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if sockaddr is 255.255.255.255.  * @param addr: address  * @param addrlen: length of address  * @return true if so  */
end_comment

begin_function_decl
name|int
name|addr_is_broadcast
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if sockaddr is 0.0.0.0 or ::0.  * @param addr: address  * @param addrlen: length of address  * @return true if so  */
end_comment

begin_function_decl
name|int
name|addr_is_any
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert new socket list item. If fails logs error.  * @param list: pointer to pointer to first item.  * @param addr: address or NULL if 'cache'.  * @param len: length of addr, or 0 if 'cache'.  * @param region: where to allocate  */
end_comment

begin_function_decl
name|void
name|sock_list_insert
parameter_list|(
name|struct
name|sock_list
modifier|*
modifier|*
name|list
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|len
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append one list to another.  Must both be from same qstate(regional).  * @param list: pointer to result list that is modified.  * @param add: item(s) to add.  They are prepended to list.  */
end_comment

begin_function_decl
name|void
name|sock_list_prepend
parameter_list|(
name|struct
name|sock_list
modifier|*
modifier|*
name|list
parameter_list|,
name|struct
name|sock_list
modifier|*
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find addr in list.  * @param list: to search in  * @param addr: address to look for.  * @param len: length. Can be 0, look for 'cache entry'.  * @return true if found.  */
end_comment

begin_function_decl
name|int
name|sock_list_find
parameter_list|(
name|struct
name|sock_list
modifier|*
name|list
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|addr
parameter_list|,
name|socklen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Merge socklist into another socket list.  Allocates the new entries  * freshly and copies them over, so also performs a region switchover.  * Allocation failures are logged.  * @param list: the destination list (checked for duplicates)  * @param region: where to allocate  * @param add: the list of entries to add.  */
end_comment

begin_function_decl
name|void
name|sock_list_merge
parameter_list|(
name|struct
name|sock_list
modifier|*
modifier|*
name|list
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|sock_list
modifier|*
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Log libcrypto error with descriptive string. Calls log_err().  * @param str: what failed.  */
end_comment

begin_function_decl
name|void
name|log_crypto_err
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * create SSL listen context  * @param key: private key file.  * @param pem: public key cert.  * @param verifypem: if nonNULL, verifylocation file.  * return SSL_CTX* or NULL on failure (logged).  */
end_comment

begin_function_decl
name|void
modifier|*
name|listen_sslctx_create
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|pem
parameter_list|,
name|char
modifier|*
name|verifypem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * create SSL connect context  * @param key: if nonNULL (also pem nonNULL), the client private key.  * @param pem: client public key (or NULL if key is NULL).  * @param verifypem: if nonNULL used for verifylocation file.  * @return SSL_CTX* or NULL on failure (logged).  */
end_comment

begin_function_decl
name|void
modifier|*
name|connect_sslctx_create
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|pem
parameter_list|,
name|char
modifier|*
name|verifypem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * accept a new fd and wrap it in a BIO in SSL  * @param sslctx: the SSL_CTX to use (from listen_sslctx_create()).  * @param fd: from accept, nonblocking.  * @return SSL or NULL on alloc failure.  */
end_comment

begin_function_decl
name|void
modifier|*
name|incoming_ssl_fd
parameter_list|(
name|void
modifier|*
name|sslctx
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * connect a new fd and wrap it in a BIO in SSL  * @param sslctx: the SSL_CTX to use (from connect_sslctx_create())  * @param fd: from connect.  * @return SSL or NULL on alloc failure  */
end_comment

begin_function_decl
name|void
modifier|*
name|outgoing_ssl_fd
parameter_list|(
name|void
modifier|*
name|sslctx
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize openssl locking for thread safety  * @return false on failure (alloc failure).  */
end_comment

begin_function_decl
name|int
name|ub_openssl_lock_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * De-init the allocated openssl locks  */
end_comment

begin_function_decl
name|void
name|ub_openssl_lock_delete
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NET_HELP_H */
end_comment

end_unit

