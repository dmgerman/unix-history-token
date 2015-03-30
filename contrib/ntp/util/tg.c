begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tg.c generate WWV or IRIG signals for test  */
end_comment

begin_comment
comment|/*  * This program can generate audio signals that simulate the WWV/H  * broadcast timecode. Alternatively, it can generate the IRIG-B  * timecode commonly used to synchronize laboratory equipment. It is  * intended to test the WWV/H driver (refclock_wwv.c) and the IRIG  * driver (refclock_irig.c) in the NTP driver collection.  *  * Besides testing the drivers themselves, this program can be used to  * synchronize remote machines over audio transmission lines or program  * feeds. The program reads the time on the local machine and sets the  * initial epoch of the signal generator within one millisecond.  * Alernatively, the initial epoch can be set to an arbitrary time. This  * is useful when searching for bugs and testing for correct response to  * a leap second in UTC. Note however, the ultimate accuracy is limited  * by the intrinsic frequency error of the codec sample clock, which can  # reach well over 100 PPM.  *  * The default is to route generated signals to the line output  * jack; the s option on the command line routes these signals to the  * internal speaker as well. The v option controls the speaker volume  * over the range 0-255. The signal generator by default uses WWV  * format; the h option switches to WWVH format and the i option  * switches to IRIG-B format.  *  * Once started the program runs continuously. The default initial epoch  * for the signal generator is read from the computer system clock when  * the program starts. The y option specifies an alternate epoch using a  * string yydddhhmmss, where yy is the year of century, ddd the day of  * year, hh the hour of day and mm the minute of hour. For instance,  * 1946Z on 1 January 2006 is 060011946. The l option lights the leap  * warning bit in the WWV/H timecode, so is handy to check for correct  * behavior at the next leap second epoch. The remaining options are  * specified below under the Parse Options heading. Most of these are  * for testing.  *  * During operation the program displays the WWV/H timecode (9 digits)  * or IRIG timecode (20 digits) as each new string is constructed. The  * display is followed by the BCD binary bits as transmitted. Note that  * the transmissionorder is low-order first as the frame is processed  * left to right. For WWV/H The leap warning L preceeds the first bit.  * For IRIG the on-time marker M preceeds the first (units) bit, so its  * code is delayed one bit and the next digit (tens) needs only three  * bits.  *  * The program has been tested with the Sun Blade 1500 running Solaris  * 10, but not yet with other machines. It uses no special features and  * should be readily portable to other hardware and operating systems.  */
end_comment

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
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/audio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|SECOND
value|8000
end_define

begin_comment
comment|/* one second of 125-us samples */
end_comment

begin_define
define|#
directive|define
name|BUFLNG
value|400
end_define

begin_comment
comment|/* buffer size */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/audio"
end_define

begin_comment
comment|/* default audio device */
end_comment

begin_define
define|#
directive|define
name|WWV
value|0
end_define

begin_comment
comment|/* WWV encoder */
end_comment

begin_define
define|#
directive|define
name|IRIG
value|1
end_define

begin_comment
comment|/* IRIG-B encoder */
end_comment

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_comment
comment|/* zero amplitude */
end_comment

begin_define
define|#
directive|define
name|LOW
value|1
end_define

begin_comment
comment|/* low amplitude */
end_comment

begin_define
define|#
directive|define
name|HIGH
value|2
end_define

begin_comment
comment|/* high amplitude */
end_comment

begin_define
define|#
directive|define
name|DATA0
value|200
end_define

begin_comment
comment|/* WWV/H 0 pulse */
end_comment

begin_define
define|#
directive|define
name|DATA1
value|500
end_define

begin_comment
comment|/* WWV/H 1 pulse */
end_comment

begin_define
define|#
directive|define
name|PI
value|800
end_define

begin_comment
comment|/* WWV/H PI pulse */
end_comment

begin_define
define|#
directive|define
name|M2
value|2
end_define

begin_comment
comment|/* IRIG 0 pulse */
end_comment

begin_define
define|#
directive|define
name|M5
value|5
end_define

begin_comment
comment|/* IRIG 1 pulse */
end_comment

begin_define
define|#
directive|define
name|M8
value|8
end_define

begin_comment
comment|/* IRIG PI pulse */
end_comment

begin_comment
comment|/*  * Companded sine table amplitude 3000 units  */
end_comment

begin_decl_stmt
name|int
name|c3000
index|[]
init|=
block|{
literal|1
block|,
literal|48
block|,
literal|63
block|,
literal|70
block|,
literal|78
block|,
literal|82
block|,
literal|85
block|,
literal|89
block|,
literal|92
block|,
literal|94
block|,
comment|/* 0-9 */
literal|96
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|103
block|,
literal|103
block|,
comment|/* 10-19 */
literal|103
block|,
literal|103
block|,
literal|103
block|,
literal|103
block|,
literal|102
block|,
literal|101
block|,
literal|101
block|,
literal|100
block|,
literal|99
block|,
literal|98
block|,
comment|/* 20-29 */
literal|96
block|,
literal|94
block|,
literal|92
block|,
literal|89
block|,
literal|85
block|,
literal|82
block|,
literal|78
block|,
literal|70
block|,
literal|63
block|,
literal|48
block|,
comment|/* 30-39 */
literal|129
block|,
literal|176
block|,
literal|191
block|,
literal|198
block|,
literal|206
block|,
literal|210
block|,
literal|213
block|,
literal|217
block|,
literal|220
block|,
literal|222
block|,
comment|/* 40-49 */
literal|224
block|,
literal|226
block|,
literal|227
block|,
literal|228
block|,
literal|229
block|,
literal|229
block|,
literal|230
block|,
literal|231
block|,
literal|231
block|,
literal|231
block|,
comment|/* 50-59 */
literal|231
block|,
literal|231
block|,
literal|231
block|,
literal|231
block|,
literal|230
block|,
literal|229
block|,
literal|229
block|,
literal|228
block|,
literal|227
block|,
literal|226
block|,
comment|/* 60-69 */
literal|224
block|,
literal|222
block|,
literal|220
block|,
literal|217
block|,
literal|213
block|,
literal|210
block|,
literal|206
block|,
literal|198
block|,
literal|191
block|,
literal|176
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 70-79 */
end_comment

begin_comment
comment|/*  * Companded sine table amplitude 6000 units  */
end_comment

begin_decl_stmt
name|int
name|c6000
index|[]
init|=
block|{
literal|1
block|,
literal|63
block|,
literal|78
block|,
literal|86
block|,
literal|93
block|,
literal|98
block|,
literal|101
block|,
literal|104
block|,
literal|107
block|,
literal|110
block|,
comment|/* 0-9 */
literal|112
block|,
literal|113
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|117
block|,
literal|118
block|,
literal|118
block|,
literal|119
block|,
literal|119
block|,
comment|/* 10-19 */
literal|119
block|,
literal|119
block|,
literal|119
block|,
literal|118
block|,
literal|118
block|,
literal|117
block|,
literal|117
block|,
literal|116
block|,
literal|115
block|,
literal|113
block|,
comment|/* 20-29 */
literal|112
block|,
literal|110
block|,
literal|107
block|,
literal|104
block|,
literal|101
block|,
literal|98
block|,
literal|93
block|,
literal|86
block|,
literal|78
block|,
literal|63
block|,
comment|/* 30-39 */
literal|129
block|,
literal|191
block|,
literal|206
block|,
literal|214
block|,
literal|221
block|,
literal|226
block|,
literal|229
block|,
literal|232
block|,
literal|235
block|,
literal|238
block|,
comment|/* 40-49 */
literal|240
block|,
literal|241
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|245
block|,
literal|246
block|,
literal|246
block|,
literal|247
block|,
literal|247
block|,
comment|/* 50-59 */
literal|247
block|,
literal|247
block|,
literal|247
block|,
literal|246
block|,
literal|246
block|,
literal|245
block|,
literal|245
block|,
literal|244
block|,
literal|243
block|,
literal|241
block|,
comment|/* 60-69 */
literal|240
block|,
literal|238
block|,
literal|235
block|,
literal|232
block|,
literal|229
block|,
literal|226
block|,
literal|221
block|,
literal|214
block|,
literal|206
block|,
literal|191
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 70-79 */
end_comment

begin_comment
comment|/*  * Decoder operations at the end of each second are driven by a state  * machine. The transition matrix consists of a dispatch table indexed  * by second number. Each entry in the table contains a case switch  * number and argument.  */
end_comment

begin_struct
struct|struct
name|progx
block|{
name|int
name|sw
decl_stmt|;
comment|/* case switch number */
name|int
name|arg
decl_stmt|;
comment|/* argument */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Case switch numbers  */
end_comment

begin_define
define|#
directive|define
name|DATA
value|0
end_define

begin_comment
comment|/* send data (0, 1, PI) */
end_comment

begin_define
define|#
directive|define
name|COEF
value|1
end_define

begin_comment
comment|/* send BCD bit */
end_comment

begin_define
define|#
directive|define
name|DEC
value|2
end_define

begin_comment
comment|/* decrement to next digit */
end_comment

begin_define
define|#
directive|define
name|MIN
value|3
end_define

begin_comment
comment|/* minute pulse */
end_comment

begin_define
define|#
directive|define
name|LEAP
value|4
end_define

begin_comment
comment|/* leap warning */
end_comment

begin_define
define|#
directive|define
name|DUT1
value|5
end_define

begin_comment
comment|/* DUT1 bits */
end_comment

begin_define
define|#
directive|define
name|DST1
value|6
end_define

begin_comment
comment|/* DST1 bit */
end_comment

begin_define
define|#
directive|define
name|DST2
value|7
end_define

begin_comment
comment|/* DST2 bit */
end_comment

begin_comment
comment|/*  * WWV/H format (100-Hz, 9 digits, 1 m frame)  */
end_comment

begin_decl_stmt
name|struct
name|progx
name|progx
index|[]
init|=
block|{
block|{
name|MIN
block|,
literal|800
block|}
block|,
comment|/* 0 minute sync pulse */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 1 */
block|{
name|DST2
block|,
literal|0
block|}
block|,
comment|/* 2 DST2 */
block|{
name|LEAP
block|,
literal|0
block|}
block|,
comment|/* 3 leap warning */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 4 1 year units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 5 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 6 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 7 8 */
block|{
name|DEC
block|,
name|DATA0
block|}
block|,
comment|/* 8 */
block|{
name|DATA
block|,
name|PI
block|}
block|,
comment|/* 9 p1 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 10 1 minute units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 11 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 12 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 13 8 */
block|{
name|DEC
block|,
name|DATA0
block|}
block|,
comment|/* 14 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 15 10 minute tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 16 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 17 40 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 18 80 (not used) */
block|{
name|DEC
block|,
name|PI
block|}
block|,
comment|/* 19 p2 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 20 1 hour units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 21 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 22 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 23 8 */
block|{
name|DEC
block|,
name|DATA0
block|}
block|,
comment|/* 24 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 25 10 hour tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 26 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 27 40 (not used) */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 28 80 (not used) */
block|{
name|DEC
block|,
name|PI
block|}
block|,
comment|/* 29 p3 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 30 1 day units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 31 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 32 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 33 8 */
block|{
name|DEC
block|,
name|DATA0
block|}
block|,
comment|/* 34 not used */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 35 10 day tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 36 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 37 40 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 38 80 */
block|{
name|DEC
block|,
name|PI
block|}
block|,
comment|/* 39 p4 */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 40 100 day hundreds */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 41 200 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 42 400 (not used) */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 43 800 (not used) */
block|{
name|DEC
block|,
name|DATA0
block|}
block|,
comment|/* 44 */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 45 */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 46 */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 47 */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 48 */
block|{
name|DATA
block|,
name|PI
block|}
block|,
comment|/* 49 p5 */
block|{
name|DUT1
block|,
literal|8
block|}
block|,
comment|/* 50 DUT1 sign */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 51 10 year tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 52 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 53 40 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 54 80 */
block|{
name|DST1
block|,
literal|0
block|}
block|,
comment|/* 55 DST1 */
block|{
name|DUT1
block|,
literal|1
block|}
block|,
comment|/* 56 0.1 DUT1 fraction */
block|{
name|DUT1
block|,
literal|2
block|}
block|,
comment|/* 57 0.2 */
block|{
name|DUT1
block|,
literal|4
block|}
block|,
comment|/* 58 0.4 */
block|{
name|DATA
block|,
name|PI
block|}
block|,
comment|/* 59 p6 */
block|{
name|DATA
block|,
name|DATA0
block|}
block|,
comment|/* 60 leap */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * IRIG format except first frame (1000 Hz, 20 digits, 1 s frame)  */
end_comment

begin_decl_stmt
name|struct
name|progx
name|progy
index|[]
init|=
block|{
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 0 1 units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 1 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 2 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 3 8 */
block|{
name|DEC
block|,
name|M2
block|}
block|,
comment|/* 4 im */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 5 10 tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 6 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 7 40 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 8 80 */
block|{
name|DEC
block|,
name|M8
block|}
block|,
comment|/* 9 pi */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * IRIG format first frame (1000 Hz, 20 digits, 1 s frame)  */
end_comment

begin_decl_stmt
name|struct
name|progx
name|progz
index|[]
init|=
block|{
block|{
name|MIN
block|,
name|M8
block|}
block|,
comment|/* 0 pi (second) */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 1 1 units */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 2 2 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 3 4 */
block|{
name|COEF
block|,
literal|8
block|}
block|,
comment|/* 4 8 */
block|{
name|DEC
block|,
name|M2
block|}
block|,
comment|/* 5 im */
block|{
name|COEF
block|,
literal|1
block|}
block|,
comment|/* 6 10 tens */
block|{
name|COEF
block|,
literal|2
block|}
block|,
comment|/* 7 20 */
block|{
name|COEF
block|,
literal|4
block|}
block|,
comment|/* 8 40 */
block|{
name|DEC
block|,
name|M8
block|}
block|,
comment|/* 9 pi */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Forward declarations  */
end_comment

begin_function_decl
name|void
name|sec
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* send second */
end_comment

begin_function_decl
name|void
name|digit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* encode digit */
end_comment

begin_function_decl
name|void
name|peep
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* send cycles */
end_comment

begin_function_decl
name|void
name|delay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* delay samples */
end_comment

begin_comment
comment|/*  * Global variables  */
end_comment

begin_decl_stmt
name|char
name|buffer
index|[
name|BUFLNG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output buffer */
end_comment

begin_decl_stmt
name|int
name|bufcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer counter */
end_comment

begin_decl_stmt
name|int
name|second
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* seconds counter */
end_comment

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* audio codec file descriptor */
end_comment

begin_decl_stmt
name|int
name|tone
init|=
literal|1000
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WWV sync frequency */
end_comment

begin_decl_stmt
name|int
name|level
init|=
name|AUDIO_MAX_GAIN
operator|/
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output level */
end_comment

begin_decl_stmt
name|int
name|port
init|=
name|AUDIO_LINE_OUT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output port */
end_comment

begin_decl_stmt
name|int
name|encode
init|=
name|WWV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* encoder select */
end_comment

begin_decl_stmt
name|int
name|leap
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* leap indicator */
end_comment

begin_decl_stmt
name|int
name|dst
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* winter/summer time */
end_comment

begin_decl_stmt
name|int
name|dut1
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DUT1 correction (sign, magnitude) */
end_comment

begin_decl_stmt
name|int
name|utc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* option epoch */
end_comment

begin_comment
comment|/*  * Main program  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
comment|/* command line options */
name|char
modifier|*
modifier|*
name|argv
comment|/* poiniter to list of tokens */
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* system clock at startup */
name|audio_info_t
name|info
decl_stmt|;
comment|/* Sun audio structure */
name|struct
name|tm
modifier|*
name|tm
init|=
name|NULL
decl_stmt|;
comment|/* structure returned by gmtime */
name|char
name|device
index|[
literal|50
index|]
decl_stmt|;
comment|/* audio device */
name|char
name|code
index|[
literal|100
index|]
decl_stmt|;
comment|/* timecode */
name|int
name|rval
decl_stmt|,
name|temp
decl_stmt|,
name|arg
decl_stmt|,
name|sw
decl_stmt|,
name|ptr
decl_stmt|;
name|int
name|minute
decl_stmt|,
name|hour
decl_stmt|,
name|day
decl_stmt|,
name|year
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	 * Parse options 	 */
name|strlcpy
argument_list|(
name|device
argument_list|,
name|DEVICE
argument_list|,
sizeof|sizeof
argument_list|(
name|device
argument_list|)
argument_list|)
expr_stmt|;
name|year
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|temp
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"a:dhilsu:v:y:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|temp
condition|)
block|{
case|case
literal|'a'
case|:
comment|/* specify audio device (/dev/audio) */
name|strlcpy
argument_list|(
name|device
argument_list|,
name|optarg
argument_list|,
sizeof|sizeof
argument_list|(
name|device
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
comment|/* set DST for summer (WWV/H only) */
name|dst
operator|++
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
comment|/* select WWVH sync frequency */
name|tone
operator|=
literal|1200
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* select irig format */
name|encode
operator|=
name|IRIG
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
comment|/* set leap warning bit (WWV/H only) */
name|leap
operator|++
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* enable speaker */
name|port
operator||=
name|AUDIO_SPEAKER
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
comment|/* set DUT1 offset (-7 to +7) */
name|sscanf
argument_list|(
name|optarg
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|dut1
argument_list|)
expr_stmt|;
if|if
condition|(
name|dut1
operator|<
literal|0
condition|)
name|dut1
operator|=
name|abs
argument_list|(
name|dut1
argument_list|)
expr_stmt|;
else|else
name|dut1
operator||=
literal|0x8
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
comment|/* set output level (0-255) */
name|sscanf
argument_list|(
name|optarg
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|level
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'y'
case|:
comment|/* set initial date and time */
name|sscanf
argument_list|(
name|optarg
argument_list|,
literal|"%2d%3d%2d%2d"
argument_list|,
operator|&
name|year
argument_list|,
operator|&
name|day
argument_list|,
operator|&
name|hour
argument_list|,
operator|&
name|minute
argument_list|)
expr_stmt|;
name|utc
operator|++
expr_stmt|;
break|break;
name|defult
label|:
name|printf
argument_list|(
literal|"invalid option %c\n"
argument_list|,
name|temp
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* 	 * Open audio device and set options 	 */
name|fd
operator|=
name|open
argument_list|(
literal|"/dev/audio"
argument_list|,
name|O_WRONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"audio open %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|rval
operator|=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|AUDIO_GETINFO
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
name|printf
argument_list|(
literal|"audio control %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|info
operator|.
name|play
operator|.
name|port
operator|=
name|port
expr_stmt|;
name|info
operator|.
name|play
operator|.
name|gain
operator|=
name|level
expr_stmt|;
name|info
operator|.
name|play
operator|.
name|sample_rate
operator|=
name|SECOND
expr_stmt|;
name|info
operator|.
name|play
operator|.
name|channels
operator|=
literal|1
expr_stmt|;
name|info
operator|.
name|play
operator|.
name|precision
operator|=
literal|8
expr_stmt|;
name|info
operator|.
name|play
operator|.
name|encoding
operator|=
name|AUDIO_ENCODING_ULAW
expr_stmt|;
name|printf
argument_list|(
literal|"port %d gain %d rate %d chan %d prec %d encode %d\n"
argument_list|,
name|info
operator|.
name|play
operator|.
name|port
argument_list|,
name|info
operator|.
name|play
operator|.
name|gain
argument_list|,
name|info
operator|.
name|play
operator|.
name|sample_rate
argument_list|,
name|info
operator|.
name|play
operator|.
name|channels
argument_list|,
name|info
operator|.
name|play
operator|.
name|precision
argument_list|,
name|info
operator|.
name|play
operator|.
name|encoding
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|fd
argument_list|,
name|AUDIO_SETINFO
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
comment|/* 	 * Unless specified otherwise, read the system clock and 	 * initialize the time. 	 */
if|if
condition|(
operator|!
name|utc
condition|)
block|{
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|tm
operator|=
name|gmtime
argument_list|(
operator|&
name|tv
operator|.
name|tv_sec
argument_list|)
expr_stmt|;
name|minute
operator|=
name|tm
operator|->
name|tm_min
expr_stmt|;
name|hour
operator|=
name|tm
operator|->
name|tm_hour
expr_stmt|;
name|day
operator|=
name|tm
operator|->
name|tm_yday
operator|+
literal|1
expr_stmt|;
name|year
operator|=
name|tm
operator|->
name|tm_year
operator|%
literal|100
expr_stmt|;
name|second
operator|=
name|tm
operator|->
name|tm_sec
expr_stmt|;
comment|/* 		 * Delay the first second so the generator is accurately 		 * aligned with the system clock within one sample (125 		 * microseconds ). 		 */
name|delay
argument_list|(
name|SECOND
operator|-
name|tv
operator|.
name|tv_usec
operator|*
literal|8
operator|/
literal|1000
argument_list|)
expr_stmt|;
block|}
name|memset
argument_list|(
name|code
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|code
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|encode
condition|)
block|{
comment|/* 	 * For WWV/H and default time, carefully set the signal 	 * generator seconds number to agree with the current time. 	 */
case|case
name|WWV
case|:
name|printf
argument_list|(
literal|"year %d day %d time %02d:%02d:%02d tone %d\n"
argument_list|,
name|year
argument_list|,
name|day
argument_list|,
name|hour
argument_list|,
name|minute
argument_list|,
name|second
argument_list|,
name|tone
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|code
argument_list|,
sizeof|sizeof
argument_list|(
name|code
argument_list|)
argument_list|,
literal|"%01d%03d%02d%02d%01d"
argument_list|,
name|year
operator|/
literal|10
argument_list|,
name|day
argument_list|,
name|hour
argument_list|,
name|minute
argument_list|,
name|year
operator|%
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
name|ptr
operator|=
literal|8
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|second
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|progx
index|[
name|i
index|]
operator|.
name|sw
operator|==
name|DEC
condition|)
name|ptr
operator|--
expr_stmt|;
block|}
break|break;
comment|/* 	 * For IRIG the signal generator runs every second, so requires 	 * no additional alignment. 	 */
case|case
name|IRIG
case|:
name|printf
argument_list|(
literal|"sbs %x year %d day %d time %02d:%02d:%02d\n"
argument_list|,
literal|0
argument_list|,
name|year
argument_list|,
name|day
argument_list|,
name|hour
argument_list|,
name|minute
argument_list|,
name|second
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* 	 * Run the signal generator to generate new timecode strings 	 * once per minute for WWV/H and once per second for IRIG. 	 */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* 		 * Crank the state machine to propagate carries to the 		 * year of century. Note that we delayed up to one 		 * second for alignment after reading the time, so this 		 * is the next second. 		 */
name|second
operator|=
operator|(
name|second
operator|+
literal|1
operator|)
operator|%
literal|60
expr_stmt|;
if|if
condition|(
name|second
operator|==
literal|0
condition|)
block|{
name|minute
operator|++
expr_stmt|;
if|if
condition|(
name|minute
operator|>=
literal|60
condition|)
block|{
name|minute
operator|=
literal|0
expr_stmt|;
name|hour
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|hour
operator|>=
literal|24
condition|)
block|{
name|hour
operator|=
literal|0
expr_stmt|;
name|day
operator|++
expr_stmt|;
block|}
comment|/* 			 * At year rollover check for leap second. 			 */
if|if
condition|(
name|day
operator|>=
operator|(
name|year
operator|&
literal|0x3
condition|?
literal|366
else|:
literal|367
operator|)
condition|)
block|{
if|if
condition|(
name|leap
condition|)
block|{
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nleap!"
argument_list|)
expr_stmt|;
name|leap
operator|=
literal|0
expr_stmt|;
block|}
name|day
operator|=
literal|1
expr_stmt|;
name|year
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|encode
operator|==
name|WWV
condition|)
block|{
name|snprintf
argument_list|(
name|code
argument_list|,
sizeof|sizeof
argument_list|(
name|code
argument_list|)
argument_list|,
literal|"%01d%03d%02d%02d%01d"
argument_list|,
name|year
operator|/
literal|10
argument_list|,
name|day
argument_list|,
name|hour
argument_list|,
name|minute
argument_list|,
name|year
operator|%
literal|10
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
name|ptr
operator|=
literal|8
expr_stmt|;
block|}
block|}
if|if
condition|(
name|encode
operator|==
name|IRIG
condition|)
block|{
name|snprintf
argument_list|(
name|code
argument_list|,
sizeof|sizeof
argument_list|(
name|code
argument_list|)
argument_list|,
literal|"%04x%04d%06d%02d%02d%02d"
argument_list|,
literal|0
argument_list|,
name|year
argument_list|,
name|day
argument_list|,
name|hour
argument_list|,
name|minute
argument_list|,
name|second
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|code
argument_list|)
expr_stmt|;
name|ptr
operator|=
literal|19
expr_stmt|;
block|}
comment|/* 		 * Generate data for the second 		 */
switch|switch
condition|(
name|encode
condition|)
block|{
comment|/* 		 * The IRIG second consists of 20 BCD digits of width- 		 * modulateod pulses at 2, 5 and 8 ms and modulated 50 		 * percent on the 1000-Hz carrier. 		 */
case|case
name|IRIG
case|:
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|<
literal|10
condition|)
block|{
name|sw
operator|=
name|progz
index|[
name|i
index|]
operator|.
name|sw
expr_stmt|;
name|arg
operator|=
name|progz
index|[
name|i
index|]
operator|.
name|arg
expr_stmt|;
block|}
else|else
block|{
name|sw
operator|=
name|progy
index|[
name|i
operator|%
literal|10
index|]
operator|.
name|sw
expr_stmt|;
name|arg
operator|=
name|progy
index|[
name|i
operator|%
literal|10
index|]
operator|.
name|arg
expr_stmt|;
block|}
switch|switch
condition|(
name|sw
condition|)
block|{
case|case
name|COEF
case|:
comment|/* send BCD bit */
if|if
condition|(
name|code
index|[
name|ptr
index|]
operator|&
name|arg
condition|)
block|{
name|peep
argument_list|(
name|M5
argument_list|,
literal|1000
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
name|peep
argument_list|(
name|M5
argument_list|,
literal|1000
argument_list|,
name|LOW
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|peep
argument_list|(
name|M2
argument_list|,
literal|1000
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
name|peep
argument_list|(
name|M8
argument_list|,
literal|1000
argument_list|,
name|LOW
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|DEC
case|:
comment|/* send IM/PI bit */
name|ptr
operator|--
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|peep
argument_list|(
name|arg
argument_list|,
literal|1000
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
name|peep
argument_list|(
literal|10
operator|-
name|arg
argument_list|,
literal|1000
argument_list|,
name|LOW
argument_list|)
expr_stmt|;
break|break;
case|case
name|MIN
case|:
comment|/* send data bit */
name|peep
argument_list|(
name|arg
argument_list|,
literal|1000
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
name|peep
argument_list|(
literal|10
operator|-
name|arg
argument_list|,
literal|1000
argument_list|,
name|LOW
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"M "
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|ptr
operator|<
literal|0
condition|)
break|break;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
comment|/* 		 * The WWV/H second consists of 9 BCD digits of width- 		 * modulateod pulses 200, 500 and 800 ms at 100-Hz. 		 */
case|case
name|WWV
case|:
name|sw
operator|=
name|progx
index|[
name|second
index|]
operator|.
name|sw
expr_stmt|;
name|arg
operator|=
name|progx
index|[
name|second
index|]
operator|.
name|arg
expr_stmt|;
switch|switch
condition|(
name|sw
condition|)
block|{
case|case
name|DATA
case|:
comment|/* send data bit */
name|sec
argument_list|(
name|arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|COEF
case|:
comment|/* send BCD bit */
if|if
condition|(
name|code
index|[
name|ptr
index|]
operator|&
name|arg
condition|)
block|{
name|sec
argument_list|(
name|DATA1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"0"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|LEAP
case|:
comment|/* send leap bit */
if|if
condition|(
name|leap
condition|)
block|{
name|sec
argument_list|(
name|DATA1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  "
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|DEC
case|:
comment|/* send data bit */
name|ptr
operator|--
expr_stmt|;
name|sec
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
break|break;
case|case
name|MIN
case|:
comment|/* send minute sync */
name|peep
argument_list|(
name|arg
argument_list|,
name|tone
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
name|peep
argument_list|(
literal|1000
operator|-
name|arg
argument_list|,
name|tone
argument_list|,
name|OFF
argument_list|)
expr_stmt|;
break|break;
case|case
name|DUT1
case|:
comment|/* send DUT1 bits */
if|if
condition|(
name|dut1
operator|&
name|arg
condition|)
name|sec
argument_list|(
name|DATA1
argument_list|)
expr_stmt|;
else|else
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
break|break;
case|case
name|DST1
case|:
comment|/* send DST1 bit */
name|ptr
operator|--
expr_stmt|;
if|if
condition|(
name|dst
condition|)
name|sec
argument_list|(
name|DATA1
argument_list|)
expr_stmt|;
else|else
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
break|break;
case|case
name|DST2
case|:
comment|/* send DST2 bit */
if|if
condition|(
name|dst
condition|)
name|sec
argument_list|(
name|DATA1
argument_list|)
expr_stmt|;
else|else
name|sec
argument_list|(
name|DATA0
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/*  * Generate WWV/H 0 or 1 data pulse.  */
end_comment

begin_function
name|void
name|sec
parameter_list|(
name|int
name|code
comment|/* DATA0, DATA1, PI */
parameter_list|)
block|{
comment|/* 	 * The WWV data pulse begins with 5 ms of 1000 Hz follwed by a 	 * guard time of 25 ms. The data pulse is 170, 570 or 770 ms at 	 * 100 Hz corresponding to 0, 1 or position indicator (PI), 	 * respectively. Note the 100-Hz data pulses are transmitted 6 	 * dB below the 1000-Hz sync pulses. Originally the data pulses 	 * were transmited 10 dB below the sync pulses, but the station 	 * engineers increased that to 6 dB because the Heath GC-1000 	 * WWV/H radio clock worked much better. 	 */
name|peep
argument_list|(
literal|5
argument_list|,
name|tone
argument_list|,
name|HIGH
argument_list|)
expr_stmt|;
comment|/* send seconds tick */
name|peep
argument_list|(
literal|25
argument_list|,
name|tone
argument_list|,
name|OFF
argument_list|)
expr_stmt|;
name|peep
argument_list|(
name|code
operator|-
literal|30
argument_list|,
literal|100
argument_list|,
name|LOW
argument_list|)
expr_stmt|;
comment|/* send data */
name|peep
argument_list|(
literal|1000
operator|-
name|code
argument_list|,
literal|100
argument_list|,
name|OFF
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Generate cycles of 100 Hz or any multiple of 100 Hz.  */
end_comment

begin_function
name|void
name|peep
parameter_list|(
name|int
name|pulse
parameter_list|,
comment|/* pulse length (ms) */
name|int
name|freq
parameter_list|,
comment|/* frequency (Hz) */
name|int
name|amp
comment|/* amplitude */
parameter_list|)
block|{
name|int
name|increm
decl_stmt|;
comment|/* phase increment */
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
if|if
condition|(
name|amp
operator|==
name|OFF
operator|||
name|freq
operator|==
literal|0
condition|)
name|increm
operator|=
literal|10
expr_stmt|;
else|else
name|increm
operator|=
name|freq
operator|/
literal|100
expr_stmt|;
name|j
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|pulse
operator|*
literal|8
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|amp
condition|)
block|{
case|case
name|HIGH
case|:
name|buffer
index|[
name|bufcnt
operator|++
index|]
operator|=
operator|~
name|c6000
index|[
name|j
index|]
expr_stmt|;
break|break;
case|case
name|LOW
case|:
name|buffer
index|[
name|bufcnt
operator|++
index|]
operator|=
operator|~
name|c3000
index|[
name|j
index|]
expr_stmt|;
break|break;
default|default:
name|buffer
index|[
name|bufcnt
operator|++
index|]
operator|=
operator|~
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|bufcnt
operator|>=
name|BUFLNG
condition|)
block|{
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|BUFLNG
argument_list|)
expr_stmt|;
name|bufcnt
operator|=
literal|0
expr_stmt|;
block|}
name|j
operator|=
operator|(
name|j
operator|+
name|increm
operator|)
operator|%
literal|80
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Delay for initial phasing  */
end_comment

begin_function
name|void
name|delay
parameter_list|(
name|int
name|delay
comment|/* delay in samples */
parameter_list|)
block|{
name|int
name|samples
decl_stmt|;
comment|/* samples remaining */
name|samples
operator|=
name|delay
expr_stmt|;
name|memset
argument_list|(
name|buffer
argument_list|,
literal|0
argument_list|,
name|BUFLNG
argument_list|)
expr_stmt|;
while|while
condition|(
name|samples
operator|>=
name|BUFLNG
condition|)
block|{
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|BUFLNG
argument_list|)
expr_stmt|;
name|samples
operator|-=
name|BUFLNG
expr_stmt|;
block|}
name|write
argument_list|(
name|fd
argument_list|,
name|buffer
argument_list|,
name|samples
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

