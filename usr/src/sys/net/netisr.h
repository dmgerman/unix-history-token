begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)netisr.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The networking code runs off software interrupts.  *  * You can switch into the network by doing splnet() and return by splx().  * The software interrupt level for the network is higher than the software  * level for the clock (so you can enter the network in routines called  * at timeout time).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|mtpr(SIRR, 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Each ``pup-level-1'' input queue has a bit in a ``netisr'' status  * word which is used to de-multiplex a single software  * interrupt used for scheduling the network code to calls  * on the lowest level routine of each protocol.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_RAW
value|0
end_define

begin_comment
comment|/* same as AF_UNSPEC */
end_comment

begin_define
define|#
directive|define
name|NETISR_IP
value|2
end_define

begin_comment
comment|/* same as AF_INET */
end_comment

begin_define
define|#
directive|define
name|NETISR_IMP
value|3
end_define

begin_comment
comment|/* same as AF_IMPLINK */
end_comment

begin_define
define|#
directive|define
name|NETISR_NS
value|6
end_define

begin_comment
comment|/* same as AF_NS */
end_comment

begin_define
define|#
directive|define
name|NETISR_ISO
value|7
end_define

begin_comment
comment|/* same as AF_ISO */
end_comment

begin_define
define|#
directive|define
name|NETISR_CCITT
value|10
end_define

begin_comment
comment|/* same as AF_CCITT */
end_comment

begin_define
define|#
directive|define
name|schednetisr
parameter_list|(
name|anisr
parameter_list|)
value|{ netisr |= 1<<(anisr); setsoftnet(); }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|netisr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling bits for network */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

