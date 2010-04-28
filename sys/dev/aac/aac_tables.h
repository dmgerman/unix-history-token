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
name|ST_OK
block|}
block|,
block|{
literal|"operation not permitted"
block|,
name|ST_PERM
block|}
block|,
block|{
literal|"not found"
block|,
name|ST_NOENT
block|}
block|,
block|{
literal|"I/O error"
block|,
name|ST_IO
block|}
block|,
block|{
literal|"device not configured"
block|,
name|ST_NXIO
block|}
block|,
block|{
literal|"too big"
block|,
name|ST_E2BIG
block|}
block|,
block|{
literal|"permission denied"
block|,
name|ST_ACCES
block|}
block|,
block|{
literal|"file exists"
block|,
name|ST_EXIST
block|}
block|,
block|{
literal|"cross-device link"
block|,
name|ST_XDEV
block|}
block|,
block|{
literal|"operation not supported by device"
block|,
name|ST_NODEV
block|}
block|,
block|{
literal|"not a directory"
block|,
name|ST_NOTDIR
block|}
block|,
block|{
literal|"is a directory"
block|,
name|ST_ISDIR
block|}
block|,
block|{
literal|"invalid argument"
block|,
name|ST_INVAL
block|}
block|,
block|{
literal|"file too large"
block|,
name|ST_FBIG
block|}
block|,
block|{
literal|"no space on device"
block|,
name|ST_NOSPC
block|}
block|,
block|{
literal|"readonly filesystem"
block|,
name|ST_ROFS
block|}
block|,
block|{
literal|"too many links"
block|,
name|ST_MLINK
block|}
block|,
block|{
literal|"operation would block"
block|,
name|ST_WOULDBLOCK
block|}
block|,
block|{
literal|"file name too long"
block|,
name|ST_NAMETOOLONG
block|}
block|,
block|{
literal|"directory not empty"
block|,
name|ST_NOTEMPTY
block|}
block|,
block|{
literal|"quota exceeded"
block|,
name|ST_DQUOT
block|}
block|,
block|{
literal|"stale file handle"
block|,
name|ST_STALE
block|}
block|,
block|{
literal|"too many levels of remote in path"
block|,
name|ST_REMOTE
block|}
block|,
block|{
literal|"device busy (spinning up)"
block|,
name|ST_NOT_READY
block|}
block|,
block|{
literal|"bad file handle"
block|,
name|ST_BADHANDLE
block|}
block|,
block|{
literal|"not sync"
block|,
name|ST_NOT_SYNC
block|}
block|,
block|{
literal|"bad cookie"
block|,
name|ST_BAD_COOKIE
block|}
block|,
block|{
literal|"operation not supported"
block|,
name|ST_NOTSUPP
block|}
block|,
block|{
literal|"too small"
block|,
name|ST_TOOSMALL
block|}
block|,
block|{
literal|"server fault"
block|,
name|ST_SERVERFAULT
block|}
block|,
block|{
literal|"bad type"
block|,
name|ST_BADTYPE
block|}
block|,
block|{
literal|"jukebox"
block|,
name|ST_JUKEBOX
block|}
block|,
block|{
literal|"not mounted"
block|,
name|ST_NOTMOUNTED
block|}
block|,
block|{
literal|"in maintenance mode"
block|,
name|ST_MAINTMODE
block|}
block|,
block|{
literal|"stale ACL"
block|,
name|ST_STALEACL
block|}
block|,
block|{
literal|"bus reset - command aborted"
block|,
name|ST_BUS_RESET
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
literal|"i960 80303"
block|,
name|CPUI960_80303
block|}
block|,
block|{
literal|"StrongARM SA110"
block|,
name|CPUARM_SA110
block|}
block|,
block|{
literal|"PPC603e"
block|,
name|CPUPPC_603e
block|}
block|,
block|{
literal|"XScale 80321"
block|,
name|CPU_XSCALE_80321
block|}
block|,
block|{
literal|"MIPS 4KC"
block|,
name|CPU_MIPS_4KC
block|}
block|,
block|{
literal|"MIPS 5KC"
block|,
name|CPU_MIPS_5KC
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
literal|"RAID 0/1"
block|,
name|CT_RAID10
block|}
block|,
block|{
literal|"RAID 0/0"
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
literal|"RAID 0/5"
block|,
name|CT_RAID50
block|}
block|,
block|{
literal|"RAID 5D"
block|,
name|CT_RAID5D
block|}
block|,
block|{
literal|"RAID 0/5D"
block|,
name|CT_RAID5D0
block|}
block|,
block|{
literal|"RAID 1E"
block|,
name|CT_RAID1E
block|}
block|,
block|{
literal|"RAID 6"
block|,
name|CT_RAID6
block|}
block|,
block|{
literal|"RAID 0/6"
block|,
name|CT_RAID60
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

