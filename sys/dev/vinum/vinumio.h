begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumio.h,v 1.19 2000/04/26 04:17:33 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|L
value|'F'
end_define

begin_comment
comment|/* ID letter of our ioctls */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_define
define|#
directive|define
name|MAX_IOCTL_REPLY
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_IOCTL_REPLY
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_struct
struct|struct
name|debuginfo
block|{
name|int
name|changeit
decl_stmt|;
name|int
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|objecttype
block|{
name|drive_object
block|,
name|sd_object
block|,
name|plex_object
block|,
name|volume_object
block|,
name|invalid_object
block|}
enum|;
end_enum

begin_comment
comment|/*  * The state to set with VINUM_SETSTATE.  Since each object has a  * different set of states, we need to translate later.  */
end_comment

begin_enum
enum|enum
name|objectstate
block|{
name|object_down
block|,
name|object_initializing
block|,
name|object_initialized
block|,
name|object_up
block|}
enum|;
end_enum

begin_comment
comment|/*  * This structure is used for modifying objects  * (VINUM_SETSTATE, VINUM_REMOVE, VINUM_RESETSTATS, VINUM_ATTACH,  * VINUM_DETACH, VINUM_REPLACE  */
end_comment

begin_struct
struct|struct
name|vinum_ioctl_msg
block|{
name|int
name|index
decl_stmt|;
name|enum
name|objecttype
name|type
decl_stmt|;
name|enum
name|objectstate
name|state
decl_stmt|;
comment|/* state to set (VINUM_SETSTATE) */
name|enum
name|parityop
name|op
decl_stmt|;
comment|/* for parity ops */
name|int
name|force
decl_stmt|;
comment|/* do it even if it doesn't make sense */
name|int
name|recurse
decl_stmt|;
comment|/* recurse (VINUM_REMOVE) */
name|int
name|verify
decl_stmt|;
comment|/* verify (initsd, rebuildparity) */
name|int
name|otherobject
decl_stmt|;
comment|/* superordinate object (attach), 							    * replacement object (replace) */
name|int
name|rename
decl_stmt|;
comment|/* rename object (attach) */
name|int64_t
name|offset
decl_stmt|;
comment|/* offset of subdisk (for attach) */
name|int
name|blocksize
decl_stmt|;
comment|/* size of block to revive (bytes) */
block|}
struct|;
end_struct

begin_comment
comment|/* VINUM_CREATE returns a buffer of this kind */
end_comment

begin_struct
struct|struct
name|_ioctl_reply
block|{
name|int
name|error
decl_stmt|;
name|char
name|msg
index|[
name|MAX_IOCTL_REPLY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vinum_rename_msg
block|{
name|int
name|index
decl_stmt|;
name|int
name|recurse
decl_stmt|;
comment|/* rename subordinate objects too */
name|enum
name|objecttype
name|type
decl_stmt|;
name|char
name|newname
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* new name to give to object */
block|}
struct|;
end_struct

begin_comment
comment|/* ioctl requests */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|1024
end_define

begin_comment
comment|/* size of buffer, including continuations */
end_comment

begin_define
define|#
directive|define
name|VINUM_CREATE
value|_IOC(IOC_IN | IOC_OUT, L, 64, BUFSIZE)
end_define

begin_comment
comment|/* configure vinum */
end_comment

begin_define
define|#
directive|define
name|VINUM_GETCONFIG
value|_IOR(L, 65, struct _vinum_conf)
end_define

begin_comment
comment|/* get global config */
end_comment

begin_define
define|#
directive|define
name|VINUM_DRIVECONFIG
value|_IOWR(L, 66, struct drive)
end_define

begin_comment
comment|/* get drive config */
end_comment

begin_define
define|#
directive|define
name|VINUM_SDCONFIG
value|_IOWR(L, 67, struct sd)
end_define

begin_comment
comment|/* get subdisk config */
end_comment

begin_define
define|#
directive|define
name|VINUM_PLEXCONFIG
value|_IOWR(L, 68, struct plex)
end_define

begin_comment
comment|/* get plex config */
end_comment

begin_define
define|#
directive|define
name|VINUM_VOLCONFIG
value|_IOWR(L, 69, struct volume)
end_define

begin_comment
comment|/* get volume config */
end_comment

begin_define
define|#
directive|define
name|VINUM_PLEXSDCONFIG
value|_IOWR(L, 70, struct sd)
end_define

begin_comment
comment|/* get sd config for plex (plex, sdno) */
end_comment

begin_define
define|#
directive|define
name|VINUM_GETFREELIST
value|_IOWR(L, 71, struct drive_freelist)
end_define

begin_comment
comment|/* get freelist element (drive, fe) */
end_comment

begin_define
define|#
directive|define
name|VINUM_SAVECONFIG
value|_IOW(L, 72, int)
end_define

begin_comment
comment|/* write config to disk */
end_comment

begin_define
define|#
directive|define
name|VINUM_RESETCONFIG
value|_IOC(0, L, 73, 0)
end_define

begin_comment
comment|/* trash config on disk */
end_comment

begin_define
define|#
directive|define
name|VINUM_INIT
value|_IOC(0, L, 74, 0)
end_define

begin_comment
comment|/* read config from disk */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_define
define|#
directive|define
name|VINUM_DEBUG
value|_IOWR(L, 75, struct debuginfo)
end_define

begin_comment
comment|/* call the debugger from ioctl () */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Start an object.  Pass two integers:  * msg [0] index in vinum_conf.<object>  * msg [1] type of object (see below)  *  * Return ioctl_reply  */
end_comment

begin_define
define|#
directive|define
name|VINUM_SETSTATE
value|_IOC(IOC_IN | IOC_OUT, L, 76, MAX_IOCTL_REPLY)
end_define

begin_comment
comment|/* start an object */
end_comment

begin_define
define|#
directive|define
name|VINUM_RELEASECONFIG
value|_IOC(0, L, 77, 0)
end_define

begin_comment
comment|/* release locks and write config to disk */
end_comment

begin_define
define|#
directive|define
name|VINUM_STARTCONFIG
value|_IOW(L, 78, int)
end_define

begin_comment
comment|/* start a configuration operation */
end_comment

begin_define
define|#
directive|define
name|VINUM_MEMINFO
value|_IOR(L, 79, struct meminfo)
end_define

begin_comment
comment|/* get memory usage summary */
end_comment

begin_define
define|#
directive|define
name|VINUM_MALLOCINFO
value|_IOWR(L, 80, struct mc)
end_define

begin_comment
comment|/* get specific malloc information [i] */
end_comment

begin_define
define|#
directive|define
name|VINUM_LABEL
value|_IOC(IOC_IN | IOC_OUT, L, 81, MAX_IOCTL_REPLY)
end_define

begin_comment
comment|/* label a volume */
end_comment

begin_define
define|#
directive|define
name|VINUM_INITSD
value|_IOW(L, 82, int)
end_define

begin_comment
comment|/* initialize a subdisk */
end_comment

begin_define
define|#
directive|define
name|VINUM_REMOVE
value|_IOWR(L, 83, struct _ioctl_reply)
end_define

begin_comment
comment|/* remove an object */
end_comment

begin_define
define|#
directive|define
name|VINUM_READPOL
value|_IOWR(L, 84, struct _ioctl_reply)
end_define

begin_comment
comment|/* set read policy */
end_comment

begin_define
define|#
directive|define
name|VINUM_SETSTATE_FORCE
value|_IOC(IOC_IN | IOC_OUT, L, 85, MAX_IOCTL_REPLY)
end_define

begin_comment
comment|/* diddle object state */
end_comment

begin_define
define|#
directive|define
name|VINUM_RESETSTATS
value|_IOWR(L, 86, struct _ioctl_reply)
end_define

begin_comment
comment|/* reset object stats */
end_comment

begin_define
define|#
directive|define
name|VINUM_ATTACH
value|_IOWR(L, 87, struct _ioctl_reply)
end_define

begin_comment
comment|/* attach an object */
end_comment

begin_define
define|#
directive|define
name|VINUM_DETACH
value|_IOWR(L, 88, struct _ioctl_reply)
end_define

begin_comment
comment|/* remove an object */
end_comment

begin_define
define|#
directive|define
name|VINUM_RENAME
value|_IOWR(L, 89, struct _ioctl_reply)
end_define

begin_comment
comment|/* rename an object */
end_comment

begin_define
define|#
directive|define
name|VINUM_REPLACE
value|_IOWR(L, 90, struct _ioctl_reply)
end_define

begin_comment
comment|/* replace an object */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_define
define|#
directive|define
name|VINUM_RQINFO
value|_IOWR(L, 91, struct rqinfo)
end_define

begin_comment
comment|/* get request info [i] from trace buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VINUM_DAEMON
value|_IOC(0, L, 92, 0)
end_define

begin_comment
comment|/* perform the kernel part of Vinum daemon */
end_comment

begin_define
define|#
directive|define
name|VINUM_FINDDAEMON
value|_IOC(0, L, 93, 0)
end_define

begin_comment
comment|/* check for presence of Vinum daemon */
end_comment

begin_define
define|#
directive|define
name|VINUM_SETDAEMON
value|_IOW(L, 94, int)
end_define

begin_comment
comment|/* set daemon flags */
end_comment

begin_define
define|#
directive|define
name|VINUM_GETDAEMON
value|_IOR(L, 95, int)
end_define

begin_comment
comment|/* get daemon flags */
end_comment

begin_define
define|#
directive|define
name|VINUM_PARITYOP
value|_IOWR(L, 96, struct _ioctl_reply)
end_define

begin_comment
comment|/* check/rebuild RAID-4/5 parity */
end_comment

begin_define
define|#
directive|define
name|VINUM_MOVE
value|_IOWR(L, 98, struct _ioctl_reply)
end_define

begin_comment
comment|/* move an object */
end_comment

end_unit

