begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  Parts copyright (c) 1997, 1998 Cybernet Corporation, NetMAX project.  *  *  Written by Greg Lehey  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *	Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumobj.h,v 1.2 2001/05/23 23:04:18 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions of Vinum objects: drive, subdisk, plex and volume.  * This file is included both by userland programs and by kernel code.  * The userland structures are a subset of the kernel structures, and  * all userland fields are at the beginning, so that a simple copy in  * the length of the userland structure will be sufficient.  In order  * to perform this copy, vinumioctl must know both structures, so it  * includes this file again with _KERNEL reset.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Flags for all objects.  Most of them only apply  * to specific objects, but we currently have  * space for all in any 32 bit flags word.  */
end_comment

begin_enum
enum|enum
name|objflags
block|{
name|VF_LOCKED
init|=
literal|1
block|,
comment|/* somebody has locked access to this object */
name|VF_LOCKING
init|=
literal|2
block|,
comment|/* we want access to this object */
name|VF_OPEN
init|=
literal|4
block|,
comment|/* object has openers */
name|VF_WRITETHROUGH
init|=
literal|8
block|,
comment|/* volume: write through */
name|VF_INITED
init|=
literal|0x10
block|,
comment|/* unit has been initialized */
name|VF_WLABEL
init|=
literal|0x20
block|,
comment|/* label area is writable */
name|VF_LABELLING
init|=
literal|0x40
block|,
comment|/* unit is currently being labelled */
name|VF_WANTED
init|=
literal|0x80
block|,
comment|/* someone is waiting to obtain a lock */
name|VF_RAW
init|=
literal|0x100
block|,
comment|/* raw volume (no file system) */
name|VF_LOADED
init|=
literal|0x200
block|,
comment|/* module is loaded */
name|VF_CONFIGURING
init|=
literal|0x400
block|,
comment|/* somebody is changing the config */
name|VF_WILL_CONFIGURE
init|=
literal|0x800
block|,
comment|/* somebody wants to change the config */
name|VF_CONFIG_INCOMPLETE
init|=
literal|0x1000
block|,
comment|/* haven't finished changing the config */
name|VF_CONFIG_SETUPSTATE
init|=
literal|0x2000
block|,
comment|/* set a volume up if all plexes are empty */
name|VF_READING_CONFIG
init|=
literal|0x4000
block|,
comment|/* we're reading config database from disk */
name|VF_FORCECONFIG
init|=
literal|0x8000
block|,
comment|/* configure drives even with different names */
name|VF_NEWBORN
init|=
literal|0x10000
block|,
comment|/* for objects: we've just created it */
name|VF_CONFIGURED
init|=
literal|0x20000
block|,
comment|/* for drives: we read the config */
name|VF_STOPPING
init|=
literal|0x40000
block|,
comment|/* for vinum_conf: stop on last close */
name|VF_DAEMONOPEN
init|=
literal|0x80000
block|,
comment|/* the daemon has us open (only superdev) */
name|VF_CREATED
init|=
literal|0x100000
block|,
comment|/* for volumes: freshly created, more then new */
name|VF_HOTSPARE
init|=
literal|0x200000
block|,
comment|/* for drives: use as hot spare */
name|VF_RETRYERRORS
init|=
literal|0x400000
block|,
comment|/* don't down subdisks on I/O errors */
name|VF_HASDEBUG
init|=
literal|0x800000
block|,
comment|/* set if we support debug */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global configuration information for the vinum subsystem */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|struct
name|_vinum_conf
end_macro

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|__vinum_conf
endif|#
directive|endif
block|{
name|int
name|version
decl_stmt|;
comment|/* version of structures */
ifdef|#
directive|ifdef
name|_KERNEL
comment|/* Pointers to vinum structures */
name|struct
name|drive
modifier|*
name|drive
decl_stmt|;
name|struct
name|sd
modifier|*
name|sd
decl_stmt|;
name|struct
name|plex
modifier|*
name|plex
decl_stmt|;
name|struct
name|volume
modifier|*
name|volume
decl_stmt|;
else|#
directive|else
comment|/* Pointers to vinum structures */
name|struct
name|_drive
modifier|*
name|drive
decl_stmt|;
name|struct
name|_sd
modifier|*
name|sd
decl_stmt|;
name|struct
name|_plex
modifier|*
name|plex
decl_stmt|;
name|struct
name|_volume
modifier|*
name|volume
decl_stmt|;
endif|#
directive|endif
comment|/* the number allocated */
name|int
name|drives_allocated
decl_stmt|;
name|int
name|subdisks_allocated
decl_stmt|;
name|int
name|plexes_allocated
decl_stmt|;
name|int
name|volumes_allocated
decl_stmt|;
comment|/* and the number currently in use */
name|int
name|drives_used
decl_stmt|;
name|int
name|subdisks_used
decl_stmt|;
name|int
name|plexes_used
decl_stmt|;
name|int
name|volumes_used
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* see above */
define|#
directive|define
name|VINUM_MAXACTIVE
value|30000
comment|/* maximum number of active requests */
name|int
name|active
decl_stmt|;
comment|/* current number of requests outstanding */
name|int
name|maxactive
decl_stmt|;
comment|/* maximum number of requests ever outstanding */
ifdef|#
directive|ifdef
name|_KERNEL
ifdef|#
directive|ifdef
name|VINUMDEBUG
name|struct
name|request
modifier|*
name|lastrq
decl_stmt|;
name|struct
name|buf
modifier|*
name|lastbuf
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Use these defines to simplify code */
end_comment

begin_define
define|#
directive|define
name|DRIVE
value|vinum_conf.drive
end_define

begin_define
define|#
directive|define
name|SD
value|vinum_conf.sd
end_define

begin_define
define|#
directive|define
name|PLEX
value|vinum_conf.plex
end_define

begin_define
define|#
directive|define
name|VOL
value|vinum_conf.volume
end_define

begin_define
define|#
directive|define
name|VFLAGS
value|vinum_conf.flags
end_define

begin_comment
comment|/*  * A drive corresponds to a disk slice.  We use a different term to show  * the difference in usage: it doesn't have to be a slice, and could  * theoretically be a complete, unpartitioned disk  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|struct
name|drive
end_macro

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|_drive
endif|#
directive|endif
block|{
name|char
name|devicename
index|[
name|MAXDRIVENAME
index|]
decl_stmt|;
comment|/* name of the slice it's on */
name|struct
name|vinum_label
name|label
decl_stmt|;
comment|/* and the label information */
name|enum
name|drivestate
name|state
decl_stmt|;
comment|/* current state */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|subdisks_allocated
decl_stmt|;
comment|/* number of entries in sd */
name|int
name|subdisks_used
decl_stmt|;
comment|/* and the number used */
name|int
name|blocksize
decl_stmt|;
comment|/* size of fs blocks */
name|int
name|pid
decl_stmt|;
comment|/* of locker */
name|u_int64_t
name|sectors_available
decl_stmt|;
comment|/* number of sectors still available */
name|int
name|secsperblock
decl_stmt|;
name|int
name|lasterror
decl_stmt|;
comment|/* last error on drive */
name|int
name|driveno
decl_stmt|;
comment|/* index of drive in vinum_conf */
name|int
name|opencount
decl_stmt|;
comment|/* number of up subdisks */
name|u_int64_t
name|reads
decl_stmt|;
comment|/* number of reads on this drive */
name|u_int64_t
name|writes
decl_stmt|;
comment|/* number of writes on this drive */
name|u_int64_t
name|bytes_read
decl_stmt|;
comment|/* number of bytes read */
name|u_int64_t
name|bytes_written
decl_stmt|;
comment|/* number of bytes written */
define|#
directive|define
name|DRIVE_MAXACTIVE
value|30000
comment|/* maximum number of active requests */
name|int
name|active
decl_stmt|;
comment|/* current number of requests outstanding */
name|int
name|maxactive
decl_stmt|;
comment|/* maximum number of requests ever outstanding */
name|int
name|freelist_size
decl_stmt|;
comment|/* number of entries alloced in free list */
name|int
name|freelist_entries
decl_stmt|;
comment|/* number of entries used in free list */
name|struct
name|drive_freelist
modifier|*
name|freelist
decl_stmt|;
comment|/* sorted list of free space on drive */
ifdef|#
directive|ifdef
name|_KERNEL
name|u_int
name|sectorsize
decl_stmt|;
name|off_t
name|mediasize
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
comment|/* device information */
ifdef|#
directive|ifdef
name|VINUMDEBUG
name|char
name|lockfilename
index|[
literal|16
index|]
decl_stmt|;
comment|/* name of file from which we were locked */
name|int
name|lockline
decl_stmt|;
comment|/* and the line number */
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|struct
name|sd
end_macro

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|_sd
endif|#
directive|endif
block|{
name|char
name|name
index|[
name|MAXSDNAME
index|]
decl_stmt|;
comment|/* name of subdisk */
name|enum
name|sdstate
name|state
decl_stmt|;
comment|/* state */
name|int
name|flags
decl_stmt|;
name|int
name|lasterror
decl_stmt|;
comment|/* last error occurred */
comment|/* offsets in blocks */
name|int64_t
name|driveoffset
decl_stmt|;
comment|/* offset on drive */
comment|/*      * plexoffset is the offset from the beginning      * of the plex to the very first part of the      * subdisk, in sectors.  For striped, RAID-4 and      * RAID-5 plexes, only the first stripe is      * located at this offset      */
name|int64_t
name|plexoffset
decl_stmt|;
comment|/* offset in plex */
name|u_int64_t
name|sectors
decl_stmt|;
comment|/* and length in sectors */
name|int
name|plexno
decl_stmt|;
comment|/* index of plex, if it belongs */
name|int
name|driveno
decl_stmt|;
comment|/* index of the drive on which it is located */
name|int
name|sdno
decl_stmt|;
comment|/* our index in vinum_conf */
name|int
name|plexsdno
decl_stmt|;
comment|/* and our number in our plex */
comment|/* (undefined if no plex) */
name|u_int64_t
name|reads
decl_stmt|;
comment|/* number of reads on this subdisk */
name|u_int64_t
name|writes
decl_stmt|;
comment|/* number of writes on this subdisk */
name|u_int64_t
name|bytes_read
decl_stmt|;
comment|/* number of bytes read */
name|u_int64_t
name|bytes_written
decl_stmt|;
comment|/* number of bytes written */
comment|/* revive parameters */
name|u_int64_t
name|revived
decl_stmt|;
comment|/* block number of current revive request */
name|int
name|revive_blocksize
decl_stmt|;
comment|/* revive block size (bytes) */
name|int
name|revive_interval
decl_stmt|;
comment|/* and time to wait between transfers */
name|pid_t
name|reviver
decl_stmt|;
comment|/* PID of reviving process */
comment|/* init parameters */
name|u_int64_t
name|initialized
decl_stmt|;
comment|/* block number of current init request */
name|int
name|init_blocksize
decl_stmt|;
comment|/* init block size (bytes) */
name|int
name|init_interval
decl_stmt|;
comment|/* and time to wait between transfers */
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|request
modifier|*
name|waitlist
decl_stmt|;
comment|/* list of requests waiting on revive op */
name|dev_t
name|dev
decl_stmt|;
comment|/* associated device */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|struct
name|plex
end_macro

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|_plex
endif|#
directive|endif
block|{
name|enum
name|plexorg
name|organization
decl_stmt|;
comment|/* Plex organization */
name|enum
name|plexstate
name|state
decl_stmt|;
comment|/* and current state */
name|u_int64_t
name|length
decl_stmt|;
comment|/* total length of plex (sectors) */
name|int
name|flags
decl_stmt|;
name|int
name|stripesize
decl_stmt|;
comment|/* size of stripe or raid band, in sectors */
name|int
name|subdisks
decl_stmt|;
comment|/* number of associated subdisks */
name|int
name|subdisks_allocated
decl_stmt|;
comment|/* number of subdisks allocated space for */
name|int
modifier|*
name|sdnos
decl_stmt|;
comment|/* list of component subdisks */
name|int
name|plexno
decl_stmt|;
comment|/* index of plex in vinum_conf */
name|int
name|volno
decl_stmt|;
comment|/* index of volume */
name|int
name|volplexno
decl_stmt|;
comment|/* number of plex in volume */
comment|/* Statistics */
name|u_int64_t
name|reads
decl_stmt|;
comment|/* number of reads on this plex */
name|u_int64_t
name|writes
decl_stmt|;
comment|/* number of writes on this plex */
name|u_int64_t
name|bytes_read
decl_stmt|;
comment|/* number of bytes read */
name|u_int64_t
name|bytes_written
decl_stmt|;
comment|/* number of bytes written */
name|u_int64_t
name|recovered_reads
decl_stmt|;
comment|/* number of recovered read operations */
name|u_int64_t
name|degraded_writes
decl_stmt|;
comment|/* number of degraded writes */
name|u_int64_t
name|parityless_writes
decl_stmt|;
comment|/* number of parityless writes */
name|u_int64_t
name|multiblock
decl_stmt|;
comment|/* requests that needed more than one block */
name|u_int64_t
name|multistripe
decl_stmt|;
comment|/* requests that needed more than one stripe */
name|int
name|sddowncount
decl_stmt|;
comment|/* number of subdisks down */
comment|/* Lock information */
name|int
name|usedlocks
decl_stmt|;
comment|/* number currently in use */
name|int
name|lockwaits
decl_stmt|;
comment|/* and number of waits for locks */
name|off_t
name|checkblock
decl_stmt|;
comment|/* block number for parity op */
name|char
name|name
index|[
name|MAXPLEXNAME
index|]
decl_stmt|;
comment|/* name of plex */
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|rangelock
modifier|*
name|lock
decl_stmt|;
comment|/* ranges of locked addresses */
name|struct
name|mtx
name|lockmtx
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
comment|/* associated device */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_macro
unit|struct
name|volume
end_macro

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|_volume
endif|#
directive|endif
block|{
name|char
name|name
index|[
name|MAXVOLNAME
index|]
decl_stmt|;
comment|/* name of volume */
name|enum
name|volumestate
name|state
decl_stmt|;
comment|/* current state */
name|int
name|plexes
decl_stmt|;
comment|/* number of plexes */
name|int
name|preferred_plex
decl_stmt|;
comment|/* plex to read from, -1 for round-robin */
comment|/*      * index of plex used for last read, for      * round-robin.      */
name|int
name|last_plex_read
decl_stmt|;
name|int
name|volno
decl_stmt|;
comment|/* volume number */
name|int
name|flags
decl_stmt|;
comment|/* status and configuration flags */
name|int
name|openflags
decl_stmt|;
comment|/* flags supplied to last open(2) */
name|u_int64_t
name|size
decl_stmt|;
comment|/* size of volume */
name|int
name|blocksize
decl_stmt|;
comment|/* logical block size */
name|int
name|active
decl_stmt|;
comment|/* number of outstanding requests active */
name|int
name|subops
decl_stmt|;
comment|/* and the number of suboperations */
comment|/* Statistics */
name|u_int64_t
name|bytes_read
decl_stmt|;
comment|/* number of bytes read */
name|u_int64_t
name|bytes_written
decl_stmt|;
comment|/* number of bytes written */
name|u_int64_t
name|reads
decl_stmt|;
comment|/* number of reads on this volume */
name|u_int64_t
name|writes
decl_stmt|;
comment|/* number of writes on this volume */
name|u_int64_t
name|recovered_reads
decl_stmt|;
comment|/* reads recovered from another plex */
comment|/*      * Unlike subdisks in the plex, space for the      * plex pointers is static.      */
name|int
name|plex
index|[
name|MAXPLEX
index|]
decl_stmt|;
comment|/* index of plexes */
ifdef|#
directive|ifdef
name|_KERNEL
name|dev_t
name|dev
decl_stmt|;
comment|/* associated device */
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

