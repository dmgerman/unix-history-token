begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*options.h--------------------------------------------------------------------  	Matsushita(Panasonic) / Creative CD-ROM Driver	(matcd) 	Authored by Frank Durda IV  	Copyright 1994, 1995  Frank Durda IV.  All rights reserved. 	"FDIV" is a trademark of Frank Durda IV.   	Redistribution and use in source and binary forms, with or 	without modification, are permitted provided that the following 	conditions are met: 	1.  Redistributions of source code must retain the above copyright 	    notice positioned at the very beginning of this file without 	    modification, all copyright strings, all related programming 	    codes that display the copyright strings, this list of 	    conditions and the following disclaimer. 	2.  Redistributions in binary form must contain all copyright strings 	    and related programming code that display the copyright strings. 	3.  Redistributions in binary form must reproduce the above copyright 	    notice, this list of conditions and the following disclaimer in 	    the documentation and/or other materials provided with the 	    distribution. 	4.  All advertising materials mentioning features or use of this 	    software must display the following acknowledgement: 		"The Matsushita/Panasonic CD-ROM driver  was developed 		 by Frank Durda IV for use with "FreeBSD" and similar 		 operating systems." 	    "Similar operating systems" includes mainly non-profit oriented 	    systems for research and education, including but not restricted 	    to "NetBSD", "386BSD", and "Mach" (by CMU).  The wording of the 	    acknowledgement (in electronic form or printed text) may not be 	    changed without permission from the author. 	5.  Absolutely no warranty of function, fitness or purpose is made 	    by the author Frank Durda IV. 	6.  Neither the name of the author nor the name "FreeBSD" may 	    be used to endorse or promote products derived from this software 	    without specific prior written permission. 	    (The author can be reached at   bsdmail@nemesis.lonestar.org) 	7.  The product containing this software must meet all of these 	    conditions even if it is unsupported, not a complete system 	    and/or does not contain compiled code. 	8.  These conditions will be in force for the full life of the 	    copyright. 	9.  If all the above conditions are met, modifications to other 	    parts of this file may be freely made, although any person 	    or persons making changes do not receive the right to add their 	    name or names to the copyright strings and notices in this 	    software.  Persons making changes are encouraged to insert edit 	    history in matcd.c and to put your name and details of the 	    change there. 	10. You must have prior written permission from the author to 	    deviate from these terms.  	Vendors who produce product(s) containing this code are encouraged 	(but not required) to provide copies of the finished product(s) to 	the author and to correspond with the author about development 	activity relating to this code.   Donations of development hardware 	and/or software are also welcome.  (This is one of the faster ways 	to get a driver developed for a device.)   	THIS SOFTWARE IS PROVIDED BY THE DEVELOPER(S) ``AS IS'' AND ANY  	EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  	PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPER(S) BE  	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  	OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  	OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  	LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   -----No changes are allowed above this line------------------------------------ ----------------------------------------------------------------------------- 	Conditional compilation flags - change to suit your system ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*	AUTOHUNT	Adds extra code that allows the driver to search 			for interface cards rather than having to hard-code 			the locations in the kernel conf file. 			Leaving AUTOHUNT enabled is the recommended setting. */
end_comment

begin_define
define|#
directive|define
name|AUTOHUNT
end_define

begin_comment
comment|/*	NUMCTRLRS	Configures support for between one and four 			host interfaces, for up to 16 drives. 			The number of entries in the kernel config 			file is used by default, but this may be changed 			to a specific value if desired.  			Leaving NUMCTRLRS based on NMATCD is the 			recommended setting. */
end_comment

begin_if
if|#
directive|if
name|NMATCD
operator|>=
literal|4
end_if

begin_define
define|#
directive|define
name|NUMCTRLRS
value|4
end_define

begin_comment
comment|/*Limit driver to four host interfaces*/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*NMATCD*/
end_comment

begin_define
define|#
directive|define
name|NUMCTRLRS
value|NMATCD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NMATCD*/
end_comment

begin_comment
comment|/*	FULLDRIVER	If not set, the audio, non-data functions and 			some error recovery functions are eliminated from 			the compiled driver.  The resulting driver will be 			smaller and may help a kernel fit on a boot floppy. 			Leaving FULLDRIVER enabled is the recommended setting. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BOOTMFS
end_ifndef

begin_define
define|#
directive|define
name|FULLDRIVER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*BOOTMFS*/
end_comment

begin_comment
comment|/*	RESETONBOOT	causes the driver to reset the drive(s) to be 			reset during probing.  This causes any audio 			playback to be aborted and the drives will close 			their trays if they are open. 			Leaving RESETONBOOT enabled is the recommended setting. */
end_comment

begin_define
define|#
directive|define
name|RESETONBOOT
end_define

begin_comment
comment|/*<15>	LOCKDRIVE	If enabled, when a drive is opened using a<15>			minor number greater than 127, the drive door is<15>			locked.  The drive door remains locked until all<23>			partitions on the drive are closed.  The EJECT,<23>			ALLOW and PREVENT ioctls are refused when this locking<23>			mechanism is active.<15>			The additional code size is small so enabling<15>			LOCKDRIVE is the recommended setting. */
end_comment

begin_define
define|#
directive|define
name|LOCKDRIVE
end_define

begin_comment
comment|/*<14>	KRYTEN		This enables a bug that someone might consider<14>			to be a feature.  If KRYTEN is enabled and you are<14>			playing audio and you issue the resume-play ioctl,<14>			the audio will stutter, playing the same quarter<14>			of a second or so of audio several times before<14>			resuming normally.  Resuming from a pause acts<14>			normally regardless of the setting of this flag.<14>			Leaving KRYTEN disabled is the recommended setting.<14>*/
end_comment

begin_comment
comment|/*#define KRYTEN*/
end_comment

begin_comment
comment|/*--------------------------------------------------------------------------- 	This structure contains the hints for where we should look for the 	host adapter.  If you want to change where we search or reduce the 	places we search to avoid confusing some other device, either 	specify explicit addresses in the kernel config file (preferred) 	or change this array.  	If the kernel config file has multiple ? entries, the probe routines 	will use this table multiple times and will eliminate each failed 	entry that probe tries.  	WARNING:  The number of controller entries for this driver in config 	must be less than or equal to the number of hints if hints are used.  	If you add entries to the table, add them immediately before 	the -1 end-of-table marker.  The values already present are 	the ones used by Creative Labs boards and those of a few 	other vendors.  	Each additional entry increases the boot time by four seconds, 	and can increase the chance of accessing some other device. 	Therefore, the list should be kept to a minimum.  Once the 	devices have been correctly located, the kernel should be 	configured so that it looks only at the correct location from 	that point on.  	Be sure to search devices located below 0x3ff BEFORE scanning 	higher locations.  Some boards don't decode all I/O address lines, 	so 0x230 and 0x630 appear identical. ---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTOHUNT
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|port_hints
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|PC98
literal|0x30d2
block|,
literal|0x30d0
block|,
literal|0x30d4
block|,
literal|0x30d6
block|,
literal|0x30d8
block|,
literal|0x30da
block|,
literal|0x30dc
block|,
literal|0x30de
block|,
else|#
directive|else
comment|/* IBM-PC */
literal|0x230
block|,
comment|/*SB Pro& SB16*/
literal|0x240
block|,
comment|/*SB Pro& SB16*/
literal|0x250
block|,
comment|/*Creative omniCD standalone boards*/
literal|0x260
block|,
comment|/*Creative omniCD standalone boards*/
literal|0x340
block|,
comment|/*Laser Mate*/
literal|0x360
block|,
comment|/*Laser Mate*/
literal|0x630
block|,
comment|/*IBM*/
if|#
directive|if
literal|0
comment|/*	These locations are alternate settings for LaserMate and IBM 	boards, but they usually conflict with network and SCSI cards. 	I recommend against probing these randomly. */
block|0x310,
comment|/*Laser Mate*/
block|0x320,
comment|/*Laser Mate*/
block|0x330,
comment|/*Laser Mate*/
block|0x350,
comment|/*Laser Mate*/
block|0x370,
comment|/*Laser Mate*/
block|0x650,
comment|/*IBM*/
block|0x670,
comment|/*IBM*/
block|0x690,
comment|/*IBM*/
endif|#
directive|endif
comment|/*0*/
endif|#
directive|endif
comment|/* PC98 */
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*use.  Table MUST end with -1*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*AUTOHUNT*/
end_comment

begin_comment
comment|/*--------------------------------------------------------------------------- 	Debugging flags - Turn these on only if you are looking at a 			problem. ---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*	DEBUGOPEN	If enabled, debug messages for open and close 			operations. */
end_comment

begin_comment
comment|/*#define    	DEBUGOPEN*/
end_comment

begin_comment
comment|/*	DEBUGIO		If enabled, reports on calls to strategy, start 			and other I/O related functions. */
end_comment

begin_comment
comment|/*#define   	DEBUGIO*/
end_comment

begin_comment
comment|/*	DEBUGQUEUE	If enabled, shows activity on disk request queues. 			Warning - This debug is VERY VERY NOISY and will 			loop endlessly if queues are not null terminated 			as they should be. */
end_comment

begin_comment
comment|/*#define   	DEBUGQUEUE*/
end_comment

begin_comment
comment|/*	DEBUGCMD	If enabled, shows the actual commands being issued 			to the CD-ROM drives. */
end_comment

begin_comment
comment|/*#define 	DEBUGCMD*/
end_comment

begin_comment
comment|/*	DEBUGSLEEP	If enabled, reports on timeouts, wakeups, dropped 			threads, etc. */
end_comment

begin_comment
comment|/*#define 	DEBUGSLEEP*/
end_comment

begin_comment
comment|/*	DEBUGIOCTL	If enabled, reports on the various ioctl-related 			calls and operations.  You might have to enable 			DEBUGCMD as well to get enough debugging information. */
end_comment

begin_comment
comment|/*#define 	DEBUGIOCTL*/
end_comment

begin_comment
comment|/*	DEBUGPROBE	If enabled, reports on the process of locating 			adapters and drives.  The debugging in matcdprobe() 			and matcdattach() routines is enabled with this 			flag. */
end_comment

begin_comment
comment|/*#define 	DEBUGPROBE*/
end_comment

begin_comment
comment|/*End of options.h*/
end_comment

end_unit

