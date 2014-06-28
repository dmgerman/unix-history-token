begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Alexander Motin<mav@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_RAID_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_RAID_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|G_RAID_CLASS_NAME
value|"RAID"
end_define

begin_define
define|#
directive|define
name|G_RAID_MAGIC
value|"GEOM::RAID"
end_define

begin_define
define|#
directive|define
name|G_RAID_VERSION
value|0
end_define

begin_struct_decl
struct_decl|struct
name|g_raid_md_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|g_raid_tr_object
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|G_RAID_DEVICE_FLAG_NOAUTOSYNC
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|G_RAID_DEVICE_FLAG_NOFAILSYNC
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|G_RAID_DEVICE_FLAG_MASK
value|(G_RAID_DEVICE_FLAG_NOAUTOSYNC | \ 					 G_RAID_DEVICE_FLAG_NOFAILSYNC)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|u_int
name|g_raid_aggressive_spare
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|g_raid_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_raid_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_raid_read_err_thresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|g_raid_start_timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_class
name|g_raid_class
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|G_RAID_DEBUG
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (g_raid_debug>= (lvl)) {					\ 		if (g_raid_debug> 0) {					\ 			printf("GEOM_RAID[%u]: " fmt "\n",		\ 			    lvl, ## __VA_ARGS__);			\ 		} else {						\ 			printf("GEOM_RAID: " fmt "\n",			\ 			    ## __VA_ARGS__);				\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_RAID_DEBUG1
parameter_list|(
name|lvl
parameter_list|,
name|sc
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (g_raid_debug>= (lvl)) {					\ 		if (g_raid_debug> 0) {					\ 			printf("GEOM_RAID[%u]: %s: " fmt "\n",		\ 			    lvl, (sc)->sc_name, ## __VA_ARGS__);	\ 		} else {						\ 			printf("GEOM_RAID: %s: " fmt "\n",		\ 			    (sc)->sc_name, ## __VA_ARGS__);		\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_RAID_LOGREQ
parameter_list|(
name|lvl
parameter_list|,
name|bp
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (g_raid_debug>= (lvl)) {					\ 		if (g_raid_debug> 0) {					\ 			printf("GEOM_RAID[%u]: " fmt " ",		\ 			    lvl, ## __VA_ARGS__);			\ 		} else							\ 			printf("GEOM_RAID: " fmt " ", ## __VA_ARGS__);	\ 		g_print_bio(bp);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * Flags we use to distinguish I/O initiated by the TR layer to maintain  * the volume's characteristics, fix subdisks, extra copies of data, etc.  *  * G_RAID_BIO_FLAG_SYNC		I/O to update an extra copy of the data  *				for RAID volumes that maintain extra data  *				and need to rebuild that data.  * G_RAID_BIO_FLAG_REMAP	I/O done to try to provoke a subdisk into  *				doing some desirable action such as bad  *				block remapping after we detect a bad part  *				of the disk.  * G_RAID_BIO_FLAG_LOCKED	I/O holds range lock that should re released.  *  * and the following meta item:  * G_RAID_BIO_FLAG_SPECIAL	And of the I/O flags that need to make it  *				through the range locking which would  *				otherwise defer the I/O until after that  *				range is unlocked.  */
end_comment

begin_define
define|#
directive|define
name|G_RAID_BIO_FLAG_SYNC
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_BIO_FLAG_REMAP
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_BIO_FLAG_SPECIAL
define|\
value|(G_RAID_BIO_FLAG_SYNC|G_RAID_BIO_FLAG_REMAP)
end_define

begin_define
define|#
directive|define
name|G_RAID_BIO_FLAG_LOCKED
value|0x80
end_define

begin_struct
struct|struct
name|g_raid_lock
block|{
name|off_t
name|l_offset
decl_stmt|;
name|off_t
name|l_length
decl_stmt|;
name|void
modifier|*
name|l_callback_arg
decl_stmt|;
name|int
name|l_pending
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|g_raid_lock
argument_list|)
name|l_next
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_RAID_EVENT_WAIT
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_EVENT_VOLUME
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_EVENT_SUBDISK
value|0x04
end_define

begin_define
define|#
directive|define
name|G_RAID_EVENT_DISK
value|0x08
end_define

begin_define
define|#
directive|define
name|G_RAID_EVENT_DONE
value|0x10
end_define

begin_struct
struct|struct
name|g_raid_event
block|{
name|void
modifier|*
name|e_tgt
decl_stmt|;
name|int
name|e_event
decl_stmt|;
name|int
name|e_flags
decl_stmt|;
name|int
name|e_error
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|g_raid_event
argument_list|)
name|e_next
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_RAID_DISK_S_NONE
value|0x00
end_define

begin_comment
comment|/* State is unknown. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_OFFLINE
value|0x01
end_define

begin_comment
comment|/* Missing disk placeholder. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_DISABLED
value|0x02
end_define

begin_comment
comment|/* Disabled. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_FAILED
value|0x03
end_define

begin_comment
comment|/* Failed. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_STALE_FAILED
value|0x04
end_define

begin_comment
comment|/* Old failed. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_SPARE
value|0x05
end_define

begin_comment
comment|/* Hot-spare. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_STALE
value|0x06
end_define

begin_comment
comment|/* Old disk, unused now. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_S_ACTIVE
value|0x07
end_define

begin_comment
comment|/* Operational. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_DISK_E_DISCONNECTED
value|0x01
end_define

begin_struct
struct|struct
name|g_raid_disk
block|{
name|struct
name|g_raid_softc
modifier|*
name|d_softc
decl_stmt|;
comment|/* Back-pointer to softc. */
name|struct
name|g_consumer
modifier|*
name|d_consumer
decl_stmt|;
comment|/* GEOM disk consumer. */
name|void
modifier|*
name|d_md_data
decl_stmt|;
comment|/* Disk's metadata storage. */
name|struct
name|g_kerneldump
name|d_kd
decl_stmt|;
comment|/* Kernel dumping method/args. */
name|int
name|d_candelete
decl_stmt|;
comment|/* BIO_DELETE supported. */
name|uint64_t
name|d_flags
decl_stmt|;
comment|/* Additional flags. */
name|u_int
name|d_state
decl_stmt|;
comment|/* Disk state. */
name|u_int
name|d_load
decl_stmt|;
comment|/* Disk average load. */
name|off_t
name|d_last_offset
decl_stmt|;
comment|/* Last head offset. */
name|int
name|d_read_errs
decl_stmt|;
comment|/* Count of the read errors */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|g_raid_subdisk
argument_list|)
name|d_subdisks
expr_stmt|;
comment|/* List of subdisks. */
name|TAILQ_ENTRY
argument_list|(
argument|g_raid_disk
argument_list|)
name|d_next
expr_stmt|;
comment|/* Next disk in the node. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_NONE
value|0x00
end_define

begin_comment
comment|/* Absent. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_FAILED
value|0x01
end_define

begin_comment
comment|/* Failed. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_NEW
value|0x02
end_define

begin_comment
comment|/* Blank. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_REBUILD
value|0x03
end_define

begin_comment
comment|/* Blank + rebuild. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_UNINITIALIZED
value|0x04
end_define

begin_comment
comment|/* Disk of the new volume. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_STALE
value|0x05
end_define

begin_comment
comment|/* Dirty. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_RESYNC
value|0x06
end_define

begin_comment
comment|/* Dirty + check/repair. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_S_ACTIVE
value|0x07
end_define

begin_comment
comment|/* Usable. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_E_NEW
value|0x01
end_define

begin_comment
comment|/* A new subdisk has arrived */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_E_FAILED
value|0x02
end_define

begin_comment
comment|/* A subdisk failed, but remains in volume */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_E_DISCONNECTED
value|0x03
end_define

begin_comment
comment|/* A subdisk removed from volume. */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_E_FIRST_TR_PRIVATE
value|0x80
end_define

begin_comment
comment|/* translation private events */
end_comment

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_POS
parameter_list|(
name|sd
parameter_list|)
define|\
value|((sd)->sd_disk ? ((sd)->sd_disk->d_last_offset - (sd)->sd_offset) : 0)
end_define

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_TRACK_SIZE
value|(1 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_LOAD
parameter_list|(
name|sd
parameter_list|)
define|\
value|((sd)->sd_disk ? ((sd)->sd_disk->d_load) : 0)
end_define

begin_define
define|#
directive|define
name|G_RAID_SUBDISK_LOAD_SCALE
value|256
end_define

begin_struct
struct|struct
name|g_raid_subdisk
block|{
name|struct
name|g_raid_softc
modifier|*
name|sd_softc
decl_stmt|;
comment|/* Back-pointer to softc. */
name|struct
name|g_raid_disk
modifier|*
name|sd_disk
decl_stmt|;
comment|/* Where this subdisk lives. */
name|struct
name|g_raid_volume
modifier|*
name|sd_volume
decl_stmt|;
comment|/* Volume, sd is a part of. */
name|off_t
name|sd_offset
decl_stmt|;
comment|/* Offset on the disk. */
name|off_t
name|sd_size
decl_stmt|;
comment|/* Size on the disk. */
name|u_int
name|sd_pos
decl_stmt|;
comment|/* Position in volume. */
name|u_int
name|sd_state
decl_stmt|;
comment|/* Subdisk state. */
name|off_t
name|sd_rebuild_pos
decl_stmt|;
comment|/* Rebuild position. */
name|int
name|sd_recovery
decl_stmt|;
comment|/* Count of recovery reqs. */
name|TAILQ_ENTRY
argument_list|(
argument|g_raid_subdisk
argument_list|)
name|sd_next
expr_stmt|;
comment|/* Next subdisk on disk. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_RAID_MAX_SUBDISKS
value|16
end_define

begin_define
define|#
directive|define
name|G_RAID_MAX_VOLUMENAME
value|32
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_STARTING
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_BROKEN
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_DEGRADED
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_SUBOPTIMAL
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_OPTIMAL
value|0x04
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_UNSUPPORTED
value|0x05
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_STOPPED
value|0x06
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_S_ALIVE
parameter_list|(
name|s
parameter_list|)
define|\
value|((s) == G_RAID_VOLUME_S_DEGRADED ||			\      (s) == G_RAID_VOLUME_S_SUBOPTIMAL ||		\      (s) == G_RAID_VOLUME_S_OPTIMAL)
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_E_DOWN
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_E_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_E_START
value|0x10
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_E_STARTMD
value|0x11
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID0
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID1
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID3
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID4
value|0x04
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID5
value|0x05
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID6
value|0x06
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAIDMDF
value|0x07
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID1E
value|0x11
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_SINGLE
value|0x0f
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_CONCAT
value|0x1f
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID5E
value|0x15
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID5EE
value|0x25
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_RAID5R
value|0x35
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RL_UNKNOWN
value|0xff
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R1SM
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R1MM
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R3P0
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R3PN
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R4P0
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R4PN
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5LA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5LS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R6RA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R6RS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R6LA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R6LS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_RMDFRA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_RMDFRS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_RMDFLA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_RMDFLS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R1EA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R1EO
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5ERA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5ERS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5ELA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5ELS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5EERA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5EERS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5EELA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5EELS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RRA
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RRS
value|0x01
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RLA
value|0x02
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_R5RLS
value|0x03
end_define

begin_define
define|#
directive|define
name|G_RAID_VOLUME_RLQ_UNKNOWN
value|0xff
end_define

begin_struct_decl
struct_decl|struct
name|g_raid_volume
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|g_raid_volume
block|{
name|struct
name|g_raid_softc
modifier|*
name|v_softc
decl_stmt|;
comment|/* Back-pointer to softc. */
name|struct
name|g_provider
modifier|*
name|v_provider
decl_stmt|;
comment|/* GEOM provider. */
name|struct
name|g_raid_subdisk
name|v_subdisks
index|[
name|G_RAID_MAX_SUBDISKS
index|]
decl_stmt|;
comment|/* Subdisks of this volume. */
name|void
modifier|*
name|v_md_data
decl_stmt|;
comment|/* Volume's metadata storage. */
name|struct
name|g_raid_tr_object
modifier|*
name|v_tr
decl_stmt|;
comment|/* Transformation object. */
name|char
name|v_name
index|[
name|G_RAID_MAX_VOLUMENAME
index|]
decl_stmt|;
comment|/* Volume name. */
name|u_int
name|v_state
decl_stmt|;
comment|/* Volume state. */
name|u_int
name|v_raid_level
decl_stmt|;
comment|/* Array RAID level. */
name|u_int
name|v_raid_level_qualifier
decl_stmt|;
comment|/* RAID level det. */
name|u_int
name|v_disks_count
decl_stmt|;
comment|/* Number of disks in array. */
name|u_int
name|v_mdf_pdisks
decl_stmt|;
comment|/* Number of parity disks 						   in RAIDMDF array. */
name|uint16_t
name|v_mdf_polynomial
decl_stmt|;
comment|/* Polynomial for RAIDMDF. */
name|uint8_t
name|v_mdf_method
decl_stmt|;
comment|/* Generation method for RAIDMDF. */
name|u_int
name|v_strip_size
decl_stmt|;
comment|/* Array strip size. */
name|u_int
name|v_rotate_parity
decl_stmt|;
comment|/* Rotate RAID5R parity 						   after numer of stripes. */
name|u_int
name|v_sectorsize
decl_stmt|;
comment|/* Volume sector size. */
name|off_t
name|v_mediasize
decl_stmt|;
comment|/* Volume media size.  */
name|struct
name|bio_queue_head
name|v_inflight
decl_stmt|;
comment|/* In-flight write requests. */
name|struct
name|bio_queue_head
name|v_locked
decl_stmt|;
comment|/* Blocked I/O requests. */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|g_raid_lock
argument_list|)
name|v_locks
expr_stmt|;
comment|/* List of locked regions. */
name|int
name|v_pending_lock
decl_stmt|;
comment|/* writes to locked region */
name|int
name|v_dirty
decl_stmt|;
comment|/* Volume is DIRTY. */
name|struct
name|timeval
name|v_last_done
decl_stmt|;
comment|/* Time of the last I/O. */
name|time_t
name|v_last_write
decl_stmt|;
comment|/* Time of the last write. */
name|u_int
name|v_writes
decl_stmt|;
comment|/* Number of active writes. */
name|struct
name|root_hold_token
modifier|*
name|v_rootmount
decl_stmt|;
comment|/* Root mount delay token. */
name|int
name|v_starting
decl_stmt|;
comment|/* Volume is starting */
name|int
name|v_stopping
decl_stmt|;
comment|/* Volume is stopping */
name|int
name|v_provider_open
decl_stmt|;
comment|/* Number of opens. */
name|int
name|v_global_id
decl_stmt|;
comment|/* Global volume ID (rX). */
name|int
name|v_read_only
decl_stmt|;
comment|/* Volume is read-only. */
name|TAILQ_ENTRY
argument_list|(
argument|g_raid_volume
argument_list|)
name|v_next
expr_stmt|;
comment|/* List of volumes entry. */
name|LIST_ENTRY
argument_list|(
argument|g_raid_volume
argument_list|)
name|v_global_next
expr_stmt|;
comment|/* Global list entry. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_RAID_NODE_E_WAKE
value|0x00
end_define

begin_define
define|#
directive|define
name|G_RAID_NODE_E_START
value|0x01
end_define

begin_struct
struct|struct
name|g_raid_softc
block|{
name|struct
name|g_raid_md_object
modifier|*
name|sc_md
decl_stmt|;
comment|/* Metadata object. */
name|struct
name|g_geom
modifier|*
name|sc_geom
decl_stmt|;
comment|/* GEOM class instance. */
name|uint64_t
name|sc_flags
decl_stmt|;
comment|/* Additional flags. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|g_raid_volume
argument_list|)
name|sc_volumes
expr_stmt|;
comment|/* List of volumes. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|g_raid_disk
argument_list|)
name|sc_disks
expr_stmt|;
comment|/* List of disks. */
name|struct
name|sx
name|sc_lock
decl_stmt|;
comment|/* Main node lock. */
name|struct
name|proc
modifier|*
name|sc_worker
decl_stmt|;
comment|/* Worker process. */
name|struct
name|mtx
name|sc_queue_mtx
decl_stmt|;
comment|/* Worker queues lock. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|g_raid_event
argument_list|)
name|sc_events
expr_stmt|;
comment|/* Worker events queue. */
name|struct
name|bio_queue_head
name|sc_queue
decl_stmt|;
comment|/* Worker I/O queue. */
name|int
name|sc_stopping
decl_stmt|;
comment|/* Node is stopping */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_name
value|sc_geom->name
end_define

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_geom_raid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * KOBJ parent class of metadata processing modules.  */
end_comment

begin_struct
struct|struct
name|g_raid_md_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|int
name|mdc_enable
decl_stmt|;
name|int
name|mdc_priority
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|g_raid_md_class
argument_list|)
name|mdc_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KOBJ instance of metadata processing module.  */
end_comment

begin_struct
struct|struct
name|g_raid_md_object
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|struct
name|g_raid_md_class
modifier|*
name|mdo_class
decl_stmt|;
name|struct
name|g_raid_softc
modifier|*
name|mdo_softc
decl_stmt|;
comment|/* Back-pointer to softc. */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|g_raid_md_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|G_RAID_MD_DECLARE
parameter_list|(
name|name
parameter_list|,
name|label
parameter_list|)
define|\
value|static moduledata_t g_raid_md_##name##_mod = {		\ 	"g_raid_md_" __XSTRING(name),				\ 	g_raid_md_modevent,					\&g_raid_md_##name##_class				\     };								\     DECLARE_MODULE(g_raid_md_##name, g_raid_md_##name##_mod,	\ 	SI_SUB_DRIVERS, SI_ORDER_SECOND);			\     MODULE_DEPEND(g_raid_md_##name, geom_raid, 0, 0, 0);	\     SYSCTL_NODE(_kern_geom_raid, OID_AUTO, name, CTLFLAG_RD,	\ 	NULL, label " metadata module");			\     SYSCTL_INT(_kern_geom_raid_##name, OID_AUTO, enable,	\ 	CTLFLAG_RWTUN,&g_raid_md_##name##_class.mdc_enable, 0,	\ 	"Enable " label " metadata format taste")
end_define

begin_comment
comment|/*  * KOBJ parent class of data transformation modules.  */
end_comment

begin_struct
struct|struct
name|g_raid_tr_class
block|{
name|KOBJ_CLASS_FIELDS
expr_stmt|;
name|int
name|trc_enable
decl_stmt|;
name|int
name|trc_priority
decl_stmt|;
name|int
name|trc_accept_unmapped
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|g_raid_tr_class
argument_list|)
name|trc_list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KOBJ instance of data transformation module.  */
end_comment

begin_struct
struct|struct
name|g_raid_tr_object
block|{
name|KOBJ_FIELDS
expr_stmt|;
name|struct
name|g_raid_tr_class
modifier|*
name|tro_class
decl_stmt|;
name|struct
name|g_raid_volume
modifier|*
name|tro_volume
decl_stmt|;
comment|/* Back-pointer to volume. */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|g_raid_tr_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|G_RAID_TR_DECLARE
parameter_list|(
name|name
parameter_list|,
name|label
parameter_list|)
define|\
value|static moduledata_t g_raid_tr_##name##_mod = {		\ 	"g_raid_tr_" __XSTRING(name),				\ 	g_raid_tr_modevent,					\&g_raid_tr_##name##_class				\     };								\     DECLARE_MODULE(g_raid_tr_##name, g_raid_tr_##name##_mod,	\ 	SI_SUB_DRIVERS, SI_ORDER_FIRST);			\     MODULE_DEPEND(g_raid_tr_##name, geom_raid, 0, 0, 0);	\     SYSCTL_NODE(_kern_geom_raid, OID_AUTO, name, CTLFLAG_RD,	\ 	NULL, label " transformation module");			\     SYSCTL_INT(_kern_geom_raid_##name, OID_AUTO, enable,	\ 	CTLFLAG_RWTUN,&g_raid_tr_##name##_class.trc_enable, 0,	\ 	"Enable " label " transformation module taste")
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|g_raid_volume_level2str
parameter_list|(
name|int
name|level
parameter_list|,
name|int
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_volume_str2level
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
modifier|*
name|level
parameter_list|,
name|int
modifier|*
name|qual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|g_raid_volume_state2str
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|g_raid_subdisk_state2str
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|g_raid_disk_state2str
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_raid_softc
modifier|*
name|g_raid_create_node
parameter_list|(
name|struct
name|g_class
modifier|*
name|mp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|g_raid_md_object
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_create_node_format
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|struct
name|gctl_req
modifier|*
name|req
parameter_list|,
name|struct
name|g_geom
modifier|*
modifier|*
name|gp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_raid_volume
modifier|*
name|g_raid_create_volume
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_raid_disk
modifier|*
name|g_raid_create_disk
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|g_raid_get_diskname
parameter_list|(
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_get_disk_info
parameter_list|(
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_start_volume
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_destroy_node
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|int
name|worker
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_destroy_volume
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_destroy_disk
parameter_list|(
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_iodone
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_subdisk_iostart
parameter_list|(
name|struct
name|g_raid_subdisk
modifier|*
name|sd
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_subdisk_kerneldump
parameter_list|(
name|struct
name|g_raid_subdisk
modifier|*
name|sd
parameter_list|,
name|void
modifier|*
name|virtual
parameter_list|,
name|vm_offset_t
name|physical
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_consumer
modifier|*
name|g_raid_open_consumer
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_kill_consumer
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|g_consumer
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_report_disk_state
parameter_list|(
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_change_disk_state
parameter_list|(
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_change_subdisk_state
parameter_list|(
name|struct
name|g_raid_subdisk
modifier|*
name|sd
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_change_volume_state
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_write_metadata
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|struct
name|g_raid_subdisk
modifier|*
name|sd
parameter_list|,
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_fail_disk
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|g_raid_subdisk
modifier|*
name|sd
parameter_list|,
name|struct
name|g_raid_disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_raid_tr_flush_common
parameter_list|(
name|struct
name|g_raid_tr_object
modifier|*
name|tr
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_tr_kerneldump_common
parameter_list|(
name|struct
name|g_raid_tr_object
modifier|*
name|tr
parameter_list|,
name|void
modifier|*
name|virtual
parameter_list|,
name|vm_offset_t
name|physical
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|g_raid_ndisks
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|g_raid_nsubdisks
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|g_raid_nopens
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|g_raid_subdisk
modifier|*
name|g_raid_get_subdisk
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|G_RAID_DESTROY_SOFT
value|0
end_define

begin_define
define|#
directive|define
name|G_RAID_DESTROY_DELAYED
value|1
end_define

begin_define
define|#
directive|define
name|G_RAID_DESTROY_HARD
value|2
end_define

begin_function_decl
name|int
name|g_raid_destroy
parameter_list|(
name|struct
name|g_raid_softc
modifier|*
name|sc
parameter_list|,
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_event_send
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|event
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_lock_range
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|off_t
name|off
parameter_list|,
name|off_t
name|len
parameter_list|,
name|struct
name|bio
modifier|*
name|ignore
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g_raid_unlock_range
parameter_list|(
name|struct
name|g_raid_volume
modifier|*
name|vol
parameter_list|,
name|off_t
name|off
parameter_list|,
name|off_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|g_ctl_req_t
name|g_raid_ctl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_RAID_H_ */
end_comment

end_unit

