begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*       ________________________________________________________        */
end_comment

begin_comment
comment|/*      /                                                        \       */
end_comment

begin_comment
comment|/*     |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*     |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*      \________________________________________________________/       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	Copyright (c) 1989 by Advanced Computer Communications           */
end_comment

begin_comment
comment|/*  	720 Santa Barbara Street, Santa Barbara, California  93101       */
end_comment

begin_comment
comment|/*  	(805) 963-9431                                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Files:		if_pi.c, if_pivar.c                              */
end_comment

begin_comment
comment|/*			ACP_PI (Programmer Interface) for 4.3bsd and	 */
end_comment

begin_comment
comment|/*			Ultrix 2.0 (and newer)				 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		??? (Steve or Charles)				 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		Programmers Interface for 6250 software		 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Function:		To enable network connections on ACP_PI to	 */
end_comment

begin_comment
comment|/*			communicate with UNIX.				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* Configuration Entry:							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*      device dda0 at uba? csr 0166740 vector ddainta ddaintb		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* 									 */
end_comment

begin_comment
comment|/*  Revision History at end of file					 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* Usage Notes:								 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*      - make devices in /dev for those pi				 */
end_comment

begin_comment
comment|/*        devices which you want in your configuration			 */
end_comment

begin_comment
comment|/* 									 */
end_comment

begin_comment
comment|/* System Notes:							 */
end_comment

begin_comment
comment|/* 									 */
end_comment

begin_comment
comment|/*       Refer to the installation instructions, readme.txt, which	 */
end_comment

begin_comment
comment|/*       are included on the pi driver distribution medium.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* Design Overview:							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* Data flows in two directions through the PI interface.  This section	 */
end_comment

begin_comment
comment|/* covers how data gets in and out of the driver.			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* OUTBOUND DATA (user process -> FE):					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* 1) The user process issues an ioctl(2) call with pi_dblock  structure */
end_comment

begin_comment
comment|/*    which gives the address and length of the user data as well as	 */
end_comment

begin_comment
comment|/*    the lcn that the data is to go out on.				 */
end_comment

begin_comment
comment|/* 2) The piioctl routine in the case XIOWRITE checks the validity of    */
end_comment

begin_comment
comment|/*    the specified lcn the calls pi_write.				 */
end_comment

begin_comment
comment|/* 3) The pi_write routine allocates a small mbuf.  If the user data	 */
end_comment

begin_comment
comment|/*    is longer than MLEN (112) bytes then a page cluster is allocated	 */
end_comment

begin_comment
comment|/*    to convert the small mbuf into a large mbuf.  The user data is	 */
end_comment

begin_comment
comment|/*    then copied to the mbuf.  The mbuf is put on the output queue for  */
end_comment

begin_comment
comment|/*    the lcn (dc->dc_oq) using the IF_ENQUEUE macros.  If the queue is  */
end_comment

begin_comment
comment|/*    full then the process will sleep on dc->dc_oq.  The wakeup will    */
end_comment

begin_comment
comment|/*    come from the pi_data routine when it sees a write completion.     */
end_comment

begin_comment
comment|/*    After the data is queue the dda_start is called to try to send the */
end_comment

begin_comment
comment|/*    data.								 */
end_comment

begin_comment
comment|/* 4) The dda_start routine dequeues the data from the per lcn ouput     */
end_comment

begin_comment
comment|/*    data queue and hooks the mbuf onto the write side of the hdx_chan  */
end_comment

begin_comment
comment|/*    structure for the lcn. The routine dda_wrq is called passing this  */
end_comment

begin_comment
comment|/*    structure.							 */
end_comment

begin_comment
comment|/* 5) The routine dda_wrq takes the hc structure and puts it on the      */
end_comment

begin_comment
comment|/*     global output queue ds->dda_sioq. It then calls start_chn().	 */
end_comment

begin_comment
comment|/* 6) start_chn() set up the comregs and request an A interrupt.  The    */
end_comment

begin_comment
comment|/*    A interrupt routine will handle the transfer grant and write 	 */
end_comment

begin_comment
comment|/*    completion.							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* INBOUND DATA (FE -> user process):					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* A) interrupt side----						 */
end_comment

begin_comment
comment|/*    1) Initially a read is posted for every logical circuit.  When     */
end_comment

begin_comment
comment|/*	 data comes in the interrupt A routine will handle doing the	 */
end_comment

begin_comment
comment|/*	 transfer grant. When the read completes then the type of	 */
end_comment

begin_comment
comment|/*	 channel is determined (IP,X.29 or PI).  For PI data the routine */
end_comment

begin_comment
comment|/*	 pi_data() is called with the mbuf and read completion status.   */
end_comment

begin_comment
comment|/*    2) In the routine pi_data() if the read completion status is       */
end_comment

begin_comment
comment|/*	 DDAIOCOK then the the packet is complete so the routine	 */
end_comment

begin_comment
comment|/*	 pi_queue_data is called to queue the data for the user process  */
end_comment

begin_comment
comment|/*	 to read.  If the status is DDAIOCOKP then the packet has not	 */
end_comment

begin_comment
comment|/*	 been completely read.  In this case the routine dda_rrq is	 */
end_comment

begin_comment
comment|/*	 called to allocate a new mbuf and chain it to the end of the	 */
end_comment

begin_comment
comment|/*	 mbufs that have already been filled from this packet.  When the */
end_comment

begin_comment
comment|/*	 packet is exhausted then the whole chain of mbufs will be 	 */
end_comment

begin_comment
comment|/*	 passed to pi_queue_data.					 */
end_comment

begin_comment
comment|/*    3) The routine pi_queue_data uses a small array of pi_qmem	 */
end_comment

begin_comment
comment|/*	 structures to form a queue of input data.  Each of these	 */
end_comment

begin_comment
comment|/*	 structures has a pointer to an mbuf.  This may point to a	 */
end_comment

begin_comment
comment|/*	 single mbuf or a chain of mbufs depending on how many mbufs it	 */
end_comment

begin_comment
comment|/*	 took to read the packet.  Pi_queue_data will copy the important */
end_comment

begin_comment
comment|/*	 information to the pi_qmem structure and then wakeup any	 */
end_comment

begin_comment
comment|/*	 processes that have slept waiting for data to come in.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/* B) system call side----						 */
end_comment

begin_comment
comment|/*    1) The user process issues the XIOREAD ioctl with a pi_dblock	 */
end_comment

begin_comment
comment|/*	structure describing the target buffer.				 */
end_comment

begin_comment
comment|/*    2) the piioctl routine using the XIOREAD case calls the routine	 */
end_comment

begin_comment
comment|/*       pi_rem_qdata to get the next data item.  If there are no data	 */
end_comment

begin_comment
comment|/*       items ready then pi_rem_qdata will return -1  and the process	 */
end_comment

begin_comment
comment|/*       will sleep waiting for data to come in.  The wakeup will be done*/
end_comment

begin_comment
comment|/*       in pi_queue_data.  When a data item is dequeued from a channel	 */
end_comment

begin_comment
comment|/*       that is not the supervisor channel then a new read is issued on */
end_comment

begin_comment
comment|/*       that logical circuit.  This means that at most 1 data item will */
end_comment

begin_comment
comment|/*       be present in the input queue for a particular data circuit.    */
end_comment

begin_comment
comment|/*	 This excludes the supervisory circuit 0.			 */
end_comment

begin_comment
comment|/*    3) the pi_rem_qdata routine will dequeue  an mbuf and copy the	 */
end_comment

begin_comment
comment|/*	 data to the user buffer along with other information such as	 */
end_comment

begin_comment
comment|/*	 the lcn and read completions statuses.  If several mbufs were	 */
end_comment

begin_comment
comment|/*	 used to hold a single packet then the entire chain will be	 */
end_comment

begin_comment
comment|/*	 scanned and all the data placed in the user buffer.		 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_include
include|#
directive|include
file|"if_pivar.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../vaxif/if_pivar.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%                   LOCAL  FUNCTIONS                          %%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
name|PRIVATE
name|void
name|pi_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_init_single
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_clear_piq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_clear_single
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_free_all_lcns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_queue_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|pi_rem_qdata
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|pi_find_chan_for_ring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|pi_write
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%                   LOCAL  VARIABLES                          %%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/* PILINES: number of channels (minor device numbers) allocated per board */
end_comment

begin_comment
comment|/* PIQLEN: max number of messages that can be queued for a channel */
end_comment

begin_define
define|#
directive|define
name|PILINES
value|32
end_define

begin_define
define|#
directive|define
name|PIQLEN
value|8
end_define

begin_define
define|#
directive|define
name|NPILINES
value|(NDDA * PILINES)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_decl_stmt
name|int
name|pi_placemark
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PI_PLACEMARK
parameter_list|(
name|n
parameter_list|)
value|(pi_placemark = (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PI_PLACEMARK
parameter_list|(
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the pi_qmem structure is used to hold essential information about  * incomming data until the user process has a chance to issue a read.  * These structures form a queue of input data. All fields should be 0  * when the structure is not actively part of the queue.  */
end_comment

begin_struct
struct|struct
name|pi_qmem
block|{
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
name|u_char
name|stat
decl_stmt|;
name|u_char
name|substat
decl_stmt|;
name|u_char
name|lcn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* the pi_info structure describes a data channel which corresponds to a  * minor device.  The values in the protocols fields are only valid when  * the PI_ACCEPT_RING bit is set in flags.  The 0 element is the lowest  * protocol, The 1 element is the highest.  */
end_comment

begin_struct
struct|struct
name|pi_info
block|{
name|u_short
name|flags
decl_stmt|;
name|u_int
name|pgrp
decl_stmt|;
comment|/* process group */
name|u_int
name|signal
decl_stmt|;
comment|/* signal to use upon data ready */
name|struct
name|mbuf
modifier|*
name|msav
decl_stmt|;
comment|/* place to hang mbuf waiting to go out */
name|struct
name|pi_qmem
name|pi_q
index|[
name|PIQLEN
index|]
decl_stmt|;
comment|/* queue of pending input data */
name|u_char
name|firstq
decl_stmt|,
name|lastq
decl_stmt|;
comment|/* index of first and last queue 					 * members */
name|u_char
name|pi_qlen
decl_stmt|;
comment|/* length of the input queue */
name|u_char
name|protocols
index|[
literal|2
index|]
decl_stmt|;
comment|/* low and high protocol range */
block|}
struct|;
end_struct

begin_comment
comment|/* bits for the flags field */
end_comment

begin_define
define|#
directive|define
name|PI_ACCEPT_RING
value|0x1
end_define

begin_define
define|#
directive|define
name|PI_ACCEPT_ANY
value|0x2
end_define

begin_decl_stmt
name|struct
name|pi_info
name|pi_info
index|[
name|NPILINES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty structures */
end_comment

begin_comment
comment|/* this macro gives the channel (minor device number) associated with  * an active lcn.  */
end_comment

begin_define
define|#
directive|define
name|CHANNEL
parameter_list|(
name|lcn
parameter_list|,
name|ds
parameter_list|)
value|((ds)->dda_cb[(lcn)].dc_line)
end_define

begin_comment
comment|/*  * macro to translate a device number to the unit (i.e. ACP_PI)  * with which it is associated,  M001 use V7 major and minor macros  */
end_comment

begin_define
define|#
directive|define
name|PI_UNIT
parameter_list|(
name|x
parameter_list|)
value|(minor(x) / PILINES)
end_define

begin_comment
comment|/* ACP_PI controlling this line */
end_comment

begin_define
define|#
directive|define
name|PI_LINE
parameter_list|(
name|x
parameter_list|)
value|(minor(x) % PILINES)
end_define

begin_comment
comment|/* Line number */
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%                   GLOBAL ROUTINES                           %%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                       PIIOCTL()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Process ioctl request.                                         */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           piioctl(dev, cmd, data, flag)                  */
end_comment

begin_comment
comment|/*  Argument:       dev:   device                                  */
end_comment

begin_comment
comment|/*                  cmd:   ioctl command                           */
end_comment

begin_comment
comment|/*                  data:  pointer to data                         */
end_comment

begin_comment
comment|/*                  flag:  ignored                                 */
end_comment

begin_comment
comment|/*  Returns:        0 for sucess, else nonzero error code          */
end_comment

begin_comment
comment|/*  Called by:      kernel software software,  this routine is in  */
end_comment

begin_comment
comment|/*                  the cdevsw table                               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|piioctl
argument_list|(
argument|dev
argument_list|,
argument|cmd
argument_list|,
argument|data
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|int
name|l
decl_stmt|,
name|unit
decl_stmt|,
name|maxlcn
decl_stmt|;
name|l
operator|=
name|PI_LINE
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|unit
operator|=
name|PI_UNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|maxlcn
operator|=
name|nddach
index|[
name|unit
index|]
expr_stmt|;
name|ds
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
expr_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|XIOWRITE
case|:
block|{
name|struct
name|pi_dblock
modifier|*
name|pd
decl_stmt|;
name|pd
operator|=
operator|(
expr|struct
name|pi_dblock
operator|*
operator|)
name|data
expr_stmt|;
if|if
condition|(
name|pd
operator|->
name|lcn
operator|>
name|maxlcn
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|66
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"XIOWRITE: invalid lcn %d\n"
operator|,
name|pd
operator|->
name|lcn
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
if|if
condition|(
name|pd
operator|->
name|lcn
operator|&&
operator|(
name|CHANNEL
argument_list|(
name|pd
operator|->
name|lcn
argument_list|,
name|ds
argument_list|)
operator|!=
name|l
operator|)
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|67
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"XIOWRITE: lcn %d not associated with channel %d.\n"
operator|,
name|pd
operator|->
name|lcn
operator|,
name|l
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
return|return
operator|(
name|pi_write
argument_list|(
name|ds
argument_list|,
name|l
argument_list|,
name|pd
argument_list|)
operator|)
return|;
block|}
case|case
name|XIOREAD
case|:
block|{
name|int
name|ret
decl_stmt|;
name|struct
name|pi_dblock
modifier|*
name|pd
decl_stmt|;
name|pd
operator|=
operator|(
expr|struct
name|pi_dblock
operator|*
operator|)
name|data
expr_stmt|;
while|while
condition|(
name|ret
operator|=
name|pi_rem_qdata
argument_list|(
name|l
argument_list|,
name|pd
argument_list|)
condition|)
block|{
if|if
condition|(
name|ret
operator|>
literal|0
condition|)
goto|goto
name|newread
goto|;
elseif|else
if|if
condition|(
name|pd
operator|->
name|flags
operator|&
name|DB_NONBLOCK
condition|)
return|return
operator|(
name|EWOULDBLOCK
operator|)
return|;
comment|/* read already posted */
else|else
block|{
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(r sl) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sleep
argument_list|(
name|pi_info
index|[
name|l
index|]
operator|.
name|pi_q
argument_list|,
name|TTIPRI
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(r wo) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
name|newread
label|:
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(r go) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|pd
operator|->
name|lcn
condition|)
comment|/* issue new read for the lcn */
name|dda_rrq
argument_list|(
name|ds
argument_list|,
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|pd
operator|->
name|lcn
index|]
operator|.
name|dc_rchan
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
case|case
name|XIORPEND
case|:
block|{
name|int
name|s
decl_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|data
operator|)
operator|=
name|pi_info
index|[
name|l
index|]
operator|.
name|pi_qlen
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XIOACCRING
case|:
block|{
name|struct
name|proto_range
modifier|*
name|pr
decl_stmt|;
name|int
name|s
decl_stmt|;
name|pr
operator|=
operator|(
name|proto_range
operator|*
operator|)
name|data
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|pi_info
index|[
name|l
index|]
operator|.
name|flags
operator||=
name|PI_ACCEPT_RING
expr_stmt|;
name|pi_info
index|[
name|l
index|]
operator|.
name|protocols
index|[
literal|0
index|]
operator|=
name|pr
operator|->
name|lower
expr_stmt|;
name|pi_info
index|[
name|l
index|]
operator|.
name|protocols
index|[
literal|1
index|]
operator|=
name|pr
operator|->
name|upper
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XIOANYPROTO
case|:
name|pi_info
index|[
name|l
index|]
operator|.
name|flags
operator||=
name|PI_ACCEPT_ANY
expr_stmt|;
break|break;
case|case
name|XIOFREELCN
case|:
block|{
name|u_char
name|lcn
decl_stmt|;
name|lcn
operator|=
operator|*
operator|(
operator|(
name|u_char
operator|*
operator|)
name|data
operator|)
expr_stmt|;
if|if
condition|(
name|lcn
operator|>
name|maxlcn
condition|)
return|return
name|EINVAL
return|;
name|dc
operator|=
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
expr_stmt|;
if|if
condition|(
name|CHANNEL
argument_list|(
name|lcn
argument_list|,
name|ds
argument_list|)
operator|!=
name|l
condition|)
return|return
name|EINVAL
return|;
else|else
block|{
name|abort_io
argument_list|(
name|unit
argument_list|,
name|lcn
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
name|dc
operator|->
name|dc_line
operator|=
operator|-
literal|1
expr_stmt|;
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* forget address */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
block|}
break|break;
block|}
case|case
name|XIOABORT
case|:
block|{
name|u_char
name|lcn
decl_stmt|;
name|lcn
operator|=
operator|*
operator|(
operator|(
name|u_char
operator|*
operator|)
name|data
operator|)
expr_stmt|;
if|if
condition|(
name|lcn
operator|>
name|maxlcn
condition|)
return|return
name|EINVAL
return|;
name|dc
operator|=
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
expr_stmt|;
if|if
condition|(
name|CHANNEL
argument_list|(
name|lcn
argument_list|,
name|ds
argument_list|)
operator|!=
name|l
condition|)
return|return
name|EINVAL
return|;
else|else
name|abort_io
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|lcn
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|XIOGETLCN
case|:
comment|/* 	 * find a free lcn.  Init the line field for this minor device. stuff 	 * lcn number in struct. init the circuit state.  	 */
if|if
condition|(
name|dc
operator|=
name|find_free_lcn
argument_list|(
name|ds
argument_list|)
condition|)
block|{
name|dc
operator|->
name|dc_flags
operator|=
name|DC_RAW
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_DATA_IDLE
expr_stmt|;
name|dc
operator|->
name|dc_line
operator|=
name|l
expr_stmt|;
operator|*
name|data
operator|=
name|dc
operator|->
name|dc_lcn
expr_stmt|;
block|}
else|else
operator|*
name|data
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|XIOCLRCHAN
case|:
name|pi_clear_piq
argument_list|(
name|ds
argument_list|,
operator|&
name|pi_info
index|[
name|l
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
name|XIONORING
case|:
name|pi_info
index|[
name|l
index|]
operator|.
name|flags
operator|&=
operator|~
operator|(
name|PI_ACCEPT_ANY
operator||
name|PI_ACCEPT_RING
operator|)
expr_stmt|;
break|break;
case|case
name|XIORSIG
case|:
name|pi_info
index|[
name|l
index|]
operator|.
name|signal
operator|=
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|data
operator|)
expr_stmt|;
break|break;
comment|/* case XIOABORTIO: do an abort-io on the channel */
default|default:
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                       PIOPEN()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Open a line.                                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           piopen(dev, flag)                              */
end_comment

begin_comment
comment|/*  Argument:       dev:   device                                  */
end_comment

begin_comment
comment|/*                  flag:  indicates type of open, "nonblocking"   */
end_comment

begin_comment
comment|/*                         "or block if in use"                    */
end_comment

begin_comment
comment|/*  Returns:        0 for success, else nonzero error code         */
end_comment

begin_comment
comment|/*  Called by:      kernel software software,  this routine is in  */
end_comment

begin_comment
comment|/*                  the cdevsw table                               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|piopen
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|unit
decl_stmt|,
name|d
decl_stmt|;
name|unit
operator|=
name|PI_UNIT
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|d
operator|=
name|PI_LINE
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|>=
name|NPILINES
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* wait for interface to come up */
while|while
condition|(
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_state
operator|!=
name|S_LINK_UP
condition|)
name|sleep
argument_list|(
operator|&
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_state
argument_list|,
name|TTIPRI
argument_list|)
expr_stmt|;
if|if
condition|(
name|pi_info
index|[
name|d
index|]
operator|.
name|pgrp
operator|==
literal|0
condition|)
name|pi_info
index|[
name|d
index|]
operator|.
name|pgrp
operator|=
name|u
operator|.
name|u_procp
operator|->
name|p_pid
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                       PICLOSE()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Close a line.                                                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           piclose(dev, flag)                             */
end_comment

begin_comment
comment|/*  Argument:       dev:   device                                  */
end_comment

begin_comment
comment|/*                  flag:  unused                                  */
end_comment

begin_comment
comment|/*  Returns:        nothing                                        */
end_comment

begin_comment
comment|/*  Called by:      kernel software software,  this routine is in  */
end_comment

begin_comment
comment|/*                  the cdevsw table                               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|piclose
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|pi_clear_single
argument_list|(
operator|&
name|dda_softc
index|[
name|PI_UNIT
argument_list|(
name|dev
argument_list|)
index|]
argument_list|,
operator|&
name|pi_info
index|[
name|PI_LINE
argument_list|(
name|dev
argument_list|)
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pi_free_all_lcns
argument_list|(
name|PI_UNIT
argument_list|(
name|dev
argument_list|)
argument_list|,
name|PI_LINE
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%                   LOCAL  FUNCTIONS                          %%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      PI_SUPR()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*       This routine processes received supervisor messages.      */
end_comment

begin_comment
comment|/*       Depending on the message type, the appropriate action is  */
end_comment

begin_comment
comment|/*       taken.                                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              pi_supr(ds, mb)                             */
end_comment

begin_comment
comment|/*  Arguments:         ds:  pointer to dev control block struct    */
end_comment

begin_comment
comment|/*                     mb:  pointer to mbuf 			   */
end_comment

begin_comment
comment|/*                              containing the supervisor message  */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         dda_supr()                                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_supr
parameter_list|(
name|ds
parameter_list|,
name|mb
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
block|{
name|u_char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
specifier|register
name|int
name|chan
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|unit
operator|=
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) pi_supr()\n"
operator|,
name|unit
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|p
operator|=
name|mtod
argument_list|(
name|mb
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|p
index|[
literal|0
index|]
condition|)
block|{
case|case
name|LINE_STATUS
case|:
comment|/* link status msg */
case|case
name|RESTART
case|:
comment|/* restart received */
case|case
name|RSTRT_ACK
case|:
comment|/* restart ack */
case|case
name|STATRESP
case|:
comment|/* Statistics Response from FEP */
case|case
name|CLEARVC
case|:
comment|/* clear by VCN */
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|64
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) pi_supr: unexpected msg type 0x%x\n"
operator|,
name|unit
operator|,
name|p
index|[
literal|0
index|]
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RING
case|:
comment|/* incoming call */
if|if
condition|(
operator|(
name|chan
operator|=
name|pi_find_chan_for_ring
argument_list|(
name|p
argument_list|)
operator|)
operator|>=
literal|0
condition|)
name|pi_queue_data
argument_list|(
name|unit
argument_list|,
name|chan
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|mb
argument_list|)
expr_stmt|;
else|else
comment|/* if no willing channel's */
block|{
comment|/* reject the call */
name|send_supr
argument_list|(
name|ds
argument_list|,
name|CLEARVC
argument_list|,
name|p
index|[
literal|2
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* clear call */
if|if
condition|(
name|LOG_CALLS
condition|)
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) Call REJECTED VC 0x%x\n"
operator|,
name|unit
operator|,
name|p
index|[
literal|1
index|]
name|DDAELOG
expr_stmt|;
block|}
break|break;
case|case
name|ANSWER
case|:
comment|/* call answered */
case|case
name|CLEARLC
case|:
comment|/* clear by LCN */
case|case
name|RESET
case|:
comment|/* X25 reset */
case|case
name|INTERRUPT
case|:
comment|/* X25 interrupt */
case|case
name|INTR_ACK
case|:
name|lcn
operator|=
name|p
index|[
literal|1
index|]
operator|/
literal|2
expr_stmt|;
comment|/* get LCN */
name|pi_queue_data
argument_list|(
name|unit
argument_list|,
name|CHANNEL
argument_list|(
name|lcn
argument_list|,
name|ds
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|mb
argument_list|)
expr_stmt|;
break|break;
default|default:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|65
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) supervisor error (%x %x %x %x)\n"
operator|,
name|unit
operator|,
name|p
index|[
literal|0
index|]
operator|,
name|p
index|[
literal|1
index|]
operator|,
name|p
index|[
literal|2
index|]
operator|,
name|p
index|[
literal|3
index|]
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                       PI_DATA()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    This routine is called when a data channel I/O completes.    */
end_comment

begin_comment
comment|/*    If the completion was for a write, an attempt is made to     */
end_comment

begin_comment
comment|/*    start output on the next packet waiting for output on that   */
end_comment

begin_comment
comment|/*    LCN.  If the completion was for a read, the received packet  */
end_comment

begin_comment
comment|/*    is sent to the pi input queue (if no error).                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              pi_data(ds, hc, cc, cnt, subcc)             */
end_comment

begin_comment
comment|/*  Argument:          ds:  device control block                   */
end_comment

begin_comment
comment|/*                     hc:  half duplex channel control block      */
end_comment

begin_comment
comment|/*                     cc:   Mailbox I/O completion status         */
end_comment

begin_comment
comment|/*                     cnt:  byte count                            */
end_comment

begin_comment
comment|/*		       subcc: Mailbox I/O completion substatus     */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddainta()                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_data
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|cc
parameter_list|,
name|cnt
parameter_list|,
name|subcc
parameter_list|)
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
name|int
name|cc
decl_stmt|,
name|cnt
decl_stmt|,
name|subcc
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
init|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|hc
operator|->
name|hc_chan
operator|/
literal|2
index|]
operator|)
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|unit
operator|=
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|18
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) pi_data: chan=0x%x  cc=0x%x  cnt=0x%x subcc=0x%x\n"
operator|,
name|unit
operator|,
name|hc
operator|->
name|hc_chan
operator|,
name|cc
operator|,
name|cnt
operator|,
name|subcc
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(dt"
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|hc
operator|->
name|hc_chan
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|cc
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|cnt
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|0x01
condition|)
comment|/* was it read or write? */
block|{
comment|/* write, fire up next output */
ifdef|#
directive|ifdef
name|DDADEBUG
name|dc
operator|->
name|dc_out_t
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn off output completion timer */
endif|#
directive|endif
if|if
condition|(
operator|(
name|hc
operator|->
name|hc_func
operator|!=
name|DDAABT
operator|)
operator|&&
operator|(
name|hc
operator|->
name|hc_curr
operator|=
name|hc
operator|->
name|hc_curr
operator|->
name|m_next
operator|)
condition|)
name|dda_wrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
block|{
name|m_freem
argument_list|(
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_func
operator|==
name|DDAABT
condition|)
block|{
name|hc
operator|->
name|hc_func
operator|&=
operator|~
name|DDAABT
expr_stmt|;
name|hc
operator|->
name|hc_sbfc
operator|&=
operator|~
name|INVALID_MBUF
expr_stmt|;
block|}
else|else
name|ds
operator|->
name|dda_if
operator|.
name|if_opackets
operator|++
expr_stmt|;
name|dc
operator|->
name|dc_flags
operator|&=
operator|~
name|DC_OBUSY
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(w wa) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wakeup
argument_list|(
operator|&
operator|(
name|dc
operator|->
name|dc_oq
operator|)
argument_list|)
expr_stmt|;
comment|/* wake up anyone sleeping on output */
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/* and try to output */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* reset timer */
block|}
block|}
else|else
comment|/* read, process rcvd packet */
block|{
ifdef|#
directive|ifdef
name|DDADEBUG
ifdef|#
directive|ifdef
name|notdef
if|if
condition|(
name|DDADBCH
argument_list|(
literal|19
argument_list|,
name|unit
argument_list|)
condition|)
block|{
name|u_char
modifier|*
name|p
decl_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) "
operator|,
name|unit
name|DDAELOG
expr_stmt|;
name|p
operator|=
name|mtod
argument_list|(
name|hc
operator|->
name|hc_curr
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
name|p
argument_list|,
operator|(
name|cnt
operator|<
literal|56
condition|?
name|cnt
else|:
literal|56
operator|)
argument_list|)
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"\n"
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
name|cc
operator|==
name|DDAIOCOK
condition|)
block|{
comment|/* Queue good packet for input */
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|+=
name|cnt
expr_stmt|;
comment|/* update byte count */
name|ds
operator|->
name|dda_if
operator|.
name|if_ipackets
operator|++
expr_stmt|;
name|pi_queue_data
argument_list|(
name|unit
argument_list|,
name|dc
operator|->
name|dc_line
argument_list|,
name|dc
operator|->
name|dc_lcn
argument_list|,
name|cc
argument_list|,
name|subcc
argument_list|,
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cc
operator|==
name|DDAIOCOKP
condition|)
comment|/* more data pending in this packet */
block|{
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|+=
name|cnt
expr_stmt|;
comment|/* update byte count */
name|dda_rrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_freem
argument_list|(
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dda_rrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|)
expr_stmt|;
block|}
comment|/* don't hang new data read.  This is done in the user read ioctl */
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                       PI_INIT()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This function initializes the pi_info structure.  The      */
end_comment

begin_comment
comment|/*	active flag is non-zero if the interface is active and got */
end_comment

begin_comment
comment|/*	a reset.  In this case pi_clear_single is called which     */
end_comment

begin_comment
comment|/*	free any resources held and send a hangup to the           */
end_comment

begin_comment
comment|/*	controlling process.                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_init(unit, active)                          */
end_comment

begin_comment
comment|/*  Argument:       unit: unit to be initialized.                  */
end_comment

begin_comment
comment|/*                  active: non-zero if the interface is active    */
end_comment

begin_comment
comment|/*                          when the reset is issued.              */
end_comment

begin_comment
comment|/*  Returns:        nothing.                                       */
end_comment

begin_comment
comment|/*  Called by:      ddareset(), ddainit(), bufreset().             */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_init
parameter_list|(
name|unit
parameter_list|,
name|active
parameter_list|)
name|int
name|unit
decl_stmt|;
name|int
name|active
decl_stmt|;
block|{
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|ds
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
expr_stmt|;
name|end
operator|=
name|pi_info
operator|+
operator|(
operator|(
name|unit
operator|+
literal|1
operator|)
operator|*
name|PILINES
operator|)
expr_stmt|;
for|for
control|(
name|pi
operator|=
name|end
operator|-
name|PILINES
init|;
name|pi
operator|<
name|end
condition|;
name|pi
operator|++
control|)
if|if
condition|(
name|active
condition|)
name|pi_clear_single
argument_list|(
name|ds
argument_list|,
name|pi
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|pi_init_single
argument_list|(
name|pi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                    PI_INIT_SINGLE()                         %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	Initialize a pi_info structure.  For now all this means is */
end_comment

begin_comment
comment|/*	zeroing out everything.	This routine is here to make future*/
end_comment

begin_comment
comment|/*	enhancements easier.				           */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_init_single (pi)                            */
end_comment

begin_comment
comment|/*  Argument:       pi: pointer to pi_info structure               */
end_comment

begin_comment
comment|/*  Returns:        nothing.                                       */
end_comment

begin_comment
comment|/*  Called by:      pi_init(), pi_clear_single().                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_init_single
parameter_list|(
name|pi
parameter_list|)
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
block|{
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pi
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pi_info
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                 PI_CLEAR_PIQ()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This routine will free up all the mbufs that are queued on */
end_comment

begin_comment
comment|/*	the pi_q.  Note that this routine assumes that any pi_q    */
end_comment

begin_comment
comment|/*	element is zeroed when not in use.  			   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  IMPORTANT: this routine reissues reads for all the lcn         */
end_comment

begin_comment
comment|/*	whose data is removed from the queue.  This parallels what */
end_comment

begin_comment
comment|/*	is done when the data is dequeue normally by XIOREAD       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_clear_piq (ds, pi)                          */
end_comment

begin_comment
comment|/*  Argument:       ds: pointer to softc used to call dda_rrq.     */
end_comment

begin_comment
comment|/*                  pi: pointer to pi_info structure.              */
end_comment

begin_comment
comment|/*  Returns:        nothing                                        */
end_comment

begin_comment
comment|/*  Called by:      pi_clear_single(), piioctl() case XIOCLRCHAN   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_clear_piq
parameter_list|(
name|ds
parameter_list|,
name|pi
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|PIQLEN
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|pi
operator|->
name|pi_q
index|[
name|i
index|]
operator|.
name|mb
condition|)
block|{
name|m_freem
argument_list|(
name|pi
operator|->
name|pi_q
index|[
name|i
index|]
operator|.
name|mb
argument_list|)
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|pi_q
index|[
name|i
index|]
operator|.
name|lcn
condition|)
comment|/* issue new read for the lcn */
name|dda_rrq
argument_list|(
name|ds
argument_list|,
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|pi
operator|->
name|pi_q
index|[
name|i
index|]
operator|.
name|lcn
index|]
operator|.
name|dc_rchan
argument_list|)
expr_stmt|;
block|}
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pi
operator|->
name|pi_q
argument_list|,
sizeof|sizeof
argument_list|(
name|pi
operator|->
name|pi_q
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|->
name|pi_qlen
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                  PI_CLEAR_SINGLE()                          %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	this routine will re-initialize a single pi_info structure.*/
end_comment

begin_comment
comment|/*	If hangup is non-zero then a hangup signal will be sent to */
end_comment

begin_comment
comment|/*	the controlling process.                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_clear_single (ds, pi, hangup)               */
end_comment

begin_comment
comment|/*  Argument:       ds: pointer to dda_softc structure             */
end_comment

begin_comment
comment|/*                  pi: pointer to pi_info structure               */
end_comment

begin_comment
comment|/*                  hangup: non-zero if hangup is to be sent.      */
end_comment

begin_comment
comment|/*  Returns:        nothing.                                       */
end_comment

begin_comment
comment|/*  Called by:      piclose(), pi_init().                          */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/* reset a pi_info structure that is active.  This includes freeing any  * queue mbufs and sending a hangup to the controlling process  */
end_comment

begin_function
name|PRIVATE
name|void
name|pi_clear_single
parameter_list|(
name|ds
parameter_list|,
name|pi
parameter_list|,
name|hangup
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
name|int
name|hangup
decl_stmt|;
comment|/* non-zero if a hangup is to be sent to 				 * controlling process */
block|{
name|pi_clear_piq
argument_list|(
name|ds
argument_list|,
name|pi
argument_list|)
expr_stmt|;
if|if
condition|(
name|hangup
operator|&&
name|pi
operator|->
name|pgrp
condition|)
block|{
name|gsignal
argument_list|(
name|pi
operator|->
name|pgrp
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
name|gsignal
argument_list|(
name|pi
operator|->
name|pgrp
argument_list|,
name|SIGCONT
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pi
operator|->
name|msav
condition|)
name|m_freem
argument_list|(
name|pi
operator|->
name|msav
argument_list|)
expr_stmt|;
name|pi_init_single
argument_list|(
name|pi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                 PI_FREE_ALL_LCNS ()                         %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	this routine will free all logical circuits associated with*/
end_comment

begin_comment
comment|/*	a particular channel.  This should return all mbufs that   */
end_comment

begin_comment
comment|/*	Are used by the channel.                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_free_all_lcns (unit,chan)                   */
end_comment

begin_comment
comment|/*  Argument:       chan: channel number.                          */
end_comment

begin_comment
comment|/*		    unit: unit number.                             */
end_comment

begin_comment
comment|/*  Returns:        nothing.                                       */
end_comment

begin_comment
comment|/*  Called by:      piclose()                                      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_free_all_lcns
parameter_list|(
name|unit
parameter_list|,
name|chan
parameter_list|)
name|int
name|unit
decl_stmt|;
name|int
name|chan
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|maxlcn
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|maxlcn
operator|=
name|nddach
index|[
name|unit
index|]
expr_stmt|;
name|dc
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_cb
index|[
literal|1
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|maxlcn
condition|;
name|i
operator|++
operator|,
name|dc
operator|++
control|)
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_RAW
operator|)
operator|&&
name|dc
operator|->
name|dc_line
operator|==
name|chan
condition|)
block|{
name|abort_io
argument_list|(
name|unit
argument_list|,
name|dc
operator|->
name|dc_lcn
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
name|dc
operator|->
name|dc_line
operator|=
operator|-
literal|1
expr_stmt|;
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* forget address */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                   PI_QUEUE_DATA()                           %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This routine queue up supervisory and data messages.  This */
end_comment

begin_comment
comment|/*	messages will be dequeued when the user does a read using  */
end_comment

begin_comment
comment|/*	the XIOREAD ioctl.  If the user tried to do a read and no  */
end_comment

begin_comment
comment|/*	data was ready then the process sleeps on pi_info[chan]pi_q*/
end_comment

begin_comment
comment|/*      This routine wakes up any of the sleeping processes.       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_queue_data( unit, chan, lcn, cc, subcc, mb) */
end_comment

begin_comment
comment|/*  Argument:       unit: unit number (board)                      */
end_comment

begin_comment
comment|/*                  chan: channel for the data to be queue on      */
end_comment

begin_comment
comment|/*		    lcn: the lcn that the data came in on          */
end_comment

begin_comment
comment|/*		    cc: the read completion status from the mailbox*/
end_comment

begin_comment
comment|/*		    subcc: the read completion substatus           */
end_comment

begin_comment
comment|/*		    mb: pointer to the mbuf (or mbuf chain) that   */
end_comment

begin_comment
comment|/*		        contains the data packet.                  */
end_comment

begin_comment
comment|/*  Returns:        0 for success, else nonzero error code         */
end_comment

begin_comment
comment|/*  Called by:      pi_data(), pi_supr().                          */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|pi_queue_data
parameter_list|(
name|unit
parameter_list|,
name|chan
parameter_list|,
name|lcn
parameter_list|,
name|cc
parameter_list|,
name|subcc
parameter_list|,
name|mb
parameter_list|)
name|int
name|unit
decl_stmt|;
name|int
name|chan
decl_stmt|;
name|int
name|lcn
decl_stmt|;
name|int
name|cc
decl_stmt|;
name|int
name|subcc
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
block|{
name|int
name|s
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
name|struct
name|pi_qmem
modifier|*
name|pq
decl_stmt|;
if|if
condition|(
name|chan
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* invalid channel */
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|68
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) data queue on dead channel: lcn %d\n"
operator|,
name|unit
operator|,
name|lcn
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
comment|/* don't do it, otherwise panic! */
block|}
name|pi
operator|=
operator|&
name|pi_info
index|[
name|chan
index|]
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|pi_qlen
operator|==
name|PIQLEN
condition|)
comment|/* overflow */
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|68
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:(pi) Data queue full, message dropped  chan %d lcn %d\n"
operator|,
name|unit
operator|,
name|chan
operator|,
name|lcn
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|mb
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
name|pi
operator|->
name|pi_qlen
operator|++
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|lastq
operator|==
operator|(
name|PIQLEN
operator|-
literal|1
operator|)
condition|)
name|pi
operator|->
name|lastq
operator|=
literal|0
expr_stmt|;
else|else
name|pi
operator|->
name|lastq
operator|++
expr_stmt|;
name|pq
operator|=
operator|&
name|pi
operator|->
name|pi_q
index|[
name|pi
operator|->
name|lastq
index|]
expr_stmt|;
name|pq
operator|->
name|mb
operator|=
name|mb
expr_stmt|;
name|pq
operator|->
name|lcn
operator|=
name|lcn
expr_stmt|;
name|pq
operator|->
name|stat
operator|=
name|cc
expr_stmt|;
name|pq
operator|->
name|substat
operator|=
name|subcc
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(r wa) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|wakeup
argument_list|(
name|pi
operator|->
name|pi_q
argument_list|)
expr_stmt|;
comment|/* wakeup any sleepers */
if|if
condition|(
name|pi
operator|->
name|signal
condition|)
name|gsignal
argument_list|(
name|pi
operator|->
name|pgrp
argument_list|,
name|pi
operator|->
name|signal
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                     PI_REM_QDATA()                          %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	Remove a data item from the input queue and copy the       */
end_comment

begin_comment
comment|/*	information to the user pi_dblock structure that was       */
end_comment

begin_comment
comment|/*	passed to the XIOREAD case in piioctl.                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_rem_qdata(chan, dblk)                       */
end_comment

begin_comment
comment|/*  Argument:       chan: index of the channel to read.            */
end_comment

begin_comment
comment|/*                  dblk: pointer to user pi_dblock.               */
end_comment

begin_comment
comment|/*  Returns:        -1 if the input queue is empty.                */
end_comment

begin_comment
comment|/*                  0 if pi_dblock was filled in successfully.     */
end_comment

begin_comment
comment|/*		    error code if there was an error filling in    */
end_comment

begin_comment
comment|/*		       the pi_dblock.				   */
end_comment

begin_comment
comment|/*  Called by:      piioctl()                                      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|pi_rem_qdata
parameter_list|(
name|chan
parameter_list|,
name|dblk
parameter_list|)
name|int
name|chan
decl_stmt|;
name|struct
name|pi_dblock
modifier|*
name|dblk
decl_stmt|;
block|{
name|int
name|s
decl_stmt|,
name|cnt
init|=
literal|0
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
name|struct
name|pi_qmem
modifier|*
name|pq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|,
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|usrdata
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|pi
operator|=
operator|&
name|pi_info
index|[
name|chan
index|]
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|pi_qlen
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
else|else
name|pi
operator|->
name|pi_qlen
operator|--
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|firstq
operator|==
operator|(
name|PIQLEN
operator|-
literal|1
operator|)
condition|)
name|pi
operator|->
name|firstq
operator|=
literal|0
expr_stmt|;
else|else
name|pi
operator|->
name|firstq
operator|++
expr_stmt|;
name|pq
operator|=
operator|&
name|pi
operator|->
name|pi_q
index|[
name|pi
operator|->
name|firstq
index|]
expr_stmt|;
name|mb
operator|=
name|pq
operator|->
name|mb
expr_stmt|;
name|dblk
operator|->
name|func
operator|=
name|pq
operator|->
name|stat
expr_stmt|;
name|dblk
operator|->
name|subfunc
operator|=
name|pq
operator|->
name|substat
expr_stmt|;
name|dblk
operator|->
name|lcn
operator|=
name|pq
operator|->
name|lcn
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pq
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pq
argument_list|)
argument_list|)
expr_stmt|;
comment|/* zero the structure out */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
for|for
control|(
name|m
operator|=
name|mb
operator|,
name|usrdata
operator|=
name|dblk
operator|->
name|dataptr
init|;
name|m
condition|;
name|m
operator|=
name|m
operator|->
name|m_next
control|)
block|{
if|if
condition|(
name|dblk
operator|->
name|length
operator|<
name|cnt
operator|+
name|m
operator|->
name|m_len
condition|)
block|{
name|error
operator|=
name|EINVAL
expr_stmt|;
goto|goto
name|out
goto|;
block|}
if|if
condition|(
name|copyout
argument_list|(
name|mtod
argument_list|(
name|m
argument_list|,
name|char
operator|*
argument_list|)
argument_list|,
name|usrdata
argument_list|,
name|m
operator|->
name|m_len
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|out
goto|;
block|}
name|cnt
operator|+=
name|m
operator|->
name|m_len
expr_stmt|;
name|usrdata
operator|+=
name|m
operator|->
name|m_len
expr_stmt|;
block|}
name|out
label|:
name|dblk
operator|->
name|length
operator|=
name|cnt
expr_stmt|;
name|m_freem
argument_list|(
name|mb
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%               PI_FIND_CHAN_FOR_RING()                       %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This routine picks a channel to handle a ring.  It uses    */
end_comment

begin_comment
comment|/*	a static int (lastchan) to remember where it left off      */
end_comment

begin_comment
comment|/*	during the last search.  This will prevent it from always  */
end_comment

begin_comment
comment|/*	picking the same channel if there is more than 1 channel   */
end_comment

begin_comment
comment|/*	willing to accept the call.  If no channel is willing to   */
end_comment

begin_comment
comment|/*	accept the protocol type then it will go to a channel that */
end_comment

begin_comment
comment|/*	has indicated that it will accept any protocol type.       */
end_comment

begin_comment
comment|/* 	Note that the ring will not be given to a channel that     */
end_comment

begin_comment
comment|/*	has a full input queue.					   */
end_comment

begin_comment
comment|/*      This routine should be called a interrupt level.           */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_find_chan_for_ring (p)                      */
end_comment

begin_comment
comment|/*  Argument:       p: pointer to data containg the ring packet.   */
end_comment

begin_comment
comment|/*  Returns:        index of a channel willing to accept the call. */
end_comment

begin_comment
comment|/*                  -1 is return if no channel can accept          */
end_comment

begin_comment
comment|/*  Called by:      pi_supr()                                      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|pi_find_chan_for_ring
parameter_list|(
name|p
parameter_list|)
name|u_char
name|p
index|[]
decl_stmt|;
comment|/* p is a pointer to a ring packet */
block|{
specifier|register
name|u_char
modifier|*
name|cp
decl_stmt|;
name|int
name|i
decl_stmt|,
name|proto
decl_stmt|,
name|anychan
init|=
operator|-
literal|1
decl_stmt|;
specifier|static
name|int
name|lastchan
init|=
literal|0
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
name|cp
operator|=
name|p
operator|+
literal|4
expr_stmt|;
comment|/* skip over code, lcn, vcn and count in 				 * answer message */
comment|/* cp now points to length of called address */
name|cp
operator|+=
operator|*
name|cp
operator|+
literal|1
expr_stmt|;
comment|/* skip over called address and length byte */
comment|/* cp now points to length of calling address */
name|cp
operator|+=
operator|*
name|cp
operator|+
literal|1
expr_stmt|;
comment|/* skip over calling address and length byte */
comment|/* cp now points to length of protocol */
if|if
condition|(
operator|*
name|cp
operator|++
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|proto
operator|=
operator|*
name|cp
expr_stmt|;
name|i
operator|=
name|lastchan
expr_stmt|;
do|do
block|{
name|i
operator|=
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|NPILINES
expr_stmt|;
name|pi
operator|=
operator|&
name|pi_info
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|pi
operator|->
name|flags
operator|&
name|PI_ACCEPT_RING
condition|)
block|{
if|if
condition|(
name|proto
operator|>=
name|pi
operator|->
name|protocols
index|[
literal|0
index|]
operator|&&
name|proto
operator|<=
name|pi
operator|->
name|protocols
index|[
literal|1
index|]
operator|&&
name|pi
operator|->
name|pi_qlen
operator|<
name|PIQLEN
condition|)
block|{
name|lastchan
operator|=
name|i
expr_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
block|}
if|if
condition|(
operator|(
name|pi
operator|->
name|flags
operator|&
name|PI_ACCEPT_ANY
operator|)
operator|&&
name|anychan
operator|==
operator|-
literal|1
operator|&&
name|pi
operator|->
name|pi_qlen
operator|<
name|PIQLEN
condition|)
name|anychan
operator|=
name|i
expr_stmt|;
block|}
do|while
condition|(
name|i
operator|!=
name|lastchan
condition|)
do|;
if|if
condition|(
name|anychan
operator|>=
literal|0
condition|)
name|lastchan
operator|=
name|anychan
expr_stmt|;
return|return
operator|(
name|anychan
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%          PI_CIRCUIT_TO_HANDLE_PROTOCOL()                    %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This routine find out if there is a pi channel that is     */
end_comment

begin_comment
comment|/*	willing to accept a particular protocol.  This is needed   */
end_comment

begin_comment
comment|/*	because the PI interface has precedence over IP and X.29   */
end_comment

begin_comment
comment|/*	interfaces.  This routine is called before the data is     */
end_comment

begin_comment
comment|/*	passed to one of the interfaces.			   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           pi_circuit_to_handle_protocol(proto)           */
end_comment

begin_comment
comment|/*  Argument:       proto: protocol byte to check.                 */
end_comment

begin_comment
comment|/*  Returns:        1 if PI interface will handle the call.        */
end_comment

begin_comment
comment|/*		    0 otherwise.				   */
end_comment

begin_comment
comment|/*  Called by:      dda_decode_type().                             */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|pi_circuit_to_handle_protocol
parameter_list|(
name|proto
parameter_list|)
name|u_char
name|proto
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|struct
name|pi_info
modifier|*
name|pi
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|pi
operator|=
name|pi_info
init|;
name|i
operator|<
name|NPILINES
condition|;
name|i
operator|++
operator|,
name|pi
operator|++
control|)
block|{
if|if
condition|(
name|pi
operator|->
name|flags
operator|&
name|PI_ACCEPT_RING
condition|)
if|if
condition|(
name|proto
operator|>=
name|pi
operator|->
name|protocols
index|[
literal|0
index|]
operator|&&
name|proto
operator|<=
name|pi
operator|->
name|protocols
index|[
literal|1
index|]
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      PI_WRITE()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*	This routine copies user data to an mbuf and queue the     */
end_comment

begin_comment
comment|/*	mbuf to go out.  The process will sleep if the output      */
end_comment

begin_comment
comment|/*	queue is full.   If the non-block bit is set then the      */
end_comment

begin_comment
comment|/*	process will not sleep and EWOULDBLOCK is returned.        */
end_comment

begin_comment
comment|/*      The last  byte of the built in data area for the mbuf      */
end_comment

begin_comment
comment|/*      is used to store the subfunction byte.  This byte is then  */
end_comment

begin_comment
comment|/*	put in the comregs by start_chn when it sees that this is  */
end_comment

begin_comment
comment|/*	a write for a RAW circuit.                                 */
end_comment

begin_comment
comment|/*								   */
end_comment

begin_comment
comment|/*  Call:           pi_write (ds, l, dblk)                         */
end_comment

begin_comment
comment|/*  Argument:       ds : pointer to dda_softc structure            */
end_comment

begin_comment
comment|/*                  l  : the channel (minor device) number         */
end_comment

begin_comment
comment|/*		    dblk : pointer to the pi_dblock for user data  */
end_comment

begin_comment
comment|/*  Returns:        0 for success, else nonzero error code         */
end_comment

begin_comment
comment|/*  Called by:      piioctl.                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|pi_write
parameter_list|(
name|ds
parameter_list|,
name|l
parameter_list|,
name|dblk
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|int
name|l
decl_stmt|;
name|struct
name|pi_dblock
modifier|*
name|dblk
decl_stmt|;
block|{
specifier|register
name|int
name|length
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|struct
name|ifqueue
modifier|*
name|oq
decl_stmt|;
name|int
name|s
decl_stmt|,
name|unit
decl_stmt|;
name|length
operator|=
name|dblk
operator|->
name|length
expr_stmt|;
name|unit
operator|=
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
expr_stmt|;
if|if
condition|(
name|length
operator|<=
literal|0
operator|||
name|length
operator|>
name|CLBYTES
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|69
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"XIOWRITE: invalid length %d.\n"
operator|,
name|length
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|m
operator|=
literal|0
expr_stmt|;
name|MGET
argument_list|(
name|m
argument_list|,
name|M_WAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|70
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"XIOWRITE: could not get small mbuf\n"
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
if|if
condition|(
name|length
operator|>
operator|(
name|MLEN
operator|-
literal|1
operator|)
condition|)
block|{
if|#
directive|if
name|ACC_ULTRIX
operator|>
literal|12
name|struct
name|mbuf
modifier|*
name|p
decl_stmt|;
name|MCLGET
argument_list|(
name|m
argument_list|,
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
else|#
directive|else
name|MCLGET
argument_list|(
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|->
name|m_len
operator|!=
name|CLBYTES
condition|)
endif|#
directive|endif
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|71
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"XIOWRITE: could not get page cluster\n"
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
block|}
name|cp
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|copyin
argument_list|(
name|dblk
operator|->
name|dataptr
argument_list|,
name|cp
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return
operator|(
name|EFAULT
operator|)
return|;
block|}
name|m
operator|->
name|m_len
operator|=
name|length
expr_stmt|;
if|if
condition|(
name|length
operator|<
operator|(
name|MLEN
operator|-
literal|1
operator|)
condition|)
name|m
operator|->
name|m_dat
index|[
name|MLEN
operator|-
literal|1
index|]
operator|=
name|dblk
operator|->
name|subfunc
expr_stmt|;
comment|/* store subfunction in last byte */
name|dc
operator|=
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|dblk
operator|->
name|lcn
index|]
expr_stmt|;
name|oq
operator|=
operator|&
operator|(
name|dc
operator|->
name|dc_oq
operator|)
expr_stmt|;
comment|/* point to output queue */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
while|while
condition|(
name|IF_QFULL
argument_list|(
name|oq
argument_list|)
condition|)
comment|/* if q full */
block|{
if|if
condition|(
name|dblk
operator|->
name|flags
operator|&
name|DB_NONBLOCK
condition|)
block|{
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|EWOULDBLOCK
operator|)
return|;
block|}
else|else
block|{
comment|/* 	     * note that we save the mbuf here.  It may happen that the 	     * process dies in its sleep and we need a way to recover the 	     * allocated mbuf  	     */
name|pi_info
index|[
name|l
index|]
operator|.
name|msav
operator|=
name|m
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(w sl) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sleep
argument_list|(
operator|&
operator|(
name|dc
operator|->
name|dc_oq
operator|)
argument_list|,
name|TTIPRI
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(w wo) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(w go) "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|IF_ENQUEUE
argument_list|(
name|oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* otherwise queue it */
name|pi_info
index|[
name|l
index|]
operator|.
name|msav
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/* and try to output */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* reset timer */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  Revision History:  13-Jul-89 PST	Modified LOCAL_VOIDs and statics to PRIVATE.  18-Jul-89 PST	Moved dc_key.ttyline out of union, creating dc_line.  26-Jul-89 PST	Replaced kernel printfs with DDALOG calls.  16-Aug-89 PST	Fixed DMESG macros.  29-Oct-89 PST	Fixed off-by-one errors where user could allocate but not 		use last LCN.  (Fix from brad@invector)  */
end_comment

end_unit

