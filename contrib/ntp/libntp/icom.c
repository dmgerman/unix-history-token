begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Program to control ICOM radios  *  * This is a ripoff of the utility routines in the ICOM software  * distribution. The only function provided is to load the radio  * frequency. All other parameters must be manually set before use.  */
end_comment

begin_include
include|#
directive|include
file|"icom.h"
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
name|HAVE_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TERMIOS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_TERMIOS_H */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Scraps  */
end_comment

begin_define
define|#
directive|define
name|BMAX
value|50
end_define

begin_comment
comment|/* max command length */
end_comment

begin_define
define|#
directive|define
name|DICOM
value|/dev/icom/
end_define

begin_comment
comment|/* ICOM port link */
end_comment

begin_comment
comment|/*  * FSA definitions  */
end_comment

begin_define
define|#
directive|define
name|S_IDLE
value|0
end_define

begin_comment
comment|/* idle */
end_comment

begin_define
define|#
directive|define
name|S_HDR
value|1
end_define

begin_comment
comment|/* header */
end_comment

begin_define
define|#
directive|define
name|S_TX
value|2
end_define

begin_comment
comment|/* address */
end_comment

begin_define
define|#
directive|define
name|S_DATA
value|3
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|S_ERROR
value|4
end_define

begin_comment
comment|/* error */
end_comment

begin_comment
comment|/*  * Local function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|doublefreq
name|P
argument_list|(
operator|(
name|double
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|sndpkt
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|sndoctet
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|rcvoctet
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local variables  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace flags */
end_comment

begin_decl_stmt
specifier|static
name|int
name|state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fsa state */
end_comment

begin_comment
comment|/*  * icom_freq(fd, ident, freq) - load radio frequency  */
end_comment

begin_function
name|int
name|icom_freq
parameter_list|(
comment|/* returns 0 (ok), EIO (error) */
name|int
name|fd
parameter_list|,
comment|/* file descriptor */
name|int
name|ident
parameter_list|,
comment|/* ICOM radio identifier */
name|double
name|freq
comment|/* frequency (MHz) */
parameter_list|)
block|{
name|u_char
name|cmd
index|[
name|BMAX
index|]
decl_stmt|,
name|rsp
index|[
name|BMAX
index|]
decl_stmt|;
name|int
name|temp
decl_stmt|;
name|cmd
index|[
literal|0
index|]
operator|=
name|V_SFREQ
expr_stmt|;
if|if
condition|(
name|ident
operator|==
name|IC735
condition|)
name|temp
operator|=
literal|4
expr_stmt|;
else|else
name|temp
operator|=
literal|5
expr_stmt|;
name|doublefreq
argument_list|(
name|freq
operator|*
literal|1e6
argument_list|,
operator|&
name|cmd
index|[
literal|1
index|]
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|temp
operator|=
name|sndpkt
argument_list|(
name|fd
argument_list|,
name|ident
argument_list|,
name|cmd
argument_list|,
name|rsp
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|<
literal|1
operator|||
name|rsp
index|[
literal|0
index|]
operator|!=
name|ACK
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * doublefreq(freq, y, len) - double to ICOM frequency with padding  */
end_comment

begin_function
specifier|static
name|void
name|doublefreq
parameter_list|(
comment|/* returns void */
name|double
name|freq
parameter_list|,
comment|/* frequency */
name|u_char
modifier|*
name|x
parameter_list|,
comment|/* radio frequency */
name|int
name|len
comment|/* length (octets) */
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|char
name|s1
index|[
literal|11
index|]
decl_stmt|;
name|char
modifier|*
name|y
decl_stmt|;
name|sprintf
argument_list|(
name|s1
argument_list|,
literal|" %10.0f"
argument_list|,
name|freq
argument_list|)
expr_stmt|;
name|y
operator|=
name|s1
operator|+
literal|10
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|y
operator|!=
literal|' '
condition|)
block|{
name|x
index|[
name|i
index|]
operator|=
operator|*
name|y
operator|--
operator|&
literal|0x0f
expr_stmt|;
name|x
index|[
name|i
index|]
operator|=
name|x
index|[
name|i
index|]
operator||
operator|(
operator|(
operator|*
name|y
operator|--
operator|&
literal|0x0f
operator|)
operator|<<
literal|4
operator|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
for|for
control|(
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
name|x
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|x
index|[
name|i
index|]
operator|=
name|FI
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Packet routines  *  * These routines send a packet and receive the response. If an error  * (collision) occurs on transmit, the packet is resent. If an error  * occurs on receive (timeout), all input to the terminating FI is  * discarded and the packet is resent. If the maximum number of retries  * is not exceeded, the program returns the number of octets in the user  * buffer; otherwise, it returns zero.  *  * ICOM frame format  *  * Frames begin with a two-octet preamble PR-PR followyd by the  * transceiver address RE, controller address TX, control code CN, zero  * or more data octets DA (depending on command), and terminator FI.  * Since the bus is bidirectional, every octet output is echoed on  * input. Every valid frame sent is answered with a frame in the same  * format, but with the RE and TX fields interchanged. The CN field is  * set to NAK if an error has occurred. Otherwise, the data are returned  * in this and following DA octets. If no data are returned, the CN  * octet is set to ACK.  *  *	+------+------+------+------+------+--//--+------+  *	|  PR  |  PR  |  RE  |  TX  |  CN  |  DA  |  FI  |  *	+------+------+------+------+------+--//--+------+  */
end_comment

begin_comment
comment|/*  * icom_open() - open and initialize serial interface  *  * This routine opens the serial interface for raw transmission; that  * is, character-at-a-time, no stripping, checking or monkeying with the  * bits. For Unix, an input operation ends either with the receipt of a  * character or a 0.5-s timeout.  */
end_comment

begin_function
name|int
name|icom_init
parameter_list|(
name|char
modifier|*
name|device
parameter_list|,
comment|/* device name/link */
name|int
name|speed
parameter_list|,
comment|/* line speed */
name|int
name|trace
comment|/* trace flags */
parameter_list|)
block|{
name|struct
name|termios
name|ttyb
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|flags
operator|=
name|trace
expr_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|device
argument_list|,
name|O_RDWR
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
return|return
operator|(
name|fd
operator|)
return|;
name|tcgetattr
argument_list|(
name|fd
argument_list|,
operator|&
name|ttyb
argument_list|)
expr_stmt|;
name|ttyb
operator|.
name|c_iflag
operator|=
literal|0
expr_stmt|;
comment|/* input modes */
name|ttyb
operator|.
name|c_oflag
operator|=
literal|0
expr_stmt|;
comment|/* output modes */
name|ttyb
operator|.
name|c_cflag
operator|=
name|IBAUD
operator||
name|CS8
operator||
name|CREAD
operator||
name|CLOCAL
expr_stmt|;
comment|/* control modes */
name|ttyb
operator|.
name|c_lflag
operator|=
literal|0
expr_stmt|;
comment|/* local modes */
name|ttyb
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|0
expr_stmt|;
comment|/* min chars */
name|ttyb
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|5
expr_stmt|;
comment|/* receive timeout */
name|cfsetispeed
argument_list|(
operator|&
name|ttyb
argument_list|,
operator|(
name|u_int
operator|)
name|speed
argument_list|)
expr_stmt|;
name|cfsetospeed
argument_list|(
operator|&
name|ttyb
argument_list|,
operator|(
name|u_int
operator|)
name|speed
argument_list|)
expr_stmt|;
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSANOW
argument_list|,
operator|&
name|ttyb
argument_list|)
expr_stmt|;
return|return
operator|(
name|fd
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * sndpkt(r, x, y) - send packet and receive response  *  * This routine sends a command frame, which consists of all except the  * preamble octets PR-PR. It then listens for the response frame and  * returns the payload to the caller. The routine checks for correct  * response header format; that is, the length of the response vector  * returned to the caller must be at least 2 and the RE and TX octets  * must be interchanged; otherwise, the operation is retried up to  * the number of times specified in a global variable.  *  * The trace function, which is enabled by the P_TRACE bit of the global  * flags variable, prints all characters received or echoed on the bus  * preceded by a T (transmit) or R (receive). The P_ERMSG bit of the  * flags variable enables printing of bus error messages.  *  * Note that the first octet sent is a PAD in order to allow time for  * the radio to flush its receive buffer after sending the previous  * response. Even with this precaution, some of the older radios  * occasionally fail to receive a command and it has to be sent again.  */
end_comment

begin_function
specifier|static
name|int
name|sndpkt
parameter_list|(
comment|/* returns octet count */
name|int
name|fd
parameter_list|,
comment|/* file descriptor */
name|int
name|r
parameter_list|,
comment|/* radio address */
name|u_char
modifier|*
name|cmd
parameter_list|,
comment|/* command vector */
name|u_char
modifier|*
name|rsp
comment|/* response vector */
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|temp
decl_stmt|;
operator|(
name|void
operator|)
name|tcflush
argument_list|(
name|fd
argument_list|,
name|TCIOFLUSH
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|RETRY
condition|;
name|i
operator|++
control|)
block|{
name|state
operator|=
name|S_IDLE
expr_stmt|;
comment|/* 		 * Transmit packet. 		 */
if|if
condition|(
name|flags
operator|&
name|P_TRACE
condition|)
name|printf
argument_list|(
literal|"icom T:"
argument_list|)
expr_stmt|;
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|PAD
argument_list|)
expr_stmt|;
comment|/* send header */
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|PR
argument_list|)
expr_stmt|;
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|PR
argument_list|)
expr_stmt|;
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|r
argument_list|)
expr_stmt|;
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|TX
argument_list|)
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|BMAX
condition|;
name|j
operator|++
control|)
block|{
comment|/* send body */
if|if
condition|(
name|sndoctet
argument_list|(
name|fd
argument_list|,
name|cmd
index|[
name|j
index|]
argument_list|)
operator|==
name|FI
condition|)
break|break;
block|}
while|while
condition|(
name|rcvoctet
argument_list|(
name|fd
argument_list|)
operator|!=
name|FI
condition|)
empty_stmt|;
comment|/* purge echos */
if|if
condition|(
name|cmd
index|[
literal|0
index|]
operator|==
name|V_FREQT
operator|||
name|cmd
index|[
literal|0
index|]
operator|==
name|V_MODET
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* shortcut for broadcast */
comment|/* 		 * Receive packet. First, delete all characters 		 * preceeding a PR, then discard all PRs. Check that the 		 * RE and TX fields are correctly interchanged, then 		 * copy the remaining data and FI to the user buffer. 		 */
if|if
condition|(
name|flags
operator|&
name|P_TRACE
condition|)
name|printf
argument_list|(
literal|"\nicom R:"
argument_list|)
expr_stmt|;
name|j
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|temp
operator|=
name|rcvoctet
argument_list|(
name|fd
argument_list|)
operator|)
operator|!=
name|FI
condition|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|S_IDLE
case|:
if|if
condition|(
name|temp
operator|!=
name|PR
condition|)
continue|continue;
name|state
operator|=
name|S_HDR
expr_stmt|;
break|break;
case|case
name|S_HDR
case|:
if|if
condition|(
name|temp
operator|==
name|PR
condition|)
block|{
continue|continue;
block|}
elseif|else
if|if
condition|(
name|temp
operator|!=
name|TX
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|P_ERMSG
condition|)
name|printf
argument_list|(
literal|"icom: TX error\n"
argument_list|)
expr_stmt|;
name|state
operator|=
name|S_ERROR
expr_stmt|;
block|}
name|state
operator|=
name|S_TX
expr_stmt|;
break|break;
case|case
name|S_TX
case|:
if|if
condition|(
name|temp
operator|!=
name|r
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|P_ERMSG
condition|)
name|printf
argument_list|(
literal|"icom: RE error\n"
argument_list|)
expr_stmt|;
name|state
operator|=
name|S_ERROR
expr_stmt|;
block|}
name|state
operator|=
name|S_DATA
expr_stmt|;
break|break;
case|case
name|S_DATA
case|:
if|if
condition|(
name|j
operator|>=
name|BMAX
condition|)
block|{
if|if
condition|(
name|flags
operator|&
name|P_ERMSG
condition|)
name|printf
argument_list|(
literal|"icom: buffer overrun\n"
argument_list|)
expr_stmt|;
name|state
operator|=
name|S_ERROR
expr_stmt|;
name|j
operator|=
literal|0
expr_stmt|;
block|}
name|rsp
index|[
name|j
operator|++
index|]
operator|=
operator|(
name|u_char
operator|)
name|temp
expr_stmt|;
break|break;
case|case
name|S_ERROR
case|:
break|break;
block|}
block|}
if|if
condition|(
name|flags
operator|&
name|P_TRACE
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|j
operator|>
literal|0
condition|)
block|{
name|rsp
index|[
name|j
operator|++
index|]
operator|=
name|FI
expr_stmt|;
return|return
operator|(
name|j
operator|)
return|;
block|}
block|}
if|if
condition|(
name|flags
operator|&
name|P_ERMSG
condition|)
name|printf
argument_list|(
literal|"icom: retries exceeded\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Interface routines  *  * These routines read and write octets on the bus. In case of receive  * timeout a FI code is returned. In case of output collision (echo  * does not match octet sent), the remainder of the collision frame  * (including the trailing FI) is discarded.  */
end_comment

begin_comment
comment|/*  * sndoctet(fd, x) - send octet  */
end_comment

begin_function
specifier|static
name|int
name|sndoctet
parameter_list|(
comment|/* returns octet */
name|int
name|fd
parameter_list|,
comment|/* file descriptor */
name|int
name|x
comment|/* octet */
parameter_list|)
block|{
name|u_char
name|y
decl_stmt|;
name|y
operator|=
operator|(
name|u_char
operator|)
name|x
expr_stmt|;
name|write
argument_list|(
name|fd
argument_list|,
operator|&
name|y
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * rcvoctet(fd) - receive octet  */
end_comment

begin_function
specifier|static
name|int
name|rcvoctet
parameter_list|(
comment|/* returns octet */
name|int
name|fd
comment|/* file descriptor */
parameter_list|)
block|{
name|u_char
name|y
decl_stmt|;
if|if
condition|(
name|read
argument_list|(
name|fd
argument_list|,
operator|&
name|y
argument_list|,
literal|1
argument_list|)
operator|<
literal|1
condition|)
name|y
operator|=
name|FI
expr_stmt|;
comment|/* come here if timeout */
if|if
condition|(
name|flags
operator|&
name|P_TRACE
operator|&&
name|y
operator|!=
name|PAD
condition|)
name|printf
argument_list|(
literal|" %02x"
argument_list|,
name|y
argument_list|)
expr_stmt|;
return|return
operator|(
name|y
operator|)
return|;
block|}
end_function

begin_comment
comment|/* end program */
end_comment

end_unit

