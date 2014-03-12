begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2003 Luigi Rizzo  * Copyright (c) 1996 Alex Nash, Paul Traina, Poul-Henning Kamp  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Idea and grammar partially left from:  * Copyright (c) 1993 Daniel Boulet  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * NEW command line interface for IP firewall facility  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Options that can be set on the command line.  * When reading commands from a file, a subset of the options can also  * be applied globally by specifying them before the file name.  * After that, each line can contain its own option that changes  * the global value.  * XXX The context is not restored after each line.  */
end_comment

begin_struct
struct|struct
name|cmdline_opts
block|{
comment|/* boolean options: */
name|int
name|do_value_as_ip
decl_stmt|;
comment|/* show table value as IP */
name|int
name|do_resolv
decl_stmt|;
comment|/* try to resolve all ip to names */
name|int
name|do_time
decl_stmt|;
comment|/* Show time stamps */
name|int
name|do_quiet
decl_stmt|;
comment|/* Be quiet in add and flush */
name|int
name|do_pipe
decl_stmt|;
comment|/* this cmd refers to a pipe/queue/sched */
name|int
name|do_nat
decl_stmt|;
comment|/* this cmd refers to a nat config */
name|int
name|do_dynamic
decl_stmt|;
comment|/* display dynamic rules */
name|int
name|do_expired
decl_stmt|;
comment|/* display expired dynamic rules */
name|int
name|do_compact
decl_stmt|;
comment|/* show rules in compact mode */
name|int
name|do_force
decl_stmt|;
comment|/* do not ask for confirmation */
name|int
name|show_sets
decl_stmt|;
comment|/* display the set each rule belongs to */
name|int
name|test_only
decl_stmt|;
comment|/* only check syntax */
name|int
name|comment_only
decl_stmt|;
comment|/* only print action and comment */
name|int
name|verbose
decl_stmt|;
comment|/* be verbose on some commands */
comment|/* The options below can have multiple values. */
name|int
name|do_sort
decl_stmt|;
comment|/* field to sort results (0 = no) */
comment|/* valid fields are 1 and above */
name|int
name|use_set
decl_stmt|;
comment|/* work with specified set number */
comment|/* 0 means all sets, otherwise apply to set use_set - 1 */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cmdline_opts
name|co
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * _s_x is a structure that stores a string<-> token pairs, used in  * various places in the parser. Entries are stored in arrays,  * with an entry with s=NULL as terminator.  * The search routines are match_token() and match_value().  * Often, an element with x=0 contains an error string.  *  */
end_comment

begin_struct
struct|struct
name|_s_x
block|{
name|char
specifier|const
modifier|*
name|s
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|tokens
block|{
name|TOK_NULL
init|=
literal|0
block|,
name|TOK_OR
block|,
name|TOK_NOT
block|,
name|TOK_STARTBRACE
block|,
name|TOK_ENDBRACE
block|,
name|TOK_ACCEPT
block|,
name|TOK_COUNT
block|,
name|TOK_PIPE
block|,
name|TOK_LINK
block|,
name|TOK_QUEUE
block|,
name|TOK_FLOWSET
block|,
name|TOK_SCHED
block|,
name|TOK_DIVERT
block|,
name|TOK_TEE
block|,
name|TOK_NETGRAPH
block|,
name|TOK_NGTEE
block|,
name|TOK_FORWARD
block|,
name|TOK_SKIPTO
block|,
name|TOK_DENY
block|,
name|TOK_REJECT
block|,
name|TOK_RESET
block|,
name|TOK_UNREACH
block|,
name|TOK_CHECKSTATE
block|,
name|TOK_NAT
block|,
name|TOK_REASS
block|,
name|TOK_CALL
block|,
name|TOK_RETURN
block|,
name|TOK_ALTQ
block|,
name|TOK_LOG
block|,
name|TOK_TAG
block|,
name|TOK_UNTAG
block|,
name|TOK_TAGGED
block|,
name|TOK_UID
block|,
name|TOK_GID
block|,
name|TOK_JAIL
block|,
name|TOK_IN
block|,
name|TOK_LIMIT
block|,
name|TOK_KEEPSTATE
block|,
name|TOK_LAYER2
block|,
name|TOK_OUT
block|,
name|TOK_DIVERTED
block|,
name|TOK_DIVERTEDLOOPBACK
block|,
name|TOK_DIVERTEDOUTPUT
block|,
name|TOK_XMIT
block|,
name|TOK_RECV
block|,
name|TOK_VIA
block|,
name|TOK_FRAG
block|,
name|TOK_IPOPTS
block|,
name|TOK_IPLEN
block|,
name|TOK_IPID
block|,
name|TOK_IPPRECEDENCE
block|,
name|TOK_DSCP
block|,
name|TOK_IPTOS
block|,
name|TOK_IPTTL
block|,
name|TOK_IPVER
block|,
name|TOK_ESTAB
block|,
name|TOK_SETUP
block|,
name|TOK_TCPDATALEN
block|,
name|TOK_TCPFLAGS
block|,
name|TOK_TCPOPTS
block|,
name|TOK_TCPSEQ
block|,
name|TOK_TCPACK
block|,
name|TOK_TCPWIN
block|,
name|TOK_ICMPTYPES
block|,
name|TOK_MAC
block|,
name|TOK_MACTYPE
block|,
name|TOK_VERREVPATH
block|,
name|TOK_VERSRCREACH
block|,
name|TOK_ANTISPOOF
block|,
name|TOK_IPSEC
block|,
name|TOK_COMMENT
block|,
name|TOK_PLR
block|,
name|TOK_NOERROR
block|,
name|TOK_BUCKETS
block|,
name|TOK_DSTIP
block|,
name|TOK_SRCIP
block|,
name|TOK_DSTPORT
block|,
name|TOK_SRCPORT
block|,
name|TOK_ALL
block|,
name|TOK_MASK
block|,
name|TOK_FLOW_MASK
block|,
name|TOK_SCHED_MASK
block|,
name|TOK_BW
block|,
name|TOK_DELAY
block|,
name|TOK_PROFILE
block|,
name|TOK_BURST
block|,
name|TOK_RED
block|,
name|TOK_GRED
block|,
name|TOK_DROPTAIL
block|,
name|TOK_PROTO
block|,
comment|/* dummynet tokens */
name|TOK_WEIGHT
block|,
name|TOK_LMAX
block|,
name|TOK_PRI
block|,
name|TOK_TYPE
block|,
name|TOK_SLOTSIZE
block|,
name|TOK_IP
block|,
name|TOK_IF
block|,
name|TOK_ALOG
block|,
name|TOK_DENY_INC
block|,
name|TOK_SAME_PORTS
block|,
name|TOK_UNREG_ONLY
block|,
name|TOK_SKIP_GLOBAL
block|,
name|TOK_RESET_ADDR
block|,
name|TOK_ALIAS_REV
block|,
name|TOK_PROXY_ONLY
block|,
name|TOK_REDIR_ADDR
block|,
name|TOK_REDIR_PORT
block|,
name|TOK_REDIR_PROTO
block|,
name|TOK_IPV6
block|,
name|TOK_FLOWID
block|,
name|TOK_ICMP6TYPES
block|,
name|TOK_EXT6HDR
block|,
name|TOK_DSTIP6
block|,
name|TOK_SRCIP6
block|,
name|TOK_IPV4
block|,
name|TOK_UNREACH6
block|,
name|TOK_RESET6
block|,
name|TOK_FIB
block|,
name|TOK_SETFIB
block|,
name|TOK_LOOKUP
block|,
name|TOK_SOCKARG
block|,
name|TOK_SETDSCP
block|, }
enum|;
end_enum

begin_comment
comment|/*  * the following macro returns an error message if we run out of  * arguments.  */
end_comment

begin_define
define|#
directive|define
name|NEED
parameter_list|(
name|_p
parameter_list|,
name|msg
parameter_list|)
value|{if (!_p) errx(EX_USAGE, msg);}
end_define

begin_define
define|#
directive|define
name|NEED1
parameter_list|(
name|msg
parameter_list|)
value|{if (!(*av)) errx(EX_USAGE, msg);}
end_define

begin_function_decl
name|int
name|pr_u64
parameter_list|(
name|uint64_t
modifier|*
name|pd
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* memory allocation support */
end_comment

begin_function_decl
name|void
modifier|*
name|safe_calloc
parameter_list|(
name|size_t
name|number
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|safe_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* string comparison functions used for historical compatibility */
end_comment

begin_function_decl
name|int
name|_substrcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_substrcmp2
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|,
specifier|const
name|char
modifier|*
name|str3
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* utility functions */
end_comment

begin_function_decl
name|int
name|match_token
parameter_list|(
name|struct
name|_s_x
modifier|*
name|table
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|match_value
parameter_list|(
name|struct
name|_s_x
modifier|*
name|p
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_cmd
parameter_list|(
name|int
name|optname
parameter_list|,
name|void
modifier|*
name|optval
parameter_list|,
name|uintptr_t
name|optlen
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|in6_addr
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|n2mask
parameter_list|(
name|struct
name|in6_addr
modifier|*
name|mask
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|contigmask
parameter_list|(
name|uint8_t
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Forward declarations to avoid include way too many headers.  * C does not allow duplicated typedefs, so we use the base struct  * that the typedef points to.  * Should the typedefs use a different type, the compiler will  * still detect the change when compiling the body of the  * functions involved, so we do not lose error checking.  */
end_comment

begin_struct_decl
struct_decl|struct
name|_ipfw_insn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ipfw_insn_altq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ipfw_insn_u32
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ipfw_insn_ip6
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ipfw_insn_icmp6
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The reserved set numer. This is a constant in ip_fw.h  * but we store it in a variable so other files do not depend  * in that header just for one constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|resvd_set_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first-level command handlers */
end_comment

begin_function_decl
name|void
name|ipfw_add
parameter_list|(
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_show_nat
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_config_pipe
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_config_nat
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_sets_handler
parameter_list|(
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_table_handler
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_sysctl_handler
parameter_list|(
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_delete
parameter_list|(
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_flush
parameter_list|(
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_zero
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|optname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_list
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|show_counters
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PF
end_ifdef

begin_comment
comment|/* altq.c */
end_comment

begin_function_decl
name|void
name|altq_set_enabled
parameter_list|(
name|int
name|enabled
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|altq_name_to_qid
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_altq_cmd
parameter_list|(
name|struct
name|_ipfw_insn_altq
modifier|*
name|altqptr
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO_ALTQ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* dummynet.c */
end_comment

begin_function_decl
name|void
name|dummynet_list
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|show_counters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dummynet_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipfw_delete_pipe
parameter_list|(
name|int
name|pipe_or_queue
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ipv6.c */
end_comment

begin_function_decl
name|void
name|print_unreach6_code
parameter_list|(
name|uint16_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ip6
parameter_list|(
name|struct
name|_ipfw_insn_ip6
modifier|*
name|cmd
parameter_list|,
name|char
specifier|const
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_flow6id
parameter_list|(
name|struct
name|_ipfw_insn_u32
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_icmp6types
parameter_list|(
name|struct
name|_ipfw_insn_u32
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_ext6hdr
parameter_list|(
name|struct
name|_ipfw_insn
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|_ipfw_insn
modifier|*
name|add_srcip6
parameter_list|(
name|struct
name|_ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|av
parameter_list|,
name|int
name|cblen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|_ipfw_insn
modifier|*
name|add_dstip6
parameter_list|(
name|struct
name|_ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|av
parameter_list|,
name|int
name|cblen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_flow6
parameter_list|(
name|struct
name|_ipfw_insn_u32
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|av
parameter_list|,
name|int
name|cblen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_unreach6_code
parameter_list|(
name|u_short
modifier|*
name|codep
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_icmp6types
parameter_list|(
name|struct
name|_ipfw_insn_icmp6
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|av
parameter_list|,
name|int
name|cblen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_ext6hdr
parameter_list|(
name|struct
name|_ipfw_insn
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

end_unit

