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
literal|"@(#)def.h	9.8 91/06/11"
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
file|"config.h"
end_include

begin_include
include|#
directive|include
include|STDIO_H
end_include

begin_include
include|#
directive|include
include|CTYPE_H
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

begin_typedef
typedef|typedef
name|struct
name|dom
name|dom
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
comment|/* flags for n_flag */
end_comment

begin_define
define|#
directive|define
name|ISPRIVATE
value|0x0001
end_define

begin_comment
comment|/* invisible outside its definition file */
end_comment

begin_define
define|#
directive|define
name|NALIAS
value|0x0002
end_define

begin_comment
comment|/* heaped as an alias */
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
comment|/* extracted from heap */
end_comment

begin_define
define|#
directive|define
name|NDEAD
value|0x0010
end_define

begin_comment
comment|/* out links are dead */
end_comment

begin_define
define|#
directive|define
name|HASLEFT
value|0x0020
end_define

begin_comment
comment|/* has a left side net character */
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
comment|/* network pseudo-host */
end_comment

begin_define
define|#
directive|define
name|INDFS
value|0x0100
end_define

begin_comment
comment|/* used when removing net cycles (for -g) */
end_comment

begin_define
define|#
directive|define
name|DUMP
value|0x0200
end_define

begin_comment
comment|/* we have dumped this net's edges (for -g) */
end_comment

begin_define
define|#
directive|define
name|PRINTED
value|0x0400
end_define

begin_comment
comment|/* this host has been printed */
end_comment

begin_define
define|#
directive|define
name|NTERMINAL
value|0x0800
end_define

begin_comment
comment|/* heaped as terminal edge (or alias thereto) */
end_comment

begin_define
define|#
directive|define
name|NREF
value|0x1000
end_define

begin_comment
comment|/* node has an "interesting" reference */
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
name|ALTEREGO
parameter_list|(
name|n1
parameter_list|,
name|n2
parameter_list|)
value|((n1)->n_name == (n2)->n_name)
end_define

begin_define
define|#
directive|define
name|DEADHOST
parameter_list|(
name|n
parameter_list|)
value|(((n)->n_flag& (NDEAD | NTERMINAL))&& !ISANET(n))
end_define

begin_define
define|#
directive|define
name|DEADLINK
parameter_list|(
name|l
parameter_list|)
value|((l)->l_flag& LDEAD)
end_define

begin_define
define|#
directive|define
name|DEADNET
parameter_list|(
name|n
parameter_list|)
value|(((n)->n_flag& (NNET | NDEAD)) == (NNET | NDEAD))
end_define

begin_define
define|#
directive|define
name|GATEWAYED
parameter_list|(
name|n
parameter_list|)
value|(DEADNET(n) || ISADOMAIN(n))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_comment
comment|/*  * save some space in nodes -- there are> 10,000 allocated!  */
end_comment

begin_define
define|#
directive|define
name|n_root
value|un1.nu_root
end_define

begin_define
define|#
directive|define
name|n_net
value|un1.nu_net
end_define

begin_define
define|#
directive|define
name|n_copy
value|un1.nu_copy
end_define

begin_define
define|#
directive|define
name|n_private
value|un2.nu_priv
end_define

begin_define
define|#
directive|define
name|n_parent
value|un2.nu_par
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
comment|/* adjacency list */
name|Cost
name|n_cost
decl_stmt|;
comment|/* cost to this host */
union|union
block|{
name|node
modifier|*
name|nu_net
decl_stmt|;
comment|/* others in this network (parsing) */
name|node
modifier|*
name|nu_root
decl_stmt|;
comment|/* root of net cycle (graph dumping) */
name|node
modifier|*
name|nu_copy
decl_stmt|;
comment|/* circular copy list (mapping) */
block|}
name|un1
union|;
union|union
block|{
name|node
modifier|*
name|nu_priv
decl_stmt|;
comment|/* other privates in this file (parsing) */
name|node
modifier|*
name|nu_par
decl_stmt|;
comment|/* parent in shortest path tree (mapping) */
block|}
name|un2
union|;
name|unsigned
name|short
name|n_tloc
decl_stmt|;
comment|/* back ptr to heap/hash table */
name|unsigned
name|short
name|n_flag
decl_stmt|;
comment|/* see manifests above */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEBUG*/
end_comment

begin_define
define|#
directive|define
name|MILLION
value|(1000L * 1000L)
end_define

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
value|((Cost) 100 * MILLION)
end_define

begin_comment
comment|/* infinitely expensive link */
end_comment

begin_define
define|#
directive|define
name|DEFPENALTY
value|((Cost) 200)
end_define

begin_comment
comment|/* default avoidance cost */
end_comment

begin_comment
comment|/* data structure for adjacency list representation */
end_comment

begin_comment
comment|/* flags for l_dir */
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
value|((l)->l_netop)
end_define

begin_define
define|#
directive|define
name|LDIR
value|0x0008
end_define

begin_comment
comment|/* 0 for left, 1 for right */
end_comment

begin_define
define|#
directive|define
name|LRIGHT
value|0x0000
end_define

begin_comment
comment|/* user@host style */
end_comment

begin_define
define|#
directive|define
name|LLEFT
value|0x0008
end_define

begin_comment
comment|/* host!user style */
end_comment

begin_define
define|#
directive|define
name|LDEAD
value|0x0010
end_define

begin_comment
comment|/* this link is dead */
end_comment

begin_define
define|#
directive|define
name|LALIAS
value|0x0020
end_define

begin_comment
comment|/* this link is an alias */
end_comment

begin_define
define|#
directive|define
name|LTREE
value|0x0040
end_define

begin_comment
comment|/* member of shortest path tree */
end_comment

begin_define
define|#
directive|define
name|LGATEWAY
value|0x0080
end_define

begin_comment
comment|/* this link is a gateway */
end_comment

begin_define
define|#
directive|define
name|LTERMINAL
value|0x0100
end_define

begin_comment
comment|/* this link is terminal */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_comment
comment|/*  * borrow a field for link/node tracing.  there's a shitload of  * edges -- every word counts.  only so much squishing is possible:  * alignment dictates that the size be a multiple of four.  */
end_comment

begin_define
define|#
directive|define
name|l_next
value|un.lu_next
end_define

begin_define
define|#
directive|define
name|l_from
value|un.lu_from
end_define

begin_struct
struct|struct
name|link
block|{
name|node
modifier|*
name|l_to
decl_stmt|;
comment|/* adjacent node */
name|Cost
name|l_cost
decl_stmt|;
comment|/* edge cost */
union|union
block|{
name|link
modifier|*
name|lu_next
decl_stmt|;
comment|/* rest of adjacency list (not tracing) */
name|node
modifier|*
name|lu_from
decl_stmt|;
comment|/* source node (tracing) */
block|}
name|un
union|;
name|short
name|l_flag
decl_stmt|;
comment|/* right/left syntax, flags */
name|char
name|l_netop
decl_stmt|;
comment|/* network operator */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEBUG*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  * flattening out the unions makes it easier  * to debug (when pi is unavailable).  */
end_comment

begin_struct
struct|struct
name|node
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
name|link
modifier|*
name|n_link
decl_stmt|;
name|Cost
name|n_cost
decl_stmt|;
name|node
modifier|*
name|n_net
decl_stmt|;
name|node
modifier|*
name|n_root
decl_stmt|;
name|node
modifier|*
name|n_copy
decl_stmt|;
name|node
modifier|*
name|n_private
decl_stmt|;
name|node
modifier|*
name|n_parent
decl_stmt|;
name|unsigned
name|short
name|n_tloc
decl_stmt|;
name|unsigned
name|short
name|n_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|link
block|{
name|node
modifier|*
name|l_to
decl_stmt|;
name|Cost
name|l_cost
decl_stmt|;
name|link
modifier|*
name|l_next
decl_stmt|;
name|node
modifier|*
name|l_from
decl_stmt|;
name|short
name|l_flag
decl_stmt|;
name|char
name|l_netop
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEBUG*/
end_comment

begin_comment
comment|/* doubly linked list for known and unknown domains */
end_comment

begin_struct
struct|struct
name|dom
block|{
name|dom
modifier|*
name|next
decl_stmt|;
name|dom
modifier|*
name|prev
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

end_unit

