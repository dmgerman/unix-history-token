begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Ugen J.S.Antsilevich  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * Snoop stuff.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SNOOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SNOOP_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
comment|/* This one also,64K enough 						 * If we grow more,something 						 * really bad in this world.. 						 */
end_comment

begin_comment
comment|/*  * This is the main snoop per-device  * structure...  */
end_comment

begin_struct
struct|struct
name|snoop
block|{
name|dev_t
name|snp_target
decl_stmt|;
comment|/* major/minor number of device*/
name|struct
name|tty
modifier|*
name|snp_tty
decl_stmt|;
comment|/* tty device pointer	       */
name|u_long
name|snp_len
decl_stmt|;
comment|/* buffer data length	       */
name|u_long
name|snp_base
decl_stmt|;
comment|/* buffer data base	       */
name|u_long
name|snp_blen
decl_stmt|;
comment|/* Overall buffer len	       */
name|caddr_t
name|snp_buf
decl_stmt|;
comment|/* Data buffer		       */
name|int
name|snp_flags
decl_stmt|;
comment|/* Flags place		       */
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
comment|/* XXX several wrong storage classes and types here. */
end_comment

begin_decl_stmt
name|int
name|snpdown
name|__P
argument_list|(
operator|(
expr|struct
name|snoop
operator|*
name|snp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snpin
name|__P
argument_list|(
operator|(
expr|struct
name|snoop
operator|*
name|snp
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snpinc
name|__P
argument_list|(
operator|(
expr|struct
name|snoop
operator|*
name|snp
operator|,
name|char
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Theese are snoop io controls  * SNPSTTY accepts 'struct snptty' as input.  * If ever type or  unit set to -1,snoop device  * detached from its current tty.  */
end_comment

begin_define
define|#
directive|define
name|SNPSTTY
value|_IOW('T', 90, dev_t)
end_define

begin_define
define|#
directive|define
name|SNPGTTY
value|_IOR('T', 89, dev_t)
end_define

begin_comment
comment|/*  * Theese values would be returned by FIONREAD ioctl  * instead of number of characters in buffer in case  * of specific errors.  */
end_comment

begin_define
define|#
directive|define
name|SNP_OFLOW
value|-1
end_define

begin_define
define|#
directive|define
name|SNP_TTYCLOSE
value|-2
end_define

begin_define
define|#
directive|define
name|SNP_DETACH
value|-3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SNOOP_H_ */
end_comment

end_unit

