begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004, 2010, Oracle and/or its affiliates. All rights reserved.  *  * Common routines for acquiring snapshots of kstats for  * iostat, mpstat, and vmstat.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STATCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_STATCOMMON_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<kstat.h>
include|#
directive|include
file|<sys/time.h>
include|#
directive|include
file|<sys/types.h>
include|#
directive|include
file|<sys/buf.h>
include|#
directive|include
file|<sys/dnlc.h>
include|#
directive|include
file|<sys/sysinfo.h>
include|#
directive|include
file|<sys/processor.h>
include|#
directive|include
file|<sys/pset.h>
include|#
directive|include
file|<sys/avl.h>
comment|/* No CPU present at this CPU position */
define|#
directive|define
name|ID_NO_CPU
value|-1
comment|/* CPU belongs to no pset (we number this as "pset 0")  */
define|#
directive|define
name|ID_NO_PSET
value|0
comment|/* CPU is usable */
define|#
directive|define
name|CPU_ONLINE
parameter_list|(
name|s
parameter_list|)
value|((s) == P_ONLINE || (s) == P_NOINTR)
comment|/* will the CPU have kstats */
define|#
directive|define
name|CPU_ACTIVE
parameter_list|(
name|c
parameter_list|)
value|(CPU_ONLINE((c)->cs_state)&& (c)->cs_id != ID_NO_CPU)
comment|/* IO device has no identified ID */
define|#
directive|define
name|IODEV_NO_ID
value|-1
comment|/* no limit to iodevs to collect */
define|#
directive|define
name|UNLIMITED_IODEVS
value|((size_t)-1)
define|#
directive|define
name|NODATE
value|0
comment|/* Default:  No time stamp */
define|#
directive|define
name|DDATE
value|1
comment|/* Standard date format */
define|#
directive|define
name|UDATE
value|2
comment|/* Internal representation of Unix time */
enum|enum
name|snapshot_types
block|{
comment|/* All CPUs separately */
name|SNAP_CPUS
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* Aggregated processor sets */
name|SNAP_PSETS
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* sys-wide stats including aggregated CPU stats */
name|SNAP_SYSTEM
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* interrupt sources and counts */
name|SNAP_INTERRUPTS
init|=
literal|1
operator|<<
literal|3
block|,
comment|/* disk etc. stats */
name|SNAP_IODEVS
init|=
literal|1
operator|<<
literal|4
block|,
comment|/* disk controller aggregates */
name|SNAP_CONTROLLERS
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* mpxio L I (multipath) paths: -X: Lun,LunInitiator */
name|SNAP_IOPATHS_LI
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* mpxio LTI (multipath) paths: -Y: Lun,LunTarget,LunTargetInitiator */
name|SNAP_IOPATHS_LTI
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* disk error stats */
name|SNAP_IODEV_ERRORS
init|=
literal|1
operator|<<
literal|8
block|,
comment|/* pretty names for iodevs */
name|SNAP_IODEV_PRETTY
init|=
literal|1
operator|<<
literal|9
block|,
comment|/* devid for iodevs */
name|SNAP_IODEV_DEVID
init|=
literal|1
operator|<<
literal|10
block|}
enum|;
struct|struct
name|cpu_snapshot
block|{
comment|/* may be ID_NO_CPU if no CPU present */
name|processorid_t
name|cs_id
decl_stmt|;
comment|/* may be ID_NO_PSET if no pset */
name|psetid_t
name|cs_pset_id
decl_stmt|;
comment|/* as in p_online(2) */
name|int
name|cs_state
decl_stmt|;
comment|/* stats for this CPU */
name|kstat_t
name|cs_vm
decl_stmt|;
name|kstat_t
name|cs_sys
decl_stmt|;
block|}
struct|;
struct|struct
name|pset_snapshot
block|{
comment|/* ID may be zero to indicate the "none set" */
name|psetid_t
name|ps_id
decl_stmt|;
comment|/* number of CPUs in set */
name|size_t
name|ps_nr_cpus
decl_stmt|;
comment|/* the CPUs in this set */
name|struct
name|cpu_snapshot
modifier|*
modifier|*
name|ps_cpus
decl_stmt|;
block|}
struct|;
struct|struct
name|intr_snapshot
block|{
comment|/* name of interrupt source */
name|char
name|is_name
index|[
name|KSTAT_STRLEN
index|]
decl_stmt|;
comment|/* total number of interrupts from this source */
name|ulong_t
name|is_total
decl_stmt|;
block|}
struct|;
struct|struct
name|sys_snapshot
block|{
name|sysinfo_t
name|ss_sysinfo
decl_stmt|;
name|vminfo_t
name|ss_vminfo
decl_stmt|;
name|struct
name|nc_stats
name|ss_nc
decl_stmt|;
comment|/* vm/sys stats aggregated across all CPUs */
name|kstat_t
name|ss_agg_vm
decl_stmt|;
name|kstat_t
name|ss_agg_sys
decl_stmt|;
comment|/* ticks since boot */
name|ulong_t
name|ss_ticks
decl_stmt|;
name|long
name|ss_deficit
decl_stmt|;
block|}
struct|;
comment|/* order is significant (see sort_before()) */
enum|enum
name|iodev_type
block|{
name|IODEV_CONTROLLER
init|=
literal|1
operator|<<
literal|0
block|,
name|IODEV_DISK
init|=
literal|1
operator|<<
literal|1
block|,
name|IODEV_PARTITION
init|=
literal|1
operator|<<
literal|2
block|,
name|IODEV_TAPE
init|=
literal|1
operator|<<
literal|3
block|,
name|IODEV_NFS
init|=
literal|1
operator|<<
literal|4
block|,
name|IODEV_IOPATH_LT
init|=
literal|1
operator|<<
literal|5
block|,
comment|/* synthetic LunTarget */
name|IODEV_IOPATH_LI
init|=
literal|1
operator|<<
literal|6
block|,
comment|/* synthetic LunInitiator */
name|IODEV_IOPATH_LTI
init|=
literal|1
operator|<<
literal|7
block|,
comment|/* LunTgtInitiator (pathinfo) */
name|IODEV_UNKNOWN
init|=
literal|1
operator|<<
literal|8
block|}
enum|;
comment|/* identify a disk, partition, etc. */
struct|struct
name|iodev_id
block|{
name|int
name|id
decl_stmt|;
comment|/* target id (for disks) */
name|char
name|tid
index|[
name|KSTAT_STRLEN
index|]
decl_stmt|;
block|}
struct|;
comment|/*  * Used for disks, partitions, tapes, nfs, controllers, iopaths  * Each entry can be a branch of a tree; for example, the disks  * of a controller constitute the children of the controller  * iodev_snapshot. This relationship is not strictly maintained  * if is_pretty can't be found.  */
struct|struct
name|iodev_snapshot
block|{
comment|/* original kstat name */
name|char
name|is_name
index|[
name|KSTAT_STRLEN
index|]
decl_stmt|;
comment|/* type of kstat */
name|enum
name|iodev_type
name|is_type
decl_stmt|;
comment|/* ID if meaningful */
name|struct
name|iodev_id
name|is_id
decl_stmt|;
comment|/* parent ID if meaningful */
name|struct
name|iodev_id
name|is_parent_id
decl_stmt|;
comment|/* user-friendly name if found */
name|char
modifier|*
name|is_pretty
decl_stmt|;
comment|/* device ID if applicable */
name|char
modifier|*
name|is_devid
decl_stmt|;
comment|/* mount-point if applicable */
name|char
modifier|*
name|is_dname
decl_stmt|;
comment|/* number of direct children */
name|int
name|is_nr_children
decl_stmt|;
comment|/* children of this I/O device */
name|struct
name|iodev_snapshot
modifier|*
name|is_children
decl_stmt|;
comment|/* standard I/O stats */
name|kstat_io_t
name|is_stats
decl_stmt|;
comment|/* iodev error stats */
name|kstat_t
name|is_errors
decl_stmt|;
comment|/* creation time of the stats */
name|hrtime_t
name|is_crtime
decl_stmt|;
comment|/* time at which iodev snapshot was taken */
name|hrtime_t
name|is_snaptime
decl_stmt|;
comment|/* kstat module */
name|char
name|is_module
index|[
name|KSTAT_STRLEN
index|]
decl_stmt|;
comment|/* kstat instance */
name|int
name|is_instance
decl_stmt|;
comment|/* kstat (only used temporarily) */
name|kstat_t
modifier|*
name|is_ksp
decl_stmt|;
name|struct
name|iodev_snapshot
modifier|*
name|is_prev
decl_stmt|;
name|struct
name|iodev_snapshot
modifier|*
name|is_next
decl_stmt|;
comment|/* AVL structures to speedup insertion */
name|avl_tree_t
modifier|*
name|avl_list
decl_stmt|;
comment|/* list this element belongs to */
name|avl_node_t
name|avl_link
decl_stmt|;
block|}
struct|;
comment|/* which iodevs to show. */
struct|struct
name|iodev_filter
block|{
comment|/* nr. of iodevs to choose */
name|size_t
name|if_max_iodevs
decl_stmt|;
comment|/* bit mask of enum io_types to allow */
name|int
name|if_allowed_types
decl_stmt|;
comment|/* should we show floppy ? if_names can override this */
name|int
name|if_skip_floppy
decl_stmt|;
comment|/* nr. of named iodevs */
name|size_t
name|if_nr_names
decl_stmt|;
name|char
modifier|*
modifier|*
name|if_names
decl_stmt|;
block|}
struct|;
comment|/* The primary structure of a system snapshot. */
struct|struct
name|snapshot
block|{
comment|/* what types were *requested* */
name|enum
name|snapshot_types
name|s_types
decl_stmt|;
name|size_t
name|s_nr_cpus
decl_stmt|;
name|struct
name|cpu_snapshot
modifier|*
name|s_cpus
decl_stmt|;
name|size_t
name|s_nr_psets
decl_stmt|;
name|struct
name|pset_snapshot
modifier|*
name|s_psets
decl_stmt|;
name|size_t
name|s_nr_intrs
decl_stmt|;
name|struct
name|intr_snapshot
modifier|*
name|s_intrs
decl_stmt|;
name|size_t
name|s_nr_iodevs
decl_stmt|;
name|struct
name|iodev_snapshot
modifier|*
name|s_iodevs
decl_stmt|;
name|size_t
name|s_iodevs_is_name_maxlen
decl_stmt|;
name|struct
name|sys_snapshot
name|s_sys
decl_stmt|;
name|struct
name|biostats
name|s_biostats
decl_stmt|;
block|}
struct|;
comment|/* print a message and exit with failure */
name|void
name|fail
parameter_list|(
name|int
name|do_perror
parameter_list|,
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
comment|/* strdup str, or exit with failure */
name|char
modifier|*
name|safe_strdup
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/* malloc successfully, or exit with failure */
name|void
modifier|*
name|safe_alloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/*  * Copy a kstat from src to dst. If the source kstat contains no data,  * then set the destination kstat data to NULL and size to zero.  * Returns 0 on success.  */
name|int
name|kstat_copy
parameter_list|(
specifier|const
name|kstat_t
modifier|*
name|src
parameter_list|,
name|kstat_t
modifier|*
name|dst
parameter_list|)
function_decl|;
comment|/*  * Look up the named kstat, and give the ui64 difference i.e.  * new - old, or if old is NULL, return new.  */
name|uint64_t
name|kstat_delta
parameter_list|(
name|kstat_t
modifier|*
name|old
parameter_list|,
name|kstat_t
modifier|*
name|new
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* Return the number of ticks delta between two hrtime_t values. */
name|uint64_t
name|hrtime_delta
parameter_list|(
name|hrtime_t
name|old
parameter_list|,
name|hrtime_t
name|new
parameter_list|)
function_decl|;
comment|/*  * Add the integer-valued stats from "src" to the  * existing ones in "dst". If "dst" does not contain  * stats, then a kstat_copy() is performed.  */
name|int
name|kstat_add
parameter_list|(
specifier|const
name|kstat_t
modifier|*
name|src
parameter_list|,
name|kstat_t
modifier|*
name|dst
parameter_list|)
function_decl|;
comment|/* return the number of CPUs with kstats (i.e. present and online) */
name|int
name|nr_active_cpus
parameter_list|(
name|struct
name|snapshot
modifier|*
name|ss
parameter_list|)
function_decl|;
comment|/*  * Return the difference in CPU ticks between the two sys  * kstats.  */
name|uint64_t
name|cpu_ticks_delta
parameter_list|(
name|kstat_t
modifier|*
name|old
parameter_list|,
name|kstat_t
modifier|*
name|new
parameter_list|)
function_decl|;
comment|/*  * Open the kstat chain. Cannot fail.  */
name|kstat_ctl_t
modifier|*
name|open_kstat
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*  * Return a struct snapshot based on the snapshot_types parameter  * passed in. iodev_filter may be NULL in which case all iodevs  * are selected if SNAP_IODEVS is passed.  */
name|struct
name|snapshot
modifier|*
name|acquire_snapshot
parameter_list|(
name|kstat_ctl_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|iodev_filter
modifier|*
parameter_list|)
function_decl|;
comment|/* free a snapshot */
name|void
name|free_snapshot
parameter_list|(
name|struct
name|snapshot
modifier|*
name|ss
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|snapshot_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|old
parameter_list|,
name|void
modifier|*
name|new
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/*  * Call the call back for each pair of data items of the given type,  * passing the data pointer passed in as well. If an item has been  * added, the first pointer will be NULL; if removed, the second pointer  * will be NULL.  *  * A non-zero return value indicates configuration has changed.  */
name|int
name|snapshot_walk
parameter_list|(
name|enum
name|snapshot_types
name|type
parameter_list|,
name|struct
name|snapshot
modifier|*
name|old
parameter_list|,
name|struct
name|snapshot
modifier|*
name|new
parameter_list|,
name|snapshot_cb
name|cb
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/*  * Output a line detailing any configuration changes such as a CPU  * brought online, etc, bracketed by<<>>.  */
name|void
name|snapshot_report_changes
parameter_list|(
name|struct
name|snapshot
modifier|*
name|old
parameter_list|,
name|struct
name|snapshot
modifier|*
name|new
parameter_list|)
function_decl|;
comment|/* Return non-zero if configuration has changed. */
name|int
name|snapshot_has_changed
parameter_list|(
name|struct
name|snapshot
modifier|*
name|old
parameter_list|,
name|struct
name|snapshot
modifier|*
name|new
parameter_list|)
function_decl|;
comment|/* free the given iodev */
name|void
name|free_iodev
parameter_list|(
name|struct
name|iodev_snapshot
modifier|*
name|iodev
parameter_list|)
function_decl|;
comment|/* acquire the I/O devices */
name|int
name|acquire_iodevs
parameter_list|(
name|struct
name|snapshot
modifier|*
name|ss
parameter_list|,
name|kstat_ctl_t
modifier|*
name|kc
parameter_list|,
name|struct
name|iodev_filter
modifier|*
name|df
parameter_list|)
function_decl|;
comment|/* strcmp-style I/O device comparator */
name|int
name|iodev_cmp
parameter_list|(
name|struct
name|iodev_snapshot
modifier|*
name|io1
parameter_list|,
name|struct
name|iodev_snapshot
modifier|*
name|io2
parameter_list|)
function_decl|;
comment|/* sleep until *wakeup + interval, keeping cadence where desired */
name|void
name|sleep_until
parameter_list|(
name|hrtime_t
modifier|*
name|wakeup
parameter_list|,
name|hrtime_t
name|interval
parameter_list|,
name|int
name|forever
parameter_list|,
name|int
modifier|*
name|caught_cont
parameter_list|)
function_decl|;
comment|/* signal handler - so we can be aware of SIGCONT */
name|void
name|cont_handler
parameter_list|(
name|int
name|sig_number
parameter_list|)
function_decl|;
comment|/* Print a timestamp in either Unix or standard format. */
name|void
name|print_timestamp
parameter_list|(
name|uint_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STATCOMMON_H */
end_comment

end_unit

