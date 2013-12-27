begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Status codes for block read/write commands, etc.  *  * XXX many of these would not normally be returned, as they are  * relevant only to FSA operations.  */
end_comment

begin_define
unit|static const struct aac_code_lookup aac_command_status_table[] = { 	{"OK",					ST_OK}, 	{"operation not permitted",		ST_PERM}, 	{"not found",				ST_NOENT}, 	{"I/O error",				ST_IO}, 	{"device not configured",		ST_NXIO}, 	{"too big",				ST_E2BIG}, 	{"permission denied",			ST_ACCES}, 	{"file exists",				ST_EXIST}, 	{"cross-device link",			ST_XDEV}, 	{"operation not supported by device",	ST_NODEV}, 	{"not a directory",			ST_NOTDIR}, 	{"is a directory",			ST_ISDIR}, 	{"invalid argument",			ST_INVAL}, 	{"file too large",			ST_FBIG}, 	{"no space on device",			ST_NOSPC}, 	{"readonly filesystem",			ST_ROFS}, 	{"too many links",			ST_MLINK}, 	{"operation would block",		ST_WOULDBLOCK}, 	{"file name too long",			ST_NAMETOOLONG}, 	{"directory not empty",			ST_NOTEMPTY}, 	{"quota exceeded",			ST_DQUOT}, 	{"stale file handle",			ST_STALE}, 	{"too many levels of remote in path",	ST_REMOTE}, 	{"device busy (spinning up)",		ST_NOT_READY}, 	{"bad file handle",			ST_BADHANDLE}, 	{"not sync",				ST_NOT_SYNC}, 	{"bad cookie",				ST_BAD_COOKIE}, 	{"operation not supported",		ST_NOTSUPP}, 	{"too small",				ST_TOOSMALL}, 	{"server fault",			ST_SERVERFAULT}, 	{"bad type",				ST_BADTYPE}, 	{"jukebox",				ST_JUKEBOX}, 	{"not mounted",				ST_NOTMOUNTED}, 	{"in maintenance mode",			ST_MAINTMODE}, 	{"stale ACL",				ST_STALEACL}, 	{"bus reset - command aborted",		ST_BUS_RESET}, 	{NULL, 					0}, 	{"unknown command status",		0} };
define|#
directive|define
name|AAC_COMMAND_STATUS
parameter_list|(
name|x
parameter_list|)
value|aac_describe_code(aac_command_status_table, x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
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
specifier|const
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
specifier|const
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

