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
literal|"Dial Command, 5A(046) 2 Nov 92"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U D I A	 --  Module for automatic modem dialing. */
end_comment

begin_comment
comment|/*   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University.    Original (version 1, 1985) author: Herm Fischer, Encino, CA.   Contributed to Columbia University in 1985 for inclusion in C-Kermit 4.0.   Author and maintainer since 1985: Frank da Cruz, Columbia University,   fdc@columbia.edu.    Contributions by many others throughout the years, including: Fernando   Cabral, John Chmielewski, Joe Doupnik, Richard Hill, Larry Jacobs, Eric   Jones, Tom Kloos, Bob Larson, Peter Mauzey, Joe Orost, Kevin O'Gorman, Kai   Uwe Rommel, Dan Schullman, Warren Tucker, and others too numerous to list   here (but see acknowledgements in ckcmai.c).    This module calls externally defined system-dependent functions for   communications i/o, as defined in CKCPLM.DOC, the C-Kermit Program Logic   Manual, and thus should be portable to all systems that implement those   functions, and where alarm() and signal() work as they do in UNIX. */
end_comment

begin_comment
comment|/*   To add support for another modem, do the following, all in this module:    1. Define a modem-type number symbol (n_XXX) for it.    2. Adjust MAX_MDM to the new number of modem types.    3. Create a MDMINF structure for it.    4. Add the address of the MDMINF structure to the ptrtab[] array,      according to the numerical value of the modem-type number.    5. Add the user-visible (SET MODEM) name and corresponding modem      number to the mdmtab[] array, in alphabetical order by modem-name string.    6. Read through the code and add modem-specific sections as necessary.    NOTE: The MINIDIAL symbol is used to build this module to include support   for only a minimum number of standard and/or generally useful modem types,   namely Hayes, CCITT V.25bis, "Unknown", and None.  When adding support for   a new modem type, keep it outside of the MINIDIAL sections. */
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

begin_include
include|#
directive|include
file|"ckcnet.h"
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
name|int
comment|/* SET DIAL parameters */
name|dialhng
init|=
literal|1
decl_stmt|,
comment|/* DIAL HANGUP, default is ON */
name|dialdpy
init|=
literal|0
decl_stmt|,
comment|/* DIAL DISPLAY, default is OFF */
name|mdmspd
init|=
literal|1
decl_stmt|,
comment|/* DIAL SPEED-MATCHING (1 = ON) */
name|dialtmo
init|=
literal|0
decl_stmt|,
comment|/* DIAL TIMEOUT */
name|dialksp
init|=
literal|0
decl_stmt|,
comment|/* DIAL KERMIT-SPOOF */
name|dialmnp
init|=
literal|0
decl_stmt|,
comment|/* DIAL MNP-ENABLE */
ifdef|#
directive|ifdef
name|NOMDMHUP
name|dialmhu
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIAL MODEM-HANGUP */
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|dialmhu
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* DIAL MODEM-HANGUP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMDMHUP */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialdir
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIAL DIRECTORY, default none */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialini
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIAL INIT-STRING, default none */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialcmd
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIAL DIAL-COMMAND, default none */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialnpr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIAL NUMBER-PREFIX, ditto */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|dialfd
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor of dial directory */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

begin_comment
comment|/*   Telebit model codes:    ATI  Model Numbers           Examples   ---  -------------           --------   123                          Telebit in "total Hayes-1200" emulation mode   960                          Telebit in Conventional Command (Hayes) mode   961  RA12C                   IBM PC internal original Trailblazer   962  RA12E                   External original Trailblazer   963  RM12C                   Rackmount original Trailblazer   964  T18PC                   IBM PC internal Trailblazer-Plus (TB+)   965  T18SA, T2SAA, T2SAS     External TB+, T1600, T2000, T3000, WB, and later   966  T18RMM                  Rackmount TB+   967  T2MC                    IBM PS/2 internal TB+   968  T1000                   External T1000   969  ?                       Qblazer   971  T2500                   External T2500   972  T2500                   Rackmount T2500 */
end_comment

begin_comment
comment|/* Telebit model codes */
end_comment

begin_define
define|#
directive|define
name|TB_UNK
value|0
end_define

begin_comment
comment|/* Unknown Telebit model */
end_comment

begin_define
define|#
directive|define
name|TB_BLAZ
value|1
end_define

begin_comment
comment|/* Original TrailBlazer */
end_comment

begin_define
define|#
directive|define
name|TB_PLUS
value|2
end_define

begin_comment
comment|/* TrailBlazer Plus */
end_comment

begin_define
define|#
directive|define
name|TB_1000
value|3
end_define

begin_comment
comment|/* T1000 */
end_comment

begin_define
define|#
directive|define
name|TB_1500
value|4
end_define

begin_comment
comment|/* T1500 */
end_comment

begin_define
define|#
directive|define
name|TB_1600
value|5
end_define

begin_comment
comment|/* T1600 */
end_comment

begin_define
define|#
directive|define
name|TB_2000
value|6
end_define

begin_comment
comment|/* T2000 */
end_comment

begin_define
define|#
directive|define
name|TB_2500
value|7
end_define

begin_comment
comment|/* T2500 */
end_comment

begin_define
define|#
directive|define
name|TB_3000
value|8
end_define

begin_comment
comment|/* T3000 */
end_comment

begin_define
define|#
directive|define
name|TB_QBLA
value|9
end_define

begin_comment
comment|/* Qblazer */
end_comment

begin_define
define|#
directive|define
name|TB_WBLA
value|10
end_define

begin_comment
comment|/* WorldBlazer */
end_comment

begin_define
define|#
directive|define
name|TB__MAX
value|10
end_define

begin_comment
comment|/* Highest number */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tb_name
index|[]
init|=
block|{
comment|/* Array of model names */
literal|"Unknown"
block|,
comment|/* TB_UNK  */
literal|"TrailBlazer"
block|,
comment|/* TB_BLAZ */
literal|"TrailBlazer-Plus"
block|,
comment|/* TB_PLUS */
literal|"T1000"
block|,
comment|/* TB_1000 */
literal|"T1500"
block|,
comment|/* TB_1500 */
literal|"T1600"
block|,
comment|/* TB_1600 */
literal|"T2000"
block|,
comment|/* TB_2000 */
literal|"T2500"
block|,
comment|/* TB_2500 */
literal|"T3000"
block|,
comment|/* TB_3000 */
literal|"Qblazer"
block|,
comment|/* TB_QBLA */
literal|"WorldBlazer"
block|,
comment|/* TB_WBLA */
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
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
name|backgrd
decl_stmt|,
name|parity
decl_stmt|,
name|seslog
decl_stmt|,
name|network
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|carrier
decl_stmt|,
name|duplex
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NETCONN
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ttnproto
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

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

begin_macro
name|_PROTOTYP
argument_list|(
argument|static int ddinc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
argument|(int,int)
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

begin_macro
name|_PROTOTYP
argument_list|(
argument|static VOID tbati3
argument_list|,
argument|(int n)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|int
name|esc_time
decl_stmt|;
comment|/* guard time on escape sequence (msecs) */
name|char
modifier|*
name|esc_str
decl_stmt|;
comment|/* escape sequence */
name|char
modifier|*
name|hup_str
decl_stmt|;
comment|/* hangup string */
name|_PROTOTYP
argument_list|(
name|int
argument_list|(
operator|*
name|ok_fn
argument_list|)
argument_list|,
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* func to read response string */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Define symbolic modem numbers.  *  * The numbers MUST correspond to the ordering of entries  * within the ptrtab array, and start at one (1).  *  * It is assumed that there are relatively few of these  * values, and that the high(er) bytes of the value may  * be used for modem-specific mode information.  *  * REMEMBER that only the first eight characters of these  * names are guaranteed to be unique.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIDIAL
end_ifdef

begin_comment
comment|/* Minimum dialer support */
end_comment

begin_comment
comment|/* Only for CCITT, HAYES, and UNK */
end_comment

begin_define
define|#
directive|define
name|n_CCITT
value|1
end_define

begin_define
define|#
directive|define
name|n_HAYES
value|2
end_define

begin_define
define|#
directive|define
name|n_UNKNOWN
value|3
end_define

begin_define
define|#
directive|define
name|MAX_MDM
value|3
end_define

begin_comment
comment|/* Number of modem types */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Full-blown dialer support */
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
name|n_CCITT
value|4
end_define

begin_define
define|#
directive|define
name|n_CERMETEK
value|5
end_define

begin_define
define|#
directive|define
name|n_DF03
value|6
end_define

begin_define
define|#
directive|define
name|n_DF100
value|7
end_define

begin_define
define|#
directive|define
name|n_DF200
value|8
end_define

begin_define
define|#
directive|define
name|n_GDC
value|9
end_define

begin_define
define|#
directive|define
name|n_HAYES
value|10
end_define

begin_define
define|#
directive|define
name|n_PENRIL
value|11
end_define

begin_define
define|#
directive|define
name|n_RACAL
value|12
end_define

begin_define
define|#
directive|define
name|n_UNKNOWN
value|13
end_define

begin_define
define|#
directive|define
name|n_USROBOT
value|14
end_define

begin_define
define|#
directive|define
name|n_VENTEL
value|15
end_define

begin_define
define|#
directive|define
name|n_CONCORD
value|16
end_define

begin_define
define|#
directive|define
name|n_ATTUPC
value|17
end_define

begin_comment
comment|/* aka UNIX PC and ATT7300 */
end_comment

begin_define
define|#
directive|define
name|n_ROLM
value|18
end_define

begin_comment
comment|/* Rolm CBX DCM */
end_comment

begin_define
define|#
directive|define
name|n_MICROCOM
value|19
end_define

begin_define
define|#
directive|define
name|n_HST
value|20
end_define

begin_define
define|#
directive|define
name|n_TELEBIT
value|21
end_define

begin_comment
comment|/* Telebits of all kinds */
end_comment

begin_define
define|#
directive|define
name|n_DIGITEL
value|22
end_define

begin_comment
comment|/* Digitel DT-22 (CCITT variant) */
end_comment

begin_define
define|#
directive|define
name|MAX_MDM
value|22
end_define

begin_comment
comment|/* Number of modem types */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

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
name|n_HAYESNV
value|( n_HAYES   | DIAL_NV )
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_comment
comment|/*  * Declare structures containing modem-specific information.  *  * REMEMBER that only the first SEVEN characters of these  * names are guaranteed to be unique.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|CCITT
init|=
comment|/* CCITT V.25bis autodialer */
comment|/*   According to V.25bis:   . Even parity is required for giving commands to the modem.   . Commands might or might not echo.   . Responses ("Indications") from the modem are terminated by CR and LF.   . Call setup is accomplished by:     - DTE raises DTR (V.24 circuit 108)              [ttopen() does this]     - Modem raises CTS (V.24 circuit 106)            [C-Kermit ignores this]     - DTE issues a call request command ("CRN")     - Modem responds with "VAL" ("command accepted")     - If the call is completed:         modem responds with "CNX" ("call connected");         modem turns CTS (106) OFF;         modem turns DSR (107) ON;       else:         modem responds with "CFI<parameter>" ("call failure indication").   . To clear a call, the DTE turns DTR (108) OFF.   . There is no mention of the Carrier Detect circuit (109) in the standard.   . There is no provision for "escaping back" to the modem's command mode.    It is not known whether there exists in real life a pure V.25bis modem.   If there is, this code has never been tested on it.  See the Digitel entry. */
block|{
literal|40
block|,
comment|/* dial_time -- programmable -- */
literal|",:"
block|,
comment|/* pause_chars -- "," waits for programmable time */
comment|/* ":" waits for dial tone */
literal|10
block|,
comment|/* pause_time (seconds, just a guess) */
literal|""
block|,
comment|/* wake_str (none) */
literal|200
block|,
comment|/* wake_rate (msec) */
literal|"VAL"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str (none) */
literal|""
block|,
comment|/* dmode_prompt (none) */
literal|"CRN%s\015"
block|,
comment|/* dial_str */
literal|200
block|,
comment|/* dial_rate (msec) */
literal|0
block|,
comment|/* No esc_time */
literal|""
block|,
comment|/* No esc_str  */
literal|""
block|,
comment|/* No hup_str  */
name|NULL
comment|/* No ok_fn    */
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

begin_comment
comment|/* Don't include the following if -DMINIDIAL ... */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|CERMETEK
init|=
comment|/* Information for "Cermetek Info-Mate 212 A" modem */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|DIGITEL
init|=
comment|/* Digitel DT-22 CCITT variant used in Brazil */
comment|/*   Attempts to adhere strictly to the V.25bis specification do not produce good   results in real life.  The modem for which this code was developed: (a)   ignores parity; (b) sometimes terminates responses with LF CR instead of CR   LF; (c) has a Hayes-like escape sequence; (d) supports a hangup ("HUP")   command.  Information from Fernando Cabral in Brasilia. */
block|{
literal|40
block|,
comment|/* dial_time -- programmable -- */
literal|",:"
block|,
comment|/* pause_chars -- "," waits for programmable time */
comment|/* ":" waits for dial tone */
literal|10
block|,
comment|/* pause_time (seconds, just a guess) */
literal|"HUP\015"
block|,
comment|/* wake_str (Not Standard CCITT) */
literal|200
block|,
comment|/* wake_rate (msec) */
literal|"VAL"
block|,
comment|/* wake_prompt */
literal|""
block|,
comment|/* dmode_str (none) */
literal|""
block|,
comment|/* dmode_prompt (none) */
literal|"CRN%s\015"
block|,
comment|/* dial_str */
literal|200
block|,
comment|/* dial_rate (msec) */
literal|1100
block|,
comment|/* esc_time (Not Standard CCITT) */
literal|"+++"
block|,
comment|/* esc_str  (Not Standard CCITT) */
literal|"HUP\015"
block|,
comment|/* hup_str  (Not Standard CCITT) */
name|getok
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
name|HAYES
init|=
comment|/* Information for Hayes and Hayes-like modems */
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
literal|"ATQ0\015"
block|,
comment|/* wake_str */
comment|/*   Note: Other wake_str's are possible here.  For a Hayes 2400 that is to   be used for both in and out calls, AT&F&D3 might be best.  For out calls   only, maybe AT&F&D2.  See Hayes 2400 manual. */
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
block|,
comment|/* dial_rate */
literal|1100
block|,
comment|/* esc_time */
literal|"+++"
block|,
comment|/* esc_str */
literal|"ATQ0H0\015"
block|,
comment|/* hup_str */
name|getok
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MDMINF
name|RACAL
init|=
comment|/* information for "Racal Vadic" modem, e.g. VA4492E */
block|{
literal|35
block|,
comment|/* dial_time (manual says modem is hardwired to 60) */
literal|"Kk"
block|,
comment|/* pause_chars */
literal|5
block|,
comment|/* pause_time */
literal|"\005\015"
block|,
comment|/* wake_str, ^E^M */
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
block|,
comment|/* dial_rate */
literal|1100
block|,
comment|/* esc_time */
literal|"\003\004"
block|,
comment|/* esc_str, ^C^D (this actually hangs up) */
literal|"\005"
block|,
comment|/* hup_str, ^E (this goes back to command mode) */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_comment
comment|/*   The intent of the "unknown" modem is to allow KERMIT to support   unknown modems by having the user type the entire autodial sequence   (possibly including control characters, etc.) as the "phone number".   The protocol and other characteristics of this modem are unknown, with   some "reasonable" values being chosen for some of them.  The only way to   detect if a connection is made is to look for carrier. */
end_comment

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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
block|,
comment|/* dial_rate */
literal|0
block|,
comment|/* esc_time */
literal|""
block|,
comment|/* esc_str */
literal|""
block|,
comment|/* hup_str */
name|NULL
comment|/* ok_fn */
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
literal|"ATQ0S2=43X7&B1&M4\015"
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
block|,
comment|/* dial_rate */
literal|1100
block|,
comment|/* esc_time */
literal|"+++"
block|,
comment|/* esc_str */
literal|"ATQ0H0\015"
block|,
comment|/* hup_str */
name|getok
comment|/* ok_fn */
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
comment|/*   NOTE: The wake_string MUST contain the I command (model query), and otherwise   must contain commands that work on ALL Telebit models.  Here we ensure that   result codes are returned (Q0), and ask for extended result codes (X1), and   ensure that the escape sequence is +++ and it is enabled.  And also, make   sure the final character is not a digit (whose echo might be mistaken for a   result code).  The Ctrl-Q and multiple A's are recommended by Telebit. */
literal|"\021AAAATQ0X1S12=50 S2=43 I\015"
block|,
comment|/* wake_str. */
literal|100
block|,
comment|/* wake_rate = 100 msec */
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
comment|/* dial_str, Note: no T or P */
literal|80
block|,
comment|/* dial_rate */
literal|1100
block|,
comment|/* esc_time (guard time) */
literal|"+++"
block|,
comment|/* esc_str */
literal|"ATQ0H0\015"
block|,
comment|/* hup_str */
name|getok
comment|/* ok_fn */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Declare table for converting modem numbers to information pointers.  *  * The entries MUST be in ascending order by modem number, without any  * "gaps" in the numbers, and starting from one (1).  *  * This table should NOT include entries for the "variant" modem numbers,  * since they share the same information as the normal value.  */
end_comment

begin_decl_stmt
specifier|static
name|MDMINF
modifier|*
name|ptrtab
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|MINIDIAL
operator|&
name|CCITT
block|,
operator|&
name|HAYES
block|,
operator|&
name|UNKNOWN
else|#
directive|else
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
name|CCITT
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
operator|&
name|ROLM
block|,
operator|&
name|MICROCOM
block|,
operator|&
name|HST
block|,
operator|&
name|TELEBIT
block|,
operator|&
name|DIGITEL
endif|#
directive|endif
comment|/* MINIDIAL */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Declare modem names and associated numbers for command parsing,  * and also for doing number-to-name translation.  *  * The entries must be in alphabetical order by modem name.  */
end_comment

begin_decl_stmt
name|struct
name|keytab
name|mdmtab
index|[]
init|=
block|{
ifndef|#
directive|ifndef
name|MINIDIAL
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
endif|#
directive|endif
comment|/* MINIDIAL */
literal|"ccitt-v25bis"
block|,
name|n_CCITT
block|,
literal|0
block|,
ifndef|#
directive|ifndef
name|MINIDIAL
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
literal|"digitel-dt22"
block|,
name|n_DIGITEL
block|,
literal|0
block|,
endif|#
directive|endif
comment|/* MINIDIAL */
literal|"direct"
block|,
literal|0
block|,
name|CM_INV
block|,
comment|/* Synonym for NONE */
ifndef|#
directive|ifndef
name|MINIDIAL
literal|"gdc-212a/ed"
block|,
name|n_GDC
block|,
literal|0
block|,
literal|"gendatacomm"
block|,
name|n_GDC
block|,
name|CM_INV
block|,
comment|/* Synonym for GDC */
endif|#
directive|endif
comment|/* MINIDIAL */
literal|"hayes"
block|,
name|n_HAYES
block|,
literal|0
block|,
ifndef|#
directive|ifndef
name|MINIDIAL
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
endif|#
directive|endif
comment|/* MINIDIAL */
literal|"none"
block|,
literal|0
block|,
literal|0
block|,
ifndef|#
directive|ifndef
name|MINIDIAL
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
endif|#
directive|endif
comment|/* MINIDIAL */
literal|"unknown"
block|,
name|n_UNKNOWN
block|,
literal|0
block|,
ifndef|#
directive|ifndef
name|MINIDIAL
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
endif|#
directive|endif
comment|/* MINIDIAL */
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
comment|/* Number of modems */
end_comment

begin_define
define|#
directive|define
name|CONNECTED
value|1
end_define

begin_comment
comment|/* For completion status */
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
comment|/* Failure reasons for message */
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
init|=
name|NULL
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

begin_define
define|#
directive|define
name|RBUFL
value|63
end_define

begin_decl_stmt
specifier|static
name|char
name|rbuf
index|[
name|RBUFL
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modem response buffer */
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
comment|/* For saving alarm handler */
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
comment|/* For saving interrupt handler */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

begin_decl_stmt
name|int
name|tbmodel
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Telebit modem model */
end_comment

begin_function
name|char
modifier|*
name|gtbmodel
parameter_list|()
block|{
comment|/* Function to return name of Telebit model */
if|if
condition|(
name|tbmodel
operator|<
literal|0
operator|||
name|tbmodel
operator|>
name|TB__MAX
condition|)
name|tbmodel
operator|=
name|TB_UNK
expr_stmt|;
return|return
operator|(
name|tb_name
index|[
name|tbmodel
index|]
operator|)
return|;
block|}
end_function

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

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
comment|/* Timer interrupt handler */
name|n1
operator|=
name|F_time
expr_stmt|;
comment|/* Failure reason = timeout */
ifdef|#
directive|ifdef
name|__EMX__
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|SIG_ACK
argument_list|)
expr_stmt|;
comment|/* Needed for OS/2 */
endif|#
directive|endif
comment|/* __EMX__ */
ifdef|#
directive|ifdef
name|OSK
comment|/* OS-9 */
comment|/*   We are in an intercept routine but do not perform a F$RTE (done implicitly   by RTS), so we have to decrement the sigmask as F$RTE does.  Warning:   longjump only restores the CPU registers, NOT the FPU registers.  So, don't   use FPU at all or at least don't use common FPU (double or float) register   variables. */
name|sigmask
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OSK */
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
comment|/* Keyboard interrupt handler */
name|n1
operator|=
name|F_int
expr_stmt|;
ifdef|#
directive|ifdef
name|__EMX__
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_ACK
argument_list|)
expr_stmt|;
comment|/* Needed for OS/2 */
endif|#
directive|endif
comment|/* __EMX__ */
ifdef|#
directive|ifdef
name|OSK
comment|/* OS-9, see comment in dialtime() */
name|sigmask
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OSK */
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_int
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*   Routine to read a character from communication device, handling TELNET   protocol negotiations in case we're connected to the modem through a   TCP/IP TELNET modem server. */
end_comment

begin_function
specifier|static
name|int
name|ddinc
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
name|int
name|c
decl_stmt|;
ifdef|#
directive|ifdef
name|TNCODE
name|int
name|done
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|!
name|done
condition|)
block|{
name|c
operator|=
name|ttinc
argument_list|(
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"ddinc"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
return|return
operator|(
name|c
operator|)
return|;
if|if
condition|(
name|c
operator|==
name|IAC
operator|&&
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
condition|)
block|{
switch|switch
condition|(
name|tn_doop
argument_list|(
call|(
name|CHAR
call|)
argument_list|(
name|c
operator|&
literal|0xff
argument_list|)
argument_list|,
name|duplex
argument_list|,
name|ttinc
argument_list|)
condition|)
block|{
case|case
literal|2
case|:
name|duplex
operator|=
literal|0
expr_stmt|;
continue|continue;
case|case
literal|1
case|:
name|duplex
operator|=
literal|1
expr_stmt|;
default|default:
continue|continue;
block|}
block|}
else|else
name|done
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|c
operator|&
literal|0xff
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|ttinc
argument_list|(
name|n
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* TNCODE */
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
comment|/* Output s-l-o-w-l-y */
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
name|ddinc
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
name|dreset
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
ifdef|#
directive|ifdef
name|CK_ANSIC
name|spdchg
parameter_list|(
name|long
name|s
parameter_list|)
else|#
directive|else
function|spdchg
parameter_list|(
name|s
parameter_list|)
name|long
name|s
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* spdchg */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MINIDIAL
end_ifndef

begin_comment
comment|/*   tbati3() -- Routine to find out Telebit model when ATI reports "965"   or "971". This routine sends another query, ATI3, to get further info   to narrow down the model number.  Argument is ATI response as integer.   Result: sets tbmodel variable to Telebit model. */
end_comment

begin_function
specifier|static
name|VOID
name|tbati3
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
name|int
name|status
decl_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer */
name|ttslow
argument_list|(
literal|"ATI3\015"
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|/* Send ATI3<CR> */
name|status
operator|=
name|getok
argument_list|(
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Get OK response, nonstrict */
if|if
condition|(
name|status
operator|<
literal|1
condition|)
block|{
comment|/* ERROR or timeout */
name|tbmodel
operator|=
name|TB_UNK
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"tbati3 fails"
argument_list|,
name|rbuf
argument_list|,
name|status
argument_list|)
expr_stmt|;
return|return;
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"tbati3 rbuf"
argument_list|,
name|rbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Got a good response, check the model info */
if|if
condition|(
name|n
operator|==
literal|965
condition|)
block|{
comment|/* "965" - various models. */
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"T1600"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_1600
expr_stmt|;
comment|/* T1600 */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"T3000"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_3000
expr_stmt|;
comment|/* T3000 */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"World"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_WBLA
expr_stmt|;
comment|/* WorldBlazer */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"Version B"
argument_list|)
operator|||
comment|/* TrailBlazer-Plus models */
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"TBSA"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"TBRM"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"DC"
argument_list|)
condition|)
block|{
comment|/* Ven-Tel EC18K */
name|tbmodel
operator|=
name|TB_PLUS
expr_stmt|;
block|}
else|else
name|tbmodel
operator|=
name|TB_UNK
expr_stmt|;
comment|/* Others: Unknown */
block|}
elseif|else
if|if
condition|(
name|n
operator|==
literal|971
condition|)
block|{
comment|/* "971" could be T1500 or T1600. */
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"T1500"
argument_list|)
condition|)
name|tbmodel
operator|=
name|TB_1500
expr_stmt|;
else|else
name|tbmodel
operator|=
name|TB_2500
expr_stmt|;
block|}
comment|/* Other, don't change tbmodel. */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIDIAL */
end_comment

begin_comment
comment|/*  C K D I A L	 --  Dial up the remote system */
end_comment

begin_comment
comment|/* Returns 1 if call completed, 0 otherwise */
end_comment

begin_decl_stmt
specifier|static
name|int
name|waitct
decl_stmt|,
name|mdmwait
decl_stmt|,
name|mdmstat
init|=
literal|0
decl_stmt|;
end_decl_stmt

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
name|char
name|errmsg
index|[
literal|50
index|]
decl_stmt|,
modifier|*
name|erp
decl_stmt|;
comment|/* for error messages */
name|char
name|fullnum
index|[
literal|100
index|]
decl_stmt|;
comment|/* for full (prefixed) phone number */
name|MDMINF
modifier|*
name|pmdminf
decl_stmt|;
comment|/* pointer to modem-specific info */
name|int
name|x
decl_stmt|,
name|m
decl_stmt|,
name|n
init|=
name|F_time
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
ifndef|#
directive|ifndef
name|MINIDIAL
name|tbmodel
operator|=
name|TB_UNK
expr_stmt|;
comment|/* Initialize Telebit model */
endif|#
directive|endif
comment|/* MINIDIAL */
if|if
condition|(
name|mymdmtyp
operator|<
literal|1
condition|)
block|{
if|if
condition|(
name|network
condition|)
name|printf
argument_list|(
literal|"Please SET HOST first, and then SET MODEM\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Sorry, you must SET MODEM first\n"
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
literal|"Sorry, you must SET LINE or SET HOST first\n"
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
name|network
operator|&&
name|speed
operator|<
literal|0L
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must SET SPEED first\n"
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
literal|"dial number"
argument_list|,
name|telnbr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"dial prefix"
argument_list|,
operator|(
name|dialnpr
condition|?
name|dialnpr
else|:
literal|""
operator|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Add prefix to phone number */
if|if
condition|(
name|dialnpr
operator|&&
operator|*
name|dialnpr
condition|)
block|{
name|sprintf
argument_list|(
name|fullnum
argument_list|,
literal|"%s%s"
argument_list|,
operator|(
name|dialnpr
condition|?
name|dialnpr
else|:
literal|""
operator|)
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
name|telnbr
operator|=
name|fullnum
expr_stmt|;
block|}
name|debug
argument_list|(
name|F110
argument_list|,
literal|"prefixed number"
argument_list|,
name|telnbr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNAMIC
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
literal|"Sorry, DIAL memory buffer can't be allocated\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* DYNAMIC */
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
comment|/* Condition console terminal and communication line */
comment|/* Place line into "clocal" dialing state, */
comment|/* important mainly for System V UNIX.     */
if|if
condition|(
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|FLO_DIAL
argument_list|,
name|parity
argument_list|)
operator|<
literal|0
condition|)
block|{
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* If ttpkt fails do all this... */
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
name|FLO_DIAL
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
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
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
comment|/* Interdigit waits for tone dial */
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
ifndef|#
directive|ifndef
name|MINIDIAL
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
endif|#
directive|endif
comment|/* MINIDIAL */
block|}
else|else
block|{
comment|/* User-specified timeout */
name|waitct
operator|=
name|dialtmo
expr_stmt|;
block|}
comment|/*   waitct is our alarm() timer.   mdmwait is how long we tell the modem to wait for carrier.   We set mdmwait to be 1 second less than waitct, to increase the   chance that we get a response from the modem before timing out. */
if|if
condition|(
name|waitct
operator|<
literal|0
condition|)
name|waitct
operator|=
literal|0
expr_stmt|;
name|mdmwait
operator|=
operator|(
name|waitct
operator|>
literal|5
operator|)
condition|?
name|waitct
operator|-
literal|5
else|:
name|waitct
expr_stmt|;
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
if|if
condition|(
operator|!
name|quiet
operator|&&
operator|!
name|backgrd
condition|)
block|{
comment|/* Print information messages. */
name|printf
argument_list|(
literal|" Dialing: %s\n"
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
if|if
condition|(
name|network
condition|)
block|{
name|printf
argument_list|(
literal|" Via modem server: %s, modem-dialer: %s\n"
argument_list|,
name|ttname
argument_list|,
operator|(
name|m
operator|>=
name|nmdm
condition|?
literal|"(unknown)"
else|:
name|mdmtab
index|[
name|m
index|]
operator|.
name|kwd
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|" Device: %s, modem-dialer: %s"
argument_list|,
name|ttname
argument_list|,
operator|(
name|m
operator|>=
name|nmdm
condition|?
literal|"(unknown)"
else|:
name|mdmtab
index|[
name|m
index|]
operator|.
name|kwd
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|speed
operator|>
operator|-
literal|1L
condition|)
name|printf
argument_list|(
literal|", speed: %ld\n"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|", speed: (unknown)\n"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" Dial timeout: %d seconds\n"
argument_list|,
name|waitct
argument_list|)
expr_stmt|;
name|printf
argument_list|(
ifdef|#
directive|ifdef
name|MAC
literal|" Type Command-. to cancel dialing\n"
else|#
directive|else
ifdef|#
directive|ifdef
name|UNIX
literal|" To cancel: type your interrupt character (normally Ctrl-C)\n"
else|#
directive|else
literal|" To cancel: type Ctrl-C\n"
endif|#
directive|endif
comment|/* UNIX */
endif|#
directive|endif
comment|/* MAC */
argument_list|)
expr_stmt|;
block|}
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
comment|/* Hang up the modem (in case it wasn't "on hook") */
comment|/* But only if SET DIAL HANGUP ON... */
if|if
condition|(
name|dialhup
argument_list|()
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckdial dialhup failed"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
comment|/* Telebit might need a BREAK */
name|ttsndb
argument_list|()
expr_stmt|;
comment|/*  first. */
endif|#
directive|endif
comment|/* MINIDIAL */
if|if
condition|(
name|dialhng
condition|)
block|{
comment|/* If it failed, */
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* close and reopen the device. */
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
literal|"Sorry, Can't hang up communication device\n"
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
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|augmdmtyp
operator|==
name|n_ROLM
condition|)
comment|/* Don't start talking to Rolm */
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* too soon... */
endif|#
directive|endif
comment|/* MINIDIAL */
comment|/*   Establish jump vector, or handle "failure" jumps.   longjmp() sets global failure reason, n1. */
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
ifdef|#
directive|ifdef
name|OSK
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
operator|(
name|SIGTYP
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
else|#
directive|else
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
comment|/* OS9 */
endif|#
directive|endif
comment|/* MAC */
name|alarm
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* Be sure to exit this section */
block|}
switch|switch
condition|(
name|n
condition|)
block|{
comment|/* Type of failure */
case|case
name|F_time
case|:
block|{
comment|/* Timed out */
name|printf
argument_list|(
literal|"DIAL TIMEOUT interval expired.\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mymdmtyp
operator|==
name|n_HAYES
ifndef|#
directive|ifndef
name|MINIDIAL
operator|||
name|mymdmtyp
operator|==
name|n_TELEBIT
operator|||
name|mymdmtyp
operator|==
name|n_HST
endif|#
directive|endif
comment|/* MINIDIAL */
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
comment|/* Dialing interrupted */
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
ifndef|#
directive|ifndef
name|MINIDIAL
operator|||
name|mymdmtyp
operator|==
name|n_TELEBIT
operator|||
name|mymdmtyp
operator|==
name|n_HST
endif|#
directive|endif
comment|/* MINIDIAL */
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
comment|/* Modem detected a failure */
name|printf
argument_list|(
literal|"Call failed (\""
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
comment|/* Display printable reason */
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
comment|/* Cannot initialize modem */
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
name|dreset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
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
comment|/* Set timer and interrupt handlers. */
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* No alarms yet. */
ifdef|#
directive|ifdef
name|MAC
name|savint
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
comment|/* And terminal interrupt handler. */
else|#
directive|else
comment|/* MAC */
ifdef|#
directive|ifdef
name|OSK
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
operator|(
name|SIGTYP
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dialint
argument_list|)
expr_stmt|;
else|#
directive|else
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
endif|#
directive|endif
comment|/* OS-9 */
endif|#
directive|endif
comment|/* MAC */
comment|/* Put modem in command mode. */
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
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
comment|/* Set alarm handler. */
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
name|dreset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
name|printf
argument_list|(
literal|" Call failed.\r\n"
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
name|dreset
argument_list|()
expr_stmt|;
comment|/* reset alarms, etc. */
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|FLO_DIAX
argument_list|,
name|parity
argument_list|)
expr_stmt|;
comment|/* cancel dialing ioctl */
if|if
condition|(
operator|!
name|quiet
operator|&&
operator|!
name|backgrd
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
literal|" Call complete.\07\r\n"
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
ifndef|#
directive|ifndef
name|MINIDIAL
case|case
name|n_HST
case|:
if|if
condition|(
name|augmdmtyp
operator|==
name|n_HST
condition|)
name|m
operator|=
literal|255
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* MINIDIAL */
name|m
operator|=
literal|60
expr_stmt|;
comment|/* Maximum value for S7 */
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
name|mdmstat
operator|=
name|getok
argument_list|(
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmstat
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
name|mdmstat
operator|>
literal|0
condition|)
block|{
comment|/* Initialized OK. */
name|char
name|hbuf
index|[
literal|10
index|]
decl_stmt|;
comment|/*   Now tell the modem about our dial timeout.  For Hayes 1200, the maximum   is 60 seconds.  For Hayes 2400 (the manual says) it is 30 seconds, but I'm   not sure I believe this (I don't have one handy to see for myself).   If you give the modem a value larger than its maximum, it sets the timeout   to its maximum.  The manual does not say what happens when the value is 0,   but experimentation shows that it allows the modem to wait forever, in   which case Kermit will time out at the desired time. */
comment|/*   Note by Kai Uwe Rommel:   This is not acceptable for general use of the hayes modem type with other   compatible modems. Most other modems allow a range of 1..255 while 0 is   invalid on several modems. Let it be the user's responsibility to make   sure a valid value is used. Higher values are desirable for users with   rotary dialing and with high speed modems, where protocol negotiation takes   quite a long time. */
ifdef|#
directive|ifdef
name|COMMENT
if|if
condition|(
name|mdmwait
operator|>
name|m
condition|)
comment|/* If larger than maximum, */
name|mdmwait
operator|=
literal|0
expr_stmt|;
comment|/* make it infinite. */
else|#
directive|else
if|if
condition|(
name|mdmwait
operator|>
literal|255
condition|)
comment|/* If larger than maximum, */
name|mdmwait
operator|=
literal|255
expr_stmt|;
comment|/* make it maximum. */
endif|#
directive|endif
comment|/* COMMENT */
name|sprintf
argument_list|(
name|hbuf
argument_list|,
literal|"ATS7=%d%c"
argument_list|,
name|mdmwait
argument_list|,
literal|13
argument_list|)
expr_stmt|;
comment|/* S7 = Carrier wait time */
name|ttslow
argument_list|(
name|hbuf
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
comment|/* Set it. */
name|mdmstat
operator|=
name|getok
argument_list|(
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Get response from modem */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"S7 mdmstat"
argument_list|,
literal|""
argument_list|,
name|mdmstat
argument_list|)
expr_stmt|;
break|break;
comment|/* Errors here are not fatal */
block|}
comment|/* modem-initialization failure */
name|n1
operator|=
operator|(
name|mdmstat
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
ifndef|#
directive|ifndef
name|MINIDIAL
comment|/*   Telebit modems fall into two basic groups: old and new.  The functions and   command sets are different between the two groups, and also vary by specific   models within each group, and even by firmware ROM revision number.  Read   ckcker.bwr for details.    Commands used by C-Kermit include:      Old       New            Meaning     -------   --------       ----------------------------------------     Q0        Q0             Enable result codes.     X1        X1             Extended result codes.     X1        X1             Extended result codes + BUSY, NO DIALTONE, etc.     I         I              Model number inquiry.     I3        I3             Additional model information inquiry.     S12=50    S12=50         Escape sequence guard time (1 sec).     S2=43     S2=43          Escape character is '+'.     S7=xx     S7=xx          DIAL TIMEOUT, calculated or SET by user.     S48=0     S48=0          7-bit data (Kermit's PARITY is not NONE).     S48=1     S48=1          8-bit data (Kermit's PARITY is NONE).     S50=0     S50=0          Automatic speed& protocol determination.     S50=3     S50=3          2400/1200/300 bps.     S50=6     S50=6          V.32 (9600 bps).     S50=255   S50=255        PEP mode.     S110=1    S190=1 S191=7  Allow compression in PEP mode.     S51=?     S51=?          DTE interface speed (left alone by Kermit).     S54=3     S61=0 S63=0    Pass BREAK signal (always).     S58=2     S58=2          RTS/CTS flow control if Kermit's FLOW is RTS/CTS.     S58=?     S58=?          S58 unchanged if Kermit's FLOW is not RTS/CTS.     S68=255   S68=255        Use flow control specified by S58 (always).     S95=0     S180=0         MNP disabled (SET DIAL MNP-ENABLE OFF)     S95=2     S180=3         MNP, fallback to direct (also as V.42 fallback)     S97=1     S180=2         Enable V.42 (LAPM) error correction     S98=3                    Enable compression in both directions     S106=1                   V.42bis compression enable  For Kermit Spoof (same commands for all models that support it):      S111=0                   No Kermit spoofing     S111=10                  Kermit with no parity     S111=11                  Kermit with odd parity     S111=12                  Kermit with even parity     S111=13                  Kermit with mark parity     S111=14                  Kermit with space parity     S112=??                  Kermit's start-of-packet character (stchr). */
case|case
name|n_TELEBIT
case|:
comment|/* Telebits... */
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
name|n_TBNV
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
name|S111
decl_stmt|;
comment|/* Telebit Kermit spoof register */
name|char
name|tbcmdbuf
index|[
literal|64
index|]
decl_stmt|;
comment|/* Telebit modem command buffer */
name|char
modifier|*
name|mnpstr
init|=
literal|""
decl_stmt|;
comment|/* Pointer to MNP-enable string */
name|char
modifier|*
name|dprstr
init|=
literal|""
decl_stmt|;
comment|/* Pointer to dial protocol string */
comment|/*   If user defined a DIAL INIT-STRING, send that now, otherwise send built-in   Telebit string.  Try up to 4 times to get OK or 0 response from modem.   NOTE: The default init string *must* be independent of Telebit model. */
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
name|ttsndb
argument_list|()
expr_stmt|;
comment|/* Begin by sending BREAK */
name|ttslow
argument_list|(
name|ws
argument_list|,
name|pmdminf
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
comment|/* Send wakeup string */
name|mdmstat
operator|=
name|getok
argument_list|(
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Get modem's response */
if|if
condition|(
name|mdmstat
condition|)
break|break;
comment|/* If response OK, done */
name|msleep
argument_list|(
literal|300
argument_list|)
expr_stmt|;
comment|/* Otherwise, sleep 1/3 second */
name|dialhup
argument_list|()
expr_stmt|;
comment|/* Hang up */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer and try again */
block|}
if|if
condition|(
name|mdmstat
operator|<
literal|1
condition|)
block|{
comment|/* If we didn't get a response */
name|n1
operator|=
name|F_minit
expr_stmt|;
comment|/* fail, reason = can't initialize */
name|longjmp
argument_list|(
name|sjbuf
argument_list|,
name|F_minit
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|dialini
condition|)
block|{
comment|/* If using built-in init strings... */
comment|/*   Try to get the model number.  It should be in the getok() response buffer,   rbuf[], because the Telebit init string asks for it with the "I" command.   If the model number is 965, we have to make another query to narrow it down. */
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"962"
argument_list|)
operator|||
comment|/* Check model number */
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"961"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"963"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_BLAZ
expr_stmt|;
comment|/* Trailblazer */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"972"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_2500
expr_stmt|;
comment|/* T2500 */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"968"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_1000
expr_stmt|;
comment|/* T1000 */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"966"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"967"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"964"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_PLUS
expr_stmt|;
comment|/* Trailblazer-Plus */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"969"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_QBLA
expr_stmt|;
comment|/* Qblazer */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"965"
argument_list|)
condition|)
block|{
comment|/* Most new models */
name|tbati3
argument_list|(
literal|965
argument_list|)
expr_stmt|;
comment|/* Go find out */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"971"
argument_list|)
condition|)
block|{
comment|/* T1500 or T2500 */
name|tbati3
argument_list|(
literal|971
argument_list|)
expr_stmt|;
comment|/* Go find out */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"123"
argument_list|)
operator|||
name|didweget
argument_list|(
name|rbuf
argument_list|,
literal|"960"
argument_list|)
condition|)
block|{
name|tbmodel
operator|=
name|TB_UNK
expr_stmt|;
comment|/* Telebit in Hayes mode */
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"Telebit model"
argument_list|,
name|tb_name
index|[
name|tbmodel
index|]
argument_list|,
name|tbmodel
argument_list|)
expr_stmt|;
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"Telebit model: %s\n"
argument_list|,
name|tb_name
index|[
name|tbmodel
index|]
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
comment|/*   Dial timeout.  S7 is set to the DIAL TIMEOUT value, or else to 255 if the   dial timeout is greater than 255, which is the maximum value for Telebits.   S7 can't be set to 0 on Telebits -- it gives an error. */
if|if
condition|(
name|mdmwait
operator|>
literal|255
condition|)
comment|/* If dial timeout too big */
name|mdmwait
operator|=
literal|255
expr_stmt|;
comment|/* make it as big as possible. */
comment|/*   Flow control.  If C-Kermit's FLOW-CONTROL is RTS/CTS, then we set this on   the modem too.  Unfortunately, many versions of UNIX only allow RTS/CTS   to be set outside of Kermit (e.g. by selecting a special device name).   In that case, Kermit doesn't know that it should set RTS/CTS on the modem,   in which case the user can add the appropriate Telebit command with   SET DIAL DIAL-COMMAND. */
if|if
condition|(
name|flow
operator|==
name|FLO_RTSC
condition|)
block|{
comment|/* RTS/CTS active in Kermit */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"ATS7=%d S48=%d S50=0 S58=2 S68=255\015"
argument_list|,
name|mdmwait
argument_list|,
name|parity
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
comment|/* Otherwise, don't touch modem's */
literal|"ATS7=%d S48=%d S50=0 S68=255\015"
argument_list|,
comment|/* flow control */
name|mdmwait
argument_list|,
name|parity
condition|?
literal|0
else|:
literal|1
argument_list|)
expr_stmt|;
comment|/* setting. */
name|s
operator|=
name|tbcmdbuf
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
name|mdmstat
operator|=
name|getok
argument_list|(
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmstat
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
name|mdmstat
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
comment|/*   Model-dependent items, but constant per model. */
switch|switch
condition|(
name|tbmodel
condition|)
block|{
case|case
name|TB_BLAZ
case|:
case|case
name|TB_PLUS
case|:
comment|/* TrailBlazer-Plus */
case|case
name|TB_1000
case|:
comment|/* T1000 */
case|case
name|TB_2000
case|:
comment|/* T2000 */
case|case
name|TB_2500
case|:
comment|/* T2500 */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Code from edit 183 told modem to follow RS-232 wrt CD and DTR */
comment|/* DTR, CD, follow RS-232, pass BREAK */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"ATS52=1 S53=4 S54=3\015"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* But everybody agreed we should not touch modem's CD and DTR settings. */
comment|/* Just pass BREAK */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"ATS54=3\015"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
break|break;
case|case
name|TB_1600
case|:
comment|/* T1600 */
case|case
name|TB_3000
case|:
comment|/* T3000 */
case|case
name|TB_WBLA
case|:
comment|/* WorldBlazer */
case|case
name|TB_QBLA
case|:
comment|/* Qblazer */
ifdef|#
directive|ifdef
name|COMMENT
comment|/* Code from edit 183 */
comment|/* Follow RS-232, No CONNECT suffix, pass BREAK */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"AT&C1&D2&Q0 S59=0 S61=0 S63=0\015"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Everybody agrees we should not touch modem's CD and DTR settings. */
comment|/* Also no more&Q0, no more S59=0 (doesn't matter, so don't touch). */
comment|/* So this section now deals only with treatment of BREAK. */
comment|/* Here we also raise the result code from X1 to X2, which allows */
comment|/* the T1600, T3000, and WB to supply NO DIALTONE, BUSY, RRING, and DIALING. */
comment|/* X2 means something else on the other models. */
comment|/* Transmit BREAK in sequence, raise result code. */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"ATX2 S61=0 S63=0\015"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
break|break;
default|default:
comment|/* Others, do nothing */
name|tbcmdbuf
index|[
literal|0
index|]
operator|=
name|NUL
expr_stmt|;
break|break;
block|}
name|s
operator|=
name|tbcmdbuf
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
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
name|mdmstat
operator|=
name|getok
argument_list|(
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmstat
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
name|mdmstat
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
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckdial Telebit init step 3 skipped"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Error correction, MNP or V.42 */
if|if
condition|(
name|augmdmtyp
operator|&
name|DIAL_V42
condition|)
block|{
comment|/* User wants V.42 */
switch|switch
condition|(
name|tbmodel
condition|)
block|{
comment|/* which implies fallback to MNP. */
case|case
name|TB_PLUS
case|:
comment|/* BC7.00 and up firmware */
case|case
name|TB_2000
case|:
comment|/* now really the same as TB+ ? */
case|case
name|TB_2500
case|:
comment|/* LAPM+compress->MNP->direct */
name|mnpstr
operator|=
literal|"S50=0 S95=2 S97=1 S98=3 S106=1"
expr_stmt|;
break|break;
case|case
name|TB_1600
case|:
case|case
name|TB_3000
case|:
case|case
name|TB_WBLA
case|:
case|case
name|TB_QBLA
case|:
ifdef|#
directive|ifdef
name|COMMENT
name|mnpstr
operator|=
literal|"S180=2 S181=0"
expr_stmt|;
comment|/* V.42, fallback = lock speed */
else|#
directive|else
comment|/* Better not to mess with S181, let it be used however user has it set. */
comment|/* S180=2 allows fallback to MNP, S180=1 disallows fallback to MNP. */
name|mnpstr
operator|=
literal|"S180=2"
expr_stmt|;
comment|/* V.42 */
endif|#
directive|endif
comment|/* COMMENT */
break|break;
default|default:
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"V.42 not supported by this Telebit model\n"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Handle DIAL MNP-ENABLE setting */
switch|switch
condition|(
name|tbmodel
condition|)
block|{
case|case
name|TB_BLAZ
case|:
comment|/* TrailBlazer */
case|case
name|TB_PLUS
case|:
comment|/* TrailBlazer-Plus */
case|case
name|TB_1000
case|:
comment|/* T1000 */
case|case
name|TB_2000
case|:
comment|/* T2000 */
case|case
name|TB_2500
case|:
comment|/* T2500 */
name|mnpstr
operator|=
name|dialmnp
condition|?
literal|"S95=2"
else|:
literal|"S95=0"
expr_stmt|;
comment|/* ON, OFF */
break|break;
case|case
name|TB_1600
case|:
comment|/* T1600 */
case|case
name|TB_3000
case|:
comment|/* T3000 */
case|case
name|TB_WBLA
case|:
comment|/* WorldBlazer */
case|case
name|TB_QBLA
case|:
comment|/* Qblazer */
name|mnpstr
operator|=
name|dialmnp
condition|?
literal|"S180=3"
else|:
literal|"S180=0"
expr_stmt|;
comment|/* ON, OFF */
comment|/* (Leave S181 fallback method alone) */
break|break;
default|default:
name|mnpstr
operator|=
literal|""
expr_stmt|;
block|}
block|}
comment|/* Dialing protocol */
name|dprstr
operator|=
literal|""
expr_stmt|;
comment|/* Initialize dialing protocol string */
name|p
operator|=
literal|""
expr_stmt|;
comment|/* and message string */
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_TELEBIT
case|:
comment|/* Start at highest and work down */
case|case
name|n_TBNV
case|:
name|p
operator|=
literal|"standard"
expr_stmt|;
switch|switch
condition|(
name|tbmodel
condition|)
block|{
comment|/* First group starts with PEP */
case|case
name|TB_BLAZ
case|:
comment|/* TrailBlazer */
case|case
name|TB_PLUS
case|:
comment|/* TrailBlazer-Plus */
case|case
name|TB_1000
case|:
comment|/* T1000 */
case|case
name|TB_2000
case|:
comment|/* T2000 */
case|case
name|TB_2500
case|:
comment|/* T2500 */
name|dprstr
operator|=
literal|"S50=0 S110=1"
expr_stmt|;
comment|/* PEP, compression allowed. */
break|break;
case|case
name|TB_WBLA
case|:
comment|/* WorldBlazer has PEP */
name|dprstr
operator|=
literal|"S50=0 S190=1 S191=7"
expr_stmt|;
comment|/* PEP, */
break|break;
comment|/* compression allowed. */
case|case
name|TB_1600
case|:
comment|/* T1600 doesn't have PEP */
case|case
name|TB_3000
case|:
comment|/* T3000 doesn't */
case|case
name|TB_QBLA
case|:
comment|/* Qblazer doesn't*/
default|default:
name|dprstr
operator|=
literal|"S50=0"
expr_stmt|;
comment|/* No PEP available */
break|break;
block|}
break|break;
case|case
name|n_TBS
case|:
comment|/* Telebit up to 2400 Baud */
case|case
name|n_TBSNV
case|:
comment|/* i.e. "Slow mode". */
name|p
operator|=
literal|"300/1200/2400 Baud"
expr_stmt|;
comment|/* Leave S90 alone assuming it is */
name|dprstr
operator|=
literal|"S50=3"
expr_stmt|;
comment|/* already set for V.22 vs 212A */
break|break;
case|case
name|n_TB3
case|:
comment|/* Telebit V.32 */
case|case
name|n_TB3NV
case|:
if|if
condition|(
name|tbmodel
operator|==
name|TB_3000
operator|||
name|tbmodel
operator|==
name|TB_1600
operator|||
name|tbmodel
operator|==
name|TB_2500
operator|||
name|tbmodel
operator|==
name|TB_WBLA
condition|)
block|{
name|p
operator|=
literal|"V.32"
expr_stmt|;
comment|/* Note: we don't touch S51 (interface speed) here. */
comment|/* We're already talking to the modem, and the modem */
comment|/* SHOULD be able to make a V.32 call no matter what */
comment|/* its interface speed is.  (In practice, however, */
comment|/* that is not always true.) */
name|dprstr
operator|=
literal|"S50=6"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"V.32 not supported by this Telebit model.\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|n_TBPEP
case|:
comment|/* Force PEP Protocol */
case|case
name|n_TBPNV
case|:
if|if
condition|(
name|tbmodel
operator|!=
name|TB_1600
operator|&&
comment|/* Models that don't support PEP */
name|tbmodel
operator|!=
name|TB_3000
operator|&&
name|tbmodel
operator|!=
name|TB_QBLA
condition|)
block|{
name|p
operator|=
literal|"PEP"
expr_stmt|;
if|if
condition|(
name|tbmodel
operator|==
name|TB_WBLA
condition|)
comment|/* WorldBlazer */
name|dprstr
operator|=
literal|"S50=255 S190=1 S191=7"
expr_stmt|;
elseif|else
if|if
condition|(
name|tbmodel
operator|!=
name|TB_1000
condition|)
name|dprstr
operator|=
literal|"S50=255 S110=1"
expr_stmt|;
comment|/* TrailBlazer, etc. */
else|else
name|dprstr
operator|=
literal|"S50=255"
expr_stmt|;
comment|/* T1000, no compression */
block|}
elseif|else
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"PEP not supported by this Telebit model.\n"
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Kermit Spoof */
if|if
condition|(
name|dialksp
condition|)
block|{
name|p
operator|=
literal|"Kermit Spoof"
expr_stmt|;
switch|switch
condition|(
name|parity
condition|)
block|{
comment|/* S111 value depends on parity */
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
case|case
literal|0
case|:
default|default:
name|S111
operator|=
literal|10
expr_stmt|;
break|break;
block|}
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   This code forced the use of PEP mode if DIAL KERMIT-SPOOF was ON, which   prevented successful connection if the other modem did not support PEP. */
if|if
condition|(
name|tbmodel
operator|==
name|TB_BLAZ
operator|||
comment|/* Must force PEP on old models */
name|tbmodel
operator|==
name|TB_PLUS
operator|||
name|tbmodel
operator|==
name|TB_1000
operator|||
name|tbmodel
operator|==
name|TB_2000
operator|||
name|tbmodel
operator|==
name|TB_2500
condition|)
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"AT%s %s S50=255 S111=%d S112=%d\015"
argument_list|,
name|mnpstr
argument_list|,
name|dprstr
argument_list|,
name|S111
argument_list|,
name|stchr
argument_list|)
expr_stmt|;
comment|/* PEP is not required on T1500, T1600, T3000, and WB */
comment|/* (but MNP is, but that is user's responsibility).   */
elseif|else
endif|#
directive|endif
comment|/* COMMENT */
if|if
condition|(
name|tbmodel
operator|!=
name|TB_QBLA
condition|)
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"AT%s %s S111=%d S112=%d\015"
argument_list|,
name|mnpstr
argument_list|,
name|dprstr
argument_list|,
name|S111
argument_list|,
name|stchr
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* Qblazer has no Kermit spoof */
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"AT%s %s\015"
argument_list|,
name|mnpstr
argument_list|,
name|dprstr
argument_list|)
expr_stmt|;
name|p
operator|=
literal|"No Kermit Spoof"
expr_stmt|;
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"Kermit Spoof not supported by Qblazer\n"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* No Kermit spoof */
name|p
operator|=
literal|"No Kermit Spoof"
expr_stmt|;
name|sprintf
argument_list|(
name|tbcmdbuf
argument_list|,
literal|"AT%s %s %s\015"
argument_list|,
name|mnpstr
argument_list|,
name|dprstr
argument_list|,
operator|(
name|tbmodel
operator|==
name|TB_QBLA
operator|)
condition|?
literal|""
else|:
literal|"S111=0 S112=0"
argument_list|)
expr_stmt|;
block|}
name|s
operator|=
name|tbcmdbuf
expr_stmt|;
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
name|mdmstat
operator|=
name|getok
argument_list|(
literal|5
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmstat
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
literal|"ckdial telebit init mdmstat"
argument_list|,
literal|""
argument_list|,
name|mdmstat
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmstat
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
comment|/* Interdigit waits for tone dial */
block|{
name|jmp_buf
name|savejmp
decl_stmt|;
name|alarm
argument_list|(
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
comment|/* Set alarm handler. */
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
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   Kermit spoof for Microcom modems.  Untested.   This is reportedly the way to do it for QX/3296c, QX/4232hs, QX/4232bis,   and QX/9624c.  The effect on other models is unknown. */
name|ws
operator|=
name|dialksp
condition|?
literal|"APM1\015"
else|:
literal|"APM0\015"
expr_stmt|;
comment|/* Kermit spoof */
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
endif|#
directive|endif
comment|/* COMMENT */
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
comment|/* Set alarm handler. */
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
endif|#
directive|endif
comment|/* MINIDIAL */
default|default:
comment|/* Place modem into command mode */
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
if|if
condition|(
name|ws
operator|&&
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|ws
argument_list|)
operator|>
literal|0
condition|)
block|{
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
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckdial no wake_str"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|pmdminf
operator|->
name|wake_prompt
operator|&&
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|pmdminf
operator|->
name|wake_prompt
argument_list|)
operator|>
literal|0
condition|)
block|{
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
block|}
else|else
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckdial no wake_prompt"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Turn off alarm */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|savalrm
argument_list|)
expr_stmt|;
comment|/* Restore alarm handler. */
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
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* Allow settling time */
ifndef|#
directive|ifndef
name|MINIDIAL
comment|/* Enable/disable MNP (Telebit already done above) */
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
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Get response */
break|break;
comment|/* Add others here ... */
default|default:
break|break;
block|}
endif|#
directive|endif
comment|/* MINIDIAL */
comment|/* Put modem into dialing mode, if the modem requires it. */
if|if
condition|(
name|pmdminf
operator|->
name|dmode_str
operator|&&
operator|*
operator|(
name|pmdminf
operator|->
name|dmode_str
operator|)
condition|)
block|{
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
if|if
condition|(
name|pmdminf
operator|->
name|dmode_prompt
condition|)
block|{
comment|/* Wait for prompt, if any expected */
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
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Turn off alarm on dialing prompts */
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|savalrm
argument_list|)
expr_stmt|;
comment|/* Restore alarm */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Clear out stuff from waking modem up */
block|}
comment|/* Dial the number.  First form the dialing string. */
name|sprintf
argument_list|(
name|lbuf
argument_list|,
name|dialcmd
condition|?
name|dialcmd
else|:
name|pmdminf
operator|->
name|dial_str
argument_list|,
name|telnbr
argument_list|)
expr_stmt|;
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
name|ttslow
argument_list|(
name|lbuf
argument_list|,
name|pmdminf
operator|->
name|dial_rate
argument_list|)
expr_stmt|;
comment|/* Send the dialing string */
name|savalrm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|dialtime
argument_list|)
expr_stmt|;
comment|/* Time to allow for connecting */
name|x
operator|=
name|alarm
argument_list|(
name|waitct
argument_list|)
expr_stmt|;
comment|/* This much time... */
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
ifndef|#
directive|ifndef
name|MINIDIAL
switch|switch
condition|(
name|augmdmtyp
condition|)
block|{
case|case
name|n_RACAL
case|:
comment|/* Acknowledge printout of dialing string */
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
endif|#
directive|endif
comment|/* MINIDIAL */
comment|/* Check for connection */
name|mdmstat
operator|=
literal|0
expr_stmt|;
comment|/* No status yet */
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"No Connection"
argument_list|)
expr_stmt|;
comment|/* Default reason for failure */
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
while|while
condition|(
name|mdmstat
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
operator|-
literal|1
init|;
name|n
operator|<
name|LBUFL
operator|-
literal|1
condition|;
control|)
block|{
comment|/* Accumulate response */
name|c2
operator|=
name|ddinc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Read a character, blocking */
if|if
condition|(
name|c2
operator|==
literal|0
operator|||
name|c2
operator|==
operator|-
literal|1
condition|)
comment|/* Ignore NULs and errors */
continue|continue;
comment|/* (Timeout will handle errors) */
else|else
comment|/* Real character, keep it */
name|lbuf
index|[
operator|++
name|n
index|]
operator|=
name|c2
operator|&
literal|0177
expr_stmt|;
name|dialoc
argument_list|(
name|lbuf
index|[
name|n
index|]
argument_list|)
expr_stmt|;
comment|/* Maybe echo it  */
if|if
condition|(
name|augmdmtyp
operator|==
name|n_CCITT
condition|)
block|{
comment|/* V.25 bis dialing... */
comment|/*   This assumes that V.25bis indications are all at least 3 characters long   and are terminated by either CRLF or LFCR. */
if|if
condition|(
name|n
operator|<
literal|3
condition|)
continue|continue;
if|if
condition|(
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|CR
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|LF
operator|)
condition|)
break|break;
if|if
condition|(
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|LF
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|CR
operator|)
condition|)
break|break;
block|}
ifndef|#
directive|ifndef
name|MINIDIAL
elseif|else
if|if
condition|(
name|augmdmtyp
operator|==
name|n_DIGITEL
condition|)
block|{
if|if
condition|(
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|CR
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|LF
operator|)
operator|||
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|LF
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|CR
operator|)
condition|)
break|break;
else|else
continue|continue;
block|}
endif|#
directive|endif
comment|/* MINIDIAL */
else|else
block|{
comment|/* All others, break on CR or LF */
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
block|}
name|lbuf
index|[
operator|++
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
ifndef|#
directive|ifndef
name|MINIDIAL
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
endif|#
directive|endif
comment|/* MINIDIAL */
case|case
name|n_CCITT
case|:
comment|/* CCITT V.25bis */
ifndef|#
directive|ifndef
name|MINIDIAL
case|case
name|n_DIGITEL
case|:
comment|/* or Digitel variant */
endif|#
directive|endif
comment|/* MINIDIAL */
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"VAL"
argument_list|)
condition|)
block|{
comment|/* Dial command confirmation */
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|augmdmtyp
operator|==
name|n_CCITT
condition|)
endif|#
directive|endif
comment|/* MINIDIAL */
continue|continue;
comment|/* Go back and read more */
ifndef|#
directive|ifndef
name|MINIDIAL
comment|/* Digitel doesn't give an explicit connect confirmation message */
else|else
block|{
name|int
name|n
decl_stmt|;
for|for
control|(
name|n
operator|=
operator|-
literal|1
init|;
name|n
operator|<
name|LBUFL
operator|-
literal|1
condition|;
control|)
block|{
name|lbuf
index|[
operator|++
name|n
index|]
operator|=
name|c2
operator|=
name|ddinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
name|dialoc
argument_list|(
name|lbuf
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|CR
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|LF
operator|)
operator|||
operator|(
name|lbuf
index|[
name|n
index|]
operator|==
name|LF
operator|)
operator|&&
operator|(
name|lbuf
index|[
name|n
operator|-
literal|1
index|]
operator|==
name|CR
operator|)
condition|)
break|break;
block|}
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
comment|/* Assume we're connected */
if|if
condition|(
name|dialdpy
operator|&&
name|carrier
operator|!=
name|CAR_OFF
condition|)
block|{
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Wait a second */
name|n
operator|=
name|ttgmdm
argument_list|()
expr_stmt|;
comment|/* Try to read modem signals */
if|if
condition|(
operator|(
name|n
operator|>
operator|-
literal|1
operator|)
operator|&&
operator|(
name|n
operator|&
name|BM_DCD
operator|==
literal|0
operator|)
condition|)
name|printf
argument_list|(
literal|"Warning: No Carrier\n"
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* MINIDIAL */
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CNX"
argument_list|)
condition|)
block|{
comment|/* Connected */
name|mdmstat
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
literal|"INV"
argument_list|)
condition|)
block|{
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
comment|/* Command error */
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"INV"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CFI"
argument_list|)
condition|)
block|{
comment|/* Call Failure */
ifdef|#
directive|ifdef
name|COMMENT
comment|/*   V.25 bis says that the failure reason comes on the same line, so   we don't need to read any more characters here. */
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
comment|/* Read reason */
name|lbuf
index|[
name|n
index|]
operator|=
name|c2
operator|=
operator|(
name|ddinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
operator|)
expr_stmt|;
if|if
condition|(
name|c2
operator|==
name|LF
condition|)
comment|/* Modem answers LF CR */
continue|continue;
name|dialoc
argument_list|(
name|lbuf
index|[
name|n
index|]
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
endif|#
directive|endif
comment|/* COMMENT */
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"AB"
argument_list|)
condition|)
comment|/* Interpret reason code */
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"AB: Timed out"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CB"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"CB: Local DCE Busy"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"ET"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"ET: Busy"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NS"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"NS: Number not stored"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"NT"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"NT: No answer"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"RT"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"RT: Ring tone"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"PV"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"PV: Parameter value error"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"PS"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"PS: Parameter syntax error"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"MS"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"MS: Message syntax error"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"CU"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"CU: Command unknown"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"FC"
argument_list|)
condition|)
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"FC: Forbidden call"
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"INC"
argument_list|)
condition|)
block|{
comment|/* Incoming Call */
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"INC: Incoming call"
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DLC"
argument_list|)
condition|)
block|{
comment|/* Delayed Call */
name|strcpy
argument_list|(
name|lbuf
argument_list|,
literal|"DLC: Delayed call"
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
block|}
elseif|else
comment|/* Response was probably an echo. */
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|augmdmtyp
operator|==
name|n_CCITT
condition|)
endif|#
directive|endif
comment|/* MINIDIAL */
continue|continue;
ifndef|#
directive|ifndef
name|MINIDIAL
else|else
comment|/* Digitel: If no error, then connect. */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
endif|#
directive|endif
comment|/* MINIDIAL */
break|break;
ifndef|#
directive|ifndef
name|MINIDIAL
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_USROBOT
case|:
case|case
name|n_HST
case|:
case|case
name|n_TELEBIT
case|:
endif|#
directive|endif
comment|/* MINIDIAL */
case|case
name|n_HAYES
case|:
if|if
condition|(
name|mdmspd
operator|&&
operator|!
name|network
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
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
operator|&&
operator|!
name|backgrd
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
ifndef|#
directive|ifndef
name|MINIDIAL
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
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
operator|&&
operator|!
name|backgrd
condition|)
name|printf
argument_list|(
literal|"FAST/KERM "
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
endif|#
directive|endif
comment|/* MINIDIAL */
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
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"DIALING"
argument_list|)
condition|)
block|{
name|mdmstat
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
name|mdmstat
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
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
block|}
break|break;
ifndef|#
directive|ifndef
name|MINIDIAL
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
literal|"INVALID GROUP NAME"
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
operator|||
name|didweget
argument_list|(
name|lbuf
argument_list|,
literal|"INVALID DATA LINE NUMBER"
argument_list|)
condition|)
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
comment|/* trailing speed ignored */
break|break;
endif|#
directive|endif
comment|/* MINIDIAL */
block|}
block|}
break|break;
ifndef|#
directive|ifndef
name|MINIDIAL
case|case
name|n_DF03
case|:
comment|/* because response lacks CR or NL */
name|c
operator|=
name|ddinc
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
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'B'
condition|)
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
break|break;
case|case
name|n_TBNV
case|:
comment|/* Hayeslike modems in digit */
case|case
name|n_TB3NV
comment|/* response mode... */
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
endif|#
directive|endif
comment|/* MINIDIAL */
case|case
name|n_HAYESNV
case|:
comment|/*   The method for reading Hayes numeric result codes has been totally   redone as of 5A(174) to account for all of the following.  Not all have   been tested, and others probably need to be added.    Hayes numeric result codes (Hayes 1200 and higher):      0 = OK      1 = CONNECT at 300 bps (or 1200 bps on Hayes 1200 with basic code set)      2 = RING      3 = NO CARRIER      4 = ERROR (in command line)      5 = CONNECT 1200 (extended code set)   Hayes 2400 and higher:      6 = NO DIALTONE      7 = BUSY      8 = NO ANSWER      9 = (there is no 9)     10 = CONNECT 2400   Reportedly, the codes for Hayes V.32 modems are:     1x = CONNECT<suffix>     5x = CONNECT 1200<suffix>     9x = CONNECT 2400<suffix>    11x = CONNECT 4800<suffix>    12x = CONNECT 9600<suffix>   Where:     x:   suffix:     R  = RELIABLE     RC = RELIABLE COMPRESSED     L  = LAPM     LC = LAPM COMPRESSED   And for Telebits, all the above, except no suffix in numeric mode, plus:     11 = CONNECT 4800     12 = CONNECT 9600     13 = CONNECT 14400     14 = CONNECT 19200     15 = CONNECT 38400     16 = CONNECT 57600     20 = CONNECT 300/REL  (= MNP)     22 = CONNECT 1200/REL (= MNP)     23 = CONNECT 2400/REL (= MNP)     46 = CONNECT 7512  (i.e. 75/1200)     47 = CONNECT 1275  (i.e. 1200/75)     48 = CONNECT 7200     49 = CONNECT 12000     50 = CONNECT FAST (not on T1600/3000)     52 = RRING     53 = DIALING     54 = NO PROMPTTONE     61 = CONNECT FAST/KERM (Kermit spoof)     70 = CONNECT FAST/COMP (PEP + compression)     71 = CONNECT FAST/KERM/COMP (PEP + compression + Kermit spoof) */
define|#
directive|define
name|NBUFL
value|8
block|{
comment|/* Nonverbal response code handler */
name|char
name|nbuf
index|[
name|NBUFL
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Response buffer */
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* Buffer pointers */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"RESPONSE mdmecho"
argument_list|,
literal|""
argument_list|,
name|mdmecho
argument_list|)
expr_stmt|;
if|if
condition|(
name|mdmecho
condition|)
block|{
comment|/* Sponge up dialing string echo. */
while|while
condition|(
literal|1
condition|)
block|{
name|c
operator|=
name|ddinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0x7f
expr_stmt|;
name|debug
argument_list|(
name|F000
argument_list|,
literal|"SPONGE"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|CR
condition|)
break|break;
block|}
block|}
while|while
condition|(
name|mdmstat
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
name|NBUFL
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
name|ddinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Get first digit of response. */
comment|/* using an untimed, blocking read. */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"RESPONSE-A"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
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
comment|/* Got first digit, save it. */
while|while
condition|(
name|c
operator|!=
name|CR
operator|&&
name|i
operator|<
literal|8
condition|)
block|{
comment|/* Now read characters up to CR */
name|x
operator|=
name|ddinc
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Get a character. */
name|c
operator|=
operator|(
name|char
operator|)
name|x
expr_stmt|;
comment|/* Got it OK. */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"RESPONSE-C"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|!=
name|CR
condition|)
comment|/* If it's not a carriage return, */
name|nbuf
index|[
name|i
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|/*  save it. */
name|dialoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Echo it. */
block|}
name|nbuf
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Done, terminate the buffer. */
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
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
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|13
case|:
comment|/* CONNECT 14400 */
name|spdchg
argument_list|(
literal|14400L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|14
case|:
name|spdchg
argument_list|(
literal|19200L
argument_list|)
expr_stmt|;
comment|/* CONNECT 19200 */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|15
case|:
comment|/* CONNECT 34800 */
name|spdchg
argument_list|(
literal|38400L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|16
case|:
comment|/* CONNECT 57600 */
name|spdchg
argument_list|(
literal|57600L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|20
case|:
comment|/* CONNECT 300/REL */
name|spdchg
argument_list|(
literal|300L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|22
case|:
comment|/* CONNECT 1200/REL */
name|spdchg
argument_list|(
literal|1200L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|23
case|:
comment|/* CONNECT 2400/REL */
name|spdchg
argument_list|(
literal|2400L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|46
case|:
comment|/* CONNECT 7512 */
name|spdchg
argument_list|(
literal|8880L
argument_list|)
expr_stmt|;
comment|/* 75/1200 split speed */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
comment|/* (special C-Kermit code) */
break|break;
case|case
literal|47
case|:
comment|/* CONNECT 1200/75 */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
comment|/* Speed not supported by Kermit */
name|printf
argument_list|(
literal|"CONNECT 1200/75 - Not support by C-Kermit\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|48
case|:
comment|/* CONNECT 7200 */
name|spdchg
argument_list|(
literal|7200L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|49
case|:
comment|/* CONNECT 12000 */
name|spdchg
argument_list|(
literal|12000L
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
ifndef|#
directive|ifndef
name|MINIDIAL
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
comment|/* Early models only */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
case|case
literal|52
case|:
comment|/* RRING */
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
literal|53
case|:
comment|/* DIALING */
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
literal|" Dialing...\r\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|54
case|:
comment|/* NO PROMPTTONE */
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
block|{
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|"\r\n No Prompttone.\r\n"
argument_list|)
expr_stmt|;
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
block|}
break|break;
case|case
literal|61
case|:
comment|/* Various Telebit PEP modes */
case|case
literal|62
case|:
case|case
literal|63
case|:
case|case
literal|70
case|:
case|case
literal|71
case|:
case|case
literal|72
case|:
case|case
literal|73
case|:
if|if
condition|(
name|mymdmtyp
operator|==
name|n_TELEBIT
condition|)
comment|/* Early models only */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
break|break;
endif|#
directive|endif
comment|/* MINIDIAL */
default|default:
break|break;
block|}
block|}
if|if
condition|(
name|mdmstat
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
name|mdmstat
operator|=
name|FAILED
expr_stmt|;
comment|/* Assume failure. */
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
comment|/* Can't, fail. */
if|if
condition|(
name|x
operator|&
name|BM_DCD
condition|)
block|{
comment|/* Got signals OK.  Carrier present? */
name|mdmstat
operator|=
name|CONNECTED
expr_stmt|;
comment|/* Yes, done. */
break|break;
block|}
comment|/* No, keep waiting. */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
comment|/* switch (augmdmtyp) */
block|}
comment|/* while (mdmstat == 0) */
name|x
operator|=
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Turn off alarm. */
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
if|if
condition|(
name|mdmstat
operator|!=
name|CONNECTED
condition|)
block|{
comment|/* Modem-detected failure */
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
comment|/* Exit (with reason in lbuf) */
block|}
name|msleep
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* In case DTR blinks  */
name|alarm
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* Precaution in case of trouble */
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
ifndef|#
directive|ifndef
name|MINIDIAL
if|if
condition|(
name|augmdmtyp
operator|!=
name|n_ROLM
condition|)
comment|/* Rolm has wierd modem signaling */
endif|#
directive|endif
comment|/* MINIDIAL */
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|FLO_DIAX
argument_list|,
name|parity
argument_list|)
expr_stmt|;
comment|/* Cancel dialing state ioctl */
name|dreset
argument_list|()
expr_stmt|;
comment|/* Reset alarms, etc. */
if|if
condition|(
operator|!
name|quiet
operator|&&
operator|!
name|backgrd
condition|)
name|printf
argument_list|(
literal|" Call complete.\07\n"
argument_list|)
expr_stmt|;
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
comment|/* Return successfully */
block|}
end_function

begin_comment
comment|/*   getok() - wait up to n seconds for OK (0) or ERROR (4) response from modem.   Use with Hayeslike or CCITT modems for reading the reply to a nondialing   command.    Second argument says whether to be strict about numeric result codes, i.e.   to require they be preceded by CR or else be the first character in the   response, e.g. to prevent the ATH0<CR> echo from looking like a valid   response.  Strict == 0 is needed for ATI on Telebit, which can return the   model number concatenated with the numeric response code, e.g. "9620"   ("962" is the model number, "0" is the response code).  getok() Returns:     0 if it timed out,    1 if it succeeded,   -1 on modem command, i/o, or other error. */
end_comment

begin_decl_stmt
specifier|static
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
ifdef|#
directive|ifdef
name|OSK
comment|/* OS-9, see comment in dialtime(). */
name|sigmask
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OSK */
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
parameter_list|,
name|strict
parameter_list|)
name|int
name|n
decl_stmt|,
name|strict
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
decl_stmt|,
name|oldalarm
decl_stmt|;
name|SIGTYP
function_decl|(
modifier|*
name|saval
function_decl|)
parameter_list|()
function_decl|;
comment|/* For saving alarm handler locally */
name|mdmecho
operator|=
literal|0
expr_stmt|;
comment|/* Assume no echoing of commands */
name|saval
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|oktimo
argument_list|)
expr_stmt|;
comment|/* Set response timer, */
name|oldalarm
operator|=
name|alarm
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|/* saving old one. */
if|if
condition|(
name|setjmp
argument_list|(
name|okbuf
argument_list|)
condition|)
block|{
comment|/* Timed out. */
name|alarm
argument_list|(
name|oldalarm
argument_list|)
expr_stmt|;
comment|/* Restore old alarm */
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
comment|/* and alarm handler */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getok timeout"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* and return timeout indication */
block|}
elseif|else
if|if
condition|(
name|augmdmtyp
operator|==
name|n_CCITT
comment|/* CCITT, easy... */
ifndef|#
directive|ifndef
name|MINIDIAL
operator|||
name|augmdmtyp
operator|==
name|n_DIGITEL
comment|/* Digitel, ditto. */
endif|#
directive|endif
comment|/* MINIDIAL */
condition|)
block|{
name|waitfor
argument_list|(
literal|"VAL"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* Hayes& friends, start here... */
name|status
operator|=
literal|0
expr_stmt|;
comment|/* No status yet. */
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
name|RBUFL
condition|;
name|x
operator|++
control|)
comment|/* Initialize response buffer */
name|rbuf
index|[
name|x
index|]
operator|=
name|SP
expr_stmt|;
comment|/*  to all spaces */
name|rbuf
index|[
name|RBUFL
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* and terminate with NUL. */
while|while
condition|(
name|status
operator|==
literal|0
condition|)
block|{
comment|/* While no status... */
name|x
operator|=
name|ddinc
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
block|{
comment|/* I/O error */
name|alarm
argument_list|(
name|oldalarm
argument_list|)
expr_stmt|;
comment|/* Turn off alarm */
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
comment|/* and restore handler. */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Return error code. */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getok ddinc"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* Got a character. */
name|c
operator|=
name|x
operator|&
literal|0x7f
expr_stmt|;
comment|/* Get low order 7 bits */
if|if
condition|(
operator|!
name|c
condition|)
comment|/* Don't deposit NULs */
continue|continue;
comment|/* or else didweget() won't work */
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
name|RBUFL
operator|-
literal|1
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
name|RBUFL
operator|-
literal|1
index|]
operator|=
name|c
expr_stmt|;
comment|/* Deposit character at end */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"getok:"
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
comment|/* Got a carriage return. */
switch|switch
condition|(
name|rbuf
index|[
name|RBUFL
operator|-
literal|2
index|]
condition|)
block|{
comment|/* Look at character before it. */
case|case
literal|'0'
case|:
comment|/* 0 = OK numeric response */
if|if
condition|(
operator|!
name|strict
operator|||
name|rbuf
index|[
name|RBUFL
operator|-
literal|3
index|]
operator|==
name|CR
operator|||
name|rbuf
index|[
name|RBUFL
operator|-
literal|3
index|]
operator|==
name|SP
condition|)
block|{
name|augmdmtyp
operator||=
name|DIAL_NV
expr_stmt|;
comment|/* OR in the "nonverbal" bit. */
name|status
operator|=
literal|1
expr_stmt|;
comment|/* Good response */
block|}
break|break;
case|case
literal|'4'
case|:
comment|/* 4 = ERROR numeric response */
if|if
condition|(
operator|!
name|strict
operator|||
name|rbuf
index|[
name|RBUFL
operator|-
literal|3
index|]
operator|==
name|CR
operator|||
name|rbuf
index|[
name|RBUFL
operator|-
literal|3
index|]
operator|==
name|SP
condition|)
block|{
name|augmdmtyp
operator||=
name|DIAL_NV
expr_stmt|;
comment|/* OR in the nonverbal bit. */
name|status
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Bad command */
block|}
break|break;
block|}
if|if
condition|(
name|dialdpy
operator|&&
operator|(
name|augmdmtyp
operator|&
name|DIAL_NV
operator|)
condition|)
comment|/* If numeric results, */
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
comment|/* Got a linefeed. */
comment|/* 		  Note use of explicit octal codes in the string for 		  CR and LF.  We want real CR and LF here, not whatever 		  the compiler happens to define \r and \n as... 		*/
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
name|RBUFL
operator|-
literal|4
argument_list|,
literal|"OK\015\012"
argument_list|)
condition|)
comment|/* Good response */
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
operator|+
name|RBUFL
operator|-
literal|7
argument_list|,
literal|"ERROR\015\012"
argument_list|)
condition|)
comment|/* Error */
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
name|RBUFL
operator|-
literal|3
argument_list|,
literal|"\015at"
argument_list|)
operator|||
comment|/* See if it's "at" */
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
name|RBUFL
operator|-
literal|3
argument_list|,
literal|" at"
argument_list|)
condition|)
name|mdmecho
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"MDMECHO-t"
argument_list|,
name|rbuf
operator|+
name|RBUFL
operator|-
literal|2
argument_list|,
name|mdmecho
argument_list|)
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
name|RBUFL
operator|-
literal|3
argument_list|,
literal|"\015AT"
argument_list|)
operator|||
comment|/* See if it's "AT" */
operator|!
name|strcmp
argument_list|(
name|rbuf
operator|+
name|RBUFL
operator|-
literal|3
argument_list|,
literal|" AT"
argument_list|)
condition|)
name|mdmecho
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"MDMECHO-T"
argument_list|,
name|rbuf
operator|+
name|RBUFL
operator|-
literal|3
argument_list|,
name|mdmecho
argument_list|)
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
name|oldalarm
argument_list|)
expr_stmt|;
comment|/* Restore previous alarm */
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
comment|/* and handler */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush input buffer */
return|return
operator|(
name|status
operator|)
return|;
comment|/* Return status */
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
name|mdmhup
argument_list|()
expr_stmt|;
comment|/* Try modem-specific method first */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"dialhup mdmhup"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
comment|/* If it worked, */
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|" Modem hangup OK\r\n"
argument_list|)
expr_stmt|;
comment|/* fine. */
block|}
elseif|else
if|if
condition|(
name|network
condition|)
block|{
comment|/* If we're telnetted to */
if|if
condition|(
name|dialdpy
condition|)
comment|/* a modem server, just print a msg */
name|printf
argument_list|(
literal|" Warning: modem hangup failed\r\n"
argument_list|)
expr_stmt|;
comment|/* don't hangup! */
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
comment|/* Otherwise */
name|x
operator|=
name|tthang
argument_list|()
expr_stmt|;
comment|/* Tell the OS to turn off DTR. */
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
literal|" Hangup OK\r\n"
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
block|}
elseif|else
if|if
condition|(
name|dialdpy
condition|)
name|printf
argument_list|(
literal|" Hangup skipped\r\n"
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

begin_comment
comment|/*   M D M H U P  --    Sends escape sequence to modem, then sends its hangup command.  Returns:    0: If modem type is 0 (direct serial connection),       or if modem type is< 0 (network connection),       or if no action taken because DIAL MODEM-HANGUP is OFF)         or because no hangup string for current modem type,       or C-Kermit is in remote mode,       or if action taken but there was no positive response from modem;    1: Success: modem is in command state and acknowledged the hangup command;   -1: On modem command error. */
end_comment

begin_function
name|int
name|mdmhup
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|MDMHUP
name|MDMINF
modifier|*
name|p
decl_stmt|;
comment|/* Modem info structure pointer */
name|int
name|m
decl_stmt|,
name|x
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|dialmhu
operator|==
literal|0
operator|||
name|local
operator|==
literal|0
condition|)
comment|/* If DIAL MODEM-HANGUP is OFF, */
return|return
operator|(
literal|0
operator|)
return|;
comment|/*  or not in local mode, fail. */
ifdef|#
directive|ifdef
name|OS2
comment|/*   In OS/2, if CARRIER is OFF, and there is indeed no carrier signal, any   attempt to do i/o at this point can hang the program.  This might be true   for other operating systems too. */
if|if
condition|(
operator|!
name|network
condition|)
block|{
comment|/* Not a network connection */
name|m
operator|=
name|ttgmdm
argument_list|()
expr_stmt|;
comment|/* Get modem signals */
if|if
condition|(
operator|(
name|m
operator|>
operator|-
literal|1
operator|)
operator|&&
operator|(
name|m
operator|&
name|BM_DCD
operator|==
literal|0
operator|)
condition|)
comment|/* Check for carrier */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* No carrier, skip the rest */
block|}
endif|#
directive|endif
comment|/* OS2 */
name|m
operator|=
name|mdmtyp
operator|&
literal|0xff
expr_stmt|;
comment|/* Get basic modem type (no bits!). */
if|if
condition|(
operator|(
name|m
operator|<
literal|1
operator|)
operator|||
operator|(
name|m
operator|>
name|MAX_MDM
operator|)
condition|)
comment|/* If modem type not in range, */
return|return
operator|(
literal|0
operator|)
return|;
comment|/*  fail. */
name|p
operator|=
name|ptrtab
index|[
name|m
operator|-
literal|1
index|]
expr_stmt|;
comment|/* Get modem info pointer */
if|if
condition|(
operator|!
operator|(
name|p
operator|->
name|hup_str
operator|)
operator|||
operator|!
operator|*
operator|(
name|p
operator|->
name|hup_str
operator|)
condition|)
block|{
comment|/* No hangup string? */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"mdmhup no hup_str"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* No, */
return|return
operator|(
literal|0
operator|)
return|;
comment|/*  fail. */
block|}
else|else
block|{
name|debug
argument_list|(
name|F110
argument_list|,
literal|"mdmhup hup_str"
argument_list|,
name|p
operator|->
name|hup_str
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Yes. */
if|if
condition|(
name|p
operator|->
name|esc_str
operator|&&
operator|*
operator|(
name|p
operator|->
name|esc_str
operator|)
condition|)
block|{
comment|/* Have escape sequence? */
name|debug
argument_list|(
name|F110
argument_list|,
literal|"mdmhup esc_str"
argument_list|,
name|p
operator|->
name|esc_str
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"mdmhup esc_time"
argument_list|,
literal|""
argument_list|,
name|p
operator|->
name|esc_time
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttpkt
argument_list|(
name|speed
argument_list|,
name|FLO_DIAL
argument_list|,
name|parity
argument_list|)
operator|<
literal|0
condition|)
comment|/* Condition line */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/*  for dialing. */
if|if
condition|(
name|p
operator|->
name|esc_time
condition|)
comment|/* If we have a guard time */
name|msleep
argument_list|(
name|p
operator|->
name|esc_time
argument_list|)
expr_stmt|;
comment|/* Pause for guard time */
ifdef|#
directive|ifdef
name|NETCONN
comment|/* Send modem's escape sequence */
if|if
condition|(
name|network
condition|)
block|{
comment|/* Must catch errors here. */
if|if
condition|(
name|ttol
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
operator|(
name|p
operator|->
name|esc_str
operator|)
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|p
operator|->
name|esc_str
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
name|ttslow
argument_list|(
name|p
operator|->
name|esc_str
argument_list|,
name|p
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
comment|/* Send escape sequence */
block|}
else|#
directive|else
name|ttslow
argument_list|(
name|p
operator|->
name|esc_str
argument_list|,
name|p
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
comment|/* Send escape sequence */
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|p
operator|->
name|esc_time
condition|)
comment|/* Pause for guard time again */
name|msleep
argument_list|(
name|p
operator|->
name|esc_time
argument_list|)
expr_stmt|;
name|msleep
argument_list|(
literal|500
argument_list|)
expr_stmt|;
comment|/* Wait half a sec for echoes. */
name|ttflui
argument_list|()
expr_stmt|;
comment|/* Flush response or echo, if any */
block|}
ifdef|#
directive|ifdef
name|NETCONN
comment|/* Send modem's hangup command */
if|if
condition|(
name|network
condition|)
block|{
comment|/* Must catch errors here. */
if|if
condition|(
name|ttol
argument_list|(
operator|(
name|CHAR
operator|*
operator|)
operator|(
name|p
operator|->
name|hup_str
operator|)
argument_list|,
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|p
operator|->
name|hup_str
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
name|ttslow
argument_list|(
name|p
operator|->
name|hup_str
argument_list|,
name|p
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|ttslow
argument_list|(
name|p
operator|->
name|hup_str
argument_list|,
name|p
operator|->
name|wake_rate
argument_list|)
expr_stmt|;
comment|/* Now Send hangup string */
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|p
operator|->
name|ok_fn
condition|)
block|{
comment|/* Look for OK response */
name|x
operator|=
operator|(
operator|*
operator|(
name|p
operator|->
name|ok_fn
operator|)
operator|)
operator|(
literal|3
operator|,
literal|1
operator|)
expr_stmt|;
comment|/* Give it 3 seconds, be strict. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"mdmhup hangup response"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* No OK function, */
name|x
operator|=
literal|1
expr_stmt|;
comment|/* so assume it worked */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"mdmhup no ok_fn"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|x
operator|)
return|;
comment|/* Return OK function's return code. */
block|}
else|#
directive|else
comment|/* MDMHUP not defined. */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Always fail. */
endif|#
directive|endif
comment|/* MDMHUP */
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
comment|/* about dial init-string. */
name|MDMINF
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|mdmtyp
operator|&
literal|0xff
operator|)
operator|<
literal|1
operator|||
operator|(
name|mdmtyp
operator|&
literal|0xff
operator|)
operator|>
name|MAX_MDM
condition|)
return|return
operator|(
literal|""
operator|)
return|;
name|p
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
name|p
operator|->
name|wake_str
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|getdcs
parameter_list|(
name|mdmtyp
parameter_list|)
name|int
name|mdmtyp
decl_stmt|;
block|{
comment|/* Same deal for dial-command */
name|MDMINF
modifier|*
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|mdmtyp
operator|&
literal|0xff
operator|)
operator|<
literal|1
operator|||
operator|(
name|mdmtyp
operator|&
literal|0xff
operator|)
operator|>
name|MAX_MDM
condition|)
return|return
operator|(
literal|""
operator|)
return|;
name|p
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
name|dialcmd
condition|?
name|dialcmd
else|:
name|p
operator|->
name|dial_str
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NODIAL */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dialv
init|=
literal|"Dial Command Disabled"
decl_stmt|;
end_decl_stmt

begin_function
name|int
comment|/* To allow NODIAL versions to */
name|mdmhup
parameter_list|()
block|{
comment|/* call mdmhup(), so calls to  */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* mdmhup() need not be within */
block|}
end_function

begin_comment
comment|/* #ifndef NODIAL conditionals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

end_unit

