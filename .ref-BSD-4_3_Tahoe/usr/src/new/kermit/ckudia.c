begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|dialv
init|=
literal|"Dial Command, V2.0(008) 26 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U D I A  --  Dialing program for connection to remote system */
end_comment

begin_comment
comment|/*  Author: Herm Fischer (HFISCHER@USC-ECLB)  Contributed to Columbia University for inclusion in C-Kermit.  Copyright (C) 1985, Herman Fischer, 16400 Ventura Blvd, Encino CA 91436  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.    ------   This module should work under all versions of Unix.  It calls externally  defined system-depended functions for i/o, but depends upon the existence  of various modem control functions.   This module, and the supporting routines in the ckutio.c module, assume  that the computer and modem properly utilize the following data communi-  cations signals (that means one should prepare the modem to use, not  circumvent, these signals):       Data Terminal Ready:  This signal is asserted by the computer      when Kermit is about to ask the modem to dial a call, and is      removed when Kermit wishes to have the modem hang up a call.      The signal is asserted both while Kermit is asking the modem      to dial a specific number, and after connection, while Kermit      is in a data exchange mode.         Carrier detect:  This signal must be asserted by the modem when      a carrier is detected from a remote modem on a communications      circuit.  It must be removed by the modem when the circuit      disconnects or is hung up.  (Carrier detect is ignored while      Kermit is asking the modem to dial the call, because there is      no consistant usage of this signal during the dialing phase      among different modem manufacturers.)  */
end_comment

begin_comment
comment|/*  * Modifications:  *  *	21-Jul-85	Fixed failure returns hanging on no carrier signal  *			Requires tthang change too (ckutio.c revision)  *							-- Herm Fischer  *  *	28-Jun-85	Fixed bug with defaulting the modem-failure message  *			in lbuf.  *							-- Dan Schullman  *  *	27-Jun-85	Merged in code from Joe Orost at Berkeley for  *			supporting the US Robotics modem, which included  *			changing the single characters in MDMINF into  *			multi-character strings and modifying waitFor.  *							-- Dan Schullman  *  *	26-Jun-85	Allow interrupts to be used to abort dialing,  *			and ring the bell when a connection is made.  *			Reorganized some of the failure paths to use the  *			same code, and now close the line on failures.  *			Allow use of stored numbers with the DF100 and  *			DF200 modems.  Handlers now declared after the  *			call to setjmp.  *							-- Dan Schullman  *  *	24-May-85	DF03, DF100-series, DF200-series, and "unknown" modem  *			support added.  Also restructured the various data  *			tables, fixed some bugs related to missing data and  *			missing case labels, and modified the failure message  *			to display the "reason" given by the modem.  *							-- Dan Schullman  */
end_comment

begin_comment
comment|/*  * To add support for another modem, do the following:  *  *	Define a modem number symbol (n_XXX) for it, keeping the list  *	in alphabetical and numerical order, and renumbering the values  *	as necessary.  *  *	Create a MDMINF structure for it, again keeping the list alphabetical  *	for sanity's sake.  *  *	Add the address of the MDMINF structure to the ptrtab array, again  *	in alphabetical and numerical order.  *  *	Add the "user visible" modem name and corresponding modem number to  *	the mdmtab array, again in alphabetical order.  *  *	Read through the code and add modem-specific sections as necessary.  */
end_comment

begin_comment
comment|/*  * The intent of the "unknown" modem is hopefully to allow KERMIT to support  * unknown modems by having the user type the entire autodial sequence  * (possibly including control characters, etc.) as the "phone number".  * The only reason that the CONNECT command cannot be used to do this is  * that a remote line cannot normally be opened unless carrier is present.  *  * The protocol and other characteristics of this modem are unknown, with  * some "reasonable" values being chosen for some of them.  The only way to  * detect if a connection is made is to look for carrier present.  *  * SUPPORT IS CURRENTLY ONLY PARTIALLY SKETCHED OUT FOR THIS.  ALSO, IT  * SHOULD PERHAPS BE HANDLED MUCH EARLIER, SIMPLY READING USER INPUT AND  * SENDING IT TO THE MODEM AND ECHOING MODEM RESPONSES BACK TO THE USER,  * ALL THE TIME LOOKING FOR CARRIER.  OF COURSE, THE PROBLEM THEN BECOMES  * ONE OF ALLOWING THE USER TO ABORT THE DIALING.  WE COULD CHOOSE SOME  * PHRASE THAT WOULD PRESUMABLY NEVER BE A PART OF A VALID AUTODIAL SEQUENCE  * (E.G., "QUIT" and "quit"). -- DS  */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
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
name|n_CERMETEK
value|1
end_define

begin_define
define|#
directive|define
name|n_DF03
value|2
end_define

begin_define
define|#
directive|define
name|n_DF100
value|3
end_define

begin_define
define|#
directive|define
name|n_DF200
value|4
end_define

begin_define
define|#
directive|define
name|n_GDC
value|5
end_define

begin_define
define|#
directive|define
name|n_HAYES
value|6
end_define

begin_define
define|#
directive|define
name|n_PENRIL
value|7
end_define

begin_define
define|#
directive|define
name|n_RACAL
value|8
end_define

begin_define
define|#
directive|define
name|n_UNKNOWN
value|9
end_define

begin_define
define|#
directive|define
name|n_USROBOT
value|10
end_define

begin_define
define|#
directive|define
name|n_VENTEL
value|11
end_define

begin_comment
comment|/*  * Declare modem "variant" numbers for any of the above for which it is  * necessary to note various operational modes, using the second byte  * of a modem number.  *  * It is assumed that such modem modes share the same modem-specific  * information (see MDMINF structure) but may differ in some of the actions  * that are performed.  */
end_comment

begin_define
define|#
directive|define
name|n_HAYESNV
value|( n_HAYES + ( 1<<8 ) )
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Declare structures containing modem-specific information.  *  * REMEMBER that only the first SEVEN characters of these  * names are guaranteed to be unique.  */
end_comment

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
literal|"  XY\016R\r"
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
literal|""
block|,
comment|/* dmode_prompt */
literal|"\016D '%s'\r"
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
literal|""
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
literal|""
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
literal|""
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
literal|"\r\r"
block|,
comment|/* wake_str */
literal|500
block|,
comment|/* wake_rate */
literal|"$"
block|,
comment|/* wake_prompt */
literal|"D\r"
block|,
comment|/* dmode_str */
literal|":"
block|,
comment|/* dmode_prompt */
literal|"T%s\r"
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
literal|"AT\r"
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
literal|"AT DT %s\r"
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
literal|"\r\r"
block|,
comment|/* wake_str */
literal|300
block|,
comment|/* wake_rate */
literal|">"
block|,
comment|/* wake_prompt */
literal|"k\r"
block|,
comment|/* dmode_str */
literal|":"
block|,
comment|/* dmode_prompt */
literal|"%s\r"
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
literal|"\005\r"
block|,
comment|/* wake_str */
literal|50
block|,
comment|/* wake_rate */
literal|"*"
block|,
comment|/* wake_prompt */
literal|"D\r"
block|,
comment|/* dmode_str */
literal|"?"
block|,
comment|/* dmode_prompt */
literal|"%s\r"
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
literal|""
block|,
comment|/* dmode_prompt */
literal|"%s\r"
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
literal|"ATS2=01\r"
block|,
comment|/* wake_str */
literal|0
block|,
comment|/* wake_rate */
literal|"OK\r"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str */
literal|""
block|,
comment|/* dmode_prompt */
literal|"ATTD%s\r"
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
literal|"\r\r\r"
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
literal|""
block|,
comment|/* dmode_prompt */
literal|"<K%s'r>"
block|,
comment|/* dial_str */
literal|0
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
literal|"cermetek"
block|,
name|n_CERMETEK
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
literal|"penril"
block|,
name|n_PENRIL
block|,
literal|0
block|,
literal|"racalvadic"
block|,
name|n_RACAL
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

begin_escape
end_escape

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

begin_define
define|#
directive|define
name|LBUFL
value|100
end_define

begin_decl_stmt
specifier|static
name|char
name|lbuf
index|[
name|LBUFL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|jmp_buf
name|sjbuf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|savAlrm
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for saving alarm handler */
end_comment

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|savInt
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for saving interrupt handler */
end_comment

begin_macro
name|dialtime
argument_list|()
end_macro

begin_block
block|{
comment|/* timer interrupt handler */
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_time
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|dialint
argument_list|()
end_macro

begin_comment
comment|/* user-interrupt handler */
end_comment

begin_block
block|{
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_int
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|ttolSlow
argument_list|(
argument|s
argument_list|,
argument|millisec
argument_list|)
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|millisec
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

begin_comment
comment|/*  * Wait for a string of characters.  *  * The characters are waited for individually, and other characters may  * be received "in between".  This merely guarantees that the characters  * ARE received, and in the order specified.  */
end_comment

begin_expr_stmt
specifier|static
name|waitFor
argument_list|(
argument|s
argument_list|)
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|CHAR
name|c
decl_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
operator|++
condition|)
comment|/* while more characters remain... */
while|while
condition|(
operator|(
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
operator|)
operator|!=
name|c
condition|)
empty_stmt|;
comment|/* wait for the character */
block|}
end_block

begin_expr_stmt
specifier|static
name|didWeGet
argument_list|(
argument|s
argument_list|,
argument|r
argument_list|)
name|char
operator|*
name|s
operator|,
operator|*
name|r
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* Looks in string s for response r */
name|int
name|lr
init|=
name|strlen
argument_list|(
name|r
argument_list|)
decl_stmt|;
comment|/*  0 means not found, 1 means found it */
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
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

begin_expr_stmt
specifier|static
name|reset
argument_list|()
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
block|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|savAlrm
argument_list|)
block|;
comment|/* restore alarm handler */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|savInt
argument_list|)
block|;
comment|/* restore interrupt handler */
block|}
comment|/*  D I A L  --  Dial up the remote system */
name|dial
argument_list|(
argument|telnbr
argument_list|)
name|char
operator|*
name|telnbr
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
name|char
modifier|*
name|i
decl_stmt|,
modifier|*
name|j
decl_stmt|;
name|int
name|waitct
decl_stmt|,
name|status
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
name|augmdmtyp
decl_stmt|;
comment|/* "augmented" modem type, to handle modem modes */
name|int
name|mdmEcho
init|=
literal|0
decl_stmt|;
comment|/* assume modem does not echo */
name|int
name|n
decl_stmt|,
name|n1
decl_stmt|;
name|char
modifier|*
name|pc
decl_stmt|;
comment|/* pointer to a character */
if|if
condition|(
operator|!
name|mdmtyp
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set modem' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
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
operator|-
literal|2
operator|)
return|;
block|}
if|if
condition|(
name|speed
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must 'set speed' first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mdmtyp
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Open, no wait for carrier */
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
operator|-
literal|2
operator|)
return|;
block|}
name|pmdminf
operator|=
name|ptrtab
index|[
name|mdmtyp
operator|-
literal|1
index|]
expr_stmt|;
comment|/* set pointer to modem info */
name|augmdmtyp
operator|=
name|mdmtyp
expr_stmt|;
comment|/* initialize "augmented" modem type */
comment|/* cont'd... */
comment|/* interdigit waits for tone dial */
comment|/* ...dial, cont'd */
name|waitct
operator|=
literal|1
operator|*
name|strlen
argument_list|(
name|telnbr
argument_list|)
expr_stmt|;
comment|/* compute time to dial worst case */
name|waitct
operator|+=
name|pmdminf
operator|->
name|dial_time
expr_stmt|;
comment|/* dialtone + completion wait times */
for|for
control|(
name|i
operator|=
name|telnbr
init|;
operator|*
name|i
condition|;
name|i
operator|++
control|)
comment|/* add in pause characters time */
for|for
control|(
name|j
operator|=
name|pmdminf
operator|->
name|pause_chars
init|;
operator|*
name|j
condition|;
name|j
operator|++
control|)
if|if
condition|(
operator|*
name|i
operator|==
operator|*
name|j
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
name|printf
argument_list|(
literal|"Dialing thru %s, speed %d, number %s.\r\n"
argument_list|,
name|ttname
argument_list|,
name|speed
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"The timeout for completing the call is %d seconds.\r\n"
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Type the interrupt character to cancel the dialing.\r\n"
argument_list|)
expr_stmt|;
comment|/* Hang up the modem (in case it wasn't "on hook") */
if|if
condition|(
name|tthang
argument_list|()
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, Can't hang up tty line\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
comment|/* Condition console terminal and communication line */
comment|/* place line into "clocal" dialing state */
if|if
condition|(
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|DIALING
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
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
comment|/*  * Establish jump vector, or handle "failure" jumps.  */
if|if
condition|(
name|n
operator|=
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
comment|/* if a "failure jump" was taken... */
block|{
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* disable timeouts */
if|if
condition|(
name|n1
operator|=
name|setjmp
argument_list|(
name|sjbuf
argument_list|)
condition|)
comment|/* failure while handling failure */
block|{
name|printf
argument_list|(
literal|"%s failure while handling failure.\r\n"
argument_list|,
name|F_reason
index|[
name|n1
index|]
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* first (i.e., non-nested) failure */
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
comment|/* be sure to catch signals */
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
name|alarm
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* be sure to get out of this section */
name|ttclos
argument_list|()
expr_stmt|;
comment|/* hangup and close the line */
block|}
switch|switch
condition|(
name|n
condition|)
comment|/* type of failure */
block|{
case|case
name|F_time
case|:
comment|/* timed out */
block|{
name|printf
argument_list|(
literal|"No connection made within the allotted time.\r\n"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|F_int
case|:
comment|/* dialing interrupted */
block|{
name|printf
argument_list|(
literal|"Dialing interrupted.\r\n"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|F_modem
case|:
comment|/* modem detected a failure */
block|{
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
literal|"\").\r\n"
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|F_minit
case|:
comment|/* cannot initialize modem */
block|{
name|printf
argument_list|(
literal|"Cannot initialize modem.\r\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|reset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
return|return
operator|(
operator|-
literal|2
operator|)
return|;
comment|/* exit with failure code */
block|}
comment|/*  * Set timer and interrupt handlers.  */
name|savAlrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
comment|/* set alarm handler */
if|if
condition|(
operator|(
name|savInt
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
comment|/* set int handler if not ignored */
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* give modem 10 seconds to wake up */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* flush input buffer if any */
comment|/*  * Put modem in command mode.  */
define|#
directive|define
name|OKAY
value|1
comment|/* modem attention attempt status */
define|#
directive|define
name|IGNORE
value|2
define|#
directive|define
name|GOT_O
value|-2
define|#
directive|define
name|GOT_A
value|-3
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_HAYES
case|:
case|case
name|n_HAYESNV
case|:
while|while
condition|(
name|tries
operator|++
operator|<
literal|4
condition|)
block|{
name|ttol
argument_list|(
name|HAYES
operator|.
name|wake_str
argument_list|,
name|strlen
argument_list|(
name|HAYES
operator|.
name|wake_str
argument_list|)
argument_list|)
expr_stmt|;
comment|/* wakeup */
name|status
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|status
operator|<=
literal|0
condition|)
block|{
switch|switch
condition|(
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
condition|)
block|{
case|case
literal|'A'
case|:
comment|/* echoing, ignore */
name|status
operator|=
name|GOT_A
expr_stmt|;
break|break;
case|case
literal|'T'
case|:
if|if
condition|(
name|status
operator|==
name|GOT_A
condition|)
block|{
name|mdmEcho
operator|=
literal|1
expr_stmt|;
comment|/* expect echoing later */
name|status
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|status
operator|=
name|IGNORE
expr_stmt|;
break|break;
case|case
literal|'\n'
case|:
case|case
literal|'\r'
case|:
name|status
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'0'
case|:
comment|/* numeric result code */
name|augmdmtyp
operator|=
name|n_HAYESNV
expr_stmt|;
comment|/* nonverbal result codes */
name|status
operator|=
name|OKAY
expr_stmt|;
break|break;
case|case
literal|'O'
case|:
comment|/* maybe English result code*/
name|status
operator|=
name|GOT_O
expr_stmt|;
break|break;
case|case
literal|'K'
case|:
if|if
condition|(
name|status
operator|==
name|GOT_O
condition|)
block|{
name|augmdmtyp
operator|=
name|n_HAYES
expr_stmt|;
name|status
operator|=
name|OKAY
expr_stmt|;
break|break;
block|}
comment|/* else its default anyway */
default|default:
name|status
operator|=
name|IGNORE
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|status
operator|==
name|OKAY
condition|)
break|break;
if|if
condition|(
name|status
operator|==
name|IGNORE
condition|)
name|ttflui
argument_list|()
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* wait before retrying */
block|}
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
break|break;
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
comment|/* modem-initialization failure */
comment|/* cont'd... */
comment|/* interdigit waits for tone dial */
comment|/* ...dial, cont'd */
default|default:
comment|/* place modem into command mode */
name|ttolSlow
argument_list|(
name|pmdminf
operator|->
name|wake_str
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
name|waitFor
argument_list|(
name|pmdminf
operator|->
name|wake_prompt
argument_list|)
expr_stmt|;
break|break;
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off alarm */
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* give things settling time */
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* alarm on dialing prompts */
comment|/* Dial the number */
comment|/* put modem into dialing mode */
name|ttolSlow
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
if|if
condition|(
name|pmdminf
operator|->
name|dmode_prompt
condition|)
block|{
comment|/* wait for prompt, if any expected */
name|waitFor
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
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off alarm on dialing prompts */
name|alarm
argument_list|(
name|waitct
argument_list|)
expr_stmt|;
comment|/* time to allow for connecting */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* clear out stuff from waking modem up */
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
comment|/* form dialing string */
name|ttolSlow
argument_list|(
name|lbuf
argument_list|,
name|pmdminf
operator|->
name|dial_rate
argument_list|)
expr_stmt|;
comment|/* send dialing string */
if|if
condition|(
name|augmdmtyp
operator|==
name|n_RACAL
condition|)
block|{
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
literal|'\r'
argument_list|)
expr_stmt|;
block|}
comment|/* cont'd... */
comment|/* interdigit waits for tone dial */
comment|/* ...dial, cont'd */
comment|/* Check for connection */
comment|/*  * I believe we also need to look for carrier in order to determine if a  * connection has been made.  In fact, for many we may only want to look for  * the "failure" responses in order to short-circuit the timeout, and let  * carrier be the determination of whether a connection has been made. -- DS  */
name|status
operator|=
literal|0
expr_stmt|;
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"No Connection"
argument_list|)
expr_stmt|;
comment|/* default failure reason */
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
operator|(
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
operator|)
expr_stmt|;
if|if
condition|(
name|lbuf
index|[
name|n
index|]
operator|==
literal|'\r'
operator|||
name|lbuf
index|[
name|n
index|]
operator|==
literal|'\n'
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
comment|/* terminate response from modem */
if|if
condition|(
name|n
condition|)
block|{
comment|/* if one or more characters present */
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_CERMETEK
case|:
if|if
condition|(
name|didWeGet
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
name|ttolSlow
argument_list|(
literal|"\016U 1\r"
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
comment|/* DF100 won't generate some of these */
case|case
name|n_DF200
case|:
if|if
condition|(
name|didWeGet
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
comment|/* 		     * The DF100 will respond with "Attached" even if DTR 		     * and/or carrier are not present.  Another reason to 		     * (also) wait for carrier? 		     */
if|if
condition|(
name|didWeGet
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
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"Disconnected"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"Error"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"No answer"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"No dial tone"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
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
comment|/* 		     * It appears that the "Speed:..." response comes after an 		     * "Attached" response, so this is never seen.  HOWEVER, 		     * it would be very handy to detect this and temporarily 		     * reset the speed, since it's a nuiscance otherwise. 		     * If we wait for some more input from the modem, how do 		     * we know if it's from the remote host or the modem? 		     * Carrier reportedly doesn't get set until after the 		     * "Speed:..." response (if any) is sent.  Another reason 		     * to (also) wait for carrier. 		     */
break|break;
case|case
name|n_GDC
case|:
if|if
condition|(
name|didWeGet
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
if|if
condition|(
name|didWeGet
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
if|if
condition|(
name|didWeGet
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
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"NO CARRIER"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_PENRIL
case|:
if|if
condition|(
name|didWeGet
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
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
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
name|didWeGet
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
if|if
condition|(
name|didWeGet
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
name|n_VENTEL
case|:
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"ONLINE!"
argument_list|)
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"BUSY"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|didWeGet
argument_list|(
name|lbuf
argument_list|,
literal|"DEAD PHONE"
argument_list|)
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
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
name|c
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
if|if
condition|(
name|mdmEcho
condition|)
block|{
comment|/* sponge up dialing string */
name|mdmEcho
operator|=
name|c
operator|!=
literal|'\r'
expr_stmt|;
comment|/* until return is echoed */
break|break;
block|}
if|if
condition|(
name|c
operator|==
literal|'1'
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'3'
condition|)
name|status
operator|=
name|FAILED
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'5'
condition|)
name|status
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
name|n_UNKNOWN
case|:
comment|/** SHOULD WAIT FOR CARRIER OR TIMEOUT -- DS **/
break|break;
block|}
comment|/* switch (augmdmtyp) */
block|}
comment|/* while status == 0 */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* turn off alarm on connecting */
if|if
condition|(
name|status
operator|!=
name|CONNECTED
condition|)
comment|/* modem-detected failure */
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_modem
argument_list|)
expr_stmt|;
comment|/* exit (with reason in lbuf) */
name|alarm
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* precaution in case of trouble */
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|CONNECT
argument_list|)
expr_stmt|;
comment|/* cancel dialing state ioctl */
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
literal|"Call completed.\07\r\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* return, and presumably connect */
block|}
end_block

end_unit

