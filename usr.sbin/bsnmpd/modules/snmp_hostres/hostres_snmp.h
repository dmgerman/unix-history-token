begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005-2006 The FreeBSD Project  * All rights reserved.  *  * Author: Victor Cruceru<soc-victor@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Host Resources MIB for SNMPd.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTRES_SNMP_H_1132245017
end_ifndef

begin_define
define|#
directive|define
name|HOSTRES_SNMP_H_1132245017
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<devinfo.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/asn1.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/snmp.h>
end_include

begin_include
include|#
directive|include
file|<bsnmp/snmpmod.h>
end_include

begin_comment
comment|/*  * Default package directory for hrSWInstalledTable. Can be overridden  * via SNMP or configuration file.  */
end_comment

begin_define
define|#
directive|define
name|PATH_PKGDIR
value|"/var/db/pkg"
end_define

begin_comment
comment|/*  * These are the default maximum caching intervals for the various tables  * in seconds. They can be overridden from the configuration file.  */
end_comment

begin_define
define|#
directive|define
name|HR_STORAGE_TBL_REFRESH
value|7
end_define

begin_define
define|#
directive|define
name|HR_FS_TBL_REFRESH
value|7
end_define

begin_define
define|#
directive|define
name|HR_DISK_TBL_REFRESH
value|7
end_define

begin_define
define|#
directive|define
name|HR_NETWORK_TBL_REFRESH
value|7
end_define

begin_define
define|#
directive|define
name|HR_SWINS_TBL_REFRESH
value|120
end_define

begin_define
define|#
directive|define
name|HR_SWRUN_TBL_REFRESH
value|3
end_define

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statfs
struct_decl|;
end_struct_decl

begin_comment
comment|/* a debug macro */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|HRDBG
parameter_list|(
modifier|...
parameter_list|)
value|do {							\ 	fprintf(stderr, "HRDEBUG: %s: ", __func__);			\ 	fprintf(stderr, __VA_ARGS__);					\ 	fprintf(stderr, "\n");						\    } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HRDBG
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NDEBUG*/
end_comment

begin_comment
comment|/* path to devd(8) output pipe */
end_comment

begin_define
define|#
directive|define
name|PATH_DEVD_PIPE
value|"/var/run/devd.pipe"
end_define

begin_define
define|#
directive|define
name|IS_KERNPROC
parameter_list|(
name|kp
parameter_list|)
value|(((kp)->ki_flag& P_KTHREAD) == P_KTHREAD)
end_define

begin_enum
enum|enum
name|snmpTCTruthValue
block|{
name|SNMP_TRUE
init|=
literal|1
block|,
name|SNMP_FALSE
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* The number of CPU load samples per one minute, per each CPU */
end_comment

begin_define
define|#
directive|define
name|MAX_CPU_SAMPLES
value|4
end_define

begin_comment
comment|/*  * This structure is used to hold a SNMP table entry  * for HOST-RESOURCES-MIB's hrDeviceTable  */
end_comment

begin_struct
struct|struct
name|device_entry
block|{
name|int32_t
name|index
decl_stmt|;
name|struct
name|asn_oid
name|type
decl_stmt|;
name|u_char
name|descr
index|[
literal|64
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|asn_oid
name|id
decl_stmt|;
name|int32_t
name|status
decl_stmt|;
comment|/* enum DeviceStatus */
name|uint32_t
name|errors
decl_stmt|;
define|#
directive|define
name|HR_DEVICE_FOUND
value|0x001
comment|/* not dectected by libdevice, so don't try to refresh it*/
define|#
directive|define
name|HR_DEVICE_IMMUTABLE
value|0x002
comment|/* next 3 are not from the SNMP mib table, only to be used internally */
name|uint32_t
name|flags
decl_stmt|;
name|u_char
name|name
index|[
literal|32
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
name|location
index|[
literal|128
operator|+
literal|1
index|]
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|device_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Next structure is used to keep o list of mappings from a specific  * name (a_name) to an entry in the hrFSTblEntry;  * We are trying to keep the same index for a specific name at least  * for the duration of one SNMP agent run.  */
end_comment

begin_struct
struct|struct
name|device_map_entry
block|{
name|int32_t
name|hrIndex
decl_stmt|;
comment|/* used for hrDeviceTblEntry::index */
comment|/* map key is the pair (name_key, location_key) */
name|u_char
name|name_key
index|[
literal|32
operator|+
literal|1
index|]
decl_stmt|;
comment|/* copy of device name */
name|u_char
name|location_key
index|[
literal|128
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 	 * Next may be NULL if the respective hrDeviceTblEntry 	 * is (temporally) gone. 	 */
name|struct
name|device_entry
modifier|*
name|entry_p
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|device_map_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|device_map
argument_list|,
name|device_map_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* descriptor to access kernel memory */
end_comment

begin_decl_stmt
specifier|extern
name|kvm_t
modifier|*
name|hr_kd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table used for consistent device table indexing. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|device_map
name|device_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of ticks between two updates for hrStorageTable */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|storage_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of ticks between updated of FS table */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|fs_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of ticks between updates of SWRun and SWRunPerf table */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|swrun_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of ticks between device table refreshs. */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|device_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of ticks between refreshs */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|disk_storage_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of ticks between updates of network table */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|swins_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of ticks between updates of network table */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|network_tbl_refresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* package directory */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|pkg_dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize and populate storage table */
end_comment

begin_function_decl
name|void
name|init_storage_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrStorageTable. */
end_comment

begin_function_decl
name|void
name|fini_storage_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Refresh routine for hrStorageTable. */
end_comment

begin_function_decl
name|void
name|refresh_storage_tbl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the type of filesystem referenced in a struct statfs * -  * used by FSTbl and StorageTbl functions.  */
end_comment

begin_function_decl
specifier|const
name|struct
name|asn_oid
modifier|*
name|fs_get_type
parameter_list|(
specifier|const
name|struct
name|statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Because hrFSTable depends to hrStorageTable we are  * refreshing hrFSTable by refreshing hrStorageTable.  * When one entry "of type" fs from hrStorageTable is refreshed  * then the corresponding entry from hrFSTable is refreshed  * FS_tbl_pre_refresh_v() is called  before refeshing fs part of hrStorageTable  */
end_comment

begin_function_decl
name|void
name|fs_tbl_pre_refresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fs_tbl_process_statfs_entry
parameter_list|(
specifier|const
name|struct
name|statfs
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Called after refreshing fs part of hrStorageTable */
end_comment

begin_function_decl
name|void
name|fs_tbl_post_refresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Refresh the FS table if neccessary. */
end_comment

begin_function_decl
name|void
name|refresh_fs_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrFSTable. */
end_comment

begin_function_decl
name|void
name|fini_fs_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Init the things for both of hrSWRunTable and hrSWRunPerfTable */
end_comment

begin_function_decl
name|void
name|init_swrun_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for both of hrSWRunTable and hrSWRunPerfTable */
end_comment

begin_function_decl
name|void
name|fini_swrun_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Init and populate hrDeviceTable */
end_comment

begin_function_decl
name|void
name|init_device_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* start devd monitoring */
end_comment

begin_function_decl
name|void
name|start_device_tbl
parameter_list|(
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrDeviceTable */
end_comment

begin_function_decl
name|void
name|fini_device_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Refresh routine for hrDeviceTable. */
end_comment

begin_function_decl
name|void
name|refresh_device_tbl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find an item in hrDeviceTbl by its entry->index. */
end_comment

begin_function_decl
name|struct
name|device_entry
modifier|*
name|device_find_by_index
parameter_list|(
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find an item in hrDeviceTbl by name. */
end_comment

begin_function_decl
name|struct
name|device_entry
modifier|*
name|device_find_by_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a new entry out of thin air. */
end_comment

begin_function_decl
name|struct
name|device_entry
modifier|*
name|device_entry_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Init the things for hrProcessorTable. */
end_comment

begin_function_decl
name|void
name|init_processor_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrProcessorTable. */
end_comment

begin_function_decl
name|void
name|fini_processor_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start the processor table CPU load collector. */
end_comment

begin_function_decl
name|void
name|start_processor_tbl
parameter_list|(
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Init the things for hrDiskStorageTable */
end_comment

begin_function_decl
name|int
name|init_disk_storage_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrDiskStorageTable. */
end_comment

begin_function_decl
name|void
name|fini_disk_storage_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Refresh routine for hrDiskStorageTable. */
end_comment

begin_function_decl
name|void
name|refresh_disk_storage_tbl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrPartitionTable. */
end_comment

begin_function_decl
name|void
name|fini_partition_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrNetworkTable. */
end_comment

begin_function_decl
name|void
name|fini_network_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* populate network table */
end_comment

begin_function_decl
name|void
name|start_network_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialize installed software table */
end_comment

begin_function_decl
name|void
name|init_swins_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* finalize installed software table */
end_comment

begin_function_decl
name|void
name|fini_swins_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* refresh the hrSWInstalledTable if necessary */
end_comment

begin_function_decl
name|void
name|refresh_swins_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Init the things for hrPrinterTable */
end_comment

begin_function_decl
name|void
name|init_printer_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finalization routine for hrPrinterTable. */
end_comment

begin_function_decl
name|void
name|fini_printer_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Refresh printer table */
end_comment

begin_function_decl
name|void
name|refresh_printer_tbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get boot command line */
end_comment

begin_function_decl
name|int
name|OS_getSystemInitialLoadParameters
parameter_list|(
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Start refreshing the partition table */
end_comment

begin_function_decl
name|void
name|partition_tbl_post_refresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Handle refresh for the given disk */
end_comment

begin_function_decl
name|void
name|partition_tbl_handle_disk
parameter_list|(
name|int32_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finish refreshing the partition table. */
end_comment

begin_function_decl
name|void
name|partition_tbl_pre_refresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the FS index in a partition table entry */
end_comment

begin_function_decl
name|void
name|handle_partition_fs_index
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make an SNMP DateAndTime from a struct tm. */
end_comment

begin_function_decl
name|int
name|make_date_time
parameter_list|(
name|u_char
modifier|*
parameter_list|,
specifier|const
name|struct
name|tm
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free all static data */
end_comment

begin_function_decl
name|void
name|fini_scalars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HOSTRES_SNMP_H_1132245017 */
end_comment

end_unit

