begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* clocktypes.c,v 3.1 1993/07/06 01:08:09 jbj Exp  * Data for pretty printing clock types  */
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
literal|"local clock synchronization (1)"
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
literal|"Precision Standard Time WWV clock (3)"
block|,
literal|"WWV_PST"
block|}
block|,
block|{
name|REFCLK_WWVB_SPECTRACOM
block|,
literal|"Spectracom WWVB clock (4)"
block|,
literal|"WWVB_SPEC"
block|}
block|,
block|{
name|REFCLK_GOES_TRUETIME
block|,
literal|"True Time GPS/GOES clock (5)"
block|,
literal|"GPS_GOES_TRUE"
block|}
block|,
block|{
name|REFCLK_IRIG_AUDIO
block|,
literal|"IRIG audio decoder (6)"
block|,
literal|"IRIG_AUDIO"
block|}
block|,
block|{
name|REFCLK_CHU
block|,
literal|"Direct synced to CHU (7)"
block|,
literal|"CHU"
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
literal|"Magnavox MX4200 GPS clock (9)"
block|,
literal|"GPS_MX4200"
block|}
block|,
block|{
name|REFCLK_GPS_AS2201
block|,
literal|"Austron 2201A GPS clock (10)"
block|,
literal|"GPS_AS2201"
block|}
block|,
block|{
name|REFCLK_OMEGA_TRUETIME
block|,
literal|"TrueTime OMEGA clock (11)"
block|,
literal|"OMEGA_TRUE"
block|}
block|,
block|{
name|REFCLK_IRIG_TPRO
block|,
literal|"Odetics/KSI TPRO IRIG decoder (12)"
block|,
literal|"IRIG_TPRO"
block|}
block|,
block|{
name|REFCLK_ATOM_LEITCH
block|,
literal|"Leitch CSD 5300 controller (13)"
block|,
literal|"ATOM_LEITCH"
block|}
block|,
block|{
name|REFCLK_MSF_EES
block|,
literal|"MSF EES M201, UK (14)"
block|,
literal|"MSF_EES"
block|}
block|,
block|{
name|REFCLK_GPSTM_TRUETIME
block|,
literal|"TrueTime GPS/TM-TMD clock (15)"
block|,
literal|"GPS_TRUE"
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
name|num
parameter_list|)
name|int
name|num
decl_stmt|;
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
block|{
return|return
name|clk
operator|->
name|abbrev
return|;
block|}
block|}
return|return
name|NULL
return|;
block|}
end_function

end_unit

