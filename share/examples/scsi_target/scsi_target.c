begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SCSI Disk Emulator  *  * Copyright (c) 2002 Nate Lawson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<aio.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<cam/cam_queue.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_targetio.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_message.h>
end_include

begin_include
include|#
directive|include
file|"scsi_target.h"
end_include

begin_comment
comment|/* Maximum amount to transfer per CTIO */
end_comment

begin_define
define|#
directive|define
name|MAX_XFER
value|MAXPHYS
end_define

begin_comment
comment|/* Maximum number of allocated CTIOs */
end_comment

begin_define
define|#
directive|define
name|MAX_CTIOS
value|32
end_define

begin_comment
comment|/* Maximum sector size for emulated volume */
end_comment

begin_define
define|#
directive|define
name|MAX_SECTOR
value|32768
end_define

begin_comment
comment|/* Global variables */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|volume_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|sector_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|buf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local variables */
end_comment

begin_decl_stmt
specifier|static
name|int
name|targ_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|kq_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|file_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|num_ctios
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ccb_queue
name|pending_queue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ccb_queue
name|work_queue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ioc_enable_lun
name|ioc_enlun
init|=
block|{
name|CAM_BUS_WILDCARD
block|,
name|CAM_TARGET_WILDCARD
block|,
name|CAM_LUN_WILDCARD
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local functions */
end_comment

begin_function_decl
specifier|static
name|void
name|cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|init_ccbs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|request_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|handle_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* static int		work_atio(struct ccb_accept_tio *); */
end_comment

begin_function_decl
specifier|static
name|void
name|queue_io
parameter_list|(
name|struct
name|ccb_scsiio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|run_queue
parameter_list|(
name|struct
name|ccb_accept_tio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|work_inot
parameter_list|(
name|struct
name|ccb_immed_notify
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|ccb_scsiio
modifier|*
name|get_ctio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* static void		free_ccb(union ccb *); */
end_comment

begin_function_decl
specifier|static
name|cam_status
name|get_sim_flags
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|rel_simq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|abort_all_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|ch
decl_stmt|,
name|unit
decl_stmt|;
name|char
modifier|*
name|file_name
decl_stmt|,
name|targname
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|req_flags
decl_stmt|,
name|sim_flags
decl_stmt|;
name|off_t
name|user_size
decl_stmt|;
comment|/* Initialize */
name|debug
operator|=
literal|0
expr_stmt|;
name|req_flags
operator|=
name|sim_flags
operator|=
literal|0
expr_stmt|;
name|user_size
operator|=
literal|0
expr_stmt|;
name|targ_fd
operator|=
name|file_fd
operator|=
name|kq_fd
operator|=
operator|-
literal|1
expr_stmt|;
name|num_ctios
operator|=
literal|0
expr_stmt|;
name|sector_size
operator|=
name|SECTOR_SIZE
expr_stmt|;
name|buf_size
operator|=
name|DFLTPHYS
expr_stmt|;
comment|/* Prepare resource pools */
name|TAILQ_INIT
argument_list|(
operator|&
name|pending_queue
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|work_queue
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"AdSTb:c:s:W:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'A'
case|:
name|req_flags
operator||=
name|SID_Addr16
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|debug
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'S'
case|:
name|req_flags
operator||=
name|SID_Sync
expr_stmt|;
break|break;
case|case
literal|'T'
case|:
name|req_flags
operator||=
name|SID_CmdQue
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|buf_size
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf_size
operator|<
literal|256
operator|||
name|buf_size
operator|>
name|MAX_XFER
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"Unreasonable buf size: %s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|sector_size
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
if|if
condition|(
name|sector_size
operator|<
literal|512
operator|||
name|sector_size
operator|>
name|MAX_SECTOR
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"Unreasonable sector size: %s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
block|{
name|int
name|last
decl_stmt|,
name|shift
init|=
literal|0
decl_stmt|;
name|last
operator|=
name|strlen
argument_list|(
name|optarg
argument_list|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|last
operator|>
literal|0
condition|)
block|{
switch|switch
condition|(
name|tolower
argument_list|(
name|optarg
index|[
name|last
index|]
argument_list|)
condition|)
block|{
case|case
literal|'e'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'p'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'t'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'g'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'m'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
comment|/* FALLTHROUGH */
case|case
literal|'k'
case|:
name|shift
operator|+=
literal|10
expr_stmt|;
name|optarg
index|[
name|last
index|]
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
name|user_size
operator|=
name|strtoll
argument_list|(
name|optarg
argument_list|,
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
argument_list|,
comment|/*base*/
literal|10
argument_list|)
expr_stmt|;
name|user_size
operator|<<=
name|shift
expr_stmt|;
if|if
condition|(
name|user_size
operator|<
literal|0
condition|)
name|errx
argument_list|(
literal|1
argument_list|,
literal|"Unreasonable volume size: %s"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
literal|'W'
case|:
name|req_flags
operator|&=
operator|~
operator|(
name|SID_WBus16
operator||
name|SID_WBus32
operator|)
expr_stmt|;
switch|switch
condition|(
name|atoi
argument_list|(
name|optarg
argument_list|)
condition|)
block|{
case|case
literal|8
case|:
comment|/* Leave req_flags zeroed */
break|break;
case|case
literal|16
case|:
name|req_flags
operator||=
name|SID_WBus16
expr_stmt|;
break|break;
case|case
literal|32
case|:
name|req_flags
operator||=
name|SID_WBus32
expr_stmt|;
break|break;
default|default:
name|warnx
argument_list|(
literal|"Width %s not supported"
argument_list|,
name|optarg
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
break|break;
default|default:
name|usage
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
name|sscanf
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|"%u:%u:%u"
argument_list|,
operator|&
name|ioc_enlun
operator|.
name|path_id
argument_list|,
operator|&
name|ioc_enlun
operator|.
name|target_id
argument_list|,
operator|&
name|ioc_enlun
operator|.
name|lun_id
argument_list|)
expr_stmt|;
name|file_name
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|ioc_enlun
operator|.
name|path_id
operator|==
name|CAM_BUS_WILDCARD
operator|||
name|ioc_enlun
operator|.
name|target_id
operator|==
name|CAM_TARGET_WILDCARD
operator|||
name|ioc_enlun
operator|.
name|lun_id
operator|==
name|CAM_LUN_WILDCARD
condition|)
block|{
name|warnx
argument_list|(
literal|"Incomplete target path specified"
argument_list|)
expr_stmt|;
name|usage
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
comment|/* We don't support any vendor-specific commands */
name|ioc_enlun
operator|.
name|grp6_len
operator|=
literal|0
expr_stmt|;
name|ioc_enlun
operator|.
name|grp7_len
operator|=
literal|0
expr_stmt|;
comment|/* Open backing store for IO */
name|file_fd
operator|=
name|open
argument_list|(
name|file_name
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|file_fd
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"open backing store file"
argument_list|)
expr_stmt|;
comment|/* Check backing store size or use the size user gave us */
if|if
condition|(
name|user_size
operator|==
literal|0
condition|)
block|{
name|struct
name|stat
name|st
decl_stmt|;
if|if
condition|(
name|fstat
argument_list|(
name|file_fd
argument_list|,
operator|&
name|st
argument_list|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"fstat file"
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
if|if
condition|(
operator|(
name|st
operator|.
name|st_mode
operator|&
name|S_IFCHR
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* raw device */
name|off_t
name|mediasize
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|file_fd
argument_list|,
name|DIOCGMEDIASIZE
argument_list|,
operator|&
name|mediasize
argument_list|)
operator|<
literal|0
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"DIOCGMEDIASIZE"
argument_list|)
expr_stmt|;
comment|/* XXX get sector size by ioctl()?? */
name|volume_size
operator|=
name|mediasize
operator|/
name|sector_size
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|volume_size
operator|=
name|st
operator|.
name|st_size
operator|/
name|sector_size
expr_stmt|;
block|}
else|else
block|{
name|volume_size
operator|=
name|user_size
operator|/
name|sector_size
expr_stmt|;
block|}
if|if
condition|(
name|debug
condition|)
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
name|warnx
argument_list|(
literal|"volume_size: %d bytes x %jd sectors"
argument_list|,
else|#
directive|else
argument|warnx(
literal|"volume_size: %d bytes x %lld sectors"
argument|,
endif|#
directive|endif
argument|sector_size, volume_size);  	if (volume_size<=
literal|0
argument|) 		errx(
literal|1
argument|,
literal|"volume must be larger than %d"
argument|, sector_size);  	{ 		struct aiocb aio
argument_list|,
argument|*aiop;
comment|/* Make sure we have working AIO support */
argument|memset(&aio,
literal|0
argument|, sizeof(aio)); 		aio.aio_buf = malloc(sector_size); 		if (aio.aio_buf == NULL) 			err(
literal|1
argument|,
literal|"malloc"
argument|); 		aio.aio_fildes = file_fd; 		aio.aio_offset =
literal|0
argument|; 		aio.aio_nbytes = sector_size; 		signal(SIGSYS, SIG_IGN); 		if (aio_read(&aio) !=
literal|0
argument|) { 			printf(
literal|"You must enable VFS_AIO in your kernel "
literal|"or load the aio(4) module.\n"
argument|); 			err(
literal|1
argument|,
literal|"aio_read"
argument|); 		} 		if (aio_waitcomplete(&aiop, NULL) != sector_size) 			err(
literal|1
argument|,
literal|"aio_waitcomplete"
argument|); 		assert(aiop ==&aio); 		signal(SIGSYS, SIG_DFL); 		free((void *)aio.aio_buf); 		if (debug) 			warnx(
literal|"aio support tested ok"
argument|); 	}
comment|/* Go through all the control devices and find one that isn't busy. */
argument|unit =
literal|0
argument|; 	do { 		snprintf(targname, sizeof(targname),
literal|"/dev/targ%d"
argument|, unit++);     		targ_fd = open(targname, O_RDWR); 	} while (targ_fd<
literal|0
argument|&& errno == EBUSY);  	if (targ_fd<
literal|0
argument|)     	    err(
literal|1
argument|,
literal|"Tried to open %d devices, none available"
argument|, unit);
comment|/* The first three are handled by kevent() later */
argument|signal(SIGHUP, SIG_IGN); 	signal(SIGINT, SIG_IGN); 	signal(SIGTERM, SIG_IGN); 	signal(SIGPROF, SIG_IGN); 	signal(SIGALRM, SIG_IGN); 	signal(SIGSTOP, SIG_IGN); 	signal(SIGTSTP, SIG_IGN);
comment|/* Register a cleanup handler to run when exiting */
argument|atexit(cleanup);
comment|/* Enable listening on the specified LUN */
argument|if (ioctl(targ_fd, TARGIOCENABLE,&ioc_enlun) !=
literal|0
argument|) 		err(
literal|1
argument|,
literal|"TARGIOCENABLE"
argument|);
comment|/* Enable debugging if requested */
argument|if (debug) { 		if (ioctl(targ_fd, TARGIOCDEBUG,&debug) !=
literal|0
argument|) 			err(
literal|1
argument|,
literal|"TARGIOCDEBUG"
argument|); 	}
comment|/* Set up inquiry data according to what SIM supports */
argument|if (get_sim_flags(&sim_flags) != CAM_REQ_CMP) 		errx(
literal|1
argument|,
literal|"get_sim_flags"
argument|); 	if (tcmd_init(req_flags, sim_flags) !=
literal|0
argument|) 		errx(
literal|1
argument|,
literal|"Initializing tcmd subsystem failed"
argument|);
comment|/* Queue ATIOs and INOTs on descriptor */
argument|if (init_ccbs() !=
literal|0
argument|) 		errx(
literal|1
argument|,
literal|"init_ccbs failed"
argument|);  	if (debug) 		warnx(
literal|"main loop beginning"
argument|); 	request_loop();  	exit(
literal|0
argument|); }  static void cleanup() { 	struct ccb_hdr *ccb_h;  	if (debug) { 		warnx(
literal|"cleanup called"
argument|); 		debug =
literal|0
argument|; 		ioctl(targ_fd, TARGIOCDEBUG,&debug); 	} 	ioctl(targ_fd, TARGIOCDISABLE, NULL); 	close(targ_fd);  	while ((ccb_h = TAILQ_FIRST(&pending_queue)) != NULL) { 		TAILQ_REMOVE(&pending_queue, ccb_h, periph_links.tqe); 		free_ccb((union ccb *)ccb_h); 	} 	while ((ccb_h = TAILQ_FIRST(&work_queue)) != NULL) { 		TAILQ_REMOVE(&work_queue, ccb_h, periph_links.tqe); 		free_ccb((union ccb *)ccb_h); 	}  	if (kq_fd != -
literal|1
argument|) 		close(kq_fd); }
comment|/* Allocate ATIOs/INOTs and queue on HBA */
argument|static int init_ccbs() { 	int i;  	for (i =
literal|0
argument|; i< MAX_INITIATORS; i++) { 		struct ccb_accept_tio *atio; 		struct atio_descr *a_descr; 		struct ccb_immed_notify *inot;  		atio = (struct ccb_accept_tio *)malloc(sizeof(*atio)); 		if (atio == NULL) { 			warn(
literal|"malloc ATIO"
argument|); 			return (-
literal|1
argument|); 		} 		a_descr = (struct atio_descr *)malloc(sizeof(*a_descr)); 		if (a_descr == NULL) { 			free(atio); 			warn(
literal|"malloc atio_descr"
argument|); 			return (-
literal|1
argument|); 		} 		atio->ccb_h.func_code = XPT_ACCEPT_TARGET_IO; 		atio->ccb_h.targ_descr = a_descr; 		send_ccb((union ccb *)atio,
comment|/*priority*/
literal|1
argument|);  		inot = (struct ccb_immed_notify *)malloc(sizeof(*inot)); 		if (inot == NULL) { 			warn(
literal|"malloc INOT"
argument|); 			return (-
literal|1
argument|); 		} 		inot->ccb_h.func_code = XPT_IMMED_NOTIFY; 		send_ccb((union ccb *)inot,
comment|/*priority*/
literal|1
argument|); 	}  	return (
literal|0
argument|); }  static void request_loop() { 	struct kevent events[MAX_EVENTS]; 	struct timespec ts
argument_list|,
argument|*tptr; 	int quit;
comment|/* Register kqueue for event notification */
argument|if ((kq_fd = kqueue())<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"init kqueue"
argument|);
comment|/* Set up some default events */
argument|EV_SET(&events[
literal|0
argument|], SIGHUP, EVFILT_SIGNAL, EV_ADD|EV_ENABLE,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 	EV_SET(&events[
literal|1
argument|], SIGINT, EVFILT_SIGNAL, EV_ADD|EV_ENABLE,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 	EV_SET(&events[
literal|2
argument|], SIGTERM, EVFILT_SIGNAL, EV_ADD|EV_ENABLE,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 	EV_SET(&events[
literal|3
argument|], targ_fd, EVFILT_READ, EV_ADD|EV_ENABLE,
literal|0
argument|,
literal|0
argument|,
literal|0
argument|); 	if (kevent(kq_fd, events,
literal|4
argument|, NULL,
literal|0
argument|, NULL)<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"kevent signal registration"
argument|);  	ts.tv_sec =
literal|0
argument|; 	ts.tv_nsec =
literal|0
argument|; 	tptr = NULL; 	quit =
literal|0
argument|;
comment|/* Loop until user signal */
argument|while (quit ==
literal|0
argument|) { 		int retval
argument_list|,
argument|i; 		struct ccb_hdr *ccb_h;
comment|/* Check for the next signal, read ready, or AIO completion */
argument|retval = kevent(kq_fd, NULL,
literal|0
argument|, events, MAX_EVENTS, tptr); 		if (retval<
literal|0
argument|) { 			if (errno == EINTR) { 				if (debug) 					warnx(
literal|"EINTR, looping"
argument|); 				continue;             		} 			else { 				err(
literal|1
argument|,
literal|"kevent failed"
argument|); 			} 		} else if (retval> MAX_EVENTS) { 			errx(
literal|1
argument|,
literal|"kevent returned more events than allocated?"
argument|); 		}
comment|/* Process all received events. */
argument|for (i =
literal|0
argument|; i< retval; i++) { 			if ((events[i].flags& EV_ERROR) !=
literal|0
argument|) 				errx(
literal|1
argument|,
literal|"kevent registration failed"
argument|);  			switch (events[i].filter) { 			case EVFILT_READ: 				if (debug) 					warnx(
literal|"read ready"
argument|); 				handle_read(); 				break; 			case EVFILT_AIO: 			{ 				struct ccb_scsiio *ctio; 				struct ctio_descr *c_descr; 				if (debug) 					warnx(
literal|"aio ready"
argument|);  				ctio = (struct ccb_scsiio *)events[i].udata; 				c_descr = (struct ctio_descr *) 					  ctio->ccb_h.targ_descr; 				c_descr->event = AIO_DONE;
comment|/* Queue on the appropriate ATIO */
argument|queue_io(ctio);
comment|/* Process any queued completions. */
argument|run_queue(c_descr->atio); 				break; 			} 			case EVFILT_SIGNAL: 				if (debug) 					warnx(
literal|"signal ready, setting quit"
argument|); 				quit =
literal|1
argument|; 				break; 			default: 				warnx(
literal|"unknown event %#x"
argument|, events[i].filter); 				break; 			}  			if (debug) 				warnx(
literal|"event done"
argument|); 		}
comment|/* Grab the first CCB and perform one work unit. */
argument|if ((ccb_h = TAILQ_FIRST(&work_queue)) != NULL) { 			union ccb *ccb;  			ccb = (union ccb *)ccb_h; 			switch (ccb_h->func_code) { 			case XPT_ACCEPT_TARGET_IO:
comment|/* Start one more transfer. */
argument|retval = work_atio(&ccb->atio); 				break; 			case XPT_IMMED_NOTIFY: 				retval = work_inot(&ccb->cin); 				break; 			default: 				warnx(
literal|"Unhandled ccb type %#x on workq"
argument|, 				      ccb_h->func_code); 				abort();
comment|/* NOTREACHED */
argument|}
comment|/* Assume work function handled the exception */
argument|if ((ccb_h->status& CAM_DEV_QFRZN) !=
literal|0
argument|) { 				if (debug) { 					warnx(
literal|"Queue frozen receiving CCB, "
literal|"releasing"
argument|); 				} 				rel_simq(); 			}
comment|/* No more work needed for this command. */
argument|if (retval ==
literal|0
argument|) { 				TAILQ_REMOVE(&work_queue, ccb_h, 					     periph_links.tqe); 			} 		}
comment|/* 		 * Poll for new events (i.e. completions) while we 		 * are processing CCBs on the work_queue. Once it's 		 * empty, use an infinite wait. 		 */
argument|if (!TAILQ_EMPTY(&work_queue)) 			tptr =&ts; 		else 			tptr = NULL; 	} }
comment|/* CCBs are ready from the kernel */
argument|static void handle_read() { 	union ccb *ccb_array[MAX_INITIATORS]
argument_list|,
argument|*ccb; 	int ccb_count
argument_list|,
argument|i;  	ccb_count = read(targ_fd, ccb_array, sizeof(ccb_array)); 	if (ccb_count<=
literal|0
argument|) { 		warn(
literal|"read ccb ptrs"
argument|); 		return; 	} 	ccb_count /= sizeof(union ccb *); 	if (ccb_count<
literal|1
argument|) { 		warnx(
literal|"truncated read ccb ptr?"
argument|); 		return; 	}  	for (i =
literal|0
argument|; i< ccb_count; i++) { 		ccb = ccb_array[i]; 		TAILQ_REMOVE(&pending_queue,&ccb->ccb_h, periph_links.tqe);  		switch (ccb->ccb_h.func_code) { 		case XPT_ACCEPT_TARGET_IO: 		{ 			struct ccb_accept_tio *atio; 			struct atio_descr *a_descr;
comment|/* Initialize ATIO descr for this transaction */
argument|atio =&ccb->atio; 			a_descr = (struct atio_descr *)atio->ccb_h.targ_descr; 			bzero(a_descr, sizeof(*a_descr)); 			TAILQ_INIT(&a_descr->cmplt_io); 			a_descr->flags = atio->ccb_h.flags& 				(CAM_DIS_DISCONNECT | CAM_TAG_ACTION_VALID);
comment|/* XXX add a_descr->priority */
argument|if ((atio->ccb_h.flags& CAM_CDB_POINTER) ==
literal|0
argument|) 				a_descr->cdb = atio->cdb_io.cdb_bytes; 			else 				a_descr->cdb = atio->cdb_io.cdb_ptr;
comment|/* ATIOs are processed in FIFO order */
argument|TAILQ_INSERT_TAIL(&work_queue,&ccb->ccb_h, 					  periph_links.tqe); 			break; 		} 		case XPT_CONT_TARGET_IO: 		{ 			struct ccb_scsiio *ctio; 			struct ctio_descr *c_descr;  			ctio =&ccb->ctio; 			c_descr = (struct ctio_descr *)ctio->ccb_h.targ_descr; 			c_descr->event = CTIO_DONE;
comment|/* Queue on the appropriate ATIO */
argument|queue_io(ctio);
comment|/* Process any queued completions. */
argument|run_queue(c_descr->atio); 			break; 		} 		case XPT_IMMED_NOTIFY:
comment|/* INOTs are handled with priority */
argument|TAILQ_INSERT_HEAD(&work_queue,&ccb->ccb_h, 					  periph_links.tqe); 			break; 		default: 			warnx(
literal|"Unhandled ccb type %#x in handle_read"
argument|, 			      ccb->ccb_h.func_code); 			break; 		} 	} }
comment|/* Process an ATIO CCB from the kernel */
argument|int work_atio(struct ccb_accept_tio *atio) { 	struct ccb_scsiio *ctio; 	struct atio_descr *a_descr; 	struct ctio_descr *c_descr; 	cam_status status; 	int ret;  	if (debug) 		warnx(
literal|"Working on ATIO %p"
argument|, atio);  	a_descr = (struct atio_descr *)atio->ccb_h.targ_descr;
comment|/* Get a CTIO and initialize it according to our known parameters */
argument|ctio = get_ctio(); 	if (ctio == NULL) 		return (
literal|1
argument|); 	ret =
literal|0
argument|; 	ctio->ccb_h.flags = a_descr->flags; 	ctio->tag_id = atio->tag_id; 	ctio->init_id = atio->init_id;
comment|/* XXX priority needs to be added to a_descr */
argument|c_descr = (struct ctio_descr *)ctio->ccb_h.targ_descr; 	c_descr->atio = atio; 	if ((a_descr->flags& CAM_DIR_IN) !=
literal|0
argument|) 		c_descr->offset = a_descr->base_off + a_descr->targ_req; 	else if ((a_descr->flags& CAM_DIR_MASK) == CAM_DIR_OUT) 		c_descr->offset = a_descr->base_off + a_descr->init_req; 	else 		c_descr->offset = a_descr->base_off;
comment|/*  	 * Return a check condition if there was an error while 	 * receiving this ATIO. 	 */
argument|if (atio->sense_len !=
literal|0
argument|) { 		struct scsi_sense_data *sense;  		if (debug) { 			warnx(
literal|"ATIO with %u bytes sense received"
argument|, 			      atio->sense_len); 		} 		sense =&atio->sense_data; 		tcmd_sense(ctio->init_id, ctio, sense->flags, 			   sense->add_sense_code, sense->add_sense_code_qual); 		send_ccb((union ccb *)ctio,
comment|/*priority*/
literal|1
argument|); 		return (
literal|0
argument|); 	}  	status = atio->ccb_h.status& CAM_STATUS_MASK; 	switch (status) { 	case CAM_CDB_RECVD: 		ret = tcmd_handle(atio, ctio, ATIO_WORK); 		break; 	case CAM_REQ_ABORTED:
comment|/* Requeue on HBA */
argument|TAILQ_REMOVE(&work_queue,&atio->ccb_h, periph_links.tqe); 		send_ccb((union ccb *)atio,
comment|/*priority*/
literal|1
argument|); 		ret =
literal|1
argument|; 		break; 	default: 		warnx(
literal|"ATIO completed with unhandled status %#x"
argument|, status); 		abort();
comment|/* NOTREACHED */
argument|break; 	}  	return (ret); }  static void queue_io(struct ccb_scsiio *ctio) { 	struct ccb_hdr *ccb_h; 	struct io_queue *ioq; 	struct ctio_descr *c_descr
argument_list|,
argument|*curr_descr; 	 	c_descr = (struct ctio_descr *)ctio->ccb_h.targ_descr;
comment|/* If the completion is for a specific ATIO, queue in order */
argument|if (c_descr->atio != NULL) { 		struct atio_descr *a_descr;  		a_descr = (struct atio_descr *)c_descr->atio->ccb_h.targ_descr; 		ioq =&a_descr->cmplt_io; 	} else { 		errx(
literal|1
argument|,
literal|"CTIO %p has NULL ATIO"
argument|, ctio); 	}
comment|/* Insert in order, sorted by offset */
argument|if (!TAILQ_EMPTY(ioq)) { 		TAILQ_FOREACH_REVERSE(ccb_h, ioq, io_queue, periph_links.tqe) { 			curr_descr = (struct ctio_descr *)ccb_h->targ_descr; 			if (curr_descr->offset<= c_descr->offset) { 				TAILQ_INSERT_AFTER(ioq, ccb_h,&ctio->ccb_h, 						   periph_links.tqe); 				break; 			} 			if (TAILQ_PREV(ccb_h, io_queue, periph_links.tqe) 			    == NULL) { 				TAILQ_INSERT_BEFORE(ccb_h,&ctio->ccb_h,  						    periph_links.tqe); 				break; 			} 		} 	} else { 		TAILQ_INSERT_HEAD(ioq,&ctio->ccb_h, periph_links.tqe); 	} }
comment|/*  * Go through all completed AIO/CTIOs for a given ATIO and advance data  * counts, start continuation IO, etc.  */
argument|static void run_queue(struct ccb_accept_tio *atio) { 	struct atio_descr *a_descr; 	struct ccb_hdr *ccb_h; 	int sent_status
argument_list|,
argument|event;  	if (atio == NULL) 		return;  	a_descr = (struct atio_descr *)atio->ccb_h.targ_descr;  	while ((ccb_h = TAILQ_FIRST(&a_descr->cmplt_io)) != NULL) { 		struct ccb_scsiio *ctio; 		struct ctio_descr *c_descr;  		ctio = (struct ccb_scsiio *)ccb_h; 		c_descr = (struct ctio_descr *)ctio->ccb_h.targ_descr;  		if (ctio->ccb_h.status == CAM_REQ_ABORTED) { 			TAILQ_REMOVE(&a_descr->cmplt_io, ccb_h, 				     periph_links.tqe); 			free_ccb((union ccb *)ctio); 			send_ccb((union ccb *)atio,
comment|/*priority*/
literal|1
argument|); 			continue; 		}
comment|/* If completed item is in range, call handler */
argument|if ((c_descr->event == AIO_DONE&& 		    c_descr->offset == a_descr->base_off + a_descr->targ_ack) 		 || (c_descr->event == CTIO_DONE&& 		    c_descr->offset == a_descr->base_off + a_descr->init_ack)) { 			sent_status = (ccb_h->flags& CAM_SEND_STATUS) !=
literal|0
argument|; 			event = c_descr->event;  			TAILQ_REMOVE(&a_descr->cmplt_io, ccb_h, 				     periph_links.tqe); 			tcmd_handle(atio, ctio, c_descr->event);
comment|/* If entire transfer complete, send back ATIO */
argument|if (sent_status !=
literal|0
argument|&& event == CTIO_DONE) 				send_ccb((union ccb *)atio,
comment|/*priority*/
literal|1
argument|); 		} else {
comment|/* Gap in offsets so wait until later callback */
argument|if (debug) 				warnx(
literal|"IO %p out of order"
argument|, ccb_h); 			break; 		} 	} }  static int work_inot(struct ccb_immed_notify *inot) { 	cam_status status; 	int sense;  	if (debug) 		warnx(
literal|"Working on INOT %p"
argument|, inot);  	status = inot->ccb_h.status; 	sense = (status& CAM_AUTOSNS_VALID) !=
literal|0
argument|; 	status&= CAM_STATUS_MASK;  	switch (status) { 	case CAM_SCSI_BUS_RESET: 		tcmd_ua(CAM_TARGET_WILDCARD, UA_BUS_RESET); 		abort_all_pending(); 		break; 	case CAM_BDR_SENT: 		tcmd_ua(CAM_TARGET_WILDCARD, UA_BDR); 		abort_all_pending(); 		break; 	case CAM_MESSAGE_RECV: 		switch (inot->message_args[
literal|0
argument|]) { 		case MSG_TASK_COMPLETE: 		case MSG_INITIATOR_DET_ERR: 		case MSG_ABORT_TASK_SET: 		case MSG_MESSAGE_REJECT: 		case MSG_NOOP: 		case MSG_PARITY_ERROR: 		case MSG_TARGET_RESET: 		case MSG_ABORT_TASK: 		case MSG_CLEAR_TASK_SET: 		default: 			warnx(
literal|"INOT message %#x"
argument|, inot->message_args[
literal|0
argument|]); 			break; 		} 		break; 	case CAM_REQ_ABORTED: 		warnx(
literal|"INOT %p aborted"
argument|, inot); 		break; 	default: 		warnx(
literal|"Unhandled INOT status %#x"
argument|, status); 		break; 	}
comment|/* If there is sense data, use it */
argument|if (sense !=
literal|0
argument|) { 		struct scsi_sense_data *sense;  		sense =&inot->sense_data; 		tcmd_sense(inot->initiator_id, NULL, sense->flags, 			   sense->add_sense_code, sense->add_sense_code_qual); 		if (debug) 			warnx(
literal|"INOT has sense: %#x"
argument|, sense->flags); 	}
comment|/* Requeue on SIM */
argument|TAILQ_REMOVE(&work_queue,&inot->ccb_h, periph_links.tqe); 	send_ccb((union ccb *)inot,
comment|/*priority*/
literal|1
argument|);  	return (
literal|1
argument|); }  void send_ccb(union ccb *ccb, int priority) { 	if (debug) 		warnx(
literal|"sending ccb (%#x)"
argument|, ccb->ccb_h.func_code); 	ccb->ccb_h.pinfo.priority = priority; 	if (XPT_FC_IS_QUEUED(ccb)) { 		TAILQ_INSERT_TAIL(&pending_queue,&ccb->ccb_h, 				  periph_links.tqe); 	} 	if (write(targ_fd,&ccb, sizeof(ccb)) != sizeof(ccb)) { 		warn(
literal|"write ccb"
argument|); 		ccb->ccb_h.status = CAM_PROVIDE_FAIL; 	} }
comment|/* Return a CTIO/descr/buf combo from the freelist or malloc one */
argument|static struct ccb_scsiio * get_ctio() { 	struct ccb_scsiio *ctio; 	struct ctio_descr *c_descr; 	struct sigevent *se;  	if (num_ctios == MAX_CTIOS) 		return (NULL);  	ctio = (struct ccb_scsiio *)malloc(sizeof(*ctio)); 	if (ctio == NULL) { 		warn(
literal|"malloc CTIO"
argument|); 		return (NULL); 	} 	c_descr = (struct ctio_descr *)malloc(sizeof(*c_descr)); 	if (c_descr == NULL) { 		free(ctio); 		warn(
literal|"malloc ctio_descr"
argument|); 		return (NULL); 	} 	c_descr->buf = malloc(buf_size); 	if (c_descr->buf == NULL) { 		free(c_descr); 		free(ctio); 		warn(
literal|"malloc backing store"
argument|); 		return (NULL); 	} 	num_ctios++;
comment|/* Initialize CTIO, CTIO descr, and AIO */
argument|ctio->ccb_h.func_code = XPT_CONT_TARGET_IO; 	ctio->ccb_h.retry_count =
literal|2
argument|; 	ctio->ccb_h.timeout = CAM_TIME_INFINITY; 	ctio->data_ptr = c_descr->buf; 	ctio->ccb_h.targ_descr = c_descr; 	c_descr->aiocb.aio_buf = c_descr->buf; 	c_descr->aiocb.aio_fildes = file_fd; 	se =&c_descr->aiocb.aio_sigevent; 	se->sigev_notify = SIGEV_KEVENT; 	se->sigev_notify_kqueue = kq_fd; 	se->sigev_value.sival_ptr = ctio;  	return (ctio); }  void free_ccb(union ccb *ccb) { 	switch (ccb->ccb_h.func_code) { 	case XPT_CONT_TARGET_IO: 	{ 		struct ctio_descr *c_descr;  		c_descr = (struct ctio_descr *)ccb->ccb_h.targ_descr; 		free(c_descr->buf); 		num_ctios--;
comment|/* FALLTHROUGH */
argument|} 	case XPT_ACCEPT_TARGET_IO: 		free(ccb->ccb_h.targ_descr);
comment|/* FALLTHROUGH */
argument|case XPT_IMMED_NOTIFY: 	default: 		free(ccb); 		break; 	} }  static cam_status get_sim_flags(u_int16_t *flags) { 	struct ccb_pathinq cpi; 	cam_status status;
comment|/* Find SIM capabilities */
argument|bzero(&cpi, sizeof(cpi)); 	cpi.ccb_h.func_code = XPT_PATH_INQ; 	send_ccb((union ccb *)&cpi,
comment|/*priority*/
literal|1
argument|); 	status = cpi.ccb_h.status& CAM_STATUS_MASK; 	if (status != CAM_REQ_CMP) { 		fprintf(stderr,
literal|"CPI failed, status %#x\n"
argument|, status); 		return (status); 	}
comment|/* Can only enable on controllers that support target mode */
argument|if ((cpi.target_sprt& PIT_PROCESSOR) ==
literal|0
argument|) { 		fprintf(stderr,
literal|"HBA does not support target mode\n"
argument|); 		status = CAM_PATH_INVALID; 		return (status); 	}  	*flags = cpi.hba_inquiry; 	return (status); }  static void rel_simq() { 	struct ccb_relsim crs;  	bzero(&crs, sizeof(crs)); 	crs.ccb_h.func_code = XPT_REL_SIMQ; 	crs.release_flags = RELSIM_RELEASE_AFTER_QEMPTY; 	crs.openings =
literal|0
argument|; 	crs.release_timeout =
literal|0
argument|; 	crs.qfrozen_cnt =
literal|0
argument|; 	send_ccb((union ccb *)&crs,
comment|/*priority*/
literal|0
argument|); }
comment|/* Cancel all pending CCBs. */
argument|static void abort_all_pending() { 	struct ccb_abort	 cab; 	struct ccb_hdr		*ccb_h;  	if (debug) 		  warnx(
literal|"abort_all_pending"
argument|);  	bzero(&cab, sizeof(cab)); 	cab.ccb_h.func_code = XPT_ABORT; 	TAILQ_FOREACH(ccb_h,&pending_queue, periph_links.tqe) { 		if (debug) 			  warnx(
literal|"Aborting pending CCB %p\n"
argument|, ccb_h); 		cab.abort_ccb = (union ccb *)ccb_h; 		send_ccb((union ccb *)&cab,
comment|/*priority*/
literal|1
argument|); 		if (cab.ccb_h.status != CAM_REQ_CMP) { 			warnx(
literal|"Unable to abort CCB, status %#x\n"
argument|, 			       cab.ccb_h.status); 		} 	} }  static void usage() { 	fprintf(stderr,
literal|"Usage: scsi_target [-AdST] [-b bufsize] [-c sectorsize]\n"
literal|"\t\t[-r numbufs] [-s volsize] [-W 8,16,32]\n"
literal|"\t\tbus:target:lun filename\n"
argument|); 	exit(
literal|1
argument|); }
end_function

end_unit

