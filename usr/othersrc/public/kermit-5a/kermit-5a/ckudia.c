begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|dialv
init|=
literal|"Dial Command, 5A(028) 23 Dec 91"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U D I A	 --  Dialing program for connection to remote system */
end_comment

begin_comment
comment|/*   Original author: Herm Fischer (HFISCHER@USC-ECLB).   Contributed to Columbia University for inclusion in C-Kermit.   Copyright (C) 1985, Herman Fischer, 16400 Ventura Blvd, Encino CA 91436, and   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University.   Os9/68k and Microcom modem support by Bob Larson (Blarson@ecla.usc.edu)  Additional code by many others over the years.   ------   This module should work under all versions of Unix.  It calls externally  defined system-depended functions for i/o, but depends upon the existence  of various modem control functions.   This module, and the supporting routines in the ckutio.c module, assume  that the computer and modem properly utilize the following data communi-  cations signals (that means one should prepare the modem to use, not  circumvent, these signals):       Data Terminal Ready (DTR):  This signal is asserted by the computer      when Kermit is about to ask the modem to dial a call, and is      removed when Kermit wishes to have the modem hang up a call.      The signal is asserted both while Kermit is asking the modem      to dial a specific number, and after connection, while Kermit      is in a data exchange mode.       Carrier Detect (CD):  This signal must be asserted by the modem when      a carrier is detected from a remote modem on a communications      circuit.  It must be removed by the modem when the circuit      disconnects or is hung up.	 (Carrier Detect is ignored while      Kermit is asking the modem to dial the call, because there is      no consistant usage of this signal during the dialing phase      among different modem manufacturers.) */
end_comment

begin_comment
comment|/*  * Modifications:  *  *	21-Jul-85	Fixed failure returns hanging on no carrier signal  *			Requires tthang change too (ckutio.c revision)  *							-- Herm Fischer  *  *	28-Jun-85	Fixed bug with defaulting the modem-failure message  *			in lbuf.  *							-- Dan Schullman  *  *	27-Jun-85	Merged in code from Joe Orost at Berkeley for  *			supporting the US Robotics modem, which included  *			changing the single characters in MDMINF into  *			multi-character strings and modifying waitfor.  *							-- Dan Schullman  *  *	26-Jun-85	Allow interrupts to be used to abort dialing,  *			and ring the bell when a connection is made.  *			Reorganized some of the failure paths to use the  *			same code, and now close the line on failures.  *			Allow use of stored numbers with the DF100 and  *			DF200 modems.  Handlers now declared after the  *			call to setjmp.  *							-- Dan Schullman  *  *	24-May-85	DF03, DF100-series, DF200-series, and "unknown" modem  *			support added.	Also restructured the various data  *			tables, fixed some bugs related to missing data and  *			missing case labels, and modified the failure message  *			to display the "reason" given by the modem.  *							-- Dan Schullman  *	16-Mar-87	Support for the ATT7300 UNIX PC internal modem was  *			added.  *							-- Richard E. Hill  *  *	21-Feb-88	Os9/68k and microcom modem support.  *							-- Bob Larson  *  *	14-Mar-88	Rewrite code for ATT7300 (here and in ckutio.c)  *			Avoids dial(3c) with it's LCK files, hangs up line  *			correctly, enables user interrupts and timeouts,  *			turns on/off the system getty() login procedure.  *			Correct Hayes command sequence at little.  *			Procedures: attdial, atthang, ongetty, offgetty.  *			Parts adapted from work of Richard E. Hill and  *			Kevin O'Gorman.  *							-- Joe R. Doupnik  *  *      13-Jan-89       Added IBM/Siemens/Rolm CBX dialing support.  *                      - F. da Cruz  *  *	29-Aug-89	Added support for AT&T 2212C, 2224B, 2224CEO, and  *			2296A switched-network modems in AT&T mode, and  *			for the AT&T Digital Terminal Data Module (DTDM).  *							-- Eric F. Jones  *  *       4-Jun-90       Added delay on "ANSWERED" for AT&T DTDM  *       7-Jun-90       Added support for AT&T ISN Network  *                      - John L. Chmielewski, AT&T  *  *       March 1991     Support for Telebit modems, Kermit spoofing.  *                      Warren Tucker, Larry Jacobs, Frank da Cruz.  */
end_comment

begin_comment
comment|/*  * To add support for another modem, do the following:  *  *	Define a modem number symbol (n_XXX) for it, keeping the list  *	in alphabetical and numerical order, and renumbering the values  *	as necessary.  Make sure the n_XXX symbol is unique within 7 chars.  *  *	Create a MDMINF structure for it, again keeping the list alphabetical  *	for sanity's sake.  *  *	Add the address of the MDMINF structure to the ptrtab array, again  *	in alphabetical and numerical order.  *  *	Add the "user visible" modem name and corresponding modem number to  *	the mdmtab array, again in alphabetical order.  *  *	Read through the code and add modem-specific sections as necessary.  */
end_comment

begin_comment
comment|/*  * The intent of the "unknown" modem is hopefully to allow KERMIT to support  * unknown modems by having the user type the entire autodial sequence  * (possibly including control characters, etc.) as the "phone number".  * The only reason that the CONNECT command cannot be used to do this is  * that a remote line cannot normally be opened unless carrier is present.  *  * The protocol and other characteristics of this modem are unknown, with  * some "reasonable" values being chosen for some of them.  The only way to  * detect if a connection is made is to look for carrier present.  */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_include
include|#
directive|include
file|"ckucmd.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ZILOG
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* Longjumps */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<setret.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZILOG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|signal
value|msignal
end_define

begin_define
define|#
directive|define
name|SIGTYP
value|long
end_define

begin_define
define|#
directive|define
name|alarm
value|malarm
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|0
end_define

begin_define
define|#
directive|define
name|SIGALRM
value|1
end_define

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_expr_stmt
name|SIGTYP
argument_list|(
operator|*
name|msignal
argument_list|(
argument|int type
argument_list|,
argument|SIGTYP (*func)(int)
argument_list|)
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flow
decl_stmt|,
name|local
decl_stmt|,
name|mdmtyp
decl_stmt|,
name|quiet
decl_stmt|,
name|parity
decl_stmt|,
name|seslog
decl_stmt|,
name|network
decl_stmt|,
name|dialhng
decl_stmt|,
name|dialdpy
decl_stmt|,
name|mdmspd
decl_stmt|,
name|dialtmo
decl_stmt|,
name|dialksp
decl_stmt|,
name|dialmnp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dialini
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CHAR
name|stchr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ttname
index|[]
decl_stmt|,
name|sesfil
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Failure reasons for use with the 'longjmp' exit.  */
end_comment

begin_define
define|#
directive|define
name|F_time
value|1
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|F_int
value|2
end_define

begin_comment
comment|/* interrupt */
end_comment

begin_define
define|#
directive|define
name|F_modem
value|3
end_define

begin_comment
comment|/* modem-detected failure */
end_comment

begin_define
define|#
directive|define
name|F_minit
value|4
end_define

begin_comment
comment|/* cannot initialize modem */
end_comment

begin_decl_stmt
specifier|static
name|int
name|mymdmtyp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local copy of modem type. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|n1
init|=
name|F_time
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_define
define|#
directive|define
name|MDMINF
value|struct mdminf
end_define

begin_macro
name|MDMINF
end_macro

begin_comment
comment|/* structure for modem-specific information */
end_comment

begin_block
block|{
name|int
name|dial_time
decl_stmt|;
comment|/* time modem allows for dialing (secs) */
name|char
modifier|*
name|pause_chars
decl_stmt|;
comment|/* character(s) to tell modem to pause */
name|int
name|pause_time
decl_stmt|;
comment|/* time associated with pause chars (secs) */
name|char
modifier|*
name|wake_str
decl_stmt|;
comment|/* string to wakeup modem& put in cmd mode */
name|int
name|wake_rate
decl_stmt|;
comment|/* delay between wake_str characters (msecs) */
name|char
modifier|*
name|wake_prompt
decl_stmt|;
comment|/* string prompt after wake_str */
name|char
modifier|*
name|dmode_str
decl_stmt|;
comment|/* string to put modem in dialing mode */
name|char
modifier|*
name|dmode_prompt
decl_stmt|;
comment|/* string prompt for dialing mode */
name|char
modifier|*
name|dial_str
decl_stmt|;
comment|/* dialing string, with "%s" for number */
name|int
name|dial_rate
decl_stmt|;
comment|/* delay between dialing characters (msecs) */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Define symbolic modem numbers.  *  * The numbers MUST correspond to the ordering of entries  * within the ptrtab array, and start at one (1).  *  * It is assumed that there are relatively few of these  * values, and that the high(er) bytes of the value may  * be used for modem-specific mode information.  *  * REMEMBER that only the first eight characters of these  * names are guaranteed to be unique.  */
end_comment

begin_define
define|#
directive|define
name|n_ATTDTDM
value|1
end_define

begin_define
define|#
directive|define
name|n_ATTISN
value|2
end_define

begin_define
define|#
directive|define
name|n_ATTMODEM
value|3
end_define

begin_define
define|#
directive|define
name|n_CERMETEK
value|4
end_define

begin_define
define|#
directive|define
name|n_DF03
value|5
end_define

begin_define
define|#
directive|define
name|n_DF100
value|6
end_define

begin_define
define|#
directive|define
name|n_DF200
value|7
end_define

begin_define
define|#
directive|define
name|n_GDC
value|8
end_define

begin_define
define|#
directive|define
name|n_HAYES
value|9
end_define

begin_define
define|#
directive|define
name|n_PENRIL
value|10
end_define

begin_define
define|#
directive|define
name|n_RACAL
value|11
end_define

begin_define
define|#
directive|define
name|n_UNKNOWN
value|12
end_define

begin_define
define|#
directive|define
name|n_USROBOT
value|13
end_define

begin_define
define|#
directive|define
name|n_VENTEL
value|14
end_define

begin_define
define|#
directive|define
name|n_CONCORD
value|15
end_define

begin_define
define|#
directive|define
name|n_ATTUPC
value|16
end_define

begin_comment
comment|/* aka Unix PC and ATT7300 */
end_comment

begin_define
define|#
directive|define
name|n_ROLM
value|17
end_define

begin_comment
comment|/* Rolm CBX DCM */
end_comment

begin_define
define|#
directive|define
name|n_MICROCOM
value|18
end_define

begin_define
define|#
directive|define
name|n_HST
value|19
end_define

begin_define
define|#
directive|define
name|n_TELEBIT
value|20
end_define

begin_comment
comment|/* Telebit Trailblazer */
end_comment

begin_define
define|#
directive|define
name|MAX_MDM
value|20
end_define

begin_comment
comment|/*  * Declare modem "variant" numbers for any of the above for which it is  * necessary to note various operational modes, using the second byte  * of a modem number.  *  * It is assumed that such modem modes share the same modem-specific  * information (see MDMINF structure) but may differ in some of the actions  * that are performed.  */
end_comment

begin_comment
comment|/*  Warning - this is starting to get kind of hokey... */
end_comment

begin_define
define|#
directive|define
name|DIAL_NV
value|256
end_define

begin_define
define|#
directive|define
name|DIAL_PEP
value|512
end_define

begin_define
define|#
directive|define
name|DIAL_V32
value|1024
end_define

begin_define
define|#
directive|define
name|DIAL_V42
value|2048
end_define

begin_define
define|#
directive|define
name|DIAL_SLO
value|4096
end_define

begin_define
define|#
directive|define
name|n_HAYESNV
value|( n_HAYES   | DIAL_NV )
end_define

begin_define
define|#
directive|define
name|n_TBPEP
value|( n_TELEBIT | DIAL_PEP )
end_define

begin_define
define|#
directive|define
name|n_TB3
value|( n_TELEBIT | DIAL_V32 )
end_define

begin_define
define|#
directive|define
name|n_TBNV
value|( n_TELEBIT | DIAL_NV )
end_define

begin_define
define|#
directive|define
name|n_TBPNV
value|( n_TELEBIT | DIAL_NV | DIAL_PEP )
end_define

begin_define
define|#
directive|define
name|n_TB3NV
value|( n_TELEBIT | DIAL_NV | DIAL_V32 )
end_define

begin_define
define|#
directive|define
name|n_TB4
value|( n_TELEBIT | DIAL_V42 )
end_define

begin_define
define|#
directive|define
name|n_TBS
value|( n_TELEBIT | DIAL_SLO )
end_define

begin_define
define|#
directive|define
name|n_TB4NV
value|( n_TELEBIT | DIAL_NV | DIAL_V42 )
end_define

begin_define
define|#
directive|define
name|n_TBSNV
value|( n_TELEBIT | DIAL_NV | DIAL_SLO )
end_define

begin_comment
comment|/*  * Declare structures containing modem-specific information.  *  * REMEMBER that only the first SEVEN characters of these  * names are guaranteed to be unique.  */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|ATTISN
init|=
comment|/* AT&T ISN Network */
block|{
literal|30
block|,
comment|/* Dial time */
literal|""
block|,
comment|/* Pause characters */
literal|0
block|,
comment|/* Pause time */
literal|"\015\015\015\015"
block|,
comment|/* Wake string */
literal|900
block|,
comment|/* Wake rate */
literal|"DIAL"
block|,
comment|/* Wake prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|ATTMODEM
init|=
comment|/* information for AT&T switched-network modems */
comment|/* "Number" following "dial" can include: p's and 			 * t's to indicate pulse or tone (default) dialing, 			 * + for wait for dial tone, , for pause, r for 			 * last number dialed, and, except for 2224B, some 			 * comma-delimited options like o12=y, before number.   * "Important" options for the modems:  *  *	All:		Except for 2224B, enable option 12 for "transparent  *			data," o12=y.  If a computer port used for both  *			incoming and outgoing calls is connected to the  *			modem, disable "enter interactive mode on carriage  *			return," EICR.  The Kermit "dial" command can  *			function with EIA leads standard, EIAS.  *  *	2212C:		Internal hardware switches at their default  *			positions (four rockers down away from numbers)  *			unless EICR is not wanted (rocker down at the 4).  *			For EIAS, rocker down at the 1.  *  *	2224B:		Front-panel switch position 1 must be up (at the 1,  *			closed).  Disable EICR with position 2 down.  *			For EIAS, position 4 down.  *			All switches on the back panel down.  *  *	2224CEO:	All front-panel switches down except either 5 or 6.  *			Enable interactive flow control with o16=y.  *			Select normal asynchronous mode with o34=0 (zero).  *			Disable EICR with position 3 up.  For EIAS, 1 up.  *			Reset the modem after changing switches.  *  *	2296A:		If option 00 (zeros) is present, use o00=0.  *			Enable interactive flow control with o16=y.  *			Select normal asynchronous mode with o34=0 (zero).  *                      (available in Microcom Networking version, but  *                      not necessarily other models of the 2296A).  *			Enable modem-port flow control (if available) with  * 			o42=y.  Enable asynchronous operation with o50=y.  * 			Disable EICR with o69=n.  For EIAS, o66=n, using  * 			front panel.  */
block|{
literal|20
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"+"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"at%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|ATTDTDM
init|=
comment|/* information for AT&T Digital Terminal Data Module  *			For dialing: KYBD switch down, others usually up. */
block|{
literal|20
block|,
comment|/* dial_time */
literal|""
block|,
comment|/* pause_chars */
literal|0
block|,
comment|/* pause_time */
literal|""
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
comment|/* not used */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|CERMETEK
init|=
comment|/* information for "Cermetek Info-Mate 212 A" modem */
block|{
literal|20
block|,
comment|/* dial_time */
literal|"BbPpTt"
block|,
comment|/* pause_chars */
literal|0
block|,
comment|/* pause_time */
comment|/** unknown -- DS **/
literal|"  XY\016R\015"
block|,
comment|/* wake_str */
literal|200
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"\016D '%s'\015"
block|,
comment|/* dial_str */
literal|200
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|DF03
init|=
comment|/* information for "DEC DF03-AC" modem */
block|{
literal|27
block|,
comment|/* dial_time */
literal|"="
block|,
comment|/* pause_chars */
comment|/* wait for second dial tone */
literal|15
block|,
comment|/* pause_time */
literal|"\001\002"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"%s"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|DF100
init|=
comment|/* information for "DEC DF100-series" modem */
comment|/* 			 * The telephone "number" can include "P"s and/or "T"s 			 * within it to indicate that subsequent digits are 			 * to be dialed using pulse or tone dialing.  The 			 * modem defaults to pulse dialing.  You may modify 			 * the dial string below to explicitly default all 			 * dialing to pulse or tone, but doing so prevents 			 * the use of phone numbers that you may have stored 			 * in the modem's memory. 			 */
block|{
literal|30
block|,
comment|/* dial_time */
literal|"="
block|,
comment|/* pause_chars */
comment|/* wait for second dial tone */
literal|15
block|,
comment|/* pause_time */
literal|"\001"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"%s#"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|DF200
init|=
comment|/* information for "DEC DF200-series" modem */
comment|/* 			 * The telephone "number" can include "P"s and/or "T"s 			 * within it to indicate that subsequent digits are 			 * to be dialed using pulse or tone dialing.  The 			 * modem defaults to pulse dialing.  You may modify 			 * the dial string below to explicitly default all 			 * dialing to pulse or tone, but doing so prevents 			 * the use of phone numbers that you may have stored 			 * in the modem's memory. 			 */
block|{
literal|30
block|,
comment|/* dial_time */
literal|"=W"
block|,
comment|/* pause_chars */
comment|/* =: second tone; W: 5 secs */
literal|15
block|,
comment|/* pause_time */
comment|/* worst case */
literal|"\002"
block|,
comment|/* wake_str */
comment|/* allow stored number usage */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"%s!"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|GDC
init|=
comment|/* information for "GeneralDataComm 212A/ED" modem */
block|{
literal|32
block|,
comment|/* dial_time */
literal|"%"
block|,
comment|/* pause_chars */
literal|3
block|,
comment|/* pause_time */
literal|"\015\015"
block|,
comment|/* wake_str */
literal|500
block|,
comment|/* wake_rate */
literal|"$"
block|,
comment|/* wake_prompt */
literal|"D\015"
block|,
comment|/* dmode_str */
literal|":"
block|,
comment|/* dmode_prompt */
literal|"T%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|HAYES
init|=
comment|/* information for "Hayes" modem */
block|{
literal|35
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"AT\015"
block|,
comment|/* wake_str */
comment|/*   Note: Other wake_str's are possible here.  For Hayes 2400 that is to   be used for both in and out calls, AT&F&D3 might be best.  For out calls   only, maybe AT&F&D2.  See Hayes 2400 manual. */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"ATD%s\015"
block|,
comment|/* dial_str, note: user can supply D or T */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|PENRIL
init|=
comment|/* information for "Penril" modem */
block|{
literal|50
block|,
comment|/* dial_time */
literal|""
block|,
comment|/* pause_chars */
comment|/** unknown -- HF **/
literal|0
block|,
comment|/* pause_time */
literal|"\015\015"
block|,
comment|/* wake_str */
literal|300
block|,
comment|/* wake_rate */
literal|">"
block|,
comment|/* wake_prompt */
literal|"k\015"
block|,
comment|/* dmode_str */
literal|":"
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|RACAL
init|=
comment|/* information for "Racal Vadic" modem */
block|{
literal|35
block|,
comment|/* dial_time */
literal|"Kk"
block|,
comment|/* pause_chars */
literal|5
block|,
comment|/* pause_time */
literal|"\005\015"
block|,
comment|/* wake_str */
literal|50
block|,
comment|/* wake_rate */
literal|"*"
block|,
comment|/* wake_prompt */
literal|"D\015"
block|,
comment|/* dmode_str */
literal|"?"
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|UNKNOWN
init|=
comment|/* information for "Unknown" modem */
block|{
literal|30
block|,
comment|/* dial_time */
literal|""
block|,
comment|/* pause_chars */
literal|0
block|,
comment|/* pause_time */
literal|""
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|USROBOT
init|=
comment|/* information for "US Robotics 212A" modem */
block|{
literal|30
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"ATS2=01\015"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|"OK\015"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"ATTD%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* Reportedly this does not work at all. */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|VENTEL
init|=
comment|/* information for "Ventel" modem */
block|{
literal|20
block|,
comment|/* dial_time */
literal|"%"
block|,
comment|/* pause_chars */
literal|5
block|,
comment|/* pause_time */
literal|"\015\015\015"
block|,
comment|/* wake_str */
literal|300
block|,
comment|/* wake_rate */
literal|"$"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"<K\015%s\015>"
block|,
comment|/* dial_str (was "<K%s\r>") */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* and this does. */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|VENTEL
init|=
comment|/* information for "Ventel" modem */
block|{
literal|20
block|,
comment|/* dial_time */
literal|"%"
block|,
comment|/* pause_chars */
literal|5
block|,
comment|/* pause_time */
literal|"\015\015\015"
block|,
comment|/* wake_str */
literal|300
block|,
comment|/* wake_rate */
literal|"$"
block|,
comment|/* wake_prompt */
literal|"K\015"
block|,
comment|/* dmode_str (was "") */
literal|"Number to call: "
block|,
comment|/* dmode_prompt (was NULL) */
literal|"%s\015"
block|,
comment|/* dial_str (was "<K%s\r>") */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|CONCORD
init|=
comment|/* Info for Condor CDS 220 2400b modem */
block|{
literal|35
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"\015\015"
block|,
comment|/* wake_str */
literal|20
block|,
comment|/* wake_rate */
literal|"CDS>"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"<D M%s\015>"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|ATTUPC
init|=
comment|/* dummy information for "ATT7300/Unix PC" internal modem */
block|{
literal|30
block|,
comment|/* dial_time */
literal|""
block|,
comment|/* pause_chars */
literal|0
block|,
comment|/* pause_time */
literal|""
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|""
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|ROLM
init|=
comment|/* IBM / Siemens / Rolm 8000, 9000, 9751 CBX */
block|{
literal|60
block|,
comment|/* dial_time */
literal|""
block|,
comment|/* pause_chars */
literal|0
block|,
comment|/* pause_time */
literal|"\015\015"
block|,
comment|/* wake_str */
literal|5
block|,
comment|/* wake_rate */
literal|"MODIFY?"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"CALL %s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|MICROCOM
init|=
comment|/* information for "Microcom" modems in native mode */
comment|/* (long answer only) */
block|{
literal|35
block|,
comment|/* dial_time */
literal|",!@"
block|,
comment|/* pause_chars (! and @ aren't pure pauses) */
literal|3
block|,
comment|/* pause_time */
literal|"\015"
block|,
comment|/* wake_str */
literal|100
block|,
comment|/* wake_rate */
literal|"!"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
name|NULL
block|,
comment|/* dmode_prompt */
literal|"d%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|HST
init|=
comment|/* information for Courier HST modem */
block|{
literal|35
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"ATE1Q0S2=43X7&B1&M4\015"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|"OK\015"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"ATD%s\015"
block|,
comment|/* dial_str */
literal|0
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|TELEBIT
init|=
comment|/* information for Telebits */
block|{
literal|60
block|,
comment|/* dial_time */
literal|","
block|,
comment|/* pause_chars */
literal|2
block|,
comment|/* pause_time */
literal|"AAAAATF1M1Q4X3S2=43\015"
block|,
comment|/* wake_str */
literal|10
block|,
comment|/* wake_rate */
literal|"OK\015"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"ATD%s\015"
block|,
comment|/* dial_str */
literal|80
comment|/* dial_rate */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * Declare table for converting modem numbers to information pointers.  *  * The entries MUST be in ascending order by modem number, without any  * "gaps" in the numbers, and starting from one (1).  *  * This table should NOT include entries for the "variant" modem numbers,  * since it is assumed that they share the same information as the normal  * value.  */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
modifier|*
name|ptrtab
index|[]
init|=
block|{
operator|&
name|ATTDTDM
block|,
operator|&
name|ATTISN
block|,
operator|&
name|ATTMODEM
block|,
operator|&
name|CERMETEK
block|,
operator|&
name|DF03
block|,
operator|&
name|DF100
block|,
operator|&
name|DF200
block|,
operator|&
name|GDC
block|,
operator|&
name|HAYES
block|,
operator|&
name|PENRIL
block|,
operator|&
name|RACAL
block|,
operator|&
name|UNKNOWN
block|,
operator|&
name|USROBOT
block|,
operator|&
name|VENTEL
block|,
operator|&
name|CONCORD
block|,
operator|&
name|ATTUPC
block|,
comment|/* ATT7300 internal modem, jrd*/
operator|&
name|ROLM
block|,
comment|/* Rolm CBX, fdc */
operator|&
name|MICROCOM
block|,
operator|&
name|HST
block|,
operator|&
name|TELEBIT
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Declare modem names and associated numbers for command parsing,  * and also for doing number-to-name translation.  *  * The entries MUST be in alphabetical order by modem name.  */
end_comment

begin_decl_stmt
name|struct
name|keytab
name|mdmtab
index|[]
init|=
block|{
literal|"attdtdm"
block|,
name|n_ATTDTDM
block|,
literal|0
block|,
literal|"attisn"
block|,
name|n_ATTISN
block|,
literal|0
block|,
literal|"attmodem"
block|,
name|n_ATTMODEM
block|,
literal|0
block|,
literal|"att7300"
block|,
name|n_ATTUPC
block|,
literal|0
block|,
literal|"cermetek"
block|,
name|n_CERMETEK
block|,
literal|0
block|,
literal|"concord"
block|,
name|n_CONCORD
block|,
literal|0
block|,
literal|"df03-ac"
block|,
name|n_DF03
block|,
literal|0
block|,
literal|"df100-series"
block|,
name|n_DF100
block|,
literal|0
block|,
literal|"df200-series"
block|,
name|n_DF200
block|,
literal|0
block|,
literal|"direct"
block|,
literal|0
block|,
literal|0
block|,
literal|"gendatacomm"
block|,
name|n_GDC
block|,
literal|0
block|,
literal|"hayes"
block|,
name|n_HAYES
block|,
literal|0
block|,
literal|"hst-courier"
block|,
name|n_HST
block|,
literal|0
block|,
literal|"microcom"
block|,
name|n_MICROCOM
block|,
literal|0
block|,
literal|"none"
block|,
literal|0
block|,
literal|0
block|,
literal|"penril"
block|,
name|n_PENRIL
block|,
literal|0
block|,
literal|"pep-telebit"
block|,
name|n_TBPEP
block|,
literal|0
block|,
literal|"racalvadic"
block|,
name|n_RACAL
block|,
literal|0
block|,
literal|"rolm"
block|,
name|n_ROLM
block|,
literal|0
block|,
literal|"slow-telebit"
block|,
name|n_TBS
block|,
literal|0
block|,
literal|"telebit"
block|,
name|n_TELEBIT
block|,
literal|0
block|,
literal|"unknown"
block|,
name|n_UNKNOWN
block|,
literal|0
block|,
literal|"usrobotics-212a"
block|,
name|n_USROBOT
block|,
literal|0
block|,
literal|"v32-telebit"
block|,
name|n_TB3
block|,
literal|0
block|,
literal|"v42-telebit"
block|,
name|n_TB4
block|,
literal|0
block|,
literal|"ventel"
block|,
name|n_VENTEL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nmdm
init|=
operator|(
sizeof|sizeof
argument_list|(
name|mdmtab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|keytab
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of modems */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dialhup
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int getok
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|getdws
argument_list|,
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID ttslow
argument_list|,
argument|(char *s, int millisec)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID xcpy
argument_list|,
argument|(char *to, char *from, unsigned len)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID waitfor
argument_list|,
argument|(char *s)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID dialoc
argument_list|,
argument|(char c)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static int didweget
argument_list|,
argument|(char *s, char *r)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID spdchg
argument_list|,
argument|(long s)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|DIALING
value|4
end_define

begin_comment
comment|/* for ttpkt parameter */
end_comment

begin_define
define|#
directive|define
name|CONNECT
value|5
end_define

begin_define
define|#
directive|define
name|CONNECTED
value|1
end_define

begin_comment
comment|/* for completion status */
end_comment

begin_define
define|#
directive|define
name|FAILED
value|2
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|F_reason
index|[
literal|5
index|]
init|=
block|{
comment|/* failure reasons for message */
literal|"Unknown"
block|,
literal|"Timeout"
block|,
literal|"Interrupt"
block|,
literal|"Modem"
block|,
literal|"Initialize"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tries
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|mdmecho
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume modem does not echo */
end_comment

begin_decl_stmt
specifier|static
name|int
name|augmdmtyp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "augmented" modem type, to handle modem modes */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For command strings& messages */
end_comment

begin_define
define|#
directive|define
name|LBUFL
value|100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|lbuf
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|lbuf
index|[
name|LBUFL
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_decl_stmt
specifier|static
name|jmp_buf
name|sjbuf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|SIGTYP
function_decl|(
modifier|*
name|savalrm
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for saving alarm handler */
end_comment

begin_function_decl
specifier|static
name|SIGTYP
function_decl|(
modifier|*
name|savint
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for saving interrupt handler */
end_comment

begin_function
name|VOID
name|xcpy
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|len
parameter_list|)
comment|/* Copy the given number of bytes */
specifier|register
name|char
modifier|*
name|to
decl_stmt|,
decl|*
name|from
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|len
operator|--
condition|)
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
expr_stmt|;
block|}
end_block

begin_function
name|SIGTYP
name|dialtime
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* timer interrupt handler */
name|n1
operator|=
name|F_time
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_time
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|SIGTYP
name|dialint
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* user-interrupt handler */
name|n1
operator|=
name|F_int
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_int
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|VOID
name|ttslow
parameter_list|(
name|s
parameter_list|,
name|millisec
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
name|int
name|millisec
decl_stmt|;
block|{
comment|/* output s-l-o-w-l-y */
for|for
control|(
init|;
operator|*
name|s
condition|;
name|s
operator|++
control|)
block|{
name|ttoc
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
name|millisec
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Wait for a string of characters.  *  * The characters are waited for individually, and other characters may  * be received "in between".  This merely guarantees that the characters  * ARE received, and in the order specified.  */
end_comment

begin_function
specifier|static
name|VOID
name|waitfor
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|CHAR
name|c
decl_stmt|,
name|x
decl_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
operator|++
condition|)
block|{
comment|/* while more characters remain... */
do|do
block|{
comment|/* wait for the character */
name|x
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"dial waitfor got"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialdpy
condition|)
block|{
if|if
condition|(
name|x
operator|!=
name|LF
condition|)
name|conoc
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
name|CR
condition|)
name|conoc
argument_list|(
name|LF
argument_list|)
expr_stmt|;
block|}
block|}
do|while
condition|(
name|x
operator|!=
name|c
condition|)
do|;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|didweget
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|,
decl|*
name|r
decl_stmt|;
end_function

begin_block
block|{
comment|/* Looks in string s for response r */
name|int
name|lr
init|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|r
argument_list|)
decl_stmt|;
comment|/*  0 means not found, 1 means found it */
name|int
name|i
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"didweget"
argument_list|,
name|r
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" in"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
operator|-
name|lr
init|;
name|i
operator|>=
literal|0
condition|;
name|i
operator|--
control|)
if|if
condition|(
name|s
index|[
name|i
index|]
operator|==
name|r
index|[
literal|0
index|]
condition|)
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|s
operator|+
name|i
argument_list|,
name|r
argument_list|,
name|lr
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* R E S E T -- Reset alarms, etc. on exit. */
end_comment

begin_function
specifier|static
name|VOID
name|reset
parameter_list|()
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|savalrm
argument_list|)
expr_stmt|;
comment|/* restore alarm handler */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|savint
argument_list|)
expr_stmt|;
comment|/* restore interrupt handler */
block|}
end_function

begin_comment
comment|/*   Call this routine when the modem reports that it has connected at a certain   speed, giving that speed as the argument.  If the connection speed is not   the same as Kermit's current communication speed, AND the modem interface   speed is not locked (i.e. DIAL SPEED-MATCHING is not ON), then change the   device speed to the one given. */
end_comment

begin_function
specifier|static
name|VOID
name|spdchg
parameter_list|(
name|s
parameter_list|)
name|long
name|s
decl_stmt|;
block|{
name|int
name|s2
decl_stmt|;
if|if
condition|(
operator|!
name|mdmspd
condition|)
comment|/* If modem interface speed locked, */
return|return;
comment|/*  don't do this. */
if|if
condition|(
name|speed
operator|!=
name|s
condition|)
block|{
comment|/* Speeds differ? */
name|s2
operator|=
name|s
operator|/
literal|10L
expr_stmt|;
comment|/* Convert to cps expressed as int */
if|if
condition|(
name|ttsspd
argument_list|(
name|s2
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Change speed. */
name|printf
argument_list|(
literal|" Warning: speed change to %ld failed.\r\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" Speed changed to %ld.\r\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|speed
operator|=
name|s
expr_stmt|;
comment|/* Update global speed variable */
block|}
block|}
block|}
end_function

begin_comment
comment|/*   Display all characters received from modem dialer through this routine,   for consistent handling of carriage returns and linefeeds. */
end_comment

begin_function
specifier|static
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|dialoc
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|dialoc
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
block|{
comment|/* dialoc */
comment|/* Dial Output Character */
if|if
condition|(
name|dialdpy
condition|)
block|{
if|if
condition|(
name|c
operator|!=
name|LF
condition|)
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Don't echo LF */
if|if
condition|(
name|c
operator|==
name|CR
condition|)
name|conoc
argument_list|(
name|LF
argument_list|)
expr_stmt|;
comment|/* Echo CR as CRLF */
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  C K D I A L	 --  Dial up the remote system */
end_comment

begin_comment
comment|/* Returns 1 if call completed, 0 otherwise */
end_comment

begin_function
name|int
name|ckdial
parameter_list|(
name|telnbr
parameter_list|)
name|char
modifier|*
name|telnbr
decl_stmt|;
block|{
name|char
name|c
decl_stmt|,
name|c2
decl_stmt|;
name|int
name|waitct
decl_stmt|,
name|status
init|=
literal|0
decl_stmt|;
name|char
name|errmsg
index|[
literal|50
index|]
decl_stmt|,
modifier|*
name|erp
decl_stmt|;
name|MDMINF
modifier|*
name|pmdminf
decl_stmt|;
comment|/* pointer to modem-specific info */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|m
decl_stmt|,
name|n
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|pc
decl_stmt|,
modifier|*
name|ws
decl_stmt|;
name|long
name|conspd
decl_stmt|;
name|char
modifier|*
name|cptr
decl_stmt|;
name|mymdmtyp
operator|=
name|mdmtyp
expr_stmt|;
comment|/* Make local copy of modem type */
if|if
condition|(
name|network
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, 'dial' not available on network connection\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|mymdmtyp
operator|<
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set modem' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|local
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set line' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|speed
operator|<
literal|0L
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set speed' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial string"
argument_list|,
name|telnbr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Carrier no-wait can be invalidated by ckutio fun and games, jrd */
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mymdmtyp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Open, no carrier wait */
name|erp
operator|=
name|errmsg
expr_stmt|;
name|sprintf
argument_list|(
name|erp
argument_list|,
literal|"Sorry, can't open %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|errmsg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|pmdminf
operator|=
name|ptrtab
index|[
operator|(
name|mymdmtyp
operator|&
literal|0xff
operator|)
operator|-
literal|1
index|]
expr_stmt|;
comment|/* set pointer to modem info */
name|augmdmtyp
operator|=
name|mymdmtyp
expr_stmt|;
comment|/* initialize "augmented" modem type */
name|mymdmtyp
operator|&=
literal|0xff
expr_stmt|;
comment|/* major modem type */
comment|/* interdigit waits for tone dial */
if|if
condition|(
name|dialtmo
operator|<
literal|1
condition|)
block|{
comment|/* Automatic computation. */
name|waitct
operator|=
literal|1
operator|*
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|telnbr
argument_list|)
expr_stmt|;
comment|/* Compute worst case dial time */
name|waitct
operator|+=
name|pmdminf
operator|->
name|dial_time
expr_stmt|;
comment|/* dialtone + completion wait times */
for|for
control|(
name|s
operator|=
name|telnbr
init|;
operator|*
name|s
condition|;
name|s
operator|++
control|)
block|{
comment|/* add in pause characters time */
for|for
control|(
name|p
operator|=
name|pmdminf
operator|->
name|pause_chars
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
if|if
condition|(
operator|*
name|s
operator|==
operator|*
name|p
condition|)
block|{
name|waitct
operator|+=
name|pmdminf
operator|->
name|pause_time
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|augmdmtyp
operator|==
name|n_TBPEP
operator|||
name|augmdmtyp
operator|==
name|n_TBPNV
condition|)
block|{
name|waitct
operator|+=
literal|30
expr_stmt|;
comment|/* Longer connect wait for PEP call */
block|}
block|}
else|else
block|{
comment|/* User-specified timeout */
name|waitct
operator|=
name|dialtmo
expr_stmt|;
block|}
for|for
control|(
name|m
operator|=
literal|0
init|;
name|m
operator|<
name|nmdm
condition|;
name|m
operator|++
control|)
block|{
comment|/* Look up modem type. */
if|if
condition|(
name|mdmtab
index|[
name|m
index|]
operator|.
name|kwval
operator|==
name|mymdmtyp
condition|)
block|{
break|break;
block|}
block|}
name|printf
argument_list|(
literal|" Dialing %s\n"
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Device=%s, modem=%s, speed=%ld\n"
argument_list|,
name|ttname
argument_list|,
operator|(
name|m
operator|>=
name|nmdm
condition|?
literal|"unk"
else|:
name|mdmtab
index|[
name|m
index|]
operator|.
name|kwd
operator|)
argument_list|,
name|speed
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" The timeout for completing the call is %d seconds.\n"
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
name|printf
argument_list|(
ifdef|#
directive|ifdef
name|MAC
literal|" Type Command-. to cancel the dialing.\n"
argument_list|)
expr_stmt|;
else|#
directive|else
literal|" Type your interrupt character (normally ^C) to cancel the dialing.\n"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ckdial"
argument_list|,
name|ttname
argument_list|,
call|(
name|int
call|)
argument_list|(
name|speed
operator|/
literal|10L
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial timeout"
argument_list|,
literal|""
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Hang up the modem (in case it wasn't "on hook") */
end_comment

begin_comment
comment|/* But only if SET DIAL HANGUP ON... */
end_comment

begin_if
if|if
condition|(
name|dialhup
argument_list|()
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|dialhng
condition|)
block|{
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mymdmtyp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, Can't hang up tty line\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Try 'set line %s' again\n"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
block|}
end_if

begin_if
if|if
condition|(
name|augmdmtyp
operator|==
name|n_ROLM
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* Condition console terminal and communication line */
end_comment

begin_comment
comment|/* Place line into "clocal" dialing state */
end_comment

begin_if
if|if
condition|(
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|DIALING
argument_list|,
name|parity
argument_list|)
operator|<
literal|0
condition|)
block|{
name|dialhup
argument_list|()
expr_stmt|;
comment|/* If ttpkt fails do all this... */
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mymdmtyp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|erp
operator|=
name|errmsg
expr_stmt|;
name|sprintf
argument_list|(
name|erp
argument_list|,
literal|"Sorry, can't reopen %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|errmsg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* And try again. */
if|if
condition|(
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|DIALING
argument_list|,
name|parity
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, Can't condition communication line\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Try 'set line %s' again\n"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_if
if|if
condition|(
operator|!
operator|(
name|lbuf
operator|=
name|malloc
argument_list|(
name|LBUFL
operator|+
literal|1
argument_list|)
operator|)
condition|)
block|{
comment|/* Allocate input line buffer */
name|printf
argument_list|(
literal|"Sorry, memory buffer can't be allocated\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_expr_stmt
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Let it finish waking up. */
end_comment

begin_comment
comment|/*   Establish jump vector, or handle "failure" jumps.   longjmp() sets global failure reason, n1. */
end_comment

begin_if
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* if a "failure jump" was taken... */
name|n
operator|=
name|n1
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* disable timeouts */
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* failure while handling failure */
name|printf
argument_list|(
literal|"%s failure while handling failure.\n"
argument_list|,
name|F_reason
index|[
name|n1
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* first (i.e., non-nested) failure */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
comment|/* be sure to catch signals */
ifdef|#
directive|ifdef
name|MAC
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* MAC */
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* be sure to exit this section */
block|}
switch|switch
condition|(
name|n
condition|)
block|{
comment|/* type of failure */
case|case
name|F_time
case|:
block|{
comment|/* timed out */
name|printf
argument_list|(
literal|"No connection made within the allotted time.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mymdmtyp
operator|==
name|n_HAYES
operator|||
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
name|ttoc
argument_list|(
literal|'\015'
argument_list|)
expr_stmt|;
comment|/* Send CR to interrupt dialing */
comment|/* some hayes modems don't fail with BUSY on busy lines */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial"
argument_list|,
literal|"timeout"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|F_int
case|:
block|{
comment|/* dialing interrupted */
name|printf
argument_list|(
literal|"Dialing interrupted.\n"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial"
argument_list|,
literal|"interrupted"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|mymdmtyp
operator|==
name|n_HAYES
operator|||
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
name|ttoc
argument_list|(
literal|'\015'
argument_list|)
expr_stmt|;
comment|/* Send CR to interrupt dialing */
break|break;
block|}
case|case
name|F_modem
case|:
block|{
comment|/* modem detected a failure */
name|printf
argument_list|(
literal|"Failed (\""
argument_list|)
expr_stmt|;
for|for
control|(
name|pc
operator|=
name|lbuf
init|;
operator|*
name|pc
condition|;
name|pc
operator|++
control|)
if|if
condition|(
name|isprint
argument_list|(
operator|*
name|pc
argument_list|)
condition|)
name|putchar
argument_list|(
operator|*
name|pc
argument_list|)
expr_stmt|;
comment|/* display printable reason */
name|printf
argument_list|(
literal|"\").\n"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial"
argument_list|,
name|lbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|F_minit
case|:
block|{
comment|/* cannot initialize modem */
name|printf
argument_list|(
literal|"Can't initialize modem.\n"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial"
argument_list|,
literal|"modem init"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|reset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
name|dialhup
argument_list|()
expr_stmt|;
comment|/* try to hang up phone. */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* exit with failure code */
block|}
end_if

begin_comment
comment|/* Set timer and interrupt handlers. */
end_comment

begin_expr_stmt
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Set alarm handler */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_expr_stmt
name|savint
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MAC */
end_comment

begin_if
if|if
condition|(
operator|(
name|savint
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|)
operator|!=
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* Set int handler if not ignored */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_expr_stmt
name|x
operator|=
literal|10
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Give modem 10 seconds to wake up */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial wakeup timout"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|x
operator|=
name|alarm
argument_list|(
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial previous alarm"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Put modem in command mode. */
end_comment

begin_switch
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
comment|/* Send the wakeup string */
ifdef|#
directive|ifdef
name|ATT7300
case|case
name|n_ATTUPC
case|:
block|{
comment|/*   For ATT7300/Unix PC's with their special internal modem.  Timeout   and user interrupts are enabled during dialing.  attdial() is in   file ckutio.c.  - jrd */
name|_PROTOTYP
argument_list|(
argument|int attdial
argument_list|,
argument|(char *, long, char *)
argument_list|)
empty_stmt|;
name|alarm
argument_list|(
name|waitct
argument_list|)
expr_stmt|;
comment|/* do alarm properly */
if|if
condition|(
name|attdial
argument_list|(
name|ttname
argument_list|,
name|speed
argument_list|,
name|telnbr
argument_list|)
condition|)
block|{
comment|/* dial internal modem */
name|reset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|" Call did not complete."
argument_list|)
expr_stmt|;
name|dialhup
argument_list|()
expr_stmt|;
comment|/* Hangup the call */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return failure */
block|}
name|reset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|CONNECT
argument_list|,
name|parity
argument_list|)
expr_stmt|;
comment|/* cancel dialing ioctl */
if|if
condition|(
operator|!
name|quiet
condition|)
block|{
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" Call completed.\07\r\n"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
return|return
operator|(
literal|1
operator|)
return|;
comment|/* no conversation with modem to complete dialing */
block|}
endif|#
directive|endif
comment|/* ATT7300 */
comment|/*   For Hayes modem command language, figure out if modem is giving verbose   or digit result codes. */
case|case
name|n_HAYES
case|:
case|case
name|n_HAYESNV
case|:
name|ws
operator|=
name|dialini
condition|?
name|dialini
else|:
name|HAYES
operator|.
name|wake_str
expr_stmt|;
for|for
control|(
name|tries
operator|=
literal|4
init|;
name|tries
operator|>
literal|0
condition|;
name|tries
operator|--
control|)
block|{
name|ttslow
argument_list|(
name|ws
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|status
operator|=
name|getok
argument_list|(
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|>
literal|0
condition|)
break|break;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Wait before retrying */
block|}
if|if
condition|(
name|status
operator|>
literal|0
condition|)
break|break;
comment|/* Initialized OK. */
comment|/* modem-initialization failure */
name|n1
operator|=
operator|(
name|status
operator|==
literal|0
operator|)
condition|?
name|F_minit
else|:
name|F_modem
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|n1
argument_list|)
expr_stmt|;
comment|/*     Telebit support: Trailblazer, T1000, T2500.     C-Kermit global variables 'dialksp', 'flow', 'dialini', 'parity',     and local variable 'augmdmtyp' modify our behavior:      modulation- and confguration-independent initialization:     S11         DTMF timing (left alone)     S45         remote access (left alone)     S48=1       all 8 bits are significant, 0 only 7 bits     S51=255     set serial port baud rate automatically (no typeahead)     S52=2       go on hook when DTR drops and reset to NV-RAM     S53         DCD/DSR control (left alone)     S54=2       pass BREAK signal to remote modem immediately     S55=0       respond to command escape sequence<sec>+++<sec>     depending upon the value of 'flow':     ==FLO_NONE  S58=0   DTE uses no flow control     ==FLO_HARD  S58=2   DTE uses hardware (CTS/RTS) flow control     ==FLO_XONX  S58=3   DTE uses XON/XOFF flow control     S66         lock interface speed: depends on value of mdmspd variable:                 mdmspd == 0 sets S66=1 (lock speed, use flow control)                 mdmspd != 0 sets S66=0 (change speed, no flow control)     S68=255     DCE uses whatever flow control DTE uses (specified in S58)     S95=0       MNP: depends on value of dialmnp variable:                 dialmnp == 0 sets S95=0 (no MNP)                 dialmnp != 0 sets S95=2 (auto MNP)     S110=1      use data compression if remote modem agrees      SET MODEM TELEBIT     "traditional" configuration (PEP, V.22, V.22bis, 212A, 103):     S50=0       use automatic configuration to answering modem      SET MODEM PEP-TELEBIT     PEP mode with SET DIAL KERMIT-SPOOF ON     S50=255     use PEP + lock DCE speed to DTE speed     S111=10     Kermit with no parity     S111=11     Kermit with odd parity     S111=12     Kermit with even parity     S111=13     Kermit with mark parity     S111=14     Kermit with space parity     S112=??     set to Kermit's start-of-packet character, stchr      SET MODEM PEP-TELEBIT with SET DIAL KERMIT-SPOOF OFF     S50=255     use PEP + lock DCE speed to DTE speed     S111=0      use normal PEP inter-modem protocol      SET MODEM V32-TELEBIT  (doesn't work with Trailblazer or T1000)     S50=6       use V.32      SET MODEM V42-TELEBIT     S50=0       auto speed select     S95=1	MNP reliable mode     S96=1	enable MNP data compression         S97=1	enable LAP-M     S98=3	compression in both directions     S106=1	V.42 detection enable      SET MODEM SLOW-TELEBIT     S94=1	connect to any speed up to maximum specified by S50     S50=3	connect to Bell 103/212a, V.21, V.22 and V.22bis */
case|case
name|n_TELEBIT
case|:
comment|/* Telebits... */
case|case
name|n_TBNV
case|:
case|case
name|n_TBPEP
case|:
case|case
name|n_TB3
case|:
case|case
name|n_TB4
case|:
case|case
name|n_TBS
case|:
case|case
name|n_TBPNV
case|:
case|case
name|n_TB3NV
case|:
case|case
name|n_TB4NV
case|:
case|case
name|n_TBSNV
case|:
block|{
name|int
name|S58
decl_stmt|,
name|S66
decl_stmt|,
name|S95
decl_stmt|,
name|S111
decl_stmt|,
name|S112
decl_stmt|;
comment|/* Some Telebit register names */
name|char
name|t25buf
index|[
literal|64
index|]
decl_stmt|;
comment|/* Modem command buffer */
comment|/*   If user defined a DIAL INIT-STRING, send that now, otherwise send built-in   Telebit string.  Try up to 4 times to get OK or 0 response from modem. */
name|ws
operator|=
name|dialini
condition|?
name|dialini
else|:
name|TELEBIT
operator|.
name|wake_str
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckdial telebit init string"
argument_list|,
name|ws
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|tries
operator|=
literal|4
init|;
name|tries
operator|>
literal|0
condition|;
name|tries
operator|--
control|)
block|{
name|ttslow
argument_list|(
name|ws
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|status
operator|=
name|getok
argument_list|(
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
break|break;
name|dialhup
argument_list|()
expr_stmt|;
comment|/* Hang up */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer */
block|}
if|if
condition|(
name|status
operator|<
literal|1
condition|)
block|{
name|n1
operator|=
name|F_minit
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
comment|/* Failed. */
block|}
if|if
condition|(
operator|!
name|dialini
condition|)
block|{
comment|/* If using built-in init strings */
comment|/* Step 2 */
name|sprintf
argument_list|(
name|t25buf
argument_list|,
literal|"ATS48=%d S51=255 S52=2 S54=2\015"
argument_list|,
name|parity
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
name|s
operator|=
name|t25buf
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckdial Telebit init step 2"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|tries
operator|=
literal|4
init|;
name|tries
operator|>
literal|0
condition|;
name|tries
operator|--
control|)
block|{
name|ttslow
argument_list|(
name|s
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|status
operator|=
name|getok
argument_list|(
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
break|break;
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|status
operator|<
literal|1
condition|)
block|{
name|n1
operator|=
name|F_minit
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
comment|/* Failed. */
block|}
switch|switch
condition|(
name|flow
condition|)
block|{
comment|/* Flow control */
case|case
name|FLO_HARD
case|:
name|S58
operator|=
literal|2
expr_stmt|;
break|break;
comment|/* RTX/CTS  (hardware) */
default|default:
name|S58
operator|=
literal|0
expr_stmt|;
break|break;
comment|/* NONE (or other) */
block|}
if|if
condition|(
name|dialmnp
condition|)
block|{
comment|/* MNP negotiation */
name|S95
operator|=
literal|2
expr_stmt|;
comment|/* Enabled (auto) */
block|}
else|else
block|{
name|S95
operator|=
literal|0
expr_stmt|;
comment|/* Disabled */
block|}
name|S66
operator|=
name|mdmspd
condition|?
literal|0
else|:
literal|1
expr_stmt|;
comment|/* Interface speed locked? */
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|t25buf
argument_list|,
literal|"ATS58=%d S55=0 S66=%d S68=255 S95=%d\015"
argument_list|,
name|S58
argument_list|,
name|S66
argument_list|,
name|S95
argument_list|)
expr_stmt|;
name|s
operator|=
name|t25buf
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckdial Telebit init step 3"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|tries
operator|=
literal|4
init|;
name|tries
operator|>
literal|0
condition|;
name|tries
operator|--
control|)
block|{
name|ttslow
argument_list|(
name|s
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|status
operator|=
name|getok
argument_list|(
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
break|break;
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|status
operator|<
literal|1
condition|)
block|{
name|n1
operator|=
name|F_minit
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
comment|/* Failed. */
block|}
name|p
operator|=
literal|""
expr_stmt|;
name|s
operator|=
literal|""
expr_stmt|;
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
comment|/* we will auto-config */
case|case
name|n_TELEBIT
case|:
comment|/* 103,212,v22bis modulation */
case|case
name|n_TBNV
case|:
name|p
operator|=
literal|"standard"
expr_stmt|;
comment|/* Automatic speed determination */
name|s
operator|=
literal|"ATS50=0 S110=0\015"
expr_stmt|;
break|break;
case|case
name|n_TBPEP
case|:
comment|/* PEP Protocol */
case|case
name|n_TBPNV
case|:
if|if
condition|(
name|dialksp
condition|)
block|{
comment|/* SET DIAL KERMIT-SPOOF ON? */
switch|switch
condition|(
name|parity
condition|)
block|{
case|case
literal|'e'
case|:
name|S111
operator|=
literal|12
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|S111
operator|=
literal|13
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|S111
operator|=
literal|11
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|S111
operator|=
literal|14
expr_stmt|;
break|break;
default|default:
case|case
literal|0
case|:
name|S111
operator|=
literal|10
expr_stmt|;
break|break;
block|}
name|S112
operator|=
name|stchr
expr_stmt|;
comment|/* Start-of-packet character */
name|sprintf
argument_list|(
name|t25buf
argument_list|,
literal|"ATS50=255 S110=1 S111=%d S112=%d\015"
argument_list|,
name|S111
argument_list|,
name|S112
argument_list|)
expr_stmt|;
name|p
operator|=
literal|"PEP/Kermit"
expr_stmt|;
name|s
operator|=
name|t25buf
expr_stmt|;
block|}
else|else
block|{
comment|/* SET DIAL KERMIT-SPOOF OFF */
name|p
operator|=
literal|"PEP/No-Kermit"
expr_stmt|;
name|s
operator|=
literal|"ATS50=255 S110=1\015"
expr_stmt|;
comment|/* Accept any protocol */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial telebit pep waitct"
argument_list|,
literal|""
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
break|break;
case|case
name|n_TB3
case|:
comment|/* Telebit V.32 */
case|case
name|n_TB3NV
case|:
name|p
operator|=
literal|"V.32"
expr_stmt|;
name|s
operator|=
literal|"ATS50=6\015"
expr_stmt|;
break|break;
case|case
name|n_TB4
case|:
comment|/* Telebit V.42 */
case|case
name|n_TB4NV
case|:
name|p
operator|=
literal|"V.42"
expr_stmt|;
name|s
operator|=
literal|"ATS50=0 S95=1 S96=1 S97=1 S98=3 S106=1\015"
expr_stmt|;
break|break;
case|case
name|n_TBS
case|:
comment|/* Telebit up to 2400 Baud */
case|case
name|n_TBSNV
case|:
name|p
operator|=
literal|"300/1200/2400 Baud"
expr_stmt|;
name|s
operator|=
literal|"ATS94=1 S50=3\015"
expr_stmt|;
break|break;
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ckdial Telebit config"
argument_list|,
name|p
argument_list|,
name|speed
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckdial Telebit init step 4"
argument_list|,
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
for|for
control|(
name|tries
operator|=
literal|4
init|;
name|tries
operator|>
literal|0
condition|;
name|tries
operator|--
control|)
block|{
name|ttslow
argument_list|(
name|s
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|status
operator|=
name|getok
argument_list|(
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
break|break;
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial telebit init status"
argument_list|,
literal|""
argument_list|,
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|<
literal|1
condition|)
block|{
name|n1
operator|=
name|F_minit
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Done with Telebit protocols, remove bits from modem type */
comment|/* Except nonverbal bit */
name|augmdmtyp
operator|&=
operator|~
operator|(
name|DIAL_PEP
operator||
name|DIAL_V32
operator||
name|DIAL_V42
operator||
name|DIAL_SLO
operator|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial Telebit augmdmtyp"
argument_list|,
literal|""
argument_list|,
name|augmdmtyp
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|n_MICROCOM
case|:
comment|/* interdigit waits for tone dial */
block|{
name|jmp_buf
name|savejmp
decl_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|xcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|savejmp
argument_list|,
operator|(
name|char
operator|*
operator|)
name|sjbuf
argument_list|,
sizeof|sizeof
name|savejmp
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
block|{
comment|/* try the autobaud sequence */
name|xcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|sjbuf
argument_list|,
operator|(
name|char
operator|*
operator|)
name|savejmp
argument_list|,
sizeof|sizeof
name|savejmp
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|ttslow
argument_list|(
literal|"44445"
argument_list|,
name|MICROCOM
operator|.
name|wake_rate
argument_list|)
expr_stmt|;
name|waitfor
argument_list|(
name|MICROCOM
operator|.
name|wake_str
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|alarm
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|ws
operator|=
name|dialini
condition|?
name|dialini
else|:
name|MICROCOM
operator|.
name|wake_str
expr_stmt|;
name|ttslow
argument_list|(
name|ws
argument_list|,
name|MICROCOM
operator|.
name|wake_rate
argument_list|)
expr_stmt|;
name|waitfor
argument_list|(
name|ws
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|xcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|sjbuf
argument_list|,
operator|(
name|char
operator|*
operator|)
name|savejmp
argument_list|,
sizeof|sizeof
name|savejmp
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|n_ATTDTDM
case|:
comment|/* DTDM requires BREAK to wake up */
name|ttsndb
argument_list|()
expr_stmt|;
comment|/* Send BREAK */
break|break;
comment|/* ttsndb() defined in ckutio.c */
default|default:
comment|/* place modem into command mode */
name|ws
operator|=
name|dialini
condition|?
name|dialini
else|:
name|pmdminf
operator|->
name|wake_str
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ckdial default, wake string"
argument_list|,
name|ws
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|ttslow
argument_list|(
name|ws
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckdial default, waiting for wake_prompt"
argument_list|,
name|pmdminf
operator|->
name|wake_prompt
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|waitfor
argument_list|(
name|pmdminf
operator|->
name|wake_prompt
argument_list|)
expr_stmt|;
break|break;
block|}
end_switch

begin_expr_stmt
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* turn off alarm */
end_comment

begin_if
if|if
condition|(
name|augmdmtyp
operator|!=
name|n_TELEBIT
condition|)
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckdial got wake prompt"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* give things settling time */
end_comment

begin_comment
comment|/* Enable/disable MNP (Telebit already done above) */
end_comment

begin_switch
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_HST
case|:
if|if
condition|(
name|dialmnp
condition|)
name|ttslow
argument_list|(
literal|"AT&K2\015"
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
else|else
name|ttslow
argument_list|(
literal|"AT&K0\015"
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|getok
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* Get response */
break|break;
default|default:
break|break;
block|}
end_switch

begin_comment
comment|/* Dial the number */
end_comment

begin_comment
comment|/* put modem into dialing mode */
end_comment

begin_expr_stmt
name|ttslow
argument_list|(
name|pmdminf
operator|->
name|dmode_str
argument_list|,
name|pmdminf
operator|->
name|dial_rate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|pmdminf
operator|->
name|dmode_prompt
condition|)
block|{
comment|/* wait for prompt, if any expected */
name|waitfor
argument_list|(
name|pmdminf
operator|->
name|dmode_prompt
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* turn off alarm on dialing prompts */
end_comment

begin_expr_stmt
name|ttflui
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* clear out stuff from waking modem up */
end_comment

begin_expr_stmt
name|sprintf
argument_list|(
name|lbuf
argument_list|,
name|pmdminf
operator|->
name|dial_str
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* form dialing string */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dialing"
argument_list|,
name|lbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ttslow
argument_list|(
name|lbuf
argument_list|,
name|pmdminf
operator|->
name|dial_rate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* send dialing string */
end_comment

begin_expr_stmt
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Time to allow for connecting */
end_comment

begin_expr_stmt
name|x
operator|=
name|alarm
argument_list|(
name|waitct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This much time... */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial old alarm"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial waitct"
argument_list|,
literal|""
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_RACAL
case|:
comment|/* acknowledge printout of dialing string */
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
name|ttoc
argument_list|(
literal|'\015'
argument_list|)
expr_stmt|;
break|break;
case|case
name|n_VENTEL
case|:
name|waitfor
argument_list|(
literal|"\012\012"
argument_list|)
expr_stmt|;
comment|/* Ignore the first two strings */
break|break;
default|default:
break|break;
block|}
end_switch

begin_comment
comment|/* Check for connection */
end_comment

begin_comment
comment|/*  * I believe we also need to look for carrier in order to determine if a  * connection has been made.  In fact, for many we may only want to look for  * the "failure" responses in order to short-circuit the timeout, and let  * carrier be the determination of whether a connection has been made. -- DS  */
end_comment

begin_expr_stmt
name|status
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"No Connection"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* default failure reason */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dial awaiting response, augmdmtyp"
argument_list|,
literal|""
argument_list|,
name|augmdmtyp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|status
operator|==
literal|0
condition|)
block|{
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
default|default:
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|LBUFL
operator|-
literal|1
condition|;
name|n
operator|++
control|)
block|{
comment|/* accumulate response */
name|lbuf
index|[
name|n
index|]
operator|=
name|c2
operator|=
operator|(
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
operator|)
expr_stmt|;
name|dialoc
argument_list|(
name|c2
argument_list|)
expr_stmt|;
if|if
condition|(
name|lbuf
index|[
name|n
index|]
operator|==
name|CR
operator|||
name|lbuf
index|[
name|n
index|]
operator|==
name|LF
condition|)
break|break;
block|}
name|lbuf
index|[
name|n
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate response from modem */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"dial modem response"
argument_list|,
name|lbuf
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
condition|)
block|{
comment|/* If one or more characters present */
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
comment|/* check for modem response message. */
case|case
name|n_ATTMODEM
case|:
comment|/* Careful - "Connected" / "Not Connected" */
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Busy"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Not connected"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Not Connected"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No dial tone"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No Dial Tone"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No answer"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No Answer"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Answered"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Connected"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
name|n_ATTISN
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ANSWERED"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DISCONNECT"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO ANSWER"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"WRONG ADDRESS"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_ATTDTDM
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ANSWERED"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CHECK OPTIONS"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DISCONNECTED"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DENIED"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
ifdef|#
directive|ifdef
name|ATT6300
elseif|else
if|if
condition|(
name|deblog
operator|&&
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"~~"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
endif|#
directive|endif
comment|/* ATT6300 */
endif|#
directive|endif
comment|/* DEBUG */
break|break;
case|case
name|n_CERMETEK
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"\016A"
argument_list|)
condition|)
block|{
name|status
operator|=
name|CONNECTED
expr_stmt|;
name|ttslow
argument_list|(
literal|"\016U 1\015"
argument_list|,
literal|200
argument_list|)
expr_stmt|;
comment|/* make transparent*/
block|}
break|break;
case|case
name|n_DF100
case|:
comment|/* DF100 has short response codes */
if|if
condition|(
name|strcmp
argument_list|(
name|lbuf
argument_list|,
literal|"A"
argument_list|)
operator|==
literal|0
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
comment|/* Attached */
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|lbuf
argument_list|,
literal|"N"
argument_list|)
operator|==
literal|0
operator|||
comment|/* No Ans or Dialtone */
name|strcmp
argument_list|(
name|lbuf
argument_list|,
literal|"E"
argument_list|)
operator|==
literal|0
operator|||
comment|/* Error */
name|strcmp
argument_list|(
name|lbuf
argument_list|,
literal|"R"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Ready */
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
block|}
comment|/* otherwise fall thru... */
case|case
name|n_DF200
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Attached"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
comment|/* 		     * The DF100 will respond with "Attached" even if DTR 		     * and/or carrier are not present.	Another reason to 		     * (also) wait for carrier? 		     */
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Busy"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Disconnected"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Error"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No answer"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"No dial tone"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Speed:"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
comment|/* 		     * It appears that the "Speed:..." response comes after an 		     * "Attached" response, so this is never seen.  HOWEVER, 		     * it would be very handy to detect this and temporarily 		     * reset the speed, since it's a nuisance otherwise. 		     * If we wait for some more input from the modem, how do 		     * we know if it's from the remote host or the modem? 		     * Carrier reportedly doesn't get set until after the 		     * "Speed:..." response (if any) is sent.  Another reason 		     * to (also) wait for carrier. 		     */
break|break;
case|case
name|n_GDC
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ON LINE"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO CONNECT"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_HAYES
case|:
case|case
name|n_USROBOT
case|:
case|case
name|n_HST
case|:
case|case
name|n_TELEBIT
case|:
if|if
condition|(
name|mdmspd
condition|)
block|{
name|s
operator|=
name|lbuf
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|!=
literal|'\0'
operator|&&
operator|*
name|s
operator|!=
literal|'C'
condition|)
name|s
operator|++
expr_stmt|;
name|cptr
operator|=
operator|(
operator|*
name|s
operator|==
literal|'C'
operator|)
condition|?
name|s
else|:
name|NULL
expr_stmt|;
name|conspd
operator|=
literal|0L
expr_stmt|;
if|if
condition|(
operator|(
name|cptr
operator|!=
name|NULL
operator|)
operator|&&
operator|!
name|strncmp
argument_list|(
name|cptr
argument_list|,
literal|"CONNECT "
argument_list|,
literal|8
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|cptr
argument_list|)
operator|<
literal|9
condition|)
comment|/* Just CONNECT, */
name|conspd
operator|=
literal|300L
expr_stmt|;
comment|/* use 300 bps */
elseif|else
if|if
condition|(
name|isdigit
argument_list|(
operator|*
operator|(
name|cptr
operator|+
literal|8
operator|)
argument_list|)
condition|)
comment|/* not CONNECT FAST */
name|conspd
operator|=
name|atol
argument_list|(
name|cptr
operator|+
literal|8
argument_list|)
expr_stmt|;
comment|/* CONNECT nnnn */
if|if
condition|(
name|conspd
operator|!=
name|speed
condition|)
block|{
if|if
condition|(
operator|(
name|conspd
operator|/
literal|10L
operator|)
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|ttsspd
argument_list|(
call|(
name|int
call|)
argument_list|(
name|conspd
operator|/
literal|10L
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|" Can't change speed to %lu\r\n"
argument_list|,
name|conspd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|speed
operator|=
name|conspd
expr_stmt|;
name|status
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|" Speed changed to %lu\r\n"
argument_list|,
name|conspd
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Expanded to handle any conceivable speed */
block|}
block|}
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
block|{
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CONNECT FAST/KERM"
argument_list|)
condition|)
block|{
name|status
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|"FAST/KERM "
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"RRING"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"RINGING"
argument_list|)
condition|)
block|{
name|status
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CONNECT"
argument_list|)
condition|)
block|{
name|status
operator|=
name|CONNECTED
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO CARRIER"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO DIALTONE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO DIAL TONE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO ANSWER"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"VOICE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"RING"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ERROR"
argument_list|)
condition|)
block|{
name|status
operator|=
name|FAILED
expr_stmt|;
block|}
break|break;
case|case
name|n_PENRIL
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"OK"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO RING"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_RACAL
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ON LINE"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"FAILED CALL"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_ROLM
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CALLING"
argument_list|)
condition|)
name|status
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"COMPLETE"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"FAILED"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NOT AVAILABLE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"LACKS PERMISSION"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NOT A DATALINE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ABANDONDED"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DOES NOT ANSWER"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
comment|/*                       Early versions of the Rolm 9751 CBX software do not                       give a CALL COMPLETE indication when dialing an                       outpool number, but they do seem to return a long                       string of DELs at that point.  (this doesn't really                       work...) 		    else if (didweget(lbuf,"\177\177\177")) 			status = CONNECTED; 		    */
break|break;
case|case
name|n_VENTEL
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ONLINE!"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Online!"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DEAD PHONE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"Busy"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_CONCORD
case|:
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"INITIATING"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CALL FAILED"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_MICROCOM
case|:
comment|/* "RINGBACK" means phone line ringing, continue */
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO CONNECT"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NO DIALTONE"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"COMMAND ERROR"
argument_list|)
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"IN USE"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CONNECT"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
comment|/* trailing speed ignored */
break|break;
block|}
block|}
break|break;
case|case
name|n_DF03
case|:
comment|/* because response lacks CR or NL */
name|c
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"dial df03 got"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'A'
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'B'
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_HAYESNV
case|:
comment|/* Hayeslike modems in digit */
case|case
name|n_TBNV
case|:
comment|/* response mode... */
case|case
name|n_TB3NV
case|:
case|case
name|n_TBPNV
case|:
case|case
name|n_TB4NV
case|:
case|case
name|n_TBSNV
case|:
comment|/*   The method for reading Hayes numeric result codes has been totally    redone as of 5A(174) to account for all of the following.  Not all have   been tested, and others probably need to be added.    Hayes numeric result codes (Hayes 1200 and higher):      0 = OK      1 = CONNECT at 300 bps (or 1200 bps on Hayes 1200 with basic code set)      2 = RING      3 = NO CARRIER      4 = ERROR (in command line)      5 = CONNECT 1200 (extended code set)   Hayes 2400 and higher:        6 = NO DIALTONE      7 = BUSY      8 = NO ANSWER      9 = (there is no 9)     10 = CONNECT 2400   Reportedly, the codes for Hayes V.32 modems are:     1x = CONNECT<suffix>     5x = CONNECT 1200<suffix>     9x = CONNECT 2400<suffix>    11x = CONNECT 4800<suffix>    12x = CONNECT 9600<suffix>   Where:     x:   suffix:     R  = RELIABLE     RC = RELIABLE COMPRESSED     L  = LAPM     LC = LAPM COMPRESSED   And for Telebits:     50 = CONNECT FAST     52 = RRING     What else? */
block|{
comment|/* Nonverbal response code handler */
name|char
name|nbuf
index|[
literal|8
index|]
decl_stmt|;
comment|/* Response buffer */
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* Buffer pointers */
if|if
condition|(
name|mdmecho
condition|)
block|{
comment|/* Sponge up dialing string echo. */
while|while
condition|(
operator|(
name|c
operator|=
operator|(
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
operator|)
operator|)
operator|!=
name|CR
condition|)
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
name|status
operator|==
literal|0
condition|)
block|{
comment|/* Read response */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
comment|/* Clear the buffer */
name|nbuf
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
comment|/* Reset the buffer pointer. */
name|c
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Get first digit of response. */
comment|/* using an untimed, blocking read. */
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Echo it if requested. */
if|if
condition|(
operator|!
name|isdigit
argument_list|(
name|c
argument_list|)
condition|)
comment|/* If not a digit, keep looking. */
continue|continue;
name|nbuf
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|/* Got a digit, save it. */
while|while
condition|(
name|i
operator|<
literal|8
condition|)
block|{
comment|/* Keep reading till we time out */
name|y
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* Save current alarm */
name|x
operator|=
name|ttinc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Read char with 1-sec timeout */
if|if
condition|(
name|y
operator|>
literal|0
condition|)
name|alarm
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|/* Restore alarm */
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
comment|/* If we didn't time out, */
name|c
operator|=
operator|(
name|char
operator|)
name|x
expr_stmt|;
comment|/*  we got this character. */
if|if
condition|(
name|c
operator|!=
name|CR
condition|)
comment|/* Save it, */
name|nbuf
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|/* if it's not a carriage return. */
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Echo it. */
block|}
else|else
break|break;
comment|/* Otherwise assume end of response. */
block|}
name|nbuf
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate the buffer. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"dial hayesnv lbuf"
argument_list|,
name|lbuf
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"dial hayesnv got"
argument_list|,
name|nbuf
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|/* 		  Separate any non-numeric suffix from the numeric result code 		  with a null. 		*/
for|for
control|(
name|j
operator|=
name|i
operator|-
literal|1
init|;
operator|(
name|j
operator|>
operator|-
literal|1
operator|)
operator|&&
operator|!
name|isdigit
argument_list|(
name|nbuf
index|[
name|j
index|]
argument_list|)
condition|;
name|j
operator|--
control|)
name|nbuf
index|[
name|j
operator|+
literal|1
index|]
operator|=
name|nbuf
index|[
name|j
index|]
expr_stmt|;
name|j
operator|++
expr_stmt|;
name|nbuf
index|[
name|j
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial hayesnv numeric"
argument_list|,
name|nbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"dial hayesnv suffix "
argument_list|,
name|nbuf
operator|+
name|j
argument_list|,
name|j
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|nbuf
argument_list|)
operator|>
literal|3
condition|)
comment|/* Probably phone number echoing. */
continue|continue;
comment|/* 		  Now read and interpret the results... 		*/
name|i
operator|=
name|atoi
argument_list|(
name|nbuf
argument_list|)
expr_stmt|;
comment|/* Convert to integer */
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
comment|/* CONNECT */
name|status
operator|=
name|CONNECTED
expr_stmt|;
comment|/* Could be any speed */
break|break;
case|case
literal|2
case|:
comment|/* RING */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n Local phone is ringing!\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* NO CARRIER */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n No Carrier.\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|4
case|:
comment|/* ERROR */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n Modem Command Error.\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|5
case|:
comment|/* CONNECT 1200 */
name|spdchg
argument_list|(
literal|1200L
argument_list|)
expr_stmt|;
comment|/* Change speed if necessary. */
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|6
case|:
comment|/* NO DIALTONE */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n No Dialtone.\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|7
case|:
comment|/* BUSY */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n Busy.\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|8
case|:
comment|/* NO ANSWER */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n No Answer.\r\n"
argument_list|)
expr_stmt|;
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
literal|9
case|:
comment|/* CONNECT 2400 */
case|case
literal|10
case|:
name|spdchg
argument_list|(
literal|2400L
argument_list|)
expr_stmt|;
comment|/* Change speed if necessary. */
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|11
case|:
comment|/* CONNECT 4800 */
name|spdchg
argument_list|(
literal|4800L
argument_list|)
expr_stmt|;
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|12
case|:
comment|/* CONNECT 9600 */
name|spdchg
argument_list|(
literal|9600L
argument_list|)
expr_stmt|;
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|52
case|:
comment|/* RRING */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dial hayesnv 52 mymdmtyp"
argument_list|,
literal|""
argument_list|,
name|mymdmtyp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dial hayesnv 52 n_TELEBIT"
argument_list|,
literal|""
argument_list|,
name|n_TELEBIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|" Ringing...\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|50
case|:
comment|/* CONNECT FAST */
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
comment|/* CONNECT FAST */
break|break;
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|status
operator|==
name|CONNECTED
operator|&&
name|nbuf
index|[
name|j
index|]
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|dialdpy
condition|)
block|{
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|nbuf
index|[
name|j
index|]
operator|==
literal|'R'
condition|)
name|printf
argument_list|(
literal|"RELIABLE"
argument_list|)
expr_stmt|;
if|if
condition|(
name|nbuf
index|[
name|j
index|]
operator|==
literal|'L'
condition|)
name|printf
argument_list|(
literal|"LAPM"
argument_list|)
expr_stmt|;
if|if
condition|(
name|nbuf
index|[
name|j
operator|+
literal|1
index|]
operator|==
literal|'C'
condition|)
name|printf
argument_list|(
literal|" COMPRESSED"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
break|break;
case|case
name|n_UNKNOWN
case|:
block|{
name|int
name|x
decl_stmt|,
name|y
init|=
name|waitct
decl_stmt|;
while|while
condition|(
name|y
operator|--
operator|>
operator|-
literal|1
condition|)
block|{
name|x
operator|=
name|ttchk
argument_list|()
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|x
operator|>
name|LBUFL
condition|)
name|x
operator|=
name|LBUFL
expr_stmt|;
name|x
operator|=
name|ttxin
argument_list|(
name|x
argument_list|,
operator|(
name|CHAR
operator|*
operator|)
name|lbuf
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|>
literal|0
operator|)
operator|&&
name|dialdpy
condition|)
name|conol
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
block|}
name|x
operator|=
name|ttgmdm
argument_list|()
expr_stmt|;
comment|/* Try to read modem signals */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
break|break;
comment|/* Can't, pretend we suceeded */
if|if
condition|(
name|x
operator|&
name|BM_DCD
condition|)
comment|/* Got signals OK.  Carrier present? */
break|break;
comment|/* Yes, done. */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
block|}
block|}
comment|/* switch (augmdmtyp) */
block|}
end_while

begin_comment
comment|/* while status == 0 */
end_comment

begin_expr_stmt
name|x
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* turn off alarm on connecting */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F101
argument_list|,
literal|"ckdial alarm off"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|status
operator|!=
name|CONNECTED
condition|)
block|{
comment|/* modem-detected failure */
name|n1
operator|=
name|F_modem
expr_stmt|;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_modem
argument_list|)
expr_stmt|;
comment|/* exit (with reason in lbuf) */
block|}
end_if

begin_expr_stmt
name|msleep
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* in case DTR blinks  */
end_comment

begin_expr_stmt
name|alarm
argument_list|(
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* precaution in case of trouble */
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial"
argument_list|,
literal|"succeeded"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|augmdmtyp
operator|!=
name|n_ROLM
condition|)
comment|/* Rolm has wierd modem signaling */
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|CONNECT
argument_list|,
name|parity
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* cancel dialing state ioctl */
end_comment

begin_expr_stmt
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reset alarms, etc. */
end_comment

begin_if
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|" Call completed.\07\n"
argument_list|)
expr_stmt|;
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_if
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_return
return|return
operator|(
literal|1
operator|)
return|;
end_return

begin_comment
comment|/* return, and presumably connect */
end_comment

begin_comment
unit|}
comment|/*   getok - wait up to n seconds for "OK<CRLF>" or "<CR>0" from modem.   Use with Hayeslike modems for reading reply to a nondialing command.   Does its own internal timeout handling, but resets alarms to 0.   Returns 0 if it timed out, 1 if it succeeded, -1 on modem command error. */
end_comment

begin_decl_stmt
unit|static
name|jmp_buf
name|okbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Jump-buf for getok(). */
end_comment

begin_function
name|SIGTYP
name|oktimo
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* Alarm handler for getok(). */
name|longjmp
argument_list|(
name|okbuf
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|getok
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
name|CHAR
name|c
decl_stmt|;
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|status
decl_stmt|;
name|char
name|rbuf
index|[
literal|8
index|]
decl_stmt|;
comment|/* response buffer */
name|SIGTYP
function_decl|(
modifier|*
name|saval
function_decl|)
parameter_list|()
function_decl|;
comment|/* for saving alarm handler locally */
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|oktimo
argument_list|)
expr_stmt|;
comment|/* set timer */
name|alarm
argument_list|(
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|okbuf
argument_list|)
condition|)
block|{
comment|/* handle timeout */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|saval
condition|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|saval
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getok timed out"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
comment|/* not timed out... */
name|status
operator|=
literal|0
expr_stmt|;
name|rbuf
index|[
literal|7
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate response buffer */
while|while
condition|(
name|status
operator|==
literal|0
condition|)
block|{
name|x
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Read a character */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* i/o error */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getok ttinc returns"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|c
operator|=
name|x
operator|&
literal|0x7f
expr_stmt|;
comment|/* Get low order 7 bits */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getok converts this to char"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialdpy
condition|)
name|conoc
argument_list|(
operator|(
name|char
operator|)
name|c
argument_list|)
expr_stmt|;
comment|/* Echo it if requested */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
comment|/* Rotate buffer */
name|rbuf
index|[
name|i
index|]
operator|=
name|rbuf
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|rbuf
index|[
literal|6
index|]
operator|=
name|c
expr_stmt|;
comment|/* Deposit character */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"getok"
argument_list|,
name|rbuf
argument_list|,
operator|(
name|int
operator|)
name|c
argument_list|)
expr_stmt|;
comment|/* Log it */
switch|switch
condition|(
name|c
condition|)
block|{
comment|/* Interpret it. */
case|case
name|CR
case|:
comment|/* Got carriage return. */
if|if
condition|(
name|augmdmtyp
operator|&
name|DIAL_NV
condition|)
comment|/* If using digit result codes */
name|conoc
argument_list|(
name|LF
argument_list|)
expr_stmt|;
comment|/* echo a linefeed too. */
break|break;
case|case
name|LF
case|:
comment|/* Got linefeed. */
comment|/* 		  Note use of explicit octal codes in the string for 		  CR and LF.  We want real CR and LF here, not whatever 		  the compiler happens to define \r and \n as... 		*/
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
literal|3
argument_list|,
literal|"OK\015\012"
argument_list|)
condition|)
name|status
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|rbuf
argument_list|,
literal|"ERROR\015\012"
argument_list|)
condition|)
name|status
operator|=
operator|-
literal|1
expr_stmt|;
name|augmdmtyp
operator|&=
operator|~
operator|(
name|DIAL_NV
operator|)
expr_stmt|;
comment|/* Turn off the nonverbal bit */
break|break;
comment|/* Check whether modem echoes its commands... */
case|case
literal|'t'
case|:
comment|/* Got little t */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
literal|4
argument_list|,
literal|"\015at"
argument_list|)
condition|)
name|mdmecho
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'T'
case|:
comment|/* Got Big T */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
literal|4
argument_list|,
literal|"\015AT"
argument_list|)
condition|)
name|mdmecho
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'0'
case|:
comment|/* Got 0: Numeric result code? */
if|if
condition|(
name|rbuf
index|[
literal|5
index|]
operator|==
name|CR
condition|)
block|{
comment|/* Yes if previous char was CR. */
name|augmdmtyp
operator||=
name|DIAL_NV
expr_stmt|;
comment|/* OR in the "nonverbal" bit. */
name|status
operator|=
literal|1
expr_stmt|;
block|}
break|break;
case|case
literal|'4'
case|:
comment|/* Command line error */
if|if
condition|(
name|rbuf
index|[
literal|5
index|]
operator|==
name|CR
condition|)
comment|/* if previous char was CR */
name|status
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
default|default:
comment|/* Other characters, accumulate. */
name|status
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getok returns"
argument_list|,
literal|""
argument_list|,
name|status
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|saval
condition|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|saval
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* Maybe hang up the phone, depending on various SET DIAL parameters. */
end_comment

begin_function
name|int
name|dialhup
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|dialhng
condition|)
block|{
comment|/* DIAL HANGUP ON? */
name|x
operator|=
name|tthang
argument_list|()
expr_stmt|;
if|if
condition|(
name|dialdpy
condition|)
block|{
comment|/* DIAL DISPLAY ON? */
if|if
condition|(
name|x
operator|>
literal|0
condition|)
comment|/* Yes, tell results from tthang() */
name|printf
argument_list|(
literal|" Hangup ok\r\n"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|x
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|" Hangup skipped\r\n"
argument_list|)
expr_stmt|;
else|else
name|perror
argument_list|(
literal|" Hangup error"
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|" No hangup\r\n"
argument_list|)
expr_stmt|;
comment|/* DIAL HANGUP OFF */
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
comment|/* Let external routines ask */
name|getdws
parameter_list|(
name|mdmtyp
parameter_list|)
name|int
name|mdmtyp
decl_stmt|;
block|{
comment|/* about dial wake string. */
name|MDMINF
modifier|*
name|pmdminf
decl_stmt|;
if|if
condition|(
name|mdmtyp
operator|<
literal|1
operator|||
name|mdmtyp
operator|>
name|MAX_MDM
condition|)
return|return
operator|(
literal|""
operator|)
return|;
name|pmdminf
operator|=
name|ptrtab
index|[
operator|(
name|mdmtyp
operator|&
literal|0xff
operator|)
operator|-
literal|1
index|]
expr_stmt|;
return|return
operator|(
name|dialini
condition|?
name|dialini
else|:
name|pmdminf
operator|->
name|wake_str
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|dialv
init|=
literal|"Dial Command Disabled"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

end_unit

