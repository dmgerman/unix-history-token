begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|versio
init|=
literal|"C-Kermit 5A(188), 23 Nov 92"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Version herald. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*   For Macintosh, also remember to change the Mac-specific version in ckmkr2.r. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|versio
init|=
literal|"Mac Kermit 0.99(188) Pre-ALPHA, 23 Nov 92"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_decl_stmt
name|long
name|vernum
init|=
literal|501188L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   String and numeric version numbers, keep these three in sync!   First digit of vermum = major version, i.e. 5.   Second 2 digits of vernum: 00 = no minor version, 01 = A, 02 = B, etc.   Last three digits are edit number.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERWHO
end_ifndef

begin_comment
comment|/* Change verwho in following line, or with -DVERWHO=x in makefile CFLAGS. */
end_comment

begin_define
define|#
directive|define
name|VERWHO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERWHO */
end_comment

begin_decl_stmt
name|int
name|verwho
init|=
name|VERWHO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Who produced this version, 0 = Columbia University */
end_comment

begin_comment
comment|/*   IMPORTANT: If you are working on your own private version of C-Kermit, please   include some special notation, like your site name or your initials, in the   "versio" string, e.g. "5A(182)-XXX", and use a nonzero code for the "verwho"   variable (e.g. in the USA use your zip code).  Unless we stick to this   discipline, divergent copies of C-Kermit will begin to appear that are   intistinguishable from each other, which is a big support issue.  Also, if   you have edited C-Kermit and made copies available to others, please add   appropriate text to the BUG command (ckuus6.c, function dobug()). */
end_comment

begin_define
define|#
directive|define
name|CKCMAI
end_define

begin_comment
comment|/*  C K C M A I  --  C-Kermit Main program  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.    COPYRIGHT NOTICE:    Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University.    DOCUMENTATION:    "Using C-Kermit" by Frank da Cruz and Christine M. Gianone,   Digital Press, Burlington, MA, USA.  Publication date: Winter 1992.   Order Number: EY-J896E-DP   Digital Press ISBN: 1-55558-108-0   Prentice Hall ISBN: 0-13-037490-3    DISCLAIMER:    The C-Kermit software is provided in source code form by Kermit Development   and Distribution, Columbia University.  The software is provided "as is;" no   other warranty is provided, express or implied, including without   limitations, any implied warranty of merchantability or implied warranty of   fitness for a particular purpose.    Neither Columbia University nor any of the contributors to the C-Kermit   development effort, including, but not limited to, AT&T, Digital Equipment   Corporation, Data General Corporation, or International Business Machines   Corporation, warrant C-Kermit software or documentation in any way.  In   addition, neither the authors of any Kermit programs, publications or   documentation, nor Columbia University nor any contributing institutions or   individuals acknowledge any liability resulting from program or   documentation errors.    ACKNOWLEDGMENTS:    The Kermit file transfer protocol was developed at the Columbia University   Center for Computing Activities (CUCCA).  It is named after Kermit the Frog,   star of the television series THE MUPPET SHOW; the name is used by permission   of Henson Associates, Inc.    Thanks to at least the following people for their contributions to this   program over the years, and apologies to anybody I missed:     Chris Adie, Edinburgh U, Scotland (OS/2 support)    Robert Adsett, University of Waterloo, Canada    Larry Afrin, Clemson U    Greg Andrews, Telebit Corp    Barry Archer, U of Missouri    Robert Andersson, International Systems A/S, Oslo, Norway    Chris Armstrong, Brookhaven National Lab (OS/2)    William Bader, Software Consulting Services, Nazareth, PA    Fuat Baran, CUCCA    Stan Barber, Rice U    Jim Barbour, U of Colorado    Donn Baumgartner, Dell    Nelson Beebe, U of Utah    Karl Berry, UMB    Dean W Bettinger, SUNY    Gary Bilkus    Marc Boucher, U of Montreal    Charles Brooks, EDN    Bob Brown    Mike Brown, Purdue U    Jack Bryans, California State U at Long Beach    Mark Buda, DEC (VAX/VMS)    Fernando Cabral, Padrao IX, Brasilia, Brazil    Bjorn Carlsson, Stockholm University Computer Centre QZ, Sweden    Bill Catchings, formerly of CUCCA    Bob Cattani, Columbia U CS Dept    Davide Cervone, Rochester University    Seth Chaiklin, Denmark    John Chandler, Harvard U / Smithsonian Astronomical Observatory    John L Chmielewski, AT&T, Lisle, IL    Howard Chu, U of Michigan    Bill Coalson, McDonnell Douglas    Bertie Coopersmith, London, UK    Chet Creider, University of Western Ontario, Canada    Alan Crosswell, CUCCA    Jeff Damens, formerly of CUCCA    Mark Davies, Bath U, UK    S. Dezawa, Fujifilm, Japan    Joe R. Doupnik, Utah State U    Frank Dreano (Honeywell)    John Dunlap, University of Washington    David Dyck, John Fluke Mfg Co.    Stefaan A. Eeckels, Eurokom, Luxembourg    Paul Eggert, Twin Sun, Inc., El Segundo, CA    Bernie Eiben, DEC    Kristoffer Eriksson, Peridot Konsult AB, Oerebro, Sweden    John R. Evans, IRS, Kansas City    Glenn Everhart, RCA Labs    Charlie Finan, Cray Research    Herm Fischer, Encino, CA (extensive contributions to version 4.0)    Carl Fongheiser, CWRU    Marcello Frutig, Catholic University, Sao Paulo, Brazil (X.25 support)    Hirofumi Fujii, Japan Nat'l Lab for High Energy Physics, Tokyo (Kanji)    Chuck Fuller, Westinghouse Corporate Computer Services    Andy Fyfe, Caltech    Christine M. Gianone, CUCCA    John Gilmore, UC Berkeley    German Goldszmidt, IBM    Alistair Gorman, New Zealand    Richard Gration, ADFA, Australia    Chris Green, Essex U, UK    Alan Grieg, Dundee Tech, Scotland, UK    Yekta Gursel, MIT    Jim Guyton, Rand Corp    Michael Haertel    Bob Hain, UMN    Marion Hakanson, ORST    John Hamilston, Iowa State U    Simon Hania, Netherlands    Stan Hanks, Rice U.    Ken Harrenstein, SRI    Eugenia Harris, Data General (AOS/VS)    David Harrison, Kingston Warren Corp    James Harvey, Indiana/Purdue U (VMS)    Rob Healey    Chuck Hedrick, Rutgers U    Ron Heiby, Technical Systems Division, Motorola Computer Group    Steve Hemminger, Tektronix    Christian Hemsing, RWTH Aachen, Germany (OS-9)    Andrew Herbert, Monash Univ, Australia    Mike Hickey, ITI    R E Hill    Bill Homer, Cray Research    Ray Hunter, The Wollongong Group    Randy Huntziger, National Library of Medicine    Larry Jacobs, Transarc    Steve Jenkins, Lancaster University, UK    Dave Johnson, Gradient Technologies    Mark B Johnson, Apple Computer    Eric F Jones, AT&T    Luke Jones, AT&T    Peter Jones, U of Quebec Montreal    Phil Julian, SAS Institute    Peter Kabal, U of Quebec    Mic Kaczmarczik, U of Texas at Austin    Sergey Kartashoff, Inst. of Precise Mechanics& Computer Equipment, Moscow    Howie Kaye, CUCCA    Rob Kedoin, Linotype Co, Hauppauge, NY (OS/2)    Mark Kennedy, IBM    Terry Kennedy, St Peter's College, Jersey City, NJ (VAX/VMS, 2.11 BSD)    Douglas Kingston, morgan.com    Tom Kloos, Sequent Computer Systems    Jim Knutson, U of Texas at Austin    Scott Kramer, SRI International, Menlo Park, CA    David Kricker, Encore Computer    Thomas Krueger, UWM    Bo Kullmar, Central Bank of Sweden, Kista    R. Brad Kummer, AT&T Bell Labs, Atlanta, GA    John Kunze, UC Berkeley    Bob Larson, USC (OS-9)    Bert Laverman, Groningen U, Netherlands    Steve Layton    David Lawyer, UC Irvine    David LeVine, National Semiconductor Corporation    S.O. Lidie, Lehigh U    Tor Lillqvist, Helsinki University, Finland    Dean Long    Kevin Lowey, U of Saskatchewan (OS/2)    Andy Lowry, Columbia University    David MacKenzie, Environmental Defense Fund, University of Maryland    John Mackin, University of Sidney, Australia    Martin Maclaren, Bath U, UK    Chris Maio, Columbia U CS Dept    Fulvio Marino, Olivetti, Ivrea, Italy    Peter Mauzey, AT&T    Tye McQueen, Utah State U    Ted Medin    Hellmuth Michaelis, Hanseatischer Computerservice GmbH, Hamburg, Germany    Leslie Mikesell, American Farm Bureau    Martin Minow, DEC (VAX/VMS)    Pawan Mistra, Bellcore    Ken Mizialko, IBM, Manassas, VA    Ray Moody, Purdue U    Bruce J Moore, Allen-Bradley Co, Highland Heights, OH (Atari ST)    Steve Morley, Convex    Peter Mossel, Columbia University    Tony Movshon, NYU    Lou Muccioli, Swanson Analysis Systems    Dan Murphy    Gary Mussar    John Nall, FSU    Jack Nelson, University of Pittsburgh    Jim Noble, Planning Research Corporation (Macintosh)    Ian O'Brien, Bath U, UK    John Owens    Michael Pins, Iowa Computer Aided Engineering Network    Andre' Pirard, University of Liege, Belgium    Paul Placeway, Ohio State U (Macintosh& more)    Piet W. Plomp, ICCE, Groningen University, Netherlands    Ken Poulton, HP Labs    Manfred Prange, Oakland U    Christopher Pratt, APV Baker, UK    Frank Prindle, NADC    Tony Querubin, U of Hawaii    Anton Rang    Scott Ribe    Alan Robiette, Oxford University, UK    Michel Robitaille, U of Montreal (Mac)    Kai Uwe Rommel, Technische Universitaet Muenchen (OS/2)    Larry Rosenman (Amiga)    Jay Rouman, U of Michigan    Jack Rouse, SAS Institute (Data General and/or Apollo)    Stew Rubenstein, Harvard U (VAX/VMS)    Bill Schilit, Columbia University    Michael Schmidt, U of Paderborn, Germany    Eric Schnoebelen, Convex    Benn Schreiber, DEC    Dan Schullman, DEC (modems, DIAL command, etc)    John Schultz, 3M    Steven Schultz, Contel (PDP-11)    APPP Scorer, Leeds Polytechnic, UK    Gordon Scott, Micro Focus, Newbury UK    Gisbert W. Selke, WIdO, Bonn, Germany    David Sizeland, U of London Medical School    Fridrik Skulason, Iceland    Dave Slate    Bradley Smith, UCLA    Richard S Smith, Cal State    Ryan Stanisfer, UNT    Bertil Stenstroem, Stockholm University Computer Centre (QZ), Sweden    James Sturdevant, CAP GEMENI AMERICA, Minneapolis    Peter Svanberg, Royal Techn. HS, Sweden    James R. Swenson, Accu-Weather, Inc.    Andy Tanenbaum, Vrije U, Amsterdam, Netherlands    Markku Toijala, Helsinki U of Technology    Rick Troxel, NIH    Warren Tucker, Tridom Corp, Mountain Park, GA    Dave Tweten, AMES-NAS    G Uddeborg, Sweden    Walter Underwood, Ford Aerospace    Pieter Van Der Linden, Centre Mondial, Paris    Ge van Geldorp, Netherlands    Fred van Kempen, MINIX User Group, Voorhout, Netherlands    Wayne Van Pelt, GE/CRD    Mark Vasoll, Oklahoma State U (V7 UNIX)    Konstantin Vinogradov, ICSTI, Moscow    Paul Vixie, DEC    Dimitri Vulis, CUNY    Roger Wallace, Raytheon    Stephen Walton, Calif State U, Northridge (Amiga)    Jamie Watson, Adasoft, Switzerland (RS/6000)    Rick Watson, U of Texas (Macintosh)    Robert Weiner, Programming Plus, New York City    Lauren Weinstein, Vortex Technlogy    David Wexelblat, AT&T    Joachim Wiesel, U of Karlsruhe    Lon Willett, U of Utah    Michael Williams, UCLA    Nate Williams, U of Montana    David Wilson    Patrick Wolfe, Kuck& Associates, Inc.    Gregg Wonderly, Oklahoma State U (V7 UNIX)    Farrell Woods, Concurrent (formerly Masscomp)    Dave Woolley, CAP Communication Systems, London    Jack Woolley, SCT Corp    Frank Wortner    Ken Yap, U of Rochester    John Zeeff, Ann Arbor, MI */
end_comment

begin_comment
comment|/*   ckcsym.h is used for for defining symbols that normally would be defined   using -D or -d on the cc command line, for use with compilers that don't   support this feature. */
end_comment

begin_include
include|#
directive|include
file|"ckcsym.h"
end_include

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_comment
comment|/* ASCII character symbols */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Debug& other symbols */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_comment
comment|/* Kermit symbols */
end_comment

begin_include
include|#
directive|include
file|"ckcnet.h"
end_include

begin_comment
comment|/* Network symbols */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_include
include|#
directive|include
file|"ckuusr.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|NOSERVER
end_ifndef

begin_comment
comment|/* Text message definitions.. each should be 256 chars long, or less. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"\r\ Mac Kermit Server Commands:\r\ \r\     BYE\r\     FINISH\r\     GET filespec\r\     REMOTE CD directory\r\     REMOTE HELP\r\     SEND filespec\r\ \r\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server Commands:\n\ \n\ GET filespec, SEND filespec, FINISH, BYE, REMOTE HELP\n\ \n\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server REMOTE Commands:\n\ \n\ GET files  REMOTE CD [dir]     REMOTE DIRECTORY [files]\n\ SEND files REMOTE SPACE [dir]  REMOTE HOST command\n\ FINISH     REMOTE DELETE files REMOTE TYPE files\n\ BYE        REMOTE HELP         REMOTE SET parameter value\n\ \n\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server REMOTE Commands:\n\ GET SEND BYE FINISH REMOTE: CD DEL DIR HELP HOST SET SPACE TYPE WHO\n\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server REMOTE Commands:\r\n\ \r\n\ GET files  REMOTE CD [dir]     REMOTE DIRECTORY [files]\r\n\ SEND files REMOTE SPACE [dir]  REMOTE HOST command\r\n\ MAIL files REMOTE DELETE files REMOTE WHO [user]\r\n\ BYE        REMOTE PRINT files  REMOTE TYPE files\r\n\ FINISH     REMOTE HELP         REMOTE SET parameter value\r\n\ \0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server REMOTE Commands:\n\ \n\ GET files  REMOTE CD [dir]     REMOTE DIRECTORY [filespec]\n\ SEND files REMOTE SPACE [dir]  REMOTE HOST command\n\ BYE        REMOTE TYPE file    REMOTE DELETE files\n\ FINISH     REMOTE WHO          REMOTE SET\n\ \0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|hlptxt
init|=
literal|"C-Kermit Server REMOTE Commands:\n\ \n\ GET files  REMOTE CD [dir]     REMOTE DIRECTORY [files]\n\ SEND files REMOTE SPACE [dir]  REMOTE HOST command\n\ MAIL files REMOTE DELETE files REMOTE WHO [user]\n\ BYE        REMOTE PRINT files  REMOTE TYPE files\n\ FINISH     REMOTE HELP         REMOTE SET parameter value\n\ \n\0"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|MINIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|srvtxt
init|=
literal|"\r\n\ Entering server mode.\r\n\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|srvtxt
init|=
literal|"\r\l\ Entering server mode.  If your local Kermit software is menu driven, use\r\l\ the menus to send commands to the server.  Otherwise, enter the escape\r\l\ sequence to return to your local Kermit prompt and issue commands from\r\l\ there.  Use SEND and GET for file transfer.  Use REMOTE HELP for a list of\r\l\ other available services.  Use BYE or FINISH to end server mode.\r\l\0"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UNIX, VMS, AOS/VS, and all others */
end_comment

begin_decl_stmt
name|char
modifier|*
name|srvtxt
init|=
literal|"\r\n\ Entering server mode.  If your local Kermit software is menu driven, use\r\n\ the menus to send commands to the server.  Otherwise, enter the escape\r\n\ sequence to return to your local Kermit prompt and issue commands from\r\n\ there.  Use SEND and GET for file transfer.  Use REMOTE HELP for a list of\r\n\ other available services.  Use BYE or FINISH to end server mode.\r\n\0"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* server mode disabled */
end_comment

begin_decl_stmt
name|char
modifier|*
name|srvtxt
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSERVER */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Declarations for Send-Init Parameters */
end_comment

begin_decl_stmt
name|int
name|spsiz
init|=
name|DSPSIZ
decl_stmt|,
comment|/* Current packet size to send */
name|spmax
init|=
name|DSPSIZ
decl_stmt|,
comment|/* Biggest packet size we can send */
name|spsizr
init|=
name|DSPSIZ
decl_stmt|,
comment|/* Send-packet size requested */
name|spsizf
init|=
literal|0
decl_stmt|,
comment|/* Flag to override size negotiation */
name|rpsiz
init|=
name|DRPSIZ
decl_stmt|,
comment|/* Biggest we want to receive */
name|urpsiz
init|=
name|DRPSIZ
decl_stmt|,
comment|/* User-requested receive pkt size */
name|maxrps
init|=
name|MAXRP
decl_stmt|,
comment|/* Maximum incoming long packet size */
name|maxsps
init|=
name|MAXSP
decl_stmt|,
comment|/* Maximum outbound l.p. size */
name|maxtry
init|=
name|MAXTRY
decl_stmt|,
comment|/* Maximum retries per packet */
name|wslots
init|=
literal|1
decl_stmt|,
comment|/* Window size currently in use */
name|wslotr
init|=
literal|1
decl_stmt|,
comment|/* Window size from SET WINDOW */
name|wslotn
init|=
literal|1
decl_stmt|,
comment|/* Window size negotiated in S-pkt */
name|timeouts
init|=
literal|0
decl_stmt|,
comment|/* For statistics reporting */
name|spackets
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|rpackets
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|retrans
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|crunched
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|wmax
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|wcur
init|=
literal|0
decl_stmt|,
comment|/*  ... */
name|srvdis
init|=
literal|0
decl_stmt|,
comment|/* Server file xfer display */
name|srvtim
init|=
name|DSRVTIM
decl_stmt|,
comment|/* Server command wait timeout */
comment|/*   timint is the timeout interval I use when waiting for a packet.   pkttim is the SET RECEIVE TIMEOUT value, sent to the other Kermit.   rtimo is the SET SEND TIMEOUT value.  rtimo is the initial value of   timint.  timint is changed by the value in the incoming negotiation   packet unless a SET SEND TIMEOUT command was given. */
name|timint
init|=
name|DMYTIM
decl_stmt|,
comment|/* Timeout interval I use */
name|pkttim
init|=
name|URTIME
decl_stmt|,
comment|/* Timeout I want you to use */
name|rtimo
init|=
name|DMYTIM
decl_stmt|,
comment|/* Normal packet wait timeout */
name|timef
init|=
literal|0
decl_stmt|,
comment|/* Flag to override what you ask */
name|npad
init|=
name|MYPADN
decl_stmt|,
comment|/* How much padding to send */
name|mypadn
init|=
name|MYPADN
decl_stmt|,
comment|/* How much padding to ask for */
name|bctr
init|=
literal|1
decl_stmt|,
comment|/* Block check type requested */
name|bctu
init|=
literal|1
decl_stmt|,
comment|/* Block check type used */
name|bctl
init|=
literal|1
decl_stmt|,
comment|/* Block check length */
name|ebq
init|=
name|MYEBQ
decl_stmt|,
comment|/* 8th bit prefix */
name|ebqflg
init|=
literal|0
decl_stmt|,
comment|/* 8th-bit quoting flag */
name|rqf
init|=
operator|-
literal|1
decl_stmt|,
comment|/* Flag used in 8bq negotiation */
name|rq
init|=
literal|0
decl_stmt|,
comment|/* Received 8bq bid */
name|sq
init|=
literal|'Y'
decl_stmt|,
comment|/* Sent 8bq bid */
name|rpt
init|=
literal|0
decl_stmt|,
comment|/* Repeat count */
name|rptq
init|=
name|MYRPTQ
decl_stmt|,
comment|/* Repeat prefix */
name|rptflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repeat processing flag */
end_comment

begin_decl_stmt
name|int
name|capas
init|=
literal|9
decl_stmt|,
comment|/* Position of Capabilities */
name|atcapb
init|=
literal|8
decl_stmt|,
comment|/* Attribute capability */
name|atcapr
init|=
literal|1
decl_stmt|,
comment|/*  requested */
name|atcapu
init|=
literal|0
decl_stmt|,
comment|/*  used */
name|swcapb
init|=
literal|4
decl_stmt|,
comment|/* Sliding Window capability */
name|swcapr
init|=
literal|1
decl_stmt|,
comment|/*  requested (allowed) */
name|swcapu
init|=
literal|0
decl_stmt|,
comment|/*  used */
name|lpcapb
init|=
literal|2
decl_stmt|,
comment|/* Long Packet capability */
name|lpcapr
init|=
literal|1
decl_stmt|,
comment|/*  requested */
name|lpcapu
init|=
literal|0
decl_stmt|,
comment|/*  used */
name|lscapb
init|=
literal|32
decl_stmt|,
comment|/* Locking Shift capability */
name|lscapr
init|=
literal|1
decl_stmt|,
comment|/*  requested by default */
name|lscapu
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  used */
end_comment

begin_comment
comment|/* Flags for whether to use particular attributes */
end_comment

begin_decl_stmt
name|int
name|atenci
init|=
literal|1
decl_stmt|,
comment|/* Encoding in */
name|atenco
init|=
literal|1
decl_stmt|,
comment|/* Encoding out */
name|atdati
init|=
literal|1
decl_stmt|,
comment|/* Date in */
name|atdato
init|=
literal|1
decl_stmt|,
comment|/* Date out */
name|atdisi
init|=
literal|1
decl_stmt|,
comment|/* Disposition in/out */
name|atdiso
init|=
literal|1
decl_stmt|,
name|atleni
init|=
literal|1
decl_stmt|,
comment|/* Length in/out (both kinds) */
name|atleno
init|=
literal|1
decl_stmt|,
name|atblki
init|=
literal|1
decl_stmt|,
comment|/* Blocksize in/out */
name|atblko
init|=
literal|1
decl_stmt|,
name|attypi
init|=
literal|1
decl_stmt|,
comment|/* File type in/out */
name|attypo
init|=
literal|1
decl_stmt|,
name|atsidi
init|=
literal|1
decl_stmt|,
comment|/* System ID in/out */
name|atsido
init|=
literal|1
decl_stmt|,
name|atsysi
init|=
literal|1
decl_stmt|,
comment|/* System-dependent parameters in/out */
name|atsyso
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CHAR
name|padch
init|=
name|MYPADC
decl_stmt|,
comment|/* Padding character to send */
name|mypadc
init|=
name|MYPADC
decl_stmt|,
comment|/* Padding character to ask for */
name|seol
init|=
name|MYEOL
decl_stmt|,
comment|/* End-Of-Line character to send */
name|eol
init|=
name|MYEOL
decl_stmt|,
comment|/* End-Of-Line character to look for */
name|ctlq
init|=
name|CTLQ
decl_stmt|,
comment|/* Control prefix in incoming data */
name|myctlq
init|=
name|CTLQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Outbound control character prefix */
end_comment

begin_decl_stmt
name|struct
name|zattr
name|iattr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incoming file attributes */
end_comment

begin_comment
comment|/* File related variables, mainly for the benefit of VAX/VMS */
end_comment

begin_decl_stmt
name|int
name|fblksiz
init|=
name|DBLKSIZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File blocksize */
end_comment

begin_decl_stmt
name|int
name|frecl
init|=
name|DLRECL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File record length */
end_comment

begin_decl_stmt
name|int
name|frecfm
init|=
name|XYFF_S
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File record format (default = stream) */
end_comment

begin_decl_stmt
name|int
name|forg
init|=
name|XYFO_S
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File organization (sequential) */
end_comment

begin_decl_stmt
name|int
name|fcctrl
init|=
name|XYFP_N
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File carriage control (ctrl chars) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* VMS labeled file options */
end_comment

begin_decl_stmt
name|int
name|lf_opts
init|=
name|LBL_NAM
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|lf_opts
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/* Packet-related variables */
end_comment

begin_decl_stmt
name|int
name|pktnum
init|=
literal|0
decl_stmt|,
comment|/* Current packet number */
name|sndtyp
init|=
literal|0
decl_stmt|,
comment|/* Type of packet just sent */
name|rsn
decl_stmt|,
comment|/* Received packet sequence number */
name|rln
decl_stmt|,
comment|/* Received packet length */
name|size
decl_stmt|,
comment|/* Current size of output pkt data */
name|osize
decl_stmt|,
comment|/* Previous output packet data size */
name|maxsize
decl_stmt|,
comment|/* Max size for building data field */
name|spktl
init|=
literal|0
decl_stmt|,
comment|/* Length packet being sent */
name|rpktl
init|=
literal|0
decl_stmt|,
comment|/* Length of packet just received */
name|rprintf
decl_stmt|,
comment|/* REMOTE PRINT flag */
name|rmailf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MAIL flag */
end_comment

begin_decl_stmt
name|CHAR
ifdef|#
directive|ifdef
name|NO_MORE
comment|/* Buffers used before sliding windows... */
name|sndpkt
index|[
name|MAXSP
operator|+
literal|100
index|]
decl_stmt|,
comment|/* Entire packet being sent */
name|recpkt
index|[
name|MAXRP
operator|+
literal|200
index|]
decl_stmt|,
comment|/* Packet most recently received */
name|data
index|[
name|MAXSP
operator|+
literal|4
index|]
decl_stmt|,
comment|/* Packet data buffer */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DYNAMIC
modifier|*
name|srvcmd
init|=
operator|(
name|CHAR
operator|*
operator|)
literal|0
decl_stmt|,
comment|/* Where to decode server command */
else|#
directive|else
name|srvcmd
index|[
name|MAXRP
operator|+
literal|4
index|]
decl_stmt|,
comment|/* Where to decode server command */
endif|#
directive|endif
name|padbuf
index|[
literal|95
index|]
decl_stmt|,
comment|/* Buffer for send-padding */
modifier|*
name|recpkt
decl_stmt|,
modifier|*
name|rdatap
decl_stmt|,
comment|/* Pointer to received packet data */
modifier|*
name|data
init|=
operator|(
name|CHAR
operator|*
operator|)
literal|0
decl_stmt|,
comment|/* Pointer to send-packet data */
modifier|*
name|srvptr
decl_stmt|,
comment|/* Pointer to srvcmd */
name|mystch
init|=
name|SOH
decl_stmt|,
comment|/* Outbound packet-start character */
name|stchr
init|=
name|SOH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Incoming packet-start character */
end_comment

begin_escape
end_escape

begin_comment
comment|/* File-related variables */
end_comment

begin_decl_stmt
name|char
name|filnam
index|[
literal|257
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current file. */
end_comment

begin_decl_stmt
name|char
name|cmdfil
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Application file name. */
end_comment

begin_decl_stmt
name|int
name|nfils
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of files in file group */
end_comment

begin_decl_stmt
name|long
name|fsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of current file */
end_comment

begin_decl_stmt
name|int
name|wildxpand
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Who expands wildcards */
end_comment

begin_decl_stmt
name|int
name|clfils
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for command-line files */
end_comment

begin_decl_stmt
name|int
name|stayflg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag for "stay", i.e. "-S" */
end_comment

begin_comment
comment|/* Communication line variables */
end_comment

begin_decl_stmt
name|char
name|ttname
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of communication line. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_decl_stmt
name|int
name|connected
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if connected */
end_comment

begin_decl_stmt
name|int
name|startconnected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial state of connected */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_decl_stmt
name|long
name|speed
init|=
operator|-
literal|1L
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line speed */
end_comment

begin_decl_stmt
name|int
name|parity
decl_stmt|,
comment|/* Parity specified, 0,'e','o',etc */
name|autopar
init|=
literal|0
decl_stmt|,
comment|/* Automatic parity change flag */
name|sosi
init|=
literal|0
decl_stmt|,
comment|/* Shift-In/Out flag */
name|flow
decl_stmt|,
comment|/* Flow control */
name|turn
init|=
literal|0
decl_stmt|,
comment|/* Line turnaround handshake flag */
name|turnch
init|=
name|XON
decl_stmt|,
comment|/* Line turnaround character */
name|duplex
init|=
literal|0
decl_stmt|,
comment|/* Duplex, full by default */
name|escape
init|=
name|DFESC
decl_stmt|,
comment|/* Escape character for connect */
name|delay
init|=
name|DDELAY
decl_stmt|,
comment|/* Initial delay before sending */
name|tnlm
init|=
literal|0
decl_stmt|,
comment|/* Terminal newline mode */
name|mdmtyp
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Modem type (initially none)  */
end_comment

begin_comment
comment|/* Networks for SET HOST */
end_comment

begin_define
define|#
directive|define
name|MYHOSTL
value|100
end_define

begin_decl_stmt
name|char
name|myhost
index|[
name|MYHOSTL
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local host name */
end_comment

begin_decl_stmt
name|int
name|network
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Network vs tty connection */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* For now, DECnet is the only type supported by OS/2 */
end_comment

begin_decl_stmt
name|int
name|nettype
init|=
name|NET_DEC
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|nettype
init|=
name|NET_TCPB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assume TCP/IP (BSD sockets) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_extern
extern|extern initpad(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|revcall
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X.25 reverse call not selected */
end_comment

begin_decl_stmt
name|int
name|closgr
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X.25 closed user group not selected */
end_comment

begin_decl_stmt
name|int
name|cudata
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X.25 call user data not specified */
end_comment

begin_decl_stmt
name|char
name|udata
index|[
name|MAXCUDATA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* X.25 call user data */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_comment
comment|/* Other recent additions */
end_comment

begin_decl_stmt
name|int
name|tlevel
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Take-file command level */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|cmdlvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maclvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro invocation level */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
name|int
name|carrier
init|=
name|CAR_AUT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pay attention to carrier signal */
end_comment

begin_decl_stmt
name|int
name|cdtimo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Carrier wait timeout */
end_comment

begin_decl_stmt
name|int
name|xitsta
init|=
name|GOOD_EXIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program exit status */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* Default filename collision action */
end_comment

begin_decl_stmt
name|int
name|fncact
init|=
name|XYFX_X
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* REPLACE for VAX/VMS */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|fncact
init|=
name|XYFX_B
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BACKUP for everybody else */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_decl_stmt
name|int
name|bgset
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BACKGROUND mode set explicitly */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_decl_stmt
name|int
name|suspend
init|=
name|DFSUSP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether SUSPEND command, etc, */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* is to be allowed. */
end_comment

begin_decl_stmt
name|int
name|suspend
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_comment
comment|/* Statistics variables */
end_comment

begin_decl_stmt
name|long
name|filcnt
decl_stmt|,
comment|/* Number of files in transaction */
name|flci
decl_stmt|,
comment|/* Characters from line, current file */
name|flco
decl_stmt|,
comment|/* Chars to line, current file  */
name|tlci
decl_stmt|,
comment|/* Chars from line in transaction */
name|tlco
decl_stmt|,
comment|/* Chars to line in transaction */
name|ffc
decl_stmt|,
comment|/* Chars to/from current file */
name|tfc
decl_stmt|,
comment|/* Chars to/from files in transaction */
name|rptn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Repeated characters compressed */
end_comment

begin_decl_stmt
name|int
name|tsecs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Seconds for transaction */
end_comment

begin_decl_stmt
name|int
name|fsecs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Per-file timer */
end_comment

begin_comment
comment|/* Flags */
end_comment

begin_decl_stmt
name|int
name|deblog
init|=
literal|0
decl_stmt|,
comment|/* Flag for debug logging */
name|debses
init|=
literal|0
decl_stmt|,
comment|/* Flag for DEBUG SESSION */
name|pktlog
init|=
literal|0
decl_stmt|,
comment|/* Flag for packet logging */
name|seslog
init|=
literal|0
decl_stmt|,
comment|/* Session logging */
name|tralog
init|=
literal|0
decl_stmt|,
comment|/* Transaction logging */
name|displa
init|=
literal|0
decl_stmt|,
comment|/* File transfer display on/off */
name|stdouf
init|=
literal|0
decl_stmt|,
comment|/* Flag for output to stdout */
name|stdinf
init|=
literal|0
decl_stmt|,
comment|/* Flag for input from stdin */
name|xflg
init|=
literal|0
decl_stmt|,
comment|/* Flag for X instead of F packet */
name|hcflg
init|=
literal|0
decl_stmt|,
comment|/* Doing Host command */
name|fncnv
init|=
literal|1
decl_stmt|,
comment|/* Flag for file name conversion */
name|binary
init|=
literal|0
decl_stmt|,
comment|/* Flag for binary file */
name|savmod
init|=
literal|0
decl_stmt|,
comment|/* Saved file mode (whole session) */
name|bsave
init|=
literal|0
decl_stmt|,
comment|/* Saved file mode (per file) */
name|bsavef
init|=
literal|0
decl_stmt|,
comment|/* Flag if bsave was used. */
name|cmask
init|=
literal|0177
decl_stmt|,
comment|/* Connect byte mask */
name|fmask
init|=
literal|0377
decl_stmt|,
comment|/* File byte mask */
name|warn
init|=
literal|0
decl_stmt|,
comment|/* Flag for file warning */
name|quiet
init|=
literal|0
decl_stmt|,
comment|/* Be quiet during file transfer */
name|local
init|=
literal|0
decl_stmt|,
comment|/* Flag for external tty vs stdout */
name|server
init|=
literal|0
decl_stmt|,
comment|/* Flag for being a server */
name|cflg
init|=
literal|0
decl_stmt|,
comment|/* Connect before transaction */
name|cnflg
init|=
literal|0
decl_stmt|,
comment|/* Connect after transaction */
name|cxseen
init|=
literal|0
decl_stmt|,
comment|/* Flag for cancelling a file */
name|czseen
init|=
literal|0
decl_stmt|,
comment|/* Flag for cancelling file group */
name|discard
init|=
literal|0
decl_stmt|,
comment|/* Flag for file to be discarded */
name|keep
init|=
literal|0
decl_stmt|,
comment|/* Keep incomplete files */
name|unkcs
init|=
literal|1
decl_stmt|,
comment|/* Keep file w/unknown character set */
name|nakstate
init|=
literal|0
decl_stmt|,
comment|/* In a state where we can send NAKs */
name|dblchar
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character to double when sending */
end_comment

begin_comment
comment|/* Variables passed from command parser to protocol module */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSPL
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int parser
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The parser itself */
end_comment

begin_decl_stmt
name|char
modifier|*
name|clcmds
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to command-line commands */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_decl_stmt
name|CHAR
name|sstate
init|=
operator|(
name|CHAR
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starting state for automaton */
end_comment

begin_decl_stmt
name|CHAR
name|zstate
init|=
operator|(
name|CHAR
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For remembering sstate */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmarg
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to command data */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmarg2
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to 2nd command data */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|cmlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to file list in argv */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Flags for the ENABLE and DISABLE commands */
end_comment

begin_decl_stmt
name|int
name|en_cwd
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CD/CWD */
end_comment

begin_decl_stmt
name|int
name|en_del
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DELETE */
end_comment

begin_decl_stmt
name|int
name|en_dir
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIRECTORY */
end_comment

begin_decl_stmt
name|int
name|en_fin
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FINISH/BYE */
end_comment

begin_decl_stmt
name|int
name|en_get
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GET */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOPUSH
end_ifndef

begin_decl_stmt
name|int
name|en_hos
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* HOST enabled */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|en_hos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* HOST disabled */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPUSH */
end_comment

begin_decl_stmt
name|int
name|en_sen
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SEND */
end_comment

begin_decl_stmt
name|int
name|en_set
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SET */
end_comment

begin_decl_stmt
name|int
name|en_spa
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPACE */
end_comment

begin_decl_stmt
name|int
name|en_typ
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TYPE */
end_comment

begin_decl_stmt
name|int
name|en_who
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WHO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_comment
comment|/* Data General AOS/VS can't do this */
end_comment

begin_decl_stmt
name|int
name|en_bye
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BYE */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|en_bye
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BYE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Miscellaneous */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global copies of argv */
end_comment

begin_decl_stmt
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and argc  */
end_comment

begin_decl_stmt
name|int
name|xargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* an immutable copy of argc */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xarg0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and of argv[0] */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dftty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default tty name from ck?tio.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default location: remote/local */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfprty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default parity */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dfflow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default flow control */
end_comment

begin_comment
comment|/*   Buffered file input and output buffers.  See getpkt() in ckcfns.c   and zoutdump() in the system-dependent file i/o module (usually ck?fio.c). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DYNAMIC
end_ifndef

begin_comment
comment|/* Now we allocate them dynamically, see getiobs() below. */
end_comment

begin_decl_stmt
name|char
name|zinbuffer
index|[
name|INBUFSIZE
index|]
decl_stmt|,
name|zoutbuffer
index|[
name|OBUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|zinptr
decl_stmt|,
modifier|*
name|zoutptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|zincnt
decl_stmt|,
name|zoutcnt
decl_stmt|;
end_decl_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int getiobs
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_escape
end_escape

begin_comment
comment|/*  M A I N  --  C-Kermit main program  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCCTRAP
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|extern
name|jmp_buf
name|cmjbuf
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_comment
comment|/* Special for Atari ST */
end_comment

begin_expr_stmt
name|cc_clean
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCCTRAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_comment
comment|/* On the Apollo, intercept main to insert a cleanup handler */
end_comment

begin_decl_stmt
name|int
name|ckcmai
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
else|#
directive|else
function|int main
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
modifier|*
name|argv
decl_stmt|;
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* aegis */
block|{
ifdef|#
directive|ifdef
name|datageneral
name|short
modifier|*
name|pfha
init|=
literal|016000000036
decl_stmt|;
comment|/* Get around LANG_RT problem -- */
operator|*
name|pfha
operator|=
operator|(
name|short
operator|)
literal|0
expr_stmt|;
comment|/* No user protection fault handler */
endif|#
directive|endif
comment|/* datageneral */
comment|/* Do some initialization */
if|if
condition|(
name|sysinit
argument_list|()
operator|<
literal|0
condition|)
comment|/* System-dependent initialization. */
name|fatal
argument_list|(
literal|"Can't initialize!"
argument_list|)
expr_stmt|;
name|connoi
argument_list|()
expr_stmt|;
comment|/* Console interrupts off */
ifndef|#
directive|ifndef
name|MAC
name|xargc
operator|=
name|xargs
operator|=
name|argc
expr_stmt|;
comment|/* Make global copies of argc */
name|xargv
operator|=
name|argv
expr_stmt|;
comment|/* ...and argv. */
name|xarg0
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
endif|#
directive|endif
comment|/* MAC */
name|sstate
operator|=
literal|0
expr_stmt|;
comment|/* No default start state. */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|getiobs
argument_list|()
operator|<
literal|0
condition|)
name|fatal
argument_list|(
literal|"Can't allocate i/o buffers!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DYNAMIC */
name|ckhost
argument_list|(
name|myhost
argument_list|,
name|MYHOSTL
argument_list|)
expr_stmt|;
comment|/* Name of local host */
name|strcpy
argument_list|(
name|ttname
argument_list|,
name|dftty
argument_list|)
expr_stmt|;
comment|/* Set up default tty name. */
name|local
operator|=
name|dfloc
expr_stmt|;
comment|/* And whether it's local or remote. */
name|parity
operator|=
name|dfprty
expr_stmt|;
comment|/* Set initial parity, */
name|flow
operator|=
name|dfflow
expr_stmt|;
comment|/* and flow control. */
if|if
condition|(
name|local
condition|)
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* If default tty line */
name|printf
argument_list|(
literal|"%s: Can't open device\n"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
comment|/* is external, open it */
name|local
operator|=
literal|0
expr_stmt|;
comment|/* now... */
name|strcpy
argument_list|(
name|ttname
argument_list|,
name|CTTNAM
argument_list|)
expr_stmt|;
block|}
name|speed
operator|=
name|ttgspd
argument_list|()
expr_stmt|;
comment|/* Get transmission speed. */
ifdef|#
directive|ifdef
name|SUNX25
name|initpad
argument_list|()
expr_stmt|;
comment|/* Initialize X.25 PAD */
endif|#
directive|endif
comment|/* SUNX25 */
if|if
condition|(
name|inibufs
argument_list|(
name|SBSIZ
argument_list|,
name|RBSIZ
argument_list|)
operator|<
literal|0
condition|)
comment|/* Allocate packet buffers */
name|fatal
argument_list|(
literal|"Can't allocate packet buffers!"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOICP
ifdef|#
directive|ifdef
name|MAC
name|cmdini
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* Not MAC */
comment|/* Attempt to take ini file before doing command line */
operator|*
name|cmdfil
operator|=
literal|'\0'
expr_stmt|;
comment|/* Assume no command file. */
name|prescan
argument_list|()
expr_stmt|;
comment|/* But first check for -y option */
ifndef|#
directive|ifndef
name|NOCCTRAP
name|setint
argument_list|()
expr_stmt|;
comment|/* Set up interrupts */
if|if
condition|(
name|setjmp
argument_list|(
name|cmjbuf
argument_list|)
condition|)
block|{
comment|/* Control-C trap returns to here. */
ifdef|#
directive|ifdef
name|GEMDOS
name|cc_clean
argument_list|()
expr_stmt|;
comment|/* Atari: Clean up after ^C-trap. */
endif|#
directive|endif
comment|/* GEMDOS */
name|doexit
argument_list|(
name|GOOD_EXIT
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Exit with good status. */
block|}
else|else
block|{
endif|#
directive|endif
comment|/* NOCCTRAP */
name|cmdini
argument_list|()
expr_stmt|;
comment|/* Sets tlevel */
while|while
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Execute init file. */
name|sstate
operator|=
name|parser
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Loop getting commands. */
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
comment|/* Enter protocol if requested. */
block|}
ifndef|#
directive|ifndef
name|NOCCTRAP
block|}
endif|#
directive|endif
comment|/* NOCCTRAP */
comment|/*   In UNIX there are two ways to invoke Kermit with a cmdfile:   (1) From the kermit command line, e.g. "kermit cmdfile [ options... ]"       argv[0] = "kermit"       argv[1] = "cmdfile"   (2) By executing a cmdfile whose first line is like "#!/path/kermit"       argv[0] = "/path/kermit" (sometimes just "kermit")       argv[1] = "/path/cmdfile" */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
if|if
condition|(
operator|*
name|argv
index|[
literal|1
index|]
operator|!=
literal|'-'
condition|)
block|{
if|if
condition|(
name|zchki
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
operator|>
literal|0
condition|)
block|{
name|strcpy
argument_list|(
name|cmdfil
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
operator|*
name|cmdfil
condition|)
block|{
comment|/* If we got one, */
name|dotake
argument_list|(
name|cmdfil
argument_list|)
expr_stmt|;
comment|/* execute it */
while|while
condition|(
name|tlevel
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* until it runs out. */
name|sstate
operator|=
name|parser
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Loop getting commands. */
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
comment|/* Enter protocol if requested. */
block|}
block|}
operator|*
name|cmdfil
operator|=
literal|'\0'
expr_stmt|;
comment|/* Done, nullify the file name */
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* NOICP */
ifndef|#
directive|ifndef
name|NOCMDL
comment|/* Look for a UNIX-style command line... */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
comment|/* Command line arguments? */
name|sstate
operator|=
name|cmdlin
argument_list|()
expr_stmt|;
comment|/* Yes, parse. */
name|zstate
operator|=
name|sstate
expr_stmt|;
comment|/* Remember sstate around protocol */
if|if
condition|(
name|cflg
condition|)
name|conect
argument_list|()
expr_stmt|;
comment|/* Connect first if requested */
if|if
condition|(
name|sstate
condition|)
block|{
if|if
condition|(
name|displa
condition|)
name|concb
argument_list|(
operator|(
name|char
operator|)
name|escape
argument_list|)
expr_stmt|;
comment|/* (for console "interrupts") */
ifndef|#
directive|ifndef
name|NOCCTRAP
name|setint
argument_list|()
expr_stmt|;
comment|/* Set up interrupts */
if|if
condition|(
name|setjmp
argument_list|(
name|cmjbuf
argument_list|)
condition|)
block|{
comment|/* Control-C trap returns to here. */
ifdef|#
directive|ifdef
name|GEMDOS
name|cc_clean
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* GEMDOS */
if|if
condition|(
name|cnflg
condition|)
name|conect
argument_list|()
expr_stmt|;
comment|/* connect again if requested, */
block|}
else|else
block|{
endif|#
directive|endif
comment|/* NOCCTRAP */
name|proto
argument_list|()
expr_stmt|;
comment|/* Take any requested action, then */
if|if
condition|(
operator|!
name|quiet
condition|)
comment|/* put cursor back at left margin, */
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|cnflg
condition|)
name|conect
argument_list|()
expr_stmt|;
comment|/* connect if requested, */
ifndef|#
directive|ifndef
name|NOCCTRAP
block|}
endif|#
directive|endif
comment|/* NOCCTRAP */
block|}
comment|/*   If interactive commands were given on the command line (using the   -C "command, command, ..." option), assign them to a macro called   "cl_commands", then execute the macro and leave it defined for   subsequent re-execution if desired. */
ifndef|#
directive|ifndef
name|NOSPL
if|if
condition|(
name|clcmds
condition|)
block|{
comment|/* Check for -C commands */
name|int
name|x
decl_stmt|;
name|x
operator|=
name|addmac
argument_list|(
literal|"cl_commands"
argument_list|,
name|clcmds
argument_list|)
expr_stmt|;
comment|/* Put macro in table */
if|if
condition|(
name|x
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* If successful, */
name|dodo
argument_list|(
name|x
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* set up for macro execution */
while|while
condition|(
name|maclvl
operator|>
operator|-
literal|1
condition|)
block|{
comment|/* Loop getting macro commands. */
name|sstate
operator|=
name|parser
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
comment|/* Enter protocol if requested. */
block|}
block|}
block|}
endif|#
directive|endif
comment|/* NOSPL */
ifndef|#
directive|ifndef
name|NOICP
comment|/*   If a command-line action argument was given and -S ("stay") was not given,   exit now. */
if|if
condition|(
operator|(
name|cflg
operator|||
name|cnflg
operator|||
name|zstate
operator|)
operator|&&
operator|!
name|stayflg
condition|)
endif|#
directive|endif
comment|/* NOICP */
name|doexit
argument_list|(
name|GOOD_EXIT
argument_list|,
name|xitsta
argument_list|)
expr_stmt|;
comment|/* exit with good status */
block|}
endif|#
directive|endif
comment|/* NOCMDL */
ifdef|#
directive|ifdef
name|NOICP
comment|/* No interactive command parser */
else|else
block|{
ifndef|#
directive|ifndef
name|NOCMDL
name|usage
argument_list|()
expr_stmt|;
comment|/* Command-line-only version */
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Neither one! */
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOCMDL */
block|}
else|#
directive|else
comment|/* not NOICP */
comment|/*   If no action requested on command line, or if -S ("stay") was included,   enter the interactive command parser. */
name|herald
argument_list|()
expr_stmt|;
comment|/* Display program herald. */
ifndef|#
directive|ifndef
name|NOCCTRAP
comment|/* If not no Control-C trap */
name|ccagain
label|:
if|if
condition|(
name|setjmp
argument_list|(
name|cmjbuf
argument_list|)
condition|)
block|{
comment|/* Control-C trap returns to here. */
ifdef|#
directive|ifdef
name|GEMDOS
name|cc_clean
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* GEMDOS */
name|fixcmd
argument_list|()
expr_stmt|;
comment|/* Pop command stacks, etc. */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckcmai got interrupt"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
goto|goto
name|ccagain
goto|;
comment|/* set up trap again. */
block|}
else|else
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"ckcmai setting interrupt trap"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setint
argument_list|()
expr_stmt|;
comment|/* Set up command interrupt traps */
block|}
else|#
directive|else
comment|/* NOCCTRAP */
name|setint
argument_list|()
expr_stmt|;
comment|/* Set up command interrupt traps */
endif|#
directive|endif
comment|/* NOCCTRAP */
ifdef|#
directive|ifdef
name|MAC
while|while
condition|(
literal|1
condition|)
block|{
specifier|extern
name|char
modifier|*
name|lfiles
decl_stmt|;
comment|/* fake pointer cast */
if|if
condition|(
name|connected
condition|)
block|{
name|debug
argument_list|(
name|F100
argument_list|,
literal|"main: calling macparser"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sstate
operator|=
name|newparser
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
comment|/* ignore null command state */
if|if
condition|(
name|sstate
operator|==
literal|'n'
condition|)
name|sstate
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* 	     * process take files the finder gave us. 	     */
if|if
condition|(
operator|(
name|tlevel
operator|==
operator|-
literal|1
operator|)
operator|&&
name|lfiles
condition|)
name|startlfile
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"main: calling parser"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sstate
operator|=
name|parser
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sstate
operator|==
literal|'c'
condition|)
comment|/* if MAC connect */
name|sstate
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* Not MAC */
comment|/*   Running from an application file, or a command filename was   specified on the command line. */
if|if
condition|(
operator|*
name|cmdfil
condition|)
name|dotake
argument_list|(
name|cmdfil
argument_list|)
expr_stmt|;
comment|/* Command file spec'd on cmd line */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Loop getting commands. */
name|sstate
operator|=
name|parser
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sstate
condition|)
name|proto
argument_list|()
expr_stmt|;
comment|/* Enter protocol if requested. */
block|}
endif|#
directive|endif
comment|/* MAC */
endif|#
directive|endif
comment|/* NOICP */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_comment
comment|/* Allocate file i/o buffers */
end_comment

begin_decl_stmt
name|char
modifier|*
name|zinbuffer
decl_stmt|,
modifier|*
name|zoutbuffer
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|getiobs
parameter_list|()
block|{
name|zinbuffer
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|INBUFSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|zinbuffer
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|zoutbuffer
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|OBUFSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|zoutbuffer
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"getiobs ok"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
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
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

end_unit

