begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|VERSION
value|"13-Nov-1989\n"
end_define

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
comment|/*	Copyright (c) 1988 by Advanced Computer Communications		 */
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
comment|/*  File:		acpconfig.c					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Author:		Clare E. Russ					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Project:		Installation verification program for ACC	 */
end_comment

begin_comment
comment|/*			ACP 5100/6100 and ACP 5250/6250 network		 */
end_comment

begin_comment
comment|/*			interface drivers.   Acpconfig provides a user	 */
end_comment

begin_comment
comment|/*			interface which supports the configuration of a	 */
end_comment

begin_comment
comment|/*			network	 interface.				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Function:								 */
end_comment

begin_comment
comment|/*	  Based on socket ioctls, provide user interface to Network	 */
end_comment

begin_comment
comment|/*	  Interface Drivers for the following ACC ACP devices:		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*		    ACP 5100/6100  'acp' interface			 */
end_comment

begin_comment
comment|/*		    ACP 5250/6250  'dda' interface			 */
end_comment

begin_comment
comment|/*		    ACP 625	   'ddn' interface			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	  The ioctl indicates what type of message is to be sent to the	 */
end_comment

begin_comment
comment|/*	  front end device (ie, bring up the HDLC line in external	 */
end_comment

begin_comment
comment|/*	  loopback mode).						 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Components:		acpconfig.c, ioctl.h				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Usage Notes:							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -A filename							 */
end_comment

begin_comment
comment|/*		Add the contents of the named file to the address	 */
end_comment

begin_comment
comment|/*		translation table for PDN service			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -a ipaddr x25addr						 */
end_comment

begin_comment
comment|/*		Add the specified address pair to the address		 */
end_comment

begin_comment
comment|/*		translation table for PDN service			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -b baud							 */
end_comment

begin_comment
comment|/*		Note that the baud rate values are different for the	 */
end_comment

begin_comment
comment|/*		ACP 625.  Table 1 contains the baud rates which apply	 */
end_comment

begin_comment
comment|/*		to the ACP 6100, ACP 5250/6250 products.  Table 2	 */
end_comment

begin_comment
comment|/*		contains the baud rates which apply to the ACP 625.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	  Table 1:  Nominal baud rates for ACP 5100/6100, ACP 5250/6250	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*			2.00M  2000K  2.0M  1.33M  1333K  1.3M		 */
end_comment

begin_comment
comment|/*			1.00M  1000K  1.0M  500K   250K	  100K		 */
end_comment

begin_comment
comment|/*			64K    64000  56K   56000  30K	  19.2K		 */
end_comment

begin_comment
comment|/*			9.6K   9600   4.8K  4800   2.4K	  2400		 */
end_comment

begin_comment
comment|/*			1.2K   1200					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	  Table 2:  Nominal baud rates for ACP 625			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*			316000	153600	 115200	  76800	  76.8K		 */
end_comment

begin_comment
comment|/*			 57600	 57.6K	  38400	  38.4K	  28800		 */
end_comment

begin_comment
comment|/*			 28.8K	 19200	  19.2K	   9600	   9.6K		 */
end_comment

begin_comment
comment|/*			  4800	  4.8K	   2400	   2.4K	   2150		 */
end_comment

begin_comment
comment|/*			  1760	  1200					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*		An argument of 0 or "external" to the -b option		 */
end_comment

begin_comment
comment|/*		specifies external clocking for the ACP 5100/6100	 */
end_comment

begin_comment
comment|/*		and ACP 5250/6250 interfaces. (The ACP 625 does not	 */
end_comment

begin_comment
comment|/*		support this feature.)	 All other values imply		 */
end_comment

begin_comment
comment|/*		internal clocking.					 */
end_comment

begin_comment
comment|/*		The M for megabits/second and K for kilobits/second	 */
end_comment

begin_comment
comment|/*		are optional.  Note that Table 1 allows for the entry	 */
end_comment

begin_comment
comment|/*		of 9.6 (with the assumed unit of Kilobits/second), but	 */
end_comment

begin_comment
comment|/*		also allows for the entry of 9600 (bits/second).  Thus	 */
end_comment

begin_comment
comment|/*		there is more than one entry for some of the baud rate	 */
end_comment

begin_comment
comment|/*		values.							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -c msgnum							 */
end_comment

begin_comment
comment|/*		Toggle the enable status of driver message number msgnum */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -d ipaddr							 */
end_comment

begin_comment
comment|/*		Delete the specified address entry from the address	 */
end_comment

begin_comment
comment|/*		translation table for PDN service			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -D								 */
end_comment

begin_comment
comment|/*		Delete all address entries form the address translation	 */
end_comment

begin_comment
comment|/*		table for PDN service					 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -e size							    */
end_comment

begin_comment
comment|/*		set the firmware buffer size to size.  This also resets	 */
end_comment

begin_comment
comment|/*		the board.  size comes from a table of valid sizes and	 */
end_comment

begin_comment
comment|/*		may also be "default" to get the default size.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -h mode							 */
end_comment

begin_comment
comment|/*		Read driver histogram and print on standard output. Each */
end_comment

begin_comment
comment|/*		entry is of the form sec.usec. The entries are as	 */
end_comment

begin_comment
comment|/*		follows:						 */
end_comment

begin_comment
comment|/*		0    : number of seconds the link was up		 */
end_comment

begin_comment
comment|/*		1    : starting time					 */
end_comment

begin_comment
comment|/*		2    : ending time					 */
end_comment

begin_comment
comment|/*		3    : current value for tmo_data_idle			 */
end_comment

begin_comment
comment|/*		4-69 : seconds n logical channels were open for		 */
end_comment

begin_comment
comment|/*		       n = 0 to 64 (126)				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*		If mode is 0 then data is read.	 If mode is 1 then data	 */
end_comment

begin_comment
comment|/*		is read and the histogram is reinitialized.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -f parameter status						 */
end_comment

begin_comment
comment|/*		Control flow control parameter negotiation where	 */
end_comment

begin_comment
comment|/*		parameter is either "packet" or "window" and		 */
end_comment

begin_comment
comment|/*		status is either "on" or "off".				 */
end_comment

begin_comment
comment|/*		Note:  incoming flow control parameter negotiation	 */
end_comment

begin_comment
comment|/*		if not effected by this option.				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -l								 */
end_comment

begin_comment
comment|/*	   -ln								 */
end_comment

begin_comment
comment|/*		List the currently active lcns.  The 'n' suffix		 */
end_comment

begin_comment
comment|/*		disables address to name lookups.			 */
end_comment

begin_comment
comment|/*									 */
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
comment|/*		by white space.	 Numbers with leading ``0'' are taken	 */
end_comment

begin_comment
comment|/*		as octal, other numbers taken as HEX, decimal is not	 */
end_comment

begin_comment
comment|/*		supported.  Hex and octal may be intermixed, as in	 */
end_comment

begin_comment
comment|/*		``0140 0 0 2 89 017''.	The message is terminated by the */
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
comment|/*		message.  The message is limited to MLEN = 112 bytes.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -N network							 */
end_comment

begin_comment
comment|/*		Set network type					 */
end_comment

begin_comment
comment|/*		transpac - french transpac network addressing		 */
end_comment

begin_comment
comment|/*		default	 - normal x25 network				 */
end_comment

begin_comment
comment|/*		net15	 - normal network but with 15 digit addrs	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -n circuits							 */
end_comment

begin_comment
comment|/*		Set the number of logical channels to ``circuits'', which*/
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
comment|/*	   -q 2	 Reserved for ACC debugging				 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -r count							 */
end_comment

begin_comment
comment|/*		Read the specified number of entries from the address	 */
end_comment

begin_comment
comment|/*		translation table for PDN service			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -r 0	 read all entries from the address translation table	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -s X.25 service						 */
end_comment

begin_comment
comment|/*		Select DDN standard X.25 service or basic X.25 service	 */
end_comment

begin_comment
comment|/*		or Public Data Network X.25 service			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -s standard	select standard X.25 service			 */
end_comment

begin_comment
comment|/*	   -s basic	select basic X.25 service			 */
end_comment

begin_comment
comment|/*	   -s pdn	select X.25 Public Data Network service		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -t sec	Set idle circuit timeout			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -u down  bring down the link					 */
end_comment

begin_comment
comment|/*	   -u dte   bring up link, no loopback, DTE			 */
end_comment

begin_comment
comment|/*	   -u dce   bring up link, no loopback, DCE			 */
end_comment

begin_comment
comment|/*	   -u ext   bring up link, external loopback mode		 */
end_comment

begin_comment
comment|/*	   -u int   bring up link, internal loopback mode		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -v variable value						 */
end_comment

begin_comment
comment|/*		Set the value of a driver variable symbolized by	 */
end_comment

begin_comment
comment|/*		"variable" to "value" decimal.	"Variables" understood	 */
end_comment

begin_comment
comment|/*		are "window" and "packet" to set the driver's notion of	 */
end_comment

begin_comment
comment|/*		negotiable window size, and negotiable packet size.	 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	   -z  reset the specifed front-end device			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  Compile Notes:							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	The associated makefile builds the acpconfig executable image	 */
end_comment

begin_comment
comment|/*	for UNIX or the specified emulation/simulation such as		 */
end_comment

begin_comment
comment|/*	The Wollongong Group (TWG) software which runs under VAX/VMS.	 */
end_comment

begin_comment
comment|/*	The makefile must be invoked with the argument which specifies	 */
end_comment

begin_comment
comment|/*	the target host operating system, otherwise the makefile	 */
end_comment

begin_comment
comment|/*	defaults to creating an executable image for UNIX.		 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*		  make		       (compile for UNIX 4.nBSD)	 */
end_comment

begin_comment
comment|/*		  make clean						 */
end_comment

begin_comment
comment|/*		  make print						 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*  System Notes:							 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	Create a socket of the AF_INET address family and of type	 */
end_comment

begin_comment
comment|/*	datagram, SOCK_DGRAM.  Use the socket to send a socket ioctl	 */
end_comment

begin_comment
comment|/*	to the network driver of the specified interface ('acp0' in	 */
end_comment

begin_comment
comment|/*	the usage notes).   Depending on the type of message specified	 */
end_comment

begin_comment
comment|/*	in the command line, send the appropriate socket ioctl to	 */
end_comment

begin_comment
comment|/*	specify what kind of action is to be taken.			 */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	For those drivers which support the Control Interface (CIF)	 */
end_comment

begin_comment
comment|/*	the message exchange conforms to the CIF which defines paired	 */
end_comment

begin_comment
comment|/*	command/response Control Interface Messages (CIMs) between the	 */
end_comment

begin_comment
comment|/*	host and the front end.	  Otherwise, the exchange of messages	 */
end_comment

begin_comment
comment|/*	is the pre-CIF protocol (i.e., that used  by the ddn interface). */
end_comment

begin_comment
comment|/*									 */
end_comment

begin_comment
comment|/*	Assignment of subcodes for the SIOCACPCONFIG ioctl:		 */
end_comment

begin_comment
comment|/*									 */
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
comment|/*	`c'		-c msgnum					 */
end_comment

begin_comment
comment|/*	`d'		-d command (PDN)				 */
end_comment

begin_comment
comment|/*	`e'		-e size						 */
end_comment

begin_comment
comment|/*	`h'		-h 0						 */
end_comment

begin_comment
comment|/*	`H'		-h 1						 */
end_comment

begin_comment
comment|/*	`m'		-m (message command)				 */
end_comment

begin_comment
comment|/*	`n'		-n circuits (limit lcns)			 */
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
comment|/*	`t'		-t sec (timeout set)				 */
end_comment

begin_comment
comment|/*	`S'		-s 0						 */
end_comment

begin_comment
comment|/*	`T'		-s 1						 */
end_comment

begin_comment
comment|/*	`U'		-s 2						 */
end_comment

begin_comment
comment|/*	`V'		-v command (set variable)			 */
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
comment|/*%%								    %%*/
end_comment

begin_comment
comment|/*%%		   INCLUDE FILES				    %%*/
end_comment

begin_comment
comment|/*%%								    %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*   There are alternate path names for The Wollongong Group (TWG)    */
end_comment

begin_comment
comment|/*   IPTCP and Eunice software which runs under VMS,		      */
end_comment

begin_comment
comment|/*   and for TGV, Incorporated's MultiNet software which also runs    */
end_comment

begin_comment
comment|/*   under VMS.							      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAXVMS
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|EXIT_ERR
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_OK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXIT_ERR
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

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

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_include
include|#
directive|include
file|<vaxif/if_ddaioctl.h>
end_include

begin_comment
comment|/* multinet doesn't fix ioctl.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VAXVMS
end_ifdef

begin_comment
comment|/* TWG or TGV */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"/sys/netinet/in.h"
end_include

begin_include
include|#
directive|include
file|"/sys/net/if.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|errno
end_ifdef

begin_undef
undef|#
directive|undef
name|errno
end_undef

begin_endif
endif|#
directive|endif
endif|errno
end_endif

begin_define
define|#
directive|define
name|errno
value|socket_errno
end_define

begin_comment
comment|/* MultiNet runtime errors	*/
end_comment

begin_define
define|#
directive|define
name|Perror
parameter_list|(
name|s
parameter_list|)
value|XPerror(s)
end_define

begin_comment
comment|/* Keep different from perror() */
end_comment

begin_define
define|#
directive|define
name|ioctl
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|socket_ioctl(s,c,d)
end_define

begin_comment
comment|/* MultiNet ioctl() routine	*/
end_comment

begin_endif
endif|#
directive|endif
endif|MULTINET
end_endif

begin_define
define|#
directive|define
name|NDDA
value|1
end_define

begin_define
define|#
directive|define
name|NONE
value|0
end_define

begin_comment
comment|/* used by the -o option */
end_comment

begin_define
define|#
directive|define
name|EXTENDED
value|1
end_define

begin_comment
comment|/* used by -o option */
end_comment

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
value|35
end_define

begin_comment
comment|/* for X.25 service flag, -s */
end_comment

begin_define
define|#
directive|define
name|ACTUAL_VAL
value|83
end_define

begin_comment
comment|/* for X.25 service flag 'S' */
end_comment

begin_comment
comment|/* network values */
end_comment

begin_define
define|#
directive|define
name|NET_STANDARD
value|0
end_define

begin_comment
comment|/* on standard network */
end_comment

begin_define
define|#
directive|define
name|NET_TRANSPAC
value|1
end_define

begin_comment
comment|/* on transpac style network */
end_comment

begin_comment
comment|/* delay macro from /sys/vax/param.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax11c
end_ifdef

begin_define
define|#
directive|define
name|NEW_DELAY
parameter_list|(
name|n
parameter_list|)
value|sleep(n / 100000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NEW_DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Table of baud rate values and the associated parameter for the Set	*/
end_comment

begin_comment
comment|/* System Parameters message, ddninit_msg.  The 'parameter1' is nonzero */
end_comment

begin_comment
comment|/* for valid baud rate divisors.  The user's manual gives both the	*/
end_comment

begin_comment
comment|/* actual and nominal baud rates, either one is accepted from the user, */
end_comment

begin_comment
comment|/* but the nominal baud rate is the figure which is closest to the rate */
end_comment

begin_comment
comment|/* set on the front end.						*/
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

begin_ifndef
ifndef|#
directive|ifndef
name|MULTINET
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|kmemf
init|=
literal|"/dev/kmem"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MULTINET
end_endif

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VAXVMS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WINS
end_ifdef

begin_include
include|#
directive|include
file|<vaxif/if_ddareg.h>
end_include

begin_include
include|#
directive|include
file|<vaxif/if_ddavar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_include
include|#
directive|include
file|"[-.kernel.vaxif]if_ddareg.h"
end_include

begin_include
include|#
directive|include
file|"[-.kernel.vaxif]if_ddavar.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
else|VAXVMS
end_else

begin_comment
comment|/* must be unix or ultrix */
end_comment

begin_include
include|#
directive|include
file|"/sys/vaxif/if_ddareg.h"
end_include

begin_include
include|#
directive|include
file|"/sys/vaxif/if_ddavar.h"
end_include

begin_endif
endif|#
directive|endif
endif|VAXVMS
end_endif

begin_comment
comment|/* EXTERNAL FUNCTIONS */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|routename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_ntoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|inet_network
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Weirdness for test-jig, re-map all ioctl and socket calls to go  *	through driver simulator.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_define
define|#
directive|define
name|ioctl
value|fake_unix_ioctl
end_define

begin_define
define|#
directive|define
name|socket
value|fake_unix_socket
end_define

begin_define
define|#
directive|define
name|main
value|cf_main
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	Print contents of queues and various data structures  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|state_tab
index|[]
init|=
block|{
literal|"Down"
block|,
literal|"Rstrt"
block|,
literal|"Idle"
block|,
literal|"Call"
block|,
literal|"Open"
block|,
literal|"Clear"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NSTATES
value|5
end_define

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%			     MAIN()				    %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*								      */
end_comment

begin_comment
comment|/*  Purpose:							      */
end_comment

begin_comment
comment|/*								      */
end_comment

begin_comment
comment|/*	For the specified interface, create a socket for a socket     */
end_comment

begin_comment
comment|/*	ioctl to set the Internet address and configuration.  The     */
end_comment

begin_comment
comment|/*	ioctl kicks the appropriate driver, the value in ifr_data     */
end_comment

begin_comment
comment|/*	indicates the type of action to be taken.  ('b' indicates     */
end_comment

begin_comment
comment|/*	external clock, 1-14 indicates baud rate from the table of    */
end_comment

begin_comment
comment|/*	possible values, '0' - '4' indicates -u options, and 's','t', */
end_comment

begin_comment
comment|/*	'u' indicate -s options.)				      */
end_comment

begin_comment
comment|/*	Enhancement: 'a' indicates addition of an address table	      */
end_comment

begin_comment
comment|/*	entry, 'd' indicates deletion of an address table entry,      */
end_comment

begin_comment
comment|/*	and 'r' is a request to read address table entries.	      */
end_comment

begin_comment
comment|/*	Etc, etc (see comment at top for complete list)		      */
end_comment

begin_comment
comment|/*								      */
end_comment

begin_comment
comment|/*  Call:		main( argc, argv)			      */
end_comment

begin_comment
comment|/*  Arguments:		argc:	argument count			      */
end_comment

begin_comment
comment|/*			argv:	argument value			      */
end_comment

begin_comment
comment|/*  Returns:		nothing					      */
end_comment

begin_comment
comment|/*  Called by:		invoked by privileged user		      */
end_comment

begin_comment
comment|/*  Calls to:		socket()				      */
end_comment

begin_comment
comment|/*			perror()				      */
end_comment

begin_comment
comment|/*			strcpy()				      */
end_comment

begin_comment
comment|/*			strncpy()				      */
end_comment

begin_comment
comment|/*			sizeof()				      */
end_comment

begin_comment
comment|/*			usage()					      */
end_comment

begin_comment
comment|/*			long_usage()				      */
end_comment

begin_comment
comment|/*			get_bfrsize_index()			      */
end_comment

begin_comment
comment|/*			ioctl()					      */
end_comment

begin_comment
comment|/*			exit()					      */
end_comment

begin_comment
comment|/*			Perror()				      */
end_comment

begin_comment
comment|/*								      */
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

begin_decl_stmt
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* control host name lookup (symbolic) */
end_comment

begin_decl_stmt
name|struct
name|ddactl
name|ddactl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|trtab
name|trtab
decl_stmt|;
end_decl_stmt

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
name|char
modifier|*
name|fe_bfr_sizes
index|[]
init|=
block|{
literal|"default"
block|,
comment|/* entry 0: Default Size */
literal|"256"
block|,
comment|/* entry 1: 256 bytes */
literal|"512"
block|,
comment|/* entry 2: 512 bytes */
literal|"1024"
block|,
comment|/* entry 3: 1K bytes (currently same as default) */
literal|"2048"
block|,
comment|/* entry 4: 2K bytes */
literal|"4096"
block|,
comment|/* entry 5: 4K bytes */
literal|"8192"
block|,
comment|/* entry 6: 8K bytes */
literal|"16384"
block|,
comment|/* entry 7: 16K bytes */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure used to hold the results of an nlist library  * function call.  */
end_comment

begin_decl_stmt
name|struct
name|nlist
name|nl
index|[]
init|=
block|{
block|{
literal|"_dda_softc"
block|}
block|,
define|#
directive|define
name|SOFTC
value|0
literal|""
block|, }
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VAXVMS
end_ifndef

begin_comment
comment|/*  * Seek into the kernel for a value.  * Used by the -l option of acpconfig.  */
end_comment

begin_macro
name|klseek
argument_list|(
argument|fd
argument_list|,
argument|base
argument_list|,
argument|off
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|off
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
name|base
argument_list|,
name|off
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig:  Bad lseek fd=%d,bas=%x,off=%d "
argument_list|,
name|fd
argument_list|,
name|base
argument_list|,
name|off
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|""
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

begin_macro
name|klread
argument_list|(
argument|fd
argument_list|,
argument|buf
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|size
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"Read"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
endif|VAXVMS
end_endif

begin_comment
comment|/*  *	Routine used in conjunction with the -l option.  *	This function displays the status of each active  *	lcn for the given unit.  */
end_comment

begin_macro
name|display
argument_list|(
argument|addr
argument_list|,
argument|nddach
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nddach
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of circuits currently available */
end_comment

begin_block
block|{
name|struct
name|dda_softc
name|dda_softc
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|header
decl_stmt|;
if|if
condition|(
name|addr
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"acpconfig: nlist--symbol not defined\n"
argument_list|)
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|MULTINET
name|klseek
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|klread
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|dda_softc
argument_list|,
sizeof|sizeof
argument_list|(
name|dda_softc
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
else|MULTINET
name|klseek
argument_list|(
name|kmem
argument_list|,
name|addr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|klread
argument_list|(
name|kmem
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|dda_softc
argument_list|,
sizeof|sizeof
argument_list|(
name|dda_softc
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|MULTINET
name|header
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|nddach
condition|;
name|i
operator|++
control|)
block|{
name|dc
operator|=
operator|&
name|dda_softc
operator|.
name|dda_cb
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_state
operator|!=
name|LC_IDLE
operator|)
operator|&&
operator|(
name|dc
operator|->
name|dc_state
operator|!=
name|LC_DOWN
operator|)
condition|)
block|{
if|if
condition|(
operator|!
name|header
condition|)
block|{
name|printf
argument_list|(
literal|"\n\t\t\tACP 6250 / 5250 (dda%d) Status\n"
argument_list|,
name|dda_softc
operator|.
name|dda_if
operator|.
name|if_unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"lcn Qlen Dropped Flags Timer State  Pin Pout Win Wout  IP Addr\n"
argument_list|)
expr_stmt|;
block|}
name|header
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"%3d "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%4d "
argument_list|,
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%6d  "
argument_list|,
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_drops
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_CLIENTS
condition|)
block|{
case|case
name|DC_X29
case|:
name|p
operator|=
literal|"Pad "
expr_stmt|;
break|break;
case|case
name|DC_X29W
case|:
name|p
operator|=
literal|"Host"
expr_stmt|;
break|break;
case|case
name|DC_RAW
case|:
name|p
operator|=
literal|"PI  "
expr_stmt|;
break|break;
case|case
name|DC_IP
case|:
name|p
operator|=
literal|"IP  "
expr_stmt|;
break|break;
default|default:
name|p
operator|=
literal|"bug!"
expr_stmt|;
break|break;
block|}
name|printf
argument_list|(
literal|"%c %s"
argument_list|,
operator|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_OBUSY
condition|?
literal|'B'
else|:
literal|' '
operator|)
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %3d  "
argument_list|,
name|dc
operator|->
name|dc_timer
argument_list|)
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_state
operator|>
name|NSTATES
condition|)
name|printf
argument_list|(
literal|"%4x? "
argument_list|,
name|dc
operator|->
name|dc_state
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%-5s "
argument_list|,
name|state_tab
index|[
name|dc
operator|->
name|dc_state
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|dc
operator|->
name|dc_pktsizein
condition|?
literal|"%4d "
else|:
literal|" ??? "
argument_list|,
literal|1
operator|<<
name|dc
operator|->
name|dc_pktsizein
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|dc
operator|->
name|dc_pktsizeout
condition|?
literal|"%4d "
else|:
literal|" ??? "
argument_list|,
literal|1
operator|<<
name|dc
operator|->
name|dc_pktsizeout
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|dc
operator|->
name|dc_wsizein
condition|?
literal|"%3d "
else|:
literal|"??? "
argument_list|,
name|dc
operator|->
name|dc_wsizein
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|dc
operator|->
name|dc_wsizeout
condition|?
literal|"%3d "
else|:
literal|"??? "
argument_list|,
name|dc
operator|->
name|dc_wsizeout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dc
operator|->
name|dc_flags
operator|&
name|DC_CLIENTS
operator|)
operator|==
name|DC_IP
condition|)
name|printf
argument_list|(
literal|"  %s"
argument_list|,
name|routename
argument_list|(
name|dc
operator|->
name|dc_inaddr
argument_list|)
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
operator|!
name|header
operator|)
operator|&&
operator|(
name|i
operator|==
name|nddach
operator|+
literal|1
operator|)
condition|)
name|printf
argument_list|(
literal|"lcns 0 through %d inactive\n"
argument_list|,
name|nddach
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|dda_softc
operator|.
name|dda_ipaddr
operator|.
name|s_addr
expr_stmt|;
name|printf
argument_list|(
literal|"Our addr: %s"
argument_list|,
name|routename
argument_list|(
name|sin
operator|.
name|sin_addr
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|char
modifier|*
name|routename
parameter_list|(
name|in
parameter_list|)
name|struct
name|in_addr
name|in
decl_stmt|;
block|{
name|char
modifier|*
name|cp
init|=
literal|0
decl_stmt|;
specifier|static
name|char
name|line
index|[
literal|50
index|]
decl_stmt|;
name|int
name|lna
decl_stmt|,
name|net
decl_stmt|;
name|net
operator|=
name|inet_netof
argument_list|(
name|in
argument_list|)
expr_stmt|;
name|lna
operator|=
name|inet_lnaof
argument_list|(
name|in
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|nflag
condition|)
block|{
if|if
condition|(
name|lna
operator|==
name|INADDR_ANY
condition|)
block|{
name|struct
name|netent
modifier|*
name|np
init|=
name|getnetbyaddr
argument_list|(
name|net
argument_list|,
name|AF_INET
argument_list|)
decl_stmt|;
if|if
condition|(
name|np
condition|)
name|cp
operator|=
name|np
operator|->
name|n_name
expr_stmt|;
block|}
else|else
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
name|hp
operator|=
name|gethostbyaddr
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|in
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|in_addr
argument_list|)
argument_list|,
name|AF_INET
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
condition|)
name|cp
operator|=
name|hp
operator|->
name|h_name
expr_stmt|;
block|}
block|}
if|if
condition|(
name|cp
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|line
argument_list|,
name|cp
argument_list|)
expr_stmt|;
else|else
block|{
name|u_char
modifier|*
name|ucp
init|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|in
decl_stmt|;
if|if
condition|(
name|lna
operator|==
name|INADDR_ANY
condition|)
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|line
argument_list|,
literal|"%u.%u.%u"
argument_list|,
name|ucp
index|[
literal|0
index|]
argument_list|,
name|ucp
index|[
literal|1
index|]
argument_list|,
name|ucp
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|line
argument_list|,
literal|"%u.%u.%u.%u"
argument_list|,
name|ucp
index|[
literal|0
index|]
argument_list|,
name|ucp
index|[
literal|1
index|]
argument_list|,
name|ucp
index|[
literal|2
index|]
argument_list|,
name|ucp
index|[
literal|3
index|]
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|line
operator|)
return|;
block|}
end_function

begin_macro
name|get_bfrsize_index
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
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
name|fe_bfr_sizes
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|str
argument_list|,
name|fe_bfr_sizes
index|[
name|i
index|]
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|i
operator|)
return|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Invalid size: %s\nBuffer sizes available are: "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|fe_bfr_sizes
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s "
argument_list|,
name|fe_bfr_sizes
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

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
decl_stmt|,
name|offset
decl_stmt|;
name|int
name|unit
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
name|char
modifier|*
name|ap
decl_stmt|;
name|char
name|option_byte1
init|=
literal|0
decl_stmt|;
name|int
name|o_flag
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|argc
operator|==
literal|1
condition|)
block|{
name|long_usage
argument_list|()
expr_stmt|;
block|}
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
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|name
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
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
name|unit
operator|=
operator|(
operator|*
name|argv
operator|)
index|[
literal|3
index|]
operator|&
literal|0x0F
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
operator|*
name|argv
operator|!=
literal|'-'
condition|)
name|setifaddr
argument_list|(
operator|*
name|argv
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
comment|/* process flag(s) */
block|{
case|case
literal|'b'
case|:
comment|/* set baud rate or ext clocking */
name|ap
operator|=
operator|*
name|argv
expr_stmt|;
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
name|ap
operator|+=
literal|2
expr_stmt|;
comment|/* -bN case, skip over the "-b" */
comment|/* ap points to purported number, regardless -bN or -b N */
if|if
condition|(
operator|(
operator|*
name|ap
operator|==
literal|'0'
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|ap
argument_list|,
literal|"external"
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
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
name|arg1
index|[
literal|0
index|]
operator|=
literal|'b'
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
name|arg1
expr_stmt|;
block|}
else|else
comment|/* set baud rate, if N is valid */
block|{
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
case|case
literal|'l'
case|:
comment|/* monitor status of lcns */
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
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
literal|3
index|]
operator|==
literal|'\0'
condition|)
name|nflag
operator|=
literal|1
expr_stmt|;
comment|/* "-ln" - numeric */
elseif|else
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
literal|'\0'
condition|)
name|nflag
operator|=
literal|0
expr_stmt|;
comment|/* "-l" - symbolic */
else|else
name|usage
argument_list|()
expr_stmt|;
comment|/* other - wrong. */
if|if
condition|(
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|<
literal|3
condition|)
block|{
ifdef|#
directive|ifdef
name|VAXVMS
ifdef|#
directive|ifdef
name|MULTINET
if|if
condition|(
name|multinet_kernel_nlist
argument_list|(
literal|"MULTINET_NETWORK_IMAGE:"
argument_list|,
name|nl
argument_list|)
operator|==
operator|-
literal|1
condition|)
else|#
directive|else
else|MULTINET
comment|/* must be TWG instead */
name|char
modifier|*
name|vmsnlist
parameter_list|()
function_decl|;
name|kmemf
operator|=
name|vmsnlist
argument_list|()
expr_stmt|;
if|if
condition|(
name|nlist
argument_list|(
name|kmemf
argument_list|,
name|nl
argument_list|)
operator|==
operator|-
literal|1
condition|)
endif|#
directive|endif
endif|MULTINET
else|#
directive|else
else|VAXVMS
if|if
condition|(
name|nlist
argument_list|(
literal|"/vmunix"
argument_list|,
name|nl
argument_list|)
operator|==
operator|-
literal|1
condition|)
endif|#
directive|endif
endif|VAXVMS
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: could not open /vmunix\n"
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
name|nl
index|[
name|SOFTC
index|]
operator|.
name|n_value
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig:  No namelist\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|VAXVMS
name|kmem
operator|=
name|open
argument_list|(
name|kmemf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|kmem
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig:  cannot open "
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|kmemf
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
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
literal|0
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
name|display
argument_list|(
call|(
name|off_t
call|)
argument_list|(
name|nl
index|[
name|SOFTC
index|]
operator|.
name|n_value
operator|+
name|unit
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|dda_softc
argument_list|)
argument_list|)
argument_list|,
operator|*
operator|(
name|int
operator|*
operator|)
name|ifr
operator|.
name|ifr_data
argument_list|)
expr_stmt|;
block|}
else|else
name|usage
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|kmem
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
comment|/* collect X.25 1984 options */
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
comment|/* handle -oNAME and -o NAME */
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
literal|"acpconfig: -o what?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|cp
argument_list|,
literal|"none"
argument_list|)
operator|==
literal|0
condition|)
name|option_byte1
operator|=
name|NONE
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|cp
argument_list|,
literal|"extended"
argument_list|)
operator|==
literal|0
condition|)
name|option_byte1
operator||=
name|EXTENDED
expr_stmt|;
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -o %s invalid\n"
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
name|o_flag
operator|++
expr_stmt|;
block|}
break|break;
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
operator|!
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
condition|)
block|{
name|offset
operator|=
literal|0
expr_stmt|;
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
block|}
else|else
name|offset
operator|=
literal|2
expr_stmt|;
if|if
condition|(
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
index|]
operator|>=
literal|'0'
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
index|]
operator|<
literal|'3'
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
operator|+
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
name|offset
index|]
operator|+=
name|SERVICE_VAL
expr_stmt|;
comment|/* match 'S','T','U' */
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
name|offset
index|]
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|strncmp
argument_list|(
operator|&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
index|]
argument_list|,
literal|"standard"
argument_list|,
literal|8
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
operator|+
literal|8
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
name|offset
index|]
operator|=
name|ACTUAL_VAL
expr_stmt|;
comment|/* match 'S' */
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
name|offset
index|]
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|strncmp
argument_list|(
operator|&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
index|]
argument_list|,
literal|"basic"
argument_list|,
literal|5
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
operator|+
literal|5
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
name|offset
index|]
operator|=
name|ACTUAL_VAL
operator|+
literal|1
expr_stmt|;
comment|/* match 'T' */
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
name|offset
index|]
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|strncmp
argument_list|(
operator|&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
index|]
argument_list|,
literal|"pdn"
argument_list|,
literal|3
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|*
name|argv
operator|)
index|[
name|offset
operator|+
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
name|offset
index|]
operator|=
name|ACTUAL_VAL
operator|+
literal|2
expr_stmt|;
comment|/* 'U' */
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
name|offset
index|]
operator|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig:  invalid X.25 service\n"
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* display proper syntax for user */
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
block|}
break|break;
case|case
literal|'u'
case|:
block|{
name|char
modifier|*
name|vp
init|=
operator|*
name|argv
decl_stmt|;
comment|/* value to set it to. */
name|char
modifier|*
name|cp
decl_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|vp
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
name|vp
operator|=
operator|*
name|argv
expr_stmt|;
block|}
else|else
name|vp
operator|+=
literal|2
expr_stmt|;
comment|/* value at 3rd char of this arg */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"-u command must be last on line\n"
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
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"down"
argument_list|)
operator|==
literal|0
operator|||
operator|*
name|vp
operator|==
literal|'0'
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
literal|"0"
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"dte"
argument_list|)
operator|==
literal|0
operator|||
operator|*
name|vp
operator|==
literal|'1'
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
literal|"1"
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"dce"
argument_list|)
operator|==
literal|0
operator|||
operator|*
name|vp
operator|==
literal|'2'
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
literal|"2"
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"ext"
argument_list|)
operator|==
literal|0
operator|||
operator|*
name|vp
operator|==
literal|'3'
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
literal|"3"
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"int"
argument_list|)
operator|==
literal|0
operator|||
operator|*
name|vp
operator|==
literal|'4'
condition|)
name|ifr
operator|.
name|ifr_data
operator|=
literal|"4"
expr_stmt|;
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
literal|"acpconfig: -u invalid mode '%s'\n"
argument_list|,
operator|*
name|vp
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
block|}
break|break;
case|case
literal|'f'
case|:
comment|/* control initiation of flow control */
comment|/* parameters netgotiation. */
block|{
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* keyword determining which parameter */
comment|/* to control*/
name|char
modifier|*
name|vp
decl_stmt|;
comment|/* value to set it to. */
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
comment|/* handle -fNAME VAL and -f NAME VAL */
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
literal|"acpconfig: -f what?\n"
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
literal|"acpconfig: -f %s what?\n"
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
if|if
condition|(
name|strcmp
argument_list|(
name|cp
argument_list|,
literal|"packet"
argument_list|)
operator|==
literal|0
condition|)
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|cp
argument_list|,
literal|"window"
argument_list|)
operator|==
literal|0
condition|)
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -f %s invalid\n"
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
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"on"
argument_list|)
operator|==
literal|0
condition|)
name|ddactl
operator|.
name|drval
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"off"
argument_list|)
operator|==
literal|0
condition|)
name|ddactl
operator|.
name|drval
operator|=
literal|0
expr_stmt|;
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: -f %s invalid\n"
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
name|ddactl
operator|.
name|func
operator|=
literal|'f'
expr_stmt|;
operator|(
name|void
operator|)
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
literal|'h'
case|:
comment|/* histogram information */
block|{
name|char
modifier|*
name|cp
init|=
operator|*
name|argv
decl_stmt|;
name|struct
name|timeval
name|databuf
index|[
name|HISTSIZE
index|]
decl_stmt|;
specifier|register
name|int
name|i
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
literal|"acpconfig: -h what?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
operator|*
operator|(
operator|(
name|char
operator|*
operator|)
name|databuf
operator|)
operator|=
operator|(
operator|*
name|cp
operator|==
literal|'1'
operator|)
condition|?
literal|'H'
else|:
literal|'h'
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
name|databuf
expr_stmt|;
operator|(
name|void
operator|)
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
operator|*
operator|(
name|cp
operator|+
literal|1
operator|)
operator|==
literal|'r'
condition|)
block|{
name|printf
argument_list|(
literal|"%ld.%06ld\t"
argument_list|,
name|databuf
index|[
name|H_LINK_UP
index|]
operator|.
name|tv_sec
argument_list|,
name|databuf
index|[
name|H_LINK_UP
index|]
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%ld.%06ld"
argument_list|,
name|databuf
index|[
name|H_START
index|]
operator|.
name|tv_sec
argument_list|,
name|databuf
index|[
name|H_START
index|]
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t%ld.%06ld"
argument_list|,
name|databuf
index|[
name|H_END
index|]
operator|.
name|tv_sec
argument_list|,
name|databuf
index|[
name|H_END
index|]
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t%ld.%06ld"
argument_list|,
name|databuf
index|[
name|H_TMO
index|]
operator|.
name|tv_sec
argument_list|,
name|databuf
index|[
name|H_TMO
index|]
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|H_LINK_UP
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"\t%ld.%06ld"
argument_list|,
name|databuf
index|[
name|i
index|]
operator|.
name|tv_sec
argument_list|,
name|databuf
index|[
name|i
index|]
operator|.
name|tv_usec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
else|else
name|hist_data_out
argument_list|(
name|databuf
argument_list|)
expr_stmt|;
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
name|stderr
argument_list|,
literal|"\nacpconfig: -m message too long\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
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
elseif|else
if|if
condition|(
operator|*
operator|(
name|int
operator|*
operator|)
name|ifr
operator|.
name|ifr_data
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"acpconfig: %s: %d circuits currently available.\n"
argument_list|,
name|name
argument_list|,
operator|*
operator|(
name|int
operator|*
operator|)
name|ifr
operator|.
name|ifr_data
argument_list|)
expr_stmt|;
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
name|int
name|mode
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
literal|"acpconfig: -q what?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|mode
operator|=
name|atoi
argument_list|(
name|cp
argument_list|)
expr_stmt|;
name|ddactl
operator|.
name|func
operator|=
literal|'q'
expr_stmt|;
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
operator|=
name|mode
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
operator|(
name|void
operator|)
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
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
literal|0
case|:
name|fmtstats
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|fmtmode
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|fmtsilo
argument_list|(
name|ddactl
operator|.
name|msg
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
break|break;
case|case
literal|'t'
case|:
comment|/* set idle circuit timeout limit */
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
literal|'t'
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
operator|(
name|void
operator|)
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
literal|'c'
case|:
comment|/* disable/enable driver console message */
block|{
name|char
modifier|*
name|ap
init|=
operator|*
name|argv
decl_stmt|;
name|int
name|val
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
if|if
condition|(
operator|(
name|ap
operator|==
name|NULL
operator|)
operator|||
operator|(
operator|*
name|ap
operator|==
literal|'-'
operator|)
operator|||
operator|(
operator|*
name|ap
operator|==
literal|'\0'
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig: no message number specified for -c\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ddactl
operator|.
name|func
operator|=
literal|'c'
expr_stmt|;
name|val
operator|=
name|ddactl
operator|.
name|drval
operator|=
name|atoi
argument_list|(
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
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
else|else
block|{
name|printf
argument_list|(
literal|"acpconfig: %s: Driver message #%d is now %s\n"
argument_list|,
name|name
argument_list|,
name|val
argument_list|,
operator|*
operator|(
name|u_char
operator|*
operator|)
name|ifr
operator|.
name|ifr_data
condition|?
literal|"disabled"
else|:
literal|"enabled"
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|'N'
case|:
comment|/* set net id */
block|{
name|char
modifier|*
name|vp
init|=
operator|*
name|argv
decl_stmt|;
comment|/* value to set it to. */
name|char
modifier|*
name|cp
decl_stmt|;
name|int
name|net_type
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|vp
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
name|vp
operator|=
operator|*
name|argv
expr_stmt|;
block|}
else|else
name|vp
operator|+=
literal|2
expr_stmt|;
comment|/* value at 3rd char of this arg */
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"transpac"
argument_list|)
operator|==
literal|0
condition|)
name|net_type
operator|=
name|NET_TRANSPAC
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"0"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"standard"
argument_list|)
operator|==
literal|0
condition|)
name|net_type
operator|=
name|NET_STANDARD
expr_stmt|;
if|if
condition|(
name|net_type
operator|!=
operator|-
literal|1
condition|)
block|{
name|ddactl
operator|.
name|func
operator|=
literal|'N'
expr_stmt|;
name|ddactl
operator|.
name|drval
operator|=
name|net_type
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
name|setconfig
argument_list|(
operator|&
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|net_type
operator|==
name|NET_TRANSPAC
operator|||
name|strcmp
argument_list|(
name|vp
argument_list|,
literal|"net15"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* allow 15 digit addrs */
name|ddactl
operator|.
name|func
operator|=
literal|'m'
expr_stmt|;
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
name|bcopy
argument_list|(
literal|"\140\0\0\2\177\17"
argument_list|,
name|ddactl
operator|.
name|msg
argument_list|,
literal|6
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
name|setconfig
argument_list|(
operator|&
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
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
comment|/* debug, dbgunit, and log are obsolete */
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
literal|"dbgunit"
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
literal|3
condition|)
comment|/* log, debug: masks: read in hexadecimal */
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
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
literal|3
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
operator|(
name|void
operator|)
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
literal|'e'
case|:
block|{
name|char
modifier|*
name|cp
init|=
operator|*
name|argv
decl_stmt|;
name|char
name|databuf
index|[
literal|10
index|]
decl_stmt|;
specifier|register
name|int
name|i
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
name|databuf
index|[
literal|0
index|]
operator|=
literal|'e'
expr_stmt|;
name|i
operator|=
name|get_bfrsize_index
argument_list|(
name|cp
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* get_bfrsize_index will print error message */
else|else
name|databuf
index|[
literal|1
index|]
operator|=
name|i
expr_stmt|;
name|ifr
operator|.
name|ifr_data
operator|=
operator|(
name|caddr_t
operator|)
name|databuf
expr_stmt|;
if|if
condition|(
operator|!
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig:  buffer reset in progress, wait 1 minute\n"
argument_list|)
expr_stmt|;
break|break;
block|}
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
if|if
condition|(
operator|!
name|setconfig
argument_list|(
name|ifr
operator|.
name|ifr_data
argument_list|,
name|s
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig:  reset in progress, wait 1 minute\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"acpconfig: Could not create UCBs\n"
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
literal|80
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
operator|(
name|void
operator|)
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
comment|/* 			fprintf(stdout, 				"acpconfig: processing translation %s ==> %s\n", 				arg1, arg2); */
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
operator|(
name|MAXADDRLEN
operator|-
literal|1
operator|)
operator|||
name|top
operator|<
operator|(
name|MINADDRLEN
operator|-
literal|1
operator|)
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
operator|(
name|void
operator|)
name|strncpy
argument_list|(
operator|(
name|char
operator|*
operator|)
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
name|MAXADDRLEN
operator|-
literal|1
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
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
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
operator|(
name|MAXADDRLEN
operator|-
literal|1
operator|)
operator|||
name|top
operator|<
operator|(
name|MINADDRLEN
operator|-
literal|1
operator|)
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
operator|(
name|void
operator|)
name|strncpy
argument_list|(
operator|(
name|char
operator|*
operator|)
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
name|MAXADDRLEN
operator|-
literal|1
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
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
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
literal|'D'
case|:
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
name|trtab
operator|.
name|func
operator|=
literal|'D'
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
operator|(
name|void
operator|)
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
operator|(
name|void
operator|)
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
literal|"%s ==> %01.16s\n"
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
comment|/*  *	Send ioctl for gathered -o options.  *	Presently (08-31-87) the -o option supports only  *	one byte of options.  If the number of firmware  *	supported options reaches 9, then a second byte  *	will be used.  The driver must be modified if a  *	second byte is used.  The value of PKT_OPTIONS  *	must be changed from 0x77 to 0xB7 to notify the  *	FE that PKT_OPTIONS is a 2-Byte Valued ID.  */
if|if
condition|(
name|o_flag
condition|)
block|{
comment|/* send ioctl for gathered options */
name|ddactl
operator|.
name|func
operator|=
literal|'o'
expr_stmt|;
name|ddactl
operator|.
name|msg
index|[
literal|0
index|]
operator|=
name|option_byte1
expr_stmt|;
operator|(
name|void
operator|)
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
comment|/*  *	if simulation, simply return to main loop of test jig  */
ifndef|#
directive|ifndef
name|SIMULATION
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
comment|/*  Call:            setifaddr(addr)                                  */
end_comment

begin_comment
comment|/*  Arguments:       addr:   internet address                         */
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
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|addr
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
operator|(
name|void
operator|)
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
decl_stmt|,
ifdef|#
directive|ifdef
name|VAXVMS
modifier|*
name|_gethtbyname
argument_list|()
decl_stmt|;
else|#
directive|else
else|VAXVMS
operator|*
name|gethostbyname
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|VAXVMS
name|struct
name|netent
modifier|*
name|np
decl_stmt|;
name|int
name|val
decl_stmt|;
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
ifdef|#
directive|ifdef
name|VAXVMS
name|hp
operator|=
name|_gethtbyname
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* Use host table, not name server */
else|#
directive|else
else|VAXVMS
ifdef|#
directive|ifdef
name|SIMULATION
name|hp
operator|=
literal|0
expr_stmt|;
comment|/* don't find our address by host name */
else|#
directive|else
else|SIMULATION
name|hp
operator|=
name|gethostbyname
argument_list|(
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|SIMULATION
endif|#
directive|endif
endif|VAXVMS
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
operator|(
name|int
operator|)
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
operator|(
name|void
operator|)
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
name|NEW_DELAY
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
literal|"Usage: acpconfig interface [address] [-A filename] [-a ipaddr x25addr]\n\ \t[-b baud] [-c msgnum] [-d ipaddr] [-D] [-e size] [-f facility status]\n\ \t[-h mode[r]] [-l] [-m message] [-n circuits] [-o option]\n\ \t[-q type] [-r count] [-s X.25_service] [-t secs]\n\ \t[-u mode] [-v variable value] [-z]\n"
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
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig generation %s\n"
argument_list|,
name|VERSION
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
comment|/*%%                   LONG_USAGE()                                 %%*/
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
comment|/*      This routine is called when no arguments are passed to        */
end_comment

begin_comment
comment|/*      acpconfig, this generally indicates that the user want to see */
end_comment

begin_comment
comment|/*      the usage line as opposed to making a mistake in the          */
end_comment

begin_comment
comment|/*      arguments                                                     */
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
name|longusemsg
init|=
literal|"Usage: acpconfig interface [address] \n\ [-a ipaddr x25addr]  : add a single IP to X.25 address translation (PDN only)\n\ [-A filename]        : read IP to X.25 addr translations from file (PDN only)\n\ [-b baud]            : set baud rate to baud. 0 designates external clocking\n\ [-c msgnum]          : enable/disable driver console message\n\ [-d ipaddr]          : delete an IP to X.25 translation (PDN only)\n\ [-D]                 : delete all IP to X.25 translations (PDN only)\n\ [-e size]            : set front-end buffer size\n\ [-f facility status] : control initiation of flow control negotiation\n\                        status is \"on\" or \"off\"; facility is \"packet\" or\n\                        \"window\"\n\ [-h mode[r]]         : print statistics on logical circuit usage\n\                        mode is 0 (read) or 1 (read and reset); \"r\"\n\                        specifies raw mode\n\ [-l[n]]              : display status of each active logical channel\n\ 		       the optional \"n\" argument will cause acpconfig\n\ [-m message]         : send specified supervisor message\n\ [-n circuits]        : set number of virtual circuits\n\ [-N net]             : set network type;  values for net are one of:\n\                        transpac - the French Transpac network\n\                        net15    - any network using 15 digit addresses\n\                        default  - standard network configuration\n\ [-o option]          : set or disable extended clear handling; option is\n\                        \"extended\" or \"none\"\n\ [-q type]            : query driver or front end status; type is 0 for\n\                        front end, 1 for driver\n\ [-r count]           : read and print address translation table; count\n\                        is number of translations to read; 0 means all\n\ [-s X.25_service]    : specify DDN standard, DDN basic or PDN service;\n\                        X.25_service is: \"standard\", \"basic\" or \"pdn\"\n\ [-t secs]            : set the idle circuit timeout to secs seconds\n\ [-u mode]            : set interface mode to:\n\                        down - disable interface\n\                        dte  - online as DTE\n\                        dce  - online as DCE\n\                        ext  - external loopback\n\                        int  - internal loopback\n\ [-v variable value]  : set driver variable; variable/values are one of:\n\                        packet DDD - set X.25 packet size to DDD decimal\n\                        window DDD - set X.25 window size to DDD decimal\n\ [-z]                 : reset the board\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|long_usage
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|longusemsg
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\nacpconfig generation %s\n"
argument_list|,
name|VERSION
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
literal|"Operation not supported by this version of the firmware.\n"
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
comment|/*  * from SAGE::PROJECT:[X25.ACP5250W.HCOMMON]NCP.H on  */
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
comment|/*  * A long time ago in a UNIBUS far, far away, there was a Z80 based  * front end processor happily talking to its PDP-11 host.  They  * exchanged many cheerful messages, some of which were statistics  * queries.  The statistics query was defined in the only logical  * format, the format shared by both the Z80 and its PDP-11 host.  * Well, thousands of computer generations passed, and the little  * Z80 grew up into a big, strong 68000 based front end.  His  * friendly little PDP-11 host grew up too, into a big honkin'  * VAX.  They still liked to exchange cheerful messages, though,  * and some of those were still the same well-worn statistics  * queries, which are still in the only "logical" data format.  * So don't ask again why a VAX and a 68000 exchange data in Z80  * byte ordering!  */
end_comment

begin_define
define|#
directive|define
name|z80toVAX
parameter_list|(
name|l
parameter_list|)
value|(((l)<< 16) | (((l)>> 16)& 0xFFFF))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU__
end_ifdef

begin_comment
comment|/* gnu compiler prefers ANSII C */
end_comment

begin_define
define|#
directive|define
name|pr
parameter_list|(
name|A
parameter_list|)
value|printf("%-10s%10d%10d\n", #A, sp->A##_sent, sp->A##_rcvd)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* idiot compiler */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * internal routines for use by query commands  */
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
operator|(
name|void
operator|)
name|gettimeofday
argument_list|(
operator|&
name|t
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ctime
argument_list|(
operator|&
name|t
operator|.
name|tv_sec
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
operator|.
name|tv_sec
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
operator|.
name|tv_sec
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
operator|(
name|u_char
operator|)
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
literal|"<DDN_STANDARD>\n"
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
literal|"<DDN_BASIC>\n"
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
literal|"<PDN>\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|&
literal|0x40
condition|)
name|printf
argument_list|(
literal|"\t<Packet Size Facility Negotiation Initiation Enabled>\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|buf
operator|&
literal|0x80
condition|)
name|printf
argument_list|(
literal|"\t<Window Size Facility Negotiation Initiation Enabled>\n"
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

begin_macro
name|fmtsilo
argument_list|(
argument|buf
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
literal|256
condition|;
name|j
operator|+=
literal|16
control|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"%02x "
argument_list|,
name|buf
index|[
name|j
operator|+
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
name|putchar
argument_list|(
name|isalpha
argument_list|(
name|buf
index|[
name|j
operator|+
name|i
index|]
argument_list|)
condition|?
name|buf
index|[
name|j
operator|+
name|i
index|]
else|:
literal|'.'
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
empty_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* print out data from the histogram request */
end_comment

begin_function
name|double
name|tval_dbl
parameter_list|(
name|tv
parameter_list|)
name|struct
name|timeval
modifier|*
name|tv
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|double
operator|)
name|tv
operator|->
name|tv_sec
operator|+
operator|(
name|double
operator|)
name|tv
operator|->
name|tv_usec
operator|/
operator|(
name|double
operator|)
literal|1000000.0
operator|)
return|;
block|}
end_function

begin_macro
name|hist_data_out
argument_list|(
argument|times
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeval
name|times
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|double
name|percents
index|[
name|HISTSIZE
index|]
decl_stmt|;
name|double
name|totaltime
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|p1
decl_stmt|;
name|totaltime
operator|=
name|tval_dbl
argument_list|(
name|times
operator|+
name|H_END
argument_list|)
operator|-
name|tval_dbl
argument_list|(
name|times
operator|+
name|H_START
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|H_LINK_UP
condition|;
name|i
operator|++
control|)
name|percents
index|[
name|i
index|]
operator|=
name|tval_dbl
argument_list|(
name|times
operator|+
name|i
argument_list|)
operator|/
name|totaltime
expr_stmt|;
name|p1
operator|=
name|p
operator|=
name|ctime
argument_list|(
operator|&
name|times
index|[
name|H_START
index|]
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\n'
condition|)
operator|*
name|p
operator|=
literal|' '
expr_stmt|;
operator|*
name|p
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"START: %s"
argument_list|,
name|p1
argument_list|)
expr_stmt|;
name|p1
operator|=
name|p
operator|=
name|ctime
argument_list|(
operator|&
name|times
index|[
name|H_END
index|]
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
literal|'\n'
condition|)
operator|*
name|p
operator|=
literal|' '
expr_stmt|;
operator|*
name|p
operator|++
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\t\tEND: %s\n"
argument_list|,
name|p1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"total time: %6.2f seconds"
argument_list|,
name|totaltime
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\ttime up: %ld seconds (%3.2f%%)\n"
argument_list|,
name|times
index|[
name|H_LINK_UP
index|]
operator|.
name|tv_sec
argument_list|,
name|percents
index|[
name|H_LINK_UP
index|]
operator|*
literal|100.0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"idle circuit timeout: %ld seconds\n"
argument_list|,
name|times
index|[
name|H_TMO
index|]
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|H_LINK_UP
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|percents
index|[
name|i
index|]
operator|<=
literal|0.0
condition|)
continue|continue;
name|printf
argument_list|(
literal|"%3d %6.2f\n"
argument_list|,
name|i
argument_list|,
name|percents
index|[
name|i
index|]
operator|*
literal|100.0
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Revision History:	  9-AUG-1987	Steph Price	V2.3 	Add new -f option for controlling the initiation of flow control 	parameter negotiation.  The default in the driver is no flow 	control parameter negotiation initiation.  To turn on packet or window 	size negotiation initiation, issue the new acpconfig commands: 		-f packet on 		-f window on 	To turn off initiation: 		-f packet off 		-f window off 	Note that these options are valid only on a per call basis.  If a 	circuit is already open for the requested destination, the status of 	flow control parameter negotiation initiation can't be altered until 	the circuit is cleared either by timing out or by a reset.  	Add "external" argument to the -b option. 	Add new arguments to the -s option.  They are as follows: 		-s standard (equivalent to -s 0) 		-s basic (equivalent to -s 1) 		-s pdn (equivalent to -s 2) 	SERVICE_VAL was modified to accomodate the new arguments. 	Previously the driver expected arguments of s, t, and u to be 	passed for the -s 0, -s 1, and -s 2 options.  Since an argument of v 	is already in use, use of the -s0/standard option will result in the 	use of 'S' as an argument to the driver's ioctl routine. 	Similarly, 'T', 'U', and 'V' will be passed for the -s1/basic, 	-s2/pdn, and -s3/class_b_c options.  	Add the -o option to enable root to select extended clear and extended 	clear confirmation packets as the first step toward X.25 1984 	compatability.  	Add the -l option to enable root to display the status of each active 	lcn.  	Modify reset case to check for returned value before printing a message 	saying that a reset is in progress.  	Fix bug in -n case.  The interface was not given.  25-OCT-87	Stephanie Price 	Modified -l option to used /dev/kmem instead of /dev/mem.  Removed 	mask of high order bit in klseek() routine. 6-NOV-87	Brad Engstrom 	Add -D flag 11-NOV-87	Brad Engstrom 	Add -h and -H histogram flags 18-NOV-87	Brad Engstrom 	Changed -A option handling so that acpconfig does not exit upon seeing 	an address already in use error. 18-DEC-87	Brad Engstrom 	Added -t options to set the idle circuit timeout value to a certain 	number of seconds. 21-APR-88	Brad Engstrom 	Added the -v dbgunit option to the -v flag to set the debug unit 	variable in the driver. 22-APR-88	Brad Engstrom 	Added the -c command to enable or disable driver console messages.  Each 	use of the command for a particular message will toggle the message 	status. 26-APR-88	Brad Engstrom 	Modified the -n command so that a command of the form "-n 0" will 	print the number of circuits currently available.  Also the -l 	command uses this information to print the number of circuits free. 	This allows the new driver to work with old firmware easier. 10-MAY-88	Brad Engstrom 	Made all references to the length of an X.25 address refer to theo 	constants MAXADDRLEN and MINADDRLEN which are defined in if_ddavar.h. 26-JAN-89	Steve Johnson 	Added -N option to support TRANSPAC net. 	Merged in extra TWG support. 15-FEB-89	Paul Traina 	Fixed bug with -N command parsing. 	Implemented an improved form of Brad's changes for Transpac. 17-FEB-89	Paul Traina 	Installed Multinet support. 10-MAR-89	Paul Traina 	Installed simulation support. 13-MAR-89	Paul Traina 	Installed support for undocumented -q 2 command. 31-MAY-89	Paul Traina 	Updated command parsing on -u fixed documentation. 20-JUN-89	Paul Traina 	Obsoleted -v debug and -v dbg_unit commands.  New driver is *NOT* 	compatible with the old crufty debugging format. 26-JUN-89	Paul Traina 	Removed the tolower()'s on -u and -N arguments. 	Reinstalled Charles' changes to 3.1 acpconfig for -ln 	Fixed things so -h w/o an argument doesn't core. 19-Jul-89	Paul Traina 	Changed version date id due to incompatible changes in the dc 	structure located in if_ddavar.h 13-Nov-89	Paul Traina 	Changed query ioctl interface.  Incompatible with old drivers.  End of Revision History */
end_comment

end_unit

