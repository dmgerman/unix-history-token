begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Site-specific definitions.     For supported systems, you shouldn't need to make any changes here.    However, you may want to, in order to deal with site-specific    differences. */
end_comment

begin_comment
comment|/* Add any site-specific definitions and inclusions here... */
end_comment

begin_comment
comment|/* #include<site-foo-bar.h> */
end_comment

begin_comment
comment|/* #define SITE_FOOBAR */
end_comment

begin_comment
comment|/* Define this if you don't want dhcpd to run as a daemon and do want    to see all its output printed to stdout instead of being logged via    syslog().   This also makes dhcpd use the dhcpd.conf in its working    directory and write the dhcpd.leases file there. */
end_comment

begin_comment
comment|/* #define DEBUG */
end_comment

begin_comment
comment|/* Define this to see what the parser is parsing.   You probably don't    want to see this. */
end_comment

begin_comment
comment|/* #define DEBUG_TOKENS */
end_comment

begin_comment
comment|/* Define this to see dumps of incoming and outgoing packets.    This    slows things down quite a bit... */
end_comment

begin_comment
comment|/* #define DEBUG_PACKET */
end_comment

begin_comment
comment|/* Define this if you want to see dumps of expression evaluation. */
end_comment

begin_comment
comment|/* #define DEBUG_EXPRESSIONS */
end_comment

begin_comment
comment|/* Define this if you want to see dumps of find_lease() in action. */
end_comment

begin_comment
comment|/* #define DEBUG_FIND_LEASE */
end_comment

begin_comment
comment|/* Define this if you want to see dumps of parsed expressions. */
end_comment

begin_comment
comment|/* #define DEBUG_EXPRESSION_PARSE */
end_comment

begin_comment
comment|/* Define this if you want to watch the class matching process. */
end_comment

begin_comment
comment|/* #define DEBUG_CLASS_MATCHING */
end_comment

begin_comment
comment|/* Define this if you want to track memory usage for the purpose of    noticing memory leaks quickly. */
end_comment

begin_comment
comment|/* #define DEBUG_MEMORY_LEAKAGE */
end_comment

begin_comment
comment|/* Define this if you want exhaustive (and very slow) checking of the    malloc pool for corruption. */
end_comment

begin_comment
comment|/* #define DEBUG_MALLOC_POOL */
end_comment

begin_comment
comment|/* Define this if you want to see a message every time a lease's state    changes. */
end_comment

begin_comment
comment|/* #define DEBUG_LEASE_STATE_TRANSITIONS */
end_comment

begin_comment
comment|/* Define this if you want to maintain a history of the last N operations    that changed reference counts on objects.   This can be used to debug    cases where an object is dereferenced too often, or not often enough. */
end_comment

begin_comment
comment|/* #define DEBUG_RC_HISTORY */
end_comment

begin_comment
comment|/* Define this if you want to see the history every cycle. */
end_comment

begin_comment
comment|/* #define DEBUG_RC_HISTORY_EXHAUSTIVELY */
end_comment

begin_comment
comment|/* This is the number of history entries to maintain - by default, 256. */
end_comment

begin_comment
comment|/* #define RC_HISTORY_MAX 10240 */
end_comment

begin_comment
comment|/* Define this if you want dhcpd to dump core when a non-fatal memory    allocation error is detected (i.e., something that would cause a    memory leak rather than a memory smash). */
end_comment

begin_comment
comment|/* #define POINTER_DEBUG */
end_comment

begin_comment
comment|/* Define this if you want debugging output for DHCP failover protocol    messages. */
end_comment

begin_comment
comment|/* #define DEBUG_FAILOVER_MESSAGES */
end_comment

begin_comment
comment|/* Define this if you want debugging output for DHCP failover protocol    lease assignment timing. */
end_comment

begin_comment
comment|/* #define DEBUG_FAILOVER_TIMING */
end_comment

begin_comment
comment|/* Define this if you want all leases written to the lease file, even if    they are free leases that have never been used. */
end_comment

begin_define
define|#
directive|define
name|DEBUG_DUMP_ALL_LEASES
end_define

begin_comment
comment|/* Define this if you want DHCP failover protocol support in the DHCP    server. */
end_comment

begin_define
define|#
directive|define
name|FAILOVER_PROTOCOL
end_define

begin_comment
comment|/* Define this if you want DNS update functionality to be available. */
end_comment

begin_define
define|#
directive|define
name|NSUPDATE
end_define

begin_comment
comment|/* Define this if you want the dhcpd.pid file to go somewhere other than    the default (which varies from system to system, but is usually either    /etc or /var/run. */
end_comment

begin_comment
comment|/* #define _PATH_DHCPD_PID	"/var/run/dhcpd.pid" */
end_comment

begin_comment
comment|/* Define this if you want the dhcpd.leases file (the dynamic lease database)    to go somewhere other than the default location, which is normally    /etc/dhcpd.leases. */
end_comment

begin_comment
comment|/* #define _PATH_DHCPD_DB	"/etc/dhcpd.leases" */
end_comment

begin_comment
comment|/* Define this if you want the dhcpd.conf file to go somewhere other than    the default location.   By default, it goes in /etc/dhcpd.conf. */
end_comment

begin_comment
comment|/* #define _PATH_DHCPD_CONF	"/etc/dhcpd.conf" */
end_comment

begin_comment
comment|/* Network API definitions.   You do not need to choose one of these - if    you don't choose, one will be chosen for you in your system's config    header.    DON'T MESS WITH THIS UNLESS YOU KNOW WHAT YOU'RE DOING!!! */
end_comment

begin_comment
comment|/* Define this to use the standard BSD socket API.     On many systems, the BSD socket API does not provide the ability to    send packets to the 255.255.255.255 broadcast address, which can    prevent some clients (e.g., Win95) from seeing replies.   This is    not a problem on Solaris.     In addition, the BSD socket API will not work when more than one    network interface is configured on the server.     However, the BSD socket API is about as efficient as you can get, so if    the aforementioned problems do not matter to you, or if no other    API is supported for your system, you may want to go with it. */
end_comment

begin_comment
comment|/* #define USE_SOCKETS */
end_comment

begin_comment
comment|/* Define this to use the Sun Streams NIT API.     The Sun Streams NIT API is only supported on SunOS 4.x releases. */
end_comment

begin_comment
comment|/* #define USE_NIT */
end_comment

begin_comment
comment|/* Define this to use the Berkeley Packet Filter API.     The BPF API is available on all 4.4-BSD derivatives, including    NetBSD, FreeBSD and BSDI's BSD/OS.   It's also available on    DEC Alpha OSF/1 in a compatibility mode supported by the Alpha OSF/1    packetfilter interface. */
end_comment

begin_comment
comment|/* #define USE_BPF */
end_comment

begin_comment
comment|/* Define this to use the raw socket API.     The raw socket API is provided on many BSD derivatives, and provides    a way to send out raw IP packets.   It is only supported for sending    packets - packets must be received with the regular socket API.    This code is experimental - I've never gotten it to actually transmit    a packet to the 255.255.255.255 broadcast address - so use it at your    own risk. */
end_comment

begin_comment
comment|/* #define USE_RAW_SOCKETS */
end_comment

begin_comment
comment|/* Define this to change the logging facility used by dhcpd. */
end_comment

begin_comment
comment|/* #define DHCPD_LOG_FACILITY LOG_DAEMON */
end_comment

begin_comment
comment|/* Define this if you aren't debugging and you want to save memory    (potentially a _lot_ of memory) by allocating leases in chunks rather    than one at a time. */
end_comment

begin_define
define|#
directive|define
name|COMPACT_LEASES
end_define

begin_comment
comment|/* Define this if you want to be able to save and playback server operational    traces. */
end_comment

begin_define
define|#
directive|define
name|TRACING
end_define

end_unit

