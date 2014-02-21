begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005  *	Damien Bergamini<damien.bergamini@free.fr>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"iwi0"
argument_list|)
expr_stmt|;
return|return
name|EX_OK
return|;
block|}
end_function

begin_struct
specifier|static
specifier|const
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
block|}
name|tbl
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"Current transmission rate"
block|}
block|,
block|{
literal|2
block|,
literal|"Fragmentation threshold"
block|}
block|,
block|{
literal|3
block|,
literal|"RTS threshold"
block|}
block|,
block|{
literal|4
block|,
literal|"Number of frames submitted for transfer"
block|}
block|,
block|{
literal|5
block|,
literal|"Number of frames transmitted"
block|}
block|,
block|{
literal|6
block|,
literal|"Number of unicast frames transmitted"
block|}
block|,
block|{
literal|7
block|,
literal|"Number of unicast 802.11b frames transmitted at 1Mb/s"
block|}
block|,
block|{
literal|8
block|,
literal|"Number of unicast 802.11b frames transmitted at 2Mb/s"
block|}
block|,
block|{
literal|9
block|,
literal|"Number of unicast 802.11b frames transmitted at 5.5Mb/s"
block|}
block|,
block|{
literal|10
block|,
literal|"Number of unicast 802.11b frames transmitted at 11Mb/s"
block|}
block|,
block|{
literal|19
block|,
literal|"Number of unicast 802.11g frames transmitted at 1Mb/s"
block|}
block|,
block|{
literal|20
block|,
literal|"Number of unicast 802.11g frames transmitted at 2Mb/s"
block|}
block|,
block|{
literal|21
block|,
literal|"Number of unicast 802.11g frames transmitted at 5.5Mb/s"
block|}
block|,
block|{
literal|22
block|,
literal|"Number of unicast 802.11g frames transmitted at 6Mb/s"
block|}
block|,
block|{
literal|23
block|,
literal|"Number of unicast 802.11g frames transmitted at 9Mb/s"
block|}
block|,
block|{
literal|24
block|,
literal|"Number of unicast 802.11g frames transmitted at 11Mb/s"
block|}
block|,
block|{
literal|25
block|,
literal|"Number of unicast 802.11g frames transmitted at 12Mb/s"
block|}
block|,
block|{
literal|26
block|,
literal|"Number of unicast 802.11g frames transmitted at 18Mb/s"
block|}
block|,
block|{
literal|27
block|,
literal|"Number of unicast 802.11g frames transmitted at 24Mb/s"
block|}
block|,
block|{
literal|28
block|,
literal|"Number of unicast 802.11g frames transmitted at 36Mb/s"
block|}
block|,
block|{
literal|29
block|,
literal|"Number of unicast 802.11g frames transmitted at 48Mb/s"
block|}
block|,
block|{
literal|30
block|,
literal|"Number of unicast 802.11g frames transmitted at 54Mb/s"
block|}
block|,
block|{
literal|31
block|,
literal|"Number of multicast frames transmitted"
block|}
block|,
block|{
literal|32
block|,
literal|"Number of multicast 802.11b frames transmitted at 1Mb/s"
block|}
block|,
block|{
literal|33
block|,
literal|"Number of multicast 802.11b frames transmitted at 2Mb/s"
block|}
block|,
block|{
literal|34
block|,
literal|"Number of multicast 802.11b frames transmitted at 5.5Mb/s"
block|}
block|,
block|{
literal|35
block|,
literal|"Number of multicast 802.11b frames transmitted at 11Mb/s"
block|}
block|,
block|{
literal|44
block|,
literal|"Number of multicast 802.11g frames transmitted at 1Mb/s"
block|}
block|,
block|{
literal|45
block|,
literal|"Number of multicast 802.11g frames transmitted at 2Mb/s"
block|}
block|,
block|{
literal|46
block|,
literal|"Number of multicast 802.11g frames transmitted at 5.5Mb/s"
block|}
block|,
block|{
literal|47
block|,
literal|"Number of multicast 802.11g frames transmitted at 6Mb/s"
block|}
block|,
block|{
literal|48
block|,
literal|"Number of multicast 802.11g frames transmitted at 9Mb/s"
block|}
block|,
block|{
literal|49
block|,
literal|"Number of multicast 802.11g frames transmitted at 11Mb/s"
block|}
block|,
block|{
literal|50
block|,
literal|"Number of multicast 802.11g frames transmitted at 12Mb/s"
block|}
block|,
block|{
literal|51
block|,
literal|"Number of multicast 802.11g frames transmitted at 18Mb/s"
block|}
block|,
block|{
literal|52
block|,
literal|"Number of multicast 802.11g frames transmitted at 24Mb/s"
block|}
block|,
block|{
literal|53
block|,
literal|"Number of multicast 802.11g frames transmitted at 36Mb/s"
block|}
block|,
block|{
literal|54
block|,
literal|"Number of multicast 802.11g frames transmitted at 48Mb/s"
block|}
block|,
block|{
literal|55
block|,
literal|"Number of multicast 802.11g frames transmitted at 54Mb/s"
block|}
block|,
block|{
literal|56
block|,
literal|"Number of transmission retries"
block|}
block|,
block|{
literal|57
block|,
literal|"Number of transmission failures"
block|}
block|,
block|{
literal|58
block|,
literal|"Number of CRC errors"
block|}
block|,
block|{
literal|61
block|,
literal|"Number of full scans"
block|}
block|,
block|{
literal|62
block|,
literal|"Number of partial scans"
block|}
block|,
block|{
literal|64
block|,
literal|"Number of bytes transmitted"
block|}
block|,
block|{
literal|65
block|,
literal|"Current RSSI"
block|}
block|,
block|{
literal|66
block|,
literal|"Number of beacons received"
block|}
block|,
block|{
literal|67
block|,
literal|"Number of beacons missed"
block|}
block|,
block|{
operator|-
literal|1
block|,
name|NULL
block|}
block|}
struct|;
end_struct

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
name|size_t
name|len
decl_stmt|;
name|int
name|ifaceno
decl_stmt|;
if|if
condition|(
name|sscanf
argument_list|(
name|iface
argument_list|,
literal|"iwi%u"
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
argument_list|(
name|stats
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|oid
argument_list|,
sizeof|sizeof
argument_list|(
name|oid
argument_list|)
argument_list|,
literal|"dev.iwi.%u.stats"
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
operator|-
literal|1
condition|;
name|stat
operator|++
control|)
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%-60s[%u]\n"
argument_list|,
name|stat
operator|->
name|desc
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
end_function

end_unit

