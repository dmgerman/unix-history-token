begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *	@(#)if_acp.c	7.3 (Berkeley) %G%  */
end_comment

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
comment|/*  	Copyright (c) 1985 by Advanced Computer Communications           */
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
comment|/*  File:		if_acp.c                                         */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		Arthur Berggreen                                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		ACP6100 (UPB with HDLC firmware)                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Function:		4.2BSD UNIX Network Interface Driver for ACP6100 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Components:		if_acp.c, if_acpreg.h, if_acpvar.h               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Revision History:                                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    16-AUG-1985  Clare Russ:  add fileheader and comments              */
end_comment

begin_comment
comment|/*    24-SEP-1985  Clare Russ:  modify for socket ioctl user interface   */
end_comment

begin_comment
comment|/*    06-NOV-1985  Clare Russ:  modify for socket ioctl under TWG        */
end_comment

begin_comment
comment|/*    11-NOV-1985  Clare Russ:  Add a call to acpreset() in acpioctl()   */
end_comment

begin_comment
comment|/*         before processing socket ioctl to clear COMREGs.  In the      */
end_comment

begin_comment
comment|/*         acpinit() routine, avoid redundant allocation of UMRs by      */
end_comment

begin_comment
comment|/*         doing so only if the front end is not RUNNING.                */
end_comment

begin_comment
comment|/*    14-NOV-1985  Clare Russ:  Trace if_ubainit failure:  happens with  */
end_comment

begin_comment
comment|/*         TWG, not 4.2BSD.                                              */
end_comment

begin_comment
comment|/*    21-NOV-1985  Clare Russ:  Modify for compliance with the new       */
end_comment

begin_comment
comment|/*         Control Interface (CIF) and Access Path Allocation Protocol   */
end_comment

begin_comment
comment|/*         (APAP).  The CIF requires that Control Interface Messages     */
end_comment

begin_comment
comment|/*         (CIMs) are exchanged between the host and front end in        */
end_comment

begin_comment
comment|/*         command/response pairs.  The APAP requires that the control   */
end_comment

begin_comment
comment|/*         and data paths be established (via exchange of CIMs between   */
end_comment

begin_comment
comment|/*         the host and the front end) prior to use.                     */
end_comment

begin_comment
comment|/*    26-NOV-1985  Clare Russ:  Add ability to bring down line in        */
end_comment

begin_comment
comment|/*         response to 'acpconfig' command.                              */
end_comment

begin_comment
comment|/*    27-NOV-1985  Clare Russ:  Add ability to specify DTE or DCE mode   */
end_comment

begin_comment
comment|/*         in response to 'acpconfig' command.                           */
end_comment

begin_comment
comment|/*    02-DEC-1985  Clare Russ:  Add ability to set baud rate (external   */
end_comment

begin_comment
comment|/*         clock) or set internal clock.                                 */
end_comment

begin_comment
comment|/*    14-JAN-1986  Clare Russ:  Add acpinit call to acpioctl under       */
end_comment

begin_comment
comment|/*         SIOCSIFADDR processing                                        */
end_comment

begin_comment
comment|/*    21-JAN-1986  Clare Russ:  Flush pending I/O in acpreset, free the  */
end_comment

begin_comment
comment|/*         mbufs                                                         */
end_comment

begin_comment
comment|/*    30-MAY-1986  Clare Russ:  Update MPCP host request subfunction     */
end_comment

begin_comment
comment|/*         values, fix baud rate values in baud_rate[], change default   */
end_comment

begin_comment
comment|/*         clock source from internal to external (in ssp_msg[])         */
end_comment

begin_comment
comment|/*    24-JUL-1986  Clare Russ:  In supr_msg() print out RSF field when   */
end_comment

begin_comment
comment|/*         path allocation or deallocation fails                         */
end_comment

begin_comment
comment|/*    23-FEB-1987  Jeff Berkowitz: port to 4.3BSD by adding #ifdefs for  */
end_comment

begin_comment
comment|/*	   new interface address formats, trapping 0 length mbufs, etc.  */
end_comment

begin_comment
comment|/*    08-JAN-1988  Brad Engstrom:  port to ULTRIX 2.0 by using the       */
end_comment

begin_comment
comment|/*	   UBAUVII (ultrix 2.0) and MVAX (microvax) defines to handle    */
end_comment

begin_comment
comment|/*         special cases.  These cases are:                              */
end_comment

begin_comment
comment|/*         1) not declaring br, cvec as value-result in the probe routine*/
end_comment

begin_comment
comment|/*         2) using 0x17 as the ipl for a microvax                       */
end_comment

begin_comment
comment|/*         3) in all other cases the ULTRIX drivers behaves like a 4.3   */
end_comment

begin_comment
comment|/*            driver.                                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Usage Notes:                                                         */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    device acp0 at uba0 csr 016700 flags 0 vector acpinta acpintb      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         The 'flags' value is nonzero in the configuration file        */
end_comment

begin_comment
comment|/*         for TWG, and may be left as zero in the configuration         */
end_comment

begin_comment
comment|/*         file for UNIX 4.2 BSD.                                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Application Notes:	                                                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*    Refer to the Installation Instructions and the UNIX Programmer's   */
end_comment

begin_comment
comment|/*    Manual page which are on the driver distribution medium.           */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/* #define ACPDEBUG 1	/* define for debug printf statements */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPDEBUG
end_ifdef

begin_decl_stmt
name|int
name|acp_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* acp_debug is 1-8 for increasing verbosity */
end_comment

begin_endif
endif|#
directive|endif
endif|ACPDEBUG
end_endif

begin_escape
end_escape

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%                          INCLUDE FILES                            %%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/* The number of ACP 6100s in the system is defined in the configuration */
end_comment

begin_comment
comment|/* file in /sys/conf.  When 'config' is run, the file acp.h is created   */
end_comment

begin_comment
comment|/* with the definition of NACP, the number of ACP 6100s in the system.   */
end_comment

begin_include
include|#
directive|include
file|"acp.h"
end_include

begin_if
if|#
directive|if
name|NACP
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|"../include/pte.h"
end_include

begin_include
include|#
directive|include
file|"sys/param.h"
end_include

begin_include
include|#
directive|include
file|"sys/systm.h"
end_include

begin_include
include|#
directive|include
file|"sys/mbuf.h"
end_include

begin_include
include|#
directive|include
file|"sys/buf.h"
end_include

begin_include
include|#
directive|include
file|"sys/protosw.h"
end_include

begin_include
include|#
directive|include
file|"sys/socket.h"
end_include

begin_include
include|#
directive|include
file|"sys/vmmac.h"
end_include

begin_include
include|#
directive|include
file|"sys/errno.h"
end_include

begin_include
include|#
directive|include
file|"sys/time.h"
end_include

begin_include
include|#
directive|include
file|"sys/kernel.h"
end_include

begin_include
include|#
directive|include
file|"sys/ioctl.h"
end_include

begin_include
include|#
directive|include
file|"net/if.h"
end_include

begin_include
include|#
directive|include
file|"net/netisr.h"
end_include

begin_include
include|#
directive|include
file|"net/route.h"
end_include

begin_include
include|#
directive|include
file|"netinet/in.h"
end_include

begin_include
include|#
directive|include
file|"netinet/in_systm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FOURTWO
end_ifndef

begin_include
include|#
directive|include
file|"netinet/in_var.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"netinet/ip.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_var.h"
end_include

begin_include
include|#
directive|include
file|"../include/cpu.h"
end_include

begin_include
include|#
directive|include
file|"../include/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"../if/if_acpreg.h"
end_include

begin_include
include|#
directive|include
file|"../if/if_acpvar.h"
end_include

begin_include
include|#
directive|include
file|"../if/if_uba.h"
end_include

begin_include
include|#
directive|include
file|"../uba/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"../uba/ubavar.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%                        GLOBAL FUNCTIONS                           %%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
name|int
name|acpprobe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpattach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpreset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpoutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acptimer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* currently no timer routine exists   */
end_comment

begin_function_decl
name|int
name|acpioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpinta
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpintb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpstart
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%                         LOCAL FUNCTIONS                           %%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
specifier|static
name|void
name|acp_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* allocate control and data paths       */
end_comment

begin_function_decl
specifier|static
name|void
name|acp_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* send Set System Parameters Message    */
end_comment

begin_function_decl
specifier|static
name|void
name|acp_iorq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|start_chn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|acp_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|acp_response
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* send CIM response to the front end    */
end_comment

begin_function_decl
specifier|static
name|void
name|acp_supr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|supr_msg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|send_supr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPDEBUG
end_ifdef

begin_function_decl
specifier|static
name|void
name|prt_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|prt_bytes
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|ACPDEBUG
end_endif

begin_escape
end_escape

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%                         LOCAL VARIABLES                           %%*/
end_comment

begin_comment
comment|/*%%                                                                   %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|acpinfo
index|[
name|NACP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptrs to device info           */
end_comment

begin_decl_stmt
name|u_short
name|acpstd
index|[]
init|=
block|{
literal|0767000
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* standard UNIBUS CSR addresses */
end_comment

begin_decl_stmt
name|struct
name|uba_driver
name|acpdriver
init|=
comment|/* device driver info            */
block|{
name|acpprobe
block|,
comment|/* device probe routine */
literal|0
block|,
comment|/* slave probe routine */
name|acpattach
block|,
comment|/* device attach routine */
literal|0
block|,
comment|/* "dmago" routine */
name|acpstd
block|,
comment|/* device address */
literal|"acp"
block|,
comment|/* device name */
name|acpinfo
comment|/* ptr to device info ptrs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The alloc_msg array contains the Command Interface Message (CIM)    */
end_comment

begin_comment
comment|/* for path allocation.  There are 12 bytes of header followed by 6    */
end_comment

begin_comment
comment|/* bytes of command information                                        */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|alloc_msg
index|[]
init|=
block|{
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|FAC_ALLOC
block|,
comment|/* front end ALLOC facility    */
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|CMD_ALLOC
block|,
comment|/* allocate path command       */
literal|0x0f
block|,
literal|0x0a
block|,
literal|0x0c
block|,
literal|0x0e
block|,
comment|/* Command ID (CID)            */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* Response/Status Field (RSF) */
literal|0x00
block|,
name|ACP_SUPR
block|,
comment|/* Data Path Number (DPN)      */
literal|0x00
block|,
name|FAC_HDLC
block|,
comment|/* front end HDLC facility     */
literal|0x00
block|,
name|TYPE_CNTL
comment|/* type of path:  control      */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The dealloc_msg array contains the Command Interface Message (CIM)  */
end_comment

begin_comment
comment|/* for path deallocation.  There are 12 bytes of header followed by 2  */
end_comment

begin_comment
comment|/* bytes of command information                                        */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|dealloc_msg
index|[]
init|=
block|{
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|FAC_ALLOC
block|,
comment|/* front end ALLOC facility    */
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|CMD_DEALLOC
block|,
comment|/* allocate path command       */
literal|0x0c
block|,
literal|0x0a
block|,
literal|0x0f
block|,
literal|0x0e
block|,
comment|/* Command ID (CID)            */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* Response/Status Field (RSF) */
literal|0x00
block|,
name|ACP_SUPR
block|,
comment|/* Data Path Number (DPN)      */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Table of baud rate values and the associated parameter for the Set  */
end_comment

begin_comment
comment|/* System Parameters message, ssp_msg.  The second byte is nonzero for */
end_comment

begin_comment
comment|/* valid baud rate divisors.                                           */
end_comment

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
name|baud_rate
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|0x00
block|,
literal|0x02
block|}
block|,
block|{
literal|2
block|,
literal|0x00
block|,
literal|0x03
block|}
block|,
block|{
literal|3
block|,
literal|0x00
block|,
literal|0x04
block|}
block|,
block|{
literal|4
block|,
literal|0x00
block|,
literal|0x08
block|}
block|,
block|{
literal|5
block|,
literal|0x00
block|,
literal|0x10
block|}
block|,
block|{
literal|6
block|,
literal|0x00
block|,
literal|0x28
block|}
block|,
block|{
literal|7
block|,
literal|0x00
block|,
literal|0x3e
block|}
block|,
block|{
literal|8
block|,
literal|0x00
block|,
literal|0x47
block|}
block|,
block|{
literal|9
block|,
literal|0x00
block|,
literal|0x85
block|}
block|,
block|{
literal|10
block|,
literal|0x00
block|,
literal|0xd0
block|}
block|,
block|{
literal|11
block|,
literal|0x01
block|,
literal|0xa1
block|}
block|,
block|{
literal|12
block|,
literal|0x03
block|,
literal|0x41
block|}
block|,
block|{
literal|13
block|,
literal|0x06
block|,
literal|0x83
block|}
block|,
block|{
literal|14
block|,
literal|0x0d
block|,
literal|0x05
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|, }
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* The ssp_msg array contains the Command Interface Message (CIM) for  */
end_comment

begin_comment
comment|/* Setting HDLC System Paramters.  There are 12 bytes of header        */
end_comment

begin_comment
comment|/* followed by the line number and parameter modification commands     */
end_comment

begin_comment
comment|/* (PMCs).  The driver sends this CIM to the front end when kicked by  */
end_comment

begin_comment
comment|/* the acpconfig program (via socket ioctl).  In future versions, the  */
end_comment

begin_comment
comment|/* CIM won't be here in the driver, it will be passed to the driver.   */
end_comment

begin_decl_stmt
name|u_char
name|ssp_msg
index|[]
init|=
block|{
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|FAC_HDLC
block|,
comment|/* front end HDLC facility     */
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|CMD_SSP
block|,
comment|/* set HDCL system parameters  */
literal|0x0b
block|,
literal|0x0e
block|,
literal|0x0e
block|,
literal|0x0f
block|,
comment|/* Command ID (CID)            */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* Response/Status Field (RSF) */
literal|0x00
block|,
literal|0x00
block|,
comment|/* HDLC Line Number (0)        */
name|LINK_DISABLE
block|,
comment|/* link disable                */
name|LINK_LOOPBACK
block|,
comment|/* loopback mode               */
name|LOOP_EXTERNAL
block|,
comment|/*   external loopback         */
name|DCE_OR_DTE
block|,
comment|/* specify DTE or DCE mode     */
name|DTE_MODE
block|,
comment|/*   DTE mode                  */
name|BAUD_CNTL
block|,
comment|/* baud rate divisor           */
literal|0x00
block|,
comment|/*                             */
literal|0x03
block|,
comment|/*  3 = 1.333 Mb/sec           */
name|IDLE_POLL
block|,
comment|/* idle poll selection         */
literal|0x01
block|,
comment|/*  1 = on                     */
name|CLOCK_CNTL
block|,
comment|/* xmit clock selection        */
literal|0x00
block|,
comment|/*  0 = external source        */
name|LINK_ENABLE
comment|/* link enable                 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The response_msg array contains the Command Interface Message (CIM) */
end_comment

begin_comment
comment|/* response to be sent back to the front end in response to a CIM      */
end_comment

begin_comment
comment|/* command for Frame Level Status from the front end.   The front end  */
end_comment

begin_comment
comment|/* sends the Frame Level Status CIM command to the host when the frame */
end_comment

begin_comment
comment|/* level status changes from up to down or vice versa.  In keeping     */
end_comment

begin_comment
comment|/* with the philosophy with CIMs, they are always exchanged in command */
end_comment

begin_comment
comment|/* response pairs.                                                     */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|response_msg
index|[]
init|=
block|{
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|FAC_HDLC
block|,
comment|/* front end HDLC facility     */
literal|0x00
block|,
comment|/* reserved, must be zero      */
name|RSP_FLUP
block|,
comment|/* Frame Level Status          */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* Command ID (CID)            */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* RSF is 0 for success        */
literal|0x00
block|,
literal|0x00
comment|/* HDLC Line Number  (0)       */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/***********************************************************************\ *									* *	Information for each device unit is maintained in an array	* *	of structures named acp_softc[].  The array is indexed by	* *	unit number.  Each entry includes the network interface		* *	structure (acp_if) used by the routing code to locate the	* *	interface,  an array of Logical	Channel control blocks which	* *	maintain information about each of the Logical Channels (LCNs)	* *	through which communication with the ACP is maintained, a queue * *	of I/O requests pending for the ACP, the UNIBUS interrupt	* *	vector for the unit and misc flags.  The Logical Channel	* *	Control blocks maintain information about the state of each	* *	LCN, a queue of outbound data, Half Duplex Channel (HDX) blocks	* *	used for queuing I/O requests to the ACP and an ifuba		* *	structure which records the UNIBUS resources being held by	* *	the LCN.							* *									* \***********************************************************************/
end_comment

begin_struct
struct|struct
name|sioq
comment|/* Start I/O queue head */
block|{
name|struct
name|hdx_chan
modifier|*
name|sq_head
decl_stmt|;
comment|/* queue head */
name|struct
name|hdx_chan
modifier|*
name|sq_tail
decl_stmt|;
comment|/* queue tail */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hdx_chan
comment|/* HDX channel block */
block|{
name|struct
name|hdx_chan
modifier|*
name|hc_next
decl_stmt|;
comment|/* link to next HDX channel */
name|u_char
name|hc_chan
decl_stmt|;
comment|/* HDX channel number */
name|u_char
name|hc_adx
decl_stmt|;
comment|/* address bits 17-16 */
name|u_short
name|hc_addr
decl_stmt|;
comment|/* address bits 15-00 */
name|u_short
name|hc_cnt
decl_stmt|;
comment|/* byte count */
name|u_char
name|hc_func
decl_stmt|;
comment|/* I/O function */
name|u_char
name|hc_sbfc
decl_stmt|;
comment|/* I/O subfunction */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acp_cb
comment|/* Logical Channel control block */
block|{
name|u_char
name|dc_lcn
decl_stmt|;
comment|/* LCN number */
name|struct
name|ifqueue
name|dc_oq
decl_stmt|;
comment|/* LCN output queue */
name|struct
name|hdx_chan
name|dc_rchan
decl_stmt|;
comment|/* LCN read HDX channel */
name|struct
name|hdx_chan
name|dc_wchan
decl_stmt|;
comment|/* LCN write HDX channel */
name|struct
name|ifuba
name|dc_ifuba
decl_stmt|;
comment|/* UNIBUS resources */
name|u_short
name|dc_flags
decl_stmt|;
comment|/* misc flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acp_softc
comment|/* device control structure */
block|{
name|struct
name|ifnet
name|acp_if
decl_stmt|;
comment|/* network-visible interface   */
name|struct
name|acp_cb
name|acp_cb
index|[
name|NACPCH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Logical Channel cntl blks */
name|struct
name|sioq
name|acp_sioq
decl_stmt|;
comment|/* start I/O queue             */
name|u_short
name|acp_vector
decl_stmt|;
comment|/* UNIBUS interrupt vector     */
name|u_short
name|acp_flags
decl_stmt|;
comment|/* ACP operational flag        */
name|u_char
name|acp_path
decl_stmt|;
comment|/* path allocation flag        */
name|u_short
name|acp_maxout
decl_stmt|;
comment|/* maximum IP message sent     */
name|u_short
name|acp_maxin
decl_stmt|;
comment|/* maximum IP message rcvd     */
ifndef|#
directive|ifndef
name|FOURTWO
name|struct
name|in_addr
name|acp_ipaddr
decl_stmt|;
comment|/* local IP address */
endif|#
directive|endif
block|}
name|acp_softc
index|[
name|NACP
index|]
struct|;
end_struct

begin_comment
comment|/* The acp_path flag indicates whether or not a path has been allocated */
end_comment

begin_comment
comment|/* and also whether or not to call acp_init to send an ssp_msg to the   */
end_comment

begin_comment
comment|/* front end:  acp_path = 1    indicates supervisory path is allocated  */
end_comment

begin_comment
comment|/*             acp_path = 2    indicates data path is allocated         */
end_comment

begin_comment
comment|/*             acp_path = 0x10 indicates acp_init should be called      */
end_comment

begin_comment
comment|/*                             to send CIM ssp_msg to the front end     */
end_comment

begin_escape
end_escape

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
comment|/*%%                      ACPPROBE()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/* Purpose:                                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  This routine probes the device to obtain the UNIBUS interrupt  */
end_comment

begin_comment
comment|/*  vector.  Since the ACP is a soft vector device, we obtain an   */
end_comment

begin_comment
comment|/*  unused vector from the uba structure and return that.  The ACP */
end_comment

begin_comment
comment|/*  is given the vector and the board is reset.  In order to save  */
end_comment

begin_comment
comment|/*  the vector in the device info structure, we place it in a      */
end_comment

begin_comment
comment|/*  static temporary where the attach routine can find it and save */
end_comment

begin_comment
comment|/*  it in the device info structure.  This is necessary because    */
end_comment

begin_comment
comment|/*  probe only provides a pointer to the device and we have no     */
end_comment

begin_comment
comment|/*  idea which unit is being referenced.  This works in 4.2BSD     */
end_comment

begin_comment
comment|/*  because the attach routine is called immediately after a       */
end_comment

begin_comment
comment|/*  successful probe.                                              */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          acpprobe(reg)                                   */
end_comment

begin_comment
comment|/*  Argument:      reg:  caddr_t address in virtual memory of the  */
end_comment

begin_comment
comment|/*                        control-status register                  */
end_comment

begin_comment
comment|/*  Returns:       length of register structure for ACP device     */
end_comment

begin_comment
comment|/*  Called by:     network software, part of autoconfiguration on  */
end_comment

begin_comment
comment|/*                 the VAX, the address of this routine is one of  */
end_comment

begin_comment
comment|/*                 the fields of the uba_driver structure          */
end_comment

begin_comment
comment|/*  Calls to:      nothing                                         */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
specifier|static
name|int
name|savevec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* static variable for vector */
end_comment

begin_macro
name|acpprobe
argument_list|(
argument|reg
argument_list|,
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|reg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TWG VAX/VMS ONLY! */
end_comment

begin_block
block|{
ifndef|#
directive|ifndef
name|UBAUVII
comment|/* not for Ultrix 2.0 */
specifier|register
name|int
name|br
decl_stmt|,
name|cvec
decl_stmt|;
comment|/* r11, r10 value-result */
endif|#
directive|endif
endif|UBAUVII
specifier|register
name|struct
name|acpregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|acpregs
operator|*
operator|)
name|reg
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|br
operator|=
literal|0
expr_stmt|;
name|cvec
operator|=
name|br
expr_stmt|;
name|br
operator|=
name|cvec
expr_stmt|;
comment|/* these variables are value-result */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VAXVMS
name|cvec
operator|=
name|savevec
operator|=
name|ui
operator|->
name|ui_flags
operator|&
literal|0x1f8
expr_stmt|;
comment|/* use flags from config file */
else|#
directive|else
name|cvec
operator|=
name|savevec
operator|=
operator|(
name|uba_hd
index|[
name|numuba
index|]
operator|.
name|uh_lastiv
operator|-
literal|8
operator|)
operator|&
operator|~
literal|7
expr_stmt|;
name|uba_hd
index|[
name|numuba
index|]
operator|.
name|uh_lastiv
operator|=
name|cvec
expr_stmt|;
endif|#
directive|endif
endif|VAXVMS
comment|/* return a vector pair */
comment|/*   aligned on QUADWORD boundary */
comment|/* cvec is the interrupt vector   */
comment|/*   address on the UNIBUS        */
comment|/* br is the IPL of the device    */
comment|/*   when it interrupts           */
ifdef|#
directive|ifdef
name|MVAX
name|br
operator|=
literal|0x17
expr_stmt|;
comment|/* return bus level for a uVAX */
else|#
directive|else
name|br
operator|=
literal|0x15
expr_stmt|;
comment|/* return bus level */
endif|#
directive|endif
endif|MVAX
name|addr
operator|->
name|req_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear handshake flags */
name|addr
operator|->
name|cmp_flags
operator|=
literal|0
expr_stmt|;
name|addr
operator|->
name|xfr_flags
operator|=
literal|0
expr_stmt|;
name|addr
operator|->
name|sys_stat
operator|=
literal|0
expr_stmt|;
name|addr
operator|->
name|sys_vect
operator|=
name|cvec
operator|>>
literal|2
expr_stmt|;
comment|/* pass vector to ACP */
name|addr
operator|->
name|csr
operator|=
name|CSR_RESET
expr_stmt|;
comment|/* reset the board */
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
comment|/* enable status intr */
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|acpregs
argument_list|)
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPATTACH()                            %%*/
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
comment|/*  This routine attaches the device to the network software.  The */
end_comment

begin_comment
comment|/*  network interface structure is filled in.  The device will be  */
end_comment

begin_comment
comment|/*  initialized when the system is ready to accept packets.        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           acpattach(ui)                                  */
end_comment

begin_comment
comment|/*  Argument:       ui:  ptr to the uba_device data structure      */
end_comment

begin_comment
comment|/*  Returns:        nothing                                        */
end_comment

begin_comment
comment|/*  Called by:      network software, part of network system       */
end_comment

begin_comment
comment|/*                  configuration, identification to the network   */
end_comment

begin_comment
comment|/*                  software,  the address of this routine is one  */
end_comment

begin_comment
comment|/*                  of the fields of the uba_driver sturcture      */
end_comment

begin_comment
comment|/*  Calls to:       if_attach()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpattach
argument_list|(
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
index|[
name|ui
operator|->
name|ui_unit
index|]
decl_stmt|;
name|ds
operator|->
name|acp_vector
operator|=
name|savevec
expr_stmt|;
comment|/* save vector from probe() */
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
operator|=
name|ui
operator|->
name|ui_unit
expr_stmt|;
comment|/* set unit number */
name|ds
operator|->
name|acp_if
operator|.
name|if_name
operator|=
literal|"acp"
expr_stmt|;
comment|/* set device name */
name|ds
operator|->
name|acp_if
operator|.
name|if_mtu
operator|=
name|ACPMTU
expr_stmt|;
comment|/* set max msg size */
name|ds
operator|->
name|acp_if
operator|.
name|if_init
operator|=
name|acpinit
expr_stmt|;
comment|/* set init routine addr */
name|ds
operator|->
name|acp_if
operator|.
name|if_ioctl
operator|=
name|acpioctl
expr_stmt|;
comment|/* set ioctl routine addr */
name|ds
operator|->
name|acp_if
operator|.
name|if_output
operator|=
name|acpoutput
expr_stmt|;
comment|/* set output routine addr */
name|ds
operator|->
name|acp_if
operator|.
name|if_start
operator|=
name|acpstart
expr_stmt|;
comment|/* set start routine addr */
name|ds
operator|->
name|acp_if
operator|.
name|if_reset
operator|=
name|acpreset
expr_stmt|;
comment|/* set reset routine addr */
name|if_attach
argument_list|(
operator|&
name|ds
operator|->
name|acp_if
argument_list|)
expr_stmt|;
comment|/* attach new network device */
comment|/*  add to list of "active"  */
comment|/*  interfaces, the argument */
comment|/*  passed locates the ifnet */
comment|/*  data structure           */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPRESET()                             %%*/
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
comment|/*      Reset of interface after UNIBUS reset.  If interface is on */
end_comment

begin_comment
comment|/*      specified uba, reset its state.                            */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              acpreset(unit, uban)                        */
end_comment

begin_comment
comment|/*  Arguments:         unit:   ACP device unit number              */
end_comment

begin_comment
comment|/*                     uban:   UNIBUS adapter number               */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         network software, address of routine is     */
end_comment

begin_comment
comment|/*                     defined in acp_if network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:          printf()                                    */
end_comment

begin_comment
comment|/*                     IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpreset
argument_list|(
argument|unit
argument_list|,
argument|uban
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|,
name|uban
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
comment|/* per "device" structure        */
specifier|register
name|struct
name|acpregs
modifier|*
name|addr
decl_stmt|;
comment|/* ACP device register struct    */
specifier|register
name|struct
name|acp_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NACP
operator|||
operator|(
name|ui
operator|=
name|acpinfo
index|[
name|unit
index|]
operator|)
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_alive
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_ubanum
operator|!=
name|uban
condition|)
return|return;
name|printf
argument_list|(
literal|"acp%d\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|acpregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
comment|/* address of device in I/O space  */
name|addr
operator|->
name|req_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear handshake flags, mailbox     */
comment|/*  flags for I/O requests            */
name|addr
operator|->
name|cmp_flags
operator|=
literal|0
expr_stmt|;
comment|/* mailbox flags for I/O completion   */
name|addr
operator|->
name|xfr_flags
operator|=
literal|0
expr_stmt|;
comment|/* mailbox flags for I/O transfer     */
comment|/*  requests                          */
name|addr
operator|->
name|sys_stat
operator|=
literal|0
expr_stmt|;
comment|/* mailbox flags for system status    */
name|addr
operator|->
name|sys_vect
operator|=
name|acp_softc
index|[
name|unit
index|]
operator|.
name|acp_vector
operator|>>
literal|2
expr_stmt|;
comment|/* pass base interrupt */
comment|/*  vector to ACP                     */
name|addr
operator|->
name|csr
operator|=
name|CSR_RESET
expr_stmt|;
comment|/* reset the board                    */
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
comment|/* enable status intr                 */
name|acp_softc
index|[
name|unit
index|]
operator|.
name|acp_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear ACP operational flag         */
name|acp_softc
index|[
name|unit
index|]
operator|.
name|acp_path
operator|=
literal|0
expr_stmt|;
comment|/* clear path allocation flag         */
name|dc
operator|=
name|acp_softc
index|[
name|unit
index|]
operator|.
name|acp_cb
expr_stmt|;
comment|/* flush any queued output data */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|NACPCH
condition|;
name|lcn
operator|++
control|)
comment|/* for all LCN's ... */
block|{
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
name|dc
operator|++
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPINIT()                              %%*/
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
comment|/*    This routine initializes the interface for operation.  The   */
end_comment

begin_comment
comment|/*    device control blocks are initialized, UNIBUS resources are  */
end_comment

begin_comment
comment|/*    allocated and an initialization message is sent to the ACP.  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:             acpinit(unit)                                */
end_comment

begin_comment
comment|/*  Argument:         unit:  ACP device unit number                */
end_comment

begin_comment
comment|/*  Returns:          nothing                                      */
end_comment

begin_comment
comment|/*  Called by:        network software, address of this routine is */
end_comment

begin_comment
comment|/*                    defined in acp_if network interface struct   */
end_comment

begin_comment
comment|/*                    acpioctl()                                   */
end_comment

begin_comment
comment|/*                    acpintb()                                    */
end_comment

begin_comment
comment|/*  Calls to:         in_netof() return the network number from    */
end_comment

begin_comment
comment|/*                               internet address                  */
end_comment

begin_comment
comment|/*                    if_ubainit()                                 */
end_comment

begin_comment
comment|/*                    btoc()                                       */
end_comment

begin_comment
comment|/*                    splimp()                                     */
end_comment

begin_comment
comment|/*                    acp_ioreq()                                  */
end_comment

begin_comment
comment|/*                    acp_alloc()                                  */
end_comment

begin_comment
comment|/*                    acp_init()                                   */
end_comment

begin_comment
comment|/*                    splx()                                       */
end_comment

begin_comment
comment|/*                    if_rtinit()                                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpinit
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|acp_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|acpinfo
index|[
name|unit
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|FOURTWO
name|struct
name|sockaddr_in
modifier|*
name|sin
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
name|acp_if
operator|.
name|if_addrlist
decl_stmt|;
endif|#
directive|endif
name|int
name|lcn
decl_stmt|,
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: acpinit()\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
ifdef|#
directive|ifdef
name|FOURTWO
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
name|acp_if
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
name|ifa
operator|=
name|ds
operator|->
name|acp_if
operator|.
name|ifaddrlist
expr_stmt|;
ifdef|#
directive|ifdef
name|AF_LINK
for|for
control|(
init|;
name|ifa
condition|;
name|ifa
operator|=
name|ifa
operator|->
name|ifa_next
control|)
if|if
condition|(
name|ifa
operator|->
name|ifa_addr
operator|->
name|sa_family
operator|!=
name|AF_LINK
condition|)
break|break;
endif|#
directive|endif
if|if
condition|(
name|ifa
operator|==
literal|0
condition|)
comment|/* if we have no internet addr */
endif|#
directive|endif
return|return;
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_flags
operator|&
name|ACPF_OK
operator|)
operator|==
literal|0
condition|)
comment|/* or if ACP not operational */
return|return;
comment|/*   don't init */
name|dc
operator|=
name|ds
operator|->
name|acp_cb
expr_stmt|;
comment|/* setup ptr to first LCN cntl block */
for|for
control|(
name|lcn
operator|=
name|ACP_ALLOC
init|;
name|lcn
operator|<=
name|NACPCH
condition|;
name|lcn
operator|++
control|)
comment|/* for all LCN's ... */
block|{
name|dc
operator|->
name|dc_lcn
operator|=
name|lcn
expr_stmt|;
comment|/* record LCN */
comment|/* init LCN output queue */
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_head
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
name|dc_oq
operator|.
name|ifq_tail
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
name|dc_oq
operator|.
name|ifq_len
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_maxlen
operator|=
name|ACP_OQMAX
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_drops
operator|=
literal|0
expr_stmt|;
comment|/* init HDX channels */
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_next
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_chan
operator|=
name|lcn
operator|*
literal|2
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_next
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_chan
operator|=
operator|(
name|lcn
operator|*
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* init UNIBUS resources, allocate UNIBUS map registers */
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_if
operator|.
name|if_flags
operator|&
name|IFF_RUNNING
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|if_ubainit
argument_list|(
operator|&
name|dc
operator|->
name|dc_ifuba
argument_list|,
name|ui
operator|->
name|ui_ubanum
argument_list|,
literal|0
argument_list|,
operator|(
name|int
operator|)
name|btoc
argument_list|(
name|ACPMTU
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: failed getting UBA resources for lcn %d\n"
argument_list|,
name|unit
argument_list|,
name|lcn
argument_list|)
expr_stmt|;
name|ds
operator|->
name|acp_if
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
return|return;
block|}
block|}
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
comment|/* initialize flags */
name|dc
operator|++
expr_stmt|;
comment|/* point at next cntl blk */
block|}
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_tail
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|ds
operator|->
name|acp_if
operator|.
name|if_flags
operator||=
name|IFF_RUNNING
expr_stmt|;
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/* disable interrupts        */
name|dc
operator|=
name|ds
operator|->
name|acp_cb
expr_stmt|;
comment|/* setup ptr to first LCN cntl block */
for|for
control|(
name|lcn
operator|=
name|ACP_ALLOC
init|;
name|lcn
operator|<=
name|NACPCH
condition|;
name|lcn
operator|++
control|)
comment|/* issue reads on all LCNs */
block|{
name|acp_iorq
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|,
name|ACPMTU
argument_list|,
name|ACPRED
operator|+
name|ACPSTR
argument_list|)
expr_stmt|;
name|dc
operator|++
expr_stmt|;
block|}
comment|/* if not already established, allocate control and data paths  */
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_path
operator|&
name|ACP_SUPR
operator|)
operator|==
literal|0
condition|)
name|acp_alloc
argument_list|(
name|ds
argument_list|,
name|TYPE_CNTL
argument_list|)
expr_stmt|;
comment|/* allocate control path  */
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_path
operator|&
name|ACP_DATA
operator|)
operator|==
literal|0
condition|)
name|acp_alloc
argument_list|(
name|ds
argument_list|,
name|TYPE_DATA
argument_list|)
expr_stmt|;
comment|/* allocate data path     */
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_path
operator|&
name|INIT_OK
operator|)
operator|==
name|INIT_OK
condition|)
block|{
name|acp_init
argument_list|(
name|ds
argument_list|)
expr_stmt|;
comment|/* init the ACP, if ioctl to do so */
name|ds
operator|->
name|acp_path
operator|&=
operator|~
name|INIT_OK
expr_stmt|;
comment|/* turn off flag for acpinit() */
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* enable interrupts        */
ifdef|#
directive|ifdef
name|FOURTWO
name|if_rtinit
argument_list|(
operator|&
name|ds
operator|->
name|acp_if
argument_list|,
name|RTF_UP
argument_list|)
expr_stmt|;
comment|/* initialize the routing table entry */
comment|/*  according to the network, args    */
comment|/*  are the addr of the ifnet struct  */
comment|/*  and RTF_UP means the route is     */
comment|/*  useable                           */
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPOUTPUT()                            %%*/
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
comment|/*   IP datagram to send out this interface.  The datagtram is     */
end_comment

begin_comment
comment|/*   queued for output on that LCN.                                */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            acpoutput(ifp, m0, dst)                       */
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
comment|/*                 defined in the acp_if network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:      printf()                                        */
end_comment

begin_comment
comment|/*                 mfreem()                                        */
end_comment

begin_comment
comment|/*                 splimp()                                        */
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
comment|/*                 m_freem()                                       */
end_comment

begin_comment
comment|/*                 acp_start()                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpoutput
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

begin_comment
comment|/* network interface          */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer                     */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|dst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket destination address */
end_comment

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
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
index|[
name|ifp
operator|->
name|if_unit
index|]
decl_stmt|;
specifier|register
name|struct
name|acp_cb
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
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_if
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
comment|/* address format of protocol family */
comment|/*  this is the internet:  TCP, UDP, */
comment|/*  ICMP, IP, etc.                   */
break|break;
endif|#
directive|endif
endif|INET
default|default:
name|printf
argument_list|(
literal|"acp%d: can't handle af%d\n"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|,
name|dst
operator|->
name|sin_family
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
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|6
condition|)
block|{
name|printf
argument_list|(
literal|"acpoutput(): dst = "
argument_list|)
expr_stmt|;
name|prt_addr
argument_list|(
name|dst
operator|->
name|sin_addr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
comment|/* In 4.3, the IP code may pass mbuf chains with 0-length mbufs */
comment|/* This causes "transfer count = 0" messages and might even     */
comment|/* cause actual garbage data transmission if the mbuf is at the */
comment|/* end of the chain (we don't think it ever will be, but one    */
comment|/* can't be too sure...so we scan the chain first).		    */
comment|/* WE DO ASSUME that there is at least one nonempty mbuf!	    */
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
comment|/* disable interrupts  */
name|dc
operator|=
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_DATA
index|]
operator|)
expr_stmt|;
comment|/*   data channel          */
name|oq
operator|=
operator|&
operator|(
name|dc
operator|->
name|dc_oq
operator|)
expr_stmt|;
comment|/*   point to output queue */
if|if
condition|(
name|IF_QFULL
argument_list|(
name|oq
argument_list|)
condition|)
comment|/*   if q full */
block|{
name|IF_DROP
argument_list|(
name|oq
argument_list|)
expr_stmt|;
comment|/*     drop the data */
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|ds
operator|->
name|acp_if
operator|.
name|if_collisions
operator|++
expr_stmt|;
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
comment|/*   otherwise queue it */
name|acp_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
comment|/*   and try to output  */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/*   enable interrupts  */
return|return
operator|(
literal|0
operator|)
return|;
comment|/*   successful return  */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPIOCTL()                             %%*/
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
comment|/*   This routine processes device dependent ioctl's.  Supported   */
end_comment

begin_comment
comment|/*   ioctls set the host's internet address for this network       */
end_comment

begin_comment
comment|/*   interface, or send CIMs (Command Interface Messages) to the   */
end_comment

begin_comment
comment|/*   ACP (ie to bring up the line).  The logic for setting the     */
end_comment

begin_comment
comment|/*   interface address must remain compatible with both ifconfig   */
end_comment

begin_comment
comment|/*   and acpconfig programs.                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            acpioctl(ifp, cmd, data)                      */
end_comment

begin_comment
comment|/*  Argument:        ifp:   pointer to the network interface data  */
end_comment

begin_comment
comment|/*                               structure, ifnet                  */
end_comment

begin_comment
comment|/*                   cmd:   identifies the type of ioctl           */
end_comment

begin_comment
comment|/*                   data:  information for the ioctl              */
end_comment

begin_comment
comment|/*  Returns:         0 for success, or the nonzero error value:    */
end_comment

begin_comment
comment|/*                                EINVAL invalid ioctl request     */
end_comment

begin_comment
comment|/*  Called by:        network software, address of this routine is */
end_comment

begin_comment
comment|/*                    defined in af_inet network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:         splimp()                                     */
end_comment

begin_comment
comment|/*                    if_rtinit()                                  */
end_comment

begin_comment
comment|/*                    in_netof()                                   */
end_comment

begin_comment
comment|/*                    in_lnaof()                                   */
end_comment

begin_comment
comment|/*                    acpinit()                                    */
end_comment

begin_comment
comment|/*                    acpreset()                                   */
end_comment

begin_comment
comment|/*                    printf()                                     */
end_comment

begin_comment
comment|/*                    splx()                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_expr_stmt
name|acpioctl
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

begin_comment
comment|/* network interface data structure      */
end_comment

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of ioctl request                 */
end_comment

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of data for ioctl request     */
end_comment

begin_block
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|acpinfo
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
comment|/* ifreq is the interface */
comment|/* request struct used for socket ioctls  */
name|struct
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
index|[
name|ifp
operator|->
name|if_unit
index|]
decl_stmt|;
name|int
name|s
init|=
name|splimp
argument_list|()
decl_stmt|,
name|error
init|=
literal|0
decl_stmt|;
comment|/* disable interrupts    */
ifdef|#
directive|ifdef
name|FOURTWO
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
name|acp_if
operator|.
name|if_addrlist
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d:  acpioctl()\n"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SIOCSIFADDR
case|:
comment|/* set ifnet address    */
ifdef|#
directive|ifdef
name|FOURTWO
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
comment|/* RTF_UP means route useable */
else|else
name|acpinit
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
else|#
directive|else
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
name|acpinit
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
name|ds
operator|->
name|acp_ipaddr
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
break|break;
case|case
name|SIOCACPCONFIG
case|:
comment|/* if not trying to bring down link (case '0') then trying to bring */
comment|/* it up, or reconfigure it -- don't do cmd unless internet address */
comment|/* has already been set                                             */
if|if
condition|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
operator|!=
literal|'0'
condition|)
block|{
ifdef|#
directive|ifdef
name|FOURTWO
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
name|acp_if
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
name|acp_if
operator|.
name|if_addrlist
operator|==
literal|0
condition|)
endif|#
directive|endif
block|{
name|printf
argument_list|(
literal|"acp%d:  no internet address is set,"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" acpconfig command ignored\n"
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
block|}
name|acpreset
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|,
name|ui
operator|->
name|ui_ubanum
argument_list|)
expr_stmt|;
comment|/* reset device */
name|ds
operator|->
name|acp_path
operator||=
name|INIT_OK
expr_stmt|;
comment|/* set flag for acpinit() */
comment|/* if command is set the baud rate, then set clocking for  */
comment|/* internal generation, and look up the value for the baud */
comment|/* rate divisor in the baud_rate table, put this value in  */
comment|/* the Set System Parameters message, ssp_msg              */
if|if
condition|(
operator|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
operator|>=
literal|1
operator|)
operator|&&
operator|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
operator|<=
literal|14
operator|)
condition|)
block|{
specifier|register
name|struct
name|baud
modifier|*
name|p
decl_stmt|;
name|ssp_msg
index|[
name|CLOCK_OFFSET
index|]
operator|=
name|INTERNAL_CLOCK
expr_stmt|;
for|for
control|(
name|p
operator|=
name|baud_rate
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
name|ssp_msg
index|[
name|BAUD_OFFSET
index|]
operator|=
name|p
operator|->
name|parameter1
expr_stmt|;
name|ssp_msg
index|[
name|BAUD_OFFSET
operator|+
literal|1
index|]
operator|=
name|p
operator|->
name|parameter2
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|b_value
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: invalid value for baud rate\n"
argument_list|,
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
block|}
else|else
block|{
switch|switch
condition|(
operator|*
operator|(
name|ifr
operator|->
name|ifr_data
operator|)
condition|)
block|{
case|case
literal|'0'
case|:
name|ssp_msg
index|[
name|DOWN_OFFSET
index|]
operator|=
name|LINK_DISABLE
expr_stmt|;
break|break;
case|case
literal|'1'
case|:
name|ssp_msg
index|[
name|LOOP_OFFSET
index|]
operator|=
name|LOOP_NONE
expr_stmt|;
name|ssp_msg
index|[
name|DTE_OFFSET
index|]
operator|=
name|DTE_MODE
expr_stmt|;
name|ssp_msg
index|[
name|DOWN_OFFSET
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
break|break;
case|case
literal|'2'
case|:
name|ssp_msg
index|[
name|LOOP_OFFSET
index|]
operator|=
name|LOOP_NONE
expr_stmt|;
name|ssp_msg
index|[
name|DTE_OFFSET
index|]
operator|=
name|DCE_MODE
expr_stmt|;
name|ssp_msg
index|[
name|DOWN_OFFSET
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
break|break;
case|case
literal|'3'
case|:
name|ssp_msg
index|[
name|LOOP_OFFSET
index|]
operator|=
name|LOOP_EXTERNAL
expr_stmt|;
name|ssp_msg
index|[
name|DOWN_OFFSET
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
break|break;
case|case
literal|'4'
case|:
name|ssp_msg
index|[
name|LOOP_OFFSET
index|]
operator|=
name|LOOP_INTERNAL
expr_stmt|;
name|ssp_msg
index|[
name|DOWN_OFFSET
index|]
operator|=
name|LINK_ENABLE
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|ssp_msg
index|[
name|CLOCK_OFFSET
index|]
operator|=
name|EXTERNAL_CLOCK
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
goto|goto
name|exit
goto|;
block|}
block|}
name|acpinit
argument_list|(
name|ifp
operator|->
name|if_unit
argument_list|)
expr_stmt|;
comment|/* send ssp_msg to frontend */
break|break;
default|default:
name|error
operator|=
name|EINVAL
expr_stmt|;
block|}
name|exit
label|:
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* enable interrupts   */
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPINTA()                              %%*/
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
comment|/*  This is the interrupt handler for I/O interrupts from the ACP  */
end_comment

begin_comment
comment|/*  The I/O mailboxes are scanned for handshake events to process. */
end_comment

begin_comment
comment|/*  The events are Transfer Request, I/O Request done and I/O      */
end_comment

begin_comment
comment|/*  Completion ready.  Note that the Transfer Request is not yet   */
end_comment

begin_comment
comment|/*  supported; an error message is printed if one is received.     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           acpinta(unit)                                  */
end_comment

begin_comment
comment|/*  Argument:       unit:  ACP device unit number                  */
end_comment

begin_comment
comment|/*  Returns:        nothing                                        */
end_comment

begin_comment
comment|/*  Called by:      network software, address of this routine is   */
end_comment

begin_comment
comment|/*                  defined in af_inet network interface struct    */
end_comment

begin_comment
comment|/*  Calls to:       printf()                                       */
end_comment

begin_comment
comment|/*                  start_chn()                                    */
end_comment

begin_comment
comment|/*                  acp_data()                                     */
end_comment

begin_comment
comment|/*                  acp_supr()                                     */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpinta
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|acpregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|acpregs
operator|*
operator|)
name|acpinfo
index|[
name|unit
index|]
operator|->
name|ui_addr
decl_stmt|;
specifier|register
name|struct
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
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
name|int
name|chan
decl_stmt|,
name|cc
decl_stmt|,
name|cnt
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|7
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: acpinta()\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
comment|/* Figure out what kind of interrupt it was */
if|if
condition|(
name|addr
operator|->
name|xfr_flags
operator|&
name|FLAGS_RDY
condition|)
comment|/* Transfer Request Mailbox */
block|{
name|printf
argument_list|(
literal|"acp%d: UNEXPECTED TRANSFER REQUEST!\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|addr
operator|->
name|xfr_cnt
operator|=
literal|0
expr_stmt|;
name|addr
operator|->
name|xfr_flags
operator|=
operator|(
name|addr
operator|->
name|xfr_flags
operator|&
operator|~
name|FLAGS_RDY
operator|)
operator||
name|FLAGS_DON
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
block|}
if|if
condition|(
name|addr
operator|->
name|req_flags
operator|&
name|FLAGS_DON
condition|)
comment|/* I/O Request Mailbox  */
block|{
comment|/* try to start any queued i/o request */
if|if
condition|(
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
operator|=
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
operator|->
name|hc_next
condition|)
block|{
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|addr
operator|->
name|req_flags
operator|&=
operator|~
name|FLAGS_DON
expr_stmt|;
block|}
block|}
if|if
condition|(
name|addr
operator|->
name|cmp_flags
operator|&
name|FLAGS_RDY
condition|)
comment|/* I/O Completion  Mailbox */
block|{
comment|/* 	 * Get logical channel info. 	 */
if|if
condition|(
operator|(
name|chan
operator|=
name|addr
operator|->
name|cmp_chan
operator|)
operator|>
name|NACPCH
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: unknown channel, chan=%d\n"
argument_list|,
name|unit
argument_list|,
name|chan
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|addr
operator|->
name|cmp_flags
operator|&
name|FLAGS_DIR
condition|)
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|chan
index|]
operator|.
name|dc_wchan
operator|)
expr_stmt|;
else|else
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|chan
index|]
operator|.
name|dc_rchan
operator|)
expr_stmt|;
name|cc
operator|=
name|addr
operator|->
name|cmp_stat
expr_stmt|;
comment|/* Mailbox I/O completion status      */
name|cnt
operator|=
name|addr
operator|->
name|cmp_cnt
expr_stmt|;
comment|/* Mailbox I/O completion byte count  */
switch|switch
condition|(
name|cc
condition|)
comment|/* check for unsuccessful I/O completion status */
block|{
case|case
name|ACPIOCABT
case|:
name|printf
argument_list|(
literal|"acp%d: I/O abort "
argument_list|,
name|unit
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|ACPIOCERR
case|:
name|printf
argument_list|(
literal|"acp%d: program error "
argument_list|,
name|unit
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|ACPIOCOVR
case|:
name|printf
argument_list|(
literal|"acp%d: overrun error "
argument_list|,
name|unit
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|ACPIOCUBE
case|:
name|printf
argument_list|(
literal|"acp%d: NXM timeout or UB parity error "
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|daterr
label|:
name|printf
argument_list|(
literal|"chan=%d func=%x\n"
argument_list|,
name|chan
argument_list|,
name|hc
operator|->
name|hc_func
argument_list|)
expr_stmt|;
if|if
condition|(
name|addr
operator|->
name|cmp_flags
operator|&
name|FLAGS_DIR
condition|)
name|ds
operator|->
name|acp_if
operator|.
name|if_oerrors
operator|++
expr_stmt|;
else|else
name|ds
operator|->
name|acp_if
operator|.
name|if_ierrors
operator|++
expr_stmt|;
block|}
comment|/* was it supervisor or data traffic? */
if|if
condition|(
name|chan
operator|>
name|ACP_SUPR
condition|)
name|acp_data
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
else|else
name|acp_supr
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|,
name|chan
argument_list|)
expr_stmt|;
comment|/* chan = ACP_ALLOC or ACP_SUPR */
comment|/*     	 * Ack the interrupt.  Fix the Mailbox Ready and Done bits:  set          * DON bits, and clear RDY bits so mailbox may be reused.     	 */
name|addr
operator|->
name|cmp_flags
operator|=
operator|(
name|addr
operator|->
name|cmp_flags
operator|&
operator|~
name|FLAGS_RDY
operator|)
operator||
name|FLAGS_DON
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
comment|/* enable interrupt "a" */
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACPINTB()                              %%*/
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
comment|/*   This is the interrupt handler for system interrupts from the  */
end_comment

begin_comment
comment|/*   ACP.                                                          */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:             acpintb(unit)                                */
end_comment

begin_comment
comment|/*  Argument:         unit: ACP device unit number                 */
end_comment

begin_comment
comment|/*  Returns:          nothing                                      */
end_comment

begin_comment
comment|/*  Called by:        network software, address of this routine is */
end_comment

begin_comment
comment|/*                    defined in af_inet network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:         printf()                                     */
end_comment

begin_comment
comment|/*                    acpinit()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|acpintb
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|acpregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|acpregs
operator|*
operator|)
name|acpinfo
index|[
name|unit
index|]
operator|->
name|ui_addr
decl_stmt|;
specifier|register
name|struct
name|acp_softc
modifier|*
name|ds
init|=
operator|&
name|acp_softc
index|[
name|unit
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: acpintb()\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
if|if
condition|(
name|ds
operator|->
name|acp_flags
operator|&
name|ACPF_OK
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: Unexpected System interrupt, status = %d\n"
argument_list|,
name|unit
argument_list|,
name|addr
operator|->
name|sys_stat
argument_list|)
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"acp%d: DISABLED!\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|ds
operator|->
name|acp_if
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
block|}
else|else
block|{
if|if
condition|(
name|addr
operator|->
name|sys_stat
operator|!=
name|ACPSTAT_OK
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: PWRUP Diagnostic failure = %d\n"
argument_list|,
name|unit
argument_list|,
name|addr
operator|->
name|sys_stat
argument_list|)
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|ds
operator|->
name|acp_flags
operator||=
name|ACPF_OK
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
operator|(
name|CSR_IENA
operator||
name|CSR_DMAEN
operator|)
expr_stmt|;
name|acpinit
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                             %%*/
end_comment

begin_comment
comment|/*%%                   LOCAL  ROUTINES                           %%*/
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
comment|/*%%                      ACP_ALLOC()                            %%*/
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
comment|/*   This routine allocates control or data paths.  Commands are   */
end_comment

begin_comment
comment|/*   sent (over DPN 0) from the host to the ALLOC facility on the  */
end_comment

begin_comment
comment|/*   front end to allocate the paths.  The ALLOC facility returns  */
end_comment

begin_comment
comment|/*   a response to the allocation command which indicates success  */
end_comment

begin_comment
comment|/*   or failure.  Note that DPN 0 is used only for the ALLOC       */
end_comment

begin_comment
comment|/*   commands, and is not a control path as it was been in the     */
end_comment

begin_comment
comment|/*   past.  The paths are symbolically defined as ACP_ALLOC,       */
end_comment

begin_comment
comment|/*   ACP_SUPR, and ACP_DATA for allocation messages, control       */
end_comment

begin_comment
comment|/*   messages, and data respectively.  The CID field indicates     */
end_comment

begin_comment
comment|/*   the data path number of the allocation command.  The CID      */
end_comment

begin_comment
comment|/*   is set here so that the response will have the same CID, and  */
end_comment

begin_comment
comment|/*   will therefore indicate to which path the response            */
end_comment

begin_comment
comment|/*   corresponds. (The CID is set in the command and must be       */
end_comment

begin_comment
comment|/*   returned, untouched, in the response.)                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          acp_alloc(ds, type)                             */
end_comment

begin_comment
comment|/*  Argument:      ds:  pointer to ACP device control structure    */
end_comment

begin_comment
comment|/*                 type:  specifies if path is for control or data */
end_comment

begin_comment
comment|/*  Returns:       nothing                                         */
end_comment

begin_comment
comment|/*  Called by:     acpinit()                                       */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     printf()                                    */
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
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_alloc
parameter_list|(
name|ds
parameter_list|,
name|type
parameter_list|)
name|struct
name|acp_softc
modifier|*
name|ds
decl_stmt|;
name|int
name|type
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
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|4
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: acp_alloc()\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|MGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
comment|/* try to get init buffer */
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: couldn't get init buffer\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* modify the path allocation message to get a control path */
comment|/* or a data path                                           */
if|if
condition|(
name|type
operator|==
name|TYPE_CNTL
condition|)
block|{
name|alloc_msg
index|[
name|CID_OFFSET
index|]
operator|=
name|ACP_SUPR
expr_stmt|;
comment|/* set CID for response */
name|alloc_msg
index|[
name|DPN_OFFSET
index|]
operator|=
name|ACP_SUPR
expr_stmt|;
comment|/* path number          */
name|alloc_msg
index|[
name|TYPE_OFFSET
index|]
operator|=
name|TYPE_CNTL
expr_stmt|;
comment|/* path type = control  */
block|}
else|else
block|{
name|alloc_msg
index|[
name|CID_OFFSET
index|]
operator|=
name|ACP_DATA
expr_stmt|;
comment|/* set CID for response  */
name|alloc_msg
index|[
name|DPN_OFFSET
index|]
operator|=
name|ACP_DATA
expr_stmt|;
comment|/* path number           */
name|alloc_msg
index|[
name|TYPE_OFFSET
index|]
operator|=
name|TYPE_DATA
expr_stmt|;
comment|/* path type = data      */
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
name|bcopy
argument_list|(
name|alloc_msg
argument_list|,
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|alloc_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* set sys params msg in mbuf */
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|5
condition|)
block|{
name|printf
argument_list|(
literal|"acp_alloc():  "
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|alloc_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* print 12-byte header + data */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|m
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
name|alloc_msg
argument_list|)
expr_stmt|;
comment|/* set msg length */
name|IF_ENQUEUE
argument_list|(
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_ALLOC
index|]
operator|.
name|dc_oq
operator|)
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* output queue   */
name|acp_start
argument_list|(
name|ds
argument_list|,
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_ALLOC
index|]
operator|)
argument_list|)
expr_stmt|;
comment|/* start ouput of data  */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_INIT()                             %%*/
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
comment|/*   This routine builds and sends an initialization message to    */
end_comment

begin_comment
comment|/*   the ACP.  A canned Set System Parameters Message is sent to   */
end_comment

begin_comment
comment|/*   start HDLC.                                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          acp_init(ds)                                    */
end_comment

begin_comment
comment|/*  Argument:      ds:  pointer to ACP device control structure    */
end_comment

begin_comment
comment|/*  Returns:                nothing                                */
end_comment

begin_comment
comment|/*  Called by:         acpinit()                                   */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     printf()                                    */
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
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_init
parameter_list|(
name|ds
parameter_list|)
name|struct
name|acp_softc
modifier|*
name|ds
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
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|5
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: acp_init()\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|MGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
comment|/* try to get init buffer */
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: couldn't get init buffer\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
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
name|bcopy
argument_list|(
name|ssp_msg
argument_list|,
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|ssp_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* put msg into mbuf */
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|4
condition|)
block|{
name|printf
argument_list|(
literal|"acp_init():  ssp msg\n"
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|ssp_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* print 12-byte header + data */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|m
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
name|ssp_msg
argument_list|)
expr_stmt|;
comment|/* set msg length */
name|IF_ENQUEUE
argument_list|(
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_SUPR
index|]
operator|.
name|dc_oq
operator|)
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* output queue   */
name|acp_start
argument_list|(
name|ds
argument_list|,
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_SUPR
index|]
operator|)
argument_list|)
expr_stmt|;
comment|/* start ouput of data  */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_START()                            %%*/
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
comment|/*    buffer and an I/O request queued to the ACP.                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              acpstart(ds, dc)                            */
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
comment|/*  Called by:         acpoutput()                                 */
end_comment

begin_comment
comment|/*                     acp_init()                                  */
end_comment

begin_comment
comment|/*                     acp_data()                                  */
end_comment

begin_comment
comment|/*                     acp_supr()                                  */
end_comment

begin_comment
comment|/*  Calls to:          IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     if_wubaput()                                */
end_comment

begin_comment
comment|/*                     acp_ioreqs()                                */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_start
parameter_list|(
name|ds
parameter_list|,
name|dc
parameter_list|)
specifier|register
name|struct
name|acp_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|acp_cb
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
name|int
name|len
decl_stmt|;
comment|/*      * If output isn't active, attempt to      * start sending a new packet.      */
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|7
condition|)
block|{
name|printf
argument_list|(
literal|"acp: acp_start()\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
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
condition|)
return|return;
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
comment|/* remove data from LCN output queue */
name|len
operator|=
name|if_wubaput
argument_list|(
operator|&
name|dc
operator|->
name|dc_ifuba
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* copy data to mapped mem */
if|if
condition|(
name|len
operator|>
name|ds
operator|->
name|acp_maxout
condition|)
block|{
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|7
condition|)
block|{
name|printf
argument_list|(
literal|"acp: %d byte msg sent.\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|ds
operator|->
name|acp_maxout
operator|=
name|len
expr_stmt|;
block|}
name|dc
operator|->
name|dc_flags
operator||=
name|DC_OBUSY
expr_stmt|;
name|acp_iorq
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|,
name|len
argument_list|,
name|ACPWRT
operator|+
name|ACPEOS
argument_list|)
expr_stmt|;
comment|/* build I/O request, enqueue */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_IORQ()                             %%*/
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
comment|/*    This routine builds ACP I/O requests and queues them for     */
end_comment

begin_comment
comment|/*    delivery to the ACP. If the ACP I/O request comm regs are    */
end_comment

begin_comment
comment|/*    not busy, the I/O request is passed to the ACP.              */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            acp_iorq(ds, dc, len, func)                   */
end_comment

begin_comment
comment|/*  Argument:        ds:   pointer to device control block struct  */
end_comment

begin_comment
comment|/*                   dc:   pointer to the Logical Channel control  */
end_comment

begin_comment
comment|/*                                block structure                  */
end_comment

begin_comment
comment|/*                   len:  byte count                              */
end_comment

begin_comment
comment|/*                   func: the function:  read or write            */
end_comment

begin_comment
comment|/*  Returns:         nothing                                       */
end_comment

begin_comment
comment|/*  Called by:         acpinit()                                   */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                     acp_data()                                  */
end_comment

begin_comment
comment|/*                     acp_supr()                                  */
end_comment

begin_comment
comment|/*  Calls to:          start_chn()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_iorq
parameter_list|(
name|ds
parameter_list|,
name|dc
parameter_list|,
name|len
parameter_list|,
name|func
parameter_list|)
name|struct
name|acp_softc
modifier|*
name|ds
decl_stmt|;
name|struct
name|acp_cb
modifier|*
name|dc
decl_stmt|;
name|int
name|len
decl_stmt|,
name|func
decl_stmt|;
block|{
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
specifier|register
name|int
name|info
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|6
condition|)
name|printf
argument_list|(
literal|"acp: acp_iorq()\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|ACPDEBUG
comment|/* get appropriate UNIBUS mapping info */
if|if
condition|(
operator|(
name|func
operator|&
name|FCN_MASK
operator|)
operator|==
name|ACPRED
condition|)
comment|/* read or write? */
block|{
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_rchan
expr_stmt|;
comment|/* read */
name|info
operator|=
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_info
expr_stmt|;
block|}
else|else
block|{
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_wchan
expr_stmt|;
comment|/* write */
name|info
operator|=
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_w
operator|.
name|ifrw_info
expr_stmt|;
block|}
comment|/* set channel info */
name|hc
operator|->
name|hc_adx
operator|=
call|(
name|u_char
call|)
argument_list|(
operator|(
name|info
operator|&
literal|0x30000
operator|)
operator|>>
literal|12
argument_list|)
expr_stmt|;
comment|/* address bits 17-16 */
name|hc
operator|->
name|hc_addr
operator|=
call|(
name|unsigned
name|short
call|)
argument_list|(
name|info
operator|&
literal|0xffff
argument_list|)
expr_stmt|;
comment|/* address bits 15-00 */
name|hc
operator|->
name|hc_cnt
operator|=
name|len
expr_stmt|;
comment|/* byte count         */
name|hc
operator|->
name|hc_func
operator|=
operator|(
name|u_char
operator|)
name|func
expr_stmt|;
comment|/* I/O function       */
if|if
condition|(
name|dc
operator|->
name|dc_lcn
operator|>
name|ACP_SUPR
condition|)
name|hc
operator|->
name|hc_sbfc
operator|=
name|SBFCN_DATA
expr_stmt|;
comment|/* I/O subfunction for data */
else|else
name|hc
operator|->
name|hc_sbfc
operator|=
name|SBFCN_SUPR
expr_stmt|;
comment|/* I/O subfunction for cntrl */
comment|/*      * If ACP comm regs busy, queue start i/o for later.      */
if|if
condition|(
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
condition|)
block|{
operator|(
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_tail
operator|)
operator|->
name|hc_next
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* start i/o on channel now */
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      START_CHN()                            %%*/
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
comment|/*    This routine copies ACP I/O requests into the ACP comm regs  */
end_comment

begin_comment
comment|/*    and notifies the ACP.                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              start_chn(ds)                               */
end_comment

begin_comment
comment|/*  Argument:          ds:  pointer to device control block struct */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         acpinta()                                   */
end_comment

begin_comment
comment|/*                     acp_iorq()                                  */
end_comment

begin_comment
comment|/*  Calls to:          none                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|start_chn
parameter_list|(
name|ds
parameter_list|)
name|struct
name|acp_softc
modifier|*
name|ds
decl_stmt|;
block|{
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
init|=
name|ds
operator|->
name|acp_sioq
operator|.
name|sq_head
decl_stmt|;
specifier|register
name|struct
name|acpregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|acpregs
operator|*
operator|)
name|acpinfo
index|[
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
index|]
operator|->
name|ui_addr
decl_stmt|;
comment|/*      * Set up comm regs.      */
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|7
condition|)
block|{
name|printf
argument_list|(
literal|"acp: start_chn()\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|addr
operator|->
name|req_chan
operator|=
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
expr_stmt|;
name|addr
operator|->
name|req_adx
operator|=
name|hc
operator|->
name|hc_adx
expr_stmt|;
name|addr
operator|->
name|req_addr
operator|=
name|hc
operator|->
name|hc_addr
expr_stmt|;
name|addr
operator|->
name|req_cnt
operator|=
name|hc
operator|->
name|hc_cnt
expr_stmt|;
name|addr
operator|->
name|req_fcn
operator|=
name|hc
operator|->
name|hc_func
expr_stmt|;
name|addr
operator|->
name|req_sbf
operator|=
name|hc
operator|->
name|hc_sbfc
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|1
condition|)
name|addr
operator|->
name|req_flags
operator|=
name|FLAGS_RDY
operator||
name|FLAGS_DIR
expr_stmt|;
else|else
name|addr
operator|->
name|req_flags
operator|=
name|FLAGS_RDY
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_DATA()                             %%*/
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
comment|/*  Call:              acp_data(ds, hc, cc, rcnt)                  */
end_comment

begin_comment
comment|/*  Arguments:         ds:  pointer to device control block struct */
end_comment

begin_comment
comment|/*                     hc:  pointer to half duplex channel control */
end_comment

begin_comment
comment|/*                               block                             */
end_comment

begin_comment
comment|/*                     cc:  Mailbox I/O completion status          */
end_comment

begin_comment
comment|/*                     rcnt: byte count                            */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         acpinta()                                   */
end_comment

begin_comment
comment|/*  Calls to:          m_freem()                                   */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                     if_rubaget()                                */
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
comment|/*                     acp_ioreq()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_data
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|cc
parameter_list|,
name|rcnt
parameter_list|)
specifier|register
name|struct
name|acp_softc
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
name|rcnt
decl_stmt|;
block|{
specifier|register
name|struct
name|acp_cb
modifier|*
name|dc
init|=
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|hc
operator|->
name|hc_chan
operator|/
literal|2
index|]
operator|)
decl_stmt|;
specifier|register
name|struct
name|ifqueue
modifier|*
name|inq
init|=
operator|&
name|ipintrq
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
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
comment|/*   write, fire up next output */
name|ds
operator|->
name|acp_if
operator|.
name|if_opackets
operator|++
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
condition|)
block|{
name|m_freem
argument_list|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
operator|=
literal|0
expr_stmt|;
block|}
name|dc
operator|->
name|dc_flags
operator|&=
operator|~
name|DC_OBUSY
expr_stmt|;
name|acp_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
block|}
else|else
comment|/*   read, process rcvd packet */
block|{
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|6
condition|)
block|{
name|printf
argument_list|(
literal|"acp: data read completed, cc = %d, cnt = %d\n"
argument_list|,
name|cc
argument_list|,
name|rcnt
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_addr
operator|)
argument_list|,
operator|(
name|rcnt
operator|<
literal|20
condition|?
name|rcnt
else|:
literal|20
operator|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
if|if
condition|(
name|cc
operator|==
name|ACPIOCOK
condition|)
block|{
comment|/* Queue good packet for input */
name|ds
operator|->
name|acp_if
operator|.
name|if_ipackets
operator|++
expr_stmt|;
if|if
condition|(
name|rcnt
operator|>
name|ds
operator|->
name|acp_maxin
condition|)
block|{
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|4
condition|)
block|{
name|printf
argument_list|(
literal|"acp: %d byte msg received.\n"
argument_list|,
name|rcnt
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|ds
operator|->
name|acp_maxin
operator|=
name|rcnt
expr_stmt|;
block|}
comment|/* call if_rubaget() to pull read data  */
comment|/*  off the interface, the args are the */
comment|/*  ifuba struct, the length of data,   */
comment|/*  and the 0 indicates that no trailer */
comment|/*  protocol is used                    */
name|m
operator|=
name|if_rubaget
argument_list|(
operator|&
operator|(
name|dc
operator|->
name|dc_ifuba
operator|)
argument_list|,
name|rcnt
argument_list|,
literal|0
argument_list|,
operator|&
operator|(
name|ds
operator|->
name|acp_if
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
block|{
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
block|}
block|}
comment|/* hang a new data read */
name|acp_iorq
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|,
name|ACPMTU
argument_list|,
name|ACPRED
operator|+
name|ACPSTR
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_RESPONSE()                         %%*/
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
comment|/*   This routine sends a Control Interface Message (CIM) response */
end_comment

begin_comment
comment|/*   to the front end to indicate that a CIM command from the      */
end_comment

begin_comment
comment|/*   front end was successfully received.  Presently there are two */
end_comment

begin_comment
comment|/*   types of CIM responses sent to the front end:  frame level    */
end_comment

begin_comment
comment|/*   up, and frame level down.  Future applications may send a     */
end_comment

begin_comment
comment|/*   CIM response to DCP CIM commands.  The basic philosophy with  */
end_comment

begin_comment
comment|/*   CIMs is that there is always a paired command/response which  */
end_comment

begin_comment
comment|/*   is exchanged between the host and the front end.              */
end_comment

begin_comment
comment|/*   Currently, the front end does not process the responses from  */
end_comment

begin_comment
comment|/*   the host, they are merely discarded.  The one thing left to   */
end_comment

begin_comment
comment|/*   do in the case that the front end does ever look at these     */
end_comment

begin_comment
comment|/*   responses is to use the same CID (Command ID field, bytes 5   */
end_comment

begin_comment
comment|/*   to 8 of the CIM header) that was present in the command.      */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          acp_response(ds, response)                      */
end_comment

begin_comment
comment|/*  Argument:      ds:  pointer to ACP device control structure    */
end_comment

begin_comment
comment|/*                 response:  response for CIM command field       */
end_comment

begin_comment
comment|/*                   the response value = command value + 1        */
end_comment

begin_comment
comment|/*  Returns:       nothing                                         */
end_comment

begin_comment
comment|/*  Called by:     supr_msg()                                      */
end_comment

begin_comment
comment|/*  Calls to:          MGET()                                      */
end_comment

begin_comment
comment|/*                     printf()                                    */
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
comment|/*                     IF_ENQUEUE()                                */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_response
parameter_list|(
name|ds
parameter_list|,
name|response
parameter_list|)
name|struct
name|acp_softc
modifier|*
name|ds
decl_stmt|;
name|u_char
name|response
decl_stmt|;
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|u_char
modifier|*
name|bp
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
comment|/* try to get init buffer */
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d: couldn't get init buffer\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* put response in CIM cmd field */
name|response_msg
index|[
name|CMD_OFFSET
index|]
operator|=
name|response
expr_stmt|;
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
name|bcopy
argument_list|(
name|response_msg
argument_list|,
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|response_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* put msg in mbuf */
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|6
condition|)
block|{
name|printf
argument_list|(
literal|"acp_response():  "
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
name|bp
argument_list|,
sizeof|sizeof
argument_list|(
name|response_msg
argument_list|)
argument_list|)
expr_stmt|;
comment|/* print messge  */
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
name|m
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
name|response_msg
argument_list|)
expr_stmt|;
comment|/* set msg length */
name|IF_ENQUEUE
argument_list|(
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_SUPR
index|]
operator|.
name|dc_oq
operator|)
argument_list|,
name|m
argument_list|)
expr_stmt|;
comment|/* output queue   */
name|acp_start
argument_list|(
name|ds
argument_list|,
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|ACP_SUPR
index|]
operator|)
argument_list|)
expr_stmt|;
comment|/* start ouput of data  */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      ACP_SUPR()                             %%*/
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
comment|/*  Call:              acp_supr(ds, hc, cc, rcnt, channel)         */
end_comment

begin_comment
comment|/*  Argument:          ds:   pointer to dev control block struct   */
end_comment

begin_comment
comment|/*                     hc:   pointer to the Half Duplex cntrl      */
end_comment

begin_comment
comment|/*                                 block structure                 */
end_comment

begin_comment
comment|/*                     cc:   Mailbox I/O completion status         */
end_comment

begin_comment
comment|/*                     rcnt:  byte count, length of data           */
end_comment

begin_comment
comment|/*                     channel:  indicates ACP_ALLOC or ACP_SUPR   */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         acpinta()                                   */
end_comment

begin_comment
comment|/*  Calls to:          m_freem()                                   */
end_comment

begin_comment
comment|/*                     acp_start()                                 */
end_comment

begin_comment
comment|/*                     supr_msg()                                  */
end_comment

begin_comment
comment|/*                     acp_ioreq()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|acp_supr
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|cc
parameter_list|,
name|rcnt
parameter_list|,
name|chan
parameter_list|)
specifier|register
name|struct
name|acp_softc
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
name|rcnt
decl_stmt|,
name|chan
decl_stmt|;
block|{
specifier|register
name|struct
name|acp_cb
modifier|*
name|dc
init|=
operator|&
operator|(
name|ds
operator|->
name|acp_cb
index|[
name|chan
index|]
operator|)
decl_stmt|;
specifier|register
name|u_char
modifier|*
name|p
decl_stmt|;
comment|/* was it read or write? */
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|0x01
condition|)
block|{
if|if
condition|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
condition|)
block|{
name|m_freem
argument_list|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_xtofree
operator|=
literal|0
expr_stmt|;
block|}
name|dc
operator|->
name|dc_flags
operator|&=
operator|~
name|DC_OBUSY
expr_stmt|;
name|acp_start
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|ACPDEBUG
if|if
condition|(
name|acp_debug
operator|>
literal|3
condition|)
block|{
name|printf
argument_list|(
literal|"acp: acp_supr(), read completed, cc = %d, cnt = %d\n"
argument_list|,
name|cc
argument_list|,
name|rcnt
argument_list|)
expr_stmt|;
name|prt_bytes
argument_list|(
operator|(
name|u_char
operator|*
operator|)
operator|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_addr
operator|)
argument_list|,
name|rcnt
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|ACPDEBUG
if|if
condition|(
name|cc
operator|==
name|ACPIOCOK
condition|)
block|{
name|p
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|(
name|dc
operator|->
name|dc_ifuba
operator|.
name|ifu_r
operator|.
name|ifrw_addr
operator|)
expr_stmt|;
comment|/* process supervisor message */
name|supr_msg
argument_list|(
name|ds
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
comment|/* hang a new supr read */
name|acp_iorq
argument_list|(
name|ds
argument_list|,
name|dc
argument_list|,
name|ACPMTU
argument_list|,
name|ACPRED
operator|+
name|ACPSTR
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

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
comment|/*       taken.  Note that the RSF field is checked for responses. */
end_comment

begin_comment
comment|/*       The RSF field is 4 bytes long, but ony that least         */
end_comment

begin_comment
comment|/*       significant byte is used.                                 */
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
comment|/*  Called by:         acp_supr()                                  */
end_comment

begin_comment
comment|/*  Calls to:          printf()                                    */
end_comment

begin_comment
comment|/*                     IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                     acp_response()                              */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|supr_msg
parameter_list|(
name|ds
parameter_list|,
name|p
parameter_list|)
name|struct
name|acp_softc
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
name|acp_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
switch|switch
condition|(
name|p
index|[
literal|3
index|]
condition|)
block|{
case|case
name|RSP_ALLOC
case|:
comment|/*  alloc response   */
if|if
condition|(
name|p
index|[
name|RSF_OFFSET
index|]
condition|)
comment|/* check if RSF is 0 for success */
block|{
name|printf
argument_list|(
literal|"acp%d:  attempt to allocate path failed "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"rsf field = %x\n"
argument_list|,
name|p
index|[
name|RSF_OFFSET
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
if|if
condition|(
name|p
index|[
name|CID_OFFSET
index|]
operator|>=
name|ACP_SUPR
operator|&&
name|p
index|[
name|CID_OFFSET
index|]
operator|<=
name|ACP_DATA
condition|)
name|ds
operator|->
name|acp_path
operator||=
name|p
index|[
name|CID_OFFSET
index|]
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"acp%d:  path allocation "
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"response contains invalid DPN = %d\n"
argument_list|,
name|p
index|[
name|CID_OFFSET
index|]
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|RSP_DEALLOC
case|:
comment|/*  dealloc response */
if|if
condition|(
name|p
index|[
name|RSF_OFFSET
index|]
condition|)
comment|/* check if RSF is 0 for success */
block|{
name|printf
argument_list|(
literal|"acp%d:  attempt to deallocate path failed "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"rsf field = %x\n"
argument_list|,
name|p
index|[
name|RSF_OFFSET
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|RSP_SSP
case|:
comment|/*  set sys parm rsp */
if|if
condition|(
name|p
index|[
name|RSF_OFFSET
index|]
condition|)
comment|/* check if RSF is 0 for success */
block|{
name|printf
argument_list|(
literal|"acp%d:  attempt to set HDLC system parameters failed\n"
argument_list|)
expr_stmt|;
return|return;
block|}
break|break;
case|case
name|CMD_FLUP
case|:
comment|/*   frame level up  */
comment|/* check that the data path was successfully allocated, we */
comment|/* know that the control path was successfully allocated   */
comment|/* otherwise the FLUP command would not have been issued   */
if|if
condition|(
operator|(
name|ds
operator|->
name|acp_path
operator|&
name|ACP_DATA
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acp%d:  data path was not successfully allocated\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
block|}
name|ds
operator|->
name|acp_if
operator|.
name|if_flags
operator||=
name|IFF_UP
expr_stmt|;
name|printf
argument_list|(
literal|"acp%d:  frame level up\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
name|acp_response
argument_list|(
name|ds
argument_list|,
name|RSP_FLUP
argument_list|)
expr_stmt|;
comment|/* send response to front end */
break|break;
case|case
name|CMD_FLDWN
case|:
comment|/* frame level down  */
name|ds
operator|->
name|acp_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
name|dc
operator|=
name|ds
operator|->
name|acp_cb
expr_stmt|;
for|for
control|(
name|lcn
operator|=
name|ACP_ALLOC
init|;
name|lcn
operator|<=
name|NACPCH
condition|;
name|lcn
operator|++
control|)
comment|/* for all LCN's */
block|{
while|while
condition|(
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
condition|)
comment|/* drop pending data */
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
name|dc
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"acp%d:  frame level down\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
name|acp_response
argument_list|(
name|ds
argument_list|,
name|RSP_FLDWN
argument_list|)
expr_stmt|;
comment|/* send response to front end */
break|break;
default|default:
name|printf
argument_list|(
literal|"acp%d: supervisor error, code=%x\n"
argument_list|,
name|ds
operator|->
name|acp_if
operator|.
name|if_unit
argument_list|,
name|p
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|ACPDEBUG
end_ifdef

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                            PRT_ADDR()                             %%*/
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
comment|/*	This routine is used to print internet addresses in the		 */
end_comment

begin_comment
comment|/*	standard A.B.C.D format.  Note that this routine is for          */
end_comment

begin_comment
comment|/*	debugging purposes (ifdef ACPDEBUG).                             */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Call:  		prt_addr(addr)                                   */
end_comment

begin_comment
comment|/*  Argument:      	addr:  internet address structure                */
end_comment

begin_comment
comment|/*  Returns:  		nothing                                          */
end_comment

begin_comment
comment|/*  Called by:  	acpoutput()                                      */
end_comment

begin_comment
comment|/*  Calls to:   	printf()                                         */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|prt_addr
parameter_list|(
name|addr
parameter_list|)
name|struct
name|in_addr
name|addr
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|FOURTWO
union|union
block|{
name|struct
name|in_addr
name|ip
decl_stmt|;
struct|struct
block|{
comment|/* (assume Class A network number) */
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
name|imp_addr
union|;
name|imp_addr
operator|.
name|ip
operator|=
name|addr
expr_stmt|;
name|printf
argument_list|(
literal|"%d.%d.%d.%d"
argument_list|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_net
argument_list|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_host
argument_list|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_lh
argument_list|,
name|imp_addr
operator|.
name|imp
operator|.
name|s_impno
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%d.%d.%d.%d"
argument_list|,
name|addr
operator|.
name|s_net
argument_list|,
name|addr
operator|.
name|s_host
argument_list|,
name|addr
operator|.
name|s_lh
argument_list|,
name|addr
operator|.
name|s_impno
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

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
comment|/*	This routine is used to print a string of bytes in hex.		 */
end_comment

begin_comment
comment|/*	Note that this routine is for debugging purposes (ifdef          */
end_comment

begin_comment
comment|/*	ACPDEBUG).                                                       */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Call:  		prt_bytes(bp, cnt)                               */
end_comment

begin_comment
comment|/*  Argument:      	bp:  pointer to the string                       */
end_comment

begin_comment
comment|/*                 	cnt: number of bytes                             */
end_comment

begin_comment
comment|/*  Returns:  		nothing                                          */
end_comment

begin_comment
comment|/*  Called by:  	acp_data()                                       */
end_comment

begin_comment
comment|/*              	acp_supr()                                       */
end_comment

begin_comment
comment|/*              	supr_msg()                                       */
end_comment

begin_comment
comment|/*  Calls to:   	printf()                                         */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
specifier|static
name|void
name|prt_bytes
parameter_list|(
name|bp
parameter_list|,
name|cnt
parameter_list|)
name|u_char
modifier|*
name|bp
decl_stmt|;
name|int
name|cnt
decl_stmt|;
block|{
while|while
condition|(
name|cnt
operator|--
condition|)
block|{
name|printf
argument_list|(
literal|" %x"
argument_list|,
operator|*
name|bp
operator|++
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
endif|ACPDEBUG
end_endif

begin_endif
endif|#
directive|endif
endif|NACP
end_endif

end_unit

