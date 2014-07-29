begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * resolver.h  *  * DNS Resolver definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Defines the  ldns_resolver structure, a stub resolver that can send queries and parse answers.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RESOLVER_H
end_define

begin_include
include|#
directive|include
file|<ldns/error.h>
end_include

begin_include
include|#
directive|include
file|<ldns/common.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rr.h>
end_include

begin_include
include|#
directive|include
file|<ldns/tsig.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<ldns/packet.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/** Default location of the resolv.conf file */
define|#
directive|define
name|LDNS_RESOLV_CONF
value|"/etc/resolv.conf"
comment|/** Default location of the hosts file */
define|#
directive|define
name|LDNS_RESOLV_HOSTS
value|"/etc/hosts"
define|#
directive|define
name|LDNS_RESOLV_KEYWORD
value|-1
define|#
directive|define
name|LDNS_RESOLV_DEFDOMAIN
value|0
define|#
directive|define
name|LDNS_RESOLV_NAMESERVER
value|1
define|#
directive|define
name|LDNS_RESOLV_SEARCH
value|2
define|#
directive|define
name|LDNS_RESOLV_SORTLIST
value|3
define|#
directive|define
name|LDNS_RESOLV_OPTIONS
value|4
define|#
directive|define
name|LDNS_RESOLV_ANCHOR
value|5
define|#
directive|define
name|LDNS_RESOLV_KEYWORDS
value|6
define|#
directive|define
name|LDNS_RESOLV_INETANY
value|0
define|#
directive|define
name|LDNS_RESOLV_INET
value|1
define|#
directive|define
name|LDNS_RESOLV_INET6
value|2
define|#
directive|define
name|LDNS_RESOLV_RTT_INF
value|0
comment|/* infinity */
define|#
directive|define
name|LDNS_RESOLV_RTT_MIN
value|1
comment|/* reachable */
comment|/**  * DNS stub resolver structure  */
struct|struct
name|ldns_struct_resolver
block|{
comment|/**  Port to send queries to */
name|uint16_t
name|_port
decl_stmt|;
comment|/** Array of nameservers to query (IP addresses or dnames) */
name|ldns_rdf
modifier|*
modifier|*
name|_nameservers
decl_stmt|;
comment|/** Number of nameservers in \c _nameservers */
name|size_t
name|_nameserver_count
decl_stmt|;
comment|/* how many do we have */
comment|/**  Round trip time; 0 -> infinity. Unit: ms? */
name|size_t
modifier|*
name|_rtt
decl_stmt|;
comment|/**  Wether or not to be recursive */
name|bool
name|_recursive
decl_stmt|;
comment|/**  Print debug information */
name|bool
name|_debug
decl_stmt|;
comment|/**  Default domain to add to non fully qualified domain names */
name|ldns_rdf
modifier|*
name|_domain
decl_stmt|;
comment|/**  Searchlist array, add the names in this array if a query cannot be found */
name|ldns_rdf
modifier|*
modifier|*
name|_searchlist
decl_stmt|;
comment|/** Number of entries in the searchlist array */
name|size_t
name|_searchlist_count
decl_stmt|;
comment|/**  Number of times to retry before giving up */
name|uint8_t
name|_retry
decl_stmt|;
comment|/**  Time to wait before retrying */
name|uint8_t
name|_retrans
decl_stmt|;
comment|/**  Use new fallback mechanism (try EDNS, then do TCP) */
name|bool
name|_fallback
decl_stmt|;
comment|/**  Whether to do DNSSEC */
name|bool
name|_dnssec
decl_stmt|;
comment|/**  Whether to set the CD bit on DNSSEC requests */
name|bool
name|_dnssec_cd
decl_stmt|;
comment|/** Optional trust anchors for complete DNSSEC validation */
name|ldns_rr_list
modifier|*
name|_dnssec_anchors
decl_stmt|;
comment|/**  Whether to use tcp or udp (tcp if the value is true)*/
name|bool
name|_usevc
decl_stmt|;
comment|/**  Whether to ignore the tc bit */
name|bool
name|_igntc
decl_stmt|;
comment|/**  Whether to use ip6, 0->does not matter, 1 is IPv4, 2 is IPv6 */
name|uint8_t
name|_ip6
decl_stmt|;
comment|/**  If true append the default domain */
name|bool
name|_defnames
decl_stmt|;
comment|/**  If true apply the search list */
name|bool
name|_dnsrch
decl_stmt|;
comment|/**  Timeout for socket connections */
name|struct
name|timeval
name|_timeout
decl_stmt|;
comment|/**  Only try the first nameserver, and return with an error directly if it fails */
name|bool
name|_fail
decl_stmt|;
comment|/**  Randomly choose a nameserver */
name|bool
name|_random
decl_stmt|;
comment|/** Keep some things to make AXFR possible */
name|int
name|_socket
decl_stmt|;
comment|/** Count the number of LDNS_RR_TYPE_SOA RRs we have seen so far 	 * (the second one signifies the end of the AXFR) 	 */
name|int
name|_axfr_soa_count
decl_stmt|;
comment|/* when axfring we get complete packets from the server 	   but we want to give the caller 1 rr at a time, so 	   keep the current pkt */
comment|/** Packet currently handled when doing part of an AXFR */
name|ldns_pkt
modifier|*
name|_cur_axfr_pkt
decl_stmt|;
comment|/** Counter for within the AXFR packets */
name|uint16_t
name|_axfr_i
decl_stmt|;
comment|/* EDNS0 available buffer size */
name|uint16_t
name|_edns_udp_size
decl_stmt|;
comment|/* Optional tsig key for signing queries, 	outgoing messages are signed if and only if both are set 	*/
comment|/** Name of the key to use with TSIG, if _tsig_keyname and _tsig_keydata both contain values, outgoing messages are automatically signed with TSIG. */
name|char
modifier|*
name|_tsig_keyname
decl_stmt|;
comment|/** Secret key data to use with TSIG, if _tsig_keyname and _tsig_keydata both contain values, outgoing messages are automatically signed with TSIG. */
name|char
modifier|*
name|_tsig_keydata
decl_stmt|;
comment|/** TSIG signing algorithm */
name|char
modifier|*
name|_tsig_algorithm
decl_stmt|;
comment|/** Source address to query from */
name|ldns_rdf
modifier|*
name|_source
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_resolver
name|ldns_resolver
typedef|;
comment|/* prototypes */
comment|/* read access functions */
comment|/**  * Get the port the resolver should use  * \param[in] r the resolver  * \return the port number  */
name|uint16_t
name|ldns_resolver_port
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the source address the resolver should use  * \param[in] r the resolver  * \return the source rdf  */
name|ldns_rdf
modifier|*
name|ldns_resolver_source
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Is the resolver set to recurse  * \param[in] r the resolver  * \return true if so, otherwise false  */
name|bool
name|ldns_resolver_recursive
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the debug status of the resolver  * \param[in] r the resolver  * \return true if so, otherwise false  */
name|bool
name|ldns_resolver_debug
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the number of retries  * \param[in] r the resolver  * \return the number of retries  */
name|uint8_t
name|ldns_resolver_retry
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the retransmit interval  * \param[in] r the resolver  * \return the retransmit interval  */
name|uint8_t
name|ldns_resolver_retrans
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the truncation fallback status  * \param[in] r the resolver  * \return whether the truncation fallback mechanism is used  */
name|bool
name|ldns_resolver_fallback
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver use ip6 or ip4  * \param[in] r the resolver  * \return 0: both, 1: ip4, 2:ip6  */
name|uint8_t
name|ldns_resolver_ip6
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the resolver's udp size  * \param[in] r the resolver  * \return the udp mesg size  */
name|uint16_t
name|ldns_resolver_edns_udp_size
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver use tcp or udp  * \param[in] r the resolver  * \return true: tcp, false: udp  */
name|bool
name|ldns_resolver_usevc
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver only try the first nameserver  * \param[in] r the resolver  * \return true: yes, fail, false: no, try the others  */
name|bool
name|ldns_resolver_fail
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver apply default domain name  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_defnames
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver apply search list  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_dnsrch
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver do DNSSEC  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_dnssec
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver set the CD bit  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_dnssec_cd
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Get the resolver's DNSSEC anchors  * \param[in] r the resolver  * \return an rr_list containg trusted DNSSEC anchors  */
name|ldns_rr_list
modifier|*
name|ldns_resolver_dnssec_anchors
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver ignore the TC bit (truncated)  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_igntc
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Does the resolver randomize the nameserver before usage  * \param[in] r the resolver  * \return true: yes, false: no  */
name|bool
name|ldns_resolver_random
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * How many nameserver are configured in the resolver  * \param[in] r the resolver  * \return number of nameservers  */
name|size_t
name|ldns_resolver_nameserver_count
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * What is the default dname to add to relative queries  * \param[in] r the resolver  * \return the dname which is added  */
name|ldns_rdf
modifier|*
name|ldns_resolver_domain
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * What is the timeout on socket connections  * \param[in] r the resolver  * \return the timeout as struct timeval  */
name|struct
name|timeval
name|ldns_resolver_timeout
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * What is the searchlist as used by the resolver  * \param[in] r the resolver  * \return a ldns_rdf pointer to a list of the addresses  */
name|ldns_rdf
modifier|*
modifier|*
name|ldns_resolver_searchlist
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the configured nameserver ip address  * \param[in] r the resolver  * \return a ldns_rdf pointer to a list of the addresses  */
name|ldns_rdf
modifier|*
modifier|*
name|ldns_resolver_nameservers
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the used round trip times for the nameservers  * \param[in] r the resolver  * \return a size_t* pointer to the list.  * yet)  */
name|size_t
modifier|*
name|ldns_resolver_rtt
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the used round trip time for a specific nameserver  * \param[in] r the resolver  * \param[in] pos the index to the nameserver  * \return the rrt, 0: infinite,>0: undefined (as of * yet)  */
name|size_t
name|ldns_resolver_nameserver_rtt
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|size_t
name|pos
parameter_list|)
function_decl|;
comment|/**  * Return the tsig keyname as used by the nameserver  * \param[in] r the resolver  * \return the name used.  */
name|char
modifier|*
name|ldns_resolver_tsig_keyname
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the tsig algorithm as used by the nameserver  * \param[in] r the resolver  * \return the algorithm used.  */
name|char
modifier|*
name|ldns_resolver_tsig_algorithm
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the tsig keydata as used by the nameserver  * \param[in] r the resolver  * \return the keydata used.  */
name|char
modifier|*
name|ldns_resolver_tsig_keydata
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * pop the last nameserver from the resolver.  * \param[in] r the resolver  * \return the popped address or NULL if empty  */
name|ldns_rdf
modifier|*
name|ldns_resolver_pop_nameserver
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Return the resolver's searchlist count  * \param[in] r the resolver  * \return the searchlist count  */
name|size_t
name|ldns_resolver_searchlist_count
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/* write access function */
comment|/**  * Set the port the resolver should use  * \param[in] r the resolver  * \param[in] p the port number  */
name|void
name|ldns_resolver_set_port
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|uint16_t
name|p
parameter_list|)
function_decl|;
comment|/**  * Set the source rdf (address) the resolver should use  * \param[in] r the resolver  * \param[in] s the source address  */
name|void
name|ldns_resolver_set_source
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|s
parameter_list|)
function_decl|;
comment|/**  * Set the resolver recursion  * \param[in] r the resolver  * \param[in] b true: set to recurse, false: unset  */
name|void
name|ldns_resolver_set_recursive
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the resolver debugging  * \param[in] r the resolver  * \param[in] b true: debug on: false debug off  */
name|void
name|ldns_resolver_set_debug
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Incremental the resolver's nameserver count.  * \param[in] r the resolver  */
name|void
name|ldns_resolver_incr_nameserver_count
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Decrement the resolver's nameserver count.  * \param[in] r the resolver  */
name|void
name|ldns_resolver_dec_nameserver_count
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Set the resolver's nameserver count directly.  * \param[in] r the resolver  * \param[in] c the nameserver count  */
name|void
name|ldns_resolver_set_nameserver_count
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|size_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the resolver's nameserver count directly by using an rdf list  * \param[in] r the resolver  * \param[in] rd the resolver addresses  */
name|void
name|ldns_resolver_set_nameservers
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * Set the resolver's default domain. This gets appended when no  * absolute name is given  * \param[in] r the resolver  * \param[in] rd the name to append  */
name|void
name|ldns_resolver_set_domain
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * Set the resolver's socket time out when talking to remote hosts  * \param[in] r the resolver  * \param[in] timeout the timeout to use  */
name|void
name|ldns_resolver_set_timeout
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|struct
name|timeval
name|timeout
parameter_list|)
function_decl|;
comment|/**  * Push a new rd to the resolver's searchlist  * \param[in] r the resolver  * \param[in] rd to push  */
name|void
name|ldns_resolver_push_searchlist
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses the name set with _set_domain  * \param[in] r the resolver  * \param[in] b true: use the defaults, false: don't use them  */
name|void
name|ldns_resolver_set_defnames
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses a virtual circuit (TCP)  * \param[in] r the resolver  * \param[in] b true: use TCP, false: don't use TCP  */
name|void
name|ldns_resolver_set_usevc
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses the searchlist  * \param[in] r the resolver  * \param[in] b true: use the list, false: don't use the list  */
name|void
name|ldns_resolver_set_dnsrch
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses DNSSEC  * \param[in] r the resolver  * \param[in] b true: use DNSSEC, false: don't use DNSSEC  */
name|void
name|ldns_resolver_set_dnssec
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses the checking disable bit  * \param[in] r the resolver  * \param[in] b true: enable , false: don't use TCP  */
name|void
name|ldns_resolver_set_dnssec_cd
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the resolver's DNSSEC anchor list directly. RRs should be of type DS or DNSKEY.  * \param[in] r the resolver  * \param[in] l the list of RRs to use as trust anchors  */
name|void
name|ldns_resolver_set_dnssec_anchors
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr_list
modifier|*
name|l
parameter_list|)
function_decl|;
comment|/**  * Push a new trust anchor to the resolver. It must be a DS or DNSKEY rr  * \param[in] r the resolver.  * \param[in] rr the RR to add as a trust anchor.  * \return a status  */
name|ldns_status
name|ldns_resolver_push_dnssec_anchor
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * Set the resolver retrans timeout (in seconds)  * \param[in] r the resolver  * \param[in] re the retransmission interval in seconds  */
name|void
name|ldns_resolver_set_retrans
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|uint8_t
name|re
parameter_list|)
function_decl|;
comment|/**  * Set whether the resolvers truncation fallback mechanism is used  * when ldns_resolver_query() is called.  * \param[in] r the resolver  * \param[in] fallback whether to use the fallback mechanism  */
name|void
name|ldns_resolver_set_fallback
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|fallback
parameter_list|)
function_decl|;
comment|/**  * Set the number of times a resolver should retry a nameserver before the  * next one is tried.  * \param[in] r the resolver  * \param[in] re the number of retries  */
name|void
name|ldns_resolver_set_retry
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|uint8_t
name|re
parameter_list|)
function_decl|;
comment|/**  * Whether the resolver uses ip6  * \param[in] r the resolver  * \param[in] i 0: no pref, 1: ip4, 2: ip6  */
name|void
name|ldns_resolver_set_ip6
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|uint8_t
name|i
parameter_list|)
function_decl|;
comment|/**  * Whether or not to fail after one failed query  * \param[in] r the resolver  * \param[in] b true: yes fail, false: continue with next nameserver  */
name|void
name|ldns_resolver_set_fail
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Whether or not to ignore the TC bit  * \param[in] r the resolver  * \param[in] b true: yes ignore, false: don't ignore  */
name|void
name|ldns_resolver_set_igntc
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set maximum udp size  * \param[in] r the resolver  * \param[in] s the udp max size  */
name|void
name|ldns_resolver_set_edns_udp_size
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|uint16_t
name|s
parameter_list|)
function_decl|;
comment|/**  * Set the tsig key name  * \param[in] r the resolver  * \param[in] tsig_keyname the tsig key name  */
name|void
name|ldns_resolver_set_tsig_keyname
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|char
modifier|*
name|tsig_keyname
parameter_list|)
function_decl|;
comment|/**  * Set the tsig algorithm  * \param[in] r the resolver  * \param[in] tsig_algorithm the tsig algorithm  */
name|void
name|ldns_resolver_set_tsig_algorithm
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|char
modifier|*
name|tsig_algorithm
parameter_list|)
function_decl|;
comment|/**  * Set the tsig key data  * \param[in] r the resolver  * \param[in] tsig_keydata the key data  */
name|void
name|ldns_resolver_set_tsig_keydata
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|char
modifier|*
name|tsig_keydata
parameter_list|)
function_decl|;
comment|/**  * Set round trip time for all nameservers. Note this currently  * differentiates between: unreachable and reachable.  * \param[in] r the resolver  * \param[in] rtt a list with the times  */
name|void
name|ldns_resolver_set_rtt
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|size_t
modifier|*
name|rtt
parameter_list|)
function_decl|;
comment|/**  * Set round trip time for a specific nameserver. Note this  * currently differentiates between: unreachable and reachable.  * \param[in] r the resolver  * \param[in] pos the nameserver position  * \param[in] value the rtt  */
name|void
name|ldns_resolver_set_nameserver_rtt
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|size_t
name|pos
parameter_list|,
name|size_t
name|value
parameter_list|)
function_decl|;
comment|/**  * Should the nameserver list be randomized before each use  * \param[in] r the resolver  * \param[in] b: true: randomize, false: don't  */
name|void
name|ldns_resolver_set_random
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Push a new nameserver to the resolver. It must be an IP  * address v4 or v6.  * \param[in] r the resolver  * \param[in] n the ip address  * \return ldns_status a status  */
name|ldns_status
name|ldns_resolver_push_nameserver
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|n
parameter_list|)
function_decl|;
comment|/**  * Push a new nameserver to the resolver. It must be an  * A or AAAA RR record type  * \param[in] r the resolver  * \param[in] rr the resource record  * \return ldns_status a status  */
name|ldns_status
name|ldns_resolver_push_nameserver_rr
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * Push a new nameserver rr_list to the resolver.  * \param[in] r the resolver  * \param[in] rrlist the rr_list to push  * \return ldns_status a status  */
name|ldns_status
name|ldns_resolver_push_nameserver_rr_list
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr_list
modifier|*
name|rrlist
parameter_list|)
function_decl|;
comment|/**  * Send the query for using the resolver and take the search list into account  * The search algorithm is as follows:  * If the name is absolute, try it as-is, otherwise apply the search list  * \param[in] *r operate using this resolver  * \param[in] *rdf query for this name  * \param[in] t query for this type (may be 0, defaults to A)  * \param[in] c query for this class (may be 0, default to IN)  * \param[in] flags the query flags  *  * \return ldns_pkt* a packet with the reply from the nameserver  */
name|ldns_pkt
modifier|*
name|ldns_resolver_search
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Send the query for using the resolver and take the search list into account  * The search algorithm is as follows:  * If the name is absolute, try it as-is, otherwise apply the search list  * \param[out] pkt a packet with the reply from the nameserver  * \param[in] *r operate using this resolver  * \param[in] *rdf query for this name  * \param[in] t query for this type (may be 0, defaults to A)  * \param[in] c query for this class (may be 0, default to IN)  * \param[in] flags the query flags  *  * \return ldns_status LDNS_STATUS_OK on success  */
name|ldns_status
name|ldns_resolver_search_status
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|pkt
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Form a query packet from a resolver and name/type/class combo  * \param[out] **q a pointer to a ldns_pkt pointer (initialized by this function)  * \param[in] *r operate using this resolver  * \param[in] *name query for this name  * \param[in] t query for this type (may be 0, defaults to A)  * \param[in] c query for this class (may be 0, default to IN)  * \param[in] f the query flags  *  * \return ldns_pkt* a packet with the reply from the nameserver  */
name|ldns_status
name|ldns_resolver_prepare_query_pkt
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|q
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|f
parameter_list|)
function_decl|;
comment|/**  * Send the query for name as-is  * \param[out] **answer a pointer to a ldns_pkt pointer (initialized by this function)  * \param[in] *r operate using this resolver  * \param[in] *name query for this name  * \param[in] t query for this type (may be 0, defaults to A)  * \param[in] c query for this class (may be 0, default to IN)  * \param[in] flags the query flags  *  * \return ldns_pkt* a packet with the reply from the nameserver  */
name|ldns_status
name|ldns_resolver_send
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|answer
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Send the given packet to a nameserver  * \param[out] **answer a pointer to a ldns_pkt pointer (initialized by this function)  * \param[in] *r operate using this resolver  * \param[in] *query_pkt query  */
name|ldns_status
name|ldns_resolver_send_pkt
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|answer
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_pkt
modifier|*
name|query_pkt
parameter_list|)
function_decl|;
comment|/**  * Send a query to a nameserver  * \param[out] pkt a packet with the reply from the nameserver  * \param[in] *r operate using this resolver  * \param[in] *name query for this name  * \param[in] *t query for this type (may be 0, defaults to A)  * \param[in] *c query for this class (may be 0, default to IN)  * \param[in] flags the query flags  *  * \return ldns_status LDNS_STATUS_OK on success  * if _defnames is true the default domain will be added  */
name|ldns_status
name|ldns_resolver_query_status
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|pkt
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Send a query to a nameserver  * \param[in] *r operate using this resolver   *               (despite the const in the declaration,  *                the struct is altered as a side-effect)  * \param[in] *name query for this name  * \param[in] *t query for this type (may be 0, defaults to A)  * \param[in] *c query for this class (may be 0, default to IN)  * \param[in] flags the query flags  *  * \return ldns_pkt* a packet with the reply from the nameserver  * if _defnames is true the default domain will be added  */
name|ldns_pkt
modifier|*
name|ldns_resolver_query
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Create a new resolver structure  * \return ldns_resolver* pointer to new strcture  */
name|ldns_resolver
modifier|*
name|ldns_resolver_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Create a resolver structure from a file like /etc/resolv.conf  * \param[out] r the new resolver  * \param[in] fp file pointer to create new resolver from  *      if NULL use /etc/resolv.conf  * \return LDNS_STATUS_OK or the error  */
name|ldns_status
name|ldns_resolver_new_frm_fp
parameter_list|(
name|ldns_resolver
modifier|*
modifier|*
name|r
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
comment|/**  * Create a resolver structure from a file like /etc/resolv.conf  * \param[out] r the new resolver  * \param[in] fp file pointer to create new resolver from  *      if NULL use /etc/resolv.conf  * \param[in] line_nr pointer to an integer containing the current line number (for debugging purposes)  * \return LDNS_STATUS_OK or the error  */
name|ldns_status
name|ldns_resolver_new_frm_fp_l
parameter_list|(
name|ldns_resolver
modifier|*
modifier|*
name|r
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
modifier|*
name|line_nr
parameter_list|)
function_decl|;
comment|/**  * Configure a resolver by means of a resolv.conf file  * The file may be NULL in which case there will  be  * looked the RESOLV_CONF (defaults to /etc/resolv.conf  * \param[out] r the new resolver  * \param[in] filename the filename to use  * \return LDNS_STATUS_OK or the error  */
name|ldns_status
name|ldns_resolver_new_frm_file
parameter_list|(
name|ldns_resolver
modifier|*
modifier|*
name|r
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
comment|/**  * Frees the allocated space for this resolver. Only frees the resolver pionter! You should probably be using _deep_free.  * \param res resolver to free  */
name|void
name|ldns_resolver_free
parameter_list|(
name|ldns_resolver
modifier|*
name|res
parameter_list|)
function_decl|;
comment|/**  * Frees the allocated space for this resolver and all it's data  * \param res resolver to free  */
name|void
name|ldns_resolver_deep_free
parameter_list|(
name|ldns_resolver
modifier|*
name|res
parameter_list|)
function_decl|;
comment|/**  * Get the next stream of RRs in a AXFR  * \param[in] resolver the resolver to use. First ldns_axfr_start() must be  * called  * \return ldns_rr the next RR from the AXFR stream  * After you get this returned RR (not NULL: on error), then check if   * ldns_axfr_complete() is true to see if the zone transfer has completed.  */
name|ldns_rr
modifier|*
name|ldns_axfr_next
parameter_list|(
name|ldns_resolver
modifier|*
name|resolver
parameter_list|)
function_decl|;
comment|/**  * Abort a transfer that is in progress  * \param[in] resolver the resolver that is used  */
name|void
name|ldns_axfr_abort
parameter_list|(
name|ldns_resolver
modifier|*
name|resolver
parameter_list|)
function_decl|;
comment|/**  * Returns true if the axfr transfer has completed (i.e. 2 SOA RRs and no errors were encountered  * \param[in] resolver the resolver that is used  * \return bool true if axfr transfer was completed without error  */
name|bool
name|ldns_axfr_complete
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|resolver
parameter_list|)
function_decl|;
comment|/**  * Returns a pointer to the last ldns_pkt that was sent by the server in the AXFR transfer  * uasable for instance to get the error code on failure  * \param[in] res the resolver that was used in the axfr transfer  * \return ldns_pkt the last packet sent  */
name|ldns_pkt
modifier|*
name|ldns_axfr_last_pkt
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|res
parameter_list|)
function_decl|;
comment|/**  * Randomize the nameserver list in the resolver  * \param[in] r the resolver  */
name|void
name|ldns_resolver_nameservers_randomize
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Returns true if at least one of the provided keys is a trust anchor  * \param[in] r the current resolver  * \param[in] keys the keyset to check  * \param[out] trusted_keys the subset of trusted keys in the 'keys' rrset  * \return true if at least one of the provided keys is a configured trust anchor  */
name|bool
name|ldns_resolver_trusted_key
parameter_list|(
specifier|const
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr_list
modifier|*
name|keys
parameter_list|,
name|ldns_rr_list
modifier|*
name|trusted_keys
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_RESOLVER_H */
end_comment

end_unit

