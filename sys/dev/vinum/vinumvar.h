begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  Parts copyright (c) 1997, 1998 Cybernet Corporation, NetMAX project.  *  *  Written by Greg Lehey  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *	Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumvar.h,v 1.27 2001/05/22 04:07:22 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<dev/vinum/vinumstate.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/*  * Some configuration maxima.  They're an enum because  * we can't define global constants.  Sorry about that.  *  * These aren't as bad as they look: most of them are soft limits.  */
end_comment

begin_define
define|#
directive|define
name|VINUMROOT
end_define

begin_enum
enum|enum
name|constants
block|{
comment|/*      * Current version of the data structures.  This      * is used to ensure synchronization between      * kernel module and userland vinum(8).      */
name|VINUMVERSION
init|=
literal|1
block|,
name|VINUM_HEADER
init|=
literal|512
block|,
comment|/* size of header on disk */
name|MAXCONFIGLINE
init|=
literal|1024
block|,
comment|/* maximum size of a single config line */
name|MINVINUMSLICE
init|=
literal|1048576
block|,
comment|/* minimum size of a slice */
name|VINUM_CDEV_MAJOR
init|=
literal|91
block|,
comment|/* major number for character device */
name|ROUND_ROBIN_READPOL
init|=
operator|-
literal|1
block|,
comment|/* round robin read policy */
comment|/* type field in minor number */
name|VINUM_VOLUME_TYPE
init|=
literal|0
block|,
name|VINUM_PLEX_TYPE
init|=
literal|1
block|,
name|VINUM_SD_TYPE
init|=
literal|2
block|,
name|VINUM_DRIVE_TYPE
init|=
literal|3
block|,
name|VINUM_SUPERDEV_TYPE
init|=
literal|4
block|,
comment|/* super device. */
name|VINUM_RAWPLEX_TYPE
init|=
literal|5
block|,
comment|/* anonymous plex */
name|VINUM_RAWSD_TYPE
init|=
literal|6
block|,
comment|/* anonymous subdisk */
comment|/* Shifts for the individual fields in the device */
name|VINUM_TYPE_SHIFT
init|=
literal|28
block|,
name|VINUM_VOL_SHIFT
init|=
literal|0
block|,
name|VINUM_PLEX_SHIFT
init|=
literal|16
block|,
name|VINUM_SD_SHIFT
init|=
literal|20
block|,
name|VINUM_VOL_WIDTH
init|=
literal|8
block|,
name|VINUM_PLEX_WIDTH
init|=
literal|3
block|,
name|VINUM_SD_WIDTH
init|=
literal|8
block|,
comment|/*    * Shifts for the second half of raw plex and    * subdisk numbers  */
name|VINUM_RAWPLEX_SHIFT
init|=
literal|8
block|,
comment|/* shift the second half this much */
name|VINUM_RAWPLEX_WIDTH
init|=
literal|12
block|,
comment|/* width of second half */
name|MAJORDEV_SHIFT
init|=
literal|8
block|,
name|MAXPLEX
init|=
literal|8
block|,
comment|/* maximum number of plexes in a volume */
name|MAXSD
init|=
literal|256
block|,
comment|/* maximum number of subdisks in a plex */
name|MAXDRIVENAME
init|=
literal|32
block|,
comment|/* maximum length of a device name */
name|MAXSDNAME
init|=
literal|64
block|,
comment|/* maximum length of a subdisk name */
name|MAXPLEXNAME
init|=
literal|64
block|,
comment|/* maximum length of a plex name */
name|MAXVOLNAME
init|=
literal|64
block|,
comment|/* maximum length of a volume name */
name|MAXNAME
init|=
literal|64
block|,
comment|/* maximum length of any name */
comment|/*      * Define a minor device number.      * This is not used directly; instead, it's      * called by the other macros.      */
define|#
directive|define
name|VINUMMINOR
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|( (v<< VINUM_VOL_SHIFT)		\ 			      | (p<< VINUM_PLEX_SHIFT)		\ 			      | (s<< VINUM_SD_SHIFT)		\ 			      | (t<< VINUM_TYPE_SHIFT) )
comment|/* Create device minor numbers */
define|#
directive|define
name|VINUMDEV
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|s
parameter_list|,
name|t
parameter_list|)
value|makedev (VINUM_CDEV_MAJOR, VINUMMINOR (v, p, s, t))
define|#
directive|define
name|VINUM_PLEX
parameter_list|(
name|p
parameter_list|)
value|makedev (VINUM_CDEV_MAJOR,				\ 				 (VINUM_RAWPLEX_TYPE<< VINUM_TYPE_SHIFT) \ 				 | (p& 0xff)				\ 				 | ((p& ~0xff)<< 8) )
define|#
directive|define
name|VINUM_SD
parameter_list|(
name|s
parameter_list|)
value|makedev (VINUM_CDEV_MAJOR,				\ 				 (VINUM_RAWSD_TYPE<< VINUM_TYPE_SHIFT) \ 				 | (s& 0xff)				\ 				 | ((s& ~0xff)<< 8) )
comment|/* Create a bit mask for x bits */
define|#
directive|define
name|MASK
parameter_list|(
name|x
parameter_list|)
value|((1<< (x)) - 1)
comment|/* Create a raw block device minor number */
define|#
directive|define
name|VINUMRMINOR
parameter_list|(
name|d
parameter_list|,
name|t
parameter_list|)
value|( ((d& MASK (VINUM_VOL_WIDTH))<< VINUM_VOL_SHIFT)	\ 			  | ((d& ~MASK (VINUM_VOL_WIDTH))			\<< (VINUM_PLEX_SHIFT + VINUM_VOL_WIDTH))		\ 			  | (t<< VINUM_TYPE_SHIFT) )
comment|/* extract device type */
define|#
directive|define
name|DEVTYPE
parameter_list|(
name|x
parameter_list|)
value|((minor (x)>> VINUM_TYPE_SHIFT)& 7)
comment|/*      * This mess is used to catch people who compile      * a debug vinum(8) and non-debug kernel module,      * or the other way round.      */
define|#
directive|define
name|VINUM_SUPERDEV
value|VINUMMINOR (1, 0, 0, VINUM_SUPERDEV_TYPE)
comment|/* superdevice number */
define|#
directive|define
name|VINUM_DAEMON_DEV
value|VINUMMINOR (0, 0, 0, VINUM_SUPERDEV_TYPE)
comment|/* daemon superdevice number */
comment|/*  * the number of object entries to cater for initially, and also the  * value by which they are incremented.  It doesn't take long  * to extend them, so theoretically we could start with 1 of each, but  * it's untidy to allocate such small areas.  These values are  * probably too small.  */
name|INITIAL_DRIVES
init|=
literal|4
block|,
name|INITIAL_VOLUMES
init|=
literal|4
block|,
name|INITIAL_PLEXES
init|=
literal|8
block|,
name|INITIAL_SUBDISKS
init|=
literal|16
block|,
name|INITIAL_SUBDISKS_IN_PLEX
init|=
literal|4
block|,
comment|/* number of subdisks to allocate to a plex */
name|INITIAL_SUBDISKS_IN_DRIVE
init|=
literal|4
block|,
comment|/* number of subdisks to allocate to a drive */
name|INITIAL_DRIVE_FREELIST
init|=
literal|16
block|,
comment|/* number of entries in drive freelist */
name|PLEX_REGION_TABLE_SIZE
init|=
literal|8
block|,
comment|/* number of entries in plex region tables */
name|PLEX_LOCKS
init|=
literal|256
block|,
comment|/* number of locks to allocate to a plex */
name|MAX_REVIVE_BLOCKSIZE
init|=
name|MAXPHYS
block|,
comment|/* maximum revive block size */
name|DEFAULT_REVIVE_BLOCKSIZE
init|=
literal|65536
block|,
comment|/* default revive block size */
name|VINUMHOSTNAMELEN
init|=
literal|32
block|,
comment|/* host name field in label */
block|}
enum|;
end_enum

begin_comment
comment|/* device numbers */
end_comment

begin_comment
comment|/*  *  31 30   28  27                  20  19 18    16  15                 8    7                   0  * |-----------------------------------------------------------------------------------------------|  * |X |  Type  |    Subdisk number     | X| Plex   |      Major number     |  volume number        |  * |-----------------------------------------------------------------------------------------------|  *  *    0x2                 03                 1           19                      06  *  * The fields in the minor number are interpreted as follows:  *  * Volume:              Only type and volume number are relevant  * Plex in volume:      type, plex number in volume and volume number are relevant  * raw plex:            type, plex number is made of bits 27-16 and 7-0  * raw subdisk:         type, subdisk number is made of bits 27-16 and 7-0  */
end_comment

begin_comment
comment|/* This doesn't get used.  Consider removing it. */
end_comment

begin_struct
struct|struct
name|devcode
block|{
comment|/*  * CARE.  These fields assume a big-endian word.  On a  * little-endian system, they're the wrong way around  */
name|unsigned
name|volume
range|:
literal|8
decl_stmt|;
comment|/* up to 256 volumes */
name|unsigned
name|major
range|:
literal|8
decl_stmt|;
comment|/* this is where the major number fits */
name|unsigned
name|plex
range|:
literal|3
decl_stmt|;
comment|/* up to 8 plexes per volume */
name|unsigned
name|unused
range|:
literal|1
decl_stmt|;
comment|/* up for grabs */
name|unsigned
name|sd
range|:
literal|8
decl_stmt|;
comment|/* up to 256 subdisks per plex */
name|unsigned
name|type
range|:
literal|3
decl_stmt|;
comment|/* type of object */
comment|/*      * type field      VINUM_VOLUME = 0,      VINUM_PLEX = 1,      VINUM_SUBDISK = 2,      VINUM_DRIVE = 3,      VINUM_SUPERDEV = 4,      VINUM_RAWPLEX = 5,      VINUM_RAWSD = 6 */
name|unsigned
name|signbit
range|:
literal|1
decl_stmt|;
comment|/* to make 32 bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VINUM_DIR
value|"/dev/vinum"
end_define

begin_comment
comment|/*  * These definitions help catch  * userland/kernel mismatches.  */
end_comment

begin_define
define|#
directive|define
name|VINUM_SUPERDEV_NAME
value|VINUM_DIR"/control"
end_define

begin_comment
comment|/* normal super device */
end_comment

begin_define
define|#
directive|define
name|VINUM_DAEMON_DEV_NAME
value|VINUM_DIR"/controld"
end_define

begin_comment
comment|/* super device for daemon only */
end_comment

begin_comment
comment|/*  * Slice header  *  * Vinum drives start with this structure:  *  *\                                            Sector  * |--------------------------------------|  * |   PDP-11 memorial boot block         |      0  * |--------------------------------------|  * |   Disk label, maybe                  |      1  * |--------------------------------------|  * |   Slice definition  (vinum_hdr)      |      8  * |--------------------------------------|  * |                                      |  * |   Configuration info, first copy     |      9  * |                                      |  * |--------------------------------------|  * |                                      |  * |   Configuration info, second copy    |      9 + size of config  * |                                      |  * |--------------------------------------|  */
end_comment

begin_comment
comment|/* Sizes and offsets of our information */
end_comment

begin_enum
enum|enum
block|{
name|VINUM_LABEL_OFFSET
init|=
literal|4096
block|,
comment|/* offset of vinum label */
name|VINUMHEADERLEN
init|=
literal|512
block|,
comment|/* size of vinum label */
name|VINUM_CONFIG_OFFSET
init|=
literal|4608
block|,
comment|/* offset of first config copy */
name|MAXCONFIG
init|=
literal|65536
block|,
comment|/* and size of config copy */
name|DATASTART
init|=
operator|(
name|MAXCONFIG
operator|*
literal|2
operator|+
name|VINUM_CONFIG_OFFSET
operator|)
operator|/
name|DEV_BSIZE
comment|/* this is where the data starts */
block|}
enum|;
end_enum

begin_comment
comment|/*  * hostname is 256 bytes long, but we don't need to shlep  * multiple copies in vinum.  We use the host name just  * to identify this system, and 32 bytes should be ample  * for that purpose  */
end_comment

begin_struct
struct|struct
name|vinum_label
block|{
name|char
name|sysname
index|[
name|VINUMHOSTNAMELEN
index|]
decl_stmt|;
comment|/* system name at time of creation */
name|char
name|name
index|[
name|MAXDRIVENAME
index|]
decl_stmt|;
comment|/* our name of the drive */
name|struct
name|timeval
name|date_of_birth
decl_stmt|;
comment|/* the time it was created */
name|struct
name|timeval
name|last_update
decl_stmt|;
comment|/* and the time of last update */
comment|/*      * total size in bytes of the drive.  This value      * includes the headers.      */
name|off_t
name|drive_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vinum_hdr
block|{
name|uint64_t
name|magic
decl_stmt|;
comment|/* we're long on magic numbers */
define|#
directive|define
name|VINUM_MAGIC
value|22322600044678729LL
comment|/* should be this */
define|#
directive|define
name|VINUM_NOMAGIC
value|22322600044678990LL
comment|/* becomes this after obliteration */
comment|/*      * Size in bytes of each copy of the      * configuration info.  This must be a multiple      * of the sector size.      */
name|int
name|config_length
decl_stmt|;
name|struct
name|vinum_label
name|label
decl_stmt|;
comment|/* unique label */
block|}
struct|;
end_struct

begin_comment
comment|/* Information returned from read_drive_label */
end_comment

begin_enum
enum|enum
name|drive_label_info
block|{
name|DL_CANT_OPEN
block|,
comment|/* invalid partition */
name|DL_NOT_OURS
block|,
comment|/* valid partition, but no vinum label */
name|DL_DELETED_LABEL
block|,
comment|/* valid partition, deleted label found */
name|DL_WRONG_DRIVE
block|,
comment|/* drive name doesn't match */
name|DL_OURS
comment|/* valid partition and label found */
block|}
enum|;
end_enum

begin_comment
comment|/* kinds of plex organization */
end_comment

begin_enum
enum|enum
name|plexorg
block|{
name|plex_disorg
block|,
comment|/* disorganized */
name|plex_concat
block|,
comment|/* concatenated plex */
name|plex_striped
block|,
comment|/* striped plex */
name|plex_raid4
block|,
comment|/* RAID4 plex */
name|plex_raid5
comment|/* RAID5 plex */
block|}
enum|;
end_enum

begin_comment
comment|/* Recognize plex organizations */
end_comment

begin_define
define|#
directive|define
name|isstriped
parameter_list|(
name|p
parameter_list|)
value|(p->organization>= plex_striped)
end_define

begin_comment
comment|/* RAID 1, 4 or 5 */
end_comment

begin_define
define|#
directive|define
name|isparity
parameter_list|(
name|p
parameter_list|)
value|(p->organization>= plex_raid4)
end_define

begin_comment
comment|/* RAID 4 or 5 */
end_comment

begin_comment
comment|/* Address range definitions, for locking volumes */
end_comment

begin_struct
struct|struct
name|rangelock
block|{
name|daddr_t
name|stripe
decl_stmt|;
comment|/* address + 1 of the range being locked  */
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* user's buffer pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drive_freelist
block|{
comment|/* sorted list of free space on drive */
name|u_int64_t
name|offset
decl_stmt|;
comment|/* offset of entry */
name|u_int64_t
name|sectors
decl_stmt|;
comment|/* and length in sectors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Include the structure definitions shared  * between userland and kernel.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<dev/vinum/vinumobj.h>
end_include

begin_undef
undef|#
directive|undef
name|_KERNEL
end_undef

begin_include
include|#
directive|include
file|<dev/vinum/vinumobj.h>
end_include

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dev/vinum/vinumobj.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Table expansion.  Expand table, which contains oldcount  * entries of type element, by increment entries, and change  * oldcount accordingly  */
end_comment

begin_define
define|#
directive|define
name|EXPAND
parameter_list|(
name|table
parameter_list|,
name|element
parameter_list|,
name|oldcount
parameter_list|,
name|increment
parameter_list|)
define|\
value|{							    \   expand_table ((void **)&table,			    \ 		oldcount * sizeof (element),		    \ 		(oldcount + increment) * sizeof (element) ); \   oldcount += increment;				    \   }
end_define

begin_comment
comment|/* Information on vinum's memory usage */
end_comment

begin_struct
struct|struct
name|meminfo
block|{
name|int
name|mallocs
decl_stmt|;
comment|/* number of malloced blocks */
name|int
name|total_malloced
decl_stmt|;
comment|/* total amount malloced */
name|int
name|highwater
decl_stmt|;
comment|/* maximum number of mallocs */
name|struct
name|mc
modifier|*
name|malloced
decl_stmt|;
comment|/* pointer to kernel table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MCFILENAMELEN
value|16
end_define

begin_struct
struct|struct
name|mc
block|{
name|struct
name|timeval
name|time
decl_stmt|;
name|int
name|seq
decl_stmt|;
name|int
name|size
decl_stmt|;
name|short
name|line
decl_stmt|;
name|caddr_t
name|address
decl_stmt|;
name|char
name|file
index|[
name|MCFILENAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These enums are used by the state transition  * routines.  They're in bit map format:  *  * Bit 0: Other plexes in the volume are down  * Bit 1: Other plexes in the volume are up  * Bit 2: The current plex is up  * Maybe they should be local to  * state.c  */
end_comment

begin_enum
enum|enum
name|volplexstate
block|{
name|volplex_onlyusdown
init|=
literal|0
block|,
comment|/* 0: we're the only plex, and we're down */
name|volplex_alldown
block|,
comment|/* 1: another plex is down, and so are we */
name|volplex_otherup
block|,
comment|/* 2: another plex is up */
name|volplex_otherupdown
block|,
comment|/* 3: other plexes are up and down */
name|volplex_onlyus
block|,
comment|/* 4: we're up and alone */
name|volplex_onlyusup
block|,
comment|/* 5: only we are up, others are down */
name|volplex_allup
block|,
comment|/* 6: all plexes are up */
name|volplex_someup
comment|/* 7: some plexes are up, including us */
block|}
enum|;
end_enum

begin_comment
comment|/* state map for plex */
end_comment

begin_enum
enum|enum
name|sdstates
block|{
name|sd_emptystate
init|=
literal|1
block|,
name|sd_downstate
init|=
literal|2
block|,
comment|/* SD is down */
name|sd_crashedstate
init|=
literal|4
block|,
comment|/* SD is crashed */
name|sd_obsoletestate
init|=
literal|8
block|,
comment|/* SD is obsolete */
name|sd_stalestate
init|=
literal|16
block|,
comment|/* SD is stale */
name|sd_rebornstate
init|=
literal|32
block|,
comment|/* SD is reborn */
name|sd_upstate
init|=
literal|64
block|,
comment|/* SD is up */
name|sd_initstate
init|=
literal|128
block|,
comment|/* SD is initializing */
name|sd_initializedstate
init|=
literal|256
block|,
comment|/* SD is initialized */
name|sd_otherstate
init|=
literal|512
block|,
comment|/* SD is in some other state */
block|}
enum|;
end_enum

begin_comment
comment|/*  * This is really just a parameter to pass to  * set_<foo>_state, but since it needs to be known  * in the external definitions, we need to define  * it here  */
end_comment

begin_enum
enum|enum
name|setstateflags
block|{
name|setstate_none
init|=
literal|0
block|,
comment|/* no flags */
name|setstate_force
init|=
literal|1
block|,
comment|/* force the state change */
name|setstate_configuring
init|=
literal|2
block|,
comment|/* we're currently configuring, don't save */
block|}
enum|;
end_enum

begin_comment
comment|/* Operations for parityops to perform. */
end_comment

begin_enum
enum|enum
name|parityop
block|{
name|checkparity
block|,
name|rebuildparity
block|,
name|rebuildandcheckparity
block|,
comment|/* rebuildparity with the -v option */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_comment
comment|/* Debugging stuff */
end_comment

begin_enum
enum|enum
name|debugflags
block|{
name|DEBUG_ADDRESSES
init|=
literal|1
block|,
comment|/* show buffer information during requests */
name|DEBUG_NUMOUTPUT
init|=
literal|2
block|,
comment|/* show the value of vp->v_numoutput */
name|DEBUG_RESID
init|=
literal|4
block|,
comment|/* go into debugger in complete_rqe */
name|DEBUG_LASTREQS
init|=
literal|8
block|,
comment|/* keep a circular buffer of last requests */
name|DEBUG_REVIVECONFLICT
init|=
literal|16
block|,
comment|/* print info about revive conflicts */
name|DEBUG_EOFINFO
init|=
literal|32
block|,
comment|/* print info about EOF detection */
name|DEBUG_MEMFREE
init|=
literal|64
block|,
comment|/* keep info about Frees */
name|DEBUG_BIGDRIVE
init|=
literal|128
block|,
comment|/* pretend our drives are 100 times the size */
name|DEBUG_REMOTEGDB
init|=
literal|256
block|,
comment|/* go into remote gdb */
name|DEBUG_WARNINGS
init|=
literal|512
block|,
comment|/* log various relatively harmless warnings  */
name|DEBUG_LOCKREQS
init|=
literal|1024
block|,
comment|/* log locking requests  */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|longjmp
value|LongJmp
end_define

begin_comment
comment|/* test our longjmps */
end_comment

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

begin_comment
comment|/* Local Variables: */
end_comment

begin_comment
comment|/* fill-column: 50 */
end_comment

begin_comment
comment|/* End: */
end_comment

end_unit

