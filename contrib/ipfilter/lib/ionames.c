begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: ionames.c,v 1.7 2002/01/28 06:50:46 darrenr Exp  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_decl_stmt
name|struct
name|ipopt_names
name|ionames
index|[]
init|=
block|{
block|{
name|IPOPT_NOP
block|,
literal|0x000001
block|,
literal|1
block|,
literal|"nop"
block|}
block|,
comment|/* RFC791 */
block|{
name|IPOPT_RR
block|,
literal|0x000002
block|,
literal|7
block|,
literal|"rr"
block|}
block|,
comment|/* 1 route */
block|{
name|IPOPT_ZSU
block|,
literal|0x000004
block|,
literal|3
block|,
literal|"zsu"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_MTUP
block|,
literal|0x000008
block|,
literal|3
block|,
literal|"mtup"
block|}
block|,
comment|/* RFC1191 */
block|{
name|IPOPT_MTUR
block|,
literal|0x000010
block|,
literal|3
block|,
literal|"mtur"
block|}
block|,
comment|/* RFC1191 */
block|{
name|IPOPT_ENCODE
block|,
literal|0x000020
block|,
literal|3
block|,
literal|"encode"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_TS
block|,
literal|0x000040
block|,
literal|8
block|,
literal|"ts"
block|}
block|,
comment|/* 1 TS */
block|{
name|IPOPT_TR
block|,
literal|0x000080
block|,
literal|3
block|,
literal|"tr"
block|}
block|,
comment|/* RFC1393 */
block|{
name|IPOPT_SECURITY
block|,
literal|0x000100
block|,
literal|11
block|,
literal|"sec"
block|}
block|,
comment|/* RFC1108 */
block|{
name|IPOPT_SECURITY
block|,
literal|0x000100
block|,
literal|11
block|,
literal|"sec-class"
block|}
block|,
comment|/* RFC1108 */
block|{
name|IPOPT_LSRR
block|,
literal|0x000200
block|,
literal|7
block|,
literal|"lsrr"
block|}
block|,
comment|/* 1 route */
block|{
name|IPOPT_E_SEC
block|,
literal|0x000400
block|,
literal|3
block|,
literal|"e-sec"
block|}
block|,
comment|/* RFC1108 */
block|{
name|IPOPT_CIPSO
block|,
literal|0x000800
block|,
literal|3
block|,
literal|"cipso"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_SATID
block|,
literal|0x001000
block|,
literal|4
block|,
literal|"satid"
block|}
block|,
comment|/* RFC791 */
block|{
name|IPOPT_SSRR
block|,
literal|0x002000
block|,
literal|7
block|,
literal|"ssrr"
block|}
block|,
comment|/* 1 route */
block|{
name|IPOPT_ADDEXT
block|,
literal|0x004000
block|,
literal|3
block|,
literal|"addext"
block|}
block|,
comment|/* IPv7 ?? */
block|{
name|IPOPT_VISA
block|,
literal|0x008000
block|,
literal|3
block|,
literal|"visa"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_IMITD
block|,
literal|0x010000
block|,
literal|3
block|,
literal|"imitd"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_EIP
block|,
literal|0x020000
block|,
literal|3
block|,
literal|"eip"
block|}
block|,
comment|/* RFC1385 */
block|{
name|IPOPT_FINN
block|,
literal|0x040000
block|,
literal|3
block|,
literal|"finn"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_DPS
block|,
literal|0x080000
block|,
literal|3
block|,
literal|"dps"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_SDB
block|,
literal|0x100000
block|,
literal|3
block|,
literal|"sdb"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_NSAPA
block|,
literal|0x200000
block|,
literal|3
block|,
literal|"nsapa"
block|}
block|,
comment|/* size ?? */
block|{
name|IPOPT_RTRALRT
block|,
literal|0x400000
block|,
literal|3
block|,
literal|"rtralrt"
block|}
block|,
comment|/* RFC2113 */
block|{
name|IPOPT_UMP
block|,
literal|0x800000
block|,
literal|3
block|,
literal|"ump"
block|}
block|,
comment|/* size ?? */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|(
name|char
operator|*
operator|)
name|NULL
block|}
comment|/* must be last */
block|}
decl_stmt|;
end_decl_stmt

end_unit

