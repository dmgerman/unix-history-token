begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* in_systm.h 4.1 81/11/08 */
end_comment

begin_comment
comment|/*  * Miscellaneous internetwork  * definitions for kernel.  */
end_comment

begin_comment
comment|/* THESE SHOULD BE ELIMINATED */
end_comment

begin_define
define|#
directive|define
name|NCON
value|20
end_define

begin_comment
comment|/* SHOULD BE DYNAMIC, NO LIMIT */
end_comment

begin_define
define|#
directive|define
name|NHOST
value|20
end_define

begin_comment
comment|/* SHOULD BE SOME DYNAMIC LIMIT */
end_comment

begin_comment
comment|/* END SHOULD BE ELIMINATED */
end_comment

begin_comment
comment|/*  * Network types.  *  * Internally the system keeps counters in the headers with the bytes  * swapped so that VAX instructions will work on them.  It reverses  * the bytes before transmission at each protocol level.  The n_ types  * represent the types with the bytes in ``high-ender'' order.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|n_short
typedef|;
end_typedef

begin_comment
comment|/* short as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_long
typedef|;
end_typedef

begin_comment
comment|/* long as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|seq_t
typedef|;
end_typedef

begin_comment
comment|/* sequence number */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_time
typedef|;
end_typedef

begin_comment
comment|/* ms since 00:00 GMT, byte rev */
end_comment

begin_comment
comment|/*  * The network runs as a software interrupt process.  * You can switch into the network by doing splnet() and return by splx().  * The software interrupt level for the network is higher than the software  * level for the clock (so you can enter the network in routines called  * at timeout time).  Splimp is an ipl high enough to block all imps.  * While manipulating the mbuf buffer pool you have to block imps since  * allocation occurs at interrupt level.  (It would be easier to  * use interlocked instructions, but we don't do this yet.)  */
end_comment

begin_define
define|#
directive|define
name|splimp
value|spl5
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|mtpr(SIRR, 12)
end_define

begin_comment
comment|/* splnet is defined in ../sys/asm.sed */
end_comment

begin_comment
comment|/*  * Network statistics record.  *  * SHOULD BE KEPT PER INTERFACE, AND WITH CNT, RATE, SUM.  */
end_comment

begin_struct
struct|struct
name|net_stat
block|{
name|int
name|imp_resets
decl_stmt|;
comment|/* # times imp reset */
name|int
name|imp_flushes
decl_stmt|;
comment|/* # packets flushed by imp */
name|int
name|imp_drops
decl_stmt|;
comment|/* # msgs from imp no-one wants */
name|int
name|m_drops
decl_stmt|;
comment|/* # mbuf drops from lack of bufs */
name|int
name|ip_badsum
decl_stmt|;
comment|/* # bad ip checksums */
name|int
name|t_badsum
decl_stmt|;
comment|/* # bad tcp checksums */
name|int
name|t_badsegs
decl_stmt|;
comment|/* # bad tcp segments */
name|int
name|t_unack
decl_stmt|;
comment|/* # tcp segs placed on rcv_unack */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|nnetpages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|net_stat
name|netstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* net statistics block */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KPROF
end_ifdef

begin_include
include|#
directive|include
file|"../inet/count.h"
end_include

begin_define
define|#
directive|define
name|COUNT
parameter_list|(
name|i
parameter_list|)
value|nrcount[i]++
end_define

begin_decl_stmt
name|int
name|nrcount
index|[
name|NCOUNTERS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COUNT
parameter_list|(
name|i
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

