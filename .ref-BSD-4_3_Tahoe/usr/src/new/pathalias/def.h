begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pathalias -- by steve bellovin, as told to peter honeyman */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|h_sccsid
init|=
literal|"@(#)def.h	8.1 (down!honey) 86/01/19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MAIN*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*lint*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_typedef
typedef|typedef
name|long
name|Cost
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|node
name|node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|link
name|link
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|vprintf
value|fprintf
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!lint -- this gives null effect warning*/
end_comment

begin_comment
comment|/* because it's there ... */
end_comment

begin_define
define|#
directive|define
name|vprintf
value|!Vflag ? 0 : fprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*lint*/
end_comment

begin_define
define|#
directive|define
name|NTRACE
value|16
end_define

begin_comment
comment|/* can trace up to NTRACE hosts/links */
end_comment

begin_comment
comment|/* scanner states (yylex, parse) */
end_comment

begin_define
define|#
directive|define
name|OTHER
value|0
end_define

begin_define
define|#
directive|define
name|COSTING
value|1
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|2
end_define

begin_define
define|#
directive|define
name|isnetc
parameter_list|(
name|c
parameter_list|)
value|((c)=='!' || (c)==':' || (c)=='@' || (c)=='%')
end_define

begin_define
define|#
directive|define
name|dirbits
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_comment
comment|/* flags for n_flag */
end_comment

begin_define
define|#
directive|define
name|ISPRIVATE
value|0x0001
end_define

begin_comment
comment|/* this node invisible outside its definition file */
end_comment

begin_define
define|#
directive|define
name|COLLISION
value|0x0002
end_define

begin_comment
comment|/* collides with a private host name */
end_comment

begin_define
define|#
directive|define
name|ATSIGN
value|0x0004
end_define

begin_comment
comment|/* seen an at sign?  used for magic @/% rules */
end_comment

begin_define
define|#
directive|define
name|MAPPED
value|0x0008
end_define

begin_comment
comment|/* done mapping this node */
end_comment

begin_define
define|#
directive|define
name|NDEAD
value|0x0010
end_define

begin_comment
comment|/* node is dead */
end_comment

begin_define
define|#
directive|define
name|HASLEFT
value|0x0020
end_define

begin_comment
comment|/* route has a left side net character */
end_comment

begin_define
define|#
directive|define
name|HASRIGHT
value|0x0040
end_define

begin_comment
comment|/* route has a right side net character */
end_comment

begin_define
define|#
directive|define
name|NNET
value|0x0080
end_define

begin_comment
comment|/* node is a network name */
end_comment

begin_define
define|#
directive|define
name|INDFS
value|0x0100
end_define

begin_comment
comment|/* used when removing net cycles */
end_comment

begin_define
define|#
directive|define
name|DUMP
value|0x0200
end_define

begin_comment
comment|/* we have dumped this net's edges */
end_comment

begin_define
define|#
directive|define
name|GATEWAYIN
value|0x0400
end_define

begin_comment
comment|/* heaped via gatewayed net */
end_comment

begin_define
define|#
directive|define
name|ISADOMAIN
parameter_list|(
name|n
parameter_list|)
value|((n)->n_name[0] == '.')
end_define

begin_define
define|#
directive|define
name|ISANET
parameter_list|(
name|n
parameter_list|)
value|(((n)->n_flag& NNET) || ISADOMAIN(n))
end_define

begin_define
define|#
directive|define
name|DEADHOST
parameter_list|(
name|n
parameter_list|)
value|(((n)->n_flag& (NNET | NDEAD)) == NDEAD)
end_define

begin_define
define|#
directive|define
name|GATEWAYED
parameter_list|(
name|n
parameter_list|)
value|(((n)->n_flag& (NNET | NDEAD)) == (NNET | NDEAD) || ISADOMAIN(n))
end_define

begin_comment
comment|/*  * save some space in nodes -- there are> 10,000 allocated!  *  *	node	*n_net		others in this network (parsing)  * 	node	*n_root		root of net cycle (mapping)  *  *	node	*n_private	other privates in this file (parsing)  *	char	*n_parent	parent in shortest path tree (mapping)  *		  */
end_comment

begin_define
define|#
directive|define
name|n_root
value|n_net_root
end_define

begin_define
define|#
directive|define
name|n_net
value|n_net_root
end_define

begin_define
define|#
directive|define
name|n_private
value|n_private_parent
end_define

begin_define
define|#
directive|define
name|n_parent
value|n_private_parent
end_define

begin_comment
comment|/* WARNING: if> 2^16 nodes, type of n_tloc must change */
end_comment

begin_struct
struct|struct
name|node
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* host name */
name|link
modifier|*
name|n_link
decl_stmt|;
comment|/* head of adjacency list */
name|node
modifier|*
name|n_net_root
decl_stmt|;
name|node
modifier|*
name|n_private_parent
decl_stmt|;
name|Cost
name|n_cost
decl_stmt|;
comment|/* cost to this host */
name|unsigned
name|short
name|n_tloc
decl_stmt|;
comment|/* back ptr to heap/hash table */
name|short
name|n_flag
decl_stmt|;
comment|/* see manifests above */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFNET
value|'!'
end_define

begin_comment
comment|/* default network operator */
end_comment

begin_define
define|#
directive|define
name|DEFDIR
value|LLEFT
end_define

begin_comment
comment|/* host on left is default */
end_comment

begin_define
define|#
directive|define
name|DEFCOST
value|((Cost) 4000)
end_define

begin_comment
comment|/* default cost of a link */
end_comment

begin_define
define|#
directive|define
name|INF
value|((Cost) 30000000)
end_define

begin_comment
comment|/* infinitely expensive link */
end_comment

begin_comment
comment|/* data structure for adjacency list representation */
end_comment

begin_comment
comment|/* flags for l_dir */
end_comment

begin_comment
comment|/*  * there's an ugly dependency between the following manifests and the  * variable Netchars = "!:^@%", defined in extern.c.  this saves 2  * bytes per link (of which there are well over 20k).  this does not  * mean i'm satsified with bad design.  */
end_comment

begin_define
define|#
directive|define
name|NETDIR
parameter_list|(
name|l
parameter_list|)
value|((l)->l_flag& LDIR)
end_define

begin_define
define|#
directive|define
name|NETCHAR
parameter_list|(
name|l
parameter_list|)
value|(Netchars[(l)->l_flag& LNETCHARS])
end_define

begin_define
define|#
directive|define
name|LNETCHARS
value|0x3
end_define

begin_define
define|#
directive|define
name|LBANG
value|0x0
end_define

begin_define
define|#
directive|define
name|LCOLON
value|0x1
end_define

begin_define
define|#
directive|define
name|LAT
value|0x2
end_define

begin_define
define|#
directive|define
name|LPERCENT
value|0x3
end_define

begin_define
define|#
directive|define
name|LDIR
value|0x8
end_define

begin_comment
comment|/* 0 for left, 1 for right */
end_comment

begin_define
define|#
directive|define
name|LRIGHT
value|0x0
end_define

begin_comment
comment|/* user@host style */
end_comment

begin_define
define|#
directive|define
name|LLEFT
value|0x8
end_define

begin_comment
comment|/* host!user style */
end_comment

begin_define
define|#
directive|define
name|LDEAD
value|0x10
end_define

begin_comment
comment|/* this link is dead */
end_comment

begin_define
define|#
directive|define
name|LTREE
value|0x20
end_define

begin_comment
comment|/* member of shortest path tree */
end_comment

begin_define
define|#
directive|define
name|LALIAS
value|0x40
end_define

begin_comment
comment|/* alias */
end_comment

begin_define
define|#
directive|define
name|LGATEWAY
value|0x80
end_define

begin_comment
comment|/* this link is a gateway */
end_comment

begin_comment
comment|/*  * borrow a field for link/node tracing  *  *	link	*l_next;	rest of adjacency list (not tracing)  *	link	*l_from;	source node (tracing) -- requires a cast  *		  */
end_comment

begin_define
define|#
directive|define
name|l_next
value|l_next_from
end_define

begin_define
define|#
directive|define
name|l_from
value|l_next_from
end_define

begin_struct
struct|struct
name|link
block|{
name|link
modifier|*
name|l_next_from
decl_stmt|;
name|node
modifier|*
name|l_to
decl_stmt|;
comment|/* adjacent node */
name|Cost
name|l_cost
decl_stmt|;
comment|/* edge cost */
name|char
name|l_flag
decl_stmt|;
comment|/* right/left syntax */
block|}
struct|;
end_struct

begin_comment
comment|/*  * static functions don't show up in prof(1), so ...  * someday i'll be done profiling.  * yeah, sure, like when hell freezes over.  */
end_comment

begin_define
define|#
directive|define
name|STATIC
end_define

begin_comment
comment|/*static*/
end_comment

begin_comment
comment|/* external functions */
end_comment

begin_decl_stmt
specifier|extern
name|node
modifier|*
name|addnode
argument_list|()
decl_stmt|,
modifier|*
name|newnode
argument_list|()
decl_stmt|,
modifier|*
modifier|*
name|newtable
argument_list|()
decl_stmt|,
modifier|*
name|addprivate
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|link
modifier|*
name|addlink
argument_list|()
decl_stmt|,
modifier|*
name|addgateway
argument_list|()
decl_stmt|,
modifier|*
name|newlink
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strsave
argument_list|()
decl_stmt|,
modifier|*
name|local
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* external variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|node
modifier|*
name|Home
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Cfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|Ifiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ProgName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|node
modifier|*
modifier|*
name|Table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Tabsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Netchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Iflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Ncount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Lcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Graphout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Linkout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|node
modifier|*
name|Private
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|Hashpart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Scanstate
decl_stmt|;
end_decl_stmt

end_unit

