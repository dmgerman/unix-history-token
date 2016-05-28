begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013, 2014 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file zfsd.h  *  * Class definitions and supporting data strutures for the ZFS fault  * management daemon.  *  * Header requirements:  *  *    #include<sys/fs/zfs.h>  *  *    #include<libzfs.h>  *  *    #include<list>  *    #include<map>  *    #include<string>  *  *    #include<devdctl/guid.h>  *    #include<devdctl/event.h>  *    #include<devdctl/event_factory.h>  *    #include<devdctl/consumer.h>  *  *    #include "vdev_iterator.h"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZFSD_H_
end_define

begin_comment
comment|/*=========================== Forward Declarations ===========================*/
end_comment

begin_struct_decl
struct_decl|struct
name|pidfh
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|zpool_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|zpool_handle
name|zpool_handle_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|zfs_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|libzfs_handle
name|libzfs_handle_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|nvlist
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|nvlist
name|nvlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|LeafIterFunc
parameter_list|(
name|zpool_handle_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*================================ Global Data ===============================*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|libzfs_handle_t
modifier|*
name|g_zfsHandle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*--------------------------------- ZfsDaemon --------------------------------*/
end_comment

begin_comment
comment|/**  * Static singleton orchestrating the operations of the ZFS daemon program.  */
end_comment

begin_decl_stmt
name|class
name|ZfsDaemon
range|:
name|public
name|DevdCtl
operator|::
name|Consumer
block|{
name|public
operator|:
comment|/** Return the ZfsDaemon singleton. */
specifier|static
name|ZfsDaemon
operator|&
name|Get
argument_list|()
block|;
comment|/** 	 * Used by signal handlers to ensure, in a race free way, that 	 * the event loop will perform at least one more full loop 	 * before sleeping again. 	 */
specifier|static
name|void
name|WakeEventLoop
argument_list|()
block|;
comment|/** 	 * Schedules a rescan of devices in the system for potential 	 * candidates to replace a missing vdev.  The scan is performed 	 * during the next run of the event loop. 	 */
specifier|static
name|void
name|RequestSystemRescan
argument_list|()
block|;
comment|/** Daemonize and perform all functions of the ZFS daemon. */
specifier|static
name|void
name|Run
argument_list|()
block|;
name|private
operator|:
name|ZfsDaemon
argument_list|()
block|;
operator|~
name|ZfsDaemon
argument_list|()
block|;
specifier|static
name|VdevCallback_t
name|VdevAddCaseFile
block|;
comment|/** Purge our cache of outstanding ZFS issues in the system. */
name|void
name|PurgeCaseFiles
argument_list|()
block|;
comment|/** Build a cache of outstanding ZFS issues in the system. */
name|void
name|BuildCaseFiles
argument_list|()
block|;
comment|/** 	 * Iterate over all known issues and attempt to solve them 	 * given resources currently available in the system. 	 */
name|void
name|RescanSystem
argument_list|()
block|;
comment|/** 	 * Interrogate the system looking for previously unknown 	 * faults that occurred either before ZFSD was started, 	 * or during a period of lost communication with Devd. 	 */
name|void
name|DetectMissedEvents
argument_list|()
block|;
comment|/** 	 * Wait for and process event source activity. 	 */
name|void
name|EventLoop
argument_list|()
block|;
comment|/** 	 * Signal handler for which our response is to 	 * log the current state of the daemon. 	 * 	 * \param sigNum  The signal caught. 	 */
specifier|static
name|void
name|InfoSignalHandler
argument_list|(
argument|int sigNum
argument_list|)
block|;
comment|/** 	 * Signal handler for which our response is to 	 * request a case rescan. 	 * 	 * \param sigNum  The signal caught. 	 */
specifier|static
name|void
name|RescanSignalHandler
argument_list|(
argument|int sigNum
argument_list|)
block|;
comment|/** 	 * Signal handler for which our response is to 	 * gracefully terminate. 	 * 	 * \param sigNum  The signal caught. 	 */
specifier|static
name|void
name|QuitSignalHandler
argument_list|(
argument|int sigNum
argument_list|)
block|;
comment|/** 	 * Open and lock our PID file. 	 */
specifier|static
name|void
name|OpenPIDFile
argument_list|()
block|;
comment|/** 	 * Update our PID file with our PID. 	 */
specifier|static
name|void
name|UpdatePIDFile
argument_list|()
block|;
comment|/** 	 * Close and release the lock on our PID file. 	 */
specifier|static
name|void
name|ClosePIDFile
argument_list|()
block|;
comment|/** 	 * Perform syslog configuration. 	 */
specifier|static
name|void
name|InitializeSyslog
argument_list|()
block|;
specifier|static
name|ZfsDaemon
operator|*
name|s_theZfsDaemon
block|;
comment|/** 	 * Set to true when our program is signaled to 	 * gracefully exit. 	 */
specifier|static
name|bool
name|s_logCaseFiles
block|;
comment|/** 	 * Set to true when our program is signaled to 	 * gracefully exit. 	 */
specifier|static
name|bool
name|s_terminateEventLoop
block|;
comment|/** 	 * The canonical path and file name of zfsd's PID file. 	 */
specifier|static
name|char
name|s_pidFilePath
index|[]
block|;
comment|/** 	 * Control structure for PIDFILE(3) API. 	 */
specifier|static
name|pidfh
operator|*
name|s_pidFH
block|;
comment|/** 	 * Pipe file descriptors used to close races with our 	 * signal handlers. 	 */
specifier|static
name|int
name|s_signalPipeFD
index|[
literal|2
index|]
block|;
comment|/** 	 * Flag controlling a rescan from ZFSD's event loop of all 	 * GEOM providers in the system to find candidates for solving 	 * cases. 	 */
specifier|static
name|bool
name|s_systemRescanRequested
block|;
comment|/** 	 * Flag controlling whether events can be queued.  This boolean 	 * is set during event replay to ensure that events for pools or 	 * devices no longer in the system are not retained forever. 	 */
specifier|static
name|bool
name|s_consumingEvents
block|;
specifier|static
name|DevdCtl
operator|::
name|EventFactory
operator|::
name|Record
name|s_registryEntries
index|[]
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ZFSD_H_ */
end_comment

end_unit

