begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Header: bsd_audioirig.h,v 1.0 93/08/02 12:42:00  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_AUDIOIRIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSD_AUDIOIRIG_H_
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/********************************************************************/
end_comment

begin_comment
comment|/* user interface */
end_comment

begin_comment
comment|/*  * irig ioctls  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ibm032
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|AUDIO_IRIG_OPEN
value|_IO('A', 50)
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_CLOSE
value|_IO('A', 51)
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_SETFORMAT
value|_IOWR('A', 52, int)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AUDIO_IRIG_OPEN
value|_IO(A, 50)
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_CLOSE
value|_IO(A, 51)
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_SETFORMAT
value|_IOWR(A, 52, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * irig error codes  */
end_comment

begin_define
define|#
directive|define
name|AUDIO_IRIG_BADSIGNAL
value|0x01
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_BADDATA
value|0x02
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_BADSYNC
value|0x04
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_BADCLOCK
value|0x08
end_define

begin_define
define|#
directive|define
name|AUDIO_IRIG_OLDDATA
value|0x10
end_define

begin_comment
comment|/********************************************************************/
end_comment

begin_comment
comment|/*  * auib definitions  */
end_comment

begin_define
define|#
directive|define
name|AUIB_SIZE
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|AUIB_INC
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|AUIB_MOD
parameter_list|(
name|k
parameter_list|)
value|((k)& 0x0038)
end_define

begin_define
define|#
directive|define
name|AUIB_INIT
parameter_list|(
name|ib
parameter_list|)
value|((ib)->ib_head = (ib)->ib_tail = (ib)->ib_lock = \ 			 (ib)->phase = (ib)->shi = (ib)->slo = (ib)->high = \ 			 (ib)->level0 = (ib)->level1 = \ 			 (ib)->shift[0] = (ib)->shift[1] = (ib)->shift[2] = \ 			 (ib)->shift[3] = (ib)->sdata[0] = (ib)->sdata[1] = \ 			 (ib)->sdata[2] = (ib)->sdata[3] = (ib)->err = 0)
end_define

begin_define
define|#
directive|define
name|AUIB_EMPTY
parameter_list|(
name|ib
parameter_list|)
value|((ib)->ib_head == (ib)->ib_tail)
end_define

begin_define
define|#
directive|define
name|AUIB_LEN
parameter_list|(
name|ib
parameter_list|)
value|(AUIB_MOD((ib)->ib_tail - (ib)->ib_head))
end_define

begin_define
define|#
directive|define
name|AUIB_LEFT
parameter_list|(
name|ib
parameter_list|)
value|(AUIB_MOD((ib)->ib_head - (ib)->ib_tail - 1))
end_define

begin_define
define|#
directive|define
name|IRIGDELAY
value|3
end_define

begin_define
define|#
directive|define
name|IRIGLEVEL
value|1355
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * irig_time holds IRIG data for one second  */
end_comment

begin_struct
struct|struct
name|irig_time
block|{
name|struct
name|timeval
name|stamp
decl_stmt|;
comment|/* timestamp */
name|u_char
name|bits
index|[
literal|13
index|]
decl_stmt|;
comment|/* 100 irig data bits */
name|u_char
name|status
decl_stmt|;
comment|/* status byte */
name|char
name|time
index|[
literal|14
index|]
decl_stmt|;
comment|/* time string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * auib's are used for IRIG data communication between the trap  * handler and the software interrupt.  */
end_comment

begin_struct
struct|struct
name|auib
block|{
comment|/* driver variables */
name|u_short
name|active
decl_stmt|;
comment|/* 0=inactive, else=active */
name|u_short
name|format
decl_stmt|;
comment|/* time output format */
name|struct
name|irig_time
name|timestr
decl_stmt|;
comment|/* time structure */
name|char
name|buffer
index|[
literal|14
index|]
decl_stmt|;
comment|/* output formation buffer */
comment|/* hardware interrupt variables */
name|struct
name|timeval
name|tv1
decl_stmt|,
name|tv2
decl_stmt|,
name|tv3
decl_stmt|;
comment|/* time stamps (median filter) */
name|int
name|level0
decl_stmt|,
name|level1
decl_stmt|;
comment|/* lo/hi input levels */
name|int
name|level
decl_stmt|;
comment|/* decision level */
name|int
name|high
decl_stmt|;
comment|/* recent largest sample */
name|int
name|sl0
decl_stmt|,
name|sl1
decl_stmt|;
comment|/* recent sample levels */
name|int
name|lasts
decl_stmt|;
comment|/* last sample value */
name|u_short
name|scount
decl_stmt|;
comment|/* sample count */
name|u_long
name|eacc
decl_stmt|;
comment|/* 10-bit element accumulator */
name|u_long
name|ebit
decl_stmt|;
comment|/* current bit in element */
name|u_char
name|r_level
decl_stmt|,
name|mmr1
decl_stmt|;
comment|/* recording level 0-255 */
name|int
name|shi
decl_stmt|,
name|slo
decl_stmt|,
name|phase
decl_stmt|;
comment|/* AGC variables */
name|u_long
name|err
decl_stmt|;
comment|/* error status bits */
name|int
name|ecount
decl_stmt|;
comment|/* count of elements this second */
name|long
name|shift
index|[
literal|4
index|]
decl_stmt|;
comment|/* shift register of pos ident */
name|long
name|sdata
index|[
literal|4
index|]
decl_stmt|;
comment|/* shift register of symbols */
name|int
name|ib_head
decl_stmt|;
comment|/* queue head */
name|int
name|ib_tail
decl_stmt|;
comment|/* queue tail */
name|u_short
name|ib_lock
decl_stmt|;
comment|/* queue head lock */
name|u_long
name|ib_data
index|[
name|AUIB_SIZE
index|]
decl_stmt|;
comment|/* data buffer */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_AUDIOIRIG_H_ */
end_comment

end_unit

