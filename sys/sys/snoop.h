begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * Snoop stuff.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SNOOP_H
end_ifndef

begin_define
define|#
directive|define
name|SNOOP_H
end_define

begin_define
define|#
directive|define
name|SNOOP_MINLEN
value|(4*1024)
end_define

begin_comment
comment|/* This should be power of 2. 						 * 4K tested to be the minimum 						 * for which on normal tty 						 * usage there is no need to 						 * allocate more. 						 */
end_comment

begin_define
define|#
directive|define
name|SNOOP_MAXLEN
value|(64*1024)
end_define

begin_comment
comment|/* This one also,64K enough  						 * If we grow more,something 						 * really bad in this world.. 						 */
end_comment

begin_comment
comment|/*  * This is the main snoop per-device   * structure...  */
end_comment

begin_struct
struct|struct
name|snoop
block|{
name|int
name|snp_unit
decl_stmt|;
comment|/* Pty unit number to snoop on */
name|int
name|snp_type
decl_stmt|;
comment|/* Type same as st_type later  */
name|u_long
name|snp_len
decl_stmt|,
name|snp_base
decl_stmt|;
comment|/* Buffer data len and base    */
name|u_long
name|snp_blen
decl_stmt|;
comment|/* Overall buffer len	       */
name|char
modifier|*
name|snp_buf
decl_stmt|;
comment|/* Data buffer		       */
name|int
name|snp_flags
decl_stmt|;
comment|/* Flags place		       */
define|#
directive|define
name|SNOOP_NBIO
value|0x0001
define|#
directive|define
name|SNOOP_ASYNC
value|0x0002
define|#
directive|define
name|SNOOP_OPEN
value|0x0004
define|#
directive|define
name|SNOOP_RWAIT
value|0x0008
define|#
directive|define
name|SNOOP_OFLOW
value|0x0010
define|#
directive|define
name|SNOOP_DOWN
value|0x0020
name|struct
name|selinfo
name|snp_sel
decl_stmt|;
comment|/* Selection info	       */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is structure to be passed  * to ioctl() so we can define different  * types of tty's..  */
end_comment

begin_struct
struct|struct
name|snptty
block|{
name|int
name|st_unit
decl_stmt|;
name|int
name|st_type
decl_stmt|;
define|#
directive|define
name|ST_PTY
value|0
comment|/* Regular Pty       */
define|#
directive|define
name|ST_VTY
value|1
comment|/* Vty for SysCons.. */
define|#
directive|define
name|ST_SIO
value|2
comment|/* Serial lines	     */
define|#
directive|define
name|ST_MAXTYPE
value|2
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SNPSTTY
value|_IOW('T', 90, struct snptty)
end_define

begin_define
define|#
directive|define
name|SNPGTTY
value|_IOR('T', 89, struct snptty)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

