begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Status codes for block read/write commands, etc.  *  * XXX many of these would not normally be returned, as they are  * relevant only to FSA operations.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|aac_code_lookup
name|aac_command_status_table
index|[]
init|=
block|{
block|{
literal|"OK"
block|,
literal|0
block|}
block|,
block|{
literal|"operation not permitted"
block|,
literal|1
block|}
block|,
block|{
literal|"not found"
block|,
literal|2
block|}
block|,
block|{
literal|"I/O error"
block|,
literal|5
block|}
block|,
block|{
literal|"device not configured"
block|,
literal|6
block|}
block|,
block|{
literal|"too big"
block|,
literal|7
block|}
block|,
block|{
literal|"permission denoed"
block|,
literal|13
block|}
block|,
block|{
literal|"file exists"
block|,
literal|17
block|}
block|,
block|{
literal|"cross-device link"
block|,
literal|18
block|}
block|,
block|{
literal|"operation not supported by device"
block|,
literal|19
block|}
block|,
block|{
literal|"not a directory"
block|,
literal|20
block|}
block|,
block|{
literal|"is a directory"
block|,
literal|21
block|}
block|,
block|{
literal|"invalid argument"
block|,
literal|22
block|}
block|,
block|{
literal|"file too large"
block|,
literal|27
block|}
block|,
block|{
literal|"no space on device"
block|,
literal|28
block|}
block|,
block|{
literal|"readonly filesystem"
block|,
literal|30
block|}
block|,
block|{
literal|"too many links"
block|,
literal|31
block|}
block|,
block|{
literal|"operation would block"
block|,
literal|35
block|}
block|,
block|{
literal|"file name too long"
block|,
literal|63
block|}
block|,
block|{
literal|"directory not empty"
block|,
literal|66
block|}
block|,
block|{
literal|"quota exceeded"
block|,
literal|69
block|}
block|,
block|{
literal|"stale file handle"
block|,
literal|70
block|}
block|,
block|{
literal|"too many levels of remote in path"
block|,
literal|71
block|}
block|,
block|{
literal|"bad file handle"
block|,
literal|10001
block|}
block|,
block|{
literal|"not sync"
block|,
literal|10002
block|}
block|,
block|{
literal|"bad cookie"
block|,
literal|10003
block|}
block|,
block|{
literal|"operation not supported"
block|,
literal|10004
block|}
block|,
block|{
literal|"too small"
block|,
literal|10005
block|}
block|,
block|{
literal|"server fault"
block|,
literal|10006
block|}
block|,
block|{
literal|"bad type"
block|,
literal|10007
block|}
block|,
block|{
literal|"jukebox"
block|,
literal|10008
block|}
block|,
block|{
literal|"not mounted"
block|,
literal|10009
block|}
block|,
block|{
literal|"in maintenace mode"
block|,
literal|10010
block|}
block|,
block|{
literal|"stale ACL"
block|,
literal|10011
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown command status"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AAC_COMMAND_STATUS
parameter_list|(
name|x
parameter_list|)
value|aac_describe_code(aac_command_status_table, x)
end_define

begin_decl_stmt
specifier|static
name|struct
name|aac_code_lookup
name|aac_cpu_variant
index|[]
init|=
block|{
block|{
literal|"i960JX"
block|,
name|CPUI960_JX
block|}
block|,
block|{
literal|"i960CX"
block|,
name|CPUI960_CX
block|}
block|,
block|{
literal|"i960HX"
block|,
name|CPUI960_HX
block|}
block|,
block|{
literal|"i960RX"
block|,
name|CPUI960_RX
block|}
block|,
block|{
literal|"StrongARM SA110"
block|,
name|CPUARM_SA110
block|}
block|,
block|{
literal|"PowerPC 603e"
block|,
name|CPUPPC_603e
block|}
block|,
block|{
literal|"Unknown StrongARM"
block|,
name|CPUARM_xxx
block|}
block|,
block|{
literal|"Unknown PowerPC"
block|,
name|CPUPPC_xxx
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"Unknown processor"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aac_code_lookup
name|aac_battery_platform
index|[]
init|=
block|{
block|{
literal|"required battery present"
block|,
name|PLATFORM_BAT_REQ_PRESENT
block|}
block|,
block|{
literal|"REQUIRED BATTERY NOT PRESENT"
block|,
name|PLATFORM_BAT_REQ_NOTPRESENT
block|}
block|,
block|{
literal|"optional battery present"
block|,
name|PLATFORM_BAT_OPT_PRESENT
block|}
block|,
block|{
literal|"optional battery not installed"
block|,
name|PLATFORM_BAT_OPT_NOTPRESENT
block|}
block|,
block|{
literal|"no battery support"
block|,
name|PLATFORM_BAT_NOT_SUPPORTED
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown battery platform"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aac_code_lookup
name|aac_container_types
index|[]
init|=
block|{
block|{
literal|"Volume"
block|,
name|CT_VOLUME
block|}
block|,
block|{
literal|"RAID 1 (Mirror)"
block|,
name|CT_MIRROR
block|}
block|,
block|{
literal|"RAID 0 (Stripe)"
block|,
name|CT_STRIPE
block|}
block|,
block|{
literal|"RAID 5"
block|,
name|CT_RAID5
block|}
block|,
block|{
literal|"SSRW"
block|,
name|CT_SSRW
block|}
block|,
block|{
literal|"SSRO"
block|,
name|CT_SSRO
block|}
block|,
block|{
literal|"Morph"
block|,
name|CT_MORPH
block|}
block|,
block|{
literal|"Passthrough"
block|,
name|CT_PASSTHRU
block|}
block|,
block|{
literal|"RAID 4"
block|,
name|CT_RAID4
block|}
block|,
block|{
literal|"RAID 10"
block|,
name|CT_RAID10
block|}
block|,
block|{
literal|"RAID 00"
block|,
name|CT_RAID00
block|}
block|,
block|{
literal|"Volume of Mirrors"
block|,
name|CT_VOLUME_OF_MIRRORS
block|}
block|,
block|{
literal|"Pseudo RAID 3"
block|,
name|CT_PSEUDO_RAID3
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

