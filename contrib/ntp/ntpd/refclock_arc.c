begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_arc - clock driver for ARCRON MSF receivers  */
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
name|CLOCK_ARCRON_MSF
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|arc_version
index|[]
init|=
block|{
literal|"V1.1 1997/06/23"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|ARCRON_DEBUG
end_undef

begin_comment
comment|/* Define only while in development... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCRON_NOT_KEEN
end_ifndef

begin_define
define|#
directive|define
name|ARCRON_KEEN
value|1
end_define

begin_comment
comment|/* Be keen, and trusting of the clock, if defined. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCRON_NOT_MULTIPLE_SAMPLES
end_ifndef

begin_define
define|#
directive|define
name|ARCRON_MULTIPLE_SAMPLES
value|1
end_define

begin_comment
comment|/* Use all timestamp bytes as samples. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCRON_NOT_LEAPSECOND_KEEN
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ARCRON_LEAPSECOND_KEEN
end_ifndef

begin_undef
undef|#
directive|undef
name|ARCRON_LEAPSECOND_KEEN
end_undef

begin_comment
comment|/* Respond quickly to leap seconds: doesn't work yet. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Code by Derek Mulcahy,<derek@toybox.demon.co.uk>, 1997. Modifications by Damon Hart-Davis,<d@hd.org>, 1997.  THIS CODE IS SUPPLIED AS IS, WITH NO WARRANTY OF ANY KIND.  USE AT YOUR OWN RISK.  Orginally developed and used with ntp3-5.85 by Derek Mulcahy.  Built against ntp3-5.90 on Solaris 2.5 using gcc 2.7.2.  This code may be freely copied and used and incorporated in other systems providing the disclaimer and notice of authorship are reproduced.  -------------------------------------------------------------------------------  Author's original note:  I enclose my ntp driver for the Galleon Systems Arc MSF receiver.  It works (after a fashion) on both Solaris-1 and Solaris-2.  I am currently using ntp3-5.85.  I have been running the code for about 7 months without any problems.  Even coped with the change to BST!  I had to do some funky things to read from the clock because it uses the power from the receive lines to drive the transmit lines.  This makes the code look a bit stupid but it works.  I also had to put in some delays to allow for the turnaround time from receive to transmit.  These delays are between characters when requesting a time stamp so that shouldn't affect the results too drastically.  ...  The bottom line is that it works but could easily be improved.  You are free to do what you will with the code.  I haven't been able to determine how good the clock is.  I think that this requires a known good clock to compare it against.  -------------------------------------------------------------------------------  Damon's notes for adjustments:  MAJOR CHANGES SINCE V1.0 ========================  1) Removal of pollcnt variable that made the clock go permanently     off-line once two time polls failed to gain responses.   2) Avoiding (at least on Solaris-2) terminal becoming the controlling     terminal of the process when we do a low-level open().   3) Additional logic (conditional on ARCRON_LEAPSECOND_KEEN being     defined) to try to resync quickly after a potential leap-second     insertion or deletion.   4) Code significantly slimmer at run-time than V1.0.   GENERAL =======   1) The C preprocessor symbol to have the clock built has been changed     from ARC to ARCRON_MSF to CLOCK_ARCRON_MSF to minimise the     possiblity of clashes with other symbols in the future.   2) PRECISION should be -4/-5 (63ms/31ms) for the following reasons:       a) The ARC documentation claims the internal clock is (only)         accurate to about 20ms relative to Rugby (plus there must be         noticable drift and delay in the ms range due to transmission         delays and changing atmospheric effects).  This clock is not         designed for ms accuracy as NTP has spoilt us all to expect.       b) The clock oscillator looks like a simple uncompensated quartz         crystal of the sort used in digital watches (ie 32768Hz) which         can have large temperature coefficients and drifts; it is not         clear if this oscillator is properly disciplined to the MSF         transmission, but as the default is to resync only once per         *day*, we can imagine that it is not, and is free-running.  We         can minimise drift by resyncing more often (at the cost of         reduced battery life), but drift/wander may still be         significant.       c) Note that the bit time of 3.3ms adds to the potential error in         the the clock timestamp, since the bit clock of the serial link         may effectively be free-running with respect to the host clock         and the MSF clock.  Actually, the error is probably 1/16th of         the above, since the input data is probably sampled at at least         16x the bit rate.      By keeping the clock marked as not very precise, it will have a     fairly large dispersion, and thus will tend to be used as a     `backup' time source and sanity checker, which this clock is     probably ideal for.  For an isolated network without other time     sources, this clock can probably be expected to provide *much*     better than 1s accuracy, which will be fine.      By default, PRECISION is set to -4, but experience, especially at a     particular geographic location with a particular clock, may allow     this to be altered to -5.  (Note that skews of +/- 10ms are to be     expected from the clock from time-to-time.)  This improvement of     reported precision can be instigated by setting flag3 to 1, though     the PRECISION will revert to the normal value while the clock     signal quality is unknown whatever the flag3 setting.      IN ANY CASE, BE SURE TO SET AN APPROPRIATE FUDGE FACTOR TO REMOVE     ANY RESIDUAL SKEW, eg:          server 127.127.27.0 # ARCRON MSF radio clock unit 0.         # Fudge timestamps by about 20ms.         fudge 127.127.27.0 time1 0.020      You will need to observe your system's behaviour, assuming you have     some other NTP source to compare it with, to work out what the     fudge factor should be.  For my Sun SS1 running SunOS 4.1.3_U1 with     my MSF clock with my distance from the MSF transmitter, +20ms     seemed about right, after some observation.   3) REFID has been made "MSFa" to reflect the MSF time source and the     ARCRON receiver.   4) DEFAULT_RESYNC_TIME is the time in seconds (by default) before     forcing a resync since the last attempt.  This is picked to give a     little less than an hour between resyncs and to try to avoid     clashing with any regular event at a regular time-past-the-hour     which might cause systematic errors.      The INITIAL_RESYNC_DELAY is to avoid bothering the clock and     running down its batteries unnecesarily if ntpd is going to crash     or be killed or reconfigured quickly.  If ARCRON_KEEN is defined     then this period is long enough for (with normal polling rates)     enough time samples to have been taken to allow ntpd to sync to     the clock before the interruption for the clock to resync to MSF.     This avoids ntpd syncing to another peer first and then     almost immediately hopping to the MSF clock.      The RETRY_RESYNC_TIME is used before rescheduling a resync after a     resync failed to reveal a statisfatory signal quality (too low or     unknown).   5) The clock seems quite jittery, so I have increased the     median-filter size from the typical (previous) value of 3.  I     discard up to half the results in the filter.  It looks like maybe     1 sample in 10 or so (maybe less) is a spike, so allow the median     filter to discard at least 10% of its entries or 1 entry, whichever     is greater.   6) Sleeping *before* each character sent to the unit to allow required     inter-character time but without introducting jitter and delay in     handling the response if possible.   7) If the flag ARCRON_KEEN is defined, take time samples whenever     possible, even while resyncing, etc.  We rely, in this case, on the     clock always giving us a reasonable time or else telling us in the     status byte at the end of the timestamp that it failed to sync to     MSF---thus we should never end up syncing to completely the wrong     time.   8) If the flag ARCRON_OWN_FILTER is defined, use own versions of     refclock median-filter routines to get round small bug in 3-5.90     code which does not return the median offset. XXX Removed this     bit due NTP Version 4 upgrade - dlm.   9) We would appear to have a year-2000 problem with this clock since     it returns only the two least-significant digits of the year.  But     ntpd ignores the year and uses the local-system year instead, so     this is in fact not a problem.  Nevertheless, we attempt to do a     sensible thing with the dates, wrapping them into a 100-year     window.   10)Logs stats information that can be used by Derek's Tcl/Tk utility     to show the status of the clock.   11)The clock documentation insists that the number of bits per     character to be sent to the clock, and sent by it, is 11, including     one start bit and two stop bits.  The data format is either 7+even     or 8+none.   TO-DO LIST ==========    * Eliminate use of scanf(), and maybe sprintf().    * Allow user setting of resync interval to trade battery life for     accuracy; maybe could be done via fudge factor or unit number.    * Possibly note the time since the last resync of the MSF clock to     MSF as the age of the last reference timestamp, ie trust the     clock's oscillator not very much...    * Add very slow auto-adjustment up to a value of +/- time2 to correct     for long-term errors in the clock value (time2 defaults to 0 so the     correction would be disabled by default).    * Consider trying to use the tty_clk/ppsclock support.    * Possibly use average or maximum signal quality reported during     resync, rather than just the last one, which may be atypical.  */
end_comment

begin_comment
comment|/* Notes for HKW Elektronik GmBH Radio clock driver */
end_comment

begin_comment
comment|/* Author Lyndon David, Sentinet Ltd, Feb 1997      */
end_comment

begin_comment
comment|/* These notes seem also to apply usefully to the ARCRON clock. */
end_comment

begin_comment
comment|/* The HKW clock module is a radio receiver tuned into the Rugby */
end_comment

begin_comment
comment|/* MSF time signal tranmitted on 60 kHz. The clock module connects */
end_comment

begin_comment
comment|/* to the computer via a serial line and transmits the time encoded */
end_comment

begin_comment
comment|/* in 15 bytes at 300 baud 7 bits two stop bits even parity */
end_comment

begin_comment
comment|/* Clock communications, from the datasheet */
end_comment

begin_comment
comment|/* All characters sent to the clock are echoed back to the controlling */
end_comment

begin_comment
comment|/* device. */
end_comment

begin_comment
comment|/* Transmit time/date information */
end_comment

begin_comment
comment|/* syntax ASCII o<cr> */
end_comment

begin_comment
comment|/* Character o may be replaced if neccesary by a character whose code */
end_comment

begin_comment
comment|/* contains the lowest four bits f(hex) eg */
end_comment

begin_comment
comment|/* syntax binary: xxxx1111 00001101 */
end_comment

begin_comment
comment|/* DHD note: You have to wait for character echo + 10ms before sending next character. */
end_comment

begin_comment
comment|/* The clock replies to this command with a sequence of 15 characters */
end_comment

begin_comment
comment|/* which contain the complete time and a final<cr> making 16 characters */
end_comment

begin_comment
comment|/* in total. */
end_comment

begin_comment
comment|/* The RC computer clock will not reply immediately to this command because */
end_comment

begin_comment
comment|/* the start bit edge of the first reply character marks the beginning of */
end_comment

begin_comment
comment|/* the second. So the RC Computer Clock will reply to this command at the */
end_comment

begin_comment
comment|/* start of the next second */
end_comment

begin_comment
comment|/* The characters have the following meaning */
end_comment

begin_comment
comment|/* 1. hours tens   */
end_comment

begin_comment
comment|/* 2. hours units  */
end_comment

begin_comment
comment|/* 3. minutes tens */
end_comment

begin_comment
comment|/* 4. minutes units */
end_comment

begin_comment
comment|/* 5. seconds tens  */
end_comment

begin_comment
comment|/* 6. seconds units */
end_comment

begin_comment
comment|/* 7. day of week 1-monday 7-sunday */
end_comment

begin_comment
comment|/* 8. day of month tens */
end_comment

begin_comment
comment|/* 9. day of month units */
end_comment

begin_comment
comment|/* 10. month tens */
end_comment

begin_comment
comment|/* 11. month units */
end_comment

begin_comment
comment|/* 12. year tens */
end_comment

begin_comment
comment|/* 13. year units */
end_comment

begin_comment
comment|/* 14. BST/UTC status */
end_comment

begin_comment
comment|/*      bit 7   parity */
end_comment

begin_comment
comment|/*      bit 6   always 0 */
end_comment

begin_comment
comment|/*      bit 5   always 1 */
end_comment

begin_comment
comment|/*      bit 4   always 1 */
end_comment

begin_comment
comment|/*      bit 3   always 0 */
end_comment

begin_comment
comment|/*      bit 2   =1 if UTC is in effect, complementary to the BST bit */
end_comment

begin_comment
comment|/*      bit 1   =1 if BST is in effect, according to the BST bit     */
end_comment

begin_comment
comment|/*      bit 0   BST/UTC change impending bit=1 in case of change impending */
end_comment

begin_comment
comment|/* 15. status */
end_comment

begin_comment
comment|/*      bit 7   parity */
end_comment

begin_comment
comment|/*      bit 6   always 0 */
end_comment

begin_comment
comment|/*      bit 5   always 1 */
end_comment

begin_comment
comment|/*      bit 4   always 1 */
end_comment

begin_comment
comment|/*      bit 3   =1 if low battery is detected */
end_comment

begin_comment
comment|/*      bit 2   =1 if the very last reception attempt failed and a valid */
end_comment

begin_comment
comment|/*              time information already exists (bit0=1) */
end_comment

begin_comment
comment|/*              =0 if the last reception attempt was successful */
end_comment

begin_comment
comment|/*      bit 1   =1 if at least one reception since 2:30 am was successful */
end_comment

begin_comment
comment|/*              =0 if no reception attempt since 2:30 am was successful */
end_comment

begin_comment
comment|/*      bit 0   =1 if the RC Computer Clock contains valid time information */
end_comment

begin_comment
comment|/*              This bit is zero after reset and one after the first */
end_comment

begin_comment
comment|/*              successful reception attempt */
end_comment

begin_comment
comment|/* DHD note: Also note g<cr> command which confirms that a resync is in progress, and if so what signal quality (0--5) is available. Also note h<cr> command which starts a resync to MSF signal. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSV_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/*  * This driver supports the ARCRON MSF Radio Controlled Clock  */
end_comment

begin_comment
comment|/*  * Interface definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/arc%d"
end_define

begin_comment
comment|/* Device name and unit. */
end_comment

begin_define
define|#
directive|define
name|SPEED
value|B300
end_define

begin_comment
comment|/* UART speed (300 baud) */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-4)
end_define

begin_comment
comment|/* Precision  (~63 ms). */
end_comment

begin_define
define|#
directive|define
name|HIGHPRECISION
value|(-5)
end_define

begin_comment
comment|/* If things are going well... */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"MSFa"
end_define

begin_comment
comment|/* Reference ID. */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"ARCRON MSF Receiver"
end_define

begin_define
define|#
directive|define
name|NSAMPLESLONG
value|8
end_define

begin_comment
comment|/* Stages of long filter. */
end_comment

begin_define
define|#
directive|define
name|LENARC
value|16
end_define

begin_comment
comment|/* Format `o' timecode length. */
end_comment

begin_define
define|#
directive|define
name|BITSPERCHAR
value|11
end_define

begin_comment
comment|/* Bits per character. */
end_comment

begin_define
define|#
directive|define
name|BITTIME
value|0x0DA740E
end_define

begin_comment
comment|/* Time for 1 bit at 300bps. */
end_comment

begin_define
define|#
directive|define
name|CHARTIME10
value|0x8888888
end_define

begin_comment
comment|/* Time for 10-bit char at 300bps. */
end_comment

begin_define
define|#
directive|define
name|CHARTIME11
value|0x962FC96
end_define

begin_comment
comment|/* Time for 11-bit char at 300bps. */
end_comment

begin_define
define|#
directive|define
name|CHARTIME
comment|/* Time for char at 300bps. */
define|\
value|( (BITSPERCHAR == 11) ? CHARTIME11 : ( (BITSPERCHAR == 10) ? CHARTIME10 : \ 				       (BITSPERCHAR * BITTIME) ) )
end_define

begin_comment
comment|/* Allow for UART to accept char half-way through final stop bit. */
end_comment

begin_define
define|#
directive|define
name|INITIALOFFSET
value|(u_int32)(-BITTIME/2)
end_define

begin_comment
comment|/*     charoffsets[x] is the time after the start of the second that byte     x (with the first byte being byte 1) is received by the UART,     assuming that the initial edge of the start bit of the first byte     is on-time.  The values are represented as the fractional part of     an l_fp.      We store enough values to have the offset of each byte including     the trailing \r, on the assumption that the bytes follow one     another without gaps.     */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u_int32
name|charoffsets
index|[
name|LENARC
operator|+
literal|1
index|]
init|=
block|{
if|#
directive|if
name|BITSPERCHAR
operator|==
literal|11
comment|/* Usual case. */
comment|/* Offsets computed as accurately as possible... */
literal|0
block|,
name|INITIALOFFSET
operator|+
literal|0x0962fc96
block|,
comment|/*  1 chars,  11 bits */
name|INITIALOFFSET
operator|+
literal|0x12c5f92c
block|,
comment|/*  2 chars,  22 bits */
name|INITIALOFFSET
operator|+
literal|0x1c28f5c3
block|,
comment|/*  3 chars,  33 bits */
name|INITIALOFFSET
operator|+
literal|0x258bf259
block|,
comment|/*  4 chars,  44 bits */
name|INITIALOFFSET
operator|+
literal|0x2eeeeeef
block|,
comment|/*  5 chars,  55 bits */
name|INITIALOFFSET
operator|+
literal|0x3851eb85
block|,
comment|/*  6 chars,  66 bits */
name|INITIALOFFSET
operator|+
literal|0x41b4e81b
block|,
comment|/*  7 chars,  77 bits */
name|INITIALOFFSET
operator|+
literal|0x4b17e4b1
block|,
comment|/*  8 chars,  88 bits */
name|INITIALOFFSET
operator|+
literal|0x547ae148
block|,
comment|/*  9 chars,  99 bits */
name|INITIALOFFSET
operator|+
literal|0x5dddddde
block|,
comment|/* 10 chars, 110 bits */
name|INITIALOFFSET
operator|+
literal|0x6740da74
block|,
comment|/* 11 chars, 121 bits */
name|INITIALOFFSET
operator|+
literal|0x70a3d70a
block|,
comment|/* 12 chars, 132 bits */
name|INITIALOFFSET
operator|+
literal|0x7a06d3a0
block|,
comment|/* 13 chars, 143 bits */
name|INITIALOFFSET
operator|+
literal|0x8369d037
block|,
comment|/* 14 chars, 154 bits */
name|INITIALOFFSET
operator|+
literal|0x8ccccccd
block|,
comment|/* 15 chars, 165 bits */
name|INITIALOFFSET
operator|+
literal|0x962fc963
comment|/* 16 chars, 176 bits */
else|#
directive|else
comment|/* Offsets computed with a small rounding error... */
literal|0
block|,
name|INITIALOFFSET
operator|+
literal|1
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|2
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|3
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|4
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|5
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|6
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|7
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|8
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|9
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|10
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|11
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|12
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|13
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|14
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|15
operator|*
name|CHARTIME
block|,
name|INITIALOFFSET
operator|+
literal|16
operator|*
name|CHARTIME
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chose filter length dependent on fudge flag 4. */
end_comment

begin_define
define|#
directive|define
name|CHOSENSAMPLES
parameter_list|(
name|pp
parameter_list|)
define|\
value|(((pp)->sloppyclockflag& CLK_FLAG4) ? NSAMPLESLONG : NSAMPLES)
end_define

begin_comment
comment|/* Chose how many filter samples to keep.  Several factors are in play.   1) Discard at least one sample to allow a spike value to be     discarded.   2) Discard about 1-in-8 to 1-in-30 samples to handle spikes.   3) Keep an odd number of samples to avoid median value being biased     high or low. */
end_comment

begin_define
define|#
directive|define
name|NKEEP
parameter_list|(
name|pp
parameter_list|)
value|((CHOSENSAMPLES(pp) - 1 - (CHOSENSAMPLES(pp)>>3)) | 1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_RESYNC_TIME
value|(57*60)
end_define

begin_comment
comment|/* Gap between resync attempts (s). */
end_comment

begin_define
define|#
directive|define
name|RETRY_RESYNC_TIME
value|(27*60)
end_define

begin_comment
comment|/* Gap to emergency resync attempt. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARCRON_KEEN
end_ifdef

begin_define
define|#
directive|define
name|INITIAL_RESYNC_DELAY
value|500
end_define

begin_comment
comment|/* Delay before first resync. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INITIAL_RESYNC_DELAY
value|50
end_define

begin_comment
comment|/* Delay before first resync. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|int
name|moff
index|[
literal|12
index|]
init|=
block|{
literal|0
block|,
literal|31
block|,
literal|59
block|,
literal|90
block|,
literal|120
block|,
literal|151
block|,
literal|181
block|,
literal|212
block|,
literal|243
block|,
literal|273
block|,
literal|304
block|,
literal|334
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flags for a raw open() of the clock serial device. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|O_NOCTTY
end_ifdef

begin_comment
comment|/* Good, we can avoid tty becoming controlling tty. */
end_comment

begin_define
define|#
directive|define
name|OPEN_FLAGS
value|(O_RDWR | O_NOCTTY)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Oh well, it may not matter... */
end_comment

begin_define
define|#
directive|define
name|OPEN_FLAGS
value|(O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Length of queue of command bytes to be sent. */
end_comment

begin_define
define|#
directive|define
name|CMDQUEUELEN
value|4
end_define

begin_comment
comment|/* Enough for two cmds + each \r. */
end_comment

begin_comment
comment|/* Queue tick time; interval in seconds between chars taken off queue. */
end_comment

begin_comment
comment|/* Must be>= 2 to allow o\r response to come back uninterrupted. */
end_comment

begin_define
define|#
directive|define
name|QUEUETICK
value|2
end_define

begin_comment
comment|/* Allow o\r reply to finish. */
end_comment

begin_comment
comment|/*  * ARC unit control structure  */
end_comment

begin_struct
struct|struct
name|arcunit
block|{
name|l_fp
name|lastrec
decl_stmt|;
comment|/* Time tag for the receive time (system). */
name|int
name|status
decl_stmt|;
comment|/* Clock status. */
name|int
name|quality
decl_stmt|;
comment|/* Quality of reception 0--5 for unit. */
comment|/* We may also use the values -1 or 6 internally. */
name|u_long
name|next_resync
decl_stmt|;
comment|/* Next resync time (s) compared to current_time. */
name|int
name|resyncing
decl_stmt|;
comment|/* Resync in progress if true. */
comment|/* In the outgoing queue, cmdqueue[0] is next to be sent. */
name|char
name|cmdqueue
index|[
name|CMDQUEUELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Queue of outgoing commands + \0. */
name|u_long
name|saved_flags
decl_stmt|;
comment|/* Saved fudge flags. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ARCRON_LEAPSECOND_KEEN
end_ifdef

begin_comment
comment|/* The flag `possible_leap' is set non-zero when any MSF unit        thinks a leap-second may have happened.         Set whenever we receive a valid time sample in the first hour of        the first day of the first/seventh months.         Outside the special hour this value is unconditionally set        to zero by the receive routine.         On finding itself in this timeslot, as long as the value is        non-negative, the receive routine sets it to a positive value to        indicate a resync to MSF should be performed.         In the poll routine, if this value is positive and we are not        already resyncing (eg from a sync that started just before        midnight), start resyncing and set this value negative to        indicate that a leap-triggered resync has been started.  Having        set this negative prevents the receive routine setting it        positive and thus prevents multiple resyncs during the witching        hour.      */
end_comment

begin_decl_stmt
specifier|static
name|int
name|possible_leap
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No resync required by default. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static void dummy_event_handler P((struct peer *)); static void   arc_event_handler P((struct peer *));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|QUALITY_UNKNOWN
value|-1
end_define

begin_comment
comment|/* Indicates unknown clock quality. */
end_comment

begin_define
define|#
directive|define
name|MIN_CLOCK_QUALITY
value|0
end_define

begin_comment
comment|/* Min quality clock will return. */
end_comment

begin_define
define|#
directive|define
name|MIN_CLOCK_QUALITY_OK
value|3
end_define

begin_comment
comment|/* Min quality for OK reception. */
end_comment

begin_define
define|#
directive|define
name|MAX_CLOCK_QUALITY
value|5
end_define

begin_comment
comment|/* Max quality clock will return. */
end_comment

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|arc_start
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|arc_shutdown
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|arc_receive
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|arc_poll
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_arc
init|=
block|{
name|arc_start
block|,
comment|/* start up driver */
name|arc_shutdown
block|,
comment|/* shut down driver */
name|arc_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used (old arc_control) */
name|noentry
block|,
comment|/* initialize driver (not used) */
name|noentry
block|,
comment|/* not used (old arc_buginfo) */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue us up for the next tick. */
end_comment

begin_define
define|#
directive|define
name|ENQUEUE
parameter_list|(
name|up
parameter_list|)
define|\
value|do { \ 	     if((up)->ev.next != 0) { break; }
comment|/* WHOOPS! */
value|\ 	     peer->nextdate = current_time + QUEUETICK; \ 	} while(0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Placeholder event handler---does nothing safely---soaks up lose tick. */
end_comment

begin_ifdef
unit|static void dummy_event_handler( 	struct peer *peer 	) {
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
end_ifdef

begin_endif
unit|if(debug) { printf("arc: dummy_event_handler() called.\n"); }
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/* Normal event handler.  Take first character off queue and send to clock if not a null.  Shift characters down and put a null on the end.  We assume that there is no parallelism so no race condition, but even if there is nothing bad will happen except that we might send some bad data to the clock once in a while. */
end_comment

begin_ifdef
unit|static void arc_event_handler( 	struct peer *peer 	) { 	struct refclockproc *pp = peer->procptr; 	register struct arcunit *up = (struct arcunit *)pp->unitptr; 	int i; 	char c;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
end_ifdef

begin_endif
unit|if(debug> 2) { printf("arc: arc_event_handler() called.\n"); }
endif|#
directive|endif
end_endif

begin_comment
unit|c = up->cmdqueue[0];
comment|/* Next char to be sent. */
end_comment

begin_comment
comment|/* Shift down characters, shifting trailing \0 in at end. */
end_comment

begin_comment
unit|for(i = 0; i< CMDQUEUELEN; ++i) 	{ up->cmdqueue[i] = up->cmdqueue[i+1]; }
comment|/* Don't send '\0' characters. */
end_comment

begin_ifdef
unit|if(c != '\0') { 		if(write(pp->io.fd,&c, 1) != 1) { 			msyslog(LOG_NOTICE, "ARCRON: write to fd %d failed", pp->io.fd); 		}
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
end_ifdef

begin_endif
unit|else if(debug) { printf("arc: sent `%2.2x', fd %d.\n", c, pp->io.fd); }
endif|#
directive|endif
end_endif

begin_endif
unit|} }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/*  * arc_start - open the devices and initialize data for processing  */
end_comment

begin_function
specifier|static
name|int
name|arc_start
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|arcunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
name|device
index|[
literal|20
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_TERMIOS
name|struct
name|termios
name|arg
decl_stmt|;
endif|#
directive|endif
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: %s: opening unit %d"
argument_list|,
name|arc_version
argument_list|,
name|unit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: %s: attempt to open unit %d.\n"
argument_list|,
name|arc_version
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Prevent a ridiculous device number causing overflow of device[]. */
if|if
condition|(
operator|(
name|unit
operator|<
literal|0
operator|)
operator|||
operator|(
name|unit
operator|>
literal|255
operator|)
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * Open serial port. Use CLK line discipline, if available. 	 */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|device
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|fd
operator|=
name|refclock_open
argument_list|(
name|device
argument_list|,
name|SPEED
argument_list|,
name|LDISC_CLK
argument_list|)
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: unit %d using open().\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|fd
operator|=
name|open
argument_list|(
name|device
argument_list|,
name|OPEN_FLAGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: failed [open()] to open %s.\n"
argument_list|,
name|device
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* clear the descriptor flags */
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"Opened RS232 port with file descriptor %d.\n"
argument_list|,
name|fd
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_TERMIOS
name|arg
operator|.
name|c_iflag
operator|=
name|IGNBRK
operator||
name|ISTRIP
expr_stmt|;
name|arg
operator|.
name|c_oflag
operator|=
literal|0
expr_stmt|;
name|arg
operator|.
name|c_cflag
operator|=
name|B300
operator||
name|CS8
operator||
name|CREAD
operator||
name|CLOCAL
operator||
name|CSTOPB
expr_stmt|;
name|arg
operator|.
name|c_lflag
operator|=
literal|0
expr_stmt|;
name|arg
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
name|arg
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSANOW
argument_list|,
operator|&
name|arg
argument_list|)
expr_stmt|;
else|#
directive|else
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ARCRON: termios not supported in this driver"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
name|up
operator|=
operator|(
expr|struct
name|arcunit
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|arcunit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|up
condition|)
block|{
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Set structure to all zeros... */
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|up
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|arcunit
argument_list|)
argument_list|)
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|clock_recv
operator|=
name|arc_receive
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|srcclock
operator|=
operator|(
name|caddr_t
operator|)
name|peer
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|datalen
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|fd
operator|=
name|fd
expr_stmt|;
if|if
condition|(
operator|!
name|io_addclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|up
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|pp
operator|->
name|unitptr
operator|=
operator|(
name|caddr_t
operator|)
name|up
expr_stmt|;
comment|/* 	 * Initialize miscellaneous variables 	 */
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
name|peer
operator|->
name|stratum
operator|=
literal|2
expr_stmt|;
comment|/* Default to stratum 2 not 0. */
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|pp
operator|->
name|refid
argument_list|,
name|REFID
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* Spread out resyncs so that they should remain separated. */
name|up
operator|->
name|next_resync
operator|=
name|current_time
operator|+
name|INITIAL_RESYNC_DELAY
operator|+
operator|(
literal|67
operator|*
name|unit
operator|)
operator|%
literal|1009
expr_stmt|;
if|#
directive|if
literal|0
comment|/* Not needed because of zeroing of arcunit structure... */
block|up->resyncing = 0;
comment|/* Not resyncing yet. */
block|up->saved_flags = 0;
comment|/* Default is all flags off. */
comment|/* Clear send buffer out... */
block|{ 		int i; 		for(i = CMDQUEUELEN; i>= 0; --i) { up->cmdqueue[i] = '\0'; } 	}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ARCRON_KEEN
name|up
operator|->
name|quality
operator|=
name|QUALITY_UNKNOWN
expr_stmt|;
comment|/* Trust the clock immediately. */
else|#
directive|else
name|up
operator|->
name|quality
operator|=
name|MIN_CLOCK_QUALITY
expr_stmt|;
comment|/* Don't trust the clock yet. */
endif|#
directive|endif
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * arc_shutdown - shut down the clock  */
end_comment

begin_function
specifier|static
name|void
name|arc_shutdown
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|arcunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|arcunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|io_closeclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|up
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Compute space left in output buffer. */
end_comment

begin_function
specifier|static
name|int
name|space_left
parameter_list|(
specifier|register
name|struct
name|arcunit
modifier|*
name|up
parameter_list|)
block|{
name|int
name|spaceleft
decl_stmt|;
comment|/* Compute space left in buffer after any pending output. */
for|for
control|(
name|spaceleft
operator|=
literal|0
init|;
name|spaceleft
operator|<
name|CMDQUEUELEN
condition|;
operator|++
name|spaceleft
control|)
block|{
if|if
condition|(
name|up
operator|->
name|cmdqueue
index|[
name|CMDQUEUELEN
operator|-
literal|1
operator|-
name|spaceleft
index|]
operator|!=
literal|'\0'
condition|)
block|{
break|break;
block|}
block|}
return|return
operator|(
name|spaceleft
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Send command by copying into command buffer as far forward as possible, after any pending output.  Indicate an error by returning 0 if there is not space for the command. */
end_comment

begin_function
specifier|static
name|int
name|send_slow
parameter_list|(
specifier|register
name|struct
name|arcunit
modifier|*
name|up
parameter_list|,
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|int
name|sl
init|=
name|strlen
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|int
name|spaceleft
init|=
name|space_left
argument_list|(
name|up
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: spaceleft = %d.\n"
argument_list|,
name|spaceleft
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|spaceleft
operator|<
name|sl
condition|)
block|{
comment|/* Should not normally happen... */
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: send-buffer overrun (%d/%d)"
argument_list|,
name|sl
argument_list|,
name|spaceleft
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
comment|/* FAILED! */
block|}
comment|/* Copy in the command to be sent. */
while|while
condition|(
operator|*
name|s
condition|)
block|{
name|up
operator|->
name|cmdqueue
index|[
name|CMDQUEUELEN
operator|-
name|spaceleft
operator|--
index|]
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Macro indicating action we will take for different quality values. */
end_comment

begin_define
define|#
directive|define
name|quality_action
parameter_list|(
name|q
parameter_list|)
define|\
value|(((q) == QUALITY_UNKNOWN) ?         "UNKNOWN, will use clock anyway" : \  (((q)< MIN_CLOCK_QUALITY_OK) ? "TOO POOR, will not use clock" : \   "OK, will use clock"))
end_define

begin_comment
comment|/*  * arc_receive - receive data from the serial interface  */
end_comment

begin_function
specifier|static
name|void
name|arc_receive
parameter_list|(
name|struct
name|recvbuf
modifier|*
name|rbufp
parameter_list|)
block|{
specifier|register
name|struct
name|arcunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|,
name|n
decl_stmt|,
name|wday
decl_stmt|,
name|month
decl_stmt|,
name|bst
decl_stmt|,
name|status
decl_stmt|;
name|int
name|arc_last_offset
decl_stmt|;
comment|/* 	 * Initialize pointers and read the timecode and timestamp 	 */
name|peer
operator|=
operator|(
expr|struct
name|peer
operator|*
operator|)
name|rbufp
operator|->
name|recv_srcclock
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|arcunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
comment|/* 	  If the command buffer is empty, and we are resyncing, insert a 	  g\r quality request into it to poll for signal quality again. 	*/
if|if
condition|(
operator|(
name|up
operator|->
name|resyncing
operator|)
operator|&&
operator|(
name|space_left
argument_list|(
name|up
argument_list|)
operator|==
name|CMDQUEUELEN
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: inserting signal-quality poll.\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|send_slow
argument_list|(
name|up
argument_list|,
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"g\r"
argument_list|)
expr_stmt|;
block|}
comment|/* 	  The `arc_last_offset' is the offset in lastcode[] of the last byte 	  received, and which we assume actually received the input 	  timestamp.  	  (When we get round to using tty_clk and it is available, we 	  assume that we will receive the whole timecode with the 	  trailing \r, and that that \r will be timestamped.  But this 	  assumption also works if receive the characters one-by-one.) 	*/
name|arc_last_offset
operator|=
name|pp
operator|->
name|lencode
operator|+
name|rbufp
operator|->
name|recv_length
operator|-
literal|1
expr_stmt|;
comment|/* 	  We catch a timestamp iff:  	  * The command code is `o' for a timestamp.  	  * If ARCRON_MULTIPLE_SAMPLES is undefined then we must have 	  exactly char in the buffer (the command code) so that we 	  only sample the first character of the timecode as our 	  `on-time' character.  	  * The first character in the buffer is not the echoed `\r' 	  from the `o` command (so if we are to timestamp an `\r' it 	  must not be first in the receive buffer with lencode==1. 	  (Even if we had other characters following it, we probably 	  would have a premature timestamp on the '\r'.)  	  * We have received at least one character (I cannot imagine 	  how it could be otherwise, but anyway...). 	*/
name|c
operator|=
name|rbufp
operator|->
name|recv_buffer
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|pp
operator|->
name|a_lastcode
index|[
literal|0
index|]
operator|==
literal|'o'
operator|)
operator|&&
ifndef|#
directive|ifndef
name|ARCRON_MULTIPLE_SAMPLES
operator|(
name|pp
operator|->
name|lencode
operator|==
literal|1
operator|)
operator|&&
endif|#
directive|endif
operator|(
operator|(
name|pp
operator|->
name|lencode
operator|!=
literal|1
operator|)
operator|||
operator|(
name|c
operator|!=
literal|'\r'
operator|)
operator|)
operator|&&
operator|(
name|arc_last_offset
operator|>=
literal|1
operator|)
condition|)
block|{
comment|/* Note that the timestamp should be corrected if>1 char rcvd. */
name|l_fp
name|timestamp
decl_stmt|;
name|timestamp
operator|=
name|rbufp
operator|->
name|recv_time
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
comment|/* Show \r as `R', other non-printing char as `?'. */
name|printf
argument_list|(
literal|"arc: stamp -->%c<-- (%d chars rcvd)\n"
argument_list|,
operator|(
operator|(
name|c
operator|==
literal|'\r'
operator|)
condition|?
literal|'R'
else|:
operator|(
name|isgraph
argument_list|(
operator|(
name|int
operator|)
name|c
argument_list|)
condition|?
name|c
else|:
literal|'?'
operator|)
operator|)
argument_list|,
name|rbufp
operator|->
name|recv_length
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 		  Now correct timestamp by offset of last byte received---we 		  subtract from the receive time the delay implied by the 		  extra characters received.  		  Reject the input if the resulting code is too long, but 		  allow for the trailing \r, normally not used but a good 		  handle for tty_clk or somesuch kernel timestamper. 		*/
if|if
condition|(
name|arc_last_offset
operator|>
name|LENARC
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: input code too long (%d cf %d); rejected.\n"
argument_list|,
name|arc_last_offset
argument_list|,
name|LENARC
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
name|L_SUBUF
argument_list|(
operator|&
name|timestamp
argument_list|,
name|charoffsets
index|[
name|arc_last_offset
index|]
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: %s%d char(s) rcvd, the last for lastcode[%d]; -%sms offset applied.\n"
argument_list|,
operator|(
operator|(
name|rbufp
operator|->
name|recv_length
operator|>
literal|1
operator|)
condition|?
literal|"*** "
else|:
literal|""
operator|)
argument_list|,
name|rbufp
operator|->
name|recv_length
argument_list|,
name|arc_last_offset
argument_list|,
name|mfptoms
argument_list|(
operator|(
name|unsigned
name|long
operator|)
literal|0
argument_list|,
name|charoffsets
index|[
name|arc_last_offset
index|]
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ARCRON_MULTIPLE_SAMPLES
comment|/* 		  If taking multiple samples, capture the current adjusted 		  sample iff:  		  * No timestamp has yet been captured (it is zero), OR  		  * This adjusted timestamp is earlier than the one already 		  captured, on the grounds that this one suffered less 		  delay in being delivered to us and is more accurate.  		*/
if|if
condition|(
name|L_ISZERO
argument_list|(
operator|&
operator|(
name|up
operator|->
name|lastrec
operator|)
argument_list|)
operator|||
name|L_ISGEQ
argument_list|(
operator|&
operator|(
name|up
operator|->
name|lastrec
operator|)
argument_list|,
operator|&
name|timestamp
argument_list|)
condition|)
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: system timestamp captured.\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_MULTIPLE_SAMPLES
if|if
condition|(
operator|!
name|L_ISZERO
argument_list|(
operator|&
operator|(
name|up
operator|->
name|lastrec
operator|)
argument_list|)
condition|)
block|{
name|l_fp
name|diff
decl_stmt|;
name|diff
operator|=
name|up
operator|->
name|lastrec
expr_stmt|;
name|L_SUB
argument_list|(
operator|&
name|diff
argument_list|,
operator|&
name|timestamp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"arc: adjusted timestamp by -%sms.\n"
argument_list|,
name|mfptoms
argument_list|(
name|diff
operator|.
name|l_i
argument_list|,
name|diff
operator|.
name|l_f
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
endif|#
directive|endif
name|up
operator|->
name|lastrec
operator|=
name|timestamp
expr_stmt|;
block|}
block|}
comment|/* Just in case we still have lots of rubbish in the buffer... */
comment|/* ...and to avoid the same timestamp being reused by mistake, */
comment|/* eg on receipt of the \r coming in on its own after the      */
comment|/* timecode.                                                   */
if|if
condition|(
name|pp
operator|->
name|lencode
operator|>=
name|LENARC
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|&&
operator|(
name|rbufp
operator|->
name|recv_buffer
index|[
literal|0
index|]
operator|!=
literal|'\r'
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"arc: rubbish in pp->a_lastcode[].\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* Append input to code buffer, avoiding overflow. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rbufp
operator|->
name|recv_length
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pp
operator|->
name|lencode
operator|>=
name|LENARC
condition|)
block|{
break|break;
block|}
comment|/* Avoid overflow... */
name|c
operator|=
name|rbufp
operator|->
name|recv_buffer
index|[
name|i
index|]
expr_stmt|;
comment|/* Drop trailing '\r's and drop `h' command echo totally. */
if|if
condition|(
name|c
operator|!=
literal|'\r'
operator|&&
name|c
operator|!=
literal|'h'
condition|)
block|{
name|pp
operator|->
name|a_lastcode
index|[
name|pp
operator|->
name|lencode
operator|++
index|]
operator|=
name|c
expr_stmt|;
block|}
comment|/* 		  If we've just put an `o' in the lastcode[0], clear the 		  timestamp in anticipation of a timecode arriving soon.  		  We would expect to get to process this before any of the 		  timecode arrives. 		*/
if|if
condition|(
operator|(
name|c
operator|==
literal|'o'
operator|)
operator|&&
operator|(
name|pp
operator|->
name|lencode
operator|==
literal|1
operator|)
condition|)
block|{
name|L_CLR
argument_list|(
operator|&
operator|(
name|up
operator|->
name|lastrec
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: clearing timestamp.\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
comment|/* Handle a quality message. */
if|if
condition|(
name|pp
operator|->
name|a_lastcode
index|[
literal|0
index|]
operator|==
literal|'g'
condition|)
block|{
name|int
name|r
decl_stmt|,
name|q
decl_stmt|;
if|if
condition|(
name|pp
operator|->
name|lencode
operator|<
literal|3
condition|)
block|{
return|return;
block|}
comment|/* Need more data... */
name|r
operator|=
operator|(
name|pp
operator|->
name|a_lastcode
index|[
literal|1
index|]
operator|&
literal|0x7f
operator|)
expr_stmt|;
comment|/* Strip parity. */
name|q
operator|=
operator|(
name|pp
operator|->
name|a_lastcode
index|[
literal|2
index|]
operator|&
literal|0x7f
operator|)
expr_stmt|;
comment|/* Strip parity. */
if|if
condition|(
operator|(
operator|(
name|q
operator|&
literal|0x70
operator|)
operator|!=
literal|0x30
operator|)
operator|||
operator|(
operator|(
name|q
operator|&
literal|0xf
operator|)
operator|>
name|MAX_CLOCK_QUALITY
operator|)
operator|||
operator|(
operator|(
name|r
operator|&
literal|0x70
operator|)
operator|!=
literal|0x30
operator|)
condition|)
block|{
comment|/* Badly formatted response. */
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: bad `g' response %2x %2x.\n"
argument_list|,
name|r
argument_list|,
name|q
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return;
block|}
if|if
condition|(
name|r
operator|==
literal|'3'
condition|)
block|{
comment|/* Only use quality value whilst sync in progress. */
name|up
operator|->
name|quality
operator|=
operator|(
name|q
operator|&
literal|0xf
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: signal quality %d.\n"
argument_list|,
name|up
operator|->
name|quality
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
comment|/* (r == '2')&& */
name|up
operator|->
name|resyncing
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: sync finished, signal quality %d: %s\n"
argument_list|,
name|up
operator|->
name|quality
argument_list|,
name|quality_action
argument_list|(
name|up
operator|->
name|quality
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: sync finished, signal quality %d: %s"
argument_list|,
name|up
operator|->
name|quality
argument_list|,
name|quality_action
argument_list|(
name|up
operator|->
name|quality
argument_list|)
argument_list|)
expr_stmt|;
name|up
operator|->
name|resyncing
operator|=
literal|0
expr_stmt|;
comment|/* Resync is over. */
ifdef|#
directive|ifdef
name|ARCRON_KEEN
comment|/* Clock quality dubious; resync earlier than usual. */
if|if
condition|(
operator|(
name|up
operator|->
name|quality
operator|==
name|QUALITY_UNKNOWN
operator|)
operator|||
operator|(
name|up
operator|->
name|quality
operator|<
name|MIN_CLOCK_QUALITY_OK
operator|)
condition|)
block|{
name|up
operator|->
name|next_resync
operator|=
name|current_time
operator|+
name|RETRY_RESYNC_TIME
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
return|return;
block|}
comment|/* Stop now if this is not a timecode message. */
if|if
condition|(
name|pp
operator|->
name|a_lastcode
index|[
literal|0
index|]
operator|!=
literal|'o'
condition|)
block|{
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* If we don't have enough data, wait for more... */
if|if
condition|(
name|pp
operator|->
name|lencode
operator|<
name|LENARC
condition|)
block|{
return|return;
block|}
comment|/* WE HAVE NOW COLLECTED ONE TIMESTAMP (phew)... */
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
operator|>
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"arc: NOW HAVE TIMESTAMP...\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* But check that we actually captured a system timestamp on it. */
if|if
condition|(
name|L_ISZERO
argument_list|(
operator|&
operator|(
name|up
operator|->
name|lastrec
operator|)
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: FAILED TO GET SYSTEM TIMESTAMP\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	  Append a mark of the clock's received signal quality for the 	  benefit of Derek Mulcahy's Tcl/Tk utility (we map the `unknown' 	  quality value to `6' for his s/w) and terminate the string for 	  sure.  This should not go off the buffer end. 	*/
name|pp
operator|->
name|a_lastcode
index|[
name|pp
operator|->
name|lencode
index|]
operator|=
operator|(
operator|(
name|up
operator|->
name|quality
operator|==
name|QUALITY_UNKNOWN
operator|)
condition|?
literal|'6'
else|:
operator|(
literal|'0'
operator|+
name|up
operator|->
name|quality
operator|)
operator|)
expr_stmt|;
name|pp
operator|->
name|a_lastcode
index|[
name|pp
operator|->
name|lencode
operator|+
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Terminate for printf(). */
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|pp
operator|->
name|a_lastcode
argument_list|)
expr_stmt|;
comment|/* We don't use the micro-/milli- second part... */
name|pp
operator|->
name|usec
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|msec
operator|=
literal|0
expr_stmt|;
name|n
operator|=
name|sscanf
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|,
literal|"o%2d%2d%2d%1d%2d%2d%2d%1d%1d"
argument_list|,
operator|&
name|pp
operator|->
name|hour
argument_list|,
operator|&
name|pp
operator|->
name|minute
argument_list|,
operator|&
name|pp
operator|->
name|second
argument_list|,
operator|&
name|wday
argument_list|,
operator|&
name|pp
operator|->
name|day
argument_list|,
operator|&
name|month
argument_list|,
operator|&
name|pp
operator|->
name|year
argument_list|,
operator|&
name|bst
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* Validate format and numbers. */
if|if
condition|(
name|n
operator|!=
literal|9
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
comment|/* Would expect to have caught major problems already... */
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: badly formatted data.\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	  Validate received values at least enough to prevent internal 	  array-bounds problems, etc. 	*/
if|if
condition|(
operator|(
name|pp
operator|->
name|hour
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|hour
operator|>
literal|23
operator|)
operator|||
operator|(
name|pp
operator|->
name|minute
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|minute
operator|>
literal|59
operator|)
operator|||
operator|(
name|pp
operator|->
name|second
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|second
operator|>
literal|60
operator|)
comment|/*Allow for leap seconds.*/
operator|||
operator|(
name|wday
operator|<
literal|1
operator|)
operator|||
operator|(
name|wday
operator|>
literal|7
operator|)
operator|||
operator|(
name|pp
operator|->
name|day
operator|<
literal|1
operator|)
operator|||
operator|(
name|pp
operator|->
name|day
operator|>
literal|31
operator|)
operator|||
operator|(
name|month
operator|<
literal|1
operator|)
operator|||
operator|(
name|month
operator|>
literal|12
operator|)
operator|||
operator|(
name|pp
operator|->
name|year
operator|<
literal|0
operator|)
operator|||
operator|(
name|pp
operator|->
name|year
operator|>
literal|99
operator|)
condition|)
block|{
comment|/* Data out of range. */
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Check that BST/UTC bits are the complement of one another. */
if|if
condition|(
operator|!
operator|(
name|bst
operator|&
literal|2
operator|)
operator|==
operator|!
operator|(
name|bst
operator|&
literal|4
operator|)
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|status
operator|&
literal|0x8
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: battery low"
argument_list|)
expr_stmt|;
block|}
comment|/* Year-2000 alert! */
comment|/* Attempt to wrap 2-digit date into sensible window. */
if|if
condition|(
name|pp
operator|->
name|year
operator|<
name|YEAR_PIVOT
condition|)
block|{
name|pp
operator|->
name|year
operator|+=
literal|100
expr_stmt|;
block|}
comment|/* Y2KFixes */
name|pp
operator|->
name|year
operator|+=
literal|1900
expr_stmt|;
comment|/* use full four-digit year */
comment|/* Y2KFixes */
comment|/* 	  Attempt to do the right thing by screaming that the code will 	  soon break when we get to the end of its useful life.  What a 	  hero I am...  PLEASE FIX LEAP-YEAR AND WRAP CODE IN 209X! 	*/
if|if
condition|(
name|pp
operator|->
name|year
operator|>=
name|YEAR_PIVOT
operator|+
literal|2000
operator|-
literal|2
condition|)
block|{
comment|/* Y2KFixes */
comment|/*This should get attention B^> */
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: fix me!  EITHER YOUR DATE IS BADLY WRONG or else I will break soon!"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: n=%d %02d:%02d:%02d %02d/%02d/%04d %1d %1d\n"
argument_list|,
name|n
argument_list|,
name|pp
operator|->
name|hour
argument_list|,
name|pp
operator|->
name|minute
argument_list|,
name|pp
operator|->
name|second
argument_list|,
name|pp
operator|->
name|day
argument_list|,
name|month
argument_list|,
name|pp
operator|->
name|year
argument_list|,
name|bst
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	  The status value tested for is not strictly supported by the 	  clock spec since the value of bit 2 (0x4) is claimed to be 	  undefined for MSF, yet does seem to indicate if the last resync 	  was successful or not. 	*/
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOWARNING
expr_stmt|;
name|status
operator|&=
literal|0x7
expr_stmt|;
if|if
condition|(
name|status
operator|==
literal|0x3
condition|)
block|{
if|if
condition|(
name|status
operator|!=
name|up
operator|->
name|status
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: signal acquired"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|status
operator|!=
name|up
operator|->
name|status
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: signal lost"
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
comment|/* MSF clock is free-running. */
name|up
operator|->
name|status
operator|=
name|status
expr_stmt|;
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|up
operator|->
name|status
operator|=
name|status
expr_stmt|;
name|pp
operator|->
name|day
operator|+=
name|moff
index|[
name|month
operator|-
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|isleap_4
argument_list|(
name|pp
operator|->
name|year
argument_list|)
operator|&&
name|month
operator|>
literal|2
condition|)
block|{
name|pp
operator|->
name|day
operator|++
expr_stmt|;
block|}
comment|/* Y2KFixes */
comment|/* Convert to UTC if required */
if|if
condition|(
name|bst
operator|&
literal|2
condition|)
block|{
name|pp
operator|->
name|hour
operator|--
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|hour
operator|<
literal|0
condition|)
block|{
name|pp
operator|->
name|hour
operator|=
literal|23
expr_stmt|;
name|pp
operator|->
name|day
operator|--
expr_stmt|;
comment|/* If we try to wrap round the year (BST on 1st Jan), reject.*/
if|if
condition|(
name|pp
operator|->
name|day
operator|<
literal|0
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
comment|/* If clock signal quality is unknown, revert to default PRECISION...*/
if|if
condition|(
name|up
operator|->
name|quality
operator|==
name|QUALITY_UNKNOWN
condition|)
block|{
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
block|}
comment|/* ...else improve precision if flag3 is set... */
else|else
block|{
name|peer
operator|->
name|precision
operator|=
operator|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG3
operator|)
condition|?
name|HIGHPRECISION
else|:
name|PRECISION
operator|)
expr_stmt|;
block|}
comment|/* Notice and log any change (eg from initial defaults) for flags. */
if|if
condition|(
name|up
operator|->
name|saved_flags
operator|!=
name|pp
operator|->
name|sloppyclockflag
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: flags enabled: %s%s%s%s"
argument_list|,
operator|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG1
operator|)
condition|?
literal|"1"
else|:
literal|"."
operator|)
argument_list|,
operator|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG2
operator|)
condition|?
literal|"2"
else|:
literal|"."
operator|)
argument_list|,
operator|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG3
operator|)
condition|?
literal|"3"
else|:
literal|"."
operator|)
argument_list|,
operator|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG4
operator|)
condition|?
literal|"4"
else|:
literal|"."
operator|)
argument_list|)
expr_stmt|;
comment|/* Note effects of flags changing... */
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: CHOSENSAMPLES(pp) = %d.\n"
argument_list|,
name|CHOSENSAMPLES
argument_list|(
name|pp
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"arc: NKEEP(pp) = %d.\n"
argument_list|,
name|NKEEP
argument_list|(
name|pp
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"arc: PRECISION = %d.\n"
argument_list|,
name|peer
operator|->
name|precision
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|up
operator|->
name|saved_flags
operator|=
name|pp
operator|->
name|sloppyclockflag
expr_stmt|;
block|}
comment|/* Note time of last believable timestamp. */
name|pp
operator|->
name|lastrec
operator|=
name|up
operator|->
name|lastrec
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_LEAPSECOND_KEEN
comment|/* Find out if a leap-second might just have happened... 	   (ie is this the first hour of the first day of Jan or Jul?) 	*/
if|if
condition|(
operator|(
name|pp
operator|->
name|hour
operator|==
literal|0
operator|)
operator|&&
operator|(
name|pp
operator|->
name|day
operator|==
literal|1
operator|)
operator|&&
operator|(
operator|(
name|month
operator|==
literal|1
operator|)
operator|||
operator|(
name|month
operator|==
literal|7
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|possible_leap
operator|>=
literal|0
condition|)
block|{
comment|/* A leap may have happened, and no resync has started yet...*/
name|possible_leap
operator|=
literal|1
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Definitely not leap-second territory... */
name|possible_leap
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|refclock_process
argument_list|(
name|pp
argument_list|)
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
return|return;
block|}
name|refclock_receive
argument_list|(
name|peer
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* request_time() sends a time request to the clock with given peer. */
end_comment

begin_comment
comment|/* This automatically reports a fault if necessary. */
end_comment

begin_comment
comment|/* No data should be sent after this until arc_poll() returns. */
end_comment

begin_decl_stmt
specifier|static
name|void
name|request_time
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|request_time
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|refclockproc
modifier|*
name|pp
init|=
name|peer
operator|->
name|procptr
decl_stmt|;
specifier|register
name|struct
name|arcunit
modifier|*
name|up
init|=
operator|(
expr|struct
name|arcunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: unit %d: requesting time.\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|send_slow
argument_list|(
name|up
argument_list|,
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"o\r"
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|ARCRON_DEBUG
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: unit %d: problem sending"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
return|return;
block|}
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * arc_poll - called by the transmit procedure  */
end_comment

begin_function
specifier|static
name|void
name|arc_poll
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
specifier|register
name|struct
name|arcunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|int
name|resync_needed
decl_stmt|;
comment|/* Should we start a resync? */
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|arcunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|pp
operator|->
name|lencode
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* Flush input. */
block|tcflush(pp->io.fd, TCIFLUSH);
endif|#
directive|endif
comment|/* Resync if our next scheduled resync time is here or has passed. */
name|resync_needed
operator|=
operator|(
name|up
operator|->
name|next_resync
operator|<=
name|current_time
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARCRON_LEAPSECOND_KEEN
comment|/* 	  Try to catch a potential leap-second insertion or deletion quickly.  	  In addition to the normal NTP fun of clocks that don't report 	  leap-seconds spooking their hosts, this clock does not even 	  sample the radio sugnal the whole time, so may miss a 	  leap-second insertion or deletion for up to a whole sample 	  time.  	  To try to minimise this effect, if in the first few minutes of 	  the day immediately following a leap-second-insertion point 	  (ie in the first hour of the first day of the first and sixth 	  months), and if the last resync was in the previous day, and a 	  resync is not already in progress, resync the clock 	  immediately.  	*/
if|if
condition|(
operator|(
name|possible_leap
operator|>
literal|0
operator|)
operator|&&
comment|/* Must be 00:XX 01/0{1,7}/XXXX. */
operator|(
operator|!
name|up
operator|->
name|resyncing
operator|)
condition|)
block|{
comment|/* No resync in progress yet. */
name|resync_needed
operator|=
literal|1
expr_stmt|;
name|possible_leap
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Prevent multiple resyncs. */
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: unit %d: checking for leap second"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Do a resync if required... */
if|if
condition|(
name|resync_needed
condition|)
block|{
comment|/* First, reset quality value to `unknown' so we can detect */
comment|/* when a quality message has been responded to by this     */
comment|/* being set to some other value.                           */
name|up
operator|->
name|quality
operator|=
name|QUALITY_UNKNOWN
expr_stmt|;
comment|/* Note that we are resyncing... */
name|up
operator|->
name|resyncing
operator|=
literal|1
expr_stmt|;
comment|/* Now actually send the resync command and an immediate poll. */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: sending resync command (h\\r).\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|msyslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ARCRON: unit %d: sending resync command"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|send_slow
argument_list|(
name|up
argument_list|,
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"h\r"
argument_list|)
expr_stmt|;
comment|/* Schedule our next resync... */
name|up
operator|->
name|next_resync
operator|=
name|current_time
operator|+
name|DEFAULT_RESYNC_TIME
expr_stmt|;
comment|/* Drop through to request time if appropriate. */
block|}
comment|/* If clock quality is too poor to trust, indicate a fault. */
comment|/* If quality is QUALITY_UNKNOWN and ARCRON_KEEN is defined,*/
comment|/* we'll cross our fingers and just hope that the thing     */
comment|/* synced so quickly we did not catch it---we'll            */
comment|/* double-check the clock is OK elsewhere.                  */
if|if
condition|(
ifdef|#
directive|ifdef
name|ARCRON_KEEN
operator|(
name|up
operator|->
name|quality
operator|!=
name|QUALITY_UNKNOWN
operator|)
operator|&&
else|#
directive|else
operator|(
name|up
operator|->
name|quality
operator|==
name|QUALITY_UNKNOWN
operator|)
operator|||
endif|#
directive|endif
operator|(
name|up
operator|->
name|quality
operator|<
name|MIN_CLOCK_QUALITY_OK
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"arc: clock quality %d too poor.\n"
argument_list|,
name|up
operator|->
name|quality
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* This is the normal case: request a timestamp. */
name|request_time
argument_list|(
name|unit
argument_list|,
name|peer
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_arc_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

