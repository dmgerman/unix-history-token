begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Data for pretty printing clock types  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
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

begin_decl_stmt
name|struct
name|clktype
name|clktypes
index|[]
init|=
block|{
block|{
name|REFCLK_NONE
block|,
literal|"unspecified type (0)"
block|,
literal|"UNKNOWN"
block|}
block|,
block|{
name|REFCLK_LOCALCLOCK
block|,
literal|"Undisciplined local clock (1)"
block|,
literal|"LOCAL"
block|}
block|,
block|{
name|REFCLK_GPS_TRAK
block|,
literal|"TRAK 8810 GPS Receiver (2)"
block|,
literal|"GPS_TRAK"
block|}
block|,
block|{
name|REFCLK_WWV_PST
block|,
literal|"PSTI/Traconex WWV/WWVH Receiver (3)"
block|,
literal|"WWV_PST"
block|}
block|,
block|{
name|REFCLK_SPECTRACOM
block|,
literal|"Spectracom (generic) Receivers (4)"
block|,
literal|"SPECTRACOM"
block|}
block|,
block|{
name|REFCLK_TRUETIME
block|,
literal|"TrueTime (generic) Receivers (5)"
block|,
literal|"TRUETIME"
block|}
block|,
block|{
name|REFCLK_IRIG_AUDIO
block|,
literal|"IRIG Audio Decoder (6)"
block|,
literal|"IRIG_AUDIO"
block|}
block|,
block|{
name|REFCLK_CHU_AUDIO
block|,
literal|"CHU Audio Demodulator/Decoder (7)"
block|,
literal|"CHU_AUDIO"
block|}
block|,
block|{
name|REFCLK_PARSE
block|,
literal|"Generic reference clock driver (8)"
block|,
literal|"GENERIC"
block|}
block|,
block|{
name|REFCLK_GPS_MX4200
block|,
literal|"Magnavox MX4200 GPS Receiver (9)"
block|,
literal|"GPS_MX4200"
block|}
block|,
block|{
name|REFCLK_GPS_AS2201
block|,
literal|"Austron 2201A GPS Receiver (10)"
block|,
literal|"GPS_AS2201"
block|}
block|,
block|{
name|REFCLK_GPS_ARBITER
block|,
literal|"Arbiter 1088A/B GPS Receiver (11)"
block|,
literal|"GPS_ARBITER"
block|}
block|,
block|{
name|REFCLK_IRIG_TPRO
block|,
literal|"KSI/Odetics TPRO/S IRIG Interface (12)"
block|,
literal|"IRIG_TPRO"
block|}
block|,
block|{
name|REFCLK_ATOM_LEITCH
block|,
literal|"Leitch CSD 5300 Master Clock Controller (13)"
block|,
literal|"ATOM_LEITCH"
block|}
block|,
block|{
name|REFCLK_MSF_EES
block|,
literal|"EES M201 MSF Receiver (14)"
block|,
literal|"MSF_EES"
block|}
block|,
block|{
name|REFCLK_GPSTM_TRUE
block|,
literal|"TrueTime (old GPSTM driver) Receiver (15)"
block|,
literal|"GPSTM_TRUE"
block|}
block|,
block|{
name|REFCLK_IRIG_BANCOMM
block|,
literal|"Bancomm GPS/IRIG Receiver (16)"
block|,
literal|"GPS_BANC"
block|}
block|,
block|{
name|REFCLK_GPS_DATUM
block|,
literal|"Datum Precision Time System (17)"
block|,
literal|"GPS_DATUM"
block|}
block|,
block|{
name|REFCLK_NIST_ACTS
block|,
literal|"NIST Automated Computer Time Service (18)"
block|,
literal|"ACTS_NIST"
block|}
block|,
block|{
name|REFCLK_WWV_HEATH
block|,
literal|"Heath WWV/WWVH Receiver (19)"
block|,
literal|"WWV_HEATH"
block|}
block|,
block|{
name|REFCLK_GPS_NMEA
block|,
literal|"Generic NMEA GPS Receiver (20)"
block|,
literal|"GPS_NMEA"
block|}
block|,
block|{
name|REFCLK_GPS_VME
block|,
literal|"TrueTime GPS-VME Interface (21)"
block|,
literal|"GPS_VME"
block|}
block|,
block|{
name|REFCLK_ATOM_PPS
block|,
literal|"PPS Clock Discipline (22)"
block|,
literal|"PPS"
block|}
block|,
block|{
name|REFCLK_PTB_ACTS
block|,
literal|"PTB Automated Computer Time Service (23)"
block|,
literal|"ACTS_PTB"
block|}
block|,
block|{
name|REFCLK_USNO
block|,
literal|"Naval Observatory dialup (24)"
block|,
literal|"ACTS_USNO"
block|}
block|,
block|{
name|REFCLK_TRUETIME
block|,
literal|"TrueTime (generic) Receivers (25)"
block|,
literal|"TRUETIME"
block|}
block|,
block|{
name|REFCLK_GPS_HP
block|,
literal|"HP 58503A GPS Time& Frequency Receiver (26)"
block|,
literal|"GPS_HP"
block|}
block|,
block|{
name|REFCLK_ARCRON_MSF
block|,
literal|"ARCRON MSF (and DCF77) Receiver (27)"
block|,
literal|"MSF_ARCRON"
block|}
block|,
block|{
name|REFCLK_SHM
block|,
literal|"Clock attached thru shared Memory (28)"
block|,
literal|"SHM"
block|}
block|,
block|{
name|REFCLK_PALISADE
block|,
literal|"Trimble Navigation Palisade GPS (29)"
block|,
literal|"GPS_PALISADE"
block|}
block|,
block|{
name|REFCLK_ONCORE
block|,
literal|"Motorola UT Oncore GPS (30)"
block|,
literal|"GPS_ONCORE"
block|}
block|,
block|{
name|REFCLK_GPS_JUPITER
block|,
literal|"Rockwell Jupiter GPS (31)"
block|,
literal|"GPS_JUPITER"
block|}
block|,
block|{
name|REFCLK_CHRONOLOG
block|,
literal|"Chrono-log K (32)"
block|,
literal|"CHRONOLOG"
block|}
block|,
block|{
name|REFCLK_DUMBCLOCK
block|,
literal|"Dumb generic hh:mm:ss local clock (33)"
block|,
literal|"DUMBCLOCK"
block|}
block|,
block|{
name|REFCLK_ULINK
block|,
literal|"Ultralink M320 WWVB receiver (34)"
block|,
literal|"ULINK_M320"
block|}
block|,
block|{
name|REFCLK_PCF
block|,
literal|"Conrad parallel port radio clock (35)"
block|,
literal|"PCF"
block|}
block|,
block|{
name|REFCLK_WWV_AUDIO
block|,
literal|"WWV/H Audio Demodulator/Decoder (36)"
block|,
literal|"WWV_AUDIO"
block|}
block|,
block|{
name|REFCLK_FG
block|,
literal|"Forum Graphic GPS Dating Station (37)"
block|,
literal|"GPS_FG"
block|}
block|,
block|{
name|REFCLK_HOPF_SERIAL
block|,
literal|"hopf Elektronic serial line receiver (38)"
block|,
literal|"HOPF_S"
block|}
block|,
block|{
name|REFCLK_HOPF_PCI
block|,
literal|"hopf Elektronic PCI receiver (39)"
block|,
literal|"HOPF_P"
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|""
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|clockname
parameter_list|(
name|int
name|num
parameter_list|)
block|{
specifier|register
name|struct
name|clktype
modifier|*
name|clk
decl_stmt|;
for|for
control|(
name|clk
operator|=
name|clktypes
init|;
name|clk
operator|->
name|code
operator|!=
operator|-
literal|1
condition|;
name|clk
operator|++
control|)
block|{
if|if
condition|(
name|num
operator|==
name|clk
operator|->
name|code
condition|)
return|return
operator|(
name|clk
operator|->
name|abbrev
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

