begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	 ________________________________________________________	 */
end_comment

begin_comment
comment|/*	/							 \	 */
end_comment

begin_comment
comment|/*     |	  AAA	       CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*     |	 AAAAA	      CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     |	AAAAAAA	      CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC		CCCC		  |	 */
end_comment

begin_comment
comment|/*     |   AAAA	 AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |	 */
end_comment

begin_comment
comment|/*     |  AAAA	  AAAAAAAAAAA CCCCCCCCCCCCCCCC	CCCCCCCCCCCCCCCC  |	 */
end_comment

begin_comment
comment|/*     | AAAA	   AAAAAAAAA   CCCCCCCCCCCCCC	 CCCCCCCCCCCCCC	  |	 */
end_comment

begin_comment
comment|/*	\________________________________________________________/	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	Copyright (c) 1986 by Advanced Computer Communications		 */
end_comment

begin_comment
comment|/*	720 Santa Barbara Street, Santa Barbara, California  93101	 */
end_comment

begin_comment
comment|/*	(805) 963-9431							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  File:		if_dda.c					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Project:		DDN-X.25 Network Interface Driver for ACP 5250	 */
end_comment

begin_comment
comment|/*			and ACP 6250					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Function:		This is a network interface driver supporting	 */
end_comment

begin_comment
comment|/*			the ACP5250/6250 under UNIX versions 4.2, 4.3,	 */
end_comment

begin_comment
comment|/*			4.3-tahoe, Ultrix versions 1.2 and 2.0, and	 */
end_comment

begin_comment
comment|/*			under VMS,  TWG WIN/VX and TGV Multinet.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Components:		required: if_dda.c, if_ddareg.h, if_ddavar.h,	 */
end_comment

begin_comment
comment|/*			  and one of: if_dda_uqbus.c if_dda_bibus.c	 */
end_comment

begin_comment
comment|/*			optional: if_pi.c, if_pivar.h, if_x29.c,	 */
end_comment

begin_comment
comment|/*				  if_vmsx29.c				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"dda.h"
end_include

begin_if
if|#
directive|if
name|NDDA
operator|>
literal|0
end_if

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%		       SYSTEM CONFIGURATION			 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACC_ULTRIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACC_BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACC_VMS
argument_list|)
end_if

begin_expr_stmt
name|ERROR
name|an
name|ACC
name|OS
name|specific
name|option
name|must
name|be
name|defined
name|in
name|your
name|config
name|file
name|ERROR
endif|#
directive|endif
comment|/*  *	now define the un-set options to zero  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACC_ULTRIX
argument_list|)
define|#
directive|define
name|ACC_ULTRIX
value|00
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACC_BSD
argument_list|)
define|#
directive|define
name|ACC_BSD
value|00
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACC_VMS
argument_list|)
define|#
directive|define
name|ACC_VMS
value|00
endif|#
directive|endif
comment|/*  * the define DDA_MSGQ enables the message queue.  this adds 2k to the  * data size of the driver.  It should only be used during driver development  */
comment|/*#define DDA_MSGQ		/* uncomment this to enable message queue */
comment|/*  * The following line disables the use of the histogram facilities.  This  * value (DDA_HISTOGRAM) is automatically undefined for all 4.2 and ULTRIX  * 1.2 systems which do not support the histogram facilities.  */
define|#
directive|define
name|DDA_HISTOGRAM
comment|/* comment this out to disable histogram */
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
comment|/*%%								 %%*/
comment|/*%%		       INCLUDE FILES				 %%*/
comment|/*%%								 %%*/
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
ifndef|#
directive|ifndef
name|SIMULATION
comment|/* real unix system */
include|#
directive|include
file|"../machine/pte.h"
comment|/* page table entries */
include|#
directive|include
file|"../h/param.h"
include|#
directive|include
file|"../h/systm.h"
include|#
directive|include
file|"../h/mbuf.h"
include|#
directive|include
file|"../h/buf.h"
include|#
directive|include
file|"../h/protosw.h"
include|#
directive|include
file|"../h/socket.h"
include|#
directive|include
file|"../h/vmmac.h"
include|#
directive|include
file|"../h/errno.h"
include|#
directive|include
file|"../h/dir.h"
include|#
directive|include
file|"../h/user.h"
include|#
directive|include
file|"../h/kernel.h"
include|#
directive|include
file|"../h/ioctl.h"
include|#
directive|include
file|"../vax/cpu.h"
include|#
directive|include
file|"../vax/mtpr.h"
include|#
directive|include
file|"../net/if.h"
include|#
directive|include
file|"../net/netisr.h"
include|#
directive|include
file|"../net/route.h"
include|#
directive|include
file|"../netinet/in.h"
include|#
directive|include
file|"../netinet/in_systm.h"
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
operator|||
name|ACC_ULTRIX
operator|>
literal|12
include|#
directive|include
file|"../netinet/in_var.h"
endif|#
directive|endif
include|#
directive|include
file|"../netinet/ip.h"
include|#
directive|include
file|"../netinet/ip_var.h"
include|#
directive|include
file|"../vaxif/if_ddareg.h"
include|#
directive|include
file|"../vaxif/if_ddavar.h"
else|#
directive|else
else|SIMULATION
include|#
directive|include
file|"machine/pte.h"
comment|/* page table entries */
include|#
directive|include
file|"h/param.h"
include|#
directive|include
file|"h/systm.h"
include|#
directive|include
file|"h/mbuf.h"
include|#
directive|include
file|"h/buf.h"
include|#
directive|include
file|"h/protosw.h"
include|#
directive|include
file|"h/socket.h"
include|#
directive|include
file|"h/vmmac.h"
include|#
directive|include
file|"h/errno.h"
include|#
directive|include
file|"h/dir.h"
include|#
directive|include
file|"h/user.h"
include|#
directive|include
file|"h/kernel.h"
include|#
directive|include
file|"h/ioctl.h"
include|#
directive|include
file|"vax/cpu.h"
include|#
directive|include
file|"vax/mtpr.h"
include|#
directive|include
file|"net/if.h"
include|#
directive|include
file|"net/netisr.h"
include|#
directive|include
file|"net/route.h"
include|#
directive|include
file|"netinet/in.h"
include|#
directive|include
file|"netinet/in_systm.h"
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
operator|||
name|ACC_ULTRIX
operator|>
literal|12
include|#
directive|include
file|"netinet/in_var.h"
endif|#
directive|endif
include|#
directive|include
file|"netinet/ip.h"
include|#
directive|include
file|"netinet/ip_var.h"
include|#
directive|include
file|"if_ddareg.h"
include|#
directive|include
file|"if_ddavar.h"
ifndef|#
directive|ifndef
name|SIOCACPCONFIG
define|#
directive|define
name|SIOCACPCONFIG
value|_IOWR(i,40,struct ifreq)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|INET
define|#
directive|define
name|INET
value|1
endif|#
directive|endif
specifier|extern
expr|struct
name|ifqueue
name|ipintrq
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* IP input queue */
end_comment

begin_endif
endif|#
directive|endif
endif|SIMULATION
end_endif

begin_if
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|eunice
end_ifdef

begin_define
define|#
directive|define
name|WINS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTINET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WINS
end_ifdef

begin_include
include|#
directive|include
file|<vms/adpdef.h>
end_include

begin_comment
comment|/* Define Adapters */
end_comment

begin_include
include|#
directive|include
file|<vms/dcdef.h>
end_include

begin_comment
comment|/* Define AT$_UBA, adapter type */
end_comment

begin_else
else|#
directive|else
else|MULTINET
end_else

begin_include
include|#
directive|include
file|"../vaxif/if_ddaioctl.h"
end_include

begin_comment
comment|/* not in ioctl.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* disable histogram functions for BSD 4.2 and ULTRIX 1.2 */
end_comment

begin_if
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
end_if

begin_undef
undef|#
directive|undef
name|DDA_HISTOGRAM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Ultrix doesn't have syslog, so use printf instead.  Since the two  * functions take different arg list formats, embed the open paren in  * the defined symbol; provide DDAELOG to close the call while keeping  * parentheses matched.	 The argument to DDALOG is ignored for printf;  * for log(), debugging messages use LOG_DEBUG, all others use LOG_ERR.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|ACC_BSD
operator|>
literal|42
operator|||
name|ACC_VMS
operator|>
literal|00
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SIMULATION
argument_list|)
end_if

begin_include
include|#
directive|include
file|"syslog.h"
end_include

begin_define
define|#
directive|define
name|DDALOG
parameter_list|(
name|s
parameter_list|)
value|log( s,
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DDALOG
parameter_list|(
name|s
parameter_list|)
value|printf(
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DDAELOG
value|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DDADEBUG
end_ifndef

begin_define
define|#
directive|define
name|PRIVATE
value|static
end_define

begin_comment
comment|/* hide our internal functions */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRIVATE
end_define

begin_comment
comment|/* let the world see them */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%		       GLOBAL FUNCTIONS				 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
name|int
name|ddaprobe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddaattach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddareset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddainit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddaoutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddatimer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddaioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddainta
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* service interrupt "a" from front end */
end_comment

begin_function_decl
name|int
name|ddaintb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* service interrupt "b" from front end */
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%		       LOCAL  FUNCTIONS				 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
name|PRIVATE
name|void
name|send_config
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|struct
name|dda_cb
modifier|*
name|locate_x25_lcn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|struct
name|dda_cb
modifier|*
name|find_free_lcn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|boolean
name|convert_ip_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|u_long
name|convert_x25_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|boolean
name|make_x25_call
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_start
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_rrq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_wrq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|start_chn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|supr_msg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|boolean
name|decode_ring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|decode_answer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|clear_lcn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|send_restart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|send_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|start_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|abort_io
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|prt_addr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
end_ifdef

begin_function_decl
name|PRIVATE
name|int
name|dda_decode_type
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
name|DDA_PADOPT
end_ifdef

begin_function_decl
name|PRIVATE
name|void
name|x29_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|x29_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|x29_init
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|DDA_PADOPT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_RAWOPT
end_ifdef

begin_function_decl
name|PRIVATE
name|void
name|pi_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|pi_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|pi_circuit_to_handle_protocol
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|DDA_RAWOPT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_function_decl
name|PRIVATE
name|void
name|prt_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|PRIVATE
name|char
modifier|*
name|fmt_x25
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_HISTOGRAM
end_ifdef

begin_function_decl
name|PRIVATE
name|void
name|hist_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* histogram functions */
end_comment

begin_function_decl
name|PRIVATE
name|void
name|hist_lcn_state
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|hist_all_lcns
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|hist_link_state
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|hist_read
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|hist_copyout
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
else|DDA_HISTOGRAM
end_else

begin_comment
comment|/* make all histogram functions no-op's */
end_comment

begin_define
define|#
directive|define
name|hist_init
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|hist_lcn_state
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|hist_all_lcns
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|hist_link_state
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|hist_read
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|hist_copyout
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
endif|DDA_HISTOGRAM
end_endif

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%		       LOCAL  VARIABLES				 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
name|PRIVATE
name|int
name|tmo_data_idle
init|=
name|TMO_DATA_IDLE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* idle circuit timeout for 						 * all boards */
end_comment

begin_decl_stmt
name|PRIVATE
name|int
name|nddach
index|[
literal|4
index|]
init|=
block|{
comment|/* number of channels currently in use */
name|NDDACH_DEFAULT
block|,
name|NDDACH_DEFAULT
block|,
name|NDDACH_DEFAULT
block|,
name|NDDACH_DEFAULT
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|char
modifier|*
name|dda_product
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of product, like "ACP5250" */
end_comment

begin_decl_stmt
name|PRIVATE
name|int
name|dda_hasmaint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do we have a maintenance board? */
end_comment

begin_comment
comment|/* the message bits are used in the DMESG macros defined in if_ddavar.h */
end_comment

begin_comment
comment|/* word 1 and 2 (msgs 0   -  63)  are reserved for the IP interface	*/
end_comment

begin_comment
comment|/* word 3	(msgs 64  -  95)  are reserved for the PI interface	*/
end_comment

begin_comment
comment|/* word 4	(msgs 96  -  127) are reserved for the X.29 interface	*/
end_comment

begin_comment
comment|/* word 5 and 6 (msgs 128 -  191) are reserved for debugging main module*/
end_comment

begin_comment
comment|/* word 7	(msgs 192 -  223) are reserved for debugging the PI     */
end_comment

begin_comment
comment|/* word 8	(msgs 224 -  255) are reserved for debugging X29	*/
end_comment

begin_comment
comment|/* word 9	(msgs 256 -  287) are reserved for call logging		*/
end_comment

begin_define
define|#
directive|define
name|NDMESGWORDS
value|9
end_define

begin_define
define|#
directive|define
name|MAXDMSGS
value|(NDMESGWORDS * 32)
end_define

begin_decl_stmt
name|PRIVATE
name|long
name|ddamsgs
index|[
name|NDDA
index|]
index|[
name|NDMESGWORDS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*					       |  |  |  |   |   |   |   |   |  * default:	all informational messages on, /--/--/--/   |   |   |   |   |  *		all debug messages off,	--------------------/---/---/---/   |  *		log busys, but not calls or I/O aborts ---------------------/  */
end_comment

begin_comment
comment|/* Must be as large as the larger of (trtab, ddactl, dnload): */
end_comment

begin_decl_stmt
name|char
name|dda_iobuf
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dda_softc
name|dda_softc
index|[
name|NDDA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per device infomation */
end_comment

begin_comment
comment|/*  header for building command to be sent to the front end in	 */
end_comment

begin_comment
comment|/*  response to ACPCONFIG user command				 */
end_comment

begin_decl_stmt
name|PRIVATE
name|u_char
name|acpconfig_msg
index|[]
init|=
block|{
name|LINE_CNTL
block|,
comment|/* set command code */
literal|0x00
block|,
comment|/* not used */
literal|0x00
block|,
comment|/* not used */
literal|0x00
block|,
comment|/* extension length (set at runtime) */
literal|0x00
block|,
comment|/* cmd space */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|bfr_size_msg
index|[]
init|=
block|{
name|SET_BFR_SIZE
block|,
comment|/* set command code */
literal|0x00
block|,
comment|/* not used */
literal|0x00
block|,
comment|/* not used */
literal|0x01
block|,
comment|/* extension length */
literal|0x00
block|,
comment|/* cmd space */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_cmnd
index|[
literal|4
index|]
init|=
block|{
name|CALL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_called_addr
index|[
literal|16
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_calling_addr
index|[
literal|16
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_facilities
index|[
literal|64
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_protocol
index|[
literal|5
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
name|ddacb_user_data
index|[
literal|64
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_decl_stmt
name|u_char
name|dda_silo_counter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|dda_debug_silo
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Table of baud rate values and the associated parameter for the Set	*/
end_comment

begin_comment
comment|/* System Parameters message, ddainit_msg.  The 'parameter1' is nonzero */
end_comment

begin_comment
comment|/* for valid baud rate divisors.  These are nominal baud rates.		*/
end_comment

begin_macro
name|PRIVATE
end_macro

begin_struct
struct|struct
name|baud
block|{
name|char
name|b_value
decl_stmt|;
name|u_char
name|parameter1
decl_stmt|;
comment|/* first byte of baud rate setting  */
name|u_char
name|parameter2
decl_stmt|;
comment|/* second byte of baud rate setting */
block|}
name|ddabaud_rate
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|0x02
block|,
literal|0x00
block|}
block|,
comment|/* 2.00M */
block|{
literal|2
block|,
literal|0x03
block|,
literal|0x00
block|}
block|,
comment|/* 1.33M */
block|{
literal|3
block|,
literal|0x04
block|,
literal|0x00
block|}
block|,
comment|/* 1.00M */
block|{
literal|4
block|,
literal|0x08
block|,
literal|0x00
block|}
block|,
comment|/* 500K	 */
block|{
literal|5
block|,
literal|0x10
block|,
literal|0x00
block|}
block|,
comment|/* 250K	 */
block|{
literal|6
block|,
literal|0x28
block|,
literal|0x00
block|}
block|,
comment|/* 100K	 */
block|{
literal|7
block|,
literal|0x3e
block|,
literal|0x00
block|}
block|,
comment|/* 64K	 */
block|{
literal|8
block|,
literal|0x47
block|,
literal|0x00
block|}
block|,
comment|/* 56K	 */
block|{
literal|9
block|,
literal|0x85
block|,
literal|0x00
block|}
block|,
comment|/* 30K	 */
block|{
literal|10
block|,
literal|0xd0
block|,
literal|0x00
block|}
block|,
comment|/* 19.2K */
block|{
literal|11
block|,
literal|0xa1
block|,
literal|0x01
block|}
block|,
comment|/* 9600	 */
block|{
literal|12
block|,
literal|0x41
block|,
literal|0x03
block|}
block|,
comment|/* 4800	 */
block|{
literal|13
block|,
literal|0x83
block|,
literal|0x06
block|}
block|,
comment|/* 2400	 */
block|{
literal|14
block|,
literal|0x05
block|,
literal|0x0d
block|}
block|,
comment|/* 1200	 */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%% Address Translation Table for Internet<-> X.25 addresses	 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_define
define|#
directive|define
name|DDANATT
value|32
end_define

begin_comment
comment|/* number of addr translation table entries */
end_comment

begin_decl_stmt
name|PRIVATE
name|int
name|dda_num_addr_tr
index|[
name|NDDA
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of address 						 * translations */
end_comment

begin_comment
comment|/* currently stored */
end_comment

begin_macro
name|PRIVATE
end_macro

begin_struct
struct|struct
name|dda_addr_tr
block|{
comment|/* X.25 PDN address translation table */
name|u_long
name|ip_addr
decl_stmt|;
comment|/* internet address */
name|u_char
name|x25_addr
index|[
name|MAXADDRLEN
index|]
decl_stmt|;
comment|/* X.25 address */
block|}
name|dda_addr_tr
index|[
name|NDDA
index|]
index|[
name|DDANATT
index|]
init|=
block|{
block|{
literal|0L
block|,
literal|""
block|}
block|}
struct|;
end_struct

begin_comment
comment|/* null */
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%% Aliasing of IP address for 4.2 ==> 4.3 compatibility	 %%*/
end_comment

begin_comment
comment|/*%% Note: this union is not required in 4.2, since the s_net	 %%*/
end_comment

begin_comment
comment|/*%% field and its friends are in an include file.  We use it to %%*/
end_comment

begin_comment
comment|/*%% minimize the number of #ifdef dependencies in the code.	 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|s_net
end_ifdef

begin_comment
comment|/* 4.2 */
end_comment

begin_undef
undef|#
directive|undef
name|s_net
end_undef

begin_undef
undef|#
directive|undef
name|s_host
end_undef

begin_undef
undef|#
directive|undef
name|s_lh
end_undef

begin_undef
undef|#
directive|undef
name|s_impno
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|imp_addr
block|{
name|struct
name|in_addr
name|ip
decl_stmt|;
struct|struct
name|imp
block|{
name|u_char
name|s_net
decl_stmt|;
name|u_char
name|s_host
decl_stmt|;
name|u_char
name|s_lh
decl_stmt|;
name|u_char
name|s_impno
decl_stmt|;
block|}
name|imp
struct|;
block|}
union|;
end_union

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%		       GLOBAL ROUTINES				 %%*/
end_comment

begin_comment
comment|/*%%								 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACP_BI
end_ifdef

begin_include
include|#
directive|include
file|"if_dda_bibus.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"if_dda_uqbus.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%			  DDAIOCTL()				 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*								   */
end_comment

begin_comment
comment|/*  Purpose:							   */
end_comment

begin_comment
comment|/*								   */
end_comment

begin_comment
comment|/*   This routine processes device dependent ioctl's.  Supported   */
end_comment

begin_comment
comment|/*   ioctls set the host's internet address for this network	   */
end_comment

begin_comment
comment|/*   interface, or send Set System Parameters Message to the ACP.  */
end_comment

begin_comment
comment|/*   The logic for setting the interface address must remain	   */
end_comment

begin_comment
comment|/*   compatible with both ifconfig and acpconfig programs.	   */
end_comment

begin_comment
comment|/*   If the ioctl comes from the acpconfig program, the front end  */
end_comment

begin_comment
comment|/*   is not initialized because the user will specify explicitly   */
end_comment

begin_comment
comment|/*   what parameters are desired.  If the ioctl comes from the	   */
end_comment

begin_comment
comment|/*   ifconfig program, the fron end is initialized with default	   */
end_comment

begin_comment
comment|/*   parameters in the ddainit_msg array.			   */
end_comment

begin_comment
comment|/*								   */
end_comment

begin_comment
comment|/*  Call:	     ddaioctl(ifp, cmd, data)			   */
end_comment

begin_comment
comment|/*  Argument:	     ifp:   pointer to the network interface data  */
end_comment

begin_comment
comment|/*				 structure, ifnet		   */
end_comment

begin_comment
comment|/*		     cmd:   identifies the type of ioctl	   */
end_comment

begin_comment
comment|/*		     data:  information for the ioctl		   */
end_comment

begin_comment
comment|/*  Returns:	     0 for success, or the nonzero error value:	   */
end_comment

begin_comment
comment|/*				  EINVAL invalid ioctl request	   */
end_comment

begin_comment
comment|/*  Called by:	      network software, address of this routine is */
end_comment

begin_comment
comment|/*		      defined in af_inet network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:	      splimp()					   */
end_comment

begin_comment
comment|/*		      if_rtinit()				   */
end_comment

begin_comment
comment|/*		      in_netof()				   */
end_comment

begin_comment
comment|/*		      in_lnaof()				   */
end_comment

begin_comment
comment|/*		      ddainit()					   */
end_comment

begin_comment
comment|/*		      send_config()				   */
end_comment

begin_comment
comment|/*		      DDALOG()					   */
end_comment

begin_comment
comment|/*		      splx()					   */
end_comment

begin_comment
comment|/*								   */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_decl_stmt
specifier|volatile
name|int
name|StatQuery_Completed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Polled for board stat ioctl */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ddaioctl
argument_list|(
name|ifp
argument_list|,
name|cmd
argument_list|,
name|data
argument_list|)
specifier|register
expr|struct
name|ifnet
operator|*
name|ifp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|ifp
operator|->
name|if_unit
index|]
decl_stmt|;
name|struct
name|ifreq
modifier|*
name|ifr
init|=
operator|(
expr|struct
name|ifreq
operator|*
operator|)
name|data
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DDA_PADOPT
argument_list|)
operator|&&
name|defined
argument_list|(
name|WINS
argument_list|)
name|int
name|prealloc_x29
parameter_list|()
function_decl|;
comment|/* Preallocate UCBs for X29 */
endif|#
directive|endif
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|struct
name|sockaddr_in
modifier|*
name|sin
init|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|ifr
operator|->
name|ifr_addr
decl_stmt|;
else|#
directive|else
name|struct
name|ifaddr
modifier|*
name|ifa
init|=
name|ds
operator|->
name|dda_if
operator|.
name|if_addrlist
decl_stmt|;
endif|#
directive|endif
name|int
name|s
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|register
name|struct
name|dda_addr_tr
modifier|*
name|atp
decl_stmt|,
modifier|*
name|btp
decl_stmt|;
name|struct
name|trtab
modifier|*
name|tr
decl_stmt|;
name|struct
name|ddactl
modifier|*
name|da
decl_stmt|;
name|char
name|arg2
index|[
name|MAXADDRLEN
index|]
decl_stmt|,
name|code
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|4
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ioctl()\n"
operator|,
name|ifp
operator|->
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/*      * This may not be necessary here, but under some flavors of BSDish      * systems (2.0ULTRIX) this routine is apparently called at splimp(). In      * the case that we are currently processing ioctls issued from acpconfig      * in /etc/rc, the board may not have come on line yet - so we need to be      * able to process the B interrupt while in the delay loop below.       */
ifndef|#
directive|ifndef
name|MULTINET
name|s
operator|=
name|spl0
argument_list|()
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCSIFADDR
case|:
if|if
condition|(
operator|!
name|suser
argument_list|()
condition|)
return|return
name|EACCES
return|;
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
condition|)
name|if_rtinit
argument_list|(
name|ifp
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* delete previous route */
name|ifp
operator|->
name|if_addr
operator|=
operator|*
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
name|sin
expr_stmt|;
name|ifp
operator|->
name|if_net
operator|=
name|in_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
expr_stmt|;
name|ifp
operator|->
name|if_host
index|[
literal|0
index|]
operator|=
name|in_lnaof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
condition|)
name|if_rtinit
argument_list|(
name|ifp
argument_list|,
name|RTF_UP
argument_list|)
expr_stmt|;
else|else
name|ddainit
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_ipaddr
operator|.
name|s_addr
operator|=
operator|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|ifp
operator|->
name|if_addr
operator|)
operator|->
name|sin_addr
operator|.
name|s_addr
expr_stmt|;
else|#
directive|else
comment|/* 4.3 networking */
if|if
condition|(
name|ifa
operator|->
name|ifa_addr
operator|.
name|sa_family
operator|!=
name|AF_INET
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
operator|(
name|ifp
operator|->
name|if_flags
operator|&
name|IFF_RUNNING
operator|)
operator|==
literal|0
condition|)
name|ddainit
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_ipaddr
operator|=
name|IA_SIN
argument_list|(
name|ifa
argument_list|)
operator|->
name|sin_addr
expr_stmt|;
endif|#
directive|endif
comment|/* 4.3 networking */
break|break;
case|case
name|SIOCACPCONFIG
case|:
comment|/* process ioctl from acpconfig program */
name|code
operator|=
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
expr_stmt|;
comment|/********************************************************* 	 *							 * 	 *	Commands n, h, q, and r are non-privileged	 * 	 *							 * 	 *********************************************************/
if|if
condition|(
operator|!
name|suser
argument_list|()
operator|&&
name|code
operator|!=
literal|'n'
operator|&&
name|code
operator|!=
literal|'h'
operator|&&
name|code
operator|!=
literal|'q'
operator|&&
name|code
operator|!=
literal|'r'
condition|)
return|return
name|EACCES
return|;
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|sin
operator|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|ds
operator|->
name|dda_if
operator|.
name|if_addr
expr_stmt|;
if|if
condition|(
name|in_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
operator|==
literal|0
condition|)
else|#
directive|else
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_addrlist
operator|==
literal|0
condition|)
endif|#
directive|endif
block|{
name|error
operator|=
name|EDESTADDRREQ
expr_stmt|;
comment|/* error, no internet address */
goto|goto
name|exit
goto|;
block|}
comment|/* for command to set baud rate, look up the value for the  */
comment|/* baud rate divisor in the ddabaud_rate table, put value   */
comment|/* in the Set System Parameters message, ddainit_msg        */
if|if
condition|(
name|code
operator|>=
literal|1
operator|&&
name|code
operator|<=
literal|14
condition|)
block|{
specifier|register
name|struct
name|baud
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
for|for
control|(
name|p
operator|=
name|ddabaud_rate
init|;
name|p
operator|->
name|b_value
condition|;
name|p
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
operator|-
name|p
operator|->
name|b_value
operator|)
operator|==
literal|0
condition|)
break|break;
block|}
comment|/* if internal clock not set, do so */
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_INTCLOCK
operator|)
operator|==
literal|0
condition|)
block|{
name|ds
operator|->
name|dda_init
operator||=
name|DDA_INTCLOCK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|CLOCK_CNTL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|INTERNAL_CLOCK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|BAUD_CNTL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|3
index|]
operator|=
name|p
operator|->
name|parameter1
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|4
index|]
operator|=
name|p
operator|->
name|parameter2
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|5
expr_stmt|;
block|}
else|else
block|{
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|BAUD_CNTL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|p
operator|->
name|parameter1
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|p
operator|->
name|parameter2
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|3
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|p
operator|->
name|b_value
operator|==
literal|0
operator|)
operator|||
operator|(
name|p
operator|->
name|parameter1
operator|==
literal|0
operator|)
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
comment|/* baud rate value invalid */
else|else
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
comment|/* send message to front end */
goto|goto
name|exit
goto|;
block|}
switch|switch
condition|(
name|code
condition|)
block|{
case|case
literal|'a'
case|:
comment|/* Add address translation table entry */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|>=
name|DDANATT
condition|)
block|{
comment|/* table already full */
name|error
operator|=
name|ENOMEM
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
comment|/* 	     * Copy in user arguments and point "tr" at them.  Then scan the 	     * translation table and either find location to insert or flag 	     * error  	     */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trtab
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|tr
operator|=
operator|(
expr|struct
name|trtab
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|atp
operator|=
operator|&
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
literal|0
index|]
init|;
name|i
operator|<
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
condition|;
name|i
operator|++
operator|,
name|atp
operator|++
control|)
block|{
if|if
condition|(
name|atp
operator|->
name|ip_addr
operator|==
name|tr
operator|->
name|ipaddr
condition|)
block|{
if|if
condition|(
name|bcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
name|atp
operator|->
name|x25_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|tr
operator|->
name|x25addr
argument_list|,
name|MAXADDRLEN
argument_list|)
condition|)
block|{
name|error
operator|=
name|EADDRINUSE
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
else|else
comment|/* addresses are the same, just ignore ioctl */
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|atp
operator|->
name|ip_addr
operator|>
name|tr
operator|->
name|ipaddr
condition|)
comment|/* insert entry here */
break|break;
block|}
for|for
control|(
name|btp
operator|=
operator|&
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|]
init|;
name|btp
operator|>
name|atp
condition|;
name|btp
operator|--
control|)
block|{
comment|/* open up space for a new entry */
name|btp
operator|->
name|ip_addr
operator|=
operator|(
name|btp
operator|-
literal|1
operator|)
operator|->
name|ip_addr
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|btp
operator|-
literal|1
operator|)
operator|->
name|x25_addr
argument_list|,
name|btp
operator|->
name|x25_addr
argument_list|,
name|MAXADDRLEN
argument_list|)
expr_stmt|;
block|}
name|atp
operator|->
name|ip_addr
operator|=
name|tr
operator|->
name|ipaddr
expr_stmt|;
name|bcopy
argument_list|(
name|tr
operator|->
name|x25addr
argument_list|,
name|atp
operator|->
name|x25_addr
argument_list|,
name|MAXADDRLEN
argument_list|)
expr_stmt|;
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|++
expr_stmt|;
comment|/* one more table entry */
goto|goto
name|exit
goto|;
case|case
literal|'D'
case|:
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
comment|/* clear table for use by 'r' flag of acpconfig */
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|atp
operator|=
operator|&
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
literal|0
index|]
init|;
name|i
operator|<
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
condition|;
name|i
operator|++
operator|,
name|atp
operator|++
control|)
block|{
name|atp
operator|->
name|ip_addr
operator|=
literal|0L
expr_stmt|;
name|atp
operator|->
name|x25_addr
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|=
literal|0
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'d'
case|:
comment|/* Delete address translation table entry */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trtab
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|tr
operator|=
operator|(
expr|struct
name|trtab
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|error
operator|=
name|EFAULT
expr_stmt|;
comment|/* in case inet address not in table */
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|atp
operator|=
operator|&
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
literal|0
index|]
init|;
name|i
operator|<
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
condition|;
name|i
operator|++
operator|,
name|atp
operator|++
control|)
block|{
if|if
condition|(
name|atp
operator|->
name|ip_addr
operator|==
name|tr
operator|->
name|ipaddr
condition|)
block|{
name|error
operator|=
literal|0
expr_stmt|;
comment|/* found it: cancel error */
for|for
control|(
init|;
name|i
operator|<
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|-
literal|1
condition|;
name|i
operator|++
operator|,
name|atp
operator|++
control|)
block|{
name|atp
operator|->
name|ip_addr
operator|=
operator|(
name|atp
operator|+
literal|1
operator|)
operator|->
name|ip_addr
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|atp
operator|+
literal|1
operator|)
operator|->
name|x25_addr
argument_list|,
name|atp
operator|->
name|x25_addr
argument_list|,
name|MAXADDRLEN
argument_list|)
expr_stmt|;
block|}
name|atp
operator|->
name|ip_addr
operator|=
literal|0L
expr_stmt|;
comment|/* clear last vacated entry */
name|atp
operator|->
name|x25_addr
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|dda_num_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|--
expr_stmt|;
comment|/* one fewer table 							 * entries */
break|break;
block|}
block|}
goto|goto
name|exit
goto|;
case|case
literal|'f'
case|:
comment|/* -f facility status */
comment|/* 	     * The first byte of the "msg" selects the flow control parameter 	     * and the "drval" field holds the status (on or off).  	     */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
comment|/* need 2.0 or above ROMs */
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
switch|switch
condition|(
name|da
operator|->
name|msg
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|0
case|:
comment|/* packet */
if|if
condition|(
name|da
operator|->
name|drval
condition|)
name|ds
operator|->
name|dda_init
operator||=
name|DDA_PKTNEG
expr_stmt|;
else|else
name|ds
operator|->
name|dda_init
operator|&=
operator|~
name|DDA_PKTNEG
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* window */
if|if
condition|(
name|da
operator|->
name|drval
condition|)
name|ds
operator|->
name|dda_init
operator||=
name|DDA_WNDNEG
expr_stmt|;
else|else
name|ds
operator|->
name|dda_init
operator|&=
operator|~
name|DDA_WNDNEG
expr_stmt|;
break|break;
block|}
goto|goto
name|exit
goto|;
case|case
literal|'o'
case|:
comment|/* Set options */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
comment|/* need 2.1 or above ROMs */
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_state
operator|!=
name|S_DISABLED
condition|)
block|{
comment|/* must bring link down */
name|error
operator|=
name|EINPROGRESS
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|PKT_OPTIONS
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|da
operator|->
name|msg
index|[
literal|0
index|]
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|2
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|4
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: acpconfig_msg is %x %x %x\n"
operator|,
name|ifp
operator|->
name|if_unit
operator|,
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|,
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|,
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'N'
case|:
comment|/* read network id */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|ds
operator|->
name|dda_net_id
operator|=
name|da
operator|->
name|drval
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'r'
case|:
comment|/* Read address translation table entry */
comment|/* 	     * The value stored in "ipaddr" is not an address, but an index 	     * of a translation table entry to read out.  The x25_addr field 	     * in the input structure is not used.  	     */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trtab
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|tr
operator|=
operator|(
expr|struct
name|trtab
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|i
operator|=
name|tr
operator|->
name|ipaddr
expr_stmt|;
if|if
condition|(
name|i
operator|>=
name|DDANATT
condition|)
block|{
comment|/* scanned the whole table */
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|tr
operator|->
name|ipaddr
operator|=
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
name|i
index|]
operator|.
name|ip_addr
expr_stmt|;
name|bcopy
argument_list|(
name|dda_addr_tr
index|[
name|ifp
operator|->
name|if_unit
index|]
index|[
name|i
index|]
operator|.
name|x25_addr
argument_list|,
name|tr
operator|->
name|x25addr
argument_list|,
name|MAXADDRLEN
argument_list|)
expr_stmt|;
if|if
condition|(
name|copyout
argument_list|(
name|tr
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trtab
argument_list|)
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
ifdef|#
directive|ifdef
name|DDA_HISTOGRAM
case|case
literal|'h'
case|:
comment|/* read histogram */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|hist_read
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|hist_copyout
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'H'
case|:
comment|/* read and reset histogram */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|hist_read
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
if|if
condition|(
name|hist_copyout
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
else|else
name|hist_init
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
endif|#
directive|endif
endif|DDA_HISTOGRAM
case|case
literal|'v'
case|:
comment|/* -v variable value */
comment|/* 	     * There are two "variables" in the driver which can be set via 	     * ioctl: packet size, and window size.  The "drval" field holds 	     * the value and the first byte of the "msg" selects the variable. 	     * Note that the selector is another little undocumented piece of 	     * the interface between here and the acpconfig program. It is 	     * coupled to the ordering of a little string table inside that 	     * program; new parameters should be added at the end, not the 	     * middle!  	     */
comment|/* No check to see if powerup diags are completed */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
switch|switch
condition|(
name|da
operator|->
name|msg
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|0
case|:
comment|/* set logging (obsolete) */
case|case
literal|1
case|:
comment|/* set debug (obsolete) */
case|case
literal|2
case|:
comment|/* set debug unit (obsolete) */
name|error
operator|=
name|EINVAL
expr_stmt|;
break|break;
comment|/* 		 * For both packet and window sizes, we check that the link 		 * is currently down.  The new parameters will be sent to the 		 * FEP when the link is next brought up.  See processing for 		 * -u flag.  		 */
case|case
literal|3
case|:
comment|/* set packetsize */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
comment|/* need 2.1 or above ROMs */
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_state
operator|!=
name|S_DISABLED
condition|)
block|{
comment|/* must bring link down */
name|error
operator|=
name|EINPROGRESS
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
comment|/* 		 * X.25 (1984) section 7.2.2.1.1 says 12 (4096 byte packets) 		 * BBN report 5760 (September 1984) 14.2.1.2 says 10. We just 		 * check for 12.  		 */
if|if
condition|(
name|da
operator|->
name|drval
operator|<
literal|4
operator|||
name|da
operator|->
name|drval
operator|>
literal|12
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
name|int
name|packetsize
init|=
literal|1
operator|<<
name|da
operator|->
name|drval
decl_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|3
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|MAX_PKT_SZ
expr_stmt|;
comment|/* Max negotiable */
comment|/* pkt size */
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|packetsize
operator|&
literal|0xFF
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
operator|(
name|packetsize
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
expr_stmt|;
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|4
case|:
comment|/* set windowsize */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
comment|/* need 2.0 or above ROMs */
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_state
operator|!=
name|S_DISABLED
condition|)
block|{
comment|/* must bring link down */
name|error
operator|=
name|EINPROGRESS
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|da
operator|->
name|drval
operator|<
literal|1
operator|||
name|da
operator|->
name|drval
operator|>
literal|127
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|2
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|MAX_PKT_WN
expr_stmt|;
comment|/* Max negotiable */
comment|/* pkt window */
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|da
operator|->
name|drval
expr_stmt|;
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
goto|goto
name|exit
goto|;
case|case
literal|'m'
case|:
comment|/* -m message */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|send_config
argument_list|(
name|ds
argument_list|,
name|da
operator|->
name|msg
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'n'
case|:
comment|/* -n svc_count */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
comment|/* need 2.1 or above ROMs */
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
comment|/* i holds the return value */
if|if
condition|(
name|da
operator|->
name|drval
operator|==
literal|0
condition|)
name|i
operator|=
name|nddach
index|[
name|ifp
operator|->
name|if_unit
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|ds
operator|->
name|dda_state
operator|!=
name|S_DISABLED
condition|)
block|{
comment|/* must bring link down */
name|error
operator|=
name|EINPROGRESS
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|suser
argument_list|()
condition|)
block|{
name|error
operator|=
name|EACCES
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|da
operator|->
name|drval
operator|<
literal|1
operator|||
name|da
operator|->
name|drval
operator|>
name|NDDACH
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|2
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|SVC_LIMIT
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|da
operator|->
name|drval
expr_stmt|;
name|nddach
index|[
name|ifp
operator|->
name|if_unit
index|]
operator|=
name|da
operator|->
name|drval
expr_stmt|;
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|copyout
argument_list|(
operator|&
name|i
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'c'
case|:
comment|/* -c msgnum  -- dis/enable driver mesg */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
if|if
condition|(
name|da
operator|->
name|drval
operator|<
literal|0
operator|||
name|da
operator|->
name|drval
operator|>=
name|MAXDMSGS
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
name|u_char
name|new_val
decl_stmt|;
name|DMESGTOG
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|da
operator|->
name|drval
argument_list|)
expr_stmt|;
name|new_val
operator|=
name|DMESGVAL
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|da
operator|->
name|drval
argument_list|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
comment|/* 1 means disabled, 0 means enabled */
if|if
condition|(
name|copyout
argument_list|(
operator|&
name|new_val
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
sizeof|sizeof
argument_list|(
name|u_char
argument_list|)
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
block|}
goto|goto
name|exit
goto|;
case|case
literal|'t'
case|:
comment|/* -t sec  -- set data idle timeout */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
if|if
condition|(
name|da
operator|->
name|drval
operator|<
literal|1
condition|)
name|error
operator|=
name|EINVAL
expr_stmt|;
else|else
name|tmo_data_idle
operator|=
name|da
operator|->
name|drval
operator|/
name|DDA_TIMEOUT
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'q'
case|:
comment|/* driver/FE/shm/silo state queries */
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
name|dda_iobuf
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|da
operator|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
expr_stmt|;
switch|switch
condition|(
name|da
operator|->
name|msg
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|0
case|:
comment|/* front end state query */
if|if
condition|(
operator|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|int
name|s2
init|=
name|splimp
argument_list|()
decl_stmt|;
comment|/* need 2.0 or above ROMs */
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
name|splx
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* We got it and woke up */
break|break;
block|}
ifdef|#
directive|ifdef
name|MULTINET
name|StatQuery_Completed
operator|=
literal|0
expr_stmt|;
name|send_supr
argument_list|(
name|ds
argument_list|,
name|STATQUERY
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* drop ioctl so we can be scheduled */
while|while
condition|(
operator|!
name|StatQuery_Completed
condition|)
empty_stmt|;
else|#
directive|else
else|MULTINET
name|send_supr
argument_list|(
name|ds
argument_list|,
name|STATQUERY
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
name|dda_iobuf
argument_list|,
name|PSLEP
argument_list|)
expr_stmt|;
comment|/* Interruptible with ^C */
name|splx
argument_list|(
name|s2
argument_list|)
expr_stmt|;
comment|/* We got it and woke up */
endif|#
directive|endif
endif|MULTINET
if|if
condition|(
name|copyout
argument_list|(
name|dda_iobuf
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
comment|/* driver state query */
name|da
operator|->
name|msg
index|[
literal|0
index|]
operator|=
name|ds
operator|->
name|dda_state
expr_stmt|;
name|da
operator|->
name|msg
index|[
literal|1
index|]
operator|=
name|ds
operator|->
name|dda_init
expr_stmt|;
name|da
operator|->
name|msg
index|[
literal|2
index|]
operator|=
name|ds
operator|->
name|dda_flags
expr_stmt|;
name|da
operator|->
name|msg
index|[
literal|3
index|]
operator|=
name|ds
operator|->
name|dda_firmrev
expr_stmt|;
if|if
condition|(
name|copyout
argument_list|(
name|dda_iobuf
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ddactl
argument_list|)
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|DDADEBUG
case|case
literal|2
case|:
comment|/* debug query */
if|if
condition|(
name|copyout
argument_list|(
name|dda_debug_silo
argument_list|,
name|ifr
operator|->
name|ifr_data
argument_list|,
literal|256
argument_list|)
condition|)
name|error
operator|=
name|EFAULT
expr_stmt|;
break|break;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|DDADEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|ACP_BI
argument_list|)
case|case
literal|3
case|:
comment|/* shm/biic query (temporary) */
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|ddainfo
index|[
name|ifp
operator|->
name|if_unit
index|]
decl_stmt|;
name|dda_dump_shm
argument_list|(
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
argument_list|)
expr_stmt|;
name|dda_dump_biic_regs
argument_list|(
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
argument_list|)
expr_stmt|;
block|}
break|break;
endif|#
directive|endif
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
goto|goto
name|exit
goto|;
case|case
literal|'0'
case|:
comment|/* -u 0 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|LINK_DISABLE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|1
expr_stmt|;
name|hist_link_state
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_GOING_DOWN
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_GOING_DOWN
expr_stmt|;
break|break;
case|case
literal|'1'
case|:
comment|/* -u 1 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|LINK_LOOPBACK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|LOOP_NONE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|DTE_DCE_MODE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|3
index|]
operator|=
name|DTE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|4
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|5
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_COMING_UP
expr_stmt|;
name|hist_init
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'2'
case|:
comment|/* -u 2 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|LINK_LOOPBACK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|LOOP_NONE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|DTE_DCE_MODE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|3
index|]
operator|=
name|DCE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|4
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|5
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_COMING_UP
expr_stmt|;
name|hist_init
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'3'
case|:
comment|/* -u 3 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|LINK_LOOPBACK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|LOOP_EXTERNAL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|3
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_COMING_UP
expr_stmt|;
name|hist_init
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'4'
case|:
comment|/* -u 4 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|LINK_LOOPBACK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|LOOP_INTERNAL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|2
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|3
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_COMING_UP
expr_stmt|;
name|hist_init
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
comment|/* -b 0 */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|CLOCK_CNTL
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_OFFSET
operator|+
literal|1
index|]
operator|=
name|EXTERNAL_CLOCK
expr_stmt|;
name|acpconfig_msg
index|[
name|MSG_LENGTH
index|]
operator|=
literal|2
expr_stmt|;
name|ds
operator|->
name|dda_init
operator|&=
operator|~
name|DDA_INTCLOCK
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
comment|/* select DDN standard X.25 service */
comment|/* -s 0 or -s standard */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_UP
operator|&&
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
condition|)
block|{
name|error
operator|=
name|EALREADY
expr_stmt|;
goto|goto
name|exit
goto|;
comment|/* no PDN->DDN mode change if running */
block|}
name|ds
operator|->
name|dda_init
operator|&=
operator|~
operator|(
name|DDA_BASIC
operator||
name|DDA_PDN
operator|)
expr_stmt|;
name|ds
operator|->
name|dda_init
operator||=
name|DDA_STANDARD
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'T'
case|:
comment|/* select DDN basic X.25 service */
comment|/* -s 1 or -s basic */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_UP
operator|&&
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
condition|)
block|{
name|error
operator|=
name|EALREADY
expr_stmt|;
goto|goto
name|exit
goto|;
comment|/* no PDN->DDN mode change if running */
block|}
name|ds
operator|->
name|dda_init
operator|&=
operator|~
operator|(
name|DDA_PDN
operator||
name|DDA_STANDARD
operator|)
expr_stmt|;
name|ds
operator|->
name|dda_init
operator||=
name|DDA_BASIC
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'U'
case|:
comment|/* select X.25 Public Data Network service */
comment|/* -s 2 or -s pdn */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_UP
operator|&&
operator|(
name|ds
operator|->
name|dda_init
operator|&
operator|(
name|DDA_BASIC
operator||
name|DDA_STANDARD
operator|)
operator|)
condition|)
block|{
name|error
operator|=
name|EALREADY
expr_stmt|;
goto|goto
name|exit
goto|;
comment|/* no DDN->PDN mode change if running */
block|}
name|ds
operator|->
name|dda_init
operator|&=
operator|~
operator|(
name|DDA_BASIC
operator||
name|DDA_STANDARD
operator|)
expr_stmt|;
name|ds
operator|->
name|dda_init
operator||=
name|DDA_PDN
expr_stmt|;
goto|goto
name|exit
goto|;
case|case
literal|'e'
case|:
comment|/* set buffer size */
comment|/* -e size size is encoded in second byte */
if|if
condition|(
name|error
operator|=
name|diags_completed
argument_list|(
name|ds
argument_list|)
condition|)
goto|goto
name|exit
goto|;
comment|/* 	     * check to see if we have newer at least version 2.2 roms.  	     */
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x22
condition|)
block|{
name|error
operator|=
name|ENOPROTOOPT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_UP
condition|)
block|{
name|error
operator|=
name|EALREADY
expr_stmt|;
goto|goto
name|exit
goto|;
comment|/* no PDN->DDN mode change if running */
block|}
name|bfr_size_msg
index|[
name|MSG_OFFSET
index|]
operator|=
name|ifr
operator|->
name|ifr_data
index|[
literal|1
index|]
expr_stmt|;
name|send_config
argument_list|(
name|ds
argument_list|,
name|bfr_size_msg
argument_list|)
expr_stmt|;
name|bufreset
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
ifdef|#
directive|ifdef
name|ACP_BI
case|case
literal|'L'
case|:
block|{
name|struct
name|dda_dnload
name|dl
decl_stmt|;
if|if
condition|(
name|copyin
argument_list|(
name|ifr
operator|->
name|ifr_data
argument_list|,
operator|&
name|dl
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|dda_dnload
argument_list|)
argument_list|)
condition|)
block|{
name|error
operator|=
name|EFAULT
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|error
operator|=
name|dda_dload
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
operator|&
name|dl
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|DDA_PADOPT
argument_list|)
operator|&&
name|defined
argument_list|(
name|WINS
argument_list|)
case|case
literal|'x'
case|:
comment|/* Preallocate UCBs for X29 -- VMS only */
name|printf
argument_list|(
literal|"Preallocated %d PTYs for X29\n"
argument_list|,
name|prealloc_x29
argument_list|()
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
endif|#
directive|endif
case|case
literal|'z'
case|:
comment|/* reset specified front-end device, -z */
comment|/* second parm is supposed to be uban, but ddareset doesn't care about it */
name|ddareset
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
if|if
condition|(
operator|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
operator|!=
literal|'0'
operator|)
operator|&&
operator|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
operator|)
operator|&&
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
operator|(
name|convert_ip_addr
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|arg2
argument_list|,
name|ds
argument_list|)
operator|==
literal|0
operator|)
else|#
directive|else
operator|(
name|convert_ip_addr
argument_list|(
name|ds
operator|->
name|dda_ipaddr
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|arg2
argument_list|,
name|ds
argument_list|)
operator|==
literal|0
operator|)
endif|#
directive|endif
condition|)
block|{
name|error
operator|=
name|EADDRNOTAVAIL
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
name|send_config
argument_list|(
name|ds
argument_list|,
name|acpconfig_msg
argument_list|)
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
name|exit
label|:
ifndef|#
directive|ifndef
name|MULTINET
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAOUTPUT()                            %%*/
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
comment|/*   This routine is called by the network software when it has an */
end_comment

begin_comment
comment|/*   IP datagram to send out this interface.  An attempt is made   */
end_comment

begin_comment
comment|/*   to find a LCN which has a virtual circuit open to the         */
end_comment

begin_comment
comment|/*   indicated host.  If an LCN is found the packet is queued for  */
end_comment

begin_comment
comment|/*   output on that LCN.                                           */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            ddaoutput(ifp, m0, dst)                       */
end_comment

begin_comment
comment|/*  Arguments:       ifp:  locates the network interface, ifnet    */
end_comment

begin_comment
comment|/*                   m0:   locates an mbuf buffer                  */
end_comment

begin_comment
comment|/*                   dst:  is the socket destination address       */
end_comment

begin_comment
comment|/*  Returns:         0 for success, or one of following nonzero    */
end_comment

begin_comment
comment|/*                        error indications:                       */
end_comment

begin_comment
comment|/*                               ENETDOWN                          */
end_comment

begin_comment
comment|/*                               EAFNOSUPPORT                      */
end_comment

begin_comment
comment|/*                               ENOBUFS                           */
end_comment

begin_comment
comment|/*  Called by:     network software, address of this routine is    */
end_comment

begin_comment
comment|/*                 defined in the dda_if network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:      DDALOG()                                        */
end_comment

begin_comment
comment|/*                 m_freem()                                       */
end_comment

begin_comment
comment|/*                 splimp()                                        */
end_comment

begin_comment
comment|/*                 locate_x25_lcn()                                */
end_comment

begin_comment
comment|/*                 IF_QFULL()                                      */
end_comment

begin_comment
comment|/*                 IF_DROP()                                       */
end_comment

begin_comment
comment|/*                 splx()                                          */
end_comment

begin_comment
comment|/*                 IF_ENQUEUE()                                    */
end_comment

begin_comment
comment|/*                 dda_start()                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|ddaoutput
argument_list|(
argument|ifp
argument_list|,
argument|m0
argument_list|,
argument|dst
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|dst
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
init|=
name|m0
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|ifp
operator|->
name|if_unit
index|]
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|ifqueue
modifier|*
name|oq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|prev
decl_stmt|;
name|int
name|s
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|1
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|dst
operator|->
name|sin_addr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddaoutput: dst = %d.%d.%d.%d\n"
operator|,
name|ifp
operator|->
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_UP
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ENETDOWN
operator|)
return|;
switch|switch
condition|(
name|dst
operator|->
name|sin_family
condition|)
block|{
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
break|break;
endif|#
directive|endif
endif|INET
default|default:
name|DMESG
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
literal|2
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: can't handle af%d\n"
operator|,
name|ifp
operator|->
name|if_unit
operator|,
name|dst
operator|->
name|sin_family
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m0
argument_list|)
expr_stmt|;
return|return
operator|(
name|EAFNOSUPPORT
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|2
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|dst
operator|->
name|sin_addr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddaoutput: dst = %d.%d.%d.%d\n"
operator|,
name|ifp
operator|->
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/* Mod to V1.5b ==> V1.5b1 */
comment|/* In 4.3, the IP code may pass mbuf chains with 0-length mbufs */
comment|/* This causes "transfer count = 0" messages and might even     */
comment|/* cause actual garbage data transmission if the mbuf is at the */
comment|/* end of the chain (we don't think it ever will be, but one    */
comment|/* can't be too sure...so we scan the chain first).		    */
comment|/* WE DO ASSUME that there is at least one nonempty mbuf!	    */
comment|/* (ULTRIX: we don't know, but the code is at worst harmless)   */
while|while
condition|(
name|m0
operator|->
name|m_len
operator|==
literal|0
condition|)
block|{
name|m
operator|=
name|m0
expr_stmt|;
name|m0
operator|=
name|m0
operator|->
name|m_next
expr_stmt|;
name|m
operator|->
name|m_next
operator|=
literal|0
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
comment|/* Now we know the first mbuf (at m0)  is not zero length	    */
name|prev
operator|=
name|m0
expr_stmt|;
name|m
operator|=
name|m0
operator|->
name|m_next
expr_stmt|;
while|while
condition|(
name|m
condition|)
block|{
if|if
condition|(
name|m
operator|->
name|m_len
operator|==
literal|0
condition|)
block|{
name|prev
operator|->
name|m_next
operator|=
name|m
operator|->
name|m_next
expr_stmt|;
name|m
operator|->
name|m_next
operator|=
literal|0
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|m
operator|=
name|prev
operator|->
name|m_next
expr_stmt|;
block|}
else|else
block|{
name|prev
operator|=
name|m
expr_stmt|;
name|m
operator|=
name|m
operator|->
name|m_next
expr_stmt|;
block|}
block|}
name|m
operator|=
name|m0
expr_stmt|;
comment|/* reset m to beginning of modified chain */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/* disable interrrupts */
comment|/* try to find an LCN */
if|if
condition|(
name|dc
operator|=
name|locate_x25_lcn
argument_list|(
name|ds
argument_list|,
name|dst
operator|->
name|sin_addr
argument_list|)
condition|)
block|{
comment|/* if found */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|2
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddaoutput: lcn found = %d\n"
operator|,
name|ifp
operator|->
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
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
if|if
condition|(
name|IF_QFULL
argument_list|(
name|oq
argument_list|)
condition|)
block|{
comment|/* if q full */
name|IF_DROP
argument_list|(
name|oq
argument_list|)
expr_stmt|;
comment|/* drop the data */
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_collisions
operator|++
expr_stmt|;
comment|/* for netstat display */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOBUFS
operator|)
return|;
block|}
name|IF_ENQUEUE
argument_list|(
name|oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* otherwise queue it */
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/* and try to output */
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
else|else
block|{
comment|/* if no circuit available */
name|IF_DROP
argument_list|(
operator|&
name|ifp
operator|->
name|if_snd
argument_list|)
expr_stmt|;
comment|/* drop the data */
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
name|EHOSTUNREACH
operator|)
return|;
block|}
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDATIMER()                             %%*/
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
comment|/*  This routine is entered to perform timer management. The       */
end_comment

begin_comment
comment|/*  LCN table is scanned for active timers (nonzero) which are     */
end_comment

begin_comment
comment|/*  decremented.  If a timer expires (becomes zero), the proper    */
end_comment

begin_comment
comment|/*  action is taken.                                               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              ddatimer(unit)                              */
end_comment

begin_comment
comment|/*  Arguments:         unit:  ACP device unit number               */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddainit()                                   */
end_comment

begin_comment
comment|/*  Calls to:          splimp()                                    */
end_comment

begin_comment
comment|/*                     send_restart()                              */
end_comment

begin_comment
comment|/*                     clear_lcn()                                 */
end_comment

begin_comment
comment|/*                     splx()                                      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|int
name|ddatimer
parameter_list|(
name|unit
parameter_list|)
name|int
name|unit
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|,
name|lcn
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|3
argument_list|,
name|unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddatimer()\n"
operator|,
name|unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|ds
operator|->
name|dda_if
operator|.
name|if_timer
operator|=
name|DDA_TIMEOUT
expr_stmt|;
comment|/* restart timer */
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/* LCNLINK */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|nddach
index|[
name|unit
index|]
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* scan all LCN's */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|dc
operator|->
name|dc_out_t
operator|&&
name|lcn
operator|>
literal|0
operator|&&
operator|(
operator|--
operator|(
name|dc
operator|->
name|dc_out_t
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: write completion timeout lcn %d\n"
operator|,
name|unit
operator|,
name|lcn
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|dc
operator|->
name|dc_timer
operator|&&
operator|(
operator|--
operator|(
name|dc
operator|->
name|dc_timer
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
comment|/* if a timer expired */
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_RESTART
condition|)
block|{
comment|/* if a restart was out */
name|send_restart
argument_list|(
name|ds
argument_list|)
expr_stmt|;
comment|/* send another one */
break|break;
block|}
else|else
block|{
comment|/* otherwise */
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
comment|/* if it is not an X.29 connection */
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_flags
operator|&
operator|(
name|DC_X29W
operator||
name|DC_X29
operator||
name|DC_RAW
operator|)
operator|)
operator|==
literal|0
condition|)
endif|#
directive|endif
name|clear_lcn
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/* clear the LCN */
block|}
block|}
name|dc
operator|++
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                     DIAGS_COMPLETED()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine checks to see that power up diagnostics have completed*/
end_comment

begin_comment
comment|/*    It waits for a while if necessary.                                 */
end_comment

begin_comment
comment|/*  Call:          diags_completed(ds)                                   */
end_comment

begin_comment
comment|/*  Argument:      ds - pointer to softc structure;                      */
end_comment

begin_comment
comment|/*  Returns:       0 if board is up, EINTR if it never came on line.     */
end_comment

begin_comment
comment|/*  Called by:     ddaioctl()                                            */
end_comment

begin_comment
comment|/*  Calls to:                                                            */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|diags_completed
argument_list|(
argument|ds
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|nretries
init|=
literal|10
decl_stmt|;
comment|/*      * It's overkill to check this on EVERY ioctl, because it only matters if      * we are going to touch the board.  But the driver has had repeated      * problems with not checking it when it should have - overkill is      * preferred.  The delays are here rather then in the acpconfig program      * due to a bug in acpconfig.  They will only be executed during      * /etc/rc.local when the board has not had a chance to do the "B"      * interrupt yet.  At that time the machine will be running essentially      * single thread so it won't really matter where the delays are.  (ie, if      * we put the delay into acpconfig and kept calling here 10 times, the      * machine would not do anything else useful in the meantime - might as      * well loop here).       */
while|while
condition|(
operator|(
operator|(
name|ds
operator|->
name|dda_flags
operator|&
name|DDAF_OK
operator|)
operator|==
literal|0
operator|)
operator|&&
name|nretries
operator|--
operator|>
literal|0
condition|)
name|DELAY
argument_list|(
literal|3000000
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_flags
operator|&
name|DDAF_OK
operator|)
operator|==
literal|0
condition|)
comment|/* never came on line... */
return|return
operator|(
name|EINTR
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
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
comment|/*%%                      SEND_CONFIG()                          %%*/
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
comment|/*   Send a Set System Parameters Message to the front end in      */
end_comment

begin_comment
comment|/*   response to an ACPCONFIG command from the user.               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          send_config(ds, p)                              */
end_comment

begin_comment
comment|/*  Argument:      ds:  pointer to ACP device control structure    */
end_comment

begin_comment
comment|/*		   p: pointer to the message			   */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddaioctl()                                  */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     DDALOG()                                    */
end_comment

begin_comment
comment|/*                     mtod()                                      */
end_comment

begin_comment
comment|/*                     bcopy()                                     */
end_comment

begin_comment
comment|/*                     sizeof()                                    */
end_comment

begin_comment
comment|/*                     start_supr()                                 */
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
name|send_config
parameter_list|(
name|ds
parameter_list|,
name|p
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|u_char
modifier|*
name|p
decl_stmt|;
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|u_char
modifier|*
name|bp
decl_stmt|;
name|int
name|length
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|7
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: send_config()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|MGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
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
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|18
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: can't get bfr for acpconfig msg\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|bp
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
comment|/* point to data section of mbuf */
name|length
operator|=
name|p
index|[
name|MSG_LENGTH
index|]
operator|+
name|MSG_OFFSET
expr_stmt|;
comment|/* msg length */
if|if
condition|(
name|length
operator|>
name|MLEN
operator|-
literal|1
condition|)
block|{
comment|/* 	 * Supervisory messages have to fit in a small mbuf.  The driver 	 * itself is careful never to get in trouble this way, but now that 	 * we have "-m" the user could.  Dropping such a message is not 	 * likely to cause any big problems, and the user can rephrase the 	 * request.  	 */
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|19
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: supervisor message too long\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_next
operator|=
literal|0
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return;
block|}
name|bcopy
argument_list|(
name|p
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|m
operator|->
name|m_len
operator|=
name|length
expr_stmt|;
comment|/* set msg length */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|8
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|prt_bytes
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"send_config"
argument_list|,
name|bp
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|start_supr
argument_list|(
name|ds
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      LOCATE_X25_LCN()                       %%*/
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
comment|/*    This routine tries to locate an X25 LCN associated with a    */
end_comment

begin_comment
comment|/*    remote internet address.  A linear search of the LCN table   */
end_comment

begin_comment
comment|/*    is made for a matching address.  If the search succeeds, the */
end_comment

begin_comment
comment|/*    LCN is returned.  If the search fails, the LCN table is      */
end_comment

begin_comment
comment|/*    searched for an unused table entry.  If an unused table      */
end_comment

begin_comment
comment|/*    entry is found, an X25 call is generated to the host         */
end_comment

begin_comment
comment|/*    specified in the destination internet address.  If no LCN is */
end_comment

begin_comment
comment|/*    available, zero is returned.                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              locate_x25_lcn(ds, ip_addr)                 */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*                     ip_addr:  IP address                        */
end_comment

begin_comment
comment|/*  Returns:           pointer to the dda control block which      */
end_comment

begin_comment
comment|/*                     contains LCN, else zero for failure         */
end_comment

begin_comment
comment|/*  Called by:         ddaoutput()                                 */
end_comment

begin_comment
comment|/*  Calls to:          convert_ip_addr()                           */
end_comment

begin_comment
comment|/*                     make_x25_call()                             */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|struct
name|dda_cb
modifier|*
name|locate_x25_lcn
parameter_list|(
name|ds
parameter_list|,
name|ip_addr
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|in_addr
name|ip_addr
decl_stmt|;
block|{
specifier|register
name|int
name|lcn
decl_stmt|,
name|maxlcn
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|9
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: locate_x25_lcn()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|imp_addr
operator|.
name|ip
operator|=
name|ip_addr
expr_stmt|;
comment|/* DDN X.25 doesn't know net number */
if|if
condition|(
operator|!
operator|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0x80
operator|)
operator|==
literal|0x00
condition|)
block|{
comment|/* class A */
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0xc0
operator|)
operator|==
literal|0x80
condition|)
block|{
comment|/* class B */
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* class C, should check for class C */
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/* LCNLINK */
name|maxlcn
operator|=
name|nddach
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
expr_stmt|;
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
literal|1
index|]
operator|)
expr_stmt|;
comment|/* scan LCN table for addr match */
for|for
control|(
name|lcn
operator|=
literal|1
init|;
name|lcn
operator|<=
name|maxlcn
condition|;
name|lcn
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|==
name|imp_addr
operator|.
name|ip
operator|.
name|s_addr
operator|)
operator|&&
operator|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_CALL_PENDING
operator|||
name|dc
operator|->
name|dc_state
operator|==
name|LC_DATA_IDLE
operator|)
condition|)
return|return
operator|(
name|dc
operator|)
return|;
comment|/* return LCN */
name|dc
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|dc
operator|=
name|find_free_lcn
argument_list|(
name|ds
argument_list|)
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|ddacb_user_data
index|[
literal|0
index|]
operator|=
operator|(
name|u_char
operator|)
literal|0
expr_stmt|;
comment|/* we have no user data */
if|if
condition|(
name|convert_ip_addr
argument_list|(
name|ip_addr
argument_list|,
name|ddacb_called_addr
argument_list|,
name|ds
argument_list|)
operator|&&
name|make_x25_call
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|,
name|ip_addr
argument_list|,
name|X25_PROTO_IP
argument_list|)
condition|)
block|{
comment|/* addr can be converted */
name|dc
operator|->
name|dc_inaddr
operator|=
name|ip_addr
expr_stmt|;
comment|/* store dest ip addr */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
name|imp_addr
operator|.
name|ip
operator|.
name|s_addr
expr_stmt|;
comment|/* store match key */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|9
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|ip_addr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: locate_x25_lcn: made call to %d.%d.%d.%d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
return|return
operator|(
name|dc
operator|)
return|;
comment|/* and return the LCN */
block|}
else|else
block|{
return|return
operator|(
literal|0
operator|)
return|;
comment|/* give up */
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      FIND_FREE_LCN()                        %%*/
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
comment|/*    This routine tries to locate a free X25 LCN.                 */
end_comment

begin_comment
comment|/*    The LCN table is searched for an unused entry.               */
end_comment

begin_comment
comment|/*    If no LCN is available, zero is returned.                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              find_free_lcn(ds)                           */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*  Returns:           pointer to the dda control block which      */
end_comment

begin_comment
comment|/*                     contains LCN, else zero for failure         */
end_comment

begin_comment
comment|/*  Called by:         locate_x25_lcn()                            */
end_comment

begin_comment
comment|/*		       supr_msg()				   */
end_comment

begin_comment
comment|/*		       xxcntl()					   */
end_comment

begin_comment
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|struct
name|dda_cb
modifier|*
name|find_free_lcn
parameter_list|(
name|ds
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
block|{
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|,
name|maxlcn
decl_stmt|,
name|dwnflg
init|=
literal|0
decl_stmt|;
comment|/* LCNLINK */
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
literal|1
index|]
operator|)
expr_stmt|;
comment|/* scan LCN table for free entry */
name|maxlcn
operator|=
name|nddach
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
expr_stmt|;
for|for
control|(
name|lcn
operator|=
literal|1
init|;
name|lcn
operator|<=
name|maxlcn
condition|;
name|lcn
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_IDLE
operator|&&
operator|(
name|dc
operator|->
name|dc_flags
operator|&
operator|(
name|DC_X29W
operator||
name|DC_X29
operator||
name|DC_RAW
operator|)
operator|)
operator|==
literal|0
condition|)
else|#
directive|else
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_IDLE
condition|)
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
break|break;
elseif|else
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_RESTART
operator|||
name|dc
operator|->
name|dc_state
operator|==
name|LC_DOWN
condition|)
name|dwnflg
operator|=
literal|1
expr_stmt|;
name|dc
operator|++
expr_stmt|;
block|}
comment|/* LCNLINK */
if|if
condition|(
name|lcn
operator|>
name|maxlcn
condition|)
block|{
comment|/* if we didn't find a free entry */
if|if
condition|(
name|LOG_BUSY
condition|)
block|{
if|if
condition|(
name|dwnflg
condition|)
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: no circuits available (link not up)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
else|else
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: all circuits in use\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return empty handed */
block|}
return|return
operator|(
name|dc
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      CONVERT_IP_ADDR()                      %%*/
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
comment|/*    Based on the type of X.25 service, this routine performs     */
end_comment

begin_comment
comment|/*    one of two functions.  For PDN X.25 service, the address     */
end_comment

begin_comment
comment|/*    translation table is searched for presence of local X.25     */
end_comment

begin_comment
comment|/*    address (which was entered by the user via acpconfig).       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    For DDN X.25 service, this routine accepts an internet       */
end_comment

begin_comment
comment|/*    address and attempts to translate to an equivalent X25       */
end_comment

begin_comment
comment|/*    address.  This follows the guidelines in the DDN X25         */
end_comment

begin_comment
comment|/*    interface spec.  The resultant X25 address is stored in the  */
end_comment

begin_comment
comment|/*    X25 called addr buffer.                                      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    NOTE: Although front end was designed to accept ASCII coded  */
end_comment

begin_comment
comment|/*    digits for the address fields, we only supply the binary     */
end_comment

begin_comment
comment|/*    values.  The front end only uses low four bits to extract    */
end_comment

begin_comment
comment|/*    the binary value from the ASCII digits, so this works out.   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              convert_ip_addr(ip_addr, x25addr, ds)       */
end_comment

begin_comment
comment|/*  Argument:          ip_addr:  IP address                        */
end_comment

begin_comment
comment|/*                     x25addr:  X.25 address                      */
end_comment

begin_comment
comment|/*                     ds:&dda_softc[unit]                  */
end_comment

begin_comment
comment|/*  Returns:           1 for success                               */
end_comment

begin_comment
comment|/*  Called by:         locate_x25_lcn()                            */
end_comment

begin_comment
comment|/*                     make_x25_call()                             */
end_comment

begin_comment
comment|/*                     ddaioctl()                                  */
end_comment

begin_comment
comment|/*  Calls to:          bcopy()                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|boolean
name|convert_ip_addr
parameter_list|(
name|ip_addr
parameter_list|,
name|x25addr
parameter_list|,
name|ds
parameter_list|)
name|struct
name|in_addr
name|ip_addr
decl_stmt|;
name|u_char
name|x25addr
index|[]
decl_stmt|;
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_addr_tr
modifier|*
name|atp
decl_stmt|,
modifier|*
name|hip
decl_stmt|,
modifier|*
name|lop
decl_stmt|;
specifier|register
name|int
name|temp
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
comment|/****************************************************************/
comment|/* processing for Public Data Network (PDN) X.25 service        */
comment|/* search address translation table for local address           */
comment|/****************************************************************/
if|if
condition|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
condition|)
block|{
name|x25addr
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* clear result X.25 address length */
name|lop
operator|=
operator|&
name|dda_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|[
literal|0
index|]
expr_stmt|;
comment|/* set up for binary 							 * search */
name|hip
operator|=
operator|&
name|dda_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|[
name|dda_num_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|]
expr_stmt|;
while|while
condition|(
name|lop
operator|<
name|hip
operator|-
literal|1
condition|)
block|{
comment|/* binary search loop */
name|atp
operator|=
name|lop
operator|+
operator|(
name|hip
operator|-
name|lop
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|atp
operator|->
name|ip_addr
operator|>
name|ip_addr
operator|.
name|s_addr
condition|)
name|hip
operator|=
name|atp
expr_stmt|;
else|else
name|lop
operator|=
name|atp
expr_stmt|;
block|}
if|if
condition|(
name|lop
operator|->
name|ip_addr
operator|==
name|ip_addr
operator|.
name|s_addr
condition|)
name|bcopy
argument_list|(
name|lop
operator|->
name|x25_addr
argument_list|,
name|x25addr
argument_list|,
name|MAXADDRLEN
argument_list|)
expr_stmt|;
block|}
comment|/****************************************************************/
comment|/* processing for DDN Standard or Basic X.25 service            */
comment|/* convert IP address to X.25 address                           */
comment|/****************************************************************/
else|else
block|{
name|int
name|imp_no
decl_stmt|,
name|imp_port
decl_stmt|;
name|imp_addr
operator|.
name|ip
operator|=
name|ip_addr
expr_stmt|;
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0x80
operator|)
operator|==
literal|0x00
condition|)
block|{
comment|/* class A */
name|imp_no
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
expr_stmt|;
name|imp_port
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0xc0
operator|)
operator|==
literal|0x80
condition|)
block|{
comment|/* class B */
name|imp_no
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
expr_stmt|;
name|imp_port
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
expr_stmt|;
block|}
else|else
block|{
comment|/* class C */
name|imp_no
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|/
literal|32
expr_stmt|;
name|imp_port
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|%
literal|32
expr_stmt|;
block|}
name|x25addr
index|[
literal|0
index|]
operator|=
literal|12
expr_stmt|;
comment|/* set addr length */
name|x25addr
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|/* clear DNIC */
name|x25addr
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|x25addr
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|x25addr
index|[
literal|4
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|imp_port
operator|<
literal|64
condition|)
block|{
comment|/* Physical:  0000 0 IIIHH00 [SS] */
comment|/* s_impno 				 *  -> III, s_host -> HH */
name|x25addr
index|[
literal|5
index|]
operator|=
literal|0
expr_stmt|;
comment|/* set flag bit */
name|x25addr
index|[
literal|6
index|]
operator|=
name|imp_no
operator|/
literal|100
expr_stmt|;
name|x25addr
index|[
literal|7
index|]
operator|=
operator|(
name|imp_no
operator|%
literal|100
operator|)
operator|/
literal|10
expr_stmt|;
name|x25addr
index|[
literal|8
index|]
operator|=
name|imp_no
operator|%
literal|10
expr_stmt|;
name|x25addr
index|[
literal|9
index|]
operator|=
name|imp_port
operator|/
literal|10
expr_stmt|;
name|x25addr
index|[
literal|10
index|]
operator|=
name|imp_port
operator|%
literal|10
expr_stmt|;
block|}
else|else
block|{
comment|/* Logical:   0000 1 RRRRR00 [SS]	 */
comment|/* s 				 * _host * 256 + s_impno -> RRRRR */
name|temp
operator|=
operator|(
name|imp_port
operator|<<
literal|8
operator|)
operator|+
name|imp_no
expr_stmt|;
name|x25addr
index|[
literal|5
index|]
operator|=
literal|1
expr_stmt|;
name|x25addr
index|[
literal|6
index|]
operator|=
name|temp
operator|/
literal|10000
expr_stmt|;
name|x25addr
index|[
literal|7
index|]
operator|=
operator|(
name|temp
operator|%
literal|10000
operator|)
operator|/
literal|1000
expr_stmt|;
name|x25addr
index|[
literal|8
index|]
operator|=
operator|(
name|temp
operator|%
literal|1000
operator|)
operator|/
literal|100
expr_stmt|;
name|x25addr
index|[
literal|9
index|]
operator|=
operator|(
name|temp
operator|%
literal|100
operator|)
operator|/
literal|10
expr_stmt|;
name|x25addr
index|[
literal|10
index|]
operator|=
name|temp
operator|%
literal|10
expr_stmt|;
block|}
name|x25addr
index|[
literal|11
index|]
operator|=
literal|0
expr_stmt|;
comment|/* clear rest of addr */
name|x25addr
index|[
literal|12
index|]
operator|=
literal|0
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|11
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|ip_addr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: convert_ip_addr: %d.%d.%d.%d ==> %s\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|,
name|fmt_x25
argument_list|(
argument|&x25addr[
literal|1
argument|]
argument_list|,
argument|(int) x25addr[
literal|0
argument|]
argument_list|)
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
return|return
operator|(
name|x25addr
index|[
literal|0
index|]
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      CONVERT_X25_ADDR()                     %%*/
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
comment|/*    This routine accepts an X25 address and attempts to          */
end_comment

begin_comment
comment|/*    translate to an equivalent internet address.  For DDA this   */
end_comment

begin_comment
comment|/*    follows the guidelines in the DDA X25 interface spec.  The   */
end_comment

begin_comment
comment|/*    resultant internet address is returned to the caller.        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              convert_x25_addr(x25addr, ds)               */
end_comment

begin_comment
comment|/*  Argument:          x25addr:  X.25 address                      */
end_comment

begin_comment
comment|/*                     ds:&dda_softc[unit]                  */
end_comment

begin_comment
comment|/*                     dc: pointer to allocated dda_cb structure   */
end_comment

begin_comment
comment|/*  Returns:           IP address for success, else zero for fail  */
end_comment

begin_comment
comment|/*  Called by:         supr_msg()                                  */
end_comment

begin_comment
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|u_long
name|convert_x25_addr
parameter_list|(
name|x25addr
parameter_list|,
name|ds
parameter_list|,
name|dc
parameter_list|)
name|u_char
name|x25addr
index|[]
decl_stmt|;
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
block|{
specifier|register
name|int
name|cnt
decl_stmt|,
name|temp
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
specifier|register
name|struct
name|dda_addr_tr
modifier|*
name|atp
decl_stmt|;
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
name|imp_addr
operator|.
name|ip
operator|.
name|s_addr
operator|=
literal|0L
expr_stmt|;
if|if
condition|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PDN
condition|)
block|{
for|for
control|(
name|atp
operator|=
operator|&
name|dda_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|[
literal|0
index|]
init|;
name|atp
operator|<
operator|&
name|dda_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|[
name|dda_num_addr_tr
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
index|]
condition|;
name|atp
operator|++
control|)
block|{
if|if
condition|(
name|bcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
name|atp
operator|->
name|x25_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|x25addr
argument_list|,
name|x25addr
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* set key address and print address up */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
name|imp_addr
operator|.
name|ip
operator|.
name|s_addr
operator|=
name|atp
operator|->
name|ip_addr
expr_stmt|;
break|break;
block|}
block|}
block|}
else|else
block|{
name|int
name|imp_no
decl_stmt|,
name|imp_port
decl_stmt|;
name|struct
name|in_addr
name|my_addr
decl_stmt|;
name|my_addr
operator|=
name|ds
operator|->
name|dda_ipaddr
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|cnt
operator|=
name|x25addr
index|[
literal|0
index|]
operator|)
operator|<
name|MINADDRLEN
operator|-
literal|1
operator|)
operator|||
operator|(
name|cnt
operator|>
name|MAXADDRLEN
operator|-
literal|1
operator|)
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|20
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: illegal X25 address length!\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0L
operator|)
return|;
block|}
switch|switch
condition|(
name|x25addr
index|[
literal|5
index|]
operator|&
literal|0x0f
condition|)
block|{
case|case
literal|0
case|:
comment|/* Physical:  0000 0 IIIHH00 [SS]	 */
name|imp_no
operator|=
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|6
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|100
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|7
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|10
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|8
index|]
operator|&
literal|0x0f
argument_list|)
operator|)
expr_stmt|;
name|imp_port
operator|=
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|9
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|10
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|10
index|]
operator|&
literal|0x0f
argument_list|)
operator|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* Logical:   0000 1 RRRRR00 [SS]	 */
name|temp
operator|=
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|6
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|10000
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|7
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|1000
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|8
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|100
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|9
index|]
operator|&
literal|0x0f
argument_list|)
operator|*
literal|10
operator|)
operator|+
operator|(
call|(
name|int
call|)
argument_list|(
name|x25addr
index|[
literal|10
index|]
operator|&
literal|0x0f
argument_list|)
operator|)
expr_stmt|;
name|imp_port
operator|=
name|temp
operator|>>
literal|8
expr_stmt|;
name|imp_no
operator|=
name|temp
operator|&
literal|0xff
expr_stmt|;
break|break;
default|default:
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|21
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: illegal X25 address format!\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0L
operator|)
return|;
block|}
name|dc
operator|->
name|dc_inaddr
operator|=
name|imp_addr
operator|.
name|ip
operator|=
name|my_addr
expr_stmt|;
comment|/* use local net number */
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0x80
operator|)
operator|==
literal|0x00
condition|)
block|{
comment|/* class A */
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
comment|/* mask net number */
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|=
literal|0
expr_stmt|;
comment|/* mask logical host */
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|=
name|imp_port
expr_stmt|;
operator|(
operator|(
expr|union
name|imp_addr
operator|*
operator|)
operator|&
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|)
operator|->
name|imp
operator|.
name|s_host
operator|=
name|imp_port
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|=
name|imp_no
expr_stmt|;
operator|(
operator|(
expr|union
name|imp_addr
operator|*
operator|)
operator|&
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|)
operator|->
name|imp
operator|.
name|s_impno
operator|=
name|imp_no
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|&
literal|0xc0
operator|)
operator|==
literal|0x80
condition|)
block|{
comment|/* class B */
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|=
name|imp_port
expr_stmt|;
operator|(
operator|(
expr|union
name|imp_addr
operator|*
operator|)
operator|&
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|)
operator|->
name|imp
operator|.
name|s_lh
operator|=
name|imp_port
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|=
name|imp_no
expr_stmt|;
operator|(
operator|(
expr|union
name|imp_addr
operator|*
operator|)
operator|&
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|)
operator|->
name|imp
operator|.
name|s_impno
operator|=
name|imp_no
expr_stmt|;
block|}
else|else
block|{
comment|/* class C */
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|=
operator|(
name|imp_no
operator|<<
literal|5
operator|)
operator|+
name|imp_port
expr_stmt|;
operator|(
operator|(
expr|union
name|imp_addr
operator|*
operator|)
operator|&
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|)
operator|->
name|imp
operator|.
name|s_impno
operator|=
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|=
literal|0
expr_stmt|;
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|=
literal|0
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|12
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: convert_x25_addr: %s ==> %d.%d.%d.%d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|fmt_x25
argument_list|(
operator|&
name|x25addr
index|[
literal|1
index|]
argument_list|,
operator|(
name|int
operator|)
name|x25addr
index|[
literal|0
index|]
argument_list|)
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
return|return
operator|(
name|imp_addr
operator|.
name|ip
operator|.
name|s_addr
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      MAKE_X25_CALL()                        %%*/
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
comment|/*    This routine places an X25 call using the X25 Call Msg       */
end_comment

begin_comment
comment|/*    buffer.  The calling LCN is placed in the appropriate state  */
end_comment

begin_comment
comment|/*    and a timer is started.  Based on dda_init flag, implement   */
end_comment

begin_comment
comment|/*    DDN standard or basic service.  (If PDN mode is set, then    */
end_comment

begin_comment
comment|/*    the logic for basic service is followed.)                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              make_x25_call(ds, dc, ip_addr, proto	   */
end_comment

begin_comment
comment|/*				     udlen, ud) 		   */
end_comment

begin_comment
comment|/*  Arguments:         ds:  pointer to device control structure    */
end_comment

begin_comment
comment|/*                     dc:  pointer to the Logical Channel control */
end_comment

begin_comment
comment|/*                            block structure                      */
end_comment

begin_comment
comment|/*                     ip_addr: callee's ip address                */
end_comment

begin_comment
comment|/*                     proto: protocol identifier byte             */
end_comment

begin_comment
comment|/*		       udlen: user data length			   */
end_comment

begin_comment
comment|/*		       ud:    user data				   */
end_comment

begin_comment
comment|/*  Returns:           one for success, zero for failure           */
end_comment

begin_comment
comment|/*  Called by:         locate_x25_lcn()                            */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     mtod()                                      */
end_comment

begin_comment
comment|/*                     convert_ip_addr()                           */
end_comment

begin_comment
comment|/*                     bcopy()                                     */
end_comment

begin_comment
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     start_supr()                                */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|boolean
name|make_x25_call
parameter_list|(
name|ds
parameter_list|,
name|dc
parameter_list|,
name|ip_addr
parameter_list|,
name|proto
parameter_list|,
name|udlen
parameter_list|,
name|ud
parameter_list|)
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|struct
name|in_addr
name|ip_addr
decl_stmt|;
name|u_char
name|proto
decl_stmt|;
name|u_char
name|udlen
decl_stmt|;
name|u_char
modifier|*
name|ud
decl_stmt|;
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m_callbfr
decl_stmt|;
specifier|register
name|u_char
modifier|*
name|cb
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|struct
name|sockaddr_in
modifier|*
name|our_addr
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|13
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: make_x25_call: lcn used = %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|MGET
argument_list|(
name|m_callbfr
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
comment|/* try to get call cmnd 						 * buffer */
if|if
condition|(
name|m_callbfr
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|22
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: couldn't get mbuf for call command\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|cb
operator|=
name|mtod
argument_list|(
name|m_callbfr
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
if|if
condition|(
name|ds
operator|->
name|dda_net_id
operator|==
name|TRANSPAC
condition|)
block|{
name|ddacb_calling_addr
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* send a 0 length calling address */
block|}
else|else
block|{
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|our_addr
operator|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
operator|(
name|ds
operator|->
name|dda_if
operator|.
name|if_addr
operator|)
expr_stmt|;
operator|(
name|void
operator|)
name|convert_ip_addr
argument_list|(
name|our_addr
operator|->
name|sin_addr
argument_list|,
name|ddacb_calling_addr
argument_list|,
name|ds
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|convert_ip_addr
argument_list|(
name|ds
operator|->
name|dda_ipaddr
argument_list|,
name|ddacb_calling_addr
argument_list|,
name|ds
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|ddacb_protocol
index|[
literal|0
index|]
operator|=
literal|4
expr_stmt|;
name|ddacb_protocol
index|[
literal|1
index|]
operator|=
name|proto
expr_stmt|;
comment|/* protocol type */
name|ddacb_protocol
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|ddacb_protocol
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|ddacb_protocol
index|[
literal|4
index|]
operator|=
literal|0
expr_stmt|;
comment|/*      * CCITT standard facilities must precede DDN specific facilities See BBN      * report 5476 section 2.1.2.  Firmware preceding rev 0x20 does not      * support packet size / window negotiation.       */
name|ddacb_facilities
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* initialize facilities length */
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|>=
literal|0x21
condition|)
block|{
name|ddacb_facilities
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_PKTNEG
condition|)
block|{
name|int
name|n
init|=
name|ddacb_facilities
index|[
literal|0
index|]
decl_stmt|;
comment|/* length so far */
name|ddacb_facilities
index|[
name|n
operator|+
literal|1
index|]
operator|=
name|X25_FACIL_PKTSIZE
expr_stmt|;
name|ddacb_facilities
index|[
name|n
operator|+
literal|2
index|]
operator|=
name|PKTSIZE_LARGE
expr_stmt|;
name|ddacb_facilities
index|[
name|n
operator|+
literal|3
index|]
operator|=
name|PKTSIZE_LARGE
expr_stmt|;
name|ddacb_facilities
index|[
literal|0
index|]
operator|+=
literal|3
expr_stmt|;
block|}
if|if
condition|(
name|ds
operator|->
name|dda_init
operator|&
name|DDA_WNDNEG
condition|)
block|{
name|int
name|n
init|=
name|ddacb_facilities
index|[
literal|0
index|]
decl_stmt|;
comment|/* length so far */
name|ddacb_facilities
index|[
name|n
operator|+
literal|1
index|]
operator|=
name|X25_FACIL_WINSIZE
expr_stmt|;
name|ddacb_facilities
index|[
name|n
operator|+
literal|2
index|]
operator|=
name|WINSIZE_LARGE
expr_stmt|;
name|ddacb_facilities
index|[
name|n
operator|+
literal|3
index|]
operator|=
name|WINSIZE_LARGE
expr_stmt|;
name|ddacb_facilities
index|[
literal|0
index|]
operator|+=
literal|3
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_init
operator|&
operator|(
name|DDA_BASIC
operator||
name|DDA_PDN
operator|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* DDN standard mode, 							 * tell callee */
name|int
name|n
init|=
name|ddacb_facilities
index|[
literal|0
index|]
decl_stmt|;
comment|/* length so far */
name|ddacb_facilities
index|[
literal|0
index|]
operator|+=
literal|4
expr_stmt|;
comment|/* additional facility bytes */
name|ddacb_facilities
index|[
name|n
operator|+
literal|1
index|]
operator|=
name|DDN_FACIL_MARKER
expr_stmt|;
comment|/* end of CCITT stuff, */
name|ddacb_facilities
index|[
name|n
operator|+
literal|2
index|]
operator|=
name|DDN_FACIL_MARKER
expr_stmt|;
comment|/* and start DDN local */
name|ddacb_facilities
index|[
name|n
operator|+
literal|3
index|]
operator|=
name|X25_FACIL_DDA
expr_stmt|;
comment|/* DDA standard mode */
name|ddacb_facilities
index|[
name|n
operator|+
literal|4
index|]
operator|=
name|FAC_DDASTD
expr_stmt|;
block|}
name|ddacb_cmnd
index|[
literal|0
index|]
operator|=
name|CALL
expr_stmt|;
comment|/* set command code */
name|ddacb_cmnd
index|[
literal|1
index|]
operator|=
name|dc
operator|->
name|dc_lcn
operator|<<
literal|1
expr_stmt|;
comment|/* set channel id */
name|ddacb_cmnd
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|ddacb_cmnd
index|[
literal|3
index|]
operator|=
operator|(
name|ddacb_called_addr
index|[
literal|0
index|]
operator|+
literal|1
operator|)
operator|+
comment|/* tally cmnd ext len */
operator|(
name|ddacb_calling_addr
index|[
literal|0
index|]
operator|+
literal|1
operator|)
operator|+
operator|(
name|ddacb_protocol
index|[
literal|0
index|]
operator|+
literal|1
operator|)
operator|+
operator|(
name|ddacb_facilities
index|[
literal|0
index|]
operator|+
literal|1
operator|)
operator|+
operator|(
name|ddacb_user_data
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|ddacb_cmnd
index|[
literal|3
index|]
operator|+
literal|4
operator|>
name|MLEN
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|38
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: make_x25_call message too large for mbuf (%d bytes)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
operator|(
name|unsigned
operator|)
name|ddacb_cmnd
index|[
literal|3
index|]
operator|+
literal|4
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* failure */
block|}
name|m_callbfr
operator|->
name|m_len
operator|=
name|ddacb_cmnd
index|[
literal|3
index|]
operator|+
literal|4
expr_stmt|;
comment|/* copy command header */
name|bcopy
argument_list|(
name|ddacb_cmnd
argument_list|,
name|cb
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|cb
operator|+=
literal|4
expr_stmt|;
comment|/* copy called address */
name|bcopy
argument_list|(
name|ddacb_called_addr
argument_list|,
name|cb
argument_list|,
name|ddacb_called_addr
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cb
operator|+=
operator|(
name|ddacb_called_addr
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* copy calling address */
name|bcopy
argument_list|(
name|ddacb_calling_addr
argument_list|,
name|cb
argument_list|,
name|ddacb_calling_addr
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cb
operator|+=
operator|(
name|ddacb_calling_addr
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* copy protocol */
name|bcopy
argument_list|(
name|ddacb_protocol
argument_list|,
name|cb
argument_list|,
name|ddacb_protocol
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cb
operator|+=
operator|(
name|ddacb_protocol
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* copy facilities */
name|bcopy
argument_list|(
name|ddacb_facilities
argument_list|,
name|cb
argument_list|,
name|ddacb_facilities
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cb
operator|+=
operator|(
name|ddacb_facilities
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* copy user data */
name|bcopy
argument_list|(
name|ddacb_user_data
argument_list|,
name|cb
argument_list|,
name|ddacb_user_data
index|[
literal|0
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
name|cb
operator|+=
operator|(
name|ddacb_user_data
index|[
literal|0
index|]
operator|+
literal|1
operator|)
expr_stmt|;
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_CALL_PENDING
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_CALL_PENDING
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_CALL_PENDING
expr_stmt|;
comment|/* start call timeout */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|13
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|prt_bytes
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"make_x25_call: call_bfr"
argument_list|,
name|mtod
argument_list|(
name|m_callbfr
argument_list|,
name|u_char
operator|*
argument_list|)
argument_list|,
name|m_callbfr
operator|->
name|m_len
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|ip_addr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Calling %d.%d.%d.%d (%s) on lcn %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|,
name|fmt_x25
argument_list|(
operator|&
name|ddacb_called_addr
index|[
literal|1
index|]
argument_list|,
operator|(
name|int
operator|)
name|ddacb_called_addr
index|[
literal|0
index|]
argument_list|)
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
name|start_supr
argument_list|(
name|ds
argument_list|,
name|m_callbfr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDA_START()                            %%*/
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
comment|/*    This routine attempts to start output of data queued on a    */
end_comment

begin_comment
comment|/*    specific LCN.  If the LCN was not already busy and data is   */
end_comment

begin_comment
comment|/*    available for output, the data is copied into the LCN's I/O  */
end_comment

begin_comment
comment|/*    buffer and a write request queued to the ACP device.  Data   */
end_comment

begin_comment
comment|/*    is passed in mbuf(s) from IP to ddaoutput(), ddaoutput()     */
end_comment

begin_comment
comment|/*    queues the data, and the data is dequeued here.              */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              dda_start(ds, dc)                           */
end_comment

begin_comment
comment|/*  Arguments:         ds:  pointer to device control structure    */
end_comment

begin_comment
comment|/*                     dc:  pointer to the Logical Channel control */
end_comment

begin_comment
comment|/*                            block structure                      */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddaoutput()                                 */
end_comment

begin_comment
comment|/*                     x25_init()                                  */
end_comment

begin_comment
comment|/*                     make_x25_call()                             */
end_comment

begin_comment
comment|/*                     supr_msg()                                  */
end_comment

begin_comment
comment|/*                     send_supr()                                 */
end_comment

begin_comment
comment|/*                     dda_data()                                  */
end_comment

begin_comment
comment|/*                     dda_supr()                                  */
end_comment

begin_comment
comment|/*  Calls to:          IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     dda_wrq()                                   */
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
name|dda_start
parameter_list|(
name|ds
parameter_list|,
name|dc
parameter_list|)
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
init|=
operator|&
name|dc
operator|->
name|dc_wchan
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|14
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_start()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/*      * If output isn't active, attempt to start sending a new packet.       */
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_OBUSY
operator|)
operator|||
operator|(
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
operator|==
literal|0
operator|)
operator|||
operator|(
operator|(
name|dc
operator|->
name|dc_lcn
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|dc
operator|->
name|dc_state
operator|!=
name|LC_DATA_IDLE
operator|)
operator|)
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|dc
operator|->
name|dc_lcn
operator|!=
literal|0
condition|)
name|dc
operator|->
name|dc_timer
operator|=
name|tmo_data_idle
expr_stmt|;
comment|/*  *  Raise priority whenever touching dc_oq because  *  the mbufs on this queue may be asynchronously  *  freed upon receipt of a line status msg, restart,  *  clear, or reset.  */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|IF_DEQUEUE
argument_list|(
operator|&
name|dc
operator|->
name|dc_oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
comment|/* XXX this is a bug catcher XXX */
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|24
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: dequeued NULL mbuf in IP output chain!\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|24
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"RESET dda%d MANUALLY: use /etc/acpconfig dda%d -z\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
operator|(
name|IFF_RUNNING
operator||
name|IFF_UP
operator|)
expr_stmt|;
name|hist_link_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
name|dda_disable
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
return|return;
block|}
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|m
expr_stmt|;
name|hc
operator|->
name|hc_curr
operator|=
name|m
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
comment|/* crufty kludge to get the Qbit */
if|if
condition|(
name|dc
operator|->
name|dc_flags
operator|&
operator|(
name|DC_X29
operator||
name|DC_X29W
operator||
name|DC_RAW
operator|)
condition|)
block|{
comment|/* raw or x29? */
if|if
condition|(
name|m
operator|->
name|m_len
operator|<
operator|(
name|MLEN
operator|-
literal|1
operator|)
condition|)
comment|/* small mbuf? */
name|hc
operator|->
name|hc_sbfc
operator|=
name|m
operator|->
name|m_dat
index|[
name|MLEN
operator|-
literal|1
index|]
expr_stmt|;
comment|/* ok, get the subfunc byte */
else|else
name|hc
operator|->
name|hc_sbfc
operator|=
literal|0
expr_stmt|;
comment|/* subfunc must be zero for large buffers */
block|}
else|else
name|hc
operator|->
name|hc_sbfc
operator|=
literal|0
expr_stmt|;
comment|/* subfunc must be zero for ip buffers */
else|#
directive|else
name|hc
operator|->
name|hc_sbfc
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_flags
operator||=
name|DC_OBUSY
expr_stmt|;
name|dda_wrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* write request to ACP */
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDA_DATA()                             %%*/
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
comment|/*    is sent to the IP input queue (if no error) and another read */
end_comment

begin_comment
comment|/*    is started on the LCN.                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              dda_data(ds, hc, cc, cnt)                   */
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
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddainta()                                   */
end_comment

begin_comment
comment|/*  Calls to:          m_freem()                                   */
end_comment

begin_comment
comment|/*                     dda_start()                                 */
end_comment

begin_comment
comment|/*                     IF_QFULL()                                  */
end_comment

begin_comment
comment|/*                     IF_DROP()                                   */
end_comment

begin_comment
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     schednetisr()                               */
end_comment

begin_comment
comment|/*                     dda_rrq()                                   */
end_comment

begin_comment
comment|/*                     dda_wrq()                                   */
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
name|dda_data
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|cc
parameter_list|,
name|cnt
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
name|struct
name|ifqueue
modifier|*
name|inq
init|=
operator|&
name|ipintrq
decl_stmt|;
comment|/* IP input queue */
comment|/* note that this routine is a weird case in which Ultrix 2.0 behaves like  * a 4.2 system rather than a 4.3 system.  This is reflected in the structure  * of conditional compilation segments.  */
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
comment|/* 4.3bsd or newer */
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|,
modifier|*
name|mb
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
else|#
directive|else
comment|/* 4.2, or all flavors of Ultrix */
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|18
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_data: chan=%d cc=%x cnt=%x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
operator|,
name|cc
operator|,
name|cnt
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
name|ifp
operator|=
operator|&
name|ds
operator|->
name|dda_if
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
block|{
comment|/* was it read or write? */
comment|/* write, fire up 				 * next output */
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
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_wchan
expr_stmt|;
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
name|hc_inv
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
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* read, process rcvd packet */
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_rchan
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|19
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|u_char
modifier|*
name|p
decl_stmt|;
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
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"received data"
argument_list|,
name|p
argument_list|,
operator|(
name|cnt
operator|<
literal|64
condition|?
name|cnt
else|:
literal|64
operator|)
argument_list|)
expr_stmt|;
block|}
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
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|19
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_data: chan=%d DDAIOCOK\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|ds
operator|->
name|dda_if
operator|.
name|if_ipackets
operator|++
expr_stmt|;
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_DATA_IDLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_DATA_IDLE
condition|)
name|dc
operator|->
name|dc_timer
operator|=
name|tmo_data_idle
expr_stmt|;
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|+=
name|cnt
expr_stmt|;
comment|/* update byte count */
name|m
operator|=
name|hc
operator|->
name|hc_mbuf
expr_stmt|;
comment|/* que mbuf chain */
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
comment|/* Prepend ifp pointer for 4.3 */
name|MGET
argument_list|(
name|mb
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
if|if
condition|(
name|mb
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|26
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: couldn't get mbuf for ifp header\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return;
block|}
operator|*
operator|(
name|mtod
argument_list|(
name|mb
argument_list|,
expr|struct
name|ifnet
operator|*
operator|*
argument_list|)
operator|)
operator|=
name|ifp
expr_stmt|;
name|mb
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
name|ifp
argument_list|)
expr_stmt|;
name|mb
operator|->
name|m_next
operator|=
name|m
expr_stmt|;
if|if
condition|(
name|IF_QFULL
argument_list|(
name|inq
argument_list|)
condition|)
block|{
name|IF_DROP
argument_list|(
name|inq
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|mb
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|IF_ENQUEUE
argument_list|(
name|inq
argument_list|,
name|mb
argument_list|)
expr_stmt|;
name|schednetisr
argument_list|(
name|NETISR_IP
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
if|if
condition|(
name|IF_QFULL
argument_list|(
name|inq
argument_list|)
condition|)
block|{
name|IF_DROP
argument_list|(
name|inq
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|IF_ENQUEUE
argument_list|(
name|inq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|schednetisr
argument_list|(
name|NETISR_IP
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
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
block|{
comment|/* good completion, more data pending */
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|+=
name|cnt
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
block|}
comment|/* hang a new data read */
name|dda_rrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDA_SUPR()                             %%*/
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
comment|/*    This routine is called when a supervisor I/O completes.      */
end_comment

begin_comment
comment|/*    If the completion was for a write, an attempt is made to     */
end_comment

begin_comment
comment|/*    start output on the next supervisor command waiting for      */
end_comment

begin_comment
comment|/*    output.  If the completion was for a read, the received      */
end_comment

begin_comment
comment|/*    supervisor message is processed and another read is started. */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              dda_supr(ds, hc, cc)                        */
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
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddainta()                                   */
end_comment

begin_comment
comment|/*  Calls to:          dda_start()                                 */
end_comment

begin_comment
comment|/*                     mtod()                                      */
end_comment

begin_comment
comment|/*                     supr_msg()                                  */
end_comment

begin_comment
comment|/*                     m_free()                                    */
end_comment

begin_comment
comment|/*                     dda_rrq()                                   */
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
name|dda_supr
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|cc
parameter_list|,
name|cnt
parameter_list|)
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
name|int
name|cc
decl_stmt|;
name|int
name|cnt
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
name|u_char
modifier|*
name|p
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|20
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_supr: chan=%d cc=%x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
operator|,
name|cc
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/* an odd-numbered channel indicates a write */
comment|/* the supr msg is assumed to be in 1 mbuf   */
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|0x01
condition|)
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
name|dc
operator|->
name|dc_flags
operator|&=
operator|~
name|DC_OBUSY
expr_stmt|;
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
block|}
comment|/* otherwise, process the read */
else|else
block|{
if|if
condition|(
name|cc
operator|==
name|DDAIOCOK
condition|)
block|{
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
comment|/* point to data in mbuf */
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
switch|switch
condition|(
name|dda_decode_type
argument_list|(
name|ds
argument_list|,
name|p
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DDA_PADOPT
case|case
literal|1
case|:
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|20
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"dda%d: dda_supr(): case 1: chan = %x, p = %x\n"
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|hc
operator|->
name|hc_chan
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|x29_supr
argument_list|(
name|ds
argument_list|,
name|p
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_RAWOPT
case|case
literal|2
case|:
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|20
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"dda%d: dda_supr(): case 2: chan = %x, p = %x\n"
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|hc
operator|->
name|hc_chan
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|+=
name|cnt
expr_stmt|;
name|pi_supr
argument_list|(
name|ds
argument_list|,
name|hc
operator|->
name|hc_curr
argument_list|)
expr_stmt|;
comment|/* don't free mbuf here */
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
comment|/* hang a new supr read */
return|return;
endif|#
directive|endif
default|default:
name|supr_msg
argument_list|(
name|ds
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* process supervisor message */
break|break;
block|}
else|#
directive|else
else|DDA_PAD_OR_RAW
name|supr_msg
argument_list|(
name|ds
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* process supervisor message */
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
block|}
elseif|else
if|if
condition|(
name|cc
operator|==
name|DDAIOCOKP
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|28
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: truncated supervisor message\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
block|}
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
comment|/* hang a new supr read */
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      SUPR_MSG()                             %%*/
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
comment|/*  Call:              supr_msg(ds, p)                             */
end_comment

begin_comment
comment|/*  Arguments:         ds:  pointer to dev control block struct    */
end_comment

begin_comment
comment|/*                     p:   pointer to a character array           */
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
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                     IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                     send_restart()                              */
end_comment

begin_comment
comment|/*                     send_supr()                                 */
end_comment

begin_comment
comment|/*                     dda_start()                                 */
end_comment

begin_comment
comment|/*                     decode_ring()                               */
end_comment

begin_comment
comment|/*                     decode_answer()                             */
end_comment

begin_comment
comment|/*                     convert_x25_addr()                          */
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
name|supr_msg
parameter_list|(
name|ds
parameter_list|,
name|p
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|u_char
name|p
index|[]
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
specifier|register
name|int
name|maxlcn
decl_stmt|;
name|union
name|imp_addr
name|imp_addr
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|prt_bytes
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"supr_msg"
argument_list|,
name|p
argument_list|,
call|(
name|int
call|)
argument_list|(
literal|4
operator|+
name|p
index|[
literal|3
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|maxlcn
operator|=
name|nddach
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
expr_stmt|;
comment|/* obtain SVC limit */
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
if|if
condition|(
name|p
index|[
literal|2
index|]
operator|==
name|LINK_UP
condition|)
block|{
comment|/* if link came up */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: supr_msg: HDLC link up\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|send_restart
argument_list|(
name|ds
argument_list|)
expr_stmt|;
comment|/* send restart msg */
name|ds
operator|->
name|dda_state
operator|=
name|S_COMING_UP
expr_stmt|;
block|}
else|else
block|{
comment|/* if link went down */
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
comment|/* ? should call if_down() ? */
name|hist_link_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
comment|/* LCNLINK */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|maxlcn
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* forget dest address */
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
name|dc_state
operator|=
name|LC_DOWN
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* stop timer */
name|dc
operator|++
expr_stmt|;
block|}
name|hist_all_lcns
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|LC_DOWN
argument_list|)
expr_stmt|;
name|abort_io
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ALL_CHANS
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_PADOPT
name|x29_init
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|p
index|[
literal|2
index|]
operator|==
name|LINK_DISABLED
condition|)
comment|/* link disabled */
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|29
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:  link disabled\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
else|else
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|30
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:  link down\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|RESTART
case|:
comment|/* restart received */
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_state
operator|!=
name|LC_RESTART
condition|)
block|{
comment|/* if not restarting */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: supr_msg: RESTART rcvd, no RESTART pending\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|send_supr
argument_list|(
name|ds
argument_list|,
name|RSTRT_ACK
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* send restart ack */
block|}
comment|/* fall thru */
case|case
name|RSTRT_ACK
case|:
comment|/* restart ack */
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_state
operator|==
name|S_COMING_UP
operator|)
operator|||
operator|(
name|ds
operator|->
name|dda_state
operator|==
name|S_LINK_UP
operator|)
condition|)
block|{
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|==
name|RSTRT_ACK
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|31
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Restart Ack received\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* restart. print cause and diagnostic. */
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|31
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Restart (%x %x) received\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
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
condition|?
name|p
index|[
literal|4
index|]
else|:
literal|0
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
block|}
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator||=
name|IFF_UP
expr_stmt|;
name|hist_link_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_LINK_UP
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_LINK_UP
expr_stmt|;
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
comment|/* LCNLINK */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|maxlcn
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's */
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* stop timer */
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
operator|++
expr_stmt|;
block|}
name|hist_all_lcns
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|LC_IDLE
argument_list|)
expr_stmt|;
name|abort_io
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ALL_CHANS
argument_list|)
expr_stmt|;
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|32
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: (%s rev %d.%d) link up\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dda_product
operator|,
operator|(
name|ds
operator|->
name|dda_firmrev
operator|>>
literal|4
operator|)
operator|&
literal|0xF
operator|,
name|ds
operator|->
name|dda_firmrev
operator|&
literal|0xF
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
name|x29_init
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 	     * wake up all processes that tried to open a x29 device but 	     * slept because the board was not up  	     */
name|wakeup
argument_list|(
operator|&
name|ds
operator|->
name|dda_state
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
block|}
elseif|else
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:  Unexpected RESTART in state %x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|ds
operator|->
name|dda_state
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
break|break;
case|case
name|ANSWER
case|:
comment|/* call answered */
name|lcn
operator|=
name|p
index|[
literal|1
index|]
operator|/
literal|2
expr_stmt|;
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
operator|)
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_CALL_PENDING
condition|)
block|{
comment|/* if a call pending */
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_DATA_IDLE
argument_list|)
expr_stmt|;
name|decode_answer
argument_list|(
name|p
argument_list|,
name|dc
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_DATA_IDLE
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|tmo_data_idle
expr_stmt|;
comment|/* start timer */
name|dda_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/* try to send data */
block|}
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: lcn %d connected\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|lcn
name|DDAELOG
expr_stmt|;
block|}
break|break;
case|case
name|RING
case|:
comment|/* incoming call */
comment|/* if ring looks ok, and we find a free LCN to assign */
if|if
condition|(
name|decode_ring
argument_list|(
name|p
argument_list|)
operator|&&
operator|(
name|dc
operator|=
name|find_free_lcn
argument_list|(
name|ds
argument_list|)
operator|)
condition|)
block|{
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
name|convert_x25_addr
argument_list|(
name|ddacb_calling_addr
argument_list|,
name|ds
argument_list|,
name|dc
argument_list|)
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
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: supr_msg: got call from %d.%d.%d.%d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_DATA_IDLE
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_DATA_IDLE
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|tmo_data_idle
expr_stmt|;
comment|/* start timer */
name|dc
operator|->
name|dc_pktsizein
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|send_supr
argument_list|(
name|ds
argument_list|,
name|ANSWER
argument_list|,
operator|(
name|int
operator|)
name|dc
operator|->
name|dc_lcn
operator|*
literal|2
argument_list|,
operator|(
name|int
operator|)
name|p
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* send answer */
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Accepting call from %d.%d.%d.%d (%s) on lcn %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|,
name|fmt_x25
argument_list|(
operator|&
name|ddacb_calling_addr
index|[
literal|1
index|]
argument_list|,
operator|(
name|int
operator|)
name|ddacb_calling_addr
index|[
literal|0
index|]
argument_list|)
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* if no free LCN's */
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
block|{
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Rejecting call from %s on VC 0x%x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|fmt_x25
argument_list|(
operator|&
name|ddacb_calling_addr
index|[
literal|1
index|]
argument_list|,
name|ddacb_calling_addr
index|[
literal|0
index|]
argument_list|)
operator|,
name|p
index|[
literal|1
index|]
name|DDAELOG
expr_stmt|;
block|}
block|}
break|break;
case|case
name|CLEARLC
case|:
comment|/* clear by LCN */
comment|/* 	 * This could mean one of three things: If we have a call request 	 * outstanding, this message means the call has failed. If we have a 	 * clear request outstanding, this message completes the cleanup; the 	 * channel is now available for reuse. If we have a call active, this 	 * message means the other side is closing the circuit.  	 */
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
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
operator|)
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|!=
name|LC_CLR_PENDING
condition|)
block|{
comment|/* if no clear pending */
name|send_supr
argument_list|(
name|ds
argument_list|,
name|CLEARLC
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* ack the clear */
block|}
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_CALL_PENDING
comment|/* if call is cleared */
operator|&&
operator|(
name|LOG_CALLS
operator|||
name|DMESGVAL
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|33
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Call to %d.%d.%d.%d on lcn %d failed (%x %x)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|,
name|dc
operator|->
name|dc_lcn
operator|,
name|p
index|[
literal|2
index|]
operator|,
name|p
index|[
literal|4
index|]
name|DDAELOG
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_CLR_PENDING
condition|)
block|{
comment|/* did we clear it? */
comment|/* y 							 * es, IP address is 							 * already gone.  Say 							 * channel is free.  */
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Cleared lcn %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
else|else
block|{
comment|/* cleared by net, print more info */
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Cleared lcn %d to %d.%d.%d.%d (%x %x)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
operator|,
name|p
index|[
literal|2
index|]
operator|,
name|p
index|[
literal|4
index|]
name|DDAELOG
expr_stmt|;
block|}
block|}
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_IDLE
argument_list|)
expr_stmt|;
comment|/* LCNLINK delete */
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* stop timer */
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
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
name|printf
argument_list|(
literal|"dda%d: Cleared LCN %d cause code %x diag code %x\n"
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_lcn
argument_list|,
name|p
index|[
literal|2
index|]
argument_list|,
name|p
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|CLEARVC
case|:
comment|/* clear by VCN */
name|send_supr
argument_list|(
name|ds
argument_list|,
name|CLEARVC
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* send clear ack */
if|if
condition|(
name|LOG_CALLS
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Network cleared VC %x (%x %x)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
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
literal|4
index|]
name|DDAELOG
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DDADEBUG
elseif|else
if|if
condition|(
name|DDADBCH
argument_list|(
literal|21
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: supr_msg: CLEARVC VCN=%x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|p
index|[
literal|1
index|]
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
break|break;
case|case
name|RESET
case|:
comment|/* X25 reset */
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
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
operator|)
expr_stmt|;
name|send_supr
argument_list|(
name|ds
argument_list|,
name|RESET_ACK
argument_list|,
name|p
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* send reset ack */
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
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|34
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: X25 RESET (%x %x) on lcn %d: %d.%d.%d.%d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|p
index|[
literal|2
index|]
operator|,
name|p
index|[
literal|4
index|]
operator|,
name|lcn
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|INTERRUPT
case|:
comment|/* X25 interrupt */
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
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|lcn
index|]
operator|)
expr_stmt|;
name|imp_addr
operator|.
name|ip
operator|=
name|dc
operator|->
name|dc_inaddr
expr_stmt|;
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|35
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: X25 INTERRUPT (%x) on lcn %d: %d.%d.%d.%d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|p
index|[
literal|2
index|]
operator|,
name|lcn
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
operator|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|STATRESP
case|:
comment|/* Statistics Response from FEP */
comment|/* 	 * Copy the whole message into a static buffer, dda_iobuf. The buffer 	 * is viewed as a (struct ddactl).  Wake up the ioctl thread which 	 * will copy the message out for acpconfig.  	 */
block|{
name|struct
name|ddactl
modifier|*
name|da
init|=
operator|(
expr|struct
name|ddactl
operator|*
operator|)
name|dda_iobuf
decl_stmt|;
name|bcopy
argument_list|(
name|p
argument_list|,
name|da
operator|->
name|msg
argument_list|,
name|max
argument_list|(
literal|4
operator|+
name|p
index|[
literal|3
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|da
operator|->
name|msg
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MULTINET
name|StatQuery_Completed
operator|=
literal|1
expr_stmt|;
else|#
directive|else
name|wakeup
argument_list|(
name|dda_iobuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
block|}
default|default:
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|36
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: supervisor error (%x %x %x %x)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
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
comment|/*%%                   DECODE_ANSWER()                           %%*/
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
comment|/*        This routine looks at the answer message from the FE     */
end_comment

begin_comment
comment|/*  and decodes it to find the negtiated packet and window sizes   */
end_comment

begin_comment
comment|/*  if they are present.                                           */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              decode_answer(p, dc)	                   */
end_comment

begin_comment
comment|/*  Argument:          p: pointer to mbuf data for ANSWER message  */
end_comment

begin_comment
comment|/*                     dc: pointer to relavant lcn structure       */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         supr_msg()                                  */
end_comment

begin_comment
comment|/*  Calls to:                                                      */
end_comment

begin_comment
comment|/*                     DDALOG()                                    */
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
name|decode_answer
parameter_list|(
name|p
parameter_list|,
name|dc
parameter_list|)
name|u_char
modifier|*
name|p
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
block|{
specifier|register
name|u_char
modifier|*
name|cp
decl_stmt|;
name|int
name|i
decl_stmt|,
name|faclen
decl_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
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
name|cp
operator|+=
operator|*
name|cp
operator|+
literal|1
expr_stmt|;
comment|/* skip over protocol and protocol length 				 * byte */
comment|/* cp now points to the facilities length */
name|faclen
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
comment|/* cp now points to start of facilities */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|faclen
condition|;
control|)
block|{
switch|switch
condition|(
operator|*
name|cp
operator|&
literal|0xc0
condition|)
block|{
case|case
literal|0x00
case|:
comment|/* single octet parameter field */
name|i
operator|+=
literal|2
expr_stmt|;
name|cp
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|0x40
case|:
comment|/* double octet parameter field */
switch|switch
condition|(
operator|*
name|cp
condition|)
block|{
case|case
name|X25_FACIL_PKTSIZE
case|:
comment|/* 0x42, packet size */
name|dc
operator|->
name|dc_pktsizein
operator|=
operator|*
operator|(
name|cp
operator|+
literal|1
operator|)
expr_stmt|;
name|dc
operator|->
name|dc_pktsizeout
operator|=
operator|*
operator|(
name|cp
operator|+
literal|2
operator|)
expr_stmt|;
break|break;
case|case
name|X25_FACIL_WINSIZE
case|:
comment|/* 0x43, window size */
name|dc
operator|->
name|dc_wsizein
operator|=
operator|*
operator|(
name|cp
operator|+
literal|1
operator|)
expr_stmt|;
name|dc
operator|->
name|dc_wsizeout
operator|=
operator|*
operator|(
name|cp
operator|+
literal|2
operator|)
expr_stmt|;
break|break;
block|}
name|i
operator|+=
literal|3
expr_stmt|;
name|cp
operator|+=
literal|3
expr_stmt|;
break|break;
case|case
literal|0x80
case|:
comment|/* triple octet parameter field */
name|i
operator|+=
literal|4
expr_stmt|;
name|cp
operator|+=
literal|4
expr_stmt|;
break|break;
case|case
literal|0xc0
case|:
comment|/* variable-length parameter field */
name|cp
operator|++
expr_stmt|;
name|i
operator|+=
literal|2
operator|+
operator|*
name|cp
expr_stmt|;
name|cp
operator|+=
literal|1
operator|+
operator|*
name|cp
expr_stmt|;
break|break;
comment|/* Note: No other cases (i.e., default) possible */
block|}
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DECODE_RING()                          %%*/
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
comment|/*    This routine parses and validates the incoming call message. */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              decode_ring(p)                              */
end_comment

begin_comment
comment|/*  Argument:          p:   pointer to the message                 */
end_comment

begin_comment
comment|/*  Returns:           1 for success, else 0 for failure           */
end_comment

begin_comment
comment|/*  Called by:         supr_msg()                                  */
end_comment

begin_comment
comment|/*  Calls to:          bcopy()                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|boolean
name|decode_ring
parameter_list|(
name|p
parameter_list|)
specifier|register
name|u_char
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|int
name|cnt
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|22
argument_list|,
literal|0
argument_list|)
condition|)
block|{
comment|/* no easy access to unit, assume unit 0 */
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda: decode_ring()\n"
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|p
operator|+=
literal|3
expr_stmt|;
comment|/* skip to cmnd ext length */
if|if
condition|(
operator|*
name|p
operator|++
operator|<
literal|5
condition|)
comment|/* is count appropriate */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return false if not */
comment|/* called address */
if|if
condition|(
operator|(
name|cnt
operator|=
operator|*
name|p
operator|+
literal|1
operator|)
operator|>
literal|16
condition|)
comment|/* is called addr len legal? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return false if not */
name|bcopy
argument_list|(
name|p
argument_list|,
name|ddacb_called_addr
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
comment|/* copy field */
name|p
operator|+=
name|cnt
expr_stmt|;
comment|/* calling address */
if|if
condition|(
operator|(
name|cnt
operator|=
operator|*
name|p
operator|+
literal|1
operator|)
operator|>
literal|16
condition|)
comment|/* is calling addr len legal? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return false if not */
name|bcopy
argument_list|(
name|p
argument_list|,
name|ddacb_calling_addr
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
comment|/* copy field */
name|p
operator|+=
name|cnt
expr_stmt|;
comment|/* protocol part of user data */
if|if
condition|(
operator|(
name|cnt
operator|=
operator|*
name|p
operator|+
literal|1
operator|)
operator|>
literal|5
condition|)
comment|/* is protocol len legal? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return false if not */
name|bcopy
argument_list|(
name|p
argument_list|,
name|ddacb_protocol
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
comment|/* copy field */
name|p
operator|+=
name|cnt
expr_stmt|;
comment|/* facilities */
if|if
condition|(
operator|(
name|cnt
operator|=
operator|*
name|p
operator|+
literal|1
operator|)
operator|>
literal|64
condition|)
comment|/* is facilities len legal? */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return false if not */
name|bcopy
argument_list|(
name|p
argument_list|,
name|ddacb_facilities
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
comment|/* copy field */
name|p
operator|+=
name|cnt
expr_stmt|;
comment|/* ignore rest of user data for now */
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
if|if
condition|(
name|ddacb_protocol
index|[
literal|0
index|]
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
else|DDA_PAD_OR_RAW
if|if
condition|(
operator|(
name|ddacb_protocol
index|[
literal|0
index|]
operator|==
literal|0
operator|)
operator|||
operator|(
name|ddacb_protocol
index|[
literal|1
index|]
operator|!=
name|X25_PROTO_IP
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* bad if not IP */
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
ifndef|#
directive|ifndef
name|DDA_PAD_OR_RAW
return|return
operator|(
literal|1
operator|)
return|;
comment|/* looks ok */
else|#
directive|else
ifdef|#
directive|ifdef
name|DDA_RAWOPT
return|return
operator|(
literal|1
operator|)
return|;
comment|/* anything is ok if we're PI interface */
else|#
directive|else
if|if
condition|(
name|ddacb_protocol
index|[
literal|1
index|]
operator|==
name|X25_PROTO_IP
operator|||
name|ddacb_protocol
index|[
literal|1
index|]
operator|==
name|X25_PROTO_X29
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* looks ok */
else|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* bad if not IP or X29 */
endif|#
directive|endif
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      CLEAR_LCN()                            %%*/
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
comment|/*    This routine clears an X25 circuit and releases any buffers  */
end_comment

begin_comment
comment|/*    queued for transmission.                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              clear_lcn(ds, dc)                           */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*                     dc:  pointer to the Logical Channel control */
end_comment

begin_comment
comment|/*                            block structure                      */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddatimer()                                  */
end_comment

begin_comment
comment|/*  Calls to:          IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                     send_supr()                                 */
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
name|clear_lcn
parameter_list|(
name|ds
parameter_list|,
name|dc
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|23
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: clear_lcn(%d)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|==
name|LC_CLR_PENDING
condition|)
block|{
comment|/* Unfortunately, we can't 						 * display the destination's 						 * IP address, as we cleared 						 * it when we entered 						 * clear-pending state (to 						 * prevent new data from 						 * being queued to this 						 * channel). */
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|37
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Clear request lost -- lcn %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|dc
operator|->
name|dc_lcn
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|hist_lcn_state
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|,
name|LC_CLR_PENDING
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_CLR_PENDING
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_CLR_PENDING
expr_stmt|;
comment|/* start clear timer */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* clear associated address */
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
comment|/*  *  Raise priority whenever dc_oq is touched.  */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
while|while
condition|(
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
condition|)
block|{
comment|/* drop any pending data */
name|IF_DEQUEUE
argument_list|(
operator|&
name|dc
operator|->
name|dc_oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|send_supr
argument_list|(
name|ds
argument_list|,
name|CLEARLC
argument_list|,
operator|(
name|int
operator|)
name|dc
operator|->
name|dc_lcn
operator|*
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* send clear msg */
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      SEND_RESTART()                         %%*/
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
comment|/*    This routine marks all LCNs as being in a restarting state   */
end_comment

begin_comment
comment|/*    and sends a restart command to X25.                          */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              send_restart(ds)                            */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddatimer()                                  */
end_comment

begin_comment
comment|/*                     supr_msg()                                  */
end_comment

begin_comment
comment|/*  Calls to:          IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                     send_supr()                                 */
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
name|send_restart
parameter_list|(
name|ds
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
specifier|register
name|int
name|maxlcn
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|24
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: send_restart()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
comment|/* LCNLINK */
name|maxlcn
operator|=
name|nddach
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
expr_stmt|;
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|maxlcn
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's */
name|dc
operator|->
name|dc_state
operator|=
name|LC_RESTART
expr_stmt|;
comment|/* set state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_RESTART
expr_stmt|;
comment|/* start restart timeout */
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
operator|++
expr_stmt|;
block|}
name|hist_all_lcns
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|LC_RESTART
argument_list|)
expr_stmt|;
name|abort_io
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
name|ALL_CHANS
argument_list|)
expr_stmt|;
name|send_supr
argument_list|(
name|ds
argument_list|,
name|RESTART
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* send restart msg */
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      SEND_SUPR()                            %%*/
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
comment|/*    This routine is used to send short (4 bytes only) supervisor */
end_comment

begin_comment
comment|/*    commands, except that longer ANSWER messages may be sent.    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              send_supr(ds, cmd, p1, p2)                  */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*                     cmd:  type of command                       */
end_comment

begin_comment
comment|/*                     p1:   2nd byte of supervisor message        */
end_comment

begin_comment
comment|/*                     p2:   3rd byte of supervisor message        */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         supr_msg()                                  */
end_comment

begin_comment
comment|/*                     clear_lcn()                                 */
end_comment

begin_comment
comment|/*                     send_restart()                              */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     DDALOG()                                    */
end_comment

begin_comment
comment|/*                     mtod()                                      */
end_comment

begin_comment
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     dda_start()                                 */
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
name|send_supr
parameter_list|(
name|ds
parameter_list|,
name|cmd
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|int
name|cmd
decl_stmt|,
name|p1
decl_stmt|,
name|p2
decl_stmt|;
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|u_char
modifier|*
name|cp
decl_stmt|;
name|u_char
modifier|*
name|savcp
decl_stmt|,
modifier|*
name|fp
decl_stmt|,
modifier|*
name|svcp
decl_stmt|;
name|int
name|i
decl_stmt|,
name|faclen
decl_stmt|;
name|MGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
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
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|23
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: failed to get supr msg bfr!\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|cp
operator|=
name|savcp
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
comment|/* build supervisor message */
operator|*
name|cp
operator|++
operator|=
operator|(
name|u_char
operator|)
name|cmd
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
operator|(
name|u_char
operator|)
name|p1
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
operator|(
name|u_char
operator|)
name|p2
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
name|m
operator|->
name|m_len
operator|=
literal|4
expr_stmt|;
if|if
condition|(
name|cmd
operator|==
name|ANSWER
condition|)
block|{
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
comment|/* for answer messages p1 is (lcn * 2) */
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|p1
operator|/
literal|2
index|]
operator|)
expr_stmt|;
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* zero length called address */
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* zero length calling address */
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* zero length protocol */
comment|/* check and copy facilities */
name|faclen
operator|=
literal|0
expr_stmt|;
name|svcp
operator|=
name|cp
operator|++
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|fp
operator|=
operator|&
name|ddacb_facilities
index|[
literal|1
index|]
init|;
name|i
operator|<
name|ddacb_facilities
index|[
literal|0
index|]
condition|;
control|)
block|{
switch|switch
condition|(
operator|*
name|fp
operator|&
literal|0xc0
condition|)
block|{
case|case
literal|0x00
case|:
comment|/* single octet parameter field */
name|i
operator|+=
literal|2
expr_stmt|;
name|fp
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|0x40
case|:
comment|/* double octet parameter field */
comment|/* 		 * Note that this code can in some cases attempt to negotiate 		 * the packet size or window away from the default, which 		 * appears to violate the X.25 spec. In fact, the FEP 		 * examines these values and bounds them between the 		 * requested value and the default value thus satisfying X.25  		 */
switch|switch
condition|(
operator|*
name|fp
condition|)
block|{
case|case
name|X25_FACIL_PKTSIZE
case|:
comment|/* 0x42, packet size */
operator|*
name|cp
operator|++
operator|=
name|X25_FACIL_PKTSIZE
expr_stmt|;
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
name|PKTSIZE_DEF
expr_stmt|;
comment|/* Set incoming and outgoing */
operator|*
name|cp
operator|++
operator|=
name|PKTSIZE_DEF
expr_stmt|;
comment|/* packet size to default */
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
name|PKTSIZE_DEF
expr_stmt|;
block|}
else|else
block|{
operator|*
name|cp
operator|++
operator|=
operator|*
operator|(
name|fp
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* Answer with requested */
operator|*
name|cp
operator|++
operator|=
operator|*
operator|(
name|fp
operator|+
literal|2
operator|)
expr_stmt|;
comment|/* facilities */
name|dc
operator|->
name|dc_pktsizeout
operator|=
operator|*
operator|(
name|fp
operator|+
literal|1
operator|)
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
operator|*
operator|(
name|fp
operator|+
literal|2
operator|)
expr_stmt|;
block|}
name|faclen
operator|+=
literal|3
expr_stmt|;
break|break;
case|case
name|X25_FACIL_WINSIZE
case|:
comment|/* 0x43, window size */
operator|*
name|cp
operator|++
operator|=
name|X25_FACIL_WINSIZE
expr_stmt|;
if|if
condition|(
name|ds
operator|->
name|dda_firmrev
operator|<
literal|0x21
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
name|WINSIZE_DEF
expr_stmt|;
comment|/* Set incoming and outgoing */
operator|*
name|cp
operator|++
operator|=
name|WINSIZE_DEF
expr_stmt|;
comment|/* window size to default */
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
name|WINSIZE_DEF
expr_stmt|;
block|}
else|else
block|{
operator|*
name|cp
operator|++
operator|=
operator|*
operator|(
name|fp
operator|+
literal|1
operator|)
expr_stmt|;
comment|/* Answer with requested */
operator|*
name|cp
operator|++
operator|=
operator|*
operator|(
name|fp
operator|+
literal|2
operator|)
expr_stmt|;
comment|/* facilities */
name|dc
operator|->
name|dc_wsizeout
operator|=
operator|*
operator|(
name|fp
operator|+
literal|1
operator|)
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
operator|*
operator|(
name|fp
operator|+
literal|2
operator|)
expr_stmt|;
block|}
name|faclen
operator|+=
literal|3
expr_stmt|;
break|break;
block|}
name|i
operator|+=
literal|3
expr_stmt|;
name|fp
operator|+=
literal|3
expr_stmt|;
break|break;
case|case
literal|0x80
case|:
comment|/* triple octet parameter field */
name|i
operator|+=
literal|4
expr_stmt|;
name|fp
operator|+=
literal|4
expr_stmt|;
break|break;
case|case
literal|0xc0
case|:
comment|/* variable-length parameter field */
name|fp
operator|++
expr_stmt|;
name|i
operator|+=
literal|2
operator|+
operator|*
name|fp
expr_stmt|;
name|fp
operator|+=
literal|1
operator|+
operator|*
name|fp
expr_stmt|;
break|break;
comment|/* Note: No other cases (i.e., default) possible */
block|}
block|}
if|if
condition|(
name|faclen
condition|)
block|{
comment|/* Found facilities to negotiate! */
operator|*
name|svcp
operator|=
name|faclen
expr_stmt|;
comment|/* facility length<- faclen */
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* user data length<- 0 */
operator|*
operator|(
name|savcp
operator|+
literal|3
operator|)
operator|=
name|cp
operator|-
name|savcp
operator|-
literal|4
expr_stmt|;
comment|/* set supv message length */
name|m
operator|->
name|m_len
operator|=
name|cp
operator|-
name|savcp
expr_stmt|;
comment|/* set mbuf message length */
block|}
block|}
comment|/* (end of answer message case) */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|25
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|prt_bytes
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"send_supr"
argument_list|,
name|savcp
argument_list|,
name|m
operator|->
name|m_len
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|start_supr
argument_list|(
name|ds
argument_list|,
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%				START_SUPR()			       %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	Start i/o on the supervisor channel, checking for queue full.	 */
end_comment

begin_comment
comment|/*	Added to revision 2.0 so that "queue full" checking would be	 */
end_comment

begin_comment
comment|/*	applied uniformly to all supervisory channel output.		 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Call:          start_supr(ds, m)                                     */
end_comment

begin_comment
comment|/*  Argument:      ds:  softc structure for board			 */
end_comment

begin_comment
comment|/*		   m:	mbuf holding message				 */
end_comment

begin_comment
comment|/*  Returns:       nothing                                               */
end_comment

begin_comment
comment|/*  Called by:     send_supr(), send_config(), make_x25_call()		 */
end_comment

begin_comment
comment|/*  Calls to:      DDALOG(), dda_start(), IF_ENQUEUE()			 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|start_supr
parameter_list|(
name|ds
parameter_list|,
name|m
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
block|{
specifier|register
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|27
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: start_supr\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
name|IF_QFULL
argument_list|(
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_oq
operator|)
argument_list|)
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|27
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: supervisory channel overflow (maxlen=%d)\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_oq
operator|.
name|ifq_maxlen
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_oq
operator|.
name|ifq_maxlen
operator|+=
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_oq
operator|.
name|ifq_maxlen
expr_stmt|;
block|}
comment|/*  *  Raise priority whenever you touch dc_oq.    *  We do not want to be interrupted in the middle of adding  *  an mbuf to the output queue because the interrupt may indicate  *  a condition that will cause the mbuf to be freed.  *  (The mbufs are freed on receipt of a line status msg, restart,  *  clear, or reset.)  */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
name|m
operator|->
name|m_dat
index|[
name|MLEN
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
name|IF_ENQUEUE
argument_list|(
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|.
name|dc_oq
operator|)
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|dda_start
argument_list|(
name|ds
argument_list|,
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
literal|0
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%				ABORT_IO()   		               %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	Abort outstanding I/O upon receipt of a line status message, 	 */
end_comment

begin_comment
comment|/*	restart, clear, or reset.                                        */
end_comment

begin_comment
comment|/*	The contents of the output queue (dc_oq) is cleared for each     */
end_comment

begin_comment
comment|/*	lcn;  all I/O queued on either the read or write queue           */
end_comment

begin_comment
comment|/*	(dc_rchan and dc_wchan) is marked invalid; all I/O queued on     */
end_comment

begin_comment
comment|/*	the sioq is marked invalid;                                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Call:          abort_io()        			                 */
end_comment

begin_comment
comment|/*  Argument:      none						         */
end_comment

begin_comment
comment|/*  Returns:       nothing                                               */
end_comment

begin_comment
comment|/*  Called by:                                                           */
end_comment

begin_comment
comment|/*  Calls to:      IF_DEQUEUE()                                          */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|abort_io
parameter_list|(
name|unit
parameter_list|,
name|lcn
parameter_list|)
name|int
name|unit
decl_stmt|,
name|lcn
decl_stmt|;
block|{
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|lchan
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|ptr
decl_stmt|;
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* set up range of lcns affected */
if|if
condition|(
name|lcn
operator|==
name|ALL_CHANS
condition|)
block|{
name|start
operator|=
literal|1
expr_stmt|;
name|end
operator|=
name|nddach
index|[
name|unit
index|]
expr_stmt|;
block|}
else|else
name|start
operator|=
name|end
operator|=
name|lcn
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|28
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: abort_io on lcn's %d - %d\n"
operator|,
name|unit
operator|,
name|start
operator|,
name|end
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/*  * Invalidate writes on the sioq for specified channel(s)  */
if|if
condition|(
name|ptr
operator|=
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
condition|)
for|for
control|(
init|;
name|ptr
condition|;
name|ptr
operator|=
name|ptr
operator|->
name|hc_next
control|)
comment|/* scan sioq */
if|if
condition|(
operator|(
name|ptr
operator|->
name|hc_chan
operator|&
literal|0x01
operator|)
operator|&&
operator|(
operator|(
name|lcn
operator|==
name|ALL_CHANS
operator|)
operator|||
operator|(
name|lcn
operator|==
name|ptr
operator|->
name|hc_chan
operator|>>
literal|1
operator|)
operator|)
operator|&&
operator|(
name|ptr
operator|->
name|hc_chan
operator|!=
literal|1
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|28
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: abort_io--invalidating sioq lcn %d\n"
operator|,
name|unit
operator|,
name|ptr
operator|->
name|hc_chan
operator|>>
literal|1
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|ptr
operator|->
name|hc_inv
operator||=
name|INVALID_MBUF
expr_stmt|;
block|}
comment|/*  * For each selected lcn, clear the output queue and  * add an hdx struct to the sioq that will generate an  * abort.  */
for|for
control|(
name|lchan
operator|=
name|start
init|;
name|lchan
operator|<=
name|end
condition|;
name|lchan
operator|++
control|)
block|{
comment|/* for selected LCNs */
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
name|lchan
index|]
expr_stmt|;
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_wchan
expr_stmt|;
while|while
condition|(
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
operator|&
name|dc
operator|->
name|dc_oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
operator|&&
operator|!
operator|(
name|hc
operator|->
name|hc_inv
operator|&
name|INVALID_MBUF
operator|)
condition|)
block|{
if|if
condition|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_OBUSY
condition|)
block|{
comment|/* output pending */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|28
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: abort_io--queueing abort: lcn %d\n"
operator|,
name|unit
operator|,
name|lchan
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|hc
operator|->
name|hc_inv
operator||=
name|INVALID_MBUF
expr_stmt|;
name|hc
operator|->
name|hc_func
operator|=
name|DDAABT
expr_stmt|;
comment|/*  * Add to the sioq  */
name|dda_wrq
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|DDAABT
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                            PRT_BYTES()                            %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine is used to print a label, followed by the contents of */
end_comment

begin_comment
comment|/*	a buffer in hex, 16 bytes per line.  Each line is preceded by	 */
end_comment

begin_comment
comment|/*	the device name and unit number.				 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Call:          prt_bytes(unit, label, bp, cnt)			 */
end_comment

begin_comment
comment|/*  Argument:      unit: dda unit number to be displayed		 */
end_comment

begin_comment
comment|/*		   label: pointer to string to be displayed		 */
end_comment

begin_comment
comment|/*		   bp:  pointer to the buffer to be dumped		 */
end_comment

begin_comment
comment|/*                 cnt: number of bytes in buffer			 */
end_comment

begin_comment
comment|/*  Returns:       nothing                                               */
end_comment

begin_comment
comment|/*  Called by:     dda_data()                                            */
end_comment

begin_comment
comment|/*                 dda_supr()                                            */
end_comment

begin_comment
comment|/*                 supr_msg()                                            */
end_comment

begin_comment
comment|/*  Calls to:      DDALOG()                                              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|prt_bytes
parameter_list|(
name|unit
parameter_list|,
name|label
parameter_list|,
name|bp
parameter_list|,
name|cnt
parameter_list|)
name|int
name|unit
decl_stmt|;
name|char
modifier|*
name|label
decl_stmt|;
name|u_char
modifier|*
name|bp
decl_stmt|;
name|int
name|cnt
decl_stmt|;
block|{
name|char
name|hexbuf
index|[
literal|50
index|]
decl_stmt|;
comment|/* (worst case: 3 * 16 + 1 = 49 bytes) */
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|static
name|char
name|hex
index|[]
init|=
literal|"0123456789abcdef"
decl_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: %s\n"
operator|,
name|unit
operator|,
name|label
name|DDAELOG
expr_stmt|;
while|while
condition|(
name|cnt
operator|>
literal|0
condition|)
block|{
name|i
operator|=
operator|(
name|cnt
operator|>
literal|16
operator|)
condition|?
literal|16
else|:
name|cnt
expr_stmt|;
name|cnt
operator|-=
name|i
expr_stmt|;
name|p
operator|=
name|hexbuf
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|hex
index|[
operator|*
name|bp
operator|>>
literal|4
index|]
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|hex
index|[
operator|*
name|bp
operator|++
operator|&
literal|0x0f
index|]
expr_stmt|;
block|}
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: %s\n"
operator|,
name|unit
operator|,
name|hexbuf
name|DDAELOG
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                            FMT_X25()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine is used to format an X.25 address for inclusion in	 */
end_comment

begin_comment
comment|/*    an error message.  The previous return value is invalidated each	 */
end_comment

begin_comment
comment|/*    time the function is called, as it is stored in a static buffer	 */
end_comment

begin_comment
comment|/*  Note:          The X.25 address is apparently sometimes stored in    */
end_comment

begin_comment
comment|/*                 BCD, and other times (PDN mode) in ASCII.  So we mask */
end_comment

begin_comment
comment|/*                 off the high order bits to make ourselves immune.	 */
end_comment

begin_comment
comment|/*  Call:          fmt_x25(bp, cnt)                                      */
end_comment

begin_comment
comment|/*  Argument:      bp:  pointer to the string                            */
end_comment

begin_comment
comment|/*                 cnt: number of bytes (usually from address[0])        */
end_comment

begin_comment
comment|/*  Returns:       pointer to an internal buffer containing the string;	 */
end_comment

begin_comment
comment|/*		   string is 1 to 15 digits, null-terminated.		 */
end_comment

begin_comment
comment|/*  Called by:     make_x25_call()                                       */
end_comment

begin_comment
comment|/*                 supr_msg()                                            */
end_comment

begin_comment
comment|/*                 convert_x25_addr()					 */
end_comment

begin_comment
comment|/*  Calls to:      none							 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|char
modifier|*
name|fmt_x25
parameter_list|(
name|bp
parameter_list|,
name|cnt
parameter_list|)
specifier|register
name|u_char
modifier|*
name|bp
decl_stmt|;
specifier|register
name|int
name|cnt
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
specifier|static
name|char
name|x25buf
index|[
literal|20
index|]
decl_stmt|;
comment|/* worst case is 15 digits plus trailing null */
comment|/* (Don't put this on the stack!) */
name|p
operator|=
name|x25buf
expr_stmt|;
if|if
condition|(
name|cnt
operator|>=
sizeof|sizeof
argument_list|(
name|x25buf
argument_list|)
condition|)
name|cnt
operator|=
sizeof|sizeof
argument_list|(
name|x25buf
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* (oops!) */
while|while
condition|(
name|cnt
operator|--
condition|)
operator|*
name|p
operator|++
operator|=
operator|(
operator|*
name|bp
operator|++
operator|&
literal|0x0f
operator|)
operator|+
literal|'0'
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|x25buf
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_HISTOGRAM
end_ifdef

begin_comment
comment|/*----------------------- HISTOGRAM SUPPORT ---------------------------------*/
end_comment

begin_comment
comment|/* the histogram array */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|histogram
index|[
name|NDDA
index|]
index|[
name|HISTSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these two structures save the time of the last change in the state of the  * lcn table or the board status.  */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|last_lcn_time
index|[
name|NDDA
index|]
init|=
block|{
literal|0L
block|,
literal|0L
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|last_brd_time
index|[
name|NDDA
index|]
init|=
block|{
literal|0L
block|,
literal|0L
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* h_lcn_level: the current number of active lcns */
end_comment

begin_decl_stmt
name|int
name|h_lcn_level
index|[
name|NDDA
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*#define DDA_HIST_DEBUG 1     /* set this to debug history features */
end_comment

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                           HIST_INIT()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine initializes the histogram facility when coming up or  */
end_comment

begin_comment
comment|/*    after a reset.                                                     */
end_comment

begin_comment
comment|/*  Call:          hist_init(unit,reset)                                 */
end_comment

begin_comment
comment|/*  Argument:      unit - board number to initialize.                    */
end_comment

begin_comment
comment|/*                 reset - set to 1 to force an init.                    */
end_comment

begin_comment
comment|/*  Returns:       nothing.                                              */
end_comment

begin_comment
comment|/*  Called by:     ddaioctl()                                            */
end_comment

begin_comment
comment|/*  Calls to:      microtime()                                           */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|hist_init
parameter_list|(
name|unit
parameter_list|,
name|reset
parameter_list|)
name|int
name|unit
decl_stmt|;
name|int
name|reset
decl_stmt|;
block|{
name|int
name|s
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
if|if
condition|(
name|last_lcn_time
index|[
name|unit
index|]
operator|.
name|tv_sec
operator|!=
literal|0L
operator|&&
operator|!
name|reset
condition|)
return|return;
comment|/* histogram for this unit already enabled */
name|bzero
argument_list|(
name|histogram
index|[
name|unit
index|]
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
operator|*
name|HISTSIZE
argument_list|)
expr_stmt|;
name|h_lcn_level
index|[
name|unit
index|]
operator|=
literal|0
expr_stmt|;
name|dc
operator|=
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_cb
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NDDACH
operator|+
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|dc
operator|++
operator|->
name|dc_state
operator|==
name|LC_DATA_IDLE
condition|)
name|h_lcn_level
index|[
name|unit
index|]
operator|++
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|microtime
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|H_START
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_init: starting at level %d\n"
operator|,
name|h_lcn_level
index|[
name|unit
index|]
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                     HIST_LCN_STATE()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine changes the histogram depending on how the state of   */
end_comment

begin_comment
comment|/*    a channel has changed.                                             */
end_comment

begin_comment
comment|/*  Call:          hist_lcn_state(unit, old_state, new_state)            */
end_comment

begin_comment
comment|/*  Argument:      old_state: the old state of the lcn.                  */
end_comment

begin_comment
comment|/*                 new_state: the state the lcn is changing to.          */
end_comment

begin_comment
comment|/*                 unit: unit this applies to                            */
end_comment

begin_comment
comment|/*  Returns:       nothing.                                              */
end_comment

begin_comment
comment|/*  Called by:                                                           */
end_comment

begin_comment
comment|/*  Calls to:      timevalsub(), timevaladd(), microtime()               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|hist_lcn_state
parameter_list|(
name|unit
parameter_list|,
name|old_state
parameter_list|,
name|new_state
parameter_list|)
name|int
name|unit
decl_stmt|;
name|u_char
name|old_state
decl_stmt|;
name|u_char
name|new_state
decl_stmt|;
block|{
name|struct
name|timeval
name|tv
decl_stmt|,
name|tmpv
decl_stmt|;
comment|/*      * this structure for determining state transitions is much more general      * than is necessary right now.  However it allows easy changes to the      * state transition table for the histogram so I will leave it in until      * it settles down       */
switch|switch
condition|(
name|old_state
condition|)
block|{
case|case
name|LC_DATA_IDLE
case|:
switch|switch
condition|(
name|new_state
condition|)
block|{
case|case
name|LC_DATA_IDLE
case|:
break|break;
default|default:
comment|/* all other states */
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tmpv
operator|=
name|tv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_lcn_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_lcn_state: adding %ld.%ld to level %d--\n"
operator|,
name|tv
operator|.
name|tv_sec
operator|,
name|tv
operator|.
name|tv_usec
operator|,
name|h_lcn_level
index|[
name|unit
index|]
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|h_lcn_level
index|[
name|unit
index|]
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_lcn_time
index|[
name|unit
index|]
operator|=
name|tmpv
expr_stmt|;
if|if
condition|(
operator|--
name|h_lcn_level
index|[
name|unit
index|]
operator|<
literal|0
condition|)
comment|/* safety net for driver 						 * errors */
name|h_lcn_level
index|[
name|unit
index|]
operator|=
literal|0
expr_stmt|;
break|break;
block|}
break|break;
default|default:
switch|switch
condition|(
name|new_state
condition|)
block|{
case|case
name|LC_DATA_IDLE
case|:
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tmpv
operator|=
name|tv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_lcn_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_lcn_state: adding %ld.%ld to level %d++\n"
operator|,
name|tv
operator|.
name|tv_sec
operator|,
name|tv
operator|.
name|tv_usec
operator|,
name|h_lcn_level
index|[
name|unit
index|]
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|h_lcn_level
index|[
name|unit
index|]
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_lcn_time
index|[
name|unit
index|]
operator|=
name|tmpv
expr_stmt|;
if|if
condition|(
operator|++
name|h_lcn_level
index|[
name|unit
index|]
operator|>
name|NDDACH
condition|)
comment|/* safety net for driver 						 * errors */
name|h_lcn_level
index|[
name|unit
index|]
operator|=
name|NDDACH
expr_stmt|;
break|break;
default|default:
comment|/* all other states */
break|break;
block|}
break|break;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                     HIST_ALL_LCNS()                               %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine changes the histogram when the state of all the lcns  */
end_comment

begin_comment
comment|/*    are changed as a group.                                            */
end_comment

begin_comment
comment|/*  Call:          hist_lcn_state(unit, state)                           */
end_comment

begin_comment
comment|/*  Argument:      state: state that all lcn are going to.  Currently not*/
end_comment

begin_comment
comment|/*                        used.                                          */
end_comment

begin_comment
comment|/*                 unit: unit this applies to                            */
end_comment

begin_comment
comment|/*  Returns:       nothing.                                              */
end_comment

begin_comment
comment|/*  Called by:                                                           */
end_comment

begin_comment
comment|/*  Calls to:      timevalsub(), timevaladd(), microtime()               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|hist_all_lcns
parameter_list|(
name|unit
parameter_list|,
name|state
parameter_list|)
name|int
name|unit
decl_stmt|,
name|state
decl_stmt|;
block|{
name|struct
name|timeval
name|tmpv
decl_stmt|,
name|tv
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|state
operator|=
name|state
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|last_brd_time
index|[
name|unit
index|]
operator|.
name|tv_sec
operator|==
literal|0L
operator|||
name|last_lcn_time
index|[
name|unit
index|]
operator|.
name|tv_sec
operator|==
literal|0L
condition|)
return|return;
comment|/* see if we have initialized yet */
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tmpv
operator|=
name|tv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_lcn_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_all_lcns: adding %ld.%ld to level %d\n"
operator|,
name|tv
operator|.
name|tv_sec
operator|,
name|tv
operator|.
name|tv_usec
operator|,
name|h_lcn_level
index|[
name|unit
index|]
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|h_lcn_level
index|[
name|unit
index|]
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_lcn_time
index|[
name|unit
index|]
operator|=
name|tmpv
expr_stmt|;
name|h_lcn_level
index|[
name|unit
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                     HIST_LINK_STATE()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine changes the histogram depending on how the state of   */
end_comment

begin_comment
comment|/*    the link has changed.                                              */
end_comment

begin_comment
comment|/*  Call:          hist_link_state(old_state, new_state)                 */
end_comment

begin_comment
comment|/*  Argument:      old_state: the old state of the link.                 */
end_comment

begin_comment
comment|/*                 new_state: the state the link is changing to.         */
end_comment

begin_comment
comment|/*                 unit: unit this applies to                            */
end_comment

begin_comment
comment|/*  Returns:       nothing.                                              */
end_comment

begin_comment
comment|/*  Called by:                                                           */
end_comment

begin_comment
comment|/*  Calls to:      timevalsub(), timevaladd(), microtime()               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|hist_link_state
parameter_list|(
name|unit
parameter_list|,
name|old_state
parameter_list|,
name|new_state
parameter_list|)
name|int
name|unit
decl_stmt|;
name|u_char
name|old_state
decl_stmt|;
name|u_char
name|new_state
decl_stmt|;
block|{
name|struct
name|timeval
name|tv
decl_stmt|,
name|tmpv
decl_stmt|;
comment|/*      * this structure for determining state transitions is much more general      * than is necessary right now.  However it allows easy changes to the      * state transition table for the histogram so I will leave it in until      * it settles down       */
switch|switch
condition|(
name|old_state
condition|)
block|{
case|case
name|S_LINK_UP
case|:
switch|switch
condition|(
name|new_state
condition|)
block|{
case|case
name|S_LINK_UP
case|:
break|break;
default|default:
comment|/* all other states */
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_link_state: link down\n"
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tmpv
operator|=
name|tv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_lcn_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|h_lcn_level
index|[
name|unit
index|]
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tv
operator|=
name|tmpv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_brd_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|H_LINK_UP
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_brd_time
index|[
name|unit
index|]
operator|.
name|tv_sec
operator|=
literal|0L
expr_stmt|;
break|break;
block|}
break|break;
default|default:
comment|/* all other states */
switch|switch
condition|(
name|new_state
condition|)
block|{
case|case
name|S_LINK_UP
case|:
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_link_state: link up\n"
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|microtime
argument_list|(
operator|&
name|last_brd_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
comment|/* 	     * reset last_lcn_time so 0 entry will not accumulate the time 	     * that we were down  	     */
name|last_lcn_time
index|[
name|unit
index|]
operator|=
name|last_brd_time
index|[
name|unit
index|]
expr_stmt|;
break|break;
default|default:
break|break;
block|}
break|break;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                         HIST_READ()                               %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine prepares the histogram table for reading by making    */
end_comment

begin_comment
comment|/*    all entries current.                                               */
end_comment

begin_comment
comment|/*  Call:          hist_read(unit)                                       */
end_comment

begin_comment
comment|/*  Argument:      unit : board to use.                                  */
end_comment

begin_comment
comment|/*  Returns:       nothing                                               */
end_comment

begin_comment
comment|/*  Called by:     ddaioctl()                                            */
end_comment

begin_comment
comment|/*  Calls to:      timevalsub(), timevaladd(), microtime()               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|hist_read
parameter_list|(
name|unit
parameter_list|)
name|int
name|unit
decl_stmt|;
block|{
name|struct
name|timeval
name|tmpv
decl_stmt|,
name|tv
decl_stmt|;
name|microtime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
name|tmpv
operator|=
name|tv
expr_stmt|;
name|histogram
index|[
name|unit
index|]
index|[
name|H_END
index|]
operator|=
name|tmpv
expr_stmt|;
name|histogram
index|[
name|unit
index|]
index|[
name|H_TMO
index|]
operator|.
name|tv_sec
operator|=
name|tmo_data_idle
operator|*
name|DDA_TIMEOUT
expr_stmt|;
name|histogram
index|[
name|unit
index|]
index|[
name|H_TMO
index|]
operator|.
name|tv_usec
operator|=
literal|0L
expr_stmt|;
if|if
condition|(
name|last_brd_time
index|[
name|unit
index|]
operator|.
name|tv_sec
condition|)
block|{
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_lcn_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_HIST_DEBUG
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hist_read: adding %ld.%ld to level %d\n"
operator|,
name|tv
operator|.
name|tv_sec
operator|,
name|tv
operator|.
name|tv_usec
operator|,
name|h_lcn_level
index|[
name|unit
index|]
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|h_lcn_level
index|[
name|unit
index|]
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_lcn_time
index|[
name|unit
index|]
operator|=
name|tmpv
expr_stmt|;
name|tv
operator|=
name|tmpv
expr_stmt|;
name|timevalsub
argument_list|(
operator|&
name|tv
argument_list|,
operator|&
name|last_brd_time
index|[
name|unit
index|]
argument_list|)
expr_stmt|;
name|timevaladd
argument_list|(
operator|&
name|histogram
index|[
name|unit
index|]
index|[
name|H_LINK_UP
index|]
argument_list|,
operator|&
name|tv
argument_list|)
expr_stmt|;
name|last_brd_time
index|[
name|unit
index|]
operator|=
name|tmpv
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                         HIST_COPYOUT()                            %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Purpose:                                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    This routine prepares the histogram table for reading by making    */
end_comment

begin_comment
comment|/*    all entries current.                                               */
end_comment

begin_comment
comment|/*  Call:          hist_copyout(unit, to)                                */
end_comment

begin_comment
comment|/*  Argument:      unit : board to use.                                  */
end_comment

begin_comment
comment|/*                 to   : address in user space to copy to.              */
end_comment

begin_comment
comment|/*  Returns:       return value from copyout                             */
end_comment

begin_comment
comment|/*  Called by:     ddaioctl()                                            */
end_comment

begin_comment
comment|/*  Calls to:      copyout()                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|hist_copyout
parameter_list|(
name|unit
parameter_list|,
name|to
parameter_list|)
name|int
name|unit
decl_stmt|;
name|caddr_t
name|to
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|copyout
argument_list|(
name|histogram
index|[
name|unit
index|]
argument_list|,
name|to
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
operator|*
name|HISTSIZE
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|DDA_HISTOGRAM
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_PAD_OR_RAW
end_ifdef

begin_if
if|#
directive|if
name|ACC_BSD
operator|>
literal|42
end_if

begin_include
include|#
directive|include
file|"uba.h"
end_include

begin_include
include|#
directive|include
file|"bk.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"vm.h"
end_include

begin_include
include|#
directive|include
file|"bkmac.h"
end_include

begin_include
include|#
directive|include
file|"clist.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|>
literal|00
end_if

begin_include
include|#
directive|include
file|"bk.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
end_include

begin_include
include|#
directive|include
file|"../h/proc.h"
end_include

begin_include
include|#
directive|include
file|"../h/tty.h"
end_include

begin_include
include|#
directive|include
file|"../h/map.h"
end_include

begin_include
include|#
directive|include
file|"../h/vm.h"
end_include

begin_if
if|#
directive|if
name|ACC_ULTRIX
operator|>
literal|12
end_if

begin_include
include|#
directive|include
file|"uba.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../h/bk.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_include
include|#
directive|include
file|"Clist.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../h/clist.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../h/file.h"
end_include

begin_include
include|#
directive|include
file|"../h/uio.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|PRIVATE
name|int
name|dda_decode_type
parameter_list|(
name|ds
parameter_list|,
name|p
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
name|u_char
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|u_char
modifier|*
name|cp
decl_stmt|;
name|int
name|i
decl_stmt|,
name|usrlen
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|20
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|" dda_decode_type():  p[0]= %x "
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
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
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|RESET
case|:
comment|/* X25 reset */
return|return
operator|(
literal|1
operator|)
return|;
case|case
name|ANSWER
case|:
case|case
name|CLEARLC
case|:
case|case
name|INTERRUPT
case|:
case|case
name|INTR_ACK
case|:
name|i
operator|=
name|p
index|[
literal|1
index|]
operator|/
literal|2
expr_stmt|;
comment|/* get lcn */
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
name|i
index|]
operator|.
name|dc_flags
operator|&
operator|(
name|DC_X29
operator||
name|DC_X29W
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
elseif|else
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
name|i
index|]
operator|.
name|dc_flags
operator|&
operator|(
name|DC_RAW
operator|)
condition|)
return|return
operator|(
literal|2
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|!=
name|RING
condition|)
block|{
comment|/* let standard dda handle it */
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|cp
operator|=
name|p
operator|+
literal|4
expr_stmt|;
comment|/* skip over code, lcn, vcn and count in 				 * (ring?) answer message */
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
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|usrlen
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
if|if
condition|(
name|usrlen
condition|)
block|{
ifdef|#
directive|ifdef
name|DDA_RAWOPT
if|if
condition|(
name|pi_circuit_to_handle_protocol
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
return|return
operator|(
literal|2
operator|)
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|20
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|" dda_decode_type():  return value = %x "
argument_list|,
operator|*
name|cp
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
switch|switch
condition|(
operator|*
name|cp
condition|)
block|{
case|case
name|X25_PROTO_IP
case|:
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|X25_PROTO_X29
case|:
return|return
operator|(
literal|1
operator|)
return|;
default|default:
return|return
operator|(
literal|2
operator|)
return|;
block|}
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|DDA_PAD_OR_RAW
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_PADOPT
end_ifdef

begin_include
include|#
directive|include
file|"if_x29.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_RAWOPT
end_ifdef

begin_include
include|#
directive|include
file|"if_pi.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_PADOPT
end_ifdef

begin_if
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
end_if

begin_include
include|#
directive|include
file|"../vaxif/if_vmsx29.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../vaxif/if_x29.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_RAWOPT
end_ifdef

begin_include
include|#
directive|include
file|"../vaxif/if_pi.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DDA_MSGQ
end_ifdef

begin_decl_stmt
name|u_char
name|ddamsgq
index|[
name|MSGQSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PRIVATE
name|u_char
modifier|*
name|mqptr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MSGQEND
value|(ddamsgq+MSGQSIZE)
end_define

begin_macro
name|dda_mqstr
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|mqptr
operator|==
literal|0
condition|)
name|mqptr
operator|=
name|ddamsgq
expr_stmt|;
while|while
condition|(
operator|*
name|s
condition|)
block|{
operator|*
name|mqptr
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
if|if
condition|(
name|mqptr
operator|>=
name|MSGQEND
condition|)
name|mqptr
operator|=
name|ddamsgq
expr_stmt|;
block|}
operator|*
name|mqptr
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

begin_macro
name|dda_mqnum
argument_list|(
argument|num
argument_list|,
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|int
name|num
decl_stmt|,
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|mqptr
operator|==
literal|0
condition|)
name|mqptr
operator|=
name|ddamsgq
expr_stmt|;
if|if
condition|(
operator|(
name|mqptr
operator|+
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|+
literal|2
operator|)
operator|>=
name|MSGQEND
condition|)
name|mqptr
operator|=
name|ddamsgq
expr_stmt|;
operator|*
name|mqptr
operator|++
operator|=
name|type
expr_stmt|;
operator|*
operator|(
operator|(
name|int
operator|*
operator|)
name|mqptr
operator|)
operator|=
name|num
expr_stmt|;
name|mqptr
operator|+=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
expr_stmt|;
operator|*
name|mqptr
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|DDA_MSGQ
end_endif

begin_escape
end_escape

begin_comment
comment|/* link in support for steve's test-jig */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_include
include|#
directive|include
file|"if_dda_sim.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 		Revision History:  18-Dec-87: V3.0 - Brad Engstrom 	Added the -t flag to acpconfig and the 't' case in ddaioctl to allow 	setting of the idle circuit timeout. 	The constant TMO_DATA_IDLE was changed to a variable called 	tmo_data_idle. 11-Mar-88: V3.0 - Brad Engstrom 	Modified the history routine to return the current value of the 	timeout. Also fixed bug so that level 0 records amount of time 0 	circuits were in use only when link is up. 11-Mar-88: V3.0 - Brad Engstrom 	Changed handling of supervisor channel overflows to double the max q 	length each time it overflows.  This Will prevent a flood of console 	messages while still notifying the user that there has been an 	overflow. 21-Mar-88: V3.0 - Brad Engstrom 	Fixed bug in writing the facilities field for packet and window size 	negotiation.  This was in the routine make X.25 call.  Previously 	constants were used to index into the facilities buffer now offsets 	from the current facilities length are used. 12-Apr-88: V3.0 - Brad Engstrom 	Added ability to handle class b and class c addressing.  The changes 	affect locate_x25_lcn, convert_x25_addr, and convert_ip_addr.  The 	modifications came from fixes sent to Wollongong by Lars Poulson. 12-Apr-88: V3.0 - Brad Engstrom 	Made modifications so the driver will work under Ultrix or BSD. In 	cases where there are differences between 4.3 and 4.2 bsd (shown by 	#ifdef BSD4_3) Ultrix 1.2 is exactly like a 4.2 system. Ultrix 2.0 is 	like 4.3 in most cases. New macros were added to distinquish between 	systems.  These are BSD4_2 and BSD43_OR_ULTRIX20. 13-Apr-88: V3.0 - Brad Engstrom 	ddareset() was called from ddaintb without arguments.  This could 	cause ddareset to return without doing anything. Proper arguments were 	inserted.  In ddaioctl the priority level s may be used without being 	set.  This was fixed. 18-Apr-88: V3.0 - Brad Engstrom 	Added the use of a key field in the dda_cb structure.  Previously the 	dc_inaddr field was used both for printing the ip address (-l command) 	and for searching for circuits that were open to a destination.  Using 	this for a cicuit matching address means that the network and local 	host fields needed to be masked off, thus making this field less 	usefull for printing.  Now two fields are used dc_inaddr is used for 	printing.  dc_key is used for circuit matching.  In PDN mode the 	full ip address is used as the key.  In DDN mode just the imp number 	and host(port) number are used. 18-Apr-88: V3.0 - Brad Engstrom 	Made histogram facilities a compile time option.  The histogram is 	enabled if DDA_HISTOGRAM is defined.  The facilities are always 	disabled when using 4.2 or ULTRIX 1.2 as the kernel does not have the 	proper support routines available. 22-Apr-88: V3.0 - Brad Engstrom 	Added new option to -v command to set the dda_db_unit variable. 22-Apr-88: V3.0 - Brad Engstrom 	Added the DMESG macro and the msgbits array to allow selective 	disabling of driver error messages.  To enable or disable an error 	message the -c command of acpconfig is used. The msgbits array holds 	info about whether each message is enabled or disabled.  Setting a bit 	to 1 disables a message.  Clearing a bit to 0 enables a message. 	All messages start as enabled. 22-Apr-88: V3.0 - Brad Engstrom 	Added check for DDAMAINT_BRD in probe routine.  If DDAMAINT_BRD is 	defined then assume we are using a maintenence board so don't try to 	find the firmware id because it won't be there. Fake info that was 	supposed to be contained in the firmware id. 25-Apr-88: V3.0 - Brad Engstrom 	Added check in locate_x25_lcn to see if state of lc is LC_CALL_PENDING 	or LC_DATA_IDLE in the loop that looks for an already open lc.  This 	will prevent an address of 0.0.0.0 from matching a circuit that is not 	in use.  If the address is invalid then the imp will kick it out. 26-Apr-88: V3.0 - Brad Engstrom 	Changed the -n command case so that a command of the form "-n 0" will 	return the number of channels currently available.  This will be used 	by the -l command and possible by the -h command to determine the 	number of available circuits. 10-May-88: V3.0 - Brad Engstrom 	Made all occurences of the length of and X.25 address refer to the 	constants MAXADDRLEN and MINADDRLEN defined in if_ddavar.h.  These 	constants include the 1 byte  for encoding the length. 02-Jun-88: V3.0 - Brad Engstrom 	Change the check for the firmware revision level to 2.2 for the -e 	command.  This command will crash [56]250s that don't have at least 	v2.2 firmware. 12-Jul-88: V3.0 - Brad Engstrom 	Deleted case for class_b_c addressing. 20-Jul-88: V3.0 - Brad Engstrom 	Fixed bug in parsing facilities that would cause the kernel to hang. 	The bug was not incrmenting pointers when an urecognized 2 octet 	facility was seen.  Fixes were applied to send_supr() and 	decode_answer() 30-Aug-88: V4.0 - Brad Engstrom 	Modified driver to support X.29 and a programmers interface.  Includes 	files if_x29.c, if_pi.c, and if_pivar.h 30-Aug-88: V4.0 - Brad Engstrom 	Added support for debug logging under the control of the DDA_MSGQ 	define.   Information is extracted using the new -p command of 	acpconfig. 30-Aug-88: V4.0 - Brad Engstrom 	Modified start_chan to check the ready bit before touching the 	comregs.  Also modified dda_rrq and dda_wrq to raise ipl before 	touching the sioq.  These changes fixed a bug where the FE was losing 	I/O requests. 20-Oct-88: V4.0 - Steve Johnson 	Added SIMULATION #ifdef for simulation support 08-Jan-89: V4.1 - Steve Johnson 	MERGE 4.0 and 3.1 10-Oct-88: V3.1 - Charles Carvalho 	Replace prt_x25 with fmt_x25, which returns a pointer to a formatted 	message instead of printing its data; this allows error messages to be 	output with a single call to DDALOG (or syslog).  Move prt_addr 	inline, for same reason.  Add IP address to some error messages; 	trim excess text from some error messages.  Allocate channels 	for incoming calls from lowest channel up; we do linear searches of 	the lcn table, so it's to our advantage to use the lowest numbers for 	all active circuits. (The lcn is not related to the virtual circuit 	number, so there is no need to allocate incoming channels from the 	top down.)  Modify prt_bytes to take unit number and descriptive 	string to be printed along with the buffer and byte count; it now 	formats up to 16 bytes at a time and prints a full line with each call 	to DDALOG rather than calling DDALOG for each byte. 17-Oct-88: V3.1 - Charles Carvalho 	Add definitions for DDALOG and DDAELOG, which translate into a call to 	DDALOG() or log(). 26-Oct-88: V3.1 - Charles Carvalho 	Change index for 'v' ioctl to preserve compatibility with previous  	versions.  Restrict maximum window size to 127, not 128. 7-Nov-88: V3.2 - Charles Carvalho 	Fix check for no free circuits when processing RING 17-Feb-89: V4.3.0 - Paul Traina 	Added TGV changes for Multinet. 8-Mar-89: V4.3.1 - Steve Johnson 	Installed 'Q' ioctl to support obtaining an internal trace log used 	for debugging only -- not documented for general user.  acpconfig 	dda0 -q 2 dumps 256 bytes from the dda_debug_silo[] array 13-Mar-89: V4.3.2 - Paul Traina 	Updated Multinet support. 17-Apr-89: V4.3.3 - Steve Johnson 	Split bus and simulation related code out to included files for first 	shot at 7000 and tahoe design.  Don't reset timeout counter in 	dda_data() unless link really is in idle state. 28-Apr-89: V4.3.4 - Paul Traina 	Modified changes of 17-Apr-89, added minimal tahoe support until 	driver modified to use 4.3uba transfers. 	Fixed timeout fix of 17-Apr-89 to do what was intended. 	Fixed code dealing with maintenance board, reformatted with indent 	to repair readablility. 09-May-89: V4.3.5 - Paul Traina 	Minimal tahoe support completed,  based on BSD4_3TAHOE define which 	must be uncommented manually.  Finalizing for ECO. 24-May-89: V4.3.6 - Paul Traina 	Ultrix 3.0 support added.  Revised 4.3 tahoe support for automatic 	invocation. 	*** NOTE: one of the three OS defines (ACC_BSD, ACC_ULTRIX, ACC_VMS) 	    in if_dda.c must be set to a non-zero value for the driver to 	    compile. 	Attempting multiple-os support based upon weird variables from include 	files is not acceptable with the latest proliferation of OS versions. 20-Jun-89: V4.3.7 - Paul Traina 	Removed crufty old debug stuff and integrated it with the log-message 	code.  Now X29 and PI modules can be debuged properly (no #if 0's!). 22-Jun-89:	  - Paul Traina 	Diddled ring-decode logic to check for proper ring packet decoding 	before attempting to find a free lcn.  This will make it easier to deal 	with the race condition with find_free_lcn(). 	Modified ACC os specific equates to be set as options in the config 	file.  This way, most users won't ever edit if_dda.c. 18-Jul-89:	  - Paul Traina 	Driver will no longer return errors if duplicate address-translation 	entries are made.  Errors will only happen if a redefiniton is 	attempted. 	Moved dc_key.ttyline out of union, creating dc_line. 26-Jul-89:	  - Paul Traina f/Brad Engstrom 	Added support for called user-data field (two new params to 	make_x25_call) to support extended pad mode in the X.29 module. 01-Aug-89:	  - Paul Traina 	Made ddamsgs uninitialized -- it gets inited in ddaattach now. 03-Aug-89:	  - Paul Traina 	Changed hist_copyout definition to PRIVATE. 15-Aug-89:	  - Paul Traina 	Made dda_softc and dda_iobuf non-private. 18-Aug-89:	  - Paul Traina 	Somehow, ddareset was removed from the 'z' ioctl. 28-Aug-89:	  - Paul Traina 	Changed make_x25_call so that it checks length of data to be stuffed 	into the mbuf before actually copying data in.  Removed udlen and 	ud parameters to the routine, as the public areas will be plugged 	with data before being called.  (May need to splimp()). 22-Sep-89:	  - Paul Traina 	The order of the 'v' ioctl parameters was screwed up.  This caused 	window and packet size setting to fail. 23-Oct-89:	  - Paul Traina 	Added further support for Steve's yetchy simulation.  Updated main 	module to work with BI version of dda board. 29-Oct-89:	  - Paul Traina 	Acpconfig inconsistancy (again): removed the 'p', and 'Q' ioctls. 	Since all of these are queries, I placed them under the 'q' ioctl 	with a new switch.  Some day we should just scrap the whole mess 	and design a proper ioctl interface. 11-Nov-89:	  - Paul Traina 	Moved rrq/wrq routines into bus modules because we can do several 	queue reads and writes when working with the BI. */
end_comment

begin_endif
endif|#
directive|endif
endif|NDDA> 0
end_endif

end_unit

