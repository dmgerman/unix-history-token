begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2006 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_function_decl
specifier|static
name|void
name|get_statistics
parameter_list|(
specifier|const
name|char
modifier|*
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
modifier|*
name|argv
parameter_list|)
block|{
name|get_statistics
argument_list|(
operator|(
name|argc
operator|>
literal|1
operator|)
condition|?
name|argv
index|[
literal|1
index|]
else|:
literal|"ipw0"
argument_list|)
expr_stmt|;
return|return
name|EX_OK
return|;
block|}
end_function

begin_struct
struct|struct
name|statistic
block|{
name|int
name|index
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|int
name|unit
decl_stmt|;
define|#
directive|define
name|INT
value|1
define|#
directive|define
name|HEX
value|2
define|#
directive|define
name|MASK
value|HEX
define|#
directive|define
name|PERCENTAGE
value|3
define|#
directive|define
name|BOOL
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*-   * TIM  = Traffic Information Message  * DTIM = Delivery TIM  * ATIM = Announcement TIM  * PSP  = Power Save Poll  * RTS  = Request To Send  * CTS  = Clear To Send  * RSSI = Received Signal Strength Indicator  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|statistic
name|tbl
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"Number of frames submitted for transfer"
block|,
name|INT
block|}
block|,
block|{
literal|2
block|,
literal|"Number of frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|3
block|,
literal|"Number of unicast frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|4
block|,
literal|"Number of unicast frames transmitted at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|5
block|,
literal|"Number of unicast frames transmitted at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|6
block|,
literal|"Number of unicast frames transmitted at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|7
block|,
literal|"Number of unicast frames transmitted at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|13
block|,
literal|"Number of multicast frames transmitted at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|14
block|,
literal|"Number of multicast frames transmitted at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|15
block|,
literal|"Number of multicast frames transmitted at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|16
block|,
literal|"Number of multicast frames transmitted at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|21
block|,
literal|"Number of null frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|22
block|,
literal|"Number of RTS frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|23
block|,
literal|"Number of CTS frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|24
block|,
literal|"Number of ACK frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|25
block|,
literal|"Number of association requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|26
block|,
literal|"Number of association responses transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|27
block|,
literal|"Number of reassociation requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|28
block|,
literal|"Number of reassociation responses transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|29
block|,
literal|"Number of probe requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|30
block|,
literal|"Number of probe reponses transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|31
block|,
literal|"Number of beacons transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|32
block|,
literal|"Number of ATIM frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|33
block|,
literal|"Number of disassociation requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|34
block|,
literal|"Number of authentication requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|35
block|,
literal|"Number of deauthentication requests transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|41
block|,
literal|"Number of bytes transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|42
block|,
literal|"Number of transmission retries"
block|,
name|INT
block|}
block|,
block|{
literal|43
block|,
literal|"Number of transmission retries at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|44
block|,
literal|"Number of transmission retries at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|45
block|,
literal|"Number of transmission retries at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|46
block|,
literal|"Number of transmission retries at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|51
block|,
literal|"Number of transmission failures"
block|,
name|INT
block|}
block|,
block|{
literal|54
block|,
literal|"Number of transmission aborted due to slow DMA setup"
block|,
name|INT
block|}
block|,
block|{
literal|56
block|,
literal|"Number of disassociation failures"
block|,
name|INT
block|}
block|,
block|{
literal|58
block|,
literal|"Number of spanning tree frames transmitted"
block|,
name|INT
block|}
block|,
block|{
literal|59
block|,
literal|"Number of transmission errors due to missing ACK"
block|,
name|INT
block|}
block|,
block|{
literal|61
block|,
literal|"Number of frames received"
block|,
name|INT
block|}
block|,
block|{
literal|62
block|,
literal|"Number of unicast frames received"
block|,
name|INT
block|}
block|,
block|{
literal|63
block|,
literal|"Number of unicast frames received at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|64
block|,
literal|"Number of unicast frames received at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|65
block|,
literal|"Number of unicast frames received at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|66
block|,
literal|"Number of unicast frames received at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|71
block|,
literal|"Number of multicast frames received"
block|,
name|INT
block|}
block|,
block|{
literal|72
block|,
literal|"Number of multicast frames received at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|73
block|,
literal|"Number of multicast frames received at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|74
block|,
literal|"Number of multicast frames received at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|75
block|,
literal|"Number of multicast frames received at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|80
block|,
literal|"Number of null frames received"
block|,
name|INT
block|}
block|,
block|{
literal|81
block|,
literal|"Number of poll frames received"
block|,
name|INT
block|}
block|,
block|{
literal|82
block|,
literal|"Number of RTS frames received"
block|,
name|INT
block|}
block|,
block|{
literal|83
block|,
literal|"Number of CTS frames received"
block|,
name|INT
block|}
block|,
block|{
literal|84
block|,
literal|"Number of ACK frames received"
block|,
name|INT
block|}
block|,
block|{
literal|85
block|,
literal|"Number of CF-End frames received"
block|,
name|INT
block|}
block|,
block|{
literal|86
block|,
literal|"Number of CF-End + CF-Ack frames received"
block|,
name|INT
block|}
block|,
block|{
literal|87
block|,
literal|"Number of association requests received"
block|,
name|INT
block|}
block|,
block|{
literal|88
block|,
literal|"Number of association responses received"
block|,
name|INT
block|}
block|,
block|{
literal|89
block|,
literal|"Number of reassociation requests received"
block|,
name|INT
block|}
block|,
block|{
literal|90
block|,
literal|"Number of reassociation responses received"
block|,
name|INT
block|}
block|,
block|{
literal|91
block|,
literal|"Number of probe requests received"
block|,
name|INT
block|}
block|,
block|{
literal|92
block|,
literal|"Number of probe reponses received"
block|,
name|INT
block|}
block|,
block|{
literal|93
block|,
literal|"Number of beacons received"
block|,
name|INT
block|}
block|,
block|{
literal|94
block|,
literal|"Number of ATIM frames received"
block|,
name|INT
block|}
block|,
block|{
literal|95
block|,
literal|"Number of disassociation requests received"
block|,
name|INT
block|}
block|,
block|{
literal|96
block|,
literal|"Number of authentication requests received"
block|,
name|INT
block|}
block|,
block|{
literal|97
block|,
literal|"Number of deauthentication requests received"
block|,
name|INT
block|}
block|,
block|{
literal|101
block|,
literal|"Number of bytes received"
block|,
name|INT
block|}
block|,
block|{
literal|102
block|,
literal|"Number of frames with a bad CRC received"
block|,
name|INT
block|}
block|,
block|{
literal|103
block|,
literal|"Number of frames with a bad CRC received at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|104
block|,
literal|"Number of frames with a bad CRC received at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|105
block|,
literal|"Number of frames with a bad CRC received at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|106
block|,
literal|"Number of frames with a bad CRC received at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|112
block|,
literal|"Number of duplicated frames received at 1Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|113
block|,
literal|"Number of duplicated frames received at 2Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|114
block|,
literal|"Number of duplicated frames received at 5.5Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|115
block|,
literal|"Number of duplicated frames received at 11Mb/s"
block|,
name|INT
block|}
block|,
block|{
literal|119
block|,
literal|"Number of duplicated frames received"
block|,
name|INT
block|}
block|,
block|{
literal|123
block|,
literal|"Number of frames with a bad protocol received"
block|,
name|INT
block|}
block|,
block|{
literal|124
block|,
literal|"Boot time"
block|,
name|INT
block|}
block|,
block|{
literal|125
block|,
literal|"Number of frames dropped due to no buffer"
block|,
name|INT
block|}
block|,
block|{
literal|126
block|,
literal|"Number of frames dropped due to slow DMA setup"
block|,
name|INT
block|}
block|,
block|{
literal|128
block|,
literal|"Number of frames dropped due to missing fragment"
block|,
name|INT
block|}
block|,
block|{
literal|129
block|,
literal|"Number of frames dropped due to non-seq fragment"
block|,
name|INT
block|}
block|,
block|{
literal|130
block|,
literal|"Number of frames dropped due to missing first frame"
block|,
name|INT
block|}
block|,
block|{
literal|131
block|,
literal|"Number of frames dropped due to incomplete frame"
block|,
name|INT
block|}
block|,
block|{
literal|137
block|,
literal|"Number of PSP adapter suspends"
block|,
name|INT
block|}
block|,
block|{
literal|138
block|,
literal|"Number of PSP beacon timeouts"
block|,
name|INT
block|}
block|,
block|{
literal|139
block|,
literal|"Number of PSP PsPollResponse timeouts"
block|,
name|INT
block|}
block|,
block|{
literal|140
block|,
literal|"Number of PSP mcast frame timeouts"
block|,
name|INT
block|}
block|,
block|{
literal|141
block|,
literal|"Number of PSP DTIM frames received"
block|,
name|INT
block|}
block|,
block|{
literal|142
block|,
literal|"Number of PSP TIM frames received"
block|,
name|INT
block|}
block|,
block|{
literal|143
block|,
literal|"PSP station Id"
block|,
name|INT
block|}
block|,
block|{
literal|147
block|,
literal|"RTC time of last association"
block|,
name|INT
block|}
block|,
block|{
literal|148
block|,
literal|"Percentage of missed beacons"
block|,
name|PERCENTAGE
block|}
block|,
block|{
literal|149
block|,
literal|"Percentage of missed transmission retries"
block|,
name|PERCENTAGE
block|}
block|,
block|{
literal|151
block|,
literal|"Number of access points in access points table"
block|,
name|INT
block|}
block|,
block|{
literal|153
block|,
literal|"Number of associations"
block|,
name|INT
block|}
block|,
block|{
literal|154
block|,
literal|"Number of association failures"
block|,
name|INT
block|}
block|,
block|{
literal|156
block|,
literal|"Number of full scans"
block|,
name|INT
block|}
block|,
block|{
literal|157
block|,
literal|"Card disabled"
block|,
name|BOOL
block|}
block|,
block|{
literal|160
block|,
literal|"RSSI at time of association"
block|,
name|INT
block|}
block|,
block|{
literal|161
block|,
literal|"Number of reassociations due to no probe response"
block|,
name|INT
block|}
block|,
block|{
literal|162
block|,
literal|"Number of reassociations due to poor line quality"
block|,
name|INT
block|}
block|,
block|{
literal|163
block|,
literal|"Number of reassociations due to load"
block|,
name|INT
block|}
block|,
block|{
literal|164
block|,
literal|"Number of reassociations due to access point RSSI level"
block|,
name|INT
block|}
block|,
block|{
literal|165
block|,
literal|"Number of reassociations due to load leveling"
block|,
name|INT
block|}
block|,
block|{
literal|170
block|,
literal|"Number of times authentication failed"
block|,
name|INT
block|}
block|,
block|{
literal|171
block|,
literal|"Number of times authentication response failed"
block|,
name|INT
block|}
block|,
block|{
literal|172
block|,
literal|"Number of entries in association table"
block|,
name|INT
block|}
block|,
block|{
literal|173
block|,
literal|"Average RSSI"
block|,
name|INT
block|}
block|,
block|{
literal|176
block|,
literal|"Self test status"
block|,
name|INT
block|}
block|,
block|{
literal|177
block|,
literal|"Power mode"
block|,
name|INT
block|}
block|,
block|{
literal|178
block|,
literal|"Power index"
block|,
name|INT
block|}
block|,
block|{
literal|179
block|,
literal|"IEEE country code"
block|,
name|HEX
block|}
block|,
block|{
literal|180
block|,
literal|"Channels supported for this country"
block|,
name|MASK
block|}
block|,
block|{
literal|181
block|,
literal|"Number of adapter warm resets"
block|,
name|INT
block|}
block|,
block|{
literal|182
block|,
literal|"Beacon interval"
block|,
name|INT
block|}
block|,
block|{
literal|184
block|,
literal|"Princeton version"
block|,
name|INT
block|}
block|,
block|{
literal|185
block|,
literal|"Antenna diversity disabled"
block|,
name|BOOL
block|}
block|,
if|#
directive|if
name|notset
block|{
literal|186
block|,
literal|"CCA RSSI"
block|,
name|INT
block|}
block|,
block|{
literal|187
block|,
literal|"Number of times EEPROM updated"
block|,
name|INT
block|}
block|,
endif|#
directive|endif
block|{
literal|188
block|,
literal|"Beacon intervals between DTIM"
block|,
name|INT
block|}
block|,
block|{
literal|189
block|,
literal|"Current channel"
block|,
name|INT
block|}
block|,
block|{
literal|190
block|,
literal|"RTC time"
block|,
name|INT
block|}
block|,
block|{
literal|191
block|,
literal|"Operating mode"
block|,
name|INT
block|}
block|,
block|{
literal|192
block|,
literal|"Transmission rate"
block|,
name|HEX
block|}
block|,
block|{
literal|193
block|,
literal|"Supported transmission rates"
block|,
name|MASK
block|}
block|,
block|{
literal|194
block|,
literal|"ATIM window"
block|,
name|INT
block|}
block|,
block|{
literal|195
block|,
literal|"Supported basic transmission rates"
block|,
name|MASK
block|}
block|,
block|{
literal|196
block|,
literal|"Adapter highest rate"
block|,
name|HEX
block|}
block|,
block|{
literal|197
block|,
literal|"Access point highest rate"
block|,
name|HEX
block|}
block|,
block|{
literal|198
block|,
literal|"Management frame capability"
block|,
name|BOOL
block|}
block|,
block|{
literal|199
block|,
literal|"Type of authentication"
block|,
name|INT
block|}
block|,
block|{
literal|200
block|,
literal|"Adapter card platform type"
block|,
name|INT
block|}
block|,
block|{
literal|201
block|,
literal|"RTS threshold"
block|,
name|INT
block|}
block|,
block|{
literal|202
block|,
literal|"International mode"
block|,
name|BOOL
block|}
block|,
block|{
literal|203
block|,
literal|"Fragmentation threshold"
block|,
name|INT
block|}
block|,
block|{
literal|209
block|,
literal|"MAC version"
block|,
name|INT
block|}
block|,
block|{
literal|210
block|,
literal|"MAC revision"
block|,
name|INT
block|}
block|,
block|{
literal|211
block|,
literal|"Radio version"
block|,
name|INT
block|}
block|,
block|{
literal|212
block|,
literal|"NIC manufacturing date+time"
block|,
name|INT
block|}
block|,
block|{
literal|213
block|,
literal|"Microcode version"
block|,
name|INT
block|}
block|,
block|{
literal|214
block|,
literal|"RF switch state"
block|,
name|INT
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|get_statistics
parameter_list|(
specifier|const
name|char
modifier|*
name|iface
parameter_list|)
block|{
specifier|static
name|uint32_t
name|stats
index|[
literal|256
index|]
decl_stmt|;
specifier|const
name|struct
name|statistic
modifier|*
name|stat
decl_stmt|;
name|char
name|oid
index|[
literal|32
index|]
decl_stmt|;
name|int
name|ifaceno
decl_stmt|,
name|len
decl_stmt|;
if|if
condition|(
name|sscanf
argument_list|(
name|iface
argument_list|,
literal|"ipw%u"
argument_list|,
operator|&
name|ifaceno
argument_list|)
operator|!=
literal|1
condition|)
name|errx
argument_list|(
name|EX_DATAERR
argument_list|,
literal|"Invalid interface name '%s'"
argument_list|,
name|iface
argument_list|)
expr_stmt|;
name|len
operator|=
sizeof|sizeof
name|stats
expr_stmt|;
name|snprintf
argument_list|(
name|oid
argument_list|,
sizeof|sizeof
name|oid
argument_list|,
literal|"dev.ipw.%u.stats"
argument_list|,
name|ifaceno
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctlbyname
argument_list|(
name|oid
argument_list|,
name|stats
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
name|EX_OSERR
argument_list|,
literal|"Can't retrieve statistics"
argument_list|)
expr_stmt|;
for|for
control|(
name|stat
operator|=
name|tbl
init|;
name|stat
operator|->
name|index
operator|!=
literal|0
condition|;
name|stat
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"%-60s["
argument_list|,
name|stat
operator|->
name|desc
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|stat
operator|->
name|unit
condition|)
block|{
case|case
name|INT
case|:
name|printf
argument_list|(
literal|"%u"
argument_list|,
name|stats
index|[
name|stat
operator|->
name|index
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
name|BOOL
case|:
name|printf
argument_list|(
name|stats
index|[
name|stat
operator|->
name|index
index|]
condition|?
literal|"true"
else|:
literal|"false"
argument_list|)
expr_stmt|;
break|break;
case|case
name|PERCENTAGE
case|:
name|printf
argument_list|(
literal|"%u%%"
argument_list|,
name|stats
index|[
name|stat
operator|->
name|index
index|]
argument_list|)
expr_stmt|;
break|break;
case|case
name|HEX
case|:
default|default:
name|printf
argument_list|(
literal|"0x%08X"
argument_list|,
name|stats
index|[
name|stat
operator|->
name|index
index|]
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"]\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

