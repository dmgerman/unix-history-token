begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/********************************************************/
end_comment

begin_comment
comment|/*  map_vme.c                                           */
end_comment

begin_comment
comment|/*  VME control of TrueTime VME-SG sync gen  card       */
end_comment

begin_comment
comment|/*  and  TrueTime GPS-VME      receiver card            */
end_comment

begin_comment
comment|/* Version for 700 series HPUX 9.0                      */
end_comment

begin_comment
comment|/* Richard E.Schmidt, US Naval Observatory, Washington  */
end_comment

begin_comment
comment|/*  27 March 94                                         */
end_comment

begin_comment
comment|/********************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_GPSVME
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysmacros.h>
end_include

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_comment
comment|/* for rtprio */
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_comment
comment|/* for plock */
end_comment

begin_include
include|#
directive|include
file|"/etc/conf/machine/vme2.h"
end_include

begin_include
include|#
directive|include
file|"/etc/conf/h/io.h"
end_include

begin_include
include|#
directive|include
file|"gps.h"
end_include

begin_comment
comment|/* GLOBALS */
end_comment

begin_decl_stmt
name|void
modifier|*
name|gps_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
modifier|*
name|greg
index|[
name|NREGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vme2_map_addr
name|ma
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory mapped structure */
end_comment

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for VME */
end_comment

begin_function_decl
name|void
name|unmap_vme
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|caddr_t
name|map_vme
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|caddr_t
name|base
decl_stmt|;
name|struct
name|vme2_io_testx
name|tx
decl_stmt|;
name|caddr_t
name|cp
decl_stmt|;
define|#
directive|define
name|VME_START_ADDR
value|0x00000
comment|/* Starting address in A16N VME Space */
define|#
directive|define
name|VMESIZE
value|0xFF
comment|/* 256 bytes of A16N space length */
comment|/*  	   To create the HP9000/700 series device file, /dev/vme2: 	   mknod /dev/vme2 c 44 0x0; chmod 600 /dev/vme2  	   Then must create /etc/vme.CFG and run /etc/vme_config and reboot. 	*/
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|filename
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"ERROR: VME bus adapter open failed. errno:%d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|==
name|ENODEV
condition|)
block|{
name|printf
argument_list|(
literal|"ENODEV. Is driver in kernel? vme2 in dfile?\n"
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
name|tx
operator|.
name|card_type
operator|=
name|VME_A16
expr_stmt|;
name|tx
operator|.
name|vme_addr
operator|=
name|VME_START_ADDR
expr_stmt|;
name|tx
operator|.
name|width
operator|=
name|SHORT_WIDE
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|VME2_IO_TESTR
argument_list|,
operator|&
name|tx
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"ioctl to test VME space failed. Errno: %d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|tx
operator|.
name|error
condition|)
name|printf
argument_list|(
literal|"io_testr failed internal error %d\n"
argument_list|,
name|tx
operator|.
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|tx
operator|.
name|access_result
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"io_testr failed\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
comment|/* If successful mmap the device */
comment|/* NOW MAP THE CARD  */
name|ma
operator|.
name|card_type
operator|=
name|VME_A16
expr_stmt|;
name|ma
operator|.
name|vme_addr
operator|=
name|VME_START_ADDR
expr_stmt|;
name|ma
operator|.
name|size
operator|=
name|VMESIZE
expr_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|VME2_MAP_ADDR
argument_list|,
operator|&
name|ma
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"ioctl to map VME space failed. Errno: %d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ma
operator|.
name|error
condition|)
block|{
name|printf
argument_list|(
literal|"ioctl to map VME failed\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|ENOMEM
argument_list|)
expr_stmt|;
block|}
name|base
operator|=
name|ma
operator|.
name|user_addr
expr_stmt|;
return|return
operator|(
name|base
operator|)
return|;
block|}
end_function

begin_function
name|void
name|unmap_vme
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|VME2_UNMAP_ADDR
argument_list|,
operator|&
name|ma
argument_list|)
condition|)
name|printf
argument_list|(
literal|"ioctl to unmap VME space failed. Errno: %d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
name|int
name|init_vme
parameter_list|(
name|boid
parameter_list|)
block|{
comment|/*  set up address offsets */
name|gps_base
operator|=
name|map_vme
argument_list|(
name|GPS_VME
argument_list|)
expr_stmt|;
comment|/* offsets from base address: */
name|greg
index|[
literal|0
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GFRZ1
expr_stmt|;
name|greg
index|[
literal|1
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GUFRZ1
expr_stmt|;
name|greg
index|[
literal|2
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GREG1A
expr_stmt|;
name|greg
index|[
literal|3
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GREG1B
expr_stmt|;
name|greg
index|[
literal|4
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GREG1C
expr_stmt|;
name|greg
index|[
literal|5
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GREG1D
expr_stmt|;
name|greg
index|[
literal|6
index|]
operator|=
operator|(
name|unsigned
name|short
operator|*
operator|)
name|gps_base
operator|+
name|GREG1E
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not (REFCLOCK&& CLOCK_GPSVME) */
end_comment

begin_decl_stmt
name|int
name|map_vme_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not (REFCLOCK&& CLOCK_GPSVME) */
end_comment

end_unit

