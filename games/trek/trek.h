begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)trek.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_comment
comment|/* **  Global Declarations ** **	Virtually all non-local variable declarations are made in this **	file.  Exceptions are those things which are initialized, which **	are defined in "externs.c", and things which are local to one **	program file. ** **	So far as I know, nothing in here must be preinitialized to **	zero. ** **	You may have problems from the loader if you move this to a **	different machine.  These things actually get allocated in each **	source file, which UNIX allows; however, you may (on other **	systems) have to change everything in here to be "extern" and **	actually allocate stuff in "externs.c" */
end_comment

begin_comment
comment|/* external function definitions */
end_comment

begin_function_decl
specifier|extern
name|double
name|franf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* floating random number function */
end_comment

begin_function_decl
specifier|extern
name|double
name|sqrt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* square root */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|sin
argument_list|()
decl_stmt|,
name|cos
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trig functions */
end_comment

begin_function_decl
specifier|extern
name|double
name|atan2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fancy arc tangent function */
end_comment

begin_function_decl
specifier|extern
name|double
name|log
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* log base e */
end_comment

begin_function_decl
specifier|extern
name|double
name|pow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* power function */
end_comment

begin_function_decl
specifier|extern
name|double
name|fabs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* absolute value function */
end_comment

begin_function_decl
specifier|extern
name|double
name|exp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* exponential function */
end_comment

begin_comment
comment|/*********************  GALAXY  **************************/
end_comment

begin_comment
comment|/* galactic parameters */
end_comment

begin_define
define|#
directive|define
name|NSECTS
value|10
end_define

begin_comment
comment|/* dimensions of quadrant in sectors */
end_comment

begin_define
define|#
directive|define
name|NQUADS
value|8
end_define

begin_comment
comment|/* dimension of galazy in quadrants */
end_comment

begin_define
define|#
directive|define
name|NINHAB
value|32
end_define

begin_comment
comment|/* number of quadrants which are inhabited */
end_comment

begin_struct
struct|struct
name|quad
comment|/* definition for each quadrant */
block|{
name|char
name|bases
decl_stmt|;
comment|/* number of bases in this quadrant */
name|char
name|klings
decl_stmt|;
comment|/* number of Klingons in this quadrant */
name|char
name|holes
decl_stmt|;
comment|/* number of black holes in this quadrant */
name|int
name|scanned
decl_stmt|;
comment|/* star chart entry (see below) */
name|char
name|stars
decl_stmt|;
comment|/* number of stars in this quadrant */
name|char
name|qsystemname
decl_stmt|;
comment|/* starsystem name (see below) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Q_DISTRESSED
value|0200
end_define

begin_define
define|#
directive|define
name|Q_SYSTEM
value|077
end_define

begin_comment
comment|/*  systemname conventions:  *	1 -> NINHAB	index into Systemname table for live system.  *	+ Q_DISTRESSED	distressed starsystem -- systemname& Q_SYSTEM  *			is the index into the Event table which will  *			have the system name  *	0		dead or nonexistent starsystem  *  *  starchart ("scanned") conventions:  *	0 -> 999	taken as is  *	-1		not yet scanned ("...")  *	1000		supernova ("///")  *	1001		starbase + ??? (".1.") */
end_comment

begin_comment
comment|/* ascii names of systems */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Systemname
index|[
name|NINHAB
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quadrant definition */
end_comment

begin_decl_stmt
name|struct
name|quad
name|Quad
index|[
name|NQUADS
index|]
index|[
name|NQUADS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defines for sector map  (below) */
end_comment

begin_define
define|#
directive|define
name|EMPTY
value|'.'
end_define

begin_define
define|#
directive|define
name|STAR
value|'*'
end_define

begin_define
define|#
directive|define
name|BASE
value|'#'
end_define

begin_define
define|#
directive|define
name|ENTERPRISE
value|'E'
end_define

begin_define
define|#
directive|define
name|QUEENE
value|'Q'
end_define

begin_define
define|#
directive|define
name|KLINGON
value|'K'
end_define

begin_define
define|#
directive|define
name|INHABIT
value|'@'
end_define

begin_define
define|#
directive|define
name|HOLE
value|' '
end_define

begin_comment
comment|/* current sector map */
end_comment

begin_decl_stmt
name|char
name|Sect
index|[
name|NSECTS
index|]
index|[
name|NSECTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************ DEVICES ******************************/
end_comment

begin_define
define|#
directive|define
name|NDEV
value|16
end_define

begin_comment
comment|/* max number of devices */
end_comment

begin_comment
comment|/* device tokens */
end_comment

begin_define
define|#
directive|define
name|WARP
value|0
end_define

begin_comment
comment|/* warp engines */
end_comment

begin_define
define|#
directive|define
name|SRSCAN
value|1
end_define

begin_comment
comment|/* short range scanners */
end_comment

begin_define
define|#
directive|define
name|LRSCAN
value|2
end_define

begin_comment
comment|/* long range scanners */
end_comment

begin_define
define|#
directive|define
name|PHASER
value|3
end_define

begin_comment
comment|/* phaser control */
end_comment

begin_define
define|#
directive|define
name|TORPED
value|4
end_define

begin_comment
comment|/* photon torpedo control */
end_comment

begin_define
define|#
directive|define
name|IMPULSE
value|5
end_define

begin_comment
comment|/* impulse engines */
end_comment

begin_define
define|#
directive|define
name|SHIELD
value|6
end_define

begin_comment
comment|/* shield control */
end_comment

begin_define
define|#
directive|define
name|COMPUTER
value|7
end_define

begin_comment
comment|/* on board computer */
end_comment

begin_define
define|#
directive|define
name|SSRADIO
value|8
end_define

begin_comment
comment|/* subspace radio */
end_comment

begin_define
define|#
directive|define
name|LIFESUP
value|9
end_define

begin_comment
comment|/* life support systems */
end_comment

begin_define
define|#
directive|define
name|SINS
value|10
end_define

begin_comment
comment|/* Space Inertial Navigation System */
end_comment

begin_define
define|#
directive|define
name|CLOAK
value|11
end_define

begin_comment
comment|/* cloaking device */
end_comment

begin_define
define|#
directive|define
name|XPORTER
value|12
end_define

begin_comment
comment|/* transporter */
end_comment

begin_define
define|#
directive|define
name|SHUTTLE
value|13
end_define

begin_comment
comment|/* shuttlecraft */
end_comment

begin_comment
comment|/* device names */
end_comment

begin_struct
struct|struct
name|device
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
name|char
modifier|*
name|person
decl_stmt|;
comment|/* the person who fixes it */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|device
name|Device
index|[
name|NDEV
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************  EVENTS  ****************************/
end_comment

begin_define
define|#
directive|define
name|NEVENTS
value|12
end_define

begin_comment
comment|/* number of different event types */
end_comment

begin_define
define|#
directive|define
name|E_LRTB
value|1
end_define

begin_comment
comment|/* long range tractor beam */
end_comment

begin_define
define|#
directive|define
name|E_KATSB
value|2
end_define

begin_comment
comment|/* Klingon attacks starbase */
end_comment

begin_define
define|#
directive|define
name|E_KDESB
value|3
end_define

begin_comment
comment|/* Klingon destroys starbase */
end_comment

begin_define
define|#
directive|define
name|E_ISSUE
value|4
end_define

begin_comment
comment|/* distress call is issued */
end_comment

begin_define
define|#
directive|define
name|E_ENSLV
value|5
end_define

begin_comment
comment|/* Klingons enslave a quadrant */
end_comment

begin_define
define|#
directive|define
name|E_REPRO
value|6
end_define

begin_comment
comment|/* a Klingon is reproduced */
end_comment

begin_define
define|#
directive|define
name|E_FIXDV
value|7
end_define

begin_comment
comment|/* fix a device */
end_comment

begin_define
define|#
directive|define
name|E_ATTACK
value|8
end_define

begin_comment
comment|/* Klingon attack during rest period */
end_comment

begin_define
define|#
directive|define
name|E_SNAP
value|9
end_define

begin_comment
comment|/* take a snapshot for time warp */
end_comment

begin_define
define|#
directive|define
name|E_SNOVA
value|10
end_define

begin_comment
comment|/* supernova occurs */
end_comment

begin_define
define|#
directive|define
name|E_GHOST
value|0100
end_define

begin_comment
comment|/* ghost of a distress call if ssradio out */
end_comment

begin_define
define|#
directive|define
name|E_HIDDEN
value|0200
end_define

begin_comment
comment|/* event that is unreportable because ssradio out */
end_comment

begin_define
define|#
directive|define
name|E_EVENT
value|077
end_define

begin_comment
comment|/* mask to get event code */
end_comment

begin_struct
struct|struct
name|event
block|{
name|char
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* coordinates */
name|double
name|date
decl_stmt|;
comment|/* trap stardate */
name|char
name|evcode
decl_stmt|;
comment|/* event type */
name|char
name|systemname
decl_stmt|;
comment|/* starsystem name */
block|}
struct|;
end_struct

begin_comment
comment|/* systemname conventions:  *	1 -> NINHAB	index into Systemname table for reported distress calls  *  * evcode conventions:  *	1 -> NEVENTS-1	event type  *	+ E_HIDDEN	unreported (SSradio out)  *	+ E_GHOST	actually already expired  *	0		unallocated  */
end_comment

begin_define
define|#
directive|define
name|MAXEVENTS
value|25
end_define

begin_comment
comment|/* max number of concurrently pending events */
end_comment

begin_decl_stmt
name|struct
name|event
name|Event
index|[
name|MAXEVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dynamic event list; one entry per pending event */
end_comment

begin_comment
comment|/*****************************  KLINGONS  *******************************/
end_comment

begin_struct
struct|struct
name|kling
block|{
name|char
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* coordinates */
name|int
name|power
decl_stmt|;
comment|/* power left */
name|double
name|dist
decl_stmt|;
comment|/* distance to Enterprise */
name|double
name|avgdist
decl_stmt|;
comment|/* average over this move */
name|char
name|srndreq
decl_stmt|;
comment|/* set if surrender has been requested */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXKLQUAD
value|9
end_define

begin_comment
comment|/* maximum klingons per quadrant */
end_comment

begin_comment
comment|/********************** MISCELLANEOUS ***************************/
end_comment

begin_comment
comment|/* condition codes */
end_comment

begin_define
define|#
directive|define
name|GREEN
value|0
end_define

begin_define
define|#
directive|define
name|DOCKED
value|1
end_define

begin_define
define|#
directive|define
name|YELLOW
value|2
end_define

begin_define
define|#
directive|define
name|RED
value|3
end_define

begin_comment
comment|/* starbase coordinates */
end_comment

begin_define
define|#
directive|define
name|MAXBASES
value|9
end_define

begin_comment
comment|/* maximum number of starbases in galaxy */
end_comment

begin_comment
comment|/*  distress calls  */
end_comment

begin_define
define|#
directive|define
name|MAXDISTR
value|5
end_define

begin_comment
comment|/* maximum concurrent distress calls */
end_comment

begin_comment
comment|/* phaser banks */
end_comment

begin_define
define|#
directive|define
name|NBANKS
value|6
end_define

begin_comment
comment|/* number of phaser banks */
end_comment

begin_struct
struct|struct
name|xy
block|{
name|char
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* coordinates */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	note that much of the stuff in the following structs CAN NOT  *	be moved around!!!!  */
end_comment

begin_comment
comment|/* information regarding the state of the starship */
end_comment

begin_struct
struct|struct
block|{
name|double
name|warp
decl_stmt|;
comment|/* warp factor */
name|double
name|warp2
decl_stmt|;
comment|/* warp factor squared */
name|double
name|warp3
decl_stmt|;
comment|/* warp factor cubed */
name|char
name|shldup
decl_stmt|;
comment|/* shield up flag */
name|char
name|cloaked
decl_stmt|;
comment|/* set if cloaking device on */
name|int
name|energy
decl_stmt|;
comment|/* starship's energy */
name|int
name|shield
decl_stmt|;
comment|/* energy in shields */
name|double
name|reserves
decl_stmt|;
comment|/* life support reserves */
name|int
name|crew
decl_stmt|;
comment|/* ship's complement */
name|int
name|brigfree
decl_stmt|;
comment|/* space left in brig */
name|char
name|torped
decl_stmt|;
comment|/* torpedoes */
name|char
name|cloakgood
decl_stmt|;
comment|/* set if we have moved */
name|int
name|quadx
decl_stmt|;
comment|/* quadrant x coord */
name|int
name|quady
decl_stmt|;
comment|/* quadrant y coord */
name|int
name|sectx
decl_stmt|;
comment|/* sector x coord */
name|int
name|secty
decl_stmt|;
comment|/* sector y coord */
name|char
name|cond
decl_stmt|;
comment|/* condition code */
name|char
name|sinsbad
decl_stmt|;
comment|/* Space Inertial Navigation System condition */
name|char
modifier|*
name|shipname
decl_stmt|;
comment|/* name of current starship */
name|char
name|ship
decl_stmt|;
comment|/* current starship */
name|int
name|distressed
decl_stmt|;
comment|/* number of distress calls */
block|}
name|Ship
struct|;
end_struct

begin_comment
comment|/* sinsbad is set if SINS is working but not calibrated */
end_comment

begin_comment
comment|/* game related information, mostly scoring */
end_comment

begin_struct
struct|struct
block|{
name|int
name|killk
decl_stmt|;
comment|/* number of klingons killed */
name|int
name|deaths
decl_stmt|;
comment|/* number of deaths onboard Enterprise */
name|char
name|negenbar
decl_stmt|;
comment|/* number of hits on negative energy barrier */
name|char
name|killb
decl_stmt|;
comment|/* number of starbases killed */
name|int
name|kills
decl_stmt|;
comment|/* number of stars killed */
name|char
name|skill
decl_stmt|;
comment|/* skill rating of player */
name|char
name|length
decl_stmt|;
comment|/* length of game */
name|char
name|killed
decl_stmt|;
comment|/* set if you were killed */
name|char
name|killinhab
decl_stmt|;
comment|/* number of inhabited starsystems killed */
name|char
name|tourn
decl_stmt|;
comment|/* set if a tournament game */
name|char
name|passwd
index|[
literal|15
index|]
decl_stmt|;
comment|/* game password */
name|char
name|snap
decl_stmt|;
comment|/* set if snapshot taken */
name|char
name|helps
decl_stmt|;
comment|/* number of help calls */
name|int
name|captives
decl_stmt|;
comment|/* total number of captives taken */
block|}
name|Game
struct|;
end_struct

begin_comment
comment|/* per move information */
end_comment

begin_struct
struct|struct
block|{
name|char
name|free
decl_stmt|;
comment|/* set if a move is free */
name|char
name|endgame
decl_stmt|;
comment|/* end of game flag */
name|char
name|shldchg
decl_stmt|;
comment|/* set if shields changed this move */
name|char
name|newquad
decl_stmt|;
comment|/* set if just entered this quadrant */
name|char
name|resting
decl_stmt|;
comment|/* set if this move is a rest */
name|double
name|time
decl_stmt|;
comment|/* time used this move */
block|}
name|Move
struct|;
end_struct

begin_comment
comment|/* parametric information */
end_comment

begin_struct
struct|struct
block|{
name|char
name|bases
decl_stmt|;
comment|/* number of starbases */
name|char
name|klings
decl_stmt|;
comment|/* number of klingons */
name|double
name|date
decl_stmt|;
comment|/* stardate */
name|double
name|time
decl_stmt|;
comment|/* time left */
name|double
name|resource
decl_stmt|;
comment|/* Federation resources */
name|int
name|energy
decl_stmt|;
comment|/* starship's energy */
name|int
name|shield
decl_stmt|;
comment|/* energy in shields */
name|double
name|reserves
decl_stmt|;
comment|/* life support reserves */
name|int
name|crew
decl_stmt|;
comment|/* size of ship's complement */
name|int
name|brigfree
decl_stmt|;
comment|/* max possible number of captives */
name|char
name|torped
decl_stmt|;
comment|/* photon torpedos */
name|double
name|damfac
index|[
name|NDEV
index|]
decl_stmt|;
comment|/* damage factor */
name|double
name|dockfac
decl_stmt|;
comment|/* docked repair time factor */
name|double
name|regenfac
decl_stmt|;
comment|/* regeneration factor */
name|int
name|stopengy
decl_stmt|;
comment|/* energy to do emergency stop */
name|int
name|shupengy
decl_stmt|;
comment|/* energy to put up shields */
name|int
name|klingpwr
decl_stmt|;
comment|/* Klingon initial power */
name|int
name|warptime
decl_stmt|;
comment|/* time chewer multiplier */
name|double
name|phasfac
decl_stmt|;
comment|/* Klingon phaser power eater factor */
name|char
name|moveprob
index|[
literal|6
index|]
decl_stmt|;
comment|/* probability that a Klingon moves */
name|double
name|movefac
index|[
literal|6
index|]
decl_stmt|;
comment|/* Klingon move distance multiplier */
name|double
name|eventdly
index|[
name|NEVENTS
index|]
decl_stmt|;
comment|/* event time multipliers */
name|double
name|navigcrud
index|[
literal|2
index|]
decl_stmt|;
comment|/* navigation crudup factor */
name|int
name|cloakenergy
decl_stmt|;
comment|/* cloaking device energy per stardate */
name|double
name|damprob
index|[
name|NDEV
index|]
decl_stmt|;
comment|/* damage probability */
name|double
name|hitfac
decl_stmt|;
comment|/* Klingon attack factor */
name|int
name|klingcrew
decl_stmt|;
comment|/* number of Klingons in a crew */
name|double
name|srndrprob
decl_stmt|;
comment|/* surrender probability */
name|int
name|energylow
decl_stmt|;
comment|/* low energy mark (cond YELLOW) */
block|}
name|Param
struct|;
end_struct

begin_comment
comment|/* Sum of damage probabilities must add to 1000 */
end_comment

begin_comment
comment|/* other information kept in a snapshot */
end_comment

begin_struct
struct|struct
block|{
name|char
name|bases
decl_stmt|;
comment|/* number of starbases */
name|char
name|klings
decl_stmt|;
comment|/* number of klingons */
name|double
name|date
decl_stmt|;
comment|/* stardate */
name|double
name|time
decl_stmt|;
comment|/* time left */
name|double
name|resource
decl_stmt|;
comment|/* Federation resources */
name|char
name|distressed
decl_stmt|;
comment|/* number of currently distressed quadrants */
name|struct
name|event
modifier|*
name|eventptr
index|[
name|NEVENTS
index|]
decl_stmt|;
comment|/* pointer to event structs */
name|struct
name|xy
name|base
index|[
name|MAXBASES
index|]
decl_stmt|;
comment|/* locations of starbases */
block|}
name|Now
struct|;
end_struct

begin_comment
comment|/* Other stuff, not dumped in a snapshot */
end_comment

begin_struct
struct|struct
block|{
name|struct
name|kling
name|klingon
index|[
name|MAXKLQUAD
index|]
decl_stmt|;
comment|/* sorted Klingon list */
name|char
name|nkling
decl_stmt|;
comment|/* number of Klingons in this sector */
comment|/*< 0 means automatic override mode */
name|char
name|fast
decl_stmt|;
comment|/* set if speed> 300 baud */
name|struct
name|xy
name|starbase
decl_stmt|;
comment|/* starbase in current quadrant */
name|char
name|snapshot
index|[
sizeof|sizeof
name|Quad
operator|+
sizeof|sizeof
name|Event
operator|+
sizeof|sizeof
name|Now
index|]
decl_stmt|;
comment|/* snapshot for time warp */
name|char
name|statreport
decl_stmt|;
comment|/* set to get a status report on a srscan */
block|}
name|Etc
struct|;
end_struct

begin_comment
comment|/*  *	eventptr is a pointer to the event[] entry of the last  *	scheduled event of each type.  Zero if no such event scheduled.  */
end_comment

begin_comment
comment|/* Klingon move indicies */
end_comment

begin_define
define|#
directive|define
name|KM_OB
value|0
end_define

begin_comment
comment|/* Old quadrant, Before attack */
end_comment

begin_define
define|#
directive|define
name|KM_OA
value|1
end_define

begin_comment
comment|/* Old quadrant, After attack */
end_comment

begin_define
define|#
directive|define
name|KM_EB
value|2
end_define

begin_comment
comment|/* Enter quadrant, Before attack */
end_comment

begin_define
define|#
directive|define
name|KM_EA
value|3
end_define

begin_comment
comment|/* Enter quadrant, After attack */
end_comment

begin_define
define|#
directive|define
name|KM_LB
value|4
end_define

begin_comment
comment|/* Leave quadrant, Before attack */
end_comment

begin_define
define|#
directive|define
name|KM_LA
value|5
end_define

begin_comment
comment|/* Leave quadrant, After attack */
end_comment

begin_comment
comment|/* you lose codes */
end_comment

begin_define
define|#
directive|define
name|L_NOTIME
value|1
end_define

begin_comment
comment|/* ran out of time */
end_comment

begin_define
define|#
directive|define
name|L_NOENGY
value|2
end_define

begin_comment
comment|/* ran out of energy */
end_comment

begin_define
define|#
directive|define
name|L_DSTRYD
value|3
end_define

begin_comment
comment|/* destroyed by a Klingon */
end_comment

begin_define
define|#
directive|define
name|L_NEGENB
value|4
end_define

begin_comment
comment|/* ran into the negative energy barrier */
end_comment

begin_define
define|#
directive|define
name|L_SUICID
value|5
end_define

begin_comment
comment|/* destroyed in a nova */
end_comment

begin_define
define|#
directive|define
name|L_SNOVA
value|6
end_define

begin_comment
comment|/* destroyed in a supernova */
end_comment

begin_define
define|#
directive|define
name|L_NOLIFE
value|7
end_define

begin_comment
comment|/* life support died (so did you) */
end_comment

begin_define
define|#
directive|define
name|L_NOHELP
value|8
end_define

begin_comment
comment|/* you could not be rematerialized */
end_comment

begin_define
define|#
directive|define
name|L_TOOFAST
value|9
end_define

begin_comment
comment|/* pretty stupid going at warp 10 */
end_comment

begin_define
define|#
directive|define
name|L_STAR
value|10
end_define

begin_comment
comment|/* ran into a star */
end_comment

begin_define
define|#
directive|define
name|L_DSTRCT
value|11
end_define

begin_comment
comment|/* self destructed */
end_comment

begin_define
define|#
directive|define
name|L_CAPTURED
value|12
end_define

begin_comment
comment|/* captured by Klingons */
end_comment

begin_define
define|#
directive|define
name|L_NOCREW
value|13
end_define

begin_comment
comment|/* you ran out of crew */
end_comment

begin_comment
comment|/******************  COMPILE OPTIONS  ***********************/
end_comment

begin_comment
comment|/* Trace info */
end_comment

begin_define
define|#
directive|define
name|xTRACE
value|1
end_define

begin_decl_stmt
name|int
name|Trace
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|systemname
parameter_list|()
function_decl|;
end_function_decl

end_unit

