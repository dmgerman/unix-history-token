begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * audio.c - audio interface for reference clock audio drivers  */
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

begin_include
include|#
directive|include
file|"audio.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/audioio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_AUDIOIO_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SUN_AUDIOIO_H
end_ifdef

begin_include
include|#
directive|include
file|<sun/audioio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SUN_AUDIOIO_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IOCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_IOCTL_H */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/*  * Global variables  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|audio_device
name|device
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* audio device ident */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|audio_info
name|info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* audio device info */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ctl_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* audio control file descriptor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_AUDIOIO_H */
end_comment

begin_comment
comment|/*  * audio_init - open and initialize audio device  *  * This code works with SunOS 4.x and Solaris 2.x; however, it is  * believed generic and applicable to other systems with a minor twid  * or two. All it does is open the device, set the buffer size (Solaris  * only), preset the gain and set the input port. It assumes that the  * codec sample rate (8000 Hz), precision (8 bits), number of channels  * (1) and encoding (ITU-T G.711 mu-law companded) have been set by  * default.  */
end_comment

begin_function
name|int
name|audio_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|fd
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
name|int
name|rval
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_SYS_AUDIOIO_H */
comment|/* 	 * Open audio device 	 */
name|fd
operator|=
name|open
argument_list|(
literal|"/dev/audio"
argument_list|,
name|O_RDWR
operator||
name|O_NONBLOCK
argument_list|,
literal|0777
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"audio:"
argument_list|)
expr_stmt|;
return|return
operator|(
name|fd
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
comment|/* 	 * Open audio control device 	 */
name|ctl_fd
operator|=
name|open
argument_list|(
literal|"/dev/audioctl"
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|ctl_fd
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"audioctl:"
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
name|ctl_fd
operator|)
return|;
block|}
comment|/* 	 * Set audio device parameters. 	 */
name|rval
operator|=
name|audio_gain
argument_list|(
operator|(
name|AUDIO_MAX_GAIN
operator|-
name|AUDIO_MIN_GAIN
operator|)
operator|/
literal|2
argument_list|,
name|AUDIO_MICROPHONE
argument_list|)
expr_stmt|;
if|if
condition|(
name|rval
operator|<
literal|0
condition|)
block|{
name|close
argument_list|(
name|ctl_fd
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* HAVE_SYS_AUDIOIO_H */
return|return
operator|(
name|fd
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * audio_gain - adjust codec gain and port  */
end_comment

begin_function
name|int
name|audio_gain
parameter_list|(
name|int
name|gain
parameter_list|,
comment|/* gain 0-255 */
name|int
name|port
comment|/* port */
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
name|int
name|rval
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_SYS_AUDIOIO_H */
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
name|AUDIO_INITINFO
argument_list|(
operator|&
name|info
argument_list|)
expr_stmt|;
name|info
operator|.
name|record
operator|.
name|buffer_size
operator|=
name|AUDIO_BUFSIZ
expr_stmt|;
name|info
operator|.
name|record
operator|.
name|gain
operator|=
name|gain
expr_stmt|;
name|info
operator|.
name|record
operator|.
name|port
operator|=
name|port
expr_stmt|;
name|info
operator|.
name|record
operator|.
name|error
operator|=
literal|0
expr_stmt|;
name|rval
operator|=
name|ioctl
argument_list|(
name|ctl_fd
argument_list|,
operator|(
name|int
operator|)
name|AUDIO_SETINFO
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
if|if
condition|(
name|rval
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"audio:"
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
return|return
operator|(
name|info
operator|.
name|record
operator|.
name|error
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
comment|/* HAVE_SYS_AUDIOIO_H */
block|}
end_function

begin_comment
comment|/*  * audio_show - display audio parameters  *  * This code doesn't really do anything, except satisfy curiousity and  * verify the ioctl's work.  */
end_comment

begin_function
name|void
name|audio_show
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_SYS_AUDIOIO_H
name|ioctl
argument_list|(
name|ctl_fd
argument_list|,
operator|(
name|int
operator|)
name|AUDIO_GETDEV
argument_list|,
operator|&
name|device
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: name %s, version %s, config %s\n"
argument_list|,
name|device
operator|.
name|name
argument_list|,
name|device
operator|.
name|version
argument_list|,
name|device
operator|.
name|config
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|ctl_fd
argument_list|,
operator|(
name|int
operator|)
name|AUDIO_GETINFO
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: samples %d, channels %d, precision %d, encoding %d\n"
argument_list|,
name|info
operator|.
name|record
operator|.
name|sample_rate
argument_list|,
name|info
operator|.
name|record
operator|.
name|channels
argument_list|,
name|info
operator|.
name|record
operator|.
name|precision
argument_list|,
name|info
operator|.
name|record
operator|.
name|encoding
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: gain %d, port %d, buffer %d\n"
argument_list|,
name|info
operator|.
name|record
operator|.
name|gain
argument_list|,
name|info
operator|.
name|record
operator|.
name|port
argument_list|,
name|info
operator|.
name|record
operator|.
name|buffer_size
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: gain %d, port %d\n"
argument_list|,
name|info
operator|.
name|record
operator|.
name|gain
argument_list|,
name|info
operator|.
name|record
operator|.
name|port
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: samples %d, eof %d, pause %d, error %d, waiting %d, balance %d\n"
argument_list|,
name|info
operator|.
name|record
operator|.
name|samples
argument_list|,
name|info
operator|.
name|record
operator|.
name|eof
argument_list|,
name|info
operator|.
name|record
operator|.
name|pause
argument_list|,
name|info
operator|.
name|record
operator|.
name|error
argument_list|,
name|info
operator|.
name|record
operator|.
name|waiting
argument_list|,
name|info
operator|.
name|record
operator|.
name|balance
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"audio: monitor %d, muted %d\n"
argument_list|,
name|info
operator|.
name|monitor_gain
argument_list|,
name|info
operator|.
name|output_muted
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SYS_AUDIOIO_H */
ifdef|#
directive|ifdef
name|__NetBSD__
name|printf
argument_list|(
literal|"audio: monitor %d, blocksize %d, hiwat %d, lowat %d, mode %d\n"
argument_list|,
name|info
operator|.
name|monitor_gain
argument_list|,
name|info
operator|.
name|blocksize
argument_list|,
name|info
operator|.
name|hiwat
argument_list|,
name|info
operator|.
name|lowat
argument_list|,
name|info
operator|.
name|mode
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* __NetBSD__ */
block|}
end_function

end_unit

