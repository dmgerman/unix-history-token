begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	acpconfig.c		V2.2 		30 June 1987             */
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
comment|/*  	Copyright (c) 1986 by Advanced Computer Communications           */
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
comment|/*  File:		acpconfig.c                                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Author:		Clare E. Russ                                    */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		Installation verification program for ACC        */
end_comment

begin_comment
comment|/*			ACP 5100/6100 and ACP 5250/6250 network          */
end_comment

begin_comment
comment|/* 			interface drivers.   Acpconfig provides a user   */
end_comment

begin_comment
comment|/*			interface which supports the configuration of a  */
end_comment

begin_comment
comment|/*			network  interface.                              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Function:                                                            */
end_comment

begin_comment
comment|/*        Based on socket ioctls, provide user interface to Network      */
end_comment

begin_comment
comment|/*        Interface Drivers for the following ACC ACP devices:           */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                  ACP 5100/6100  'acp' interface                       */
end_comment

begin_comment
comment|/*                  ACP 5250/6250  'dda' interface                       */
end_comment

begin_comment
comment|/*                  ACP 625        'ddn' interface                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*        The ioctl indicates what type of message is to be sent to the  */
end_comment

begin_comment
comment|/*        front end device (ie, bring up the HDLC line in external       */
end_comment

begin_comment
comment|/*        loopback mode).                                                */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Components:		acpconfig.c, ioctl.h                             */
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
comment|/* 16-SEP-1985  Clare Russ:     first generated, cut and paste from      */
end_comment

begin_comment
comment|/*                              ifconfig.c                               */
end_comment

begin_comment
comment|/* 20-OCT-1985  Clare Russ:     modify for compatibility with TWG        */
end_comment

begin_comment
comment|/*                              software                                 */
end_comment

begin_comment
comment|/* 28-APR-1986  Clare Russ:     BETA RELEASE V1.2 (version number tracks */
end_comment

begin_comment
comment|/*                              ACC Software Library entry)              */
end_comment

begin_comment
comment|/*                              next version:  condense code in main(),  */
end_comment

begin_comment
comment|/*                              create acpconfig.h for includes and defs */
end_comment

begin_comment
comment|/* 14-MAY-1986  Clare Russ:     BETA RELEASE V1.3 (version number tracks */
end_comment

begin_comment
comment|/*                              ACC Software Library entry)              */
end_comment

begin_comment
comment|/*                              fix error in baud rate logic             */
end_comment

begin_comment
comment|/* 30-MAY-1986  Randy Graves    BETA RELEASE V1.4 (version number tracks */
end_comment

begin_comment
comment|/*                              ACC Software Library entry) make         */
end_comment

begin_comment
comment|/*                              changes to support Public Data Networks  */
end_comment

begin_comment
comment|/* 11-JUL-1986  Clare Russ:     BETA RELEASE V0.5 (version number tracks */
end_comment

begin_comment
comment|/*                              ACC Software Library entry) make         */
end_comment

begin_comment
comment|/*                              changes to support Public Data Networks  */
end_comment

begin_comment
comment|/*                              in_addr differences reconciled           */
end_comment

begin_comment
comment|/* 06-AUG-1986  Clare Russ:     V2.0 (version number tracks ACC Software */
end_comment

begin_comment
comment|/*                              Library entry) modify for compatibility  */
end_comment

begin_comment
comment|/*                              with ULTRIX-32(m) V1.2                   */
end_comment

begin_comment
comment|/* 10-SEP-1986  Clare Russ:     V2.1 (version number tracks ACC Software */
end_comment

begin_comment
comment|/*                              Library entry) add ability to reset the  */
end_comment

begin_comment
comment|/*                              front end.                               */
end_comment

begin_comment
comment|/* 18-FEB-1987  Jeff Berkowitz  V2.2 Add ability to pass baud rate	 */
end_comment

begin_comment
comment|/*				divisor to FEP.  New ioctl to query	 */
end_comment

begin_comment
comment|/*				service mode.  Add interface to		 */
end_comment

begin_comment
comment|/*				statistics query message.  Add general	 */
end_comment

begin_comment
comment|/*				configuration interface from user space. */
end_comment

begin_comment
comment|/*				Fix white space syntax on -b to allow	 */
end_comment

begin_comment
comment|/*				-b 9600.  Use acpconfig for debug/log	 */
end_comment

begin_comment
comment|/*				message control.  Add ioctl to configure */
end_comment

begin_comment
comment|/*				the number of LCNs.			 */
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
comment|/*      acpconfig interface [address] [-A filename] [-a ipaddr x25addr]  */
end_comment

begin_comment
comment|/*		  [-b baud] [-d ipaddr] [-m message] 			 */
end_comment

begin_comment
comment|/*		  [-n #_lcns] [-q type] [-r count] [-s X.25_service]	 */
end_comment

begin_comment
comment|/*		  [-u mode] [-v variable value] [-z]			 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -A filename                                                   */
end_comment

begin_comment
comment|/*              Add the contents of the named file to the address        */
end_comment

begin_comment
comment|/*              translation table for PDN service                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -a ipaddr x25addr                                             */
end_comment

begin_comment
comment|/*              Add the specified address pair to the address            */
end_comment

begin_comment
comment|/*              translation table for PDN service                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -b baud                                                       */
end_comment

begin_comment
comment|/*              Note that the baud rate values are different for the     */
end_comment

begin_comment
comment|/*              ACP 625.  Table 1 contains the baud rates which apply    */
end_comment

begin_comment
comment|/*              to the ACP 6100, ACP 5250/6250 products.  Table 2        */
end_comment

begin_comment
comment|/*              contains the baud rates which apply to the ACP 625.      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	  Table 1:  Nominal baud rates for ACP 5100/6100, ACP 5250/6250  */
end_comment

begin_comment
comment|/*  			                                                 */
end_comment

begin_comment
comment|/*  			2.00M  2000K  2.0M  1.33M  1333K  1.3M           */
end_comment

begin_comment
comment|/*  			1.00M  1000K  1.0M  500K   250K   100K           */
end_comment

begin_comment
comment|/*  			64K    64000  56K   56000  30K    19.2K          */
end_comment

begin_comment
comment|/*  			9.6K   9600   4.8K  4800   2.4K   2400           */
end_comment

begin_comment
comment|/*  			1.2K   1200                                      */
end_comment

begin_comment
comment|/*  			                                                 */
end_comment

begin_comment
comment|/*  	  Table 2:  Nominal baud rates for ACP 625		         */
end_comment

begin_comment
comment|/*  			                                                 */
end_comment

begin_comment
comment|/*  			316000  153600   115200   76800   76.8K          */
end_comment

begin_comment
comment|/*			 57600   57.6K    38400   38.4K   28800          */
end_comment

begin_comment
comment|/*			 28.8K   19200    19.2K    9600    9.6K          */
end_comment

begin_comment
comment|/*			  4800    4.8K     2400    2.4K    2150          */
end_comment

begin_comment
comment|/*			  1760    1200                                   */
end_comment

begin_comment
comment|/*  			                                                 */
end_comment

begin_comment
comment|/*  	        The M for megabits/second and K for kilobits/second      */
end_comment

begin_comment
comment|/*  	        are optional.  Note that Table 1 allows for the entry    */
end_comment

begin_comment
comment|/*  	        of 9.6 (with the assumed unit of Kilobits/second), but   */
end_comment

begin_comment
comment|/*              also allows for the entry of 9600 (bits/second).  Thus   */
end_comment

begin_comment
comment|/*              there is more than one entry for some of the baud rate   */
end_comment

begin_comment
comment|/*		values.                                                  */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -d ipaddr                                                     */
end_comment

begin_comment
comment|/*              Delete the specified address entry from the address      */
end_comment

begin_comment
comment|/*              translation table for PDN service                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	   -m message							 */
end_comment

begin_comment
comment|/*		Pass ``message'' to the FEP as a supervisory channel	 */
end_comment

begin_comment
comment|/*		message.  Message is a sequence of numbers separated	 */
end_comment

begin_comment
comment|/*		by white space.  Numbers with leading ``0'' are taken	 */
end_comment

begin_comment
comment|/*		as octal, other numbers taken as HEX, decimal is not	 */
end_comment

begin_comment
comment|/*		supported.  Hex and octal may be intermixed, as in	 */
end_comment

begin_comment
comment|/*		``0140 0 0 2 89 017''.  The message is terminated by the */
end_comment

begin_comment
comment|/*		end of the argument list or by an argument beginning	 */
end_comment

begin_comment
comment|/*		with a dash ``-''.  Absolutely no checking is performed; */
end_comment

begin_comment
comment|/*		the bytes are written to the FEP as a supervisor	 */
end_comment

begin_comment
comment|/*		message.  The message is limited to MLEN = 112 bytes.    */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -n #_lcns							 */
end_comment

begin_comment
comment|/*		Set the number of logical channels to ``#_lcns'', which  */
end_comment

begin_comment
comment|/*		must be less than some implementation defined maximum.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -q query-type						 */
end_comment

begin_comment
comment|/*		Query the board or driver and place results on stdout.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -q 0	 Statistics query to FEP				 */
end_comment

begin_comment
comment|/*	   -q 1	 Driver operating mode query				 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -r count                                                      */
end_comment

begin_comment
comment|/*              Read the specified number of entries from the address    */
end_comment

begin_comment
comment|/*              translation table for PDN service                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -r 0  read all entries from the address translation table     */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -s X.25 service                                               */
end_comment

begin_comment
comment|/*              Select DDN standard X.25 service or basic X.25 service   */
end_comment

begin_comment
comment|/*              or Public Data Network X.25 service                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -s 0  select standard X.25 service                            */
end_comment

begin_comment
comment|/*         -s 1  select basic X.25 service                               */
end_comment

begin_comment
comment|/*         -s 2  select X.25 Public Data Network service                 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -u mode                                                       */
end_comment

begin_comment
comment|/*              Bring the link up or down.                               */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*         -u 0  bring down the link                                     */
end_comment

begin_comment
comment|/*         -u 1  bring up link for normal operation, no loopback, DTE    */
end_comment

begin_comment
comment|/*         -u 2  bring up link for normal operation, no loopback, DCE    */
end_comment

begin_comment
comment|/*         -u 3  bring up the link in external loopback mode             */
end_comment

begin_comment
comment|/*         -u 4  bring up the link in internal loopback mode             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	   -v variable value						 */
end_comment

begin_comment
comment|/*		Set the value of a driver variable symbolized by	 */
end_comment

begin_comment
comment|/*		"variable" to "value" decimal.  "Variables" understood   */
end_comment

begin_comment
comment|/* 		are "log", "debug", "window" and "packet" to set the	 */
end_comment

begin_comment
comment|/* 		driver's notion of logging, debug flags, negotiable	 */
end_comment

begin_comment
comment|/*		window size, and negotiable packet size.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*         -z  reset the specifed front-end device                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Compile Notes:                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*      The associated makefile builds the acpconfig executable image    */
end_comment

begin_comment
comment|/*      for UNIX 4.2BSD or the specified emulation/simulation such as    */
end_comment

begin_comment
comment|/*      The Wollongong Group (TWG) software which runs under VAX/VMS.    */
end_comment

begin_comment
comment|/*      The makefile must be invoked with the argument which specifies   */
end_comment

begin_comment
comment|/*      the target host operating system, otherwise the makefile         */
end_comment

begin_comment
comment|/*      defaults to creating an executable image for UNIX 4.2BSD.        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                make                 (compile for UNIX 4.2BSD)         */
end_comment

begin_comment
comment|/*                make sysbsd          (compile for UNIX 4.2BSD)         */
end_comment

begin_comment
comment|/*                make systwg          (compile for TWG under VAX/VMS)   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                make clean                                             */
end_comment

begin_comment
comment|/*                make print                                             */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  System Notes:                                                        */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*      Create a socket of the AF_INET address family and of type        */
end_comment

begin_comment
comment|/*      datagram, SOCK_DGRAM.  Use the socket to send a socket ioctl     */
end_comment

begin_comment
comment|/*      to the network driver of the specified interface ('acp0' in      */
end_comment

begin_comment
comment|/*      the usage notes).   Depending on the type of message specified   */
end_comment

begin_comment
comment|/*      in the command line, send the appropriate socket ioctl to        */
end_comment

begin_comment
comment|/*      specify what kind of action is to be taken.                      */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*      For those drivers which support the Control Interface (CIF)      */
end_comment

begin_comment
comment|/*      the message exchange conforms to the CIF which defines paired    */
end_comment

begin_comment
comment|/*      command/response Control Interface Messages (CIMs) between the   */
end_comment

begin_comment
comment|/*      host and the front end.   Otherwise, the exchange of messages    */
end_comment

begin_comment
comment|/*      is the pre-CIF protocol (i.e., that used  by the ddn interface). */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	Assignment of subcodes for the SIOCACPCONFIG ioctl:		 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*	1..14		-bRATE for RATE != 0				 */
end_comment

begin_comment
comment|/*	`0'..`4'	-u N (line control)				 */
end_comment

begin_comment
comment|/*	`a'		-A and -a commands (PDN)			 */
end_comment

begin_comment
comment|/*	`b'		-b0 (set external clock)			 */
end_comment

begin_comment
comment|/*	`d'		-d command (PDN)				 */
end_comment

begin_comment
comment|/*	`m'		-m (message command)				 */
end_comment

begin_comment
comment|/*	`n'		-n #_lcns (limit lcns)				 */
end_comment

begin_comment
comment|/*	`p'		-q 0 (statistics query)				 */
end_comment

begin_comment
comment|/*	`q'		-q 1 (driver query)				 */
end_comment

begin_comment
comment|/*	`r'		-r command (PDN)				 */
end_comment

begin_comment
comment|/*	`s'		-s 0						 */
end_comment

begin_comment
comment|/*	`t'		-s 1						 */
end_comment

begin_comment
comment|/*	`u'		-s 2						 */
end_comment

begin_comment
comment|/*	`v'		-v command (set variable)		 	 */
end_comment

begin_comment
comment|/*	`z'		-z command (reset)				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                                                                %%*/
end_comment

begin_comment
comment|/*%%               INCLUDE FILES                                    %%*/
end_comment

begin_comment
comment|/*%%                                                                %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*   There are alternate path names for The Wollongong Group (TWG)    */
end_comment

begin_comment
comment|/*   IPTCP and Eunice software which runs under VMS                   */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TWG
end_ifdef

begin_include
include|#
directive|include
file|</sys/twgtcp/kernel/h/ioctl.h>
end_include

begin_include
include|#
directive|include
file|</sys/twgtcp/kernel/netinet/in.h>
end_include

begin_include
include|#
directive|include
file|</sys/twgtcp/kernel/net/if.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
endif|TWG
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/* 'iface' interface definitions */
end_comment

begin_define
define|#
directive|define
name|ACP_INTERFACE
value|0x01
end_define

begin_comment
comment|/* for acp interface */
end_comment

begin_define
define|#
directive|define
name|DDN_INTERFACE
value|0x02
end_define

begin_comment
comment|/* for ddn interface */
end_comment

begin_define
define|#
directive|define
name|BAUD_VAL
value|50
end_define

begin_comment
comment|/* for baud rate flag, -b */
end_comment

begin_define
define|#
directive|define
name|SERVICE_VAL
value|67
end_define

begin_comment
comment|/* for X.25 service flag, -s */
end_comment

begin_comment
comment|/* Change these for PDN X.25 Addresses of other formats.  E.g., for no */
end_comment

begin_comment
comment|/* restriction change PDNX25AMIN to 1 and PDNBADDNIC to "Z" */
end_comment

begin_define
define|#
directive|define
name|PDNX25AMIN
value|12
end_define

begin_comment
comment|/* Minimum X.25 address length */
end_comment

begin_define
define|#
directive|define
name|PDNBADDNIC
value|"0000"
end_define

begin_comment
comment|/* X.25 addr prefix to EXCLUDE */
end_comment

begin_comment
comment|/* delay macro from /sys/vax/param.h */
end_comment

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_escape
end_escape

begin_comment
comment|/* The baud_rate structure maps the user-supplied baud rate into the */
end_comment

begin_comment
comment|/* parameter used in the socket ioctl to the driver.  In some cases, */
end_comment

begin_comment
comment|/* more than one representation of a value is present to ease the    */
end_comment

begin_comment
comment|/* interface.  The manual page for acpconfig recommends that the     */
end_comment

begin_comment
comment|/* user give the baud rate with the assumed unit of Kilobits/second. */
end_comment

begin_struct
struct|struct
name|baud
block|{
name|char
modifier|*
name|b_rate
decl_stmt|;
name|char
name|parameter
decl_stmt|;
block|}
name|baud_rate
index|[]
init|=
block|{
block|{
literal|"2.00"
block|,
literal|1
block|}
block|,
comment|/* these are nominal baud rates */
block|{
literal|"2.00M"
block|,
literal|1
block|}
block|,
block|{
literal|"2000K"
block|,
literal|1
block|}
block|,
block|{
literal|"2000k"
block|,
literal|1
block|}
block|,
block|{
literal|"2.0"
block|,
literal|1
block|}
block|,
block|{
literal|"2.0M"
block|,
literal|1
block|}
block|,
block|{
literal|"1.33"
block|,
literal|2
block|}
block|,
block|{
literal|"1.33M"
block|,
literal|2
block|}
block|,
block|{
literal|"1333K"
block|,
literal|2
block|}
block|,
block|{
literal|"1333k"
block|,
literal|2
block|}
block|,
block|{
literal|"1.3"
block|,
literal|2
block|}
block|,
block|{
literal|"1.3M"
block|,
literal|2
block|}
block|,
block|{
literal|"1.00"
block|,
literal|3
block|}
block|,
block|{
literal|"1.00M"
block|,
literal|3
block|}
block|,
block|{
literal|"1000K"
block|,
literal|3
block|}
block|,
block|{
literal|"1000k"
block|,
literal|3
block|}
block|,
block|{
literal|"1.0M"
block|,
literal|3
block|}
block|,
block|{
literal|"1.0"
block|,
literal|3
block|}
block|,
block|{
literal|"500"
block|,
literal|4
block|}
block|,
block|{
literal|"500K"
block|,
literal|4
block|}
block|,
block|{
literal|"500k"
block|,
literal|4
block|}
block|,
block|{
literal|"250"
block|,
literal|5
block|}
block|,
block|{
literal|"250K"
block|,
literal|5
block|}
block|,
block|{
literal|"250k"
block|,
literal|5
block|}
block|,
block|{
literal|"100"
block|,
literal|6
block|}
block|,
block|{
literal|"100K"
block|,
literal|6
block|}
block|,
block|{
literal|"100k"
block|,
literal|6
block|}
block|,
block|{
literal|"64"
block|,
literal|7
block|}
block|,
block|{
literal|"64K"
block|,
literal|7
block|}
block|,
block|{
literal|"64k"
block|,
literal|7
block|}
block|,
block|{
literal|"64000"
block|,
literal|7
block|}
block|,
block|{
literal|"56"
block|,
literal|8
block|}
block|,
block|{
literal|"56K"
block|,
literal|8
block|}
block|,
block|{
literal|"56k"
block|,
literal|8
block|}
block|,
block|{
literal|"56000"
block|,
literal|8
block|}
block|,
block|{
literal|"30"
block|,
literal|9
block|}
block|,
block|{
literal|"30K"
block|,
literal|9
block|}
block|,
block|{
literal|"30k"
block|,
literal|9
block|}
block|,
block|{
literal|"19.2"
block|,
literal|10
block|}
block|,
block|{
literal|"19.2K"
block|,
literal|10
block|}
block|,
block|{
literal|"19.2k"
block|,
literal|10
block|}
block|,
block|{
literal|"9.6"
block|,
literal|11
block|}
block|,
block|{
literal|"9.6K"
block|,
literal|11
block|}
block|,
block|{
literal|"9.6k"
block|,
literal|11
block|}
block|,
block|{
literal|"9600"
block|,
literal|11
block|}
block|,
block|{
literal|"4.8"
block|,
literal|12
block|}
block|,
block|{
literal|"4.8K"
block|,
literal|12
block|}
block|,
block|{
literal|"4.8k"
block|,
literal|12
block|}
block|,
block|{
literal|"4800"
block|,
literal|12
block|}
block|,
block|{
literal|"2.4"
block|,
literal|13
block|}
block|,
block|{
literal|"2.4K"
block|,
literal|13
block|}
block|,
block|{
literal|"2.4k"
block|,
literal|13
block|}
block|,
block|{
literal|"2400"
block|,
literal|13
block|}
block|,
block|{
literal|"1.2"
block|,
literal|14
block|}
block|,
block|{
literal|"1.2K"
block|,
literal|14
block|}
block|,
block|{
literal|"1.2k"
block|,
literal|14
block|}
block|,
block|{
literal|"1200"
block|,
literal|14
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|, }
struct|;
end_struct

begin_comment
comment|/* Table of baud rate values and the associated parameter for the Set   */
end_comment

begin_comment
comment|/* System Parameters message, ddninit_msg.  The 'parameter1' is nonzero */
end_comment

begin_comment
comment|/* for valid baud rate divisors.  The user's manual gives both the      */
end_comment

begin_comment
comment|/* actual and nominal baud rates, either one is accepted from the user, */
end_comment

begin_comment
comment|/* but the nominal baud rate is the figure which is closest to the rate */
end_comment

begin_comment
comment|/* set on the front end.                                                */
end_comment

begin_decl_stmt
name|struct
name|baud
name|ddnbaud_rate
index|[]
init|=
block|{
block|{
literal|"333333"
block|,
literal|1
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"316000"
block|,
literal|1
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"153846"
block|,
literal|2
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"153600"
block|,
literal|2
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"114285"
block|,
literal|3
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"115200"
block|,
literal|3
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"76923"
block|,
literal|4
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"76800"
block|,
literal|4
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"76.8K"
block|,
literal|4
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"76.8k"
block|,
literal|4
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"57971"
block|,
literal|5
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"57600"
block|,
literal|5
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"57.6K"
block|,
literal|5
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"57.6k"
block|,
literal|5
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"38461"
block|,
literal|6
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"38400"
block|,
literal|6
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"38.4K"
block|,
literal|6
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"38.4k"
block|,
literal|6
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"28776"
block|,
literal|7
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"28800"
block|,
literal|7
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"28.8K"
block|,
literal|7
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"28.8k"
block|,
literal|7
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"19230"
block|,
literal|8
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"19200"
block|,
literal|8
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"19.2K"
block|,
literal|8
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"19.2k"
block|,
literal|8
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"9592"
block|,
literal|9
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"9600"
block|,
literal|9
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"9.6K"
block|,
literal|9
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"9.6k"
block|,
literal|9
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"4801"
block|,
literal|10
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"4800"
block|,
literal|10
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"4.8K"
block|,
literal|10
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"4.8k"
block|,
literal|10
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"2400"
block|,
literal|11
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"2.4K"
block|,
literal|11
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"2.4k"
block|,
literal|11
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"2150"
block|,
literal|12
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"1760"
block|,
literal|13
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"1760"
block|,
literal|13
block|}
block|,
comment|/* actual baud rate  */
block|{
literal|"1200"
block|,
literal|14
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"1.2K"
block|,
literal|14
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|"1.2k"
block|,
literal|14
block|}
block|,
comment|/* nominal baud rate */
block|{
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                         MAIN()                                 %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Purpose:                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*      For the specified interface, create a socket for a socket     */
end_comment

begin_comment
comment|/*      ioctl to set the Internet address and configuration.  The     */
end_comment

begin_comment
comment|/*      ioctl kicks the appropriate driver, the value in ifr_data     */
end_comment

begin_comment
comment|/*      indicates the type of action to be taken.  ('b' indicates     */
end_comment

begin_comment
comment|/*      external clock, 1-14 indicates baud rate from the table of    */
end_comment

begin_comment
comment|/*      possible values, '0' - '4' indicates -u options, and 's','t', */
end_comment

begin_comment
comment|/*      'u' indicate -s options.)                                     */
end_comment

begin_comment
comment|/*      Enhancement: 'a' indicates addition of an address table       */
end_comment

begin_comment
comment|/*      entry, 'd' indicates deletion of an address table entry,      */
end_comment

begin_comment
comment|/*      and 'r' is a request to read address table entries.           */
end_comment

begin_comment
comment|/*	Etc, etc (see comment at top for complete list)		      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Call:               main( argc, argv)                             */
end_comment

begin_comment
comment|/*  Arguments:          argc:   argument count                        */
end_comment

begin_comment
comment|/*                      argv:   argument value                        */
end_comment

begin_comment
comment|/*  Returns:            nothing                                       */
end_comment

begin_comment
comment|/*  Called by:          invoked by privileged user                    */
end_comment

begin_comment
comment|/*  Calls to:           socket()                                      */
end_comment

begin_comment
comment|/*                      perror()                                      */
end_comment

begin_comment
comment|/*                      strcpy()                                      */
end_comment

begin_comment
comment|/*                      strncpy()                                     */
end_comment

begin_comment
comment|/*                      sizeof()                                      */
end_comment

begin_comment
comment|/*                      usage()                                       */
end_comment

begin_comment
comment|/*                      ioctl()                                       */
end_comment

begin_comment
comment|/*                      exit()                                        */
end_comment

begin_comment
comment|/*                      Perror()                                      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
name|struct
name|ifreq
name|ifr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|sin
init|=
block|{
name|AF_INET
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|name
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket descriptor */
end_comment

begin_struct
struct|struct
name|ddactl
block|{
comment|/* used by various ioctls */
name|u_char
name|func
decl_stmt|;
comment|/* must be first */
name|u_char
name|nothing
index|[
literal|3
index|]
decl_stmt|;
comment|/* alignment */
name|int
name|drval
decl_stmt|;
comment|/* used by -v, etc */
name|char
name|msg
index|[
literal|112
index|]
decl_stmt|;
comment|/* used by -m, -q: XXX 112 should be "MLEN" */
block|}
name|ddactl
struct|;
end_struct

begin_struct
struct|struct
name|trtab
block|{
comment|/* Address Translation Table Entry */
name|u_char
name|func
decl_stmt|;
name|u_char
name|x25addr
index|[
literal|15
index|]
decl_stmt|;
name|u_long
name|ipaddr
decl_stmt|;
block|}
name|trtab
struct|;
end_struct

begin_struct
struct|struct
name|lg2tab
block|{
comment|/* For use with packet sizes, so just the */
name|int
name|base2log
decl_stmt|;
comment|/* legal packet sizes for X.25 are here */
name|int
name|binval
decl_stmt|;
block|}
name|lg2tab
index|[]
init|=
block|{
literal|4
block|,
literal|16
block|,
literal|5
block|,
literal|32
block|,
literal|6
block|,
literal|64
block|,
literal|7
block|,
literal|128
block|,
literal|8
block|,
literal|256
block|,
literal|9
block|,
literal|512
block|,
literal|10
block|,
literal|1024
block|,
literal|11
block|,
literal|2048
block|,
literal|12
block|,
literal|4096
block|,
literal|0
block|,
literal|0
block|, }
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|struct
name|baud
modifier|*
name|p
decl_stmt|;
comment|/* baud rates */
name|int
name|iface
init|=
literal|0
decl_stmt|;
comment|/* indicate interface, i.e. acp */
name|int
name|tmp
decl_stmt|,
name|top
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
name|line
index|[
literal|80
index|]
decl_stmt|,
name|arg1
index|[
literal|40
index|]
decl_stmt|,
name|arg2
index|[
literal|40
index|]
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n acpconfig:  invalid number of arguments\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
block|}
name|s
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* try create socket */
if|if
condition|(
name|s
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"acpconfig: socket"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
comment|/* interface name */
name|strcpy
argument_list|(
name|name
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|==
literal|'n'
condition|)
comment|/* check for 'ddn' interface */
name|iface
operator||=
name|DDN_INTERFACE
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'a'
condition|)
comment|/* check for 'acp' interface */
name|iface
operator||=
name|ACP_INTERFACE
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCGIFFLAGS
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCGIFFLAGS)"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
block|{
name|argv
operator|++
expr_stmt|;
if|if
condition|(
operator|*
operator|*
name|argv
operator|!=
literal|'-'
condition|)
name|setifaddr
argument_list|(
operator|*
name|argv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* set interface address */
else|else
block|{
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
condition|)
block|{
comment|/* process flag(s) */
case|case
literal|'b'
case|:
comment|/* set baud rate or ext clocking */
block|{
comment|/* accept -bN or -b N for any N */
name|char
modifier|*
name|ap
init|=
operator|*
name|argv
decl_stmt|;
if|if
condition|(
name|ap
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
block|{
comment|/* -b N case */
name|argc
operator|--
operator|,
name|argv
operator|++
operator|,
name|ap
operator|=
operator|*
name|argv
expr_stmt|;
if|if
condition|(
name|ap
operator|==
literal|0
condition|)
name|ap
operator|=
literal|"???"
expr_stmt|;
block|}
else|else
block|{
name|ap
operator|+=
literal|2
expr_stmt|;
comment|/* -bN case, skip over the "-b" */
block|}
comment|/* ap points to purported number, regardless -bN or -b N */
if|if
condition|(
operator|*
name|ap
operator|==
literal|'0'
condition|)
block|{
comment|/* set external clocking */
if|if
condition|(
name|iface
operator|&
name|DDN_INTERFACE
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig %s: -b 0 invalid\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
break|break;
block|}
operator|*
name|ap
operator|=
literal|'b'
expr_stmt|;
comment|/* cookie for driver ioctl routine */
name|ifr
operator|.
name|ifr_data
operator|=
name|ap
expr_stmt|;
block|}
else|else
block|{
comment|/* set baud rate, if N is valid */
if|if
condition|(
name|iface
operator|&
name|DDN_INTERFACE
condition|)
name|p
operator|=
name|ddnbaud_rate
expr_stmt|;
else|else
name|p
operator|=
name|baud_rate
expr_stmt|;
while|while
condition|(
name|p
operator|->
name|b_rate
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|ap
argument_list|,
name|p
operator|->
name|b_rate
argument_list|)
operator|==
literal|0
condition|)
break|break;
name|p
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|p
operator|->
name|parameter
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
name|p
operator|->
name|parameter
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig: -b %s invalid\n"
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
block|}
break|break;
block|}
case|case
literal|'s'
case|:
comment|/* select DDN standard X.25 service  */
comment|/* or basic X.25 service, accept -sn */
comment|/* or -s n  */
if|if
condition|(
name|iface
operator|&
name|ACP_INTERFACE
condition|)
block|{
comment|/* error if 'acp' device */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n acpconfig:  '-s' flag invalid for"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" specified interface\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
comment|/* clear value */
if|if
condition|(
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|>=
literal|'0'
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|<=
literal|'2'
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|3
index|]
operator|==
literal|0
condition|)
block|{
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|+=
name|SERVICE_VAL
expr_stmt|;
comment|/* match 's','t','u' */
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
expr_stmt|;
block|}
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
if|if
condition|(
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|>=
literal|'0'
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|<=
literal|'2'
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
operator|==
literal|0
condition|)
block|{
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|+=
name|SERVICE_VAL
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|ifr
operator|.
name|ifr_data
operator|==
literal|0
operator|)
operator|||
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EALREADY
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: must shut down interface to\  change modes between DDN and PDN\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n acpconfig:  invalid X.25 service\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
block|}
block|}
break|break;
case|case
literal|'u'
case|:
comment|/* bring up the line, specify loopback  */
comment|/* or DTE/DCE, accept -un or -u n       */
if|if
condition|(
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|>=
literal|'0'
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|<=
literal|'4'
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|3
index|]
operator|==
literal|0
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
expr_stmt|;
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
if|if
condition|(
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|>=
literal|'0'
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|<=
literal|'4'
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
operator|==
literal|0
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
comment|/* any more parameters? */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" acpconfig: -u flag must be last\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ifr
operator|.
name|ifr_data
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n acpconfig:  invalid mode"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" '%s'\n"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
block|}
else|else
block|{
if|if
condition|(
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EADDRNOTAVAIL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: no local X.25 address \ translation in table; cannot start up PDN mode\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
block|}
block|}
block|}
break|break;
case|case
literal|'m'
case|:
comment|/* Send supervisory message to FEP */
block|{
name|char
modifier|*
name|mp
init|=
name|ddactl
operator|.
name|msg
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|static
name|char
modifier|*
name|xfmt
init|=
literal|"%x"
decl_stmt|;
specifier|static
name|char
modifier|*
name|ofmt
init|=
literal|"%o"
decl_stmt|;
name|bzero
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
block|{
name|argv
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|argv
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
block|{
comment|/* hit a non-number */
name|argc
operator|++
expr_stmt|;
comment|/* fix these guys for */
name|argv
operator|--
expr_stmt|;
comment|/* the main loop */
break|break;
block|}
if|if
condition|(
name|mp
operator|>
operator|&
name|ddactl
operator|.
name|msg
index|[
sizeof|sizeof
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
index|]
condition|)
block|{
name|fprintf
argument_list|(
literal|"\nacpconfig: -m message too long\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|notdef
name|printf
argument_list|(
literal|"argument %s argc %d\n"
argument_list|,
operator|*
name|argv
argument_list|,
name|argc
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sscanf
argument_list|(
operator|*
name|argv
argument_list|,
operator|(
operator|*
operator|*
name|argv
operator|==
literal|'0'
operator|)
condition|?
name|ofmt
else|:
name|xfmt
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
operator|*
name|mp
operator|++
operator|=
name|i
expr_stmt|;
block|}
comment|/* while */
name|ddactl
operator|.
name|func
operator|=
literal|'m'
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|ddactl
expr_stmt|;
ifdef|#
directive|ifdef
name|notdef
name|printf
argument_list|(
literal|"before ioctl msg %x %x %x %x %x %x %x %x\n"
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|1
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|2
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|3
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|4
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|5
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|6
index|]
argument_list|,
name|ddactl
operator|.
name|msg
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'n'
case|:
comment|/* set SVC limit */
block|{
name|char
modifier|*
name|ap
init|=
operator|*
name|argv
decl_stmt|;
if|if
condition|(
name|ap
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
block|{
name|argc
operator|--
expr_stmt|;
comment|/* value is next arg; fix pointers */
name|argv
operator|++
expr_stmt|;
name|ap
operator|=
operator|*
name|argv
expr_stmt|;
block|}
else|else
name|ap
operator|+=
literal|2
expr_stmt|;
comment|/* value at 3rd char of this arg */
name|ddactl
operator|.
name|func
operator|=
literal|'n'
expr_stmt|;
name|ddactl
operator|.
name|drval
operator|=
name|atoi
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|ddactl
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'q'
case|:
comment|/* query board or driver for status */
block|{
name|char
modifier|*
name|cp
init|=
operator|*
name|argv
decl_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|cp
argument_list|)
operator|>
literal|2
condition|)
name|cp
operator|+=
literal|2
expr_stmt|;
else|else
block|{
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|cp
operator|=
operator|*
name|argv
expr_stmt|;
block|}
name|doquery
argument_list|(
name|atoi
argument_list|(
name|cp
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'v'
case|:
comment|/* set variable */
block|{
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* keyword determining what to set */
name|char
modifier|*
name|vp
decl_stmt|;
comment|/* value to set it to. */
name|int
name|i
decl_stmt|,
name|val
decl_stmt|;
comment|/* 		     * The ORDERING of this table must match the 		     * cases in the processing for this ioctl 		     * inside the driver (kludgy interface!) 		     */
specifier|static
name|char
modifier|*
name|nametab
index|[]
init|=
block|{
literal|"log"
block|,
literal|"debug"
block|,
literal|"packet"
block|,
literal|"window"
block|,
literal|0
block|}
decl_stmt|;
name|cp
operator|=
operator|*
name|argv
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|cp
argument_list|)
operator|>
literal|2
condition|)
comment|/* handle -vNAME VAL and -v NAME VAL */
name|cp
operator|+=
literal|2
expr_stmt|;
else|else
block|{
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|cp
operator|=
operator|*
name|argv
expr_stmt|;
if|if
condition|(
name|cp
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -v what?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|vp
operator|=
operator|*
name|argv
expr_stmt|;
if|if
condition|(
name|vp
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -v %s what?\n"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|nametab
index|[
name|i
index|]
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
if|if
condition|(
literal|0
operator|==
name|strcmp
argument_list|(
name|nametab
index|[
name|i
index|]
argument_list|,
name|cp
argument_list|)
condition|)
goto|goto
name|strmatch
goto|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -v: \"%s\" unknown\n"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|strmatch
label|:
comment|/* hit the keyword, and "i" is its index */
if|if
condition|(
name|i
operator|<
literal|2
condition|)
comment|/* log, debug: masks: read in hexadecimal */
name|sscanf
argument_list|(
name|vp
argument_list|,
literal|"%x"
argument_list|,
operator|&
name|val
argument_list|)
expr_stmt|;
else|else
comment|/* window, packet: counts: read in decimal */
name|sscanf
argument_list|(
name|vp
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|val
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|2
condition|)
block|{
comment|/* packet size: take base 2 log */
name|struct
name|lg2tab
modifier|*
name|lp
decl_stmt|;
comment|/* 			 * The sad thing is that after putting in all this 			 * code to take the base 2 log, I realized that the 			 * FEP takes this argument in BYTES and does the 			 * log internally.  Left the code in, though, since 			 * it's the easiest way to check the argument. 			 * (The driver converts to bytes with a shift). 			 */
for|for
control|(
name|lp
operator|=
name|lg2tab
init|;
name|lp
operator|->
name|base2log
condition|;
operator|++
name|lp
control|)
if|if
condition|(
name|lp
operator|->
name|binval
operator|==
name|val
condition|)
block|{
name|val
operator|=
name|lp
operator|->
name|base2log
expr_stmt|;
goto|goto
name|goodsize
goto|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -v: bad packet size\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|goodsize
label|:
name|ddactl
operator|.
name|drval
operator|=
name|val
expr_stmt|;
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
operator|=
name|i
expr_stmt|;
name|ddactl
operator|.
name|func
operator|=
literal|'v'
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|ddactl
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'z'
case|:
comment|/* reset the specified front-end device*/
name|ifr
operator|.
name|ifr_data
operator|=
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
operator|)
expr_stmt|;
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig:  reset in progress, wait 1 minute\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'A'
case|:
comment|/* add a file of address translation table entries */
comment|/* accept "-A filename OR "-Afilename"             */
if|if
condition|(
name|iface
operator|&
name|ACP_INTERFACE
condition|)
block|{
comment|/* error if 'acp' device */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: '-A' flag invalid for specified \ interface\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
comment|/* clear value */
if|if
condition|(
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|>
literal|2
condition|)
name|fp
operator|=
name|fopen
argument_list|(
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
name|fp
operator|=
name|fopen
argument_list|(
operator|*
name|argv
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|fp
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: cannot open file '%s'\n"
argument_list|,
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'-'
operator|)
condition|?
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
else|:
operator|*
name|argv
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"acpconfig: processing file '%s'; please wait...\n"
argument_list|,
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'-'
operator|)
condition|?
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
else|:
operator|*
name|argv
argument_list|)
expr_stmt|;
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
literal|124
argument_list|,
name|fp
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|line
index|[
literal|0
index|]
operator|==
literal|'#'
operator|||
name|line
index|[
literal|0
index|]
operator|==
literal|'\n'
condition|)
continue|continue;
name|sscanf
argument_list|(
name|line
argument_list|,
literal|"%s %s"
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
comment|/*         		fprintf(stdout, 				"acpconfig: processing translation %s ==> %s\n", 				arg1, arg2); */
if|if
condition|(
operator|(
name|top
operator|=
name|strlen
argument_list|(
name|arg2
argument_list|)
operator|)
operator|>
literal|14
operator|||
name|top
operator|<
name|PDNX25AMIN
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: bad X.25 address length: '%s'\n"
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|tmp
operator|=
literal|0
init|;
name|tmp
operator|<
name|top
condition|;
name|tmp
operator|++
control|)
if|if
condition|(
name|arg2
index|[
name|tmp
index|]
operator|>
literal|'9'
operator|||
name|arg2
index|[
name|tmp
index|]
operator|<
literal|'0'
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: invalid X.25 address '%s'\n"
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|strncmp
argument_list|(
name|arg2
argument_list|,
name|PDNBADDNIC
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: incomplete X.25 address '%s'\n"
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|getaddr
argument_list|(
name|arg1
argument_list|,
operator|&
name|sin
argument_list|)
expr_stmt|;
name|trtab
operator|.
name|func
operator|=
literal|'a'
expr_stmt|;
name|trtab
operator|.
name|ipaddr
operator|=
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
expr_stmt|;
name|trtab
operator|.
name|x25addr
index|[
literal|0
index|]
operator|=
name|strlen
argument_list|(
name|arg2
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
operator|&
name|trtab
operator|.
name|x25addr
index|[
literal|1
index|]
argument_list|,
name|arg2
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|trtab
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'a'
case|:
comment|/* add an address translation table entry */
comment|/* accept "-a inet_addr x25_addr"         */
comment|/* OR "-ainet_addr x25_addr"              */
if|if
condition|(
name|iface
operator|&
name|ACP_INTERFACE
condition|)
block|{
comment|/* error if 'acp' device */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: '-a' flag invalid for specified \ interface\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
comment|/* clear value */
if|if
condition|(
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|>
literal|2
condition|)
name|getaddr
argument_list|(
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
argument_list|,
operator|&
name|sin
argument_list|)
expr_stmt|;
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
name|getaddr
argument_list|(
operator|*
name|argv
argument_list|,
operator|&
name|sin
argument_list|)
expr_stmt|;
block|}
name|trtab
operator|.
name|func
operator|=
literal|'a'
expr_stmt|;
name|trtab
operator|.
name|ipaddr
operator|=
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
expr_stmt|;
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|top
operator|=
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|)
operator|>
literal|14
operator|||
name|top
operator|<
name|PDNX25AMIN
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: bad X.25 address length: '%s'\n"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|tmp
operator|=
literal|0
init|;
name|tmp
operator|<
name|top
condition|;
name|tmp
operator|++
control|)
if|if
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
name|tmp
index|]
operator|>
literal|'9'
operator|||
operator|(
operator|*
name|argv
operator|)
index|[
name|tmp
index|]
operator|<
literal|'0'
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: invalid X.25 address '%s'\n"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|strncmp
argument_list|(
operator|*
name|argv
argument_list|,
name|PDNBADDNIC
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: incomplete X.25 address '%s'\n"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|trtab
operator|.
name|x25addr
index|[
literal|0
index|]
operator|=
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
operator|&
name|trtab
operator|.
name|x25addr
index|[
literal|1
index|]
argument_list|,
operator|*
name|argv
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|trtab
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'d'
case|:
comment|/* delete an address translation table entry */
comment|/* accept "-d inet_addr" OR "-dinet_addr"    */
if|if
condition|(
name|iface
operator|&
name|ACP_INTERFACE
condition|)
block|{
comment|/* error if 'acp' device */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: '-d' flag invalid for specified \ interface\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
comment|/* clear value */
if|if
condition|(
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|>
literal|2
condition|)
name|getaddr
argument_list|(
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
argument_list|,
operator|&
name|sin
argument_list|)
expr_stmt|;
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
name|getaddr
argument_list|(
operator|*
name|argv
argument_list|,
operator|&
name|sin
argument_list|)
expr_stmt|;
block|}
name|trtab
operator|.
name|func
operator|=
literal|'d'
expr_stmt|;
name|trtab
operator|.
name|ipaddr
operator|=
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|trtab
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'r'
case|:
comment|/* read an address translation table entry */
comment|/* accept "-r length" OR "-rlength"        */
if|if
condition|(
name|iface
operator|&
name|ACP_INTERFACE
condition|)
block|{
comment|/* error if 'acp' device */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: '-r' flag invalid for specified \ interface\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ifr
operator|.
name|ifr_data
operator|=
literal|0
expr_stmt|;
comment|/* clear value */
if|if
condition|(
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|>
literal|2
condition|)
name|top
operator|=
name|atoi
argument_list|(
operator|&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|)
argument_list|)
expr_stmt|;
else|else
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
name|top
operator|=
name|atoi
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|top
operator|==
literal|0
condition|)
name|top
operator|=
literal|30000
expr_stmt|;
comment|/* (a big number) */
for|for
control|(
name|tmp
operator|=
literal|0
init|;
name|tmp
operator|<
name|top
condition|;
name|tmp
operator|++
control|)
block|{
name|trtab
operator|.
name|ipaddr
operator|=
operator|(
name|u_long
operator|)
name|tmp
expr_stmt|;
name|trtab
operator|.
name|func
operator|=
literal|'r'
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|trtab
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EFAULT
condition|)
block|{
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"acpconfig: end of address table \ (%d entries max)\n"
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
break|break;
block|}
else|else
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 		   * The byte ordering "works" on the inet_ntoa() call. 		   * Probably only on VAXen, though (fine for us). 		   */
if|if
condition|(
name|trtab
operator|.
name|x25addr
index|[
literal|0
index|]
condition|)
block|{
name|printf
argument_list|(
literal|"acpconfig: address table entry %d: "
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s ==> %01.14s\n"
argument_list|,
name|inet_ntoa
argument_list|(
name|trtab
operator|.
name|ipaddr
argument_list|)
argument_list|,
operator|&
name|trtab
operator|.
name|x25addr
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
default|default:
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
block|}
block|}
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                        SETIFADDR()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Purpose:                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*      Set the interface address.                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Call:            setifaddr(addr, param)                           */
end_comment

begin_comment
comment|/*  Arguments:       addr:   internet address                         */
end_comment

begin_comment
comment|/*                   param:  argument value                           */
end_comment

begin_comment
comment|/*  Returns:         nothing                                          */
end_comment

begin_comment
comment|/*  Called by:       main()                                           */
end_comment

begin_comment
comment|/*  Calls to:        getaddr()                                        */
end_comment

begin_comment
comment|/*                   strncpy()                                        */
end_comment

begin_comment
comment|/*                   ioctl()                                          */
end_comment

begin_comment
comment|/*                   Perror()                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|setifaddr
argument_list|(
argument|addr
argument_list|,
argument|param
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|param
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|getaddr
argument_list|(
name|addr
argument_list|,
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|ifr
operator|.
name|ifr_addr
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCSIFADDR
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCSIFADDR)"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                          GETADDR()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/* THIS ROUTINE IS SLOW AS MOLASSES - - FIX IT SOONER OR LATER !!!    */
end_comment

begin_comment
comment|/*  Purpose:                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*      Get the interface address and stick it in the appropriate     */
end_comment

begin_comment
comment|/*      data structure.  This routine has four different methods for  */
end_comment

begin_comment
comment|/*      deriving the address.  If successful return nothing, else     */
end_comment

begin_comment
comment|/*      print error message and exit.                                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Call:            getaddr(s, sin)                                  */
end_comment

begin_comment
comment|/*  Arguments:       s:    string for address                         */
end_comment

begin_comment
comment|/*                   sin:    socket address struct                    */
end_comment

begin_comment
comment|/*  Returns:         nothing for success, else error message exit     */
end_comment

begin_comment
comment|/*  Called by:       setifaddr()                                      */
end_comment

begin_comment
comment|/*  Calls to:        gethostbyname()                                  */
end_comment

begin_comment
comment|/*                   bcopy()                                          */
end_comment

begin_comment
comment|/*                   getnetbyname()                                   */
end_comment

begin_comment
comment|/*                   inet_makeaddr()                                  */
end_comment

begin_comment
comment|/*                   inet_addr()                                      */
end_comment

begin_comment
comment|/*                   inet_network()                                   */
end_comment

begin_comment
comment|/*                   fprintf()                                        */
end_comment

begin_comment
comment|/*                   exit()                                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|getaddr
argument_list|(
argument|s
argument_list|,
argument|sin
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|struct
name|netent
modifier|*
name|np
decl_stmt|;
name|int
name|val
decl_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
condition|)
block|{
name|sin
operator|->
name|sin_family
operator|=
name|hp
operator|->
name|h_addrtype
expr_stmt|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|sin
operator|->
name|sin_addr
argument_list|,
name|hp
operator|->
name|h_length
argument_list|)
expr_stmt|;
return|return;
block|}
name|np
operator|=
name|getnetbyname
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|np
condition|)
block|{
name|sin
operator|->
name|sin_family
operator|=
name|np
operator|->
name|n_addrtype
expr_stmt|;
name|sin
operator|->
name|sin_addr
operator|=
name|inet_makeaddr
argument_list|(
name|np
operator|->
name|n_net
argument_list|,
name|INADDR_ANY
argument_list|)
expr_stmt|;
return|return;
block|}
name|sin
operator|->
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|val
operator|=
name|inet_addr
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
operator|-
literal|1
condition|)
block|{
name|sin
operator|->
name|sin_addr
operator|.
name|s_addr
operator|=
name|val
expr_stmt|;
return|return;
block|}
name|val
operator|=
name|inet_network
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
operator|-
literal|1
condition|)
block|{
name|sin
operator|->
name|sin_addr
operator|=
name|inet_makeaddr
argument_list|(
name|val
argument_list|,
name|INADDR_ANY
argument_list|)
expr_stmt|;
return|return;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: invalid internet address '%s'\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                         SETCONFIG()                            %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Purpose:                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*      Set the configuration parameters by sending socket ioctl      */
end_comment

begin_comment
comment|/*      to the specified interface driver.                            */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Call:            setconfig(action, s)                             */
end_comment

begin_comment
comment|/*  Arguments:       action    indicates action to be taken           */
end_comment

begin_comment
comment|/*                   s         socket descriptor                      */
end_comment

begin_comment
comment|/*  Returns:         0 for success, nonzero for failure               */
end_comment

begin_comment
comment|/*                   NOTE:  if no internet address, doesn't return,   */
end_comment

begin_comment
comment|/*                           program exits                            */
end_comment

begin_comment
comment|/*  Called by:       main()                                           */
end_comment

begin_comment
comment|/*  Calls to:        fprintf()                                        */
end_comment

begin_comment
comment|/*                   strncpy()                                        */
end_comment

begin_comment
comment|/*                   sizeof()                                         */
end_comment

begin_comment
comment|/*                   ioctl()                                          */
end_comment

begin_comment
comment|/*                   Perror()                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|setconfig
argument_list|(
argument|action
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|action
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
name|int
name|saves
decl_stmt|;
if|if
condition|(
name|action
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|saves
operator|=
name|s
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig:  command in progress\n"
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|3000000
argument_list|)
expr_stmt|;
comment|/* wait for device pwrup diags */
if|if
condition|(
name|ioctl
argument_list|(
name|saves
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                          USAGE()                               %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Purpose:                                                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*      Display the correct syntax for the acpconfig command line.    */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Call:            usage()                                          */
end_comment

begin_comment
comment|/*  Returns:         nothing                                          */
end_comment

begin_comment
comment|/*  Called by:       main()                                           */
end_comment

begin_comment
comment|/*  Calls to:        fprintf()                                        */
end_comment

begin_comment
comment|/*                   exit()                                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|usemsg
init|=
literal|"Usage: acpconfig interface [address] [-A filename] [-a ipaddr x25addr]\n\ \t[-b baud] [-d ipaddr] [-m message]\n\ \t[-n #_lcns] [-q type] [-r count] [-s X.25_service]\n\ \t[-u mode] [-v variable value] [-z]\n\ \n\ This version supports firmware revisions 1.0 and 2.0\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|usage
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|usemsg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                            PERROR()                               %%*/
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
comment|/*	print error message, based on errno                              */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Call:  		Perror(cmd)                                      */
end_comment

begin_comment
comment|/*  Arguments:      	cmd:   error message                             */
end_comment

begin_comment
comment|/*  Returns:  		nothing, exits if no internet address is set     */
end_comment

begin_comment
comment|/*  Called by:  	main()                                           */
end_comment

begin_comment
comment|/*  Calls to:   	fprintf()                                        */
end_comment

begin_comment
comment|/*                	perror()                                         */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|Perror
argument_list|(
argument|cmd
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cmd
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|errno
condition|)
block|{
case|case
name|ENXIO
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"no such interface\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EPERM
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"permission denied\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EDESTADDRREQ
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"no internet address assigned to interface\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|EINVAL
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"invalid command\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EINTR
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"device not operational\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|EINPROGRESS
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't change parameters with link up\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Bring the link down and try again\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|ENOPROTOOPT
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Changing packet size, window size, or\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"SVC limit requires firmware\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"revision 2.0 or greater\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|perror
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                            DOQUERY()                              %%*/
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
comment|/*	Query either FEP or driver for status, depending on argument	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Call:  		doquery(n)					 */
end_comment

begin_comment
comment|/*  Arguments:      	n: 0 for statistics query, 1 for driver mode	 */
end_comment

begin_comment
comment|/*  Returns:  		nothing, exits if error return from ioctl call	 */
end_comment

begin_comment
comment|/*			Prints status display on stdout			 */
end_comment

begin_comment
comment|/*  Called by:  	main()                                           */
end_comment

begin_comment
comment|/*  Calls to:   	fprintf()                                        */
end_comment

begin_comment
comment|/*                	perror()                                         */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|doquery
argument_list|(
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ddactl
operator|.
name|func
operator|=
operator|(
name|mode
operator|==
literal|0
operator|)
condition|?
literal|'p'
else|:
literal|'q'
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|ddactl
expr_stmt|;
name|strncpy
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|ifr
operator|.
name|ifr_name
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|s
argument_list|,
name|SIOCACPCONFIG
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ifr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|Perror
argument_list|(
literal|"ioctl (SIOCACPCONFIG) returns"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|==
literal|0
condition|)
name|fmtstats
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
expr_stmt|;
else|else
name|fmtmode
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * from PROJECT:[X25.ACP5250W.HCOMMON]NCP.H on  * VAX/Very Multiloquious System, node SAGE.  */
end_comment

begin_struct
struct|struct
name|stat_rsp
block|{
name|u_char
name|cmnd
decl_stmt|,
name|path
decl_stmt|,
name|var
decl_stmt|,
name|count
decl_stmt|;
comment|/* message header */
name|u_long
name|uptime
decl_stmt|;
comment|/* seconds since startup */
name|u_long
name|elapsed
decl_stmt|;
comment|/* tenths since last statistics response */
name|u_long
name|frames_sent
decl_stmt|;
comment|/* frames and... */
name|u_long
name|bytes_sent
decl_stmt|;
comment|/* bytes transmitted */
name|u_long
name|frames_rcvd
decl_stmt|;
comment|/* frames and... */
name|u_long
name|bytes_rcvd
decl_stmt|;
comment|/* bytes received */
name|u_short
name|SABMs_sent
decl_stmt|;
comment|/* similarly for SABMs, */
name|u_short
name|SABMs_rcvd
decl_stmt|;
name|u_short
name|DISCs_sent
decl_stmt|;
comment|/* DISCs */
name|u_short
name|DISCs_rcvd
decl_stmt|;
name|u_short
name|FRMRs_sent
decl_stmt|;
comment|/* FRMRs */
name|u_short
name|FRMRs_rcvd
decl_stmt|;
name|u_short
name|RRs_sent
decl_stmt|;
comment|/* RRs */
name|u_short
name|RRs_rcvd
decl_stmt|;
name|u_short
name|REJs_sent
decl_stmt|;
comment|/* REJs */
name|u_short
name|REJs_rcvd
decl_stmt|;
name|u_short
name|RNRs_sent
decl_stmt|;
comment|/* RNRs */
name|u_short
name|RNRs_rcvd
decl_stmt|;
name|u_short
name|crc_errors
decl_stmt|;
comment|/* CRC errors received */
name|u_short
name|bad_frames
decl_stmt|;
comment|/* invalid frames received */
name|u_short
name|rexmitted
decl_stmt|;
comment|/* I-frames RE-transmitted */
name|u_short
name|UAs_sent
decl_stmt|;
comment|/* UAs transmitted, received */
name|u_short
name|UAs_rcvd
decl_stmt|;
name|u_short
name|DMs_sent
decl_stmt|;
comment|/* DMs transmitted, received */
name|u_short
name|DMs_rcvd
decl_stmt|;
name|u_short
name|I_frames_sent
decl_stmt|;
comment|/* I frames transmitted, received */
name|u_short
name|I_frames_rcvd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * A long time ago in a UNIBUS far, far away, there was a Z80 based  * front end processor happily talking to its PDP-11 host.  They  * exchanged many cheerful messages, some of which were statistics  * queries.  The statistics query was defined in the only logical  * format, the format shared by both the Z80 and its PDP-11 host.  * Well, thousands of computer generations passed, and the little  * Z80 grew up into a big, strong 68000 based front end.  His  * friendly little PDP-11 host grew up too, into a big honkin'  * VAX.  They still liked to exchange cheerful messages, though,  * and some of those were still the same well-worn statistics  * queries, which are still in the only "logical" data format.  * So don't ask again why a VAX and a 68000 exchange data in Z80  * byte ordering!  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|z80toVAX
parameter_list|(
name|l
parameter_list|)
value|(((l)<< 16) | (((l)>> 16)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|pr
parameter_list|(
name|A
parameter_list|)
value|printf("%-10s%10d%10d\n", "A", sp->A
comment|/**/
value|_sent, sp->A
comment|/**/
value|_rcvd)
end_define

begin_comment
comment|/*  * internal routines for use by doquery()  */
end_comment

begin_macro
name|fmtstats
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|stat_rsp
modifier|*
name|sp
init|=
operator|(
expr|struct
name|stat_rsp
operator|*
operator|)
name|buf
decl_stmt|;
name|struct
name|timeval
name|t
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|sp
operator|->
name|elapsed
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|elapsed
argument_list|)
expr_stmt|;
name|sp
operator|->
name|uptime
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|uptime
argument_list|)
expr_stmt|;
name|sp
operator|->
name|frames_sent
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|frames_sent
argument_list|)
expr_stmt|;
name|sp
operator|->
name|frames_rcvd
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|frames_rcvd
argument_list|)
expr_stmt|;
name|sp
operator|->
name|bytes_sent
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|bytes_sent
argument_list|)
expr_stmt|;
name|sp
operator|->
name|bytes_rcvd
operator|=
name|z80toVAX
argument_list|(
name|sp
operator|->
name|bytes_rcvd
argument_list|)
expr_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|t
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|cp
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* get rid of the embedded newline */
name|printf
argument_list|(
literal|"\n----------------------------------------------\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Front End Processor statistics (host time: %s)\n"
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|t
operator|.
name|tv_sec
operator|-=
name|sp
operator|->
name|uptime
expr_stmt|;
name|cp
operator|=
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|cp
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
name|printf
argument_list|(
literal|"FEP up %d seconds (since %s)\n"
argument_list|,
name|sp
operator|->
name|uptime
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|t
operator|.
name|tv_sec
operator|+=
name|sp
operator|->
name|uptime
expr_stmt|;
name|t
operator|.
name|tv_sec
operator|-=
name|sp
operator|->
name|elapsed
expr_stmt|;
name|cp
operator|=
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|cp
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
name|printf
argument_list|(
literal|"%d seconds since last statistics (at %s)\n"
argument_list|,
name|sp
operator|->
name|elapsed
argument_list|,
name|cp
argument_list|)
expr_stmt|;
comment|/* ---- debugging stuff 	printf ("cmnd = %x path = %x var = %x count = %x\n", 		sp->cmnd, sp->path, sp->var, sp->count);    ---- */
name|printf
argument_list|(
literal|"\n%20s%10s\n"
argument_list|,
literal|"SENT"
argument_list|,
literal|"RCVD"
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|frames
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|I_frames
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|SABMs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|DISCs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|FRMRs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|RRs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|REJs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|RNRs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|UAs
argument_list|)
expr_stmt|;
name|pr
argument_list|(
name|DMs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n%d CRC errors; %d bad frames; %d frames retransmitted\n"
argument_list|,
name|sp
operator|->
name|crc_errors
argument_list|,
name|sp
operator|->
name|bad_frames
argument_list|,
name|sp
operator|->
name|rexmitted
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"--------------- END OF STATISTICS -----------------\n\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This is disgustingly ugly.  The whole interface between acpconfig  * and the driver has gotten completely out of hand.  Has to do with  * the fact that we want this program to be compatible with both  * ULTRIX and BSD and they have different include file structures AND  * historically many of the structures weren't even IN include files!  *  * buf:  *	dda_state, dda_init, dda_flags, dda_firmrev  */
end_comment

begin_macro
name|fmtmode
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
modifier|*
name|brd_modes
index|[]
init|=
block|{
literal|"DISABLED"
block|,
literal|"COMING UP"
block|,
literal|"UP"
block|,
literal|"GOING DOWN"
block|}
decl_stmt|;
name|printf
argument_list|(
literal|"\n>>> Driver status for %s (Interface is %s)<<<\n"
argument_list|,
name|name
argument_list|,
name|brd_modes
index|[
operator|*
name|buf
operator|&
literal|3
index|]
argument_list|)
expr_stmt|;
name|buf
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"\tMode 0x%x "
argument_list|,
operator|*
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|&
literal|0x1
condition|)
name|printf
argument_list|(
literal|"<DDN_STANDARD>"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|&
literal|0x2
condition|)
name|printf
argument_list|(
literal|"<DDN_BASIC>"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|&
literal|0x4
condition|)
name|printf
argument_list|(
literal|"<PDN>"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|buf
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"\tWarning, DDAF_OK is OFF<--------------\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\tInterface on-line (DDAF_OK is ON)\n"
argument_list|)
expr_stmt|;
name|buf
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"\tFirmware revision %d.%d installed\n"
argument_list|,
operator|(
operator|*
name|buf
operator|>>
literal|4
operator|)
operator|&
literal|0xF
argument_list|,
operator|*
name|buf
operator|&
literal|0xF
argument_list|)
expr_stmt|;
name|buf
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"*** End of driver status information ***\n\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

