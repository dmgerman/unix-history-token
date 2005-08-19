begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Lukas Ertl  * Copyright (c) 1997, 1998, 1999  *      Nan Yang Computer Services Limited.  All rights reserved.  *  * Parts copyright (c) 1997, 1998 Cybernet Corporation, NetMAX project.  * Parts written by Greg Lehey.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':                                                                   *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *    * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any               * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *    * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_VINUM_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_VINUM_VAR_H_
end_define

begin_comment
comment|/*  * Slice header  *  * Vinum drives start with this structure:  *  *\                                            Sector  * |--------------------------------------|  * |   PDP-11 memorial boot block         |      0  * |--------------------------------------|  * |   Disk label, maybe                  |      1  * |--------------------------------------|  * |   Slice definition  (vinum_hdr)      |      8  * |--------------------------------------|  * |                                      |  * |   Configuration info, first copy     |      9  * |                                      |  * |--------------------------------------|  * |                                      |  * |   Configuration info, second copy    |      9 + size of config  * |                                      |  * |--------------------------------------|  */
end_comment

begin_comment
comment|/* Sizes and offsets of our information. */
end_comment

begin_define
define|#
directive|define
name|GV_HDR_OFFSET
value|4096
end_define

begin_comment
comment|/* Offset of vinum header. */
end_comment

begin_define
define|#
directive|define
name|GV_HDR_LEN
value|512
end_define

begin_comment
comment|/* Size of vinum header. */
end_comment

begin_define
define|#
directive|define
name|GV_CFG_OFFSET
value|4608
end_define

begin_comment
comment|/* Offset of first config copy. */
end_comment

begin_define
define|#
directive|define
name|GV_CFG_LEN
value|65536
end_define

begin_comment
comment|/* Size of config copy. */
end_comment

begin_comment
comment|/* This is where the actual data starts. */
end_comment

begin_define
define|#
directive|define
name|GV_DATA_START
value|(GV_CFG_LEN * 2 + GV_CFG_OFFSET)
end_define

begin_comment
comment|/* #define GV_DATA_START	(GV_CFG_LEN * 2 + GV_HDR_LEN) */
end_comment

begin_define
define|#
directive|define
name|GV_MAXDRIVENAME
value|32
end_define

begin_comment
comment|/* Maximum length of a device name. */
end_comment

begin_define
define|#
directive|define
name|GV_MAXSDNAME
value|64
end_define

begin_comment
comment|/* Maximum length of a subdisk name. */
end_comment

begin_define
define|#
directive|define
name|GV_MAXPLEXNAME
value|64
end_define

begin_comment
comment|/* Maximum length of a plex name. */
end_comment

begin_define
define|#
directive|define
name|GV_MAXVOLNAME
value|64
end_define

begin_comment
comment|/* Maximum length of a volume name. */
end_comment

begin_comment
comment|/* Command line flags. */
end_comment

begin_define
define|#
directive|define
name|GV_FLAG_R
value|0x01
end_define

begin_define
define|#
directive|define
name|GV_FLAG_S
value|0x02
end_define

begin_define
define|#
directive|define
name|GV_FLAG_V
value|0x04
end_define

begin_define
define|#
directive|define
name|GV_FLAG_VV
value|0x08
end_define

begin_define
define|#
directive|define
name|GV_FLAG_F
value|0x10
end_define

begin_comment
comment|/* Object types. */
end_comment

begin_define
define|#
directive|define
name|GV_TYPE_VOL
value|1
end_define

begin_define
define|#
directive|define
name|GV_TYPE_PLEX
value|2
end_define

begin_define
define|#
directive|define
name|GV_TYPE_SD
value|3
end_define

begin_define
define|#
directive|define
name|GV_TYPE_DRIVE
value|4
end_define

begin_comment
comment|/* State changing flags. */
end_comment

begin_define
define|#
directive|define
name|GV_SETSTATE_FORCE
value|0x1
end_define

begin_define
define|#
directive|define
name|GV_SETSTATE_CONFIG
value|0x2
end_define

begin_comment
comment|/* Subdisk state bitmaps for plexes. */
end_comment

begin_define
define|#
directive|define
name|GV_SD_DOWNSTATE
value|0x01
end_define

begin_comment
comment|/* Subdisk is down. */
end_comment

begin_define
define|#
directive|define
name|GV_SD_STALESTATE
value|0x02
end_define

begin_comment
comment|/* Subdisk is stale. */
end_comment

begin_define
define|#
directive|define
name|GV_SD_INITSTATE
value|0x04
end_define

begin_comment
comment|/* Subdisk is initializing. */
end_comment

begin_define
define|#
directive|define
name|GV_SD_UPSTATE
value|0x08
end_define

begin_comment
comment|/* Subdisk is up. */
end_comment

begin_comment
comment|/* Synchronization/initialization request sizes. */
end_comment

begin_define
define|#
directive|define
name|GV_MIN_SYNCSIZE
value|512
end_define

begin_define
define|#
directive|define
name|GV_MAX_SYNCSIZE
value|MAXPHYS
end_define

begin_define
define|#
directive|define
name|GV_DFLT_SYNCSIZE
value|65536
end_define

begin_comment
comment|/* Flags for BIOs, as they are processed within vinum. */
end_comment

begin_define
define|#
directive|define
name|GV_BIO_DONE
value|0x01
end_define

begin_define
define|#
directive|define
name|GV_BIO_MALLOC
value|0x02
end_define

begin_define
define|#
directive|define
name|GV_BIO_ONHOLD
value|0x04
end_define

begin_define
define|#
directive|define
name|GV_BIO_SYNCREQ
value|0x08
end_define

begin_define
define|#
directive|define
name|GV_BIO_SUCCEED
value|0x10
end_define

begin_define
define|#
directive|define
name|GV_BIO_REBUILD
value|0x20
end_define

begin_define
define|#
directive|define
name|GV_BIO_CHECK
value|0x40
end_define

begin_define
define|#
directive|define
name|GV_BIO_PARITY
value|0x80
end_define

begin_define
define|#
directive|define
name|GV_BIO_RETRY
value|0x100
end_define

begin_comment
comment|/*  * hostname is 256 bytes long, but we don't need to shlep multiple copies in  * vinum.  We use the host name just to identify this system, and 32 bytes  * should be ample for that purpose.  */
end_comment

begin_define
define|#
directive|define
name|GV_HOSTNAME_LEN
value|32
end_define

begin_struct
struct|struct
name|gv_label
block|{
name|char
name|sysname
index|[
name|GV_HOSTNAME_LEN
index|]
decl_stmt|;
comment|/* System name at creation time. */
name|char
name|name
index|[
name|GV_MAXDRIVENAME
index|]
decl_stmt|;
comment|/* Our name of the drive. */
name|struct
name|timeval
name|date_of_birth
decl_stmt|;
comment|/* The time it was created ... */
name|struct
name|timeval
name|last_update
decl_stmt|;
comment|/* ... and the time of last update. */
name|off_t
name|drive_size
decl_stmt|;
comment|/* Total size incl. headers. */
block|}
struct|;
end_struct

begin_comment
comment|/* The 'header' of each valid vinum drive. */
end_comment

begin_struct
struct|struct
name|gv_hdr
block|{
name|uint64_t
name|magic
decl_stmt|;
define|#
directive|define
name|GV_MAGIC
value|22322600044678729LL
define|#
directive|define
name|GV_NOMAGIC
value|22322600044678990LL
name|int
name|config_length
decl_stmt|;
name|struct
name|gv_label
name|label
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A single freelist entry of a drive. */
end_comment

begin_struct
struct|struct
name|gv_freelist
block|{
name|off_t
name|size
decl_stmt|;
comment|/* Size of this free slot. */
name|off_t
name|offset
decl_stmt|;
comment|/* Offset on the drive. */
name|LIST_ENTRY
argument_list|(
argument|gv_freelist
argument_list|)
name|freelist
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Since we share structures between userland and kernel, we need this helper  * struct instead of struct bio_queue_head and friends.  Maybe I find a proper  * solution some day.  */
end_comment

begin_struct
struct|struct
name|gv_bioq
block|{
name|struct
name|bio
modifier|*
name|bp
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|gv_bioq
argument_list|)
name|queue
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This struct contains the main vinum config. */
end_comment

begin_struct
struct|struct
name|gv_softc
block|{
comment|/*struct mtx config_mtx; XXX not yet */
comment|/* Linked lists of all objects in our setup. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_drive
argument_list|)
name|drives
expr_stmt|;
comment|/* All drives. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_plex
argument_list|)
name|plexes
expr_stmt|;
comment|/* All plexes. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_sd
argument_list|)
name|subdisks
expr_stmt|;
comment|/* All subdisks. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_volume
argument_list|)
name|volumes
expr_stmt|;
comment|/* All volumes. */
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
comment|/* Pointer to our VINUM geom. */
block|}
struct|;
end_struct

begin_comment
comment|/* softc for a drive. */
end_comment

begin_struct
struct|struct
name|gv_drive
block|{
name|char
name|name
index|[
name|GV_MAXDRIVENAME
index|]
decl_stmt|;
comment|/* The name of this drive. */
name|char
name|device
index|[
name|GV_MAXDRIVENAME
index|]
decl_stmt|;
comment|/* Associated device. */
name|int
name|state
decl_stmt|;
comment|/* The state of this drive. */
define|#
directive|define
name|GV_DRIVE_DOWN
value|0
define|#
directive|define
name|GV_DRIVE_UP
value|1
name|off_t
name|size
decl_stmt|;
comment|/* Size of this drive. */
name|off_t
name|avail
decl_stmt|;
comment|/* Available space. */
name|int
name|sdcount
decl_stmt|;
comment|/* Number of subdisks. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|GV_DRIVE_THREAD_ACTIVE
value|0x01
comment|/* Drive has an active worker thread. */
define|#
directive|define
name|GV_DRIVE_THREAD_DIE
value|0x02
comment|/* Signal the worker thread to die. */
define|#
directive|define
name|GV_DRIVE_THREAD_DEAD
value|0x04
comment|/* The worker thread has died. */
define|#
directive|define
name|GV_DRIVE_NEWBORN
value|0x08
comment|/* The drive was just created. */
name|struct
name|gv_hdr
modifier|*
name|hdr
decl_stmt|;
comment|/* The drive header. */
name|int
name|freelist_entries
decl_stmt|;
comment|/* Count of freelist entries. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_freelist
argument_list|)
name|freelist
expr_stmt|;
comment|/* List of freelist entries. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_sd
argument_list|)
name|subdisks
expr_stmt|;
comment|/* Subdisks on this drive. */
name|LIST_ENTRY
argument_list|(
argument|gv_drive
argument_list|)
name|drive
expr_stmt|;
comment|/* Entry in the vinum config. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_bioq
argument_list|)
name|bqueue
expr_stmt|;
comment|/* BIO queue of this drive. */
name|struct
name|mtx
name|bqueue_mtx
decl_stmt|;
comment|/* Mtx. to protect the queue. */
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
comment|/* The geom of this drive. */
name|struct
name|gv_softc
modifier|*
name|vinumconf
decl_stmt|;
comment|/* Pointer to the vinum conf. */
block|}
struct|;
end_struct

begin_comment
comment|/* softc for a subdisk. */
end_comment

begin_struct
struct|struct
name|gv_sd
block|{
name|char
name|name
index|[
name|GV_MAXSDNAME
index|]
decl_stmt|;
comment|/* The name of this subdisk. */
name|off_t
name|size
decl_stmt|;
comment|/* The size of this subdisk. */
name|off_t
name|drive_offset
decl_stmt|;
comment|/* Offset in the underlying drive. */
name|off_t
name|plex_offset
decl_stmt|;
comment|/* Offset in the associated plex. */
name|int
name|state
decl_stmt|;
comment|/* The state of this subdisk. */
define|#
directive|define
name|GV_SD_DOWN
value|0
define|#
directive|define
name|GV_SD_STALE
value|1
define|#
directive|define
name|GV_SD_INITIALIZING
value|2
define|#
directive|define
name|GV_SD_REVIVING
value|3
define|#
directive|define
name|GV_SD_UP
value|4
name|off_t
name|initialized
decl_stmt|;
comment|/* Count of initialized bytes. */
name|int
name|init_size
decl_stmt|;
comment|/* Initialization read/write size. */
name|int
name|init_error
decl_stmt|;
comment|/* Flag error on initialization. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|GV_SD_NEWBORN
value|0x01
comment|/* Subdisk was just created. */
define|#
directive|define
name|GV_SD_INITCANCEL
value|0x02
comment|/* Cancel initialization process. */
name|char
name|drive
index|[
name|GV_MAXDRIVENAME
index|]
decl_stmt|;
comment|/* Name of underlying drive. */
name|char
name|plex
index|[
name|GV_MAXPLEXNAME
index|]
decl_stmt|;
comment|/* Name of associated plex. */
name|struct
name|gv_drive
modifier|*
name|drive_sc
decl_stmt|;
comment|/* Pointer to underlying drive. */
name|struct
name|gv_plex
modifier|*
name|plex_sc
decl_stmt|;
comment|/* Pointer to associated plex. */
name|struct
name|g_provider
modifier|*
name|provider
decl_stmt|;
comment|/* The provider this sd represents. */
name|struct
name|g_consumer
modifier|*
name|consumer
decl_stmt|;
comment|/* Consumer attached to our provider. */
name|LIST_ENTRY
argument_list|(
argument|gv_sd
argument_list|)
name|from_drive
expr_stmt|;
comment|/* Subdisk list of underlying drive. */
name|LIST_ENTRY
argument_list|(
argument|gv_sd
argument_list|)
name|in_plex
expr_stmt|;
comment|/* Subdisk list of associated plex. */
name|LIST_ENTRY
argument_list|(
argument|gv_sd
argument_list|)
name|sd
expr_stmt|;
comment|/* Entry in the vinum config. */
name|struct
name|gv_softc
modifier|*
name|vinumconf
decl_stmt|;
comment|/* Pointer to the vinum config. */
block|}
struct|;
end_struct

begin_comment
comment|/* softc for a plex. */
end_comment

begin_struct
struct|struct
name|gv_plex
block|{
name|char
name|name
index|[
name|GV_MAXPLEXNAME
index|]
decl_stmt|;
comment|/* The name of the plex. */
name|off_t
name|size
decl_stmt|;
comment|/* The size of the plex. */
name|int
name|state
decl_stmt|;
comment|/* The plex state. */
define|#
directive|define
name|GV_PLEX_DOWN
value|0
define|#
directive|define
name|GV_PLEX_INITIALIZING
value|1
define|#
directive|define
name|GV_PLEX_DEGRADED
value|2
define|#
directive|define
name|GV_PLEX_UP
value|3
name|int
name|org
decl_stmt|;
comment|/* The plex organisation. */
define|#
directive|define
name|GV_PLEX_DISORG
value|0
define|#
directive|define
name|GV_PLEX_CONCAT
value|1
define|#
directive|define
name|GV_PLEX_STRIPED
value|2
define|#
directive|define
name|GV_PLEX_RAID5
value|4
name|int
name|stripesize
decl_stmt|;
comment|/* The stripe size of the plex. */
name|char
name|volume
index|[
name|GV_MAXVOLNAME
index|]
decl_stmt|;
comment|/* Name of associated volume. */
name|struct
name|gv_volume
modifier|*
name|vol_sc
decl_stmt|;
comment|/* Pointer to associated volume. */
name|int
name|sdcount
decl_stmt|;
comment|/* Number of subdisks in this plex. */
name|int
name|sddown
decl_stmt|;
comment|/* Number of subdisks that are down. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|GV_PLEX_ADDED
value|0x01
comment|/* Added to an existing volume. */
define|#
directive|define
name|GV_PLEX_SYNCING
value|0x02
comment|/* Plex is syncing from another plex. */
define|#
directive|define
name|GV_PLEX_THREAD_ACTIVE
value|0x04
comment|/* Plex has an active RAID5 thread. */
define|#
directive|define
name|GV_PLEX_THREAD_DIE
value|0x08
comment|/* Signal the RAID5 thread to die. */
define|#
directive|define
name|GV_PLEX_THREAD_DEAD
value|0x10
comment|/* The RAID5 thread has died. */
define|#
directive|define
name|GV_PLEX_NEWBORN
value|0x20
comment|/* The plex was just created. */
name|off_t
name|synced
decl_stmt|;
comment|/* Count of synced bytes. */
name|struct
name|mtx
name|bqueue_mtx
decl_stmt|;
comment|/* Lock for the BIO queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_bioq
argument_list|)
name|bqueue
expr_stmt|;
comment|/* BIO queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_bioq
argument_list|)
name|wqueue
expr_stmt|;
comment|/* Waiting BIO queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_raid5_packet
argument_list|)
name|packets
expr_stmt|;
comment|/* RAID5 sub-requests. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_sd
argument_list|)
name|subdisks
expr_stmt|;
comment|/* List of attached subdisks. */
name|LIST_ENTRY
argument_list|(
argument|gv_plex
argument_list|)
name|in_volume
expr_stmt|;
comment|/* Plex list of associated volume. */
name|LIST_ENTRY
argument_list|(
argument|gv_plex
argument_list|)
name|plex
expr_stmt|;
comment|/* Entry in the vinum config. */
name|struct
name|g_provider
modifier|*
name|provider
decl_stmt|;
comment|/* The provider this plex represents. */
name|struct
name|g_consumer
modifier|*
name|consumer
decl_stmt|;
comment|/* Consumer attached to our provider. */
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
comment|/* The geom of this plex. */
name|struct
name|gv_softc
modifier|*
name|vinumconf
decl_stmt|;
comment|/* Pointer to the vinum config. */
block|}
struct|;
end_struct

begin_comment
comment|/* softc for a volume. */
end_comment

begin_struct
struct|struct
name|gv_volume
block|{
name|char
name|name
index|[
name|GV_MAXVOLNAME
index|]
decl_stmt|;
comment|/* The name of the volume. */
name|off_t
name|size
decl_stmt|;
comment|/* The size of the volume. */
name|int
name|plexcount
decl_stmt|;
comment|/* Number of plexes. */
name|int
name|state
decl_stmt|;
comment|/* The state of the volume. */
define|#
directive|define
name|GV_VOL_DOWN
value|0
define|#
directive|define
name|GV_VOL_UP
value|1
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|GV_VOL_THREAD_ACTIVE
value|0x01
comment|/* Volume has an active thread. */
define|#
directive|define
name|GV_VOL_THREAD_DIE
value|0x02
comment|/* Signal the thread to die. */
define|#
directive|define
name|GV_VOL_THREAD_DEAD
value|0x04
comment|/* The thread has died. */
name|struct
name|mtx
name|bqueue_mtx
decl_stmt|;
comment|/* Lock for the BIO queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gv_bioq
argument_list|)
name|bqueue
expr_stmt|;
comment|/* BIO queue. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|gv_plex
argument_list|)
name|plexes
expr_stmt|;
comment|/* List of attached plexes. */
name|LIST_ENTRY
argument_list|(
argument|gv_volume
argument_list|)
name|volume
expr_stmt|;
comment|/* Entry in vinum config. */
name|struct
name|gv_plex
modifier|*
name|last_read_plex
decl_stmt|;
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
comment|/* The geom of this volume. */
name|struct
name|gv_softc
modifier|*
name|vinumconf
decl_stmt|;
comment|/* Pointer to the vinum config. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEOM_VINUM_VAR_H */
end_comment

end_unit

