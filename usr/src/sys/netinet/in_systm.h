begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* in_systm.h 4.7 81/11/29 */
end_comment

begin_comment
comment|/*  * Miscellaneous internetwork  * definitions for kernel.  */
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
name|n_time
typedef|;
end_typedef

begin_comment
comment|/* ms since 00:00 GMT, byte rev */
end_comment

begin_comment
comment|/*  * The internet code runs off software interrupts.  * There is one software interrupt level for each IP layer protocol  * (e.g. IP, PUP, etc), and each such interrupt traps to the lowest  * level routine for that protocol.  *  * You can switch into the network by doing splnet() and return by splx().  * The software interrupt level for the network is higher than the software  * level for the clock (so you can enter the network in routines called  * at timeout time).  Splimp is an ipl high enough to block all imps.  * While manipulating the mbuf buffer pool you have to block imps.  */
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
name|setipintr
parameter_list|()
value|mtpr(SIRR, 12)
end_define

begin_define
define|#
directive|define
name|setrawintr
parameter_list|()
value|mtpr(SIRR, 13)
end_define

begin_comment
comment|/* splnet is defined in ../sys/asm.sed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|n_time
name|iptime
parameter_list|()
function_decl|;
end_function_decl

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

